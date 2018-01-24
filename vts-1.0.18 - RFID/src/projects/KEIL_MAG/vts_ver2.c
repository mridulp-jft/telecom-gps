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


extern int intrtmr;
extern int uart0buffinc;
extern int send_SOS;
extern char* stcond1;
extern char * stcond2;extern char * stcond3;extern char * stcond4;
extern int fuel;
char fuelstr[5]="";
  float rez = 0, fact = 1;
  int d,point_seen;
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
	static char* cond15=0;
	int ass;int count=0;
	float fsz;
	int log0=0;
long times,qwe,k5,enters,cursorvaluepr=0,cursorvaluene=0;
char cond;char*q1;char* q2;char* q3;char *q4;
int cntendl=0;
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
	char ignstr[9],acstr[2];
int breach=0,aliveping=0;
void send_balance(void);extern void outSRS(void);
extern void LED_state(void),LED_state2(void);
int sleep_flag=0;
int32 tmeout=4,int_erval=1; //10 SECS TIMEOUT
extern char in_char1(void),in_char2(void);
int myAtoi(char *str);
extern void out_char1(char ch),out_char2(char ch),ignstaton(),ignstatoff(),ignread();
char string_gps[100],gga[100],rmc[100],uart_string_gps[3000],data2[300],drive[5],exception[200];
char apn[25]="isafe";
void HardFault_Handler(void);
float speed=0;
void dtr_sleep(void);
int lpticks=0,voltagecbc,csq;
uint32 rtcticks=0;
long rtcticks2=0;int i,imeiinc=0;
char ticks_ch,save_rtcticks;
int syscounter=0;

char ip[100],
			port[10],
			
		 at_[100],

		 lati[20],
		 longi[20],
		 velocity[5],
		 fsize[15],
		 num_o[15],
		 interval[5],
	_rtcticks[10];

int32 timeout=0;
static char imei[20];
void send_message(char * data2);
float pr=0,la=0;
char uart_string_gsm[5000],sd_data[1400];
int ggaptr=0,rmcptr=0;
int i=0,motion_samples=0,notsleep=0;
char ch; 
void delay(int delaytime), get_gpsdata(),  loop(), auto_caliberate_accelerometer(), msg_sim800(void);
void  send_chunk(void),bat_cind();
extern void send_modem(char ch[]);
char ringflag=0,lptmr_interrupt=0;
extern void lptmr_init(int count, int clock_source),saveapn();
__inline void GPS_COLLECT(void);
__inline void GPS_COLLECT2(void);
int time52=15;
void HardFault_Handler(void);
char * cond277;char* cond20077;//char data_balance[200];
int sz,cn; int res = 0,iz;
int32 test2;
int8 id[30];



/*********************************************************************/

/********************************************************************/
int main (void)
{



//int_erval=10;
								memset(data,0,strlen(data));
								memset(data2,0,strlen(data2));
	memset(ip,0,strlen(ip));
		memset(port,0,strlen(ip));

	
start();
systick_init();	
#ifdef CMSIS  // If we are conforming to CMSIS, we need to call start here

#endif

int_erval=5;


	LED_init();		//Initialize GPIO for LEDs
	RELAY_init();		//Initialize GPIO for LEDs
	SW1_init();		//Initialize GPIO for SW1 w/ interrupt
send_SOS=0;	
	//accel_init();
	sleep_flag=0;
	DTR_OFF;	
	lptmr_init(1000, 1);	
	ADC_Init();
	memset(at_,0,strlen(at_));
	i=0;

	
	
	
	
//C0

//SCB->AIRCR = 0x05fA0000;

	int_erval=0;

		uart_putchar(UART1_BASE_PTR,0xA);
		uart_putchar(UART1_BASE_PTR,0x1A);			
	
send_GSM("\n\nAT\r\n","OK\r\n","ERROR\r\n","ERROR:",2);  
 delay(100); 

clear();delay(100);
GPS_COLLECT();
strcat(data,"CH'1'\n");	


int_erval=5;

//if(!(strstr(uart_string_gsm, "OK")|| strstr(uart_string_gsm, "ERROR")))
//{HardFault_Handler();}
ignread();

//	saveapn();
	
readapn();

//HardFault_Handler();

//RESET_ON;


send_GSM("\r\nAT+CFUN=0\r\r\n\n", "OK", "ERROR\r\n" , "ERROR",4);	
clear();	
//delay(10);

send_GSM("\r\nAT+CFUN=1\r\n", "Ready", "NOT INSERTED" , "ERROR",7);	

	
GPS_COLLECT();
strcat(data,"CH\n");	

//GPS_COLLECT();
//  strcat(data,"CH\n");	
//	

GPS_COLLECT();
strcat(data,"CH\n");	


stateCount=3;
LED_state();





	
//send_modem2("$PMTK225,0*2B");
//while(!strstr(uart_string_gsm,"OK\r\n"));

//bat_cind();
//delay(1000);

send_GSM("\n\nAT&W\r\n","OK\r\n","ERROR\r\n","ERROR:",tmeout);    //   uart_putchar(UART1_BASE_PTR,0x1A);uart_putchar(UART1_BASE_PTR,0xA);uart_putchar(UART1_BASE_PTR,0x1A);uart_putchar(UART1_BASE_PTR,0xA);uart_putchar(UART1_BASE_PTR,0x1A);		
//delay(10);

send_GSM("\n\nATS0=2\r\n","OK\r\n","ERROR\r\n","ERROR:",tmeout); 	

send_GSM("\n\nAT&F\r\n","OK\r\n","ERROR\r\n","ERROR:",tmeout); 	


send_GSM("\n\nAT&D\r\n","OK\r\n","ERROR\r\n","ERROR:",tmeout); 	


send_GSM("\n\nAT+IFC=0,0\r\n","OK\r\n","ERROR\r\n","ERROR:",tmeout);


send_GSM("\n\nAT+CIPQSEND?\r\n","OK\r\n","ERROR\r\n","ERROR:",tmeout);

send_GSM("\n\nAT+CIPQSEND=0\r\n","OK\r\n","ERROR\r\n","ERROR:",tmeout);

//delay(10);




//delay(10);
send_GSM("\n\nAT+CPBS=\"SM\"\r\n","OK\r\n","ERROR\r\n","ERROR:",tmeout);








send_GSM("\n\nAT+SD2PCM=0\r\n","OK\r\n","ERROR\r\n","ERROR:",tmeout);
//delay(10);	

send_GSM("\n\nAT&W\r\n","OK\r\n","ERROR\r\n","ERROR:",tmeout);
delay(10);	
send_GSM("\n\nAT+FSDRIVE=1\r\n","OK\r\n","ERROR\r\n","ERROR:",tmeout);
clear();
delay(10);	
//;	
//send_GSM("\n\nAT+FSCREATE=D:\\LOG.TXT\r\n","OK\r\n","ERROR\r\n","ERROR:",tmeout);

	GPS_COLLECT();
  strcat(data,"CH\n");	

send_GSM("\n\nAT+FSMEM\r\n","OK\r\n","ERROR\r\n","ERROR:",tmeout);
delay(100);	

if(strstr(uart_string_gsm,"D:")){
send_GSM("\n\nAT+FSCREATE=C:\\LOGGING_DRIVE.TXT\r\n","OK\r\n","ERROR\r\n","ERROR:",tmeout);	
	
memset(at_,0,100);
sprintf(at_,"\r\nAT+FSWRITE=C:\\LOGGING_DRIVE.TXT,0,%d,10\r\n",2);	
send_GSM(at_, ">", "ERROR\r\n" , "ERROR:",10);	
	
clear();
send_modem("D:");	
	
}
else{
send_GSM("\n\nAT+FSCREATE=C:\\LOGGING_DRIVE.TXT\r\n","OK\r\n","ERROR\r\n","ERROR:",tmeout);	
	
memset(at_,0,100);
sprintf(at_,"\r\nAT+FSWRITE=C:\\LOGGING_DRIVE.TXT,0,%d,10\r\n",2);	
send_GSM(at_, ">", "ERROR\r\n" , "ERROR:",10);	
	
clear();
send_modem("C:");		
	
}	

delay(100);

//delay(10);

send_GSM("\n\nATS0=1\r\n","OK\r\n","ERROR\r\n","ERROR:",tmeout);


send_GSM("\n\nAT+CSCLK=1\r\n","OK\r\n","ERROR\r\n","ERROR:",tmeout);


send_GSM("\r\n\r\nAT+CMGD=1,4\r\n\n\n\n","OK\r\n","ERROR\r\n","ERROR:",tmeout);	


//send_GSM("\n\nAT+CPBW=5,\"0\",129,\"OWNER5\"\r\n","OK\r\n","ERROR\r\n","ERROR:",tmeout);


//send_GSM("\n\nAT+CPBW=6,\"0\",129,\"OWNER6\"\r\n","OK\r\n","ERROR\r\n","ERROR:",tmeout);

ignread();
readapn();
readcursor();

read_interval();
send_GSM("\n\nAT+CMGF=1\n\n","OK\r\n","ERROR\r\n","ERROR:",tmeout);
//delay(10);	

send_GSM("\n\nAT+CSCA?\r\n","OK\r\n","ERROR\r\n","ERROR:",tmeout);    //   uart_putchar(UART1_BASE_PTR,0x1A);uart_putchar(UART1_BASE_PTR,0xA);uart_putchar(UART1_BASE_PTR,0x1A);uart_putchar(UART1_BASE_PTR,0xA);uart_putchar(UART1_BASE_PTR,0x1A);		
							memset(at_,0,100);
							memset(num_o,0,15);
							parse_g(uart_string_gsm, 1, 2, '\"', '\"', num_o);
							sprintf(at_, "\r\nAT+CSCA=\"%s\"\r\n", num_o);
							send_GSM(at_,"OK\r\n","ERROR\r\n","ERROR:",tmeout);



read_ip_port();
		memset(at_,0,100);
		memset(drive,0,5);
		sprintf(at_, "\nAT+FSREAD=C:\\LOGGING_DRIVE.TXT,0,100,1\r\n");		
		send_GSM(at_, "OK", "ERROR\r\n" , "ERROR:",10);	
		parse_g(uart_string_gsm, 1,3, '\n', '\r',drive);
	

msg_sim800(); 

//setting interval 4

temp=int_erval;				
int_erval=4;



								//GPS_COLLECT();
								send_GSM("\r\nAT+CIPSHUT\r\n", "OK", "ERROR\r\n" , "ERROR:",5);	
								//delay(20);		
								GPS_COLLECT();
								strcat(data,"CH\n");	


msg_sim800(); 

	memset(at_,0,100);
		sprintf(at_,"\r\nAT+CSTT=\"%s\"\r\n",apn);
send_GSM(at_,	"OK", "ERROR\r\n" , "ERROR:",tmeout);	
								//delay(20);
			//					GPS_COLLECT();

msg_sim800(); 

	
								send_GSM("\r\nAT+CIICR\r\r\n", "OK", "ERROR\r\n" , "DEACT",5);		
								//delay(20);
								GPS_COLLECT();
								strcat(data,"CH\n");	



								GPS_COLLECT();
								strcat(data,"CH\n");	

msg_sim800(); 

								
								clear();send_modem("\nAT+CIFSR\r\r\n");clear();
								delay(20);
	

msg_sim800(); 

		
								sprintf(at_, "\r\nAT+CIPSTART=\"TCP\",\"%s\",\"%s\"\r\n", ip, port);
								send_GSM( at_ , "CONNECT", "ERROR\r\n" , "ERROR",tmeout);	
								clear();


		int_erval=temp;
//resetting it to its value

								send_GSM("\r\nAT+CIPSEND\r\n", ">", "ERROR" , "CONNECT FAIL",tmeout);		


memset(stcond1,0,strlen(stcond1));	
memset(con1d,0,strlen(con1d));	
	
								//sprintf(data_2,"Latitude->%s,Longitude->%s,Velocity->%skmph\nhttps://www.google.com/search?q=%s%c2C%s&ie=utf-8&oe=utf-8\n",lati,longi,velocity,lati,'%',longi);			
						
								cond=mystrstr(uart_string_gsm,'>');
								if(cond)	
								{
									
									clear();
									memset(uart_string_gsm,0,5000);
									strcat(data,"\n");
									len=strlen(data);
									tout=0;
									k2=0;
									for(k=0;k<len;k++)
									{
										uart_putchar(UART1_BASE_PTR, data[k]);
									}uart_putchar(UART1_BASE_PTR, 0x1A);
									do
																{stcond1=strstr(uart_string_gsm,"SEND OK");
																	stcond2=strstr(uart_string_gsm, "ERROR");
																		stcond3=strstr(uart_string_gsm, "FAIL");	
																			stcond4=strstr(uart_string_gsm, "DEACT");	
																	
																}while(!(stcond2 || stcond3 || stcond4 || stcond1 || (tout > 8) ) ); //|| (timeout < 1)   
																//delay(10);clear();
														uart_putchar(UART1_BASE_PTR,0x1A);
												//delay(10);
										uart_putchar(UART1_BASE_PTR, 0x1A);uart_putchar(UART1_BASE_PTR, 0x1A);uart_putchar(UART1_BASE_PTR, 0x1A);
						
									
delay(50);
stcond1=strstr(uart_string_gsm,"SEND OK");								
								}
//else{
//log_it();
//}


if(!(stcond1) == 1 )// if no gsm connection is there ,,,... this segment reinitializes GSM, collects GPS data in RAM and attempts to send it
{									uart_putchar(UART1_BASE_PTR, 0x1A);clear();delay(10);
									uart_putchar(UART1_BASE_PTR, 0x1A);clear();delay(10);
									uart_putchar(UART1_BASE_PTR, 0x1A);clear();delay(10);

									delay(100);
									clear();//memset(uart_string_gsm,0,5000);

									memset(at_,0,100);
									sprintf(at_,"\r\nAT+FSWRITE=%s\\LOG.TXT,1,%d,10\n\n",drive,strlen(data)+1);	
									send_SD(at_, ">", "ERROR\r\n" , "ERROR",5);
if(strstr(uart_string_gsm,"ERROR")){
	drive[0]='C';drive[1]=':';
}	
									clear();	
									k2=0;									//string array counter for uart 1
									tout=0;	
									for(k=0;k<strlen(data);k++)
									{
										uart_putchar(UART1_BASE_PTR, data[k]);//clear();
									}	
										uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');	uart_putchar(UART1_BASE_PTR, '\n');	uart_putchar(UART1_BASE_PTR, '\n');	uart_putchar(UART1_BASE_PTR, '\n');	uart_putchar(UART1_BASE_PTR, '\n');	uart_putchar(UART1_BASE_PTR, '\n');	uart_putchar(UART1_BASE_PTR, '\n');	
									//memset(data,0,1000);
									//timer counts to wait for characters in uart 1 									
									while(!(strstr(uart_string_gsm,"OK\r\n")  || (strstr(uart_string_gsm, "ERROR") ||  (tout > 5) )))
									{	}
									clear();
									memset(data,0,strlen(data));
									memset(data,0,strlen(data));	
									GPS_COLLECT();
									strcat(data,"CH\n");	


									clear();	
//*************************************tcp_initialization();*********************
//setting interval 4
temp=int_erval;				
int_erval=4;

	
msg_sim800(); 
send_GSM("\r\nAT+CFUN=0\r\r\n\n", "OK", "ERROR\r\n" , "ERROR",5);	
delay(100);
send_GSM("\r\nAT+CFUN=1\r\n", "ERROR", "NOT INSERTED" , "Ready", 4);	
GPS_COLLECT2();
strcat(data,"CH\n");		
GPS_COLLECT2();
strcat(data,"CH\n");	

	
send_GSM("\r\nAT+CIPSHUT\r\n", "OK", "ERROR\r\n" , "ERROR:",4);	
GPS_COLLECT2();
strcat(data,"CH\n");	
memset(at_,0,100);
sprintf(at_,"\r\nAT+CSTT=\"%s\"\r\n",apn);
send_GSM(at_,	"OK", "ERROR\r\n" , "ERROR:",tmeout);							//delay(20);
msg_sim800(); 
send_GSM("\r\nAT+CIICR\r\r\n", "OK", "ERROR\r\n" , "DEACT",4);		
GPS_COLLECT2();
strcat(data,"CH\n");	
GPS_COLLECT2();
strcat(data,"CH\n");	


msg_sim800(); 
GPS_COLLECT2();
strcat(data,"CH\n");	
					clear();send_modem("\nAT+CIFSR\r\r\n");clear();
					delay(20);


msg_sim800(); 
int_erval=temp;
//resetting interval 
						sprintf(at_, "\r\nAT+CIPSTART=\"TCP\",\"%s\",\"%s\"\r\n", ip, port);
						send_GSM( at_ , "CONNECT", "ERROR" , "ERROR:",tmeout);	
						clear();
						
						
						send_GSM("\r\nAT+CIPSEND\r\n", ">", "ERROR" , "CONNECT FAIL",tmeout);		
						
//*************************************tcp initialization*******************************/
			clear();		
						cond=mystrstr(uart_string_gsm,'>');
								if(cond)	
								{	

									clear();
									memset(uart_string_gsm,0,5000);
									strcat(data,"\n");
									len=strlen(data);
									tout=0;
									k2=0;
									for(k=0;k<len;k++)
									{
										uart_putchar(UART1_BASE_PTR, data[k]);
									}uart_putchar(UART1_BASE_PTR, 0x1A);
									do
																{stcond1=strstr(uart_string_gsm,"SEND OK");
																	stcond2=strstr(uart_string_gsm, "ERROR");
																		stcond3=strstr(uart_string_gsm, "FAIL");	
																			stcond4=strstr(uart_string_gsm, "DEACT");	
																	
																}while(!(stcond2 || stcond3 || stcond4 || stcond1 || (tout > 8) ) ); //|| (timeout < 1)   
																delay(10);clear();
														uart_putchar(UART1_BASE_PTR,0x1A);
												delay(10);
										uart_putchar(UART1_BASE_PTR, 0x1A);uart_putchar(UART1_BASE_PTR, 0x1A);uart_putchar(UART1_BASE_PTR, 0x1A);
										uart_putchar(UART1_BASE_PTR,0x1A);clear();delay(10);
										uart_putchar(UART1_BASE_PTR,0x1A);clear();delay(10);
															
										qwe=strlen(uart_string_gsm);
										uart_putchar(UART1_BASE_PTR,0x1A);clear();delay(10);
								delay(50);
								con1d=strstr(uart_string_gsm,"SEND OK");
								if(!(con1d) == 1 )
								{
									delay(100);
									clear();//memset(uart_string_gsm,0,5000);
									memset(at_,0,100);
									sprintf(at_,"\r\nAT+FSWRITE=%s\\LOG.TXT,1,%d,10\n\n",drive,strlen(data)+1);	
									send_SD(at_, ">", "ERROR\r\n" , "ERROR",5);
if(strstr(uart_string_gsm,"ERROR")){
	drive[0]='C';drive[1]=':';
}	
									clear();	
									k2=0;									//string array counter for uart 1
									tout=0;	
									for(k=0;k<strlen(data);k++)
									{
										uart_putchar(UART1_BASE_PTR, data[k]);//clear();
									}	
										uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');	uart_putchar(UART1_BASE_PTR, '\n');	uart_putchar(UART1_BASE_PTR, '\n');	uart_putchar(UART1_BASE_PTR, '\n');	uart_putchar(UART1_BASE_PTR, '\n');	uart_putchar(UART1_BASE_PTR, '\n');	uart_putchar(UART1_BASE_PTR, '\n');	
									while(!(strstr(uart_string_gsm,"OK\r\n")  || (strstr(uart_string_gsm, "ERROR") ||  (tout > 5) )))
									{}
	                memset(data,0,strlen(data));
									clear();
									}else{
									//send_chunk();
									}	
						}else{
									delay(100);
									clear();//memset(uart_string_gsm,0,5000);

									memset(at_,0,100);
									sprintf(at_,"\r\nAT+FSWRITE=%s\\LOG.TXT,1,%d,10\n\n",drive,strlen(data)+1);	
									send_SD(at_, ">", "ERROR\r\n" , "ERROR",5);
if(strstr(uart_string_gsm,"ERROR")){
	drive[0]='C';drive[1]=':';
}	
									clear();	
									k2=0;									//string array counter for uart 1
									tout=0;	
		for(k=0;k<strlen(data);k++)
		{
			uart_putchar(UART1_BASE_PTR, data[k]);//clear();
		}	
		uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');	uart_putchar(UART1_BASE_PTR, '\n');	uart_putchar(UART1_BASE_PTR, '\n');	uart_putchar(UART1_BASE_PTR, '\n');	uart_putchar(UART1_BASE_PTR, '\n');	uart_putchar(UART1_BASE_PTR, '\n');	uart_putchar(UART1_BASE_PTR, '\n');	
								
									while(!(strstr(uart_string_gsm,"OK\r\n")  || (strstr(uart_string_gsm, "ERROR") ||  (tout > 5) )))
									{}
	                 memset(data,0,strlen(data));
									 clear();
  								logged=1;}			//

							

	} // if there is a gsm connect available this segment checks for the log available and send it in chunks,..
	else
	{
		//send_chunk();
	}		
								
								
								
	memset(data,0,strlen(data));	
	uart_putchar(UART1_BASE_PTR, 0x1A);

while(1)
{
LED_state();
LED_state2();
RESET_ON; //not reset
msg_sim800(); 
	DTR_OFF;		// not sleep	
	delay(200);

	sleep_flag=0;
//	if(voltagecbc<4000){breach=1;}
//	else{breach=0;}
	if(	(GPIOC_PDIR & 0x00000001) || (GPIOB_PDIR & 0x00000001)){
	DTR_OFF;sleep_flag = 0;
	}
	else{
	DTR_ON;sleep_flag=1;
	}

	
	
if(rtcticks2>=1500){
	DTR_OFF;
	send_modem("\r\n\r\n\r\n\n\n\n\n\nDEVICE IS RESETTING.......\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\r\n\n\n");
	clear();
		delay(100);

	savecursor();
	
				memset(at_,0,100);
				sprintf(at_,"\r\nAT+FSWRITE=%s\\LOG.TXT,1,%d,10\n\n",drive,strlen(data)+1);	
				send_SD(at_, ">", "ERROR\r\n" , "ERROR",5);
if(strstr(uart_string_gsm,"ERROR")){
	drive[0]='C';drive[1]=':';
}	
				//clear();	
				k2=0;									//string array counter for uart 1
				tout=0;	
				for(k=0;k<strlen(data);k++)
				{
					uart_putchar(UART1_BASE_PTR, data[k]);//clear();
				}	
				uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');	uart_putchar(UART1_BASE_PTR, '\n');	uart_putchar(UART1_BASE_PTR, '\n');	uart_putchar(UART1_BASE_PTR, '\n');	uart_putchar(UART1_BASE_PTR, '\n');	uart_putchar(UART1_BASE_PTR, '\n');	uart_putchar(UART1_BASE_PTR, '\n');	
				//memset(data,0,1000);
				//timer counts to wait for characters in uart 1 									
				while(!(strstr(uart_string_gsm,"OK\r\n")  || (strstr(uart_string_gsm, "ERROR") ||  (tout > 5) )))
				{				//uart_putchar(UART1_BASE_PTR, '\n');					
				}
				//clear();//uart_putchar(UART1_BASE_PTR,0x1a);
				//memset(data,0,strlen(data));
				//clear();
	RESET_OFF;
	RESET_OFF;
	delay(100);	
	RESET_ON;
	RESET_ON;	
	delay(100);
	rtcticks2 =0;

	}//3600	
memset(at_,0,100);
sprintf(at_,"\r\n\r\n              <%d>   <%d>   <=%d>         \n \n\n\r\n",aliveping,k5,rtcticks2);							
//send_modem(at_);
//send_modem(num2);	
	

	
if	((sleep_flag != 1  || (aliveping > 5) ) )			
{
	DTR_OFF;
	sleep_flag=0;
	send_GSM("\r\nAT+CIPCLOSE\r\n", "CLOSE OK", "ERROR" , "ERROR:",tmeout);		
	memset(at_,0,100);
	memset(data,0,strlen(data));

	
	if((aliveping>5))	
	{
			memset(ignstr,0,2);
if(GPIOB_PDIR & 0x00000001){
			sprintf(ignstr,"%d,%ld",1,rtcticks2);
}
else{
				sprintf(ignstr,"%d,%ld",0,rtcticks2);

}

memset(acstr,0,2); //ptb2
if(GPIOB_PDIR & 0x00000004){
			sprintf(acstr,"%d",1);
}
else{
				sprintf(acstr,"%d",0);

}

		
		aliveping=0;
		memset(data,0,strlen(data));	
		strcat(data,imei);strcat(data,",ALIVE,");strcat(data,num2);strcat(data,",F=");strcat(data,fuelstr);		strcat(data,",AC=");	
		strcat(data,acstr);
		strcat(data,",I=");	
		strcat(data,ignstr);
		strcat(data,",RS232=");
		strcat(data,id);
		strcat(data,",");
		memset(id,0,30);
		strcat(data,",\n\n\n"); 
	}	
	else{
			GPS_COLLECT();	
	}

	msg_sim800(); 
	
		sprintf(at_, "\r\nAT+CIPSTART=\"TCP\",\"%s\",\"%s\"\r\n", ip, port);
		send_GSM( at_ , "CONNECT", "ERROR" , "ERROR\r\n",tmeout);	
		send_GSM("\r\nAT+CIPSEND\r\n", ">", "ERROR" , "CONNECT FAIL",tmeout);	
		memset(stcond1,0,strlen(stcond1));
		memset(stcond2,0,strlen(stcond2));	
		memset(stcond3,0,strlen(stcond3));	
		memset(stcond4,0,strlen(stcond4));	
		memset(con1d,0,strlen(con1d));	
		cond=0;
								cond=mystrstr(uart_string_gsm,'>');
	
								if(cond)	
								{		
									clear();
									memset(uart_string_gsm,0,5000);
									strcat(data,"\n\n");
									len=strlen(data);
									tout=0;
									k2=0;
									for(k=0;k<len;k++)
									{
										uart_putchar(UART1_BASE_PTR, data[k]);
									}uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, 0x1A);uart_putchar(UART1_BASE_PTR, 0x1A);uart_putchar(UART1_BASE_PTR, 0x1A);uart_putchar(UART1_BASE_PTR, 0x1A);uart_putchar(UART1_BASE_PTR, 0x1A);
									do
																{stcond1=strstr(uart_string_gsm,"SEND OK");
																	stcond2=strstr(uart_string_gsm, "ERROR");
																		stcond3=strstr(uart_string_gsm, "FAIL");	
																			stcond4=strstr(uart_string_gsm, "DEACT");	
																	
																}while(!(stcond2 || stcond3 || stcond4 || stcond1 || (tout > 8) ) ); //|| (timeout < 1)   
																//delay(10);clear();
														uart_putchar(UART1_BASE_PTR,0x1A);
												//delay(10);
										uart_putchar(UART1_BASE_PTR, 0x1A);uart_putchar(UART1_BASE_PTR, 0x1A);uart_putchar(UART1_BASE_PTR, 0x1A);
								
									delay(20);															
									stcond1=strstr(uart_string_gsm,"SEND OK"); 
								}else{}
stcond1=strstr(uart_string_gsm,"SEND OK"); 
//checks for send ok
if(!(stcond1) == 1 ) // if not send ok  ;;;;;;;;;;;;  if no gsm connection is there ,,,... this segment reinitializes GSM, collects GPS data in RAM and attempts to send it
{									uart_putchar(UART1_BASE_PTR, 0x1A);clear();delay(10);
									uart_putchar(UART1_BASE_PTR, 0x1A);clear();delay(10);
									uart_putchar(UART1_BASE_PTR, 0x1A);clear();delay(10);
									remove_all_chars(data, '\n', '\n');
									strcat(data,"CH\n");	
									delay(100);
									clear();//memset(uart_string_gsm,0,5000);
									memset(at_,0,100);
									sprintf(at_,"\r\nAT+FSWRITE=%s\\LOG.TXT,1,%d,10\n\n",drive,strlen(data)+1);	
									send_SD(at_, ">", "ERROR\r\n" , "ERROR",5);
if(strstr(uart_string_gsm,"ERROR")){
	drive[0]='C';drive[1]=':';
}	
									clear();	
									k2=0;									//string array counter for uart 1
									tout=0;	
									for(k=0;k<strlen(data);k++)
									{
										uart_putchar(UART1_BASE_PTR, data[k]);//clear();
									}uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');
									uart_putchar(UART1_BASE_PTR, '\n');	uart_putchar(UART1_BASE_PTR, '\n');	uart_putchar(UART1_BASE_PTR, '\n');
									uart_putchar(UART1_BASE_PTR, '\n');	uart_putchar(UART1_BASE_PTR, '\n');	uart_putchar(UART1_BASE_PTR, '\n');	
									while(!(strstr(uart_string_gsm,"OK\r\n")  || (strstr(uart_string_gsm, "ERROR") ||  (tout > 8) )))
									{}
									clear();
									memset(data,0,strlen(data));
									clear();
									//	log_it();		                         //logging
									memset(data,0,strlen(data));	
temp=int_erval;				
int_erval=4;
//setting interval 4
									GPS_COLLECT();
									strcat(data,"CH\n");	
//**************************************tcp_initialization();//reinitialization*********************************/

		
	msg_sim800(); 
	send_GSM("\r\nAT+CFUN=0\r\r\n\n", "OK", "ERROR\r\n" , "ERROR",5);	
	delay(100);
	send_GSM("\r\nAT+CFUN=1\r\n", "ERROR", "NOT INSERTED" , "Ready", 4);	
	GPS_COLLECT2();
	strcat(data,"CH\n");		
	GPS_COLLECT2();
	strcat(data,"CH\n");	

	cond201=(strstr(uart_string_gsm, "OK"));
	cond200=(strstr(uart_string_gsm, "ERROR"));
	if(  (!cond201 !=0  &&   !cond200 !=0)					&& sleep_flag != 1)
	{
	delay(100);
	clear();//memset(uart_string_gsm,0,5000);
	memset(at_,0,100);
	sprintf(at_,"\r\nAT+FSWRITE=%s\\LOG.TXT,1,%d,10\n\n",drive,strlen(data)+1);	
	send_SD(at_, ">", "ERROR\r\n" , "ERROR",5);
if(strstr(uart_string_gsm,"ERROR")){
	drive[0]='C';drive[1]=':';
}	
	clear();	
	k2=0;									//string array counter for uart 1
	tout=0;	
	for(k=0;k<strlen(data);k++)
	{
	uart_putchar(UART1_BASE_PTR, data[k]);//clear();
	}	
	uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');
	uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');
	uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');
	uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');
										//memset(data,0,1000);
															//timer counts to wait for characters in uart 1 									
										while(!(strstr(uart_string_gsm,"OK\r\n")  || (strstr(uart_string_gsm, "ERROR") ||  (tout > 5) )))
										{				//uart_putchar(UART1_BASE_PTR, '\n');					
										}
										clear();//uart_putchar(UART1_BASE_PTR,0x1a);
										//clear();
										memset(data,0,strlen(data));
										clear();
										RESET_OFF;delay(100);
										RESET_ON;delay(100);		
	}
		
	send_GSM("\r\nAT+CIPSHUT\r\n", "OK", "ERROR\r\n" , "ERROR:",4);	
	GPS_COLLECT2();
	strcat(data,"CH\n");	
	memset(at_,0,100);
	sprintf(at_,"\r\nAT+CSTT=\"%s\"\r\n",apn);
	send_GSM(at_,	"OK", "ERROR\r\n" , "ERROR:",tmeout);							//delay(20);
	msg_sim800(); 
	send_GSM("\r\nAT+CIICR\r\r\n", "OK", "ERROR\r\n" , "DEACT",4);		
	GPS_COLLECT2();
	strcat(data,"CH\n");	
	GPS_COLLECT2();
	strcat(data,"CH\n");	


	msg_sim800(); 
	GPS_COLLECT2();
	strcat(data,"CH\n");	
						clear();send_modem("\nAT+CIFSR\r\r\n");clear();
						delay(20);


	msg_sim800(); 
int_erval=temp;
							sprintf(at_, "\r\nAT+CIPSTART=\"TCP\",\"%s\",\"%s\"\r\n", ip, port);
							send_GSM( at_ , "CONNECT", "ERROR" , "ERROR:",tmeout);	
							clear();
							
							
							send_GSM("\r\nAT+CIPSEND\r\n", ">", "ERROR" , "CONNECT FAIL",tmeout);		
	//*****************************************tcp_initialization ends**************************//									
										clear();		
										memset(stcond1,0,strlen(stcond1));
										memset(stcond2,0,strlen(stcond2));	
										memset(stcond3,0,strlen(stcond3));	
										memset(stcond4,0,strlen(stcond4));								
										cond=mystrstr(uart_string_gsm,'>');    //tries to send if yes sends it;
								
									if(cond)	
									{	
										clear();
										memset(uart_string_gsm,0,5000);
										strcat(data,"\n");
										len=strlen(data);
										tout=0;
										k2=0;
										for(k=0;k<len;k++)
										{uart_putchar(UART1_BASE_PTR, data[k]);
										}uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, 0x1A);uart_putchar(UART1_BASE_PTR, 0x1A);uart_putchar(UART1_BASE_PTR, 0x1A);
										do{stcond1=strstr(uart_string_gsm,"SEND OK");
												stcond2=strstr(uart_string_gsm, "ERROR");
													stcond3=strstr(uart_string_gsm, "FAIL");	
														stcond4=strstr(uart_string_gsm, "DEACT");	
											}while(!(stcond2 || stcond3 || stcond4 || stcond1 || (tout > 8) ) ); //|| (timeout < 1)   
										uart_putchar(UART1_BASE_PTR,0x1A);uart_putchar(UART1_BASE_PTR, 0x1A);uart_putchar(UART1_BASE_PTR, 0x1A);uart_putchar(UART1_BASE_PTR, 0x1A);
										con1d=	(strstr(uart_string_gsm,"SEND OK"));
																	if(!(con1d) == 1 ) 
																	{
																			delay(100);
																			clear();//memset(uart_string_gsm,0,5000);
																			memset(at_,0,100);
																			sprintf(at_,"\r\nAT+FSWRITE=%s\\LOG.TXT,1,%d,10\n\n",drive,strlen(data)+1);	
																			send_SD(at_, ">", "ERROR\r\n" , "ERROR",5);
if(strstr(uart_string_gsm,"ERROR")){
	drive[0]='C';drive[1]=':';
}	
																			clear();	
																			k2=0;									//string array counter for uart 1
																			tout=0;	
																			for(k=0;k<strlen(data);k++)
																			{
																				uart_putchar(UART1_BASE_PTR, data[k]);//clear();
																			}	
																			uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');	uart_putchar(UART1_BASE_PTR, '\n');	uart_putchar(UART1_BASE_PTR, '\n');	uart_putchar(UART1_BASE_PTR, '\n');	uart_putchar(UART1_BASE_PTR, '\n');	uart_putchar(UART1_BASE_PTR, '\n');	uart_putchar(UART1_BASE_PTR, '\n');	
																			while(!(strstr(uart_string_gsm,"OK\r\n")  || (strstr(uart_string_gsm, "ERROR") ||  (tout > 5) ))){}
																			clear();//uart_putchar(UART1_BASE_PTR,0x1a);
																			memset(data,0,strlen(data));
																			clear();
																		
																//	log_it();								
																	}else{send_chunk();}													
									//checks for the sd_data available
									}
									//con1d=strstr(uart_string_gsm,"OK");
									else
									{
											delay(100);
											clear();//memset(uart_string_gsm,0,5000);
											memset(at_,0,100);
											sprintf(at_,"\r\nAT+FSWRITE=%s\\LOG.TXT,1,%d,10\n\n",drive,strlen(data)+1);	
											send_SD(at_, ">", "ERROR\r\n" , "ERROR",5);
if(strstr(uart_string_gsm,"ERROR")){
drive[0]='C';drive[1]=':';
}	
											clear();	
											k2=0;									//string array counter for uart 1
											tout=0;	
											for(k=0;k<strlen(data);k++)
											{
											uart_putchar(UART1_BASE_PTR, data[k]);//clear();
											}	
											uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');	uart_putchar(UART1_BASE_PTR, '\n');	uart_putchar(UART1_BASE_PTR, '\n');	uart_putchar(UART1_BASE_PTR, '\n');	uart_putchar(UART1_BASE_PTR, '\n');	uart_putchar(UART1_BASE_PTR, '\n');	uart_putchar(UART1_BASE_PTR, '\n');	
											//memset(data,0,1000);
											//timer counts to wait for characters in uart 1 									
											while(!(strstr(uart_string_gsm,"OK\r\n")  || (strstr(uart_string_gsm, "ERROR") ||  (tout > 5) )))
											{				//uart_putchar(UART1_BASE_PTR, '\n');					
											}
											clear();//uart_putchar(UART1_BASE_PTR,0x1a);
											memset(data,0,strlen(data));
											clear();
										//log_it();			//otherwize log it					
									}
} // if there is a gsm connect available this segment checks for the log available and send it in chunks,..
else
{
	send_chunk();
}		
/******************sleep checker end**********************/		
		}
/******************while end**********************/		
	} 
/******************main end***********************/
}
/********************************************************************/







void HardFault_Handler()
{	long ppp=0;
send_modem("Hardfault_Handler");	


	RESET_OFF;
	RESET_OFF;
for(ppp=0;ppp<999999; ppp++);	
	
	RESET_ON;
	RESET_ON;
for(ppp=0;ppp<999999; ppp++);
}



 void LPTimer_IRQHandler(void)
{
lpticks+=1;
//rtcticks++;
	tout++;tout2++;
	rtcticks2++;
	if(sleep_flag == 1){aliveping++;}
	if(rtcticks2 > 1600)
	{
	RESET_OFF;
	RESET_OFF;
	delay(100);	
	RESET_ON;
	RESET_ON;	
	delay(100);
	rtcticks2 =0;
	}
	

	
  LPTMR0_CSR |=  LPTMR_CSR_TCF_MASK;   // write 1 to TCF to clear the LPT timer compare flag
  LPTMR0_CSR = ( LPTMR_CSR_TEN_MASK | LPTMR_CSR_TIE_MASK | LPTMR_CSR_TCF_MASK  );
  
}



void SysTick_Handler(void)
{	
	//syscounter++;
	if( intrtmr > 1)
	{
		uart0buffinc = 0;
		intrtmr=0;
	}
	else{
		intrtmr++;
	}
		
	


}





void dtr_sleep()
{

test2=GPIOB_PDIR;
memset(at_,0,strlen(at_));
sprintf(at_,"\n\n\n GPIOB = %d \n\n\n ",test2);	
send_modem(at_);
if( test2 == 0 )	
{
	sleep_flag=1;	
	DTR_ON;   //sleep

}
else
{DTR_OFF;
	
	if (sleep_flag != 0  )
	{
	// wakeup and reset
		sleep_flag=0;
    		// not sleep	
//	  HardFault_Handler();
delay(1000);
send_GSM("\n\nAT\r\n","OK\r\n","ERROR\r\n","ERROR:",tmeout);    
		
send_GSM("\n\nAT+GSV\r\n","OK\r\n","ERROR\r\n","ERROR:",tmeout);

//send_GSM("\n\nAT+CFUN=1\r\n","OK\r\n","ERROR\r\n","ERROR:",tmeout);
		
delay(1000);	
clear();	
	}  
	DTR_OFF;		// not sleep	



}

LED_state();LED_state2();
}


















__inline int myAtoi(char *str)
{res=0;
    // Initialize result

    // Iterate through all characters of input string and update result
    for (iz = 0; str[iz] != '\0'; ++iz)
        res = res*10 + str[iz] - '0';

    // return result.
    return res;
}

__inline float stof(const char* s)
{rez=0;fact=1;

  if (*s == '-'){
    s++;
    fact = -1;
  };
  for (point_seen = 0; *s; s++){
    if (*s == '.'){
      point_seen = 1; 
      continue;
    };
    d = *s - '0';
    if (d >= 0 && d <= 9){
      if (point_seen) fact /= 10.0f;
      rez = rez * 10.0f + (float)d;
    };
  };
  return rez * fact;
};



__inline void GPS_COLLECT()
{imeiinc=0;
delay(200);
clear();
//adc_read(8);							
//memset(fuelstr,0,5);
//sprintf(fuelstr,"%d,",fuel);	
	
memset(imei,0,20);
send_GSM("\r\n\n\nAT+GSN\r\n","OK","ERROR\r\n","ERROR",10);	
for(i=0;i<strlen(uart_string_gsm);i++){
		if((uart_string_gsm[i]>47)   &&   (uart_string_gsm[i]<58)){   //means numeric
			imei[imeiinc] = uart_string_gsm[i];
			imeiinc++;
		}
}
clear();	


	adc_read(9);							
	memset(fuelstr,0,5);
	sprintf(fuelstr,"%d,",fuel);

time52=15;	

	send_GSM("\r\n\r\nAT+CBC\r\n","OK","ERROR","ERROR:",tmeout);
	// not sleep	
	memset(num2,0,30);
	parse_g(uart_string_gsm, 2, 5, ',', '\r' ,num2);
	voltagecbc=myAtoi(num2);
memset(ignstr,0,2);
if(GPIOB_PDIR & 0x00000001){
			sprintf(ignstr,"%d",1);
}
else{
				sprintf(ignstr,"%d",0);

}

memset(acstr,0,2); //ptb2
if(GPIOB_PDIR & 0x00000004){
			sprintf(acstr,"%d",1);
}
else{
			sprintf(acstr,"%d",0);

}


if(int_erval>60){int_erval=5;}
while(lpticks<int_erval);
get_gpsdata();
lpticks=0;

parse_g(rmc, 3, 4, ',', ',' ,lati);
parse_g(rmc, 5, 6, ',', ',' ,longi);
parse_g(rmc, 7, 8, ',', ',' ,velocity);
		
		speed = stof(velocity);
		c=stof(lati);//7523.7412
		hh= c/100; //75
		hh11 = c/100; //75.237412
		mm11 = hh11-hh; //.237412
		mm11*=100;
		mm22=hh+mm11/60;	
		memset(lati,0,15);
		sprintf(lati,"%f",mm22);
		c=stof(longi);//7523.7412
		hh= c/100; //75
		hh11 = c/100; //75.237412
		mm11 = hh11-hh; //.237412
		mm11*=100;
		mm22=hh+mm11/60;	
		memset(longi,0,15);
		sprintf(longi,"%f",mm22);	
		strcat(data,imei);
		strcat(data,",");	
		strcat(data,"$GxGGA");	
		strcat(data,gga);
		strcat(data,",$GxRMC");	
		strcat(data,rmc);	
		strcat(data,",");	
		strcat(data,num2);	
		strcat(data,",F=");	
		strcat(data,fuelstr);		
		strcat(data,",AC=");	
		strcat(data,acstr);
		strcat(data,",I=");	
		strcat(data,ignstr);	
		strcat(data,",RS232=");
		strcat(data,id);
		strcat(data,",");
		memset(id,0,30);
		
		if( !(GPIOC_PDIR & 0x00000001)){
		}
		else{strcat(data,",BR*");}
//return 0;
}


__inline void GPS_COLLECT2()
{	
time52=15;	

//memset(imei,0,20);
//send_GSM("\r\n\n\nAT+GSN\r\n","OK","ERROR\r\n","ERROR",10);	
//for(i=0;i<strlen(uart_string_gsm);i++){
//		if((uart_string_gsm[i]>47)   &&   (uart_string_gsm[i]<58)){   //means numeric
//			imei[imeiinc] = uart_string_gsm[i];
//			imeiinc++;
//		}
//}
clear();	

	
	
	adc_read(9);							
	memset(fuelstr,0,5);
	sprintf(fuelstr,"%d,",fuel);

	send_GSM("\r\n\r\nAT+CBC\r\n","OK","ERROR","ERROR:",tmeout);
	// not sleep	
	memset(num2,0,30);
	parse_g(uart_string_gsm, 2, 5, ',', '\r' ,num2);
	voltagecbc=myAtoi(num2);	

memset(ignstr,0,2);
if(GPIOB_PDIR & 0x00000001){
			sprintf(ignstr,"%d",1);
}
else{
			sprintf(ignstr,"%d",0);

}

memset(acstr,0,2); //ptb2
if(GPIOB_PDIR & 0x00000004){
			sprintf(acstr,"%d",1);
}
else{
				sprintf(acstr,"%d",0);

}
	
while(lpticks<int_erval);
get_gpsdata();
lpticks=0;

parse_g(rmc, 3, 4, ',', ',' ,lati);
parse_g(rmc, 5, 6, ',', ',' ,longi);
parse_g(rmc, 7, 8, ',', ',' ,velocity);
		
		speed = stof(velocity);
		c=stof(lati);//7523.7412
		hh= c/100; //75
		hh11 = c/100; //75.237412
		mm11 = hh11-hh; //.237412
		mm11*=100;
		mm22=hh+mm11/60;	
		memset(lati,0,15);
		sprintf(lati,"%f",mm22);
		c=stof(longi);//7523.7412
		hh= c/100; //75
		hh11 = c/100; //75.237412
		mm11 = hh11-hh; //.237412
		mm11*=100;
		mm22=hh+mm11/60;	
		memset(longi,0,15);
		sprintf(longi,"%f",mm22);	
		strcat(data,imei);
		strcat(data,", ");	
		strcat(data,"$GxGGA");	
		strcat(data,gga);
		strcat(data,", $GxRMC");	
		strcat(data,rmc);	
		strcat(data,",");	
		strcat(data,num2);
		strcat(data,",F=");	
		strcat(data,fuelstr);
		strcat(data,",AC=");	
		strcat(data,acstr);
		strcat(data,",I=");	
		strcat(data,ignstr);	

		strcat(data,",RS232=");
		strcat(data,id);
		strcat(data,",");
		memset(id,0,30);
		if(!(GPIOC_PDIR & 0x00000001)){
		}
		else{strcat(data,",BR*");}
//return 0;
}



__inline void get_gpsdata()
{
						clear2();
						memset(uart_string_gps,0,3000);memset(gga,0,100);memset(rmc,0,100);			
						i=0;tout2=0;
//						t22=9999999;
do{
	if(UART_S1_REG(UART2_BASE_PTR) & UART_S1_RDRF_MASK)
	{		uart_string_gps[i]=UART_D_REG(UART2_BASE_PTR);//clear2();
				i++;
	}
	}while(!   (strstr(uart_string_gps,"RMC")       ||  (tout2>1)  )  );
i=0;tout2=0;
do{
	if(UART_S1_REG(UART2_BASE_PTR) & UART_S1_RDRF_MASK)
	{		rmc[i]=UART_D_REG(UART2_BASE_PTR);//clear2();
				i++;
	}
}while(     !( mystrstr(rmc,'*')    ||  tout2>1) );
memset(uart_string_gps,0,3000);
i=0;tout2=0;
do{
	if(UART_S1_REG(UART2_BASE_PTR) & UART_S1_RDRF_MASK)
	{		uart_string_gps[i]=UART_D_REG(UART2_BASE_PTR);//clear2();
				i++;
	}
}while(!  (strstr(uart_string_gps,"GGA")      ||  (tout2>1) )  );
i=0;tout2=0;
do{
	if(UART_S1_REG(UART2_BASE_PTR) & UART_S1_RDRF_MASK)
	{		gga[i]=UART_D_REG(UART2_BASE_PTR);//clear2();
				i++;
	}
}while(!(mystrstr(gga,'*')  ||  (tout2>1) ));

clear2();

		

stateCount++; 
if(stateCount>5){stateCount =0;}
LED_state2();					
}
	

__inline void msg_sim800() 
{
		cond1=0;
		cond2=0;
		cond3=0;
		cond4=0;
		cond5=0;
		cond6=0;
		cond7=0;
		cond8=0;
		cond9=0;
		cond10=0;
		cond11=0;
		cond12=0;
		cond13=0;
		cond14=0;
		cond15=0;		
	
//ringflag=1;	
	if(ringflag==1 )
	{
		sleep_flag=0;
    DTR_OFF;		// not sleep	

delay(1000);
send_GSM("\n\nAT\r\n","OK\r\n","ERROR\r\n","ERROR:",tmeout);    
		
send_GSM("\n\nAT+GSV\r\n","OK\r\n","ERROR\r\n","ERROR:",tmeout);  		
delay(1000);		
		

	send_GSM("\n\nAT+CMGF=1\n\n","OK\r\n","ERROR\r\n","ERROR:",tmeout);	
	send_GSM("\n\nAT+CSCA?\r\n","OK\r\n","ERROR\r\n","ERROR:",tmeout);    //   uart_putchar(UART1_BASE_PTR,0x1A);uart_putchar(UART1_BASE_PTR,0xA);uart_putchar(UART1_BASE_PTR,0x1A);uart_putchar(UART1_BASE_PTR,0xA);uart_putchar(UART1_BASE_PTR,0x1A);		

					send_GSM("\r\nAT+CMGR=1\r\n", "OK\r\n", "ERROR" , "OK\r\n",tmeout);	
					clear();
					memset(num2,0,30);
					parse_gsm(uart_string_gsm, 3, 4, num2);
			
						cond1=strstr(uart_string_gsm, "OWNER");	
						cond2=strstr(uart_string_gsm, "LOCATION");
						cond3=strstr(uart_string_gsm, "INTERVAL");
						cond4=strstr(uart_string_gsm, "START");
						cond5=strstr(uart_string_gsm, "OWNER1");
						cond6=strstr(uart_string_gsm, "OWNER2");
						cond7=strstr(uart_string_gsm, "OWNER3");
						cond8=strstr(uart_string_gsm, "DEBUG");
						cond9=strstr(uart_string_gsm, "RESET");
						cond10=strstr(uart_string_gsm, "IP");
						cond11=strstr(uart_string_gsm, "SUOWNER");	
						cond12=strstr(uart_string_gsm, "SOWNER");	
						cond13=strstr(uart_string_gsm, "IGNITION ON");	
						cond14=strstr(uart_string_gsm, "IGNITION OFF");	
						cond15=strstr(uart_string_gsm, "IGNSTAT");

							if(send_SOS==1){
										

								
								memset(data2,0,300);
								sprintf(data2,"\nThere is an Emergency please help:\nCoordinates:%sN,%sE\nhttps://www.google.com/search?q=%s%c2C%s&ie=utf-8&oe=utf-8\n",lati,longi,lati,'%',longi);	
								memset(num2,0,30);
								send_GSM("\r\nAT+CPBR=1\r\n","OK\r\n","ERROR\r\n","ERROR:",tmeout);	
								parse_g(uart_string_gsm, 1, 2, '"', '"', num2);										
								send_message(data2);
								memset(num2,0,30);
								send_GSM("\r\nAT+CPBR=2\r\n","OK\r\n","ERROR\r\n","ERROR:",tmeout);	
								parse_g(uart_string_gsm, 1, 2, '"', '"', num2);										
								send_message(data2);								
								send_SOS=0;
							}
							else if(cond1 && cond2)
							{
								memset(data2,0,300);
								sprintf(data2,"\nCoordinates : %s N, %s E\nSpeed : %s kmph\n\nhttps://www.google.com/search?q=%s%c2C%s&ie=utf-8&oe=utf-8\n",lati,longi,velocity,lati,'%',longi);	

								{send_message(data2);}

								send_GSM("\r\nAT+CMGD=1,4\r\n","OK\r\n","ERROR\r\n","ERROR:",tmeout);	
								
								
							}
	
							else if(cond1 && cond3)
							{
								memset(at_,0,100);
								memset(interval,0,5);
								parse_g(uart_string_gsm, 3, 5, ' ', '\r', interval);		
								int_erval=myAtoi(interval);
								save_interval();			
								send_GSM("\r\nAT+CMGD=1,4\r\n","OK\r\n","ERROR\r\n","ERROR:",tmeout);	

								
							}				

			
							else if(cond12 && cond4)
							{
								memset( apn,0,25);
								parse_g(uart_string_gsm, 3, 5, ' ', '\r', apn);			
								saveapn();								
								send_GSM("\nAT+FSCREATE=C:\\IP_PORT.TXT\r\n", "OK", "ERROR\r\n" , "ERROR:",tmeout);
								send_GSM("\nAT+FSCREATE=D:\\LOG.TXT\r\n", "OK", "ERROR\r\n" , "ERROR:",tmeout);
								send_GSM("\nAT+FSCREATE=C:\\LOG.TXT\r\n", "OK", "ERROR\r\n" , "ERROR:",tmeout);
								send_GSM("\nAT+FSCREATE=C:\\INTERVAL.TXT\r\n", "OK", "ERROR\r\n" , "ERROR:",tmeout);
								send_GSM("\nAT+FSCREATE=C:\\IGN.TXT\r\n", "OK", "ERROR\r\n" , "ERROR:",tmeout);

								memset(ip,0,100);
								memset(port,0,10);
								strcat (ip, "rudra.jellyfishtele.com");
								strcat (port, "5555");		
								memcpy (interval, "5", 1);										
								save_ip_port();
								ignstaton();

								save_interval();	
								int_erval=myAtoi(interval);		
								savecursord();

			//					printf("\n\n\t,%s,%s,%s,\n",ip,port,interval);		
								
send_GSM("\r\n AT+CMGD=1,4\r\n\r\n","OK","ERROR","ERROR:",tmeout);		

								
								
		RESET_OFF;delay(10);
		RESET_ON;delay(10);		

								
								
							}
	
						else if(cond8)
							{
								
									memset(at_,0,100);
									for(k=0;k<450;k++)
									{
										if(uart_string_gsm[k-1] == ' ' && uart_string_gsm[k-2] == 'G' && uart_string_gsm[k-3] == 'U'
										&& uart_string_gsm[k-4] == 'B' && uart_string_gsm[k-5] == 'E' && uart_string_gsm[k-6] == 'D')
										{
											for(i=0;i<100;i++)
											{
												at_[i]=uart_string_gsm[k];
												k++;
											}	
										at_[i+1]='\r';
										at_[i+2]='\n';	
										}
										else{}
									}
									
								send_GSM("\r\nAT+CMGD=1,4\r\n","OK\r\n","ERROR\r\n","ERROR:",tmeout);	
									  send_GSM(at_,"OK\r\n","ERROR\r\n","ERROR:",tmeout);		
										memset(data2,0,strlen(data2));
										sprintf(data2,"%s",uart_string_gsm);	
										send_message(data2);
										
									
								
							}
							
							else if( cond1 && cond9)
							{
								send_GSM("\r\nAT+CMGD=1,4\r\n","OK\r\n","ERROR\r\n","ERROR:",tmeout);	

strcat(data,"\n");	
GPS_COLLECT();
strcat(data,"CH\n");	

								

	delay(100);
		clear();//memset(uart_string_gsm,0,5000);
	
	memset(at_,0,100);
sprintf(at_,"\r\nAT+FSWRITE=%s\\LOG.TXT,1,%d,10\n\n",drive,strlen(data)+1);	
send_SD(at_, ">", "ERROR\r\n" , "ERROR",5);
if(strstr(uart_string_gsm,"ERROR")){
	drive[0]='C';drive[1]=':';
}	
clear();	
									k2=0;									//string array counter for uart 1
									tout=0;	
		for(k=0;k<strlen(data);k++)
		{
			uart_putchar(UART1_BASE_PTR, data[k]);//clear();
		}	
uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');	uart_putchar(UART1_BASE_PTR, '\n');	uart_putchar(UART1_BASE_PTR, '\n');	uart_putchar(UART1_BASE_PTR, '\n');	uart_putchar(UART1_BASE_PTR, '\n');	uart_putchar(UART1_BASE_PTR, '\n');	uart_putchar(UART1_BASE_PTR, '\n');	
									//memset(data,0,1000);
														//timer counts to wait for characters in uart 1 									
									while(!(strstr(uart_string_gsm,"OK\r\n")  || (strstr(uart_string_gsm, "ERROR") ||  (tout > 5) )))
									{				//uart_putchar(UART1_BASE_PTR, '\n');					
									}
	                clear();//uart_putchar(UART1_BASE_PTR,0x1a);
									//clear();
									memset(data,0,strlen(data));
									clear();

																
								
								
//log_it();								
		RESET_OFF;delay(10);
		RESET_ON;delay(10);
								send_GSM("\n\n AT+CFUN=1,1\r\n","Ready","ERROR\r\n","NOT INSERTED:",tmeout);			
							}
							
							else if(cond12 && cond10)
							{
						//		printf("\n\n\n\t%s",uart_string_gsm);
								memset(ip,0,16);
								parse_g(uart_string_gsm, 3, 4, ' ', ' ', ip);
								parse_g(uart_string_gsm, 6, 5, ' ', '\r', port);	
			//					printf("\n%s\n",port);
								save_ip_port();
							
	//							printf("\n\n\n\t%s\t||\t%s",ip,port);
								send_GSM("\r\nAT+CMGD=1,4\r\n","OK\r\n","ERROR\r\n","ERROR:",tmeout);	

//								while(1);
								
								
							}

											
							else if(cond1 && cond13)
							{
								
								IGNITION_ON;FUEL_ON;
								clear();
								ignstaton();
								delay(1000);
								send_GSM("\r\r\nAT+CMGD=1,4\r\n\n\n\n\n","OK\r\n","ERROR\r\n","ERROR:",tmeout);	
								
							}
							else if(cond1 && cond14)
							{
								
								IGNITION_OFF;FUEL_OFF;
								clear();
								ignstatoff();
								delay(1000);
								
								
								
								
								
								send_GSM("\r\r\nAT+CMGD=1,4\r\n\n\n\n\n","OK\r\n","ERROR\r\n","ERROR:",tmeout);	
								
							}
							
							else if(cond1 && cond5)
							{
								

								memset(at_,0,100);
								memset(num_o,0,15);
								parse_g(uart_string_gsm, 3, 5, ' ', '\r', num_o);
								send_GSM("\n\nAT+CPBS=\"SM\"\r\n","OK\r\n","ERROR\r\n","ERROR:",tmeout);
								send_GSM("\r\nAT+CPBW=1\r\r\n\n", "OK", "ERROR\r\n" , "ERROR",4);	

								sprintf(at_, "\r\nAT+CPBW=1,\"%s\",129,\"OWNER1\"\r\n" , num_o);
								send_GSM(at_,"OK\r\n","ERROR\r\n","ERROR:",tmeout);
								
								send_GSM("\n\nAT+CPBS=\"ME\"\r\n","OK\r\n","ERROR\r\n","ERROR:",tmeout);
								send_GSM("\r\nAT+CPBW=1\r\r\n\n", "OK", "ERROR\r\n" , "ERROR",4);	

								sprintf(at_, "\r\nAT+CPBW=1,\"%s\",129,\"OWNER1\"\r\n" , num_o);
								send_GSM(at_,"OK\r\n","ERROR\r\n","ERROR:",tmeout);

								send_GSM("\r\nAT+CMGD=1,4\r\n","OK\r\n","ERROR\r\n","ERROR:",tmeout);	
															
						
								
							}		
							else if(cond1 && cond6)
							{

								
								memset(at_,0,100);
								memset(num_o,0,15);
								parse_g(uart_string_gsm, 3, 5, ' ', '\r', num_o);
								send_GSM("\n\nAT+CPBS=\"SM\"\r\n","OK\r\n","ERROR\r\n","ERROR:",tmeout);
								send_GSM("\r\nAT+CPBW=2\r\r\n\n", "OK", "ERROR\r\n" , "ERROR",4);	

								sprintf(at_, "\r\nAT+CPBW=2,\"%s\",129,\"OWNER2\"\r\n" , num_o);
								send_GSM(at_,"OK\r\n","ERROR\r\n","ERROR:",tmeout);
								
								send_GSM("\n\nAT+CPBS=\"ME\"\r\n","OK\r\n","ERROR\r\n","ERROR:",tmeout);
								send_GSM("\r\nAT+CPBW=2\r\r\n\n", "OK", "ERROR\r\n" , "ERROR",4);	

								sprintf(at_, "\r\nAT+CPBW=2,\"%s\",129,\"OWNER2\"\r\n" , num_o);
								send_GSM(at_,"OK\r\n","ERROR\r\n","ERROR:",tmeout);								

								send_GSM("\r\nAT+CMGD=1,4\r\n","OK\r\n","ERROR\r\n","ERROR:",tmeout);	
							}									
							else if(cond1 && cond7)
							{
								
								memset(at_,0,100);
								memset(num_o,0,15);
								parse_g(uart_string_gsm, 3, 5, ' ', '\r', num_o);
								send_GSM("\n\nAT+CPBS=\"SM\"\r\n","OK\r\n","ERROR\r\n","ERROR:",tmeout);
								send_GSM("\r\nAT+CPBW=3\r\r\n\n", "OK", "ERROR\r\n" , "ERROR",4);	

								sprintf(at_, "\r\nAT+CPBW=3,\"%s\",129,\"OWNER3\"\r\n" , num_o);
								send_GSM(at_,"OK\r\n","ERROR\r\n","ERROR:",tmeout);
								
								send_GSM("\n\nAT+CPBS=\"ME\"\r\n","OK\r\n","ERROR\r\n","ERROR:",tmeout);
								send_GSM("\r\nAT+CPBW=3\r\r\n\n", "OK", "ERROR\r\n" , "ERROR",4);	

								sprintf(at_, "\r\nAT+CPBW=3,\"%s\",129,\"OWNER3\"\r\n" , num_o);
								send_GSM(at_,"OK\r\n","ERROR\r\n","ERROR:",tmeout);
								send_GSM("\r\nAT+CMGD=1,4\r\n","OK\r\n","ERROR\r\n","ERROR:",tmeout);	
							}			
							else if(cond11)
							{

								memset(at_,0,100);
								memset(num_o,0,15);
								parse_g(uart_string_gsm, 3, 5, ' ', '\r', num_o);
								send_GSM("\n\nAT+CPBS=\"SM\"\r\n","OK\r\n","ERROR\r\n","ERROR:",tmeout);
								send_GSM("\r\nAT+CPBW=4\r\r\n\n", "OK", "ERROR\r\n" , "ERROR",4);	

								sprintf(at_, "\r\nAT+CPBW=4,\"%s\",129,\"SOWNER\"\r\n" , num_o);
								send_GSM(at_,"OK\r\n","ERROR\r\n","ERROR:",tmeout);
								
								send_GSM("\n\nAT+CPBS=\"ME\"\r\n","OK\r\n","ERROR\r\n","ERROR:",tmeout);
								send_GSM("\r\nAT+CPBW=4\r\r\n\n", "OK", "ERROR\r\n" , "ERROR",4);	

								sprintf(at_, "\r\nAT+CPBW=4,\"%s\",129,\"SOWNER\"\r\n" , num_o);
								send_GSM(at_,"OK\r\n","ERROR\r\n","ERROR:",tmeout);
								
								send_GSM("\r\nAT+CMGD=1,4\r\n","OK\r\n","ERROR\r\n","ERROR:",tmeout);	
								
							}	
							else if(cond15)
							{
								send_message(ignstr);
								
							}							

							else
							{							
								send_GSM("\r\n AT+CMGD=1,4\r\n","OK\r\n","ERROR\r\n","ERROR:",tmeout);	
							}


		ringflag=0;
clear();							
send_GSM("\r\n AT+CMGD=1,4\r\n\r\n","OK","ERROR","ERROR:",tmeout);		
delay(1000);					
		}
		
}
int count_char(char ch,char* string)
{count=0;

	//remove_all_chars(string,'\0','\0');
//	ass=strlen(string);
	for(ass=0;ass<strlen(string);ass++)
	{
		if(string[ass] == ch)
		{count++;}
		
	}
return count;
}






int cursor_val(char * stringsd, int cur){
int curinc=0,curcounter=0,cur2=0;
for(curinc=0;curinc<strlen(stringsd);curinc++){
		
		if(stringsd[curinc] == '\n'     &&    curcounter < cur   ){ //&& curcounter<=cur	){
			++curcounter;     cur2=curinc;
		}

		

}
	
	
	return cur2;

}


__inline void  send_chunk(){
fsz=0;
times=-2;	
	

temp=int_erval;				
int_erval=1;

	
memset(at_,0,100);
sprintf(at_,"\r\n\r\nAT+FSFLSIZE=%s\\LOG.TXT\r\n",drive);	
send_GSM(at_, "OK", "ERROR\r\n" , "ERROR:",tmeout);
parse_g(uart_string_gsm, 1,5, ' ', '\r', fsize);
fsz=stof(fsize);//7523.7412	              //1400 is the maximum imit  //200 is the maximum size of 1 data	
//reading buffer of SD data = 1400 // need to concatinate maximum amount of data in it and a 200 character data
	
times =	(fsz/900) + 2;
for(;k5<=(times);){
if(fsz==0){log0=1;break;}
else log0=0;

	RESET_ON;
	DTR_OFF;
	
msg_sim800(); 

memset(data,0,strlen(data));	
strcat(data,"\n");	
	
	
	memset(at_,0,100);
	sprintf(at_,"\r\n\r\nAT+FSFLSIZE=%s\\LOG.TXT\r\n",drive);
GPS_COLLECT();

	
	send_GSM(at_, "OK", "ERROR\r\n" , "ERROR:",tmeout);
	parse_g(uart_string_gsm, 1,5, ' ', '\r', fsize);
	fsz=stof(fsize);//7523.7412	              //1400 is the maximum imit  //200 is the maximum size of 1 data	
	//reading buffer of SD data = 1400 // need to concatinate maximum amount of data in it and a 200 character data
	times =	(fsz/900) + 1;	
	
	
memset(at_,0,100);
sprintf(at_,"\r\n\r\n              <%d>   <%d>   <=%d>          \r\n\r\n",times,k5,rtcticks2);							
send_modem(at_);
clear();
	
	
		sprintf(at_, "\r\n\r\nAT+FSREAD=%s\\LOG.TXT,1,1100,%d\r\n",drive,cursorvaluepr );		//1256
		send_GSM(at_, "OK", "ERROR\r\n" , "ERROR:",5);
			if(strstr(uart_string_gsm,"ERROR")){
				RESET_OFF;
				delay(50);
				RESET_ON;
				delay(50);
			}
		cntendl=count_char('\n',uart_string_gsm);
   //if(cntendl!=0)
		enters = cntendl;		
		memset(sd_data,0,1400);
		parse_g(uart_string_gsm, 1,enters-2, '\n', '\n' ,sd_data);	
		strcat(sd_data,"\n");
		strcat(sd_data,data);
		if(strstr(sd_data,"SEND OK")    ||   strstr(sd_data,"ERROR") || strstr(sd_data,"FAIL")  ||  strstr(sd_data,"DEACT"))	{
		memset(exception,0,200);	
		strcat(exception,"exception : COMPARED RESPONCES IN THE DATA\n\n\n\n");	
		}
		else{memset(exception,0,200);}

	
		qwe=strlen(uart_string_gsm);
		memset(uart_string_gsm,0,qwe);
		

	
		
		send_GSM("\r\nAT+CIPSEND\r\n", ">", "ERROR" , "CONNECT",tmeout);	
								cond =mystrstr(uart_string_gsm,'>');
									if(cond)	
									{	
									clear();
									memset(uart_string_gsm,0,5000);
									if(strlen(exception) > 5){
									qwe=strlen(exception);
									}
									else{										
									qwe=strlen(sd_data);
									}										
									tout=0;
									k2=0;
									for(k=0;k<(qwe);k++)
									{
										if(strlen(exception) > 5){
										uart_putchar(UART1_BASE_PTR, exception[k]);	
										}
										else{										
										uart_putchar(UART1_BASE_PTR, sd_data[k]);
										}
									}uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, 0x1A);uart_putchar(UART1_BASE_PTR, 0x1A);uart_putchar(UART1_BASE_PTR, 0x1A);uart_putchar(UART1_BASE_PTR, 0x1A);	uart_putchar(UART1_BASE_PTR, 0x1A);uart_putchar(UART1_BASE_PTR, 0x1A);	
									do
																{q1=strstr(uart_string_gsm,"SEND OK");
																	q2=strstr(uart_string_gsm, "ERROR");
																		q3=strstr(uart_string_gsm, "FAIL");	
																			q4=strstr(uart_string_gsm, "DEACT");	
																	
																}while(!(q1 || q2 || q3 || q4 || (tout > 8) ) ); //|| (timeout < 1)   
																delay(10);clear();
														uart_putchar(UART1_BASE_PTR,0x1A);
												delay(10);
										uart_putchar(UART1_BASE_PTR, 0x1A);uart_putchar(UART1_BASE_PTR, 0x1A);uart_putchar(UART1_BASE_PTR, 0x1A);
delay(50);
if(strstr(uart_string_gsm,"SEND OK"))
{
cursorvaluene=cursor_val(sd_data,enters-3);
cursorvaluepr+=cursorvaluene;
k5++;
}
else{remove_all_chars(data, '\n', '\n');
			strcat(data,"CH\n");

	delay(100);
		clear();//memset(uart_string_gsm,0,5000);
	
	memset(at_,0,100);
sprintf(at_,"\r\nAT+FSWRITE=%s\\LOG.TXT,1,%d,10\n\n",drive,strlen(data)+1);	
send_SD(at_, ">", "ERROR\r\n" , "ERROR",5);

	
clear();	
									k2=0;									//string array counter for uart 1
									tout=0;	
		for(k=0;k<strlen(data);k++)
		{
			uart_putchar(UART1_BASE_PTR, data[k]);//clear();
		}	
uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');	uart_putchar(UART1_BASE_PTR, '\n');	uart_putchar(UART1_BASE_PTR, '\n');	uart_putchar(UART1_BASE_PTR, '\n');	uart_putchar(UART1_BASE_PTR, '\n');	uart_putchar(UART1_BASE_PTR, '\n');	uart_putchar(UART1_BASE_PTR, '\n');	
														//timer counts to wait for characters in uart 1 									
									while(!(strstr(uart_string_gsm,"OK\r\n")  || (strstr(uart_string_gsm, "ERROR") ||  (tout > 5) )))
									{	}
	                clear();
									memset(data,0,strlen(data));
									clear();

								



//	log_it();

			memset(data,0,strlen(data));
//*********************************tcp_initialization();***************************************//

	
msg_sim800(); 
send_GSM("\r\nAT+CFUN=0\r\r\n\n", "OK", "ERROR\r\n" , "ERROR",5);	
delay(100);
send_GSM("\r\nAT+CFUN=1\r\n", "Ready", "NOT INSERTED" , "ERROR", 4);	
GPS_COLLECT2();
strcat(data,"CH\n");		
GPS_COLLECT2();
strcat(data,"CH\n");	
GPS_COLLECT2();
strcat(data,"CH\n");
cond201=(strstr(uart_string_gsm, "OK"));
cond200=(strstr(uart_string_gsm, "ERROR"));
if(  (!cond201 !=0  &&   !cond200 !=0)					&& sleep_flag != 1)
{
delay(100);
clear();//memset(uart_string_gsm,0,5000);
memset(at_,0,100);
sprintf(at_,"\r\nAT+FSWRITE=%s\\LOG.TXT,1,%d,10\n\n",drive,strlen(data)+1);	
send_SD(at_, ">", "ERROR\r\n" , "ERROR",5);
clear();	
k2=0;									//string array counter for uart 1
tout=0;	
for(k=0;k<strlen(data);k++)
{
uart_putchar(UART1_BASE_PTR, data[k]);//clear();
}	
uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');	uart_putchar(UART1_BASE_PTR, '\n');	uart_putchar(UART1_BASE_PTR, '\n');	uart_putchar(UART1_BASE_PTR, '\n');	uart_putchar(UART1_BASE_PTR, '\n');	uart_putchar(UART1_BASE_PTR, '\n');	uart_putchar(UART1_BASE_PTR, '\n');	
									//memset(data,0,1000);
														//timer counts to wait for characters in uart 1 									
									while(!(strstr(uart_string_gsm,"OK\r\n")  || (strstr(uart_string_gsm, "ERROR") ||  (tout > 5) )))
									{				//uart_putchar(UART1_BASE_PTR, '\n');					
									}
	                clear();//uart_putchar(UART1_BASE_PTR,0x1a);
									//clear();
									memset(data,0,strlen(data));
									clear();
									RESET_OFF;delay(100);
									RESET_ON;delay(100);		
}
	
send_GSM("\r\nAT+CIPSHUT\r\n", "OK", "ERROR\r\n" , "ERROR:",4);	
GPS_COLLECT2();
strcat(data,"CH\n");	
memset(at_,0,100);
sprintf(at_,"\r\nAT+CSTT=\"%s\"\r\n",apn);
send_GSM(at_,	"OK", "ERROR\r\n" , "ERROR:",tmeout);							//delay(20);
msg_sim800(); 
send_GSM("\r\nAT+CIICR\r\r\n", "OK", "ERROR\r\n" , "DEACT",4);		
GPS_COLLECT2();
strcat(data,"CH\n");	
GPS_COLLECT2();
strcat(data,"CH\n");	


msg_sim800(); 
GPS_COLLECT2();
strcat(data,"CH\n");	
					clear();send_modem("\nAT+CIFSR\r\r\n");clear();
					delay(20);


msg_sim800(); 

						sprintf(at_, "\r\nAT+CIPSTART=\"TCP\",\"%s\",\"%s\"\r\n", ip, port);
						send_GSM( at_ , "CONNECT", "ERROR" , "ERROR:",tmeout);	
						clear();
						
						
						send_GSM("\r\nAT+CIPSEND\r\n", ">", "ERROR" , "CONNECT FAIL",tmeout);											
									
//*********************************tcp_initialization ends*************************************//									
			if(mystrstr(uart_string_gsm,'>')){
									clear();
									memset(uart_string_gsm,0,5000);
									qwe=strlen(data);
									tout=0;
									k2=0;
									for(k=0;k<(qwe);k++)
									{
										uart_putchar(UART1_BASE_PTR, data[k]);
									}uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, 0x1A);uart_putchar(UART1_BASE_PTR, 0x1A);	uart_putchar(UART1_BASE_PTR, 0x1A);uart_putchar(UART1_BASE_PTR, 0x1A);	uart_putchar(UART1_BASE_PTR, 0x1A);uart_putchar(UART1_BASE_PTR, 0x1A);	
															do
																{q1=strstr(uart_string_gsm,"SEND OK");
																	q2=strstr(uart_string_gsm, "ERROR");
																		q3=strstr(uart_string_gsm, "FAIL");	
																			q4=strstr(uart_string_gsm, "DEACT");	
																	
																}while(!(q1 || q2 || q3 || q4 || (tout > 8) ) );
															
																			delay(10);clear();
														uart_putchar(UART1_BASE_PTR,0x1A);
												delay(10);
										uart_putchar(UART1_BASE_PTR, 0x1A);uart_putchar(UART1_BASE_PTR, 0x1A);uart_putchar(UART1_BASE_PTR, 0x1A);
delay(20);
if(!strstr(uart_string_gsm,"SEND OK")){


	delay(100);
		clear();//memset(uart_string_gsm,0,5000);
	
	memset(at_,0,100);
sprintf(at_,"\r\nAT+FSWRITE=%s\\LOG.TXT,1,%d,10\n\n",drive,strlen(data)+1);	
send_SD(at_, ">", "ERROR\r\n" , "ERROR",5);
//uart_putchar(UART1_BASE_PTR,'\n');uart_putchar(UART1_BASE_PTR,'\n');uart_putchar(UART1_BASE_PTR,'\n');	
//	if(strstr(uart_string_gsm,"ERROR")){
//	sprintf(at_,"\nAT+FSCREATE=%s\\LOG.TXT\r\n",drive);
//	send_GSM(at_, "OK", "ERROR\r\n" , "ERROR:",tmeout);
//	}
	
clear();	
									k2=0;									//string array counter for uart 1
									tout=0;	
		for(k=0;k<strlen(data);k++)
		{
			uart_putchar(UART1_BASE_PTR, data[k]);//clear();
		}	
uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');	uart_putchar(UART1_BASE_PTR, '\n');	uart_putchar(UART1_BASE_PTR, '\n');	uart_putchar(UART1_BASE_PTR, '\n');	uart_putchar(UART1_BASE_PTR, '\n');	uart_putchar(UART1_BASE_PTR, '\n');	uart_putchar(UART1_BASE_PTR, '\n');	
									//memset(data,0,1000);
														//timer counts to wait for characters in uart 1 									
									while(!(strstr(uart_string_gsm,"OK\r\n")  || (strstr(uart_string_gsm, "ERROR") ||  (tout > 5) )))
									{				//uart_putchar(UART1_BASE_PTR, '\n');					
									}
	                clear();//uart_putchar(UART1_BASE_PTR,0x1a);
									//clear();
									memset(data,0,strlen(data));
									clear();

								

break;
//log_it();
}
			
			
			
			
			
			}
			else
			{
			
			
		delay(100);
		clear();//memset(uart_string_gsm,0,5000);
	
	memset(at_,0,100);
	sprintf(at_,"\r\nAT+FSWRITE=%s\\LOG.TXT,1,%d,10\n\n",drive,strlen(data)+1);	
	send_SD(at_, ">", "ERROR\r\n" , "ERROR",5);
	
	clear();	
									k2=0;									//string array counter for uart 1
									tout=0;	
		for(k=0;k<strlen(data);k++)
		{
			uart_putchar(UART1_BASE_PTR, data[k]);//clear();
		}	
		uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');	uart_putchar(UART1_BASE_PTR, '\n');	uart_putchar(UART1_BASE_PTR, '\n');	uart_putchar(UART1_BASE_PTR, '\n');	uart_putchar(UART1_BASE_PTR, '\n');	uart_putchar(UART1_BASE_PTR, '\n');	uart_putchar(UART1_BASE_PTR, '\n');	
									//memset(data,0,1000);
														//timer counts to wait for characters in uart 1 									
									while(!(strstr(uart_string_gsm,"OK\r\n")  || (strstr(uart_string_gsm, "ERROR") ||  (tout > 5) )))
									{}
	                clear();
									memset(data,0,strlen(data));
									clear();

								
			break;
			///returning; 
			//log_it();
			}


}

//if(notsentflag==0){cursorvaluene=cursor_val(sd_data);cursorvaluepr+=cursorvaluene;}


}
else{
	remove_all_chars(data, '\n', '\n');
			strcat(data,"CH\n");	
			
	
	  delay(100);
		clear();//memset(uart_string_gsm,0,5000);
	
	memset(at_,0,100);
sprintf(at_,"\r\nAT+FSWRITE=%s\\LOG.TXT,1,%d,10\n\n",drive,strlen(data)+1);	
send_SD(at_, ">", "ERROR\r\n" , "ERROR",5);
clear();	
									k2=0;									//string array counter for uart 1
									tout=0;	
		for(k=0;k<strlen(data);k++)
		{
			uart_putchar(UART1_BASE_PTR, data[k]);//clear();
		}	
uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');	uart_putchar(UART1_BASE_PTR, '\n');	uart_putchar(UART1_BASE_PTR, '\n');	uart_putchar(UART1_BASE_PTR, '\n');	uart_putchar(UART1_BASE_PTR, '\n');	uart_putchar(UART1_BASE_PTR, '\n');	uart_putchar(UART1_BASE_PTR, '\n');	
									//memset(data,0,1000);
														//timer counts to wait for characters in uart 1 									
									while(!(strstr(uart_string_gsm,"OK\r\n")  || (strstr(uart_string_gsm, "ERROR") ||  (tout > 5) )))
									{				//uart_putchar(UART1_BASE_PTR, '\n');					
									}
	                clear();//uart_putchar(UART1_BASE_PTR,0x1a);
									//clear();
									memset(data,0,strlen(data));
									clear();

								
	
	
	
	//log_it();
			memset(data,0,strlen(data));
//*****************************tcp_initialization();************************************//

	
msg_sim800(); 
send_GSM("\r\nAT+CFUN=0\r\r\n\n", "OK", "ERROR\r\n" , "ERROR",5);	
delay(100);
send_GSM("\r\nAT+CFUN=1\r\n", "ERROR", "NOT INSERTED" , "Ready", 4);	
GPS_COLLECT2();
strcat(data,"CH\n");		
GPS_COLLECT2();
strcat(data,"CH\n");	
GPS_COLLECT2();
strcat(data,"CH\n");
cond201=(strstr(uart_string_gsm, "OK"));
cond200=(strstr(uart_string_gsm, "ERROR"));
if(  (!cond201 !=0  &&   !cond200 !=0)					&& sleep_flag != 1)
{
delay(100);
clear();//memset(uart_string_gsm,0,5000);
memset(at_,0,100);
sprintf(at_,"\r\nAT+FSWRITE=%s\\LOG.TXT,1,%d,10\n\n",drive,strlen(data)+1);	
send_SD(at_, ">", "ERROR\r\n" , "ERROR",5);
clear();	
k2=0;									//string array counter for uart 1
tout=0;	
for(k=0;k<strlen(data);k++)
{
uart_putchar(UART1_BASE_PTR, data[k]);//clear();
}	
uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');	uart_putchar(UART1_BASE_PTR, '\n');	uart_putchar(UART1_BASE_PTR, '\n');	uart_putchar(UART1_BASE_PTR, '\n');	uart_putchar(UART1_BASE_PTR, '\n');	uart_putchar(UART1_BASE_PTR, '\n');	uart_putchar(UART1_BASE_PTR, '\n');	
									//memset(data,0,1000);
														//timer counts to wait for characters in uart 1 									
									while(!(strstr(uart_string_gsm,"OK\r\n")  || (strstr(uart_string_gsm, "ERROR") ||  (tout > 5) )))
									{				//uart_putchar(UART1_BASE_PTR, '\n');					
									}
	                clear();//uart_putchar(UART1_BASE_PTR,0x1a);
									//clear();
									memset(data,0,strlen(data));
									clear();
									RESET_OFF;delay(100);
									RESET_ON;delay(100);		
}
	
send_GSM("\r\nAT+CIPSHUT\r\n", "OK", "ERROR\r\n" , "ERROR:",4);	
GPS_COLLECT2();
strcat(data,"CH\n");	
memset(at_,0,100);
sprintf(at_,"\r\nAT+CSTT=\"%s\"\r\n",apn);
send_GSM(at_,	"OK", "ERROR\r\n" , "ERROR:",tmeout);							//delay(20);
msg_sim800(); 
send_GSM("\r\nAT+CIICR\r\r\n", "OK", "ERROR\r\n" , "DEACT",4);		
GPS_COLLECT2();
strcat(data,"CH\n");	
GPS_COLLECT2();
strcat(data,"CH\n");	


msg_sim800(); 
GPS_COLLECT2();
strcat(data,"CH\n");	
					clear();send_modem("\nAT+CIFSR\r\r\n");clear();
					delay(20);


msg_sim800(); 

						sprintf(at_, "\r\nAT+CIPSTART=\"TCP\",\"%s\",\"%s\"\r\n", ip, port);
						send_GSM( at_ , "CONNECT", "ERROR" , "ERROR:",tmeout);	
						clear();
						
						
						send_GSM("\r\nAT+CIPSEND\r\n", ">", "ERROR" , "CONNECT FAIL",tmeout);											
//*****************************tcp_initialization ends**********************************//		

			if(mystrstr(uart_string_gsm,'>')){
									clear();
									memset(uart_string_gsm,0,5000);
									qwe=strlen(data);
									tout=0;
									k2=0;
									for(k=0;k<(qwe);k++)
									{
										uart_putchar(UART1_BASE_PTR, data[k]);
									}uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, 0x1A);uart_putchar(UART1_BASE_PTR, 0x1A);	uart_putchar(UART1_BASE_PTR, 0x1A);uart_putchar(UART1_BASE_PTR, 0x1A);	uart_putchar(UART1_BASE_PTR, 0x1A);uart_putchar(UART1_BASE_PTR, 0x1A);	
															do
																{q1=strstr(uart_string_gsm,"SEND OK");
																	q2=strstr(uart_string_gsm, "ERROR");
																		q3=strstr(uart_string_gsm, "FAIL");	
																			q4=strstr(uart_string_gsm, "DEACT");	
																	
																}while(!(q1 || q2 || q3 || q4 || (tout > 8) ) );
															
																			delay(10);clear();
														uart_putchar(UART1_BASE_PTR,0x1A);
												delay(10);
										uart_putchar(UART1_BASE_PTR, 0x1A);uart_putchar(UART1_BASE_PTR, 0x1A);uart_putchar(UART1_BASE_PTR, 0x1A);
delay(20);
if(!strstr(uart_string_gsm,"SEND OK")){


	delay(100);
		clear();//memset(uart_string_gsm,0,5000);
	
	memset(at_,0,100);
sprintf(at_,"\r\nAT+FSWRITE=%s\\LOG.TXT,1,%d,10\n\n",drive,strlen(data)+1);	
send_SD(at_, ">", "ERROR\r\n" , "ERROR",5);
//uart_putchar(UART1_BASE_PTR,'\n');uart_putchar(UART1_BASE_PTR,'\n');uart_putchar(UART1_BASE_PTR,'\n');	
//	if(strstr(uart_string_gsm,"ERROR")){
//	sprintf(at_,"\nAT+FSCREATE=%s\\LOG.TXT\r\n",drive);
//	send_GSM(at_, "OK", "ERROR\r\n" , "ERROR:",tmeout);
//	}
	
clear();	
									k2=0;									//string array counter for uart 1
									tout=0;	
		for(k=0;k<strlen(data);k++)
		{
			uart_putchar(UART1_BASE_PTR, data[k]);//clear();
		}	
uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');	uart_putchar(UART1_BASE_PTR, '\n');	uart_putchar(UART1_BASE_PTR, '\n');	uart_putchar(UART1_BASE_PTR, '\n');	uart_putchar(UART1_BASE_PTR, '\n');	uart_putchar(UART1_BASE_PTR, '\n');	uart_putchar(UART1_BASE_PTR, '\n');	
									//memset(data,0,1000);
														//timer counts to wait for characters in uart 1 									
									while(!(strstr(uart_string_gsm,"OK\r\n")  || (strstr(uart_string_gsm, "ERROR") ||  (tout > 5) )))
									{				//uart_putchar(UART1_BASE_PTR, '\n');					
									}
	                clear();//uart_putchar(UART1_BASE_PTR,0x1a);
									//clear();
									memset(data,0,strlen(data));
									clear();

								
break;
//log_it();
}
			
			
			
			
			
			}
			else
			{
				
				
				
	delay(100);
		clear();//memset(uart_string_gsm,0,5000);
	
	memset(at_,0,100);
sprintf(at_,"\r\nAT+FSWRITE=%s\\LOG.TXT,1,%d,10\n\n",drive,strlen(data)+1);	
send_SD(at_, ">", "ERROR\r\n" , "ERROR",5);
//uart_putchar(UART1_BASE_PTR,'\n');uart_putchar(UART1_BASE_PTR,'\n');uart_putchar(UART1_BASE_PTR,'\n');	
//	if(strstr(uart_string_gsm,"ERROR")){
//	sprintf(at_,"\nAT+FSCREATE=%s\\LOG.TXT\r\n",drive);
//	send_GSM(at_, "OK", "ERROR\r\n" , "ERROR:",tmeout);
//	}
	
clear();	
									k2=0;									//string array counter for uart 1
									tout=0;	
		for(k=0;k<strlen(data);k++)
		{
			uart_putchar(UART1_BASE_PTR, data[k]);//clear();
		}	
uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');	uart_putchar(UART1_BASE_PTR, '\n');	uart_putchar(UART1_BASE_PTR, '\n');	uart_putchar(UART1_BASE_PTR, '\n');	uart_putchar(UART1_BASE_PTR, '\n');	uart_putchar(UART1_BASE_PTR, '\n');	uart_putchar(UART1_BASE_PTR, '\n');	
									//memset(data,0,1000);
														//timer counts to wait for characters in uart 1 									
									while(!(strstr(uart_string_gsm,"OK\r\n")  || (strstr(uart_string_gsm, "ERROR") ||  (tout > 5) )))
									{				//uart_putchar(UART1_BASE_PTR, '\n');					
									}
	                clear();//uart_putchar(UART1_BASE_PTR,0x1a);
									//clear();
									memset(data,0,strlen(data));
									clear();

								
				
				//log_it();
			
			
			
			
			break;
			}
//			memset(at_,0,100);
//			sprintf(at_,"\nAT+FSFLSIZE=%s\\LOG.TXT\r\n",drive);	
//			send_GSM(at_, "OK", "ERROR\r\n" , "ERROR:",tmeout);
//			parse_g(uart_string_gsm, 1, 2, ' ', '\n', fsize);
//			fsz=stof(fsize);//7523.7412
//			times=(fsz/1256)+1;
		}	
	
//
if(rtcticks2>=1500){break;}		
}

if(((k5>=times) && log0!=1)){
	cursorvaluepr=0;times=-2;k5=0;
	memset(at_,0,100);
	sprintf(at_,"\r\nAT+FSCREATE=%s\\LOG.TXT\r\n",drive);
	send_GSM(at_, "OK", "ERROR\r\n" , "ERROR:",tmeout);

}		

int_erval=temp;
}

	
	
	
	
			
__inline	void send_message(char * data2)
	{memset(uart_string_gsm,0,5000);
									memset(at_,0,100);
									sprintf(at_, "\nAT+CMGS=\"%s\"\r\n" ,num2);
									send_MSG(at_, ">", "ERROR\r\n" , "ERROR:",tmeout);	
									if( strstr(uart_string_gsm, ">"))
									{
										//
										
											for(k=0;k<strlen(data2);k++)
											{
												
												uart_putchar(UART1_BASE_PTR, data2[k]);
												//uart0_putchar(UART0_BASE_PTR, data2[k]);
												clear();
												
											}		
											uart_putchar(UART1_BASE_PTR, 0x1A);
											k2=0;									//string array counter for uart 1
											timeout=99999;						//timer counts to wait for characters in uart 1 									
											while(!(strstr(uart_string_gsm,"+CMGS:")  ||  (timeout < 1)))
																{
																	timeout--;
//																	if(timeout % 4000 == 0)
//																	{
//																		uart0_putchar(UART0_BASE_PTR,'1');
//																		uart_putchar(UART1_BASE_PTR,0x1A);
//																	}
																}
							
									}
		
	memset(uart_string_gsm,0,5000);								
	}





	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	

