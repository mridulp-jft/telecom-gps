/*
 * File:		Phased_PWM.c
 * Purpose:		Main process
 *
 * Description:
 *    This program generates two pulse width 
 * modulated signals with high true pulses using
 * separate channels of the same TPM module.  However,
 * the pulse width modulated signals are out of phase
 * from each other.
 *
 * Terminal Configuration:
 *
 * Baud rate - 19200
 * Data bits - 8
 * Parity    - None
 * Stop bits - 1
 * Control   - None
 *
 * TPM Configuration:
 * 
 * This project uses TPM0 for the showcased TPM module.  
 * The IRCLK is the source clock for the TPM0 module in
 * this example.  
 *
 * Channels 2 and 3 are used to generate the out of 
 * phase PWMs.  They are configured as follows:
 * 
 * Channel 2 - configured as an edge-aligned PWM
 * Channel 3 - configured for output compare with pin
 *             toggle functionality (when not using the LED outputs).
 * Channel 4 - configured for output compare with pin
 *             toggle functionality (when not using the LED outputs).
 *
 * Instructions:
 *    To change the Period of the pulse width modulated signals
 * change the define PULSE_PERIOD_TICS.  
 * To change the duty cycle of the PWMs, follow the directions 
 * displayed in the terminal display.  
 * 
 */

#include "common.h"
#include "stdio.h"
#include "uif.h"

#ifdef CMSIS
#include "start.h"
#endif


/******************************
 * Variables & Definitions
 *
 * USE_LED_LIGHTS - This definition configures the application to output 
 *     the PWMs to the on-board LEDs or to unused digital pins.  
 *
 ****************************************************************************
 * PULSE_PERIOD_TICS_DEFAULT - This defines the default period of both PWMs in 
 *     tics. For this example, the TPM uses the Fast IRC (@ 2MHz) for the 
 *     source. However, the TPM prescaler is used to divide the TPM source
 *     clock down by 32.  So each tic is 16 us.  
 *
 ****************************************************************************
 * Pulse_period_tics - This is the variable that holds the period of both
 *     PWMs in tics.  
 *
 ****************************************************************************
 * Chn2_pulse_width_pct - This variable holds the user input pulse width 
 *     for pulse #1 as a percentage of the period.  This pulse is the 0 
 *     count aligned PWM.  
 *
 ****************************************************************************
 * Chn2_pulse_width_tics - This variable hold the pulse width for pulse #1
 *     in tics.  It's value is derived from Chn2_pulse_width_pct. 
 *
 ****************************************************************************
 * Chn3_pulse_width_pct - This variable holds the user input pulse width 
 *     for pulse #2 (when NOT outputting the PWMs to the LEDs) as a percentage 
 *     of the period.  This pulse is the offset PWM.  
 *
 ****************************************************************************
 * Chn3_pulse_width_tics - This variable hold the pulse width for pulse #2
 *     in tics.  It's value is derived from Chn3_pulse_width_pct.
 *
 ****************************************************************************
 * Chn3_pulse_offset_pct - This variable holds the user input pulse offset 
 *     for pulse #2 as a percentage of the period.  This value cannot be 
 *     greater than or equal to 100 - Chn3_pulse_width_pct.  
 *
 ****************************************************************************
 * Chn3_pulse_offset_tics - This variable hold the pulse width for pulse #1
 *     in tics.  It's value is derived from Chn3_pulse_offset_pct.
 *
 ****************************************************************************
 * Chn4_pulse_width_pct - This variable holds the user input pulse width 
 *     for pulse #2 (when outputting the PWMs to the LEDs) as a percentage 
 *     of the period.  This pulse is the offset PWM.  
 *
 ****************************************************************************
 * Chn4_pulse_width_tics - This variable hold the pulse width for pulse #2
 *     in tics.  It's value is derived from Chn4_pulse_width_pct.
 *
 ****************************************************************************
 * Chn4_pulse_offset_pct - This variable holds the user input pulse offset 
 *     for pulse #2 as a percentage of the period.  This value cannot be 
 *     greater than or equal to 100 - Chn4_pulse_width_pct.  
 *
 ****************************************************************************
 * Chn4_pulse_offset_tics - This variable hold the pulse width for pulse #1
 *     in tics.  It's value is derived from Chn4_pulse_offset_pct.
 *
 ****************************************************************************
 * cmdline1 - This variable holds the user inputs which get converted to 
 *     the appropriate variable values.  
 *
 *****************************/

#define         USE_LED_LIGHTS                          // Define this to output PWMs to the LEDs

#define         PULSE_PERIOD_TICS_DEFAULT       40000  // PWM Period in Tics; 1 Tic = 0.5 us

uint16 Pulse_period_tics = PULSE_PERIOD_TICS_DEFAULT;

uint16 Chn2_pulse_width_pct = 0;       // PWM #1 pulse width as a percentage
uint16 Chn2_pulse_width_tics = 0;      // PWM #1 pulse width in timer tics. 

#ifdef USE_LED_LIGHTS

uint16 Chn4_pulse_width_pct = 0;
uint16 Chn4_pulse_width_tics = 0;

uint16 Chn4_pulse_offset_pct = 0;
uint16 Chn4_pulse_offset_tics = 0;

#else
uint16 Chn3_pulse_width_pct = 0;
uint16 Chn3_pulse_width_tics = 0;

uint16 Chn3_pulse_offset_pct = 0;
uint16 Chn3_pulse_offset_tics = 0;

#endif

static char cmdline1 [UIF_MAX_LINE];

void Configure_TPM(void);
void TPM0_IRQHandler(void);

/********************************************************************/
int main (void)
{
    	char ch, i, Pulse2InputValid = 0;
        int numargs = 0;
        
#ifdef CMSIS  // If we are conforming to CMSIS, we need to call start here
    start();
#endif
        
  	printf("\n\r\n\r*** Running the Phased_PWM project ***\n\r");
        ///////////////////////////////////////////////////////////////////////
        ///////////////////////////////////////////////////////////////////////
        //
        // Get the pulse width for Pulse #1. 
        //
        ///////////////////////////////////////////////////////////////////////
        ///////////////////////////////////////////////////////////////////////
        do
        {
            printf("\n\rEnter desired pulse width (as a percentage) for pulse #1 and press enter:  \n\r");
            numargs = 0;
            get_line(cmdline1);
            
            for (i=0; i<=3; i++)
            {
               if((cmdline1[i] >= 48) && (cmdline1[i] <= 57))
                   numargs++;
               else if (cmdline1[i] > 0)
               {
                   printf("Please enter only numbers. \n\n\r");
                   numargs = 3;
                   break;
               }
               else
                   break;
            }
            
            if (numargs == 0)
                printf("Please enter only numbers and then press enter.\n\n\r");
            if (numargs > 2)
                printf("Out of range value entered.  Valid range is 0-99 percent. \n\n\r");
            
        } while ((numargs > 2) && (numargs != 0));
        
        if (numargs == 2)
            Chn2_pulse_width_pct = ((cmdline1[0] - 48) *10) + (cmdline1[1] - 48);
        else
            Chn2_pulse_width_pct = cmdline1[0] - 48;
        Chn2_pulse_width_tics = (Pulse_period_tics * Chn2_pulse_width_pct)/100;
        
            
        do
        {
            ///////////////////////////////////////////////////////////////////////
            ///////////////////////////////////////////////////////////////////////
            //
            // Get the pulse width for Pulse #2.
            //
            ///////////////////////////////////////////////////////////////////////
            ///////////////////////////////////////////////////////////////////////
            do
            {
                printf("\n\rEnter desired pulse width (as a percentage) for pulse #2 and press enter:  \n\r");
                numargs = 0;
                get_line(cmdline1);
            
                for (i=0; i<=3; i++)
                {
                     if((cmdline1[i] >= 48) && (cmdline1[i] <= 57))
                        numargs++;
                else if (cmdline1[i] > 0)
                {
                    printf("Please enter only numbers. \n\n\r");
                    numargs = 3;
                    break;
                }
                else
                    break;
             }
            
             if (numargs == 0)
                 printf("Please enter only numbers and then press enter.\n\n\r");
             if (numargs > 2)
                 printf("Out of range value entered.  Valid range is 0-99 percent. \n\n\r");
            
            } while ((numargs > 2) && (numargs != 0));
        
#ifdef USE_LED_LIGHTS
            if (numargs == 2)
                Chn4_pulse_width_pct = ((cmdline1[0] - 48) *10) + (cmdline1[1] - 48);
            else
                Chn4_pulse_width_pct = cmdline1[0] - 48;
            Chn4_pulse_width_tics = (Pulse_period_tics * Chn4_pulse_width_pct) / 100;
        
#else
            if (numargs == 2)
                Chn3_pulse_width_pct = ((cmdline1[0] - 48) *10) + (cmdline1[1] - 48);
            else
                Chn3_pulse_width_pct = cmdline1[0] - 48;
            Chn3_pulse_width_tics = (Pulse_period_tics * Chn3_pulse_width_pct) / 100;
#endif
        
        
            ///////////////////////////////////////////////////////////////////////
            ///////////////////////////////////////////////////////////////////////
            //
            // Get offset for Pulse #2.
            //
            ///////////////////////////////////////////////////////////////////////
            ///////////////////////////////////////////////////////////////////////
            do
            {
                printf("\n\rEnter desired offset for pulse #2 (as a percentage of the period) and press enter:  \n\r");
                numargs = 0;
                get_line(cmdline1);
            
                for (i=0; i<=3; i++)
                {
                    if((cmdline1[i] >= 48) && (cmdline1[i] <= 57))
                       numargs++;
                    else if (cmdline1[i] > 0)
                    {
                        printf("Please enter only numbers. \n\n\r");
                        numargs = 3;
                        break;
                    }
                    else
                        break;
                }
            
                if (numargs == 0)
                    printf("Please enter only numbers and then press enter.\n\n\r");
                if (numargs > 2)
                    printf("Out of range value entered.  Valid range is 0-99 percent. \n\n\r");
            
            } while ((numargs > 2) && (numargs != 0));
        
#ifdef USE_LED_LIGHTS
            
            if (numargs == 2)
                Chn4_pulse_offset_pct = ((cmdline1[0] - 48) * 10) + (cmdline1[1] - 48);
            else
                Chn4_pulse_offset_pct = (cmdline1[0] - 48);
            Chn4_pulse_offset_tics = (Pulse_period_tics * Chn4_pulse_offset_pct) / 100; 
#else
            if (numargs == 2)
                Chn3_pulse_offset_pct = ((cmdline1[0] - 48) *10) + (cmdline1[1] - 48);
            else
                Chn3_pulse_offset_pct = (cmdline1[0] - 48);
            Chn3_pulse_offset_tics = (Pulse_period_tics * Chn3_pulse_offset_pct) / 100;
#endif
            
#ifdef USE_LED_LIGHTS
            if ((Chn4_pulse_offset_pct + Chn4_pulse_width_pct) >= 100)
            {
                printf("Invalid input for Pulse #2 characteristics!\n\n\r");
                Pulse2InputValid = 0;
            }
            else
            {
                Pulse2InputValid = 1;
                Chn4_pulse_width_tics = Chn4_pulse_width_tics + Chn4_pulse_offset_tics;
            }
#else
            if ((Chn3_pulse_offset_pct + Chn3_pulse_width_pct) >= 100)
            {
                printf("Invalid input for Pulse #2 characteristics!\n\n\r");
                Pulse2InputValid = 0;
            }
            else
            {
                Pulse2InputValid = 1;
                Chn3_pulse_width_tics = Chn3_pulse_width_tics + Chn3_pulse_offset_tics;
            }
#endif
        }
        while (Pulse2InputValid == 0);
        Configure_TPM();
        
	while(1)
	{
		ch = in_char();
		out_char(ch);
	} 
}
/********************************************************************/

void Configure_TPM(void)
{
    // Enable the Clock gate to the MODULE!!
    SIM_SCGC6 |= SIM_SCGC6_TPM0_MASK;
    SIM_SCGC5 |= SIM_SCGC5_PORTD_MASK;
    
    // Ensure that the module is disabled first
    TPM0_SC = 0x00;
    
    /////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////
    //                       
    //                           PIN CONFIGURATION
    //
    ////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    
    // Configure PTD2 and 3 for TPM functionality
#ifdef USE_LED_LIGHTS
    PORTE_PCR29 = PORT_PCR_MUX(3);
    PORTE_PCR31 = PORT_PCR_MUX(3);
#else
    PORTD_PCR2 = PORT_PCR_MUX(4);
    PORTD_PCR3 = PORT_PCR_MUX(4);
#endif
    
    /////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////
    //                       
    //                           CLOCK CONFIGURATION
    //
    ////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    
    // Enable the IRCLK
    MCG_C1 |= MCG_C1_IRCLKEN_MASK;
    
    // Set the IRCLK to fast clock
    MCG_C2 |= MCG_C2_IRCS_MASK;
    
    // Set the TPM clock source to the IRCLK
    SIM_SOPT2 &= ~SIM_SOPT2_TPMSRC_MASK;
    SIM_SOPT2 |= SIM_SOPT2_TPMSRC(3);
    
    // Select a Prescale value of 32 to get a 16 us resolution
    TPM0_SC |= TPM_SC_PS(5);
    
    /////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////
    //                       
    //                           CHANNEL CONFIGURATIONS
    //
    ////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    
    // Configure module registers
    TPM0_C2SC = TPM_CnSC_CHF_MASK;
    
#ifdef USE_LED_LIGHTS
    TPM0_C4SC = TPM_CnSC_CHF_MASK;
#else
    TPM0_C3SC = TPM_CnSC_CHF_MASK;
#endif
    
    // Turn on Debug Mode
    TPM0_CONF |= TPM_CONF_DBGMODE(3);
    
    /////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////
    //                       
    //                           CHANNEL 2 CONFIGURATIONS
    //                           (PULSE 1 CONFIG)
    //
    ////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    
    // Setup TPM0 Ch2 for Edge aligned PWM
    TPM0_C2SC = (TPM_CnSC_MSB_MASK
                 | TPM_CnSC_ELSB_MASK);
    
    // Initialize Channel value register
    TPM0_C2V = Chn2_pulse_width_tics;
    
    /////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////
    //                       
    //                           CHANNEL 3/4 CONFIGURATIONS
    //                           (PULSE 2 CONFIG)
    //
    ////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
#ifdef USE_LED_LIGHTS
    // Setup TPM0 Ch4 for Output Compare Mode (Toggle on Match)
    TPM0_C4SC = (TPM_CnSC_MSA_MASK
                 | TPM_CnSC_ELSA_MASK
                 | TPM_CnSC_CHIE_MASK);
    
    // Initialize Channel value register
    TPM0_C4V = Chn4_pulse_offset_tics;
    
#else
    // Setup TPM0 Ch3 for Output Compare Mode (Toggle on Match)
    TPM0_C3SC = (TPM_CnSC_MSA_MASK
                 | TPM_CnSC_ELSA_MASK
                 | TPM_CnSC_CHIE_MASK);
    
    // Initialize Channel value register
    TPM0_C3V = Chn3_pulse_offset_tics;
    
#endif
    
    
    // Configure the MOD register
    TPM0_MOD = Pulse_period_tics;
    
    TPM0_CNT = 0;
    
    // Enable TPM0 IRQ (IRQ #17)
    enable_irq(17);
    
    // Finally Enable the TPM module
    TPM0_SC |= TPM_SC_CMOD(1);
}

void TPM0_IRQHandler(void)
{
#ifdef USE_LED_LIGHTS
    if((TPM0_STATUS & TPM_STATUS_CH4F_MASK) == TPM_STATUS_CH4F_MASK)
    {
        TPM0_STATUS |= TPM_STATUS_CH4F_MASK;
        if(TPM0_C4V == Chn4_pulse_offset_tics)
            TPM0_C4V = Chn4_pulse_width_tics;
        else
            TPM0_C4V = Chn4_pulse_offset_tics;
    }
    
#else
    if((TPM0_STATUS & TPM_STATUS_CH3F_MASK) == TPM_STATUS_CH3F_MASK)
    {
        TPM0_STATUS |= TPM_STATUS_CH3F_MASK;
        if(TPM0_C3V == Chn3_pulse_offset_tics)
            TPM0_C3V = Chn3_pulse_width_tics;
        else
            TPM0_C3V = Chn3_pulse_offset_tics;
    }
    
#endif
}
