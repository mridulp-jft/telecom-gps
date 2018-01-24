/****************************************************************************************************/
/**
Copyright (c) 2008 Freescale Semiconductor
Freescale Confidential Proprietary
\file       RingBuffer.h
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
* Module definition against multiple inclusion
*****************************************************************************************************/

#ifndef RINGBUFFER_H_
#define RINGBUFFER_H_
/*****************************************************************************************************
* Include files
*****************************************************************************************************/
/*****************************************************************************************************
* Declaration of project wide TYPES
*****************************************************************************************************/
/*!
    \enum eRingBufferFlags
    \brief Ringbuffer state flags
*/
typedef enum
{
	RING_BUFFER_OVERFLOW = 0,
	RING_BUFFER_ALLOCATED,
	RING_BUFFER_NOT_ENOUGH_SPACE,
	RING_BUFFER_WR_PTR_ROLLED_OVER,
	RING_BUFFER_WR_PTR_WITHIN_BOUNDARY,
	RING_BUFFER_DATA_PENDING,
	RING_BUFFER_RING_BUFFER_EMPTY
}eRingBufferFlags;
/*!
    \enum sRingBuffer
    \brief Struct for ring buffer
*/
typedef struct
{
	u32	* pu32WritePointer;
	u32	* pu32ReadPointer;
	u32 u32StartAddress;
	u32 u32EndAddress;
	u32 u32BufferSize;
	u32 u32BufferStatus;

}sRingBuffer;
/*****************************************************************************************************
* Definition of project wide VARIABLES
*****************************************************************************************************/

/*****************************************************************************************************
* Definition of project wide MACROS / #DEFINE-CONSTANTS
*****************************************************************************************************/

/*****************************************************************************************************
* Declaration of project wide FUNCTIONS
*****************************************************************************************************/
void vfnRingBuffer_Init(sRingBuffer * spRingBuffer, u32 * pu32StartAddress, u32 u32BufferSize);
void vfnRingBuffer_WriteBuffer(sRingBuffer * psRingBuffer, u32 * pu32OutData, u32 u32DatatoWrite);
void vfnRingBuffer_WriteData(sRingBuffer * psRingBuffer, u32 * pu32OutData);
void vfnRingBuffer_ReadData(sRingBuffer * psRingBuffer, u32 * pu32Data);
void vfnRingBuffer_Reset(sRingBuffer * spRingBuffer);
/*****************************************************************************************************
* Declaration of module wide FUNCTIONs - NOT for use in other modules
*****************************************************************************************************/

#endif /*RINGBUFFER_H_*/

