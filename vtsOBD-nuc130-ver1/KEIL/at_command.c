#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "NUC100Series.h"
#define osObjectsPublic										 // define objects in main module
#include "osObjects.h"											// RTOS object definitions
#include "uart.h"
#include "cmsis_os.h"							 // CMSIS RTOS header file

/*	Extern Variables
*****************************************************************/
extern char g_u8SendData[TXBUFSIZE];
extern char g_u8RecData[RXBUFSIZE];
extern	int32_t life;
extern void SendChar(int ch);
/****************************************************************/


/*	Global Variables
*****************************************************************/
int32_t	inc=0;
uint8_t u8InChar=0xFF;
int32_t g_u8RecDataptr=0;
float	u32ADC0Result;
float u32ADC0Result1;
int8_t charging, cpinready, cregready;
int motion_counts,immotion_counts;
int32_t timer0ticks=0;
int32_t tmr0sec=0;
char * r1;
char * r2;
char * r3;
char temp[100];
char fileinstance[20] = {0};
int8_t  network;uint8_t sendfs=0;
int breaker=0;
int seeker = 0;
int imeiptr0=0;
char imei[25];
int imeiptr=0;

/****************************************************************/



osMutexDef (uart_mutex);		// Declare mutex
osMutexId	(uart_mutex_id); // Mutex ID
		
osMutexDef (tcp_mutex);		// Declare mutex
osMutexId	(tcp_mutex_id); // Mutex ID

osMutexDef (fs_mutex);		// Declare mutex
osMutexId	(fs_mutex_id); // Mutex ID		


/*	Function Declarations
*****************************************************************/
void SendAT(char * command, char * response1, char * response2, char * response3, int32_t timeout);
void SendAT_FS(char * command, char * response1, char * response2, char * response3, int32_t timeout);
void TCP_Send_ch(char * tcpcommand,char * tcpdataq, char * tcpresponse1, char * tcpresponse2, char * tcpresponse3, int32_t tcptimeout);
void SendAT_GPS_WO_MUTEX(char * command, char * response1, char * response2, char * response3, int32_t timeout);
void TCP_Send_ch(char * tcpcommand,char * tcpdataq, char * tcpresponse1, char * tcpresponse2, char * tcpresponse3, int32_t tcptimeout);
void TCP_Send(char * tcpcommand,char * tcpdata, char * tcpresponse1, char * tcpresponse2, char * tcpresponse3, int32_t tcptimeout);

void clear(void);
__inline void manualdelay(int delayms);
__inline void fileclose(void);  
__inline void fileopen(void);
__inline void parse_g(char* str, int first, int sec, char f, char s , char *string);
__inline void remove_all_chars(char* str, char c, char d);
__inline void manualdelay(int delayms);
__inline void strreplace(char s[], char chr, char repl_chr);

void cregquerry(void);
void cpinquerry(void);
void Save_FS(void);
void Send_FS(void);


/****************************************************************/

void SendAT(char * command, char * response1, char * response2, char * response3, int32_t timeout)
{
	static int attry;
	osDelay(100);
	osMutexWait(uart_mutex_id, osWaitForever);
	tmr0sec=0;
//	timeout =5;
	r1=0;
	r2=0;
	r3=0;
	g_u8RecDataptr=0;
	memset(g_u8RecData,0,RXBUFSIZE);
	printf("%c",0x1A);
	clear();
	printf(command);
//	send_string_to_uart1("\r\nAT\r\n");
	do{
		r1 = strstr(g_u8RecData, response1);
		r2 = strstr(g_u8RecData, response2);
		r3 = strstr(g_u8RecData, response3);
	}while(!(r1 || r2 || r3 ||((tmr0sec >= timeout))));	 //!(r1 || r2 || r3 ||

	 if(!(strstr(command, "QILOCIP") || strstr(command, "QGNSSC")))
	 {
		 if(!(r1 || r2 || r3))
			{
				PA13=1;
				attry++;
				if(attry > 3){
					printf("\r\n\r\nAT+CFUN=1,1\r\n\r\n");
					manualdelay(100);
					fileclose();
					fileopen();
					SendAT("\r\nAT+QGNSSC=1\r\n\r\n", "OK", "ERROR", "7103", 10);
				}
				PA13=0;
			}
			else{attry=0;}
	 }
	
	osMutexRelease(uart_mutex_id);
osDelay(10);
}

__inline void manualdelay(int delayms)
{
//	int delayus=0;
	int d1,d2;
	for(d1 = 0; d1 < delayms ; d1++)
	{
		for(d2=0; d2 < 65535; d2++)
		{
		}
	}
}

__inline void fileopen(void)
{
  if(strlen(fileinstance) == 0)
  {
    SendAT("\r\nAT+QFOPEN=\"LOG.TXT\",0\r\n", "Ready", "OK" , "ERROR",10);	
    if(strstr(g_u8RecData,"CME ERROR"))
    {
        PA13=1;
        printf("\r\n\r\nAT+CFUN=1,1\r\n\r\n");
        manualdelay(100);
        PA13=0;
        memset(fileinstance,0,20);
    SendAT("\r\nAT+QFOPEN=\"LOG.TXT\",0\r\n", "Ready", "OK" , "ERROR",10);	
    }
    parse_g(g_u8RecData, 1, 2, ' ', '\n' , fileinstance);
    remove_all_chars(fileinstance, '\r', '\n');   
    SendAT("\r\nAT+QGNSSC=1\r\n\r\n", "OK", "ERROR", "7103", 5);
  }
}

__inline void remove_all_chars(char* str, char c, char d) {
    char *pr = str, *pw = str;
    while (*pr) {
        *pw = *pr++;
			pw += (*pw != c && *pw != d && *pw != ' ' && *pw != '/' && *pw != ':');
    }
    *pw = '\0';
}



__inline void parse_g(char* str, int first, int sec, char f, char s , char *string)
{int sz1,sz2,i11,temp11,j11,l;

		sz1=	strlen(str);
		sz2=	strlen(string);
		memset(string,0,sz2);
		for(i11=0,temp11=0;i11<sz1;i11++)
		{
		if(str[i11]==s)
			{
        temp11++;
        j11=i11;
      }
		else{}
			
		if(temp11>=sec){i11=9900;}
		else{}	
		
		}	
		
		for(i11=0,temp11=0;i11<sz1;i11++)
		{
		if(str[i11]==f)
			{
        temp11++;l=i11;
      }										
		else{}
		if(temp11>=first){i11=9900;}else{}
		}	
		for(i11=0;i11<(j11-l-1);i11++)
		{
      string[i11] = str[l+i11+1];
		}
	
}


__inline void fileclose(void)
{
    memset(temp,0,100);
    sprintf(temp,"\r\nAT+QFCLOSE=%s\r\n\r\n",fileinstance);
    SendAT(temp, "+CME ERROR", "OK" , "ERROR",10);
    memset(fileinstance,0,20);
}


void clear()
{char dump = 0;
    while(!UART_GET_RX_EMPTY(UART1)) 
    {
      dump = UART_READ(UART1);
    }
}

void Send_FS(void)
{
  if(sendfs==1){
  TCP_Send_ch("\r\nAT+QISEND\r\n\r\n",g_u8SendData,">","ERROR","SEND OK",10);	
  }
}


void Save_FS(void)
{
  int len=0;
 	osMutexWait(uart_mutex_id, osWaitForever);
  fileopen();
  SendAT("\r\nAT+QFLDS=\"UFS\"\r\n", "Ready", "OK" , "ERROR",50);
	memset(temp,0,100);
	sprintf(temp,"\r\nAT+QFSEEK=%s,0,2\r\n",fileinstance);
	SendAT(temp, "CONNECT", "OK" , "ERROR",10);	  
  len = strlen(g_u8SendData);
  strcat(g_u8SendData,"\n\n\n\n\n");  
  len = strlen(g_u8SendData);

  strreplace(g_u8SendData, 0x1A, '\n');  
	memset(temp,0,100);
	sprintf(temp,"\r\nAT+QFWRITE=%s,%d,3\r\n",fileinstance,(len));
	SendAT(temp, "CONNECT", "OK" , "ERROR",10);	
  len = strlen(g_u8SendData);
  remove_all_chars(g_u8SendData,'\r',0x1A);
  SendAT_FS(g_u8SendData, "QWRITE", "OK" , "ERROR",20);	
  if(strstr(g_u8RecData,"+QFWRITE"))
  {
    memset(g_u8SendData,0,TXBUFSIZE);
  }
 
  fileclose();
	osMutexRelease(uart_mutex_id);
}

 void cpinquerry()
{
  int timeout;
	osDelay(100);  
  osMutexWait(uart_mutex_id, osWaitForever);
	tmr0sec=0;
	timeout =5;
	r1=0;
	r2=0;
	r3=0;
	g_u8RecDataptr=0;
	memset(g_u8RecData,0,RXBUFSIZE);
	printf("%c",0x1A);
	clear();
	printf("\r\nAT+CPIN?\r\n\r\n");
	do{
		r1 = strstr(g_u8RecData, "CPIN: READY");
		r2 = strstr(g_u8RecData, "OK");
		r3 = strstr(g_u8RecData, "ERROR");
			
	}while(!(r1 || r2 || r3 ||((tmr0sec >= timeout))));	 //!(r1 || r2 || r3 ||
 clear();
 
  if(r1)
  {
    cpinready=1;
  }
  else
  {
    cpinready=0;
  }

osMutexRelease(uart_mutex_id);
//osDelay(5);  
}

void cregquerry()
{
  int timeout;
  char cregresp[10];
	osDelay(100); 
  osMutexWait(uart_mutex_id, osWaitForever);
	tmr0sec=0;
	timeout =5;
	r1=0;
	r2=0;
	r3=0;
	g_u8RecDataptr=0;
	memset(g_u8RecData,0,RXBUFSIZE);
	printf("%c",0x1A);
	clear();
	printf("\r\nAT+CREG?\r\n\r\n");
	do{
		r1 = strstr(g_u8RecData, "CPIN: READY");
		r2 = strstr(g_u8RecData, "OK");
		r3 = strstr(g_u8RecData, "ERROR");
			
	}while(!(r1 || r2 || r3 ||((tmr0sec >= timeout))));	 //!(r1 || r2 || r3 ||
clear();
  memset(cregresp,0,10);
  parse_g(g_u8RecData, 1, 2, ',', '\n' , cregresp);
  if(strstr(cregresp,"1") || strstr(cregresp, "5"))
  {
    cregready=1;
  }
  else
  {
    cregready=0;
  }
  
  
  osMutexRelease(uart_mutex_id);
  osDelay(5);
 
}




void SendAT_FS(char * command, char * response1, char * response2, char * response3, int32_t timeout)
{
	osMutexWait(uart_mutex_id, osWaitForever);
	tmr0sec=0;
//	timeout =5;
	osDelay(100);
	r1=0;
	r2=0;
	r3=0;
	g_u8RecDataptr=0;
	memset(g_u8RecData,0,RXBUFSIZE);
//	printf("%c",0x1A);
	clear();
	printf(command);
	do{
		r1 = strstr(g_u8RecData, response1);
		r2 = strstr(g_u8RecData, response2);
		r3 = strstr(g_u8RecData, response3);
	}while(!(r1 || r2 || r3 ||((tmr0sec >= timeout))));	 //!(r1 || r2 || r3 ||
clear();
   if(!strstr(command, "QILOCIP"))
   {
     if(!(r1 || r2 || r3))
      {
        PA13=1;
        printf("\r\n\r\nAT+CFUN=1,1\r\n\r\n");
        manualdelay(100);
        fileclose();
        fileopen();
        SendAT("\r\nAT+QGNSSC=1\r\n\r\n", "OK", "ERROR", "7103", 10);

        PA13=0;
      }
   }
  
  osMutexRelease(uart_mutex_id);
osDelay(10);
}

__inline void strreplace(char s[], char chr, char repl_chr)
{
     int i=0;
     while(s[i]!='\0')
     {
           if(s[i]==chr)
           {
               s[i]=repl_chr;
           }  
           i++; 
     }
}

__inline int count_char(char ch,char* string)
{
int32_t	count=0;
int32_t ass=0;

	for(ass=0;ass<strlen(string);ass++)
	{
		if(string[ass] == ch)
		{count++;}
		
	}
return count;
}

__inline int8_t checkallnumsinstring(char* checkstring)
{
  int returnval, checkstringptr, lencheckstring=0;
  lencheckstring  = strlen(checkstring);
  for(checkstringptr  = 0 ; checkstringptr < lencheckstring ; checkstringptr++)
  {
    if((checkstring[checkstringptr]  > 47 ) && (checkstring[checkstringptr]  < 58 ))
    {returnval  = 0;}
    else
    {returnval  = 1;break;}
  }
  return returnval;
}


void TCP_Send_ch(char * tcpcommand,char * tcpdataq, char * tcpresponse1, char * tcpresponse2, char * tcpresponse3, int32_t tcptimeout)
{
  int tcpdatalength=0;
	int tcpdataptr=0;
	int times = 0;
	int timesptr=0;
	int tdp=0;
	int tdpend=600;
  char chdatalength[5];
  char tcpdata[600];
  int  cc =0;
  breaker = 0;
	osMutexWait(uart_mutex_id, osWaitForever);
//	osMutexWait(tcp_mutex_id, osWaitForever);
 	osDelay(500);
	printf("%c",0x1A);
	tmr0sec=0;
	tcptimeout =5;
	r1=0;
	r2=0;
	r3=0;
  SendAT("\r\nAT+QFLDs=\"UFS\"\r\n", "Ready", "OK" , "ERROR",50);
  
  memset(chdatalength,0,5);
  SendAT("\r\nAT+QFLST=\"LOG.TXT\"\r\n", "Ready", "OK" , "ERROR",50);
  parse_g(g_u8RecData, 1, 2, ',', '\n' , chdatalength);
	remove_all_chars(chdatalength, '\r', 0x1A);		
  tcpdatalength =  atoi(chdatalength);

  fileopen();

  if(tcpdatalength%600 == 0)
  {
    times = (tcpdatalength/600);
  }
  else
  {
    times = (tcpdatalength/600)+1;
  }  

  for(timesptr=0; timesptr<times ;timesptr++)
  {
	g_u8RecDataptr=0;

		if(tcpdatalength>15)
		{
      clear();
      SendAT_GPS_WO_MUTEX("\r\nAT+QGNSSRD=\"NMEA/RMC\"\r\n", "+MGPSSTATUS", "OK" , "ERROR",10);	
      memset(temp,0,100);
      sprintf(temp,"\r\nAT+QFSEEK=%s,%d\r\n\r\n",fileinstance,seeker);
      SendAT(temp, "+CME ERROR", "OK" , "ERROR",10);
      if(seeker > tcpdatalength)
      {
        seeker = 0;
        fileclose();
        SendAT("\r\nAT+QFDEL=\"LOG.TXT\"\r\n", "Ready", "OK" , "ERROR",10);
        breaker = 1;
        break;
      }
      if(strstr(g_u8RecData, "+CME ERROR")){breaker = 1;break;}
      memset(temp,0,100);
      clear();
      sprintf(temp,"\r\nAT+QFREAD=%s,600\r\n\r\n",fileinstance);
      SendAT(temp, "+CME ERROR", "OK" , "ERROR",10);
      clear();
      if(strstr(g_u8RecData, "+CME ERROR")){breaker = 1;break;}
      if(strlen(g_u8RecData) < 100){
        fileclose();
        SendAT("\r\nAT+QFDEL=\"LOG.TXT\"\r\n", "Ready", "OK" , "ERROR",10);
        breaker = 1;
        break;
      }
      
      memset(tcpdata,0,600);
      remove_all_chars(g_u8RecData, '\r', 0x1A);	
      cc=count_char('\n',g_u8RecData)-1;      
      parse_g(g_u8RecData, 2,cc, '\n', '\n' , tcpdata);  
      memset(temp,0,100);
			g_u8RecDataptr=0;
			tmr0sec=0;
			memset(g_u8RecData,0,RXBUFSIZE);
			printf(tcpcommand);
			do{
				r1 = strstr(g_u8RecData, tcpresponse1);
				r2 = strstr(g_u8RecData, tcpresponse2);
				r3 = strstr(g_u8RecData, tcpresponse3);
					
			}while(!(r1 || r2 || r3 ||((tmr0sec >= tcptimeout))));	 //!(r1 || r2 || r3 ||
    clear();
				tmr0sec=0;
				if(r1)
					{
						tmr0sec=0;
						tcptimeout =5;
						r1=0;
						r2=0;
						r3=0;
						g_u8RecDataptr=0;
						memset(g_u8RecData,0,RXBUFSIZE);
						clear();
//						printf(tcpdata);

 						tcpdataptr=0;
            tdpend=strlen(tcpdata);
           
						for(tdp=0;tdp<tdpend;tdp++)
						{
						SendChar(tcpdata[tdp]);
						tcpdataptr++;
            }
						printf("%c",0x1A);
						do{
							r1 = strstr(g_u8RecData, tcpresponse1);
							r2 = strstr(g_u8RecData, tcpresponse2);
							r3 = strstr(g_u8RecData, tcpresponse3);
						}while(!(r1 || r2 || r3 ||((tmr0sec >= tcptimeout))));
          }

			if(!(r3))
			{
				network=1;
        breaker = 1;        
				break;

			}
			else
			{
				network=0;
			}

    }
   
	if(network == 0 && timesptr>=times)
	{
//		memset(tcpdata,0,TXBUFSIZE);
	}
  seeker+=600;
		
	}
  
  fileclose();
  
  
  if(network == 0 && (timesptr>= times))
  {
  fileclose();
    
  seeker = 0;
  SendAT("\r\nAT+QFDEL=\"LOG.TXT\"\r\n", "Ready", "OK" , "ERROR",10);    

  }
	r1=0;
	r2=0;
	r3=0;
//	osMutexRelease(tcp_mutex_id);
	osMutexRelease(uart_mutex_id);

osDelay(10);

}

void TCP_Send(char * tcpcommand,char * tcpdata, char * tcpresponse1, char * tcpresponse2, char * tcpresponse3, int32_t tcptimeout)
{
	int tcpdatalength=0;
	int tcpdataptr=0;
	int times = 0;
	int timesptr=0;
	int tdp=0;
	int tdpend=600;
	osMutexWait(uart_mutex_id, osWaitForever);
//	osMutexWait(tcp_mutex_id, osWaitForever);
 	osDelay(100);

	tmr0sec=0;
	tcptimeout =5;
	r1=0;
	r2=0;
	r3=0;

 
//	memset(g_u8RecData,0,RXBUFSIZE);
	g_u8RecDataptr=0;
	printf("%c",0x1A);
	tcpdatalength = strlen(tcpdata);
	if(tcpdatalength%600 == 0)
	{
		times = (tcpdatalength/600);
	}
	else
		{
			times = (tcpdatalength/600)+1;
		}
		if(tcpdatalength>15)
		{
			clear();
			for(timesptr = 0; timesptr < times ; timesptr++)
			{
			g_u8RecDataptr=0;
			tmr0sec=0;
			memset(g_u8RecData,0,RXBUFSIZE);
			printf(tcpcommand);
			do{
				r1 = strstr(g_u8RecData, tcpresponse1);
				r2 = strstr(g_u8RecData, tcpresponse2);
				r3 = strstr(g_u8RecData, tcpresponse3);
					
			}while(!(r1 || r2 || r3 ||((tmr0sec >= tcptimeout))));	 //!(r1 || r2 || r3 ||
clear();

				tmr0sec=0;
				if(r1)
					{
						tmr0sec=0;
						tcptimeout =5;
						r1=0;
						r2=0;
						r3=0;
						g_u8RecDataptr=0;
						memset(g_u8RecData,0,RXBUFSIZE);
						clear();
//						printf(tcpdata);
						if(timesptr == (times-1))
						{
							tdpend = tcpdatalength%600;
						}
						for(tdp=0;tdp<tdpend;tdp++)
						{
						SendChar(tcpdata[tcpdataptr]);
						tcpdataptr++;}
						printf("%c",0x1A);
						do{
							r1 = strstr(g_u8RecData, tcpresponse1);
							r2 = strstr(g_u8RecData, tcpresponse2);
							r3 = strstr(g_u8RecData, tcpresponse3);
						}while(!(r1 || r2 || r3 ||((tmr0sec >= tcptimeout))));

           clear();
            
          }

			if(!(r3))
			{
				network=1;
				break;
			}
			else
			{
				network=0;
			}
		}

   
	if(network == 0 && timesptr>=times)
	{
		memset(g_u8SendData,0,TXBUFSIZE);
    Send_FS();
      sendfs=1;
 	}
  else{
    sendfs=0;
  }
		
	}


//osMutexRelease(tcp_mutex_id);
osMutexRelease(uart_mutex_id);    

osDelay(5);

}



void SendAT_GPS(char * command, char * response1, char * response2, char * response3, int32_t timeout)
{

  SendAT("\r\nAT+QGNSSC=1\r\n\r\n", "OK", "OK" , "ERROR",5);	

	osDelay(100);
	osMutexWait(uart_mutex_id, osWaitForever);
  
	tmr0sec=0;
	r1=0;
	r2=0;
	r3=0;
	g_u8RecDataptr=0;
	memset(g_u8RecData,0,RXBUFSIZE);
//	printf("%c",0x1A);
	clear();
	if(checkallnumsinstring(imei) ||  (strlen(imei) < 5))
	{
		printf("\r\n\r\nAT+GSN\r\n\r\n");
		do{
			r1 = strstr(g_u8RecData, response1);
			r2 = strstr(g_u8RecData, response2);
			r3 = strstr(g_u8RecData, response3);
		}while(!(r1 || r2 || r3 || ((tmr0sec >= timeout))));	 //!(r1 || r2 || r3 ||
		memset(imei,0,25);
		imeiptr0=0;
		for(imeiptr=0;imeiptr<strlen(g_u8RecData);imeiptr++)
		{
			if((g_u8RecData[imeiptr]>47)	&& (g_u8RecData[imeiptr]<58))
			{
				imei[imeiptr0] = g_u8RecData[imeiptr];
				imeiptr0++;
      }
		}
	remove_all_chars(imei, '\r', 0x1a);		
	}
	tmr0sec=0;
	r1=0;
	r2=0;
	r3=0;
	g_u8RecDataptr=0;
	memset(g_u8RecData,0,RXBUFSIZE);
//	printf("%c",0x1A);
  clear();

	printf(command);
	do{
		r1 = strstr(g_u8RecData, response1);
		r2 = strstr(g_u8RecData, response2);
		r3 = strstr(g_u8RecData, response3);
	}while(!(r1 || r2 || r3 || ((tmr0sec >= timeout))));	 //!(r1 || r2 || r3 ||
  clear();
	if(strstr(g_u8RecData,"GNRMC"))
	{
    u32ADC0Result = 3;
    ADC_START_CONV(ADC);
    u32ADC0Result = ADC_GET_CONVERSION_DATA(ADC, 0);
    u32ADC0Result = (3.943/2.097)*((u32ADC0Result*3.312) /4096);
    
		memset(temp,0,100);
		parse_g(g_u8RecData, 2, 10, 'C', ',' , temp);
		strcat(g_u8SendData,imei);
		strcat(g_u8SendData,",");
		strcat(g_u8SendData,temp);
		memset(temp,0,100);
		sprintf(temp,",F=%.1f",u32ADC0Result);
		strcat(g_u8SendData,temp);
				memset(temp,0,100);
		sprintf(temp,",LIFE=%d\n",life);
		strcat(g_u8SendData,temp);
  }
  if((strlen(g_u8SendData) > 2900))
  {
    memset(g_u8SendData,0,TXBUFSIZE);
    strcat(g_u8SendData,imei);
    strcat(g_u8SendData,"error:RAMfull\n");
  }
  

	osMutexRelease(uart_mutex_id);
	osDelay(5);
}

void SendAT_GPS_WO_MUTEX(char * command, char * response1, char * response2, char * response3, int32_t timeout)
{
//	osMutexWait(uart_mutex_id, osWaitForever);
	osDelay(500);
	tmr0sec=0;
	r1=0;
	r2=0;
	r3=0;
	g_u8RecDataptr=0;
	memset(g_u8RecData,0,RXBUFSIZE);
	printf("%c",0x1A);
	clear();
	if(checkallnumsinstring(imei) ||  (strlen(imei) < 5))
	{
		printf("\r\nAT+GSN\r\n");
		do{
			r1 = strstr(g_u8RecData, response1);
			r2 = strstr(g_u8RecData, response2);
			r3 = strstr(g_u8RecData, response3);
		}while(!(r1 || r2 || r3 || ((tmr0sec >= timeout))));	 //!(r1 || r2 || r3 ||
		memset(imei,0,25);
		imeiptr0=0;
		for(imeiptr=0;imeiptr<strlen(g_u8RecData);imeiptr++)
		{
			if((g_u8RecData[imeiptr]>47)	&& (g_u8RecData[imeiptr]<58))
			{
				imei[imeiptr0] = g_u8RecData[imeiptr];
				imeiptr0++;
      }
		}
	remove_all_chars(imei, '\r', 0x1a);		
	}
	tmr0sec=0;
	r1=0;
	r2=0;
	r3=0;
	g_u8RecDataptr=0;
	memset(g_u8RecData,0,RXBUFSIZE);
	clear();
	printf("%c",0x1A);
	printf(command);
	do{
		r1 = strstr(g_u8RecData, response1);
		r2 = strstr(g_u8RecData, response2);
		r3 = strstr(g_u8RecData, response3);
	}while(!(r1 || r2 || r3 || ((tmr0sec >= timeout))));	 //!(r1 || r2 || r3 ||
	if(strstr(g_u8RecData,"GNRMC"))
	{
    u32ADC0Result = 3;
    ADC_START_CONV(ADC);
    u32ADC0Result = ADC_GET_CONVERSION_DATA(ADC, 0);
    u32ADC0Result = (3.943/2.097)*((u32ADC0Result*3.312) /4096);
    
		memset(temp,0,100);
		parse_g(g_u8RecData, 2, 10, 'C', ',' , temp);
		strcat(g_u8SendData,imei);
		strcat(g_u8SendData,",");
		strcat(g_u8SendData,temp);
		memset(temp,0,100);
		sprintf(temp,",F=%.1f",u32ADC0Result);
		strcat(g_u8SendData,temp);
		memset(temp,0,100);
		sprintf(temp,",LIFE=%d\n",life);
		strcat(g_u8SendData,temp);
  }
  if((strlen(g_u8SendData) > 2900))
  {
    memset(g_u8SendData,0,TXBUFSIZE);
    strcat(g_u8SendData,imei);
    strcat(g_u8SendData,"error:RAMfull\n");
  }

//	osMutexRelease(uart_mutex_id);
//	osDelay(1);
}








