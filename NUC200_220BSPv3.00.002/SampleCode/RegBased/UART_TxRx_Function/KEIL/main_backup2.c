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


#define SLEEP PB2

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
int datainterval = 5;
int dataintervalflag=1;

/*---------------------------------------------------------------------------------------------------------*/
/* Define functions prototype                                                                              */
/*---------------------------------------------------------------------------------------------------------*/
int32_t main(void);
void UART_TEST_HANDLE(void);
void UART_FunctionTest(void);
extern __INLINE void delay(int32_t sec);
extern __INLINE void delayms(int32_t sec);
extern __INLINE void UART1_Init();
extern __INLINE void UART0_Init();
extern __INLINE void SYS_Init(void);












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

								sendAT("\r\nAT+MGPSC=1\r\n", "+MGPSSTATUS", "OK" , "ERROR",5);	
								sendAT("\r\nAT+EGPSC=1\r\n", "MGPSSTATUS", "DEACT" , "ERROR",5);	
								sendAT("\r\nAT+MGPSS=\"PMTK353,1,1,0,1,0*2C\"\r\n", "Ready", "OK" , "ERROR",5);
//								sendAT("\r\nAT+MGPSS=\"PMTK353,1,0,0,0,1*2B\"\r\n", "Ready", "OK" , "ERROR",5);
								sendAT("\r\nAT+MGPSEPO=1\r\n", "Ready", "OK" , "ERROR",5);	

								sendAT("\r\nAT+CSCLK=1\r\n","OK","ERROR","DEACT",5);
								sendAT("\r\nAT+FSINFO=?\r\n","OK","ERROR","DEACT",5);
//    TIMER0->TCMPR = __LIRC;
//    TIMER0->TCSR = TIMER_TOGGLE_MODE | TIMER_TCSR_IE_Msk | TIMER_TCSR_WAKE_EN_Msk;								
	  TIMER0->TCMPR = __HXT;
    TIMER0->TCSR = TIMER_TCSR_IE_Msk | TIMER_PERIODIC_MODE;
    TIMER_SET_PRESCALE_VALUE(TIMER0, 0);
    NVIC_EnableIRQ(TMR0_IRQn);
    TIMER_Start(TIMER0);

    while(1)
			{
				if(datacount >= 5)
				{
						datacount = 0;
						rep=0;
								SLEEP = 0;
								sendAT("\r\nAT\r\n","OK","ERROR","DEACT",1);
								GETGPSDATA();
					
//								delay(1);					
//								sendAT("\r\nAT+CFUN=0\r\n", "OK", "CME ERROR" , "ERROR",5);	
								sendAT("\r\nAT+CFUN=1\r\n", "OK", "NOT INSERTED" , "ERROR",5);
								delay(5);
//								sendAT("\r\nAT+CMEE=1\r\n", "Ready", "OK" , "ERROR",5);	
//								sendAT("\r\nAT+GETGPS=\"GNGGA\",1\r\n","Ready", "OK" , "ERROR",5);
								GETGPSDATA();
								sendAT("\r\nAT+MGPSC=1\r\n", "+MGPSSTATUS", "OK" , "ERROR",5);	
								sendAT("\r\nAT+MGPSC?\r\n", "+MGPSSTATUS", "OK" , "ERROR",5);	
//								GETGPSDATA();

//							sendAT("\r\nAT+CIPSHUT\r\n", "OK", "DEACT" , "ERROR",5);
//							sendAT("\r\nAT+CFUN=0\r\n", "CLOSED", "OK" , "ERROR",5);
//							sendAT("\r\nAT+CFUN=1\r\n", "EUSIM", "OK" , "ERROR",5);
//							delay(10);

							sendAT("\r\nAT+CSTT=\"iot.com\"\r\n", "Ready", "OK" , "ERROR",5);	
							sendAT("\r\nAT+CGATT?\r\n", "Ready", "OK" , "ERROR",5);	
							GETGPSDATA();

							sendAT("\r\nAT+CGATT=1\r\n", "Ready", "OK" , "ERROR",5);
							delay(2);
							sendAT("\r\nAT+CIICR\r\n", "Ready", "OK" , "ERROR",5);
							delay(1);
							sendAT("\r\nAT+CIFSR\r\n", "Ready", "OK" , "ERROR",5);	
//								GETGPSDATA();
				
//							GETGPSDATA();
				
				
							sendAT("\r\nAT+CIPMUX=0\r\n", "Ready", "OK" , "ERROR",5);	
							sendAT("\r\nAT+CSQ\r\n", "Ready", "OK" , "ERROR",5);	

								TCPsend();
								intervaltimercount = 0;					

				}
				else if(dataintervalflag == 1)//(intervaltimercount == (0*datainterval) || intervaltimercount == (1*datainterval) || intervaltimercount == (2*datainterval) || intervaltimercount == (3*datainterval) || intervaltimercount == (4*datainterval))
				{
					SLEEP = 0;
					GETGPSDATA();
					dataintervalflag=0;
				}
				else
					{
							if(rep == 0)
								{
//										sendAT("\r\nAT+MGPSC=0\r\n", "+MGPSSTATUS", "OK" , "ERROR",5);	


									sendAT("\r\nAT+CFUN=0\r\n", "OK", "CLOSED" , "ERROR",2);
									SLEEP = 1;
//								delay(5);								
									rep++;		
								}
								SLEEP = 1;

//										sendAT("\r\nAT\r\n", "OK", "CLOSED" , "ERROR",5);
						
								SLEEP = 1;

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







