/*
 * File:        sysinit.c
 * Purpose:     Kinetis L Family Configuration
 *              Initializes processor to a default state
 *
 * Notes:
 *
 *
 */

#include "common.h"
#include "sysinit.h"
#include "UART.h"

/********************************************************************/

/* System clock frequency variables - Represents the current system clock
 * settings
 */
int mcg_clk_hz;
int mcg_clk_khz;
int core_clk_khz;
int periph_clk_khz;
int pll_clk_khz;
int uart0_clk_khz;
uint32 uart0_clk_hz;
extern uint32_t SystemCoreClock;



/********************************************************************/
void sysinit (void)
{
        /* Enable all of the port clocks. These have to be enabled to configure
         * pin muxing options, so most code will need all of these on anyway.
         */
        SIM_SCGC5 |= (SIM_SCGC5_PORTA_MASK
                      | SIM_SCGC5_PORTB_MASK
                      | SIM_SCGC5_PORTC_MASK
                      | SIM_SCGC5_PORTD_MASK
                      | SIM_SCGC5_PORTE_MASK );
        
        // Release hold with ACKISO:  Only has an effect if recovering from VLLS1, VLLS2, or VLLS3
        // if ACKISO is set you must clear ackiso before calling pll_init 
        //    or pll init hangs waiting for OSC to initialize
        // if osc enabled in low power modes - enable it first before ack
        // if I/O needs to be maintained without glitches enable outputs and modules first before ack.
        if (PMC_REGSC &  PMC_REGSC_ACKISO_MASK)
        PMC_REGSC |= PMC_REGSC_ACKISO_MASK;
        
#ifdef ENABLE_CLKOUT
        // Initialize trace clk functionality
        clk_out_init();
#endif
				
#ifndef CMSIS
       /* Ramp up the system clock */
       /* Set the system dividers */
       /* NOTE: The PLL init will not configure the system clock dividers,
        * so they must be configured appropriately before calling the PLL
        * init function to ensure that clocks remain in valid ranges.
        */  
        SIM_CLKDIV1 = ( 0
                        | SIM_CLKDIV1_OUTDIV1(OUTDIV1_VAL)
                        | SIM_CLKDIV1_OUTDIV4(OUTDIV4_VAL) );
 
#if defined(NO_PLL_INIT)
        // If PLL initialization is not desired, set FLL to 48 MHz clock in default FEI mode
        // Set DMX32 and DRST_DRS values accordingly
        MCG_C4 = ((MCG_C4 & ~(MCG_C4_DRST_DRS_MASK)) | ((FLL_DMX32 << MCG_C4_DMX32_SHIFT)
                                                     | (FLL_DRST_DRS << MCG_C4_DRST_DRS_SHIFT)));
        if (FLL_DMX32 == 0)
            mcg_clk_hz = 640 * (FLL_DRST_DRS + 1) * FLL_REF_FREQ;
        else 
            mcg_clk_hz = 732 * (FLL_DRST_DRS + 1) * FLL_REF_FREQ;
        
        SIM_SOPT2 &= ~SIM_SOPT2_PLLFLLSEL_MASK; // clear PLLFLLSEL to select the FLL for this clock source
        
        uart0_clk_khz = (mcg_clk_hz / 1000); // the uart0 clock frequency will equal the FLL frequency
        
        SIM_SOPT2 = ((SIM_SOPT2 & ~SIM_SOPT2_UART0SRC_MASK) | SIM_SOPT2_UART0SRC(1));
       
#else 
       /* Initialize PLL */
       /* PLL will be the source for MCG CLKOUT so the core, system, and flash clocks are derived from it */ 
       mcg_clk_hz = pll_init(CLK0_FREQ_HZ,  /* CLKIN0 frequency */
                             LOW_POWER,     /* Set the oscillator for low power mode */
                             CLK0_TYPE,     /* Crystal or canned oscillator clock input */
                             PLL0_PRDIV,    /* PLL predivider value */
                             PLL0_VDIV,     /* PLL multiplier */
                             MCGOUT);       /* Use the output from this PLL as the MCGOUT */
														 
														 
			/* Check the value returned from pll_init() to make sure there wasn't an error */
       if (mcg_clk_hz < 0x100)
         while(1);
       
       SIM_SOPT2 |= SIM_SOPT2_PLLFLLSEL_MASK; // set PLLFLLSEL to select the PLL for this clock source
       
       uart0_clk_khz = ((mcg_clk_hz / 2) / 1000); // UART0 clock frequency will equal half the PLL frequency
       
       SIM_SOPT2 = ((SIM_SOPT2 & ~SIM_SOPT2_UART0SRC_MASK) | SIM_SOPT2_UART0SRC(1));
#endif 
			 
#else
mcg_clk_hz = SystemCoreClock;
			 
if (CLOCK_SETUP == 3)
{
	// If PLL initialization is not desired, set FLL to 48 MHz clock in default FEI mode
  MCG_C4 |= (MCG_C4_DRST_DRS(1) | MCG_C4_DMX32_MASK);
        
  SIM_SOPT2 &= ~SIM_SOPT2_PLLFLLSEL_MASK; // clear PLLFLLSEL to select the FLL for this clock source
        
  uart0_clk_khz = (mcg_clk_hz / 1000); // the uart0 clock frequency will equal the FLL frequency
        
  SIM_SOPT2 = ((SIM_SOPT2 & ~SIM_SOPT2_UART0SRC_MASK) | SIM_SOPT2_UART0SRC(1));
}
else
{      
  SIM_SOPT2 |= SIM_SOPT2_PLLFLLSEL_MASK; // set PLLFLLSEL to select the PLL for this clock source
    
  uart0_clk_khz = ((mcg_clk_hz / 2) / 1000); // UART0 clock frequency will equal half the PLL frequency
       
  SIM_SOPT2 = ((SIM_SOPT2 & ~SIM_SOPT2_UART0SRC_MASK) | SIM_SOPT2_UART0SRC(1));
}
#endif    

	/*
         * Use the value obtained from the pll_init function to define variables
	 * for the core clock in kHz and also the peripheral clock. These
	 * variables can be used by other functions that need awareness of the
	 * system frequency.
	 */
        mcg_clk_khz = mcg_clk_hz / 1000;
				core_clk_khz = mcg_clk_khz / (((SIM_CLKDIV1 & SIM_CLKDIV1_OUTDIV1_MASK) >> 28)+ 1);
        periph_clk_khz = core_clk_khz / (((SIM_CLKDIV1 & SIM_CLKDIV1_OUTDIV4_MASK) >> 16)+ 1);
        
#ifdef USE_ABORT_BUTTON
        /* Enable pin interrupt for the abort button - PTA4 */
        /* This pin could also be used as the NMI interrupt, but since the NMI
         * is level sensitive each button press will cause multiple interrupts.
         * Using the GPIO interrupt instead means we can configure for an edge
         * sensitive interrupt instead = one interrupt per button press.
         */
       // enable_abort_button();
#endif
        
        
        /*
         * Configure the UART terminal port pins.  These definitions are 
         * defined in the platform header file.
         */
        
        PORT_PCR_REG(TERM_PIN_PORT, TERM_RX_PIN) = PORT_PCR_MUX(TERM_MUX_ALT);
        PORT_PCR_REG(TERM_PIN_PORT, TERM_TX_PIN) = PORT_PCR_MUX(TERM_MUX_ALT);
				
				PORT_PCR_REG(TERM_PIN_PORT1, TERM_RX_PIN1) = PORT_PCR_MUX(TERM_MUX_ALT1);
        PORT_PCR_REG(TERM_PIN_PORT1, TERM_TX_PIN1) = PORT_PCR_MUX(TERM_MUX_ALT1);
				
				PORT_PCR_REG(TERM_PIN_PORT2, TERM_RX_PIN2) = PORT_PCR_MUX(TERM_MUX_ALT2);
        PORT_PCR_REG(TERM_PIN_PORT2, TERM_TX_PIN2) = PORT_PCR_MUX(TERM_MUX_ALT2);
        
  	/* UART0 is clocked asynchronously to the core clock, but all other UARTs are
         * clocked from the peripheral clock. So we have to determine which clock
         * to send to the UART_init function.
         */

            uart0_init (UART0_BASE_PTR, uart0_clk_khz, TERMINAL_BAUD);

						uart_init (UART1_BASE_PTR, periph_clk_khz, TERMINAL_BAUD1);

            uart_init (UART2_BASE_PTR, periph_clk_khz, TERMINAL_BAUD2);

}
/********************************************************************/
void enable_abort_button(void)
{
    /* Configure the PTA4 pin for its GPIO function */
    PORTA_PCR4 = PORT_PCR_MUX(0x1); // GPIO is alt1 function for this pin
    
    /* Configure the PTA4 pin for rising edge interrupts */
    PORTA_PCR4 |= PORT_PCR_IRQC(0x9); 
    
#ifdef CMSIS
    /* Enable the associated IRQ in the NVIC */
    enable_irq(PORTA_IRQn);      
#else
	  enable_irq(30); 
#endif	
}
/********************************************************************/

/********************************************************************/
void clk_out_init(void)
{

    // If you are using UART1 for serial communications do not
    // initialize the clock out function or you may break the UART!
    if (TERM_PORT_NUM != 1)
    {
        /* Enable the CLKOUT function on PTC3 (alt5 function) */
	PORTC_PCR3 = ( PORT_PCR_MUX(0x5));
        
        /* Select the CLKOUT in the SMI_SOPT2 mux to be bus clk*/
        SIM_SOPT2 |= SIM_SOPT2_CLKOUTSEL(2);
    }
        
}