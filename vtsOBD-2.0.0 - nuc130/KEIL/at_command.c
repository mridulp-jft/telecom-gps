#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "NUC100Series.h"
#define osObjectsPublic										 // define objects in main module
#include "osObjects.h"											// RTOS object definitions
#include "uart.h"
#include "cmsis_os.h"							 // CMSIS RTOS header file

#include "WinboundFlash.h"

#define header              "HEADER"
#define vendorID            "JFT"
#define firmwareversion     "2.1.0"

/*	Extern Variables
*****************************************************************/
extern char g_u8SendData[TXBUFSIZE];
extern char g_u8RecData[RXBUFSIZE];
extern	int32_t life;
extern void SendChar(int ch);
extern void send_OBD(char * command, char * response1, char * response2, char * response3, int32_t timeout);


char SrcArray[257];char DestArray[257];

uint8_t g_u8DeviceAddr = 0x1E;
uint32_t u32Status;
uint8_t g_au8TxData[1];
uint8_t g_u8RxData;
uint8_t g_u8DataLen = 0;
uint8_t sendfs=0;
volatile uint8_t g_u8EndFlag = 0;
extern void Open_SPI_Flash(void);
extern unsigned int SpiFlash_ReadMidDid(void);
uint32_t readpt = 256;
extern int once;
extern uint32_t pt;



/****************************************************************/
extern char obdresp[20];
extern char tempobdresp[20];
extern char obdrespbinary[33];
extern char suppportedpid[100][7];
extern int pidcounter;
extern char g_u8OBDRecData[OBDRXBUFSIZE];

extern char vehicleregnum[15];
char signalquality[5] = {0};


/** Packet*****************************************/
  int tcpsendchtimer;
  int powerstatus = 0;
  int ignition = 0;
  int fix = 0;
  int emergencystatus = 0;
  char tamperalert = 'C';
  float ext_bat, int_bat, lati, longi, speed;
  float batteryvoltage = 0;
  float inputvoltage = 0;
  char latitude[12] = 0;
  char longitude[12] = 0;
  char gpsdate[7] = 0;
  char gpstime[7] = 0;
  char kmph[6] = 0;
  char heading[8] = 0;
  char alt[8] = 0;
  char sat[2] = 0;
  char latdir[2] = 0;
  char longdir[2] = 0;
  char hdop[6] = 0;
  char pdop[5] = 0;
  char networkoperator[30] = 0;
  char mcc[5] = 0;
  char mnc[5] = 0;
  char lac[5] = 0;
  char cellid[10] = 0;
  char packetstatus = 'L';
  char nmr[200] = 0;
  



/*	Global Variables
*****************************************************************/
int32_t	inc=0;
int stlen;
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
int8_t  network;
int breaker=0;
int seeker = 0;
int imeiptr0=0;
char imei[25];
int imeiptr=0;
	int tcpdatalength=0;
	int32_t tcpdataptr=0;
	int times = 0;
	int timesptr=0;
	int tdp=0;
  int read_obd = 0 ;
	int tdpend=300;
/****************************************************************/
//extern osMutexDef (uart_mutex);		// Declare mutex
extern osMutexId	(uart_mutex_id); // Mutex ID
		
//extern osMutexDef (tcp_mutex);		// Declare mutex
extern osMutexId	(tcp_mutex_id); // Mutex ID

//extern osMutexDef (fs_mutex);		// Declare mutex
extern osMutexId	(fs_mutex_id); // Mutex ID		


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
char *response1;
char *response2;
char *response3;

/****************************************************************/



void SendAT(char * command, char * res1, char * res2, char * res3, int32_t timeout)
{
  static int attry;
  response1 = res1;
  response2 = res2;
  response3 = res3;

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
	do{
    g_u8RecData[0] = '\r';
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
            printf("\r\nAT+CFUN=1,1\r\n");	
        }
        PA13=0;
      }
      else{attry=0;}
   }

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
char mystrstr(char* str1, char character)
{int sz,cn;
  sz=strlen(str1);
	for(cn=0;cn<=sz;cn++)
	{if(str1[cn] == character)
		{return 1;}
	}
	return 0;
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


void parse_g(char* str, int first, int sec, char f, char s , char *string)
{int sz1,sz2,i11,temp11,j11,l;
    if(mystrstr(str,f) && mystrstr(str,s))
    {  

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

__inline void Send_FS(void)
{
  if(sendfs==1){
  TCP_Send_ch("\r\nAT+QISEND\r\n\r\n",g_u8SendData,">","ERROR","SEND OK",5);	
  }
}


void Save_FS(void)
{ char * pch = 0;
  int i,j;
  int len=0;
  strcat(g_u8SendData,"\n");
  pch = strstr (g_u8SendData,",L,");
  if (pch){
    strncpy(pch,",H,",3);
  }
  strreplace(g_u8SendData, 0x1A, '\n'); 
  remove_all_chars(g_u8SendData,'\r',0x1A);
  SpiFlash_WaitReady();
  //testing
//  memset(SrcArray,0,256);
  remove_all_chars(g_u8SendData,'\n','\n'); 
  strcat(g_u8SendData, "S**************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************E\n");
  life = strlen(g_u8SendData); 
  times = life/256 + 1;
  j = 0;
  while(times > 0){
    //slicing string
    memset(SrcArray,0,257);
    for(i=0;i<256;i++){
      SrcArray[i] = g_u8SendData[j];
      j++;
    }
    manualdelay(25);
    SpiFlash_PageProgram(SrcArray, pt, 256);
    //checking
    memset(DestArray,0,257);
    //SpiFlash_WaitReady();
    SpiFlash_ReadData(DestArray, pt, 256);
    times--; 
    pt+=256;
  }
  memset(g_u8SendData,0,TXBUFSIZE);
}

 void cpinquerry()
{
  int timeout;
	//osDelay(100);  
  //osMutexWait(uart_mutex_id, osWaitForever);
	tmr0sec=0;
	timeout =10;
	r1=0;
	r2=0;
	r3=0;
	g_u8RecDataptr=0;
	memset(g_u8RecData,0,RXBUFSIZE);
	printf("%c",0x1A);
	clear();
	printf("\r\nAT+CPIN?\r\n\r\n");
	do{
    g_u8RecData[0] = '\r';
		r1 = strstr(g_u8RecData, "NOT READY");
		r2 = strstr(g_u8RecData, "OK");
		r3 = strstr(g_u8RecData, "ERROR");
			
	}while(!(r1 || r2 || r3 ||((tmr0sec >= timeout))));	 //!(r1 || r2 || r3 ||
  clear();
 
  if(!strstr(g_u8RecData, "NOT READY"))
  {
    cpinready=1;
  }
  else
  {
    cpinready=0;
  } 
}

void cregquerry()
{
  int timeout;
  char cregresp[10];
	//osDelay(100); 
  //osMutexWait(uart_mutex_id, osWaitForever);
	tmr0sec=0;
	timeout =10;
	r1=0;r2=0;r3=0;
	g_u8RecDataptr=0;
	memset(g_u8RecData,0,RXBUFSIZE);
	printf("%c",0x1A);
	clear();
	printf("\r\nAT+CREG?\r\n\r\n");
	do{
    g_u8RecData[0] = '\r';
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
 
}




void SendAT_FS(char * command, char * response1, char * response2, char * response3, int32_t timeout)
{
	tmr0sec=0;
//	timeout =5;
	//osDelay(100);
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
  
//osDelay(10);
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
  int outfromloop = 0;
  int tcpdatalength=0;
	int tcpdataptr=0;
	int times = 0;
	int timesptr=0;
	int tdp=0;
	int tdpend=300;
  char chdatalength[5];
  char tcpdata[300];
  int  cc =0;
  breaker = 0;
	PB2=0;
	printf("%c",0x1A);
  tcpsendchtimer = 0;

do{
  memset(tcpdata,0,300);
  //SpiFlash_WaitReady();
  SpiFlash_ReadData(tcpdata, readpt, 256);
  if(tcpdata[0] != 0xFF && tcpdata[0] != '\0')
    times = 1;
  else{
    SpiFlash_ChipErase();
    times = 0;
    pt = 0;
    readpt = 0;
    readpt = 0;
    pt = 0;    
    //once = 1;
  }
  if(times == 1){
      clear();
      //memset(temp,0,100);
      tmr0sec=0;
      tcptimeout =5;
      r1=0;
      r2=0;
      r3=0;
			g_u8RecDataptr=0;
			tmr0sec=0;
			memset(g_u8RecData,0,RXBUFSIZE);
			printf("\r\nAT+QISEND=0\r\n\r\n\r\n");
			do{
        g_u8RecData[0] = '\r';
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
 						tcpdataptr=0;
            tdpend=strlen(tcpdata);
   
						for(tdp=0;tdp<tdpend;tdp++)
						{
              SendChar(tcpdata[tdp]);
              tcpdataptr++;
            }
						printf("%c",0x1A);
						do{
              g_u8RecData[0] = '\r';
							r1 = strstr(g_u8RecData, tcpresponse1);
							r2 = strstr(g_u8RecData, tcpresponse2);
							r3 = strstr(g_u8RecData, tcpresponse3);
						}while(!(r1 || r2 || r3 ||((tmr0sec >= tcptimeout))));
          }

			if(!(r3)){
				network=1;
        breaker = 1;        
				break;
			}else{
        breaker = 0;
				network=0;
			}
      
      if(network == 0){    
        
        clear();
        tmr0sec=0;
        tcptimeout =5;
        r1=0;
        r2=0;
        r3=0;
        g_u8RecDataptr=0;
        tmr0sec=0;
        memset(g_u8RecData,0,RXBUFSIZE);
        printf("\r\nAT+QISEND=1\r\n\r\n\r\n");
        do{
          g_u8RecData[0] = '\r';
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
              tcpdataptr=0;
              tdpend=strlen(tcpdata);
     
              for(tdp=0;tdp<tdpend;tdp++)
              {
                SendChar(tcpdata[tdp]);
                tcpdataptr++;
              }
              printf("%c",0x1A);
              do{
                g_u8RecData[0] = '\r';
                r1 = strstr(g_u8RecData, tcpresponse1);
                r2 = strstr(g_u8RecData, tcpresponse2);
                r3 = strstr(g_u8RecData, tcpresponse3);
              }while(!(r1 || r2 || r3 ||((tmr0sec >= tcptimeout))));
            }

        if(!(r3)){
          network=1;
          breaker = 1;        
          break;
        }else{
          breaker = 0;
          readpt+=256;
          network=0;
        }
      }
      if(tcpsendchtimer > 4){
        breaker = 1;
        break;
      }else breaker = 0;
    
    }
  outfromloop = 1;
  }while(times == 1);

}



void TCP_Send(char * tcpcommand,char * tcpdata, char * tcpresponse1, char * tcpresponse2, char * tcpresponse3, int32_t tcptimeout)
{
	int tcpdatalength=0;
	int tcpdataptr=0;
	int times = 0;
	int timesptr=0;
	int tdp=0;
	int tdpend=600;

	tmr0sec=0;
	tcptimeout =5;
	r1=0;
	r2=0;
	r3=0;
	g_u8RecDataptr=0;
	printf("%c",0x1A);
	tcpdatalength = strlen(tcpdata);
		if(tcpdatalength>15)
		{
			clear();
			g_u8RecDataptr=0;
			tmr0sec=0;
			memset(g_u8RecData,0,RXBUFSIZE);
			printf("\r\nAT+QISEND=0\r\n\r\n\r\n");
			do{
        g_u8RecData[0] = '\r';
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
						for(tdp=0;tdp<tcpdatalength;tdp++){
						SendChar(tcpdata[tcpdataptr]);
						tcpdataptr++;
            }
						printf("%c",0x1A);
						do{
              g_u8RecData[0] = '\r';
							r1 = strstr(g_u8RecData, tcpresponse1);
							r2 = strstr(g_u8RecData, tcpresponse2);
							r3 = strstr(g_u8RecData, tcpresponse3);
						}while(!(r1 || r2 || r3 ||((tmr0sec >= tcptimeout))));
           clear();            
          }
			if(!(r3)){
				network=1;
        sendfs = 0;
			}
			else{
				network=0;
        sendfs = 1;        
			}
	}else{network = 1;sendfs = 0;} 
/***********************************************************************************************************************************************/  
  tcpdatalength=0;
  tcpdataptr=0;
  times = 0;
  timesptr=0;
  tdp=0;
  tdpend=600;  
/***********************************************************************************************************************************************/  
  if(network == 0){  
    tmr0sec=0;
    tcptimeout =5;
    r1=0;
    r2=0;
    r3=0;
    g_u8RecDataptr=0;
    printf("%c",0x1A);
    tcpdatalength = strlen(tcpdata);
      if(tcpdatalength>15)
      {
        clear();
        g_u8RecDataptr=0;
        tmr0sec=0;
        memset(g_u8RecData,0,RXBUFSIZE);
        printf("\r\nAT+QISEND=1\r\n\r\n\r\n");
        do{
          g_u8RecData[0] = '\r';
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
              for(tdp=0;tdp<tcpdatalength;tdp++){
              SendChar(tcpdata[tcpdataptr]);
              tcpdataptr++;
              }
              printf("%c",0x1A);
              do{
                g_u8RecData[0] = '\r';
                r1 = strstr(g_u8RecData, tcpresponse1);
                r2 = strstr(g_u8RecData, tcpresponse2);
                r3 = strstr(g_u8RecData, tcpresponse3);
              }while(!(r1 || r2 || r3 ||((tmr0sec >= tcptimeout))));
             clear();           
            }
        if(!(r3)){
          network=1;
          sendfs = 0;
        }
        else{
          network=0;
          sendfs = 1;
        }
    if(network == 0 && timesptr>=times){
      memset(g_u8SendData,0,TXBUFSIZE);
      sendfs=1;
    }
    else{
      sendfs=0;
    }
    }else{network = 1; sendfs = 1;}
  }
  
  if(sendfs == 1){
    memset(tcpdata,0,300);
    //SpiFlash_WaitReady();
    SpiFlash_ReadData(tcpdata, readpt, 256);
    if(tcpdata[0] != 0xFF)
      sendfs = 1;
    else
      sendfs = 0;
  }

}





void SendAT_GPS_WO_MUTEX(char * command, char * response1, char * response2, char * response3, int32_t timeout)
{
//	osMutexWait(uart_mutex_id, osWaitForever);
	//osDelay(500);
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

}


















void SendAT_GPS(char * command, char * response1, char * response2, char * response3, int32_t timeout)
{
  powerstatus = 0;
  ignition = 0;
  fix = 0;
  emergencystatus = 0;
  tamperalert = 'C';
  ext_bat, int_bat, lati, longi, speed;
  batteryvoltage = 0;
  inputvoltage = 0;
  latitude[12] = 0;
  longitude[12] = 0;
  gpsdate[7] = 0;
  gpstime[7] = 0;
  kmph[6] = 0;
  heading[8] = 0;
  alt[8] = 0;
  sat[2] = 0;
  latdir[2] = 0;
  longdir[2] = 0;
  hdop[6] = 0;
  pdop[5] = 0;
  networkoperator[30] = 0;
  mcc[5] = 0;
  mnc[5] = 0;
  lac[5] = 0;
  cellid[10] = 0;
  packetstatus = 'L';
  nmr[200] = 0;  

//  void SendAT_GPS(char * command, char * response1, char * response2, char * response3, int32_t timeout)
#ifndef OBD

	//osMutexWait(uart_mutex_id, osWaitForever);  
  SendAT("\r\nAT+QGNSSC=1\r\n\r\n", "OK", "ERROR: 7103" , "OK",5);
  clear();
  //manualdelay(100);

  SendAT("\r\nAT+CSQ\r\n\r\n", "Ready", "OK" , "ERROR",4);	
  parse_g(g_u8RecData, 1, 1, ' ', ',' , signalquality);	

	tmr0sec=0;
	r1=0;
	r2=0;
	r3=0;
	g_u8RecDataptr=0;
 	clear();
	memset(g_u8RecData,0,RXBUFSIZE);
  printf("\r\n\r\nAT+GSN\r\n\r\n");
  do{
    g_u8RecData[0] = '\r';
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
	
	tmr0sec=0;
	r1=0;
	r2=0;
	r3=0;
	g_u8RecDataptr=0;
	memset(g_u8RecData,0,RXBUFSIZE);
  clear();

	printf("\r\n\r\nAT+QGNSSRD =\"NMEA/RMC\"\r\n\r\n\r\n");
	do{
    g_u8RecData[0] = '\r';
		r1 = strstr(g_u8RecData, response1);
		r2 = strstr(g_u8RecData, response2);
		r3 = strstr(g_u8RecData, response3);
	}while(!(r1 || r2 || r3 || ((tmr0sec >= timeout))));	 //!(r1 || r2 || r3 ||
  clear();
	if(strstr(g_u8RecData,"GNRMC"))
  {  
    memset(temp, 0, 100);
    parse_g(g_u8RecData, 1, 1, '$', '*' , temp);
    parse_g(temp, 1, 1, ',', '.' , gpstime);
    parse_g(temp, 3, 4, ',', ',' , latitude);
    parse_g(temp, 4, 5, ',', ',' , latdir);
    parse_g(temp, 5, 6, ',', ',' , longitude);
    parse_g(temp, 6, 7, ',', ',' , longdir);
    parse_g(temp, 8, 9, ',', ',' , heading);
    parse_g(temp, 9, 10, ',', ',' , gpsdate);
    if(latitude != '\0')
      fix = 1;
    else
      fix = 0;
      
    tmr0sec=0;
    r1=0;
    r2=0;
    r3=0;
    g_u8RecDataptr=0;
    memset(g_u8RecData,0,RXBUFSIZE);
    clear();
    printf("\r\n\r\nAT+QGNSSRD=\"NMEA/GGA\"\r\n\r\n\r\n");
    do{
      g_u8RecData[0] = '\r';
      r1 = strstr(g_u8RecData, response1);
      r2 = strstr(g_u8RecData, response2);
      r3 = strstr(g_u8RecData, response3);
    }while(!(r1 || r2 || r3 || ((tmr0sec >= timeout))));	 //!(r1 || r2 || r3 ||
    clear();  

    memset(temp, 0, 100);
    parse_g(g_u8RecData, 1, 1, '$', '*' , temp);
    parse_g(temp, 7, 8, ',', ',' , sat);
    parse_g(temp, 8, 9, ',', ',' , hdop);
    parse_g(temp, 9, 10, ',', ',' , alt);
    
    tmr0sec=0;
    r1=0;
    r2=0;
    r3=0;
    g_u8RecDataptr=0;
    memset(g_u8RecData,0,RXBUFSIZE);
    clear();

    printf("\r\n\r\nAT+QGNSSRD=\"NMEA/VTG\"\r\n\r\n\r\n");
    do{
      g_u8RecData[0] = '\r';
      r1 = strstr(g_u8RecData, response1);
      r2 = strstr(g_u8RecData, response2);
      r3 = strstr(g_u8RecData, response3);
    }while(!(r1 || r2 || r3 || ((tmr0sec >= timeout))));	 //!(r1 || r2 || r3 ||
    clear();  

    memset(temp, 0, 100);
    parse_g(g_u8RecData, 1, 1, '$', '*' , temp);
    parse_g(temp, 7, 8, ',', ',' , kmph);
 
    tmr0sec=0;
    r1=0;
    r2=0;
    r3=0;
    g_u8RecDataptr=0;
    memset(g_u8RecData,0,RXBUFSIZE);
    clear();

    printf("\r\n\r\nAT+QGNSSRD=\"NMEA/GSA\"\r\n\r\n\r\n");
    do{
      g_u8RecData[0] = '\r';
      r1 = strstr(g_u8RecData, response1);
      r2 = strstr(g_u8RecData, response2);
      r3 = strstr(g_u8RecData, response3);
    }while(!(r1 || r2 || r3 || ((tmr0sec >= timeout))));	 //!(r1 || r2 || r3 ||
    clear();  

    memset(temp, 0, 100);
    parse_g(g_u8RecData, 1, 1, '$', '*' , temp);
    parse_g(temp, 15, 16, ',', ',' , pdop);  

    tmr0sec=0;
    r1=0;
    r2=0;
    r3=0;
    g_u8RecDataptr=0;
    memset(g_u8RecData,0,RXBUFSIZE);
    clear();
    printf("\r\n\r\nAT+COPS=0,1,0\r\n\r\n\r\n");
    do{
      g_u8RecData[0] = '\r';
      r1 = strstr(g_u8RecData, response1);
      r2 = strstr(g_u8RecData, response2);
      r3 = strstr(g_u8RecData, response3);
    }while(!(r1 || r2 || r3 || ((tmr0sec >= timeout))));	 //!(r1 || r2 || r3 ||
    clear();  
   
    tmr0sec=0;
    r1=0;
    r2=0;
    r3=0;
    g_u8RecDataptr=0;
    memset(g_u8RecData,0,RXBUFSIZE);
    clear();
    printf("\r\n\r\nAT+COPS?\r\n\r\n\r\n");
    do{
      g_u8RecData[0] = '\r';
      r1 = strstr(g_u8RecData, response1);
      r2 = strstr(g_u8RecData, response2);
      r3 = strstr(g_u8RecData, response3);
    }while(!(r1 || r2 || r3 || ((tmr0sec >= timeout))));	 //!(r1 || r2 || r3 ||
    clear();  

    parse_g(g_u8RecData, 1,2, '"', '"' , networkoperator);  
    tmr0sec=0;
    r1=0;
    r2=0;
    r3=0;
    g_u8RecDataptr=0;
    memset(g_u8RecData,0,RXBUFSIZE);
    clear();

    printf("\r\n\r\nAT+QENG = 2,3\r\n\r\n\r\n");
    do{
      g_u8RecData[0] = '\r';
      r1 = strstr(g_u8RecData, "NULL");
      r2 = strstr(g_u8RecData, "NULL");
      r3 = strstr(g_u8RecData, "+QENG: 2");
    }while(!(r1 || r2 || r3 || ((tmr0sec >= timeout))));	 //!(r1 || r2 || r3 ||
    clear();  
    
    memset(mcc,0,strlen(mcc));
    memset(mnc,0,strlen(mnc));
    memset(lac,0,strlen(lac));
    memset(cellid,0,strlen(cellid));
    memset(nmr,0,200);
    parse_g(g_u8RecData, 2, 3, ',', ',' , mcc);
    parse_g(g_u8RecData, 3, 4, ',', ',' , mnc);
    parse_g(g_u8RecData, 4, 5, ',', ',' , lac);
    parse_g(g_u8RecData, 5, 6, ',', ',' , cellid);
    parse_g(g_u8RecData, 20, 60, ',', ',' , nmr);
   
    /*  
      1,782,-94,56,31,7,404,04,1f5,a25b,2,743,-95,18,26,2,404,04,1f5,a25a,3,780,-102,29,-3,-1000,404,04,090,a715,4,x,x,x,x,x,x,x,x,x,
    */

    tmr0sec=0;
    r1=0;
    r2=0;
    r3=0;
    g_u8RecDataptr=0;
    memset(g_u8RecData,0,RXBUFSIZE);
    clear();    
    printf("\r\n\r\nAT+QENG = 0\r\n\r\n\r\n");
    do{
      g_u8RecData[0] = '\r';
      r1 = strstr(g_u8RecData, "OK");
      r2 = strstr(g_u8RecData, "ERROR");
      r3 = strstr(g_u8RecData, "ËRROR");
    }while(!(r1 || r2 || r3 || ((tmr0sec >= timeout))));	 //!(r1 || r2 || r3 ||
    clear();  
        
    packetstatus = 'L';
    u32ADC0Result = 3;
    ADC_START_CONV(ADC);
    u32ADC0Result = ADC_GET_CONVERSION_DATA(ADC, 0);
    u32ADC0Result = (3.943/2.097)*((u32ADC0Result*3.312) /4096);
    batteryvoltage = u32ADC0Result;

    // Live Data packet
    
    sprintf(g_u8SendData, "$%s,%s,%s,NR,%c,%s,%s,%d,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%d,%d,%.1f,%.1f,%d,%c,%s,%s,%s,%s,%s,%s\n"\
    ,header, vendorID, firmwareversion, packetstatus, imei,vehicleregnum,fix,gpsdate,\
    gpstime,latitude,latdir,longitude,longdir,kmph,heading,sat,alt,pdop,hdop,networkoperator,\
    ignition,powerstatus,inputvoltage,batteryvoltage,emergencystatus,tamperalert,signalquality,\
    mcc, mnc, lac, cellid, nmr);
  
    }
    if((strlen(g_u8SendData) > 2900))
    {
      memset(g_u8SendData,0,TXBUFSIZE);
      strcat(g_u8SendData,imei);
      strcat(g_u8SendData,"error:RAMfull\n");
    }
    osDelay(5);
  #endif
  #ifdef OBD

    SendAT("\r\nAT+QGNSSC=1\r\n\r\n", "OK", "OK" , "ERROR",5);	

    tmr0sec=0;
    r1=0;
    r2=0;
    r3=0;
    g_u8RecDataptr=0;
    memset(g_u8RecData,0,RXBUFSIZE);
    clear();
    if(checkallnumsinstring(imei) ||  (strlen(imei) < 5)||  (strlen(imei) > 16))
    {
      printf("\r\n\r\nAT+GSN\r\n\r\n");
      do{
        g_u8RecData[0] = '\r';
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

    printf(command);
    do{
      g_u8RecData[0] = '\r';
      r1 = strstr(g_u8RecData, response1);
      r2 = strstr(g_u8RecData, response2);
      r3 = strstr(g_u8RecData, response3);
    }while(!(r1 || r2 || r3 || ((tmr0sec >= timeout))));	 //!(r1 || r2 || r3 ||
    clear();
    if(strstr(g_u8RecData,"GNRMC"))
    {
      memset(g_u8SendData,0,TXBUFSIZE);
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
    }
    stlen = strlen(g_u8SendData);
    if((strlen(g_u8SendData) > 2900))
    {
      memset(g_u8SendData,0,TXBUFSIZE);
      strcat(g_u8SendData,imei);
      strcat(g_u8SendData,"error:RAMfull\n");
    }

    //osMutexRelease(uart_mutex_id);  
  #endif
}