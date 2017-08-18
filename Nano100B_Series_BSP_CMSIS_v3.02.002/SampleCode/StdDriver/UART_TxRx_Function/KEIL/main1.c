/******************************************************************************
 * @file     main.c
 * @version  V1.00
 * $Revision: 6 $
 * $Date: 14/09/11 5:31p $
 * @brief    Personal Tracking system microcontroller with GSM/GPS combo module.
 *
 * @note
 * Copyright (C) 2013 Nuvoton Technology Corp. All rights reserved.
*****************************************************************************/
#include <string.h>
#include <stdio.h>
#include "Nano100Series.h"
/*----------------------------------------------------------------------------
 * CMSIS-RTOS 'main' function template
 *---------------------------------------------------------------------------*/

#define osObjectsPublic                     // define objects in main module
#include "osObjects.h"                      // RTOS object definitions
#include "uart.h"
#include "cmsis_os.h"               // CMSIS RTOS header file


osMutexDef (uart_mutex);    // Declare mutex
osMutexId  (uart_mutex_id); // Mutex ID
		
osMutexDef (tcp_mutex);    // Declare mutex
osMutexId  (tcp_mutex_id); // Mutex ID

 osMutexDef (fs_mutex);    // Declare mutex
 osMutexId  (fs_mutex_id); // Mutex ID		

extern osThreadId tid_Thread1;                                          // thread id
extern int Init_Thread (void);                   // thread object
extern void Init_Timers (void);
void clear();
extern  int32_t life;
//int32_t parseok=0;
void SendAT(char * command, char * response1, char * response2, char * response3, int32_t timeout);

__inline void Save_FS();
__inline void manualdelay(int delayms);
__inline void Send_FS();
__inline int count_char(char ch,char* string);
__inline void parse_g(char* str, int first, int sec, char f, char s , char *string);
extern void remove_all_chars(char* str, char c, char d);

void TCP_Send(char * tcpcommand,char * tcpdata, char * tcpresponse1, char * tcpresponse2, char * tcpresponse3, int32_t tcptimeout);
void SendAT_GPS(char * command, char * response1, char * response2, char * response3, int32_t timeout);

/*---------------------------------------------------------------------------------------------------------*/
/* Global variables                                                                                        */
/*---------------------------------------------------------------------------------------------------------*/
char g_u8SendData[TXBUFSIZE] = {0};
char g_u8RecData[RXBUFSIZE]  = {0};
int32_t	inc=0;
uint8_t u8InChar=0xFF;
int32_t g_u8RecDataptr=0;
int32_t timer0ticks=0;
int32_t tmr0sec=0;

/* Global variables */
__IO int32_t   _Wakeup_Flag = 0;    /* 1 indicates system wake up from power down mode */
__IO uint32_t  _Pin_Setting[11];    /* store Px_H_MFP and Px_L_MFP */
__IO uint32_t  _PullUp_Setting[6];  /* store GPIOx_PUEN */

char * r1;
char * r2;
char * r3;
volatile uint32_t g_u32comRbytes = 0;
volatile uint32_t g_u32comRhead  = 0;
volatile uint32_t g_u32comRtail  = 0;
volatile int32_t g_bWait         = TRUE;
volatile int32_t g_i32pointer = 0;
char temp[100];
int network=0;
char imei[25];
int imeiptr0=0;
int imeiptr=0;
/*---------------------------------------------------------------------------------------------------------*/
/* Define functions prototype                                                                              */
/*---------------------------------------------------------------------------------------------------------*/
int32_t main(void);
void UART1_TEST_HANDLE(void);
void UART_FunctionTest(void);

void SavePinSetting();
void RestorePinSetting();
void Enter_PowerDown();
void Leave_PowerDown();

void Thread1 (void const *argument);


__inline int count_char(char ch,char* string)
{
int32_t	count=0;
int32_t ass=0;

	for(ass=0;ass<strlen(string);ass++)
	{
		if(string[ass] == ch)
		{count++;}
		
	}
return count;
}







__inline void manualdelay(int delayms)
{
	int delayus=0;
	int d1,d2;
	for(d1 = 0; d1 < delayms ; d1++)
	{
		for(d2=0; d2 < 65535; d2++)
		{
		}
	}
}









void SYS_Init(void)
{
    /*---------------------------------------------------------------------------------------------------------*/
    /* Init System Clock                                                                                       */
    /*---------------------------------------------------------------------------------------------------------*/
    /* Unlock protected registers */
    SYS_UnlockReg();

    /* Enable External XTAL (4~24 MHz) */
    CLK->PWRCTL |= (0x1 << CLK_PWRCTL_HXT_EN_Pos); // HXT Enabled

    /* Waiting for 12MHz clock ready */
    CLK_WaitClockReady( CLK_CLKSTATUS_HXT_STB_Msk);

    /* Switch HCLK clock source to XTAL */
    CLK->CLKSEL0 &= ~CLK_CLKSEL0_HCLK_S_Msk;
    CLK->CLKSEL0 |= CLK_CLKSEL0_HCLK_S_HXT;

    /* Enable IP clock */
    CLK->APBCLK |= CLK_APBCLK_UART0_EN; // UART0 Clock Enable
    CLK->APBCLK |= CLK_APBCLK_UART1_EN; // UART1 Clock Enable

    /* Select IP clock source */
    CLK->CLKSEL1 &= ~CLK_CLKSEL1_UART_S_Msk;
    CLK->CLKSEL1 |= (0x0 << CLK_CLKSEL1_UART_S_Pos);// Clock source from external 12 MHz or 32 KHz crystal clock

    /* Update System Core Clock */
    /* User can use SystemCoreClockUpdate() to calculate PllClock, SystemCoreClock and CycylesPerUs automatically. */
    SystemCoreClockUpdate();
/**************************************************************************************/

//    CLK->PWRCTL |= (0x1 << CLK_PWRCTL_LXT_EN_Pos); // LXT Enable

//    /* Waiting for 12MHz clock ready */
//    CLK_WaitClockReady( CLK_CLKSTATUS_HXT_STB_Msk);
//    /* Waiting for 32KHz clock ready */
//    CLK_WaitClockReady( CLK_CLKSTATUS_LXT_STB_Msk);

//    /* Switch HCLK clock source to XTAL */
//    CLK->CLKSEL0 &= ~CLK_CLKSEL0_HCLK_S_Msk;
//    CLK->CLKSEL0 |= CLK_CLKSEL0_HCLK_S_HXT;

//    /* Select IP clock source */
//    CLK->CLKSEL1 &= ~CLK_CLKSEL1_UART_S_Msk;
//    CLK->CLKSEL1 |= (0x0 << CLK_CLKSEL1_UART_S_Pos);// Clock source from external 12 MHz or 32 KHz crystal clock

//    CLK->CLKSEL1 &= ~CLK_CLKSEL1_LCD_S_Msk;
//    CLK->CLKSEL1 |= (0x0 << CLK_CLKSEL1_LCD_S_LXT);// Clock source from external 12 MHz or 32 KHz crystal clock

//    /* Enable IP clock */
//    CLK->APBCLK |= CLK_APBCLK_UART0_EN; // UART0 Clock Enable
//    CLK->APBCLK |= CLK_APBCLK_LCD_EN;
//    CLK->APBCLK |= CLK_APBCLK_RTC_EN;

//    /* Update System Core Clock */
//    /* User can use SystemCoreClockUpdate() to calculate PllClock, SystemCoreClock and CycylesPerUs automatically. */
//    SystemCoreClockUpdate();



/**************************************************************************************/

    /*---------------------------------------------------------------------------------------------------------*/
    /* Init I/O Multi-function                                                                                 */
    /*---------------------------------------------------------------------------------------------------------*/
    /* Set PB multi-function pins for UART0 RXD and TXD  */
    SYS->PB_L_MFP &= ~(SYS_PB_L_MFP_PB0_MFP_Msk | SYS_PB_L_MFP_PB1_MFP_Msk);
    SYS->PB_L_MFP |= (SYS_PB_L_MFP_PB0_MFP_UART0_RX | SYS_PB_L_MFP_PB1_MFP_UART0_TX);

    /* Set PB multi-function pins for UART1 RXD, TXD, RTS, CTS  */
    SYS->PB_L_MFP &= ~(SYS_PB_L_MFP_PB4_MFP_Msk | SYS_PB_L_MFP_PB5_MFP_Msk );//|
                      // SYS_PB_L_MFP_PB6_MFP_Msk | SYS_PB_L_MFP_PB7_MFP_Msk);
    SYS->PB_L_MFP |= (SYS_PB_L_MFP_PB4_MFP_UART1_RX | SYS_PB_L_MFP_PB5_MFP_UART1_TX); //|
                      //SYS_PB_L_MFP_PB6_MFP_UART1_RTS  | SYS_PB_L_MFP_PB7_MFP_UART1_CTS);

    /* Lock protected registers */
    SYS_LockReg();

}

void UART0_Init()
{
    /*---------------------------------------------------------------------------------------------------------*/
    /* Init UART                                                                                               */
    /*---------------------------------------------------------------------------------------------------------*/
    UART_Open(UART0, 115200);
	  UART_ENABLE_INT(UART0, (UART_IER_RDA_IE_Msk ));
    NVIC_EnableIRQ(UART0_IRQn);
}

void UART1_Init()
{
    UART_Open(UART1, 115200);
}


void Timer_Init()
{
//    //Enable Timer0 clock and select Timer0 clock source
//    CLK_EnableModuleClock(TMR0_MODULE);
//    CLK_SetModuleClock(TMR0_MODULE, CLK_CLKSEL1_TMR0_S_HXT, 0);

//    //Initial Timer0 to periodic mode with 2Hz
//    TIMER_Open(TIMER0, TIMER_PERIODIC_MODE, 2);
//    //Enable Timer0 interrupt
//    TIMER_EnableInt(TIMER0);
//    NVIC_EnableIRQ(TMR0_IRQn);
//    TIMER_Start(TIMER0);
}
void delay(int32_t ms)
{
	int32_t us;
	for(;ms>0;ms--)
	{
		for(us=0;us<100000;us++){}
		
	}
}


int main(void)
{
    SYS_Init();
//		GPIO_SetMode(PA, BIT3, GPIO_PMD_OUTPUT);
//		GPIO_SetMode(PA, BIT4, GPIO_PMD_OUTPUT);
//		GPIO_SetMode(PA, BIT5, GPIO_PMD_OUTPUT);
//		GPIO_SetMode(PA, BIT6, GPIO_PMD_OUTPUT);
		GPIO_SetMode(PB, BIT2, GPIO_PMD_OUTPUT);
    UART0_Init();
    UART1_Init();
//		Timer_Init();
		Init_Timers();
		osKernelInitialize ();                    // initialize CMSIS-RTOS
		uart_mutex_id = osMutexCreate(osMutex(uart_mutex));
		tcp_mutex_id = osMutexCreate(osMutex(tcp_mutex));
		fs_mutex_id = osMutexCreate(osMutex(fs_mutex));
	
		Init_Thread();
		osKernelStart ();                         // start thread execution 
    while(1)
		{
	//		PB2=1;
	//		Enter_PowerDown();
		}
}


/*---------------------------------------------------------------------------------------------------------*/
/* ISR to handle UART Channel 0 interrupt event                                                            */
/*---------------------------------------------------------------------------------------------------------*/
void UART1_IRQHandler(void)
{
  //  UART1_TEST_HANDLE();
}

/*---------------------------------------------------------------------------------------------------------*/
/* UART Callback function                                                                                  */
/*---------------------------------------------------------------------------------------------------------*/

void UART0_IRQHandler(void)
{    
					while(!UART_GET_RX_EMPTY(UART0)) 
					{
            g_u8RecData[g_u8RecDataptr] = UART_READ(UART0);
						g_u8RecDataptr++;
					}

}


__inline void parse_g(char* str, int first, int sec, char f, char s , char *string)
{int sz1,sz2,i11,temp11,j11,l;

		sz1=	strlen(str);
		sz2=  strlen(string);
		memset(string,0,sz2);
		for(i11=0,temp11=0;i11<sz1;i11++)
		{
		if(str[i11]==s)
			{temp11++;j11=i11;}
		else{}
			
		if(temp11>=sec){i11=9900;}
		else{}	
		
		}	
		
		for(i11=0,temp11=0;i11<sz1;i11++)
		{
		if(str[i11]==f)
			{temp11++;l=i11;}										
		else{}
		if(temp11>=first){i11=9900;}else{}
		}	
		for(i11=0;i11<(j11-l-1);i11++)
		{
		string[i11] = str[l+i11+1];
		}
	
}



void SavePinSetting()
{
    /* Save Pin selection setting */
    _Pin_Setting[0] = SYS->PA_L_MFP;
    _Pin_Setting[1] = SYS->PA_H_MFP;
    _Pin_Setting[2] = SYS->PB_L_MFP;
    _Pin_Setting[3] = SYS->PB_H_MFP;
    _Pin_Setting[4] = SYS->PC_L_MFP;
    _Pin_Setting[5] = SYS->PC_H_MFP;
    _Pin_Setting[6] = SYS->PD_L_MFP;
    _Pin_Setting[7] = SYS->PD_H_MFP;
    _Pin_Setting[8] = SYS->PE_L_MFP;
    _Pin_Setting[9] = SYS->PE_H_MFP;
    _Pin_Setting[10] = SYS->PF_L_MFP;

    /* Save Pull-up setting */
    _PullUp_Setting[0] =  PA->PUEN;
    _PullUp_Setting[1] =  PB->PUEN;
    _PullUp_Setting[2] =  PC->PUEN;
    _PullUp_Setting[3] =  PD->PUEN;
    _PullUp_Setting[4] =  PE->PUEN;
    _PullUp_Setting[5] =  PF->PUEN;
}


/**
  * @brief  Restore original setting of multi-function pin selection.
  * @param  None.
  * @return None.
  */
void RestorePinSetting()
{
    /* Restore Pin selection setting */
    SYS->PA_L_MFP = _Pin_Setting[0];
    SYS->PA_H_MFP = _Pin_Setting[1];
    SYS->PB_L_MFP = _Pin_Setting[2];
    SYS->PB_H_MFP = _Pin_Setting[3];
    SYS->PC_L_MFP = _Pin_Setting[4];
    SYS->PC_H_MFP = _Pin_Setting[5];
    SYS->PD_L_MFP = _Pin_Setting[6];
    SYS->PD_H_MFP = _Pin_Setting[7];
    SYS->PE_L_MFP = _Pin_Setting[8];
    SYS->PE_H_MFP = _Pin_Setting[9];
    SYS->PF_L_MFP = _Pin_Setting[10];

    /* Restore Pull-up setting */
    PA->PUEN = _PullUp_Setting[0];
    PB->PUEN = _PullUp_Setting[1];
    PC->PUEN = _PullUp_Setting[2];
    PD->PUEN = _PullUp_Setting[3];
    PE->PUEN = _PullUp_Setting[4];
    PF->PUEN = _PullUp_Setting[5];
}


/**
  * @brief  Save multi-function pin setting and then go to power down.
  * @param  None.
  * @return None.
  */
void Enter_PowerDown()
{
    /* Back up original setting */
    SavePinSetting();

    /* Set function pin to GPIO mode */
    SYS->PA_L_MFP = 0;
    SYS->PA_H_MFP = 0;
    SYS->PB_L_MFP = 0;
    SYS->PB_H_MFP = 0;
    SYS->PC_L_MFP = 0;
    SYS->PC_H_MFP = 0;
    SYS->PD_L_MFP = 0;
    SYS->PD_H_MFP = 0;
    SYS->PE_L_MFP = 0;
    SYS->PE_H_MFP = 0;
    SYS->PF_L_MFP = 0x00007700;

    /* Enable GPIO pull up */
    PA->PUEN = 0xFFFF;
    PB->PUEN = 0xFFFF;
    PC->PUEN = 0xFFFF;
    PD->PUEN = 0xFFFF;
    PE->PUEN = 0xFFFF;
    PF->PUEN = 0x0033;      /* exclude GPF2 and GPF3 which are HXT OUT/IN */

    /* Disable LCD clock */
    CLK->APBCLK &= ~CLK_APBCLK_LCD_EN; /* Disable LCD clock */
    CLK->PWRCTL &= ~CLK_PWRCTL_LXT_EN_Msk; /* disable LXT - 32Khz */

    CLK_PowerDown();

}


/**
  * @brief  This function will not be called.
  * @param  None.
  * @return None.
  */
void Leave_PowerDown()
{

    /* Restore pin setting */
    RestorePinSetting();

    /* Set PF.0 and PF.1 to ICE Data and Clock */
    SYS->PF_L_MFP |= 0x00000077;

    /* Enable LCD clock */
    CLK->PWRCTL |= CLK_PWRCTL_LXT_EN_Msk; /* enable LXT - 32Khz */
    CLK->APBCLK |= CLK_APBCLK_LCD_EN; /* enable LCD clock */

}










void clear()
{
					if(!UART_GET_RX_EMPTY(UART0)) 
					{
            g_u8RecData[g_u8RecDataptr] = UART_READ(UART0);
						g_u8RecDataptr++;
					}
	
}





// end










void SendAT1(char * command, char * response1, char * response2, char * response3, int32_t timeout)
{


//	osMutexWait(uart_mutex_id, osWaitForever);
	tmr0sec=0;
//	timeout =5;

	r1=0;
	r2=0;
	r3=0;
	g_u8RecDataptr=0;
	memset(g_u8RecData,0,RXBUFSIZE);
	printf("%c",0x1A);
	clear();
	printf(command);
	do{
		r1 = strstr(g_u8RecData, response1);
		r2 = strstr(g_u8RecData, response2);
		r3 = strstr(g_u8RecData, response3);
			
	}while(!(r1 || r2 || r3 ||((tmr0sec >= timeout))));   //!(r1 || r2 || r3 ||
//	PB2=1;
//	osMutexRelease(uart_mutex_id);
osDelay(5);
}











void SendAT(char * command, char * response1, char * response2, char * response3, int32_t timeout)
{


	osMutexWait(uart_mutex_id, osWaitForever);
	tmr0sec=0;
//	timeout =5;
	PB2=0;

	r1=0;
	r2=0;
	r3=0;
	g_u8RecDataptr=0;
	memset(g_u8RecData,0,RXBUFSIZE);
	printf("%c",0x1A);
	clear();
	printf(command);
	do{
		r1 = strstr(g_u8RecData, response1);
		r2 = strstr(g_u8RecData, response2);
		r3 = strstr(g_u8RecData, response3);
			
	}while(!(r1 || r2 || r3 ||((tmr0sec >= timeout))));   //!(r1 || r2 || r3 ||
	PB2=1;
	osMutexRelease(uart_mutex_id);
osDelay(5);
}


void TCP_Send(char * tcpcommand,char * tcpdata, char * tcpresponse1, char * tcpresponse2, char * tcpresponse3, int32_t tcptimeout)
{
	int tcpdatalength=0;
	int tcpdataptr=0;
	int times = 0;
	int timesptr=0;
	int tdp=0;
	int tdpend=200;
	osMutexWait(uart_mutex_id, osWaitForever);
	osMutexWait(tcp_mutex_id, osWaitForever);
	PB2=0;
	tmr0sec=0;
	tcptimeout =5;
	r1=0;
	r2=0;
	r3=0;

//	memset(g_u8RecData,0,RXBUFSIZE);
	g_u8RecDataptr=0;
	printf("%c",0x1A);
	tcpdatalength = strlen(tcpdata);
	if(tcpdatalength%200 == 0)
	{
		times = (tcpdatalength/200);
	}
	else
		{
			times = (tcpdatalength/200)+1;
		}
		if(tcpdatalength>25)
		{
			clear();
			for(timesptr = 0; timesptr < times ; timesptr++)
			{
			g_u8RecDataptr=0;
			tmr0sec=0;
			memset(g_u8RecData,0,RXBUFSIZE);
			printf(tcpcommand);
			do{
				r1 = strstr(g_u8RecData, tcpresponse1);
				r2 = strstr(g_u8RecData, tcpresponse2);
				r3 = strstr(g_u8RecData, tcpresponse3);
					
			}while(!(r1 || r2 || r3 ||((tmr0sec >= tcptimeout))));   //!(r1 || r2 || r3 ||

				tmr0sec=0;
			

					if(r1)
					{
						tmr0sec=0;
						tcptimeout =5;
						r1=0;
						r2=0;
						r3=0;
						g_u8RecDataptr=0;
						memset(g_u8RecData,0,RXBUFSIZE);
						clear();
//						printf(tcpdata);
						if(timesptr == (times-1))
						{
							tdpend = tcpdatalength%200;
						}
						for(tdp=0;tdp<tdpend;tdp++)
						{
						SendChar(tcpdata[tcpdataptr]);
						tcpdataptr++;}
						printf("%c",0x1A);

						do{
							r1 = strstr(g_u8RecData, tcpresponse1);
							r2 = strstr(g_u8RecData, tcpresponse2);
							r3 = strstr(g_u8RecData, tcpresponse3);
						}while(!(r1 || r2 || r3 ||((tmr0sec >= tcptimeout))));
					}

			if(!(r3))
			{
				network=1;
				break;
			}
			else
			{
//
				network=0;
			}
		}
	if(network == 0 && timesptr>=times)
	{
		memset(g_u8SendData,0,TXBUFSIZE);
	}
		
	}
	PB2=1;

	osMutexRelease(tcp_mutex_id);
	osMutexRelease(uart_mutex_id);

//osDelay(5);

}



void SendAT_GPS(char * command, char * response1, char * response2, char * response3, int32_t timeout)
{

	osMutexWait(uart_mutex_id, osWaitForever);
//	timeout =5;
	PB2=0;
	osDelay(1000);
	tmr0sec=0;
	r1=0;
	r2=0;
	r3=0;
	g_u8RecDataptr=0;
	memset(g_u8RecData,0,RXBUFSIZE);
	printf("%c",0x1A);
	clear();
	if(strlen(imei)<5)
	{
		printf("\r\nAT+GSN\r\n");
		do{
			r1 = strstr(g_u8RecData, response1);
			r2 = strstr(g_u8RecData, response2);
			r3 = strstr(g_u8RecData, response3);
		}while(!(r1 || r2 || r3 || ((tmr0sec >= timeout))));   //!(r1 || r2 || r3 ||
		memset(imei,0,25);
		imeiptr0=0;
		for(imeiptr=0;imeiptr<strlen(g_u8RecData);imeiptr++)
		{
			if((g_u8RecData[imeiptr]>47)  && (g_u8RecData[imeiptr]<58))
			{
				imei[imeiptr0] = g_u8RecData[imeiptr];
				imeiptr0++;
			}
		}
	remove_all_chars(imei, '\r', 0x1a);		

	}
	tmr0sec=0;
	r1=0;
	r2=0;
	r3=0;
	g_u8RecDataptr=0;
	memset(g_u8RecData,0,RXBUFSIZE);
	clear();
	printf("%c",0x1A);
	printf(command);
	do{
		r1 = strstr(g_u8RecData, response1);
		r2 = strstr(g_u8RecData, response2);
		r3 = strstr(g_u8RecData, response3);
	}while(!(r1 || r2 || r3 || ((tmr0sec >= timeout))));   //!(r1 || r2 || r3 ||
//	strcat(g_u8SendData,"\n");

//	if(strlen(g_u8RecData)<20)
//	{
//		g_u8RecDataptr=0;
//	}
	if(strstr(g_u8RecData,"GNRMC"))
	{
		memset(temp,0,100);
		parse_g(g_u8RecData, 1, 1, ' ', '*' , temp);
//		strcat(g_u8SendData,"\n");
		strcat(g_u8SendData,imei);
		strcat(g_u8SendData,",");
		strcat(temp,"\n");
		strcat(g_u8SendData,temp);
		
			if(strlen(g_u8SendData) > 2500)
			{
					memset(g_u8SendData,0,TXBUFSIZE);
			}
		
		
	}
//	sprintf(temp,"\n%d\n",life);

	PB2=1;

	osMutexRelease(uart_mutex_id);
	osDelay(5);
}













 int qfread(char* fi)
{int32_t charcounts=0;
	osMutexWait(fs_mutex_id, osWaitForever);
		memset(temp,0,100);
		sprintf(temp,"\r\nAT+QFREAD=%s,1000\r\n",fi);
		SendAT(temp, "OK", "OK" , "ERROR",5);	
		charcounts = count_char('\n',g_u8RecData);
		memset(g_u8SendData,0,TXBUFSIZE);
		parse_g(g_u8RecData, 2, charcounts, '\n', '\n' , g_u8SendData);	
		remove_all_chars(g_u8SendData, '\r', 0x1A);		

	osMutexRelease(fs_mutex_id);
	
	if(charcounts <= 3)
	{return 1;}
	else{return 0;}
}



