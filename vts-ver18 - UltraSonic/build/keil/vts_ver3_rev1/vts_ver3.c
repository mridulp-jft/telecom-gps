/*
 * File:		KEIL_MAG.c
 * Purpose:		Main process
 *
 */

#include "common.h"
#include "modem.c"
#include "accelerometer.c"
#include "gps.c"
#include "gpios.c"
#include "systick.c"
#include "stdlib.h"
#include <stdint.h>
#include "string.h"
//#include "lptmr.c"





#ifdef CMSIS
#include "start.h"
#endif



char prev[8],latest[10];
int iz;
double a,b,c;int hh,mm1,mm2;
double a1,b1,c1;
double hh11, mm11,mm22;
int logged;
char *check;
	int qwe,len;
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
char string_gps[100],gga[100],rmc[100],uart_string_gps[3000],data2[300],drive[5],exception[200];
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

static char imei[20];
void send_message(char * data2);
float pr=0,la=0;
char uart_string_gsm[5000],sd_data[1400];
int ggaptr=0,rmcptr=0;
int i=0,motion_samples=0,notsleep=0;
char ch; 
void delay(int delaytime), get_gpsdata(),  loop(), auto_caliberate_accelerometer(),  tcp_initialization2(), 	 msg_sim800();
void  send_chunk(void),bat_cind();
extern void send_modem(char ch[]);void get_imei(void);
char ringflag=0,lptmr_interrupt=0;
extern void lptmr_init(int count, int clock_source),saveapn();
int GPS_COLLECT(void),tcp_initialization();
int time52=15;
void HardFault_Handler(void);
char * cond277;char* cond20077;char data_balance[200];

char mystrstr(char* str1, char character)
{int sz,cn;
	sz=strlen(str1);
	for(cn=0;cn<=sz;cn++)
	{if(str1[cn] == character)
		{return 1;}
	}
	return 0;
}


void remove_all_chars(char* str, char c, char d) {
    char *pr = str, *pw = str;
    while (*pr) {
        *pw = *pr++;
			pw += (*pw != c && *pw != d && *pw != ' ' && *pw != '/' && *pw != ':');
    }
    *pw = '\0';
}


/*************************** delay*****************************************/
 void delay(int32 delaytime)
{
 while(delaytime--)
    {for(i=2000;i>0;i--)
			{	
			}			// about 1 ms
    }
}
 void delay2(int delaytime)
{
 while(delaytime--)
    {for(i=5000;i>0;i--);  // about 1 ms
    }
}
        


/*********************************************************************/



/********************************************************************/
int main (void)
{int32 test2;



//int_erval=10;
								memset(data,0,strlen(data));
								memset(data2,0,strlen(data2));
	
start();
systick_init();	
#ifdef CMSIS  // If we are conforming to CMSIS, we need to call start here

#endif

int_erval=5;


	LED_init();		//Initialize GPIO for LEDs
	RELAY_init();		//Initialize GPIO for LEDs
	SW1_init();		//Initialize GPIO for SW1 w/ interrupt	
	//accel_init();
	sleep_flag=0;
	DTR_OFF;	
	lptmr_init(1000, 1);	


	int_erval=0;

		uart_putchar(UART1_BASE_PTR,0xA);
		uart_putchar(UART1_BASE_PTR,0x1A);			
	
send_GSM("\n\nAT\r\n","OK\r\n","ERROR\r\n","ERROR:",2);  
 delay(100); 

clear();delay(100);
get_imei();	
GPS_COLLECT();
strcat(data,"CH'1'\n");	


int_erval=5;

//if(!(strstr(uart_string_gsm, "OK")|| strstr(uart_string_gsm, "ERROR")))
//{HardFault_Handler();}
ignread();

//	saveapn();
	
	readapn();





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


get_imei();	

	
//send_modem2("$PMTK225,0*2B");
//while(!strstr(uart_string_gsm,"OK\r\n"));

//bat_cind();
//delay(1000);

send_GSM("\n\nAT&W\r\n","OK\r\n","ERROR\r\n","ERROR:",tmeout);    //   uart_putchar(UART1_BASE_PTR,0x1A);uart_putchar(UART1_BASE_PTR,0xA);uart_putchar(UART1_BASE_PTR,0x1A);uart_putchar(UART1_BASE_PTR,0xA);uart_putchar(UART1_BASE_PTR,0x1A);		
//delay(10);

send_GSM("\n\nATS0=2\r\n","OK\r\n","ERROR\r\n","ERROR:",tmeout); 	

get_imei();

send_GSM("\n\nAT&F\r\n","OK\r\n","ERROR\r\n","ERROR:",tmeout); 	


send_GSM("\n\nAT&D\r\n","OK\r\n","ERROR\r\n","ERROR:",tmeout); 	


send_GSM("\n\nAT+IFC=0,0\r\n","OK\r\n","ERROR\r\n","ERROR:",tmeout);


send_GSM("\n\nAT+CIPQSEND?\r\n","OK\r\n","ERROR\r\n","ERROR:",tmeout);

send_GSM("\n\nAT+CIPQSEND=0\r\n","OK\r\n","ERROR\r\n","ERROR:",tmeout);


//delay(10);


//delay(10);

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


send_GSM("\n\nAT+CPBW=5,\"9873999108\",129,\"OWNER5\"\r\n","OK\r\n","ERROR\r\n","ERROR:",tmeout);


send_GSM("\n\nAT+CPBW=6,\"8287324005\",129,\"OWNER6\"\r\n","OK\r\n","ERROR\r\n","ERROR:",tmeout);

ignread();
readapn();

read_interval();
send_GSM("\n\nAT+CMGF=1\n\n","OK\r\n","ERROR\r\n","ERROR:",tmeout);
//delay(10);	

send_GSM("\n\nAT+CSCA?\r\n","OK\r\n","ERROR\r\n","ERROR:",tmeout);    //   uart_putchar(UART1_BASE_PTR,0x1A);uart_putchar(UART1_BASE_PTR,0xA);uart_putchar(UART1_BASE_PTR,0x1A);uart_putchar(UART1_BASE_PTR,0xA);uart_putchar(UART1_BASE_PTR,0x1A);		
							memset(at_,0,100);
							memset(num_o,0,15);
							parse_g(uart_string_gsm, 1, 2, '\"', '\"', num_o);
							sprintf(at_, "\r\nAT+CSCA=\"%s\"\r\n", num_o);
							send_GSM(at_,"OK\r\n","ERROR\r\n","ERROR:",tmeout);

//delay(10);	

								send_GSM("\nAT+FSCREATE=C:\\IP_PORT.TXT\r\n", "OK", "ERROR\r\n" , "ERROR:",tmeout);
				//				send_GSM("\nAT+FSCREATE=C:\\LOG.TXT\r\n", "OK", "ERROR\r\n" , "ERROR:",tmeout);
								send_GSM("\nAT+FSCREATE=C:\\INTERVAL.TXT\r\n", "OK", "ERROR\r\n" , "ERROR:",tmeout);
								memcpy (ip, "104.236.203.4", 13);
								memcpy (port, "5555", 4);		
								memcpy (interval, "5", 1);										
								save_ip_port();
								save_interval();
			//					printf("\n\n\t,%s,%s,%s,\n",ip,port,interval);		

//			RESET_OFF;
//			delay(20);
//			RESET_ON;


read_ip_port();
		memset(at_,0,100);
		memset(drive,0,5);
		sprintf(at_, "\nAT+FSREAD=C:\\LOGGING_DRIVE.TXT,0,100,1\r\n");		
		send_GSM(at_, "OK", "ERROR\r\n" , "ERROR:",10);	
		parse_g(uart_string_gsm, 1,3, '\n', '\r',drive);
	

tcp_initialization2();

//							GPS_COLLECT();		accel_read();detect_motion();

//do{
//printf("%s\n",send_GPS("\n\nAT+CGPSPWR=1\n\n","OK\r\n","ERROR\r\n","ERROR:",tmeout));
//delay(50);
//printf("%s\n",send_GPS("\n\nAT+CGPSOUT=255\n\n","OK\r\n","ERROR\r\n","ERROR:",tmeout));
//}while(strstr(uart_string_gps,"ERROR"));

//delay(50);

//auto_caliberate_accelerometer();
//tcp_initialization();

//phonebook_read("5");parse(1,2);
	

while(1)
{
LED_state();
LED_state2();
	

RESET_ON; //not reset
send_GSM("\r\nAT+CIPCLOSE\r\n", "CLOSE OK", "ERROR" , "ERROR:",tmeout);		
msg_sim800(); 	
							
	DTR_OFF;		// not sleep	
	delay(100);
	send_GSM("\n\nAT+CBC\r\n","OK","ERROR","ERROR:",tmeout);
	// not sleep	
	memset(num2,0,30);
	parse_g(uart_string_gsm, 2, 3, ',', '\r' ,num2);
	voltagecbc=myAtoi(num2);

	msg_sim800();
	sleep_flag=0;

	test2=GPIOB_PDIR;	
	if(voltagecbc<4000  ||  test2==1){
	DTR_OFF;sleep_flag = 0;
	}
	else{
//	GPS_COLLECT();	
	DTR_ON;sleep_flag=1;
	}
sprintf(num2,"\n<%d><%ld>\n",aliveping,rtcticks2);
send_modem(num2);
	
if	((sleep_flag != 1  || (aliveping > 60) ) )			
{ DTR_OFF;

	sleep_flag=0;
	
							
	
							memset(at_,0,100);
	
							memset(data,0,strlen(data));

							GPS_COLLECT();	
							sprintf(at_, "\r\nAT+CIPSTART=\"TCP\",\"%s\",\"%s\"\r\n", ip, port);



							send_GSM( at_ , "CONNECT", "ERROR" , "ERROR\r\n",tmeout);	
							send_GSM("\r\nAT+CIPSEND\r\n", ">", "ERROR" , "CONNECT FAIL",tmeout);	
		
if((aliveping>60))	
{
		aliveping=0;
		memset(data,0,strlen(data));	
		strcat(data,imei);strcat(data,",ALIVE,");strcat(data,num2);strcat(data,"\n");
	  
}	




























memset(stcond1,0,strlen(stcond1));	
memset(con1d,0,strlen(con1d));	
								//sprintf(data_2,"Latitude->%s,Longitude->%s,Velocity->%skmph\nhttps://www.google.com/search?q=%s%c2C%s&ie=utf-8&oe=utf-8\n",lati,longi,velocity,lati,'%',longi);			

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
																	
																}while(!(stcond2 || stcond3 || stcond4 || stcond1 || (tout > 4) ) ); //|| (timeout < 1)   
																//delay(10);clear();
														uart_putchar(UART1_BASE_PTR,0x1A);
												//delay(10);
										uart_putchar(UART1_BASE_PTR, 0x1A);uart_putchar(UART1_BASE_PTR, 0x1A);uart_putchar(UART1_BASE_PTR, 0x1A);
						
									
									
									
									if(flagch==1){		int_erval=temp;flagch=0;	}
									
									
									

//									for(k=0;k<len;k++)
//									{
//										uart_putchar(UART1_BASE_PTR, data[k]);//clear();// uart0_putchar(UART0_BASE_PTR, data[k]);
//									}
//  								uart_putchar(UART1_BASE_PTR, 0x1A);uart_putchar(UART1_BASE_PTR,0x1A);uart_putchar(UART1_BASE_PTR,0x1A);uart_putchar(UART1_BASE_PTR,0x1A);uart_putchar(UART1_BASE_PTR,0x1A);

//									
//													k2=0;									//string array counter for uart 1
//													 timeout=99001;						//timer counts to wait for characters in uart 1 									
//													while(!(  strstr(uart_string_gsm,"OK")  || strstr(uart_string_gsm,"FAIL")  || strstr(uart_string_gsm,"ERROR") || strstr(uart_string_gsm,"DEACT") ||  (timeout <= 1)))       
//																{
//																	timeout--;
//																//	if(timeout%10000 == 0){uart_putchar(UART1_BASE_PTR,0x1A);delay(10);}
//
									delay(20);															
stcond1=strstr(uart_string_gsm,"SEND OK"); 

								}

  //checks for send ok
if(!stcond1) // if not send ok  ;;;;;;;;;;;;  if no gsm connection is there ,,,... this segment reinitializes GSM, collects GPS data in RAM and attempts to send it
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

								
			
	
	//	log_it();		                         //logging
		memset(data,0,strlen(data));	

					   	if(flagch!=1){
							temp=int_erval;				
							int_erval=4;
							flagch=1;}
							get_imei();
							clear();	
									GPS_COLLECT();
									strcat(data,"CH\n");	

									tcp_initialization();           //reinitialization                   
									
						clear();		
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
									{
										uart_putchar(UART1_BASE_PTR, data[k]);
									}uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, 0x1A);uart_putchar(UART1_BASE_PTR, 0x1A);uart_putchar(UART1_BASE_PTR, 0x1A);
									do
																{stcond1=strstr(uart_string_gsm,"SEND OK");
																	stcond2=strstr(uart_string_gsm, "ERROR");
																		stcond3=strstr(uart_string_gsm, "FAIL");	
																			stcond4=strstr(uart_string_gsm, "DEACT");	
																	
																}while(!(stcond2 || stcond3 || stcond4 || stcond1 || (tout > 4) ) ); //|| (timeout < 1)   
															//	delay(10);clear();
														uart_putchar(UART1_BASE_PTR,0x1A);
											//	delay(10);
										uart_putchar(UART1_BASE_PTR, 0x1A);uart_putchar(UART1_BASE_PTR, 0x1A);uart_putchar(UART1_BASE_PTR, 0x1A);
						


									
															
															
//															uart_putchar(UART1_BASE_PTR,0x1A);clear();delay(10);
//															uart_putchar(UART1_BASE_PTR,0x1A);clear();delay(10);
															
														//qwe=strlen(uart_string_gsm);
													//	uart_putchar(UART1_BASE_PTR,0x1A);clear();delay(10);
															delay(20);
															con1d=	(strstr(uart_string_gsm,"SEND OK"));
																if(!con1d)
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

								
									
									
									
									
									//log_it();			//otherwize log it					
								}

																
//delay(50);

//else{
//log_it();}
								
								
	} // if there is a gsm connect available this segment checks for the log available and send it in chunks,..
	else
	{
		send_chunk();
	}		
								
								
								
	memset(data,0,strlen(data));	
	uart_putchar(UART1_BASE_PTR, 0x1A);
	









//send_tcp();
	
	
	}





		
/******************while end**********************/		
	} 
/******************main end***********************/
}
/********************************************************************/












void HardFault_Handler()
{long ppp=0;	

	RESET_OFF;
	RESET_OFF;
for(ppp=0;ppp<9999999; ppp++){
	
}
	
	
	RESET_ON;
	RESET_ON;
for(ppp=0;ppp<9999999; ppp++){
	
}
}


void LPTimer_IRQHandler(void)
{
lpticks+=1;
//rtcticks++;
	tout++;tout2++;
	rtcticks2++;
	

	if(sleep_flag == 1){aliveping++;}

	
	
	
	if(rtcticks2>=86400){
		
	uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');
	uart_putchar(UART1_BASE_PTR, 0x1A);
	uart_putchar(UART1_BASE_PTR, 0x1A);
	uart_putchar(UART1_BASE_PTR, 0x1A);
	uart_putchar(UART1_BASE_PTR, 0x1A);
	uart_putchar(UART1_BASE_PTR, 0x1A);

delay(500);		
		strcat(data, "\r\n\r\nHey, This is your device restrting after 86400 seconds \r\n\r\n");
		send_modem(data);
		
		


	log_it();	
		delay(100);
		
	RESET_OFF;
	delay(100);
	RESET_ON;
	delay(100);
	
	}//3600
	
	
//switch(rtcticks)
//	{
//		case 60:
//			IGNITION_OFF;
//			break;
//		case 120:
//			IGNITION_ON;rtcticks=0;
//			break;	
//	}
//	
//		
//	
	
	
	
	
	

  LPTMR0_CSR |=  LPTMR_CSR_TCF_MASK;   // write 1 to TCF to clear the LPT timer compare flag
  LPTMR0_CSR = ( LPTMR_CSR_TEN_MASK | LPTMR_CSR_TIE_MASK | LPTMR_CSR_TCF_MASK  );
  
}



void dtr_sleep()
{int32 test2;

test2=GPIOB_PDIR;
memset(at_,0,strlen(at_));
sprintf(at_,"\n\n\n GPIOB = %d \n\n\n ",test2);	
send_modem(at_);
if( test2 == 0 )	
{
	//send_GSM("\r\nAT+CFUN=0\r\n", "OK\r\n", "ERROR\r\n" , "ERROR:",7);	
//	send_GSM("\r\nAT+CFUN=1\r\n", "Ready", "NOT INSERTED" , "ERROR",10);	

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


















int myAtoi(char *str)
{
    int res = 0,iz; // Initialize result

    // Iterate through all characters of input string and update result
    for (iz = 0; str[iz] != '\0'; ++iz)
        res = res*10 + str[iz] - '0';

    // return result.
    return res;
}

float stof(const char* s)
{
  float rez = 0, fact = 1;
	int d,point_seen;
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



int GPS_COLLECT()
{



//		strcat(data,imei);
//		strcat(data,", ");	
//		strcat(data,"$GxGGA");	
//		strcat(data,gga);
//		strcat(data,", $GxRMC");	
//		strcat(data,rmc);	
//		strcat(data,"\n");		

//	return 0;
	
	
	
clear();		
clear();
clear();
	
if((strlen(imei) < 15 )){


	
send_GSM("\r\n\n\nAT+GSN\r\n","OK","ERROR\r\n","ERROR",10);	

memset(imei,0,20);
for(i=0;i<strlen(uart_string_gsm);i++){
		if((uart_string_gsm[i]>47)   &&   (uart_string_gsm[i]<58)){   //means numeric
			imei[imeiinc] = uart_string_gsm[i];
			imeiinc++;
		}

}
	
	
	}		
	
//parse_g(uart_string_gsm,1,3,'\n','\r',imei);	
clear();	

	
//get_imei();	


//send_GSM("\r\n\nAT+CSQ\r\n","OK","ERROR","ERROR:",tmeout);
//memset(num2,0,30);
//parse_g(uart_string_gsm, 1, 4, ' ', '\r' ,num2);

time52=15;	
//stateCount++; 
//if(stateCount>5){stateCount =0;}
//LED_state();



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

		//strcat(data,"\n");
		strcat(data,imei);
		strcat(data,", ");	
		strcat(data,"$GxGGA");	
		strcat(data,gga);
		strcat(data,", $GxRMC");	
		strcat(data,rmc);	
		strcat(data,",");	
		strcat(data,num2);	

		if	(breach == 1){strcat(data,",BR*");}



return 0;
}






int GPS_COLLECT2()
{

	
clear();		
clear();
clear();
	
if((strlen(imei) < 15 )){


	
send_GSM("\r\n\n\nAT+GSN\r\n","OK","ERROR\r\n","ERROR",10);	

memset(imei,0,20);
for(i=0;i<strlen(uart_string_gsm);i++){
		if((uart_string_gsm[i]>47)   &&   (uart_string_gsm[i]<58)){   //means numeric
			imei[imeiinc] = uart_string_gsm[i];
			imeiinc++;
		}

}
	
	
	}		
	
//parse_g(uart_string_gsm,1,3,'\n','\r',imei);	
clear();	

//get_imei();	
	
time52=15;	
stateCount++; 
//if(stateCount>5){stateCount =0;}
//LED_state();



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

		//strcat(data,"\n");
		strcat(data,imei);
		strcat(data,", ");	
		strcat(data,"$GxGGA");	
		strcat(data,gga);
		strcat(data,", $GxRMC");	
		strcat(data,rmc);	


return 0;
}














int tcp_initialization()
{ char * cond2;char * cond200;
get_imei();	
msg_sim800(); 
//clear();

	
	send_GSM("\r\nAT+CFUN=0\r\r\n\n", "OK", "ERROR\r\n" , "ERROR",5);	



delay(100);
	
//get_imei();	

send_GSM("\r\nAT+CFUN=1\r\n", "OK", "NOT INSERTED\r\nOK" , "ERROR", 4);	
//GPS_COLLECT();
//strcat(data,"CH\n");	
	
GPS_COLLECT2();
strcat(data,"CH\n");		

	
GPS_COLLECT2();
strcat(data,"CH\n");	



GPS_COLLECT2();
strcat(data,"CH\n");
	cond2=(strstr(uart_string_gsm, "OK"));
	cond200=(strstr(uart_string_gsm, "ERROR"));
if((!(cond2|| cond200 ))  && sleep_flag != 1){
	
	
	
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

								
	
	
	
	//	log_it();
									
									RESET_OFF;delay(100);
		RESET_ON;delay(100);		
}

	//send_GSM("\r\nAT+CIPSHUT\r\n", "SHUT OK\r\n", "ERROR\r\n" , "ERROR:",tmeout);	

//msg_sim800(); 


	
send_GSM("\r\nAT+CIPSHUT\r\n", "OK", "ERROR\r\n" , "ERROR:",4);	
GPS_COLLECT2();
strcat(data,"CH\n");	

	memset(at_,0,100);
sprintf(at_,"\r\nAT+CSTT=\"%s\"\r\n",apn);
send_GSM(at_,	"OK", "ERROR\r\n" , "ERROR:",tmeout);							//delay(20);

msg_sim800(); 

						
						send_GSM("\r\nAT+CIICR\r\r\n", "OK", "ERROR\r\n" , "DEACT",4);		

GPS_COLLECT();
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
//GPS_COLLECT();
//strcat(data,"CH\n");	

		
return 0;
}


void tcp_initialization2()
{
get_imei();
msg_sim800(); 

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

								GPS_COLLECT();
								strcat(data,"CH\n");	

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
																	
																}while(!(stcond2 || stcond3 || stcond4 || stcond1 || (tout > 4) ) ); //|| (timeout < 1)   
																//delay(10);clear();
														uart_putchar(UART1_BASE_PTR,0x1A);
												//delay(10);
										uart_putchar(UART1_BASE_PTR, 0x1A);uart_putchar(UART1_BASE_PTR, 0x1A);uart_putchar(UART1_BASE_PTR, 0x1A);
						
									
									
									
									
									
									
									

//									for(k=0;k<len;k++)
//									{
//										uart_putchar(UART1_BASE_PTR, data[k]);//clear();// uart0_putchar(UART0_BASE_PTR, data[k]);
//									}
//  								uart_putchar(UART1_BASE_PTR, 0x1A);uart_putchar(UART1_BASE_PTR,0x1A);uart_putchar(UART1_BASE_PTR,0x1A);uart_putchar(UART1_BASE_PTR,0x1A);uart_putchar(UART1_BASE_PTR,0x1A);

//									
//													k2=0;									//string array counter for uart 1
//													 timeout=99001;						//timer counts to wait for characters in uart 1 									
//													while(!(  strstr(uart_string_gsm,"OK")  || strstr(uart_string_gsm,"FAIL")  || strstr(uart_string_gsm,"ERROR") || strstr(uart_string_gsm,"DEACT") ||  (timeout <= 1)))       
//																{
//																	timeout--;
//																//	if(timeout%10000 == 0){uart_putchar(UART1_BASE_PTR,0x1A);delay(10);}
//																}
																if(flagch==1){		int_erval=temp;flagch=0;	}
delay(50);
stcond1=strstr(uart_string_gsm,"SEND OK");								
								}
//else{
//log_it();
//}


if(!stcond1) // if no gsm connection is there ,,,... this segment reinitializes GSM, collects GPS data in RAM and attempts to send it
{									uart_putchar(UART1_BASE_PTR, 0x1A);clear();delay(10);
									uart_putchar(UART1_BASE_PTR, 0x1A);clear();delay(10);
									uart_putchar(UART1_BASE_PTR, 0x1A);clear();delay(10);
						//	remove_all_chars(data, '\n', '\n');
	
	//	strcat(data,"CH\n");	
	
	
	
	
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
		memset(data,0,strlen(data));	
									GPS_COLLECT();
									strcat(data,"CH\n");	
				
					   	if(flagch!=1){
							temp=int_erval;				
							int_erval=4;
							flagch=1;}
							get_imei();
							clear();	


									tcp_initialization();
									
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
																	
																}while(!(stcond2 || stcond3 || stcond4 || stcond1 || (tout > 4) ) ); //|| (timeout < 1)   
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
								if(!con1d)
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
								}else{send_chunk();}	

																
								}else{
								
								
								
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
									logged=1;}			//

							

	} // if there is a gsm connect available this segment checks for the log available and send it in chunks,..
	else
	{
		send_chunk();
	}		
								
								
								
	memset(data,0,strlen(data));	
	uart_putchar(UART1_BASE_PTR, 0x1A);


//send_tcp2();
}







void get_gpsdata()
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
//printf("\n\t%s\n\t%s\n\t\n",gga,rmc);		
}


void auto_caliberate_accelerometer()
{
accel_read();
offxy= -xy_angle;
offxz= -xz_angle;
offyz= -yz_angle;
offx=  -resultx;
offy=  -resulty; 
offz=  -resultz; 	
	
}
	


void get_imei()
{int i,imeiinc=0;
clear();		
clear();
clear();
	
if((strlen(imei) < 15 )){


	
send_GSM("\r\n\n\nAT+GSN\r\n","OK","ERROR\r\n","ERROR",10);	

memset(imei,0,20);
for(i=0;i<strlen(uart_string_gsm);i++){
		if((uart_string_gsm[i]>47)   &&   (uart_string_gsm[i]<58)){   //means numeric
			imei[imeiinc] = uart_string_gsm[i];
			imeiinc++;
		}

}
	
	
	}		
	
//parse_g(uart_string_gsm,1,3,'\n','\r',imei);	
clear();	
}
	
	

void msg_sim800() 
{ static char* cond1=0;
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
	
//ringflag=1;	
	if(ringflag==1 )
	{
		sleep_flag=0;
    DTR_OFF;		// not sleep	
//	  HardFault_Handler();
delay(1000);
send_GSM("\n\nAT\r\n","OK\r\n","ERROR\r\n","ERROR:",tmeout);    
		
send_GSM("\n\nAT+GSV\r\n","OK\r\n","ERROR\r\n","ERROR:",tmeout);  		
delay(1000);		
		
		
//	bat_cind();
	send_GSM("\n\nAT+CMGF=1\n\n","OK\r\n","ERROR\r\n","ERROR:",tmeout);	
	send_GSM("\n\nAT+CSCA?\r\n","OK\r\n","ERROR\r\n","ERROR:",tmeout);    //   uart_putchar(UART1_BASE_PTR,0x1A);uart_putchar(UART1_BASE_PTR,0xA);uart_putchar(UART1_BASE_PTR,0x1A);uart_putchar(UART1_BASE_PTR,0xA);uart_putchar(UART1_BASE_PTR,0x1A);		
//							memset(at_,0,100);
//							memset(num_o,0,15);
//							parse_g(uart_string_gsm, 1, 2, '\"', '\"', num_o);
//							sprintf(at_, "\r\nAT+CSCA=\"%s\"\r\n", num_o);
//							printf("%s\n",send_GSM(at_,"OK\r\n","ERROR\r\n","ERROR:",tmeout));	

		
			//		printf("\n\n\thttps://www.google.com/search?q=%s%c2C%s&ie=utf-8&oe=utf-8\n",lati,'%',longi,velocity,lati,longi);
					send_GSM("\r\nAT+CMGR=1\r\n", "OK\r\n", "ERROR" , "OK\r\n",tmeout);	
					clear();
					parse_gsm(uart_string_gsm, 3, 4, num2);
			
			
			
			
			
			
			
//		
//if(cond1)
//{

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
						cond11=strstr(uart_string_gsm, "FUEL ON");	
						cond12=strstr(uart_string_gsm, "FUEL OFF");	
						cond13=strstr(uart_string_gsm, "IGNITION ON");	
						cond14=strstr(uart_string_gsm, "IGNITION OFF");	
					//	memset(uart_string_gsm,0,5000);
							if(cond1 && cond2)
							{
								memset(data2,0,strlen(data2));
								sprintf(data2,"\nCoordinates : %s N, %s E\nSpeed : %s kmph\n\nhttps://www.google.com/search?q=%s%c2C%s&ie=utf-8&oe=utf-8\n",lati,longi,velocity,lati,'%',longi);	
								//if(strstr(data2, "0.000000 N, 0.000000 E"))
								//{send_message("Sorry, No GPS Fix available at the moment\n");}
							//	else
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

			
							else if(cond1 && cond4)
							{
								memset( apn,0,25);
								parse_g(uart_string_gsm, 3, 5, ' ', '\r', apn);			
saveapn();								
								send_GSM("\nAT+FSCREATE=C:\\IP_PORT.TXT\r\n", "OK", "ERROR\r\n" , "ERROR:",tmeout);
								send_GSM("\nAT+FSCREATE=D:\\LOG.TXT\r\n", "OK", "ERROR\r\n" , "ERROR:",tmeout);
								send_GSM("\nAT+FSCREATE=C:\\LOG.TXT\r\n", "OK", "ERROR\r\n" , "ERROR:",tmeout);
								send_GSM("\nAT+FSCREATE=C:\\INTERVAL.TXT\r\n", "OK", "ERROR\r\n" , "ERROR:",tmeout);
								memcpy (ip, "104.236.203.4", 13);
								memcpy (port, "5555", 4);		
								memcpy (interval, "5", 1);										
								save_ip_port();
								save_interval();	
								int_erval=myAtoi(interval);		

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
		RESET_OFF;delay(10);
		RESET_ON;delay(10);
								send_GSM("\n\n AT+CFUN=1,1\r\n","OK\r\n","ERROR\r\n","ERROR:",tmeout);			
							}
							
							else if(cond1 && cond10)
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
							
							else if(cond5)
							{
								memset(at_,0,100);
								memset(num_o,0,15);
								parse_g(uart_string_gsm, 3, 5, ' ', '\r', num_o);
								sprintf(at_, "\r\nAT+CPBW=1,\"%s\",129,\"OWNER1\"\r\n" , num_o);
								send_GSM(at_,"OK\r\n","ERROR\r\n","ERROR:",tmeout);
								send_GSM("\r\nAT+CMGD=1,4\r\n","OK\r\n","ERROR\r\n","ERROR:",tmeout);	
															
						
								
							}		
							else if(cond6)
							{
								memset(at_,0,100);
								memset(num_o,0,15);
								parse_g(uart_string_gsm, 3, 5, ' ', '\r', num_o);
								sprintf(at_, "\r\nAT+CPBW=2,\"%s\",129,\"OWNER2\"\r\n" , num_o);
								send_GSM(at_,"OK\r\n","ERROR\r\n","ERROR:",tmeout);
								send_GSM("\r\nAT+CMGD=1,4\r\n","OK\r\n","ERROR\r\n","ERROR:",tmeout);	
								
															
								
							}									
							else if(cond7)
							{
								memset(at_,0,100);
								memset(num_o,0,15);
								parse_g(uart_string_gsm, 3, 5, ' ', '\r', num_o);
								sprintf(at_, "\r\nAT+CPBW=3,\"%s\",129,\"OWNER3\"\r\n" , num_o);
								send_GSM(at_,"OK\r\n","ERROR\r\n","ERROR:",tmeout);
								send_GSM("\r\nAT+CMGD=1,4\r\n","OK\r\n","ERROR\r\n","ERROR:",tmeout);	
															
															
									
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
{
int ass;int count=0;
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
int curinc,curcounter=0,cur2;
for(curinc=0;curinc<strlen(stringsd);curinc++){
		
		if(stringsd[curinc] == '\n'     &&    curcounter < cur   ){ //&& curcounter<=cur	){
			++curcounter;     cur2=curinc;
		}

		

}
	
	
	return cur2;

}


void send_chunk(){
float fsz;
long times,qwe,k5,enters,cursorvaluepr=0,cursorvaluene=0;
char cond;char*q1;char* q2;char* q3;char *q4;
int cntendl=0;
times=-2;	
	
memset(at_,0,100);
sprintf(at_,"\nAT+FSFLSIZE=%s\\LOG.TXT\r\n",drive);	
send_GSM(at_, "OK", "ERROR\r\n" , "ERROR:",tmeout);
parse_g(uart_string_gsm, 1,3, ' ', '\r', fsize);
fsz=stof(fsize);//7523.7412	              //1400 is the maximum imit  //200 is the maximum size of 1 data	
//reading buffer of SD data = 1400 // need to concatinate maximum amount of data in it and a 200 character data
if(fsz==0)k5=9999999;
else k5=0;	
times =	(fsz/900) + 2;
cursorvaluepr=0;
	
for(k5;k5<=(times);){
	
	RESET_ON;
	DTR_OFF;
	
	msg_sim800(); 

	get_imei();
memset(data,0,strlen(data));	
GPS_COLLECT();
strcat(data,"\n");	
	
	
	memset(at_,0,100);
	sprintf(at_,"\nAT+FSFLSIZE=%s\\LOG.TXT\r\n",drive);	
	send_GSM(at_, "OK", "ERROR\r\n" , "ERROR:",tmeout);

	
	
	
	parse_g(uart_string_gsm, 1,3, ' ', '\r', fsize);
	fsz=stof(fsize);//7523.7412	              //1400 is the maximum imit  //200 is the maximum size of 1 data	
	//reading buffer of SD data = 1400 // need to concatinate maximum amount of data in it and a 200 character data
	times =	(fsz/900) + 2;	
	
		sprintf(at_, "\nAT+FSREAD=%s\\LOG.TXT,1,1100,%d\r\n",drive,cursorvaluepr );		//1256
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

	
//		memset(at_,0,100);	

		

//		memset(at_,0,100);
//		sprintf(at_,"\nAT+FSFLSIZE=%s\\LOG.TXT\r\n",drive);	
//		send_GSM(at_, "OK", "ERROR" , "ERROR:",tmeout);
//		parse_g(uart_string_gsm, 1,6, ' ', '\r', fsize);
//		fsz=stof(fsize);//7523.7412
//		times=(fsz/1256)+1;  //1256 //1400
//		if(fsz == 0)times=0;				
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
																	
																}while(!(q1 || q2 || q3 || q4 || (tout > 4) ) ); //|| (timeout < 1)   
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

								



//	log_it();

			memset(data,0,strlen(data));
			tcp_initialization();
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
																	
																}while(!(q1 || q2 || q3 || q4 || (tout > 4) ) );
															
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
			memset(data,0,strlen(data));
			tcp_initialization();
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
																	
																}while(!(q1 || q2 || q3 || q4 || (tout > 4) ) );
															
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
			
			
			
			
			
			}
//			memset(at_,0,100);
//			sprintf(at_,"\nAT+FSFLSIZE=%s\\LOG.TXT\r\n",drive);	
//			send_GSM(at_, "OK", "ERROR\r\n" , "ERROR:",tmeout);
//			parse_g(uart_string_gsm, 1, 2, ' ', '\n', fsize);
//			fsz=stof(fsize);//7523.7412
//			times=(fsz/1256)+1;
		}	
	
//		
}
if((times != 0      && k5!=9999999)){
	memset(at_,0,100);
	sprintf(at_,"\nAT+FSCREATE=%s\\LOG.TXT\r\n",drive);
	send_GSM(at_, "OK", "ERROR\r\n" , "ERROR:",tmeout);

}		


}


















			
	
	void bat_cind()
	{int netwrk;char netwrk_c[1];
		
				send_GSM("\r\nAT+CIND?\r\n", "OK", "ERROR\r\n" , "ERROR:",tmeout);
				parse_g(uart_string_gsm, 1, 2, ',', ',', netwrk_c);
				netwrk = netwrk_c[0]- '0';
				

		switch(netwrk)
		{
			case 1:
				
    RED_OFF;		//Turn off RED LED
    GREEN_OFF;	//Turn off GREEN LED
    BLUE_OFF;		//Turn off BLUE LED			
			
				 RED_ON;		//Turn off RED LED
					
			break;
			
			case 2:
		
    RED_OFF;		//Turn off RED LED
    GREEN_OFF;	//Turn off GREEN LED
    BLUE_OFF;		//Turn off BLUE LED
			
				 RED_ON;		//Turn off RED LED
				 GREEN_ON;
			
			break;
			
			case 3:
				
    RED_OFF;		//Turn off RED LED
    GREEN_OFF;	//Turn off GREEN LED
    BLUE_OFF;		//Turn off BLUE LED
			
				 GREEN_ON;		//Turn off RED LED

			
			break;

			case 4:
				
    RED_OFF;		//Turn off RED LED
    GREEN_OFF;	//Turn off GREEN LED
    BLUE_OFF;		//Turn off BLUE LED
			
				 BLUE_ON;		//Turn off RED LED
				 GREEN_ON;
			
			break;
			
			case 5:
				
    RED_OFF;		//Turn off RED LED
    GREEN_OFF;	//Turn off GREEN LED
    BLUE_OFF;		//Turn off BLUE LED
						
				 BLUE_ON;		//Turn off RED LED
				
			break;
			
			default:
			
    RED_OFF;		//Turn off RED LED
    GREEN_OFF;	//Turn off GREEN LED
    BLUE_OFF;		//Turn off BLUE LED
			
			break;
			
			

		}			
		




		
		
		
	}
	
	
	
	
			
	void send_message(char * data2)
	{
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
		
									
	}





	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	

