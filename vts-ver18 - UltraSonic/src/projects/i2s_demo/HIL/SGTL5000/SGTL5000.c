/****************************************************************************************************/
/**
Copyright (c) 2008 Freescale Semiconductor
Freescale Confidential Proprietary
\file       SGTL5000.c
\brief
\author     Freescale Semiconductor
\author     Guadalajara Applications Laboratory RTAC Americas
\author     B22385
\version    0.1
\date       May 19, 2011
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
#include "IIC_HAL.h"
#include "SGTL5000.h"
/*****************************************************************************************************
* Declaration of module wide FUNCTIONs - NOT for use in other modules
*****************************************************************************************************/
static void vfnSGTL5000ControlStateIdle(void);
static void vfnSGTL5000ControlStateWaitComm(void);
static void vfnSGTL5000ControlStateInit(void);

void (* const vfnapSGTL5000ControlStateMachine[]) (void) =
{
		vfnSGTL5000ControlStateIdle,
		vfnSGTL5000ControlStateWaitComm,
		vfnSGTL5000ControlStateInit,
};

/*****************************************************************************************************
* Definition of module wide MACROs / #DEFINE-CONSTANTs - NOT for use in other modules
*****************************************************************************************************/
/*!
    \def SGTL5000_ADDRESS
    \brief I2C Slave address of the SGTL5000
*/
#define SGTL5000_ADDRESS	(0x14)
/*!
    \def SGTL5000_CONTROL_BUFFER_SIZE
    \brief Size to be used by the buffer for the I2C communication
*/
#define SGTL5000_CONTROL_BUFFER_SIZE	(4)
/*!
    \def SGTL5000_GEQ_MAX_VOL
    \brief Max allowed volume value for the GEQ equivalent to +12dB
*/
#define SGTL5000_GEQ_MAX_VOL	(0x5F)
/*!
    \def SGTL5000_GEQ_MIN_VOL
    \brief Min allowed volume value for the GEQ equivalent to -12dB
*/
#define SGTL5000_GEQ_MIN_VOL	(0x00)
/*!
    \def I2S_WORD_LENGTH
    \brief Word length selection for initialization
*/
#ifdef _16_BIT_WORD
	#define I2S_WORD_LENGTH	(0x30)
#elif defined(_20_BIT_WORD)
	#define I2S_WORD_LENGTH	(0x20)
#elif defined(_24_BIT_WORD)
	#define I2S_WORD_LENGTH	(0x10)
#else
	#define I2S_WORD_LENGTH	(0x00)
#endif

/*!
    \def SGTL5000_INIT_SIZE
    \brief The total size of the initialization arrays
*/
#define SGTL5000_INIT_SIZE	(23)
/*****************************************************************************************************
* Declaration of module wide TYPEs - NOT for use in other modules
*****************************************************************************************************/
/*!
    \enum eSGTL5000ControlStates
    \brief SGTL5000 driver states
*/
typedef enum
{
	SGTL5000_CONTROL_STATE_IDLE = 0,
	SGTL5000_CONTROL_STATE_WAIT_COMM,
	SGTL5000_CONTROL_STATE_INIT
}eSGTL5000ControlStates;
/*****************************************************************************************************
* Definition of module wide VARIABLEs - NOT for use in other modules
*****************************************************************************************************/
/*!
    \var volatile u8 gu8SGTL5000DriverStatus
    \brief Driver status
*/
volatile u8 gu8SGTL5000DriverStatus = 0;

/*!
    \var sStateMachine sSGTL5000ControlStateMachine
    \brief Stores the states of the state machine
*/
sSM sSGTL5000ControlStateMachine;
/*!
    \var static u8 gau8ControlOutputBuffer[SGTL5000_CONTROL_BUFFER_SIZE];
    \brief Buffer for write I2C commands
*/
static u8 gau8ControlOutputBuffer[SGTL5000_CONTROL_BUFFER_SIZE];
/*****************************************************************************************************
* Definition of module wide (CONST-) CONSTANTs - NOT for use in other modules
*****************************************************************************************************/

/*!
    \var gau16InitRegisterSequence
    \brief Registers definitions for the initialization
*/
static const u16 gau16InitRegisterSequence[SGTL5000_INIT_SIZE] =
{
	SGTL5000_CHIP_ANA_POWER,
	SGTL5000_CHIP_LINREG_CTRL,
	SGTL5000_CHIP_REF_CTRL,
	SGTL5000_CHIP_LINE_OUT_CTRL,
	SGTL5000_CHIP_SHORT_CTRL,
	SGTL5000_CHIP_ANA_POWER ,
	SGTL5000_CHIP_DIG_POWER,
	SGTL5000_CHIP_LINE_OUT_VOL,
	SGTL5000_CHIP_CLK_CTRL,
	SGTL5000_CHIP_I2S_CTRL,
	SGTL5000_CHIP_SSS_CTRL,
	SGTL5000_DAP_CONTROL,
	SGTL5000_DAP_AUDIO_EQ,
	SGTL5000_DAP_AVC_THRESHOLD,
	SGTL5000_DAP_AVC_ATTACK,
	SGTL5000_DAP_AVC_DECAY,
	SGTL5000_DAP_AVC_CTRL,
	SGTL5000_CHIP_ANA_ADC_CTRL,
	SGTL5000_CHIP_DAC_VOL,
	SGTL5000_CHIP_LINE_OUT_VOL,
	SGTL5000_CHIP_ANA_HP_CTRL,
	SGTL5000_CHIP_ADCDAC_CTRL,
	SGTL5000_CHIP_ANA_CTRL
};
/*!
    \var gau16InitRegisterValuesSequence
    \brief Registers values for the initialization.
*/
static const u16 gau16InitRegisterValuesSequence[SGTL5000_INIT_SIZE] =
{
	0x7260, //SGTL5000_CHIP_ANA_POWER
	0x0068, //SGTL5000_CHIP_LINREG_CTRL
	0x01EE, //SGTL5000_CHIP_REF_CTRL
	0x0F22, //SGTL5000_CHIP_LINE_OUT_CTRL
	0x1106, //SGTL5000_CHIP_SHORT_CTRL
	0x72FB, //SGTL5000_CHIP_ANA_POWER
	0x0073, //SGTL5000_CHIP_DIG_POWER
	0x0F0F, //SGTL5000_CHIP_LINE_OUT_VOL
	0x000A, //SGTL5000_CHIP_CLK_CTRL
	0x0080|I2S_WORD_LENGTH, //CHIP_I2S_CTRL
	0x0013, //SGTL5000_CHIP_SSS_CTRL
	0x0001, //SGTL5000_DAP_CONTROL
	0x0003, //SGTL5000_DAP_AUDIO_EQ
	0x0A40, //SGTL5000_DAP_AVC_THRESHOLD
	0x0014, //SGTL5000_DAP_AVC_ATTACK
	0x0028, //SGTL5000_DAP_AVC_DECAY
	0x0001, //SGTL5000_DAP_AVC_CTRL
	0x0000, //SGTL5000_CHIP_ANA_ADC_CTRL
	0x3C3C, //SGTL5000_CHIP_DAC_VOL
	0x0C0C, //SGTL5000_CHIP_LINE_OUT_VOL
	0x1818, //SGTL5000_CHIP_ANA_HP_CTRL
	0x0000, //SGTL5000_CHIP_ADCDAC_CTRL
	0x0004  //SGTL5000_CHIP_ANA_CTRL
};

/*!
    \var gau16GEQRegisters
    \brief Registers definitions for the GEQ
*/
static const u16 gau16GEQRegisters[5] =
{
		SGTL5000_DAP_AUDIO_EQ_BASS_BAND0,
		SGTL5000_DAP_AUDIO_EQ_BAND1,
		SGTL5000_DAP_AUDIO_EQ_BAND2,
		SGTL5000_DAP_AUDIO_EQ_BAND3,
		SGTL5000_DAP_AUDIO_EQ_TREBLE_BAND4
};

/*****************************************************************************************************
* Code of project wide FUNCTIONS
*****************************************************************************************************/

/*!
      \fn void vfnSGTL5000WriteRegister(u16 u16Register, u16 u16RegisterData)
      \brief  Provides the ability to write control registers to the codec
      \param  u16Register: Register to be written
      \param  u16RegisterData: Value of the desired register
      \return void
*/
void vfnSGTL5000WriteRegister(u16 u16Register, u16 u16RegisterData)
{
	/* set the driver as busy and the next state to wait physical layer driver */
	gu8SGTL5000DriverStatus |= (1 << SGTL5000_STATUS_BUSY);

	sSGTL5000ControlStateMachine.ActualState = SGTL5000_CONTROL_STATE_WAIT_COMM;
	/* Set the command buffer to send the data thru physical layer */
	gau8ControlOutputBuffer[0] = (u8)(u16Register>>8);
	gau8ControlOutputBuffer[1] = (u8)(u16Register & 0xFF);
	gau8ControlOutputBuffer[2] = (u8)(u16RegisterData>>8);;
	gau8ControlOutputBuffer[3] = (u8)(u16RegisterData & 0xFF);;


	vfnIICWrite(SGTL5000_ADDRESS,&gau8ControlOutputBuffer[0],4);
}

/*!
      \fn void vfnSGTL5000ReadRegister(u16 u16Register, u8 *pu8RegisterData)
      \brief  Provides the ability to read a control registers
      \param  u16Register: Register to be read
      \param  pu8RegisterData: Pointer to where the read data will be stored
      \return void
*/
void vfnSGTL5000ReadRegister(u16 u16Register, u8 *pu8RegisterData)
{
	/* Set the driver as busy and the next state logic */
	gu8SGTL5000DriverStatus |= (1 << SGTL5000_STATUS_BUSY);

	sSGTL5000ControlStateMachine.ActualState = SGTL5000_CONTROL_STATE_WAIT_COMM;
	sSGTL5000ControlStateMachine.NextState = SGTL5000_CONTROL_STATE_IDLE;
	/* set up control buffer */
	gau8ControlOutputBuffer[0] = (u8)(u16Register>>8);
	gau8ControlOutputBuffer[1] = (u8)(u16Register & 0xFF);
	/* Use physical layer */
	vfnIICRandomRead(SGTL5000_ADDRESS,&gau8ControlOutputBuffer[0],2,(u8*)pu8RegisterData,2);
}
/*!
      \fn void vfnSGTL5000ChangeGEQVolume(u16 u16GEQBand, u16 u16Level)
      \brief  Provides the ability to change the GEQ band volume
      \param  u16GEQBand: Band to be updated
      \param  u16RegisterData: New volume value
      \return void
*/
void vfnSGTL5000ChangeGEQVolume(u16 u16GEQBand, u16 u16Level)
{
	/* Confirm the band is valid */
	if(u16GEQBand <= SGTL5000_BAND_4)
	{
		/* Confirm the volume detected is on rage */
		if(u16Level <= SGTL5000_GEQ_MAX_VOL)
		{
			/* write band register */
			vfnSGTL5000WriteRegister(gau16GEQRegisters[u16GEQBand],u16Level);
			sSGTL5000ControlStateMachine.NextState = SGTL5000_CONTROL_STATE_IDLE;
		}
	}
}

/*!
      \fn void vfnSGTLInit(void)
      \brief  starts the codec initialization, further init is done on the INIT state
      \param  none
      \return none
*/
void vfnSGTLInit(void)
{
	/* Initialize physical layer */
	vfnIICInit();
	/* Set the driver as busy */
	gu8SGTL5000DriverStatus |= (1 << SGTL5000_STATUS_BUSY);
	/* Set next state logic and write the register */
	sSGTL5000ControlStateMachine.NextState = SGTL5000_CONTROL_STATE_INIT;

	vfnSGTL5000WriteRegister(SGTL5000_CHIP_LINREG_CTRL,0x0008);
}
/*!
      \fn static void vfnSGTL5000StateIdle(void)
      \brief  Idle state
      \param  void
      \return void
*/
static void vfnSGTL5000ControlStateIdle(void)
{
	gu8SGTL5000DriverStatus &= ~(1 << SGTL5000_STATUS_BUSY);
	if(sSGTL5000ControlStateMachine.PrevState ==  SGTL5000_CONTROL_STATE_INIT)
	{
		gu8SGTL5000DriverStatus |= (1 << SGTL5000_STATUS_CONFIGURED);
	}
}

/*!
      \fn static void vfnSGTL5000StateWaitComm(void)
      \brief  Waits for the physical layer driver to finish its process
      \param  void
      \return void
*/
static void vfnSGTL5000ControlStateWaitComm(void)
{
	/*Check for the physical layer driver to be free*/
	if(!(IIC_DRIVER_BUSY))
	{
		/* Confirm if there is no error */
		if(IIC_ERROR)
		{
			IIC_CLEAR_ERROR;
			gu8SGTL5000DriverStatus |= (1<<SGTL5000_STATUS_I2C_ERROR);
		}
		sSGTL5000ControlStateMachine.ActualState = sSGTL5000ControlStateMachine.NextState;
	}
}

/*!
      \fn static void vfnSGTL5000StateInit(void)
      \brief  Keeps the codec initialization
      \param  void
      \return void
*/
static void vfnSGTL5000ControlStateInit(void)
{
	static u8 u8InitiStep = 0;

	/*retries if the I2C driver reported an error*/
	if(gu8SGTL5000DriverStatus&(1<<SGTL5000_STATUS_I2C_ERROR))
	{
		u8InitiStep--;
		gu8SGTL5000DriverStatus&= ~(1<<SGTL5000_STATUS_I2C_ERROR);
	}
	/* Check if there is any other write registers */
	if(u8InitiStep < SGTL5000_INIT_SIZE)
	{
		/* Take the register and the data to be written */
		vfnSGTL5000WriteRegister(gau16InitRegisterSequence[u8InitiStep],gau16InitRegisterValuesSequence[u8InitiStep]);

		sSGTL5000ControlStateMachine.NextState = SGTL5000_CONTROL_STATE_INIT;
		u8InitiStep++;
	}
	else
	{
		/* When finished, set IDLE state to Actual and Next states */
		u8InitiStep = 0;
		sSGTL5000ControlStateMachine.ActualState = SGTL5000_CONTROL_STATE_IDLE;
		sSGTL5000ControlStateMachine.NextState = SGTL5000_CONTROL_STATE_IDLE;
	}

}
