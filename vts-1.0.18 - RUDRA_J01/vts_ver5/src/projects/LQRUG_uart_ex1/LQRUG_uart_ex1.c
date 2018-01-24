/*
 * File:		LQRUG_uart_ex1.c
 * Purpose:		Main process
 *
 */

#include "common.h"

//#undef  TERM_PORT_NUM           0
#undef  TERM_PORT_NUM           

#define POLLING_MODE		1
#define INTERRUPT_MODE	        2

#define UART_MODE		POLLING_MODE //INTERRUPT_MODE POLLING_MODE

// Local function prototypes
void SIM_Init(void);
void PORT_Init(void);
void UART0_Init(void);

// Isr prototypes
#if UART_MODE == INTERRUPT_MODE
void uart0_isr(void);
#endif

// global variables definition
static volatile uint8 c;

/********************************************************************/
int main (void)
{

  printf("\nRunning the LQRUG_uart_ex1 project.\n");

  SIM_Init();
  PORT_Init();
  UART0_Init();
  
  // All interrupts enabled (no need bacause it is already set)
  //asm(" CPSIE i");

  while(1)
  {
#if UART_MODE == POLLING_MODE
    while(!(UART0_S1&UART_S1_RDRF_MASK));
    c = UART0_D;
    while(!(UART0_S1&UART_S1_TDRE_MASK) && !(UART0_S1&UART_S1_TC_MASK));
    UART0_D  = c;
#endif
  } 
}
/********************************************************************/

/***************************************************************************//*!
 * @brief   SIM module initialization.
 ******************************************************************************/
void SIM_Init(void)
{
  SIM_SOPT2 = SIM_SOPT2_UART0SRC(1);
  SIM_SOPT2 &= ~SIM_SOPT2_PLLFLLSEL_MASK;
  SIM_SCGC4 = SIM_SCGC4_UART0_MASK;
  SIM_SCGC5 = SIM_SCGC5_PORTA_MASK;
}

/***************************************************************************//*!
 * @brief   PORT module initialization.
 ******************************************************************************/
void PORT_Init(void)
{
  PORTA_PCR14 = PORT_PCR_ISF_MASK|PORT_PCR_MUX(0x3);
  PORTA_PCR15 = PORT_PCR_ISF_MASK|PORT_PCR_MUX(0x3);
}

/***************************************************************************//*!
 * @brief   UART0 module initialization.
 ******************************************************************************/
void UART0_Init(void)
{
  UART0_C2 &= ~ (UART0_C2_TE_MASK| UART0_C2_RE_MASK);
#if UART_MODE == INTERRUPT_MODE
  enable_irq(12); set_irq_priority(12, 3);
#endif
  /**********************************************************************
   * baud = CLK / [(OSR +1) x BR] 
   * where CLK is baud clock speed in hz, OSR is over sampling ratio, 
   * and BR is baud rate modulo divisor 
   **********************************************************************/
  UART0_BDH = 0x00;
  UART0_BDL = 0x1A; /* BR = 26 */
  UART0_C4 = 0x06; /* OSR = 6 */ //0x0F;  
  UART0_C1 = 0x00;
  UART0_C3 = 0x00;
  UART0_MA1 = 0x00;
  UART0_MA1 = 0x00;
  UART0_S1 |= 0x1F;
  UART0_S2 |= 0xC0;
#if UART_MODE == INTERRUPT_MODE
  UART0_C2 = UART0_C2_RIE_MASK;
#endif
  UART0_C2 |= UART0_C2_TE_MASK| UART0_C2_RE_MASK;
}

/***************************************************************************//*!
 * @brief   UART0 read data register full interrupt service routine.
 ******************************************************************************/
void uart0_isr(void)
{
#if UART_MODE == INTERRUPT_MODE
  if (UART0_S1&UART_S1_RDRF_MASK)
  {
    c = UART0_D;
    if ((UART0_S1&UART_S1_TDRE_MASK)||(UART0_S1&UART_S1_TC_MASK))
    {
    UART0_D  = c;
    }
  }
#endif
}
