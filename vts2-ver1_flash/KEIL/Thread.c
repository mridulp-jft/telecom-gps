#include "NUC200Series.h"
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
extern void TCP_Send_ch(char * tcpcommand,char * tcpdataq, char * tcpresponse1, char * tcpresponse2, char * tcpresponse3, int32_t tcptimeout);
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
char debug_at[200] ={0};
char IP[100];
char PORT[6];
extern int8_t charging, cpinready, cregready;
char fileinstance[20] = {0};
char ph_num[15] = {0};
char sender_num[15] = {0};
extern float	u32ADC0Result;
extern int32_t tmr0sec;

extern osMutexId	(uart_mutex_id); // Mutex ID
extern osMutexId	(tcp_mutex_id); // Mutex ID

osThreadId tid_Thread;                                          // thread id
osThreadId tid_Thread1;                                         // thread id
osThreadDef (Thread, osPriorityNormal, 1, 2050);                  // thread object
osThreadDef (Thread1, osPriorityNormal, 1, 4048);               // thread object
//extern typedef struct os_mutex_cb fs_mutex_id;
extern char imei[25];
int t1=0;
int t2=0;
//uint_8t ignstat = 0;
__inline void strreplace(char s[], char chr, char repl_chr);
extern char temp[100];
void Save_FS(void);
extern __inline void manualdelay(int delayms);
extern __inline void Send_FS(void);
extern __inline int count_char(char ch,char* string);
extern  int qfread(char* fi);
extern uint8_t sendfs;
extern int32_t g_u8RecDataptr;
extern uint8_t mainla;
extern uint8_t th1la;
extern uint8_t th2la;
extern uint8_t idla;
extern char * r1;
extern char * r2;
extern char * r3;
extern int motion;
extern char RI;
extern int imeiptr;
extern int imeiptr0;
static int pt=0;
extern char SrcArray[256];
extern char DestArray[256];
void smsrequest(int _case, char* arg1, char* arg2){
  char *sn = sender_num+3;
  int go = 0;
  switch(_case){
    case 1:

      osMutexWait(uart_mutex_id, osWaitForever);
      tmr0sec = 0;
      g_u8RecDataptr=0;
      memset(g_u8RecData,0,RXBUFSIZE);
      r1=0;
      r2=0;
      r3=0;
      clear();
      printf("\r\nAT+CPBR=4\r\n\r\n");
      do{
        r1 = strstr(g_u8RecData, ">");
        r2 = strstr(g_u8RecData, "OK");
        r3 = strstr(g_u8RecData, "ERROR");
      }while(!(r1 || r2 || r3 ||((tmr0sec >= 5))));	 //!(r1 || r2 || r3 ||
      
      if(strstr(g_u8RecData,"SOWNER"))go=1;
      else go=0;
      osMutexRelease(uart_mutex_id);

      if(go == 1){
        SendAT("\r\nAT+CPBS=\"SM\"\r\n\r\n", "OK", "ERROR", "CME", 5);
        memset(temp, 0, 100);
        sprintf(temp, "\r\nAT+CPBW=1,\"%s\",129,\"OWNER1\"\r\n\r\n",arg1);
        SendAT(temp, "OK", "ERROR", "CME", 5);

        SendAT("\r\nAT+CPBS=\"ME\"\r\n\r\n", "OK", "ERROR", "CME", 5);
        memset(temp, 0, 100);
        sprintf(temp, "\r\nAT+CPBW=1,\"%s\",129,\"OWNER1\"\r\n\r\n",arg1);    
        SendAT(temp, "OK", "ERROR", "CME", 5);
      }
    
      break;
    case 2:
      
      osMutexWait(uart_mutex_id, osWaitForever);
      tmr0sec = 0;
      g_u8RecDataptr=0;
      memset(g_u8RecData,0,RXBUFSIZE);
      r1=0;
      r2=0;
      r3=0;
      clear();
      printf("\r\nAT+CPBR=4\r\n\r\n");
      do{
        r1 = strstr(g_u8RecData, ">");
        r2 = strstr(g_u8RecData, "OK");
        r3 = strstr(g_u8RecData, "ERROR");
      }while(!(r1 || r2 || r3 ||((tmr0sec >= 5))));	 //!(r1 || r2 || r3 ||
      
      if(strstr(g_u8RecData,"SOWNER"))go=1;
      else go=0;
      osMutexRelease(uart_mutex_id);

      if(go == 1){
      SendAT("\r\nAT+CPBS=\"SM\"\r\n\r\n", "OK", "ERROR", "CME", 5);
      memset(temp, 0, 100);
      sprintf(temp, "\r\nAT+CPBW=2,\"%s\",129,\"OWNER2\"\r\n\r\n",arg1);
      SendAT(temp, "OK", "ERROR", "CME", 5);

      SendAT("\r\nAT+CPBS=\"ME\"\r\n\r\n", "OK", "ERROR", "CME", 5);
      memset(temp, 0, 100);
      sprintf(temp, "\r\nAT+CPBW=2,\"%s\",129,\"OWNER2\"\r\n\r\n",arg1);        
      SendAT(temp, "OK", "ERROR", "CME", 5);
      }

      break;
    case 3:
      
      osMutexWait(uart_mutex_id, osWaitForever);
      tmr0sec = 0;
      g_u8RecDataptr=0;
      memset(g_u8RecData,0,RXBUFSIZE);
      r1=0;
      r2=0;
      r3=0;
      clear();
      printf("\r\nAT+CPBR=4\r\n\r\n");
      do{
        r1 = strstr(g_u8RecData, ">");
        r2 = strstr(g_u8RecData, "OK");
        r3 = strstr(g_u8RecData, "ERROR");
      }while(!(r1 || r2 || r3 ||((tmr0sec >= 5))));	 //!(r1 || r2 || r3 ||
      
      if(strstr(g_u8RecData,"SOWNER"))go=1;
      else go=0;
      osMutexRelease(uart_mutex_id);

      if(go == 1){    
      SendAT("\r\nAT+CPBS=\"SM\"\r\n\r\n", "OK", "ERROR", "CME", 5);
      memset(temp, 0, 100);
      sprintf(temp, "\r\nAT+CPBW=3,\"%s\",129,\"OWNER3\"\r\n\r\n",arg1);
      SendAT(temp, "OK", "ERROR", "CME", 5);

      SendAT("\r\nAT+CPBS=\"ME\"\r\n\r\n", "OK", "ERROR", "CME", 5);
      memset(temp, 0, 100);
      sprintf(temp, "\r\nAT+CPBW=3,\"%s\",129,\"OWNER3\"\r\n\r\n",arg1);        
      SendAT(temp, "OK", "ERROR", "CME", 5);
      }

      break;
    case 4:

      SendAT("\r\nAT+CPBS=\"SM\"\r\n\r\n", "OK", "ERROR", "CME", 5);
      memset(temp, 0, 100);
      sprintf(temp, "\r\nAT+CPBW=4,\"%s\",129,\"SOWNER\"\r\n\r\n",arg1);
      SendAT(temp, "OK", "ERROR", "CME", 5);

      SendAT("\r\nAT+CPBS=\"ME\"\r\n\r\n", "OK", "ERROR", "CME", 5);
      memset(temp, 0, 100);
      sprintf(temp, "\r\nAT+CPBW=4,\"%s\",129,\"SOWNER\"\r\n\r\n",arg1);        
      SendAT(temp, "OK", "ERROR", "CME", 5);
      break;
    case 5:
      
      break;
    case 6:
        osMutexWait(uart_mutex_id, osWaitForever);
        tmr0sec = 0;
        g_u8RecDataptr=0;
        memset(g_u8RecData,0,RXBUFSIZE);
        printf("%c",0x1A);
        clear();
        printf(arg2);
        do{
        }while(!(((tmr0sec >= 5))));
        
        memset(debug_at, 0 ,200);
        strcat(debug_at, g_u8RecData);
        remove_all_chars(debug_at, '\r', '\r');

        tmr0sec = 0;
        g_u8RecDataptr=0;
        memset(g_u8RecData,0,RXBUFSIZE);
        r1=0;
        r2=0;
        r3=0;
        clear();
        printf("\r\nAT+CMGF=1\r\n\r\n");
        do{
          r1 = strstr(g_u8RecData, ">");
          r2 = strstr(g_u8RecData, "OK");
          r3 = strstr(g_u8RecData, "ERROR");
        }while(!(r1 || r2 || r3 ||((tmr0sec >= 5))));	 //!(r1 || r2 || r3 ||
        

        tmr0sec = 0;
        g_u8RecDataptr=0;
        memset(g_u8RecData,0,RXBUFSIZE);
        r1=0;
        r2=0;
        r3=0;
        clear();
        printf("\r\nAT+CSCS=\"GSM\"\r\n\r\n");
        do{
          r1 = strstr(g_u8RecData, ">");
          r2 = strstr(g_u8RecData, "OK");
          r3 = strstr(g_u8RecData, "ERROR");
        }while(!(r1 || r2 || r3 ||((tmr0sec >= 5))));	 //!(r1 || r2 || r3 ||
        
       
        tmr0sec = 0;
        g_u8RecDataptr=0;
        memset(g_u8RecData,0,RXBUFSIZE);
        r1=0;
        r2=0;
        r3=0;
        clear();
        printf("\r\nAT+CMGS=\"%s\"\r\n\r\n",arg1);
        do{
          r1 = strstr(g_u8RecData, ">");
          r2 = strstr(g_u8RecData, "OK");
          r3 = strstr(g_u8RecData, "ERROR");
        }while(!(r1 || r2 || r3 ||((tmr0sec >= 5))));	 //!(r1 || r2 || r3 ||

        if(strstr(g_u8RecData, ">")){
        
          tmr0sec = 0;
          g_u8RecDataptr=0;
          memset(g_u8RecData,0,RXBUFSIZE);
          r1=0;
          r2=0;
          r3=0;
          clear();
          printf(debug_at);  
          printf("%c%c%c%c%c",0x1A,0x1A,0x1A,0x1A,0x1A);
          do{
            r1 = strstr(g_u8RecData, "CMGS");
            r2 = strstr(g_u8RecData, "OK");
            r3 = strstr(g_u8RecData, "ERROR");
          }while(!(r1 || r2 || r3 ||((tmr0sec >= 5))));	 //!(r1 || r2 || r3 ||
        }
        osMutexRelease(uart_mutex_id);

      break;
    case 7:
        memset(IP,0,100);
        parse_g(g_u8RecData, 1, 1, '(', ')' , IP);
        memset(PORT,0,6);
        parse_g(g_u8RecData, 2, 2, '(', ')' , PORT);    
      break;
    case 8:
        PE5 = 0; //ignstate = 1;save_ign();      
      break;
    case 9:
        PE5 = 1; //ignstate = 1;save_ign();      
      break;
    case 10:
      
      break;
    default:
      
      break;
    
  }
}


__inline void save_ign(){
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
//~`
  strreplace(g_u8SendData, '~', 'C');  
  strreplace(g_u8SendData, '`', 'H');  
  strreplace(g_u8SendData, 0x1A, '\n');  
	memset(temp,0,100);
	sprintf(temp,"\r\nAT+QFWRITE=%s,%d,3\r\n",fileinstance,(len));
	SendAT(temp, "CONNECT", "OK" , "ERROR",2);	
  len = strlen(g_u8SendData);
  remove_all_chars(g_u8SendData,'\r',0x1A);
  SendAT_FS(g_u8SendData, "QWRITE", "OK" , "ERROR",20);	
  if(strstr(g_u8RecData,"+QFWRITE"))
  {
    memset(g_u8SendData,0,TXBUFSIZE);
  }
 
  fileclose();
  
     memset(temp,0,100);
 		sprintf(temp,",ALIVE,F=%.1f,~`,LIFE=%d\n\n",u32ADC0Result,life);
  
//		parse_g(g_u8RecData, 2, 10, 'C', ',' , temp);
		strcat(g_u8SendData,imei);
		strcat(g_u8SendData,",");
		strcat(g_u8SendData,temp);
		memset(temp,0,100);
  
  
  
	osMutexRelease(uart_mutex_id);
  
  
  
  
}


void imei_fun(){
//  osMutexWait(tcp_mutex_id, osWaitForever);
  osMutexWait(uart_mutex_id, osWaitForever);
  clear();
  r1=0;
	r2=0;
	r3=0;
	g_u8RecDataptr=0;
	memset(g_u8RecData,0,RXBUFSIZE);
	printf("%c",0x1A);
   memset(imei,0,50);
    tmr0sec=0;
		printf("\r\n\r\nAT+GSN\r\n\r\n");
		do{
			r1 = strstr(g_u8RecData, "OK");
			r2 = strstr(g_u8RecData, "ERROR");
			r3 = strstr(g_u8RecData, "CME");
		}while(!(r1 || r2 || r3 || ((tmr0sec >= 5))));	 //!(r1 || r2 || r3 ||
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
      
    
    osMutexRelease(uart_mutex_id);
///    osMutexRelease(tcp_mutex_id);
}

void sms_mc60(void){
  int smsreq=0;
  if(RI == 1){
	osDelay(100);
  SendAT("\r\nAT+CMGF=1\r\n\r\n", "Ready", "OK" , "ERROR",10);	    
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
	printf("\r\nAT+CMGR=1,0\r\n\r\n");
//  send_string_to_uart1("\r\nAT\r\n");
	do{
		r1 = strstr(g_u8RecData, "OK");
		r2 = strstr(g_u8RecData, "ERROR");
		r3 = strstr(g_u8RecData, "NOT INSERTED");
	}while(!(r1 || r2 || r3 ||((tmr0sec >= 5))));	 //!(r1 || r2 || r3 ||
   if(!(r1 || r2 || r3))
    {
      PA13=1;
      {
        printf("\r\nAT+CFUN=1,1\r\n");//, "Ready", "CME" , "ERROR",5);	
        fileclose();
        fileopen();
        printf("\r\nAT+QGNSSC=1\r\n\r\n");
      }
      PA13=0;
    }
    r1=r2=r3=0;   

      memset(sender_num,0,15);
      parse_g(g_u8RecData,3,4,'"','"',sender_num);    
    
    
    if(strstr(g_u8RecData,"IP")){
      smsreq = 7;
    }  
    else if(strstr(g_u8RecData,"IGNITION OFF")){
      smsreq = 8;
    }
    else if(strstr(g_u8RecData,"IGNITION ON")){
      smsreq = 9;
    }
    else if(strstr(g_u8RecData,"OWNER1")){
      smsreq = 1;
      memset(ph_num,0,15);
      parse_g(g_u8RecData,1,1,'(',')',ph_num);      
    }
    else if(strstr(g_u8RecData,"OWNER2")){
      smsreq = 2;
      memset(ph_num,0,15);
      parse_g(g_u8RecData,1,1,'(',')',ph_num);            
    }
    else if(strstr(g_u8RecData,"OWNER3")){
      smsreq = 3;
      memset(ph_num,0,15);
      parse_g(g_u8RecData,1,1,'(',')',ph_num);            
    }
    else if(strstr(g_u8RecData,"SUOWNER")){
      smsreq = 4;
      memset(ph_num,0,15);
      parse_g(g_u8RecData,1,1,'(',')',ph_num);            
    }    
    else if(strstr(g_u8RecData,"START")){
      smsreq = 5;
    }       
    else if(strstr(g_u8RecData,"DEBUG")){
      smsreq = 6;
      memset(debug_at,0,200);
      parse_g(g_u8RecData,1,1,'(',')',debug_at); 
      strcat(debug_at,"\r\n\r\n");
      memset(ph_num,0,15);
      parse_g(g_u8RecData,3,4,'"','"',ph_num); 
      
    }           
    
  RI=0; 
    
  osMutexRelease(uart_mutex_id);
  SendAT("\r\nAT+CMGD=1,4\r\n\r\n", "OK", "ERROR", "7103", 10);

  smsrequest(smsreq, ph_num, debug_at);
  osDelay(10);
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
//~`
  strreplace(g_u8SendData, '~', 'C');  
  strreplace(g_u8SendData, '`', 'H');  
  strreplace(g_u8SendData, 0x1A, '\n');  
	memset(temp,0,100);
	sprintf(temp,"\r\nAT+QFWRITE=%s,%d,3\r\n",fileinstance,(len));
	SendAT(temp, "CONNECT", "OK" , "ERROR",2);	
  len = strlen(g_u8SendData);
  remove_all_chars(g_u8SendData,'\r',0x1A);
  SendAT_FS(g_u8SendData, "QWRITE", "OK" , "ERROR",20);	
//////////////////////////////////////  

//////////////////////////////  
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
//  tid_Thread1 = osThreadCreate (osThread(Thread1), NULL);
//  if (!tid_Thread) return(-1);
  
  return(0);
}

void Thread (void const *argument) 
{
  while (1) 
	{
    
      mainla = 0;
      th1la = 1;  
      th2la = 0; 
      idla = 0;
      sms_mc60();
   
    if(motion!=0){
//    SendAT("\r\n\r\nAT+QGNSSRD=\"NMEA/GGA\"\r\n\r\n\r\n", "MGPSSTATUS", "OK" , "ERROR",10);	
    SendAT_GPS("\r\n\r\nAT+QGNSSRD=\"NMEA/RMC\"\r\n\r\n\r\n", "MGPSSTATUS", "OK" , "ERROR",10);	
    SpiFlash_WaitReady();
    memset(SrcArray,0,256);
    strcat(SrcArray, g_u8SendData);
    SpiFlash_PageProgram(SrcArray, pt, 256);
    memset(DestArray,256,0);
    SpiFlash_WaitReady();

    SpiFlash_ReadData(DestArray, pt, 256);
    pt+=256;
   }
    else{
    imei_fun();
		strcat(g_u8SendData,imei);
		strcat(g_u8SendData,",");
		strcat(g_u8SendData,"ALIVE");
		memset(temp,0,100);
		sprintf(temp,",F=%.1f",u32ADC0Result);
		strcat(g_u8SendData,temp);
		memset(temp,0,100);
		sprintf(temp,",~`,LIFE=%d\n",life);
		strcat(g_u8SendData,temp);
    }
      if(life > 1800){
        printf("\r\nAT+CFUN=1,1\r\n\r\n");
        SYS_UnlockReg();
        SYS->IPRSTC1 = SYS_IPRSTC1_CHIP_RST_Msk;
      }
   // suspend thread
    osDelay(4900);
    osDelay(10);
  }
}




void Thread1 (void const *argument)
{
	while (1) 
	{
    mainla = 0;
    th1la = 0;
    th2la = 1;  
    idla = 0;
		SendAT("\r\nAT+CFUN=1\r\n\r\n", "OK", "NOT INSERTED" , "ERROR",1);	
    osDelay(100);
    
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
        SendAT("\r\nAT+QILOCIP\r\n\r\n", "z", "OK" , "ERROR",2);	
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
 
      manualdelay(500);
    }
		else
		{
      if(life > 1800){
        printf("\r\nAT+CFUN=1,1\r\n\r\n");
        SYS_UnlockReg();
        SYS->IPRSTC1 = SYS_IPRSTC1_CHIP_RST_Msk;
      }
      osDelay(32000);                                         // suspend thread
		}
  }
}


void strreplace(char s[], char chr, char repl_chr)
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
        SendAT("\r\nAT+CGREG?\r\n\r\n", "Ready", "OK" , "ERROR",5);	
        SendAT("\r\nAT+QIREGAPP=\"isafe\"\r\n\r\n", "Ready", "OK" , "ERROR",5);	
        SendAT("\r\nAT+QIREGAPP\r\n\r\n", "Ready", "OK" , "ERROR",2);	
        SendAT("\r\nAT+QIACT\r\n\r\n", "Ready", "OK" , "ERROR",5);	
        SendAT("\r\nAT+QILOCIP\r\n\r\n", "Ready", "OK" , "ERROR",2);	
      }
    }
 }

void fileclose(void)
{
    memset(temp,0,100);
    sprintf(temp,"\r\nAT+QFCLOSE=%s\r\n\r\n",fileinstance);
    SendAT(temp, "+CME ERROR", "OK" , "ERROR",10);
    memset(fileinstance,0,20);
}
 
void fileopen(void)
{
  if(strlen(fileinstance) == 0)
  {
    SendAT("\r\nAT+QFOPEN=\"LOG.TXT\",0\r\n", "Ready", "OK" , "ERROR",10);	
    if(strstr(g_u8RecData,"CME ERROR"))
    {
        PA13=1;
        printf("\r\nAT+CFUN=1,1\r\n");//, "Ready", "CME" , "ERROR",5);	
        PA13=0;
        memset(fileinstance,0,20);
    SendAT("\r\nAT+QFOPEN=\"LOG.TXT\",0\r\n", "Ready", "OK" , "ERROR",10);	
    }
    parse_g(g_u8RecData, 1, 2, ' ', '\n' , fileinstance);
    remove_all_chars(fileinstance, '\r', '\n');   
    SendAT("\r\nAT+QGNSSC=1\r\n\r\n", "OK", "ERROR", "7103", 5);
  }
}

 
 