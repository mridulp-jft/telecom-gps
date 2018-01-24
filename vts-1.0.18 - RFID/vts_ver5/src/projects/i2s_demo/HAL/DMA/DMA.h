/****************************************************************************************************/
/**
Copyright (c) 2008 Freescale Semiconductor
Freescale Confidential Proprietary
\file       DMA.h
\brief
\author     Freescale Semiconductor
\author     Guadalajara Applications Laboratory RTAC Americas
\author     B22385
\version    0.1
\date       Sep 13, 2012
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

#ifndef DMA_H_
#define DMA_H_
/*****************************************************************************************************
* Include files
*****************************************************************************************************/

/*****************************************************************************************************
* Declaration of project wide TYPES
*****************************************************************************************************/
typedef struct
{
	u32 u32Channel;
	u32 u32SourceAddress;
	u32	u32DestinationAddress;
	u32 u32StatusByteCount;
	u32 u32Control;
	u32 u32TriggerSource;
}stcd_DMA;

typedef enum
{
	DMA_TRIGGER_DISABLE = 0,				/*  0 */
	DMA_TRIGGER_RESERVED_0,					/*  1 */
	DMA_TRIGGER_UART0_RX,					/*  2 */
	DMA_TRIGGER_UART0_TX,					/*  3 */
	DMA_TRIGGER_UART1_RX,					/*  4 */
	DMA_TRIGGER_UART1_TX,					/*  5 */
	DMA_TRIGGER_UART2_RX,					/*  6 */
	DMA_TRIGGER_UART2_TX,					/*  7 */
	DMA_TRIGGER_RESERVED_1,					/*  8 */
	DMA_TRIGGER_RESERVED_2,					/*  9 */
	DMA_TRIGGER_RESERVED_3,					/* 10 */
	DMA_TRIGGER_RESERVED_4,					/* 11 */
	DMA_TRIGGER_RESERVED_5,					/* 12 */
	DMA_TRIGGER_RESERVED_6,					/* 13 */
	DMA_TRIGGER_I2S0_RX,					/* 14 */
	DMA_TRIGGER_I2S0_TX,					/* 15 */
	DMA_TRIGGER_SPI0_RX,					/* 16 */
	DMA_TRIGGER_SPI0_TX,					/* 17 */
	DMA_TRIGGER_SPI1_RX,					/* 18 */
	DMA_TRIGGER_SPI1_TX,					/* 19 */
	DMA_TRIGGER_RESERVED_7,					/* 20 */
	DMA_TRIGGER_RESERVED_8,				/* 21 */
	DMA_TRIGGER_I2C0,						/* 22 */
	DMA_TRIGGER_I2C1,						/* 23 */
	DMA_TRIGGER_FTM0_CHANNEL_0,				/* 24 */
	DMA_TRIGGER_FTM0_CHANNEL_1,				/* 25 */
	DMA_TRIGGER_FTM0_CHANNEL_2,				/* 26 */
	DMA_TRIGGER_FTM0_CHANNEL_3,				/* 27 */
	DMA_TRIGGER_FTM0_CHANNEL_4,				/* 28 */
	DMA_TRIGGER_FTM0_CHANNEL_5,				/* 29 */
	DMA_TRIGGER_RESERVED_9,				/* 30 */
	DMA_TRIGGER_RESERVED_10,				/* 31 */
	DMA_TRIGGER_FTM1_CHANNEL_0,				/* 32 */
	DMA_TRIGGER_FTM1_CHANNEL_1,				/* 33 */
	DMA_TRIGGER_FTM2_CHANNEL_0,				/* 34 */
	DMA_TRIGGER_FTM2_CHANNEL_1,				/* 35 */
	DMA_TRIGGER_RESERVED_11,				/* 36 */
	DMA_TRIGGER_RESERVED_12,				/* 37 */
	DMA_TRIGGER_RESERVED_13,				/* 38 */
	DMA_TRIGGER_RESERVED_14,				/* 39 */
	DMA_TRIGGER_ADC0,						/* 40 */
	DMA_TRIGGER_RESERVED_15,				/* 41 */
	DMA_TRIGGER_CMP0,						/* 42 */
	DMA_TRIGGER_RESERVED_16,				/* 43 */
	DMA_TRIGGER_RESERVED_17,				/* 44 */
	DMA_TRIGGER_DAC0,						/* 45 */
	DMA_TRIGGER_RESERVED_18,				/* 46 */
	DMA_TRIGGER_RESERVED_19,				/* 47 */
	DMA_TRIGGER_RESERVED_20,				/* 48 */
	DMA_TRIGGER_PORT_A,						/* 49 */
	DMA_TRIGGER_RESERVED_21,				/* 50 */
	DMA_TRIGGER_PORT_C,						/* 51 */
	DMA_TRIGGER_PORT_D,						/* 52 */
	DMA_TRIGGER_RESERVED_22,				/* 53 */
	DMA_TRIGGER_TPM0,						/* 54 */
	DMA_TRIGGER_TMP1,						/* 55 */
	DMA_TRIGGER_TPM2,						/* 56 */
	DMA_TRIGGER_TSI,						/* 57 */
	DMA_TRIGGER_RESERVED_23,				/* 58 */
	DMA_TRIGGER_RESERVED_24,				/* 59 */
	DMA_TRIGGER_ALWAYS_EN_0,				/* 60 */
	DMA_TRIGGER_ALWAYS_EN_1,				/* 61 */
	DMA_TRIGGER_ALWAYS_EN_2,				/* 62 */
	DMA_TRIGGER_ALWAYS_EN_3,				/* 63 */
	DMA_TRIGGER_UNSUPPORT_TRIGGER			/* 64 */
}eDMATriggerSource;

typedef enum
{
	DMA_CHANNEL_0 = 0,
	DMA_CHANNEL_1,
	DMA_CHANNEL_2,
	DMA_CHANNEL_3,
	DMA_MAX_CHANNELS
}eDMAChannels;

typedef enum
{
	DMA_TRANSFER_SIZE_32_BIT = 0,
	DMA_TRANSFER_SIZE_08_BIT,
	DMA_TRANSFER_SIZE_15_BIT,	
}eDMATransferSize;

typedef enum
{
	DMA_CIRCULAR_BUFFER_DISABLED = 0,
	DMA_CIRCULAR_BUFFER_16_B,
	DMA_CIRCULAR_BUFFER_32_B,
	DMA_CIRCULAR_BUFFER_64_B,
	DMA_CIRCULAR_BUFFER_128_B,
	DMA_CIRCULAR_BUFFER_256_B,
	DMA_CIRCULAR_BUFFER_512_B,
	DMA_CIRCULAR_BUFFER_1_KB,
	DMA_CIRCULAR_BUFFER_2_KB,
	DMA_CIRCULAR_BUFFER_4_KB,
	DMA_CIRCULAR_BUFFER_8_KB,
	DMA_CIRCULAR_BUFFER_16_KB,
	DMA_CIRCULAR_BUFFER_32_KB,
	DMA_CIRCULAR_BUFFER_64_KB,
	DMA_CIRCULAR_BUFFER_128_KB,
	DMA_CIRCULAR_BUFFER_256_KB,
}eDMACircularBuffer;
/*****************************************************************************************************
* Definition of project wide VARIABLES
*****************************************************************************************************/

/*****************************************************************************************************
* Definition of project wide MACROS / #DEFINE-CONSTANTS
*****************************************************************************************************/

/*****************************************************************************************************
* Declaration of project wide FUNCTIONS
*****************************************************************************************************/


#define DMA_ENABLE_REQ(channel)								(DMA_DCR(channel) |= DMA_DCR_ERQ_MASK)
#define DMA_DISABLE_REQ(channel)							(DMA_DCR(channel) &= ~DMA_DCR_ERQ_MASK)
#define DMA_UPDATE_SOURCE_ADDRESS(channel,address)			(DMA_SAR(channel) = (u32)address)
#define DMA_UPDATE_DESTINATION_ADDRESS(channel,address)		(DMA_DAR(channel) = (u32)address)
#define DMA_UPDATE_BYTE_COUNT(channel,count)				(DMA_DSR_BCR(channel) = count)
#define DMA_UPDATE_CONTROL(channel,control)					(DMA_DCR(channel) = control)

#define DMA_CLEAR_DONE(channel)					(DMA_DSR_BCR(channel) |= DMA_DSR_BCR_DONE_MASK)

/*****************************************************************************************************
* Declaration of module wide FUNCTIONs - NOT for use in other modules
*****************************************************************************************************/
void vfnDMA_Init(stcd_DMA * spDMAChannel, void(* vfnDMAChCallback)(void));
void vfnDMA_UpdateSAR(stcd_DMA * spDMAChannel);
void vfnDMA_UpdateDAR(stcd_DMA * spDMAChannel);
void vfnDMA_UpdateDSRBSR(stcd_DMA * spDMAChannel);
void vfnDMA_UpdateDCR(stcd_DMA * spDMAChannel);
void DMA0_IRQHandler (void);
void DMA1_IRQHandler (void);
void DMA2_IRQHandler (void);
void DMA3_IRQHandler (void);
#endif /*DMA_H_*/

