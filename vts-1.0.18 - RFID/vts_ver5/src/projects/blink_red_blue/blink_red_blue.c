/*
 * File:		blink_red_blue.c
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

#define BLUE 5
#define BLUE_SHIFT (1U << 5)

#define RED_ON (GPIOE_PCOR = RED_SHIFT)
#define RED_OFF (GPIOE_PSOR = RED_SHIFT)
#define RED_TOGGLE (GPIOE_PTOR = RED_SHIFT)

#define BLUE_ON (GPIOD_PCOR = BLUE_SHIFT)
#define BLUE_OFF (GPIOD_PSOR = BLUE_SHIFT)
#define BLUE_TOGGLE (GPIOD_PTOR = BLUE_SHIFT)

void LED_init(void);
void loop_delay(void);


/********************************************************************/
int main (void)
{
    	LED_init();
        
#ifdef CMSIS  // If we are conforming to CMSIS, we need to call start here
    start();
#endif
        
  	printf("\n\r\n\r*** Running the blink_red_blue project ***\n\r");

	while(1)
	{
		loop_delay();
		
		RED_TOGGLE;
		BLUE_TOGGLE;
	} 
}
/********************************************************************/

void LED_init(){
  
    SIM_SCGC5 |= SIM_SCGC5_PORTE_MASK | SIM_SCGC5_PORTD_MASK;      //Turn on clock to PortE & D module
    
    PORTE_PCR29 = PORT_PCR_MUX(0x1);          //Set the PTE29 pin multiplexer to GPIO mode
    PORTD_PCR5 = PORT_PCR_MUX(0x1);           //Set the PTD5 pin multiplexer to GPIO mode
    
    GPIOE_PSOR |= RED_SHIFT;                //Set the initial output state to high
    GPIOD_PSOR |= BLUE_SHIFT;               //Set the inital output state to high
    
    GPIOE_PDDR |= RED_SHIFT;                //Set the pin's direction to output
    GPIOD_PDDR |= BLUE_SHIFT;               //Set the pin's direction to output
    
    RED_ON;			//Turn on RED LED
    BLUE_OFF;		//Turn off BLUE LED
	
}

void loop_delay(){
	
	volatile int i;
	
	for(i=0; i < DELAY_COUNT; i++){
				
	}

}
