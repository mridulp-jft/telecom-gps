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
//#include "lptmr.c"





#ifdef CMSIS
#include "start.h"
#endif


int32 tmeout=299999,int_erval=5; //10 SECS TIMEOUT
extern char in_char1(),in_char2();
extern void out_char1(char ch),out_char2(char ch);
char string_gps[100],gga[100],rmc[100],uart_string_gps[500],data2[200];
float speed=0;
char 
		 ip[16]="104.236.203.4",
		 port[10]="5555",
		 at_[100],
		 imei[20],
		 lati[20],
		 longi[20],
		 velocity[5],
		 fsize[15],
		 num_o[15],
		 interval[5];

int32 timeout=0;
void send_message(char * data2);
float pr=0,la=0;
char uart_string_gsm[5000],sd_data[1400];
int ggaptr=0,rmcptr=0;
int i=0,motion_samples=0,notsleep=0;
char ch; 
void delay(int delaytime), get_gpsdata(), GPS_COLLECT(), loop(), auto_caliberate_accelerometer(), tcp_initialization(), tcp_initialization2(), 	 msg_sim800();
void  send_chunk(),bat_cind();
extern void send_modem(char ch[]);void get_imei();
char ringflag=0,lptmr_interrupt=0;
extern void lptmr_init(int count, int clock_source);


void remove_all_chars(char* str, char c, char d) {
    char *pr = str, *pw = str;
    while (*pr) {
        *pw = *pr++;
			pw += (*pw != c && *pw != d && *pw != ' ' && *pw != '/' && *pw != ':');
    }
    *pw = '\0';
}


/*************************** delay*****************************************/
 void delay(int delaytime)
{
 while(delaytime--)
    {for(i=200;i>0;i--)
			{if(lptmr_interrupt == 1){accel_read();detect_motion();lptmr_interrupt = 0;}		
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




/********************************************************************/
int main (void)
{
	
delay(3000);	
	
	start();
systick_init();	
#ifdef CMSIS  // If we are conforming to CMSIS, we need to call start here

#endif
	

	
	
	
	LED_init();		//Initialize GPIO for LEDs
	RELAY_init();		//Initialize GPIO for LEDs
	SW1_init();		//Initialize GPIO for SW1 w/ interrupt	
	accel_init();
	
//while(1)	
{i++;
printf("\n Hello World %d", i);
//GPS_COLLECT();
stateCount=0;
while(1){
IGNITION_ON;delay(2000);
FUEL_ON;delay(2000);
IGNITION_OFF;delay(2000);
FUEL_OFF;delay(2000);
	
	
}

}
	
	lptmr_init(500, 1);
	

//delay(100);
	
uart_putchar(UART1_BASE_PTR,0x1A);
uart_putchar(UART1_BASE_PTR,0x1A);	

//	send_modem("$PMTK225,0*2B");	send_modem("“$PMTK225,0*2B”");



//do
	{
	
		uart_putchar(UART1_BASE_PTR,0x1A);
		uart_putchar(UART1_BASE_PTR,0xA);
		uart_putchar(UART1_BASE_PTR,0x1A);
		uart_putchar(UART1_BASE_PTR,0xA);
		uart_putchar(UART1_BASE_PTR,0x1A);		
	
	printf("%s\n",send_GSM("\n\nAT\r\n","OK\r\n","ERROR\r\n","ERROR:",tmeout));    
		
		printf("%s\n",send_GSM("\n\nAT+GSV\r\n","OK\r\n","ERROR\r\n","ERROR:",tmeout));  	
		//delay(10);

}
	
//send_modem2("$PMTK225,0*2B");
//while(!strstr(uart_string_gsm,"OK\r\n"));

//bat_cind();
//delay(1000);

printf("%s\n",send_GSM("\n\nAT&W\r\n","OK\r\n","ERROR\r\n","ERROR:",tmeout));    //   uart_putchar(UART1_BASE_PTR,0x1A);uart_putchar(UART1_BASE_PTR,0xA);uart_putchar(UART1_BASE_PTR,0x1A);uart_putchar(UART1_BASE_PTR,0xA);uart_putchar(UART1_BASE_PTR,0x1A);		
//delay(10);

printf("%s\n",send_GSM("\n\nATS0=2\r\n","OK\r\n","ERROR\r\n","ERROR:",tmeout)); 	


printf("%s\n",send_GSM("\n\nAT&F\r\n","OK\r\n","ERROR\r\n","ERROR:",tmeout)); 	


printf("%s\n",send_GSM("\n\nAT&D\r\n","OK\r\n","ERROR\r\n","ERROR:",tmeout)); 	


printf("%s\n",send_GSM("\n\nAT+IFC=0,0\r\n","OK\r\n","ERROR\r\n","ERROR:",tmeout));
//delay(10);

printf("%s\n",send_GSM("\n\nAT+GSN\r\n","OK\r\n","ERROR\r\n","ERROR:",tmeout));
get_imei();
//delay(10);

printf("%s\n",send_GSM("\n\nAT+SD2PCM=0\r\n","OK\r\n","ERROR\r\n","ERROR:",tmeout));
//delay(10);	

printf("%s\n",send_GSM("\n\nAT&W\r\n","OK\r\n","ERROR\r\n","ERROR:",tmeout));
//;	

//printf("%s\n",send_GSM("\n\nAT+IFC=0,0\r\n","OK\r\n","ERROR\r\n","ERROR:",tmeout));


printf("%s\n",send_GSM("\n\nAT+FSLS=D:\\\r\n"," ","ERROR\r\n","ERROR:",tmeout));


printf("%s\n",send_GSM("\n\nAT+FSMEM\r\n","OK\r\n","ERROR\r\n","ERROR:",tmeout));


printf("%s\n",send_GSM("\n\nAT+FSCREATE=D:\\MRIDUL.TXT\r\n","OK\r\n","ERROR\r\n","ERROR:",tmeout));





printf("%s\n",send_GSM("\n\nATS0=1\r\n","OK\r\n","ERROR\r\n","ERROR:",tmeout));



//delay(10);

//printf("%s\n",send_GSM("\n\nAT+CMGD=1,4\r\n","OK\r\n","ERROR\r\n","ERROR:",tmeout));//del_msg();
//delay(10);

//printf("%s\n",send_GSM("\n\nAT+CPBW=1,\"100\",129,\"OWNER1\"\r\n","OK\r\n","ERROR\r\n","ERROR:",tmeout));


//printf("%s\n",send_GSM("\n\nAT+CPBW=2,\"100\",129,\"OWNER2\"\r\n","OK\r\n","ERROR\r\n","ERROR:",tmeout));


//printf("%s\n",send_GSM("\n\nAT+CPBW=3,\"100\",129,\"OWNER3\"\r\n","OK\r\n","ERROR\r\n","ERROR:",tmeout));


//printf("%s\n",send_GSM("\n\nAT+CPBW=4,\"100\",129,\"OWNER4\"\r\n","OK\r\n","ERROR\r\n","ERROR:",tmeout));



printf("%s\n",send_GSM("\n\nAT+CPBW=5,\"9873999108\",129,\"OWNER5\"\r\n","OK\r\n","ERROR\r\n","ERROR:",tmeout));


printf("%s\n",send_GSM("\n\nAT+CPBW=6,\"8287324005\",129,\"OWNER6\"\r\n","OK\r\n","ERROR\r\n","ERROR:",tmeout));

//printf("%s\n",send_GSM("\n\nAT+CPBW=4,\"8287324005\",129,\"OWNER2\"\r\n","OK\r\n","ERROR\r\n","ERROR:",tmeout));
read_interval();
printf("%s\n",send_GSM("\n\nAT+CMGF=1\n\n","OK\r\n","ERROR\r\n","ERROR:",tmeout));
//delay(10);	

printf("%s\n",send_GSM("\n\nAT+CSCA?\r\n","OK\r\n","ERROR\r\n","ERROR:",tmeout));    //   uart_putchar(UART1_BASE_PTR,0x1A);uart_putchar(UART1_BASE_PTR,0xA);uart_putchar(UART1_BASE_PTR,0x1A);uart_putchar(UART1_BASE_PTR,0xA);uart_putchar(UART1_BASE_PTR,0x1A);		
							memset(at_,0,100);
							memset(num_o,0,15);
							parse_g(uart_string_gsm, 1, 2, '\"', '\"', num_o);
							sprintf(at_, "\r\nAT+CSCA=\"%s\"\r\n", num_o);
							printf("%s\n",send_GSM(at_,"OK\r\n","ERROR\r\n","ERROR:",tmeout));

//delay(10);	







read_ip_port();


tcp_initialization2();

//							GPS_COLLECT();		accel_read();detect_motion();

//do{
//printf("%s\n",send_GPS("\n\nAT+CGPSPWR=1\n\n","OK\r\n","ERROR\r\n","ERROR:",tmeout));
//delay(50);
//printf("%s\n",send_GPS("\n\nAT+CGPSOUT=255\n\n","OK\r\n","ERROR\r\n","ERROR:",tmeout));
//}while(strstr(uart_string_gps,"ERROR"));

//delay(50);

auto_caliberate_accelerometer();


//phonebook_read("5");parse(1,2);
	


while(1)
{
		accel_read();

						
					
						{ // main tcp GPS_COLLECT

							loop();

						}

		
/******************while end**********************/		
	} 
/******************main end***********************/
}
/********************************************************************/





void HardFault_Handler()
{


}


void LPTimer_IRQHandler(void)
{
  
//  printf("\n****LPT ISR entered*****\r\n");
	
//stateCount++; 
//if(stateCount>5){stateCount =0;}
//		LED_state();
		lptmr_interrupt = 1;
//accel_read();
//detect_motion();
  // enable timer
  // enable interrupts
  // clear the flag
  LPTMR0_CSR |=  LPTMR_CSR_TCF_MASK;   // write 1 to TCF to clear the LPT timer compare flag
  LPTMR0_CSR = ( LPTMR_CSR_TEN_MASK | LPTMR_CSR_TIE_MASK | LPTMR_CSR_TCF_MASK  );

}






















void loop()
{
				int qwe;
	
msg_sim800(); 


							bat_cind();

msg_sim800(); 


							GPS_COLLECT();//accel_read();detect_motion();

msg_sim800(); 


							printf("\n%s\n",send_GSM("\r\nAT+CIPCLOSE\r\n", "CLOSE OK\r\n", "ERROR\r\n" , "ERROR:",tmeout));		

msg_sim800(); 

							GPS_COLLECT();

msg_sim800(); 

							
							printf("%s\n",send_GSM("\n\nAT+GSN\r\n","OK\r\n","ERROR\r\n","ERROR:",tmeout));

							get_imei();clear();							
							printf("\n%s\t->\t%d\n",imei,strlen(imei));
							memset(at_,0,100);
							sprintf(at_, "\r\nAT+CIPSTART=\"TCP\",\"%s\",\"%s\"\r\n", ip, port);
							
							GPS_COLLECT();//accel_read();detect_motion();
							
							printf("\n%s\n",send_GSM( at_ , "CONNECT", "ERROR" , "ERROR:",tmeout));										

							GPS_COLLECT();//accel_read();detect_motion();

							printf("\n%d\n",strlen(data));
							
							printf("\n%s\n",send_GSM("\r\nAT+CIPSEND\r\n", ">", "ERROR\r\n" , "CONNECT FAIL",tmeout));	
							
							GPS_COLLECT();//accel_read();detect_motion();	//
							clear();		
							send_tcp();

msg_sim800(); 

							
							GPS_COLLECT();//accel_read();detect_motion();

msg_sim800(); 


							printf("%s\n",send_GSM("\n\nAT+CMGF=1\n\n","OK\r\n","ERROR\r\n","ERROR:",tmeout));

msg_sim800(); 

							
							//delay(10);	
							printf("%s\n",send_GSM("\n\nAT+CSCA?\r\n","OK\r\n","ERROR\r\n","ERROR:",tmeout));    //   uart_putchar(UART1_BASE_PTR,0x1A);uart_putchar(UART1_BASE_PTR,0xA);uart_putchar(UART1_BASE_PTR,0x1A);uart_putchar(UART1_BASE_PTR,0xA);uart_putchar(UART1_BASE_PTR,0x1A);		
														memset(at_,0,100);
														memset(num_o,0,15);
														parse_g(uart_string_gsm, 1, 2, '\"', '\"', num_o);
														sprintf(at_, "\r\nAT+CSCA=\"%s\"\r\n", num_o);
														printf("%s\n",send_GSM(at_,"OK\r\n","ERROR\r\n","ERROR:",tmeout));	
														
							//msg_sim800(); 

							if(motion_samples >= 200)
								{
									//vehicle not in motion
							//		gsm_gps_sleep();
									motion_samples = 0;
									
								}
							
								
msg_sim800(); 


								GPS_COLLECT();//accel_read();detect_motion();


msg_sim800(); 

								
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



void GPS_COLLECT()
{
		char prev[6],latest[6];
		int iz;
		double a,b,c;int hh,mm1,mm2;
		double a1,b1,c1;
		double hh11, mm11,mm22;

		if (int_erval<5)
		int_erval=0;

		do{
			
		get_gpsdata();
		accel_read();detect_motion();	
		parse(rmc,2,3,lati);
		parse(rmc,4,5,longi);
		parse(rmc,6,7,velocity);	
		for(iz=0;iz<6;iz++)
			{
				latest[iz]=gga[iz];		
			}
		la=stof(latest);
		printf("\n\n\t\t,%f,\t,%f,",la,pr);

		}while((la-pr < int_erval));
		pr=la;

		
		speed = stof(velocity);
		c=stof(lati);//7523.7412
		hh= c/100; //75
		hh11 = c/100; //75.237412
		mm11 = hh11-hh; //.237412
		mm11*=100;
		mm22=hh+mm11/60;	
		printf("\n\n\t\t,%d,%f,%f\t,%s,%d\n",hh,mm11,mm22,latest,la);
		memset(lati,0,15);
		sprintf(lati,"%f",mm22);
		c=stof(longi);//7523.7412
		hh= c/100; //75
		hh11 = c/100; //75.237412
		mm11 = hh11-hh; //.237412
		mm11*=100;
		mm22=hh+mm11/60;	
		printf("\n\n\t\t,%d,%f,%f\n",hh,mm11,mm22);	
		memset(longi,0,15);
		sprintf(longi,"%f",mm22);	


			
			
		strcat(data,"\n");
		strcat(data,imei);
		strcat(data,", ");	
		strcat(data,"$GxGGA,");	
		strcat(data,gga);
		strcat(data,", $GxRMC,");	
		strcat(data,rmc);	
		//strcat(data,"\n");		
		//printf("\n%s\n",data);

}






void tcp_initialization()
{

msg_sim800(); 

	
						printf("\n%s\n",send_GSM("\r\nAT+CFUN=0\r\n", "OK\r\n", "ERROR\r\n" , "ERROR:",tmeout));	
						delay(500);

						printf("\n%s\n",send_GSM("\r\nAT+CFUN=1\r\n", "OK\r\n", "ERROR\r\n" , "ERROR:",tmeout));	
						delay(2000);

msg_sim800(); 

						GPS_COLLECT();
						printf("\n%s\n",send_GSM("\r\nAT+CIPSHUT\r\n", "SHUT OK\r\n", "ERROR\r\n" , "ERROR:",tmeout));	

msg_sim800(); 

						//delay(20);								
						GPS_COLLECT();
						printf("\n%s\n",send_GSM("\r\nAT+CSTT=\"www\"\r\n", "OK\r\n", "ERROR\r\n" , "ERROR:",tmeout));	
						//delay(20);

msg_sim800(); 

						GPS_COLLECT();
						printf("\n%s\n",send_GSM("\r\nAT+CIICR\r\r\n", "OK\r\n", "ERROR\r\n" , "ERROR:",tmeout));		
						//delay(20);
		//				GPS_COLLECT();

msg_sim800(); 

						clear();send_modem("\nAT+CIFSR\r\r\n");clear();
						delay(20);


msg_sim800(); 

						sprintf(at_, "\r\nAT+CIPSTART=\"TCP\",\"%s\",\"%s\"\r\n", ip, port);
						printf("\n%s\n",send_GSM( at_ , "CONNECT", "ERROR" , "ERROR:",tmeout));	
						clear();

}


void tcp_initialization2()
{

msg_sim800(); 

								//GPS_COLLECT();
								printf("\n%s\n",send_GSM("\r\nAT+CIPSHUT\r\n", "SHUT OK\r\n", "ERROR\r\n" , "ERROR:",tmeout));	
								//delay(20);		
								GPS_COLLECT();

msg_sim800(); 


								printf("\n%s\n",send_GSM("\r\nAT+CSTT=\"www\"\r\n", "OK\r\n", "ERROR\r\n" , "ERROR:",tmeout));	
								//delay(20);
								GPS_COLLECT();

msg_sim800(); 

	
								printf("\n%s\n",send_GSM("\r\nAT+CIICR\r\r\n", "OK\r\n", "ERROR\r\n" , "ERROR:",tmeout));		
								//delay(20);
								GPS_COLLECT();

msg_sim800(); 

								
								clear();send_modem("\nAT+CIFSR\r\r\n");clear();
								delay(20);
	

msg_sim800(); 

		
								sprintf(at_, "\r\nAT+CIPSTART=\"TCP\",\"%s\",\"%s\"\r\n", ip, port);
								printf("\n%s\n",send_GSM( at_ , "CONNECT", "ERROR\r\n" , "ERROR:",tmeout));	
								clear();

}







void get_gpsdata()
{
						int m;	clear2();
						memset(uart_string_gps,0,500);memset(gga,0,100);memset(rmc,0,100);			
					i=0;
					do
						{uart_string_gps[i]=in_char2();i++;if(i>490){i=0;};
						}while(!(uart_string_gps[i-4] == 'R' && uart_string_gps[i-3] == 'M' && uart_string_gps[i-2] == 'C' && uart_string_gps[i-1] == ','));
					m=i;	
					i=0;//uart_string_gps[i-6] != 'G' && uart_string_gps[i-5] != 'P' &&
					do
						{rmc[i]=in_char2();i++;
						}while(rmc[i-1] != '*');
					
					i=m;
					do
						{uart_string_gps[i]=in_char2();i++;if(i>490){i=0;}
						}while(!(uart_string_gps[i-4] == 'G' && uart_string_gps[i-3] == 'G' && uart_string_gps[i-2] == 'A' && uart_string_gps[i-1] == ','));
					i=0;//uart_string_gps[i-6] != 'G' && uart_string_gps[i-5] != 'P' &&
					do
						{gga[i]=in_char2();i++;
						}while(gga[i-1] != '*');

						
printf("\n\t%s\n\t%s\n\t\n",gga,rmc);		
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
{int c1nt,c1nt2=0;
memset(imei,0,20);
	clear();	
	for(c1nt=0;c1nt<strlen(uart_string_gsm);c1nt++)
	{
		if(( uart_string_gsm[c1nt] == '\n')	|| (uart_string_gsm[c1nt] == '\r')	|| (uart_string_gsm[c1nt] == 'A')	
																				|| (uart_string_gsm[c1nt] == 'T')		|| (uart_string_gsm[c1nt] == '+')
																				|| (uart_string_gsm[c1nt] == 'G')		|| (uart_string_gsm[c1nt] == 'S')
																				|| (uart_string_gsm[c1nt] == 'N')		|| (uart_string_gsm[c1nt] == 'O')
																				|| (uart_string_gsm[c1nt] == 'K')		|| (uart_string_gsm[c1nt] == 'E')
																				|| (uart_string_gsm[c1nt] == 'R'))
																				{}
		
		else
		{	imei[c1nt2] = uart_string_gsm[c1nt]; c1nt2++;}		
		}
}
	
	

void msg_sim800() 
{
//ringflag=1;	
	if(ringflag==1)
	{
	
					printf("\n\n\thttps://www.google.com/search?q=%s%c2C%s&ie=utf-8&oe=utf-8\n",lati,'%',longi,velocity,lati,longi);
					printf("\n%s\n",send_GSM("\r\nAT+CMGR=1\r\n", "OK\r\n", "ERROR" , "OK\r\n",tmeout));	
					clear();
					parse_gsm(uart_string_gsm, 3, 4, num2);
			
			
			
			
			
			
			
			
					if(strstr(uart_string_gsm, "OWNER"))
					{
							if(strstr(uart_string_gsm, "LOCATION"))
							{
								memset(data2,0,strlen(data2));
								sprintf(data2,"\nCoordinates : %s N, %s E\nSpeed : %s kmph\n\nhttps://www.google.com/search?q=%s%c2C%s&ie=utf-8&oe=utf-8\n",lati,longi,velocity,lati,'%',longi);	
								send_message(data2);

								printf("%s\n",send_GSM("\n\n AT+CMGD=1,4\r\n","OK\r\n","ERROR\r\n","ERROR:",tmeout));			
								
								
							}
	
							
							
						
							else if(strstr(uart_string_gsm, "INTERVAL"))
							{
								memset(at_,0,100);
								memset(interval,0,5);
								parse_g(uart_string_gsm, 3, 5, ' ', '\r', interval);		
								int_erval=myAtoi(interval);
								save_interval();			
								printf("%s\n",send_GSM("\n\n AT+CMGD=1,4\r\n","OK\r\n","ERROR\r\n","ERROR:",tmeout));			

								
							}				



						
							if(strstr(uart_string_gsm, "START"))
							{
								printf("\n%s\n",send_GSM("\nAT+FSCREATE=C:\\IP_PORT.TXT\r\n", "OK", "ERROR\r\n" , "ERROR:",999999));
								printf("\n%s\n",send_GSM("\nAT+FSCREATE=C:\\LOG.TXT\r\n", "OK", "ERROR\r\n" , "ERROR:",999999));
								printf("\n%s\n",send_GSM("\nAT+FSCREATE=C:\\INTERVAL.TXT\r\n", "OK", "ERROR\r\n" , "ERROR:",999999));
								memcpy (ip, "104.236.203.4", 13);
								memcpy (port, "5555", 4);		
								memcpy (interval, "1", 1);										
								save_ip_port();
								save_interval();	
								printf("\n\n\t,%s,%s,%s,\n",ip,port,interval);		
								printf("%s\n",send_GSM("\n\n AT+CMGD=1,4\r\n","OK\r\n","ERROR\r\n","ERROR:",tmeout));			
								
							}
							else if(strstr(uart_string_gsm, "OWNER1"))
							{
								memset(at_,0,100);
								memset(num_o,0,15);
								parse_g(uart_string_gsm, 3, 5, ' ', '\r', num_o);
								sprintf(at_, "\r\nAT+CPBW=1,\"%s\",129,\"OWNER1\"\r\n" , num_o);
								printf("%s\n",send_GSM(at_,"OK\r\n","ERROR\r\n","ERROR:",tmeout));
								printf("%s\n",send_GSM("\n\n AT+CMGD=1,4\r\n","OK\r\n","ERROR\r\n","ERROR:",tmeout));			
															
						
								
							}		
							else if(strstr(uart_string_gsm, "OWNER2"))
							{
								memset(at_,0,100);
								memset(num_o,0,15);
								parse_g(uart_string_gsm, 3, 5, ' ', '\r', num_o);
								sprintf(at_, "\r\nAT+CPBW=2,\"%s\",129,\"OWNER2\"\r\n" , num_o);
								printf("%s\n",send_GSM(at_,"OK\r\n","ERROR\r\n","ERROR:",tmeout));
								printf("%s\n",send_GSM("\n\n AT+CMGD=1,4\r\n","OK\r\n","ERROR\r\n","ERROR:",tmeout));			
															
								
							}									
							else if(strstr(uart_string_gsm, "OWNER3"))
							{
								memset(at_,0,100);
								memset(num_o,0,15);
								parse_g(uart_string_gsm, 3, 5, ' ', '\r', num_o);
								sprintf(at_, "\r\nAT+CPBW=3,\"%s\",129,\"OWNER3\"\r\n" , num_o);
								printf("%s\n",send_GSM(at_,"OK\r\n","ERROR\r\n","ERROR:",tmeout));
								printf("%s\n",send_GSM("\n\n AT+CMGD=1,4\r\n","OK\r\n","ERROR\r\n","ERROR:",tmeout));			
															
															
									
							}		
						else if(strstr(uart_string_gsm, "DEBUG"))
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
									
									printf("%s\n",send_GSM(at_,"OK\r\n","ERROR\r\n","ERROR:",tmeout));		
										memset(data2,0,strlen(data2));
										sprintf(data2,"%s",uart_string_gsm);	
										send_message(data2);
									printf("%s\n",send_GSM("\n\n AT+CMGD=1,4\r\n","OK\r\n","ERROR\r\n","ERROR:",tmeout));		
									
								
							}
							
							else if(strstr(uart_string_gsm, "RESET"))
							{
								printf("%s\n",send_GSM("\n\n AT+CMGD=1,4\r\n","OK\r\n","ERROR\r\n","ERROR:",tmeout));			
								printf("%s\n",send_GSM("\n\n AT+CFUN=1,1\r\n","OK\r\n","ERROR\r\n","ERROR:",tmeout));			
							}
							
							else if(strstr(uart_string_gsm, "IP"))
							{
								printf("\n\n\n\t%s",uart_string_gsm);
								memset(ip,0,16);
								parse_g(uart_string_gsm, 3, 4, ' ', ' ', ip);
								parse_g(uart_string_gsm, 6, 5, ' ', '\r', port);	
								printf("\n%s\n",port);
								save_ip_port();
							
	//							printf("\n\n\n\t%s\t||\t%s",ip,port);
								printf("%s\n",send_GSM("\n\n AT+CMGD=1,4\r\n","OK\r\n","ERROR\r\n","ERROR:",tmeout));	

//								while(1);
								
								
							}							
							
												

							else
							{
								
								printf("%s\n",send_GSM("\n\n AT+CMGD=1,4\r\n","OK\r\n","ERROR\r\n","ERROR:",tmeout));			

							}

								
					}
					
					else
					{
						
						
							if(strstr(uart_string_gsm, "START"))
							{
								printf("\n%s\n",send_GSM("\nAT+FSCREATE=C:\\IP_PORT.TXT\r\n", "OK", "ERROR\r\n" , "ERROR:",999999));
								printf("\n%s\n",send_GSM("\nAT+FSCREATE=C:\\LOG.TXT\r\n", "OK", "ERROR\r\n" , "ERROR:",999999));
								printf("\n%s\n",send_GSM("\nAT+FSCREATE=C:\\INTERVAL.TXT\r\n", "OK", "ERROR\r\n" , "ERROR:",999999));
								memcpy (ip, "104.236.203.4", 13);
								memcpy (port, "5555", 4);		
								memcpy (interval, "1", 1);										
								save_ip_port();
								save_interval();	
								printf("\n\n\t,%s,%s,%s,\n",ip,port,interval);		
								printf("%s\n",send_GSM("\n\n AT+CMGD=1,4\r\n","OK\r\n","ERROR\r\n","ERROR:",tmeout));			
								
							}
							else if(strstr(uart_string_gsm, "OWNER1"))
							{
								memset(at_,0,100);
								memset(num_o,0,15);
								parse_g(uart_string_gsm, 3, 5, ' ', '\r', num_o);
								sprintf(at_, "\r\nAT+CPBW=1,\"%s\",129,\"OWNER1\"\r\n" , num_o);
								printf("%s\n",send_GSM(at_,"OK\r\n","ERROR\r\n","ERROR:",tmeout));
								printf("%s\n",send_GSM("\n\n AT+CMGD=1,4\r\n","OK\r\n","ERROR\r\n","ERROR:",tmeout));			
															
						
								
							}		
							else if(strstr(uart_string_gsm, "OWNER2"))
							{
								memset(at_,0,100);
								memset(num_o,0,15);
								parse_g(uart_string_gsm, 3, 5, ' ', '\r', num_o);
								sprintf(at_, "\r\nAT+CPBW=2,\"%s\",129,\"OWNER2\"\r\n" , num_o);
								printf("%s\n",send_GSM(at_,"OK\r\n","ERROR\r\n","ERROR:",tmeout));
								printf("%s\n",send_GSM("\n\n AT+CMGD=1,4\r\n","OK\r\n","ERROR\r\n","ERROR:",tmeout));			
															
								
							}									
							else if(strstr(uart_string_gsm, "OWNER3"))
							{
								memset(at_,0,100);
								memset(num_o,0,15);
								parse_g(uart_string_gsm, 3, 5, ' ', '\r', num_o);
								sprintf(at_, "\r\nAT+CPBW=3,\"%s\",129,\"OWNER3\"\r\n" , num_o);
								printf("%s\n",send_GSM(at_,"OK\r\n","ERROR\r\n","ERROR:",tmeout));
								printf("%s\n",send_GSM("\n\n AT+CMGD=1,4\r\n","OK\r\n","ERROR\r\n","ERROR:",tmeout));			
															
															
									
							}		
						else if(strstr(uart_string_gsm, "DEBUG"))
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
									
									printf("%s\n",send_GSM(at_,"OK\r\n","ERROR\r\n","ERROR:",tmeout));		
										memset(data2,0,strlen(data2));
										sprintf(data2,"%s",uart_string_gsm);	
										send_message(data2);
									printf("%s\n",send_GSM("\n\n AT+CMGD=1,4\r\n","OK\r\n","ERROR\r\n","ERROR:",tmeout));		
									
								
							}
							
							else if(strstr(uart_string_gsm, "RESET"))
							{
								printf("%s\n",send_GSM("\n\n AT+CMGD=1,4\r\n","OK\r\n","ERROR\r\n","ERROR:",tmeout));			
								printf("%s\n",send_GSM("\n\n AT+CFUN=1,1\r\n","OK\r\n","ERROR\r\n","ERROR:",tmeout));			
							}
							
							else if(strstr(uart_string_gsm, "IP"))
							{
								printf("\n\n\n\t%s",uart_string_gsm);
								memset(ip,0,16);
								parse_g(uart_string_gsm, 3, 4, ' ', ' ', ip);
								parse_g(uart_string_gsm, 6, 5, ' ', '\r', port);	
								printf("\n%s\n",port);
								save_ip_port();
							
	//							printf("\n\n\n\t%s\t||\t%s",ip,port);
								printf("%s\n",send_GSM("\n\n AT+CMGD=1,4\r\n","OK\r\n","ERROR\r\n","ERROR:",tmeout));	

//								while(1);
								
								}		

							else
							{
								
								printf("%s\n",send_GSM("\n\n AT+CMGD=1,4\r\n","OK\r\n","ERROR\r\n","ERROR:",tmeout));			

							}							
							
					
					}
		ringflag=0;	
		}
		
}


void send_chunk()
{float fsz;
 int times,qwe,timeout,k5;
								
	printf("\n%s\n",send_GSM("\nAT+FSFLSIZE=C:\\LOG.TXT\r\n", "OK", "ERROR\r\n" , "ERROR:",19999));
	parse_g(uart_string_gsm, 1, 2, ' ', '\n', fsize);
	fsz=stof(fsize);//7523.7412
	times=(fsz/1400)+1;
	for(k5=0;k5<times;)
	{
		memset(sd_data,0,1400);
		memset(at_,0,100);
		sprintf(at_, "\nAT+FSREAD=C:\\LOG.TXT,1,1400,%d\r\n",(k5*1400) );		
		printf("\n%d,%s\n",k5,send_GSM(at_, "OK\r\n", "ERROR\r\n" , "ERROR:",19999));	
		parse_g(uart_string_gsm, 2,9, '\n', '\n' ,sd_data);
		printf ("\n\n\n\t\t\t****************************\n%s\n\n\n\t\t\t*****************************",sd_data);
		clear();

			printf("\n%s\n",send_GSM("\r\nAT+CIPSEND\r\n", ">", "ERROR\r\n" , "CONNECT",tmeout));		
									if(strstr(uart_string_gsm,">"))	
									{
										
																clear();
																qwe=strlen(uart_string_gsm);
																printf("\nsizeofbuffer-> %d\n",qwe);
																memset(uart_string_gsm,0,qwe);

										for(k=0;k<strlen(sd_data);k++)
										{
											uart_putchar(UART1_BASE_PTR, sd_data[k]); uart0_putchar(UART0_BASE_PTR, sd_data[k]);//clear();
										}		
						
												uart_putchar(UART1_BASE_PTR, '\n');uart_putchar(UART1_BASE_PTR, 0x1A);
													k2=0;									//string array counter for uart 1
													timeout=2001;						//timer counts to wait for characters in uart 1 									
													//send_modem("\r\n");//uart_putchar(UART1_BASE_PTR, 0x1A);send_modem("\r\n");uart_putchar(UART1_BASE_PTR, 0x1A);send_modem("\r\n");

														while(!(strstr(uart_string_gsm,"SEND OK\r\n")  ||  (timeout < 1))   || (strstr(uart_string_gsm, "ERROR"))     )
																{
																	timeout--;
																if(lptmr_interrupt == 1){ accel_read(); detect_motion(); lptmr_interrupt = 0;}		
																	
																	if(timeout % 400 == 0)
																	{uart0_putchar(UART0_BASE_PTR,'1');uart_putchar(UART1_BASE_PTR,0x1A);
																	}

																}
															qwe=strlen(uart_string_gsm);
															printf("\nsizeofbuffer-> %d\n",qwe);


										
													//printf("***********************************************\n\n\n%s\n***********************************************\n",uart_string_gsm);									

										uart_putchar(UART1_BASE_PTR, 0x1A);clear();
										k5++;
								//		memset(data,0,1000);
										if(k5 >= times-1)printf("\n%s\n",send_GSM("\nAT+FSCREATE=C:\\LOG.TXT\r\n", "OK", "ERROR\r\n" , "ERROR:",2001));

									}
							else{
										log_it();
										memset(data,0,strlen(data));
										printf("reinitialization...\n");	
										tcp_initialization();
										log_it();
										printf("\n%s\n",send_GSM("\nAT+FSFLSIZE=C:\\LOG.TXT\r\n", "OK", "ERROR\r\n" , "ERROR:",2001));
										parse_g(uart_string_gsm, 1, 2, ' ', '\n', fsize);
										fsz=stof(fsize);//7523.7412
										times=fsz/1400;
									}	
		
		
		}
		

	//	sprintf(at_, "\r\nAT+CIPSTART=\"TCP\",\"%s\",\"%s\"\r\n", ip, port);
	//	printf("\n%s\n",send_GSM( at_ , "CONNECT", "ERROR\r\n" , "CONNECT",tmeout));	
	//	printf("\n%s\n",send_GSM("\r\nAT+CIPSEND\r\n", ">", "ERROR\r\n" , "CONNECT",tmeout));	

	//		
		
		
	}
			
	
	void bat_cind()
	{int netwrk;char netwrk_c[1];
		
				printf("\n%s\n",send_GSM("\r\nAT+CIND?\r\n", "OK", "ERROR\r\n" , "ERROR:",999999));
				parse_g(uart_string_gsm, 1, 2, ',', ',', netwrk_c);
				netwrk = netwrk_c[0]- '0';
				printf("\n\t%d\n\t%d\n\t%d\n\t%d\n",netwrk,netwrk,netwrk,netwrk);

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
	
			
	void send_message(char * data2)
	{
									memset(at_,0,100);
									sprintf(at_, "\nAT+CMGS=\"%s\"\r\n" ,num2);
									printf("\n%s\n",send_GSM(at_, ">", "ERROR\r\n" , "ERROR:",tmeout));	
									if( strstr(uart_string_gsm, ">"))
									{
										//
										
											for(k=0;k<strlen(data2);k++)
											{
												
												uart_putchar(UART1_BASE_PTR, data2[k]);
												uart0_putchar(UART0_BASE_PTR, data2[k]);
												clear();
												
											}		
											uart_putchar(UART1_BASE_PTR, 0x1A);
											k2=0;									//string array counter for uart 1
											timeout=19999;						//timer counts to wait for characters in uart 1 									
											while(!(strstr(uart_string_gsm,"+CMGS:")  ||  (timeout < 1)))
																{
																	timeout--;
																	if(timeout % 4000 == 0)
																	{
																		uart0_putchar(UART0_BASE_PTR,'1');
																		uart_putchar(UART1_BASE_PTR,0x1A);
																	}
																}
							
									}
		
									
	}

//		void msg_sim808() 
//		{

//	printf("\n%s\n",send_GSM("\r\nAT+CMGR=1\r\n", "OK\r\n", "ERROR\r\n" , "ERROR:",tmeout));		
////	if(strstr(uart_string_gsm,"+CMGR:"))
////  {send_modem("\nAT+CMGD=1,4\r\r\n");}					
//			
//										memset(num,0,15);
//										for(i=0,temp=0;i<100;i++)
//										{
//										if(string_a[i]=='"')
//											{temp++;j=i;}
//										else{}
//											
//										if(temp>=4){i=900;} 
//										else{}	
//										
//										}	
//										
//										for(i=0,temp=0;i<100;i++)
//										{
//										if(string_a[i]=='"')
//											{temp++;l=i;}										
//										else{}
//										if(temp>=3){i=900;}else{}
//										}	
//										for(i=0;i<(j-l-1);i++)
//										{
//										num[i] = string_a[l+i+1];
//										}					

//if(strstr(string_a,"OWNER"))
//{user=1;}
//else if(strstr(string_a,"MASTER"))
//{user=2;}
//else{user=0;}
//										
//clear();		
//delay(100);
//memset(string_c,0,300);
////if(strstr(string_a,"+CMGR:"))
////		{phonebook_read("1");
////		parse(0,1);
////		if(strstr(num,num2))
////		{user=1;}
////}										
//										
//										
//						if(strstr(string_a, "INTERVAL") && (user == 1))											//string_a was command before
//						{memset(cmd,0,20);
//									for(k=0;k<450;k++)
//									{if(string_a[k-1] == ' ' && string_a[k-2] == 'L' && string_a[k-3] == 'A' && string_a[k-4] =='V' && string_a[k-5] == 'R'&& string_a[k-6] == 'E' && string_a[k-7] == 'T' && string_a[k-8] == 'N')
//									{	for(i=0;i<100;i++)
//										{
//											
//											
//											if (  (string_a[k] != '\r') && (string_a[k] != '\n') && (string_a[k] != 'O') && (string_a[k] != 'K') && (string_a[k] != 'E') && (string_a[k] != 'R')  )
//											{cmd[i]=string_a[k];}
//										
//										
//										
//										k++;
//										}			
//									}
//									else{}
//									}	




//					  interval = myAtoi(cmd);	
//						phonebook_write("5", cmd , "INTERVAL");
//						delay(100);	
//							
//		
//						
//						}
//						
//						
//						else if(strstr(string_a, "IP:") && (user == 1))											//string_a was command before
//						{memset(cmd,0,20);
//									for(k=0;k<450;k++)
//							{if( string_a[k-1] == ':' && string_a[k-2] == 'P' && string_a[k-3] =='I')
//									{	for(i=0;i<100;i++)
//										{
//											
//											
//											if((string_a[k] != ','))
//											{cmd[i]=string_a[k];}
//						
//										k++;
//										}			
//									}
//									else{}
//									}	

//memset(ip,0,20);
//strcpy(ip,cmd);									
//						
//						phonebook_write("5", cmd , "INTERVAL");
//						delay(100);	
//						memset(cmd,0,20);
//									for(k=0;k<450;k++)
//							{if( string_a[k-1] == ':' && string_a[k-2] == 'T' && string_a[k-3] =='R'  && string_a[k-4] =='O'  && string_a[k-5] =='P')
//									{	for(i=0;i<100;i++)
//										{
//											
//											
//											if ((string_a[k] != '\r') && (string_a[k] != '\n') && (string_a[k] != 'O') && (string_a[k] != 'K') && (string_a[k] != 'E') && (string_a[k] != 'R')  )
//											{cmd[i]=string_a[k];}
//										
//										
//										
//										k++;
//										}			
//									}
//									else{}
//									}		
//									
//memset(port,0,5);
//strcpy(port,cmd);										
//									
//		
//						
//						}				


//						else if(strstr(string_a, "REGISTER OW1 ") && (user == 1))											//string_a was command before
//						{memset(cmd,0,20);
//									for(k=0;k<450;k++)
//									{if(string_a[k-1] == ' ' && string_a[k-2] == '1' && string_a[k-3] == 'W' && string_a[k-4] =='O' && string_a[k-5] == ' '&& string_a[k-6] == 'R' && string_a[k-7] == 'E' && string_a[k-8] == 'T')
//									{	for(i=0;i<100;i++)
//										{
//											
//											
//											if (  (string_a[k] != '\r') && (string_a[k] != '\n') && (string_a[k] != 'O') && (string_a[k] != 'K') && (string_a[k] != 'E') && (string_a[k] != 'R')  )
//											{cmd[i]=string_a[k];}
//										
//										
//										
//										k++;
//										}			
//									}
//									else{}
//									}	




//					 // interval = myAtoi(cmd);	
//						phonebook_write("2", cmd , "OWNER1");
//						delay(100);	
//							
//							
//						
//						}		
//						
//						
//						
//						else if(strstr(string_a, "REGISTER OW2 ") && (user == 1))											//string_a was command before
//						{memset(cmd,0,20);
//									for(k=0;k<450;k++)
//									{if(string_a[k-1] == ' ' && string_a[k-2] == '2' && string_a[k-3] == 'W' && string_a[k-4] =='O' && string_a[k-5] == ' '&& string_a[k-6] == 'R' && string_a[k-7] == 'E' && string_a[k-8] == 'T')
//									{	for(i=0;i<100;i++)
//										{
//											
//											
//											if (  (string_a[k] != '\r') && (string_a[k] != '\n') && (string_a[k] != 'O') && (string_a[k] != 'K') && (string_a[k] != 'E') && (string_a[k] != 'R')  )
//											{cmd[i]=string_a[k];}
//										
//										
//										
//										k++;
//										}			
//									}
//									else{}
//									}	




//					 
// 						interval = myAtoi(cmd);	
//						phonebook_write("3", cmd , "OWNER2");
//						delay(100);	
//							
//							
//						
//						}		

//						
//						
//						else if(strstr(string_a, "REGISTER OW3 ") && (user == 1))											//string_a was command before
//						{memset(cmd,0,20);
//									for(k=0;k<450;k++)
//									{if(string_a[k-1] == ' ' && string_a[k-2] == '3' && string_a[k-3] == 'W' && string_a[k-4] =='O' && string_a[k-5] == ' '&& string_a[k-6] == 'R' && string_a[k-7] == 'E' && string_a[k-8] == 'T')
//									{	for(i=0;i<100;i++)
//										{
//											
//											
//											if (  (string_a[k] != '\r') && (string_a[k] != '\n') && (string_a[k] != 'O') && (string_a[k] != 'K') && (string_a[k] != 'E') && (string_a[k] != 'R')  )
//											{cmd[i]=string_a[k];}
//										
//										
//										
//										k++;
//										}			
//									}
//									else{}
//									}	
//
//						interval = myAtoi(cmd);	
//						phonebook_write("4", cmd , "OWNER3");
//						delay(100);	
//							
//							
//						
//						}		

//						
//										
//						else if(strstr(string_a, "LOCATION") && (user == 1))										//string_a was command before
//						{
//							memset(string_c,0,300);k=0;l=time;
//											printf("\nAT+CMGS=\"%s\"\r\n",num);
//												do{
//													if( uart0_getchar_present (UART0_BASE_PTR))	
//													{string_c[k]=UART0_D_REG(UART0_BASE_PTR);k++;l=time; if(k>298){k=0;}    }
//													else{l--;if(l==1){AT();delay(50); }}
//													}while(!((strstr(string_c, ">"))  || (l<=0)  ||  (strstr(string_c, "ERROR\r\n")) 
//				        	||(strstr(string_c, "ERROR:"))
//																	));
//													delay(100);
//													
//										if(strstr(string_c, ">"))
//										{	
//													memset(string_c,0,300);k=0;l=time;
//													printf("%s%c",latlon,0x1A);
//												do{
//													if( uart0_getchar_present (UART0_BASE_PTR))	
//													{string_c[k]=UART0_D_REG(UART0_BASE_PTR);k++;l=time;   if(k>298){k=0;} }
//													else{l--;if(l==1){AT();delay(50); }}
//													}while(!((strstr(string_c, "+CMGS:")) || (l<=0) || (strstr(string_c, "ERROR\r\n")) 
//				        																								|| (strstr(string_c, "ERROR:"))
//																	));
//												}	
//											else{}
//						
//						}

//									else if(strstr(string_a, "DEBUG") && (user == 1 || user == 2))
//									{
//									delay(100);
//									memset(cmd,0,100);
//									for(k=0;k<450;k++)
//																										{if(string_a[k-1] == ' ' && string_a[k-2] == 'G' && string_a[k-3] == 'U' && string_a[k-4] =='B' && string_a[k-5] == 'E'&& string_a[k-6] == 'D')
//																											{	for(i=0;i<100;i++)
//																											{cmd[i]=string_a[k];
//																											k++;}			
//																											}
//																											else{}
//																										}
//														memset(string_a, 0,400);
//														k=0;l=time;																	
//														printf("\n%s\r\n",cmd);

//															k=0;l=time;
//															do{
//															if(uart0_getchar_present (UART0_BASE_PTR))	
//																	{string_a[k]=UART0_D_REG(UART0_BASE_PTR);k++;l=time;if(k>298){k=0;} }
//															else{l--;}		
//																
//																}while(uart0_getchar_present (UART0_BASE_PTR) || !(l<=0));
//																							
//															
//														delay(100);	
//																
//															memset(string_c,0,300);k=0;l=time;
//															printf("\nAT+CMGS=\"%s\"\r\n",num);
//																do{
//																	if( uart0_getchar_present (UART0_BASE_PTR))	
//																	{string_c[k]=UART0_D_REG(UART0_BASE_PTR);k++;l=time;if(k>298){k=0;} }
//																	else{l--;if(l==1){AT();delay(50); }}
//																	}while(!((strstr(string_c, ">"))  || (l<=0)  ||  (strstr(string_c, "ERROR\r\n")) 
//				        	||(strstr(string_c, "ERROR:"))
//																					));
//																	delay(100);
//														if(strstr(string_c, ">"))
//														{				
//																	memset(string_c,0,300);k=0;l=time;
//																	printf("%s%c",string_a,0x1A);
//																do{
//																	if( uart0_getchar_present (UART0_BASE_PTR))	
//																	{string_c[k]=UART0_D_REG(UART0_BASE_PTR);k++;l=time;if(k>298){k=0;} }
//																	else{l--;if(l==1){AT();delay(50); }}
//																	}while(!((strstr(string_c, "+CMGS:")) || (l<=0)
//																					||(strstr(string_c, "ERROR\r\n"))
//				        	||(strstr(string_c, "ERROR:"))
//																					));
//																}
//														else{}
//								}
//	else if(strstr(string_a, "GSM LOC") && user ==1)
//	{

//		
//		get_gsm_loc();
//		
//												
//										memset(string_c,0,300);k=0;l=time;
//										printf("\nAT+CMGS=\"%s\"\r\n",num);
//											do{
//												if( uart0_getchar_present (UART0_BASE_PTR))	
//												{string_c[k]=UART0_D_REG(UART0_BASE_PTR);k++;l=time;if(k>298){k=0;} }
//												else{l--;if(l==1){AT();delay(50); }}
//												}while(!((strstr(string_c, ">"))  || (l<=0)  ||  (strstr(string_c, "ERROR\r\n")) 
//				        	||(strstr(string_c, "ERROR:"))
//																));
//												delay(100);
//												
//									if(strstr(string_c, ">"))
//									{	
//												//memset(string_c,0,300);
//												k=0;l=time;
//												printf("%s%c",message,0x1A);
//											do{
//												if( uart0_getchar_present (UART0_BASE_PTR))	
//												{string_c[k]=UART0_D_REG(UART0_BASE_PTR);k++;l=time;if(k>298){k=0;} }
//												else{l--;if(l==1){AT();delay(50); }}
//												}while(!((strstr(string_c, "+CMGS:")) || (l<=0)  ||  (strstr(string_c, "ERROR\r\n")) 
//				        	||(strstr(string_c, "ERROR:"))
//																));
//											}			
//	
//	}
//	else if(strstr(string_a, "CELLSTAT"))
//	{}
//	else if(strstr(string_a, "SEND"))
//	{}
//	else if(strstr(string_a, "GPRS"))
//	{}
//	else {}	
//		

//					
//					
//					
//					
//					
//}














