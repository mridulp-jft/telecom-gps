/****************************************************************************************************
 *                                                                                                  *                
 *    File:  GPIO_HAL.c                                                                             *
 *   Brief:  GPIO hardware abstraction layer for toggle_LED_color.c                                 *
 *  Author:  Freescale Semiconductor                                                                *
 *           Oak Hill Microcontroller Apps                                                          *
 *           B45635                                                                                 *
 * Version:  0.1                                                                                    *
 *    Date:  May 24, 2013                                                                           *
 *                                                                                                  *
 ****************************************************************************************************/


#include "GPIO_HAL.h"

uint32_t gu32PortStatus = 0;				//Set port status

volatile uint8_t stateCount = 0;		//Set state count to 0 (inital condition)

/*************************************
 ***    Initialize LED GPIO pins   ***
 *************************************/
 
void LED_init(void){
  
    SIM_SCGC5 |= SIM_SCGC5_PORTE_MASK | SIM_SCGC5_PORTD_MASK;      //Turn on clock to PORTE & D module
    
    PORTE_PCR29 = PORT_PCR_MUX(0x1);            //Set the PTE29 pin multiplexer to GPIO mode
    PORTE_PCR31 = PORT_PCR_MUX(0x1);	        //Set the PTE31 pin multiplexer to GPIO mode
    PORTD_PCR5 = PORT_PCR_MUX(0x1);             //Set the PTD5 pin multiplexer to GPIO mode
    
    GPIOE_PSOR |= RED_SHIFT | GREEN_SHIFT;      //Set the initial output state to high
    GPIOD_PSOR |= BLUE_SHIFT;               	//Set the inital output state to high
    
    GPIOE_PDDR |= RED_SHIFT | GREEN_SHIFT;  //Set the pin's direction to output
    GPIOD_PDDR |= BLUE_SHIFT;               //Set the pin's direction to output
    
    RED_OFF;		//Turn off RED LED
    GREEN_OFF;	//Turn off GREEN LED
    BLUE_OFF;		//Turn off BLUE LED
	
}


/************************************
 ***    Initialize SW1 GPIO pin   ***
 ************************************/

void SW1_init(void){

#ifdef CMSIS
	SIM_SCGC5 |= SIM_SCGC5_PORTC_MASK;	//Turn on clock to PORTC module
	
	PORTC_PCR3 = PORT_PCR_IRQC(10)|PORT_PCR_PE_MASK|PORT_PCR_PS_MASK|PORT_PCR_MUX(0x1);	//Configure SW1 for GPIO w/interrupt
	
	enable_irq(PORTD_IRQn);		//PORTD & PORTC share interrupt vector
#else
        
        enable_irq(31);
        set_irq_priority(31, 1);
        
        SIM_SCGC5 |= SIM_SCGC5_PORTC_MASK;	//Turn on clock to PORTC module
        
        PORTC_PCR3 = PORT_PCR_ISF_MASK |PORT_PCR_MUX(0x1)| PORT_PCR_PS_MASK| PORT_PCR_PE_MASK| PORT_PCR_PFE_MASK| PORT_PCR_IRQC(10);
        
#endif
}

#ifdef CMSIS
void PORTD_IRQHandler(void){
  
	if(PORTC_ISFR & (1 << SW_PIN))		//Check for interrupt on PORTC Pin 3
	{
		PORTC_ISFR |= (1 << SW_PIN);
		gu32PortStatus |= (1 << PORTC_EVENT);	//Update port status variable
	}
}

void PORTC_action(void){
        if(PORTC_EVENT_ACK){
			
		stateCount++;     //Increment state counter variable by one
			
		PORTC_CLEAR_EVENT;		//Clear PORTC event status
	}
}
#else
void portc_isr(void){
  
  gu32PortStatus = PORTC_ISFR;
  PORTC_ISFR |= gu32PortStatus;
  stateCount++; 
}
#endif

/************************************
 ***    LED color state machine   ***
 ************************************/

void LED_state(void){
	
#ifdef CMSIS
        PORTC_action();
#endif
			
	switch(stateCount){
	
#ifndef CMSIS
            case 0:     //Red
                   RED_ON;
                   GREEN_OFF;
                   BLUE_OFF;
                   break;
#endif
            case 1:	//Yellow
		               RED_ON;
		               GREEN_ON;
		               BLUE_OFF;
		               break;
				
            case 2:	//Green
		               RED_OFF;
		               GREEN_ON;
		               BLUE_OFF;
		               break;
				
            case 3:	//Blue
		               RED_OFF;
		               GREEN_OFF;
		               BLUE_ON;
		               break;
				
            case 4:	//Violet
		               RED_ON;
		               GREEN_OFF;
		               BLUE_ON;
		               break;
				
            case 5:	//White
		              RED_ON;
		              GREEN_ON;
		              BLUE_ON;
		              break;
				
            default:	//Red
#ifdef CMSIS
		              RED_ON;
		              GREEN_OFF;
		              BLUE_OFF;
		              stateCount = 0;	//Reset state counter
			      break;
#else
                  stateCount = 0;   //Reset state counter
		              break;
#endif
    }
	
}
