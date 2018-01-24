/****************************************************************************************************/
/**
Copyright (c) 2008 Freescale Semiconductor
Freescale Confidential Proprietary
\file       GPIO_HAL.h
\brief
\author     Freescale Semiconductor
\author     Guadalajara Applications Laboratory RTAC Americas
\author     B22385
\version    0.1
\date       Dec 7, 2011
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

#ifndef GPIO_HAL_H_
#define GPIO_HAL_H_
/*****************************************************************************************************
* Include files
*****************************************************************************************************/


/*****************************************************************************************************
* Declaration of project wide TYPES
*****************************************************************************************************/

/*****************************************************************************************************
* Definition of project wide VARIABLES
*****************************************************************************************************/
extern u32 gu32PortStatus;
/*****************************************************************************************************
* Definition of project wide MACROS / #DEFINE-CONSTANTS
*****************************************************************************************************/
typedef enum ePortStatus
{
	PORTA_EVENT = 0,
	PORTB_EVENT,
	PORTC_EVENT,
	PORTD_EVENT,
	PORTE_EVENT,
	PORTF_EVENT
}eProtStatus;

#define SW_MODE_PIN	  (4)
#define SW_MODE_PIN_C (3)

#define PORTA_EVENT_ACK	(gu32PortStatus & (1<<PORTA_EVENT))
#define PORTE_EVENT_ACK	(gu32PortStatus & (1<<PORTE_EVENT))

#define PORTA_CLEAR_EVENT	(gu32PortStatus &= ~(1<<PORTA_EVENT))
#define PORTE_CLEAR_EVENT	(gu32PortStatus &= ~(1<<PORTE_EVENT))
/*****************************************************************************************************
* Declaration of project wide FUNCTIONS
*****************************************************************************************************/
void vfnGPIO_Init(void);
void vfnPortAISR(void);
void vfnPortEISR(void);
/*****************************************************************************************************
* Declaration of module wide FUNCTIONs - NOT for use in other modules
*****************************************************************************************************/

#endif /*GPIO_HAL_H_*/

