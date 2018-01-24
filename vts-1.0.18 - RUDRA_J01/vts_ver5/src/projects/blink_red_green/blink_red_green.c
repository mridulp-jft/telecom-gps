/*
 * File:		blink_red_green.c
 * Purpose:		Main process
 *
 */

#include "common.h"

#ifdef CMSIS
#include "start.h"
#endif

#define DELAY_COUNT 1000000

#define RED 29
#define RED_SHIFT (1U << 29)

#define GREEN 31
#define GREEN_SHIFT (1U << 31)

#define RED_ON (GPIOE_PCOR = RED_SHIFT)
#define RED_OFF (GPIOE_PSOR = RED_SHIFT)
#define RED_TOGGLE (GPIOE_PTOR = RED_SHIFT)

#define GREEN_ON (GPIOE_PCOR = GREEN_SHIFT)
#define GREEN_OFF (GPIOE_PSOR = GREEN_SHIFT)
#define GREEN_TOGGLE (GPIOE_PTOR = GREEN_SHIFT)

void LED_init(void);
void loop_delay(void);


/********************************************************************/
int main (void)
{
    	LED_init();
        
#ifdef CMSIS  // If we are conforming to CMSIS, we need to call start here
    start();
#endif
        
  	printf("\n\r\n\r*** Running the blink_red_green project ***\n\r");

	while(1)
	{
		loop_delay();
		
		RED_TOGGLE;
		GREEN_TOGGLE;
	} 
}
/********************************************************************/

void LED_init(){
  
    SIM_SCGC5 |= SIM_SCGC5_PORTE_MASK;      //Turn on clock to PortE module
    
    PORTE_PCR29 = PORT_PCR_MUX(0x1);          //Set the PTE29 pin multiplexer to GPIO mode
    PORTE_PCR31 = PORT_PCR_MUX(0x1);           //Set the PTE31 pin multiplexer to GPIO mode
    
    GPIOE_PSOR |= RED_SHIFT;                //Set the initial output state to high
    GPIOE_PSOR |= GREEN_SHIFT;               //Set the inital output state to high
    
    GPIOE_PDDR |= RED_SHIFT;                //Set the pin's direction to output
    GPIOE_PDDR |= GREEN_SHIFT;               //Set the pin's direction to output
    
    RED_ON;			//Turn on RED LED
    GREEN_OFF;		//Turn off GREEN LED
	
}

void loop_delay(){
	
	volatile int i;
	
	for(i=0; i < DELAY_COUNT; i++){
				
	}

}
