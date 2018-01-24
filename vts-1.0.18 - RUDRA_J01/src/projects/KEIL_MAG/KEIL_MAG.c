/*
 * File:		KEIL_MAG.c
 * Purpose:		Main process
 *
 */

#include "common.h"
#include "hal_dev_mma8451.c"
#include "hal_i2c.c"
#include "angle_cal.c"


#ifdef CMSIS
#include "start.h"
#endif
signed short accel_x, accel_y, accel_z;
signed short resultx, resulty, resultz;
char aux1;
int32 accel_mx,accel_my,accel_mz;
int32 magx,magy,magz,temp;
extern char in_char1(),in_char2();
extern void out_char1(char ch),out_char2(char ch);


void accel_init(void)
{
    unsigned char tmp;
    //printf("****Accelerometor init ****\n");
    //Configure MMA8451 sensor //MMA8451Q
    hal_dev_mma8451_init();      //Initialize I2C modules
    tmp = hal_dev_mma8451_read_reg(0x2a);
    hal_dev_mma8451_write_reg(0x2a,tmp&0xFE);
    tmp &= ~0xFE;
    hal_dev_mma8451_write_reg(0x2a,tmp|0x02);
    tmp |= 0x02;
    hal_dev_mma8451_write_reg(0x2a,tmp|0x01);
}
/******************************************************************************/
void accel_read(void)
{
    if((hal_dev_mma8451_read_reg(0x00)&0xf) != 0)
    {
//        accel_x   = hal_dev_mma8451_read_reg(0x01)<<8;
//        accel_x  |= hal_dev_mma8451_read_reg(0x02);
//        accel_x >>= 2;
			
accel_x = (int16_t)(((hal_dev_mma8451_read_reg(0x01) << 8) | hal_dev_mma8451_read_reg(0x02)))>> 2;		
accel_y = (int16_t)(((hal_dev_mma8451_read_reg(0x03) << 8) | hal_dev_mma8451_read_reg(0x04)))>> 2;		
accel_z = (int16_t)(((hal_dev_mma8451_read_reg(0x05) << 8) | hal_dev_mma8451_read_reg(0x06)))>> 2;					
magx = (hal_dev_mma8451_read_reg(0x07) << 8) | hal_dev_mma8451_read_reg(0x08);
magy = (hal_dev_mma8451_read_reg(0x09) << 8) | hal_dev_mma8451_read_reg(0x0A);
magz = (hal_dev_mma8451_read_reg(0x0B) << 8) | hal_dev_mma8451_read_reg(0x0C);
temp = hal_dev_mma8451_read_reg(0x51);
			//        accel_y   = hal_dev_mma8451_read_reg(0x03)<<8;
//        accel_y  |= hal_dev_mma8451_read_reg(0x04);
//        accel_y >>= 2;

//        accel_z   = hal_dev_mma8451_read_reg(0x05)<<8;
//        accel_z  |= hal_dev_mma8451_read_reg(0x06);
//        accel_z >>= 2;

        resultx   = hal_dev_mma8451_read_reg(0x01)<<8;
        resultx  |= hal_dev_mma8451_read_reg(0x02);
        resultx >>= 8;

        resulty   = hal_dev_mma8451_read_reg(0x03)<<8;
        resulty  |= hal_dev_mma8451_read_reg(0x04);
        resulty >>= 8;

        resultz   = hal_dev_mma8451_read_reg(0x05)<<8;
        resultz  |= hal_dev_mma8451_read_reg(0x06);
        resultz >>= 8;

        angle_calculation(); //-900  to  900
        detect_fall_detection();
				
//printf("||   %d   ||   %d   ||   %d   ||   %d   ||   %d   ||   %d   ||   %d   ||   %d   ||   %d   ||   %d    ||   %d    ||\n",accel_x,accel_y,accel_z,resultx,resulty,resultz,xy_angle,xz_angle,yz_angle,  , temp )	;			
//printf("||   %d   ||   %d   ||   %d   ||   %d   ||   %d   ||   %d   ||   %d   ||   %d   ||   %d   ||\n", (accel_x),resultx, (accel_y),resulty, (accel_z),resultz,magx,magy,magz )	;			
	
//printf("        %X       %X      \n",magz,~magz);


//				        resultx = accel_x >> 8;

//        resulty = accel_y >> 8;


//        resultz = accel_z >> 8;
//				
    }
}
/******************************************************************************/


/********************************************************************/
int main (void)
{
    	char ch;


	
#ifdef CMSIS  // If we are conforming to CMSIS, we need to call start here
    start();
#endif

accel_init();
printf("Accelerometer initialised\n");        
 	printf("\n\r\n\r*** Running the KEIL_MAG project ***\n\r");

	while(1)
	{//accel_read();
		ch = in_char();
		out_char(ch);
	} 
}
/********************************************************************/
