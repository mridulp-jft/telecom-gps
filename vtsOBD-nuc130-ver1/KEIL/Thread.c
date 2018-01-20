
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

extern void SendAT(char * command, char * response1, char * response2, char * response3, int32_t timeout);
extern void SendAT_FS(char * command, char * response1, char * response2, char * response3, int32_t timeout);
extern void TCP_Send_ch(char * tcpcommand,char * tcpdataq, char * tcpresponse1, char * tcpresponse2, char * tcpresponse3, int32_t tcptimeout);
extern void SendAT_GPS_WO_MUTEX(char * command, char * response1, char * response2, char * response3, int32_t timeout);
extern void TCP_Send_ch(char * tcpcommand,char * tcpdataq, char * tcpresponse1, char * tcpresponse2, char * tcpresponse3, int32_t tcptimeout);
extern void TCP_Send(char * tcpcommand,char * tcpdata, char * tcpresponse1, char * tcpresponse2, char * tcpresponse3, int32_t tcptimeout);
extern void SendAT_GPS(char * command, char * response1, char * response2, char * response3, int32_t timeout);
extern void send_OBD(char * command, char * response1, char * response2, char * response3, int32_t timeout);
extern void parse_g(char* str, int first, int sec, char f, char s , char *string);

/***************************************************************/




/*----------------------------------------------------------------------------
 *      Thread 1 'Thread_Name': Sample thread
 *---------------------------------------------------------------------------*/
 
void GSM (void const *argument);                             // thread function
void GNSS (void const *argument); 

osThreadId tid_Thread_GSM;                                          // thread id
osThreadDef (GSM, osPriorityNormal, 1, 2050);                   // thread object
osThreadId tid_Thread_GNSS;                                          // thread id
osThreadDef (GNSS, osPriorityNormal, 1, 4048);                   // thread object

int Init_Thread (void) {

  tid_Thread_GSM = osThreadCreate (osThread(GSM), NULL);
  if (!tid_Thread_GSM) return(-1);
  tid_Thread_GNSS = osThreadCreate (osThread(GNSS), NULL);
  if (!tid_Thread_GNSS) return(-1);  
  return(0);
}
void GNSS (void const *argument) 
{
  while (1) 
	{
    motion = 1;

    //SendAT_GPS("\r\n\r\nAT+QGNSSRD=\"NMEA/RMC\"\r\n\r\n\r\n", "MGPSSTATUS", "OK" , "ERROR",5);	
       //osMutexWait(tcp_mutex_id, osWaitForever);
    osSignalWait (0x0002, osWaitForever); // wait forever for the signal 0x0001
    osSignalClear (tid_Thread_GNSS, 0x0002);
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
    signal = osSignalSet (tid_Thread_GSM, 0x0001);
    //osMutexRelease(tcp_mutex_id);     //osDelay(4900); //4900
   }      // suspend thread
    //osDelay(100);
 
}

void GSM (void const *argument) {
int waitstatus = 0;
	while (1) 
	{
    
 
		SendAT("\r\nAT+CFUN=1\r\n\r\n", "OK", "NOT INSERTED" , "ERROR",1);	
    cpinquerry();
    if(cpinready==1)
    {
      cregquerry();
      if(cregready == 1)
      {
        SendAT("\r\nAT+CGREG?\r\n\r\n", "Ready", "OK" , "ERROR",5);	
        SendAT("\r\nAT+QIREGAPP=\"isafe\",\"\",\"\"\r\n\r\n", "Ready", "OK" , "ERROR",5);	
        SendAT("\r\nAT+QIREGAPP?\r\n\r\n", "Ready", "OK" , "ERROR",5);	
        SendAT("\r\nAT+QIACT\r\n\r\n", "Ready", "OK" , "ERROR",5);	
        SendAT("\r\nAT+QILOCIP\r\n\r\n", "Ready", "OK" , "ERROR",2);	
      }
    }
		SendAT("\r\nAT+QSCLK=1\r\n\r\n", "Ready", "OK" , "ERROR",5);
//		SendAT("\r\nAT+QISTAT\r\n\r\n", "Ready", "OK" , "ERROR",5);	
		SendAT("\r\nAT+CSQ\r\n\r\n", "Ready", "OK" , "ERROR",4);	
		SendAT("\r\nAT+QIOPEN=\"TCP\",\"104.236.203.4\",\"5556\"\r\n\r\n","CONNECT","ERROR","FAIL",10);	
		network=0;
    //osMutexWait(tcp_mutex_id, osWaitForever);
    if (start_thead != 0){
    osSignalWait (0x0001, osWaitForever); // wait forever for the signal 0x0001
    osSignalClear (tid_Thread_GSM, 0x0001);
		}start_thead = 1;
    TCP_Send("\r\nAT+QISEND\r\n\r\n\r\n",g_u8SendData,">","ERROR","SEND OK",10);	
    //osMutexRelease(tcp_mutex_id);     

		if(network == 1)
		{
      Save_FS();
      SendAT_GPS("\r\n\r\nAT+QGNSSRD=\"NMEA/RMC\"\r\n\r\n\r\n", "MGPSSTATUS", "OK" , "ERROR",5);	
      signal2 = osSignalSet (tid_Thread_GNSS, 0x0002);
      osDelay(10);    
			SendAT("\r\nAT+QICLOSE\r\n\r\n","CLOSE OK\r\n","ERROR","FAIL",10);	
			SendAT("\r\nAT+QDSIM=0\r\n\r\n", "OK", "NOT INSERTED" , "ERROR",10);
			SendAT("\r\nAT+CFUN=0\r\n\r\n", "OK", "NOT INSERTED" , "ERROR",10);
			SendAT("\r\nAT+CFUN=1\r\n\r\n", "Ready", "NOT INSERTED" , "ERROR",10);	
      manualdelay(200);
    }
		else
		{
      SendAT_GPS("\r\n\r\nAT+QGNSSRD=\"NMEA/RMC\"\r\n\r\n\r\n", "MGPSSTATUS", "OK" , "ERROR",5);	
      signal2 = osSignalSet (tid_Thread_GNSS, 0x0002);
      osDelay(10);    
//      if(life > 1500){
//        SYS_UnlockReg();
//        SYS->IPRST_CTL1 |= SYS_IPRST_CTL1_CHIP_RST_Msk; 
//      }
			//osDelay(5000);                                         // suspend thread
		}

  }
 //   osThreadYield ();                                           // suspend thread
  
}
