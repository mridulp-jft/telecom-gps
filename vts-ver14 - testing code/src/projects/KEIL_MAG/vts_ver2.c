/*
 * File:		KEIL_MAG.c
 * Purpose:		Main process
 *
 */

#include "common.h"
#include "modem.c"
#include "accelerometer.c"
#include "gps.c"
#include "gpios.c"
#include "systick.c"
#include "stdlib.h"
#include <stdint.h>
#include "string.h"
//#include "lptmr.c"





#ifdef CMSIS
#include "start.h"
#endif
void send_balance();extern void outSRS(void);
extern void LED_state(),LED_state2();
int sleep_flag=0;
int32 tmeout=4,int_erval=1; //10 SECS TIMEOUT
extern char in_char1(),in_char2();
extern void out_char1(char ch),out_char2(char ch);
char string_gps[100],gga[100],rmc[100],uart_string_gps[3000],data2[300],drive[5];
char * apn="iot.com";
void HardFault_Handler();
float speed=0;
void dtr_sleep();
int lpticks=0,voltagecbc;
uint32 rtcticks=0;
int rtcticks2=0;
char ticks_ch,save_rtcticks;
char 
		 ip[16]="104.236.203.4",
		 port[10]="5555",
		 at_[100],

		 lati[20],
		 longi[20],
		 velocity[5],
		 fsize[15],
		 num_o[15],
		 interval[5],
	_rtcticks[10];

int32 timeout=0;

static char imei[20];
void send_message(char * data2);
float pr=0,la=0;
char uart_string_gsm[5000],sd_data[1400];
int ggaptr=0,rmcptr=0;
int i=0,motion_samples=0,notsleep=0;
char ch; 
void delay(int delaytime), get_gpsdata(),  loop(), auto_caliberate_accelerometer(),  tcp_initialization2(), 	 msg_sim800();
void  send_chunk(),bat_cind();
extern void send_modem(char ch[]);void get_imei();
char ringflag=0,lptmr_interrupt=0;
extern void lptmr_init(int count, int clock_source);
int GPS_COLLECT(),tcp_initialization();
int time52=15;
void HardFault_Handler();
char * cond277;char* cond20077;char data_balance[200];

char mystrstr(char* str1, char character)
{int sz,cn;
	sz=strlen(str1);
	for(cn=0;cn<=sz;cn++)
	{if(str1[cn] == character)
		{return 1;}
	}
	return 0;
}

__inline void ignread(){
memset(at_,0,100);
		sprintf(at_, "\nAT+FSREAD=C:\\IGN.TXT,0,100,1\r\n");		
		send_GSM(at_, "OK", "ERROR\r\n" , "ERROR:",10);	
if(strstr(uart_string_gsm,"ION")){IGNITION_ON;FUEL_ON;}
else if(strstr(uart_string_gsm,"IOFF")){IGNITION_OFF;FUEL_OFF;}

}	
	
__inline void ignstaton(){
send_GSM("\nAT+FSCREATE=C:\\IGN.TXT\r\n", "OK", "ERROR\r\n" , "ERROR:",tmeout);
send_GSM("\r\nAT+FSWRITE=C:\\IGN.TXT,0,6,10\r\n", ">", "ERROR\r\n" , "ERROR:",5);
	delay(10);
send_GSM("\nION\n\n\n\n", "OK\r\n", "ERROR\r\n" , "ERROR:",10);


}	
	

void remove_all_chars(char* str, char c, char d) {
    char *pr = str, *pw = str;
    while (*pr) {
        *pw = *pr++;
			pw += (*pw != c && *pw != d && *pw != ' ' && *pw != '/' && *pw != ':');
    }
    *pw = '\0';
}


/*************************** delay*****************************************/
 void delay(int32 delaytime)
{
 while(delaytime--)
    {for(i=2000;i>0;i--)
			{	
			}			// about 1 ms
    }
}
 void delay2(int delaytime)
{
 while(delaytime--)
    {for(i=5000;i>0;i--);  // about 1 ms
    }
}
        


/*********************************************************************/
void ADC_Init(void)
{
//Turn on ADC
SIM->SCGC6 |= SIM_SCGC6_ADC0_MASK;
//bus clock/2 & singled-ended 16bit mode & div by 4
ADC0->CFG1 = ADC_CFG1_ADICLK(1) | ADC_CFG1_MODE(3) | ADC_CFG1_ADIV(1);
//select channel A & high speed mode
ADC0->CFG2 = !ADC_CFG2_MUXSEL_MASK;// | ADC_CFG2_ADHSC_MASK;
//hardware trigger & VREFH/VREFL
ADC0->SC2 = ADC_SC2_REFSEL(0);
//single shot mode
ADC0->SC3 &= ~ADC_SC3_ADCO_MASK;
}


void adc_start_conversion(uint8_t channel)
{
ADC0->SC1[0] = !ADC_SC1_AIEN_MASK | ADC_SC1_DIFF_MASK | ADC_SC1_ADCH(channel);
}

uint16_t adc_read(uint8_t channel)
{
	
//ADC0_SC1A = 26 & ADC_SC1_ADCH_MASK; //Write to SC1A to start conversion
	ADC0->SC1[0] = !ADC_SC1_AIEN_MASK | ADC_SC1_DIFF_MASK | ADC_SC1_ADCH(channel) ;
while(ADC0_SC2 & ADC_SC2_ADACT_MASK); //Conversion in progress
while(!(ADC0_SC1A & ADC_SC1_COCO_MASK)); //Wait until conversion complete
return ADC0_RA;

	
	
//ADC0->SC1[0] = !ADC_SC1_AIEN_MASK | ADC_SC1_DIFF_MASK | ADC_SC1_ADCH(channel) ; // start conversion while((ADC0->SC1[0] & ADC_SC1_COCO_MASK)!= 0){}; return ADC0->R[0];
}


/********************************************************************/
int main (void)
{int uyi;unsigned int adcin=0;long adcsample; long adcsa;
char sent=1;
//int_erval=10;
								memset(data,0,strlen(data));
								memset(data2,0,strlen(data2));
	
start();
systick_init();	
#ifdef CMSIS  // If we are conforming to CMSIS, we need to call start here

#endif

int_erval=5;


	LED_init();		//Initialize GPIO for LEDs
	RELAY_init();		//Initialize GPIO for LEDs
	SW1_init();		//Initialize GPIO for SW1 w/ interrupt	
	//accel_init();
	send_SOS=0;
	sleep_flag=0;
	DTR_OFF;	
	ADC_Init();
	lptmr_init(1000, 1);	

IGNITION_OFF;FUEL_OFF;
while(1)
{int e;
	//for(	e=0;e<500;){
	
adcin= 	adc_read(9);


//		if(adcin>40000){}
//			else{
//				adcsample+=adcin;
//			e++;}
////	adc_start_conversion(e);
	//}
//adcsa=adcsample/500;	
memset(at_,0,100);
sprintf(at_,",ADC%d=%ld, %ld",8,adcin, adcsample);	
send_modem(at_);	

	send_modem("\n");
delay(250);
	}

int_erval=0;
ignstaton();
saveapn();								
								send_GSM("\nAT+FSCREATE=C:\\IP_PORT.TXT\r\n", "OK", "ERROR\r\n" , "ERROR:",tmeout);
								send_GSM("\nAT+FSCREATE=D:\\LOG.TXT\r\n", "OK", "ERROR\r\n" , "ERROR:",tmeout);
								send_GSM("\nAT+FSCREATE=C:\\LOG.TXT\r\n", "OK", "ERROR\r\n" , "ERROR:",tmeout);
								send_GSM("\nAT+FSCREATE=C:\\INTERVAL.TXT\r\n", "OK", "ERROR\r\n" , "ERROR:",tmeout);
								memcpy (ip, "104.236.203.4", 13);
								memcpy (port, "5555", 4);		
								memcpy (interval, "5", 1);										
								save_ip_port();
								save_interval();	
								int_erval=myAtoi(interval);		


	send_GSM("\r\nAT+GSV\r\r\n\n", "OK", "ERROR\r\n" , "ERROR",4);	
	send_GSM("\r\nAT+CFUN=0\r\r\n\n", "OK", "ERROR\r\n" , "ERROR",4);	
clear();	
//delay(10);

	send_GSM("\r\nAT+CFUN=1\r\n", "Ready", "NOT INSERTED" , "ERROR",7);	



send_GSM("\n\nAT\r\n","OK\r\n","ERROR\r\n","ERROR:",2); 
if(strlen(uart_string_gsm)>2){RED_ON;}else{RED_OFF;}
delay(100);
send_GSM("\n\nAT\r\n","OK\r\n","ERROR\r\n","ERROR:",2); 
if(strlen(uart_string_gsm)>2){RED_ON;}else{RED_OFF;}
delay(100);


send_GSM("\n\nAT+CSCLK=1\r\n","OK\r\n","ERROR\r\n","ERROR:",tmeout);


GPS_COLLECT();

		send_modem(data);
		send_modem("\r\n\r\n");







send_GSM("\n\nAT+SD2PCM=0\r\n","OK\r\n","ERROR\r\n","ERROR:",tmeout);
//delay(10);	

send_GSM("\n\nAT&W\r\n","OK\r\n","ERROR\r\n","ERROR:",tmeout);
delay(10);	
send_GSM("\n\nAT+FSDRIVE=1\r\n","OK\r\n","ERROR\r\n","ERROR:",tmeout);
clear();
delay(10);	
send_GSM("\n\nAT+FSMEM\r\n","OK\r\n","ERROR\r\n","ERROR:",tmeout);








ignread();



send_GSM("\r\nAT+CPBW=0\r\r\n\n", "OK", "ERROR\r\n" , "ERROR",4);	delay(100);
//send_GSM("\r\nAT+CPBW=1\r\r\n\n", "OK", "ERROR\r\n" , "ERROR",4);	delay(100);
//send_GSM("\r\nAT+CPBW=2\r\r\n\n", "OK", "ERROR\r\n" , "ERROR",4);	delay(100);
send_GSM("\r\nAT+CPBW=3\r\r\n\n", "OK", "ERROR\r\n" , "ERROR",4);	delay(100);
//send_GSM("\r\nAT+CPBW=4\r\r\n\n", "OK", "ERROR\r\n" , "ERROR",4);	delay(100);
send_GSM("\r\nAT+CPBW=5\r\r\n\n", "OK", "ERROR\r\n" , "ERROR",4);	delay(100);
send_GSM("\r\nAT+CPBW=6\r\r\n\n", "OK", "ERROR\r\n" , "ERROR",4);	delay(100);
send_GSM("\r\nAT+CPBW=7\r\r\n\n", "OK", "ERROR\r\n" , "ERROR",4);	delay(100);
send_GSM("\r\nAT+CPBW=8\r\r\n\n", "OK", "ERROR\r\n" , "ERROR",4);	delay(100);
send_GSM("\r\nAT+CPBW=9\r\r\n\n", "OK", "ERROR\r\n" , "ERROR",4);	delay(100);
send_GSM("\r\nAT+CPBW=10\r\r\n\n", "OK", "ERROR\r\n" , "ERROR",4);delay(100);	
send_GSM("\r\nAT+CPBW=11\r\r\n\n", "OK", "ERROR\r\n" , "ERROR",4);delay(100);	
send_GSM("\r\nAT+CPBW=12\r\r\n\n", "OK", "ERROR\r\n" , "ERROR",4);	delay(100);
send_GSM("\r\nAT+CPBW=13\r\r\n\n", "OK", "ERROR\r\n" , "ERROR",4);delay(100);	
send_GSM("\r\nAT+CPBW=14\r\r\n\n", "OK", "ERROR\r\n" , "ERROR",4);	delay(100);
send_GSM("\r\nAT+CPBW=15\r\r\n\n", "OK", "ERROR\r\n" , "ERROR",4);	delay(100);
send_GSM("\r\nAT+CPBW=16\r\r\n\n", "OK", "ERROR\r\n" , "ERROR",4);	delay(100);
send_GSM("\r\nAT+CPBW=17\r\r\n\n", "OK", "ERROR\r\n" , "ERROR",4);	delay(100);
send_GSM("\r\nAT+CPBW=18\r\r\n\n", "OK", "ERROR\r\n" , "ERROR",4);	delay(100);
send_GSM("\r\nAT+CPBW=19\r\r\n\n", "OK", "ERROR\r\n" , "ERROR",4);	delay(100);
send_GSM("\r\nAT+CPBW=20\r\r\n\n", "OK", "ERROR\r\n" , "ERROR",4);	delay(100);
send_GSM("\r\nAT+CPBW=21\r\r\n\n", "OK", "ERROR\r\n" , "ERROR",4);	delay(100);
send_GSM("\r\nAT+CPBW=22\r\r\n\n", "OK", "ERROR\r\n" , "ERROR",4);	delay(100);
send_GSM("\r\nAT+CPBW=23\r\r\n\n", "OK", "ERROR\r\n" , "ERROR",4);	delay(100);


if(send_SOS==1){
send_modem("\r\n\r\npush button detected\r\n\r\n");
send_SOS=0;
}
						msg_sim800(); 	

dtr_sleep();
send_GSM("\n\nAT\r\n","OK\r\n","ERROR\r\n","ERROR:",2); 
if(strlen(uart_string_gsm)>2){GREEN_ON;}else{GREEN_OFF;}
delay(100);

HardFault_Handler();



























































do{
	
			RESET_ON;
	delay(10);
		uart_putchar(UART1_BASE_PTR,0xA);
		uart_putchar(UART1_BASE_PTR,0x1A);			
	
send_GSM("\n\nAT\r\n","OK\r\n","ERROR\r\n","ERROR:",2);  
 delay(100); 
}while(1);
clear();delay(100);
get_imei();	
GPS_COLLECT();
strcat(data,"CH\n");	


int_erval=5;

//if(!(strstr(uart_string_gsm, "OK")|| strstr(uart_string_gsm, "ERROR")))
//{HardFault_Handler();}



	send_GSM("\r\nAT+CFUN=0\r\r\n\n", "OK", "ERROR\r\n" , "ERROR",4);	
clear();	
//delay(10);

	send_GSM("\r\nAT+CFUN=1\r\n", "Ready", "NOT INSERTED" , "ERROR",7);	

	
GPS_COLLECT();
strcat(data,"CH\n");	

//GPS_COLLECT();
//  strcat(data,"CH\n");	
//	

GPS_COLLECT();
strcat(data,"CH\n");	


//delay(100);
//send_modem("Restarting the device\r");	
//uart_putchar(UART1_BASE_PTR,'A');
//uart_putchar(UART1_BASE_PTR,'B');
//uart_putchar(UART1_BASE_PTR,'C');	uart_putchar(UART1_BASE_PTR,0x1A);
//uart_putchar(UART1_BASE_PTR,0x1A);		uart_putchar(UART1_BASE_PTR,0x1A);

//	send_modem("$PMTK225,0*2B");	send_modem("“$PMTK225,0*2B”");
stateCount=3;
LED_state();

//do
//	{

//		uart_putchar(UART1_BASE_PTR,0x1A);
//		uart_putchar(UART1_BASE_PTR,0xA);
//		uart_putchar(UART1_BASE_PTR,0x1A);

	
//send_GSM("\n\nAT\r\n","OK\r\n","ERROR\r\n","ERROR:",tmeout);    
//		
//send_GSM("\n\nAT+GSV\r\n","OK\r\n","ERROR\r\n","ERROR:",tmeout);  	
//	cond277=(strstr(uart_string_gsm, "OK"));
//	cond20077=(strstr(uart_string_gsm, "ERROR"));
//if((!(cond277|| cond20077 ))  && sleep_flag != 1){
//	HardFault_Handler();
//}
		//delay(10);
//if(strlen(uart_string_gsm) < 12)

//while(1){
//HardFault_Handler();
////	RESET_OFF;delay(50);
//	
////	main();
//}

get_imei();	

	
//send_modem2("$PMTK225,0*2B");
//while(!strstr(uart_string_gsm,"OK\r\n"));

//bat_cind();
//delay(1000);

send_GSM("\n\nAT&W\r\n","OK\r\n","ERROR\r\n","ERROR:",tmeout);    //   uart_putchar(UART1_BASE_PTR,0x1A);uart_putchar(UART1_BASE_PTR,0xA);uart_putchar(UART1_BASE_PTR,0x1A);uart_putchar(UART1_BASE_PTR,0xA);uart_putchar(UART1_BASE_PTR,0x1A);		
//delay(10);

send_GSM("\n\nATS0=2\r\n","OK\r\n","ERROR\r\n","ERROR:",tmeout); 	

get_imei();

send_GSM("\n\nAT&F\r\n","OK\r\n","ERROR\r\n","ERROR:",tmeout); 	


send_GSM("\n\nAT&D\r\n","OK\r\n","ERROR\r\n","ERROR:",tmeout); 	


send_GSM("\n\nAT+IFC=0,0\r\n","OK\r\n","ERROR\r\n","ERROR:",tmeout);


send_GSM("\n\nAT+CIPQSEND?\r\n","OK\r\n","ERROR\r\n","ERROR:",tmeout);

send_GSM("\n\nAT+CIPQSEND=0\r\n","OK\r\n","ERROR\r\n","ERROR:",tmeout);


//delay(10);


//delay(10);

send_GSM("\n\nAT+SD2PCM=0\r\n","OK\r\n","ERROR\r\n","ERROR:",tmeout);
//delay(10);	

send_GSM("\n\nAT&W\r\n","OK\r\n","ERROR\r\n","ERROR:",tmeout);
delay(10);	
send_GSM("\n\nAT+FSDRIVE=1\r\n","OK\r\n","ERROR\r\n","ERROR:",tmeout);
clear();
delay(10);	
//;	
//send_GSM("\n\nAT+FSCREATE=D:\\LOG.TXT\r\n","OK\r\n","ERROR\r\n","ERROR:",tmeout);

	GPS_COLLECT();
  strcat(data,"CH\n");	

send_GSM("\n\nAT+FSMEM\r\n","OK\r\n","ERROR\r\n","ERROR:",tmeout);
delay(100);	

if(strstr(uart_string_gsm,"D:")){
send_GSM("\n\nAT+FSCREATE=C:\\LOGGING_DRIVE.TXT\r\n","OK\r\n","ERROR\r\n","ERROR:",tmeout);	
	
memset(at_,0,100);
sprintf(at_,"\r\nAT+FSWRITE=C:\\LOGGING_DRIVE.TXT,0,%d,10\r\n",2);	
send_GSM(at_, ">", "ERROR\r\n" , "ERROR:",10);	
	
clear();
send_modem("D:");	
	
}
else{
send_GSM("\n\nAT+FSCREATE=C:\\LOGGING_DRIVE.TXT\r\n","OK\r\n","ERROR\r\n","ERROR:",tmeout);	
	
memset(at_,0,100);
sprintf(at_,"\r\nAT+FSWRITE=C:\\LOGGING_DRIVE.TXT,0,%d,10\r\n",2);	
send_GSM(at_, ">", "ERROR\r\n" , "ERROR:",10);	
	
clear();
send_modem("C:");		
	
}	

delay(100);

//delay(10);

send_GSM("\n\nATS0=1\r\n","OK\r\n","ERROR\r\n","ERROR:",tmeout);

//delay(10);

//delay(10);

//printf("%s\n",send_GSM("\n\nAT+CMGD=1,4\r\n","OK\r\n","ERROR\r\n","ERROR:",tmeout));//del_msg();
//delay(10);

//printf("%s\n",send_GSM("\n\nAT+CPBW=1,\"100\",129,\"OWNER1\"\r\n","OK\r\n","ERROR\r\n","ERROR:",tmeout));


//printf("%s\n",send_GSM("\n\nAT+CPBW=2,\"100\",129,\"OWNER2\"\r\n","OK\r\n","ERROR\r\n","ERROR:",tmeout));


//printf("%s\n",send_GSM("\n\nAT+CPBW=3,\"100\",129,\"OWNER3\"\r\n","OK\r\n","ERROR\r\n","ERROR:",tmeout));


//printf("%s\n",send_GSM("\n\nAT+CPBW=4,\"100\",129,\"OWNER4\"\r\n","OK\r\n","ERROR\r\n","ERROR:",tmeout));

send_GSM("\n\nAT+CSCLK=1\r\n","OK\r\n","ERROR\r\n","ERROR:",tmeout);


send_GSM("\r\n\r\nAT+CMGD=1,4\r\n\n\n\n","OK\r\n","ERROR\r\n","ERROR:",tmeout);	


send_GSM("\n\nAT+CPBW=5,\"9873999108\",129,\"OWNER5\"\r\n","OK\r\n","ERROR\r\n","ERROR:",tmeout);


send_GSM("\n\nAT+CPBW=6,\"8287324005\",129,\"OWNER6\"\r\n","OK\r\n","ERROR\r\n","ERROR:",tmeout);

//printf("%s\n",send_GSM("\n\nAT+CPBW=4,\"8287324005\",129,\"OWNER2\"\r\n","OK\r\n","ERROR\r\n","ERROR:",tmeout));

//		memset(at_,0,100);
//		sprintf(at_, "\nAT+FSREAD=C:\\RTC_TICKS.TXT,0,100,1\r\n");		
//		send_GSM(at_, "OK", "ERROR\r\n" , "ERROR:",10);	
//		parse_g(uart_string_gsm, 1,3, '\n', '\r',_rtcticks);
//		rtcticks2=myAtoi(_rtcticks);		



read_interval();
send_GSM("\n\nAT+CMGF=1\n\n","OK\r\n","ERROR\r\n","ERROR:",tmeout);
//delay(10);	

send_GSM("\n\nAT+CSCA?\r\n","OK\r\n","ERROR\r\n","ERROR:",tmeout);    //   uart_putchar(UART1_BASE_PTR,0x1A);uart_putchar(UART1_BASE_PTR,0xA);uart_putchar(UART1_BASE_PTR,0x1A);uart_putchar(UART1_BASE_PTR,0xA);uart_putchar(UART1_BASE_PTR,0x1A);		
							memset(at_,0,100);
							memset(num_o,0,15);
							parse_g(uart_string_gsm, 1, 2, '\"', '\"', num_o);
							sprintf(at_, "\r\nAT+CSCA=\"%s\"\r\n", num_o);
							send_GSM(at_,"OK\r\n","ERROR\r\n","ERROR:",tmeout);

//delay(10);	

								send_GSM("\nAT+FSCREATE=C:\\IP_PORT.TXT\r\n", "OK", "ERROR\r\n" , "ERROR:",tmeout);
				//				send_GSM("\nAT+FSCREATE=C:\\LOG.TXT\r\n", "OK", "ERROR\r\n" , "ERROR:",tmeout);
								send_GSM("\nAT+FSCREATE=C:\\INTERVAL.TXT\r\n", "OK", "ERROR\r\n" , "ERROR:",tmeout);
								memcpy (ip, "104.236.203.4", 13);
								memcpy (port, "5555", 4);		
								memcpy (interval, "5", 1);										
								save_ip_port();
								save_interval();
			//					printf("\n\n\t,%s,%s,%s,\n",ip,port,interval);		

//			RESET_OFF;
//			delay(20);
//			RESET_ON;


read_ip_port();
		memset(at_,0,100);
		memset(drive,0,5);
		sprintf(at_, "\nAT+FSREAD=C:\\LOGGING_DRIVE.TXT,0,100,1\r\n");		
		send_GSM(at_, "OK", "ERROR\r\n" , "ERROR:",10);	
		parse_g(uart_string_gsm, 1,3, '\n', '\r',drive);
	

tcp_initialization2();

//							GPS_COLLECT();		accel_read();detect_motion();

//do{
//printf("%s\n",send_GPS("\n\nAT+CGPSPWR=1\n\n","OK\r\n","ERROR\r\n","ERROR:",tmeout));
//delay(50);
//printf("%s\n",send_GPS("\n\nAT+CGPSOUT=255\n\n","OK\r\n","ERROR\r\n","ERROR:",tmeout));
//}while(strstr(uart_string_gps,"ERROR"));

//delay(50);

//auto_caliberate_accelerometer();
//tcp_initialization();

//phonebook_read("5");parse(1,2);
	

while(1)
{int length_string;
	//	accel_read();

					
					
						{ // main tcp GPS_COLLECT

					//		bat_cind();

							send_GSM("\r\nAT+CIPCLOSE\r\n", "CLOSE OK", "ERROR" , "ERROR:",tmeout);		

						msg_sim800(); 	
							
if(rtcticks2>21600){ //21600
	rtcticks2=0;

	// wakeup and reset

    DTR_OFF;		// not sleep	
//	  HardFault_Handler();
delay(1000);
send_GSM("\n\nAT\r\n","OK\r\n","ERROR\r\n","ERROR:",tmeout);    
		
send_GSM("\n\nAT+GSV\r\n","OK\r\n","ERROR\r\n","ERROR:",tmeout);  		

clear();	

				memset(data,0,strlen(data));	

GPS_COLLECT();
strcat(data,"CH\n");
	

	
send_GSM("\n\nAT+CUSD=1,\"*111*6*2#\"\r\n","+CUSD: 4","ERROR",", 15",20); 
parse_g(uart_string_gsm, 3, 4, '\"', '\"', data_balance);
get_imei();
strcat(data,imei);
strcat(data,",");	
strcat(data,"DATA_BALANCE,");	
strcat(data,data_balance);		
strcat(data,"\n");	
rtcticks=0;
send_GSM("\n\nAT+CUSD=1,\"*\"","+CUSD: ","ERROR",", 15",20); 

GPS_COLLECT();
strcat(data,"CH\n");	
memset(at_,0,100);
sprintf(at_, "\r\nAT+CIPSTART=\"TCP\",\"%s\",\"%s\"\r\n", ip, port);
send_GSM( at_ , "CONNECT", "ERROR" , "ERROR\r\n",tmeout);	
send_GSM("\r\nAT+CIPSEND\r\n", ">", "ERROR" , "CONNECT FAIL",tmeout);	
send_tcp_bal();
send_GSM("\r\nAT+CIPCLOSE\r\n", "CLOSE OK", "ERROR" , "ERROR:",tmeout);		

}				

//if(save_rtcticks == 1){
//	// wakeup and reset

//    DTR_OFF;		// not sleep	
////	  HardFault_Handler();
//delay(1000);
//send_GSM("\n\nAT\r\n","OK\r\n","ERROR\r\n","ERROR:",tmeout);    
//		
//send_GSM("\n\nAT+GSV\r\n","OK\r\n","ERROR\r\n","ERROR:",tmeout);  		
//clear();	
//	send_GSM("\n\nAT+FSCREATE=C:\\RTC_TICKS.TXT\r\n","OK\r\n","ERROR\r\n","ERROR:",tmeout);	

//	
//	memset(_rtcticks,0,10);
//	sprintf(_rtcticks,"%d",rtcticks2);
//	
//	memset(at_,0,100);
//	sprintf(at_,"\r\nAT+FSWRITE=C:\\RTC_TICKS.TXT,0,%d,10\r\n",strlen(_rtcticks));	
//	send_GSM(at_, ">", "ERROR\r\n" , "ERROR:",tmeout);	

//	clear();
//	send_modem(_rtcticks);	
//	save_rtcticks=0;
//	
//}	
 DTR_OFF;		// not sleep	
 delay(100);
send_GSM("\n\nAT+CBC\r\n","OK","ERROR","ERROR:",tmeout);
 	// not sleep	
memset(num2,0,30);
parse_g(uart_string_gsm, 2, 3, ',', '\r' ,num2);
voltagecbc=myAtoi(num2);
//parse(uart_string_gsm, 2, 4, num2);
if(voltagecbc>4000){
dtr_sleep();}
else{DTR_OFF;sleep_flag=0;}
delay(100);


if	(sleep_flag != 1)			
{
							memset(at_,0,100);
							sprintf(at_, "\r\nAT+CIPSTART=\"TCP\",\"%s\",\"%s\"\r\n", ip, port);
							memset(data,0,strlen(data));
							GPS_COLLECT();
							send_GSM( at_ , "CONNECT", "ERROR" , "ERROR\r\n",tmeout);	
							send_GSM("\r\nAT+CIPSEND\r\n", ">", "ERROR" , "CONNECT FAIL",tmeout);	
							send_tcp();
}							





							
}

		
/******************while end**********************/		
	} 
/******************main end***********************/
}
/********************************************************************/












void HardFault_Handler()
{
DTR_OFF;		// not sleep	
 delay(100);
		
		
		send_modem("HardFault Reset\r\n");
//		uart_putchar(UART1_BASE_PTR,0xA);
		uart_putchar(UART1_BASE_PTR,0x1A);uart_putchar(UART1_BASE_PTR,0x1A);uart_putchar(UART1_BASE_PTR,0x1A);	
		
	log_it();
	
		send_GSM("\n\n AT+CMGD=1,4\r\n","OK\r\n","ERROR\r\n","ERROR:",tmeout);	
		

		RESET_OFF;
	delay(50);
	
		RESET_ON;

	delay(50);

	
	
	
		

	
	
	
//	while(1){		send_GSM("\n\n AT\r\n","OK\r\n","ERROR\r\n","ERROR:",tmeout);	}

	
//	main();
	
//	SystemInit();
//	main();
}


void LPTimer_IRQHandler(void)
{
lpticks+=1;
rtcticks++;
	tout++;tout2++;
	rtcticks2++;
//	if(rtcticks>=3600){save_rtcticks=1;rtcticks=0;}//3600
	
	
	switch(rtcticks)
	{
		case 1:
			IGNITION_OFF;
			break;
		case 2:
			IGNITION_ON;
			break;
		case 3:
			FUEL_OFF;break;
		case 4:
			FUEL_ON;rtcticks=0;break;
	
		
	
		
		
		
		
		
	}
	
	
	
	
	

  LPTMR0_CSR |=  LPTMR_CSR_TCF_MASK;   // write 1 to TCF to clear the LPT timer compare flag
  LPTMR0_CSR = ( LPTMR_CSR_TEN_MASK | LPTMR_CSR_TIE_MASK | LPTMR_CSR_TCF_MASK  );
  
}



void dtr_sleep()
{int32 test2;

	;
	if(GPIOB_PDIR & 0x00000002){		send_modem("Ignition senses 1\r\n");
}else {send_modem("Ignition senses 0\r\n");}
	
if( test2 == 0 )	
{
	//send_GSM("\r\nAT+CFUN=0\r\n", "OK\r\n", "ERROR\r\n" , "ERROR:",7);	

	sleep_flag=1;	
	DTR_ON;   //sleep

}
else
{DTR_OFF;
	if (sleep_flag == 1  )
	{
	// wakeup and reset
		sleep_flag=0;
    		// not sleep	
//	  HardFault_Handler();
delay(1000);
send_GSM("\n\nAT\r\n","OK\r\n","ERROR\r\n","ERROR:",tmeout);    
		
send_GSM("\n\nAT+GSV\r\n","OK\r\n","ERROR\r\n","ERROR:",tmeout);

//send_GSM("\n\nAT+CFUN=1\r\n","OK\r\n","ERROR\r\n","ERROR:",tmeout);
		
delay(1000);	
clear();	
	}  
	DTR_OFF;		// not sleep	



}

LED_state();LED_state2();
}


















int myAtoi(char *str)
{
    int res = 0,iz; // Initialize result

    // Iterate through all characters of input string and update result
    for (iz = 0; str[iz] != '\0'; ++iz)
        res = res*10 + str[iz] - '0';

    // return result.
    return res;
}

float stof(const char* s)
{
  float rez = 0, fact = 1;
	int d,point_seen;
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



int GPS_COLLECT()
{
char prev[8],latest[10];
		int iz;
		double a,b,c;int hh,mm1,mm2;
		double a1,b1,c1;
		double hh11, mm11,mm22;


//		strcat(data,imei);
//		strcat(data,", ");	
//		strcat(data,"$GxGGA");	
//		strcat(data,gga);
//		strcat(data,", $GxRMC");	
//		strcat(data,rmc);	
//		strcat(data,"\n");		

//	return 0;
	
get_imei();	
	
time52=15;	
stateCount++; 
if(stateCount>5){stateCount =0;}
LED_state();



while(lpticks<int_erval);
get_gpsdata();
lpticks=0;



		
		speed = stof(velocity);
		c=stof(lati);//7523.7412
		hh= c/100; //75
		hh11 = c/100; //75.237412
		mm11 = hh11-hh; //.237412
		mm11*=100;
		mm22=hh+mm11/60;	
		memset(lati,0,15);
		sprintf(lati,"%f",mm22);
		c=stof(longi);//7523.7412
		hh= c/100; //75
		hh11 = c/100; //75.237412
		mm11 = hh11-hh; //.237412
		mm11*=100;
		mm22=hh+mm11/60;	
		memset(longi,0,15);
		sprintf(longi,"%f",mm22);	

		//strcat(data,"\n");
		strcat(data,imei);
		strcat(data,", ");	
		strcat(data,"$GxGGA");	
		strcat(data,gga);
		strcat(data,", $GxRMC");	
		strcat(data,rmc);	



//if(speed<2)
//{
//	motion_samples++;
//}
//else
//{
//	motion_samples=0;
//}
}






int GPS_COLLECT2()
{
char prev[8],latest[10];
		int iz;
		double a,b,c;int hh,mm1,mm2;
		double a1,b1,c1;
		double hh11, mm11,mm22;


//		strcat(data,imei);
//		strcat(data,", ");	
//		strcat(data,"$GxGGA");	
//		strcat(data,gga);
//		strcat(data,", $GxRMC");	
//		strcat(data,rmc);	
//		strcat(data,"\n");		

//	return 0;
	
//get_imei();	
	
time52=15;	
stateCount++; 
if(stateCount>5){stateCount =0;}
LED_state();



while(lpticks<int_erval);
get_gpsdata();
lpticks=0;



		
		speed = stof(velocity);
		c=stof(lati);//7523.7412
		hh= c/100; //75
		hh11 = c/100; //75.237412
		mm11 = hh11-hh; //.237412
		mm11*=100;
		mm22=hh+mm11/60;	
		memset(lati,0,15);
		sprintf(lati,"%f",mm22);
		c=stof(longi);//7523.7412
		hh= c/100; //75
		hh11 = c/100; //75.237412
		mm11 = hh11-hh; //.237412
		mm11*=100;
		mm22=hh+mm11/60;	
		memset(longi,0,15);
		sprintf(longi,"%f",mm22);	

		//strcat(data,"\n");
		strcat(data,imei);
		strcat(data,", ");	
		strcat(data,"$GxGGA");	
		strcat(data,gga);
		strcat(data,", $GxRMC");	
		strcat(data,rmc);	



//if(speed<2)
//{
//	motion_samples++;
//}
//else
//{
//	motion_samples=0;
//}
}














int tcp_initialization()
{char *cond; char * cond2;char * cond200;
get_imei();	
msg_sim800(); 
//clear();

	
	send_GSM("\r\nAT+CFUN=0\r\r\n\n", "OK", "ERROR\r\n" , "ERROR",5);	
	cond2=(strstr(uart_string_gsm, "OK"));
	cond200=(strstr(uart_string_gsm, "ERROR"));
//if((!(cond2|| cond200 ))  && sleep_flag != 1)
//HardFault_Handler();

delay(100);
	
//get_imei();	

send_GSM("\r\nAT+CFUN=1\r\n", "OK", "NOT INSERTED\r\nOK" , "ERROR", 4);	
//GPS_COLLECT();
//strcat(data,"CH\n");	
	
GPS_COLLECT2();
strcat(data,"CH\n");		

	
GPS_COLLECT2();
strcat(data,"CH\n");	



GPS_COLLECT2();
strcat(data,"CH\n");	

	//send_GSM("\r\nAT+CIPSHUT\r\n", "SHUT OK\r\n", "ERROR\r\n" , "ERROR:",tmeout);	

//msg_sim800(); 


	
send_GSM("\r\nAT+CIPSHUT\r\n", "OK", "ERROR\r\n" , "ERROR:",4);	
GPS_COLLECT2();
strcat(data,"CH\n");	

						send_GSM("\r\nAT+CSTT=\"www\"\r\n", "OK", "ERROR\r\n" , "ERROR:",tmeout);	
						//delay(20);

msg_sim800(); 

						
						send_GSM("\r\nAT+CIICR\r\r\n", "OK", "ERROR\r\n" , "DEACT",5);		




GPS_COLLECT2();
strcat(data,"CH\n");	


msg_sim800(); 
	GPS_COLLECT2();
  strcat(data,"CH\n");	
						clear();send_modem("\nAT+CIFSR\r\r\n");clear();
						delay(20);


msg_sim800(); 

						sprintf(at_, "\r\nAT+CIPSTART=\"TCP\",\"%s\",\"%s\"\r\n", ip, port);
						send_GSM( at_ , "CONNECT", "ERROR" , "ERROR:",tmeout);	
						clear();
						
						
						send_GSM("\r\nAT+CIPSEND\r\n", ">", "ERROR" , "CONNECT FAIL",tmeout);		
//GPS_COLLECT();
//strcat(data,"CH\n");	

		
return 0;
}


void tcp_initialization2()
{
get_imei();
msg_sim800(); 

								//GPS_COLLECT();
								send_GSM("\r\nAT+CIPSHUT\r\n", "OK", "ERROR\r\n" , "ERROR:",5);	
								//delay(20);		
								GPS_COLLECT();
								strcat(data,"CH\n");	


msg_sim800(); 


								send_GSM("\r\nAT+CSTT=\"www\"\r\n", "OK", "ERROR\r\n" , "ERROR:",tmeout);	
								//delay(20);
			//					GPS_COLLECT();

msg_sim800(); 

	
								send_GSM("\r\nAT+CIICR\r\r\n", "OK", "ERROR\r\n" , "DEACT",5);		
								//delay(20);
								GPS_COLLECT();
								strcat(data,"CH\n");	


msg_sim800(); 

								
								clear();send_modem("\nAT+CIFSR\r\r\n");clear();
								delay(20);
	

msg_sim800(); 

		
								sprintf(at_, "\r\nAT+CIPSTART=\"TCP\",\"%s\",\"%s\"\r\n", ip, port);
								send_GSM( at_ , "CONNECT", "ERROR\r\n" , "ERROR",tmeout);	
								clear();

								GPS_COLLECT();
								strcat(data,"CH\n");	

						send_GSM("\r\nAT+CIPSEND\r\n", ">", "ERROR" , "CONNECT FAIL",tmeout);		




send_tcp2();
}







void get_gpsdata()
{int32_t timeoutgps,resetval=99999,t22;
						int m;	clear2();
						memset(uart_string_gps,0,3000);memset(gga,0,100);memset(rmc,0,100);			
						i=0;tout2=0;
//						t22=9999999;
do{
	if(UART_S1_REG(UART2_BASE_PTR) & UART_S1_RDRF_MASK)
	{		uart_string_gps[i]=UART_D_REG(UART2_BASE_PTR);//clear2();
				i++;
	}
	}while(!   (strstr(uart_string_gps,"RMC")       ||  (tout2>1)  )  );
i=0;tout2=0;
do{
	if(UART_S1_REG(UART2_BASE_PTR) & UART_S1_RDRF_MASK)
	{		rmc[i]=UART_D_REG(UART2_BASE_PTR);//clear2();
				i++;
	}
}while(     !( mystrstr(rmc,'*')    ||  tout2>1) );
memset(uart_string_gps,0,3000);
i=0;tout2=0;
do{
	if(UART_S1_REG(UART2_BASE_PTR) & UART_S1_RDRF_MASK)
	{		uart_string_gps[i]=UART_D_REG(UART2_BASE_PTR);//clear2();
				i++;
	}
}while(!  (strstr(uart_string_gps,"GGA")      ||  (tout2>1) )  );
i=0;tout2=0;
do{
	if(UART_S1_REG(UART2_BASE_PTR) & UART_S1_RDRF_MASK)
	{		gga[i]=UART_D_REG(UART2_BASE_PTR);//clear2();
				i++;
	}
}while(!(mystrstr(gga,'*')  ||  (tout2>1) ));

clear2();

stateCount++; 
if(stateCount>5){stateCount =0;}
LED_state2();					

}


void auto_caliberate_accelerometer()
{
accel_read();
offxy= -xy_angle;
offxz= -xz_angle;
offyz= -yz_angle;
offx=  -resultx;
offy=  -resulty; 
offz=  -resultz; 	
	
}
	


void get_imei()
{int i,imeiinc=0;
clear();		
clear();
clear();
	
if((strlen(imei) < 15 )){


	
send_GSM("\r\n\n\nAT+GSN\r\n","OK","ERROR\r\n","ERROR",10);	

memset(imei,0,20);
for(i=0;i<strlen(uart_string_gsm);i++){
		if((uart_string_gsm[i]>47)   &&   (uart_string_gsm[i]<58)){   //means numeric
			imei[imeiinc] = uart_string_gsm[i];
			imeiinc++;
		}

}
	
	
	}		
	
//parse_g(uart_string_gsm,1,3,'\n','\r',imei);	
clear();	

}
	
	

void msg_sim800() 
{char* cond1;
	char* cond2;
	char* cond3;
	char* cond4;
	char* cond5;
	char* cond6;
	char* cond7;
	char* cond8;
	char* cond9;
	char* cond10;
	char* cond11;
	char* cond12;
	char* cond13;
	char* cond14;	
	
//ringflag=1;	
	if(ringflag==1)
	{
		sleep_flag=0;
    DTR_OFF;		// not sleep	
//	  HardFault_Handler();
delay(1000);
send_GSM("\n\nAT\r\n","OK\r\n","ERROR\r\n","ERROR:",tmeout);    
		
send_GSM("\n\nAT+GSV\r\n","OK\r\n","ERROR\r\n","ERROR:",tmeout);  		
delay(1000);		
		
		
//	bat_cind();
	send_GSM("\n\nAT+CMGF=1\n\n","OK\r\n","ERROR\r\n","ERROR:",tmeout);	
	send_GSM("\n\nAT+CSCA?\r\n","OK\r\n","ERROR\r\n","ERROR:",tmeout);    //   uart_putchar(UART1_BASE_PTR,0x1A);uart_putchar(UART1_BASE_PTR,0xA);uart_putchar(UART1_BASE_PTR,0x1A);uart_putchar(UART1_BASE_PTR,0xA);uart_putchar(UART1_BASE_PTR,0x1A);		
//							memset(at_,0,100);
//							memset(num_o,0,15);
//							parse_g(uart_string_gsm, 1, 2, '\"', '\"', num_o);
//							sprintf(at_, "\r\nAT+CSCA=\"%s\"\r\n", num_o);
//							printf("%s\n",send_GSM(at_,"OK\r\n","ERROR\r\n","ERROR:",tmeout));	

		
			//		printf("\n\n\thttps://www.google.com/search?q=%s%c2C%s&ie=utf-8&oe=utf-8\n",lati,'%',longi,velocity,lati,longi);
					send_GSM("\r\nAT+CMGR=1\r\n", "OK\r\n", "ERROR" , "OK\r\n",tmeout);	
					clear();
					parse_gsm(uart_string_gsm, 3, 4, num2);
			
			
			
			
			
			
			
//		
//if(cond1)
//{

						cond1=strstr(uart_string_gsm, "OWNER");	
						cond2=strstr(uart_string_gsm, "LOCATION");
						cond3=strstr(uart_string_gsm, "INTERVAL");
						cond4=strstr(uart_string_gsm, "START");
						cond5=strstr(uart_string_gsm, "OWNER1");
						cond6=strstr(uart_string_gsm, "OWNER2");
						cond7=strstr(uart_string_gsm, "OWNER3");
						cond8=strstr(uart_string_gsm, "DEBUG");
						cond9=strstr(uart_string_gsm, "RESET");
						cond10=strstr(uart_string_gsm, "IP");
						cond11=strstr(uart_string_gsm, "FUEL ON");	
						cond12=strstr(uart_string_gsm, "FUEL OFF");	
						cond13=strstr(uart_string_gsm, "IGNITION ON");	
						cond14=strstr(uart_string_gsm, "IGNITION OFF");	
					//	memset(uart_string_gsm,0,5000);
							if(cond1 && cond2)
							{
								memset(data2,0,strlen(data2));
								sprintf(data2,"\nCoordinates : %s N, %s E\nSpeed : %s kmph\n\nhttps://www.google.com/search?q=%s%c2C%s&ie=utf-8&oe=utf-8\n",lati,longi,velocity,lati,'%',longi);	
								//if(strstr(data2, "0.000000 N, 0.000000 E"))
								//{send_message("Sorry, No GPS Fix available at the moment\n");}
							//	else
								{send_message(data2);}

								send_GSM("\r\nAT+CMGD=1,4\r\n","OK\r\n","ERROR\r\n","ERROR:",tmeout);	
								
								
							}
	
							else if(cond3)
							{
								memset(at_,0,100);
								memset(interval,0,5);
								parse_g(uart_string_gsm, 3, 5, ' ', '\r', interval);		
								int_erval=myAtoi(interval);
								save_interval();			
								send_GSM("\r\nAT+CMGD=1,4\r\n","OK\r\n","ERROR\r\n","ERROR:",tmeout);	

								
							}				

			
							else if(cond4)
							{
								send_GSM("\nAT+FSCREATE=C:\\IP_PORT.TXT\r\n", "OK", "ERROR\r\n" , "ERROR:",tmeout);
								send_GSM("\nAT+FSCREATE=D:\\LOG.TXT\r\n", "OK", "ERROR\r\n" , "ERROR:",tmeout);
								send_GSM("\nAT+FSCREATE=C:\\LOG.TXT\r\n", "OK", "ERROR\r\n" , "ERROR:",tmeout);
								send_GSM("\nAT+FSCREATE=C:\\INTERVAL.TXT\r\n", "OK", "ERROR\r\n" , "ERROR:",tmeout);
								memcpy (ip, "104.236.203.4", 13);
								memcpy (port, "5555", 4);		
								memcpy (interval, "1", 1);										
								save_ip_port();
								save_interval();	
								int_erval=myAtoi(interval);		

			//					printf("\n\n\t,%s,%s,%s,\n",ip,port,interval);		
								send_GSM("\r\nAT+CMGD=1,4\r\n","OK\r\n","ERROR\r\n","ERROR:",tmeout);	
								
								
								parse_g(uart_string_gsm, 3, 4, ' ', ' ', apn);

								
								
							}
							else if(cond5)
							{
								memset(at_,0,100);
								memset(num_o,0,15);
								parse_g(uart_string_gsm, 3, 5, ' ', '\r', num_o);
								sprintf(at_, "\r\nAT+CPBW=1,\"%s\",129,\"OWNER1\"\r\n" , num_o);
								send_GSM(at_,"OK\r\n","ERROR\r\n","ERROR:",tmeout);
								send_GSM("\r\nAT+CMGD=1,4\r\n","OK\r\n","ERROR\r\n","ERROR:",tmeout);	
															
						
								
							}		
							else if(cond6)
							{
								memset(at_,0,100);
								memset(num_o,0,15);
								parse_g(uart_string_gsm, 3, 5, ' ', '\r', num_o);
								sprintf(at_, "\r\nAT+CPBW=2,\"%s\",129,\"OWNER2\"\r\n" , num_o);
								send_GSM(at_,"OK\r\n","ERROR\r\n","ERROR:",tmeout);
								send_GSM("\r\nAT+CMGD=1,4\r\n","OK\r\n","ERROR\r\n","ERROR:",tmeout);	
								
															
								
							}									
							else if(cond7)
							{
								memset(at_,0,100);
								memset(num_o,0,15);
								parse_g(uart_string_gsm, 3, 5, ' ', '\r', num_o);
								sprintf(at_, "\r\nAT+CPBW=3,\"%s\",129,\"OWNER3\"\r\n" , num_o);
								send_GSM(at_,"OK\r\n","ERROR\r\n","ERROR:",tmeout);
								send_GSM("\r\nAT+CMGD=1,4\r\n","OK\r\n","ERROR\r\n","ERROR:",tmeout);	
															
															
									
							}		
						else if(cond8)
							{
								
									memset(at_,0,100);
									for(k=0;k<450;k++)
									{
										if(uart_string_gsm[k-1] == ' ' && uart_string_gsm[k-2] == 'G' && uart_string_gsm[k-3] == 'U'
										&& uart_string_gsm[k-4] == 'B' && uart_string_gsm[k-5] == 'E' && uart_string_gsm[k-6] == 'D')
										{
											for(i=0;i<100;i++)
											{
												at_[i]=uart_string_gsm[k];
												k++;
											}	
										at_[i+1]='\r';
										at_[i+2]='\n';	
										}
										else{}
									}
									
								send_GSM("\r\nAT+CMGD=1,4\r\n","OK\r\n","ERROR\r\n","ERROR:",tmeout);	
									  send_GSM(at_,"OK\r\n","ERROR\r\n","ERROR:",tmeout);		
										memset(data2,0,strlen(data2));
										sprintf(data2,"%s",uart_string_gsm);	
										send_message(data2);
										
									
								
							}
							
							else if(cond9)
							{
								send_GSM("\r\nAT+CMGD=1,4\r\n","OK\r\n","ERROR\r\n","ERROR:",tmeout);	

strcat(data,"\n");	
GPS_COLLECT();
strcat(data,"CH\n");	

log_it();								
		RESET_OFF;delay(10);
		RESET_ON;delay(10);
								send_GSM("\n\n AT+CFUN=1,1\r\n","OK\r\n","ERROR\r\n","ERROR:",tmeout);			
							}
							
							else if(cond10)
							{
						//		printf("\n\n\n\t%s",uart_string_gsm);
								memset(ip,0,16);
								parse_g(uart_string_gsm, 3, 4, ' ', ' ', ip);
								parse_g(uart_string_gsm, 6, 5, ' ', '\r', port);	
			//					printf("\n%s\n",port);
								save_ip_port();
							
	//							printf("\n\n\n\t%s\t||\t%s",ip,port);
								send_GSM("\r\nAT+CMGD=1,4\r\n","OK\r\n","ERROR\r\n","ERROR:",tmeout);	

//								while(1);
								
								
							}
							else if(cond13)
							{
								
								IGNITION_ON;
								clear();
								delay(1000);
								send_GSM("\r\r\nAT+CMGD=1,4\r\n\n\n\n\n","OK\r\n","ERROR\r\n","ERROR:",tmeout);	
								
							}
							else if(cond14)
							{
								
								IGNITION_OFF;
								clear();
								delay(1000);
								
								send_GSM("\r\r\nAT+CMGD=1,4\r\n\n\n\n\n","OK\r\n","ERROR\r\n","ERROR:",tmeout);	
								
							}
							
												

							else
							{
								
								send_GSM("\r\n AT+CMGD=1,4\r\n","OK\r\n","ERROR\r\n","ERROR:",tmeout);			

							}


		ringflag=0;
clear();							
send_GSM("\r\n AT+CMGD=1,4\r\n\r\n","OK","ERROR","ERROR:",tmeout);		
delay(1000);					
		}
		
}
int count_char(char ch,char* string)
{
int ass;int count=0;
	//remove_all_chars(string,'\0','\0');
//	ass=strlen(string);
	for(ass=0;ass<strlen(string);ass++)
	{
		if(string[ass] == ch)
		{count++;}
		
	}
return count;
}






int cursor_val(char * stringsd, int cur){
int curinc,curcounter=0,cur2;
for(curinc=0;curinc<strlen(stringsd);curinc++){
		
		if(stringsd[curinc] == '\n'     &&    curcounter < cur   ){ //&& curcounter<=cur	){
			++curcounter;     cur2=curinc;
		}

		

}
	
	
	return cur2;

}


void send_chunk(){
float fsz;
int times,qwe,timeout,k5,enters,cursorvaluepr=0,cursorvaluene=0;
char cond;char*q1;char* q2;char* q3;char *q4;
int notsentflag=0,cntendl=0;
times=-2;	
	
memset(at_,0,100);
sprintf(at_,"\nAT+FSFLSIZE=%s\\LOG.TXT\r\n",drive);	
send_GSM(at_, "OK", "ERROR\r\n" , "ERROR:",tmeout);
parse_g(uart_string_gsm, 1,3, ' ', '\r', fsize);
fsz=stof(fsize);//7523.7412	              //1400 is the maximum imit  //200 is the maximum size of 1 data	
//reading buffer of SD data = 1400 // need to concatinate maximum amount of data in it and a 200 character data
if(fsz==0)k5=9999999;
else k5=0;	
times =	(fsz/1100) + 1;
cursorvaluepr=0;
	
for(k5;k5<=(times);){
	
	get_imei();
memset(data,0,strlen(data));	
GPS_COLLECT();
strcat(data,"\n");	
	
	
	memset(at_,0,100);
	sprintf(at_,"\nAT+FSFLSIZE=%s\\LOG.TXT\r\n",drive);	
	send_GSM(at_, "OK", "ERROR\r\n" , "ERROR:",tmeout);
	parse_g(uart_string_gsm, 1,3, ' ', '\r', fsize);
	fsz=stof(fsize);//7523.7412	              //1400 is the maximum imit  //200 is the maximum size of 1 data	
	//reading buffer of SD data = 1400 // need to concatinate maximum amount of data in it and a 200 character data
	times =	(fsz/1100) + 2;	
	
		sprintf(at_, "\nAT+FSREAD=%s\\LOG.TXT,1,1100,%d\r\n",drive,cursorvaluepr );		//1256
		send_GSM(at_, "OK", "ERROR\r\n" , "ERROR:",5);
		cntendl=count_char('\n',uart_string_gsm);
   //if(cntendl!=0)
		enters = cntendl;		
		memset(sd_data,0,1400);
		parse_g(uart_string_gsm, 1,enters-2, '\n', '\n' ,sd_data);	
		strcat(sd_data,"\n");
		strcat(sd_data,data);
//		memset(at_,0,100);	

		

//		memset(at_,0,100);
//		sprintf(at_,"\nAT+FSFLSIZE=%s\\LOG.TXT\r\n",drive);	
//		send_GSM(at_, "OK", "ERROR" , "ERROR:",tmeout);
//		parse_g(uart_string_gsm, 1,6, ' ', '\r', fsize);
//		fsz=stof(fsize);//7523.7412
//		times=(fsz/1256)+1;  //1256 //1400
//		if(fsz == 0)times=0;				
		qwe=strlen(uart_string_gsm);
		memset(uart_string_gsm,0,qwe);
		
							send_GSM("\r\nAT+CIPSEND\r\n", ">", "ERROR" , "CONNECT",tmeout);	
								cond =mystrstr(uart_string_gsm,'>');
									if(cond)	
									{	
									clear();
									memset(uart_string_gsm,0,5000);
									qwe=strlen(sd_data);
									tout=0;
									k2=0;
									for(k=0;k<(qwe);k++)
									{
										uart_putchar(UART1_BASE_PTR, sd_data[k]);
									}uart_putchar(UART1_BASE_PTR, 0x1A);uart_putchar(UART1_BASE_PTR, 0x1A);
									do
																{q1=strstr(uart_string_gsm,"SEND OK");
																	q2=strstr(uart_string_gsm, "ERROR");
																		q3=strstr(uart_string_gsm, "FAIL");	
																			q4=strstr(uart_string_gsm, "DEACT");	
																	
																}while(!(q1 || q2 || q3 || q4 || (tout > 5) ) ); //|| (timeout < 1)   
																delay(10);clear();
														uart_putchar(UART1_BASE_PTR,0x1A);
												delay(10);
										uart_putchar(UART1_BASE_PTR, 0x1A);uart_putchar(UART1_BASE_PTR, 0x1A);uart_putchar(UART1_BASE_PTR, 0x1A);
delay(50);
if(strstr(uart_string_gsm,"SEND OK"))
{
cursorvaluene=cursor_val(sd_data,enters-3);
cursorvaluepr+=cursorvaluene;
k5++;
}
else{remove_all_chars(data, '\n', '\n');
			strcat(data,"CH\n");	log_it();

			memset(data,0,strlen(data));
			tcp_initialization();
			if(mystrstr(uart_string_gsm,'>')){
									clear();
									memset(uart_string_gsm,0,5000);
									qwe=strlen(data);
									tout=0;
									k2=0;
									for(k=0;k<(qwe);k++)
									{
										uart_putchar(UART1_BASE_PTR, data[k]);
									}uart_putchar(UART1_BASE_PTR, 0x1A);uart_putchar(UART1_BASE_PTR, 0x1A);	
															do
																{q1=strstr(uart_string_gsm,"SEND OK");
																	q2=strstr(uart_string_gsm, "ERROR");
																		q3=strstr(uart_string_gsm, "FAIL");	
																			q4=strstr(uart_string_gsm, "DEACT");	
																	
																}while(!(q1 || q2 || q3 || q4 || (tout > 5) ) );
															
																			delay(10);clear();
														uart_putchar(UART1_BASE_PTR,0x1A);
												delay(10);
										uart_putchar(UART1_BASE_PTR, 0x1A);uart_putchar(UART1_BASE_PTR, 0x1A);uart_putchar(UART1_BASE_PTR, 0x1A);
delay(20);
if(!strstr(uart_string_gsm,"SEND OK")){log_it();}
			
			
			
			
			
			}
			else
			{log_it();}


}

//if(notsentflag==0){cursorvaluene=cursor_val(sd_data);cursorvaluepr+=cursorvaluene;}


}
else{
	remove_all_chars(data, '\n', '\n');
			strcat(data,"CH\n");	
			log_it();
			memset(data,0,strlen(data));
			tcp_initialization();
			if(mystrstr(uart_string_gsm,'>')){
									clear();
									memset(uart_string_gsm,0,5000);
									qwe=strlen(data);
									tout=0;
									k2=0;
									for(k=0;k<(qwe);k++)
									{
										uart_putchar(UART1_BASE_PTR, data[k]);
									}uart_putchar(UART1_BASE_PTR, 0x1A);uart_putchar(UART1_BASE_PTR, 0x1A);	
															do
																{q1=strstr(uart_string_gsm,"SEND OK");
																	q2=strstr(uart_string_gsm, "ERROR");
																		q3=strstr(uart_string_gsm, "FAIL");	
																			q4=strstr(uart_string_gsm, "DEACT");	
																	
																}while(!(q1 || q2 || q3 || q4 || (tout > 5) ) );
															
																			delay(10);clear();
														uart_putchar(UART1_BASE_PTR,0x1A);
												delay(10);
										uart_putchar(UART1_BASE_PTR, 0x1A);uart_putchar(UART1_BASE_PTR, 0x1A);uart_putchar(UART1_BASE_PTR, 0x1A);
delay(20);
if(!strstr(uart_string_gsm,"SEND OK")){log_it();}
			
			
			
			
			
			}
			else
			{log_it();}
//			memset(at_,0,100);
//			sprintf(at_,"\nAT+FSFLSIZE=%s\\LOG.TXT\r\n",drive);	
//			send_GSM(at_, "OK", "ERROR\r\n" , "ERROR:",tmeout);
//			parse_g(uart_string_gsm, 1, 2, ' ', '\n', fsize);
//			fsz=stof(fsize);//7523.7412
//			times=(fsz/1256)+1;
		}	
	
//		
}
if((times != 0      && k5!=9999999)){
	memset(at_,0,100);
	sprintf(at_,"\nAT+FSCREATE=%s\\LOG.TXT\r\n",drive);
	send_GSM(at_, "OK", "ERROR\r\n" , "ERROR:",tmeout);

}		


}




















void send_chunk2()  //send_chunk
{float fsz;
 int times,qwe,timeout,k5,enters;
	char cond;char*q1;char* q2;char* q3;char *q4;
memset(at_,0,100);
sprintf(at_,"\nAT+FSFLSIZE=%s\\LOG.TXT\r\n",drive);	
send_GSM(at_, "OK", "ERROR\r\n" , "ERROR:",tmeout);
	parse_g(uart_string_gsm, 1,6, ' ', '\r', fsize);
	fsz=stof(fsize);//7523.7412
	times=(fsz/1256)+1;  //1256 //1400
		if(fsz == 0)times=0;
	for(k5=0;k5<times;)
	{ memset(uart_string_gsm,0,strlen(uart_string_gsm));
		memset(sd_data,0,1256);
		memset(at_,0,100);
		sprintf(at_, "\nAT+FSREAD=%s\\LOG.TXT,1,1256,%d\r\n",drive,(k5*1256) );		//1256
		send_GSM(at_, "OK\r\n", "ERROR\r\n" , "ERROR:",10);
    enters = count_char('\r',uart_string_gsm);		
		parse_g(uart_string_gsm, 1,enters-1, '\n', '\r' ,sd_data);
//		printf ("\n\n\n\t\t\t****************************\n%s\n\n\n\t\t\t*****************************",sd_data);

		
get_imei();		
clear();		
memset(data,0,strlen(data));
GPS_COLLECT();
strcat(data,"CH\n");	
log_it();
memset(at_,0,100);
sprintf(at_,"\nAT+FSFLSIZE=%s\\LOG.TXT\r\n",drive);	
send_GSM(at_, "OK", "ERROR" , "ERROR:",tmeout);
parse_g(uart_string_gsm, 1,6, ' ', '\r', fsize);
fsz=stof(fsize);//7523.7412
times=(fsz/1256)+1;  //1256 //1400
if(fsz == 0)times=0;				
qwe=strlen(uart_string_gsm);
memset(uart_string_gsm,0,qwe);
		
							send_GSM("\r\nAT+CIPSEND\r\n", ">", "ERROR" , "CONNECT",tmeout);	
								cond =mystrstr(uart_string_gsm,'>');
									if(cond)	
									{
									clear();
									memset(uart_string_gsm,0,5000);
									qwe=strlen(sd_data);
									tout=0;
									k2=0;
									for(k=0;k<(qwe-1);k++)
									{
										uart_putchar(UART1_BASE_PTR, sd_data[k]);
									}uart_putchar(UART1_BASE_PTR, 0x1A);uart_putchar(UART1_BASE_PTR, 0x1A);
									do
																{q1=strstr(uart_string_gsm,"OK");
																	q2=strstr(uart_string_gsm, "ERROR");
																		q3=strstr(uart_string_gsm, "FAIL");	
																			q4=strstr(uart_string_gsm, "DEACT");	
																	
																}while(!(q1 || q2 || q3 || q4 || (tout > 6) ) ); //|| (timeout < 1)   
																delay(10);clear();
														uart_putchar(UART1_BASE_PTR,0x1A);
												delay(10);
										uart_putchar(UART1_BASE_PTR, 0x1A);uart_putchar(UART1_BASE_PTR, 0x1A);uart_putchar(UART1_BASE_PTR, 0x1A);
						k5++;









//										
//																clear();

//										qwe=strlen(sd_data);
//										for(k=0;k<(qwe-1);k++)
//										{
//											uart_putchar(UART1_BASE_PTR, sd_data[k]); //clear();
//										}	

//											uart_putchar(UART1_BASE_PTR, 0x1A);uart_putchar(UART1_BASE_PTR, 0x1A);
//													k2=0;									//string array counter for uart 1
//													timeout=999001;						//timer counts to wait for characters in uart 1 									
//													//send_modem("\r\n");//uart_putchar(UART1_BASE_PTR, 0x1A);send_modem("\r\n");uart_putchar(UART1_BASE_PTR, 0x1A);send_modem("\r\n");

//														do
//																{q1=strstr(uart_string_gsm,"OK\r\n");
//																	q2=strstr(uart_string_gsm, "ERROR");																	
//																	timeout--;


//																}while(!( q1 || (timeout < 1) || q2) );
//																delay(10);clear();
//														uart_putchar(UART1_BASE_PTR,0x1A);
//												delay(10);
//										uart_putchar(UART1_BASE_PTR, 0x1A);uart_putchar(UART1_BASE_PTR, 0x1A);uart_putchar(UART1_BASE_PTR, 0x1A);
//														
//										k5++;
								//		memset(data,0,1000);
	//									if(k5 >= times-1){
	//										send_GSM("\nAT+FSCREATE=C:\\LOG.TXT\r\n", "OK", "ERROR\r\n" , "ERROR:",tmeout);
	//									}
									}
							else{
										log_it();
										memset(data,0,strlen(data));
										tcp_initialization();
										log_it();
										memset(at_,0,100);
										sprintf(at_,"\nAT+FSFLSIZE=%s\\LOG.TXT\r\n",drive);	
										send_GSM(at_, "OK", "ERROR\r\n" , "ERROR:",tmeout);
										parse_g(uart_string_gsm, 1, 2, ' ', '\n', fsize);
										fsz=stof(fsize);//7523.7412
										times=(fsz/1256)+1;
									}	
	
//		
		}
if((times != 0)){
memset(at_,0,100);
sprintf(at_,"\nAT+FSCREATE=%s\\LOG.TXT\r\n",drive);
send_GSM(at_, "OK", "ERROR\r\n" , "ERROR:",tmeout);
}		

	//	sprintf(at_, "\r\nAT+CIPSTART=\"TCP\",\"%s\",\"%s\"\r\n", ip, port);
	//	printf("\n%s\n",send_GSM( at_ , "CONNECT", "ERROR\r\n" , "CONNECT",tmeout));	
	//	printf("\n%s\n",send_GSM("\r\nAT+CIPSEND\r\n", ">", "ERROR\r\n" , "CONNECT",tmeout));	

	//		
		
		
	}
			
	
	void bat_cind()
	{int netwrk;char netwrk_c[1];
		
				send_GSM("\r\nAT+CIND?\r\n", "OK", "ERROR\r\n" , "ERROR:",tmeout);
				parse_g(uart_string_gsm, 1, 2, ',', ',', netwrk_c);
				netwrk = netwrk_c[0]- '0';
				

		switch(netwrk)
		{
			case 1:
				
    RED_OFF;		//Turn off RED LED
    GREEN_OFF;	//Turn off GREEN LED
    BLUE_OFF;		//Turn off BLUE LED			
			
				 RED_ON;		//Turn off RED LED
					
			break;
			
			case 2:
		
    RED_OFF;		//Turn off RED LED
    GREEN_OFF;	//Turn off GREEN LED
    BLUE_OFF;		//Turn off BLUE LED
			
				 RED_ON;		//Turn off RED LED
				 GREEN_ON;
			
			break;
			
			case 3:
				
    RED_OFF;		//Turn off RED LED
    GREEN_OFF;	//Turn off GREEN LED
    BLUE_OFF;		//Turn off BLUE LED
			
				 GREEN_ON;		//Turn off RED LED

			
			break;

			case 4:
				
    RED_OFF;		//Turn off RED LED
    GREEN_OFF;	//Turn off GREEN LED
    BLUE_OFF;		//Turn off BLUE LED
			
				 BLUE_ON;		//Turn off RED LED
				 GREEN_ON;
			
			break;
			
			case 5:
				
    RED_OFF;		//Turn off RED LED
    GREEN_OFF;	//Turn off GREEN LED
    BLUE_OFF;		//Turn off BLUE LED
						
				 BLUE_ON;		//Turn off RED LED
				
			break;
			
			default:
			
    RED_OFF;		//Turn off RED LED
    GREEN_OFF;	//Turn off GREEN LED
    BLUE_OFF;		//Turn off BLUE LED
			
			break;
			
			

		}			
		




		
		
		
	}
	
	
	void send_balance(){}
	
			
	void send_message(char * data2)
	{
									memset(at_,0,100);
									sprintf(at_, "\nAT+CMGS=\"%s\"\r\n" ,num2);
									send_MSG(at_, ">", "ERROR\r\n" , "ERROR:",tmeout);	
									if( strstr(uart_string_gsm, ">"))
									{
										//
										
											for(k=0;k<strlen(data2);k++)
											{
												
												uart_putchar(UART1_BASE_PTR, data2[k]);
												//uart0_putchar(UART0_BASE_PTR, data2[k]);
												clear();
												
											}		
											uart_putchar(UART1_BASE_PTR, 0x1A);
											k2=0;									//string array counter for uart 1
											timeout=99999;						//timer counts to wait for characters in uart 1 									
											while(!(strstr(uart_string_gsm,"+CMGS:")  ||  (timeout < 1)))
																{
																	timeout--;
//																	if(timeout % 4000 == 0)
//																	{
//																		uart0_putchar(UART0_BASE_PTR,'1');
//																		uart_putchar(UART1_BASE_PTR,0x1A);
//																	}
																}
							
									}
		
									
	}





	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	

