#include <MKL26Z4.h>
#include "gpios.h"
//extren void msg_sim800() ;
extern char ringflag;
extern int sleep_flag;
int send_SOS=0;
uint32_t gu32PortStatus = 0;				//Set port status
volatile uint8_t stateCount;		//Set state count to 0 (inital condition)
#define MASK(x) (1UL << (x))

__inline void RELAY_init(void)
{

    SIM_SCGC5 |= SIM_SCGC5_PORTA_MASK ;      //Turn on clock to PORTE & D module
    PORTA_PCR1 = PORT_PCR_MUX(0x1);            //Set the PTA1 pin multiplexer to GPIO mode
    PORTA_PCR2 = PORT_PCR_MUX(0x1);            //Set the PTA1 pin multiplexer to GPIO mode
	
    GPIOA_PSOR |= IGNITION_SHIFT | FUEL_SHIFT;      //Set the initial output state to high	
    GPIOA_PDDR |= IGNITION_SHIFT | FUEL_SHIFT;  //Set the pin's direction to output	
	
IGNITION_ON;
FUEL_ON;
	
}


__inline void LED_init(void){
  
    SIM_SCGC5 |= SIM_SCGC5_PORTE_MASK | SIM_SCGC5_PORTB_MASK | SIM_SCGC5_PORTD_MASK | SIM_SCGC5_PORTC_MASK ;      //Turn on clock to PORTE & D module


	

		PORTE_PCR29 = PORT_PCR_MUX(0x1);            //Set the PTE29 pin multiplexer to GPIO mode
  	PORTD_PCR7 = PORT_PCR_MUX(0x1);            //Set the PTE29 pin multiplexer to GPIO mode
    PORTE_PCR31 = PORT_PCR_MUX(0x1);	        //Set the PTE31 pin multiplexer to GPIO mode
    PORTD_PCR5 = PORT_PCR_MUX(0x1);             //Set the PTD5 pin multiplexer to GPIO mode
	
    PORTC_PCR5 = PORT_PCR_MUX(0x1);            //Set the PTE29 pin multiplexer to GPIO mode
    PORTC_PCR6 = PORT_PCR_MUX(0x1);	        //Set the PTE31 pin multiplexer to GPIO mode
    PORTC_PCR7 = PORT_PCR_MUX(0x1);             //Set the PTD5 pin multiplexer to GPIO mode	
    PORTC_PCR8 = PORT_PCR_MUX(0x1);             //Set the PTD5 pin multiplexer to GPIO mode	    
    PORTB_PCR2 = PORT_PCR_MUX(0x1);             //Set the PTB2 pin multiplexer to GPIO mode	   

	
	PORTB_PCR2 = PORT_PCR_MUX(0x1)| PORT_PCR_PE_MASK | PORT_PCR_PS_SHIFT; //		GPIOB_PDDR = 0;
		
	PORTB_PCR1 = PORT_PCR_MUX(0x1)| PORT_PCR_PE_MASK | PORT_PCR_PS_SHIFT; //		GPIOB_PDDR = 0;
//		GPIOB_PCOR |= ADCIGN_SHIFT 	;			//set initial input stage 0;
	PTB->PDDR &= ~MASK(ADCIGN);
	GPIOD_PDDR |= (1<<7);

	PORTB_PCR0 = PORT_PCR_MUX(0x1)| PORT_PCR_PE_MASK | PORT_PCR_PS_SHIFT; //		GPIOB_PDDR = 0;
	PORTC_PCR0 = PORT_PCR_MUX(0x1)| PORT_PCR_PE_MASK | PORT_PCR_PS_MASK; //		GPIOB_PDDR = 0;

//		GPIOB_PCOR |= ADCIGN_SHIFT 	;			//set initial input stage 0;
	//PTB->PDDR &= ~MASK(ADCIGN);
//	GPIOD_PDDR |= (1<<7);

	  
    GPIOE_PSOR |= RED_SHIFT | GREEN_SHIFT;      //Set the initial output state to high
    GPIOD_PSOR |= BLUE_SHIFT;               	//Set the inital output state to high
		GPIOC_PSOR |= REDBAT_SHIFT | BLUEBAT_SHIFT | GREENBAT_SHIFT; 
		GPIOC_PSOR |= RESET_SHIFT;
    
    GPIOE_PDDR |= RED_SHIFT | GREEN_SHIFT;  //Set the pin's direction to output
    GPIOD_PDDR |= BLUE_SHIFT;               //Set the pin's direction to output
		GPIOC_PDDR |= REDBAT_SHIFT | BLUEBAT_SHIFT | GREENBAT_SHIFT | RESET_SHIFT; 
    
    RED_ON;		//Turn off RED LED
    GREEN_ON;	//Turn off GREEN LED
    BLUE_ON;		//Turn off BLUE LED
		REDBAT_ON;
		GREENBAT_ON;
		BLUEBAT_ON;
		RESET_ON;
		
	
}



/************************************
 ***    Initialize SW1 GPIO pin   ***
 ************************************/

void SW1_init(void){

#ifdef CMSIS
	SIM_SCGC5 |= SIM_SCGC5_PORTC_MASK;	//Turn on clock to PORTC module
	
	PORTC_PCR3 = PORT_PCR_IRQC(10)|PORT_PCR_PE_MASK|PORT_PCR_PS_SHIFT|PORT_PCR_MUX(0x1);	//Configure SW1 for GPIO w/interrupt
	
	SIM_SCGC5 |= SIM_SCGC5_PORTD_MASK;	//Turn on clock to PORTD module
	
	PORTD_PCR6 = PORT_PCR_IRQC(10)|PORT_PCR_PE_MASK|PORT_PCR_PS_MASK|PORT_PCR_MUX(0x1);	//Configure SW1 for GPIO w/interrupt
	
	PORTD_PCR0 = PORT_PCR_IRQC(10)|PORT_PCR_PE_MASK|PORT_PCR_PS_SHIFT|PORT_PCR_MUX(0x1);	//Configure SW1 for GPIO w/interrupt
	
	
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
ringflag=1;
send_SOS=1;	
/**************ISR follows******/	
 stateCount++;
	}
	
	if(PORTD_ISFR & (1 << 0))		//Check for interrupt on PORTD Pin 6
	{
		PORTD_ISFR |= (1 << 0);
		gu32PortStatus |= (1 << PORTD_EVENT);	//Update port status variable
	
/**************ISR follows******/	
// stateCount++;
ringflag=1;
send_SOS=1;		

	// wakeup and reset
	
clear();	
	}	
	
	
	
	
	if(PORTD_ISFR & (1 << 6))		//Check for interrupt on PORTD Pin 6
	{
		PORTD_ISFR |= (1 << 6);
		gu32PortStatus |= (1 << PORTD_EVENT);	//Update port status variable
	
/**************ISR follows******/	
// stateCount++;
		
ringflag=1;
	// wakeup and reset
	
clear();	
	}
	
	LED_state();
}

void PORTC_action(void){
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
if(sleep_flag == 1)
{stateCount=99;
}	
			
	switch(stateCount){

		
            case 0:     //Red
                   REDBAT_ON;
                   GREENBAT_OFF;
                   BLUEBAT_OFF;
                   break;

            case 1:	//Yellow
		               REDBAT_ON;
		               GREENBAT_ON;
		               BLUEBAT_OFF;
		               break;
				
            case 2:	//Green
		               REDBAT_OFF;
		               GREENBAT_ON;
		               BLUEBAT_OFF;
		               break;
				
            case 3:	//Blue
		               REDBAT_OFF;
		               GREENBAT_OFF;
		               BLUEBAT_ON;
		               break;
				
            case 4:	//Violet
		               REDBAT_ON;
		               GREENBAT_OFF;
		               BLUEBAT_ON;
		               break;
				
            case 5:	//White
		              REDBAT_ON;
		              GREENBAT_ON;
		              BLUEBAT_ON;
		              break;
				
            default:	//Red
							

		              REDBAT_OFF;
		              GREENBAT_OFF;
		              BLUEBAT_OFF;
		              stateCount = 0;	//Reset state counter
			      break;

    }
	
}


void LED_state2(void)
{
if(sleep_flag == 1)
{stateCount=99;
}	
			
	switch(stateCount){
	

            case 0:     //Red
                   RED_ON;
                   GREEN_OFF;
                   BLUE_OFF;
                   break;

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

		              RED_OFF;
		              GREEN_OFF;
		              BLUE_OFF;
		              stateCount = 0;	//Reset state counter
			      break;

    }
	
}











//  int process0(void)
//	{
//										 RED_ON;
//										 GREEN_OFF;
//										 BLUE_OFF;
//		return 0;
//	}
//	int process1(void)
//	{
//										 RED_ON;
//										 GREEN_ON;
//										 BLUE_OFF;
//		return 0;
//	}
//	int process2(void)
//	{
//										 RED_OFF;
//										 GREEN_ON;
//										 BLUE_OFF;
//		return 0;
//	}
//	int process3(void)
//	{
//										 RED_OFF;
//										 GREEN_OFF;
//										 BLUE_ON;
//		return 0;
//	}
//	int process4(void)
//	{
//										 RED_ON;
//										 GREEN_OFF;
//										 BLUE_ON;
//		return 0;
//		
//	}
//	int process5(void)
//	{
//										RED_ON;
//										GREEN_ON;
//										BLUE_ON;
//		return 0;
//	}
//	int processdef(void)
//	{
//										RED_ON;
//										GREEN_OFF;
//										BLUE_OFF;
//										stateCount = -1;

//		return 0;
//	}  

//	void test12()
//	{
//	int (* processfunc[])	() = {process0,process1,process2,process3,process4,process5,processdef};
//	processfunc[stateCount]();
//	}


