
#include "cmsis_os.h"                                           // CMSIS RTOS header file
#include "NUC100Series.h"

/*----------------------------------------------------------------------------
 *      Timer: Sample timer functions
 *---------------------------------------------------------------------------*/
extern int32_t tmr0sec, tmr1sec;
extern int8_t charging;
extern float	u32ADC0Result;
extern float u32ADC0Result1;
extern osMutexId	(uart_mutex_id); // Mutex ID
__inline void batteryind (void);
int8_t time;
int32_t life=0;
int8_t i2ctimeout=0;

/*----- One-Shoot Timer Example -----*/
static void Timer1_Callback (void const *arg);                  // prototype for timer callback function

static osTimerId id1;                                           // timer id
static uint32_t  exec1;                                         // argument for the timer call back function
static osTimerDef (Timer1, Timer1_Callback);                    // define timers

// One-Shoot Timer Function
static void Timer1_Callback (void const *arg) {
  // add user code here
}


/*----- Periodic Timer Example -----*/
static void Timer2_Callback (void const *arg);                  // prototype for timer callback function

static osTimerId id2;                                           // timer id
static uint32_t  exec2;                                         // argument for the timer call back function
static osTimerDef (Timer2, Timer2_Callback);
 
// Periodic Timer Example
static void Timer2_Callback (void const *arg) 
{
	tmr0sec++;
  tmr1sec++;

//	batteryind();
  i2ctimeout++;
  PB13 ^= 1;
	life++;
// add user code here
}


// Example: Create and Start timers
 void Init_Timers (void) {
  osStatus status;                                              // function return status
 
  // Create one-shoot timer
  exec1 = 1;
  id1 = osTimerCreate (osTimer(Timer1), osTimerOnce, &exec1);
  if (id1 != NULL) {    // One-shot timer created
    // start timer with delay 100ms
    status = osTimerStart (id1, 100);            
    if (status != osOK) {
      // Timer could not be started
    }
  }
 
  // Create periodic timer
  exec2 = 2;
  id2 = osTimerCreate (osTimer(Timer2), osTimerPeriodic, &exec2);
  if (id2 != NULL) {    // Periodic timer created
    // start timer with periodic 1000ms interval
    status = osTimerStart (id2, 2000);            
    if (status != osOK) {
      // Timer could not be started
    }
  }
}
 






__inline void batteryind (void)
{
  time++;
  if(time == 1)
  {  
//		PA3=0;
//		PA4=0;
//		PA5=0;
//		PA6=0;
  }
  else
  {
		if( u32ADC0Result > 4.600 )
		{      
 //     PA3=PA4=PA5=PA6^=1;
      //PA3=PA4=PA5=PA6^=1;
		}
		else if( u32ADC0Result < 3.25)
		{
//			PA3^=1;
		//	PA3^=1;
			charging = 0;

			// battery lowest
		}
		else if( u32ADC0Result < 3.50 )
		{
//			PA3^=1;PA4^=1;
		//	PA3^=1;PA4^=1;
			charging = 0;

			//battery lesser
		}
		else if( u32ADC0Result < 3.75)
		{
//			PA3^=1;PA4^=1;PA5^=1;
		//	PA3^=1;PA4^=1;PA5^=1;
			charging = 0;

			//battery less
		}
		else
		{
//			PA3^=1;PA4^=1;PA5^=1;PA6^=1;
		//	PA3^=1;PA4^=1;PA5^=1;PA6^=1;
			charging = 0;
			//battery full
		}
	time=0;
  }
	
}

