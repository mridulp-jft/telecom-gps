/*
 * File:		SAI_Loopback_Keil.c
 * Purpose:		Main process
 *
 */

#include "common.h"
#include "IIC_HAL.h"
#include "SGTL5000.h"
#include "Audio_Buffer_Handler.h"
#include "TWR_AUDIO_Loopback.h"
#ifdef CMSIS
#include "start.h"
#endif

/********************************************************************/
int main (void)
{
        
#ifdef CMSIS  // If we are conforming to CMSIS, we need to call start here
    start();
#endif
        
	vfnTWRAudioInit();

	while(1)
	{
		vfnapTWRAudio[sTWRAudioStateMachine.ActualState]();
		vfnapIICDriver[sIICStateMachine.ActualState]();
		vfnapSGTL5000ControlStateMachine[sSGTL5000ControlStateMachine.ActualState]();
	}  
}
/********************************************************************/
