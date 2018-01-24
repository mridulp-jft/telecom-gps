/****************************************************************************************************/
/**
Copyright (c) 2008 Freescale Semiconductor
Freescale Confidential Proprietary
\file       RingBuffer.c
\brief
\author     Freescale Semiconductor
\author     Guadalajara Applications Laboratory RTAC Americas
\author     b22385
\version    0.1
\date       Sep 12, 2011
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
#include "RingBuffer.h"
/*****************************************************************************************************
* Declaration of module wide FUNCTIONs - NOT for use in other modules
*****************************************************************************************************/

/*****************************************************************************************************
* Definition of module wide MACROs / #DEFINE-CONSTANTs - NOT for use in other modules
*****************************************************************************************************/

/*****************************************************************************************************
* Declaration of module wide TYPEs - NOT for use in other modules
*****************************************************************************************************/

/*****************************************************************************************************
* Definition of module wide VARIABLEs - NOT for use in other modules
*****************************************************************************************************/

/*****************************************************************************************************
* Definition of module wide (CONST-) CONSTANTs - NOT for use in other modules
*****************************************************************************************************/

/*****************************************************************************************************
* Code of project wide FUNCTIONS
*****************************************************************************************************/

/*!
      \fn void vfnRingBufferInit(sRingBuffer * spRingBuffer, u32 * pu32StartAddress, u32 u32BufferSize)
      \brief  Initializes the desire buffer in ringbuffer
      \param  spRingBuffer: Ring Buffer struct to place the buffer data
      \param  pu32StartAddress: Ring buffer start address
      \param  u32BufferSize: Ring buffer size
      \return void
*/
void vfnRingBuffer_Init(sRingBuffer * spRingBuffer, u32 * pu32StartAddress, u32 u32BufferSize)
{
	spRingBuffer->u32StartAddress = (u32)pu32StartAddress;
	spRingBuffer->u32EndAddress   = ((u32)(pu32StartAddress) + (u32)(u32BufferSize) - (u32)(4));
	spRingBuffer->u32BufferSize   = u32BufferSize;
	spRingBuffer->pu32ReadPointer = pu32StartAddress;
	spRingBuffer->pu32WritePointer = pu32StartAddress;
	spRingBuffer->u32BufferStatus = 0;
}

/*!
      \fn void vfnRingBufferReset(sRingBuffer * spRingBuffer)
      \brief  Resets both Ring buffer pointers to the start address
      \param  spRingBuffer: Ring Buffer struct to reset
      \return void
*/
void vfnRingBuffer_Reset(sRingBuffer * spRingBuffer)
{
	spRingBuffer->pu32ReadPointer = (u32 *)spRingBuffer->u32StartAddress;
	spRingBuffer->pu32WritePointer = (u32 *)spRingBuffer->u32StartAddress;
}


/*!
      \fn void vfnRingBuffer_WriteBuffer(sRingBuffer * psRingBuffer, u32 * pu32OutData, u32 u32DatatoWrite)
      \brief  Writes data into the ring buffer
      \param  spRingBuffer: Ring Buffer struct to use
      \param  pu32OutData: 	Data to be written
      \param  u32DatatoWrite: Amount of data to be written
      \return void
*/
void vfnRingBuffer_WriteBuffer(sRingBuffer * psRingBuffer, u32 * pu32OutData, u32 u32DatatoWrite)
{
	u16 u16SpaceAvailable;

	/* compute current buffer size */
	if(((u32)psRingBuffer->pu32WritePointer) > ((u32)psRingBuffer->pu32ReadPointer))
	{
		u16SpaceAvailable = (u16)((u32)psRingBuffer->pu32WritePointer - (u32)psRingBuffer->pu32ReadPointer);
	}
	else
	{
		u16SpaceAvailable = (u16)(psRingBuffer->u32BufferSize - ((u32)psRingBuffer->pu32ReadPointer - (u32)psRingBuffer->pu32WritePointer));
	}

	/* set error on buffer status if there is no available space */
	if(u32DatatoWrite > u16SpaceAvailable)
	{
		psRingBuffer->u32BufferStatus |= (1<<RING_BUFFER_OVERFLOW);
	}
	
	/* loop to write the requested data */
	while(u32DatatoWrite)
	{
		*(psRingBuffer->pu32WritePointer) = (*pu32OutData);
		psRingBuffer->pu32WritePointer++;
		pu32OutData++;
		u32DatatoWrite--;

		/* send to the beginning the pointer */
		if(((u32)psRingBuffer->pu32WritePointer) > psRingBuffer->u32EndAddress)
		{
			psRingBuffer->pu32WritePointer = ((u32*)psRingBuffer->u32StartAddress);
		}
	}
	/* set error if at the end of writting both pointers reach each other */
	if(((u32)psRingBuffer->pu32WritePointer) == ((u32)psRingBuffer->pu32ReadPointer))
	{
		psRingBuffer->u32BufferStatus |= (1<<RING_BUFFER_OVERFLOW);
	}
}
/*!
      \fn void vfnRingBuffer_WriteData(sRingBuffer * psRingBuffer, u32 * pu32OutData)
      \brief  Writes a single data into the buffer
      \param  spRingBuffer: Ring Buffer struct to use
      \param  pu32OutData: 	Data to be written
      \return void
*/
void vfnRingBuffer_WriteData(sRingBuffer * psRingBuffer, u32 * pu32OutData)
{
	
	/* write data */
	*(psRingBuffer->pu32WritePointer) = (*pu32OutData);
	psRingBuffer->pu32WritePointer++;
	/* send to the beginning the pointer */
	if(((u32)psRingBuffer->pu32WritePointer) > psRingBuffer->u32EndAddress)
	{
		psRingBuffer->pu32WritePointer = ((u32*)psRingBuffer->u32StartAddress);
	}

	if(((u32)psRingBuffer->pu32WritePointer) == ((u32)psRingBuffer->pu32ReadPointer))
	{
		psRingBuffer->u32BufferStatus |= (1<<RING_BUFFER_OVERFLOW);
	}

}
/*!
      \fn void vfnRingBuffer_ReadData(sRingBuffer * psRingBuffer, u32 * pu32Data)
      \brief  Reads a single data into the buffer
      \param  spRingBuffer: Ring Buffer struct to use
      \param  pu32OutData: 	Buffer to place the data
      \return void
*/
void vfnRingBuffer_ReadData(sRingBuffer * psRingBuffer, u32 * pu32Data)
{

	*pu32Data = *(psRingBuffer->pu32ReadPointer);
	psRingBuffer->pu32ReadPointer++;
	/* send to the beginning the pointer */
	if(((u32)psRingBuffer->pu32ReadPointer) > psRingBuffer->u32EndAddress)
	{
		psRingBuffer->pu32ReadPointer = ((u32*)psRingBuffer->u32StartAddress);
	}

	if(((u32)psRingBuffer->pu32WritePointer) == ((u32)psRingBuffer->pu32ReadPointer))
	{
		psRingBuffer->u32BufferStatus |= (1<<RING_BUFFER_OVERFLOW);
	}

}


