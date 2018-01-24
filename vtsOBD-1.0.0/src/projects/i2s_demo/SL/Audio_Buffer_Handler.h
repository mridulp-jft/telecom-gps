/****************************************************************************************************/
/**
Copyright (c) 2008 Freescale Semiconductor
Freescale Confidential Proprietary
\file       Audio_Buffer_Handler.h
\brief
\author     Freescale Semiconductor
\author     Guadalajara Applications Laboratory RTAC Americas
\author     b22385
\version    0.1
\date       Jun 1, 2012
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
* Module definition against multiple inclusion
*****************************************************************************************************/

#ifndef AUDIO_BUFFER_HANDLER_H_
#define AUDIO_BUFFER_HANDLER_H_
/*****************************************************************************************************
* Include files
*****************************************************************************************************/


/*****************************************************************************************************
* Declaration of project wide TYPES
*****************************************************************************************************/
typedef enum
{
	AUDIO_BUFFER_HANDLER_TX_COMPLETE = 0,
	AUDIO_BUFFER_HANDLER_RX_COMPLETE,
	AUDIO_BUFFER_HANDLER_TX_STARTED,
	AUDIO_BUFFER_HANDLER_RX_STARTED
}eAudioBufferHandlerStatus;

/*****************************************************************************************************
* Definition of project wide VARIABLES
*****************************************************************************************************/
extern u32 gu32AudioBufferHandlerStatus;
/*****************************************************************************************************
* Definition of project wide MACROS / #DEFINE-CONSTANTS
*****************************************************************************************************/


#define AUDIO_BUFFER_HANDLER_MS	(10)

#define AUDIO_BUFFER_HANDLER_SAMPLING_RATE_48	(48)
#define AUDIO_BUFFER_HANDLER_SAMPLING_RATE_44_1	(44)
#define AUDIO_BUFFER_HANDLER_SAMPLING_RATE_32	(32)

#define AUDIO_BUFFER_HANDLER_SYSTEM_SAMPLING_RATE	(AUDIO_BUFFER_HANDLER_SAMPLING_RATE_48)

#define AUDIO_BUFFER_HANDLER_DMA_OUT	(DMA_CHANNEL_0)

#define AUDIO_BUFFER_HANDLER_DMA_IN	(DMA_CHANNEL_1)
#ifdef MCU_MK60N512VMD100
	#define AUDIO_BUFFER_HANDLER_DMA_OUT_2	(DMA_CHANNEL_1)
#define AUDIO_BUFFER_HANDLER_DMA_IN_2	(DMA_CHANNEL_3)
#endif


#define AUDIO_BUFFER_HANDLER_CHECK_STATUS(x) (gu32AudioBufferHandlerStatus & (1 << (x)) )
#define AUDIO_BUFFER_HANDLER_SET_STATUS(x)	 (gu32AudioBufferHandlerStatus |= (1 << (x)) )
#define AUDIO_BUFFER_HANDLER_CLEAR_STATUS(x) (gu32AudioBufferHandlerStatus &= ~(1 << (x)) )
/*****************************************************************************************************
* Declaration of project wide FUNCTIONS
*****************************************************************************************************/

/*****************************************************************************************************
* Declaration of module wide FUNCTIONs - NOT for use in other modules
*****************************************************************************************************/
void u32fnAudioBufferHandler_Init (void);
void vfnAudioBufferHandler_WriteBuffer16to24(u16 * pu16BufferInput, u16 u16DataSize);
void vfnAudioBufferHandler_WriteBuffer(u32 * pu32BufferInput, u16 u16DataSize);
void vfnAudioBufferHandler_ReadBuffer(u32 * pu32Buffer, u16 u16DataSize);
void vfnAudioBufferHandler_WriteBuffer16to32(u16 * pu16BufferInput, u16 u16DataSize);
#endif /*AUDIO_BUFFER_HANDLER_H_*/

