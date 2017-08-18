#include "uart.h"
#include "string.h"
void clear2(), clear(), read(char * A,char * B,char * C), read2(char * respA,char * respB,char * respC, int timeout), send_modem(char ch[]),  send_modem2(char ch[]), log_it(), parse_g(char* str, int first, int sec,	char f,		char s , char *string); 
extern void uart_putchar (UART_MemMapPtr channel, char ch),delay(int delaytime),  LED_state(void) , accel_read(void), detect_motion(), tcp_initialization(), send_chunk();
char * send_GSM(char *string, char *responseA, char *responseB, char *responseC, int32 timeout);
extern char string_gps[100],gga[100],rmc[100],uart_string_gps[500], at_[100], fsize[15], ip[16],port[10],interval[5],lptmr_interrupt;
char uart_string_gsm[5000],data[1500],num2[30];
extern volatile uint8_t stateCount = 0;	
extern float stof(const char* s);
extern int motion,motion_samples,int_erval;	
extern char* test;extern int32 tmeout;
int k,l,k2,l2;
long time=999999;



void send_tcp()
{	int qwe,timeout;
	
								//sprintf(data_2,"Latitude->%s,Longitude->%s,Velocity->%skmph\nhttps://www.google.com/search?q=%s%c2C%s&ie=utf-8&oe=utf-8\n",lati,longi,velocity,lati,'%',longi);			
								if(strstr(uart_string_gsm,">"))	
								{
									
															clear();
															qwe=strlen(uart_string_gsm);
															printf("\nsizeofbuffer-> %d\n",qwe);
															memset(uart_string_gsm,0,qwe);

									for(k=0;k<strlen(data);k++)
									{
										uart_putchar(UART1_BASE_PTR, data[k]);clear();// uart0_putchar(UART0_BASE_PTR, data[k]);
									}		
										uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, 0x1A);
												k2=0;									//string array counter for uart 1
												timeout=3001;						//timer counts to wait for characters in uart 1 									
												//send_modem("\r\n");//uart_putchar(UART1_BASE_PTR, 0x1A);send_modem("\r\n");uart_putchar(UART1_BASE_PTR, 0x1A);send_modem("\r\n");

													while(!(strstr(uart_string_gsm,"SEND OK\r\n")  ||  (timeout < 1))       )
															{
																timeout--;
																if(lptmr_interrupt == 1){accel_read();detect_motion();lptmr_interrupt = 0;}		

																if(timeout % 400 == 0)
																{
																	uart0_putchar(UART0_BASE_PTR,'1');uart_putchar(UART1_BASE_PTR,0x1A);
																}
	
															}
														qwe=strlen(uart_string_gsm);
														printf("\nsizeofbuffer-> %d\n",qwe);

												if(! strstr(uart_string_gsm,"SEND OK\r\n"))
												{
													
													log_it();
							
													
												}
									
												printf("***********************************************\n\n\n%s\n***********************************************\n",uart_string_gsm);									

									uart_putchar(UART1_BASE_PTR, 0x1A);clear();
									memset(data,0,strlen(data));

								}
						else{
									uart_putchar(UART1_BASE_PTR, 0x1A);
									printf("reinitialization ON LOOP...\n");	
									tcp_initialization();
									log_it();

								}
		
	uart_putchar(UART1_BASE_PTR, 0x1A);
	
}
	

void log_it()
{
	
	memset(at_,0,100);
	sprintf(at_,"\r\nAT+FSWRITE=C:\\LOG.TXT,1,%d,10\r\n",strlen(data));	
	printf("\n%s\n",send_GSM(at_, ">", "ERROR\r\n" , "ERROR:",19999));	
	clear();
		for(k=0;k<=strlen(data);k++)
		{
			uart_putchar(UART1_BASE_PTR, data[k]); uart0_putchar(UART0_BASE_PTR, data[k]);clear();
		}	
									//memset(data,0,1000);
									k2=0;									//string array counter for uart 1
									time=2001;						//timer counts to wait for characters in uart 1 									
									while(!(strstr(uart_string_gsm,"OK\r\n")  ||  (time < 1)  || (strstr(uart_string_gsm, "ERROR"))))
									{
									time--;
									if(lptmr_interrupt == 1){accel_read();detect_motion();lptmr_interrupt = 0;}		
			
									if(time % 400 == 0)
										{uart0_putchar(UART0_BASE_PTR,'1');uart_putchar(UART1_BASE_PTR,'\n');
										}
	
									}
	
									memset(data,0,strlen(data));

}


void save_interval()
{
	
printf("\n%s\n",send_GSM("\nAT+FSCREATE=C:\\INTERVAL.TXT\r\n", "OK", "ERROR\r\n" , "ERROR:",999999));

	memset(at_,0,100);
	sprintf(at_,"\r\nAT+FSWRITE=C:\\INTERVAL.TXT,0,%d,10\r\n",strlen(interval)+11);	
	printf("\n%s\n",send_GSM(at_, ">", "ERROR\r\n" , "ERROR:",999999));	
	clear();
	send_modem("|INTERVAL|");
		for(k=0;k<strlen(interval);k++)
		{
			uart_putchar(UART1_BASE_PTR, interval[k]); uart0_putchar(UART0_BASE_PTR, interval[k]);//clear();
		}	
			send_modem("|");			
 
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
	

	
void save_ip_port()
{
	
printf("\n%s\n",send_GSM("\nAT+FSCREATE=C:\\IP_PORT.TXT\r\n", "OK", "ERROR\r\n" , "ERROR:",999999));
	
	memset(at_,0,100);
	sprintf(at_,"\r\nAT+FSWRITE=C:\\IP_PORT.TXT,0,%d,10\r\n",strlen(ip)+12+strlen(port));	
	printf("\n%s\n",send_GSM(at_, ">", "ERROR\r\n" , "ERROR:",999999));	
	clear();
	send_modem("|IP|");
		for(k=0;k<strlen(ip);k++)
		{
			uart_putchar(UART1_BASE_PTR, ip[k]); uart0_putchar(UART0_BASE_PTR, ip[k]);//clear();
		}	
	send_modem("|PORT|");			
		for(k=0;k<strlen(port);k++)
		{
			uart_putchar(UART1_BASE_PTR, port[k]); uart0_putchar(UART0_BASE_PTR, port[k]);//clear();
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
		send_GSM(at_, "OK", "ERROR\r\n" , "ERROR:",19999);	
		parse_g(uart_string_gsm, 2,3, '|', '|',ip);
		parse_g(uart_string_gsm, 4,5, '|', '|',port);
		
		printf ("\n\n\n\t\t\t****************************\n%s\n%s\n%s\n\n\t\t\t*****************************",uart_string_gsm,ip,port);

}		
	
void read_interval()
{
		memset(at_,0,100);
		sprintf(at_, "\nAT+FSREAD=C:\\INTERVAL.TXT,0,100,1\r\n");		
		send_GSM(at_, "OK", "ERROR\r\n" , "ERROR:",99999);	
		parse_g(uart_string_gsm, 2,3, '|', '|',interval);
		int_erval=myAtoi(interval);		
		printf ("\n\n\n\t\t\t****************************\n%s\n\n\n\t\t\t*****************************",interval);

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
{char temp;
    if (UART_S1_REG(UART1_BASE_PTR) & UART_S1_OR_MASK)
    {
      temp = UART_D_REG(UART1_BASE_PTR);
		}
		
	UART_S1_REG(UART1_BASE_PTR) |= (UART_S1_OR_MASK | UART_C2_ILIE_MASK );
}	

void clear2()
{char temp;
    if (UART_S1_REG(UART2_BASE_PTR) & UART_S1_OR_MASK)
    {
      temp = UART_D_REG(UART2_BASE_PTR);
    }

	UART_S1_REG(UART2_BASE_PTR) |= (UART_S1_OR_MASK | UART_C2_ILIE_MASK );
}	



char * send_GSM(char *string, char *responseA, char *responseB, char *responseC, int32 timeout)
{	int qwe;int exitflag=1;int cntr=0; long time111,timeout222;
		qwe=strlen(uart_string_gsm);
		printf("\nsizeofbuffer-> %d, motion-> %d, motion_samples-> %d\n",qwe,motion,motion_samples);
		memset(uart_string_gsm,0,qwe);
		k2=0;									//string array counter for uart 1
	  time111=timeout;						//timer counts to wait for characters in uart 1 
		clear();
		timeout222=2001;
		send_modem(string);
		while (!((strstr(uart_string_gsm, responseA))	|| (strstr(uart_string_gsm, responseB))	|| (strstr(uart_string_gsm, responseC))  || (time111<=1)    	))
		{
			
					time111--;
				  timeout222--;
          if(lptmr_interrupt == 1){accel_read();detect_motion();lptmr_interrupt = 0;}		
					if(timeout222 % 400 == 0)
					{uart0_putchar(UART0_BASE_PTR,'1');uart_putchar(UART1_BASE_PTR,0x1A);
					}
			
		}
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
{int i=0,j=0,temp=0;

		delay(10);		
		memset(string,0,strlen(string));
		for(i=0,temp=0;i<strlen(str);i++)
		{
		if(str[i]==s)
			{temp++;j=i;}
		else{}
			
		if(temp>=sec){i=9900;}
		else{}	
		
		}	
		
		for(i=0,temp=0;i<strlen(str);i++)
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
printf("\n%s\n",send_GSM( at_ , "CONNECT", "ERROR\r\n" , "CONNECT",tmeout));										
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