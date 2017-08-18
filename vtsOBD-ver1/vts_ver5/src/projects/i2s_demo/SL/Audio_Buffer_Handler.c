/****************************************************************************************************/
/**
Copyright (c) 2008 Freescale Semiconductor
Freescale Confidential Proprietary
\file       Audio_Buffer_Handler.c
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
* Include files
*****************************************************************************************************/
#include "ProjectTypes.h"
#include "common.h"
#include "DMA.h"
#include "I2S.h"
#include "RingBuffer.h"
#include "Audio_Buffer_Handler.h"
/*****************************************************************************************************
* Declaration of module wide FUNCTIONs - NOT for use in other modules
*****************************************************************************************************/
void vfnAudioBufferHandler_DMATxCallback (void);
void vfnAudioBufferHandler_DMARxCallback (void);
/*****************************************************************************************************
* Definition of module wide MACROs / #DEFINE-CONSTANTs - NOT for use in other modules
*****************************************************************************************************/

/*****************************************************************************************************
* Declaration of module wide TYPEs - NOT for use in other modules
*****************************************************************************************************/
/*!
    \def AUDIO_OUTPUT_RING_BUFFER_SIZE
    \brief Compute the buffer size with the sampling rate, channels and amount of audio to buffer
*/
#define AUDIO_OUTPUT_RING_BUFFER_SIZE	(1024)
/*!
    \def AUDIO_INPUT_RING_BUFFER_SIZE
    \brief Compute the buffer size with the sampling rate, channels and amount of audio to buffer
*/
#define AUDIO_INPUT_RING_BUFFER_SIZE	(1024)
/*!
    \def AUDIO_OUT_RING_BUFFER_HALF_FILL
    \brief Calculate the mid point on the Tx buffer
*/
#define AUDIO_OUT_RING_BUFFER_HALF_FILL	(AUDIO_OUTPUT_RING_BUFFER_SIZE/2)
/*!
    \def AUDIO_IN_RING_BUFFER_HALF_FILL
    \brief Calculate the mid point on the Rx buffer
*/
#define AUDIO_IN_RING_BUFFER_HALF_FILL	(AUDIO_INPUT_RING_BUFFER_SIZE/2)
/*!
    \def DMA_DATA_BYTE_COUNT
    \brief sampling rate * 4 bytes * 2 channels
*/
#define DMA_DATA_BYTE_COUNT	(AUDIO_BUFFER_HANDLER_SYSTEM_SAMPLING_RATE*8)
/*****************************************************************************************************
* Definition of module wide VARIABLEs - NOT for use in other modules
*****************************************************************************************************/
/*!
    \var gau32Audio_OutputRingBuffer
    \brief Array to be implemented as ring buffer for Tx
*/
__align(4096) u32 gau32Audio_OutputRingBuffer[AUDIO_OUTPUT_RING_BUFFER_SIZE];
/*!
    \var gau32Audio_InputRingBuffer
    \brief Array to be implemented as ring buffer for Rx
*/
__align(4096) u32 gau32Audio_InputRingBuffer[AUDIO_INPUT_RING_BUFFER_SIZE];
/*!
    \var gu32Audio_OutRingBufferFillThreshold
    \brief Current status of buffer threshold to start Tx
*/
static u32 gu32Audio_OutRingBufferFillThreshold = 0;
/*!
    \var gu32Audio_InRingBufferFillThreshold
    \brief Current status of buffer threshold to start Rx
*/
static u32 gu32Audio_InRingBufferFillThreshold = 0;
/*!
    \var gu32AudioBufferHandlerStatus
    \brief Buffer handler status
*/
u32 gu32AudioBufferHandlerStatus = 0;
/*!
    \var sAudio_OutputRingBuffer
    \brief Tx ring buffer
*/
sRingBuffer sAudio_OutputRingBuffer;
/*!
    \var sAudio_InputRingBuffer
    \brief Rx ring buffer
*/
sRingBuffer sAudio_InputRingBuffer;
/*!
    \var sAudio_OutDMACh0
    \brief Tx DMA channel configuration
*/
stcd_DMA sAudio_OutDMACh0;
/*!
    \var sAudio_InDMACh0
    \brief Rx DMA channel configuration
*/
stcd_DMA sAudio_InDMACh0;

volatile u32 gu32ISRCounter = 0;

/*****************************************************************************************************
* Definition of module wide (CONST-) CONSTANTs - NOT for use in other modules
*****************************************************************************************************/

/*****************************************************************************************************
* Code of project wide FUNCTIONS
*****************************************************************************************************/
/*!
      \fn void u32fnAudioBufferHandler_Init (void)
      \brief  Initializes ring buffers, DMA channels and interrupts for data handling
      \param  none
      \return void
*/
void u32fnAudioBufferHandler_Init (void)
{

	vfnI2SInit();
	/* initialize RX and TX ring buffers */
	vfnRingBuffer_Init(&sAudio_OutputRingBuffer,&gau32Audio_OutputRingBuffer[0],sizeof(gau32Audio_OutputRingBuffer));
	vfnRingBuffer_Init(&sAudio_InputRingBuffer,&gau32Audio_InputRingBuffer[0],sizeof(gau32Audio_InputRingBuffer));


	sAudio_OutDMACh0.u32Channel = AUDIO_BUFFER_HANDLER_DMA_OUT;
	sAudio_OutDMACh0.u32SourceAddress = (u32)(&gau32Audio_OutputRingBuffer[0]);
	sAudio_OutDMACh0.u32DestinationAddress = (u32)(&I2S_TDR0);
	sAudio_OutDMACh0.u32StatusByteCount = DMA_DATA_BYTE_COUNT;
	sAudio_OutDMACh0.u32Control = DMA_DCR_EINT_MASK|DMA_DCR_SINC_MASK|DMA_DCR_SSIZE(DMA_TRANSFER_SIZE_32_BIT)|DMA_DCR_DSIZE(DMA_TRANSFER_SIZE_32_BIT)|DMA_DCR_CS_MASK|DMA_DCR_SMOD(DMA_CIRCULAR_BUFFER_4_KB);
	sAudio_OutDMACh0.u32TriggerSource = DMA_TRIGGER_I2S0_TX;
	(void)vfnDMA_Init((stcd_DMA*)&sAudio_OutDMACh0,&vfnAudioBufferHandler_DMATxCallback);
		
	sAudio_InDMACh0.u32Channel = AUDIO_BUFFER_HANDLER_DMA_IN;
	sAudio_InDMACh0.u32SourceAddress = (u32)(&I2S_RDR0);
	sAudio_InDMACh0.u32DestinationAddress = (u32)(&gau32Audio_InputRingBuffer[0]);
	sAudio_InDMACh0.u32StatusByteCount = DMA_DATA_BYTE_COUNT;
	sAudio_InDMACh0.u32Control = DMA_DCR_EINT_MASK|DMA_DCR_DINC_MASK|DMA_DCR_SSIZE(DMA_TRANSFER_SIZE_32_BIT)|DMA_DCR_DSIZE(DMA_TRANSFER_SIZE_32_BIT)|DMA_DCR_CS_MASK|DMA_DCR_DMOD(DMA_CIRCULAR_BUFFER_4_KB);
	sAudio_InDMACh0.u32TriggerSource = DMA_TRIGGER_I2S0_RX;
	(void)vfnDMA_Init((stcd_DMA*)&sAudio_InDMACh0,&vfnAudioBufferHandler_DMARxCallback);
	

	AUDIO_BUFFER_HANDLER_SET_STATUS(AUDIO_BUFFER_HANDLER_RX_COMPLETE);
	AUDIO_BUFFER_HANDLER_SET_STATUS(AUDIO_BUFFER_HANDLER_TX_COMPLETE);
}
/*!
      \fn  vfnAudioBufferHandler_WriteBuffer16to24(u16 * pu16BufferInput, u16 u16DataSize)
      \brief  Use it when application audio data is 16 bit and SSI module is used or SAI is used as 24-bit word
      \param  pu16BufferInput: Pointer to the application 16 bit audio buffer
      \param u16DataSize: Amount of samples
      \return void
*/
void vfnAudioBufferHandler_WriteBuffer16to24(u16 * pu16BufferInput, u16 u16DataSize)
{
	u32 u32TempSample;

	gu32Audio_OutRingBufferFillThreshold += u16DataSize;
	/*shift each sample to get it on 24 bits, then push it into the ringbuffer*/
	while(u16DataSize--)
	{
		u32TempSample = (u32)*pu16BufferInput;
		u32TempSample <<= 8;
		vfnRingBuffer_WriteData(&sAudio_OutputRingBuffer,&u32TempSample);
		pu16BufferInput++;
	}

	/*check if the I2S Tx is enabled, if not, that means the ring buffer needs to be filled up to 50%*/
	/* then start DMA transactions */
	if(!AUDIO_BUFFER_HANDLER_CHECK_STATUS(AUDIO_BUFFER_HANDLER_TX_STARTED))
	{
		AUDIO_BUFFER_HANDLER_SET_STATUS(AUDIO_BUFFER_HANDLER_TX_COMPLETE);
		if(gu32Audio_OutRingBufferFillThreshold >= AUDIO_OUT_RING_BUFFER_HALF_FILL)
		{
			vfnI2S_FillTxFIFO((u32 *)sAudio_OutputRingBuffer.pu32ReadPointer);
			DMA_ENABLE_REQ(AUDIO_BUFFER_HANDLER_DMA_OUT);
			I2S_TX_ENABLE;
			AUDIO_BUFFER_HANDLER_SET_STATUS(AUDIO_BUFFER_HANDLER_TX_STARTED);
			AUDIO_BUFFER_HANDLER_CLEAR_STATUS(AUDIO_BUFFER_HANDLER_TX_COMPLETE);
		}
	}
}
/*!
      \fn void vfnAudioBufferHandler_WriteBuffer16to32(u16 * pu16BufferInput, u16 u16DataSize)
      \brief  Use it when application audio data is 16 bit and SAI  module is used as 32 bit word
      \param  pu16BufferInput: Pointer to the application 16 bit audio buffer
      \param u16DataSize: Amount of samples
      \return void
*/
void vfnAudioBufferHandler_WriteBuffer16to32(u16 * pu16BufferInput, u16 u16DataSize)
{
	u32 u32TempSample;

	gu32Audio_OutRingBufferFillThreshold += u16DataSize;
	/*shift each sample to get it on 24 bits, then push it into the ringbuffer*/
	while(u16DataSize--)
	{
		u32TempSample = (u32)(*pu16BufferInput);
		u32TempSample <<= 16;
		vfnRingBuffer_WriteData(&sAudio_OutputRingBuffer,&u32TempSample);
		pu16BufferInput++;
	}

	/*check if the I2S Tx is enabled, if not, that means the ring buffer needs to be filled up to 50%*/
	/* then start DMA transactions */
	if(!AUDIO_BUFFER_HANDLER_CHECK_STATUS(AUDIO_BUFFER_HANDLER_TX_STARTED))
	{
		AUDIO_BUFFER_HANDLER_SET_STATUS(AUDIO_BUFFER_HANDLER_TX_COMPLETE);
		if(gu32Audio_OutRingBufferFillThreshold >= AUDIO_OUT_RING_BUFFER_HALF_FILL)
		{
			vfnI2S_FillTxFIFO((u32 *)sAudio_OutputRingBuffer.pu32ReadPointer);
			DMA_ENABLE_REQ(AUDIO_BUFFER_HANDLER_DMA_OUT);
			I2S_TX_ENABLE;
			AUDIO_BUFFER_HANDLER_SET_STATUS(AUDIO_BUFFER_HANDLER_TX_STARTED);
			AUDIO_BUFFER_HANDLER_CLEAR_STATUS(AUDIO_BUFFER_HANDLER_TX_COMPLETE);
		}
	}
}
/*!
      \fn void vfnAudioBufferHandler_WriteBuffer(u32 * pu32BufferInput, u16 u16DataSize)
      \brief  Used when  audio data is in 32 bit and SAI module is configured for 32 bit word
      \param  pu32BufferInput: Pointer to the 32 bit application buffer
      \param  u16DataSize: Amount of samples
      \return void
*/
void vfnAudioBufferHandler_WriteBuffer(u32 * pu32BufferInput, u16 u16DataSize)
{

	gu32Audio_OutRingBufferFillThreshold += u16DataSize;

	while(u16DataSize--)
	{
		vfnRingBuffer_WriteData(&sAudio_OutputRingBuffer,pu32BufferInput);

		pu32BufferInput++;
	}

	//check if the I2S Tx is enabled, if not, that means the ring buffer needs to be filled up to 50%
	if(!AUDIO_BUFFER_HANDLER_CHECK_STATUS(AUDIO_BUFFER_HANDLER_TX_STARTED))
	{
		AUDIO_BUFFER_HANDLER_SET_STATUS(AUDIO_BUFFER_HANDLER_TX_COMPLETE);
		if(gu32Audio_OutRingBufferFillThreshold >= AUDIO_OUT_RING_BUFFER_HALF_FILL)
		{
			vfnI2S_FillTxFIFO((u32 *)sAudio_OutputRingBuffer.pu32ReadPointer);
			DMA_ENABLE_REQ(AUDIO_BUFFER_HANDLER_DMA_OUT);
			I2S_TX_ENABLE;
			AUDIO_BUFFER_HANDLER_SET_STATUS(AUDIO_BUFFER_HANDLER_TX_STARTED);
			AUDIO_BUFFER_HANDLER_CLEAR_STATUS(AUDIO_BUFFER_HANDLER_TX_COMPLETE);
		}
	}
}
/*!
      \fn void vfnAudioBufferHandler_ReadBuffer(u32 * pu32Buffer, u16 u16DataSize)
      \brief  Reads from the audio ring buffer to application buffer in 32-bit
      \param  pu32Buffer: Pointer to the application buffer
      \param  u16DataSize: Amount of samples
      \return void
*/
void vfnAudioBufferHandler_ReadBuffer(u32 * pu32Buffer, u16 u16DataSize)
{
	gu32Audio_InRingBufferFillThreshold += u16DataSize;

	while(u16DataSize--)
	{
		vfnRingBuffer_ReadData(&sAudio_InputRingBuffer,pu32Buffer);
		pu32Buffer++;
	}

	//check if the I2S Tx is enabled, if not, that means the ring buffer needs to be filled up to 50%
	if(!AUDIO_BUFFER_HANDLER_CHECK_STATUS(AUDIO_BUFFER_HANDLER_RX_STARTED))
	{
		AUDIO_BUFFER_HANDLER_SET_STATUS(AUDIO_BUFFER_HANDLER_RX_COMPLETE);
		if(gu32Audio_InRingBufferFillThreshold >= AUDIO_IN_RING_BUFFER_HALF_FILL)
		{
			DMA_ENABLE_REQ(AUDIO_BUFFER_HANDLER_DMA_IN);
			I2S_RX_ENABLE;
			AUDIO_BUFFER_HANDLER_SET_STATUS(AUDIO_BUFFER_HANDLER_RX_STARTED);
			AUDIO_BUFFER_HANDLER_CLEAR_STATUS(AUDIO_BUFFER_HANDLER_RX_COMPLETE);
		}
	}
}
/*!
      \fn vfnAudioBufferHandler_DMARxCallback
      \brief  RX DMA ISR callback
      \param  none
      \return void
*/
void vfnAudioBufferHandler_DMARxCallback (void)
{
	AUDIO_BUFFER_HANDLER_SET_STATUS(AUDIO_BUFFER_HANDLER_RX_COMPLETE);
	gu32ISRCounter++;
	DMA_UPDATE_BYTE_COUNT(AUDIO_BUFFER_HANDLER_DMA_IN,DMA_DATA_BYTE_COUNT);
}
/*!
      \fn vfnAudioBufferHandler_DMATxCallback
      \brief  TX DMA ISR Callback
      \param  none
      \return void
*/
void vfnAudioBufferHandler_DMATxCallback (void)
{
	AUDIO_BUFFER_HANDLER_SET_STATUS(AUDIO_BUFFER_HANDLER_TX_COMPLETE);
	
	DMA_UPDATE_BYTE_COUNT(AUDIO_BUFFER_HANDLER_DMA_OUT,DMA_DATA_BYTE_COUNT);
}
