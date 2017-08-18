/****************************************************************************************************/
/**
Copyright (c) 2008 Freescale Semiconductor
Freescale Confidential Proprietary
\file       GPIO_HAL.c
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
* Include files
*****************************************************************************************************/
#include <MKL26Z4.H>
#include "ProjectTypes.h"
#include "GPIO_HAL.h"
#include "common.h"
/*****************************************************************************************************
* Declaration of module wide FUNCTIONs - NOT for use in other modules
*****************************************************************************************************/

/*****************************************************************************************************
* Definition of module wide MACROs / #DEFINE-CONSTANTs - NOT for use in other modules
*****************************************************************************************************/
#define PORT_IRQ	(PORTA_IRQn)
/*****************************************************************************************************
* Declaration of module wide TYPEs - NOT for use in other modules
*****************************************************************************************************/

/*****************************************************************************************************
* Definition of module wide VARIABLEs - NOT for use in other modules
*****************************************************************************************************/
u32 gu32PortStatus = 0;
/*****************************************************************************************************
* Definition of module wide (CONST-) CONSTANTs - NOT for use in other modules
*****************************************************************************************************/

/*****************************************************************************************************
* Code of project wide FUNCTIONS
*****************************************************************************************************/
void vfnGPIO_Init(void)
{
	SIM_SCGC5 |= SIM_SCGC5_PORTA_MASK;

	#ifdef TOWER
	/* Configure SW 1 */
	PORTA_PCR4 = PORT_PCR_IRQC(10)|PORT_PCR_PE_MASK|PORT_PCR_PS_MASK|PORT_PCR_MUX(1);
	#else
	PORTC_PCR3 = PORT_PCR_IRQC(10)|PORT_PCR_PE_MASK|PORT_PCR_PS_MASK|PORT_PCR_MUX(1);
	#endif
	

	/* Configure SW 2 */
	//PORTE->PCR[26] = PORT_PCR_IRQC(10)|PORT_PCR_PE_MASK|PORT_PCR_PS_MASK|PORT_PCR_MUX(1);

	#ifdef TOWER
	enable_irq(PORTA_IRQn);
	#else
	enable_irq(PORTD_IRQn);
	#endif


	//PORTA_PCR11 = PORT_PCR_MUX(1);

	//GPIOC_PDDR |= (1 << 0);
	//GPIOA_PDDR |= (1 << 11);
	//GPIOA_PTOR |= (1 << 11);

}


void PORTA_IRQHandler(void)
{
	if(PORTA_ISFR & (1<<SW_MODE_PIN))
	{
		PORTA_ISFR |= (1<<SW_MODE_PIN);
		gu32PortStatus |= (1<<PORTA_EVENT);
	}
}

void PORTD_IRQHandler(void)
{
	if(PORTC_ISFR & (1<<SW_MODE_PIN_C))
	{
		PORTC_ISFR |= (1<<SW_MODE_PIN_C);
		gu32PortStatus |= (1<<PORTA_EVENT);
	}
}


