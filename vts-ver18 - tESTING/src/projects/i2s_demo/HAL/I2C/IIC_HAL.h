/****************************************************************************************************/
/**
Copyright (c) 2011 Freescale Semiconductor
Freescale Confidential Proprietary
\file       IICDriver.h
\brief
\author     Freescale Semiconductor
\author     Guadalajara Applications Laboratory RTAC Americas
\author
\version    0.1
\date       September/2008
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
#ifndef __IICDriver
#define __IICDriver

/*****************************************************************************************************
* Include files
*****************************************************************************************************/
#include "ProjectTypes.h"
/*****************************************************************************************************
* Definition of project wide MACROS / #DEFINE-CONSTANTS
*****************************************************************************************************/
#define IIC_CLOCK_DIV_VALUE (0UL)
#define IIC_CLOCK_RATE_VALUE (13UL)
/*
#define IIC_CLOCK_DIV_VALUE (0)
#define IIC_CLOCK_RATE_VALUE (60)
*/

#define IIC_SLAVE_ADD   I2C0_A1

#define IIC_CLOCK_RATE(x)  ( I2C0_F = ( I2C0_F & ~I2C_F_ICR_MASK ) | ( ((x)<<(I2C_F_ICR_SHIFT))& I2C_F_ICR_MASK ) )
#define IIC_CLOCK_DIV(x)   ( I2C0_F = ( I2C0_F & ~I2C_F_MULT_MASK ) | ( ((x)<<(I2C_F_MULT_SHIFT))& I2C_F_MULT_MASK ) )

#define IIC_CONTROL_REGISTER I2C0_C1
#define IIC_CONTROL_REGISTER_VALUE (I2C_C1_IICEN_MASK | I2C_C1_IICIE_MASK)
#define IIC_TXAK(x) ( I2C0_C1 = ( I2C0_C1 & ~I2C_C1_TXAK_MASK ) | ( ((x)<<(I2C_C1_TXAK_SHIFT))& I2C_C1_TXAK_MASK ) )
#define IIC_TX(x)   ( I2C0_C1 = ( I2C0_C1 & ~I2C_C1_TX_MASK ) | ( ((x)<<(I2C_C1_TX_SHIFT))& I2C_C1_TX_MASK ) )
#define IIC_MST(x)  ( I2C0_C1 = ( I2C0_C1 & ~I2C_C1_MST_MASK ) | ( ((x)<<(I2C_C1_MST_SHIFT))& I2C_C1_MST_MASK ) )
#define IIC_RSTA(x) ( I2C0_C1 = ( I2C0_C1 & ~I2C_C1_RSTA_MASK ) | ( ((x)<<(I2C_C1_RSTA_SHIFT))& I2C_C1_RSTA_MASK ) )

#define IIC_IF          (I2C0_S & I2C_S_IICIF_MASK)
#define IIC_IF_CLEAR    (I2C0_S |=  I2C_S_IICIF_MASK )
#define IIC_ARBL        (I2C0_S & I2C_S_ARBL_MASK)
#define IIC_ARBL_CLEAR  (I2C0_S |=  I2C_S_ARBL_MASK )
#define IIC_RXAK        (I2C0_S & I2C_S_RXAK_MASK)
#define IIC_BUSY        (I2C0_S & I2C_S_BUSY_MASK)
#define IIC_IAAS(x)     (I2C0_S = ( I2C1_S & ~I2C_S_IAAS_MASK ) | ( ((x)<<(I2C_S_IAAS_SHIFT))&I2C_S_IAAS_MASK )

#define IIC_DATA_REGISTER  I2C0_D

#define IIC_ERROR			(u8IICDriverStatus&(1<<IIC_FLAGS_ERROR))
#define IIC_CLEAR_ERROR		(u8IICDriverStatus &= ~(1<<IIC_FLAGS_ERROR))
#define IIC_DRIVER_BUSY    (u8IICDriverStatus & (1<<IIC_FLAGS_BUSY))

#define IIC_IRQ (I2C0_IRQn)

/*****************************************************************************************************
* Declaration of project wide TYPES
*****************************************************************************************************/
typedef enum
{
  IIC_FLAGS_IDLE,
  IIC_FLAGS_BUSY,
  IIC_FLAGS_READY,
  IIC_FLAGS_WRITE_OK,
  IIC_FLAGS_ERROR
} eIICDriverStatus;

/*****************************************************************************************************
* Definition of project wide VARIABLES
*****************************************************************************************************/
extern volatile u8 u8IICDriverStatus;
extern void (*const vfnapIICDriver[])(void);
extern sSM sIICStateMachine;

/*****************************************************************************************************
* Declaration of project wide FUNCTIONS
*****************************************************************************************************/
void vfnIICInit(void);
void vfnIICWrite(u8 u8SlaveAddress, u8 *pu8DataOut, u8 u8Size);
void vfnIICRead(u8 u8SlaveAddress, u8 *pu8DataIn, u8 u8Size);
void vfnIICRandomRead(u8 u8SlaveAddress, u8 *pu8DataOut, u8 u8SizeOut,
		u8 *pu8DataIn, u8 u8SizeIn);
void vfnIICInterrupt(void);





/*****************************************************************************/
#endif
