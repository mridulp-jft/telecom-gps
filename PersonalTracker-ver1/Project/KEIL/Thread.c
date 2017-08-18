
#include "cmsis_os.h"                                           // CMSIS RTOS header file
#include "string.h"
#include "stdio.h"

/*----------------------------------------------------------------------------
 *      Thread 1 'Thread_Name': Sample thread
 *---------------------------------------------------------------------------*/
 
void Thread (void const *argument);                             // thread function
void Thread1 (void const *argument);                             // thread function

extern void SendAT(char * command, char * response1, char * response2, char * response3, int32_t timeout);
extern void TCP_Send(char * tcpcommand,char * tcpdata, char * tcpresponse1, char * tcpresponse2, char * tcpresponse3, int32_t tcptimeout);
extern void SendAT_GPS(char * command, char * response1, char * response2, char * response3, int32_t timeout);
extern __inline void parse_g(char* str, int first, int sec, char f, char s , char *string);

extern char g_u8RecData[RXBUFSIZE];
extern char g_u8SendData[TXBUFSIZE];
extern uint32_t life;
extern int network;
char temp_fs[100] = {0};

osThreadId tid_Thread;                                          // thread id
osThreadId tid_Thread1;                                          // thread id
osThreadDef (Thread, osPriorityNormal, 1, 2024);                   // thread object
osThreadDef (Thread1, osPriorityNormal, 1, 4048);                   // thread object
//extern typedef struct os_mutex_cb fs_mutex_id;


extern char temp[100];
extern __inline void Save_FS(void);
extern __inline void manualdelay(int delayms);
extern __inline void Send_FS(void);
extern __inline int count_char(char ch,char* string);
extern  int qfread(char* fi);

 void remove_all_chars(char* str, char c, char d) {
    char *pr = str, *pw = str;
    while (*pr) {
        *pw = *pr++;
			pw += (*pw != c && *pw != d && *pw != ' ' && *pw != '/' && *pw != ':');
    }
    *pw = '\0';
}





__inline void Send_FS()
{
char fileinstance[20] = {0};
int ret=0;
int noread=0;
	
SendAT("\r\nAT+QFOPEN=\"LOG.TXT\",0\r\n", "Ready", "OK" , "ERROR",10);	
if(strstr(g_u8RecData,"CME ERROR"))
	{
			SendAT("\r\nAT+CFUN=1,1\r\n", "Ready", "OK" , "ERROR",10);	
			manualdelay(50);
			SendAT("\r\nAT+QGNSSC=1\r\n", "OK", "ERROR", "7103", 5);
			SendAT("\r\nAT+QIREGAPP=\"isafe\"\r\n", "Ready", "OK" , "ERROR",5);	
			SendAT("\r\nAT+QIMUX=1\r\n", "Ready", "OK" , "ERROR",5);	
			SendAT("\r\nAT+QIMODE=0\r\n", "Ready", "OK" , "ERROR",5);	
			SendAT("\r\nAT+QSCLK=1\r\n", "Ready", "OK" , "ERROR",5);	
			SendAT("\r\nAT+QIREGAPP\r\n", "Ready", "OK" , "ERROR",2);	
			manualdelay(50);
			SendAT("\r\nAT+QIACT\r\n", "Ready", "OK" , "ERROR",10);	
			SendAT("\r\nAT+QILOCIP\r\n", "Ready", "OK" , "ERROR",2);	
			SendAT("\r\nAT+QIOPEN=\"TCP\",\"104.236.203.4\",\"5556\"\r\n","CONNECT OK\r\n","ERROR","FAIL",10);	
			SendAT("\r\nAT+QFOPEN=\"LOG.TXT\",0\r\n", "Ready", "OK" , "ERROR",10);	

	}
	parse_g(g_u8RecData, 1, 2, ' ', '\n' , fileinstance);
	remove_all_chars(fileinstance, '\r', '\n');		
	do{
				//		memset(g_u8SendData,0,100);
	//		sprintf(g_u8SendData,"H\n%c",0x1a);
	//		strcat(g_u8SendData,0x1a);
			network=0;
			if(noread == 0){ret = qfread(fileinstance);}
				TCP_Send("\r\nAT+QISEND\r\n",g_u8SendData,">","ERROR","SEND OK",10);	 // 	network=1;
			if(network == 1)
			{
				SendAT("\r\nAT+CFUN=0\r\n", "OK", "NOT INSERTED" , "ERROR",5);
				SendAT("\r\nAT+CFUN=1\r\n", "SMS Ready", "NOT INSERTED" , "ERROR",5);			
				SendAT("\r\nAT+QICLOSE\r\n","CLOSE OK\r\n","ERROR","FAIL",10);	
				Save_FS();
				manualdelay(100);
				noread=1;

			}
			else{noread=0;}
			
	}while(!ret);
//	SendAT(g_u8SendData, "QFWRITE", "OK" , "ERROR",10);	
	memset(temp_fs,0,100);
	sprintf(temp_fs,"\r\nAT+QFCLOSE=%s\r\n",fileinstance);
	SendAT(temp_fs, "Ready", "OK" , "ERROR",10);	
	
}




__inline void Save_FS()
{
char fileinstance[20] = {0};

SendAT("\r\nAT+QFOPEN=\"LOG.TXT\",0\r\n", "Ready", "OK" , "ERROR",10);	
	if(strstr(g_u8RecData,"CME ERROR"))
	{
			SendAT("\r\nAT+CFUN=1,1\r\n", "Ready", "OK" , "ERROR",10);	
			manualdelay(50);
			SendAT("\r\nAT+QGNSSC=1\r\n", "OK", "ERROR", "7103", 5);
			SendAT("\r\nAT+QFOPEN=\"LOG.TXT\",0\r\n", "Ready", "OK" , "ERROR",10);	
	}
	parse_g(g_u8RecData, 1, 2, ' ', '\n' , fileinstance);
	remove_all_chars(fileinstance, '\r', '\n');		
	memset(temp,0,100);
	sprintf(temp,"\r\nAT+QFWRITE=%s\r\n",fileinstance);
	SendAT(temp, "CONNECT", "OK" , "ERROR",10);	
	remove_all_chars(g_u8SendData, '\r', 0x1A);		

	SendAT(g_u8SendData, "QFWRITE", "OK" , "ERROR",20);	
//	manualdelay(50);
	memset(temp_fs,0,100);
	sprintf(temp_fs,"\r\nAT+QFCLOSE=%s\r\n",fileinstance);
	SendAT(temp_fs, "Ready", "OK" , "ERROR",10);	
	memset(g_u8SendData,0,TXBUFSIZE);

}







int Init_Thread (void) {

 tid_Thread = osThreadCreate (osThread(Thread), NULL);
  if (!tid_Thread) return(-1);
  tid_Thread1 = osThreadCreate (osThread(Thread1), NULL);
  if (!tid_Thread) return(-1);
  
  return(0);
}

void Thread (void const *argument) {

  while (1) {
//		printf("\r\n\n\n%d\n\n\r\nAT\r\n",life);
		
		SendAT_GPS("\r\nAT+QGNSSRD=\"NMEA/RMC\"\r\n", "+MGPSSTATUS", "OK" , "ERROR",10);	
    osDelay(5000);                                           // suspend thread
	
  }
}

void Thread1 (void const *argument)
{
	while (1) 
	{
		
		SendAT("\r\nAT+QIACT\r\n", "Ready", "OK" , "ERROR",1);	
		SendAT("\r\nAT+QGNSSC=1\r\n", "OK", "ERROR", "7103", 5);
		SendAT("\r\nAT+QIREGAPP=\"isafe\"\r\n", "Ready", "OK" , "ERROR",5);	
//		SendAT("\r\nAT+QIMUX=1\r\n", "Ready", "OK" , "ERROR",5);	
//		SendAT("\r\nAT+QIMODE=0\r\n", "Ready", "OK" , "ERROR",5);	
		SendAT("\r\nAT+QSCLK=1\r\n", "Ready", "OK" , "ERROR",5);	
		osDelay(2000);
		SendAT("\r\nAT+QIREGAPP\r\n", "Ready", "OK" , "ERROR",2);	
		SendAT("\r\nAT+QISTAT\r\n", "Ready", "OK" , "ERROR",10);	
		SendAT("\r\nAT+QILOCIP\r\n", "Ready", "OK" , "ERROR",2);	
		SendAT("\r\nAT+QISTAT\r\n", "Ready", "OK" , "ERROR",10);	
		SendAT("\r\nAT+CSQ\r\n", "Ready", "OK" , "ERROR",10);	
		SendAT("\r\nAT+QIOPEN=\"TCP\",\"104.236.203.4\",\"5556\"\r\n","CONNECT OK\r\n","ERROR","FAIL",10);	
//		memset(g_u8SendData,0,100);
//		sprintf(g_u8SendData,"H\n%c",0x1a);
//		strcat(g_u8SendData,0x1a);
		network=0;
		TCP_Send("\r\nAT+QISEND\r\n",g_u8SendData,">","ERROR","SEND OK",10);	
//  	network=1;
		if(network == 1)
		{
			SendAT("\r\nAT+QICLOSE\r\n","CLOSE OK\r\n","ERROR","FAIL",10);	
			SendAT("\r\nAT+CFUN=0\r\n", "OK", "NOT INSERTED" , "ERROR",5);
			SendAT("\r\nAT+CFUN=1\r\n", "SMS Ready", "NOT INSERTED" , "ERROR",5);			
			//Save_FS();

			manualdelay(100);
			SendAT("\r\nAT+QIACT\r\n", "Ready", "OK" , "ERROR",10);	

		}
		else
		{
			//Send_FS();
			osDelay(32000);                                         // suspend thread
		}
	//osThreadYield();
	
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



