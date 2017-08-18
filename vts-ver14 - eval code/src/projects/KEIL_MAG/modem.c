#include "uart.h"
#include "string.h"
#include "gpios.h"
//#include "stdlib.c"
void clear2(), clear(), read(char * A,char * B,char * C), read2(char * respA,char * respB,char * respC, int timeout), send_modem(char ch[]),  send_modem2(char ch[]), log_it(), parse_g(char* str, int first, int sec,	char f,		char s , char *string); 
//extern-static MISRA-C rule 8.8
extern void delay(int delaytime),  LED_state(void) , accel_read(void), detect_motion(),send_chunk();
//--------------------
void send_GSM(char *string, char *responseA, char *responseB, char *responseC, int32 timeout);
//extern-static MISRA-C rule 8.8
extern char string_gps[100],gga[100],rmc[100],uart_string_gps[3000], at_[100], fsize[15], ip[16],port[10],interval[5],drive[5],lptmr_interrupt;
//---------------------------------
char uart_string_gsm[5000],data[1500],num2[30];
extern  char imei[20];
extern char* apn;
extern volatile uint8_t stateCount = 0;	
extern int	GPS_COLLECT();
extern float stof(const char* s);
extern int motion,motion_samples,int_erval;	
extern char* test;extern int32 tmeout;
int k,l,k2,l2;
extern void HardFault_Handler();
extern void remove_all_chars(char* str, char c, char d);
int tout=0,tout2=0;
extern void get_imei();
long time=999999;
extern char mystrstr(char* str1, char character);
int tcp_initialization();
int temp;int flagch=0;




void send_SD(char *string, char *responseA, char *responseB, char *responseC, int32 timeout)
{	int qwe;int exitflag=1;int cntr=0; long time111,timeout222;
	char cond121;
	char* cond122;
	char* cond123;
	char* cond124;
		//uart_putchar(UART1_BASE_PTR,0xA);
		//uart_putchar(UART1_BASE_PTR,0x1A);
	clear();
	tout=0;
//	qwe=strlen(uart_string_gsm);
		memset(uart_string_gsm,0,5000);
		k2=0;									//string array counter for uart 1
	  time111=timeout;						//timer counts to wait for characters in uart 1 
		clear();
		timeout222=2001;
		send_modem(string);

	//	uart_putchar(UART1_BASE_PTR,'\n');	uart_putchar(UART1_BASE_PTR,'\n');	
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
{	int qwe,len;long timeout;
	char cond;
	char* con1d;
	char* stcond1;char * stcond2;char * stcond3;char * stcond4;char * stcond5;
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
							remove_all_chars(data, '\n', '\n');
	
		strcat(data,"CH\n");	
		log_it();		                         //logging
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
																log_it();								
																}else{send_chunk();}													
								//checks for the sd_data available
								}
								//con1d=strstr(uart_string_gsm,"OK");
								else
								{
									log_it();			//otherwize log it					
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
{	int qwe,len;long timeout;
	char cond;
	char* con1d;
	char* stcond1;char * stcond2;char * stcond3;char * stcond4;char * stcond5;
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
		log_it();		                         //logging
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
																log_it();								
																}else{send_chunk();}													
								//checks for the sd_data available
								}
								//con1d=strstr(uart_string_gsm,"OK");
								else
								{
									log_it();			//otherwize log it					
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
{	int qwe,len;long timeout;int logged;
	char cond;
	char* con1d;
	char* stcond1;char * stcond2;char * stcond3;char * stcond4;char * stcond5;
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
		log_it();		
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
									log_it();								
								}else{send_chunk();}	

																
								}else{log_it();logged=1;}			//

							

	} // if there is a gsm connect available this segment checks for the log available and send it in chunks,..
	else
	{
		send_chunk();
	}		
								
								
								
	memset(data,0,strlen(data));	
	uart_putchar(UART1_BASE_PTR, 0x1A);
	
}




void log_it()
{char *check;
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
uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, '\n');	uart_putchar(UART1_BASE_PTR, '\n');	uart_putchar(UART1_BASE_PTR, '\n');	uart_putchar(UART1_BASE_PTR, '\n');	uart_putchar(UART1_BASE_PTR, '\n');	uart_putchar(UART1_BASE_PTR, '\n');	uart_putchar(UART1_BASE_PTR, '\n');	
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























void saveapn(){
	
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

void readapn()
{
	memset(at_,0,100);
		sprintf(at_, "\nAT+FSREAD=C:\\APN.TXT,0,100,1\r\n");		
		send_GSM(at_, "OK", "ERROR\r\n" , "ERROR:",10);	
	
		parse_g(uart_string_gsm, 1,2, '|', '|',apn);
	
	
}

void save_interval()
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
	

	
void save_ip_port()
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
	
	
	
	
	
	
void read_ip_port()
{
		memset(at_,0,100);
		sprintf(at_, "\nAT+FSREAD=C:\\IP_PORT.TXT,0,100,1\r\n");		
		send_GSM(at_, "OK", "ERROR\r\n" , "ERROR:",10);	
		parse_g(uart_string_gsm, 2,3, '|', '|',ip);
		parse_g(uart_string_gsm, 4,5, '|', '|',port);
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
		


}		
	
void read_interval()
{
		memset(at_,0,100);
		sprintf(at_, "\nAT+FSREAD=C:\\INTERVAL.TXT,0,100,1\r\n");		
		send_GSM(at_, "OK", "ERROR\r\n" , "ERROR:",10);	
		parse_g(uart_string_gsm, 2,3, '|', '|',interval);
		int_erval=myAtoi(interval);		


}		
	
		
	void send_bal(){
	int qwe,len;long timeout;
	char cond;
	char* con1d;
	char* stcond1;char * stcond2;char * stcond3;char * stcond4;char * stcond5;
	
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
									}uart_putchar(UART1_BASE_PTR, 0x1A);uart_putchar(UART1_BASE_PTR, 0x1A);uart_putchar(UART1_BASE_PTR, 0x1A);
									do
																{stcond1=strstr(uart_string_gsm,"OK\r\n");
																	stcond2=strstr(uart_string_gsm, "ERROR");
																		stcond3=strstr(uart_string_gsm, "FAIL");	
																			stcond4=strstr(uart_string_gsm, "DEACT");	
																	
																}while(!(stcond2 || stcond3 || stcond4 || stcond1 || (tout > 10) ) ); //|| (timeout < 1)   
																delay(10);clear();
														uart_putchar(UART1_BASE_PTR,0x1A);
												delay(10);
										uart_putchar(UART1_BASE_PTR, 0x1A);uart_putchar(UART1_BASE_PTR, 0x1A);uart_putchar(UART1_BASE_PTR, 0x1A);
				
								}
								else{log_it;}
con1d=strstr(uart_string_gsm,"OK");		
								if(!con1d)log_it();
		
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
{int cntr;k=0;l=time;
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

void send_modem(char ch[])
	{	
						unsigned char i=0;
						for(i=0;i<strlen(ch);i++)
						{
							uart_putchar(UART1_BASE_PTR, ch[i]);//clear();
						}
						
	}

	
void send_modem2(char ch[])
	{	
						unsigned char i;
						i=0;
						while ((*(ch+i)) != '\0') // NULL
						{	
						// delay(1);
						 uart_putchar(UART2_BASE_PTR, (*(ch+i)));
						 i++;
						}
		
	}	
	
void clear()
{
	char temp;
  if (UART_S1_REG(UART1_BASE_PTR) & UART_S1_OR_MASK)
    {
      temp = UART_D_REG(UART1_BASE_PTR);
		}
		
		UART_S1_REG(UART1_BASE_PTR) |= (UART_S1_OR_MASK | UART_C2_ILIE_MASK );
}	

void clear2()
{char temp;
//    if (UART_S1_REG(UART2_BASE_PTR) & UART_S1_OR_MASK)
//    {
//      temp = UART_D_REG(UART2_BASE_PTR);
//    }

	UART_S1_REG(UART2_BASE_PTR) |= (UART_S1_OR_MASK | UART_C2_ILIE_MASK );
}	



void send_GSM(char *string, char *responseA, char *responseB, char *responseC, int32 timeout)
{	int qwe;int exitflag=1;int cntr=0; long time111,timeout222;
	char cond121;
	char* cond122;
	char* cond123;
	char* cond124;
		//uart_putchar(UART1_BASE_PTR,0xA);
		//uart_putchar(UART1_BASE_PTR,0x1A);
	clear();
	tout=0;
//	qwe=strlen(uart_string_gsm);
		memset(uart_string_gsm,0,5000);
		k2=0;									//string array counter for uart 1
	  time111=timeout;						//timer counts to wait for characters in uart 1 
		clear();
		timeout222=2001;
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



char * send_MSG(char *string, char *responseA, char *responseB, char *responseC, int32 timeout)
{	int qwe;int exitflag=1;int cntr=0; long time111,timeout222;
	char cond121;
	char* cond122;
	char* cond123;
	char* cond124;	
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


	
char * send_GPS(char * string, char* responseA, char* responseB, char* responseC, int timeout)
{
int qweq = strlen(uart_string_gps);
	
	memset(uart_string_gps,0,qweq);
	clear2();
	send_modem2(string);
	read2(responseA,responseB,responseC,timeout);
	clear2();
	return uart_string_gps;
}
	





void parse(char* str, int first, int sec, char *string)
{int i=0,j=0,temp=0;

		delay(10);		
		memset(string,0,15);
		for(i=0,temp=0;i<100;i++)
		{
		if(str[i]==',')
			{temp++;j=i;}
		else{}
			
		if(temp>=sec){i=900;}
		else{}	
		
		}	
		
		for(i=0,temp=0;i<100;i++)
		{
		if(str[i]==',')
			{temp++;l=i;}										
		else{}
		if(temp>=first){i=900;}else{}
		}	
		for(i=0;i<(j-l-1);i++)
		{
		string[i] = str[l+i+1];
		}			
	

}

void parse_gsm(char *str, int first, int sec, char *string)
{int i=0,j=0,temp=0;

		delay(10);		
		memset(string,0,15);
		for(i=0,temp=0;i<100;i++)
		{
		if(str[i]=='"')
			{temp++;j=i;}
		else{}
			
		if(temp>=sec){i=900;}
		else{}	
		
		}	
		
		for(i=0,temp=0;i<100;i++)
		{
		if(str[i]=='"')
			{temp++;l=i;}										
		else{}
		if(temp>=first){i=900;}else{}
		}	
		for(i=0;i<(j-l-1);i++)
		{
		string[i] = str[l+i+1];
		}			
	

}



void parse_g(char* str, int first, int sec, char f, char s , char *string)
{int i=0,j=0,temp=0;int sz1,sz2;

		sz1=	strlen(str);
		sz2=  strlen(string);
		memset(string,0,sz2);
		for(i=0,temp=0;i<sz1;i++)
		{
		if(str[i]==s)
			{temp++;j=i;}
		else{}
			
		if(temp>=sec){i=9900;}
		else{}	
		
		}	
		
		for(i=0,temp=0;i<sz1;i++)
		{
		if(str[i]==f)
			{temp++;l=i;}										
		else{}
		if(temp>=first){i=9900;}else{}
		}	
		for(i=0;i<(j-l-1);i++)
		{
		string[i] = str[l+i+1];
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