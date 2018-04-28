/*----------------------------------------------------------------------------
 * CMSIS-RTOS 'main' function template
 *---------------------------------------------------------------------------*/

#define osObjectsPublic                     // define objects in main module
#include "osObjects.h"                      // RTOS object definitions

/****************************************************************************
 * @file     main.c
 * @version  V2.00
 * $Revision: 1 $
 * $Date: 14/12/08 11:50a $
 * @brief    Transmit and receive data from PC terminal through RS232 interface.
 * @note
 * Copyright (C) 2014 Nuvoton Technology Corp. All rights reserved.
 *
 ******************************************************************************/
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <cstdlib.h>
#include "NUC100Series.h"
#include "WinboundFlash.h"
#include "preprocessor.h"
#include "i2c.h"
//*********configuration variables**************
    uint32_t u32BusClock;
int16_t OUT_Y_H_A,  OUT_X_H_A,  OUT_Z_H_A, OUT_X_L_A, OUT_Y_L_A, OUT_Z_L_A, STATUS_REG_A, CTRL_REG4_A;
int ay,ax,az = -1;
int simselect = 0; 
char IP1[50] = "104.236.203.4";
char PORT1[10] = "5556";
char IP2[50] = "159.89.254.53";
char PORT2[10] = "5556";
char vehicleregnum[15] = "DL15AN1234";
char apn1[20] = "airtelgprs.com";
char apn2[20] = "internet";
volatile float overspeed = 0, harshacc = 0,harshbrake = 0,rashturn = 0; 
extern volatile int wakeinterval_emer;
extern volatile int sleepinterval_i0;
extern volatile int sleepinterval_i1;
volatile int ring = 0;
extern float readpt;
extern volatile int tc;
extern volatile int loginpacket;
extern volatile int32_t tmr0sec;
extern volatile int ignition;
extern volatile int emergencystatus;  
extern int tcpsendchtimer;
extern volatile char tamperalert;
extern char emernum1[15];
extern char emernum2[15];
extern char networkoperator[30];

extern uint8_t alertid;
extern int fix;
volatile int g_u32AdcIntFlag;
volatile int netselect;

//**********************************************
uint8_t tmr1sec;
volatile uint8_t wetmr = 0;
volatile int interval_count = 0;
volatile int interval_count_health = 0;
extern volatile int sleepinterval_health;
char firmwaresize[20] = 0;
char messagedata[200];
volatile uint8_t input1, input2, input3, input4;

/*---------------------------------------------------------------------------------------------------------*/
/* Extern variables                                                                                        */
/*---------------------------------------------------------------------------------------------------------*/

#ifdef OBD
extern char suppportedpid[100][7];
#endif
extern volatile int pidcounter;

/*---------------------------------------------------------------------------------------------------------*/
/* Global variables                                                                                        */
/*---------------------------------------------------------------------------------------------------------*/

char g_u8SendData[TXBUFSIZE] = {0};
char g_u8RecData[RXBUFSIZE]	= {0};
char g_u8OBDSendData[OBDTXBUFSIZE] = {0};
char g_u8OBDRecData[OBDRXBUFSIZE]	= {0};
uint8_t g_u8OBDRecDataptr=0;
int MidDid;
volatile int parameterupgrade = 0;
volatile uint32_t g_u32comRbytes = 0;
volatile uint32_t g_u32comRhead  = 0;
volatile uint32_t g_u32comRtail  = 0;
volatile int32_t g_bWait         = TRUE;
volatile int notsentcounter= 0;
volatile int triggeruart = 0;
/*---------------------------------------------------------------------------------------------------------*/
/* Define functions prototype                                                                              */
/*---------------------------------------------------------------------------------------------------------*/
int32_t main(void);
__inline void send_sms(char* num, char* content);
__inline void SYS_Init(void);
__inline void UARTs_Init();
extern void TCP_Send_ch(char * tcpcommand,char * tcpdataq, char * tcpresponse1, char * tcpresponse2, char * tcpresponse3, int32_t tcptimeout);
void TMR0_IRQHandler(void);
void UART1_IRQHandler(void);
void UART02_IRQHandler(void);
void sms_mc60(void);
__inline void Init_IOs();
__inline void OBD_GET_PID();
__inline uint8_t I2C_Write(uint16_t u16Address, uint8_t u8Data);
__inline uint8_t I2C_Read(uint16_t u16Address);
int saveipconfigurations(void);
void readipconfigurations(void);
void smsrequest(int _case, char* arg1, char* arg2);
__inline void sendalert();
__inline void hextoascii(char* string, int len);
__inline void networkswitch();
/*---------------------------------------------------------------------------------------------------------*/
/* Extern variables                                                                              */
/*---------------------------------------------------------------------------------------------------------*/

extern void cregquerry(void);
extern void Save_FS(void);
extern volatile int32_t g_u8RecDataptr;
extern int Init_Thread (void);
extern void manualdelay(int delayms);
extern void SendAT(char * command, char * response1, char * response2, char * response3, int32_t timeout);
extern void SendAT_FS(char * command, char * response1, char * response2, char * response3, int32_t timeout);
extern void TCP_Send_ch(char * tcpcommand,char * tcpdataq, char * tcpresponse1, char * tcpresponse2, char * tcpresponse3, int32_t tcptimeout);
extern void SendAT_GPS_WO_MUTEX(char * command, char * response1, char * response2, char * response3, int32_t timeout);
extern void TCP_Send_ch(char * tcpcommand,char * tcpdataq, char * tcpresponse1, char * tcpresponse2, char * tcpresponse3, int32_t tcptimeout);
extern void TCP_Send(char * tcpcommand,char * tcpdata, char * tcpresponse1, char * tcpresponse2, char * tcpresponse3, int32_t tcptimeout);extern void Init_Timers (void);
extern void send_OBD(char * command, char * response1, char * response2, char * response3, int32_t timeout);
extern void SendAT_GPS(char * command, char * response1, char * response2, char * response3, int32_t timeout);
extern void parse_g(char* str, int first, int sec, char f, char s , char *string);
extern float batteryvoltagethreshold;
extern __inline void remove_all_chars(char* str, char c, char d);
extern void supportedpid(char command[5]);
extern  void cpinquerry();
extern int8_t charging, cpinready, cregready;
extern volatile int8_t  network;
extern float pt = 0;
extern volatile int start_thead;
extern osThreadId tid_Thread_OBD_READ;                                          // thread id
//extern osThreadId tid_Thread_GSM;                                          // thread id
osThreadId mainThreadID;
extern int32_t signal;
extern int32_t signal2;
//extern char suppportedpid[200][7];
extern char DestArray[257];
extern uint8_t sendfs;
extern volatile int breaker;
extern volatile uint8_t timeoutflag;
extern char fileinstance[20];
extern char lastlocation[50];
char sender_num[15] = 0;
char ph_num[15] = 0;
extern char imei[25];
char configdata[300];
char filename[10] = "2.1.0.bin";
volatile uint32_t g_u8IsWDTTimeoutINT;
volatile uint32_t g_u32WWDTINTCount = 0;

extern char temp[100];
int updatefirmware = 0;
int8_t i2ctimeout=0;
osMutexDef (uart_mutex);		// Declare mutex
osMutexId	(uart_mutex_id); // Mutex ID	
osMutexDef (tcp_mutex);		// Declare mutex
osMutexId	(tcp_mutex_id); // Mutex ID
osMutexDef (fs_mutex);		// Declare mutex
osMutexId	(fs_mutex_id); // Mutex ID		

volatile uint8_t g_u8DeviceAddr = 0x6B;
volatile uint8_t g_au8TxData[3];
volatile uint8_t g_u8RxData;
volatile uint8_t g_u8DataLen;
volatile uint8_t g_u8EndFlag = 0;
volatile uint32_t u32Status = 0;
/*
 * main: initialize and start the system
 */
int main (void) {

  SYS_UnlockReg();                          // Unlock Registers
  SYS_Init();                               // Initialise System
  SYS_LockReg();                            // Lock Registers
  TIMER0->TCMPR = ((SystemCoreClock / 3) / 1);
  TIMER0->TCSR = TIMER_TCSR_IE_Msk | TIMER_PERIODIC_MODE;
  TIMER_SET_PRESCALE_VALUE(TIMER0, 0);
  NVIC_EnableIRQ(TMR0_IRQn);
  TIMER_Start(TIMER0);
  ADC_Open(ADC, ADC_ADCR_DIFFEN_SINGLE_END, ADC_ADCR_ADMD_CONTINUOUS, 0x7f);
  ADC_POWER_ON(ADC);
  ADC_EnableInt(ADC, ADC_ADF_INT);  
  NVIC_EnableIRQ(ADC_IRQn);

  Open_SPI_Flash();         
  // Initialise SPI Flash  
  //Init_Timers();                            // Initialise Timers
  osKernelInitialize ();                    // initialise CMSIS-RTOS

  SYS_UnlockReg();
  g_u8IsWDTTimeoutINT = 0;
  WWDT_Open(WWDT_PRESCALER_768, 0x20, TRUE);  
  WDT_EnableInt();
  NVIC_EnableIRQ(WDT_IRQn);  
  SYS_LockReg();                            // Lock Registers

  //Init_IOs();                               // Initialise Input/Outputs
  UARTs_Init();                             // Initialise UARTs
  osKernelStart ();                         // start thread execution 

  MidDid = SpiFlash_ReadMidDid();
  MidDid = SpiFlash_ReadMidDid();
  #ifdef OBD
    OBD_GET_PID();
  #endif
  mainThreadID = osThreadGetId();
//Init_Thread ();
//SpiFlash_ChipErase();
//pt = readpt = 0;
//saveipconfigurations();

memset(temp,0,100);
//SendAT("\r\nAT+CFUN=1,1\r\n", "OK", "NOT INSERTED" , "ERROR",5);
sprintf(temp,"\r\nAT+**********************************%s*******************************\r\n\r\n", firmwareversion);
SendAT(temp, "OK", "NOT INSERTED" , "ERROR",5);
SendAT(temp, "OK", "NOT INSERTED" , "ERROR",5);

SendAT("\r\nAT+QSCLK=1\r\n\r\n", "Ready", "OK" , "ERROR",5);
SendAT("\r\nAT+QSTK?\r\n\r\n", "OK", "NOT INSERTED" , "ERROR",5);
SendAT("\r\nAT+QSTK=1\r\n\r\n", "OK", "NOT INSERTED" , "ERROR",5);
//send_sms("8287324005", "I am Rudra");
//accgyroconfig();
//saveipconfigurations();
//readipconfigurations();
  while (1) {
    //saveipconfigurations();
    readipconfigurations();
    netselect = 2;
//    memset(IP1,0,50);memset(PORT1,0,10);
//    memset(IP2,0,50);memset(PORT2,0,10);
//    memset(apn1,0,20);
//    memset(apn2,0,20);
//    strcat(apn1, "airtelgprs.com");
//    strcat(apn2, "internet");
//    
//    strcat(IP1, "104.236.203.4");
//    strcat(IP2, "159.89.254.53");
//    strcat(PORT1, "5556");
//    strcat(PORT2, "5556");
//    saveipconfigurations();

    

//    memset(configdata,0,300);
//    parse_g(configdata,1,2,'"','"',g_u8RecData);
//    hextoascii(configdata,strlen(configdata));

//    SendAT("\r\nAT\r\n\r\n", "OK", "NOT INSERTED" , "ERROR",5);
//    SendAT("\r\nAT\r\n\r\n", "OK", "NOT INSERTED" , "ERROR",5);
//    SendAT("\r\nAT\r\n\r\n", "OK", "NOT INSERTED" , "ERROR",5);
//    SendAT("\r\nAT\r\n\r\n", "OK", "NOT INSERTED" , "ERROR",5);
    
    
    
    
    if(netselect == 1){
    SendAT("\r\nAT+QDSIM=0\r\n\r\n", "OK", "NOT INSERTED" , "ERROR",5);
    }else{
    SendAT("\r\nAT+QDSIM=1\r\n\r\n", "OK", "NOT INSERTED" , "ERROR",5); 
    }
  
    
    SendAT_GPS("\r\n\r\nAT+QGNSSRD=\"NMEA/RMC\"\r\n\r\n\r\n", "MGPSSTATUS", "OK" , "ERROR",5);	
    if(network == 1){
      cpinquerry();
      if(cpinready==1){
        cregquerry();
        if(cregready == 1){
          
            SendAT("\r\nAT+CGREG?\r\n\r\n", "Ready", "OK" , "ERROR",5);
            if(netselect == 1){
              SendAT("\r\nAT+STKTR=\"810301218082028281830100\"\r\n", "+STKPCI: 0", "NAK" , "NAK",2);   //international
              manualdelay(5);
              memset(configdata,0,300);
              parse_g(g_u8RecData,3,4,'"','"',configdata);  
              hextoascii(configdata,strlen(configdata));
              // Switch to international .  You need to give command AT+STKTR="810301240082028281830100900101"  For National Switch
              if(strstr(DestArray,"National(ON)")){
                simselect = 1;
              }else if(strstr(DestArray,"International(ON)")){
                simselect = 2;
              }else{
                SendAT("\r\nAT+STKENV=\"D30782020181900101\"\r\n", "+STKPCI: 0", "NAK" , "NAK",5);
                manualdelay(5);
                memset(configdata,0,300);
                parse_g(g_u8RecData,3,4,'"','"',configdata);  
                hextoascii(configdata,strlen(configdata));
                // Switch to international .  You need to give command AT+STKTR="810301240082028281830100900101"  For National Switch
                if(strstr(DestArray,"National(ON)")){
                  simselect = 1;
                }else if(strstr(DestArray,"International(ON)")){
                  simselect = 2;
                }
              }
              //parse_g(g_u8RecData, 1,2, '"', '"' , networkoperator);  
              memset(temp,0,100);
              if(simselect == 1){
                sprintf(temp,"\r\nAT+QIREGAPP=\"%s\",\"\",\"\"\r\n\r\n",apn1);
              }else if(simselect == 2){
                sprintf(temp,"\r\nAT+QIREGAPP=\"%s\",\"\",\"\"\r\n\r\n",apn2);          
              }
            }else{
              sprintf(temp,"\r\nAT+QIREGAPP=\"%s\",\"\",\"\"\r\n\r\n","iot.com");      
            }
            SendAT(temp, "Ready", "OK" , "ERROR",5);	
            SendAT("\r\nAT+QIACT\r\n\r\n", "Ready", "OK" , "ERROR",10);	
            if(timeoutflag != 0){
                PB15 = 0;
                manualdelay(1);
                PB15 = 1;
                manualdelay(100);      
                SendAT("\r\nAT\r\n", "ERROR", "OK" , "4010",10);
            }
         
          
          if(updatefirmware == 1){
            SendAT("\r\nAT+QIFGCNT=0\r\n\r\n", "OK", "NOT INSERTED" , "ERROR",5);
            SendAT("\r\nAT+QICSGP=1,\"www\"\r\n\r\n", "OK", "NOT INSERTED" , "ERROR",5);
            SendAT("\r\nAT+CGATT=1\r\n\r\n", "Ready", "OK" , "ERROR",10);	        
            SendAT("\r\nAT+QIACT\r\n\r\n", "Ready", "OK" , "ERROR",20);	    
            SendAT("\r\nAT+QFTPCLOSE\r\n\r\n", "+QFTPCLOSE:", "NOT INSERTED" , "ERROR",5);
            SendAT("\r\nAT+QFTPUSER=\"telecomftp\"\r\n\r\n", "OK", "NOT INSERTED" , "ERROR",5);
            SendAT("\r\nAT+QFTPPASS=\"test321\"\r\n\r\n", "OK", "NOT INSERTED" , "ERROR",5);
            SendAT("\r\nAT+QFTPOPEN=\"159.65.145.181\",45000\r\n\r\n", "+QFTPOPEN:", "NOT INSERTED" , "ERROR",5);
            SendAT("\r\nAT+QFTPCFG=4,\"/UFS\/fw.bin\"\r\n\r\n", "QFTPCFG:", "NOT INSERTED" , "ERROR",5);
            SendAT("\r\nAT+QFTPPATH=\"/\"\r\n\r\n", "QFTPPATH:", "NOT INSERTED" , "ERROR",5);      
            memset(temp,0,100);
            manualdelay(200);
            sprintf(temp,"\r\nAT+QFTPSIZE=\"\/files\/%s\"\r\n",filename);
            SendAT(temp, "+QFTPSIZE:-", "NOT INSERTED" , "ERROR",10);
            memset(firmwaresize,0,20);
            parse_g(g_u8RecData,1,4,':','\n',firmwaresize);
            remove_all_chars(firmwaresize,'\r','\n');
            memset(temp,0,100);  
            manualdelay(100);          
            sprintf(temp,"\r\nAT+QFTPGET=\"\/files\/%s\"\r\n",filename);
            SendAT(temp, firmwaresize, "+QFTPGET:-" , "ERROR",60);
            memset(temp,0,100);
            parse_g(g_u8RecData,1,4,':','\n',temp);
            remove_all_chars(temp,'\r','\n');
            
            if((!(mystrstr(temp,'-'))) && (!(mystrstr(temp,'-')))){
              if(strcmp(temp,firmwaresize) == 0){
                memset(messagedata,0,200);
                sprintf(messagedata,"Proceeding to upgrade version %s",filename);
                send_sms(sender_num, messagedata);                
                //updatefirmware = 0;
                SYS_UnlockReg();                          // Unlock Registers
                SYS->IPRSTC1 = 0x1; /* Reset MCU */
              }else{
                SendAT("\r\nAT+CFUN=1,1\r\n\r\n", "OK", "NOT INSERTED" , "ERROR",5);       
              }
            }
          }
        }
      }
    }

    memset(temp,0,100);
    sprintf(temp,"\r\nAT+QIOPEN=0,\"TCP\",\"%s\",\"%s\"\r\n\r\n",IP1,PORT1);
    SendAT(temp,"CONNECT","ERROR","FAIL",10);
    if((network == 1) && strstr(g_u8RecData,"CONNECT OK")){
      memset(temp,0,100);
      sprintf(temp,"\n\n$%s$%s$%s$%s$%s\n%c",vehicleregnum,imei,firmwareversion,frameformat,lastlocation,0x1A);
      loginpacket = 1;
      TCP_Send("\r\nAT+QISEND=0\r\n\r\n\r\n",temp,">","ERROR","SEND OK",10);	
      loginpacket = 0;
    }    
    memset(temp,0,100);
    sprintf(temp,"\r\nAT+QIOPEN=1,\"TCP\",\"%s\",\"%s\"\r\n\r\n",IP2,PORT2);
    SendAT(temp,"CONNECT","ERROR","FAIL",10);
    if((network == 1) && strstr(g_u8RecData,"CONNECT OK")){
      memset(temp,0,100);
      sprintf(temp,"$%s$%s$%s$%s$%s\n%c",vehicleregnum,imei,firmwareversion,frameformat,lastlocation,0x1A);
      loginpacket = 1;      
      TCP_Send("\r\nAT+QISEND=0\r\n\r\n\r\n",temp,">","ERROR","SEND OK",10);	
      loginpacket = 0;
    }   
    network=0;
    sendfs = 0; 
    sms_mc60();    
    TCP_Send("\r\nAT+QISEND=0\r\n\r\n\r\n",g_u8SendData,">","ERROR","SEND OK",10);	
    breaker = 0;
    if(sendfs==1){
      TCP_Send_ch("\r\nAT+QISEND\r\n\r\n",g_u8SendData,">","ERROR","SEND OK",5);	
    }
   
    if(network == 1){
      notsentcounter++;
      sendalert();
      if(breaker == 1)SendAT_GPS("\r\n\r\nAT+QGNSSRD=\"NMEA/RMC\"\r\n\r\n\r\n", "MGPSSTATUS", "OK" , "ERROR",5);	
      if(notsentcounter >  10 && netselect == 1){
        notsentcounter = 0;
        networkswitch();
      }
      if(netselect == 1){
        SendAT("\r\nAT+QDSIM=0\r\n\r\n", "OK", "NOT INSERTED" , "ERROR",5);
      }else{
        SendAT("\r\nAT+QDSIM=1\r\n\r\n", "OK", "NOT INSERTED" , "ERROR",5); 
      }
      SendAT("\r\nAT+QICLOSE=0\r\n\r\n","CLOSE OK\r\n","ERROR","FAIL",10);	
      SendAT("\r\nAT+QICLOSE=1\r\n\r\n","CLOSE OK\r\n","ERROR","FAIL",10);	
      SendAT("\r\nAT+CFUN=0\r\n\r\n", "OK", "NOT INSERTED" , "ERROR",10);
      SendAT("\r\nAT+CFUN=1\r\n\r\n", "SMS Ready", "NOT INSERTED" , "ERROR",10);	
      //osDelay(2000);
      Save_FS();
      SendAT("\r\nAT+QIDEACT\r\n\r\n", "OK", "DEACT OK" , "ERROR",10);
      SendAT("\r\nAT+QIMODE=0\r\n\r\n", "OK", "NOT INSERTED" , "ERROR",5);
      SendAT("\r\nAT+QIMUX?\r\n\r\n", "OK", "NOT INSERTED" , "ERROR",5);	
      SendAT("\r\nAT+QIMUX=1\r\n\r\n", "OK", "NOT INSERTED" , "ERROR",5);
      //manualdelay(200);
    }
    else{
      // Keep looping...
      //        if(interval_count > 10000)interval_count = 0;     
//        if(interval_count_health > 10000)interval_count_health = 0;     
//        if(tc > 10000)tc = 0;     
//        if(tmr0sec > 10000)tmr0sec = 0;     
//        if(tcpsendchtimer > 10000)tcpsendchtimer = 0;     
//        if(i2ctimeout > 10000)i2ctimeout = 0;
    }
  }
}

__inline void networkswitch(){
 
  _NETSWITCH:
  PB15 = 0;
  manualdelay(1);
  PB15 = 1;
  manualdelay(100);      
  SendAT("\r\nAT\r\n", "+STKPCI", "NAK" , "NAK",40);
  manualdelay(100);
  SendAT("\r\nAT+COPS?\r\n", "OK", "NAK" , "NAK",40);
  // Set Menu 2500 is for Set Menu .
  SendAT("\r\nAT+STKTR=\"810301250082028281830100\"\r\n", "+STKPCI:", "NAK" , "NAK",40);
  manualdelay(50);
  // Check which SIM Network is Current.
  SendAT("\r\nAT+STKENV=\"D30782020181900101\"\r\n", "+STKPCI: 0", "NAK" , "NAK",40);
  manualdelay(50);
  memset(configdata,0,300);
  parse_g(g_u8RecData,3,4,'"','"',configdata);  
  hextoascii(configdata,strlen(configdata));
  // Switch to international .  You need to give command AT+STKTR="810301240082028281830100900101"  For National Switch
  if(strstr(DestArray,"National(ON)")){
    simselect = 1;
    SendAT("\r\nAT+STKTR=\"810301240082028281830100900102\"\r\n", "+STKPCI: 0", "NAK" , "NAK",40);   //international
  }else if(strstr(DestArray,"International(ON)")){
    simselect = 2;
    SendAT("\r\nAT+STKTR=\"810301240082028281830100900101\"\r\n", "+STKPCI: 0", "NAK" , "NAK",40);   //National     
  }else{
    goto _NETSWITCH;
  }      
  manualdelay(50);
  memset(configdata,0,300);
  parse_g(g_u8RecData,3,4,'"','"',configdata);
  hextoascii(configdata,strlen(configdata));
  if(simselect == 1){
    if(!strstr(DestArray,"ACTIVATE the INTERNATIONAL")){
      goto _NETSWITCH;
    }
  }      
  if(simselect == 2){
    if(!strstr(DestArray,"ACTIVATE the HOME")){
      goto _NETSWITCH;
    }
  }      
  // Give Confirmation '
  SendAT("\r\nAT+STKTR=\"810301218082028281830100\"\r\n", "+STKPCI: 0", "NAK" , "NAK",40);   //international
  manualdelay(50);
  memset(configdata,0,300);
  parse_g(g_u8RecData,3,4,'"','"',configdata);    
  hextoascii(configdata,strlen(configdata));
  if(!strstr(DestArray, "Refreshing.")){
    goto _NETSWITCH;
  }    
  // Here you need to reset the module you can use power reset
  PB15 = 0;
  manualdelay(1);
  PB15 = 1;
  manualdelay(100);      
  SendAT("\r\nAT\r\n", "+STKPCI: 0", "NAK" , "NAK",40);
  manualdelay(100);   
}

__inline void accgyroconfig(void){

  //I2C_Write(0x0D,0x01);
  //I2C_Write(0x0E,0x01);
//  I2C_Write(0x11,0x60);
  
  
  
  
  
}

__inline int binTwosComplementToSignedDecimal(int data,int significantBits) 
{
    int power = pow(2,significantBits-1);
    int sum = 0;
    int i;
    int j = 0;
    int signbit = 0;
    const size_t BITS = 8*sizeof(data);
    char binary[BITS+1];
    char newbin[BITS+1];
    memset(newbin,0,BITS+1);
    data -= 1;
    for(i=0; i<BITS; i++)
    {
      unsigned int mask = 1u << (BITS - 1 - i);
      binary[i] = (data & mask) ? '1' : '0';
    }
    binary[BITS] = '\0'; 
    i = 0;
    while(binary[i] != '1'){i++;}
    
    while(binary[i] != '\0'){
      newbin[j] = binary[i];
      i++;j++;
    }
    
    signbit = strlen(newbin);
    signbit-=1;
    for(i = 0; i <= signbit; i++){
    
      if(newbin[i] == '1'){
          if( i == 0){
            sum += pow(-2,signbit-i);
          }
          else{
            sum += pow(2, signbit-i);
          }
      }
   
    } 
    return sum;
}
void readaccgyrodata(void){
 
  I2C_Write(0x10,0x60);
  I2C_Write(0x11,0x60);  
  I2C_Write(0x20, 0x67);  
/*
    Let’s use FS ±2 g as an example sensitivity level.  As the range is -2 to +2, this would be a total of 4g.  Or 4,000 Milli-Gs.
    The output is 16 bits. 16 bits equals 65,535.   This means we can get 65,535 different readings for the range  between -2 and +2. (or -2,000 MilliGs and +2,000 MilliGs)
    4,000 MilliGs / 65,535 = 0.061
    Each time the LSB changes by one, the value changes by 0.061, which is the value highlighted in blue in the table above.
*/
  STATUS_REG_A = I2C_Read(0x1E);
  if(1){
    ax = ((I2C_Read(0x29) << 8) | I2C_Read(0x28))*0.061;
    //OUT_X_L_A = I2C_Read(0x28); 
    ay = ((I2C_Read(0x2B) << 8) | I2C_Read(0x2A))*0.061;
    //OUT_Y_L_A = I2C_Read(0x2A); 
    az = ((I2C_Read(0x2D) << 8) | I2C_Read(0x2C))*0.061;
    //OUT_Z_L_A = I2C_Read(0x2C);   
    ax = binTwosComplementToSignedDecimal(ax, 16);
    ay = binTwosComplementToSignedDecimal(ay, 16);
    az = binTwosComplementToSignedDecimal(az, 16);
  }
  
}

__inline uint8_t I2C_Write(uint16_t u16Address, uint8_t u8Data)
{
  u32Status=0;
  I2C_SET_CONTROL_REG(I2C0, I2C_I2CON_STA );
  i2ctimeout = 0;
  while((u32Status != 0x08) && (i2ctimeout == 0)){
    u32Status = I2C_GET_STATUS(I2C0);   
  }    //ST ack
  I2C_SET_DATA(I2C0, ((g_u8DeviceAddr << 1)));   
  I2C_SET_CONTROL_REG(I2C0, I2C_I2CON_SI);
  i2ctimeout = 0;while((u32Status != 0x18) && (i2ctimeout == 0)){
    u32Status = I2C_GET_STATUS(I2C0);   
  }    //SAD+W ack
  I2C_SET_DATA(I2C0, ((u16Address) ));   
  I2C_SET_CONTROL_REG(I2C0, I2C_I2CON_SI);  
  i2ctimeout = 0;while((u32Status != 0x28) && (i2ctimeout == 0)){
    u32Status = I2C_GET_STATUS(I2C0);   
  }    //SAK 
  u32Status = 0;
  I2C_SET_DATA(I2C0, ((u8Data)));  
  I2C_SET_CONTROL_REG(I2C0, I2C_I2CON_SI);  
  i2ctimeout = 0;while((u32Status != 0x28) && (i2ctimeout == 0)){
    u32Status = I2C_GET_STATUS(I2C0);   
  }    
  I2C_SET_CONTROL_REG(I2C0, I2C_I2CON_STO | I2C_I2CON_SI);  
  return 0;
}

/**
 * @brief       This function do the I2C data reading from EEPROM device.
 *
 * @param[in]   u16Address  An address of EEPROM that will be read.
 *
 * @return      The data be read out.
 */
__inline uint8_t I2C_Read(uint16_t u16Address){
  I2C_SET_CONTROL_REG(I2C0, I2C_I2CON_STA );
  i2ctimeout = 0;
  //osDelay(10);
  u32Status = I2C_GET_STATUS(I2C0);
  while((u32Status != 0x08) && (i2ctimeout == 0)){
    u32Status = I2C_GET_STATUS(I2C0);    
  }
  I2C_SET_DATA(I2C0, ((g_u8DeviceAddr << 1)| (0x00)));   
  I2C_SET_CONTROL_REG(I2C0, I2C_I2CON_SI);
  i2ctimeout = 0;
  while((u32Status != 0x18) && (i2ctimeout == 0)){
    u32Status = I2C_GET_STATUS(I2C0);
  }
  //osDelay(10);
  
  I2C_SET_DATA(I2C0, ((u16Address)));   
  I2C_SET_CONTROL_REG(I2C0, I2C_I2CON_SI);  
  i2ctimeout = 0;
  while((u32Status != 0x28) && (i2ctimeout == 0)){
    u32Status = I2C_GET_STATUS(I2C0);    
  }
  //osDelay(10);
  
  I2C_SET_CONTROL_REG(I2C0, I2C_I2CON_STA | I2C_I2CON_SI);
  i2ctimeout = 0;
  while((u32Status != 0x10) && (i2ctimeout == 0)){
    u32Status = I2C_GET_STATUS(I2C0);
  }    
  //osDelay(10);

  I2C_SET_DATA(I2C0, ((g_u8DeviceAddr << 1) | (0x01) ));   
  I2C_SET_CONTROL_REG(I2C0, I2C_I2CON_SI);
  i2ctimeout = 0;
  while((u32Status != 0x40) && (i2ctimeout == 0)){
    u32Status = I2C_GET_STATUS(I2C0);    
  }
  //osDelay(10);

  I2C_SET_CONTROL_REG(I2C0, I2C_I2CON_SI);  
  i2ctimeout = 0;
  while((u32Status != 0x58) && (i2ctimeout == 0)){
    u32Status = I2C_GET_STATUS(I2C0);    
  }
  //osDelay(1);

  g_u8RxData = I2C_GET_DATA(I2C0);
  I2C_SET_CONTROL_REG(I2C0, I2C_I2CON_STO | I2C_I2CON_SI);  
  return g_u8RxData;
}




__inline void sms_mc60(void){
  int smsreq=0;
  int del = 0;
  if(ring = 1){
	//osDelay(100);
  manualdelay(10);
  SendAT("\r\nAT+CMGF=1\r\n\r\n", "Ready", "OK" , "ERROR",10);	
  SendAT("\r\nAT+CMGR=1,0\r\n\r\n", "NAK", "NSK" , "ERROR",2);
    if(!strstr(g_u8RecData, "+CMGR:")){del = 1;}
  memset(sender_num,0,15);
  parse_g(g_u8RecData,3,4,'"','"',sender_num);    
  memset(messagedata,0,200);
    if(strstr(g_u8RecData,"SETIP1")){
      parameterupgrade = 1;
      memset(IP1,0,50);
      memset(PORT1,0,10);
      parse_g(g_u8RecData,9,10,'"','"',IP1);
      parse_g(g_u8RecData,11,12,'"','"',PORT1);
      saveipconfigurations();
      sprintf(messagedata,"IP1 %s,PORT1 %s configured and saved",IP1,PORT1);
      send_sms(sender_num, messagedata);
    }  
    else if(strstr(g_u8RecData,"SETIP2")){
      parameterupgrade = 1;
      memset(IP2,0,50);
      memset(PORT2,0,10);
      parse_g(g_u8RecData,9,10,'"','"',IP2);
      parse_g(g_u8RecData,11,12,'"','"',PORT2);    
      saveipconfigurations();
      sprintf(messagedata,"IP2 %s,PORT2 %s configured and saved",IP2,PORT2);
      send_sms(sender_num, messagedata); 
    }
    else if(strstr(g_u8RecData,"RESET")){
      SYS_UnlockReg();                          // Unlock Registers
      SYS->IPRSTC1 = 0x1; /* Reset MCU */      
    }
    else if(strstr(g_u8RecData,"SETAPN")){  
      parameterupgrade = 1;
      memset(apn1,0,20);
      memset(apn2,0,20);
      parse_g(g_u8RecData,9,10,'"','"',apn1);
      parse_g(g_u8RecData,11,12,'"','"',apn2);
      saveipconfigurations();
      sprintf(messagedata,"APN \"%s\",\"%s\" configured and saved",apn1,apn2);
      send_sms(sender_num, messagedata);      

    }
    else if(strstr(g_u8RecData,"SETSLEEPTIME")){   
      parameterupgrade = 1;
      memset(temp,0,100);
      parse_g(g_u8RecData,9,10,'"','"',temp);
      sleepinterval_i1 = atoi(temp);
      memset(temp,0,100);
      parse_g(g_u8RecData,11,12,'"','"',temp);
      sleepinterval_i0 = atoi(temp);      
      saveipconfigurations();   
      sprintf(messagedata,"IgnON:%d IgnOFF:%d freq. configured and saved",sleepinterval_i1,sleepinterval_i0);
      send_sms(sender_num, messagedata);        
    }
    else if(strstr(g_u8RecData,"SETHEALTHINTERVAL")){   
      parameterupgrade = 1;
      memset(temp,0,100);
      parse_g(g_u8RecData,9,10,'"','"',temp);
      sleepinterval_health = atoi(temp);
      saveipconfigurations();      
      sprintf(messagedata,"Health freq %d configured and saved",sleepinterval_health);
      send_sms(sender_num, messagedata);         
    }   
    else if(strstr(g_u8RecData,"SETEMERGENCYTIME")){   
      parameterupgrade = 1;
      memset(temp,0,100);
      parse_g(g_u8RecData,9,10,'"','"',temp);
      wakeinterval_emer = atoi(temp);
      saveipconfigurations();      
      sprintf(messagedata,"Emergency interval %d configured and saved",wakeinterval_emer);
      send_sms(sender_num, messagedata);         
    }      
    else if(strstr(g_u8RecData,"SETOVERSPEEDLIMIT")){  
      parameterupgrade = 1;
      memset(temp,0,100);
      parse_g(g_u8RecData,9,10,'"','"',temp);
      overspeed = atof(temp);
      saveipconfigurations();  
      sprintf(messagedata,"Overspeed alert on:%.2f km/h configured and saved",overspeed);
      send_sms(sender_num, messagedata);            
    }
    else if(strstr(g_u8RecData,"SETHARSHACCTHRESH")){
      parameterupgrade = 1;
      memset(temp,0,100);
      parse_g(g_u8RecData,9,10,'"','"',temp);
      harshacc = atof(temp);
      saveipconfigurations();  
      sprintf(messagedata,"Harsh Acc alert on:%.2f m/s2 configured and saved",harshacc);
      send_sms(sender_num, messagedata);       
    }
    else if(strstr(g_u8RecData,"SETHARSHBRAKETHRESH")){
      parameterupgrade = 1;
      memset(temp,0,100);
      parse_g(g_u8RecData,9,10,'"','"',temp);
      harshbrake = atof(temp);
      saveipconfigurations(); 
      sprintf(messagedata,"Harsh brake alert on:%.2f m/s2 configured and saved",harshbrake);
      send_sms(sender_num, messagedata);        
    }
    else if(strstr(g_u8RecData,"SETRASHTURNTHRESH")){
      parameterupgrade = 1;
      memset(temp,0,100);
      parse_g(g_u8RecData,9,10,'"','"',temp);
      rashturn = atof(temp);
      saveipconfigurations(); 
      sprintf(messagedata,"Rash turn alert on:%.2f rad/s configured and saved",rashturn);
      send_sms(sender_num, messagedata);       
    } 
    else if(strstr(g_u8RecData,"SETLICPLATE")){
      parameterupgrade = 1;
      memset(vehicleregnum,0,15);
      parse_g(g_u8RecData,9,10,'"','"',vehicleregnum);
      saveipconfigurations();    
      sprintf(messagedata,"Licence plate \"%s\" configured and saved",vehicleregnum);
      send_sms(sender_num, messagedata);         
    } 
    else if(strstr(g_u8RecData,"FOTA")){
      memset(filename,0,10);
      parse_g(g_u8RecData,9,10,'"','"',filename);  
      updatefirmware =1;

    }       
    else if(strstr(g_u8RecData,"DEBUG")){
      smsreq = 6;
      memset(temp,0,100);
      parse_g(g_u8RecData,1,1,',',',',temp); 
      strcat(temp,"\r\n\r\n");
      memset(ph_num,0,15);
      parse_g(g_u8RecData,3,4,'"','"',ph_num);  
    }       
    else if(strstr(g_u8RecData,"SETBATTHRESHOLD")){
      parameterupgrade = 1;
      memset(temp,0,100);
      parse_g(g_u8RecData,9,10,'"','"',temp);  
      batteryvoltagethreshold = atoi(temp); 
    }
    else if(strstr(g_u8RecData,"SETNETSELECT")){
      parameterupgrade = 1;
      memset(temp,0,100);
      parse_g(g_u8RecData,9,10,'"','"',temp);  
      netselect = atoi(temp); 
    }     
    else if(strstr(g_u8RecData,"GETIMEI")){
      send_sms(sender_num, imei);
    }         
    else if(strstr(g_u8RecData,"GETNMEA")){
      SendAT("\r\nAT+QGNSSRD?\r\n\r\n", "Ready", "OK" , "ERROR",10);	
    }         
  ring=0;  
  if(del == 0){
    manualdelay(100);
    SendAT("\r\nAT+CMGD=1,4\r\n\r\n", "OK", "ERROR", "7103", 10);
    }
  }
}

__inline void send_sms(char* num, char* content){
  SendAT("\r\nAT+CSCS=\"GSM\"\r\n\r\n", "OK", "ERROR", "7103", 10);
  SendAT("\r\nAT+CSCA?\r\n\r\n", "OK", "ERROR", "7103", 10);
  SendAT("\r\nAT+CMGF=1\r\n\r\n", "OK", "ERROR", "7103", 10);  
  memset(temp,0,100);
  sprintf(temp,"AT+CMGS=\"%s\"\r\n",num);
  SendAT(temp, "ERROR", "ERROR", ">", 10);
  tmr0sec=0;
  g_u8RecDataptr=0;
  memset(g_u8RecData,0,RXBUFSIZE);
  clear();
  printf(content);
  printf("%c",0x1A); 
  printf("%c",0x1A); 
  printf("%c",0x1A); 
  do{
  g_u8RecData[0] = '\r';
	}while(!(strstr(g_u8RecData, "OK") || strstr(g_u8RecData, "ERROR") || strstr(g_u8RecData, "CME") ||((tmr0sec >= 5))));	 //!(r1 || r2 || r3 ||
  //SendAT("\r\nAT+CMGD=1,4\r\n\r\n", "OK", "ERROR", "7103", 10);

}

void smsrequest(int _case, char* arg1, char* arg2){
  char *sn = sender_num+3;
  int go = 0;
  switch(_case){
    case 1:
      break;
    case 2:
      break;
    case 3:
      break;
    case 4:
      break;
    case 5:
      break;
    case 6:
      break;
    case 7:
      break;
    case 8:
      break;
    case 9:
      break;
    case 10:
      break;
    default:
      break;
    
  }
}


int saveipconfigurations(void){
  int retry = 1;
  int len;
  while(retry == 1){
    memset(fileinstance,0,20);
    SendAT("\r\nAT+QFDEL=\"IPCONFIG.TXT\"\r\n", "ERROR", "OK" , "4010",10);
    while(strstr(g_u8RecData,"ERROR")){
      //SendAT("\r\nAT+CFUN=1,1\r\n\r\n", "ERROR", "OK" , "ERROR",1);
      PB15 = 0;
        manualdelay(1);
      PB15 = 1;
      manualdelay(100);      
      SendAT("\r\nAT\r\n", "ERROR", "OK" , "4010",10);
      manualdelay(200);
      SendAT("\r\nAT\r\n", "ERROR", "CFUN: " , "4010",10);
      SendAT("\r\nAT+QFLST=\"*\"\r\n", "ERROR", "OK" , "4010",10);
      if(strstr(g_u8RecData, "IPCONFIG.TXT")){
        SendAT("\r\nAT+QFDEL=\"IPCONFIG.TXT\"\r\n", "ERROR", "OK" , "4010",10);
        manualdelay(100);
      }else{
        break;
      }
      if(!strstr(g_u8RecData,"ERROR")){
        break;
      }        
    }        
    
    SendAT("\r\nAT+QFOPEN=\"IPCONFIG.TXT\",0\r\n", "ERROR", "OK" , "ERROR",10);
    if(strstr(g_u8RecData,"ERROR")){
      //SendAT("\r\nAT+CFUN=1,1\r\n\r\n", "ERROR", "OK" , "ERROR",1);
      PB15 = 0;
        manualdelay(1);
      PB15 = 1;
      manualdelay(100);      
      SendAT("\r\nAT\r\n", "ERROR", "OK" , "4010",10);
      manualdelay(20);
      SendAT("\r\nAT\r\n", "ERROR", "CFUN: " , "4010",10);
      SendAT("\r\nAT+QFOPEN=\"IPCONFIG.TXT\",0\r\n", "ERROR", "OK" , "ERROR",10);
      //manualdelay(10);
    
    }      
      parse_g(g_u8RecData, 1, 1, ' ', 'K' , fileinstance);
      remove_all_chars(fileinstance, '\r', '\n'); 
      remove_all_chars(fileinstance, 'O', 'K');   
    
    //seek to the origin 
    memset(temp,0,100);
    sprintf(temp, "AT+QFSEEK=%s,0,0\r\n\r\n", fileinstance);
    SendAT(temp, "CONNECT", "OK" , "ERROR",10);	  

    memset(configdata,0,300);
    sprintf(configdata,"|IP1|%s|P1|%s|IP2|%s|P2|%s|F_R_P|%.0f|F_W_P|%.0f|I1_NR|%d|L_PLT|%s|APN1|%s|OS|%.1f|HA|%.1f|HB|%.1f|RT|%.1f|I_HLT|%d|I0_NR|%d|I_EM|%d|B_V_T|%.1f|net|%d|APN2|%s|\n",\
                         IP1,PORT1,IP2,PORT2,readpt,pt,sleepinterval_i1,vehicleregnum,apn1,overspeed,harshacc,harshbrake,rashturn,sleepinterval_health,sleepinterval_i0,wakeinterval_emer,batteryvoltagethreshold,netselect,apn2);
    retry = 0;    
    len = strlen(configdata);
    
    memset(temp,0,100);
    sprintf(temp, "AT+QFWRITE=%s,%d\r\n\r\n", fileinstance,len);
    SendAT(temp, "CONNECT", "OK" , "ERROR",10);	    
    if(strstr(g_u8RecData, "CONNECT")){
      SendAT(configdata, "QFWRITE", "OK" , "ERROR",10);	 
      retry = 0;
    }
    memset(temp,0,100);
    sprintf(temp,"\r\nAT+QFCLOSE=%s\r\n\r\n",fileinstance);
    SendAT(temp, "+CME ERROR", "OK" , "ERROR",10);
    manualdelay(10);
  }
return 0;
}
__inline void readipconfigurations(void){
  int retry = 1;
  int len;
  char pt_c[10] = 0;
  char readpt_c[10] = 0;
  char interval_c[10] = 0;
  do{    
    manualdelay(10);
    memset(fileinstance,0,20);
    SendAT("\r\nAT+QFOPEN=\"IPCONFIG.TXT\",0\r\n", "ERROR", "OK\r\n" , "ERROR",10);	
    if(!strstr(g_u8RecData, "OK")){
      //SendAT("\r\nAT+CFUN=1,1\r\n\r\n", "ERROR", "OK" , "ERROR",1);
      PB15 = 0;
        manualdelay(1);
      PB15 = 1;
      manualdelay(100);      
      SendAT("\r\nAT\r\n", "ERROR", "OK" , "4010",10);
      manualdelay(20);
      SendAT("\r\nAT\r\n", "ERROR", "CFUN: " , "4010",10);
      SendAT("\r\nAT+QFOPEN=\"IPCONFIG.TXT\",0\r\n", "ERROR", "OK" , "ERROR",10);
      manualdelay(10);
    }
    parse_g(g_u8RecData, 1, 1, ' ', 'K' , fileinstance);
    remove_all_chars(fileinstance, '\r', '\n'); 
    remove_all_chars(fileinstance, 'O', 'K'); 
    if(strlen(fileinstance)<1)retry = 1;
    else{
      //seek to the origin 
      manualdelay(10);
      memset(temp,0,100);
      sprintf(temp, "AT+QFSEEK=%s,0,0\r\n\r\n", fileinstance);
      SendAT(temp, "CONNECT", "OK" , "ERROR",10);	    
      memset(temp,0,100);
      manualdelay(10);
      sprintf(temp, "AT+QFREAD=%s\r\n\r\n", fileinstance);
      SendAT(temp, "OK", "OK" , "ERROR",10);	    
      memset(IP1,0,50);
      memset(IP2,0,50);
      memset(PORT1,0,7);
      memset(PORT2,0,7);
      memset(pt_c,0,10);
      memset(readpt_c,0,10);
      memset(interval_c,0,10);
      memset(apn1,0,20);
      memset(apn2,0,20);
      parse_g(g_u8RecData, 2,3,'|','|', IP1);
      parse_g(g_u8RecData, 4,5,'|','|', PORT1);
      parse_g(g_u8RecData, 6,7,'|','|', IP2);
      parse_g(g_u8RecData, 8,9,'|','|', PORT2);
      parse_g(g_u8RecData, 10,11,'|','|', readpt_c);
      parse_g(g_u8RecData, 12,13,'|','|', pt_c);
      parse_g(g_u8RecData, 14,15,'|','|', interval_c);
      parse_g(g_u8RecData, 16,17,'|','|', vehicleregnum);      
      parse_g(g_u8RecData, 18,19,'|','|', apn1);   
      memset(temp,0,100);
      parse_g(g_u8RecData, 20,21,'|','|', temp);
      overspeed = atof(temp);
      memset(temp,0,100);
      parse_g(g_u8RecData, 22,23,'|','|', temp);
      harshacc = atof(temp);
      memset(temp,0,100);
      parse_g(g_u8RecData, 24,25,'|','|', temp);
      harshbrake = atof(temp);
      memset(temp,0,100);
      parse_g(g_u8RecData, 26,27,'|','|', temp);
      rashturn = atof(temp);
      memset(temp,0,100);
      parse_g(g_u8RecData, 28,29,'|','|', temp);
      sleepinterval_health = atoi(temp);
      memset(temp,0,100);
      parse_g(g_u8RecData, 30,31,'|','|', temp);
      sleepinterval_i0 = atoi(temp);   

      memset(temp,0,100);
      parse_g(g_u8RecData, 32,33,'|','|', temp);
      wakeinterval_emer=atoi(temp);
      
      memset(temp,0,100);
      parse_g(g_u8RecData, 34,35,'|','|', temp);
      batteryvoltagethreshold=atof(temp);   

      memset(temp,0,100);
      parse_g(g_u8RecData, 36,37,'|','|', temp);
      netselect=atoi(temp);   
      parse_g(g_u8RecData, 38,39,'|','|', apn2);   
      
   
      pt = atof(pt_c);
      readpt = atof(readpt_c);
      sleepinterval_i1 = atoi(interval_c); 
      memset(temp,0,100);
      sprintf(temp,"\r\nAT+QFCLOSE=%s\r\n\r\n",fileinstance);
      SendAT(temp, "+CME ERROR", "OK" , "ERROR",10);
      retry = 0;
    }
  }while(retry);
}


__inline void OBD_GET_PID(){
//  send_OBD("ATZ\r","HELLO","NODATA",">",5);
//  send_OBD("ATE1\r","HELLO","NODATA",">",5);
//  send_OBD("ATL1\r","HELLO","NODATA",">",5);
//  send_OBD("ATSP0\r","HELLO","NODATA",">",5);
//  send_OBD("ATDP\r","HELLO","NODATA",">",5);
//  send_OBD("ATRV\r","HELLO","NODATA",">",5);
//  send_OBD("0100\r","HELLO","NODATA",">",5);
//  send_OBD("0101\r","HELLO","NODATA",">",5);
//  send_OBD("010C\r","HELLO","NODATA",">",5);
//  send_OBD("010D\r","HELLO","NODATA",">",5);
//  send_OBD("0120\r","HELLO","NODATA",">",5);
//  memset(suppportedpid, 0, sizeof(char)*200*7);
//  //   if(!(strstr(g_u8OBDRecData,"UNABLE") || strstr(g_u8OBDRecData,"NO DATA"))){	
//  pidcounter=0;
//  supportedpid("0100\r\n");
//  supportedpid("0120\r\n");
//  supportedpid("0140\r\n");
//  supportedpid("0160\r\n");
//  supportedpid("0180\r\n");
//  supportedpid("01A0\r\n");
//  supportedpid("01C0\r\n");
//  supportedpid("050100\r\n");
//  supportedpid("0900\r\n");	
}
__inline void SYS_Init(void)
{
    /*---------------------------------------------------------------------------------------------------------*/
    /* Init System Clock                                                                                       */
    /*---------------------------------------------------------------------------------------------------------*/


    /* Enable Internal RC 22.1184MHz clock */
    CLK_EnableXtalRC(CLK_PWRCON_OSC22M_EN_Msk);

    /* Waiting for Internal RC clock ready */
    CLK_WaitClockReady(CLK_CLKSTATUS_OSC22M_STB_Msk);

    /* Switch HCLK clock source to Internal RC and HCLK source divide 1 */
    CLK_SetHCLK(CLK_CLKSEL0_HCLK_S_HIRC, CLK_CLKDIV_HCLK(1));

    /* Enable external XTAL 12MHz clock */
    CLK_EnableXtalRC(CLK_PWRCON_XTL12M_EN_Msk);

    /* Waiting for external XTAL clock ready */
    CLK_WaitClockReady(CLK_CLKSTATUS_XTL12M_STB_Msk);

    /* Set core clock as PLL_CLOCK from PLL */
    CLK_SetCoreClock(PLL_CLOCK);

    /* Enable UART module clock */
    CLK_EnableModuleClock(UART0_MODULE);

    /* Select UART module clock source */
    CLK_SetModuleClock(UART0_MODULE, CLK_CLKSEL1_UART_S_HIRC, CLK_CLKDIV_UART(1));
    
    /* Enable UART module clock */
    CLK_EnableModuleClock(UART1_MODULE);

    /* Select UART module clock source */
    CLK_SetModuleClock(UART1_MODULE, CLK_CLKSEL1_UART_S_HIRC, CLK_CLKDIV_UART(1));
    
    /* Enable UART module clock */
    CLK_EnableModuleClock(UART2_MODULE);

    /* Select UART module clock source */
    CLK_SetModuleClock(UART2_MODULE, CLK_CLKSEL1_UART_S_HIRC, CLK_CLKDIV_UART(1));

    /* Enable I2C0 module clock */
    CLK_EnableModuleClock(I2C0_MODULE);
    
    /* Set GPA multi-function pins for I2C0 SDA and SCL */
    SYS->GPA_MFP &= ~(SYS_GPA_MFP_PA8_Msk | SYS_GPA_MFP_PA9_Msk);
    SYS->GPA_MFP |= SYS_GPA_MFP_PA8_I2C0_SDA | SYS_GPA_MFP_PA9_I2C0_SCL;

    CLK_EnableModuleClock(WWDT_MODULE);         
    /* Select WWDT module clock source */
    CLK_SetModuleClock(WWDT_MODULE, CLK_CLKSEL2_WWDT_S_HCLK_DIV2048, NULL);    
    /* Select ADC module clock source */
    CLK_SetModuleClock(ADC_MODULE, CLK_CLKSEL1_ADC_S_HIRC, CLK_CLKDIV_ADC(7));
    CLK_EnableModuleClock(TMR0_MODULE);   
    CLK_SetModuleClock(TMR0_MODULE, CLK_CLKSEL1_TMR0_S_HXT, NULL);
   
    /* Reset I2C0 */
    SYS->IPRSTC2 |=  SYS_IPRSTC2_I2C0_RST_Msk;
    SYS->IPRSTC2 &= ~SYS_IPRSTC2_I2C0_RST_Msk;

    /* Enable I2C0 Controller */
    I2C0->I2CON |= I2C_I2CON_ENS1_Msk;

    /* I2C0 bus clock 100K divider setting, I2CLK = PCLK/(100K*4)-1 */
    u32BusClock = 100000;
    I2C0->I2CLK = (uint32_t)(((SystemCoreClock * 10) / (u32BusClock * 4) + 5) / 10 - 1); /* Compute proper divider for I2C clock */

    /* Get I2C0 Bus Clock */
    //printf("I2C clock %d Hz\n", (SystemCoreClock / (((I2C0->I2CLK) + 1) << 2)));

    /* Set I2C0 4 Slave Addresses */
    /* Slave Address : 0x15 */
    I2C0->I2CADDR0 = (I2C0->I2CADDR0 & ~I2C_I2CADDR_I2CADDR_Msk) | (0x15 << I2C_I2CADDR_I2CADDR_Pos);
    /* Slave Address : 0x35 */
    I2C0->I2CADDR1 = (I2C0->I2CADDR1 & ~I2C_I2CADDR_I2CADDR_Msk) | (0x35 << I2C_I2CADDR_I2CADDR_Pos);
    /* Slave Address : 0x55 */
    I2C0->I2CADDR2 = (I2C0->I2CADDR2 & ~I2C_I2CADDR_I2CADDR_Msk) | (0x55 << I2C_I2CADDR_I2CADDR_Pos);
    /* Slave Address : 0x75 */
    I2C0->I2CADDR3 = (I2C0->I2CADDR3 & ~I2C_I2CADDR_I2CADDR_Msk) | (0x75 << I2C_I2CADDR_I2CADDR_Pos);

    CLK_EnableModuleClock(ADC_MODULE);
    
    CLK_SetModuleClock(ADC_MODULE, CLK_CLKSEL1_ADC_S_HIRC, CLK_CLKDIV_ADC(7));


    /*---------------------------------------------------------------------------------------------------------*/
    /* Init I/O Multi-function                                                                                 */
    /*---------------------------------------------------------------------------------------------------------*/

    /* Set GPB multi-function pins for UART0 RXD and TXD */
    SYS->GPB_MFP &= ~(SYS_GPB_MFP_PB0_Msk | SYS_GPB_MFP_PB1_Msk);
    SYS->GPB_MFP |= SYS_GPB_MFP_PB0_UART0_RXD | SYS_GPB_MFP_PB1_UART0_TXD;
    
    /* Set GPB multi-function pins for UART1 RXD and TXD */
    SYS->GPB_MFP &= ~(SYS_GPB_MFP_PB4_Msk | SYS_GPB_MFP_PB5_Msk);
    SYS->GPB_MFP |= SYS_GPB_MFP_PB4_UART1_RXD | SYS_GPB_MFP_PB5_UART1_TXD;

    /* Set GPB multi-function pins for UART2 RXD and TXD */
    SYS->GPD_MFP &= ~(SYS_GPD_MFP_PD14_Msk | SYS_GPD_MFP_PD15_Msk);
    SYS->GPD_MFP |= SYS_GPD_MFP_PD14_UART2_RXD | SYS_GPD_MFP_PD15_UART2_TXD;

    /* Configure the GPA0 - GPA7   ADC analog input pins */
    SYS->GPA_MFP &= ~(SYS_GPA_MFP_PA0_Msk | SYS_GPA_MFP_PA1_Msk | SYS_GPA_MFP_PA2_Msk | SYS_GPA_MFP_PA3_Msk | SYS_GPA_MFP_PA4_Msk | SYS_GPA_MFP_PA5_Msk | SYS_GPA_MFP_PA6_Msk);
    SYS->GPA_MFP |= SYS_GPA_MFP_PA0_ADC0 | SYS_GPA_MFP_PA1_ADC1 | SYS_GPA_MFP_PA2_ADC2 | SYS_GPA_MFP_PA3_ADC3 | SYS_GPA_MFP_PA4_ADC4 | SYS_GPA_MFP_PA5_ADC5 | SYS_GPA_MFP_PA6_ADC6 ;
    SYS->ALT_MFP1 = 0;
    
    
    //digital input
    GPIO_SetMode(PA, BIT6, GPIO_PMD_INPUT);      //input 1
    GPIO_SetMode(PA, BIT14, GPIO_PMD_INPUT);      //input 1
    GPIO_EnableInt(PA, 14, GPIO_INT_LOW);
    NVIC_EnableIRQ(GPAB_IRQn);
    GPIO_SetMode(PA, BIT15, GPIO_PMD_INPUT);      //input 2
    GPIO_EnableInt(PA, 15, GPIO_INT_LOW);
    NVIC_EnableIRQ(GPAB_IRQn);
    GPIO_SetMode(PA, BIT12, GPIO_PMD_INPUT);      //input3
    GPIO_EnableInt(PA, 12, GPIO_INT_LOW);
    NVIC_EnableIRQ(GPAB_IRQn);
    GPIO_SetMode(PA, BIT13, GPIO_PMD_INPUT);      //input 4
    GPIO_EnableInt(PA, 13, GPIO_INT_LOW);
    NVIC_EnableIRQ(GPAB_IRQn);
    
    //digital input //ring, emergency, ignition, 
//    GPIO_SetMode(PB, BIT6, GPIO_PMD_INPUT);       //ring
//    GPIO_EnableInt(PB, 6, GPIO_INT_LOW);
//    NVIC_EnableIRQ(GPAB_IRQn);
    GPIO_SetMode(PB, BIT9, GPIO_PMD_INPUT);       //emerge5ncy
    GPIO_EnableInt(PB, 9, GPIO_INT_LOW);
    NVIC_EnableIRQ(GPAB_IRQn);
    GPIO_SetMode(PB, BIT10, GPIO_PMD_INPUT);      //ignition
    GPIO_EnableInt(PB, 10, GPIO_INT_LOW);
    NVIC_EnableIRQ(GPAB_IRQn);
    GPIO_SetMode(PB, BIT13, GPIO_PMD_INPUT);      //tamper
    GPIO_EnableInt(PB, 13, GPIO_INT_LOW);
    NVIC_EnableIRQ(GPAB_IRQn);    
    
    GPIO_SetMode(PB, BIT8, GPIO_PMD_OUTPUT);       
    GPIO_SetMode(PB, BIT15, GPIO_PMD_OUTPUT);       
    GPIO_SetMode(PA, BIT7, GPIO_PMD_OUTPUT);       
    
    GPIO_SetMode(PC, BIT2, GPIO_PMD_OUTPUT);       
    GPIO_SetMode(PC, BIT3, GPIO_PMD_OUTPUT);       
    GPIO_SET_DEBOUNCE_TIME(GPIO_DBCLKSRC_LIRC, GPIO_DBCLKSEL_32768);
    GPIO_ENABLE_DEBOUNCE(PB, BIT6 | BIT9 | BIT10 | BIT13 | BIT8 | BIT15);
    GPIO_ENABLE_DEBOUNCE(PA, BIT14 | BIT15 | BIT12 | BIT13 );
//    
    PB8 = 0;
}


__inline void sendalert(){
  switch(alertid){
        case 0:
          break;
        case 3:
          send_sms(emernum1, "Alert – Disconnect from main battery");
          send_sms(emernum2, "Alert – Disconnect from main battery");
          break;
        case 4:
          send_sms(emernum1, "Alert – Low battery");
          send_sms(emernum2, "Alert – Low battery");          
          break;
        case 5:
          send_sms(emernum1, "Alert – Low battery removed");
          send_sms(emernum2, "Alert – Low battery removed");          
          break;
        case 6:
          send_sms(emernum1, "Alert – Connect back to main battery");
          send_sms(emernum2, "Alert – Connect back to main battery");          
          break;
        case 7:
          send_sms(emernum1, "Alert – Ignition ON");
          send_sms(emernum2, "Alert – Ignition ON");          
          break;
        case 8:
          send_sms(emernum1, "Alert – Ignition OFF");
          send_sms(emernum2, "Alert – Ignition OFF");          
          break;
        case 9:
          send_sms(emernum1, "Alert – GPS box opened");
          send_sms(emernum2, "Alert – GPS box opened");          
          break;
        case 10:
          send_sms(emernum1, "Alert – Emergency state ON*");
          send_sms(emernum2, "Alert – Emergency state ON*");          
          break;
        case 11:
          send_sms(emernum1, "Alert – Emergency state OFF*");
          send_sms(emernum2, "Alert – Emergency state OFF*");          
          break;        
        case 12:
          send_sms(emernum1, "Alert – over the air parameter change*");
          send_sms(emernum2, "Alert – over the air parameter change");          
          break;    
        case 13:
          send_sms(emernum1, "Alert – Harsh Braking");
          send_sms(emernum2, "Alert – Harsh Braking*");          
          break;    
        case 14:
          send_sms(emernum1, "Alert – Harsh Acceleration");
          send_sms(emernum2, "Alert – Harsh Acceleration");          
          break;
        case 15:
          send_sms(emernum1, "Alert – Rash Turning");
          send_sms(emernum2, "Alert – Rash Turning");          
          break;    
  }
}

__inline void UARTs_Init()
{
    /*---------------------------------------------------------------------------------------------------------*/
    /* Init UART                                                                                               */
    /*---------------------------------------------------------------------------------------------------------*/
    /* Reset UART0 */
    SYS_ResetModule(UART0_RST);
    SYS_ResetModule(UART1_RST);
    SYS_ResetModule(UART2_RST);

    /* Configure UART0 and set UART0 Baudrate */
    UART_Open(UART0, 9600);             // ifdef DEBUG UART elseif RS232_1  
    UART_Open(UART1, 115200);           //MAIN UART MC60
    UART_Open(UART2, 9600);             // ifdef OBD UART elseif RS232_2
		UART_ENABLE_INT(UART1, (UART_IER_RDA_IEN_Msk ));
		NVIC_EnableIRQ(UART1_IRQn);  
		UART_ENABLE_INT(UART2, (UART_IER_RDA_IEN_Msk ));
		NVIC_EnableIRQ(UART02_IRQn);  
}

void UART1_IRQHandler(void)
{char uart1data;
    while(!UART_GET_RX_EMPTY(UART1)) 
    {
      uart1data = UART_READ(UART1);
      if(uart1data != '\0'){
        g_u8RecData[g_u8RecDataptr] = uart1data;
        g_u8RecDataptr++;
        if(g_u8RecDataptr > (RXBUFSIZE-10)){
          g_u8RecDataptr = 0;
        }
      tmr0sec=0;
      }
    }
}
void UART02_IRQHandler(void)
{
    while(!UART_GET_RX_EMPTY(UART2)) 
    {
      g_u8OBDRecData[g_u8OBDRecDataptr] = UART_READ(UART2);
      g_u8OBDRecDataptr++;
    }
}



__inline void Init_IOs(){
  /* Analog 
    PA.1:  Analog in (INTERNAL_BATT_VOLTAGE_MEASURE)
    PA.2:  Analog in (CAR BATT _ VOLTAGE_MEASURE)
    PA.2:  Analog_IN_1                              
    PA.3:  Analog_IN_2                              
    PA.4:  Analog_IN_3                              
    PA.5:  Analog_IN_4     
    PA.6:  Analog in (ANT_FB)
  */
  
  /* Digital In 
    PA.12: GPIO_IN (Digital_in_3)                         
    PA.13: GPIO_IN (Digital_in_4)                         
    PA.14: GPIO_IN (Digital_in_1)
    PA.15: GPIO_IN (Digital_in_2)
    PB.2:  GPIO_IN (External power removed)
    PE.5:  GPIO_IN (IPPS_INT)
    PB.9:  GPIO_IN (Panic_MCU_In)
    PB.10: GPIO_IN (Ignition_sense_In)
    PA.10:GPIO_IN (Acc_INT1)
    PA.11:GPIO_IN (Acc_INT2)
    PB.6:   GPIO _IN                            (MCU_RI)
//    PB13 : Tamper alert/ Case Open
//  */ 
//    GPIO_SetMode(PB, BIT6, GPIO_PMD_INPUT);      //Ring Indicator
//    GPIO_EnableInt(PB, 6, GPIO_INT_RISING);
//    NVIC_EnableIRQ(GPAB_IRQn);

//    GPIO_SetMode(PA, BIT10, GPIO_PMD_INPUT);     //Acc 1 Interrupt
//    GPIO_EnableInt(PA, 10, GPIO_INT_RISING);
//    NVIC_EnableIRQ(GPAB_IRQn); 
//    
//    GPIO_SetMode(PA, BIT11, GPIO_PMD_INPUT);     //Acc 2 Interrupt
//    GPIO_EnableInt(PA, 11, GPIO_INT_RISING);
//    NVIC_EnableIRQ(GPAB_IRQn); 
//    
//    GPIO_SetMode(PB, BIT10, GPIO_PMD_INPUT);     //Ignition Sense Interrupt
//        
//    GPIO_SetMode(PB, BIT9, GPIO_PMD_INPUT);     //Panic Button Interrupt
//    GPIO_EnableInt(PB, 9, GPIO_INT_RISING);
//    NVIC_EnableIRQ(GPAB_IRQn); 
//        
//    GPIO_SetMode(PA, BIT12, GPIO_PMD_INPUT);      //DIO3 Indicator
//    GPIO_EnableInt(PA, 12, GPIO_INT_RISING);
//    NVIC_EnableIRQ(GPAB_IRQn);
//    GPIO_SetMode(PA, BIT13, GPIO_PMD_INPUT);      //DIO4 Indicator
//    GPIO_EnableInt(PA, 13, GPIO_INT_RISING);
//    NVIC_EnableIRQ(GPAB_IRQn);
//    GPIO_SetMode(PA, BIT14, GPIO_PMD_INPUT);      //DIO1 Indicator
//    GPIO_EnableInt(PA, 14, GPIO_INT_RISING);
//    NVIC_EnableIRQ(GPAB_IRQn);
//    GPIO_SetMode(PA, BIT15, GPIO_PMD_INPUT);      //DIO2 Indicator
//    GPIO_EnableInt(PA, 15, GPIO_INT_RISING);
//    NVIC_EnableIRQ(GPAB_IRQn);  
    

  /* Digital Out 
    PB.7:   GPIO_OUT                         (MCU_DTR)
    PC.0:   GPIO_OUT (Acc_add_sel)
    PC.6: GPIO_OUT (Digital_out_1)	
    PC.7: GPIO_OUT (Digtial_out_2)
    PB.3:  GPIO_OUT (relay cutoff)
    PB.11: GPIO_OUT (pwr_key_reset)
    PB.15: GPIO_OUT (GSM_Modem_OFF)
    PC.14: GPIO_OUT (MCU_SELF_RESET)
    PC.16: GPIO_OUT (MCU_PWR_RESET)
    PB.8:   GPIO_OUT (EXT_ANT_SWITCH)
    PC.2:  GPIO_OUT (LED_DEBUG_1)
    PC.3:  GPIO_OUT (LED_DEBUG_2)
    PA.7:  GPIO_OUT (BATT_MEASURE_ENABLE)
  */  
}
__inline void remove_all_characters(char* str, int len, char c, char d) {
    int i=0;char *pr = str, *pw = str;
    for(i=0;i<len;i++){
        *pw = *pr++;
			pw += (*pw != c && *pw != d);
    }
    *pw = '\0';
}

__inline int hex_to_int(char c){
        int first = c / 16 - 3;
        int second = c % 16;
        int result = first*10 + second;
        if(result > 9) result--;
        return result;
}

__inline void hextoascii(char* string, int len){
  int high, low;
  char c,d;
  int i;
  memset(DestArray,0,257);
  for(i = 0; i< len-1; i+=2){
      c = string[i];
      d = string[i+1];
      high = hex_to_int(c) * 16;
      low = hex_to_int(d);
      DestArray[i] = high+low;
    }
  remove_all_characters(DestArray,257,0x00,0x00);
  }


void waitfor123(){
    osSignalWait (0x0123, osWaitForever); // wait forever for the signal 0x0001
    osSignalClear (mainThreadID, 0x0123);
}

void signal123(){
    osSignalSet (tid_Thread_OBD_READ, 0x0123);
}
void waitfor321(){
    osSignalWait (0x0321, osWaitForever); // wait forever for the signal 0x0001
    osSignalClear (tid_Thread_OBD_READ, 0x0321);
}

void signal321(){
    osSignalSet (mainThreadID, 0x0321);
}


void GPAB_IRQHandler(void){
  int trueint = 0;
    /* To check if PE.5 interrupt occurred */
//    if(GPIO_GET_INT_FLAG(PB, BIT15)){
//        GPIO_CLR_INT_FLAG(PB, BIT15);
//    }
    if(GPIO_GET_INT_FLAG(PA, BIT14)){
        GPIO_CLR_INT_FLAG(PA, BIT14);
        input1 = 1;trueint = 1;
    }if(GPIO_GET_INT_FLAG(PA, BIT15)){
        GPIO_CLR_INT_FLAG(PA, BIT15);
        input2 = 1;trueint = 1;
    }if(GPIO_GET_INT_FLAG(PA, BIT12)){
        GPIO_CLR_INT_FLAG(PA, BIT12);
        input3 = 1;trueint = 1;
    }if(GPIO_GET_INT_FLAG(PA, BIT13)){
        GPIO_CLR_INT_FLAG(PA, BIT13);
        input4 = 1;trueint = 1;
    }  
//    if(GPIO_GET_INT_FLAG(PB, BIT6)){
//        GPIO_CLR_INT_FLAG(PB, BIT6);
//        ring = 1;trueint = 1;
//        //SendAT("\r\n\r\nAT\r\n\r\n","+CME ERROR", "OK" , "ERROR",10);

//    }
    if(GPIO_GET_INT_FLAG(PB, BIT9)){
        GPIO_CLR_INT_FLAG(PB, BIT9);
        emergencystatus = 1;
        wetmr = 0;trueint = 1;
    }if(GPIO_GET_INT_FLAG(PB, BIT10)){
        GPIO_CLR_INT_FLAG(PB, BIT10);
        ignition = 1;trueint = 1;
    }if(GPIO_GET_INT_FLAG(PB, BIT13)){
        GPIO_CLR_INT_FLAG(PB, BIT13);
        tamperalert = 'O';trueint = 1;
    }
    
    
    
    
    //if (trueint == 0)
    {
        /* Un-expected interrupt. Just clear all PC, PD, PE and PF interrupts */
        PB->ISRC = PB->ISRC;
        PA->ISRC = PA->ISRC;
    }
   printf("\r\nAT+interrupt\r\n");
}
void WDT_IRQHandler(void)
{
    // Reload WWDT counter and clear WWDT interrupt flag
    WWDT_RELOAD_COUNTER();
    WWDT_CLEAR_INT_FLAG();
   // printf("WWDT counter reload\r\n");
//    while(1);
}

void TMR0_IRQHandler(void)
{
    if(TIMER_GetIntFlag(TIMER0) == 1)
    {
        /* Clear Timer0 time-out interrupt flag */
        TIMER_ClearIntFlag(TIMER0);
        interval_count++;
        interval_count_health++;
        tmr0sec++;
        //tmr1sec++;
        tcpsendchtimer++;
        tc++;
        i2ctimeout++;
        if(emergencystatus == 1)
        wetmr++;
        //PC2^=1;
        //PC3^=1;

    }
}
void ADC_IRQHandler(void)
{
    g_u32AdcIntFlag = 1;
    ADC_CLR_INT_FLAG(ADC, ADC_ADF_INT); /* clear the A/D conversion flag */
}
