/*
 * File:        freedom.h
 * Purpose:     Kinetis Freedom hardware definitions
 *
 * Notes:
 */

#ifndef __FREEDOM_H__
#define __FREEDOM_H__

#include "mcg.h"

/********************************************************************/

/* Global defines to use for all Tower cards */
#define DEBUG_PRINT

// Define which CPU  you are using.
#define CPU_MKL26Z128VLH4

/*
* Input Clock Info
*/
#define CLK0_FREQ_HZ        8000000
#define CLK0_TYPE           CRYSTAL

// Uncomment this next line if you desire the clock output
//#define ENABLE_CLKOUT


/*
 * PLL Configuration Info
 */
//#define NO_PLL_INIT  // define this to skip PLL initilaization and stay in default FEI mode

/* The expected PLL output frequency is:
 * PLL out = (((CLKIN/PRDIV) x VDIV) / 2)
 * where the CLKIN is CLK0_FREQ_HZ.
 *
 * For more info on PLL initialization refer to the mcg driver files.
 */

#define PLL0_PRDIV      4       // divider eference by 4 = 2 MHz
#define PLL0_VDIV       24      // multiply reference by 24 = 48 MHz

// Define the FLL reference frequency.  Typically this will be 32.768 kHz,
     //  but may be different if you are not planning on using the Slow IRC.
  #define FLL_REF_FREQ 32768
  // Set DMX32 and DRST_DRS values for default frequencies  
  #define FLL_DMX32       0
  #define FLL_DRST_DRS    0

#define OUTDIV1_VAL     0
#define OUTDIV4_VAL     1

/* Serial Port Info */
/**************************************************************************
   * Note:
   * 
   * Because of the changes to the UART modules, we can no longer define
   * the TERM_PORT as a base pointer.  The uart functions have been modified 
   * accommodate this change.  Now, TERM_PORT_NUM must be defined as the 
   * number of the UART port desired to use
   *
   * TERM_PORT_NUM = 0  -- This allows you to use UART0; default pins are
   *						PTA14 and PTA15
   *
   * TERM_PORT_NUM = 1  -- This allows you to use UART1; default pins are
   *						PTC3 and PTC4
   * 
   * TERM_PORT_NUM = 2  -- This allows you to use UART2; default pins are
   *						PTD2 and PTD3
   *
   *************************************************************************/

/* Uses UART0 for both Open SDA and TWR-SER Tower card */

#define TERM_PORT_NUM       0
       
#define TERM_PIN_PORT       PORTA_BASE_PTR
#define TERM_RX_PIN         1
#define TERM_TX_PIN         2
#define TERM_MUX_ALT        2

#define TERMINAL_BAUD       19200
#undef  HW_FLOW_CONTROL

/* tower module LED defines */
  #define LED0_EN (PORTE_PCR29 = PORT_PCR_MUX(1))
  #define LED1_EN (PORTE_PCR31 = PORT_PCR_MUX(1))
  #define LED2_EN (PORTD_PCR5 = PORT_PCR_MUX(1))
  #define LED3_EN 

  #define LED0_DIR (GPIOE_PDDR |= (1U<<29))
  #define LED1_DIR (GPIOE_PDDR |= (1U<<31))
  #define LED2_DIR (GPIOD_PDDR |= (1U<<5))
  #define LED3_DIR 

  #define LED0_TOGGLE (GPIOE_PTOR = (1U<<29))
  #define LED1_TOGGLE (GPIOE_PTOR = (1U<<31))
  #define LED2_TOGGLE (GPIOD_PTOR = (1U<<5))
  #define LED3_TOGGLE 

  #define LED0_OFF (GPIOE_PSOR = (1U<<29))
  #define LED1_OFF (GPIOE_PSOR = (1U<<31))
  #define LED2_OFF (GPIOD_PSOR = (1U<<5))
  #define LED3_OFF 

  #define LED0_ON (GPIOE_PCOR = (1U<<29))
  #define LED1_ON (GPIOE_PCOR = (1U<<31))
  #define LED2_ON (GPIOD_PCOR = (1U<<5))
  #define LED3_ON 
  /* fast GPIO through IOPORT */
  #define _LED0_TOGGLE (FGPIOE_PTOR = (1U<<29))
  #define _LED1_TOGGLE (FGPIOE_PTOR = (1U<<31))
  #define _LED2_TOGGLE (FGPIOD_PTOR = (1U<<5))
  #define _LED3_TOGGLE 
  //OR
  #define F_LED0_TOGGLE (FGPIOE_PTOR = (1U<<29))
  #define F_LED1_TOGGLE (FGPIOE_PTOR = (1U<<31))
  #define F_LED2_TOGGLE (FGPIOD_PTOR = (1U<<5))
  #define F_LED3_TOGGLE 

  #define F_LED0_OFF (FGPIOE_PSOR = (1U<<29))
  #define F_LED1_OFF (FGPIOE_PSOR = (1U<<31))
  #define F_LED2_OFF (FGPIOD_PSOR = (1U<<5))
  #define F_LED3_OFF 
  
  #define F_LED0_ON (FGPIOE_PCOR = (1U<<29))
  #define F_LED1_ON (FGPIOE_PCOR = (1U<<31))
  #define F_LED2_ON (FGPIOD_PCOR = (1U<<5))
  #define F_LED3_ON 


#endif /* __TOWER_H__ */
