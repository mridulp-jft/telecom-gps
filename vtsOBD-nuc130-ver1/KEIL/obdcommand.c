#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "NUC100Series.h"
#define osObjectsPublic										 // define objects in main module
#include "osObjects.h"											// RTOS object definitions
#include "uart.h"
#include "cmsis_os.h"							 // CMSIS RTOS header file
#include "math.h"

/*	Extern Variables
*****************************************************************/
extern uint8_t g_u8OBDRecDataptr;
extern char g_u8OBDRecData[OBDRXBUFSIZE];
/****************************************************************/

/*	Global Variables
*****************************************************************/
uint8_t tmr1sec;
char *obdr1;
char *obdr2;
char *obdr3; 
/****************************************************************/

/*	Function Declarations
*****************************************************************/
void send_OBD(char * command, char * response1, char * response2, char * response3, int32_t timeout);
void clearuart2(void);
void obdcommand(char* cmd);
/****************************************************************/


void send_OBD(char * command, char * response1, char * response2, char * response3, int32_t timeout){

	tmr1sec=0;
//	timeout =5;
	obdr1=0;
	obdr2=0;
	obdr3=0;
	g_u8OBDRecDataptr=0;
	memset(g_u8OBDRecData,0,OBDRXBUFSIZE);
	clearuart2();
	obdcommand(command);
//	send_string_to_uart1("\r\nAT\r\n");
	do{
		obdr1 = strstr(g_u8OBDRecData, response1);
		obdr2 = strstr(g_u8OBDRecData, response2);
		obdr3 = strstr(g_u8OBDRecData, response3);
	}while(!(obdr1 || obdr2 || obdr3 ||((tmr1sec >= timeout))));	 //!(r1 || r2 || r3 ||

osDelay(10);
}
   
void clearuart2(void){
  char dump;
    while(!UART_GET_RX_EMPTY(UART2)) 
    {
      dump = UART_READ(UART2);
    }
}

void obdcommand(char* cmd)
{
  while(*cmd != '\0'){

    while(UART2->FSR & UART_FSR_TX_FULL_Msk);
    UART2->DATA = *cmd;
    if(*cmd == '\n')
    {
        while(UART2->FSR & UART_FSR_TX_FULL_Msk);
        UART2->DATA = '\r';
    }
  *cmd++;
  }
}





__inline int hextodecimal(char *hex){
	
	 double decimal, place;
   double val, lentt;

	int hex2deci;
	 
    decimal = 0;
    place = 1;
	   /* Finds the length of total number of hex digit */
    lentt = strlen(hex); 
    lentt--;
     
    /*
     * Converts the hexadecimal number to decimal number
     * using algorithm decimal = decimal + (hex[i] * 16 ^ digit)
     */
    for(hex2deci=0; hex[hex2deci]!='\0'; hex2deci++)
    {
        /*
         * Finds the decimal each equivalent hexadecimal digit
         */
        switch(hex[hex2deci])
        {
            case '0':
                val = 0;
                break;
            case '1':
                val = 1;
                break;
            case '2':
                val = 2;
                break;
            case '3':
                val = 3;
                break;
            case '4':
                val = 4;
                break;
            case '5':
                val = 5;
                break;
            case '6':
                val = 6;
                break;
            case '7':
                val = 7;
                break;
            case '8':
                val = 8;
                break;
            case '9':
                val = 9;
                break;
            case 'a':
            case 'A':
                val = 10;
                break;
            case 'b':
            case 'B':
                val = 11;
                break;
            case 'c':
            case 'C':
                val = 12;
                break;
            case 'd':
            case 'D':
                val = 13;
                break;
            case 'e':
            case 'E':
                val = 14;
                break;
            case 'f':
            case 'F':
                val = 15;
                break;
        }
 
        decimal += val * pow(16, lentt);
        lentt--;
    }
	
return decimal;	
	
}

	

__inline void hextobinary(char* hex, char* bin){
	int cou=0;
		while(hex[cou]){
         switch(hex[cou]){
             case '0': strcat(bin,"0000"); break;
             case '1': strcat(bin,"0001"); break;
             case '2': strcat(bin,"0010"); break;
             case '3': strcat(bin,"0011"); break;
             case '4': strcat(bin,"0100"); break;
             case '5': strcat(bin,"0101"); break;
             case '6': strcat(bin,"0110"); break;
             case '7': strcat(bin,"0111"); break;
             case '8': strcat(bin,"1000"); break;
             case '9': strcat(bin,"1001"); break;
             case 'A': strcat(bin,"1010"); break;
             case 'B': strcat(bin,"1011"); break;
             case 'C': strcat(bin,"1100"); break;
             case 'D': strcat(bin,"1101"); break;
             case 'E': strcat(bin,"1110"); break;
             case 'F': strcat(bin,"1111"); break;
             case 'a': strcat(bin,"1010"); break;
             case 'b': strcat(bin,"1011"); break;
             case 'c': strcat(bin,"1100"); break;
             case 'd': strcat(bin,"1101"); break;
             case 'e': strcat(bin,"1110"); break;
             case 'f': strcat(bin,"1111"); break;
             default:  printf("\nInvalid hexadecimal digit %c ",hex[cou]); 
         }
         cou++;
    }

}


