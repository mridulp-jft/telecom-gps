#include "uart.h"
#include "string.h"
#include "gpios.h"
//#include "stdlib.c"
void clear2(void), clear(void), read(char * A,char * B,char * C), read2(char * respA,char * respB,char * respC, int timeout), send_modem(char ch[]),  send_modem2(char ch[]), log_it(), parse_g(char* str, int first, int sec,	char f,		char s , char *string); 
//extern-static MISRA-C rule 8.8
extern int myAtoi(char *str);
extern   char * cond201;char * cond200;
extern void msg_sim800(void);
extern void GPS_COLLECT2(void);
extern void delay(int delaytime),  LED_state(void) , accel_read(void), detect_motion(),send_chunk();
//--------------------
void send_GSM(char *string, char *responseA, char *responseB, char *responseC, int32 timeout);

//extern-static MISRA-C rule 8.8
extern char string_gps[100],gga[100],rmc[100],uart_string_gps[3000], at_[100], fsize[15], interval[5],drive[5],lptmr_interrupt;
//---------------------------------
char uart_string_gsm[5000],data[1500],num2[30];
extern  char imei[20],apn[25];
extern volatile uint8_t stateCount;	
extern __inline void	GPS_COLLECT(void);
extern float stof(const char* s);
extern int motion,motion_samples,int_erval;	
extern char* test;extern int32 tmeout;
extern int sleep_flag;
extern long times,qwe,k5,enters,cursorvaluepr,cursorvaluene;

int k,l,k2,l2;
extern void HardFault_Handler(void);
extern void remove_all_chars(char* str, char c, char d);
int tout=0,tout2=0;
long time=999999;
extern char mystrstr(char* str1, char character);

int temp;int flagch=0;
	char cond121;
	char* cond122;
	char* cond123;
	char* cond124;
	int len;
char cond;
char* con1d;
static	char* stcond1;
char * stcond2;char * stcond3;char * stcond4;
extern long qwe;
long time111,timeout222;
int qweq;

int i11=0,j11=0,temp11=0;
int sz1,sz2;
extern char ip[100];
extern char port[10];


void send_SD(char *string, char *responseA, char *responseB, char *responseC, int32 timeout)
{
	clear();
	tout=0;
		memset(uart_string_gsm,0,5000);
		k2=0;									//string array counter for uart 1
		clear();
		send_modem(string);
		
		delay(10);
		uart_putchar(UART1_BASE_PTR,'\r');//uart_putchar(UART1_BASE_PTR,'\r');
	//uart_putchar(UART1_BASE_PTR,'\r');uart_putchar(UART1_BASE_PTR,'\n');//uart_putchar(UART1_BASE_PTR,0x1A);
		do
		{
			
//					time111--;
//				  timeout222--;

			
	cond122=strstr(uart_string_gsm, responseA);
	cond123=strstr(uart_string_gsm, responseB);
  cond124=strstr(uart_string_gsm, responseC);
	cond121 = (cond122	|| cond123	|| cond124  || (tout > timeout))	;
			
		}while (!cond121);
		clear();
		if(tout>timeout){
			uart_putchar(UART1_BASE_PTR,'\r');
		uart_putchar(UART1_BASE_PTR,'\n');uart_putchar(UART1_BASE_PTR,0x1A);
		uart_putchar(UART1_BASE_PTR,0x1A);uart_putchar(UART1_BASE_PTR,'\r');
		uart_putchar(UART1_BASE_PTR,'\n');}
		//return;
//		return uart_string_gsm;

}




void send_tcp()
{	
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
																	
																}while(!(stcond2 || stcond3 || stcond4 || stcond1 || (tout > 5) ) ); //|| (timeout < 1)   
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

								
	
	//log_it();		                         //logging
		memset(data,0,strlen(data));	

					   	if(flagch!=1){
							temp=int_erval;				
							int_erval=4;
							flagch=1;}
							clear();	
									GPS_COLLECT();
									strcat(data,"CH\n");	

//*********************************tcp_initialization();//reinitialization*************************************//

	
msg_sim800(); 
send_GSM("\r\nAT+CFUN=0\r\r\n\n", "OK", "ERROR\r\n" , "ERROR",5);	
delay(100);
send_GSM("\r\nAT+CFUN=1\r\n", "OK", "NOT INSERTED\r\nOK" , "ERROR", 4);	
GPS_COLLECT2();
strcat(data,"CH\n");		
GPS_COLLECT2();
strcat(data,"CH\n");	
GPS_COLLECT2();
strcat(data,"CH\n");
cond201=(strstr(uart_string_gsm, "OK"));
cond200=(strstr(uart_string_gsm, "ERROR"));
if((!(cond201|| cond200 ))  && sleep_flag != 1)
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
send_GSM("\r\nAT+CIFSR\r\r\n", "OK", "ERROR" , "DEACT",1);		

//delay(20);


msg_sim800(); 

						sprintf(at_, "\r\nAT+CIPSTART=\"TCP\",\"%s\",\"%s\"\r\n", ip, port);
						send_GSM( at_ , "CONNECT", "ERROR" , "ERROR:",tmeout);	
						clear();
						
						
						send_GSM("\r\nAT+CIPSEND\r\n", ">", "ERROR" , "CONNECT FAIL",tmeout);									
//*********************************tcp_initialization_ends*****************************************************//							
									
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
																	
																}while(!(stcond2 || stcond3 || stcond4 || stcond1 || (tout > 5) ) ); //|| (timeout < 1)   
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

								
								//								log_it();								
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
	
}
	












void send_tcp_bal()
{	
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
									}uart_putchar(UART1_BASE_PTR, 0x1A);uart_putchar(UART1_BASE_PTR, 0x1A);
									do
																{stcond1=strstr(uart_string_gsm,"SEND OK");
																	stcond2=strstr(uart_string_gsm, "ERROR");
																		stcond3=strstr(uart_string_gsm, "FAIL");	
																			stcond4=strstr(uart_string_gsm, "DEACT");	
																	
																}while(!(stcond2 || stcond3 || stcond4 || stcond1 || (tout > 5) ) ); //|| (timeout < 1)   
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
							//remove_all_chars(data, '\n', '\n');
	
		//strcat(data,"CH\n");	
		
	
	
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

								
	
	
	//log_it();		                         //logging
		memset(data,0,strlen(data));	

					   	if(flagch!=1){
							temp=int_erval;				
							int_erval=4;
							flagch=1;}
							clear();	
									GPS_COLLECT();
									strcat(data,"CH\n");	

//*************************************tcp_initialization();//reinitialization************************//

	
msg_sim800(); 
send_GSM("\r\nAT+CFUN=0\r\r\n\n", "OK", "ERROR\r\n" , "ERROR",5);	
delay(100);
send_GSM("\r\nAT+CFUN=1\r\n", "OK", "NOT INSERTED\r\nOK" , "ERROR", 4);	
GPS_COLLECT2();
strcat(data,"CH\n");		
GPS_COLLECT2();
strcat(data,"CH\n");	
GPS_COLLECT2();
strcat(data,"CH\n");
cond201=(strstr(uart_string_gsm, "OK"));
cond200=(strstr(uart_string_gsm, "ERROR"));
if((!(cond201|| cond200 ))  && sleep_flag != 1)
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
send_GSM("\r\nAT+CIFSR\r\r\n", "OK", "ERROR" , "DEACT",1);		

//delay(20);


msg_sim800(); 

						sprintf(at_, "\r\nAT+CIPSTART=\"TCP\",\"%s\",\"%s\"\r\n", ip, port);
						send_GSM( at_ , "CONNECT", "ERROR" , "ERROR:",tmeout);	
						clear();
						
						
						send_GSM("\r\nAT+CIPSEND\r\n", ">", "ERROR" , "CONNECT FAIL",tmeout);									
//*************************************tcp_initialization_ends****************************************//							
									
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
									}uart_putchar(UART1_BASE_PTR, 0x1A);uart_putchar(UART1_BASE_PTR, 0x1A);
									do
																{stcond1=strstr(uart_string_gsm,"SEND OK");
																	stcond2=strstr(uart_string_gsm, "ERROR");
																		stcond3=strstr(uart_string_gsm, "FAIL");	
																			stcond4=strstr(uart_string_gsm, "DEACT");	
																	
																}while(!(stcond2 || stcond3 || stcond4 || stcond1 || (tout > 5) ) ); //|| (timeout < 1)   
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

								
																	
																	
								//								log_it();								
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

								
									
									
									
								//	log_it();			//otherwize log it					
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
	
}
	















void send_tcp2()
{	
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

								
	
	
	
	//	log_it();		
		memset(data,0,strlen(data));	
									GPS_COLLECT();
									strcat(data,"CH\n");	
				
					   	if(flagch!=1){
							temp=int_erval;				
							int_erval=4;
							flagch=1;}
							clear();	


//**************************************tcp_initialization();********************************//

	
msg_sim800(); 
send_GSM("\r\nAT+CFUN=0\r\r\n\n", "OK", "ERROR\r\n" , "ERROR",5);	
delay(100);
send_GSM("\r\nAT+CFUN=1\r\n", "OK", "NOT INSERTED\r\nOK" , "ERROR", 4);	
GPS_COLLECT2();
strcat(data,"CH\n");		
GPS_COLLECT2();
strcat(data,"CH\n");	
GPS_COLLECT2();
strcat(data,"CH\n");
cond201=(strstr(uart_string_gsm, "OK"));
cond200=(strstr(uart_string_gsm, "ERROR"));
if((!(cond201|| cond200 ))  && sleep_flag != 1)
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
					clear();
send_GSM("\r\nAT+CIFSR\r\r\n", "OK", "ERROR" , "DEACT",1);		
//					delay(20);


msg_sim800(); 

						sprintf(at_, "\r\nAT+CIPSTART=\"TCP\",\"%s\",\"%s\"\r\n", ip, port);
						send_GSM( at_ , "CONNECT", "ERROR" , "ERROR:",tmeout);	
						clear();
						
						
						send_GSM("\r\nAT+CIPSEND\r\n", ">", "ERROR" , "CONNECT FAIL",tmeout);									
//**************************************tcp_initialization ends******************************//							
									
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
															
														//qwe=strlen(uart_string_gsm);
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

								
									
									
									
								//	log_it();								
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
									}			//

							

	} // if there is a gsm connect available this segment checks for the log available and send it in chunks,..
	else
	{
		send_chunk();
	}		
								
								
								
	memset(data,0,strlen(data));	
	uart_putchar(UART1_BASE_PTR, 0x1A);
	
}




void log_it()
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

								
						//		
}


__inline void saveapn(){
	
send_GSM("\nAT+FSCREATE=C:\\APN.TXT\r\n", "OK", "ERROR\r\n" , "ERROR:",tmeout);

	memset(at_,0,100);
	sprintf(at_,"\r\nAT+FSWRITE=C:\\APN.TXT,0,%d,10\r\n",strlen(apn)+3);	
	send_GSM(at_, ">", "ERROR\r\n" , "ERROR:",10);	
	//clear();

	
	send_modem("|");
		for(k=0;k<strlen(apn);k++)
		{
			uart_putchar(UART1_BASE_PTR, apn[k]);// uart0_putchar(UART0_BASE_PTR, interval[k]);//clear();
		}	
			send_modem("|");			
 
									k2=0;									//string array counter for uart 1
									time=19999;						//timer counts to wait for characters in uart 1 									
									while(!(strstr(uart_string_gsm,"OK\r\n")  ||  (time < 1)  ||(strstr(uart_string_gsm, "ERROR"))))
									{
									time--;
									if(time % 2000 == 0)
										{
											//uart0_putchar(UART0_BASE_PTR,'1');
											uart_putchar(UART1_BASE_PTR,'\n');
										}
	
									}


	
}

__inline void readapn()
{
	memset(at_,0,100);
		sprintf(at_, "\nAT+FSREAD=C:\\APN.TXT,0,100,1\r\n");		
		send_GSM(at_, "OK", "ERROR\r\n" , "ERROR:",10);	
	
		parse_g(uart_string_gsm, 1,2, '|', '|',apn);
	
	
}



__inline void save_interval()
{
	
send_GSM("\nAT+FSCREATE=C:\\INTERVAL.TXT\r\n", "OK", "ERROR\r\n" , "ERROR:",tmeout);

	memset(at_,0,100);
	sprintf(at_,"\r\nAT+FSWRITE=C:\\INTERVAL.TXT,0,%d,10\r\n",strlen(interval)+11);	
	send_GSM(at_, ">", "ERROR\r\n" , "ERROR:",10);	
	//clear();

	
	send_modem("|INTERVAL|");
		for(k=0;k<strlen(interval);k++)
		{
			uart_putchar(UART1_BASE_PTR, interval[k]);// uart0_putchar(UART0_BASE_PTR, interval[k]);//clear();
		}	
			send_modem("|");			
 
									k2=0;									//string array counter for uart 1
									time=19999;						//timer counts to wait for characters in uart 1 									
									while(!(strstr(uart_string_gsm,"OK\r\n")  ||  (time < 1)  ||(strstr(uart_string_gsm, "ERROR"))))
									{
									time--;
									if(time % 2000 == 0)
										{
											//uart0_putchar(UART0_BASE_PTR,'1');
											uart_putchar(UART1_BASE_PTR,'\n');
										}
	
									}


	
}	
	

	
__inline void save_ip_port()
{
	
send_GSM("\nAT+FSCREATE=C:\\IP_PORT.TXT\r\n", "OK", "ERROR\r\n" , "ERROR:",tmeout);
	
	memset(at_,0,100);
	sprintf(at_,"\r\nAT+FSWRITE=C:\\IP_PORT.TXT,0,%d,10\r\n",strlen(ip)+12+strlen(port));	
send_GSM(at_, ">", "ERROR\r\n" , "ERROR:",10);	
	clear();

	
	send_modem("|IP|");
		for(k=0;k<strlen(ip);k++)
		{
			uart_putchar(UART1_BASE_PTR, ip[k]);// uart0_putchar(UART0_BASE_PTR, ip[k]);//clear();
		}	
	send_modem("|PORT|");			
		for(k=0;k<strlen(port);k++)
		{
			uart_putchar(UART1_BASE_PTR, port[k]);// uart0_putchar(UART0_BASE_PTR, port[k]);//clear();
		}	
send_modem("|");			
									//memset(data,0,1000);
									k2=0;									//string array counter for uart 1
									time=19999;						//timer counts to wait for characters in uart 1 									
									while(!(strstr(uart_string_gsm,"OK\r\n")  ||  (time < 1)  ||(strstr(uart_string_gsm, "ERROR"))))
									{
									time--;
									if(time % 2000 == 0)
										{
											uart0_putchar(UART0_BASE_PTR,'1');
											uart_putchar(UART1_BASE_PTR,'\n');
										}
	
									}

	
}	
	
__inline void ignstaton(){
send_GSM("\nAT+FSCREATE=C:\\IGN.TXT\r\n", "OK", "ERROR\r\n" , "ERROR:",tmeout);
send_GSM("\r\nAT+FSWRITE=C:\\IGN.TXT,0,6,10\r\n", ">", "ERROR\r\n" , "ERROR:",5);
	delay(10);
send_GSM("\nION\n\n\n\n", "OK\r\n", "ERROR\r\n" , "ERROR:",10);


}	
__inline void ignstatoff(){
send_GSM("\nAT+FSCREATE=C:\\IGN.TXT\r\n", "OK", "ERROR\r\n" , "ERROR:",tmeout);
send_GSM("\r\nAT+FSWRITE=C:\\IGN.TXT,0,6,10\r\n", ">", "ERROR\r\n" , "ERROR:",5);
	delay(10);
send_GSM("\nIOFF\n\n\n\n", "OK\r\n", "ERROR\r\n" , "ERROR:",10);


}		


__inline void ignread(){
memset(at_,0,100);
		sprintf(at_, "\nAT+FSREAD=C:\\IGN.TXT,0,100,1\r\n");		
		send_GSM(at_, "OK", "ERROR\r\n" , "ERROR:",10);	
if(strstr(uart_string_gsm,"ION")){IGNITION_ON;FUEL_ON;}
else if(strstr(uart_string_gsm,"IOFF")){IGNITION_OFF;FUEL_OFF;}

}	
	
	
__inline void read_ip_port()
{
		memset(at_,0,100);
	//	memset(ip,0,strlen(ip));
		//memset(port,0,strlen(port));
		sprintf(at_, "\nAT+FSREAD=C:\\IP_PORT.TXT,0,100,1\r\n");		
		send_GSM(at_, "OK", "ERROR\r\n" , "ERROR:",10);	
		parse_g(uart_string_gsm, 2,3, '|', '|',ip);
		parse_g(uart_string_gsm, 4,5, '|', '|',port);
	
}		
	
__inline void read_interval()
{
		memset(at_,0,100);
		sprintf(at_, "\nAT+FSREAD=C:\\INTERVAL.TXT,0,100,1\r\n");		
		send_GSM(at_, "OK", "ERROR\r\n" , "ERROR:",10);	
		parse_g(uart_string_gsm, 2,3, '|', '|',interval);
		int_erval=myAtoi(interval);		


}	



	__inline void savecursor(){
send_GSM("\nAT+FSCREATE=C:\\CURSOR.TXT\r\n", "OK", "ERROR\r\n" , "ERROR:",tmeout);
send_GSM("\r\nAT+FSWRITE=C:\\CURSOR.TXT,0,50,10\r\n", ">", "ERROR\r\n" , "ERROR:",5);
	delay(10);
memset(at_,0,100);
sprintf(at_, "\n,%ld,%ld,%ld,\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n",times,k5,cursorvaluepr);		
send_GSM(at_, "OK", "ERROR\r\n" , "ERROR:",10);
}	
	__inline void savecursord(){
send_GSM("\nAT+FSCREATE=C:\\CURSOR.TXT\r\n", "OK", "ERROR\r\n" , "ERROR:",tmeout);
send_GSM("\r\nAT+FSWRITE=C:\\CURSOR.TXT,0,50,10\r\n", ">", "ERROR\r\n" , "ERROR:",5);
	delay(10);
memset(at_,0,100);
sprintf(at_, "\n,%ld,%ld,%ld,\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n",0,0,0);		
send_GSM(at_, "OK", "ERROR\r\n" , "ERROR:",10);
}	
		
	
__inline void readcursor()
{
		memset(at_,0,100);
		sprintf(at_, "\nAT+FSREAD=C:\\CURSOR.TXT,0,100,1\r\n");		
		send_GSM(at_, "OK", "ERROR\r\n" , "ERROR:",10);	
		memset(at_,0,100);
		parse_g(uart_string_gsm, 4,5, ',', ',',at_);
		times=myAtoi(at_);		
		memset(at_,0,100);
		parse_g(uart_string_gsm, 5,6, ',', ',',at_);
		k5=myAtoi(at_);		
		memset(at_,0,100);
		parse_g(uart_string_gsm, 6,7, ',', ',',at_);
		cursorvaluepr=myAtoi(at_);		


}	
	
	
	

void read(char * A,char * B,char * C)
{k=0;l=time;
			do{
			if( uart_getchar_present (UART1_BASE_PTR))	
			{uart_string_gps[k]=UART_D_REG(UART1_BASE_PTR);k++;l=time;if(k>298){k=0;}}
				else{
							l--;if(l==10){}
						}
			}while(!((strstr(uart_string_gps, "OK\r\n"))
							||(strstr(uart_string_gps, "ERROR\r\n"))  || (l<=0)
				        	||(strstr(uart_string_gps, "ERROR:"))
							));
//		clear();
}	
void read2(char * respA,char * respB,char * respC, int timeout)
{k=0;l=time;
			do{
			if( uart_getchar_present (UART2_BASE_PTR))	
			{uart_string_gps[k]=UART_D_REG(UART2_BASE_PTR);k++;l=time;if(k>298){k=0;}}
				else{				
								l--;
						}
			}while(!((strstr(uart_string_gps, respA))
							||(strstr(uart_string_gps, respB))  || (l<=0) 
				        	||(strstr(uart_string_gps, respC))
							));
//		clear();
}	

__inline void send_modem(char ch[])
	{	
						unsigned char i20=0;
						for(i20=0;i20<strlen(ch);i20++)
						{
							uart_putchar(UART1_BASE_PTR, ch[i20]);//clear();
						}
						
	}

	
void send_modem2(char ch[])
	{	
						unsigned char i21;
						i21=0;
						while ((*(ch+i21)) != '\0') // NULL
						{	
						// delay(1);
						 uart_putchar(UART2_BASE_PTR, (*(ch+i21)));
						 i21++;
						}
		
	}	
	
__inline void clear()
{
  if (UART_S1_REG(UART1_BASE_PTR) & UART_S1_OR_MASK)
    {
      temp = UART_D_REG(UART1_BASE_PTR);
		}
		
		UART_S1_REG(UART1_BASE_PTR) |= (UART_S1_OR_MASK | UART_C2_ILIE_MASK );
}	

__inline void clear2()
{
//    if (UART_S1_REG(UART2_BASE_PTR) & UART_S1_OR_MASK)
//    {
//      temp = UART_D_REG(UART2_BASE_PTR);
//    }

	UART_S1_REG(UART2_BASE_PTR) |= (UART_S1_OR_MASK | UART_C2_ILIE_MASK );
}	



__inline void send_GSM(char *string, char *responseA, char *responseB, char *responseC, int32 timeout)
{	 

		//uart_putchar(UART1_BASE_PTR,0xA);
		//uart_putchar(UART1_BASE_PTR,0x1A);
	clear();
	tout=0;
//	qwe=strlen(uart_string_gsm);
		memset(uart_string_gsm,0,5000);
		k2=0;									//string array counter for uart 1
	 						//timer counts to wait for characters in uart 1 
		clear();
		send_modem(string);
		uart_putchar(UART1_BASE_PTR,'\n');	uart_putchar(UART1_BASE_PTR,'\n');	
	delay(10);
//	uart_putchar(UART1_BASE_PTR,'\r');
	//uart_putchar(UART1_BASE_PTR,'\r');uart_putchar(UART1_BASE_PTR,'\n');//uart_putchar(UART1_BASE_PTR,0x1A);
		do
		{
			
//					time111--;
//				  timeout222--;

			
	cond122=strstr(uart_string_gsm, responseA);
	cond123=strstr(uart_string_gsm, responseB);
  cond124=strstr(uart_string_gsm, responseC);
	cond121 = (cond122	|| cond123	|| cond124  || (tout > timeout))	;
			
		}while (!cond121);
		clear();
		if(tout>timeout){
			uart_putchar(UART1_BASE_PTR,'\r');
		uart_putchar(UART1_BASE_PTR,'\n');uart_putchar(UART1_BASE_PTR,0x1A);
		uart_putchar(UART1_BASE_PTR,0x1A);uart_putchar(UART1_BASE_PTR,'\r');
		uart_putchar(UART1_BASE_PTR,'\n');}
		//return;
//		return uart_string_gsm;

		


}



__inline char * send_MSG(char *string, char *responseA, char *responseB, char *responseC, int32 timeout)
{	
		qwe=strlen(uart_string_gsm);

	
		memset(uart_string_gsm,0,qwe);
		k2=0;									//string array counter for uart 1
	  time111=99999;						//timer counts to wait for characters in uart 1 
		clear();
		timeout222=2001;
		send_modem(string);
		do	{
			
					time111--;
				  timeout222--;
//          if(lptmr_interrupt == 1){
//					//accel_read();
//					detect_motion();
//					lptmr_interrupt = 0;}		
//					if(timeout222 % 400 == 0)
//					{
//						//uart0_putchar(UART0_BASE_PTR,'1');uart_putchar(UART1_BASE_PTR,0x1A);
//					}
			
	cond122=strstr(uart_string_gsm, responseA);
	cond123=strstr(uart_string_gsm, responseB);
  cond124=strstr(uart_string_gsm, responseC);
	cond121 = (cond122	|| cond123	|| cond124  || (time111<=1))	;			
			
			
		}while (!cond121);
		clear();
		return uart_string_gsm;

}


	
__inline char * send_GPS(char * string, char* responseA, char* responseB, char* responseC, int timeout)
{
qweq = strlen(uart_string_gps);
	
	memset(uart_string_gps,0,qweq);
	clear2();
	send_modem2(string);
	read2(responseA,responseB,responseC,timeout);
	clear2();
	return uart_string_gps;
}
	





__inline void parse(char* str, int first, int sec, char *string)
{

		delay(10);		
		memset(string,0,15);
		for(i11=0,temp11=0;i11<100;i11++)
		{
		if(str[i11]==',')
			{temp11++;j11=i11;}
		else{}
			
		if(temp11>=sec){i11=900;}
		else{}	
		
		}	
		
		for(i11=0,temp11=0;i11<100;i11++)
		{
		if(str[i11]==',')
			{temp11++;l=i11;}										
		else{}
		if(temp11>=first){i11=900;}else{}
		}	
		for(i11=0;i11<(j11-l-1);i11++)
		{
		string[i11] = str[l+i11+1];
		}			
	

}

void parse_gsm(char *str, int first, int sec, char *string)
{

		delay(10);		
		memset(string,0,15);
		for(i11=0,temp11=0;i11<100;i11++)
		{
		if(str[i11]=='"')
			{temp11++;j11=i11;}
		else{}
			
		if(temp11>=sec){i11=900;}
		else{}	
		
		}	
		
		for(i11=0,temp11=0;i11<100;i11++)
		{
		if(str[i11]=='"')
			{temp11++;l=i11;}										
		else{}
		if(temp11>=first){i11=900;}else{}
		}	
		for(i11=0;i11<(j11-l-1);i11++)
		{
		string[i11] = str[l+i11+1];
		}			
	

}



__inline void parse_g(char* str, int first, int sec, char f, char s , char *string)
{

		sz1=	strlen(str);
		sz2=  strlen(string);
		memset(string,0,sz2);
		for(i11=0,temp11=0;i11<sz1;i11++)
		{
		if(str[i11]==s)
			{temp11++;j11=i11;}
		else{}
			
		if(temp11>=sec){i11=9900;}
		else{}	
		
		}	
		
		for(i11=0,temp11=0;i11<sz1;i11++)
		{
		if(str[i11]==f)
			{temp11++;l=i11;}										
		else{}
		if(temp11>=first){i11=9900;}else{}
		}	
		for(i11=0;i11<(j11-l-1);i11++)
		{
		string[i11] = str[l+i11+1];
		}			
	


}




void gsm_gps_sleep()
{
	
sprintf(at_, "\r\nAT+CIPSTART=\"TCP\",\"%s\",\"%s\"\r\n", ip, port);
send_GSM( at_ , "CONNECT", "ERROR" , "CONNECT",tmeout);										
send_chunk();
	//sleep modules;
//	do{
//				accel_read();
//				motion_samples = 0;
//				detect_motion();
//				
//	}while(motion != 1);
//	motion_samples = 0;
//wakeup modules;




}

