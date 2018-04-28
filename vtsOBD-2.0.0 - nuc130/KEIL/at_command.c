#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "NUC100Series.h"
#define osObjectsPublic										 // define objects in main module
#include "osObjects.h"											// RTOS object definitions
#include "uart.h"
#include "cmsis_os.h"							 // CMSIS RTOS header file

#include "WinboundFlash.h"
#include "preprocessor.h"
#include <math.h>

#define pi 3.14159265358979323846
//#define header              "HEADER"
//#define vendorID            "JFT"
//#define firmwareversion     "2.1.0"
//#define frameformat         "1.0.0"    
/*	Extern Variables
*****************************************************************/
extern char g_u8SendData[TXBUFSIZE];
extern char g_u8RecData[RXBUFSIZE];
extern	int32_t life;
extern void SendChar(int ch);
extern void send_OBD(char * command, char * response1, char * response2, char * response3, int32_t timeout);
extern volatile int interval_count_health;
volatile int sleepinterval_health=2;
volatile int wakeinterval_emer;
char SrcArray[257];
char DestArray[257];
extern char configdata[300];
uint8_t sendfs=0;
extern void Open_SPI_Flash(void);
extern unsigned int SpiFlash_ReadMidDid(void);
float readpt = 256;
extern int once;
extern float pt;
int loginpacket = 0;
float speed;
int messagecounter;
uint8_t alertid = 0;
extern uint32_t crc32_fsl(uint32_t crc, const uint8_t *buf, uint32_t len);
/****************************************************************/
extern float overspeed;
extern char obdresp[20];
extern char tempobdresp[20];
extern char obdrespbinary[33];
extern char suppportedpid[100][7];
extern int pidcounter;
extern char g_u8OBDRecData[OBDRXBUFSIZE];
extern int saveipconfigurations(void);
extern char vehicleregnum[15];
char lastlocation[50];
char signalquality[5] = {0};
char emernum1[15] = {0};
char emernum2[15] = {0};
extern volatile uint8_t wetmr;
extern volatile int notsentcounter;

volatile uint8_t timeoutflag = 0 ;
/** Packet*****************************************/
  int tcpsendchtimer;
  int powerstatus = 0;
  volatile int ignition = 0;
  volatile int emergencystatus = 0;  
  int fix = 0;
  float int_bat_per;
  int int_bat_thresh;
  float mem_per;
  static int d1,d2;
  int iz;
  double a,b,c;int hh,mm1,mm2;
  double a1,b1,c1;
  double hh11, mm11,mm22;
  volatile char tamperalert = 'C';
  float ext_bat, int_bat, lati, longi, speed;
  float analog1,analog2,analog3,analog4;

  float antennafeedback = 0;
  float batteryvoltage = 0;
  float inputvoltage = 0;
  char latitude[12] = 0;
  char longitude[12] = 0;
  char prevlatitude[12] = 0;
  char prevlongitude[12] = 0;
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
  extern volatile uint8_t input1, input2, input3, input4;
  extern char apn[20];
  extern volatile int parameterupgrade;
  int outfromloop = 0;


/*	Global Variables
*****************************************************************/
int32_t	inc=0;
int stlen;
uint8_t u8InChar=0xFF;
volatile int32_t g_u8RecDataptr=0;
float	u32ADC0Result;
float u32ADC0Result1;
float batteryvoltagethreshold;
int8_t charging, cpinready, cregready;
int motion_counts,immotion_counts;
volatile int32_t timer0ticks=0;
volatile int32_t tmr0sec=0;
char * r1;
char * r2;
char * r3;
char temp[100];
char fileinstance[20] = {0};
int8_t  network = 1;
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
extern unsigned int xcrc32 (const unsigned char *buf, int len, unsigned int init);
//extern osMutexDef (fs_mutex);		// Declare mutex
extern osMutexId	(fs_mutex_id); // Mutex ID		
extern volatile int interval_count;
extern volatile int g_u32AdcIntFlag;
volatile int sleepinterval_i1;
volatile int sleepinterval_i0;

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
double deg2rad(double);
double rad2deg(double);

double distance(double lat1, double lon1, double lat2, double lon2, char unit) {
  double theta, dist;
  theta = lon1 - lon2;
  dist = sin(deg2rad(lat1)) * sin(deg2rad(lat2)) + cos(deg2rad(lat1)) * cos(deg2rad(lat2)) * cos(deg2rad(theta));
  dist = acos(dist);
  dist = rad2deg(dist);
  dist = dist * 60 * 1.1515;
  switch(unit) {
    case 'M':
      break;
    case 'K':
      dist = dist * 1.609344;
      break;
    case 'N':
      dist = dist * 0.8684;
      break;
  }
  return (dist);
}

double deg2rad(double deg) {
  return (deg * pi / 180);
}


double rad2deg(double rad) {
  return (rad * 180 / pi);
}

void SendAT(char * command, char * res1, char * res2, char * res3, int32_t timeout)
{
  static int attry;
  response1 = res1;
  response2 = res2;
  response3 = res3;

  timeoutflag =  0;
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
      {timeoutflag =  1;
        ///PA13=1;
        attry++;
        if(attry > 3){
            PB15 = 0;
            manualdelay(1);
            PB15 = 1;
            manualdelay(100);      
            SendAT("\r\nAT\r\n", "ERROR", "OK" , "4010",10);
            manualdelay(200);
        }
        ///PA13=0;
      }
      else{attry=0;}
   }
readaccgyrodata();
}

 void manualdelay(int delayms)
{
	
	for(d1 = 0; d1 < delayms ; d1++)
	{
		for(d2=0; d2 < 65535; d2++)
		{//printf("\n");
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
			pw += (*pw != c && *pw != d);
    }
    *pw = '\0';
}


// && *pw != ' ' && *pw != '/' && *pw != ':'

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
  
  if(readpt == 0 && pt == 0){
      SpiFlash_WaitReady();
      SpiFlash_ChipErase();
  }
  
  strcat(g_u8SendData,"\n");
  pch = strstr (g_u8SendData,",L,");
  if (pch){
    strncpy(pch,",H,",3);
  }
  strreplace(g_u8SendData, 0x1A, '\n'); 
  remove_all_chars(g_u8SendData,'\r',0x1A);
  SpiFlash_WaitReady();
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
    manualdelay(50);
    SpiFlash_WaitReady();    
    SpiFlash_PageProgram(SrcArray, pt, 256);
    memset(DestArray,0,257);
    SpiFlash_WaitReady();
    SpiFlash_ReadData(DestArray, pt, 256);
    if(strcmp(SrcArray, DestArray) == 0){
      times--; 
      pt+=256;
    }
  }
  memset(g_u8SendData,0,TXBUFSIZE);
  saveipconfigurations();

}

 void cpinquerry()
{
  int timeout;
	////osDelay(100);  
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
	////osDelay(100); 
  //osMutexWait(uart_mutex_id, osWaitForever);
	tmr0sec=0;
	timeout =10;
	r1=0;r2=0;r3=0;
	g_u8RecDataptr=0;
	memset(g_u8RecData,0,RXBUFSIZE);
	printf("%c",0x1A);
	clear();
	printf("\r\nAT+CREG?\r\n");
	do{
    g_u8RecData[0] = '\r';
		r1 = strstr(g_u8RecData, "CPIN: READY");
		r2 = strstr(g_u8RecData, "OK");
		r3 = strstr(g_u8RecData, "ERROR");
	}while(!(r1 || r2 || r3 ||((tmr0sec >= timeout))));	 //!(r1 || r2 || r3 ||
  clear();
  memset(cregresp,0,10);
  parse_g(g_u8RecData, 1, 1, ',', 'O' , cregresp);
  remove_all_chars(cregresp,'\r','\n');
  
  if(strstr(cregresp,"1") || strstr(cregresp, "5")|| strstr(cregresp, "2"))
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
	////osDelay(100);
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
  
////osDelay(10);
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
  SpiFlash_WaitReady();
  SpiFlash_ReadData(tcpdata, readpt, 256);
  outfromloop = readpt;
  if(tcpdata[0] != 0xFF && tcpdata[0] != '\0')
    times = 1;
  else{
        SpiFlash_WaitReady();
        SpiFlash_ChipErase();
        times = 0;
        pt = 0;
        readpt = 0;
        readpt = 0;
        pt = 0; 
        //saveipconfigurations();
    
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
      if((tcpsendchtimer > 4) && (strstr(tcpdata, "*"))){
        breaker = 1;
        break;
      }else breaker = 0;
    
    }
  //outfromloop = 1;
  manualdelay(5);
  }while(times == 1);
  if (breaker==1){
    readpt-=512;
  }
  saveipconfigurations();

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
        notsentcounter= 0;
				network=0;
        sendfs = 1;        
			}
	}else{//network = 1;
    sendfs = 0;} 
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
          notsentcounter= 0;
          network=0;
          sendfs = 1;
        }
    if(network == 0 && timesptr>=times){
      if(loginpacket == 1){
        memset(temp,0,100);        
      }else{
        memset(g_u8SendData,0,TXBUFSIZE);
      }
      sendfs=1;
    }
    else{
      sendfs=0;
    }
    }else{//network = 1;
    sendfs = 1;}
  }
  
  if(sendfs == 1){
    memset(configdata,0,300);
    //SpiFlash_WaitReady();
    SpiFlash_ReadData(configdata, readpt, 256);
    if(configdata[0] != 0xFF)
      sendfs = 1;
    else
      sendfs = 0;
  }

}





void SendAT_GPS_WO_MUTEX(char * command, char * response1, char * response2, char * response3, int32_t timeout)
{
//	osMutexWait(uart_mutex_id, osWaitForever);
	////osDelay(500);
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

__inline float stof(const char* s)
{int d,point_seen;
  float rez = 0, fact = 1;
  rez=0;fact=1;

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
  



















void SendAT_GPS(char * command, char * response1, char * response2, char * response3, int32_t timeout)
{
  int batterydischarging = 0;
  int sleepinterval;
  double d_distance;
  char send_temp[1000] = {0};
  char av[3] = {0};
  uint32_t checksumdata = 0;
  fix = 0;
  tamperalert = 'C';
  ext_bat, int_bat, lati, longi, speed;
  batteryvoltage = 0;
  inputvoltage = 0;
  memset(send_temp,0,1000);
  memset(latitude,0,12);
  memset(longitude,0,12);

  memset(gpsdate,0,7);
  memset(gpstime,0,7);
  memset(kmph,0,6);
  memset(alt,0,8);
  memset(sat,0,2);
  memset(latdir,0,2);
  memset(longdir,0,2);
  memset(hdop,0,6);
  memset(pdop,0,5);
  memset(networkoperator,0,30);
  memset(mcc,0,5);
  memset(mnc,0,5);
  memset(lac,0,5);
  memset(cellid,0,10);
  memset(nmr,0,200);
  packetstatus = 'L';

//  void SendAT_GPS(char * command, char * response1, char * response2, char * response3, int32_t timeout)
#ifndef OBD
  memset(g_u8SendData,0, TXBUFSIZE);
  SendAT("\r\nAT+QGNSSC=1\r\n\r\n", "OK", "ERROR: 7103" , "OK",5);
  clear();
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
    
		c=atof(latitude);//7523.7412
		hh= c/100; //75
		hh11 = c/100; //75.237412
		mm11 = hh11-hh; //.237412
		mm11*=100;
		mm22=hh+mm11/60;	
		memset(latitude,0,12);
		sprintf(latitude,"%f",mm22);
		c=atof(longitude);//7523.7412
		hh= c/100; //75
		hh11 = c/100; //75.237412
		mm11 = hh11-hh; //.237412
		mm11*=100;
		mm22=hh+mm11/60;	
		memset(longitude,0,12);
		sprintf(longitude,"%f",mm22);	


    if(mm22 != 0){
      fix = 1;
      }else{
      fix = 0;      
    }
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
    //manualdelay(100);
    
    
    SendAT("\r\nAT+QENG=2,3\r\n", "null", "null" , "+QENG: 2,",5);
//    tmr0sec=0;
//    r1=0;
//    r2=0;
//    r3=0;
//    g_u8RecDataptr=0;
//    memset(g_u8RecData,0,RXBUFSIZE);
//    clear();

//    printf("\r\nAT+QENG=2,3\r\n");
//    do{
//      g_u8RecData[0] = '\r';
//      r1 = strstr(g_u8RecData, "NULL");
//      r2 = strstr(g_u8RecData, "NULL");
//      r3 = strstr(g_u8RecData, "+QENG: 2,");
//    }while(!(r1 || r2 || r3 || ((tmr0sec >= 2))));	 //!(r1 || r2 || r3 ||
//    clear();  
    
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
    PA7 = 1; 
    packetstatus = 'L';
    g_u32AdcIntFlag = 0;
    ADC_START_CONV(ADC);   
    while(g_u32AdcIntFlag == 0);
    PA7 = 0; 
    u32ADC0Result = ADC_GET_CONVERSION_DATA(ADC, 0);
    u32ADC0Result = (2.72/0.852)*((u32ADC0Result*3.299) /4096);
    batteryvoltage = u32ADC0Result;      
    u32ADC0Result = ADC_GET_CONVERSION_DATA(ADC, 1);
    u32ADC0Result = (12.25/0.875)*((u32ADC0Result*3.299) /4096);
    inputvoltage = u32ADC0Result;
    u32ADC0Result = ADC_GET_CONVERSION_DATA(ADC, 2);
    u32ADC0Result = (12.25/0.875)*((u32ADC0Result*3.299) /4096);
    analog1 = u32ADC0Result;
    u32ADC0Result = ADC_GET_CONVERSION_DATA(ADC, 3);
    u32ADC0Result = (12.25/0.875)*((u32ADC0Result*3.299) /4096);
    analog2 = u32ADC0Result;
    u32ADC0Result = ADC_GET_CONVERSION_DATA(ADC, 4);
    u32ADC0Result = (12.25/0.875)*((u32ADC0Result*3.299) /4096);
    analog3 = u32ADC0Result;
    u32ADC0Result = ADC_GET_CONVERSION_DATA(ADC, 5);
    u32ADC0Result = (12.25/0.875)*((u32ADC0Result*3.299) /4096);
    analog4 = u32ADC0Result;
    u32ADC0Result = ADC_GET_CONVERSION_DATA(ADC, 5);
    u32ADC0Result = (12.25/0.875)*((u32ADC0Result*3.299) /4096);
    antennafeedback = u32ADC0Result;  
    
    //Last location saved
    memset(lastlocation,0,50);
    sprintf(lastlocation,"$%s,%s,%s,%s",latitude,latdir,longitude,longdir);
    }
    if((strlen(g_u8SendData) > 2900))
    {
      memset(g_u8SendData,0,TXBUFSIZE);
      strcat(g_u8SendData,imei);
      strcat(g_u8SendData,"error:RAMfull\n");
    }
    //osDelay(5);
  #endif
  #ifdef OBD

  #endif


    
    
    
    
    speed = atof(kmph);
    if(speed > overspeed){
      
    }
  if(packetstatus == 'L'){
    alertid = 1; 
    powerstatus = 0;  
  }
//disconnected from external battery
    if(inputvoltage < 5){
      alertid = 3; 
      powerstatus = 0;  
    }else{powerstatus = 1;}  
//internal battery voltage low 
    if(batteryvoltage < batteryvoltagethreshold){
      alertid = 4;
    }   
//if internal battery is charged again    
    if(inputvoltage < 6){
      batterydischarging = 1;     
    } 
//if connected to main batteryvoltage    
    if(speed > overspeed){
      
    }    
//if ignition on triggers
    if(ignition == 1){
      alertid = 7;
      ignition = 0;
    }    
//if ignition off triggers

  
//if emergency off triggers
    if(emergencystatus == 1 && PB9 == 0){
      alertid = 11;
    }    
//if over the air upgrade requested
    if(parameterupgrade == 1){
      alertid = 12;
      parameterupgrade = 0;
    }        
//if harse braking
   
// if harsh acceleration
   
//if rash turning
    
//if device tampered
//if emergency on triggers
    if(emergencystatus == 1){
      alertid = 10;
    }  
    

    if(wetmr > wakeinterval_emer){
      emergencystatus = 0;
    }

    if(ignition == 1){
      sleepinterval = sleepinterval_i1;
    }else{
      sleepinterval = sleepinterval_i0;      
    }
    // Live Data packet
    if(interval_count >= sleepinterval){       
      interval_count = 0;
      checksumdata = 0;
      //sprintf(g_u8SendData, "$%s,%s,%s,NR,%c,%s,%s,%d,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%d,%d,%.1f,%.1f,%d,%c,%s,%s,%s,%s,%s,%s\n
      memset(temp,0,100);
      sprintf(temp,"$%s,%s,%s,NR,%.2d,%c,%s,",header,vendorID,firmwareversion,alertid,packetstatus,imei); 
      strcat(g_u8SendData,temp);                                         //$  

      
      
      memset(temp,0,100);
      sprintf(temp,"%s,%d,%s,%s,%s,%s,%s,%s,",vehicleregnum,fix,gpsdate,gpstime,latitude,latdir,longitude,longdir);       
      strcat(g_u8SendData,temp);                               //vehicleregnum  

      
      memset(temp,0,100);
      sprintf(temp,"%s,%s,%s,%s,%s,%s,%s,",kmph,heading,sat,alt,pdop,hdop,networkoperator);       
      strcat(g_u8SendData,temp);                               //vehicleregnum      
      
      memset(temp,0,100);
      sprintf(temp,"%d,%d,%.2f,%.2f,%d,%c,",PB10,powerstatus,inputvoltage,batteryvoltage,emergencystatus,tamperalert);
      strcat(g_u8SendData,temp);                                        //ignition,powerstatus,inputvoltage,batteryvoltage,emergencystatus,tamperalert

      
      memset(temp,0,100);
      sprintf(temp,"%s,%s,%s,%s,%s,",signalquality,mcc,mnc,lac,cellid);
      strcat(g_u8SendData,temp);           
 
      
      strcat(g_u8SendData,nmr);                                         //nmr  
      strcat(g_u8SendData,",");                                         //,


      memset(temp,0,100);
      sprintf(temp,"%d%d%d%d,",input1,input2,input3,input4);
      strcat(g_u8SendData,temp);       //,
      input1=input2=input3=input4 = 0;

      memset(temp,0,100);
      sprintf(temp,"11,%.6d*",messagecounter++);
      strcat(g_u8SendData,temp);                                         //,

      strcat(send_temp,g_u8SendData);
      remove_all_chars(send_temp,'$','*');      
      checksumdata = crc32_fsl(0,send_temp,strlen(send_temp));
      memset(temp,0,100);
      sprintf(temp,"%x\n",checksumdata);  
      strcat(g_u8SendData,temp);      
      alertid = 0;

    } 
    int_bat_per = (batteryvoltage/4.2) * 100;
    mem_per = (pt/134217728) * 100;
    // Health Monitoring Parameter
    if(interval_count_health >= sleepinterval_health){       
      interval_count_health = 0;
      memset(configdata,0,300);
      sprintf(configdata,"$%s,%s,%s,HP,%s,%.3f,%d,%.3f,%d,%d,%d%d%d%d,%.1f,%.1f*",header,vendorID,firmwareversion,imei,int_bat_per,batteryvoltagethreshold,mem_per,sleepinterval_i1,sleepinterval_i0,input1,input2,input3,input4,analog1,analog2);//digital i/o 0000, analog io, *
      strcat(g_u8SendData, configdata);
      remove_all_chars(configdata,'$','*');
      checksumdata = crc32_fsl(0,configdata,strlen(configdata));  
      memset(temp,0,100);
      sprintf(temp,"%x\n",checksumdata);
      strcat(g_u8SendData,temp);
    }    
    
    //Emergency Alert Packet
    if(emergencystatus == 1){
      memset(configdata,0,300);
      memset(av,0,3);
      d_distance = distance(atof(prevlatitude), atof(prevlongitude), atof(latitude), atof(longitude), 'K');      
      memset(temp,0,100);
      sprintf(temp,"%f,",d_distance);      
      if(fix == 1){
        strcat(av,"A,");                                         //,          
      }else{
        strcat(av,"V,");                                         //,                  
      }     
      memset(configdata,0,300);      
      sprintf(configdata,"$%s,EMR,%s,NM,%s%s,%s,%s,%s,%s,%s,%s,%s,%s,G,%s,%s,%s*",\
      header,imei,gpsdate,gpstime,av,latitude,latdir,longitude,longdir,alt,kmph,temp,vehicleregnum,emernum1,emernum2);
      strcat(g_u8SendData,configdata);
      remove_all_chars(configdata,'$','*');
      checksumdata = crc32_fsl(0,configdata,strlen(configdata)); 
      memset(temp,0,100);
      sprintf(temp,"%x\n",checksumdata);
      strcat(g_u8SendData,temp);
    }

//fix = strlen(g_u8SendData);
memset(prevlatitude,0,12);
memset(prevlongitude,0,12);    
strcat(prevlatitude,latitude);
strcat(prevlongitude,longitude);

}