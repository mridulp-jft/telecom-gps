/****************************************************************************************************/
/**
Copyright (c) 2011 Freescale Semiconductor
Freescale Confidential Proprietary
\file       IIC_HAL.c
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
* Include files
*****************************************************************************************************/
#include "ProjectTypes.h"
#include <MKL26Z4.H>
#include "IIC_HAL.h"
#include "common.h"
/*****************************************************************************************************
* Declaration of module wide FUNCTIONs - NOT for use in other modules
*****************************************************************************************************/
void vfnIICStateIdle(void);
void vfnIICStateStartW(void);
void vfnIICStateStartR(void);
void vfnIICStateDataW(void);
void vfnIICStateDataR(void);
void vfnIICStateRestart(void);
void vfnIICStateStop(void);

/*****************************************************************************************************
* Definition of module wide (CONST-) CONSTANTs - NOT for use in other modules
*****************************************************************************************************/
void (*const vfnapIICDriver[])(void) =
{
    vfnIICStateIdle,
    vfnIICStateStartW,
    vfnIICStateStartR,
    vfnIICStateDataW,
    vfnIICStateDataR,
    vfnIICStateRestart,
    vfnIICStateStop,
};
/*****************************************************************************************************
* Declaration of module wide TYPEs - NOT for use in other modules
*****************************************************************************************************/
/*!
    \enum eIICStates
    \brief IIC state machine states
*/
typedef enum
{
    IIC_IDLE_STATE = 0,
    IIC_START_W_STATE,
    IIC_START_R_STATE,
    IIC_DATA_W_STATE,
    IIC_DATA_R_STATE,
    IIC_RESTART_STATE,
    IIC_STOP_STATE
} eIICStates;
/*!
    \enum eIICFlags
    \brief IIC state machine states
*/
typedef enum
{
    FLAG_TCF = 0,
    FLAG_ARBL,
    FLAG_RANDOMREAD,
    FLAG_ERROR
}eIICFlags;
/*****************************************************************************************************
* Definition of project wide VARIABLEs
*****************************************************************************************************/
/*!
    \var u8IICDriverStatus
    \brief Reflects the current driver status to be used by upper layers
*/
volatile u8 u8IICDriverStatus;
/*!
    \var sIICStateMachine
    \brief Reflects state machine current, next, prev and error states
*/
sSM sIICStateMachine;
/*****************************************************************************************************
* Definition of module wide VARIABLEs - NOT for use in other modules
*****************************************************************************************************/

/*!
    \var gu8SlaveAddress
    \brief Local copy of the slave address to be used on read or write commands
*/
static u8 gu8SlaveAddress;
/*!
    \var gpu8DataOut
    \brief Stores the output buffer from a write command
*/
static u8 *gpu8DataOut;
/*!
    \var gu8SizeOut
    \brief Stores the amount of data in bytes for output
*/
static u8 gu8SizeOut;
/*!
    \var gpu8DataIn
    \brief Stores the buffer used on read command
*/
static u8 *gpu8DataIn;
/*!
    \var gu8SizeIn
    \brief Stores the amount of data in bytes to read
*/
static u8 gu8SizeIn;
/*!
    \var gu8IICStateMachineFlags
    \brief Internal flags
*/
static u8 gu8IICStateMachineFlags;

/*****************************************************************************************************
* Code of project wide FUNCTIONS
*****************************************************************************************************/

/****************************************************************************************************/
/*!
      \fn void vfnIICInit(void)
      \brief  Initializes IIC module and pins
      \return None
*/
void vfnIICInit(void)
{
	SIM_SCGC4 |= SIM_SCGC4_I2C0_MASK;
    SIM_SCGC5 |= SIM_SCGC5_PORTE_MASK|SIM_SCGC5_PORTB_MASK;

	/* configure IIC registers */
    IIC_CLOCK_RATE(IIC_CLOCK_RATE_VALUE);
    IIC_CLOCK_DIV(IIC_CLOCK_DIV_VALUE);

    IIC_CONTROL_REGISTER = I2C_C1_IICEN_MASK | I2C_C1_IICIE_MASK; //enable IIC with interrupts
    /* initialize to idle all state machine variables */
	u8IICDriverStatus |= (1<<IIC_FLAGS_IDLE);
    sIICStateMachine.ActualState = IIC_IDLE_STATE;
    sIICStateMachine.NextState = IIC_IDLE_STATE;
    sIICStateMachine.PrevState = IIC_IDLE_STATE;

	/*Multiplexing of the IIC pin signals PTB0(SCL) and PTE25(SDA) with open drain enabled*/
	PORTB_PCR0 = PORT_PCR_MUX(2);
	
	#ifdef TOWER
	PORTE_PCR25 = PORT_PCR_MUX(5);
	#else
	PORTB_PCR1 = PORT_PCR_MUX(2);
	#endif

	/* enable IIC IRQ */
	enable_irq(IIC_IRQ);
}

/****************************************************************************************************/
/*!
	\fn void vfnIICWrite(u8 u8SlaveAddress, u8 *pu8DataOut, u8 u8Size)
	\brief  Writes the data to the selected slave address
	\param	u8SlaveAddress: Bus address of the desired device
	\param	pu8DataOut: Pointer to the buffer containing the output data
	\param  u8Size: Amount of data to be sent in bytes
	\return None
*/
void vfnIICWrite(u8 u8SlaveAddress, u8 *pu8DataOut, u8 u8Size)
{
    /* Copy all the parameters to the driver variables to be used by the state machine */
	gu8SlaveAddress = u8SlaveAddress;
    gpu8DataOut = pu8DataOut;
    gu8SizeOut = u8Size;
    sIICStateMachine.PrevState = sIICStateMachine.ActualState;
    gu8IICStateMachineFlags = 0;
    sIICStateMachine.ActualState  = IIC_START_W_STATE;
    u8IICDriverStatus = (1<<IIC_FLAGS_BUSY);
}

/****************************************************************************************************/
/*!
	\fn void vfnIICRead(u8 u8SlaveAddress, u8 *pu8DataIn, u8 u8Size)
	\brief  Reads data from the selected slave address
	\param	u8SlaveAddress: Bus address of the desired device
	\param	pu8DataIn: Pointer to the buffer that is used to store the data
	\param  u8Size: Amount of data to be read in bytes
	\return None
*/
void vfnIICRead(u8 u8SlaveAddress, u8 *pu8DataIn, u8 u8Size)
{
    /* Copy all the parameters to the driver variables to be used by the state machine */
	gu8SlaveAddress = u8SlaveAddress;
    gpu8DataIn = pu8DataIn;
    gu8SizeIn = u8Size;
    sIICStateMachine.PrevState = sIICStateMachine.ActualState;
    gu8IICStateMachineFlags = 0;
    sIICStateMachine.ActualState = IIC_START_R_STATE;
    u8IICDriverStatus = (1<<IIC_FLAGS_BUSY);
}

/****************************************************************************************************/
/*!
	\fn void vfnIICRandomRead(u8 u8SlaveAddress, u8 *pu8DataOut, u8 u8SizeOut,u8 *pu8DataIn, u8 u8SizeIn)
	\brief  Perform a write and read without releasing the bus using repeated start
	\param	u8SlaveAddress: Bus address of the desired device
	\param	pu8DataOut: Pointer to the buffer containing the output data
	\param  u8SizeOut: Amount of data to be sent in bytes
	\param	pu8DataIn: Pointer to the buffer that is used to store the data
	\param  u8SizeOut: Amount of data to be read in bytes
	\return None
*/
void vfnIICRandomRead(u8 u8SlaveAddress, u8 *pu8DataOut, u8 u8SizeOut,
u8 *pu8DataIn, u8 u8SizeIn)
{
    /* Copy all the parameters to the driver variables to be used by the state machine */
	gu8SlaveAddress = u8SlaveAddress;
    gpu8DataOut = pu8DataOut;
    gu8SizeOut = u8SizeOut;
    gpu8DataIn = pu8DataIn;
    gu8SizeIn = u8SizeIn;
    gu8IICStateMachineFlags = (1<<FLAG_RANDOMREAD);
    sIICStateMachine.PrevState = sIICStateMachine.ActualState;
    sIICStateMachine.ActualState = IIC_START_W_STATE;
    u8IICDriverStatus = (1<<IIC_FLAGS_BUSY);
}

/****************************************************************************************************/
/*!
	\fn void I2C0_IRQHandler(void)
	\brief  IIC interrupt service routine
	\return None
*/
void I2C0_IRQHandler(void)
{
    /* check HW flag and clear it */
	if(IIC_IF)
    {
        gu8IICStateMachineFlags |= (1<<FLAG_TCF);
        IIC_IF_CLEAR;
    }
    else if(IIC_ARBL)
    {
        gu8IICStateMachineFlags |= (1<<FLAG_ARBL);
        u8IICDriverStatus |= (1<<IIC_FLAGS_ERROR);
        IIC_ARBL_CLEAR;
    }
}

/*****************************************************************************************************
* Code of Module wide FUNCTIONS
*****************************************************************************************************/

/*!
	\fn void vfnIICStateIdle(void)
	\brief  Idle state that is reached once a read or write command is finished
	\return None
*/
void vfnIICStateIdle(void)
{
    //Do Nothing
    u8IICDriverStatus |= (1<<IIC_FLAGS_IDLE);
}

/****************************************************************************************************/
/*!
	\fn void vfnIICStateStartW(void)
	\brief  Starts a write command
	\return None
*/
void vfnIICStateStartW(void)
{
	/* chekc if the bus is busy or not */
	if(!IIC_BUSY)
	{
		/* enable Tx and master mode */
		IIC_CONTROL_REGISTER |= I2C_C1_TX_MASK;

		IIC_CONTROL_REGISTER |= I2C_C1_MST_MASK;
		/* Set R/W bit to W and send slave address*/
		gu8SlaveAddress &= 0xFE;
		IIC_DATA_REGISTER = gu8SlaveAddress;

		sIICStateMachine.PrevState = sIICStateMachine.ActualState;
		sIICStateMachine.ActualState = IIC_DATA_W_STATE;
	}
	else
	{
		/* Turn on error flag */
		sIICStateMachine.ActualState = IIC_IDLE_STATE;
		u8IICDriverStatus |= (1<<IIC_FLAGS_ERROR);
		u8IICDriverStatus &= ~(1<<IIC_FLAGS_BUSY);
	}
}

/****************************************************************************************************/
/*!
	\fn void vfnIICStateStartR(void)
	\brief  Starts a read command
	\return None
*/
void vfnIICStateStartR(void)
{
	/* check if the bus is busy */
	if(!IIC_BUSY)
	{
		/* if is a fresh start read */
		if(sIICStateMachine.PrevState == IIC_IDLE_STATE)
		{
			/* set TX mode and master mode */
			IIC_CONTROL_REGISTER |= I2C_C1_TX_MASK;

			IIC_CONTROL_REGISTER |= I2C_C1_MST_MASK;

			/* set R/W bit to R */
			gu8SlaveAddress |= 0x01;
			IIC_DATA_REGISTER = gu8SlaveAddress;
			/* Send ACK */
			IIC_CONTROL_REGISTER &= ~I2C_C1_TXAK_MASK;
			sIICStateMachine.PrevState = sIICStateMachine.ActualState;
		}
		else
		{
			/* if is a non fresh read (read after seding slave address) */
			/* check for transfer complete flag */
			if(gu8IICStateMachineFlags & (1<<FLAG_TCF))
			{
				/* ask for slave ACK*/
				if(!(I2C0_S & I2C_S_RXAK_MASK))
				{
					gu8IICStateMachineFlags &= ~(1<<FLAG_TCF);
					/* set Rx mode */
					IIC_CONTROL_REGISTER &= ~I2C_C1_TX_MASK;
					/* generate clocks */
					(void)IIC_DATA_REGISTER;      //dummy read
					gu8SizeIn--;
					sIICStateMachine.ActualState = IIC_DATA_R_STATE;
				}
				else
				{
					/* if no ACK from slave, set error flags */
					gu8IICStateMachineFlags |= (1<<FLAG_ERROR);
					u8IICDriverStatus |= (1<<IIC_FLAGS_ERROR);
					sIICStateMachine.ActualState = IIC_STOP_STATE;
				}
			}
		}
	}
	else
	{
		/* if bus is busy, set error flags */
		sIICStateMachine.ActualState = IIC_IDLE_STATE;
		u8IICDriverStatus |= (1<<IIC_FLAGS_ERROR);
		u8IICDriverStatus &= ~(1<<IIC_FLAGS_BUSY);
	}
}

/****************************************************************************************************/
/*!
	\fn void vfnIICStateDataW(void)
	\brief  Writes N bytes to the device
	\return None
*/
void vfnIICStateDataW(void)
{
    /* complete transfer flag */
	if(gu8IICStateMachineFlags & (1<<FLAG_TCF))
    {
        gu8IICStateMachineFlags &= ~(1<<FLAG_TCF);

		/* ask for slave ACK */
        if(!(I2C0_S & I2C_S_RXAK_MASK))
        {
            /* if there is data to be send */
			if(gu8SizeOut)
            {
                IIC_DATA_REGISTER = *gpu8DataOut;
                gu8SizeOut--;
                gpu8DataOut++;
            }
            else
            {
                /* when randomread is selected, a repeated start needs to be performed */
				/* otherwise generate stop signal */
				if(gu8IICStateMachineFlags & (1<<FLAG_RANDOMREAD))
                {
                    gu8IICStateMachineFlags &= ~(1<<FLAG_RANDOMREAD);
                    sIICStateMachine.PrevState = sIICStateMachine.ActualState;
                    sIICStateMachine.ActualState = IIC_RESTART_STATE;
                }
                else
                {
                    u8IICDriverStatus |= (1<<IIC_FLAGS_WRITE_OK);
                    sIICStateMachine.PrevState = sIICStateMachine.ActualState;
                    sIICStateMachine.ActualState = IIC_STOP_STATE;
                }
            }
        }
        else
        {
            gu8IICStateMachineFlags |= (1<<FLAG_ERROR);
            u8IICDriverStatus |= (1<<IIC_FLAGS_ERROR);
            sIICStateMachine.PrevState = sIICStateMachine.ActualState;
		   sIICStateMachine.ActualState = IIC_STOP_STATE;
        }
    }
}

/****************************************************************************************************/
/*!
	\fn void vfnIICStateDataR(void)
	\brief  Reads N bytes from device
	\return None
*/
void vfnIICStateDataR(void)
{
    /* complete transfer flag */
	if(gu8IICStateMachineFlags & (1<<FLAG_TCF))
    {
        gu8IICStateMachineFlags &= ~(1<<FLAG_TCF);

		/* make sure RX mode is on */
		IIC_CONTROL_REGISTER &= ~I2C_C1_TX_MASK;

		/* if its the last byte, set the NACK flag */
        if(gu8SizeIn == 1)
        {

    		IIC_CONTROL_REGISTER |= I2C_C1_TXAK_MASK;
        }
        else if(gu8SizeIn == 0)
        {
            /* generate stop */
			u8IICDriverStatus |= (1<<IIC_FLAGS_READY);
            sIICStateMachine.PrevState = sIICStateMachine.ActualState;
            sIICStateMachine.ActualState = IIC_STOP_STATE;
            return;
        }

        /* Store data */
		*gpu8DataIn = IIC_DATA_REGISTER;
        gu8SizeIn--;
        gpu8DataIn++;
    }
}

/****************************************************************************************************/
/*!
	\fn void vfnIICStateRestart(void)
	\brief  Generates a repeated start on the bus
	\return None
*/
void vfnIICStateRestart(void)
{
    if(sIICStateMachine.PrevState != sIICStateMachine.ActualState)
    {

		/* enable TX mode and perform a repeated start */
		IIC_CONTROL_REGISTER |= I2C_C1_TX_MASK;

		IIC_CONTROL_REGISTER |= I2C_C1_RSTA_MASK;
		/* set R/W bit to R */
        gu8SlaveAddress |= 0x01;
        IIC_DATA_REGISTER = gu8SlaveAddress;

        sIICStateMachine.PrevState = sIICStateMachine.ActualState;
    }
    else
    {
        if(gu8IICStateMachineFlags & (1<<FLAG_TCF))
        {
        	/* look for slave ACK */
			if(!(I2C0_S & I2C_S_RXAK_MASK))
            {
                gu8IICStateMachineFlags &= ~(1<<FLAG_TCF);

        		/* set RX mode */
				IIC_CONTROL_REGISTER &= ~I2C_C1_TX_MASK;
				/* if just one byte is to be read, set NACK flag */
                if(gu8SizeIn == 1)
                {

            		IIC_CONTROL_REGISTER |= I2C_C1_TXAK_MASK;
                }
				/* generate clocks */
                (void)IIC_DATA_REGISTER;      //dummy read
                gu8SizeIn--;
                sIICStateMachine.ActualState = IIC_DATA_R_STATE;
            }
            else
            {
                /* set error flags if NACK is detected */
				gu8IICStateMachineFlags |= (1<<FLAG_ERROR);
                u8IICDriverStatus |= (1<<IIC_FLAGS_ERROR);
                sIICStateMachine.ActualState = IIC_STOP_STATE;
            }
        }
    }
}

/****************************************************************************************************/
/*!
	\fn void vfnIICStateStop(void)
	\brief  Generates stop signal
	\return None
*/
void vfnIICStateStop(void)
{
	static u8 u8TimeOut = 0xFF;

	/* Time out is to retry to generate stop signal */
	/* sometimes the bus is still busy because the slave keeps SDA down */
	/* perform 255 retries, if not possible to generate stop signal */
	/* set error flags */
	/* amount of retries is arbitrary */
	if(u8TimeOut)
	{
		if(sIICStateMachine.PrevState != IIC_STOP_STATE)
		{
			/* set RX mode and slave mode (stop signal) */
			IIC_CONTROL_REGISTER &= ~I2C_C1_TXAK_MASK;

			IIC_CONTROL_REGISTER &= ~I2C_C1_MST_MASK;
			/* get last data from data register */
			if ((sIICStateMachine.PrevState == IIC_DATA_R_STATE ) && !(u8IICDriverStatus & (1<<IIC_FLAGS_ERROR)))
			{
				*gpu8DataIn = IIC_DATA_REGISTER;
			}
			else
			{
				(void)IIC_DATA_REGISTER;
			}
			sIICStateMachine.PrevState = IIC_STOP_STATE;
		}
		else
		{
			/* check if the bus is busy */
			if(!IIC_BUSY)
			{
				u8IICDriverStatus |= (1<<IIC_FLAGS_IDLE);
				sIICStateMachine.ActualState = IIC_IDLE_STATE;
				u8IICDriverStatus &= ~(1<<IIC_FLAGS_BUSY);
				u8TimeOut = 0xFF;
			}
			else
			{
				u8TimeOut--;

			}

		}
	}
	else
	{
		gu8IICStateMachineFlags |= (1<<FLAG_ERROR);
		u8IICDriverStatus |= (1<<IIC_FLAGS_ERROR);
		sIICStateMachine.ActualState = IIC_IDLE_STATE;
		u8TimeOut = 0xFF;
	}
}

/*****************************************************************************/

