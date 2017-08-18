/******************************************************************************
* File:    isr.h
* Purpose: Define interrupt service routines referenced by the vector table.
* Note: Only "vectors.c" should include this header file.
******************************************************************************/

#ifndef __ISR_H
#define __ISR_H 1


/* Example */
/*
#undef  VECTOR_101
#define VECTOR_101 lpt_isr


// ISR(s) are defined in your project directory.
extern void lpt_isr(void);
*/

#undef  VECTOR_016
#define VECTOR_016 DMA0_IRQHandler

#undef  VECTOR_047
#define VECTOR_047 PORTD_IRQHandler

extern void PORTD_IRQHandler(void);

extern void DMA0_IRQHandler(void);


#endif  //__ISR_H

/* End of "isr.h" */
