/****************************************************************************************************/
/**
Copyright (c) 2008 Freescale Semiconductor
Freescale Confidential Proprietary
\file       SGTL5000.h
\brief
\author     Freescale Semiconductor
\author     Guadalajara Applications Laboratory RTAC Americas
\author     B22385
\version    0.1
\date       May 19, 2011
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

#ifndef SGTL500_H_
#define SGTL500_H_
/*****************************************************************************************************
* Include files
*****************************************************************************************************/


/*****************************************************************************************************
* Declaration of project wide TYPES
*****************************************************************************************************/
/*!
    \enum eSGTL5000Status
    \brief SGTL5000 driver status
*/
typedef enum
{
	SGTL5000_STATUS_BUSY = 0,
	SGTL5000_STATUS_CONFIGURED,
	SGTL5000_STATUS_I2C_ERROR
}eSGTL5000Status;
/*!
    \enum eSGTL5000GEQBands
    \brief SGTL5000 5 GEQ bands
*/
typedef enum
{
	SGTL5000_BAND_0 = 0,
	SGTL5000_BAND_1,
	SGTL5000_BAND_2,
	SGTL5000_BAND_3,
	SGTL5000_BAND_4
}eSGTL5000GEQBands;
/*****************************************************************************************************
* Definition of project wide VARIABLES
*****************************************************************************************************/
extern volatile u8 gu8SGTL5000DriverStatus;
extern sSM sSGTL5000ControlStateMachine;
/*****************************************************************************************************
* Definition of project wide MACROS / #DEFINE-CONSTANTS
*****************************************************************************************************/

/*Select the word length */
//#define _16_BIT_WORD
//#define _20_BIT_WORD
//#define _24_BIT_WORD
#define _32_BIT_WORD



/***************************************************************************************************/
/* * Register values. */
#define SGTL5000_CHIP_ID		        (0x0000)
#define SGTL5000_CHIP_DIG_POWER			(0x0002)
#define SGTL5000_CHIP_CLK_CTRL			(0x0004)
#define SGTL5000_CHIP_I2S_CTRL			(0x0006)
#define SGTL5000_CHIP_SSS_CTRL			(0x000a)
#define SGTL5000_CHIP_ADCDAC_CTRL		(0x000e)
#define SGTL5000_CHIP_DAC_VOL			(0x0010)
#define SGTL5000_CHIP_PAD_STRENGTH		(0x0014)
#define SGTL5000_CHIP_ANA_ADC_CTRL		(0x0020)
#define SGTL5000_CHIP_ANA_HP_CTRL		(0x0022)
#define SGTL5000_CHIP_ANA_CTRL			(0x0024)
#define SGTL5000_CHIP_LINREG_CTRL		(0x0026)
#define SGTL5000_CHIP_REF_CTRL			(0x0028)
#define SGTL5000_CHIP_MIC_CTRL			(0x002a)
#define SGTL5000_CHIP_LINE_OUT_CTRL		(0x002c)
#define SGTL5000_CHIP_LINE_OUT_VOL		(0x002e)
#define SGTL5000_CHIP_ANA_POWER			(0x0030)
#define SGTL5000_CHIP_PLL_CTRL			(0x0032)
#define SGTL5000_CHIP_CLK_TOP_CTRL		(0x0034)
#define SGTL5000_CHIP_ANA_STATUS		(0x0036)
#define SGTL5000_CHIP_SHORT_CTRL		(0x003c)
#define SGTL5000_CHIP_ANA_TEST2			(0x003a)
#define SGTL5000_DAP_BASS_ENHANCE          (0x0104)
#define SGTL5000_DAP_BASS_ENHANCE_CTRL     (0x0106)

#define SGTL5000_DAP_AUDIO_EQ                   (0x0108)
#define SGTL5000_DAP_AUDIO_EQ_BASS_BAND0        (0x0116)
#define SGTL5000_DAP_AUDIO_EQ_BAND1        (0x0118)
#define SGTL5000_DAP_AUDIO_EQ_BAND2        (0x011A)
#define SGTL5000_DAP_AUDIO_EQ_BAND3        (0x011C)
#define SGTL5000_DAP_AUDIO_EQ_TREBLE_BAND4        (0x011E)

#define SGTL5000_DAP_AVC_CTRL              (0x0124)
#define SGTL5000_DAP_AVC_THRESHOLD         (0x0126)
#define SGTL5000_DAP_AVC_ATTACK            (0x0128)
#define SGTL5000_DAP_AVC_DECAY              (0x012A)
#define SGTL5000_DAP_MAIN_CHAN             (0x0120)
#define SGTL5000_DAP_CONTROL                (0x0100)

#define SGTL5000_CHECK_STATUS(x)	(gu8SGTL5000DriverStatus&((1 << x)))

#define SGTL5000_CONTROL_BUSY	(gu8SGTL5000DriverStatus&((1 << SGTL5000_STATUS_BUSY)))

#define SGTL5000_CONFIGURED	(gu8SGTL5000DriverStatus&((1 << SGTL5000_STATUS_CONFIGURED)))

/*****************************************************************************************************
* Declaration of project wide FUNCTIONS
*****************************************************************************************************/

/*****************************************************************************************************
* Declaration of module wide FUNCTIONs - NOT for use in other modules
*****************************************************************************************************/
void vfnSGTLInit(void);
extern void (* const vfnapSGTL5000ControlStateMachine[]) (void);
void vfnSGTL5000WriteRegister(u16 u16Register, u16 u16RegisterData);
void vfnSGTL5000ReadRegister(u16 u16Register, u8 *pu8RegisterData);
void vfnSGTL5000ChangeGEQVolume(u16 u16GEQBand, u16 u16Level);

#endif /*SGTL500_H_*/

