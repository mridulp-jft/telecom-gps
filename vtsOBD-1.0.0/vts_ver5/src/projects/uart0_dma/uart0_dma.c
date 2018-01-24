/*
 * File:		uart0_dma.c
 * Purpose:		Main process
 * Author:              Freescale Semiconductor
 *                      Oak Hill Microcontroller Apps
 *                      B45635
 *
 */

#include "common.h"
#include "uart.h"

#define TRANSFER_LENGTH  0x1A

#define DMA0_DESTINATION  0x4006A007
#define DMA0_SOURCE_ADDR  0x4006A007

void DMA0_init(void);
void UART0_DMA_init(void);
void DMA0_IRQHandler(void);
void GPIO_init(void);
uint8 dma0_done = 0;

/********************************************************************/
int main (void)
{
  
    printf("\n\rRunning the uart0_dma project.\n\r");      
        
    
    enable_irq(0);
    DMA0_init();
    UART0_DMA_init();        
        
    while(1){
 
        if(dma0_done){
            printf("\nDMA_ISR, BCR Reset.\n");
            dma0_done = 0;
        }          
    }            
}
/********************************************************************/


/*****************************************
 ***                                   ***
 ***  DMA0 intialization for UART0 RX  ***
 ***                                   ***
 *****************************************/
void DMA0_init(void){
  
  /* Enable Clock gating for the DMA and DMA MUX */
  SIM_SCGC6 |= SIM_SCGC6_DMAMUX_MASK;
  SIM_SCGC7 |= SIM_SCGC7_DMA_MASK;
  
  /* Create pointer & variable for reading DMA_DSR register */
  volatile uint32_t* dma_dsr_bcr0_reg = &DMA_DSR_BCR0;
  uint32_t dma_dsr_bcr0_val = *dma_dsr_bcr0_reg;
  
  DMAMUX0_CHCFG0 = 0x00;   //Disable DMA MUX channel first
  
  /* Check for pending erors and/or the done bit */
  if (((dma_dsr_bcr0_val & DMA_DSR_BCR_DONE_MASK) == DMA_DSR_BCR_DONE_MASK) 
      | ((dma_dsr_bcr0_val & DMA_DSR_BCR_BES_MASK) == DMA_DSR_BCR_BES_MASK) 
      | ((dma_dsr_bcr0_val & DMA_DSR_BCR_BED_MASK) == DMA_DSR_BCR_BED_MASK)
      | ((dma_dsr_bcr0_val & DMA_DSR_BCR_CE_MASK) == DMA_DSR_BCR_CE_MASK))
    DMA_DSR_BCR0 |= DMA_DSR_BCR_DONE_MASK;     //Clear pending erors and/or the done bit
 

  DMA_SAR0 = DMA0_SOURCE_ADDR;   //Set source address to UART0_D REG 
  
  DMA_DSR_BCR0 = DMA_DSR_BCR_BCR(TRANSFER_LENGTH);   //Set BCR to know how many bytes to transfer
  
  DMA_DCR0 &= ~(DMA_DCR_SSIZE_MASK | DMA_DCR_DSIZE_MASK);    //Clear source size and destination size fields
  
  /* Set DMA as follows:
         Source size is 8-bit size
         Destination size is 8-bit size
         Cycle steal mode
         External requests are enabled
  */
  
  DMA_DCR0 |= (DMA_DCR_SSIZE(1)
               | DMA_DCR_DSIZE(1)
               | DMA_DCR_CS_MASK  
               | DMA_DCR_ERQ_MASK
               | DMA_DCR_EINT_MASK);

  
  DMA_DAR0 = DMA0_DESTINATION;    //Set source address to UART0_D REG
  
  DMAMUX0_CHCFG0 = 2;   //Select UART0 RX as channel source

  DMAMUX0_CHCFG0 |= DMAMUX_CHCFG_ENBL_MASK;   //Enable the DMA MUX channel
  
}

void UART0_DMA_init(void){
  
  UART0_C2 &= ~(UART0_C2_TE_MASK | UART0_C2_RE_MASK);   //Disable UART0
  
  UART0_C5 |= UART0_C5_RDMAE_MASK;   // Turn on DMA request for UART0
  
  UART0_C2 |= (UART0_C2_TE_MASK | UART0_C2_RE_MASK);   //Enable UART0
  
}

void DMA0_IRQHandler(void){ 
  
  /* Create pointer & variable for reading DMA_DSR register */
  volatile uint32_t* dma_dsr_bcr0_reg = &DMA_DSR_BCR0;
  uint32_t dma_dsr_bcr0_val = *dma_dsr_bcr0_reg;
  
  if (((dma_dsr_bcr0_val & DMA_DSR_BCR_DONE_MASK) == DMA_DSR_BCR_DONE_MASK) 
      | ((dma_dsr_bcr0_val & DMA_DSR_BCR_BES_MASK) == DMA_DSR_BCR_BES_MASK) 
      | ((dma_dsr_bcr0_val & DMA_DSR_BCR_BED_MASK) == DMA_DSR_BCR_BED_MASK)
        | ((dma_dsr_bcr0_val & DMA_DSR_BCR_CE_MASK) == DMA_DSR_BCR_CE_MASK)){
     
          
    DMA_DSR_BCR0 |= DMA_DSR_BCR_DONE_MASK;                //Clear Done bit
    DMA_DSR_BCR0 = DMA_DSR_BCR_BCR(TRANSFER_LENGTH);      //Reset BCR
    dma0_done = 1;
  }  
  
}
