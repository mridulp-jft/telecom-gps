#include "stdio.h"
#include "cmsis_os.h"                                           // CMSIS RTOS header file
#include "NUC100Series.h"
#include "stdlib.h"
#include "string.h"

extern osMutexId	(tcp_mutex_id); // Mutex ID
extern char g_u8OBDRecData[OBDRXBUFSIZE];
extern char obdresp[20];
extern char tempobdresp[20];
extern char obdrespbinary[33];
extern char suppportedpid[100][7];
extern char temp[100];
extern int pidcounter;
/************************global variables**********************/
int once = 1;
extern uint32_t pt;
int motion = 0;
int32_t signal;
int32_t signal2;
int start_thead = 0;
/***************************************************************/
/************************extern variables**********************/
extern int8_t charging, cpinready, cregready;
extern char g_u8SendData[TXBUFSIZE];
extern char g_u8RecData[RXBUFSIZE];
extern void cpinquerry(void);
extern void cregquerry(void);
extern void Save_FS(void);
extern void Send_FS(void);
extern int8_t  network;
extern int read_obd;
extern int32_t life;
/***************************************************************/
/************************EXTERN FUNCTIONS***********************/
__inline void manualdelay(int delayms);
__inline void remove_all_chars(char* str, char c, char d);
__inline void obd_get_data();
void accgyro_READ (void const *argument);
extern void SendAT(char * command, char * response1, char * response2, char * response3, int32_t timeout);
extern void SendAT_FS(char * command, char * response1, char * response2, char * response3, int32_t timeout);
extern void TCP_Send_ch(char * tcpcommand,char * tcpdataq, char * tcpresponse1, char * tcpresponse2, char * tcpresponse3, int32_t tcptimeout);
extern void SendAT_GPS_WO_MUTEX(char * command, char * response1, char * response2, char * response3, int32_t timeout);
extern void TCP_Send_ch(char * tcpcommand,char * tcpdataq, char * tcpresponse1, char * tcpresponse2, char * tcpresponse3, int32_t tcptimeout);
extern void TCP_Send(char * tcpcommand,char * tcpdata, char * tcpresponse1, char * tcpresponse2, char * tcpresponse3, int32_t tcptimeout);
extern void SendAT_GPS(char * command, char * response1, char * response2, char * response3, int32_t timeout);
extern void send_OBD(char * command, char * response1, char * response2, char * response3, int32_t timeout);
extern void parse_g(char* str, int first, int sec, char f, char s , char *string);
extern void readaccgyrodata(void);
//void GSM (void const *argument);                                // thread function
void OBD_READ (void const *argument); 
void accgyro_READ (void const *argument) ;
//osThreadId tid_Thread_GSM;                                      // thread id
//osThreadDef (GSM, osPriorityNormal, 1, 2050);                   // thread object
extern osThreadId mainThreadID;
osThreadId tid_Thread_OBD_READ;                                     // thread id
osThreadDef (OBD_READ, osPriorityNormal, 1, 1000);                  // thread object
osThreadId tid_Thread_accgyro_READ;
osThreadDef (readaccgyrodata, osPriorityNormal, 1, 1000);                  // thread object

void OBD_READ (void const *argument) 
{
  while (1) 
	{
//    motion = 1;
//    osSignalWait (0x0002, osWaitForever); // wait forever for the signal 0x0002
//    osSignalClear (tid_Thread_OBD_READ, 0x0002);
//    #ifdef OBD    
//      obd_get_data();
//    #endif    
//    signal = osSignalSet (mainThreadID, 0x0001);
//    osDelay(4900);
    readaccgyrodata();
    osDelay(100);
    
   }
 }

int Init_Thread (void) {
//  #ifdef OBD
      tid_Thread_accgyro_READ = osThreadCreate (osThread(readaccgyrodata), NULL);
      if (!tid_Thread_accgyro_READ) return(-1);  
      return(0);
//  #endif
}

__inline void obd_get_data(){
    pidcounter=0;
		while(strlen(suppportedpid[pidcounter])>3)
		{
				send_OBD(suppportedpid[pidcounter],">","NODATA",">",5);
          if((!strstr(g_u8OBDRecData, "NO DATA"))&&(!strstr(suppportedpid[pidcounter], "0100"))&&(!strstr(suppportedpid[pidcounter], "0120"))&&(!strstr(suppportedpid[pidcounter], "0140"))&&(!strstr(suppportedpid[pidcounter], "0160"))&&(!strstr(suppportedpid[pidcounter], "0180"))&&(!strstr(suppportedpid[pidcounter], "01A0"))&&(!strstr(suppportedpid[pidcounter], "01C0"))&&(!strstr(suppportedpid[pidcounter], "050100"))&&(!strstr(suppportedpid[pidcounter], "0900"))  ){
          memset(obdresp,0,20);
          memset(tempobdresp,0,20);
          parse_g(g_u8OBDRecData, 1, 2, '\r', '\r' ,tempobdresp);
          //remove_all_chars(suppportedpid[pidcounter], '\r', '\n');
          remove_all_chars(tempobdresp, '\r', ' ');
          strcat(g_u8SendData,",");
          strcat(g_u8SendData,suppportedpid[pidcounter]);
          strcat(g_u8SendData,"=");
          strcat(g_u8SendData,tempobdresp);
        }
        pidcounter++;
		}
		strcat(g_u8SendData,",<>,");	    
		memset(temp,0,100);
		sprintf(temp,",~`,LIFE=%d\n",life);
		strcat(g_u8SendData,temp);
    remove_all_chars(g_u8SendData, '\r', ' ');
    read_obd=0;
}
