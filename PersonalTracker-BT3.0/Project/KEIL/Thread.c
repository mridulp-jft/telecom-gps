#include "Nano100Series.h"
#include "cmsis_os.h"                                           // CMSIS RTOS header file
#include "string.h"
#include "stdio.h"

/*----------------------------------------------------------------------------
 *      Thread 1 'Thread_Name': Sample thread
 *---------------------------------------------------------------------------*/
 
void Thread (void const *argument);                             // thread function
void Thread1 (void const *argument);                             // thread function
void actgprs(void);
void remove_all_chars(char* str, char c, char d);

extern void SendAT(char * command, char * response1, char * response2, char * response3, int32_t timeout);
extern void TCP_Send(char * tcpcommand,char * tcpdata, char * tcpresponse1, char * tcpresponse2, char * tcpresponse3, int32_t tcptimeout);
extern void SendAT_GPS(char * command, char * response1, char * response2, char * response3, int32_t timeout);
extern __inline void parse_g(char* str, int first, int sec, char f, char s , char *string);
extern void cpinquerry(void);
extern void cregquerry(void);
extern void Send_FS(void);
void fileclose(void);
__inline void fileopen(void);
extern char g_u8RecData[RXBUFSIZE];
extern char g_u8SendData[TXBUFSIZE];
extern uint32_t life;
extern int network;
char temp_fs[100] = {0};
extern int8_t charging, cpinready, cregready;
char fileinstance[20] = {0};

extern osMutexId	(uart_mutex_id); // Mutex ID

osThreadId tid_Thread;                                          // thread id
osThreadId tid_Thread1;                                          // thread id
osThreadDef (Thread, osPriorityNormal, 1, 2024);                   // thread object
osThreadDef (Thread1, osPriorityNormal, 1, 4048);                   // thread object
//extern typedef struct os_mutex_cb fs_mutex_id;

__inline void strreplace(char s[], char chr, char repl_chr);
extern char temp[100];
void Save_FS(void);
extern __inline void manualdelay(int delayms);
extern __inline void Send_FS(void);
extern __inline int count_char(char ch,char* string);
extern  int qfread(char* fi);

extern uint8_t mainla;
extern uint8_t th1la;
extern uint8_t th2la;
extern char * r1;
extern char * r2;
extern char * r3;
extern int motion;
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


int Init_Thread (void) {

	tid_Thread = osThreadCreate (osThread(Thread), NULL);
  if (!tid_Thread) return(-1);
  tid_Thread1 = osThreadCreate (osThread(Thread1), NULL);
  if (!tid_Thread) return(-1);
  
  return(0);
}

void Thread (void const *argument) 
{
  while (1) 
	{
    mainla = 0;
    th1la = 1;
    th2la = 0;  
    if(motion!=0){
      SendAT("\r\nAT+QGNSSC=1\r\n", "OK", "ERROR", "7103", 10);
      SendAT_GPS("\r\nAT+QGNSSRD=\"NMEA/RMC\"\r\n", "+MGPSSTATUS", "OK" , "ERROR",10);	
      osDelay(5000);
    }      // suspend thread

  }
}

void Thread1 (void const *argument)
{
	while (1) 
	{
    mainla = 0;
    th1la = 0;
    th2la = 1;  
    cpinquerry();
    if(cpinready==1)
    {
      cregquerry();
      if(cregready == 1)
      {
        SendAT("\r\nAT+CGREG?\r\n", "Ready", "OK" , "ERROR",50);	
        SendAT("\r\nAT+QIREGAPP=\"isafe\"\r\n", "Ready", "OK" , "ERROR",5);	
        SendAT("\r\nAT+QIREGAPP\r\n", "Ready", "OK" , "ERROR",2);	
        SendAT("\r\nAT+QIACT\r\n", "Ready", "OK" , "ERROR",200);	
        SendAT("\r\nAT+QILOCIP\r\n", "Ready", "OK" , "ERROR",2);	
      }
    }
		SendAT("\r\nAT+QSCLK=1\r\n", "Ready", "OK" , "ERROR",5);
		SendAT("\r\nAT+QISTAT\r\n", "Ready", "OK" , "ERROR",10);	
		SendAT("\r\nAT+CSQ\r\n", "Ready", "OK" , "ERROR",10);	
		SendAT("\r\nAT+QIOPEN=\"TCP\",\"104.236.203.4\",\"5556\"\r\n","CONNECT","ERROR","FAIL",10);	
		network=0;
		TCP_Send("\r\nAT+QISEND\r\n",g_u8SendData,">","ERROR","SEND OK",10);	
		if(network == 1)
		{
      Save_FS();
  //    Send_FS();
			SendAT("\r\nAT+QICLOSE\r\n","CLOSE OK\r\n","ERROR","FAIL",10);	
			SendAT("\r\nAT+CFUN=0\r\n", "OK", "NOT INSERTED" , "ERROR",10);
			SendAT("\r\nAT+CFUN=1\r\n", "Ready", "NOT INSERTED" , "ERROR",10);	
 
      manualdelay(200);
    }
		else
		{
      if(life > 1500){
        SYS_UnlockReg();
        SYS->IPRST_CTL1 |= SYS_IPRST_CTL1_CHIP_RST_Msk; 
      }
			osDelay(32000);                                         // suspend thread
		}
  }
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

 void remove_all_chars(char* str, char c, char d) {
    char *pr = str, *pw = str;
    while (*pr) {
        *pw = *pr++;
			pw += (*pw != c && *pw != d && *pw != ' ' && *pw != '/' && *pw != ':');
    }
    *pw = '\0';
}


//SendAT("\r\nAT+CPIN?\r\n", "CPIN: READY", "OK" , "ERROR",2);	


void actgprs()
{
    cpinquerry();
    if(cpinready == 1)
    {
   		cregquerry();
      if(cregready == 1)
      {
        SendAT("\r\nAT+CGREG?\r\n", "Ready", "OK" , "ERROR",5);	
        SendAT("\r\nAT+QIREGAPP=\"isafe\"\r\n", "Ready", "OK" , "ERROR",5);	
        SendAT("\r\nAT+QIREGAPP\r\n", "Ready", "OK" , "ERROR",2);	
        SendAT("\r\nAT+QIACT\r\n", "Ready", "OK" , "ERROR",5);	
        SendAT("\r\nAT+QILOCIP\r\n", "Ready", "OK" , "ERROR",2);	
      }
    }
 }

void fileclose(void)
{
    memset(temp,0,100);
    sprintf(temp,"\r\nAT+QFCLOSE=%s\r\n",fileinstance);
    SendAT(temp, "+CME ERROR", "OK" , "ERROR",10);
}
 
__inline void fileopen(void)
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
    SendAT("\r\nAT+QGNSSC=1\r\n", "OK", "ERROR", "7103", 5);
  
}



 
 
 