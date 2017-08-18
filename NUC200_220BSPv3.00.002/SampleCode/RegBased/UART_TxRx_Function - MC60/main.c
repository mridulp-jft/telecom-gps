/****************************************************************************
 * @file     main.c
 * @version  V2.00
 * $Revision: 8 $
 * $Date: 15/04/13 3:46p $
 * @brief    Transmit and receive data from PC terminal through RS232 interface.
 * @note
 * Copyright (C) 2014 Nuvoton Technology Corp. All rights reserved.
 *
 ******************************************************************************/
#include <stdio.h>
#include "NUC200Series.h"
#include "string.h"
#include "functions.c"

#define PLLCON_SETTING  CLK_PLLCON_25MHz_HXT
#define PLL_CLOCK       25000000

#define UART0RXBUFSIZE 1240

/*---------------------------------------------------------------------------------------------------------*/
/* Global variables                                                                                        */
/*---------------------------------------------------------------------------------------------------------*/
char UART0Data[UART0RXBUFSIZE];
char IMEI[16];

uint32_t sysTicks;
extern int32_t inc;
__INLINE void sendAT(char* AT, char* resp1, char* resp2, char*resp3, uint32_t waittime_ms);
extern void wakeup();

extern  void CLK_SysTickDelay(uint32_t us);

volatile uint32_t g_u32comRbytes = 0;
volatile uint32_t g_u32comRhead  = 0;
volatile uint32_t g_u32comRtail  = 0;
volatile int32_t g_bWait         = TRUE;
volatile uint32_t g_u32AdcIntFlag;


int sent = 0;
extern int intervaltimercount;
int interval;
int datainterval = 30;
int32_t  i32ConversionData;


/*---------------------------------------------------------------------------------------------------------*/
/* Define functions prototype                                                                              */
/*---------------------------------------------------------------------------------------------------------*/
int32_t main(void);
void UART_TEST_HANDLE(void);
void UART_FunctionTest(void);
extern __INLINE void delay(int32_t sec);
extern __INLINE void delayms(int32_t sec);




__INLINE void SYS_Init(void)
{
    /*---------------------------------------------------------------------------------------------------------*/
    /* Init System Clock                                                                                       */
    /*---------------------------------------------------------------------------------------------------------*/

    /* Enable Internal RC 22.1184MHz clock */
    CLK->PWRCON |= CLK_PWRCON_OSC22M_EN_Msk;

    /* Waiting for Internal RC clock ready */
    while(!(CLK->CLKSTATUS & CLK_CLKSTATUS_OSC22M_STB_Msk));

    /* Switch HCLK clock source to Internal RC and HCLK source divide 1 */
    CLK->CLKSEL0 &= ~CLK_CLKSEL0_HCLK_S_Msk;
    CLK->CLKSEL0 |= CLK_CLKSEL0_HCLK_S_HIRC;
    CLK->CLKDIV &= ~CLK_CLKDIV_HCLK_N_Msk;
    CLK->CLKDIV |= CLK_CLKDIV_HCLK(3);

    /* Enable external XTAL 12MHz clock */
    CLK->PWRCON |= CLK_PWRCON_XTL12M_EN_Msk;

    /* Waiting for external XTAL clock ready */
    while(!(CLK->CLKSTATUS & CLK_CLKSTATUS_XTL12M_STB_Msk));

    /* Set core clock as PLL_CLOCK from PLL */
    CLK->PLLCON = PLLCON_SETTING;
    while(!(CLK->CLKSTATUS & CLK_CLKSTATUS_PLL_STB_Msk));
    CLK->CLKSEL0 &= (~CLK_CLKSEL0_HCLK_S_Msk);
    CLK->CLKSEL0 |= CLK_CLKSEL0_HCLK_S_PLL;

    /* Update System Core Clock */
    /* User can use SystemCoreClockUpdate() to calculate PllClock, SystemCoreClock and CycylesPerUs automatically. */
    //SystemCoreClockUpdate();
    PllClock        = PLL_CLOCK;            // PLL
    SystemCoreClock = PLL_CLOCK / 1;        // HCLK
    CyclesPerUs     = PLL_CLOCK /1000;  // For SYS_SysTickDelay() set for  ms

    /* Enable UART module clock */
    CLK->APBCLK |= CLK_APBCLK_UART0_EN_Msk| CLK_APBCLK_TMR0_EN_Msk ;
		CLK->APBCLK |= CLK_APBCLK_ADC_EN_Msk ;

//		CLK->APBCLK |= CLK_APBCLK_UART1_EN_Msk | CLK_APBCLK_TMR0_EN_Msk ;

    /* Select UART module clock source */
    CLK->CLKSEL1 &= ~CLK_CLKSEL1_UART_S_Msk;
    CLK->CLKSEL1 |= CLK_CLKSEL1_UART_S_HXT | CLK_CLKSEL1_TMR0_S_HXT;

    /* Select ADC module clock source */
    CLK->CLKSEL1 &= CLK_CLKSEL1_ADC_S_Msk ;
    CLK->CLKSEL1 |= CLK_CLKSEL1_ADC_S_HIRC ;

    /* ADC clock source is 22.1184MHz, set divider to 7, ADC clock is 22.1184/7 MHz */
    CLK->CLKDIV  = (CLK->CLKDIV & ~CLK_CLKDIV_ADC_N_Msk) | (((7) - 1) << CLK_CLKDIV_ADC_N_Pos);
    /*---------------------------------------------------------------------------------------------------------*/
    /* Init I/O Multi-function                                                                                 */
    /*---------------------------------------------------------------------------------------------------------*/

    /* Set GPB multi-function pins for UART0 RXD and TXD */
    SYS->GPB_MFP &= ~(SYS_GPB_MFP_PB0_Msk | SYS_GPB_MFP_PB1_Msk);
    SYS->GPB_MFP |= SYS_GPB_MFP_PB0_UART0_RXD | SYS_GPB_MFP_PB1_UART0_TXD;
//    SYS->GPB_MFP &= ~(SYS_GPB_MFP_PB4_Msk | SYS_GPB_MFP_PB5_Msk);
//    SYS->GPB_MFP |= SYS_GPB_MFP_PB4_UART1_RXD | SYS_GPB_MFP_PB5_UART1_TXD;

    PA->OFFD = 0xF << GPIO_OFFD_OFFD_Pos;

    /* Configure the GPA0 - GPA3 ADC analog input pins */
    SYS->GPA_MFP &= ~(SYS_GPA_MFP_PA0_Msk | SYS_GPA_MFP_PA1_Msk | SYS_GPA_MFP_PA2_Msk | SYS_GPA_MFP_PA3_Msk) ;
    SYS->GPA_MFP |= SYS_GPA_MFP_PA0_ADC0 | SYS_GPA_MFP_PA1_ADC1 | SYS_GPA_MFP_PA2_ADC2 | SYS_GPA_MFP_PA3_ADC3 ;
    SYS->ALT_MFP1 = 0;
      


}


__INLINE void ADCread()
{
//		ADC->ADCR = (ADC_ADCR_ADMD_SINGLE | ADC_ADCR_DIFFEN_SINGLE_END | ADC_ADCR_ADEN_CONVERTER_ENABLE);
//		ADC->ADCHER |= ((ADC->ADCHER & ~ADC_ADCHER_CHEN_Msk) | 1);
//		ADC->ADSR = ADC_ADSR_ADF_Msk;
//		ADC->ADCR |= ADC_ADCR_ADIE_Msk;
//		NVIC_EnableIRQ(ADC_IRQn);

//		/* Reset the ADC interrupt indicator and Start A/D conversion */
//		g_u32AdcIntFlag = 0;
//		ADC->ADCR |= ADC_ADCR_ADST_Msk;

//		/* Wait ADC interrupt (g_u32AdcIntFlag will be set at IRQ_Handler function)*/
//		while(g_u32AdcIntFlag == 0);

//		/* Disable the ADC interrupt */
//		ADC->ADCR &= ~ADC_ADCR_ADIE_Msk;

//		/* Get the conversion result of the ADC channel 2 */
//		i32ConversionData = (ADC->ADDR[(0)] & ADC_ADDR_RSLT_Msk) >> ADC_ADDR_RSLT_Pos;
	
	
	
	
	
	
	
	          ADC->ADCR = (ADC_ADCR_ADMD_SINGLE | ADC_ADCR_DIFFEN_SINGLE_END | ADC_ADCR_ADEN_CONVERTER_ENABLE);
            /* Enable analog input channel 2 */
            ADC->ADCHER |= ((ADC->ADCHER & ~ADC_ADCHER_CHEN_Msk) | (1 << 0));

            /* Clear the A/D interrupt flag for safe */
            ADC->ADSR = ADC_ADSR_ADF_Msk;

            /* Enable the ADC interrupt */
            ADC->ADCR |= ADC_ADCR_ADIE_Msk;
            NVIC_EnableIRQ(ADC_IRQn);

            /* Reset the ADC interrupt indicator and Start A/D conversion */
            g_u32AdcIntFlag = 0;
            ADC->ADCR |= ADC_ADCR_ADST_Msk;

            /* Wait ADC interrupt (g_u32AdcIntFlag will be set at IRQ_Handler function)*/
            while(g_u32AdcIntFlag == 0);

            /* Disable the ADC interrupt */
            ADC->ADCR &= ~ADC_ADCR_ADIE_Msk;

            /* Get the conversion result of the ADC channel 2 */
            i32ConversionData = (ADC->ADDR[(0)] & ADC_ADDR_RSLT_Msk) >> ADC_ADDR_RSLT_Pos;
	

}

__INLINE void UART0_Init()
{
    /*---------------------------------------------------------------------------------------------------------*/
    /* Init UART                                                                                               */
    /*---------------------------------------------------------------------------------------------------------*/
    /* Reset UART0 */
    SYS->IPRSTC2 |=  SYS_IPRSTC2_UART0_RST_Msk;
    SYS->IPRSTC2 &= ~SYS_IPRSTC2_UART0_RST_Msk;

    /* Configure UART0 and set UART0 Baudrate */
    UART0->BAUD = UART_BAUD_MODE2 | UART_BAUD_MODE2_DIVIDER(__HXT, 115200);
    UART0->LCR = UART_WORD_LEN_8 | UART_PARITY_NONE | UART_STOP_BIT_1;

		UART0->IER |= UART_IER_RDA_IEN_Msk;// | UART_IER_THRE_IEN_Msk | UART_IER_TOUT_IEN_Msk ;
    NVIC_EnableIRQ(UART02_IRQn);
}

__INLINE void UART1_Init()
{
    /*---------------------------------------------------------------------------------------------------------*/
    /* Init UART                                                                                               */
    /*---------------------------------------------------------------------------------------------------------*/
    /* Reset UART0 */
    SYS->IPRSTC2 |=  SYS_IPRSTC2_UART1_RST_Msk;
    SYS->IPRSTC2 &= ~SYS_IPRSTC2_UART1_RST_Msk;

    /* Configure UART0 and set UART0 Baudrate */
    UART1->BAUD = UART_BAUD_MODE2 | UART_BAUD_MODE2_DIVIDER(__HXT, 115200);
    UART1->LCR = UART_WORD_LEN_8 | UART_PARITY_NONE | UART_STOP_BIT_1;
	
	
	  UART1->IER |= UART_IER_RDA_IEN_Msk;// | UART_IER_THRE_IEN_Msk | UART_IER_TOUT_IEN_Msk ;
    NVIC_EnableIRQ(UART1_IRQn);
}



/*---------------------------------------------------------------------------------------------------------*/
/* MAIN function                                                                                           */
/*---------------------------------------------------------------------------------------------------------*/
int main(void)
{
	int rep=0;
	intervaltimercount=0;
	interval = datainterval*5;
    /* Unlock protected registers */
    SYS_UnlockReg();
    /* Init System, peripheral clock and multi-function I/O */
    SYS_Init();
    /* Lock protected registers */
    SYS_LockReg();
    /* Init UART0 for printf and testing */
    UART0_Init();

	
	
		PB->PMD = (PB->PMD & (~GPIO_PMD_PMD2_Msk)) | (GPIO_PMD_OUTPUT << GPIO_PMD_PMD2_Pos);
		PA->PMD = (PA->PMD & (~GPIO_PMD_PMD10_Msk)) | (GPIO_PMD_OUTPUT << GPIO_PMD_PMD10_Pos);
//		intervaltimercount=interval;
		PB2 = 0;
		delay(5);

								sendAT("\r\nAT+CFUN=1\r\n", "OK", "NOT INSERTED" , "ERROR",5);
								delay(5);	
	
								sendAT("\r\nAT+QGNSSC=1\r\n", "+MGPSSTATUS", "OK" , "ERROR",5);	
//								sendAT("\r\nAT+EGPSC=1\r\n", "MGPSSTATUS", "DEACT" , "ERROR",5);	
//								sendAT("\r\nAT+MGPSS=\"PMTK353,1,1,0,1,0*2C\"\r\n", "Ready", "OK" , "ERROR",5);
////								sendAT("\r\nAT+MGPSS=\"PMTK353,1,0,0,0,1*2B\"\r\n", "Ready", "OK" , "ERROR",5);
//								sendAT("\r\nAT+MGPSEPO=1\r\n", "Ready", "OK" , "ERROR",5);	

//								sendAT("\r\nAT+CSCLK=1\r\n","OK","ERROR","DEACT",5);
//    TIMER0->TCMPR = __LIRC;
//    TIMER0->TCSR = TIMER_TOGGLE_MODE | TIMER_TCSR_IE_Msk | TIMER_TCSR_WAKE_EN_Msk;								
	  TIMER0->TCMPR = __HXT;
    TIMER0->TCSR = TIMER_TCSR_IE_Msk | TIMER_PERIODIC_MODE;
    TIMER_SET_PRESCALE_VALUE(TIMER0, 0);
    NVIC_EnableIRQ(TMR0_IRQn);
    TIMER_Start(TIMER0);

    while(1)
			{
				if(1)//(intervaltimercount >= interval)
				{

						rep=0;
								PB2 = 0;
								sendAT("\r\nAT\r\n","OK","ERROR","DEACT",1);
								GETGPSDATA();
					
//								delay(1);					
//								sendAT("\r\nAT+CFUN=0\r\n", "OK", "CME ERROR" , "ERROR",5);	
								sendAT("\r\nAT+CFUN=1\r\n", "OK", "NOT INSERTED" , "ERROR",5);
								delay(5);
//								sendAT("\r\nAT+CMEE=1\r\n", "Ready", "OK" , "ERROR",5);	
//								sendAT("\r\nAT+GETGPS=\"GNGGA\",1\r\n","Ready", "OK" , "ERROR",5);
					
								sendAT("AT+QGNSSC=1\r\n", "+MGPSSTATUS", "OK" , "ERROR",5);	
								sendAT("\r\nAT+QGNSSRD=\"NMEA/RMC\"\r\n", "+MGPSSTATUS", "OK" , "EcROR",5);	

//							sendAT("\r\nAT+CIPSHUT\r\n", "OK", "DEACT" , "ERROR",5);
//							sendAT("\r\nAT+CFUN=0\r\n", "CLOSED", "OK" , "ERROR",5);
//							sendAT("\r\nAT+CFUN=1\r\n", "EUSIM", "OK" , "ERROR",5);
//							delay(10);

							sendAT("\r\nAT+CSTT=\"isafe\"\r\n", "Ready", "OK" , "ERROR",5);	
							sendAT("\r\nAT+CGATT?\r\n", "Ready", "OK" , "ERROR",5);	

							sendAT("\r\nAT+CGATT=1\r\n", "Ready", "OK" , "ERROR",5);	
							sendAT("\r\nAT+CIICR\r\n", "Ready", "OK" , "ERROR",5);	
							sendAT("\r\nAT+CIFSR\r\n", "Ready", "OK" , "ERROR",5);	
				
				
				
							sendAT("\r\nAT+CIPMUX=0\r\n", "Ready", "OK" , "ERROR",5);	
							sendAT("\r\nAT+CSQ\r\n", "Ready", "OK" , "ERROR",5);	

								TCPsend();
								intervaltimercount = 0;					

				}
				else if(intervaltimercount == (0*datainterval) || intervaltimercount == (1*datainterval) || intervaltimercount == (2*datainterval) || intervaltimercount == (3*datainterval) || intervaltimercount == (4*datainterval))
				{
					PB2 = 0;
					GETGPSDATA();
				}
				else
					{
							if(rep == 0)
								{
//										sendAT("\r\nAT+MGPSC=0\r\n", "+MGPSSTATUS", "OK" , "ERROR",5);	

									sendAT("\r\nAT+CIPSHUT\r\n", "OK", "DEACT" , "ERROR",5);
									sendAT("\r\nAT+CGATT=0\r\n", "OK", "DEACT" , "ERROR",5);
									sendAT("\r\nAT+CFUN=0\r\n", "OK", "CLOSED" , "ERROR",5);
									PB2 = 1;
//								delay(5);								
									rep++;		
								}
								PB2 = 1;

//										sendAT("\r\nAT\r\n", "OK", "CLOSED" , "ERROR",5);
						
								PB2 = 1;

//								delay(5);
//								sendAT("\r\nAT\r\n","OK","ERROR","DEACT",5);
					}
	
			}

}
















































//		//wakeup();				
//				if(!sent)
//				{
//						PA10 = 0;
//						delay(1);

//					
//					
//								sendAT("\r\nAT\r\n","OK","ERROR","DEACT",5);
//								sendAT("\r\nAT+CSCLK=1\r\n","OK","ERROR","DEACT",5);				
//								sendAT("\r\nAT+CFUN=0\r\n", "OK", "ERROR" , "ERROR",5);	
//								sendAT("\r\nAT+CFUN=1\r\n", "OK", "NOT INSERTED" , "ERROR",5);
//								sendAT("\r\nAT+CMEE=1\r\n", "Ready", "OK" , "ERROR",5);	
//								sendAT("\r\nAT+GETGPS=\"GNGGA\",1\r\n","Ready", "OK" , "ERROR",5);	 
//				//				sendAT("\r\nAT+EGPSC=0\r\n", "Ready", "OK" , "ERROR",5);	
//								sendAT("\r\nAT+MGPSS=\"PMTK353,1,1,0,1,0*2C\"\r\n", "Ready", "OK" , "ERROR",5);
//				//AT+EGDCONT=0,"IP","CMNET"
//				//AT+MGPSC=1
//				//AT+MGPSTS=1,0
//				//AT+MGPSEPO=1,0
//								
//								sendAT("\r\nAT+CIPSHUT\r\n", "Ready", "OK" , "ERROR",5);	
//								sendAT("\r\nAT+CSTT=\"isafe\"\r\n", "Ready", "OK" , "ERROR",5);	
//				//				sendAT("\r\nAT+EGPSC=0\r\n", "MGPSSTATUS", "DEACT" , "ERROR",5);	

//								sendAT("\r\nAT+CGATT?\r\n", "Ready", "OK" , "ERROR",5);	
//								sendAT("\r\nAT+CGATT=1\r\n", "Ready", "OK" , "ERROR",5);	
//				//				sendAT("\r\nAT+EGDCONT=1,\"IP\",\"isafe\"\r\n", "Ready", "OK" , "ERROR",5);	
//				//				sendAT("\r\nAT+EGDCONT=2,\"IP\",\"isafe\"\r\n", "Ready", "OK" , "ERROR",5);	
//				//				sendAT("\r\nAT+MGPSTS=1\r\n", "Ready", "OK" , "ERROR",5);	
//				//				sendAT("\r\nAT+MGPSEPO=1\r\n", "Ready", "OK" , "ERROR",5);	
//								sendAT("\r\nAT+MGPSC=1\r\n", "+MGPSSTATUS", "OK" , "ERROR",5);	
//								sendAT("\r\nAT+EGPSC=1\r\n", "MGPSSTATUS", "DEACT" , "ERROR",5);	
//								sent=1;
//				}
//				else
//					{						
//						if (intervaltimercount >= interval)
//						{
//							
//							PA10 = 0;
//							delay(1);
//							
//							GETGPSDATA();				
//							TCPsend();
//							intervaltimercount = 0;
//							
//						}else{
//										sendAT("\r\nAT+CFUN=0\r\n", "OK", "DEACT" , "ERROR",5);	
//										PA10 = 1;
//										delay(5);
//										sendAT("\r\nAT\r\n","OK","ERROR","DEACT",5);
//									}
//					
////					if(intervaltimercount >= interval)sent=0;
//					}







