#line 1 "..\\functions.c"
 
 
 
void UART1_IRQHandler(void)
{
	
	if(((DEBUG_PORT->FSR & UART_FSR_RX_EMPTY_Msk) == 0))
			{			 
				UART1Data[inc]= UART1->RBR;
				inc++;
			}

}


void SysTick_Handler(void)
{
	sysTicks++;
}

__INLINE void sendAT(char* AT, char* resp1, char* resp2, char*resp3, uint32_t waittime_ms)
{
	char*r1;
	char*r2;
	char*r3;
	uint32_t waittime_us;
	int size;
	int atpointer=0;
	inc=0;
	size=strlen(AT);
	memset(g_u8RecData,0,RXBUFSIZE);
	for(atpointer=0;atpointer<size;)
	{
   if(!(DEBUG_PORT->FSR & UART_FSR_TX_FULL_Msk))
		{ 
			DEBUG_PORT->DATA = AT[atpointer];
			atpointer++;
		}
	}
	
	SysTick->LOAD = waittime_ms * CyclesPerUs;
	SysTick->VAL  = (0x00);
	SysTick->CTRL = SysTick_CTRL_CLKSOURCE_Msk | SysTick_CTRL_ENABLE_Msk;
	do{
		r1=strstr(UART1Data,resp1);
		r2=strstr(UART1Data,resp2);
		r3=strstr(UART1Data,resp3);
	}while(!(r1||r2||r3 || (SysTick->CTRL & SysTick_CTRL_COUNTFLAG_Msk) != 0));

	SysTick->CTRL = 0;  
}


