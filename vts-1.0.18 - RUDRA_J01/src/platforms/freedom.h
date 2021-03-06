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
 *  Abort button configuration
 */
// USE_ABORT_BUTTON             // Uncomment this line if you plan to use PTA4 as an abort button.  

/*
* Input Clock Info
*/
// If you are using CMSIS, CLOCK SETUP must be defined to have the clock proplerly setup. 
//    Refer to System_MKLxxx.c for more information concerning the clock setup.  
#define CLOCK_SETUP     1

// Else.. 
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
   * TERM_PORT_NUM = 0  -- This allows you to use UART0; 
   *						
   *
   * TERM_PORT_NUM = 1  -- This allows you to use UART1; 
   *						
   * 
   * TERM_PORT_NUM = 2  -- This allows you to use UART2; 
   *						
   *
   * Improvements have also been made to allow selection of the terminal
   * port pins can be defined here.  This makes the code much more 
   * efficient.  The definitions are described below:
   *
   * TERM_PIN_PORT - This should be defined as a Pin Port base pointer of 
   *                 the port which the desired UART terminal pins are located.
   * 
   * TERM_RX_PIN   - This should be defined as the pin number on which the RX pin
   *                 is located.  For example, if the desired RX pin is PTA1,
   *                 this parameter should be defined as 1.
   *
   * TERM_TX_PIN   - This should be defined as the pin number on which the TX pin
   *                 is located.  For example, if the desired TX pin is PTA2,
   *                 this parameter should be defined as 2. 
   *
   * TERM_MUX_ALT  - This should be defined as the number of the Port PCR
   *                 mux selection number for the RX and TX pins.  These 
   *                 numbers are listed in the Signal Multiplexing and Pin
   *                 Assignments table in your part specific reference manual. 
   *************************************************************************/

/* Uses UART0 for both Open SDA and TWR-SER Tower card */

#define TERM_PORT_NUM       0
       
#define TERM_PIN_PORT       PORTA_BASE_PTR
#define TERM_RX_PIN         1
#define TERM_TX_PIN         2
#define TERM_MUX_ALT        2

#define TERMINAL_BAUD       115200
#undef  HW_FLOW_CONTROL




#define TERM_PORT_NUM1       1
       
#define TERM_PIN_PORT1       PORTE_BASE_PTR
#define TERM_RX_PIN1         1
#define TERM_TX_PIN1         0
#define TERM_MUX_ALT1        3

#define TERMINAL_BAUD1       115200

#undef  HW_FLOW_CONTROL1



#define TERM_PORT_NUM2       2
       
#define TERM_PIN_PORT2       PORTD_BASE_PTR
#define TERM_RX_PIN2         2
#define TERM_TX_PIN2         3
#define TERM_MUX_ALT2        3

#define TERMINAL_BAUD2       9600
#undef  HW_FLOW_CONTROL2



#endif /* __FREEDOM_H__ */




