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
#include "NUC100Series.h"


#define PLL_CLOCK           12000000



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
    CLK_SetModuleClock(UART0_MODULE, CLK_CLKSEL1_UART_S_HXT, CLK_CLKDIV_UART(1));
    
    /* Enable UART module clock */
    CLK_EnableModuleClock(UART1_MODULE);

    /* Select UART module clock source */
    CLK_SetModuleClock(UART1_MODULE, CLK_CLKSEL1_UART_S_HXT, CLK_CLKDIV_UART(1));
    
    /* Enable UART module clock */
    CLK_EnableModuleClock(UART2_MODULE);

    /* Select UART module clock source */
    CLK_SetModuleClock(UART2_MODULE, CLK_CLKSEL1_UART_S_HXT, CLK_CLKDIV_UART(1));

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
//    SYS_ResetModule(UART0_RST);
//    SYS_ResetModule(UART1_RST);
//    SYS_ResetModule(UART2_RST);

    /* Configure UART0 and set UART0 Baudrate */
    UART_Open(UART0, 115200);
    UART_Open(UART1, 115200);
    UART_Open(UART2, 115200);
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
    /* Init UART0 for printf and testing */
    UARTs_Init();
    /* Lock protected registers */
    SYS_LockReg();
    GPIO_SetMode(PB, BIT7, GPIO_PMD_OUTPUT);
    Init_Thread();
  
		Init_Timers();

    osKernelInitialize ();                    // initialize CMSIS-RTOS

    osKernelStart ();                         // start thread execution 
    
    while(1){
 //     printf("\n\nUART Sample Program\r\n");
//      send_OBD("\r\nHelloWorld\r\n", ">" , ">", ">", 100);
//      UART_WRITE(UART2, 'A');    
 //     SendAT("\r\nAT+QGNSSC=1\r\n\r\n", "OK", "ERROR", "7103", 10);

    }
}
