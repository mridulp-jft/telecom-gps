#line 1 "Thread.c"

#line 1 "C:\\Keil_v5\\ARM\\PACK\\ARM\\CMSIS\\5.0.1\\CMSIS\\RTOS\\RTX\\INC\\cmsis_os.h"


















































 












#line 72 "C:\\Keil_v5\\ARM\\PACK\\ARM\\CMSIS\\5.0.1\\CMSIS\\RTOS\\RTX\\INC\\cmsis_os.h"







#line 90 "C:\\Keil_v5\\ARM\\PACK\\ARM\\CMSIS\\5.0.1\\CMSIS\\RTOS\\RTX\\INC\\cmsis_os.h"

#line 1 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdint.h"
 
 





 









     
#line 27 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdint.h"
     











#line 46 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdint.h"





 

     

     
typedef   signed          char int8_t;
typedef   signed short     int int16_t;
typedef   signed           int int32_t;
typedef   signed       __int64 int64_t;

     
typedef unsigned          char uint8_t;
typedef unsigned short     int uint16_t;
typedef unsigned           int uint32_t;
typedef unsigned       __int64 uint64_t;

     

     
     
typedef   signed          char int_least8_t;
typedef   signed short     int int_least16_t;
typedef   signed           int int_least32_t;
typedef   signed       __int64 int_least64_t;

     
typedef unsigned          char uint_least8_t;
typedef unsigned short     int uint_least16_t;
typedef unsigned           int uint_least32_t;
typedef unsigned       __int64 uint_least64_t;

     

     
typedef   signed           int int_fast8_t;
typedef   signed           int int_fast16_t;
typedef   signed           int int_fast32_t;
typedef   signed       __int64 int_fast64_t;

     
typedef unsigned           int uint_fast8_t;
typedef unsigned           int uint_fast16_t;
typedef unsigned           int uint_fast32_t;
typedef unsigned       __int64 uint_fast64_t;

     




typedef   signed           int intptr_t;
typedef unsigned           int uintptr_t;


     
typedef   signed     long long intmax_t;
typedef unsigned     long long uintmax_t;




     

     





     





     





     

     





     





     





     

     





     





     





     

     






     






     






     

     


     


     


     

     
#line 216 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdint.h"

     



     






     
    
 



#line 241 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdint.h"

     







     










     











#line 305 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdint.h"






 
#line 92 "C:\\Keil_v5\\ARM\\PACK\\ARM\\CMSIS\\5.0.1\\CMSIS\\RTOS\\RTX\\INC\\cmsis_os.h"
#line 1 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stddef.h"
 






 

 
 
 





 





#line 34 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stddef.h"




  typedef signed int ptrdiff_t;



  



    typedef unsigned int size_t;    
#line 57 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stddef.h"



   



      typedef unsigned short wchar_t;  
#line 82 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stddef.h"



    




   




  typedef long double max_align_t;









#line 114 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stddef.h"



 

#line 93 "C:\\Keil_v5\\ARM\\PACK\\ARM\\CMSIS\\5.0.1\\CMSIS\\RTOS\\RTX\\INC\\cmsis_os.h"










typedef enum  {
  osPriorityIdle          = -3,          
  osPriorityLow           = -2,          
  osPriorityBelowNormal   = -1,          
  osPriorityNormal        =  0,          
  osPriorityAboveNormal   = +1,          
  osPriorityHigh          = +2,          
  osPriorityRealtime      = +3,          
  osPriorityError         =  0x84,       
  os_priority_reserved    =  0x7FFFFFFF  
} osPriority;





typedef enum  {
  osOK                    =     0,       
  osEventSignal           =  0x08,       
  osEventMessage          =  0x10,       
  osEventMail             =  0x20,       
  osEventTimeout          =  0x40,       
  osErrorParameter        =  0x80,       
  osErrorResource         =  0x81,       
  osErrorTimeoutResource  =  0xC1,       
  osErrorISR              =  0x82,       
  osErrorISRRecursive     =  0x83,       
  osErrorPriority         =  0x84,       
  osErrorNoMemory         =  0x85,       
  osErrorValue            =  0x86,       
  osErrorOS               =  0xFF,       
  os_status_reserved      =  0x7FFFFFFF  
} osStatus;



typedef enum  {
  osTimerOnce             =     0,       
  osTimerPeriodic         =     1        
} os_timer_type;


typedef void (*os_pthread) (void const *argument);


typedef void (*os_ptimer) (void const *argument);




typedef struct os_thread_cb *osThreadId;


typedef struct os_timer_cb *osTimerId;


typedef struct os_mutex_cb *osMutexId;


typedef struct os_semaphore_cb *osSemaphoreId;


typedef struct os_pool_cb *osPoolId;


typedef struct os_messageQ_cb *osMessageQId;


typedef struct os_mailQ_cb *osMailQId;



typedef struct os_thread_def  {
  os_pthread               pthread;    
  osPriority             tpriority;    
  uint32_t               instances;    
  uint32_t               stacksize;    
} osThreadDef_t;


typedef struct os_timer_def  {
  os_ptimer                 ptimer;    
  void                      *timer;    
} osTimerDef_t;


typedef struct os_mutex_def  {
  void                      *mutex;    
} osMutexDef_t;


typedef struct os_semaphore_def  {
  void                  *semaphore;    
} osSemaphoreDef_t;


typedef struct os_pool_def  {
  uint32_t                 pool_sz;    
  uint32_t                 item_sz;    
  void                       *pool;    
} osPoolDef_t;


typedef struct os_messageQ_def  {
  uint32_t                queue_sz;    
  void                       *pool;    
} osMessageQDef_t;


typedef struct os_mailQ_def  {
  uint32_t                queue_sz;    
  uint32_t                 item_sz;    
  void                       *pool;    
} osMailQDef_t;


typedef struct  {
  osStatus                 status;     
  union  {
    uint32_t                    v;     
    void                       *p;     
    int32_t               signals;     
  } value;                             
  union  {
    osMailQId             mail_id;     
    osMessageQId       message_id;     
  } def;                               
} osEvent;






osStatus osKernelInitialize (void);



osStatus osKernelStart (void);



int32_t osKernelRunning(void);




extern uint32_t const os_tickfreq;
extern uint16_t const os_tickus_i;
extern uint16_t const os_tickus_f;




uint32_t osKernelSysTick (void);










 












#line 289 "C:\\Keil_v5\\ARM\\PACK\\ARM\\CMSIS\\5.0.1\\CMSIS\\RTOS\\RTX\\INC\\cmsis_os.h"











osThreadId osThreadCreate (const osThreadDef_t *thread_def, void *argument);



osThreadId osThreadGetId (void);




osStatus osThreadTerminate (osThreadId thread_id);



osStatus osThreadYield (void);





osStatus osThreadSetPriority (osThreadId thread_id, osPriority priority);




osPriority osThreadGetPriority (osThreadId thread_id);







osStatus osDelay (uint32_t millisec);

#line 342 "C:\\Keil_v5\\ARM\\PACK\\ARM\\CMSIS\\5.0.1\\CMSIS\\RTOS\\RTX\\INC\\cmsis_os.h"






#line 357 "C:\\Keil_v5\\ARM\\PACK\\ARM\\CMSIS\\5.0.1\\CMSIS\\RTOS\\RTX\\INC\\cmsis_os.h"











osTimerId osTimerCreate (const osTimerDef_t *timer_def, os_timer_type type, void *argument);





osStatus osTimerStart (osTimerId timer_id, uint32_t millisec);




osStatus osTimerStop (osTimerId timer_id);




osStatus osTimerDelete (osTimerId timer_id);








int32_t osSignalSet (osThreadId thread_id, int32_t signals);





int32_t osSignalClear (osThreadId thread_id, int32_t signals);









__value_in_regs osEvent osSignalWait (int32_t signals, uint32_t millisec);







#line 425 "C:\\Keil_v5\\ARM\\PACK\\ARM\\CMSIS\\5.0.1\\CMSIS\\RTOS\\RTX\\INC\\cmsis_os.h"









osMutexId osMutexCreate (const osMutexDef_t *mutex_def);





osStatus osMutexWait (osMutexId mutex_id, uint32_t millisec);




osStatus osMutexRelease (osMutexId mutex_id);




osStatus osMutexDelete (osMutexId mutex_id);








#line 467 "C:\\Keil_v5\\ARM\\PACK\\ARM\\CMSIS\\5.0.1\\CMSIS\\RTOS\\RTX\\INC\\cmsis_os.h"










osSemaphoreId osSemaphoreCreate (const osSemaphoreDef_t *semaphore_def, int32_t count);





int32_t osSemaphoreWait (osSemaphoreId semaphore_id, uint32_t millisec);




osStatus osSemaphoreRelease (osSemaphoreId semaphore_id);




osStatus osSemaphoreDelete (osSemaphoreId semaphore_id);












#line 515 "C:\\Keil_v5\\ARM\\PACK\\ARM\\CMSIS\\5.0.1\\CMSIS\\RTOS\\RTX\\INC\\cmsis_os.h"









osPoolId osPoolCreate (const osPoolDef_t *pool_def);




void *osPoolAlloc (osPoolId pool_id);




void *osPoolCAlloc (osPoolId pool_id);





osStatus osPoolFree (osPoolId pool_id, void *block);












#line 562 "C:\\Keil_v5\\ARM\\PACK\\ARM\\CMSIS\\5.0.1\\CMSIS\\RTOS\\RTX\\INC\\cmsis_os.h"










osMessageQId osMessageCreate (const osMessageQDef_t *queue_def, osThreadId thread_id);






osStatus osMessagePut (osMessageQId queue_id, uint32_t info, uint32_t millisec);









__value_in_regs osEvent osMessageGet (osMessageQId queue_id, uint32_t millisec);













#line 614 "C:\\Keil_v5\\ARM\\PACK\\ARM\\CMSIS\\5.0.1\\CMSIS\\RTOS\\RTX\\INC\\cmsis_os.h"










osMailQId osMailCreate (const osMailQDef_t *queue_def, osThreadId thread_id);





void *osMailAlloc (osMailQId queue_id, uint32_t millisec);





void *osMailCAlloc (osMailQId queue_id, uint32_t millisec);





osStatus osMailPut (osMailQId queue_id, void *mail);









__value_in_regs osEvent osMailGet (osMailQId queue_id, uint32_t millisec);






osStatus osMailFree (osMailQId queue_id, void *mail);








uint32_t os_suspend (void);



void os_resume (uint32_t sleep_time);


__declspec(noreturn) void os_idle_demon (void);



__declspec(noreturn) void os_error (uint32_t error_code);






#line 3 "Thread.c"





 
 
void Thread (void const *argument);                             
void Thread1 (void const *argument);                             

extern void SendAT(char * command, char * response1, char * response2, char * response3, int32_t timeout);
extern void TCP_Send(char * tcpcommand,char * tcpdata, char * tcpresponse1, char * tcpresponse2, char * tcpresponse3, int32_t tcptimeout);
extern void SendAT_GPS(char * command, char * response1, char * response2, char * response3, int32_t timeout);

extern char g_u8RecData[800];
extern char g_u8SendData[3300];
extern uint32_t life;
extern int network;
char temp_fs[100] = {0};

osThreadId tid_Thread;                                          
osThreadId tid_Thread1;                                          
const osThreadDef_t os_thread_def_Thread = { (Thread), (osPriorityNormal), (1), (2024) };                   
const osThreadDef_t os_thread_def_Thread1 = { (Thread1), (osPriorityNormal), (1), (4048) };                   



extern char temp[100];
extern __inline void Save_FS();
extern __inline void manualdelay(int delayms);
extern __inline void Send_FS();
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
				
	
	
			network=0;
			if(noread == 0){ret = qfread(fileinstance);}
				TCP_Send("\r\nAT+QISEND\r\n",g_u8SendData,">","ERROR","SEND OK",10);	 
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

	memset(temp_fs,0,100);
	sprintf(temp_fs,"\r\nAT+QFCLOSE=%s\r\n",fileinstance);
	SendAT(temp_fs, "Ready", "OK" , "ERROR",10);	
	memset(g_u8SendData,0,3300);

}







int Init_Thread (void) {

 tid_Thread = osThreadCreate (&os_thread_def_Thread, 0);
  if (!tid_Thread) return(-1);
  tid_Thread1 = osThreadCreate (&os_thread_def_Thread1, 0);
  if (!tid_Thread) return(-1);
  
  return(0);
}

void Thread (void const *argument) {

  while (1) {

		
		SendAT_GPS("\r\nAT+QGNSSRD=\"NMEA/RMC\"\r\n", "+MGPSSTATUS", "OK" , "ERROR",10);	
    osDelay(5000);                                           
	
  }
}

void Thread1 (void const *argument)
{
	while (1) 
	{
		
		SendAT("\r\nAT+QIACT\r\n", "Ready", "OK" , "ERROR",10);	
		SendAT("\r\nAT+QGNSSC=1\r\n", "OK", "ERROR", "7103", 5);
		SendAT("\r\nAT+QIREGAPP=\"isafe\"\r\n", "Ready", "OK" , "ERROR",5);	


		SendAT("\r\nAT+QSCLK=1\r\n", "Ready", "OK" , "ERROR",5);	
		osDelay(2000);

		SendAT("\r\nAT+QIREGAPP\r\n", "Ready", "OK" , "ERROR",2);	

		SendAT("\r\nAT+QISTAT\r\n", "Ready", "OK" , "ERROR",10);	




		SendAT("\r\nAT+QILOCIP\r\n", "Ready", "OK" , "ERROR",2);	
		SendAT("\r\nAT+QISTAT\r\n", "Ready", "OK" , "ERROR",10);	
		SendAT("\r\nAT+CSQ\r\n", "Ready", "OK" , "ERROR",10);	

		SendAT("\r\nAT+QIOPEN=\"TCP\",\"104.236.203.4\",\"5556\"\r\n","CONNECT OK\r\n","ERROR","FAIL",10);	



		network=0;
		TCP_Send("\r\nAT+QISEND\r\n",g_u8SendData,">","ERROR","SEND OK",10);	

		if(network == 1)
		{
			SendAT("\r\nAT+QICLOSE\r\n","CLOSE OK\r\n","ERROR","FAIL",10);	
			SendAT("\r\nAT+CFUN=0\r\n", "OK", "NOT INSERTED" , "ERROR",5);
			SendAT("\r\nAT+CFUN=1\r\n", "SMS Ready", "NOT INSERTED" , "ERROR",5);			
			

			manualdelay(100);
			SendAT("\r\nAT+QIACT\r\n", "Ready", "OK" , "ERROR",10);	

		}
		else
		{
			
			osDelay(32000);                                         
		}
	
	
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
	int delayus=0;
	int d1,d2;
	for(d1 = 0; d1 < delayms ; d1++)
	{
		for(d2=0; d2 < 65535; d2++)
		{
		}
	}
}

