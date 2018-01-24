#include "hal_dev_mma8451.c"
#include "hal_i2c.c"
#include "angle_cal.c"

/*******************#defines*******************/
// FXOS8700CQ internal register addresses
#define FXOS8700CQ_STATUS 0x00
#define FXOS8700CQ_WHOAMI 0x00
#define FXOS8700CQ_XYZ_DATA_CFG 0x0E
#define FXOS8700CQ_CTRL_REG1 0x2A
#define FXOS8700CQ_M_CTRL_REG1 0x5B
#define FXOS8700CQ_M_CTRL_REG2 0x5C
#define FXOS8700CQ_WHOAMI_VAL 0xC7
#define A_FFMT_CFG 0x15
#define A_FFMT_SRC 0x16
extern float speed;
signed short accel_x, accel_y, accel_z;
signed short resultx, resulty, resultz;
char aux1;
int32 accel_mx,accel_my,accel_mz;
int32 magx,magy,magz,temp;
int32 offxy, offxz , offyz , offx , offy, offz;
int temp1xy,temp1xz,temp1yz,temp1x,temp1y,temp1z;
int temp2xy,temp2xz,temp2yz,temp2x,temp2y,temp2z;
int motion;extern int motion_samples;
extern void gsm_gps_sleep(void);



void accel_init(void)
{
    unsigned char tmp;
    //printf("****Accelerometor init ****\n");
    //Configure MMA8451 sensor //MMA8451Q
    hal_dev_mma8451_init();      //Initialize I2C modules
    tmp = hal_dev_mma8451_read_reg(FXOS8700CQ_CTRL_REG1);
    hal_dev_mma8451_write_reg(FXOS8700CQ_CTRL_REG1,tmp&0xFE);
    tmp &= ~0xFE;
    hal_dev_mma8451_write_reg(FXOS8700CQ_CTRL_REG1,tmp|0x02);
    tmp |= 0x02;
    hal_dev_mma8451_write_reg(FXOS8700CQ_CTRL_REG1,tmp|0x01);
//		tmp = hal_dev_mma8451_read_reg(A_FFMT_CFG);
//		hal_dev_mma8451_write_reg(A_FFMT_CFG,hal_dev_mma8451_read_reg(A_FFMT_CFG)|0x40);
}


/******************************************************************************/
void accel_read(void)
{
    if((hal_dev_mma8451_read_reg(0x00)&0xf) != 0)
    {
accel_x = (int16_t)(((hal_dev_mma8451_read_reg(0x01) << 8) | hal_dev_mma8451_read_reg(0x02)))>> 2;		
accel_y = (int16_t)(((hal_dev_mma8451_read_reg(0x03) << 8) | hal_dev_mma8451_read_reg(0x04)))>> 2;		
accel_z = (int16_t)(((hal_dev_mma8451_read_reg(0x05) << 8) | hal_dev_mma8451_read_reg(0x06)))>> 2;					
magx = (hal_dev_mma8451_read_reg(0x07) << 8) | hal_dev_mma8451_read_reg(0x08);
magy = (hal_dev_mma8451_read_reg(0x09) << 8) | hal_dev_mma8451_read_reg(0x0A);
magz = (hal_dev_mma8451_read_reg(0x0B) << 8) | hal_dev_mma8451_read_reg(0x0C);
temp = hal_dev_mma8451_read_reg(0x51);

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

	//		hal_dev_mma8451_write_reg(A_FFMT_CFG,0xFF);		
	//		hal_dev_mma8451_write_reg(A_FFMT_SRC,0xFF);					
	printf("\n\t\t******************\n\t,\t%d\t,\t%d\t,\t%d\t,\t%d\t,\t%d\t,\t%d,\t%x,\t%x\n\t\t*******************\n",xy_angle+offxy,xz_angle+offxz,yz_angle+offyz,resultx+offx,resulty+offy,resultz+offz,hal_dev_mma8451_read_reg(A_FFMT_CFG),hal_dev_mma8451_read_reg(A_FFMT_SRC));			


		}
}
/******************************************************************************/



void detect_motion()
{speed=0;
	
			//if accelerometer works do this
	//current status : not working under test
//						if(	(resultx+offx>temp1x+2) || (resultx+offx<temp1x-2) ||  (resulty+offy>temp1y+2) || (resulty+offy<temp1y-2)||(resultz+offz>temp1z+2)||(resultz+offz<temp1z-2)	)
//						{motion = 1;}
//						else
//						{motion = 0;}

//						temp1x=resultx+offx;
//						temp1y=resulty+offy;
//						temp1z=resultz+offz;  

			//else do this
if(speed <  5)
{motion = 0;}
else 
{motion = 1;}
    //

if(motion == 0)
	motion_samples++;
else
	motion_samples = 0;




}
