/****************************************************************************************************/
/**
Copyright (c) 2008 Freescale Semiconductor
Freescale Confidential Proprietary
\file       TWR_AUDIO_Loopback.c
\brief
\author     Freescale Semiconductor
\author     Guadalajara Applications Laboratory RTAC Americas
\author     B22385
\version    0.1
\date       Jun 18, 2012
*/
/****************************************************************************************************/
/*                                                                                                  */
/* All software, source code, included documentation, and any implied know-how are property of      */
/* Freescale Semiconductor and therefore considered CONFIDENTIAL INFORMATION.                       */
/* This confidential information is disclosed FOR DEMONSTRATION PURPOSES ONLY.                      */
/*                                                                                                  */
/* All Confidential Information remains the property of Freescale Semiconductor and will not be     */
/* copied or reproduced without the express written permission of the Discloser, except for copies  */
/* that are absolutely necessary in order to fulfill the Purpose.                                   */
/*                                                                                                  */
/* Services performed by FREESCALE in this matter are performed AS IS and without any warranty.     */
/* CUSTOMER retains the final decision relative to the total design and functionality of the end    */
/* product.                                                                                         */
/* FREESCALE neither guarantees nor will be held liable by CUSTOMER for the success of this project.*/
/*                                                                                                  */
/* FREESCALE disclaims all warranties, express, implied or statutory including, but not limited to, */
/* implied warranty of merchantability or fitness for a particular purpose on any hardware,         */
/* software ore advise supplied to the project by FREESCALE, and or any product resulting from      */
/* FREESCALE services.                                                                              */
/* In no event shall FREESCALE be liable for incidental or consequential damages arising out of     */
/* this agreement. CUSTOMER agrees to hold FREESCALE harmless against any and all claims demands or */
/* actions by anyone on account of any damage,or injury, whether commercial, contractual, or        */
/* tortuous, rising directly or indirectly as a result of the advise or assistance supplied CUSTOMER*/
/* in connectionwith product, services or goods supplied under this Agreement.                      */
/*                                                                                                  */
/****************************************************************************************************/

/*****************************************************************************************************
* Include files
*****************************************************************************************************/
#include "ProjectTypes.h"
#include "GPIO_HAL.h"
#include "SGTL5000.h"
#include "Audio_Buffer_Handler.h"
#include "TWR_AUDIO_Loopback.h"

/*****************************************************************************************************
* Declaration of module wide FUNCTIONs - NOT for use in other modules
*****************************************************************************************************/
void vfnTWRAudioStateIdle (void);
void vfnTWRAudioStateWaitCodec (void);
void vfnTWRAudioStateLoopback (void);
void vfnTWRAudioStateChangeEQ (void);

void (* const vfnapTWRAudio[]) (void) =
{
		vfnTWRAudioStateIdle,
		vfnTWRAudioStateWaitCodec,
		vfnTWRAudioStateLoopback,
		vfnTWRAudioStateChangeEQ
};
/*****************************************************************************************************
* Definition of module wide MACROs / #DEFINE-CONSTANTs - NOT for use in other modules
*****************************************************************************************************/
#define TWR_AUDIO_CHECK_STATUS(x)	(u32TWRAudioStatus&(1<<TWR_AUDIO_CODEC_READY))

/*****************************************************************************************************
* Declaration of module wide TYPEs - NOT for use in other modules
*****************************************************************************************************/
typedef enum
{
	TWR_AUDIO_IDLE_STATE = 0,
	TWR_AUDIO_WAIT_CODEC_STATE,
	TWR_AUDIO_LOOPBACK_STATE,
	TWR_AUDIO_CHANGEEQ_STATE
}eTWRAudioStates;
/*****************************************************************************************************
* Definition of module wide VARIABLEs - NOT for use in other modules
*****************************************************************************************************/
u32 gau32SamplesBuffer[96];

sSM sTWRAudioStateMachine;

/*****************************************************************************************************
* Definition of module wide (CONST-) CONSTANTs - NOT for use in other modules
*****************************************************************************************************/
const u16 u16BandEQRegisters[5] =
{
		SGTL5000_BAND_0,
		SGTL5000_BAND_1,
		SGTL5000_BAND_2,
		SGTL5000_BAND_3,
		SGTL5000_BAND_4,
};

const u16 u16BandEQEnableValues[5] =
{
		0x4F,	//+8dB
		0x1D,	//-4.5dB
		0x4A,	//+6.75dB
		0x17,	//-6dB
		0x5F,	//+12dB
};
const u16 u16BandEQDisableValues[5] =
{
		0x2F,	//0dB
		0x2F,	//0dB
		0x2F,	//0dB
		0x2F,	//0dB
		0x2F	//0dB
};
/*****************************************************************************************************
* Code of project wide FUNCTIONS
*****************************************************************************************************/
/*!
      \fn vfnTWRAudioInit
      \brief  Initializes the application state machine and proper modules
      \param  none
      \return void
*/
void vfnTWRAudioInit(void)
{
	vfnGPIO_Init();
	u32fnAudioBufferHandler_Init();
	vfnSGTLInit();
	sTWRAudioStateMachine.ActualState = TWR_AUDIO_WAIT_CODEC_STATE;
	sTWRAudioStateMachine.NextState = TWR_AUDIO_IDLE_STATE;
}
/*!
      \fn vfnTWRAudioStateIdle
      \brief  IDLE state. Checks for buffer events and port events
      \param  none
      \return void
*/
void vfnTWRAudioStateIdle (void)
{
	/* wait for the buffer layer to ack a new packet */
	if(AUDIO_BUFFER_HANDLER_CHECK_STATUS(AUDIO_BUFFER_HANDLER_TX_COMPLETE))
	{
		sTWRAudioStateMachine.ActualState = TWR_AUDIO_LOOPBACK_STATE;
		sTWRAudioStateMachine.NextState = TWR_AUDIO_IDLE_STATE;
	}
	/* change the GEQ settings */
	/* Make sure if there was a buffer request, do it after that */
	if(PORTA_EVENT_ACK)
	{
		if(sTWRAudioStateMachine.ActualState != TWR_AUDIO_IDLE_STATE)
		{
			sTWRAudioStateMachine.NextState = TWR_AUDIO_CHANGEEQ_STATE;
		}
		else
		{
			sTWRAudioStateMachine.ActualState = TWR_AUDIO_CHANGEEQ_STATE;
		}
		PORTA_CLEAR_EVENT;
	}
}
/*!
      \fn vfnTWRAudioStateWaitCodec
      \brief  Waits for the codec to finishes its process
      \param  none
      \return void
*/
void vfnTWRAudioStateWaitCodec (void)
{
	/* wait for the codec driver */
	if(!SGTL5000_CHECK_STATUS(SGTL5000_STATUS_BUSY))
	{
		sTWRAudioStateMachine.PrevState = sTWRAudioStateMachine.ActualState;
		sTWRAudioStateMachine.ActualState = sTWRAudioStateMachine.NextState;
	}

}
/*!
      \fn vfnTWRAudioStateLoopback
      \brief  Reads from the audio buffer to the application buffer and send it back
      \param  none
      \return void
*/
void vfnTWRAudioStateLoopback (void)
{	
	/* clear the status flag and do the loopback*/
	/* the status flags always needs to be cleared BEFORE calling the read or write functions */
	/*takes the data received from I2S Rx (Line in) and sends it to I2S Tx (Line out)*/
	AUDIO_BUFFER_HANDLER_CLEAR_STATUS(AUDIO_BUFFER_HANDLER_TX_COMPLETE);

	vfnAudioBufferHandler_ReadBuffer(&gau32SamplesBuffer[0],(u16)96);
	vfnAudioBufferHandler_WriteBuffer((u32 *)&gau32SamplesBuffer[0],(u16)96);

	sTWRAudioStateMachine.ActualState = sTWRAudioStateMachine.NextState;
}
/*!
      \fn vfnTWRAudioStateChangeEQ
      \brief  Changes the volume of the GEQ bands
      \param  none
      \return void
*/
void vfnTWRAudioStateChangeEQ (void)
{
	static u8 u8EQStatus = 0;
	static u8 u8BandIndex = 0;

	/* change the volume for the 5 bands of the GEQ */
	if(u8BandIndex < 5 )
	{
		/* select to enable/disable it */
		if(!u8EQStatus)
		{
			vfnSGTL5000ChangeGEQVolume(u16BandEQRegisters[u8BandIndex],u16BandEQEnableValues[u8BandIndex]);
		}
		else
		{
			vfnSGTL5000ChangeGEQVolume(u16BandEQRegisters[u8BandIndex],u16BandEQDisableValues[u8BandIndex]);
		}
		u8BandIndex++;
		sTWRAudioStateMachine.ActualState = TWR_AUDIO_WAIT_CODEC_STATE;
		sTWRAudioStateMachine.NextState = TWR_AUDIO_CHANGEEQ_STATE;
	}
	else
	{
		u8EQStatus ^= 1;
		u8BandIndex = 0;
		sTWRAudioStateMachine.ActualState = TWR_AUDIO_IDLE_STATE;
	}

}
