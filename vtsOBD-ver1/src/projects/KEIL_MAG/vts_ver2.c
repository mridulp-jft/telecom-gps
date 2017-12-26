/*
 * File:		KEIL_MAG.c
 * Purpose:		Main process
 *
 */

#include "common.h"
#include "modem.c"
//#include "accelerometer.c"
#include "gps.c"
#include "gpios.c"
#include "systick.c"
#include "stdlib.h"
#include <stdint.h>
#include "string.h"
#include <functions.c>
//#include "lptmr.c"

#ifdef CMSIS
#include "start.h"
#endif

extern char* stcond1;
extern char * stcond2;extern char * stcond3;extern char * stcond4;
extern int fuel;
char fuelstr[5]="";
  float rez = 0, fact = 1;
  int d,point_seen,sent;
  char * cond201;char * cond200;
  static char* cond1=0;
	static char* cond2=0;
	static char* cond3=0;
	static char* cond4=0;
	static char* cond5=0;
	static char* cond6=0;
	static char* cond7=0;
	static char* cond8=0;
	static char* cond9=0;
	static char* cond10=0;
	static char* cond11=0;
	static char* cond12=0;
	static char* cond13=0;
	static char* cond14=0;	
	int ass;int count=0;
	float fsz;
	int log0=0;
long times,qwe,k5,enters,cursorvaluepr=0,cursorvaluene=0;
char cond;char*q1;char* q2;char* q3;char *q4;
int cntendl=0;
int k23=0;
char prev[8],latest[10];
int iz;
double a,b,c;int hh,mm1,mm2;
double a1,b1,c1;
double hh11, mm11,mm22;
int logged;
char *check;
	int len;
	char cond;
	char* con1d;
	char* stcond1;char * stcond2;char * stcond3;char * stcond4;char * stcond5;
int breach=0,aliveping=0;
void send_balance(void);extern void outSRS(void);
extern void LED_state(void),LED_state2(void);
int sleep_flag=0;
int32 tmeout=4,int_erval=1; //10 SECS TIMEOUT
extern char in_char1(void),in_char2(void);
int myAtoi(char *str);
extern void out_char1(char ch),out_char2(char ch),ignstaton(),ignstatoff(),ignread();
char string_gps[100],gga[100],rmc[100],uart_string_obd[3000],data2[300],drive[5],exception[200];char filehandler[20];
char apn[25]="iot.com";
void HardFault_Handler(void);
float speed=0;
void dtr_sleep(void);
int lpticks=0,voltagecbc,csq;
uint32 rtcticks=0;
long rtcticks2=0;int i,imeiinc=0;
char ticks_ch,save_rtcticks;
char 
		 ip[16]="104.236.203.4",
		 port[10]="5555",
		 at_[100],

		 lati[20],
		 longi[20],
		 velocity[5],
		 fsize[15],
		 num_o[15],
		 interval[5],
	_rtcticks[10];

int32 timeout=0;
extern void hextobinary(char* hex, char* bin);
static char imei[20];
void send_message(char * data2);
float pr=0,la=0;
char uart_string_gsm[5000],sd_data[1400];
int ggaptr=0,rmcptr=0;
int i=0,motion_samples=0,notsleep=0;
char ch; 
void delay(int delaytime),   loop(), auto_caliberate_accelerometer();
void  bat_cind();
extern void send_modem(char ch[]);
char ringflag=0,lptmr_interrupt=0;
extern void lptmr_init(int count, int clock_source),saveapn();

int time52=15;
void HardFault_Handler(void);
char * cond277;char* cond20077;char data_balance[200];
int sz,cn; int res = 0,iz;
int32 test2;
char obdresp[20];
char tempobdresp[20];
char obdrespbinary[33];char suppportedpid[100][7];
int pidcounter;
extern void supportedpid(char* command);

__inline void GPS_Collect(){
	
	
memset(fuelstr,0,5);
memset(gga,0,100);
memset(rmc,0,100);	

	
	send_GSM("\n\nAT+QGNSSC=1\r\n","OK\r\n","ERROR\r\n","ERROR:",10);  

memset(suppportedpid, 0, sizeof(char)*100*7);
	
pidcounter=0;

supportedpid("0100");
if(!(strstr(uart_string_obd,"UNABLE") || strstr(uart_string_obd,"NO DATA")))
{	
pidcounter=0;

//supportedpid("0100");
supportedpid("0100");
supportedpid("0120");
//supportedpid("0120");
supportedpid("0140");
//supportedpid("0140");
supportedpid("0160");
//supportedpid("0160");
supportedpid("0180");
//supportedpid("0180");
supportedpid("01A0");
//supportedpid("01A0");
supportedpid("01C0");
//supportedpid("01C0");
supportedpid("050100");
//supportedpid("050100");
supportedpid("0900");	
//supportedpid("0900");	
	//send_GSM("\n\nAT+QGNSSRD?\r\n","OK\r\n","ERROR\r\n","ERROR:",10);  
	

		
	send_GSM("\n\nAT+QGNSSRD=\"NMEA/RMC\"\r\n","OK\r\n","ERROR\r\n","ERROR:",10);  
		parse_g(uart_string_gsm, 1, 3, '$', '\r' ,rmc);
		stateCount++; 
		if(stateCount>5){stateCount =0;}
		LED_state2();			
		//delay(200);
		send_GSM("\n\nAT+QGNSSRD=\"NMEA/GGA\"\r\n","OK\r\n","ERROR\r\n","ERROR:",10);  
		parse_g(uart_string_gsm, 1, 3, '$', '\r' ,gga);
		stateCount++; 
	}
else{
	strcat(gga,"ALIVE");
	delay(5000);
}
		send_OBD("ATRV\r\n");
		parse_g(uart_string_obd, 1, 2, '\r', '\r' ,fuelstr);	
		
		if(stateCount>5){stateCount =0;}
		LED_state2();			

	
		strcat(data,imei);
		strcat(data,",");	
		strcat(data,"$");	
		strcat(data,gga);
		strcat(data,",$");	
		strcat(data,rmc);	
		strcat(data,",");	
		strcat(data,num2);
		strcat(data,fuelstr);			

//		sprintf(fuelstr,"\n");//%c%c%c%c%c%c%c",0x1a,0x1a,0x1a,0x1a,0x1a,0x1a,0x1a);
		pidcounter=0;
		while(strlen(suppportedpid[pidcounter])>3)
		{
				strcat(data,",");
				send_OBD(suppportedpid[pidcounter]);
				memset(obdresp,0,20);
				memset(tempobdresp,0,20);
				parse_g(uart_string_obd, 1, 2, '\r', '\r' ,tempobdresp);
				remove_all_chars(suppportedpid[pidcounter], '\r', '\n');
				remove_all_chars(tempobdresp, '\r', ' ');
				strcat(data,suppportedpid[pidcounter]);
				strcat(data,"=");
				strcat(data,tempobdresp);
				
				pidcounter++;
		}
		strcat(data,",<>\n");		
}


/*********************************************************************/

/********************************************************************/
int main (void)
{
memset(data,0,1500);
memset(data2,0,300);
start();
systick_init();	
#ifdef CMSIS  // If we are conforming to CMSIS, we need to call start here
#endif

int_erval=5;
		sent=0;
	//LED_init();		//Initialize GPIO for LEDs
	RELAY_init();		//Initialize GPIO for LEDs
	//SW1_init();		//Initialize GPIO for SW1 w/ interrupt	
	//accel_init();
	//sleep_flag=0;
	//DTR_OFF;	
	lptmr_init(1000, 1);	
	//ADC_Init();
	

	clear();
	delay(100);
	int_erval=5;
	
RESETSTN_ON;
delay(500);
RESETSTN_OFF;
delay(500);
RESETSTN_ON;
delay(500);
RESETSTN_OFF;
delay(500);
	

	
		send_OBD("ATZ\r\n");
		delay(100);
	//	while(1)
			
	delay(100);
		send_OBD("ATRV\r\n");

		delay(100);
		send_OBD("ATSP0\r\n");
		delay(1000);
	


memset(data,0,1500);


	
	while(1)
	{
		switch(sent)
		{
			case 0:
		{		
		uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, 0x1A);uart_putchar(UART1_BASE_PTR, 0x1A);	uart_putchar(UART1_BASE_PTR, 0x1A);uart_putchar(UART1_BASE_PTR, 0x1A);
		
		
		send_GSM("\n\nAT\r\n","OK\r\n","ERROR\r\n","ERROR:",10);  
		stateCount++; 
		if(stateCount>5){stateCount =0;}
		LED_state2();			
		delay(500);
		
		memset(imei,0,20);
		memset(gga,0,100);
		memset(rmc,0,100);
		memset(fuelstr,0,5);
		memset(data,0,1500);

		
		
		send_GSM("\r\n\n\nAT+GSN\r\n","OK","ERROR\r\n","ERROR",10);	
		imeiinc=0;
		for(i=0;i<strlen(uart_string_gsm);i++){
				if((uart_string_gsm[i]>47)   &&   (uart_string_gsm[i]<58)){   //means numeric
					imei[imeiinc] = uart_string_gsm[i];
					imeiinc++;
				}
		}
		clear();	
		
//		send_GSM("\n\nAT+QGNSSC=1\r\n","OK\r\n","ERROR\r\n","ERROR:",10);  
		
		send_GSM("\n\nAT+CFUN=0\r\n","OK\r\n","ERROR\r\n","ERROR:",10);  
		stateCount++; 
		if(stateCount>5){stateCount =0;}
		LED_state2();			
    GPS_Collect();
		delay(500);
				
		send_GSM("\n\nAT+CFUN=1\r\n","SMS Ready","ERROR\r\n","DEACT",10);  
		stateCount++; 
		if(stateCount>5){stateCount =0;}
		LED_state2();			
		delay(100);
GPS_Collect();				
//		send_GSM("\n\nAT+QGNSSC=1\r\n","OK\r\n","ERROR\r\n","ERROR:",10);  
//		stateCount++; 
//		if(stateCount>5){stateCount =0;}
//		LED_state2();			
//		delay(500);
//GPS_Collect();				

		
		
		send_GSM("\n\nAT+QIFGCNT\r\n","OK\r\n","ERROR","DEACT",10);  
		stateCount++; 
		if(stateCount>5){stateCount =0;}
		LED_state2();			
		delay(100);		

//GPS_Collect();				


		
		send_GSM("\n\nAT+QICSGP=1,\"isafe\"\r\n","OK\r\n","ERROR","DEACT",10);  
		stateCount++; 
		if(stateCount>5){stateCount =0;}
		LED_state2();			
//GPS_Collect();				

		delay(100);
		
		send_GSM("\n\nAT+QIMUX=0\r\n","OK\r\n","ERROR","DEACT",10);  
		stateCount++; 
		if(stateCount>5){stateCount =0;}
		LED_state2();			
		delay(100);		
				
		send_GSM("\n\nAT+QIMODE=0\r\n","OK\r\n","ERROR","DEACT",10);  
		delay(100);
				
		send_GSM("\n\nAT+QIREGAPP\r\n","OK\r\n","ERROR","DEACT",10);  
		stateCount++; 
		if(stateCount>5){stateCount =0;}
		LED_state2();			
		delay(100);
				
		send_GSM("\n\nAT+QIACT\r\n","OK\r\n","ERROR","DEACT",10);  
		stateCount++; 
		if(stateCount>5){stateCount =0;}
		LED_state2();			
		delay(100);	
				
		send_GSM("\n\nAT+QILOCIP\r\n",".","ERROR","DEACT",10);  
		stateCount++; 
		if(stateCount>5){stateCount =0;}
		LED_state2();			
		delay(100);
sent=1;				
}
			case 1:
	{
		send_GSM("\n\nAT+QIOPEN=\"TCP\",\"104.236.203.4\",\"5555\"\r\n","CONNECT OK\r\n","ERROR","FAIL",10);  
		stateCount++; 
		if(stateCount>5){stateCount =0;}
		LED_state2();
		GPS_Collect();				
		

send_GSM("\n\nAT+QISEND\r\n",">","ERROR\r\n","FAIL",10);  
stateCount++; 
if(stateCount>5){stateCount =0;}
LED_state2();			
if(strstr(uart_string_gsm,">"))
	{memset(uart_string_gsm,0,5000);k2=0;	

		for(i=0;i<strlen(data);i++){uart_putchar(UART1_BASE_PTR, data[i]);tout = 0;}
		uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, 0x1A);uart_putchar(UART1_BASE_PTR, 0x1A);	uart_putchar(UART1_BASE_PTR, 0x1A);uart_putchar(UART1_BASE_PTR, 0x1A);
		
		while(!(strstr(uart_string_gsm,"SEND OK") || strstr(uart_string_gsm,"ERROR") || strstr(uart_string_gsm,"SEND FAIL") || tout>5));
		
	}


		if(strstr(uart_string_gsm,"SEND OK")){
			sent=1;memset(data,0,1500);
			delay(1000);
//					send_GSM("\n\nAT+QFOPEN=\"LOG.TXT\",0\r\n","OK\r\n","ERROR\r\n","ERROR:",10);  
//					if(strstr(uart_string_gsm,"QFOPEN:"))
//					{	memset(filehandler,0,20);
//						parse_g(uart_string_gsm, 1, 3, ' ', '\r' ,filehandler);
//						sent=0;
//					}
//					send_GSM("\n\nAT+QFWRITE=12451840, 10=\"LOG.TXT\",0\r\n","OK\r\n","ERROR\r\n","ERROR:",10);  

		}else
		{sent=0;}	
		
		}




	}

		if(rtcticks2>5000)
		{
			//RRESET
		}
	}

}



void HardFault_Handler()
{	long ppp=0;

	send_modem("Hardfault_Handler");	
	RESET_OFF;
	RESET_OFF;
for(ppp=0;ppp<9999999; ppp++);	
	
	RESET_ON;
	RESET_ON;
for(ppp=0;ppp<9999999; ppp++);
}



 void LPTimer_IRQHandler(void)
{
lpticks+=1;
//rtcticks++;
	tout++;tout2++;
	rtcticks2++;
	if(sleep_flag == 1){aliveping++;}

  LPTMR0_CSR |=  LPTMR_CSR_TCF_MASK;   // write 1 to TCF to clear the LPT timer compare flag
  LPTMR0_CSR = ( LPTMR_CSR_TEN_MASK | LPTMR_CSR_TIE_MASK | LPTMR_CSR_TCF_MASK  );
	
  
}



























