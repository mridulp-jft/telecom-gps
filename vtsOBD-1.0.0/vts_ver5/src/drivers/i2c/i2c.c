/*
 * File:        k60_i2c.c
 * Purpose:     Code for initializing and using I2C
 *
 * Notes:
 *
 */

#include "common.h"
#include "i2c.h"

signed char result[20];
unsigned char MasterTransmission;
unsigned char SlaveID;

/*******************************************************************/
/*!
 * I2C Initialization
 * Set Baud Rate and turn on I2C1
 */
void init_I2C(void)
{
  SIM_SCGC5 = SIM_SCGC5_PORTA_MASK | SIM_SCGC5_PORTB_MASK | SIM_SCGC5_PORTC_MASK | SIM_SCGC5_PORTD_MASK | SIM_SCGC5_PORTE_MASK;


  SIM_SCGC4 |= SIM_SCGC4_I2C1_MASK; //Turn on clock to I2C` module
  
  /* configure GPIO for I2C1 function */
  PORTC_PCR10 = PORT_PCR_MUX(2);
  PORTC_PCR11 = PORT_PCR_MUX(2);

  I2C1_F  = 0x16;       // set MULT and ICR:  For bus speed of 24MHz, 0x12 should give 400 kHz
  I2C1_C1 = I2C_C1_IICEN_MASK;       /* enable IIC */
}

/*******************************************************************/
/*!
 * I2C Initialization
 * Set Baud Rate and turn on I2C0
 */
void init_I2C0(void)
{
    SIM_SCGC5 = SIM_SCGC5_PORTE_MASK;
    
    SIM_SCGC4 |= SIM_SCGC4_I2C0_MASK; //Turn on clock to I2C` module
  
    /* configure GPIO for I2C1 function */
    PORTE_PCR24 = PORT_PCR_MUX(5);
    PORTE_PCR25 = PORT_PCR_MUX(5);

    I2C0_F  = 0x12;       // set MULT and ICR:  For bus speed of 24MHz, 0x12 should give 400 kHz
    I2C0_C1 = I2C_C1_IICEN_MASK;       /* enable IIC */
}

/*******************************************************************/
/*!
 * Start I2C Transmision
 * @param SlaveID is the 7 bit Slave Address
 * @param Mode sets Read or Write Mode
 */
void IIC_StartTransmission (unsigned char SlaveID, unsigned char Mode)
{
  if(Mode == MWSR)
  {
    /* set transmission mode */
    MasterTransmission = MWSR;
  }
  else
  {
    /* set transmission mode */
    MasterTransmission = MRSW;
  }

  /* shift ID in right possition */
  SlaveID = SlaveID << 1;

  /* Set R/W bit at end of Slave Address */
  SlaveID |= (unsigned char)MasterTransmission;

  /* send start signal */
  i2c_Start();

  /* send ID with W/R bit */
  i2c_write_byte(SlaveID);
}

/*******************************************************************/
/*!
 * Pause Routine
 */
void Pause(uint32 time){
    int n;
    for(n=1;n<time;n++) {
      asm("nop");
    }
}

/*******************************************************************/
/*!
 * Read a register from the MMA7660
 * @param u8RegisterAddress is Register Address
 * @return Data stored in Register
 */
unsigned char I2CReadRegister(unsigned char u8RegisterAddress)
{
  unsigned char result;

  /* Send Slave Address */
  IIC_StartTransmission(SlaveID,MWSR);
  i2c_Wait();

  /* Write Register Address */
  I2C1_D = u8RegisterAddress;
  i2c_Wait();

  /* Do a repeated start */
  I2C1_C1 |= I2C_C1_RSTA_MASK;

  /* Send Slave Address */
  I2C1_D = (ACCEL_I2C_ADDRESS << 1) | 0x01; //read address
  i2c_Wait();

  /* Put in Rx Mode */
  I2C1_C1 &= (~I2C_C1_TX_MASK);

  /* Turn off ACK since this is second to last byte being read*/
  I2C1_C1 |= I2C_C1_TXAK_MASK;

  /* Dummy read */
  result = I2C1_D ;
  i2c_Wait();

  /* Send stop since about to read last byte */
  i2c_Stop();

  /* Read byte */
  result = I2C1_D ;

  return result;
}



/*******************************************************************/
/*!
 * Write a byte of Data to specified register on MMA7660
 * @param u8RegisterAddress is Register Address
 * @param u8Data is Data to write
 */
void I2CWriteRegister(unsigned char SlaveAddr, unsigned char u8RegisterAddress, unsigned char u8Data)
{
  /* send data to slave */
  IIC_StartTransmission(SlaveAddr,MWSR);
  i2c_Wait();

  I2C1_D = u8RegisterAddress;
  i2c_Wait();

  I2C1_D = u8Data;
  i2c_Wait();

  i2c_Stop();

  Pause(50);
}

/*******************************************************************/
/*!
 * Write a byte of Data to specified register on MMA7660
 * @param u8RegisterAddress is Register Address
 * @param u8Data is Data to write
 */
void I2CWriteMultiRegister(unsigned char SlaveAddr, unsigned char u8RegisterAddress, unsigned char *u8Data, unsigned int length)
{
    uint16 i;
  /* send data to slave */
    FGPIOA_PCOR |= 0x20;
  IIC_StartTransmission(SlaveAddr,MWSR);
  i2c_Wait();

  I2C1_D = u8RegisterAddress;
  i2c_Wait();

  for(i=0; i<length; i++)
  {
      I2C1_D = u8Data[i];
      i2c_Wait();
  }

  
  i2c_Stop();
  FGPIOA_PSOR |= 0x20;
  
  Pause(7);
  //Pause(50);
}

/*******************************************************************/
/*!
 * Read first three registers from the MMA7660
 * @param u8RegisterAddress is Register Address
 * @return Data stored in Register
 */
unsigned char I2CReadMultiRegisters(unsigned char SlaveAddr, unsigned char u8RegisterAddress, unsigned char bytes, char buf[])
{
  unsigned char n=bytes;
  int i;

  /* Send Slave Address */
  IIC_StartTransmission(SlaveAddr,MWSR);
  i2c_Wait();

  /* Write Register Address */
  I2C1_D = u8RegisterAddress;
  i2c_Wait();

  /* Do a repeated start */
  I2C1_C1 |= I2C_C1_RSTA_MASK;

  /* Send Slave Address */
  I2C1_D = (ACCEL_I2C_ADDRESS << 1) | 0x01; //read address
  i2c_Wait();

  /* Put in Rx Mode */
  I2C1_C1 &= (~I2C_C1_TX_MASK);

  /* Ensure TXAK bit is 0 */
  I2C1_C1 &= ~I2C_C1_TXAK_MASK;

  /* Dummy read */
  result[0] = I2C1_D ;
  i2c_Wait();

  for(i=0;i<n-2;i++)
  {
    /* Read first byte */
    buf[i] = I2C1_D;
    i2c_Wait();
  }
  /* Turn off ACK since this is second to last read*/
  I2C1_C1 |= I2C_C1_TXAK_MASK;

  /* Read second byte */
  buf[i++] = I2C1_D;
  i2c_Wait();

  /* Send stop */
  i2c_Stop();

  /* Read third byte */
  buf[i++] = I2C1_D;

//  printf("%3d    %3d     %3d\n",result[0],result[2],result[4]);
  return result[0];
}

///////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
// 
//  Begin I2C0 functions
//
////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////

/*******************************************************************/
/*!
 * Start I2C Transmision
 * @param SlaveID is the 7 bit Slave Address
 * @param Mode sets Read or Write Mode
 */
void IIC0_StartTransmission (unsigned char SlaveID, unsigned char Mode)
{
  if(Mode == MWSR)
  {
    /* set transmission mode */
    MasterTransmission = MWSR;
  }
  else
  {
    /* set transmission mode */
    MasterTransmission = MRSW;
  }

  /* shift ID in right possition */
  SlaveID = SlaveID << 1;

  /* Set R/W bit at end of Slave Address */
  SlaveID |= (unsigned char)MasterTransmission;

  /* send start signal */
  i2c0_Start();

  /* send ID with W/R bit */
  i2c0_write_byte(SlaveID);
}

/*******************************************************************/
/*!
 * Read a register from the MMA7660
 * @param u8RegisterAddress is Register Address
 * @return Data stored in Register
 */
unsigned char I2C0ReadRegister(unsigned char SlaveAddr, unsigned char u8RegisterAddress)
{
  unsigned char result;

  /* Send Slave Address */
  IIC0_StartTransmission(SlaveID,MWSR);
  i2c0_Wait();

  /* Write Register Address */
  I2C0_D = u8RegisterAddress;
  i2c0_Wait();

  /* Do a repeated start */
  I2C0_C1 |= I2C_C1_RSTA_MASK;

  /* Send Slave Address */
  I2C0_D = (ACCEL_I2C_ADDRESS << 1) | MRSW; //read address
  i2c0_Wait();

  /* Put in Rx Mode */
  I2C0_C1 &= (~I2C_C1_TX_MASK);
  
  /* Dummy read */
  result = I2C0_D ;
  i2c0_Wait();

  /* Turn off ACK since this is second to last byte being read*/
  //I2C0_C1 |= I2C_C1_TXAK_MASK;

  /* Send stop since about to read last byte */
  i2c0_Stop();

  /* Read byte */
  result = I2C0_D ;

  return result;
}



/*******************************************************************/
/*!
 * Write a byte of Data to specified register on MMA7660
 * @param u8RegisterAddress is Register Address
 * @param u8Data is Data to write
 */
void I2C0WriteRegister(unsigned char SlaveAddr, unsigned char u8RegisterAddress, unsigned char u8Data)
{
  /* send data to slave */
  IIC0_StartTransmission(SlaveAddr,MWSR);
  i2c0_Wait();

  I2C0_D = u8RegisterAddress;
  i2c0_Wait();

  I2C0_D = u8Data;
  i2c0_Wait();

  i2c0_Stop();

  Pause(50);
}

/*******************************************************************/
/*!
 * Write a byte of Data to specified register on MMA7660
 * @param u8RegisterAddress is Register Address
 * @param u8Data is Data to write
 */
void I2C0WriteMultiRegister(unsigned char SlaveAddr, unsigned char u8RegisterAddress, unsigned char *u8Data, unsigned int length)
{
    uint16 i;
  /* send data to slave */
  IIC0_StartTransmission(SlaveAddr,MWSR);
  i2c0_Wait();

  I2C0_D = u8RegisterAddress;
  i2c0_Wait();

  for(i=0; i<length; i++)
  {
      I2C0_D = u8Data[i];
      i2c0_Wait();
  }

  
  i2c0_Stop();
  
  Pause(7);
  //Pause(50);
}

/*******************************************************************/
/*!
 * Read first three registers from the MMA7660
 * @param u8RegisterAddress is Register Address
 * @return Data stored in Register
 */
unsigned char I2C0ReadMultiRegisters(unsigned char SlaveAddr, unsigned char u8RegisterAddress, unsigned char bytes, char buf[])
{
  unsigned char n=bytes;
  int i;

  /* Send Slave Address */
  IIC0_StartTransmission(SlaveAddr,MWSR);
  i2c0_Wait();

  /* Write Register Address */
  I2C0_D = u8RegisterAddress;
  i2c0_Wait();

  /* Do a repeated start */
  I2C0_C1 |= I2C_C1_RSTA_MASK;

  /* Send Slave Address */
  I2C0_D = (ACCEL_I2C_ADDRESS << 1) | 0x01; //read address
  i2c0_Wait();

  /* Put in Rx Mode */
  I2C0_C1 &= (~I2C_C1_TX_MASK);

  /* Ensure TXAK bit is 0 */
  I2C0_C1 &= ~I2C_C1_TXAK_MASK;

  /* Dummy read */
  result[0] = I2C0_D ;
  i2c0_Wait();

  for(i=0;i<n-2;i++)
  {
    /* Read first byte */
    buf[i] = I2C0_D;
    i2c0_Wait();
  }
  /* Turn off ACK since this is second to last read*/
  I2C0_C1 |= I2C_C1_TXAK_MASK;

  /* Read second byte */
  buf[i++] = I2C0_D;
  i2c0_Wait();

  /* Send stop */
  i2c0_Stop();

  /* Read third byte */
  buf[i++] = I2C0_D;

//  printf("%3d    %3d     %3d\n",result[0],result[2],result[4]);
  return result[0];
}
