/*----------------------------------------------------------------------------
 * CMSIS-RTOS 'main' function template
 *---------------------------------------------------------------------------*/

#define osObjectsPublic                     // define objects in main module
#include "osObjects.h"                      // RTOS object definitions

/****************************************************************************
 * @file     main.c
 * @version  V2.00
 * $Revision: 1 $
 * $Date: 14/12/08 11:50a $
 * @brief    Transmit and receive data from PC terminal through RS232 interface.
 * @note
 * Copyright (C) 2014 Nuvoton Technology Corp. All rights reserved.
 *
 ******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "NUC100Series.h"
#include "WinboundFlash.h"

#define PLL_CLOCK           12000000
//*********configuration variables**************
char IP1[50] = "104.236.203.4";
char PORT1[7] = "5556";
char IP2[50] = "159.89.254.53";
char PORT2[7] = "5556";
char vehicleregnum[15] = "DL15AN1234";
int interval = 5;
extern uint32_t pt;
extern uint32_t readpt;
extern int tc;
//**********************************************
int interval_count = 0;


/*---------------------------------------------------------------------------------------------------------*/
/* Extern variables                                                                                        */
/*---------------------------------------------------------------------------------------------------------*/

#ifdef OBD
extern char suppportedpid[100][7];
#endif
extern int pidcounter;
/*---------------------------------------------------------------------------------------------------------*/
/* Global variables                                                                                        */
/*---------------------------------------------------------------------------------------------------------*/
char g_u8SendData[TXBUFSIZE] = {0};
char g_u8RecData[RXBUFSIZE]	= {0};
char g_u8OBDSendData[OBDTXBUFSIZE] = {0};
char g_u8OBDRecData[OBDRXBUFSIZE]	= {0};
uint8_t g_u8OBDRecDataptr=0;
int MidDid;

volatile uint32_t g_u32comRbytes = 0;
volatile uint32_t g_u32comRhead  = 0;
volatile uint32_t g_u32comRtail  = 0;
volatile int32_t g_bWait         = TRUE;

/*---------------------------------------------------------------------------------------------------------*/
/* Define functions prototype                                                                              */
/*---------------------------------------------------------------------------------------------------------*/
int32_t main(void);

__inline void SYS_Init(void);
__inline void UARTs_Init();
extern void TCP_Send_ch(char * tcpcommand,char * tcpdataq, char * tcpresponse1, char * tcpresponse2, char * tcpresponse3, int32_t tcptimeout);

void UART1_IRQHandler(void);
void UART02_IRQHandler(void);
__inline void Init_IOs();
__inline void OBD_GET_PID();
int saveipconfigurations(void);
void readipconfigurations(void);
/*---------------------------------------------------------------------------------------------------------*/
/* Extern variables                                                                              */
/*---------------------------------------------------------------------------------------------------------*/

extern void cregquerry(void);
extern void Save_FS(void);
extern int32_t g_u8RecDataptr;
extern int Init_Thread (void);
extern void manualdelay(int delayms);
extern void SendAT(char * command, char * response1, char * response2, char * response3, int32_t timeout);
extern void SendAT_FS(char * command, char * response1, char * response2, char * response3, int32_t timeout);
extern void TCP_Send_ch(char * tcpcommand,char * tcpdataq, char * tcpresponse1, char * tcpresponse2, char * tcpresponse3, int32_t tcptimeout);
extern void SendAT_GPS_WO_MUTEX(char * command, char * response1, char * response2, char * response3, int32_t timeout);
extern void TCP_Send_ch(char * tcpcommand,char * tcpdataq, char * tcpresponse1, char * tcpresponse2, char * tcpresponse3, int32_t tcptimeout);
extern void TCP_Send(char * tcpcommand,char * tcpdata, char * tcpresponse1, char * tcpresponse2, char * tcpresponse3, int32_t tcptimeout);extern void Init_Timers (void);
extern void send_OBD(char * command, char * response1, char * response2, char * response3, int32_t timeout);
extern void SendAT_GPS(char * command, char * response1, char * response2, char * response3, int32_t timeout);
extern void parse_g(char* str, int first, int sec, char f, char s , char *string);
extern __inline void remove_all_chars(char* str, char c, char d);
extern void supportedpid(char command[5]);
extern  void cpinquerry();
extern int8_t charging, cpinready, cregready;
extern int8_t  network;
extern uint32_t pt = 0;
extern int start_thead;
extern osThreadId tid_Thread_OBD_READ;                                          // thread id
//extern osThreadId tid_Thread_GSM;                                          // thread id
osThreadId mainThreadID;
extern int32_t signal;
extern int32_t signal2;
extern char suppportedpid[200][7];
extern char DestArray[257];
extern uint8_t sendfs;
extern int breaker;
extern char fileinstance[20];
char configdata[100];
volatile uint32_t g_u8IsWDTTimeoutINT;
volatile uint32_t g_u32WWDTINTCount = 0;

extern char temp[100];

osMutexDef (uart_mutex);		// Declare mutex
osMutexId	(uart_mutex_id); // Mutex ID
		
osMutexDef (tcp_mutex);		// Declare mutex
osMutexId	(tcp_mutex_id); // Mutex ID

osMutexDef (fs_mutex);		// Declare mutex
osMutexId	(fs_mutex_id); // Mutex ID		
/*
 * main: initialize and start the system
 */
int main (void) {
  SYS_UnlockReg();                          // Unlock Registers
  SYS_Init();                               // Initialise System
  SYS_LockReg();                            // Lock Registers
  Open_SPI_Flash();                         // Initialise SPI Flash  
  Init_Timers();                            // Initialise Timers
  osKernelInitialize ();                    // initialise CMSIS-RTOS
  /* Because of all bits can be written in WDT Control Register are write-protected;
     To program it needs to disable register protection first. */
  SYS_UnlockReg();
  /* Enable WDT time-out reset function and select time-out interval to 2^14 * WDT clock then start WDT counting */
  g_u8IsWDTTimeoutINT = 0;
  WWDT_Open(WWDT_PRESCALER_768, 0x20, TRUE);  
  WDT_EnableInt();
  NVIC_EnableIRQ(WDT_IRQn);  
  SYS_LockReg();                            // Lock Registers

  //Init_IOs();                               // Initialise Input/Outputs
  UARTs_Init();                             // Initialise UARTs
  osKernelStart ();                         // start thread execution 

  MidDid = SpiFlash_ReadMidDid();
  MidDid = SpiFlash_ReadMidDid();
  #ifdef OBD
    OBD_GET_PID();
  #endif
  mainThreadID = osThreadGetId();
  //Init_Thread ();
  //SpiFlash_ChipErase();
  while(1){
    memset(DestArray,0,257);
    //SpiFlash_WaitReady();
    SpiFlash_ReadData(DestArray, pt, 256);    
    if((DestArray[0]) == 0xFF)break;
    manualdelay(10);
    pt+=256;
  }
  

  while (1) {
    printf("\r\nHelloWorld1\r\n\r\n");
    osDelay(2000);
    
  }{
//    saveipconfigurations();
//    readipconfigurations();
    SendAT("\r\nAT+CFUN=1\r\n\r\n", "OK", "NOT INSERTED" , "ERROR",5);
    SendAT_GPS("\r\n\r\nAT+QGNSSRD=\"NMEA/RMC\"\r\n\r\n\r\n", "MGPSSTATUS", "OK" , "ERROR",5);	
    //  signal2 = osSignalSet (tid_Thread_OBD_READ, 0x0002);
    cpinquerry();
    if(cpinready==1){
      cregquerry();
      if(cregready == 1){
	        
        SendAT("\r\nAT+CGREG?\r\n\r\n", "Ready", "OK" , "ERROR",5);	
        SendAT("\r\nAT+QIREGAPP=\"isafe\",\"\",\"\"\r\n\r\n", "Ready", "OK" , "ERROR",5);	
        SendAT("\r\nAT+QIREGAPP?\r\n\r\n", "Ready", "OK" , "ERROR",5);	
        SendAT("\r\nAT+QIACT\r\n\r\n", "Ready", "OK" , "ERROR",10);	
        SendAT("\r\nAT+QILOCIP\r\n\r\n", "Ready", "OK" , "ERROR",0);
        osDelay(100);
      }
    }

    SendAT("\r\nAT+QSCLK=1\r\n\r\n", "Ready", "OK" , "ERROR",5);
    SendAT("\r\nAT+QIOPEN=0,\"TCP\",\"104.236.203.4\",\"5556\"\r\n\r\n","CONNECT","ERROR","FAIL",10);	
    SendAT("\r\nAT+QIOPEN=1,\"TCP\",\"159.89.254.53\",\"5556\"\r\n\r\n","CONNECT","ERROR","FAIL",10);	
    network=0;
    #ifdef OBD    
      if (start_thead != 0){
      osSignalWait (0x0001, osWaitForever); // wait forever for the signal 0x0001
      osSignalClear (mainThreadID, 0x0001);
      }start_thead = 1;
    #endif  
    sendfs = 0;      
    //do{}while(interval_count < interval);
    interval_count = 0;
    TCP_Send("\r\nAT+QISEND=0\r\n\r\n\r\n",g_u8SendData,">","ERROR","SEND OK",10);	
    breaker = 0;
    if(sendfs==1){
      TCP_Send_ch("\r\nAT+QISEND\r\n\r\n",g_u8SendData,">","ERROR","SEND OK",5);	
    }
    if(network == 1){
      if(breaker == 1)SendAT_GPS("\r\n\r\nAT+QGNSSRD=\"NMEA/RMC\"\r\n\r\n\r\n", "MGPSSTATUS", "OK" , "ERROR",5);	
      SendAT("\r\nAT+QICLOSE=0\r\n\r\n","CLOSE OK\r\n","ERROR","FAIL",10);	
      SendAT("\r\nAT+QICLOSE=1\r\n\r\n","CLOSE OK\r\n","ERROR","FAIL",10);	
      SendAT("\r\nAT+CFUN=0\r\n\r\n", "OK", "NOT INSERTED" , "ERROR",10);
      SendAT("\r\nAT+CFUN=1\r\n\r\n", "SMS Ready", "NOT INSERTED" , "ERROR",10);	
      Save_FS();
      SendAT("\r\nAT+QIDEACT\r\n\r\n", "OK", "DEACT OK" , "ERROR",10);
      SendAT("\r\nAT+QIMODE=0\r\n\r\n", "OK", "NOT INSERTED" , "ERROR",5);
      SendAT("\r\nAT+QIMUX?\r\n\r\n", "OK", "NOT INSERTED" , "ERROR",5);	
      SendAT("\r\nAT+QIMUX=1\r\n\r\n", "OK", "NOT INSERTED" , "ERROR",5);
      //manualdelay(200);
    }
    else{
      // Keep looping...
    }
  }
}


int saveipconfigurations(void){
  int retry = 1;
  int len;
  while(retry == 1){
    memset(fileinstance,0,20);
    SendAT("\r\nAT+QFOPEN=\"IPCONFIG.TXT\",0\r\n", "ERROR", "OK" , "ERROR",10);
    if(strstr(g_u8RecData,"ERROR")){
      SendAT("\r\nAT+CFUN=1,1", "ERROR", "OK" , "ERROR",10);
      manualdelay(300);
      SendAT("\r\nAT+QFOPEN=\"IPCONFIG.TXT\",0\r\n", "ERROR", "OK" , "ERROR",10);
    }      
    parse_g(g_u8RecData, 1, 2, ' ', '\n' , fileinstance);
    remove_all_chars(fileinstance, '\r', '\n'); 
    
    //seek to the origin 
    memset(temp,0,100);
    sprintf(temp, "AT+QFSEEK=%s,0,0\r\n\r\n", fileinstance);
    SendAT(temp, "CONNECT", "OK" , "ERROR",10);	  

    memset(configdata,0,100);
    sprintf(configdata,"|IP1|%s|PORT1|%s|IP2|%s|PORT2|%s|FLASHREADPTR|%d|FLASHWRITEPTR|%d|INTERVAL|%d|LICENCEPLATE|%s|\n",IP1,PORT1,IP2,PORT2,pt,readpt,interval,vehicleregnum);
    retry = 0;    
    len = strlen(configdata);
    
    memset(temp,0,100);
    sprintf(temp, "AT+QFWRITE=%s,%d\r\n\r\n", fileinstance,len);
    SendAT(temp, "CONNECT", "OK" , "ERROR",10);	    
    if(strstr(g_u8RecData, "CONNECT")){
      SendAT(configdata, "QFWRITE", "OK" , "ERROR",10);	 
      retry = 0;
    }
    memset(temp,0,100);
    sprintf(temp,"\r\nAT+QFCLOSE=%s\r\n\r\n",fileinstance);
    SendAT(temp, "+CME ERROR", "OK" , "ERROR",10);
  }
return 0;
}
__inline void readipconfigurations(void){
  int retry = 1;
  int len;
  char pt_c[10] = 0;
  char readpt_c[10] = 0;
  char interval_c[10] = 0;
  do{
    
    memset(fileinstance,0,20);
    SendAT("\r\nAT+QFOPEN=\"IPCONFIG.TXT\",0\r\n", "ERROR", "OK" , "ERROR",10);	
    if(strstr(g_u8RecData, "ERROR")){
      SendAT("\r\nAT+CFUN=1,1", "ERROR", "OK" , "ERROR",10);
      manualdelay(300);
      SendAT("\r\nAT+QFOPEN=\"IPCONFIG.TXT\",0\r\n", "ERROR", "OK" , "ERROR",10);
    }
    parse_g(g_u8RecData, 1, 2, ' ', '\n' , fileinstance);
    remove_all_chars(fileinstance, '\r', '\n'); 
    if(strlen(fileinstance)<1)retry = 1;
    else{
      //seek to the origin 
      memset(temp,0,100);
      sprintf(temp, "AT+QFSEEK=%s,0,0\r\n\r\n", fileinstance);
      SendAT(temp, "CONNECT", "OK" , "ERROR",10);	    
      memset(temp,0,100);
      sprintf(temp, "AT+QFREAD=%s\r\n\r\n", fileinstance);
      SendAT(temp, "OK", "OK" , "ERROR",10);	    
      memset(IP1,0,50);
      memset(IP2,0,50);
      memset(PORT1,0,7);
      memset(PORT2,0,7);
      memset(pt_c,0,10);
      memset(readpt_c,0,10);
      memset(interval_c,0,10);
      
      parse_g(g_u8RecData, 2,3,'|','|', IP1);
      parse_g(g_u8RecData, 4,5,'|','|', PORT1);
      parse_g(g_u8RecData, 6,7,'|','|', IP2);
      parse_g(g_u8RecData, 8,9,'|','|', PORT2);
      parse_g(g_u8RecData, 10,11,'|','|', readpt_c);
      parse_g(g_u8RecData, 12,13,'|','|', pt_c);
      parse_g(g_u8RecData, 14,15,'|','|', interval_c);
      pt = atoi(pt_c);
      readpt = atoi(readpt_c);
      interval = atoi(interval_c);
     
      memset(temp,0,100);
      sprintf(temp,"\r\nAT+QFCLOSE=%s\r\n\r\n",fileinstance);
      SendAT(temp, "+CME ERROR", "OK" , "ERROR",10);
      retry = 0;
    }
  }while(retry);
}


__inline void OBD_GET_PID(){
  send_OBD("ATZ\r","HELLO","NODATA",">",5);
  send_OBD("ATE1\r","HELLO","NODATA",">",5);
  send_OBD("ATL1\r","HELLO","NODATA",">",5);
  send_OBD("ATSP0\r","HELLO","NODATA",">",5);
  send_OBD("ATDP\r","HELLO","NODATA",">",5);
  send_OBD("ATRV\r","HELLO","NODATA",">",5);
  send_OBD("0100\r","HELLO","NODATA",">",5);
  send_OBD("0101\r","HELLO","NODATA",">",5);
  send_OBD("010C\r","HELLO","NODATA",">",5);
  send_OBD("010D\r","HELLO","NODATA",">",5);
  send_OBD("0120\r","HELLO","NODATA",">",5);
  memset(suppportedpid, 0, sizeof(char)*200*7);
  //   if(!(strstr(g_u8OBDRecData,"UNABLE") || strstr(g_u8OBDRecData,"NO DATA"))){	
  pidcounter=0;
  supportedpid("0100\r\n");
  supportedpid("0120\r\n");
  supportedpid("0140\r\n");
  supportedpid("0160\r\n");
  supportedpid("0180\r\n");
  supportedpid("01A0\r\n");
  supportedpid("01C0\r\n");
  supportedpid("050100\r\n");
  supportedpid("0900\r\n");	
}
__inline void SYS_Init(void)
{
    /*---------------------------------------------------------------------------------------------------------*/
    /* Init System Clock                                                                                       */
    /*---------------------------------------------------------------------------------------------------------*/


    /* Enable Internal RC 22.1184MHz clock */
    CLK_EnableXtalRC(CLK_PWRCON_OSC22M_EN_Msk);

    /* Waiting for Internal RC clock ready */
    CLK_WaitClockReady(CLK_CLKSTATUS_OSC22M_STB_Msk);

    /* Switch HCLK clock source to Internal RC and HCLK source divide 1 */
    CLK_SetHCLK(CLK_CLKSEL0_HCLK_S_HIRC, CLK_CLKDIV_HCLK(1));

    /* Enable external XTAL 12MHz clock */
    CLK_EnableXtalRC(CLK_PWRCON_XTL12M_EN_Msk);

    /* Waiting for external XTAL clock ready */
    CLK_WaitClockReady(CLK_CLKSTATUS_XTL12M_STB_Msk);

    /* Set core clock as PLL_CLOCK from PLL */
    CLK_SetCoreClock(PLL_CLOCK);

    /* Enable UART module clock */
    CLK_EnableModuleClock(UART0_MODULE);

    /* Select UART module clock source */
    CLK_SetModuleClock(UART0_MODULE, CLK_CLKSEL1_UART_S_HIRC, CLK_CLKDIV_UART(1));
    
    /* Enable UART module clock */
    CLK_EnableModuleClock(UART1_MODULE);

    /* Select UART module clock source */
    CLK_SetModuleClock(UART1_MODULE, CLK_CLKSEL1_UART_S_HIRC, CLK_CLKDIV_UART(1));
    
    /* Enable UART module clock */
    CLK_EnableModuleClock(UART2_MODULE);

    /* Select UART module clock source */
    CLK_SetModuleClock(UART2_MODULE, CLK_CLKSEL1_UART_S_HIRC, CLK_CLKDIV_UART(1));
    
    CLK_EnableModuleClock(WWDT_MODULE);    
        
    /* Select WWDT module clock source */
    CLK_SetModuleClock(WWDT_MODULE, CLK_CLKSEL2_WWDT_S_HCLK_DIV2048, NULL);
    
    /* Select ADC module clock source */
    CLK_SetModuleClock(ADC_MODULE, CLK_CLKSEL1_ADC_S_HIRC, CLK_CLKDIV_ADC(7));
    
//    CLK->CLKSEL1 &= CLK_CLKSEL1_ADC_S_Msk ;
//    CLK->CLKSEL1 |= CLK_CLKSEL1_ADC_S_HIRC ;

//    /* ADC clock source is 22.1184MHz, set divider to 7, ADC clock is 22.1184/7 MHz */
//    CLK->CLKDIV  = (CLK->CLKDIV & ~CLK_CLKDIV_ADC_N_Msk) | (((7) - 1) << CLK_CLKDIV_ADC_N_Pos);



    /*---------------------------------------------------------------------------------------------------------*/
    /* Init I/O Multi-function                                                                                 */
    /*---------------------------------------------------------------------------------------------------------*/

    /* Set GPB multi-function pins for UART0 RXD and TXD */
    SYS->GPB_MFP &= ~(SYS_GPB_MFP_PB0_Msk | SYS_GPB_MFP_PB1_Msk);
    SYS->GPB_MFP |= SYS_GPB_MFP_PB0_UART0_RXD | SYS_GPB_MFP_PB1_UART0_TXD;
    
    /* Set GPB multi-function pins for UART1 RXD and TXD */
    SYS->GPB_MFP &= ~(SYS_GPB_MFP_PB4_Msk | SYS_GPB_MFP_PB5_Msk);
    SYS->GPB_MFP |= SYS_GPB_MFP_PB4_UART1_RXD | SYS_GPB_MFP_PB5_UART1_TXD;

    /* Set GPB multi-function pins for UART2 RXD and TXD */
    SYS->GPD_MFP &= ~(SYS_GPD_MFP_PD14_Msk | SYS_GPD_MFP_PD15_Msk);
    SYS->GPD_MFP |= SYS_GPD_MFP_PD14_UART2_RXD | SYS_GPD_MFP_PD15_UART2_TXD;

    /* Configure the GPA0 - GPA6   ADC analog input pins */
    SYS->GPA_MFP &= ~(SYS_GPA_MFP_PA0_Msk | SYS_GPA_MFP_PA1_Msk | SYS_GPA_MFP_PA2_Msk | SYS_GPA_MFP_PA3_Msk | SYS_GPA_MFP_PA4_Msk | SYS_GPA_MFP_PA5_Msk | SYS_GPA_MFP_PA6_Msk);
    SYS->GPA_MFP |= SYS_GPA_MFP_PA0_ADC0 | SYS_GPA_MFP_PA1_ADC1 | SYS_GPA_MFP_PA2_ADC2 | SYS_GPA_MFP_PA3_ADC3 | SYS_GPA_MFP_PA4_ADC4 | SYS_GPA_MFP_PA5_ADC5 | SYS_GPA_MFP_PA6_ADC6 ;
    SYS->ALT_MFP1 = 0;
    
    
//    GPIO_SetMode(PB, BIT6, GPIO_PMD_INPUT);      //Ring Indicator
//    GPIO_EnableInt(PB, 6, GPIO_INT_RISING);
//    NVIC_EnableIRQ(GPAB_IRQn);
    
    
}

__inline void UARTs_Init()
{
    /*---------------------------------------------------------------------------------------------------------*/
    /* Init UART                                                                                               */
    /*---------------------------------------------------------------------------------------------------------*/
    /* Reset UART0 */
    SYS_ResetModule(UART0_RST);
    SYS_ResetModule(UART1_RST);
    SYS_ResetModule(UART2_RST);

    /* Configure UART0 and set UART0 Baudrate */
    UART_Open(UART0, 9600);             // ifdef DEBUG UART elseif RS232_1  
    UART_Open(UART1, 115200);           //MAIN UART MC60
    UART_Open(UART2, 9600);             // ifdef OBD UART elseif RS232_2
		UART_ENABLE_INT(UART1, (UART_IER_RDA_IEN_Msk ));
		NVIC_EnableIRQ(UART1_IRQn);  
		UART_ENABLE_INT(UART2, (UART_IER_RDA_IEN_Msk ));
		NVIC_EnableIRQ(UART02_IRQn);  
}

void UART1_IRQHandler(void)
{char uart1data;
    while(!UART_GET_RX_EMPTY(UART1)) 
    {
      uart1data = UART_READ(UART1);
      if(uart1data != 0){
        g_u8RecData[g_u8RecDataptr] = uart1data;
        g_u8RecDataptr++;
      }
    }
}
void UART02_IRQHandler(void)
{
    while(!UART_GET_RX_EMPTY(UART2)) 
    {
      g_u8OBDRecData[g_u8OBDRecDataptr] = UART_READ(UART2);
      g_u8OBDRecDataptr++;
    }
}



__inline void Init_IOs(){
  /* Analog 
    PA.1:  Analog in (INTERNAL_BATT_VOLTAGE_MEASURE)
    PA.2:  Analog in (CAR BATT _ VOLTAGE_MEASURE)
    PA.2:  Analog_IN_1                              
    PA.3:  Analog_IN_2                              
    PA.4:  Analog_IN_3                              
    PA.5:  Analog_IN_4     
    PA.6:  Analog in (ANT_FB)
  */
  
  /* Digital In 
    PA.12: GPIO_IN (Digital_in_3)                         
    PA.13: GPIO_IN (Digital_in_4)                         
    PA.14: GPIO_IN (Digital_in_1)
    PA.15: GPIO_IN (Digital_in_2)
    PB.2:  GPIO_IN (External power removed)
    PE.5:  GPIO_IN (IPPS_INT)
    PB.9:  GPIO_IN (Panic_MCU_In)
    PB.10: GPIO_IN (Ignition_sense_In)
    PA.10:GPIO_IN (Acc_INT1)
    PA.11:GPIO_IN (Acc_INT2)
    PB.6:   GPIO _IN                            (MCU_RI)
    PB13 : Tamper alert/ Case Open
  */ 
    GPIO_SetMode(PB, BIT6, GPIO_PMD_INPUT);      //Ring Indicator
    GPIO_EnableInt(PB, 6, GPIO_INT_RISING);
    NVIC_EnableIRQ(GPAB_IRQn);

    GPIO_SetMode(PA, BIT10, GPIO_PMD_INPUT);     //Acc 1 Interrupt
    GPIO_EnableInt(PA, 10, GPIO_INT_RISING);
    NVIC_EnableIRQ(GPAB_IRQn); 
    
    GPIO_SetMode(PA, BIT11, GPIO_PMD_INPUT);     //Acc 2 Interrupt
    GPIO_EnableInt(PA, 11, GPIO_INT_RISING);
    NVIC_EnableIRQ(GPAB_IRQn); 
    
    GPIO_SetMode(PB, BIT10, GPIO_PMD_INPUT);     //Ignition Sense Interrupt
        
    GPIO_SetMode(PB, BIT9, GPIO_PMD_INPUT);     //Panic Button Interrupt
    GPIO_EnableInt(PB, 9, GPIO_INT_RISING);
    NVIC_EnableIRQ(GPAB_IRQn); 
        
    GPIO_SetMode(PA, BIT12, GPIO_PMD_INPUT);      //DIO3 Indicator
    GPIO_EnableInt(PB, 12, GPIO_INT_RISING);
    NVIC_EnableIRQ(GPAB_IRQn);
    GPIO_SetMode(PA, BIT13, GPIO_PMD_INPUT);      //DIO4 Indicator
    GPIO_EnableInt(PB, 13, GPIO_INT_RISING);
    NVIC_EnableIRQ(GPAB_IRQn);
    GPIO_SetMode(PA, BIT14, GPIO_PMD_INPUT);      //DIO1 Indicator
    GPIO_EnableInt(PB, 14, GPIO_INT_RISING);
    NVIC_EnableIRQ(GPAB_IRQn);
    GPIO_SetMode(PA, BIT15, GPIO_PMD_INPUT);      //DIO2 Indicator
    GPIO_EnableInt(PB, 15, GPIO_INT_RISING);
    NVIC_EnableIRQ(GPAB_IRQn);  
    

  /* Digital Out 
    PB.7:   GPIO_OUT                         (MCU_DTR)
    PC.0:   GPIO_OUT (Acc_add_sel)
    PC.6: GPIO_OUT (Digital_out_1)	
    PC.7: GPIO_OUT (Digtial_out_2)
    PB.3:  GPIO_OUT (relay cutoff)
    PB.11: GPIO_OUT (pwr_key_reset)
    PB.15: GPIO_OUT (GSM_Modem_OFF)
    PC.14: GPIO_OUT (MCU_SELF_RESET)
    PC.16: GPIO_OUT (MCU_PWR_RESET)
    PB.8:   GPIO_OUT (EXT_ANT_SWITCH)
    PC.2:  GPIO_OUT (LED_DEBUG_1)
    PC.3:  GPIO_OUT (LED_DEBUG_2)
    PA.7:  GPIO_OUT (BATT_MEASURE_ENABLE)
  */  
}


void waitfor123(){
    osSignalWait (0x0123, osWaitForever); // wait forever for the signal 0x0001
    osSignalClear (mainThreadID, 0x0123);
}

void signal123(){
    osSignalSet (tid_Thread_OBD_READ, 0x0123);
}
void waitfor321(){
    osSignalWait (0x0321, osWaitForever); // wait forever for the signal 0x0001
    osSignalClear (tid_Thread_OBD_READ, 0x0321);
}

void signal321(){
    osSignalSet (mainThreadID, 0x0321);
}


void GPAB_IRQHandler(void){
  if (PB6 == 1){
    printf("Message Received");
  }
}
void WDT_IRQHandler(void)
{
    // Reload WWDT counter and clear WWDT interrupt flag
    WWDT_RELOAD_COUNTER();
    WWDT_CLEAR_INT_FLAG();
   // printf("WWDT counter reload\r\n");
//    while(1);
}
