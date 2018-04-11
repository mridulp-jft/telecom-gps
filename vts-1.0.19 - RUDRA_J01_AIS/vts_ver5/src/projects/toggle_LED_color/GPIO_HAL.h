/****************************************************************************************************
 *                                                                                                  *                
 *    File:  GPIO_HAL.h                                                                             *
 *   Brief:  GPIO hardware abstraction layer for toggle_LED_color.c                                 *
 *  Author:  Freescale Semiconductor                                                                *
 *           Oak Hill Microcontroller Apps                                                          *
 *           B45635                                                                                 *
 * Version:  0.1                                                                                    *
 *    Date:  May 24, 2013                                                                           *
 *                                                                                                  *
 ****************************************************************************************************/

#ifndef GPIO_HAL_H_
#define GPIO_HAL_H_

#include "common.h"
#include "isr.h"

/*********************************************
 ***    Macros for GPIO bit manipulation   ***
 *********************************************/

#define RED 29
#define RED_SHIFT (1U << RED)

#define GREEN 31
#define GREEN_SHIFT (1U << GREEN)

#define BLUE 5
#define BLUE_SHIFT (1U << BLUE)

#define RED_ON (GPIOE_PCOR = RED_SHIFT)
#define RED_OFF (GPIOE_PSOR = RED_SHIFT)
#define RED_TOGGLE (GPIOE_PTOR = RED_SHIFT)

#define GREEN_ON (GPIOE_PCOR = GREEN_SHIFT)
#define GREEN_OFF (GPIOE_PSOR = GREEN_SHIFT)
#define GREEN_TOGGLE (GPIOE_PTOR = GREEN_SHIFT)

#define BLUE_ON (GPIOD_PCOR = BLUE_SHIFT)
#define BLUE_OFF (GPIOD_PSOR = BLUE_SHIFT)
#define BLUE_TOGGLE (GPIOD_PTOR = BLUE_SHIFT)

/************************************************************
 ***    Project wide variable for port interrupt status   ***
 ************************************************************/

extern uint32_t gu32PortStatus;

/**********************************************
 ***    Macros for SW1 interrupt handling   ***
 **********************************************/

#define SW_PIN 3
#define PORTC_EVENT 0
#define PORTC_EVENT_ACK	(gu32PortStatus & (1 << PORTC_EVENT))
#define PORTC_CLEAR_EVENT (gu32PortStatus &= ~(1 << PORTC_EVENT))

/**********************************
 ***    Function definitions    ***
 **********************************/

void LED_init(void);
void SW1_init(void);
void LED_state(void);

#ifdef CMSIS
void PORTD_IRQHandler(void);
void PORTC_action(void);
#else
void portc_isr(void);
#endif

#endif
