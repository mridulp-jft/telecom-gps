/****************************************************************************************************/
/**
Copyright (c) 2008 Freescale Semiconductor
Freescale Confidential Proprietary
\file       adc_test.c
\brief      configure the adc for single end mode, and software trigger. PDB enabled for ADC triggering
\author     FSL
\version    1.0
\date       Sep 29 2011
*/


#include "common.h"
#include "edma_common.h"
#include "adc16.h"
//#include "TWR_K20D50M_DEF.h"
//#include "buzzer.h"   //include timers definitions
#include "adc_test.h"
#include "global.h"

#define MAX_SAMPLES   128u

#define ADC_POT_CHANNEL 18  //ADC0_DM3  single


#define BITS32    2
#define BITS16    1
#define BITS8     0


void vfnDMAADCCh_Init(void);
void vfnDMAtoRAM(uint32 *destiny_address);


/******************************************************************************* 
*  Global variables
*******************************************************************************/
dma_tcd tcd;
int intnum, channel_no;
dma_tcd tcd1,tcd2;
char buffer;   //If buffer = 0x80 flag of data ready  bit0 for buffer selection
char adc_reading_channel;
char last_adc_channel;


unsigned char foobar=0x00;    // ".data" variable example
int isr_flag, dma_error = 0;


//globle variables
tADC_Config Master_Adc_Config;  
tADC_Cal_Blk CalibrationStore[2];
uint16 adc_sample0;
uint16 adc_sample1;  
uint16 DMA_errorCount;
uint16 dmaIsrCount;

uint32 adc_buffer[256];


volatile uint16  wSamplesCounter;
volatile uint8   bSamplesReady;
volatile uint32  bSeqErr;

// Prototypes
void adc_init(void);
void pdb_init(void);   
void pdb_seq_error(uint16 channel,uint16 pretrigger);
void process_samples_offline(void);
void handle_pdb_seq_err(void);
void deinit_pdb_adc(void);


/**   adc_test_init
 * \brief    initialize ADC and prepare for test
 * \author   FSL
 * \param    none
 * \return   none
 * \warning   ASSUME: IPBus clock is 48MHz
 */  
void adc_test_init(void)
{

    printf("Welcome to PDB trigger ADC demo!\r\n");
    printf("Please make sure signal on ADC1 channel1 is ready, press any key to continue...!");
    printf("\r\n");
    
    // Initialize global variables
    wSamplesCounter = 0;
    bSamplesReady = 0;
    bSeqErr = 0;
    adc_init();
    vfnDMAADCCh_Init();
    vfnDMAtoRAM(adc_buffer);
    
  //  pdb_init();
 }


/**   adc_init
 * \brief    initialize and calibrate ADC0 module
 * \brief    48MHz IPBus clock; ADC clock = 48M/2/8 = 3MHz
 * \brief    Total conversion time: 56N+4ADCK
 * \brief    given sampling rate Fs = 6.4K, 156us/sample,  156*3= 468 ADCK
 * \author   FSL
 * \param    none
 * \return   none
 * \warning  assumes 48MHz IPBus clock
 */ 
void adc_init(void)
{
  
   uint8_t cal_ok;
 
   SIM_SCGC6 |= SIM_SCGC6_ADC0_MASK;
#ifdef CMSIS
   NVIC_EnableIRQ(ADC0_IRQn);
#else
   enable_irq(INT_ADC0 - 16);
#endif
     
  /* 48MHz IPBus clock
   * ADC clock = 48M/2/8 = 3MHz
   * Total conversion time: 56N+4ADCK
   * Given sampling rate Fs = 6.4K, 156us/sample,  156*3= 468 ADCK
   * the maximum h/w average number = 8
   * use h/w average number = 4
   * Total conversion time: 56*4+4 = 228 ADC clocks,76us
   * There are 468-228 = 240 ADC clocks (ie. 80us) free for post processing
   */
 

 // Initialize ADC0
  // Do calibration first with 32 h/w averages
  Master_Adc_Config.CONFIG1  = ADLPC_NORMAL | ADC_CFG1_ADIV(ADIV_8) | ADLSMP_LONG | ADC_CFG1_MODE(MODE_16)
                              | ADC_CFG1_ADICLK(ADICLK_BUS_2);  
  Master_Adc_Config.CONFIG2  = MUXSEL_ADCA | ADACKEN_ENABLED | ADHSC_HISPEED | ADC_CFG2_ADLSTS(ADLSTS_20) ;
  Master_Adc_Config.COMPARE1 = 0x1234u ; 
  Master_Adc_Config.COMPARE2 = 0x5678u ;
  Master_Adc_Config.STATUS2  = ADTRG_SW | ACFE_DISABLED | ACFGT_GREATER | ACREN_ENABLED | DMAEN_DISABLED | ADC_SC2_REFSEL(REFSEL_EXT);
  Master_Adc_Config.STATUS3  = CAL_OFF | ADCO_SINGLE | AVGE_ENABLED | ADC_SC3_AVGS(AVGS_32);
 // Master_Adc_Config.PGA      = PGAEN_DISABLED | PGACHP_NOCHOP | PGALP_NORMAL | ADC_PGA_PGAG(PGAG_64);
  Master_Adc_Config.STATUS1A = AIEN_OFF | DIFF_SINGLE | ADC_SC1_ADCH(31);       
  Master_Adc_Config.STATUS1B = AIEN_OFF | DIFF_SINGLE | ADC_SC1_ADCH(31);  
  
  ADC_Config_Alt(ADC0_BASE_PTR, &Master_Adc_Config);  // config ADC
  cal_ok = ADC_Cal(ADC0_BASE_PTR);                    // do the calibration
  if (cal_ok != 0) printf("ADC calibration error");
  ADC_Read_Cal(ADC0_BASE_PTR,&CalibrationStore[1]);   // store the cal
  
  // Now do normal ADC configuration with 4 h/w averages and h/w trigger from PDB
  Master_Adc_Config.CONFIG1  = ADLPC_NORMAL | ADC_CFG1_ADIV(ADIV_8) | ADLSMP_LONG | ADC_CFG1_MODE(MODE_12)
                              | ADC_CFG1_ADICLK(ADICLK_BUS_2);  
  Master_Adc_Config.CONFIG2  = MUXSEL_ADCB | ADACKEN_ENABLED | ADHSC_HISPEED | ADC_CFG2_ADLSTS(ADLSTS_20) ;
  Master_Adc_Config.COMPARE1 = 0x1234u ; 
  Master_Adc_Config.COMPARE2 = 0x5678u ;
  Master_Adc_Config.STATUS2  = !ADTRG_HW | ACFE_DISABLED | ACFGT_GREATER | ACREN_DISABLED | DMAEN_DISABLED | ADC_SC2_REFSEL(REFSEL_EXT);
  Master_Adc_Config.STATUS3  = CAL_OFF | ADCO_SINGLE | AVGE_ENABLED | ADC_SC3_AVGS(AVGS_4);
//  Master_Adc_Config.PGA      = PGAEN_DISABLED | PGACHP_NOCHOP | PGALP_NORMAL | ADC_PGA_PGAG(PGAG_64);

  Master_Adc_Config.STATUS1A = !AIEN_ON | DIFF_SINGLE | ADC_SC1_ADCH(31);                                                               
  Master_Adc_Config.STATUS1B = !AIEN_ON | DIFF_SINGLE | ADC_SC1_ADCH(31);    

  ADC_Config_Alt(ADC0_BASE_PTR, &Master_Adc_Config);  // config the ADC again to default conditions    
 
}

/**
 * @}
 */ /* end of group ADC_Register_Masks */



/**   adc_start_conversion, result is stored in the ADC interrupt on a global variable
 * \brief    start adc conversion of channel n
 * \author   FSL
 * \param    channel
 * \return   none
 * \warning  assumes 48MHz IPBus clock
 */ 
void adc_start_conversion(uint8 channel)
{
    ADC0_SC1A = !AIEN_ON | DIFF_SINGLE | ADC_SC1_ADCH(channel);     
   
   
}


/*
  simple read of ADC
*/

uint16 adc_read(uint8 channel)
{
  
   ADC0_SC1A = !AIEN_ON | DIFF_SINGLE | ADC_SC1_ADCH(channel) ;     // start conversion
   while((ADC0_SC1A & ADC_SC1_COCO_MASK)!= 0){};
   return ADC0_RA;
}

 



/**   adc0_isr,
 * \brief    reads the results of the Adc conversion
 * \brief    values is stored in a global variable  adc_sample0, adc_sample1
 * \author   FSL
 * \param    none
 * \return   none
 * \warning  
 */ 
#ifdef CMSIS
void ADC0_IRQHandler(void)
#else
void adc0_isrv(void)
#endif
{


  if((ADC0_SC1A & ADC_SC1_COCO_MASK)!= 0){
    adc_sample0 = ADC0_RA;
  }
 
  if((ADC0_SC1B & ADC_SC1_COCO_MASK)!= 0){
    adc_sample = ADC0_RB;
  }
     
}








#define ADC0_DMA_CH_REQ   40

void vfnDMAADCCh_Init(void) 
{
#if 0
  /* eDMA Configurations */
    SIM_SCGC6 |= SIM_SCGC6_DMAMUX_MASK;
    
    DMAMUX_CHCFG1 = 0x00;      
    
    DMA_ERQ = (DMA_ERQ_ERQ0_MASK); // Enable DMA request 14,15
    DMA_CR |= DMA_CR_EDBG_MASK;
    
    DMAMUX_CHCFG0 = (DMAMUX_CHCFG_ENBL_MASK | DMAMUX_CHCFG_SOURCE(ADC0_DMA_CH_REQ));  
    enable_irq(INT_DMA0-16);
    
#endif
    
}


void vfnDMA_Config (dma_tcd *tcdPtr)
{
#if 0
    int8 i; 
  
    i = tcdPtr->channelno ;
    
    DMA_SADDR(i) = tcdPtr->saddr ;   
    DMA_ATTR(i) = tcdPtr->tcdAttr;                                   
    DMA_SOFF(i) = tcdPtr->soff;    
    DMA_NBYTES_MLNO(i) = tcdPtr->nbytes;    
    DMA_SLAST(i) = 0x0;    
    DMA_DADDR(i) = tcdPtr->daddr;    
    DMA_CITER_ELINKNO(i) = DMA_CITER_ELINKNO_CITER(tcdPtr->loopcount);                                            
    DMA_DOFF(i) = tcdPtr->doff;                                                  
    DMA_DLAST_SGA(i) = 0x0;    
    DMA_BITER_ELINKNO(i) = DMA_BITER_ELINKNO_BITER(tcdPtr->loopcount);    
    DMA_CSR(i) = DMA_CSR_INTMAJOR_MASK;	

#endif
    
}

/*  Initializes DMA to read from ADC0 resulta and store result in RAM*/
void vfnDMAtoRAM(uint32 *destiny_address)
{
   // SPI1 RX
    tcd1.saddr = (uint32)&ADC0_RA;
    tcd1.daddr = (uint32)destiny_address;
    tcd1.nbytes = 4;
    tcd1.soff =0x00;
    tcd1.doff =0x04;
    tcd1.loopcount = 128;
    tcd1.channelno = 0; 
    vfnDMA_Config(&tcd1);
}

void  real128_fft(void);   
/*interrumpe al final */
void vfnDMACh14ISR(void)
{	
        static uint16 buffer_flag =0;

#if 0	
       DMA_CINT = DMA_CINT_CINT(0); //Clear Interrupt Request Register (DMA_CINT)
        DMA_SSRT = DMA_SSRT_SSRT(0); //Set START Bit Register (DMA_SSRT)      
#endif        
        if ((buffer_flag) == 0)
        { 
          buffer_flag = 0x1;          // prepare for following
          buffer=0x80;
          vfnDMAtoRAM(&adc_buffer[128]);
        }
        else
        {
          buffer_flag = 0x0;
          dmaIsrCount++;
          buffer=0x81;
          vfnDMAtoRAM(&adc_buffer[0]);         
        } 
        
        
// Select between  Microphone or Potentiometer channel        
         if (ti_test_adc==0) adc_reading_channel = ADC_POT_CHANNEL;
         else adc_reading_channel = ADC_POT_CHANNEL;

         if (adc_reading_channel != last_adc_channel)
         {
           ADC0_SC2   |= ADC_SC2_ADTRG_MASK; // Hardware trigger Software trigger
           ADC0_SC1A = !AIEN_ON | DIFF_SINGLE | ADC_SC1_ADCH(adc_reading_channel);  // reads MIC or POT signal
           last_adc_channel = adc_reading_channel;
         }
   
        
     
       //  real128_fft();      
}



void vfnDMA_ErrorIsr(void)
{	
     printf("DMA error");
     DMA_errorCount++;
}


