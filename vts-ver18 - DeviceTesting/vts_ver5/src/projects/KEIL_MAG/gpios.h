/****************************************************************************************************
 *                                                                                                  *                
 *    File:  gpios.h                                                                             *
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

#define IGNITION 1
#define IGNITION_SHIFT (1U << IGNITION) 

#define FUEL 2
#define FUEL_SHIFT (1U << FUEL) 


#define GREEN 31
#define GREEN_SHIFT (1U << GREEN)

#define BLUE 5
#define BLUE_SHIFT (1U << BLUE)

#define RESET 5
#define RESET_SHIFT (1U << RESET)

#define REDBAT 6
#define REDBAT_SHIFT (1U << REDBAT)

#define GREENBAT 7
#define GREENBAT_SHIFT (1U << GREENBAT)

#define BLUEBAT 8
#define BLUEBAT_SHIFT (1U << BLUEBAT)

#define RESET_OFF (GPIOC_PCOR = RESET_SHIFT)
#define RESET_ON (GPIOC_PSOR = RESET_SHIFT)
#define RESET_TOGGLE (GPIOC_PTOR = RESET_SHIFT)


#define IGNITION_ON (GPIOA_PCOR = IGNITION_SHIFT)
#define IGNITION_OFF (GPIOA_PSOR = IGNITION_SHIFT)
#define IGNITION_TOGGLE (GPIOA_PTOR = IGNITION_SHIFT)
#define FUEL_ON (GPIOA_PCOR = FUEL_SHIFT)
#define FUEL_OFF (GPIOA_PSOR = FUEL_SHIFT)
#define FUEL_TOGGLE (GPIOA_PTOR = FUEL_SHIFT)


#define REDBAT_ON (GPIOC_PCOR = REDBAT_SHIFT)
#define REDBAT_OFF (GPIOC_PSOR = REDBAT_SHIFT)
#define REDBAT_TOGGLE (GPIOC_PTOR = REDBAT_SHIFT)

#define GREENBAT_ON (GPIOC_PCOR = GREENBAT_SHIFT)
#define GREENBAT_OFF (GPIOC_PSOR = GREENBAT_SHIFT)
#define GREENBAT_TOGGLE (GPIOC_PTOR = GREENBAT_SHIFT)

#define BLUEBAT_ON (GPIOC_PCOR = BLUEBAT_SHIFT)
#define BLUEBAT_OFF (GPIOC_PSOR = BLUEBAT_SHIFT)
#define BLUEBAT_TOGGLE (GPIOC_PTOR = BLUEBAT_SHIFT)


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
#define PORTD_EVENT 0
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
