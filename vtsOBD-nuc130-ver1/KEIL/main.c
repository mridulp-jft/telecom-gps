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


#define PLL_CLOCK           12000000



/*---------------------------------------------------------------------------------------------------------*/
/* Extern variables                                                                                        */
/*---------------------------------------------------------------------------------------------------------*/

extern char suppportedpid[100][7];
extern int pidcounter;

/*---------------------------------------------------------------------------------------------------------*/
/* Global variables                                                                                        */
/*---------------------------------------------------------------------------------------------------------*/
char g_u8SendData[TXBUFSIZE] = {0};
char g_u8RecData[RXBUFSIZE]	= {0};
char g_u8OBDSendData[OBDTXBUFSIZE] = {0};
char g_u8OBDRecData[OBDRXBUFSIZE]	= {0};
uint8_t g_u8OBDRecDataptr=0;

volatile uint32_t g_u32comRbytes = 0;
volatile uint32_t g_u32comRhead  = 0;
volatile uint32_t g_u32comRtail  = 0;
volatile int32_t g_bWait         = TRUE;

/*---------------------------------------------------------------------------------------------------------*/
/* Define functions prototype                                                                              */
/*---------------------------------------------------------------------------------------------------------*/
int32_t main(void);
void UART_TEST_HANDLE(void);
void UART_FunctionTest(void);
/*---------------------------------------------------------------------------------------------------------*/
/* Extern variables                                                                              */
/*---------------------------------------------------------------------------------------------------------*/
extern int32_t g_u8RecDataptr;
extern int Init_Thread (void);
extern void SendAT(char * command, char * response1, char * response2, char * response3, int32_t timeout);
extern void Init_Timers (void);
extern void send_OBD(char * command, char * response1, char * response2, char * response3, int32_t timeout);
extern void supportedpid(char command[5]);


osMutexDef (uart_mutex);		// Declare mutex
osMutexId	(uart_mutex_id); // Mutex ID
		
osMutexDef (tcp_mutex);		// Declare mutex
osMutexId	(tcp_mutex_id); // Mutex ID

osMutexDef (fs_mutex);		// Declare mutex
osMutexId	(fs_mutex_id); // Mutex ID		

void SYS_Init(void)
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

}

void UARTs_Init()
{
    /*---------------------------------------------------------------------------------------------------------*/
    /* Init UART                                                                                               */
    /*---------------------------------------------------------------------------------------------------------*/
    /* Reset UART0 */
    SYS_ResetModule(UART0_RST);
    SYS_ResetModule(UART1_RST);
    SYS_ResetModule(UART2_RST);

    /* Configure UART0 and set UART0 Baudrate */
    UART_Open(UART0, 115200);
    UART_Open(UART1, 115200);
    UART_Open(UART2, 9600);
		UART_ENABLE_INT(UART1, (UART_IER_RDA_IEN_Msk ));
		NVIC_EnableIRQ(UART1_IRQn);  
		UART_ENABLE_INT(UART2, (UART_IER_RDA_IEN_Msk ));
		NVIC_EnableIRQ(UART02_IRQn);  
}

/*---------------------------------------------------------------------------------------------------------*/
/* ISR to handle UART Channel 0 interrupt event                                                            */
/*---------------------------------------------------------------------------------------------------------*/
void UART1_IRQHandler(void)
{
    while(!UART_GET_RX_EMPTY(UART1)) 
    {
      g_u8RecData[g_u8RecDataptr] = UART_READ(UART1);
      g_u8RecDataptr++;
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

/*
 * main: initialize and start the system
 */
int main (void) {

/*---------------------------------------------------------------------------------------------------------*/
/* MAIN function                                                                                           */
/*---------------------------------------------------------------------------------------------------------*/
    /* Unlock protected registers */
    SYS_UnlockReg();
    /* Init System, peripheral clock and multi-function I/O */
    SYS_Init();

    SYS_LockReg();
  
    /* Init UART0 for printf and testing */
    /* Lock protected registers */

  //  Init_Thread();
		uart_mutex_id = osMutexCreate(osMutex(uart_mutex));
		tcp_mutex_id = osMutexCreate(osMutex(tcp_mutex));
		fs_mutex_id = osMutexCreate(osMutex(fs_mutex));  
    Init_Timers();
    osKernelInitialize ();                    // initialize CMSIS-RTOS
    UARTs_Init();
    PA5=0;
    osKernelStart ();                         // start thread execution 

  while(1){

    send_OBD("ATZ\r","HELLO","NODATA",">",5);
    send_OBD("ATE1\r","HELLO","NODATA",">",5);
    send_OBD("ATL1\r","HELLO","NODATA",">",5);
    send_OBD("ATSP0\r","HELLO","NODATA",">",5);
//    send_OBD("ATSP1\r","HELLO","NODATA","WORLD",5);
//    send_OBD("ATSP2\r","HELLO","NODATA","WORLD",5);
//    send_OBD("ATSP3\r","HELLO","NODATA","WORLD",5);
//    send_OBD("ATSP4\r","HELLO","NODATA","WORLD",5);
//    send_OBD("ATSP5\r","HELLO","NODATA","WORLD",5);

//    send_OBD("IAT1\r","HELLO","NODATA",">",5);
    send_OBD("ATDPN\r","HELLO","NODATA",">",5);
    send_OBD("ATRV\r","HELLO","NODATA",">",5);
//    send_OBD("ATIB10\r","HELLO","NODATA",">",5);
    
    
    
   // send_OBD("ATTP0\r","HELLO","NODATA",">",5);
//    send_OBD("ATIB10\r","HELLO","NODATA",">",5);

    send_OBD("0100\r","HELLO","NODATA",">",5);
    send_OBD("0101\r","HELLO","NODATA",">",5);
    send_OBD("010C\r","HELLO","NODATA",">",5);
    send_OBD("010D\r","HELLO","NODATA",">",5);
    send_OBD("0120\r","HELLO","NODATA",">",5);
     }
    memset(suppportedpid, 0, sizeof(char)*200*7);
//   if(!(strstr(g_u8OBDRecData,"UNABLE") || strstr(g_u8OBDRecData,"NO DATA"))){	
      pidcounter=0;
      //supportedpid("0100");
      supportedpid("0100\r\n");
      supportedpid("0120\r\n");
      //supportedpid("0120");
      supportedpid("0140\r\n");
      //supportedpid("0140");
      supportedpid("0160\r\n");
      //supportedpid("0160");
      supportedpid("0180\r\n");
      //supportedpid("0180");
      supportedpid("01A0\r\n");
      //supportedpid("01A0");
      supportedpid("01C0\r\n");
      //supportedpid("01C0");
      supportedpid("050100\r\n");
      //supportedpid("050100");
      supportedpid("0900\r\n");	

    Init_Thread ();

while(1){
}
}