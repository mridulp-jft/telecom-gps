
#include "stdio.h"
#include "cmsis_os.h"                                           // CMSIS RTOS header file
#include "NUC100Series.h"


/************************global variables**********************/
int motion = 0;

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
/***************************************************************/
/************************EXTERN FUNCTIONS***********************/
__inline void manualdelay(int delayms);

extern void SendAT(char * command, char * response1, char * response2, char * response3, int32_t timeout);
extern void SendAT_FS(char * command, char * response1, char * response2, char * response3, int32_t timeout);
extern void TCP_Send_ch(char * tcpcommand,char * tcpdataq, char * tcpresponse1, char * tcpresponse2, char * tcpresponse3, int32_t tcptimeout);
extern void SendAT_GPS_WO_MUTEX(char * command, char * response1, char * response2, char * response3, int32_t timeout);
extern void TCP_Send_ch(char * tcpcommand,char * tcpdataq, char * tcpresponse1, char * tcpresponse2, char * tcpresponse3, int32_t tcptimeout);
extern void TCP_Send(char * tcpcommand,char * tcpdata, char * tcpresponse1, char * tcpresponse2, char * tcpresponse3, int32_t tcptimeout);
extern void SendAT_GPS(char * command, char * response1, char * response2, char * response3, int32_t timeout);

/***************************************************************/




/*----------------------------------------------------------------------------
 *      Thread 1 'Thread_Name': Sample thread
 *---------------------------------------------------------------------------*/
 
void GSM (void const *argument);                             // thread function
void GNSS (void const *argument); 

osThreadId tid_Thread_GSM;                                          // thread id
osThreadDef (GSM, osPriorityNormal, 1, 0);                   // thread object
osThreadId tid_Thread_GNSS;                                          // thread id
osThreadDef (GNSS, osPriorityNormal, 1, 0);                   // thread object

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
    if(motion!=0){
    SendAT_GPS("\r\n\r\nAT+QGNSSRD=\"NMEA/RMC\"\r\n\r\n\r\n", "MGPSSTATUS", "OK" , "ERROR",10);	
    osDelay(4900);
   }      // suspend thread
    osDelay(10);
  }
}

void GSM (void const *argument) {

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
        SendAT("\r\nAT+QIREGAPP=\"isafe\"\r\n\r\n", "Ready", "OK" , "ERROR",5);	
        SendAT("\r\nAT+QIREGAPP\r\n\r\n", "Ready", "OK" , "ERROR",5);	
        SendAT("\r\nAT+QIACT\r\n\r\n", "Ready", "OK" , "ERROR",5);	
        SendAT("\r\nAT+QILOCIP\r\n\r\n", "Ready", "OK" , "ERROR",2);	
      }
    }
		SendAT("\r\nAT+QSCLK=1\r\n\r\n", "Ready", "OK" , "ERROR",5);
//		SendAT("\r\nAT+QISTAT\r\n\r\n", "Ready", "OK" , "ERROR",5);	
		SendAT("\r\nAT+CSQ\r\n\r\n", "Ready", "OK" , "ERROR",4);	
		SendAT("\r\nAT+QIOPEN=\"TCP\",\"104.236.203.4\",\"5556\"\r\n\r\n","CONNECT","ERROR","FAIL",10);	
		network=0;
		TCP_Send("\r\nAT+QISEND\r\n\r\n\r\n",g_u8SendData,">","ERROR","SEND OK",10);	

		if(network == 1)
		{
      Save_FS();
  //    Send_FS();
			SendAT("\r\nAT+QICLOSE\r\n\r\n","CLOSE OK\r\n","ERROR","FAIL",10);	
			SendAT("\r\nAT+CFUN=0\r\n\r\n", "OK", "NOT INSERTED" , "ERROR",10);
			SendAT("\r\nAT+CFUN=1\r\n\r\n", "Ready", "NOT INSERTED" , "ERROR",10);	
 
      manualdelay(200);
    }
		else
		{
//      if(life > 1500){
//        SYS_UnlockReg();
//        SYS->IPRST_CTL1 |= SYS_IPRST_CTL1_CHIP_RST_Msk; 
//      }
			osDelay(32000);                                         // suspend thread
		}
  }
 //   osThreadYield ();                                           // suspend thread
  
}
