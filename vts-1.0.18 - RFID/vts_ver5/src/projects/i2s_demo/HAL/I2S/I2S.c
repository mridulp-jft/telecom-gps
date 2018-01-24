	/****************************************************************************************************/
/**
Copyright (c) 2008 Freescale Semiconductor
Freescale Confidential Proprietary
\file       I2S.c
\brief
\author     Freescale Semiconductor
\author     Guadalajara Applications Laboratory RTAC Americas
\author     B22385
\version    0.1
\date       May 18, 2011
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
#include <MKL26Z4.H>
#include "common.h"
#include "I2S.h"

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
      \fn  vfnI2SInit
      \brief  Initialization of the SAI module as I2S Slave
      \param  u32TxFIFOWm: Tx FIFO watermark
	  \param  u32RxFIFOWm: Rx FIFO watermark
      \return none
*/
void vfnI2SInit(void)
{

	/* Enable SSI CLK from SIM */
    SIM_SCGC6 |= SIM_SCGC6_I2S_MASK;

    SIM_SCGC5 |= SIM_SCGC5_PORTA_MASK;

    /* Enable SAI pins */
#ifdef TOWER
	/* TX_BCLK */
    PORTA_PCR5 = PORT_PCR_MUX(0x06);

    /* TX Frame Sync */
    PORTA_PCR13 = PORT_PCR_MUX(0x06);
	
	/* RX data line */
    PORTA_PCR15 = PORT_PCR_MUX(0x06);

    /* TX data line */
    PORTA_PCR12 = PORT_PCR_MUX(0x06);
	#else
	/* TX_BCLK */
    PORTB_PCR18 = PORT_PCR_MUX(0x04);

    /* TX Frame Sync */
    PORTB_PCR19 = PORT_PCR_MUX(0x04);
	
	/* RX data line */
    PORTC_PCR11 = PORT_PCR_MUX(0x04);

    /* TX data line */
    PORTC_PCR0 = PORT_PCR_MUX(0x06);
		
	#endif
	

	/* Tx */
	/* For using TX BLCK and FS CLK in synch mode, TX must be Asynch and Rx synch */
	/* The RM rev. 1 Draft A defines CLKMODE as bits [27:26] which is wrong, the actual bits are [31:30] */
	I2S_TCR2 = I2S_TCR2_BCP_MASK;

	//I2S_MCR &= ~I2S_MCR_MOE_MASK;

	
	/* 2 slot on a frame, Fsynch of 32 clocks */
	I2S_TCR4 =  I2S_TCR4_FRSZ_MASK |I2S_TCR4_FSE_MASK|I2S_TCR4_SYWD(31)|I2S_TCR4_MF_MASK|I2S_TCR4_FSP_MASK;

	I2S_TCR4 &= ~(I2S_TCR4_FSD_MASK);

	/*32-bit first and following words */
	I2S_TCR5 = I2S_TCR5_WNW(31)|I2S_TCR5_W0W(31)|I2S_TCR5_FBT(31);
	/* enable DMA transfer on FIFO warning */
	I2S_TCSR |= I2S_TCSR_FWDE_MASK;
	
	
	/*transmit data channel 1 enabled */
	I2S_TCR3 |= I2S_TCR3_TCE_MASK;
	
	/* RX */
	/* The RM RM rev. 1 Draft A defines CLKMODE as bits [27:26] which is wrong, the actual bits are [31:30] */
	I2S_RCR2 = 0x40000000;
	I2S_RCR4 =  I2S_RCR4_FRSZ_MASK|I2S_RCR4_FSE_MASK|I2S_RCR4_SYWD(31)|I2S_RCR4_MF_MASK|I2S_RCR4_FSP_MASK;
	I2S_RCR4 &= ~(I2S_RCR4_FSD_MASK);
	I2S_RCR5 = I2S_RCR5_WNW(31)|I2S_RCR5_W0W(31)|I2S_RCR5_FBT(31);
	I2S_RCSR |= I2S_RCSR_FWDE_MASK;
	I2S_RCR3 |= I2S_RCR3_RCE_MASK;
}
/*!
      \fn  vfnI2S_FillTxFIFO
      \brief  Fills the I2S module TX FIFO
      \param  pu32Data: Pointer to Tx data
	  \param  u8Datatofill: amount of data to fill the FIFO
      \return none
*/
void vfnI2S_FillTxFIFO(u32 * pu32Data)
{
	I2S_TX_DISABLE;
	/* Fill TX FIFO */
	I2S_TDR0 = *pu32Data;
}
