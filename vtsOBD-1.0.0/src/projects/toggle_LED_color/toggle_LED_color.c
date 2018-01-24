/****************************************************************************************************
 *                                                                                                  *                
 *    File:  toggle_LED_color.c                                                                     *
 *   Brief:  Demonstrates GPIO interrupts. LED cycles through various colors when SW is pressed.    *
 *  Author:  Freescale Semiconductor                                                                *
 *           Oak Hill Microcontroller Apps                                                          *
 *           B45635                                                                                 *
 * Version:  0.1                                                                                    *
 *    Date:  May 24, 2013                                                                           *
 *                                                                                                  *
 ****************************************************************************************************/

#include "common.h"
#include "GPIO_HAL.h"
#include "isr.h"

#ifdef CMSIS
#include "start.h"
#endif

/********************************************************************/
int main (void)
{
    	
	LED_init();		//Initialize GPIO for LEDs
	SW1_init();		//Initialize GPIO for SW1 w/ interrupt
        
#ifdef CMSIS  // If we are conforming to CMSIS, we need to call start here
    start();
#endif
        
  	printf("\n\r\n\r*** Running the toggle_LED_color project ***\n\r");
	
	while(1)
	{

            LED_state();		//Enable LED state machine
			
	} 
}
/********************************************************************/
