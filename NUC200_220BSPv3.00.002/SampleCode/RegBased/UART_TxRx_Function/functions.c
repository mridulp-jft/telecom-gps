#include <stdio.h>
#include "NUC200Series.h"
#include "string.h"

#define SLEEP PB2

#define UART0RXBUFSIZE  1240
#define PLLCON_SETTING  CLK_PLLCON_25MHz_HXT
#define PLL_CLOCK       25000000
/*---------------------------------------------------------------------------------------------------------*/
/* Global variables                                                                                        */
/*---------------------------------------------------------------------------------------------------------*/
char UART0Data[UART0RXBUFSIZE];
char IMEI[16];
char buffer[200];
char GPSdata[1500];
int intervaltimercount = 0;
int32_t  i32ConversionData;
int g_au32TMRINTCount;


char debug[1500];

extern volatile uint32_t g_u32AdcIntFlag;
extern int datainterval;
extern int sent;
extern int dataintervalflag;
int datacount;
int  seconds = 0;

uint32_t sysTicks=0;
int32_t inc=0;
int tmrcount = 0 ;
int tcpdatasize=0;
int responseok=0;
__INLINE void delayms(int32_t sec);
__INLINE void wakeup();
__INLINE void remove_all_chars(char* str, char c, char d);
__INLINE void delay(int32_t sec);
int gpscollecttimer=0;



__INLINE void SYS_Init(void)
{
    /*-----------------------------------------------------------
	----------------------------------------------*/
    /* Init System Clock                                                                                       */
    /*---------------------------------------------------------------------------------------------------------*/

    /* Enable Internal RC 22.1184MHz clock */
    CLK->PWRCON |= CLK_PWRCON_OSC22M_EN_Msk;

    /* Waiting for Internal RC clock ready */
    while(!(CLK->CLKSTATUS & CLK_CLKSTATUS_OSC22M_STB_Msk));

    /* Switch HCLK clock source to Internal RC and HCLK source divide 1 */
    CLK->CLKSEL0 &= ~CLK_CLKSEL0_HCLK_S_Msk;
    CLK->CLKSEL0 |= CLK_CLKSEL0_HCLK_S_HIRC;
    CLK->CLKDIV &= ~CLK_CLKDIV_HCLK_N_Msk;
    CLK->CLKDIV |= CLK_CLKDIV_HCLK(3);

    /* Enable external XTAL 12MHz clock */
    CLK->PWRCON |= CLK_PWRCON_XTL12M_EN_Msk;

    /* Waiting for external XTAL clock ready */
    while(!(CLK->CLKSTATUS & CLK_CLKSTATUS_XTL12M_STB_Msk));

    /* Set core clock as PLL_CLOCK from PLL */
    CLK->PLLCON = PLLCON_SETTING;
    while(!(CLK->CLKSTATUS & CLK_CLKSTATUS_PLL_STB_Msk));
    CLK->CLKSEL0 &= (~CLK_CLKSEL0_HCLK_S_Msk);
    CLK->CLKSEL0 |= CLK_CLKSEL0_HCLK_S_PLL;

    /* Update System Core Clock */
    /* User can use SystemCoreClockUpdate() to calculate PllClock, SystemCoreClock and CycylesPerUs automatically. */
    //SystemCoreClockUpdate();
    PllClock        = PLL_CLOCK;            // PLL
    SystemCoreClock = PLL_CLOCK / 1;        // HCLK
    CyclesPerUs     = PLL_CLOCK /1000;  // For SYS_SysTickDelay() set for  ms

    /* Enable UART module clock */
    CLK->APBCLK |= CLK_APBCLK_UART0_EN_Msk| CLK_APBCLK_TMR0_EN_Msk ;
		CLK->APBCLK |= CLK_APBCLK_ADC_EN_Msk ;

//		CLK->APBCLK |= CLK_APBCLK_UART1_EN_Msk | CLK_APBCLK_TMR0_EN_Msk ;

    /* Select UART module clock source */
    CLK->CLKSEL1 &= ~CLK_CLKSEL1_UART_S_Msk;
    CLK->CLKSEL1 |= CLK_CLKSEL1_UART_S_HXT | CLK_CLKSEL1_TMR0_S_HXT;

    /* Select ADC module clock source */
    CLK->CLKSEL1 &= CLK_CLKSEL1_ADC_S_Msk ;
    CLK->CLKSEL1 |= CLK_CLKSEL1_ADC_S_HIRC ;

    /* ADC clock source is 22.1184MHz, set divider to 7, ADC clock is 22.1184/7 MHz */
    CLK->CLKDIV  = (CLK->CLKDIV & ~CLK_CLKDIV_ADC_N_Msk) | (((7) - 1) << CLK_CLKDIV_ADC_N_Pos);
    /*---------------------------------------------------------------------------------------------------------*/
    /* Init I/O Multi-function                                                                                 */
    /*---------------------------------------------------------------------------------------------------------*/

    /* Set GPB multi-function pins for UART0 RXD and TXD */
    SYS->GPB_MFP &= ~(SYS_GPB_MFP_PB0_Msk | SYS_GPB_MFP_PB1_Msk);
    SYS->GPB_MFP |= SYS_GPB_MFP_PB0_UART0_RXD | SYS_GPB_MFP_PB1_UART0_TXD;
//    SYS->GPB_MFP &= ~(SYS_GPB_MFP_PB4_Msk | SYS_GPB_MFP_PB5_Msk);
//    SYS->GPB_MFP |= SYS_GPB_MFP_PB4_UART1_RXD | SYS_GPB_MFP_PB5_UART1_TXD;

    PA->OFFD = 0xF << GPIO_OFFD_OFFD_Pos;

    /* Configure the GPA0 - GPA3 ADC analog input pins */
    SYS->GPA_MFP &= ~(SYS_GPA_MFP_PA0_Msk | SYS_GPA_MFP_PA1_Msk | SYS_GPA_MFP_PA2_Msk | SYS_GPA_MFP_PA3_Msk) ;
    SYS->GPA_MFP |= SYS_GPA_MFP_PA0_ADC0 | SYS_GPA_MFP_PA1_ADC1 | SYS_GPA_MFP_PA2_ADC2 | SYS_GPA_MFP_PA3_ADC3 ;
    SYS->ALT_MFP1 = 0;
      


}

__INLINE void UART0_Init()
{
    /*---------------------------------------------------------------------------------------------------------*/
    /* Init UART                                                                                               */
    /*---------------------------------------------------------------------------------------------------------*/
    /* Reset UART0 */
    SYS->IPRSTC2 |=  SYS_IPRSTC2_UART0_RST_Msk;
    SYS->IPRSTC2 &= ~SYS_IPRSTC2_UART0_RST_Msk;

    /* Configure UART0 and set UART0 Baudrate */
    UART0->BAUD = UART_BAUD_MODE2 | UART_BAUD_MODE2_DIVIDER(__HXT, 115200);
    UART0->LCR = UART_WORD_LEN_8 | UART_PARITY_NONE | UART_STOP_BIT_1;

		UART0->IER |= UART_IER_RDA_IEN_Msk;// | UART_IER_THRE_IEN_Msk | UART_IER_TOUT_IEN_Msk ;
    NVIC_EnableIRQ(UART02_IRQn);
}

__INLINE void UART1_Init()
{
    /*---------------------------------------------------------------------------------------------------------*/
    /* Init UART                                                                                               */
    /*---------------------------------------------------------------------------------------------------------*/
    /* Reset UART0 */
    SYS->IPRSTC2 |=  SYS_IPRSTC2_UART1_RST_Msk;
    SYS->IPRSTC2 &= ~SYS_IPRSTC2_UART1_RST_Msk;

    /* Configure UART0 and set UART0 Baudrate */
    UART1->BAUD = UART_BAUD_MODE2 | UART_BAUD_MODE2_DIVIDER(__HXT, 115200);
    UART1->LCR = UART_WORD_LEN_8 | UART_PARITY_NONE | UART_STOP_BIT_1;
	
	
	  UART1->IER |= UART_IER_RDA_IEN_Msk;// | UART_IER_THRE_IEN_Msk | UART_IER_TOUT_IEN_Msk ;
    NVIC_EnableIRQ(UART1_IRQn);
}





__inline void parse_g(char* str, int first, int sec, char f, char s , char *string)
{int sz1,sz2,i11,temp11,j11,l;
	if(responseok == 1)
	{
		sz1=	strlen(str);
		sz2=  strlen(string);
		memset(string,0,sz2);
		for(i11=0,temp11=0;i11<sz1;i11++)
		{
		if(str[i11]==s)
			{temp11++;j11=i11;}
		else{}
			
		if(temp11>=sec){i11=9900;}
		else{}	
		
		}	
		
		for(i11=0,temp11=0;i11<sz1;i11++)
		{
		if(str[i11]==f)
			{temp11++;l=i11;}										
		else{}
		if(temp11>=first){i11=9900;}else{}
		}	
		for(i11=0;i11<(j11-l-1);i11++)
		{
		string[i11] = str[l+i11+1];
		}
	}		
}


__INLINE void sendAT(char* AT, char* resp1, char* resp2, char*resp3, uint32_t waittime_sec);


/*---------------------------------------------------------------------------------------------------------*/
/* ISR to handle UART Channel 1 interrupt event                                                            */
/*---------------------------------------------------------------------------------------------------------*/
void UART02_IRQHandler(void)
{
	UART0->FSR |= UART_FSR_TX_OVER_IF_Msk;
	if((UART0->FSR & UART_FSR_RX_EMPTY_Msk) == 0)   
			{			/* Get the character from UART Buffer */
				UART0Data[inc]= UART0->RBR;
				inc++;
			}
	UART0->FSR |= UART_FSR_TX_OVER_IF_Msk;

}


void SysTick_Handler(void)
{
	sysTicks++;
}


__INLINE void getimei()
{
	int imeipointer=0;
	int imeiinc=0;
	memset(IMEI,0,16);
	sendAT("\r\nAT+GSN\r\n","OK","ERROR","DEACT",4);
	for(imeipointer=0;imeipointer<strlen(UART0Data);imeipointer++)
	{
		if((UART0Data[imeipointer]>47)   &&   (UART0Data[imeipointer]<58))
			{   //means numeric
				IMEI[imeiinc] = UART0Data[imeipointer];
				imeiinc++;
		  }
	}
}


void ADC_IRQHandler(void)
{
    g_u32AdcIntFlag = 1;
    ADC->ADSR = ADC_ADSR_ADF_Msk;      /* clear the A/D conversion flag */
}

	
void TMR0_IRQHandler(void)
{
    if(TIMER_GetIntFlag(TIMER0) == 1)
    {
        /* Clear Timer0 time-out interrupt flag */
        TIMER_ClearIntFlag(TIMER0);
//				g_au32TMRINTCount++;
				gpscollecttimer+=1;
        tmrcount+=1;
				seconds+=1;
				intervaltimercount++;
					if(intervaltimercount == datainterval){
						dataintervalflag=1;
						intervaltimercount = 0;
					}
					else{						dataintervalflag=0;
					}

//				if(g_au32TMRINTCount % 2 == 0){PA3=1;PA4=1;PA5=1;PA6=1;}
//				else{PA3=0;PA4=0;PA5=0;PA6=0;} 
	
    }
}


__INLINE void GETGPSDATA()
{
	int imeipointer=0;	int imeiinc=0;
//	while(gpscollecttimer < 5){}
//		strcat(debug, UART0Data);
	
//		memset(GPSdata,0,1000);
//  	memset(buffer,0,200);
		sendAT("\r\nAT\r\n","OK","ERROR","DEACT",5);
		if(strlen(IMEI)<15)
		{
		memset(IMEI,0,16);
		sendAT("\r\nAT+GSN\r\n","OK","ERROR","DEACT",5);
		for(imeipointer=0;imeipointer<strlen(UART0Data);imeipointer++)
		{
			if((UART0Data[imeipointer]>47)   &&   (UART0Data[imeipointer]<58))
				{   //means numeric
					IMEI[imeiinc] = UART0Data[imeipointer];
					imeiinc++;
				}
		}	
		}
//		sendAT("\r\nAT+GETGPS=\"GNGGA\",1\r\n", "Ready", "OK" , "ERROR",5);
//		
//		memset(buffer,0,200);
//		parse_g(UART0Data,2,3,'\n','\r',buffer);
//		remove_all_chars(buffer, '\r', '\n');
	//	strcat(GPSdata,"\n");
		strcat(GPSdata,IMEI);
		strcat(GPSdata,",");
//		strcat(GPSdata,buffer);
//		strcat(GPSdata,",");
		sendAT("\r\nAT+GETGPS=\"GNRMC\",1\r\n", "OK", "OK" , "ERROR",10);
		memset(buffer,0,200);
		parse_g(UART0Data,2,3,'\n','\r',buffer);
		remove_all_chars(buffer, '\r', '\n');
		strcat(GPSdata,buffer);
		strcat(GPSdata,"\n");

//		sendAT("\r\nAT+GETGPS=\"ALL\",1\r\n", "Ready", "OK" , "ERROR",2);

gpscollecttimer = 0;		
}


__INLINE void ADCread()
{
//		ADC->ADCR = (ADC_ADCR_ADMD_SINGLE | ADC_ADCR_DIFFEN_SINGLE_END | ADC_ADCR_ADEN_CONVERTER_ENABLE);
//		ADC->ADCHER |= ((ADC->ADCHER & ~ADC_ADCHER_CHEN_Msk) | 1);
//		ADC->ADSR = ADC_ADSR_ADF_Msk;
//		ADC->ADCR |= ADC_ADCR_ADIE_Msk;
//		NVIC_EnableIRQ(ADC_IRQn);

//		/* Reset the ADC interrupt indicator and Start A/D conversion */
//		g_u32AdcIntFlag = 0;
//		ADC->ADCR |= ADC_ADCR_ADST_Msk;

//		/* Wait ADC interrupt (g_u32AdcIntFlag will be set at IRQ_Handler function)*/
//		while(g_u32AdcIntFlag == 0);

//		/* Disable the ADC interrupt */
//		ADC->ADCR &= ~ADC_ADCR_ADIE_Msk;

//		/* Get the conversion result of the ADC channel 2 */
//		i32ConversionData = (ADC->ADDR[(0)] & ADC_ADDR_RSLT_Msk) >> ADC_ADDR_RSLT_Pos;
	
	
	
	
	
	
	
	          ADC->ADCR = (ADC_ADCR_ADMD_SINGLE | ADC_ADCR_DIFFEN_SINGLE_END | ADC_ADCR_ADEN_CONVERTER_ENABLE);
            /* Enable analog input channel 2 */
            ADC->ADCHER |= ((ADC->ADCHER & ~ADC_ADCHER_CHEN_Msk) | (1 << 0));

            /* Clear the A/D interrupt flag for safe */
            ADC->ADSR = ADC_ADSR_ADF_Msk;

            /* Enable the ADC interrupt */
            ADC->ADCR |= ADC_ADCR_ADIE_Msk;
            NVIC_EnableIRQ(ADC_IRQn);

            /* Reset the ADC interrupt indicator and Start A/D conversion */
            g_u32AdcIntFlag = 0;
            ADC->ADCR |= ADC_ADCR_ADST_Msk;

            /* Wait ADC interrupt (g_u32AdcIntFlag will be set at IRQ_Handler function)*/
            while(g_u32AdcIntFlag == 0);

            /* Disable the ADC interrupt */
            ADC->ADCR &= ~ADC_ADCR_ADIE_Msk;

            /* Get the conversion result of the ADC channel 2 */
            i32ConversionData = (ADC->ADDR[(0)] & ADC_ADDR_RSLT_Msk) >> ADC_ADDR_RSLT_Pos;
	

}


__INLINE void TCPsend()
{
	int tcpdatapointer=0;
	char* r1=0;
	char* r2;
	char* r3;
	int try1;
	for(try1 = 0; try1 < 3; try1++)
		{GETGPSDATA();

			sendAT("\r\nAT+CREG?\r\n", "OK", "DEACT" , "ERROR",5);
			if(( 1 )) //strstr(UART0Data,"CREG: 0,1")     || strstr(UART0Data,"CREG: 0,5")
			{

				sendAT("\r\nAT+CIPSTART=\"TCP\",\"rudra.jellyfishtele.com\",\"5555\"\r\n", "CONNECT", "DEACT" , "ERROR",15);
				sendAT("\r\nAT+CIPSEND\r\n", ">", "OK" , "ERROR",15);
				r1=strstr(UART0Data,">");
				if(r1)
				{
						memset(UART0Data,0,UART0RXBUFSIZE);
						tcpdatasize = strlen(GPSdata);
						if(tcpdatasize < 100){
//						while(1);
						}
						strcat(GPSdata,"\n\n");
						for(tcpdatapointer=0;tcpdatapointer<=tcpdatasize;)
							{
							 //UART1->FSR |= UART_FSR_TX_OVER_IF_Msk;
							 if(!(UART0->FSR & UART_FSR_TX_FULL_Msk))
								{ 
									UART0->DATA = GPSdata[tcpdatapointer];
									tcpdatapointer++;
									//delayms(1);
								}
							}
							 //UART1->FSR |= UART_FSR_TX_OVER_IF_Msk;
							for(tcpdatapointer=0; tcpdatapointer<3;)
								if(!(UART0->FSR & UART_FSR_TX_FULL_Msk))
								{ 
									UART0->DATA = 0X1A;
									tcpdatapointer++;
								}			
						inc=0;//				memset(UART1Data,0,UART1RXBUFSIZE);
						tmrcount=0;
						do{
								r1=strstr(UART0Data,"SEND OK");
								r2=strstr(UART0Data,"SEND FAIL");
								r3=strstr(UART0Data,"ERROR");
							}while(! ( r1 || r2 || r3 || ((tmrcount > 5))));
				
				}
			}else{
							sendAT("\r\nAT+CIPSHUT\r\n", "OK", "DEACT" , "ERROR",15);
							sendAT("\r\nAT+CFUN=0\r\n", "CLOSED", "OK" , "ERROR",15);
							sendAT("\r\nAT+CFUN=1\r\n", "EUSIM", "OK" , "ERROR",15);
							GETGPSDATA();

							delay(7);
	//						sendAT("\r\nAT+COPS=?\r\n", "CLOSED", "OK" , "ERROR",5);

							sendAT("\r\nAT+CSTT=\"isafe\"\r\n", "Ready", "OK" , "ERROR",15);	
							GETGPSDATA();

							sendAT("\r\nAT+CGATT?\r\n", "Ready", "OK" , "ERROR",15);	
							GETGPSDATA();

							sendAT("\r\nAT+CGATT=1\r\n", "Ready", "OK" , "ERROR",15);	
							sendAT("\r\nAT+CIICR\r\n", "Ready", "OK" , "ERROR",15);	
							sendAT("\r\nAT+CIFSR\r\n", "Ready", "OK" , "ERROR",15);	
								
							sendAT("\r\nAT+CIPMUX=0\r\n", "Ready", "OK" , "ERROR",15);	
							sendAT("\r\nAT+CSQ\r\n", "Ready", "OK" , "ERROR",15);	
							sendAT("\r\nAT+CIPSTART=\"TCP\",\"rudra.jellyfishtele.com\",\"5556\"\r\n", "CONNECT", "DEACT" , "ERROR",15);

						}
			
			
			
				if(r1){
					sent=1;
					break;
				}
				else{
					if(try1>1){
					sent=0;break;}
				}

		}		
memset(GPSdata,0,1500);
}

	
	
__INLINE void delay(int32_t sec){
	int ms1,ms2;
	
	for(ms1=0;ms1<(sec*2000);ms1++)
	{
		for(ms2=0;ms2<1000;ms2++);
	}
	
}
	
__INLINE void delayms(int32_t sec){
	int ms1,ms2;
	
	for(ms1=0;ms1<(sec*2);ms1++)
	{
		for(ms2=0;ms2<999;ms2++);
	}
	
}	


__INLINE void remove_all_chars(char* str, char c, char d) {
    char *pr = str, *pw = str;
    while (*pr) {
        *pw = *pr++;
			pw += (*pw != c && *pw != d);// && *pw != ' ' && *pw != '/' && *pw != ':');
    }
    *pw = '\0';
}


__INLINE void clear()
{
	char ch;
	while((UART0->FSR & UART_FSR_RX_EMPTY_Msk) == 0)   
			{			/* Get the character from UART Buffer */
				ch= UART0->RBR;
			}

}


__INLINE void sendAT(char* AT, char* resp1, char* resp2, char* resp3, uint32_t waittime_sec)
{
	char*r1;
	char*r2;
	char*r3;
	int size,finc=0;
	char flush[100];
	int atpointer=0;
	inc=0;
	waittime_sec=20;
	tmrcount=0;
		PB2 = 0;
	size=strlen(AT);
//	delayms(1);
	memset(UART0Data,0,UART0RXBUFSIZE);

	UART0->FSR |= UART_FSR_TX_OVER_IF_Msk;
   if(!(UART0->FSR & UART_FSR_TX_FULL_Msk))
		{ 
			UART0->DATA = 0x1A;
		}	
		
	clear();
	for(atpointer=0;atpointer<size;)
	{
	UART0->FSR |= UART_FSR_TX_OVER_IF_Msk;
   if(!(UART0->FSR & UART_FSR_TX_FULL_Msk))
		{ 
			UART0->DATA = AT[atpointer];
			atpointer++;
		}
	}	
	do{
		r1=strstr(UART0Data,resp1);
		r2=strstr(UART0Data,resp2);
		r3=strstr(UART0Data,resp3);
	}while(! ( r1 || r2 || r3 || ((tmrcount >= waittime_sec ))));
	if(r1 || r2 || r3)
	{
		responseok=1;
	}
	else
	{
		responseok=0;
	}
 //CLK_SysTickDelay(1000);
//	PB2 = 1;
}




