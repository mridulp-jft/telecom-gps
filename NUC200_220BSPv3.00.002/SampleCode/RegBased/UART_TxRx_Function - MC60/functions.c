#define UART0RXBUFSIZE 1240

/*---------------------------------------------------------------------------------------------------------*/
/* Global variables                                                                                        */
/*---------------------------------------------------------------------------------------------------------*/
char UART0Data[UART0RXBUFSIZE];
char IMEI[16];
char buffer[200];
char GPSdata[1500];
int intervaltimercount = 0;
extern volatile uint32_t g_u32AdcIntFlag;


extern int sent;

uint32_t sysTicks=0;
int32_t inc=0;
int tmrcount = 0 ;
int tcpdatasize=0;
int responseok=0;
__INLINE void delayms(int32_t sec);
__INLINE void wakeup();
__INLINE void remove_all_chars(char* str, char c, char d);
__INLINE void delay(int32_t sec);


__inline void parse_g(char* str, int first, int sec, char f, char s , char *string)
{int sz1,sz2,i11,temp11,j11,l;
	if(responseok == 1)
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
}


__INLINE void sendAT(char* AT, char* resp1, char* resp2, char*resp3, uint32_t waittime_sec);


/*---------------------------------------------------------------------------------------------------------*/
/* ISR to handle UART Channel 1 interrupt event                                                            */
/*---------------------------------------------------------------------------------------------------------*/
void UART02_IRQHandler(void)
{

	if((UART0->FSR & UART_FSR_RX_EMPTY_Msk) == 0)   
			{			/* Get the character from UART Buffer */
				UART0Data[inc]= UART0->RBR;
				inc++;
			}

}


void SysTick_Handler(void)
{
	sysTicks++;
}


__INLINE void getimei()
{
	int imeipointer=0;
	int imeiinc=0;
	memset(IMEI,0,16);
	sendAT("\r\nAT+GSN\r\n","OK","ERROR","DEACT",4);
	for(imeipointer=0;imeipointer<strlen(UART0Data);imeipointer++)
	{
		if((UART0Data[imeipointer]>47)   &&   (UART0Data[imeipointer]<58))
			{   //means numeric
				IMEI[imeiinc] = UART0Data[imeipointer];
				imeiinc++;
		  }
	}
}


void ADC_IRQHandler(void)
{
    g_u32AdcIntFlag = 1;
    ADC->ADSR = ADC_ADSR_ADF_Msk;      /* clear the A/D conversion flag */
}

	
void TMR0_IRQHandler(void)
{
    if(TIMER_GetIntFlag(TIMER0) == 1)
    {
        /* Clear Timer0 time-out interrupt flag */
        TIMER_ClearIntFlag(TIMER0);

        tmrcount+=1;
				intervaltimercount++;
//				if(g_au32TMRINTCount % 2 == 0){PA3=1;PA4=1;PA5=1;PA6=1;}
//					else{PA3=0;PA4=0;PA5=0;PA6=0;} 
	
    }
}


__INLINE void GETGPSDATA()
{
	int imeipointer=0;	int imeiinc=0;
//		memset(GPSdata,0,1000);
		memset(buffer,0,200);
		memset(IMEI,0,16);
		sendAT("\r\nAT\r\n","OK","ERROR","DEACT",1);

		sendAT("\r\nAT+GSN\r\n","OK","ERROR","DEACT",2);
		for(imeipointer=0;imeipointer<strlen(UART0Data);imeipointer++)
		{
			if((UART0Data[imeipointer]>47)   &&   (UART0Data[imeipointer]<58))
				{   //means numeric
					IMEI[imeiinc] = UART0Data[imeipointer];
					imeiinc++;
				}
		}	
		
		sendAT("\r\nAT+QGNSSRD=\"NMEA/GGA\"\r\n", "+MGPSSTATUS", "OK" , "EcROR",5);	
		
		memset(buffer,0,200);
		parse_g(UART0Data,2,3,'\n','\r',buffer);
		remove_all_chars(buffer, '\r', '\n');
		strcat(GPSdata,IMEI);
		strcat(GPSdata,",");
		strcat(GPSdata,buffer);
		strcat(GPSdata,",");
		sendAT("\r\nAT+QGNSSRD=\"NMEA/RMC\"\r\n", "+MGPSSTATUS", "OK" , "EcROR",5);	
		memset(buffer,0,200);
		parse_g(UART0Data,2,3,'\n','\r',buffer);
		remove_all_chars(buffer, '\r', '\n');
		strcat(GPSdata,buffer);
		strcat(GPSdata,"\n");

//		sendAT("\r\nAT+GETGPS=\"ALL\",1\r\n", "Ready", "OK" , "ERROR",2);

		
}


__INLINE void TCPsend()
{
	int tcpdatapointer=0;
	char* r1=0;
	char* r2;
	char* r3;
	int try1;
	for(try1 = 0; try1 < 3; try1++)
		{sendAT("\r\nAT+CREG?\r\n", "OK", "DEACT" , "ERROR",5);
			if((  strstr(UART0Data,"CREG: 0,1")     || strstr(UART0Data,"CREG: 0,5")))
			{
				sendAT("\r\nAT+CIPSTART=\"TCP\",\"rudra.jellyfishtele.com\",\"5555\"\r\n", "CONNECT", "DEACT" , "ERROR",8);
				sendAT("\r\nAT+CIPSEND\r\n", ">", "OK" , "ERROR",5);
				r1=strstr(UART0Data,">");
				if(r1)
				{
						memset(UART0Data,0,UART0RXBUFSIZE);
						tcpdatasize = strlen(GPSdata);
						if(tcpdatasize < 100){
//						while(1);
						}
						strcat(GPSdata,"\n\n");
						for(tcpdatapointer=0;tcpdatapointer<=tcpdatasize;)
							{
							 //UART1->FSR |= UART_FSR_TX_OVER_IF_Msk;
							 if(!(UART0->FSR & UART_FSR_TX_FULL_Msk))
								{ 
									UART0->DATA = GPSdata[tcpdatapointer];
									tcpdatapointer++;
									//delayms(1);
								}
							}
							 //UART1->FSR |= UART_FSR_TX_OVER_IF_Msk;
							for(tcpdatapointer=0; tcpdatapointer<1;)
								if(!(UART0->FSR & UART_FSR_TX_FULL_Msk))
								{ 
									UART0->DATA = 0X1A;
									tcpdatapointer++;
								}			
						inc=0;//				memset(UART1Data,0,UART1RXBUFSIZE);
						tmrcount=0;
						do{
								r1=strstr(UART0Data,"SEND OK");
								r2=strstr(UART0Data,"SEND FAIL");
								r3=strstr(UART0Data,"ERROR");
							}while(! ( r1 || r2 || r3 || ((tmrcount > 5))));
				
				}
			}else{
							sendAT("\r\nAT+CIPSHUT\r\n", "OK", "DEACT" , "ERROR",5);
							sendAT("\r\nAT+CFUN=0\r\n", "CLOSED", "OK" , "ERROR",5);
							sendAT("\r\nAT+CFUN=1\r\n", "EUSIM", "OK" , "ERROR",5);
							delay(7);
	//						sendAT("\r\nAT+COPS=?\r\n", "CLOSED", "OK" , "ERROR",5);

							sendAT("\r\nAT+CSTT=\"isafe\"\r\n", "Ready", "OK" , "ERROR",5);	
							sendAT("\r\nAT+CGATT?\r\n", "Ready", "OK" , "ERROR",5);	

							sendAT("\r\nAT+CGATT=1\r\n", "Ready", "OK" , "ERROR",5);	
							sendAT("\r\nAT+CIICR\r\n", "Ready", "OK" , "ERROR",5);	
							sendAT("\r\nAT+CIFSR\r\n", "Ready", "OK" , "ERROR",5);	
				
				
				
							sendAT("\r\nAT+CIPMUX=0\r\n", "Ready", "OK" , "ERROR",5);	
							sendAT("\r\nAT+CSQ\r\n", "Ready", "OK" , "ERROR",5);	
							sendAT("\r\nAT+CIPSTART=\"TCP\",\"rudra.jellyfishtele.com\",\"5555\"\r\n", "CONNECT", "DEACT" , "ERROR",8);

						}
			
			
			
				if(r1){
					sent=1;
					break;
				}
				else{
					if(try1>1){
					sent=0;break;}
				}

		}		
memset(GPSdata,0,1500);
}

	
	
__INLINE void delay(int32_t sec){
	int ms1,ms2;
	
	for(ms1=0;ms1<(sec*2000);ms1++)
	{
		for(ms2=0;ms2<999;ms2++);
	}
	
}
	
__INLINE void delayms(int32_t sec){
	int ms1,ms2;
	
	for(ms1=0;ms1<(sec*2);ms1++)
	{
		for(ms2=0;ms2<999;ms2++);
	}
	
}	


__INLINE void remove_all_chars(char* str, char c, char d) {
    char *pr = str, *pw = str;
    while (*pr) {
        *pw = *pr++;
			pw += (*pw != c && *pw != d);// && *pw != ' ' && *pw != '/' && *pw != ':');
    }
    *pw = '\0';
}





__INLINE void sendAT(char* AT, char* resp1, char* resp2, char* resp3, uint32_t waittime_sec)
{
	char*r1;
	char*r2;
	char*r3;
	int size,finc=0;
	char flush[100];
	int atpointer=0;
	inc=0;
	tmrcount=0;
	size=strlen(AT);
//	delayms(1);
	memset(UART0Data,0,UART0RXBUFSIZE);

	UART0->FSR |= UART_FSR_TX_OVER_IF_Msk;
   if(!(UART0->FSR & UART_FSR_TX_FULL_Msk))
		{ 
			UART0->DATA = 0x1A;
		}	
	
	UART0->FSR |= UART_FSR_TX_OVER_IF_Msk;
	for(atpointer=0;atpointer<size;)
	{
   if(!(UART0->FSR & UART_FSR_TX_FULL_Msk))
		{ 
			UART0->DATA = AT[atpointer];
			atpointer++;
		}
	}	
	do{
		r1=strstr(UART0Data,resp1);
		r2=strstr(UART0Data,resp2);
		r3=strstr(UART0Data,resp3);
	}while(! ( r1 || r2 || r3 || ((tmrcount >= waittime_sec ))));
	if(r1 || r2 || r3)
	{
		responseok=1;
	}
	else
	{
		responseok=0;
	}
 //CLK_SysTickDelay(1000);
}




