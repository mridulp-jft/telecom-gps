extern int sz,cn,i;
int e; long adcsa, adcin,adcsample;
int fuel;







__inline void ADC_Init(void)
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


__inline void adc_start_conversion(uint8_t channel)
{
ADC0->SC1[0] = !ADC_SC1_AIEN_MASK | ADC_SC1_DIFF_MASK | ADC_SC1_ADCH(channel);
}



__inline void adc_read(uint8_t channel)
{
	adcin=0;fuel=0;adcsample=0;
for(e=0;e<500;){
	
ADC0->SC1[0] = !ADC_SC1_AIEN_MASK | ADC_SC1_DIFF_MASK | ADC_SC1_ADCH(channel) ;
while(ADC0_SC2 & ADC_SC2_ADACT_MASK); //Conversion in progress
while(!(ADC0_SC1A & ADC_SC1_COCO_MASK)); //Wait until conversion complete
adcin = ADC0_RA;


		if(adcin>40000){adcin=0;}
			else{
			adcsample+=adcin;
			}
			e++;
	}
fuel=adcsample/5000;	

}
	
	
	
	



char mystrstr(char* str1, char character)
{
	sz=strlen(str1);
	for(cn=0;cn<=sz;cn++)
	{if(str1[cn] == character)
		{return 1;}
	}
	return 0;
}


__inline void remove_all_chars(char* str, char c, char d) {
    char *pr = str, *pw = str;
    while (*pr) {
        *pw = *pr++;
			pw += (*pw != c && *pw != d && *pw != ' ' && *pw != '/' && *pw != ':');
    }
    *pw = '\0';
}


/*************************** delay*****************************************/
__inline void delay(int32 delaytime)
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
        

