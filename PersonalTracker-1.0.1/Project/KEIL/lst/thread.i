#line 1 "Thread.c"
#line 1 "..\\..\\Library\\Device\\Nuvoton\\Nano100Series\\Include\\Nano100Series.h"
 










 






































 















 

 
 
 



 



 
typedef enum IRQn {
     

    NonMaskableInt_IRQn   = -14,     
    HardFault_IRQn        = -13,     
    SVCall_IRQn           = -5,      
    PendSV_IRQn           = -2,      
    SysTick_IRQn          = -1,      

     
    BOD_IRQn              = 0,       
    WDT_IRQn              = 1,       
    EINT0_IRQn            = 2,       
    EINT1_IRQn            = 3,       
    GPABC_IRQn            = 4,       
    GPDEF_IRQn            = 5,       
    PWM0_IRQn             = 6,       
    PWM1_IRQn             = 7,       
    TMR0_IRQn             = 8,       
    TMR1_IRQn             = 9,       
    TMR2_IRQn             = 10,      
    TMR3_IRQn             = 11,      
    UART0_IRQn            = 12,      
    UART1_IRQn            = 13,      
    SPI0_IRQn             = 14,      
    SPI1_IRQn             = 15,      
    SPI2_IRQn             = 16,      
    HIRC_IRQn             = 17,      
    I2C0_IRQn             = 18,      
    I2C1_IRQn             = 19,      
    SC2_IRQn              = 20,      
    SC0_IRQn              = 21,      
    SC1_IRQn              = 22,      
    USBD_IRQn             = 23,      
    LCD_IRQn              = 25,      
    PDMA_IRQn             = 26,      
    I2S_IRQn              = 27,      
    PDWU_IRQn             = 28,      
    ADC_IRQn              = 29,      
    DAC_IRQn              = 30,      
    RTC_IRQn              = 31       
} IRQn_Type;






 

 






   


#line 1 "..\\..\\Library\\CMSIS\\Include\\core_cm0.h"
 




 

























 











#line 1 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdint.h"
 
 





 









     
#line 27 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdint.h"
     











#line 46 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdint.h"





 

     

     
typedef   signed          char int8_t;
typedef   signed short     int int16_t;
typedef   signed           int int32_t;
typedef   signed       __int64 int64_t;

     
typedef unsigned          char uint8_t;
typedef unsigned short     int uint16_t;
typedef unsigned           int uint32_t;
typedef unsigned       __int64 uint64_t;

     

     
     
typedef   signed          char int_least8_t;
typedef   signed short     int int_least16_t;
typedef   signed           int int_least32_t;
typedef   signed       __int64 int_least64_t;

     
typedef unsigned          char uint_least8_t;
typedef unsigned short     int uint_least16_t;
typedef unsigned           int uint_least32_t;
typedef unsigned       __int64 uint_least64_t;

     

     
typedef   signed           int int_fast8_t;
typedef   signed           int int_fast16_t;
typedef   signed           int int_fast32_t;
typedef   signed       __int64 int_fast64_t;

     
typedef unsigned           int uint_fast8_t;
typedef unsigned           int uint_fast16_t;
typedef unsigned           int uint_fast32_t;
typedef unsigned       __int64 uint_fast64_t;

     




typedef   signed           int intptr_t;
typedef unsigned           int uintptr_t;


     
typedef   signed     long long intmax_t;
typedef unsigned     long long uintmax_t;




     

     





     





     





     

     





     





     





     

     





     





     





     

     






     






     






     

     


     


     


     

     
#line 216 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdint.h"

     



     






     
    
 



#line 241 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdint.h"

     







     










     











#line 305 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdint.h"






 
#line 45 "..\\..\\Library\\CMSIS\\Include\\core_cm0.h"

















 




 



 

 













#line 120 "..\\..\\Library\\CMSIS\\Include\\core_cm0.h"



 







#line 162 "..\\..\\Library\\CMSIS\\Include\\core_cm0.h"

#line 1 "..\\..\\Library\\CMSIS\\Include\\core_cmInstr.h"
 




 

























 












 



 

 
#line 1 "..\\..\\Library\\CMSIS\\Include\\cmsis_armcc.h"
 




 

























 










 



 

 
 





 
static __inline uint32_t __get_CONTROL(void)
{
  register uint32_t __regControl         __asm("control");
  return(__regControl);
}






 
static __inline void __set_CONTROL(uint32_t control)
{
  register uint32_t __regControl         __asm("control");
  __regControl = control;
}






 
static __inline uint32_t __get_IPSR(void)
{
  register uint32_t __regIPSR          __asm("ipsr");
  return(__regIPSR);
}






 
static __inline uint32_t __get_APSR(void)
{
  register uint32_t __regAPSR          __asm("apsr");
  return(__regAPSR);
}






 
static __inline uint32_t __get_xPSR(void)
{
  register uint32_t __regXPSR          __asm("xpsr");
  return(__regXPSR);
}






 
static __inline uint32_t __get_PSP(void)
{
  register uint32_t __regProcessStackPointer  __asm("psp");
  return(__regProcessStackPointer);
}






 
static __inline void __set_PSP(uint32_t topOfProcStack)
{
  register uint32_t __regProcessStackPointer  __asm("psp");
  __regProcessStackPointer = topOfProcStack;
}






 
static __inline uint32_t __get_MSP(void)
{
  register uint32_t __regMainStackPointer     __asm("msp");
  return(__regMainStackPointer);
}






 
static __inline void __set_MSP(uint32_t topOfMainStack)
{
  register uint32_t __regMainStackPointer     __asm("msp");
  __regMainStackPointer = topOfMainStack;
}






 
static __inline uint32_t __get_PRIMASK(void)
{
  register uint32_t __regPriMask         __asm("primask");
  return(__regPriMask);
}






 
static __inline void __set_PRIMASK(uint32_t priMask)
{
  register uint32_t __regPriMask         __asm("primask");
  __regPriMask = (priMask);
}


#line 263 "..\\..\\Library\\CMSIS\\Include\\cmsis_armcc.h"


#line 297 "..\\..\\Library\\CMSIS\\Include\\cmsis_armcc.h"



 


 



 




 






 







 






 








 










 










 











 








 

__attribute__((section(".rev16_text"))) static __inline __asm uint32_t __REV16(uint32_t value)
{
  rev16 r0, r0
  bx lr
}







 

__attribute__((section(".revsh_text"))) static __inline __asm int32_t __REVSH(int32_t value)
{
  revsh r0, r0
  bx lr
}









 









 








 



__attribute__((always_inline)) static __inline uint32_t __RBIT(uint32_t value)
{
  uint32_t result;
  int32_t s = 4   * 8 - 1;  

  result = value;                       
  for (value >>= 1U; value; value >>= 1U)
  {
    result <<= 1U;
    result |= value & 1U;
    s--;
  }
  result <<= s;                         
  return(result);
}








 



#line 649 "..\\..\\Library\\CMSIS\\Include\\cmsis_armcc.h"

   


 



 

#line 731 "..\\..\\Library\\CMSIS\\Include\\cmsis_armcc.h"
 


#line 54 "..\\..\\Library\\CMSIS\\Include\\core_cmInstr.h"

 
#line 84 "..\\..\\Library\\CMSIS\\Include\\core_cmInstr.h"

   

#line 164 "..\\..\\Library\\CMSIS\\Include\\core_cm0.h"
#line 1 "..\\..\\Library\\CMSIS\\Include\\core_cmFunc.h"
 




 

























 












 



 

 
#line 54 "..\\..\\Library\\CMSIS\\Include\\core_cmFunc.h"

 
#line 84 "..\\..\\Library\\CMSIS\\Include\\core_cmFunc.h"

 

#line 165 "..\\..\\Library\\CMSIS\\Include\\core_cm0.h"
















 
#line 198 "..\\..\\Library\\CMSIS\\Include\\core_cm0.h"

 






 
#line 214 "..\\..\\Library\\CMSIS\\Include\\core_cm0.h"

 




 










 



 






 



 
typedef union
{
  struct
  {
    uint32_t _reserved0:28;               
    uint32_t V:1;                         
    uint32_t C:1;                         
    uint32_t Z:1;                         
    uint32_t N:1;                         
  } b;                                    
  uint32_t w;                             
} APSR_Type;

 















 
typedef union
{
  struct
  {
    uint32_t ISR:9;                       
    uint32_t _reserved0:23;               
  } b;                                    
  uint32_t w;                             
} IPSR_Type;

 






 
typedef union
{
  struct
  {
    uint32_t ISR:9;                       
    uint32_t _reserved0:15;               
    uint32_t T:1;                         
    uint32_t _reserved1:3;                
    uint32_t V:1;                         
    uint32_t C:1;                         
    uint32_t Z:1;                         
    uint32_t N:1;                         
  } b;                                    
  uint32_t w;                             
} xPSR_Type;

 





















 
typedef union
{
  struct
  {
    uint32_t _reserved0:1;                
    uint32_t SPSEL:1;                     
    uint32_t _reserved1:30;               
  } b;                                    
  uint32_t w;                             
} CONTROL_Type;

 



 







 



 
typedef struct
{
  volatile uint32_t ISER[1U];                
        uint32_t RESERVED0[31U];
  volatile uint32_t ICER[1U];                
        uint32_t RSERVED1[31U];
  volatile uint32_t ISPR[1U];                
        uint32_t RESERVED2[31U];
  volatile uint32_t ICPR[1U];                
        uint32_t RESERVED3[31U];
        uint32_t RESERVED4[64U];
  volatile uint32_t IP[8U];                  
}  NVIC_Type;

 







 



 
typedef struct
{
  volatile const  uint32_t CPUID;                   
  volatile uint32_t ICSR;                    
        uint32_t RESERVED0;
  volatile uint32_t AIRCR;                   
  volatile uint32_t SCR;                     
  volatile uint32_t CCR;                     
        uint32_t RESERVED1;
  volatile uint32_t SHP[2U];                 
  volatile uint32_t SHCSR;                   
} SCB_Type;

 















 



























 















 









 






 



 







 



 
typedef struct
{
  volatile uint32_t CTRL;                    
  volatile uint32_t LOAD;                    
  volatile uint32_t VAL;                     
  volatile const  uint32_t CALIB;                   
} SysTick_Type;

 












 



 



 









 








 
 







 






 







 


 







 

 










 









 


 



 





 

 
 









 
static __inline void NVIC_EnableIRQ(IRQn_Type IRQn)
{
  ((NVIC_Type *) ((0xE000E000UL) + 0x0100UL) )->ISER[0U] = (uint32_t)(1UL << (((uint32_t)(int32_t)IRQn) & 0x1FUL));
}






 
static __inline void NVIC_DisableIRQ(IRQn_Type IRQn)
{
  ((NVIC_Type *) ((0xE000E000UL) + 0x0100UL) )->ICER[0U] = (uint32_t)(1UL << (((uint32_t)(int32_t)IRQn) & 0x1FUL));
}








 
static __inline uint32_t NVIC_GetPendingIRQ(IRQn_Type IRQn)
{
  return((uint32_t)(((((NVIC_Type *) ((0xE000E000UL) + 0x0100UL) )->ISPR[0U] & (1UL << (((uint32_t)(int32_t)IRQn) & 0x1FUL))) != 0UL) ? 1UL : 0UL));
}






 
static __inline void NVIC_SetPendingIRQ(IRQn_Type IRQn)
{
  ((NVIC_Type *) ((0xE000E000UL) + 0x0100UL) )->ISPR[0U] = (uint32_t)(1UL << (((uint32_t)(int32_t)IRQn) & 0x1FUL));
}






 
static __inline void NVIC_ClearPendingIRQ(IRQn_Type IRQn)
{
  ((NVIC_Type *) ((0xE000E000UL) + 0x0100UL) )->ICPR[0U] = (uint32_t)(1UL << (((uint32_t)(int32_t)IRQn) & 0x1FUL));
}








 
static __inline void NVIC_SetPriority(IRQn_Type IRQn, uint32_t priority)
{
  if ((int32_t)(IRQn) < 0)
  {
    ((SCB_Type *) ((0xE000E000UL) + 0x0D00UL) )->SHP[( (((((uint32_t)(int32_t)(IRQn)) & 0x0FUL)-8UL) >> 2UL) )] = ((uint32_t)(((SCB_Type *) ((0xE000E000UL) + 0x0D00UL) )->SHP[( (((((uint32_t)(int32_t)(IRQn)) & 0x0FUL)-8UL) >> 2UL) )] & ~(0xFFUL << ( ((((uint32_t)(int32_t)(IRQn)) ) & 0x03UL) * 8UL))) |
       (((priority << (8U - 2)) & (uint32_t)0xFFUL) << ( ((((uint32_t)(int32_t)(IRQn)) ) & 0x03UL) * 8UL)));
  }
  else
  {
    ((NVIC_Type *) ((0xE000E000UL) + 0x0100UL) )->IP[( (((uint32_t)(int32_t)(IRQn)) >> 2UL) )]  = ((uint32_t)(((NVIC_Type *) ((0xE000E000UL) + 0x0100UL) )->IP[( (((uint32_t)(int32_t)(IRQn)) >> 2UL) )]  & ~(0xFFUL << ( ((((uint32_t)(int32_t)(IRQn)) ) & 0x03UL) * 8UL))) |
       (((priority << (8U - 2)) & (uint32_t)0xFFUL) << ( ((((uint32_t)(int32_t)(IRQn)) ) & 0x03UL) * 8UL)));
  }
}










 
static __inline uint32_t NVIC_GetPriority(IRQn_Type IRQn)
{

  if ((int32_t)(IRQn) < 0)
  {
    return((uint32_t)(((((SCB_Type *) ((0xE000E000UL) + 0x0D00UL) )->SHP[( (((((uint32_t)(int32_t)(IRQn)) & 0x0FUL)-8UL) >> 2UL) )] >> ( ((((uint32_t)(int32_t)(IRQn)) ) & 0x03UL) * 8UL) ) & (uint32_t)0xFFUL) >> (8U - 2)));
  }
  else
  {
    return((uint32_t)(((((NVIC_Type *) ((0xE000E000UL) + 0x0100UL) )->IP[ ( (((uint32_t)(int32_t)(IRQn)) >> 2UL) )] >> ( ((((uint32_t)(int32_t)(IRQn)) ) & 0x03UL) * 8UL) ) & (uint32_t)0xFFUL) >> (8U - 2)));
  }
}





 
static __inline void NVIC_SystemReset(void)
{
  do { __schedule_barrier(); __dsb(0xF); __schedule_barrier(); } while (0U);                                                          
 
  ((SCB_Type *) ((0xE000E000UL) + 0x0D00UL) )->AIRCR  = ((0x5FAUL << 16U) |
                 (1UL << 2U));
  do { __schedule_barrier(); __dsb(0xF); __schedule_barrier(); } while (0U);                                                           

  for(;;)                                                            
  {
    __nop();
  }
}

 



 





 













 
static __inline uint32_t SysTick_Config(uint32_t ticks)
{
  if ((ticks - 1UL) > (0xFFFFFFUL ))
  {
    return (1UL);                                                    
  }

  ((SysTick_Type *) ((0xE000E000UL) + 0x0010UL) )->LOAD  = (uint32_t)(ticks - 1UL);                          
  NVIC_SetPriority (SysTick_IRQn, (1UL << 2) - 1UL);  
  ((SysTick_Type *) ((0xE000E000UL) + 0x0010UL) )->VAL   = 0UL;                                              
  ((SysTick_Type *) ((0xE000E000UL) + 0x0010UL) )->CTRL  = (1UL << 2U) |
                   (1UL << 1U)   |
                   (1UL );                          
  return (0UL);                                                      
}



 










#line 141 "..\\..\\Library\\Device\\Nuvoton\\Nano100Series\\Include\\Nano100Series.h"
#line 1 "..\\..\\Library\\Device\\Nuvoton\\Nano100Series\\Include\\system_Nano100Series.h"
 








 












 

#line 31 "..\\..\\Library\\Device\\Nuvoton\\Nano100Series\\Include\\system_Nano100Series.h"


extern uint32_t SystemCoreClock;         
extern uint32_t CyclesPerUs;             









 

extern void SystemCoreClockUpdate (void);
extern uint32_t SysGet_PLLClockFreq(void);








 
#line 142 "..\\..\\Library\\Device\\Nuvoton\\Nano100Series\\Include\\Nano100Series.h"
#line 143 "..\\..\\Library\\Device\\Nuvoton\\Nano100Series\\Include\\Nano100Series.h"

 
 
 



 


#pragma anon_unions




 



 

typedef struct {


    












 
    volatile const  uint32_t RESULT[18];


    
















































































 
    volatile uint32_t CR;

    





























































 
    volatile uint32_t CHEN;

    



























 
    volatile uint32_t CMPR0;

    



























 
    volatile uint32_t CMPR1;

    







































 
    volatile uint32_t SR;
    uint32_t RESERVE0[1];


    









 
    volatile const  uint32_t PDMA;

    



















 
    volatile uint32_t PWRCTL;

    




















 
    volatile uint32_t CALCTL;

    










 
    volatile uint32_t CALWORD;

    

































 
    volatile uint32_t SMPLCNT0;

    
















 
    volatile uint32_t SMPLCNT1;

} ADC_T;




 






























































































































   
   


 



 

typedef struct {


    





































































 
    volatile uint32_t PWRCTL;

    
























 
    volatile uint32_t AHBCLK;

    























































































 
    volatile uint32_t APBCLK;

    

























 
    volatile const  uint32_t CLKSTATUS;

    


















 
    volatile uint32_t CLKSEL0;

    













































 
    volatile uint32_t CLKSEL1;

    

























































 
    volatile uint32_t CLKSEL2;

    


















 
    volatile uint32_t CLKDIV0;

    










 
    volatile uint32_t CLKDIV1;

    




















 
    volatile uint32_t PLLCTL;

    













 
    volatile uint32_t FRQDIV;

    







































 
    volatile uint32_t MCLKO;

    










 
    volatile  uint32_t WK_INTSTS;

} CLK_T;




 
































































































































































































































































   
   


 



 

typedef struct {


    

























 
    volatile uint32_t CTL0;

    







 
    volatile uint32_t DATA0;

    

















 
    volatile uint32_t STS0;
    uint32_t RESERVE0[1];


    

























 
    volatile uint32_t CTL1;

    







 
    volatile uint32_t DATA1;

    

















 
    volatile uint32_t STS1;
    uint32_t RESERVE1[1];


    

















 
    volatile uint32_t COMCTL;

} DAC_T;




 


































   
   


 



 

typedef struct {


    


































 
    volatile uint32_t EBICON;

    





















 
    volatile uint32_t EXTIME;

} EBI_T;




 































   
   


 



 

typedef struct {


    


































 
    volatile uint32_t ISPCON;

    









 
    volatile uint32_t ISPADR;

    









 
    volatile uint32_t ISPDAT;

    












 
    volatile uint32_t ISPCMD;

    










 
    volatile uint32_t ISPTRG;

    










 
    volatile const  uint32_t DFBADR;
    uint32_t RESERVE0[10];


    


















 
    volatile uint32_t ISPSTA;

} FMC_T;




 

















































   
   


 



 

typedef struct {


    









 
    volatile const  uint32_t PDID;

    






























 
    volatile uint32_t RST_SRC;

    


































 
    volatile uint32_t IPRST_CTL1;

    








































































 
    volatile uint32_t IPRST_CTL2;
    uint32_t RESERVE0[4];


    









 
    volatile uint32_t TEMPCTL;
    uint32_t RESERVE1[3];


    






















































 
    volatile uint32_t PA_L_MFP;

    

























































 
    volatile uint32_t PA_H_MFP;

    




















































 
    volatile uint32_t PB_L_MFP;

    























































 
    volatile uint32_t PB_H_MFP;

    



















































 
    volatile uint32_t PC_L_MFP;

    















































 
    volatile uint32_t PC_H_MFP;

    

















































 
    volatile uint32_t PD_L_MFP;

    






























 
    volatile uint32_t PD_H_MFP;

    































 
    volatile uint32_t PE_L_MFP;

    






























 
    volatile uint32_t PE_H_MFP;

    



























 
    volatile uint32_t PF_L_MFP;
    uint32_t RESERVE2[1];


    










 
    volatile uint32_t PORCTL;

    






















































 
    volatile uint32_t BODCTL;

    




























 
    volatile  uint32_t BODSTS;

    




























 
    volatile uint32_t Int_VREFCTL;
    uint32_t RESERVE3[4];


    



































 
    volatile uint32_t IRCTRIMCTL;

    
















 
    volatile uint32_t IRCTRIMIEN;

    























 
    volatile uint32_t IRCTRIMINT;
    uint32_t RESERVE4[29];


    









 
    volatile uint32_t RegLockAddr;

} SYS_T;




 






































































































































































































































































































































































































































































   
   


 



 

typedef struct {


    






















































































































 
    volatile uint32_t PMD;

    











 
    volatile uint32_t OFFD;

    











 
    volatile uint32_t DOUT;

    















 
    volatile uint32_t DMASK;

    









 
    volatile const  uint32_t PIN;

    















 
    volatile uint32_t DBEN;

    

















 
    volatile uint32_t IMD;

    






































































































































































































































































































 
    volatile uint32_t IER;

    














 
    volatile uint32_t ISRC;

    












 
    volatile uint32_t PUEN;

} GPIO_T;


typedef struct {
    

































 
    volatile uint32_t DBNCECON;
} GP_DB_T;




 








































































































































































   




 










   
   


 



 

typedef struct {


    

































 
    volatile uint32_t CON;

    












 
    volatile uint32_t INTSTS;

    


















 
    volatile const  uint32_t STATUS;

    









 
    volatile uint32_t DIV;

    















 
    volatile uint32_t TOUT;

    
















 
    volatile uint32_t DATA;

    

















 
    volatile uint32_t SADDR0;

    

















 
    volatile uint32_t SADDR1;
    uint32_t RESERVE0[2];


    












 
    volatile uint32_t SAMASK0;

    












 
    volatile uint32_t SAMASK1;
    uint32_t RESERVE1[4];


    









 
    volatile uint32_t WKUPCON;

    










 
    volatile  uint32_t WKUPSTS;

} I2C_T;




 
































































   
   


 



 

typedef struct {


    
























































































 
    volatile uint32_t CTRL;

    















 
    volatile uint32_t CLKDIV;

    






































 
    volatile uint32_t INTEN;

    

































































































 
    volatile uint32_t STATUS;

    











 
    volatile  uint32_t TXFIFO;

    











 
    volatile const  uint32_t RXFIFO;

} I2S_T;




 




















































































































































   
   


 



 

typedef struct {


    








 
    volatile const  uint32_t IRQSRC[32];


    








 
    volatile uint32_t NMI_SEL;

    















 
    volatile uint32_t MCU_IRQ;

} INTR_T;




 










   
   


 



 

typedef struct {


    









































 
    volatile uint32_t CTL;

    








































 
    volatile uint32_t DISPCTL;

    














 
    volatile uint32_t MEM_0;

    














 
    volatile uint32_t MEM_1;

    














 
    volatile uint32_t MEM_2;

    














 
    volatile uint32_t MEM_3;

    














 
    volatile uint32_t MEM_4;

    














 
    volatile uint32_t MEM_5;

    














 
    volatile uint32_t MEM_6;

    














 
    volatile uint32_t MEM_7;

    














 
    volatile uint32_t MEM_8;

    














 
    volatile uint32_t MEM_9;

    



















 
    volatile uint32_t FCR;

    













 
    volatile uint32_t FCSTS;

} LCD_T;




 















































































































































































   
   


 



 


typedef struct {


    



















































 
    volatile uint32_t CTL;

    









 
    volatile uint32_t DMASAR;
    uint32_t RESERVE0[1];


    








 
    volatile uint32_t DMABCR;
    uint32_t RESERVE1[1];


    








 
    volatile const  uint32_t DMACSAR;
    uint32_t RESERVE2[1];


    









 
    volatile const  uint32_t DMACBCR;

    












 
    volatile uint32_t DMAIER;

    



















 
    volatile uint32_t DMAISR;
    uint32_t RESERVE3[22];


    











 
    volatile uint32_t WDATA;

    








 
    volatile uint32_t SEED;

    








 
    volatile const  uint32_t CHECKSUM;

} DMA_CRC_T;


typedef struct {


    






























 
    volatile uint32_t GCRCSR;

    












































 
    volatile uint32_t DSSR0;

    





















 
    volatile uint32_t DSSR1;

    






























 
    volatile const  uint32_t GCRISR;

} DMA_GCR_T;


typedef struct {
    


















































 
    volatile uint32_t CSR;

    









 
    volatile uint32_t SAR;

    









 
    volatile uint32_t DAR;

    









 
    volatile uint32_t BCR;
    uint32_t RESERVE0[1];


    








 
    volatile const  uint32_t CSAR;

    








 
    volatile const  uint32_t CDAR;

    









 
    volatile const  uint32_t CBCR;

    


















 
    volatile uint32_t IER;

    





























 
    volatile uint32_t ISR;

    











 
    volatile uint32_t TCR;

} PDMA_T;



typedef struct {


    



























 
    volatile uint32_t CSR;

    








 
    volatile uint32_t SAR;

    








 
    volatile uint32_t DAR;

    









 
    volatile uint32_t BCR;
    uint32_t RESERVE0[1];


    








 
    volatile const  uint32_t CSAR;

    








 
    volatile const  uint32_t CDAR;

    








 
    volatile const  uint32_t CBCR;

    












 
    volatile uint32_t IER;

    


















 
    volatile uint32_t ISR;
    uint32_t RESERVE1[1];


    










 
    volatile uint32_t SASOCR;

    








 
    volatile uint32_t DASOCR;

} VDMA_T;





 





























































   





 



































































   





 






































































   





 























































   

   


 



 

typedef struct {


    


















 
    volatile uint32_t PRES;

    






















 
    volatile uint32_t CLKSEL;

    






















































 
    volatile uint32_t CTL;

    


















 
    volatile uint32_t INTEN;

    


































 
    volatile uint32_t INTSTS;

    






















 
    volatile uint32_t OE;
    uint32_t RESERVE0[1];


    


























 
    volatile uint32_t DUTY0;

    















 
    volatile const  uint32_t DATA0;
    uint32_t RESERVE1[1];


    


























 
    volatile uint32_t DUTY1;

    















 
    volatile const  uint32_t DATA1;
    uint32_t RESERVE2[1];


    


























 
    volatile uint32_t DUTY2;

    















 
    volatile const  uint32_t DATA2;
    uint32_t RESERVE3[1];


    
























 
    volatile uint32_t DUTY3;

    















 
    volatile const  uint32_t DATA3;
    uint32_t RESERVE4[3];


    




































































































 
    volatile uint32_t CAPCTL;

    






































 
    volatile uint32_t CAPINTEN;

    


























































 
    volatile uint32_t CAPINTSTS;

    










 
    volatile const  uint32_t CRL0;

    










 
    volatile const  uint32_t CFL0;

    










 
    volatile const  uint32_t CRL1;

    










 
    volatile const  uint32_t CFL1;

    










 
    volatile const  uint32_t CRL2;

    










 
    volatile const  uint32_t CFL2;

    










 
    volatile const  uint32_t CRL3;

    










 
    volatile const  uint32_t CFL3;

    


















 
    volatile const  uint32_t PDMACH0;

    


















 
    volatile const  uint32_t PDMACH2;

} PWM_T;




 

























































































































































































































































































































































































































   
   


 



 

typedef struct {


    














 
    volatile  uint32_t INIR;

    












 
    volatile  uint32_t AER;

    


























 
    volatile uint32_t FCR;

    












 
    volatile uint32_t TLR;

    












 
    volatile uint32_t CLR;

    










 
    volatile uint32_t TSSR;

    














 
    volatile uint32_t DWR;

    












 
    volatile uint32_t TAR;

    












 
    volatile uint32_t CAR;

    









 
    volatile const  uint32_t LIR;

    















 
    volatile uint32_t RIER;

    
























 
    volatile uint32_t RIIR;

    






















 
    volatile uint32_t TTR;
    uint32_t RESERVE0[2];


    























 
    volatile uint32_t SPRCTL;

    









 
    volatile uint32_t SPR[20];

} RTC_T;




 

































































































































































































   
   


 



 

typedef struct {


    union {
        








 
        volatile const  uint32_t  RBR;
        








 
        volatile  uint32_t  THR;
    };

    



















































































 
    volatile uint32_t CTL;

    






















































































 
    volatile uint32_t ALTCTL;

    









 
    volatile uint32_t EGTR;

    











 
    volatile uint32_t RFTMR;

    
















 
    volatile uint32_t ETUCR;

    




















































 
    volatile uint32_t IER;

    
















































 
    volatile uint32_t ISR;

    







































































 
    volatile uint32_t TRSR;

    








































































 
    volatile uint32_t PINCSR;

    










 
    volatile uint32_t TMR0;

    










 
    volatile uint32_t TMR1;

    










 
    volatile uint32_t TMR2;

    


























 
    volatile uint32_t UACTL;

    








 
    volatile const  uint32_t TDRA;

    










 
    volatile const  uint32_t TDRB;

} SC_T;




 

































































































































































































































































































   
   


 



 

typedef struct {


    































































































 
    volatile uint32_t CTL;

    



















































 
    volatile uint32_t STATUS;

    














 
    volatile uint32_t CLKDIV;

    

















































 
    volatile uint32_t SSR;

    










 
    volatile const  uint32_t RX0;

    










 
    volatile const  uint32_t RX1;
    uint32_t RESERVE0[2];


    












 
    volatile  uint32_t TX0;

    












 
    volatile  uint32_t TX1;
    uint32_t RESERVE1[3];


    











 
    volatile uint32_t VARCLK;

    


























 
    volatile uint32_t DMA;

    
































 
    volatile uint32_t FFCTL;
} SPI_T;




 






































































































































































   
   


 



 

typedef struct {


    






































































































































 
    volatile uint32_t CTL;

    









 
    volatile uint32_t PRECNT;

    













 
    volatile uint32_t CMPR;

    














 
    volatile uint32_t IER;

    



























 
    volatile uint32_t ISR;

    








 
    volatile const  uint32_t DR;

    









 
    volatile const  uint32_t TCAP;
} TIMER_T;





 
























































































   


   



 



 

typedef struct {


    union {

        








 
        volatile const  uint32_t  RBR;


        








 
        volatile  uint32_t  THR;
    };

    






















































 
    volatile uint32_t CTL;

    










































 
    volatile uint32_t TLCTL;

    

































 
    volatile uint32_t IER;

    












































 
    volatile  uint32_t ISR;

    
















































 
    volatile  uint32_t TRSR;

    















































 
    volatile  uint32_t FSR;

    























 
    volatile uint32_t MCSR;

    



















 
    volatile uint32_t TMCTL;

    












 
    volatile uint32_t BAUD;
    uint32_t RESERVE0[2];


    
















 
    volatile uint32_t IRCR;

    

















































 
    volatile uint32_t ALT_CTL;

    











 
    volatile uint32_t FUN_SEL;

} UART_T;




 

















































































































































































































































   
   


 



 



 
typedef struct {


    








 
    volatile uint32_t BUFSEG;

    
















 
    volatile uint32_t MXPLD;

    

































 
    volatile uint32_t CFG;
    uint32_t RESERVE;

} USBD_EP_T;

typedef struct {


    





























 
    volatile uint32_t CTL;

    

















 
    volatile const  uint32_t BUSSTS;

    


















 
    volatile uint32_t INTEN;

    

















































 
    volatile uint32_t INTSTS;

    







 
    volatile uint32_t FADDR;

    

































 
    volatile const  uint32_t EPSTS;

    









 
    volatile uint32_t BUFSEG;

    












 
    volatile const  uint32_t EPSTS2;


    USBD_EP_T EP[8];

    uint32_t RESERVE0;

    





















 
    volatile uint32_t PDMA;

} USBD_T;




 
































































































































































   
   


 



 

typedef struct {


    






































 
    volatile uint32_t CTL;

    









 
    volatile uint32_t IER;

    



























 
    volatile uint32_t ISR;

} WDT_T;




 































   
   


 



 

typedef struct {


    










 
    volatile  uint32_t RLD;

    




















 
    volatile uint32_t CR;

    










 
    volatile uint32_t IER;

    












 
    volatile uint32_t STS;

    








 
    volatile const  uint32_t VAL;

} WWDT_T;




 




























   
   





#pragma no_anon_unions





 
 






 

#line 11594 "..\\..\\Library\\Device\\Nuvoton\\Nano100Series\\Include\\Nano100Series.h"

#line 11607 "..\\..\\Library\\Device\\Nuvoton\\Nano100Series\\Include\\Nano100Series.h"

#line 11630 "..\\..\\Library\\Device\\Nuvoton\\Nano100Series\\Include\\Nano100Series.h"

   





 
#line 11663 "..\\..\\Library\\Device\\Nuvoton\\Nano100Series\\Include\\Nano100Series.h"

#line 11685 "..\\..\\Library\\Device\\Nuvoton\\Nano100Series\\Include\\Nano100Series.h"

   

   




 

typedef volatile unsigned char  vu8;        
typedef volatile unsigned short vu16;       
typedef volatile unsigned long  vu32;       





 







 







 








 







 








 







 







 






 








 







 








 







 







 






 


   

 
 
 



 











 
#line 11873 "..\\..\\Library\\Device\\Nuvoton\\Nano100Series\\Include\\Nano100Series.h"

 










   

   






 
 
 
#line 1 "..\\..\\Library\\StdDriver\\inc\\sys.h"
 








 










 



 



 

 
 
 
#line 58 "..\\..\\Library\\StdDriver\\inc\\sys.h"

 
 
 

 





 














 




 




 

#line 103 "..\\..\\Library\\StdDriver\\inc\\sys.h"

#line 112 "..\\..\\Library\\StdDriver\\inc\\sys.h"

#line 120 "..\\..\\Library\\StdDriver\\inc\\sys.h"

#line 128 "..\\..\\Library\\StdDriver\\inc\\sys.h"





















 
#line 157 "..\\..\\Library\\StdDriver\\inc\\sys.h"

#line 164 "..\\..\\Library\\StdDriver\\inc\\sys.h"

#line 171 "..\\..\\Library\\StdDriver\\inc\\sys.h"

#line 178 "..\\..\\Library\\StdDriver\\inc\\sys.h"

#line 186 "..\\..\\Library\\StdDriver\\inc\\sys.h"

#line 194 "..\\..\\Library\\StdDriver\\inc\\sys.h"

#line 201 "..\\..\\Library\\StdDriver\\inc\\sys.h"

#line 208 "..\\..\\Library\\StdDriver\\inc\\sys.h"

 
#line 216 "..\\..\\Library\\StdDriver\\inc\\sys.h"

#line 223 "..\\..\\Library\\StdDriver\\inc\\sys.h"

#line 230 "..\\..\\Library\\StdDriver\\inc\\sys.h"

#line 237 "..\\..\\Library\\StdDriver\\inc\\sys.h"

#line 244 "..\\..\\Library\\StdDriver\\inc\\sys.h"

#line 251 "..\\..\\Library\\StdDriver\\inc\\sys.h"













 
#line 271 "..\\..\\Library\\StdDriver\\inc\\sys.h"

#line 278 "..\\..\\Library\\StdDriver\\inc\\sys.h"












#line 297 "..\\..\\Library\\StdDriver\\inc\\sys.h"

#line 305 "..\\..\\Library\\StdDriver\\inc\\sys.h"

#line 313 "..\\..\\Library\\StdDriver\\inc\\sys.h"

#line 322 "..\\..\\Library\\StdDriver\\inc\\sys.h"

 
#line 330 "..\\..\\Library\\StdDriver\\inc\\sys.h"

#line 337 "..\\..\\Library\\StdDriver\\inc\\sys.h"

































 
#line 377 "..\\..\\Library\\StdDriver\\inc\\sys.h"







#line 390 "..\\..\\Library\\StdDriver\\inc\\sys.h"




























 

















#line 442 "..\\..\\Library\\StdDriver\\inc\\sys.h"

#line 449 "..\\..\\Library\\StdDriver\\inc\\sys.h"













 
























 

























 
























 





















   



 






 







 







 







 







 







 







 








 









 









 









 







 







 







 







 







 







 








 









 








 








 









 









 







 







 














 









 









 









 
static __inline void SYS_UnlockReg(void)
{
    while(((SYS_T *) (((uint32_t)0x50000000) + 0x00000))->RegLockAddr != (0x1ul << (0))) {
        ((SYS_T *) (((uint32_t)0x50000000) + 0x00000))->RegLockAddr = 0x59;
        ((SYS_T *) (((uint32_t)0x50000000) + 0x00000))->RegLockAddr = 0x16;
        ((SYS_T *) (((uint32_t)0x50000000) + 0x00000))->RegLockAddr = 0x88;
    }
}







 
static __inline void SYS_LockReg(void)
{
    ((SYS_T *) (((uint32_t)0x50000000) + 0x00000))->RegLockAddr = 0;
}

void SYS_ClearResetSrc(uint32_t u32Src);
uint32_t SYS_GetBODStatus(void);
uint32_t SYS_GetResetSrc(void);
uint32_t SYS_IsRegLocked(void);
uint32_t  SYS_ReadPDID(void);
void SYS_ResetChip(void);
void SYS_ResetCPU(void);
void SYS_ResetModule(uint32_t u32ModuleIndex);
void SYS_EnableBOD(int32_t i32Mode, uint32_t u32BODLevel);
void SYS_DisableBOD(void);
void SYS_EnableIRCTrim(uint32_t u32TrimSel,uint32_t u32TrimEnInt);
void SYS_DisableIRCTrim(void);
   

   

   







 


#line 11898 "..\\..\\Library\\Device\\Nuvoton\\Nano100Series\\Include\\Nano100Series.h"
#line 1 "..\\..\\Library\\StdDriver\\inc\\clk.h"
 








 











 



 



 


#line 40 "..\\..\\Library\\StdDriver\\inc\\clk.h"

 
#line 52 "..\\..\\Library\\StdDriver\\inc\\clk.h"


 
#line 61 "..\\..\\Library\\StdDriver\\inc\\clk.h"

 
#line 89 "..\\..\\Library\\StdDriver\\inc\\clk.h"

 
#line 97 "..\\..\\Library\\StdDriver\\inc\\clk.h"


 






 


































 












































 
#line 193 "..\\..\\Library\\StdDriver\\inc\\clk.h"

 



 



 














#line 231 "..\\..\\Library\\StdDriver\\inc\\clk.h"

 


 


 
#line 266 "..\\..\\Library\\StdDriver\\inc\\clk.h"


 
 
 
#line 281 "..\\..\\Library\\StdDriver\\inc\\clk.h"

#line 290 "..\\..\\Library\\StdDriver\\inc\\clk.h"
 
 
 
#line 299 "..\\..\\Library\\StdDriver\\inc\\clk.h"

#line 326 "..\\..\\Library\\StdDriver\\inc\\clk.h"
   




 
void CLK_DisableCKO(void);
void CLK_EnableCKO(uint32_t u32ClkSrc, uint32_t u32ClkDiv);
void CLK_PowerDown(void);
void CLK_Idle(void);
uint32_t CLK_GetHXTFreq(void);
uint32_t CLK_GetLXTFreq(void);
uint32_t CLK_GetHCLKFreq(void);
uint32_t CLK_GetCPUFreq(void);
uint32_t CLK_GetPLLClockFreq(void);
uint32_t CLK_SetCoreClock(uint32_t u32Hclk);
void CLK_SetHCLK(uint32_t u32ClkSrc, uint32_t u32ClkDiv);
void CLK_SetModuleClock(uint32_t u32ModuleIdx, uint32_t u32ClkSrc, uint32_t u32ClkDiv);
void CLK_EnableXtalRC(uint32_t u32ClkMask);
void CLK_DisableXtalRC(uint32_t u32ClkMask);
void CLK_EnableModuleClock(uint32_t u32ModuleIdx);
void CLK_DisableModuleClock(uint32_t u32ModuleIdx);
uint32_t CLK_EnablePLL(uint32_t u32PllClkSrc, uint32_t u32PllFreq);
void CLK_DisablePLL(void);
void CLK_SysTickDelay(uint32_t us);
void CLK_EnableSysTick(uint32_t u32ClkSrc, uint32_t u32Count);
void CLK_DisableSysTick(void);
uint32_t CLK_WaitClockReady(uint32_t u32ClkMask);

   

   

   







 
#line 11899 "..\\..\\Library\\Device\\Nuvoton\\Nano100Series\\Include\\Nano100Series.h"
#line 1 "..\\..\\Library\\StdDriver\\inc\\adc.h"
 








 











 



 



 

#line 76 "..\\..\\Library\\StdDriver\\inc\\adc.h"

   




 







 











 











 











 










 










 







 







 




















 
#line 195 "..\\..\\Library\\StdDriver\\inc\\adc.h"






 
















 
#line 228 "..\\..\\Library\\StdDriver\\inc\\adc.h"






 








 







 







 










 












 











 









 









 







 







 


void ADC_Open(ADC_T *adc,
              uint32_t u32InputMode,
              uint32_t u32OpMode,
              uint32_t u32ChMask);
void ADC_Close(ADC_T *adc);
void ADC_EnableHWTrigger(ADC_T *adc,
                         uint32_t u32Source,
                         uint32_t u32Param);
void ADC_DisableHWTrigger(ADC_T *adc);
void ADC_EnableTimerTrigger(ADC_T *adc,
                            uint32_t u32Source,
                            uint32_t u32PDMACnt);
void ADC_DisableTimerTrigger(ADC_T *adc);
void ADC_SetExtraSampleTime(ADC_T *adc,
                            uint32_t u32ChNum,
                            uint32_t u32SampleTime);
void ADC_EnableInt(ADC_T *adc, uint32_t u32Mask);
void ADC_DisableInt(ADC_T *adc, uint32_t u32Mask);



   

   

   







 
#line 11900 "..\\..\\Library\\Device\\Nuvoton\\Nano100Series\\Include\\Nano100Series.h"
#line 1 "..\\..\\Library\\StdDriver\\inc\\dac.h"









  











 



 




 
#line 38 "..\\..\\Library\\StdDriver\\inc\\dac.h"





   





 








 
#line 66 "..\\..\\Library\\StdDriver\\inc\\dac.h"







 







 











 

                                    









 








 
#line 121 "..\\..\\Library\\StdDriver\\inc\\dac.h"











 








 
#line 148 "..\\..\\Library\\StdDriver\\inc\\dac.h"







 
#line 162 "..\\..\\Library\\StdDriver\\inc\\dac.h"
                                   
void DAC_Open(DAC_T *dac, uint32_t u32Ch, uint32_t u32TrgSrc);
void DAC_Close(DAC_T *dac, uint32_t u32Ch);
int DAC_SetDelayTime(DAC_T *dac, uint32_t u32Delay);

   

   

   







 
#line 11901 "..\\..\\Library\\Device\\Nuvoton\\Nano100Series\\Include\\Nano100Series.h"
#line 1 "..\\..\\Library\\StdDriver\\inc\\fmc.h"
 









 










 



 




 


 
 
 









 
 
 
#line 56 "..\\..\\Library\\StdDriver\\inc\\fmc.h"





   




 

 
 
 






 







 







 







 







 







 







 







 







 







 







 







 


 
 
 

extern void FMC_Close(void);
extern int32_t FMC_Erase(uint32_t u32PageAddr);
extern int32_t FMC_GetBootSource(void);
extern void FMC_Open(void);
extern uint32_t FMC_Read(uint32_t u32Addr);
extern uint32_t FMC_ReadCID(void);
extern uint32_t FMC_ReadPID(void);
extern uint32_t FMC_ReadUCID(uint32_t u32Index);
extern uint32_t FMC_ReadUID(uint32_t u32Index);
extern uint32_t FMC_ReadDataFlashBaseAddr(void);
extern void FMC_SetVectorPageAddr(uint32_t u32PageAddr);
extern uint32_t FMC_GetVectorPageAddr(void);
extern void FMC_Write(uint32_t u32Addr, uint32_t u32Data);
extern int32_t FMC_ReadConfig(uint32_t *u32Config, uint32_t u32Count);
extern int32_t FMC_WriteConfig(uint32_t *u32Config, uint32_t u32Count);


   

   

   







 
#line 11902 "..\\..\\Library\\Device\\Nuvoton\\Nano100Series\\Include\\Nano100Series.h"
#line 1 "..\\..\\Library\\StdDriver\\inc\\ebi.h"
 









 










 



 




 


 
 
 




 



 
 
 
#line 54 "..\\..\\Library\\StdDriver\\inc\\ebi.h"

 
 
 
#line 65 "..\\..\\Library\\StdDriver\\inc\\ebi.h"


   




 

 
 
 






 








 







 








 







 








 


 
 
 

void EBI_Open(uint32_t u32Bank, uint32_t u32DataWidth, uint32_t u32TimingClass, uint32_t u32BusMode, uint32_t u32CSActiveLevel);
void EBI_Close(uint8_t u32Bank);
void EBI_SetBusTiming(uint32_t u32Bank, uint32_t u32TimingConfig, uint32_t u32MclkDiv);


   

   

   







 
#line 11903 "..\\..\\Library\\Device\\Nuvoton\\Nano100Series\\Include\\Nano100Series.h"
#line 1 "..\\..\\Library\\StdDriver\\inc\\gpio.h"
 








 











 



 



 


 
 
 




 
 
 






 
 
 



 
 
 






#line 80 "..\\..\\Library\\StdDriver\\inc\\gpio.h"














 
#line 112 "..\\..\\Library\\StdDriver\\inc\\gpio.h"

#line 129 "..\\..\\Library\\StdDriver\\inc\\gpio.h"

#line 146 "..\\..\\Library\\StdDriver\\inc\\gpio.h"

#line 163 "..\\..\\Library\\StdDriver\\inc\\gpio.h"

#line 180 "..\\..\\Library\\StdDriver\\inc\\gpio.h"

#line 187 "..\\..\\Library\\StdDriver\\inc\\gpio.h"

   



 










 











 











 











 











 











 











 












 



















 










 











 











 











 










 













 












 














 












 



void GPIO_SetMode(GPIO_T *gpio, uint32_t u32PinMask, uint32_t u32Mode);
void GPIO_EnableInt(GPIO_T *gpio, uint32_t u32Pin, uint32_t u32IntAttribs);
void GPIO_DisableInt(GPIO_T *gpio, uint32_t u32Pin);



   

   

   







 
#line 11904 "..\\..\\Library\\Device\\Nuvoton\\Nano100Series\\Include\\Nano100Series.h"
#line 1 "..\\..\\Library\\StdDriver\\inc\\i2c.h"
 








 











 



 



 









   




 







 







 







 
static __inline void I2C_STOP(I2C_T *i2c)
{
    i2c->CON |= ((0x1ul << (4)) | (0x1ul << (2)));
    while(i2c->CON & (0x1ul << (2)));
}






 
static __inline void I2C_WAIT_READY(I2C_T *i2c)
{
    while(!(i2c->INTSTS & (0x1ul << (0))));
    i2c->INTSTS |= (0x1ul << (0));
}






 








 







 









 







 









 







 


uint32_t I2C_Open(I2C_T *i2c, uint32_t u32BusClock);
void I2C_Close(I2C_T *i2c);
void I2C_ClearTimeoutFlag(I2C_T *i2c);
void I2C_Trigger(I2C_T *i2c, uint8_t u8Start, uint8_t u8Stop, uint8_t u8Si, uint8_t u8Ack);
void I2C_DisableInt(I2C_T *i2c);
void I2C_EnableInt(I2C_T *i2c);
uint32_t I2C_GetBusClockFreq(I2C_T *i2c);
uint32_t I2C_SetBusClockFreq(I2C_T *i2c, uint32_t u32BusClock);
uint32_t I2C_GetIntFlag(I2C_T *i2c);
void I2C_ClearIntFlag(I2C_T *i2c);
uint32_t I2C_GetStatus(I2C_T *i2c);
uint32_t I2C_GetData(I2C_T *i2c);
void I2C_SetData(I2C_T *i2c, uint8_t u8Data);
void I2C_SetSlaveAddr(I2C_T *i2c, uint8_t u8SlaveNo, uint8_t u8SlaveAddr, uint8_t u8GCMode);
void I2C_SetSlaveAddrMask(I2C_T *i2c, uint8_t u8SlaveNo, uint8_t u8SlaveAddrMask);
void I2C_EnableTimeout(I2C_T *i2c, uint8_t u8LongTimeout);
void I2C_DisableTimeout(I2C_T *i2c);
void I2C_EnableWakeup(I2C_T *i2c);
void I2C_DisableWakeup(I2C_T *i2c);

   

   

   







 
#line 11905 "..\\..\\Library\\Device\\Nuvoton\\Nano100Series\\Include\\Nano100Series.h"
#line 1 "..\\..\\Library\\StdDriver\\inc\\crc.h"
 








 











 



 



 

 
 
 





 
 
 





 
 
 





   



 









 










 










 










 










 










 










 



 
void CRC_Open(uint32_t u32Mode, uint32_t u32Attribute, uint32_t u32Seed, uint32_t u32DataLen);
void CRC_StartDMATransfer(uint32_t u32SrcAddr, uint32_t u32ByteCount);
uint32_t CRC_GetChecksum(void);


   

   

   







 
#line 11906 "..\\..\\Library\\Device\\Nuvoton\\Nano100Series\\Include\\Nano100Series.h"
#line 1 "..\\..\\Library\\StdDriver\\inc\\pdma.h"
 








 











 



 



 

 
 
 




 
 
 
#line 48 "..\\..\\Library\\StdDriver\\inc\\pdma.h"

 
 
 
#line 65 "..\\..\\Library\\StdDriver\\inc\\pdma.h"

#line 79 "..\\..\\Library\\StdDriver\\inc\\pdma.h"



   



 










 











 












 












 












 












 












 
#line 184 "..\\..\\Library\\StdDriver\\inc\\pdma.h"










 


void PDMA_Open(uint32_t u32Mask);
void PDMA_Close(void);
void PDMA_SetTransferCnt(uint32_t u32Ch, uint32_t u32Width, uint32_t u32TransCount);
void PDMA_SetTransferAddr(uint32_t u32Ch, uint32_t u32SrcAddr, uint32_t u32SrcCtrl, uint32_t u32DstAddr, uint32_t u32DstCtrl);
void PDMA_SetTransferMode(uint32_t u32Ch, uint32_t u32Periphral, uint32_t u32ScatterEn, uint32_t u32DescAddr);
void PDMA_SetTimeOut(uint32_t u32Ch, uint32_t u32OnOff, uint32_t u32TimeOutCnt);
void PDMA_Trigger(uint32_t u32Ch);
void PDMA_EnableInt(uint32_t u32Ch, uint32_t u32Mask);
void PDMA_DisableInt(uint32_t u32Ch, uint32_t u32Mask);

   

   

   







 
#line 11907 "..\\..\\Library\\Device\\Nuvoton\\Nano100Series\\Include\\Nano100Series.h"
#line 1 "..\\..\\Library\\StdDriver\\inc\\pwm.h"
 








 











 



 



 
#line 58 "..\\..\\Library\\StdDriver\\inc\\pwm.h"

   




 








 
#line 84 "..\\..\\Library\\StdDriver\\inc\\pwm.h"








 








 











 















 











 















 






uint32_t PWM_ConfigOutputChannel(PWM_T *pwm,
                                 uint32_t u32ChannelNum,
                                 uint32_t u32Frequency,
                                 uint32_t u32DutyCycle);
uint32_t PWM_ConfigCaptureChannel (PWM_T *pwm,
                                   uint32_t u32ChannelNum,
                                   uint32_t u32UnitTimeNsec,
                                   uint32_t u32CaptureEdge);
void PWM_Start(PWM_T *pwm, uint32_t u32ChannelMask);
void PWM_Stop(PWM_T *pwm, uint32_t u32ChannelMask);
void PWM_ForceStop(PWM_T *pwm, uint32_t u32ChannelMask);
void PWM_EnableCapture(PWM_T *pwm, uint32_t u32ChannelMask);
void PWM_DisableCapture(PWM_T *pwm, uint32_t u32ChannelMask);
void PWM_EnableOutput(PWM_T *pwm, uint32_t u32ChannelMask);
void PWM_DisableOutput(PWM_T *pwm, uint32_t u32ChannelMask);
void PWM_EnableDeadZone(PWM_T *pwm, uint32_t u32ChannelNum, uint32_t u32Duration);
void PWM_DisableDeadZone(PWM_T *pwm, uint32_t u32ChannelNum);
void PWM_EnableCaptureInt(PWM_T *pwm, uint32_t u32ChannelNum, uint32_t u32Edge);
void PWM_DisableCaptureInt(PWM_T *pwm, uint32_t u32ChannelNum, uint32_t u32Edge);
void PWM_ClearCaptureIntFlag(PWM_T *pwm, uint32_t u32ChannelNum, uint32_t u32Edge);
uint32_t PWM_GetCaptureIntFlag(PWM_T *pwm, uint32_t u32ChannelNum);
void PWM_EnablePeriodInt(PWM_T *pwm, uint32_t u32ChannelNum,  uint32_t u32IntPeriodType);
void PWM_DisablePeriodInt(PWM_T *pwm, uint32_t u32ChannelNum);
void PWM_ClearPeriodIntFlag(PWM_T *pwm, uint32_t u32ChannelNum);
uint32_t PWM_GetPeriodIntFlag(PWM_T *pwm, uint32_t u32ChannelNum);
void PWM_EnablePDMA(PWM_T *pwm, uint32_t u32ChannelNum, uint32_t u32RisingFirst, uint32_t u32Mode);
void PWM_DisablePDMA(PWM_T *pwm, uint32_t u32ChannelNum);

   

   

   







 
#line 11908 "..\\..\\Library\\Device\\Nuvoton\\Nano100Series\\Include\\Nano100Series.h"
#line 1 "..\\..\\Library\\StdDriver\\inc\\rtc.h"
 








 











 



 




 
















#line 56 "..\\..\\Library\\StdDriver\\inc\\rtc.h"

#line 64 "..\\..\\Library\\StdDriver\\inc\\rtc.h"






   




 



 
typedef struct {
    uint32_t u32Year;           
    uint32_t u32Month;          
    uint32_t u32Day;            
    uint32_t u32DayOfWeek;      
    uint32_t u32Hour;           
    uint32_t u32Minute;         
    uint32_t u32Second;         
    uint32_t u32TimeScale;      
    uint32_t u32AmPm;           
} S_RTC_TIME_DATA_T;

   




 









 










 










 









 









 









 









 









 










 









 









 



void RTC_Open(S_RTC_TIME_DATA_T *sPt);
void RTC_Close(void);
void RTC_32KCalibration(int32_t i32FrequencyX100);
void RTC_SetTickPeriod(uint32_t u32TickSelection);
void RTC_EnableInt(uint32_t u32IntFlagMask);
void RTC_DisableInt(uint32_t u32IntFlagMask);
uint32_t RTC_GetDayOfWeek(void);
void RTC_DisableTamperDetection(void);
void RTC_EnableTamperDetection(uint32_t u32PinCondition);
void RTC_SetAlarmTime(uint32_t u32Hour, uint32_t u32Minute, uint32_t u32Second, uint32_t u32TimeMode, uint32_t u32AmPm);
void RTC_SetAlarmDate(uint32_t u32Year, uint32_t u32Month, uint32_t u32Day);
void RTC_SetTime(uint32_t u32Hour, uint32_t u32Minute, uint32_t u32Second, uint32_t u32TimeMode, uint32_t u32AmPm);
void RTC_SetDate(uint32_t u32Year, uint32_t u32Month, uint32_t u32Day, uint32_t u32DayOfWeek);
void RTC_SetAlarmDateAndTime(S_RTC_TIME_DATA_T *sPt);
void RTC_SetDateAndTime(S_RTC_TIME_DATA_T *sPt);
void RTC_GetAlarmDateAndTime(S_RTC_TIME_DATA_T *sPt);
void RTC_GetDateAndTime(S_RTC_TIME_DATA_T *sPt);



   


   

   









 



#line 11909 "..\\..\\Library\\Device\\Nuvoton\\Nano100Series\\Include\\Nano100Series.h"
#line 1 "..\\..\\Library\\StdDriver\\inc\\sc.h"
 








 











 



 



 
#line 37 "..\\..\\Library\\StdDriver\\inc\\sc.h"

#line 48 "..\\..\\Library\\StdDriver\\inc\\sc.h"


   




 


















 



















 








 
#line 117 "..\\..\\Library\\StdDriver\\inc\\sc.h"








 
#line 139 "..\\..\\Library\\StdDriver\\inc\\sc.h"







 
#line 160 "..\\..\\Library\\StdDriver\\inc\\sc.h"







 
#line 181 "..\\..\\Library\\StdDriver\\inc\\sc.h"






 








 









 







 
static __inline void SC_SetTxRetry(SC_T *sc, uint32_t u32Count)
{
    
    sc->CTL &= ~((0x7ul << (20)) | (0x1ul << (23)));

    if(u32Count != 0) {
        sc->CTL |= ((u32Count - 1) << (20)) | (0x1ul << (23));
    }
}






 
static __inline void  SC_SetRxRetry(SC_T *sc, uint32_t u32Count)
{
    
    sc->CTL &= ~((0x7ul << (16)) | (0x1ul << (19)));

    if(u32Count != 0) {
        sc->CTL |= ((u32Count - 1) << (16)) | (0x1ul << (19));
    }
}


uint32_t SC_IsCardInserted(SC_T *sc);
void SC_ClearFIFO(SC_T *sc);
void SC_Close(SC_T *sc);
void SC_Open(SC_T *sc, uint32_t u32CardDet, uint32_t u32PWR);
void SC_ResetReader(SC_T *sc);
void SC_SetBlockGuardTime(SC_T *sc, uint32_t u32BGT);
void SC_SetCharGuardTime(SC_T *sc, uint32_t u32CGT);
void SC_StopAllTimer(SC_T *sc);
void SC_StartTimer(SC_T *sc, uint32_t u32TimerNum, uint32_t u32Mode, uint32_t u32ETUCount);
void SC_StopTimer(SC_T *sc, uint32_t u32TimerNum);


   

   

   







 
#line 11910 "..\\..\\Library\\Device\\Nuvoton\\Nano100Series\\Include\\Nano100Series.h"
#line 1 "..\\..\\Library\\StdDriver\\inc\\scuart.h"
 








 











 



 



 













   




 

 






 









 









 








 









 









 



 






 









 










 










 









 


 











 












 














 











 










 











 


void SCUART_Close(SC_T* sc);
uint32_t SCUART_Open(SC_T* sc, uint32_t u32baudrate);
uint32_t SCUART_Read(SC_T* sc, uint8_t *pu8RxBuf, uint32_t u32ReadBytes);
uint32_t SCUART_SetLineConfig(SC_T* sc, uint32_t u32Baudrate, uint32_t u32DataWidth, uint32_t u32Parity, uint32_t  u32StopBits);
void SCUART_SetTimeoutCnt(SC_T* sc, uint32_t u32TOC);
void SCUART_Write(SC_T* sc,uint8_t *pu8TxBuf, uint32_t u32WriteBytes);

   

   

   







 
#line 11911 "..\\..\\Library\\Device\\Nuvoton\\Nano100Series\\Include\\Nano100Series.h"
#line 1 "..\\..\\Library\\StdDriver\\inc\\spi.h"
 








 











 



 




 

















#line 55 "..\\..\\Library\\StdDriver\\inc\\spi.h"


   




 






 







 







 







 







 







 









 









 









 







 






 








 








 








 








 








 








 










 







 







 








 







 







 








 
static __inline void SPI_SET_DATA_WIDTH(SPI_T *spi, uint32_t u32Width)
{
    if(u32Width == 32)
        u32Width = 0;

    spi->CTL = (spi->CTL & ~(0x1ful << (3))) | (u32Width << (3));
}








 







 







 







 







 







 







 







 







 







 


uint32_t SPI_Open(SPI_T *spi, uint32_t u32MasterSlave, uint32_t u32SPIMode, uint32_t u32DataWidth, uint32_t u32BusClock);
void SPI_Close(SPI_T *spi);
void SPI_ClearRxFIFO(SPI_T *spi);
void SPI_ClearTxFIFO(SPI_T *spi);
void SPI_DisableAutoSS(SPI_T *spi);
void SPI_EnableAutoSS(SPI_T *spi, uint32_t u32SSPinMask, uint32_t u32ActiveLevel);
uint32_t SPI_SetBusClock(SPI_T *spi, uint32_t u32BusClock);
void SPI_EnableFIFO(SPI_T *spi, uint32_t u32TxThreshold, uint32_t u32RxThreshold);
void SPI_DisableFIFO(SPI_T *spi);
uint32_t SPI_GetBusClock(SPI_T *spi);
void SPI_EnableInt(SPI_T *spi, uint32_t u32Mask);
void SPI_DisableInt(SPI_T *spi, uint32_t u32Mask);
void SPI_EnableWakeup(SPI_T *spi);
void SPI_DisableWakeup(SPI_T *spi);
   

   

   







 
#line 11912 "..\\..\\Library\\Device\\Nuvoton\\Nano100Series\\Include\\Nano100Series.h"
#line 1 "..\\..\\Library\\StdDriver\\inc\\timer.h"
 








 











 



 



 





















   




 







 









 








 







 
static __inline void TIMER_Start(TIMER_T *timer)
{
    timer->CTL |= (0x1ul << (0));
}





 
static __inline void TIMER_Stop(TIMER_T *timer)
{
    timer->CTL &= ~(0x1ul << (0));
}






 
static __inline void TIMER_EnableWakeup(TIMER_T *timer)
{
    timer->CTL |= (0x1ul << (2));
}





 
static __inline void TIMER_DisableWakeup(TIMER_T *timer)
{
    timer->CTL &= ~(0x1ul << (2));
}






 
static __inline void TIMER_EnableCaptureDebounce(TIMER_T *timer)
{
    timer->CTL |= (0x1ul << (22));
}





 
static __inline void TIMER_DisableCaptureDebounce(TIMER_T *timer)
{
    timer->CTL &= ~(0x1ul << (22));
}






 
static __inline void TIMER_EnableEventCounterDebounce(TIMER_T *timer)
{
    timer->CTL |= (0x1ul << (14));
}





 
static __inline void TIMER_DisableEventCounterDebounce(TIMER_T *timer)
{
    timer->CTL &= ~(0x1ul << (14));
}





 
static __inline void TIMER_EnableInt(TIMER_T *timer)
{
    timer->IER |= (0x1ul << (0));
}





 
static __inline void TIMER_DisableInt(TIMER_T *timer)
{
    timer->IER &= ~(0x1ul << (0));
}





 
static __inline void TIMER_EnableCaptureInt(TIMER_T *timer)
{
    timer->IER |= (0x1ul << (1));
}





 
static __inline void TIMER_DisableCaptureInt(TIMER_T *timer)
{
    timer->IER &= ~(0x1ul << (1));
}







 
static __inline uint32_t TIMER_GetIntFlag(TIMER_T *timer)
{
    return(timer->ISR & (0x1ul << (0)) ? 1 : 0);
}





 
static __inline void TIMER_ClearIntFlag(TIMER_T *timer)
{
    timer->ISR = (0x1ul << (0));
}







 
static __inline uint32_t TIMER_GetCaptureIntFlag(TIMER_T *timer)
{
    return(timer->ISR & (0x1ul << (1)) ? 1 : 0);
}





 
static __inline void TIMER_ClearCaptureIntFlag(TIMER_T *timer)
{
    timer->ISR = (0x1ul << (1));
}







 
static __inline uint32_t TIMER_GetWakeupFlag(TIMER_T *timer)
{
    return (timer->ISR & (0x1ul << (4)) ? 1 : 0);
}





 
static __inline void TIMER_ClearWakeupFlag(TIMER_T *timer)
{
    timer->ISR = (0x1ul << (4));
}





 
static __inline uint32_t TIMER_GetCaptureData(TIMER_T *timer)
{
    return timer->TCAP;
}





 
static __inline uint32_t TIMER_GetCounter(TIMER_T *timer)
{
    return timer->DR;
}

uint32_t TIMER_Open(TIMER_T *timer, uint32_t u32Mode, uint32_t u32Freq);
void TIMER_Close(TIMER_T *timer);
void TIMER_Delay(TIMER_T *timer, uint32_t u32Usec);
void TIMER_EnableCapture(TIMER_T *timer, uint32_t u32CapMode, uint32_t u32Edge);
void TIMER_DisableCapture(TIMER_T *timer);
void TIMER_EnableEventCounter(TIMER_T *timer, uint32_t u32Edge);
void TIMER_DisableEventCounter(TIMER_T *timer);
uint32_t TIMER_GetModuleClock(TIMER_T *timer);
void TIMER_EnableFreqCounter(TIMER_T *timer,
                             uint32_t u32DropCount,
                             uint32_t u32Timeout,
                             uint32_t u32EnableInt);
void TIMER_DisableFreqCounter(TIMER_T *timer);
void TIMER_SetTriggerSource(TIMER_T *timer, uint32_t u32Src);
void TIMER_SetTriggerTarget(TIMER_T *timer, uint32_t u32Mask);

   

   

   







 
#line 11913 "..\\..\\Library\\Device\\Nuvoton\\Nano100Series\\Include\\Nano100Series.h"
#line 1 "..\\..\\Library\\StdDriver\\inc\\uart.h"
 








 












 



 



 


 
 
 


























 
 
 



 
 
 






   




 








 









 











 









 










 








 









 









 








 









 










 











 











 









 









 



















 


















 





















 








 
__inline void UART_CLEAR_RTS(UART_T* uart)
{
    uart->MCSR |= (0x1ul << (0));
}






 
__inline void UART_SET_RTS(UART_T* uart)
{
    uart->MCSR &= ~(0x1ul << (0));
}






 








 



void UART_ClearIntFlag(UART_T* uart , uint32_t u32InterruptFlag);
void UART_Close(UART_T* uart );
void UART_DisableFlowCtrl(UART_T* uart );
void UART_DisableInt(UART_T*  uart, uint32_t u32InterruptFlag );
void UART_EnableFlowCtrl(UART_T* uart );
void UART_EnableInt(UART_T*  uart, uint32_t u32InterruptFlag );
void UART_Open(UART_T* uart, uint32_t u32baudrate);
uint32_t UART_Read(UART_T* uart, uint8_t *pu8RxBuf, uint32_t u32ReadBytes);
void UART_SetLine_Config(UART_T* uart, uint32_t u32baudrate, uint32_t u32data_width, uint32_t u32parity, uint32_t  u32stop_bits);
void UART_SetTimeoutCnt(UART_T* uart, uint32_t u32TOC);
void UART_SelectIrDAMode(UART_T* uart, uint32_t u32Buadrate, uint32_t u32Direction);
void UART_SelectRS485Mode(UART_T* uart, uint32_t u32Mode, uint32_t u32Addr);
void UART_SelectLINMode(UART_T* uart, uint32_t u32Mode, uint32_t u32BreakLength);
uint32_t UART_Write(UART_T* uart,uint8_t *pu8TxBuf, uint32_t u32WriteBytes);


   

   

   







 








#line 11914 "..\\..\\Library\\Device\\Nuvoton\\Nano100Series\\Include\\Nano100Series.h"
#line 1 "..\\..\\Library\\StdDriver\\inc\\usbd.h"








 






 



 



 
typedef struct s_usbd_info {
    uint8_t *gu8DevDesc;                 
    uint8_t *gu8ConfigDesc;              
    uint8_t **gu8StringDesc;             
    uint8_t **gu8HidReportDesc;          
    uint32_t *gu32HidReportSize;         
    uint32_t *gu32ConfigHidDescIdx; 	 	
} S_USBD_INFO_T;


extern S_USBD_INFO_T gsInfo;


   



 




#line 55 "..\\..\\Library\\StdDriver\\inc\\usbd.h"


extern volatile uint32_t g_usbd_UsbConfig;

 




 
#line 76 "..\\..\\Library\\StdDriver\\inc\\usbd.h"

 
#line 85 "..\\..\\Library\\StdDriver\\inc\\usbd.h"

 



 
#line 97 "..\\..\\Library\\StdDriver\\inc\\usbd.h"

 







 


















#line 138 "..\\..\\Library\\StdDriver\\inc\\usbd.h"















   




 










 












 






 






 






 






 






 






 






 






 






 






 






 






 






 






 






 






 






 







 






 







 







 






 











 










 












 















 
static __inline void USBD_MemCopy(uint8_t *dest, uint8_t *src, int32_t size)
{
    while (size--) *dest++ = *src++;
}









 
static __inline void USBD_SetStall(uint8_t epnum)
{
    uint32_t u32CfgAddr;
    uint32_t u32Cfg;
    int i;

    for (i=0; i<8; i++) {
        u32CfgAddr = (uint32_t)(i << 4) + (uint32_t)&((USBD_T *) (((uint32_t)0x40000000) + 0x60000))->EP[0].CFG;  
        u32Cfg = *((volatile uint32_t *) (u32CfgAddr));

        if((u32Cfg & 0xf) == epnum) {
            *((volatile uint32_t *) (u32CfgAddr)) = (u32Cfg | (0x1ul << (9)));
            break;
        }
    }
}








 
static __inline void USBD_ClearStall(uint8_t epnum)
{
    uint32_t u32CfgAddr;
    uint32_t u32Cfg;
    int i;

    for (i=0; i<8; i++) {
        u32CfgAddr = (uint32_t)(i << 4) + (uint32_t)&((USBD_T *) (((uint32_t)0x40000000) + 0x60000))->EP[0].CFG;  
        u32Cfg = *((volatile uint32_t *) (u32CfgAddr));

        if((u32Cfg & 0xf) == epnum) {
            *((volatile uint32_t *) (u32CfgAddr)) = (u32Cfg & ~(0x1ul << (9)));
            break;
        }
    }
}









 
static __inline uint32_t USBD_GetStall(uint8_t epnum)
{
    uint32_t u32CfgAddr;
    uint32_t u32Cfg;
    int i;

    for (i=0; i<8; i++) {
        u32CfgAddr = (uint32_t)(i << 4) + (uint32_t)&((USBD_T *) (((uint32_t)0x40000000) + 0x60000))->EP[0].CFG;  
        u32Cfg = *((volatile uint32_t *) (u32CfgAddr));

        if((u32Cfg & 0xf) == epnum)
            break;
    }
    return (u32Cfg & (0x1ul << (9)));
}


 
extern volatile uint8_t g_usbd_RemoteWakeupEn;

typedef void (*VENDOR_REQ)(void);  

typedef void (*CLASS_REQ)(void);  

typedef void (*SET_INTERFACE_REQ)(uint32_t u32AltInterface);  

 
void USBD_Open(S_USBD_INFO_T *param, CLASS_REQ pfnClassReq, SET_INTERFACE_REQ pfnSetInterface);
void USBD_Start(void);
void USBD_GetSetupPacket(uint8_t *buf);
void USBD_ProcessSetupPacket(void);
void USBD_StandardRequest(void);
void USBD_PrepareCtrlIn(uint8_t *pu8Buf, uint32_t u32Size);
void USBD_CtrlIn(void);
void USBD_PrepareCtrlOut(uint8_t *pu8Buf, uint32_t u32Size);
void USBD_CtrlOut(void);
void USBD_SwReset(void);
void USBD_SetVendorRequest(VENDOR_REQ pfnVendorReq);
void USBD_LockEpStall(uint32_t u32EpBitmap);


   

   

   




 
#line 11915 "..\\..\\Library\\Device\\Nuvoton\\Nano100Series\\Include\\Nano100Series.h"
#line 1 "..\\..\\Library\\StdDriver\\inc\\wdt.h"
 








 











 



 



 
#line 39 "..\\..\\Library\\StdDriver\\inc\\wdt.h"






   




 






 







 







 








 








 








 







 






 
static __inline void WDT_Close(void)
{
    ((WDT_T *) (((uint32_t)0x40000000) + 0x04000))->CTL = 0;
    return;
}





 
static __inline void WDT_EnableInt(void)
{
    ((WDT_T *) (((uint32_t)0x40000000) + 0x04000))->IER = (0x1ul << (0));
    return;
}





 
static __inline void WDT_DisableInt(void)
{
    ((WDT_T *) (((uint32_t)0x40000000) + 0x04000))->IER = 0;
    return;
}

void  WDT_Open(uint32_t u32TimeoutInterval,
               uint32_t u32ResetDelay,
               uint32_t u32EnableReset,
               uint32_t u32EnableWakeup);

   

   

   







 
#line 11916 "..\\..\\Library\\Device\\Nuvoton\\Nano100Series\\Include\\Nano100Series.h"
#line 1 "..\\..\\Library\\StdDriver\\inc\\wwdt.h"
 








 











 



 



 
#line 47 "..\\..\\Library\\StdDriver\\inc\\wwdt.h"


   




 






 







 








 








 







 










 



void WWDT_Open(uint32_t u32PreScale, uint32_t u32CmpValue, uint32_t u32EnableInt);


   

   

   







 
#line 11917 "..\\..\\Library\\Device\\Nuvoton\\Nano100Series\\Include\\Nano100Series.h"
#line 1 "..\\..\\Library\\StdDriver\\inc\\i2s.h"
 








 










 



 



 





 



 



 


 



 
#line 59 "..\\..\\Library\\StdDriver\\inc\\i2s.h"

#line 68 "..\\..\\Library\\StdDriver\\inc\\i2s.h"

 



 



   



 








 
static __inline void I2S_ENABLE_TX_ZCD(I2S_T *i2s, uint32_t u32ChMask)
{
    if(u32ChMask == 0)
        i2s->CTRL |= (0x1ul << (16));
    else
        i2s->CTRL |= (0x1ul << (17));
}









 
static __inline void I2S_DISABLE_TX_ZCD(I2S_T *i2s, uint32_t u32ChMask)
{
    if(u32ChMask == 0)
        i2s->CTRL &= ~(0x1ul << (16));
    else
        i2s->CTRL &= ~(0x1ul << (17));
}






 







 







 







 







 







 







 







 







 







 







 







 










 








 







 








 








 







 







 


uint32_t I2S_Open(I2S_T *i2s, uint32_t u32MasterSlave, uint32_t u32SampleRate, uint32_t u32WordWidth, uint32_t u32Channels, uint32_t u32DataFormat, uint32_t u32AudioInterface);
void I2S_Close(I2S_T *i2s);
void I2S_EnableInt(I2S_T *i2s, uint32_t u32Mask);
void I2S_DisableInt(I2S_T *i2s, uint32_t u32Mask);
uint32_t I2S_EnableMCLK(I2S_T *i2s, uint32_t u32BusClock);
void I2S_DisableMCLK(I2S_T *i2s);
void I2S_SetFIFO(I2S_T *i2s, uint32_t u32TxThreshold, uint32_t u32RxThreshold);

   


   

   







 

#line 11918 "..\\..\\Library\\Device\\Nuvoton\\Nano100Series\\Include\\Nano100Series.h"
#line 1 "..\\..\\Library\\StdDriver\\inc\\lcd.h"
 








 








#line 20 "..\\..\\Library\\StdDriver\\inc\\lcd.h"





 



 




 


 
 
 



#line 51 "..\\..\\Library\\StdDriver\\inc\\lcd.h"

#line 58 "..\\..\\Library\\StdDriver\\inc\\lcd.h"





#line 71 "..\\..\\Library\\StdDriver\\inc\\lcd.h"

#line 80 "..\\..\\Library\\StdDriver\\inc\\lcd.h"












   




 
typedef enum {
    LCD_C_TYPE = 0,           
    LCD_EXTERNAL_R_TYPE = 1,  
    LCD_INTERNAL_R_TYPE = 2,  
    LCD_EXTERNAL_C_TYPE = 3   
} LCD_PanelType;

   




 







 








 








 








 








 








 


uint32_t LCD_EnableFrameCounter(uint32_t u32Count);
void LCD_DisableFrameCounter(void);
uint32_t LCD_EnableBlink(uint32_t u32ms);
void LCD_DisableBlink(void);
void LCD_EnableInt(uint32_t IntSrc);
void LCD_DisableInt(uint32_t IntSrc);
uint32_t LCD_Open(uint32_t u32DrivingType, uint32_t u32ComNum, uint32_t u32BiasLevel, uint32_t u32FramerateDiv, uint32_t u32DrivingVol);
void LCD_SetPixel(uint32_t u32Com, uint32_t u32Seg, uint32_t u32OnFlag);
void LCD_SetAllPixels(uint32_t u32OnOff);
void LCD_Close(void);








 
static __inline void LCD_EnableDisplay(void)
{
     
    ((LCD_T *) (((uint32_t)0x40000000) + 0xB0000))->CTL |= (0x1ul << (0));
}








 
static __inline void LCD_DisableDisplay(void)
{
     
    ((LCD_T *) (((uint32_t)0x40000000) + 0xB0000))->CTL &= ~(0x1ul << (0));
}



   


   

   










 


#line 11919 "..\\..\\Library\\Device\\Nuvoton\\Nano100Series\\Include\\Nano100Series.h"



 

#line 2 "Thread.c"
#line 1 "C:\\Keil_v5\\ARM\\PACK\\ARM\\CMSIS\\5.2.0\\CMSIS\\RTOS\\RTX\\INC\\cmsis_os.h"









































 












#line 63 "C:\\Keil_v5\\ARM\\PACK\\ARM\\CMSIS\\5.2.0\\CMSIS\\RTOS\\RTX\\INC\\cmsis_os.h"







#line 81 "C:\\Keil_v5\\ARM\\PACK\\ARM\\CMSIS\\5.2.0\\CMSIS\\RTOS\\RTX\\INC\\cmsis_os.h"

#line 83 "C:\\Keil_v5\\ARM\\PACK\\ARM\\CMSIS\\5.2.0\\CMSIS\\RTOS\\RTX\\INC\\cmsis_os.h"
#line 1 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stddef.h"
 






 

 
 
 





 





#line 34 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stddef.h"




  typedef signed int ptrdiff_t;



  



    typedef unsigned int size_t;    
#line 57 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stddef.h"



   



      typedef unsigned short wchar_t;  
#line 82 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stddef.h"



    




   




  typedef long double max_align_t;









#line 114 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stddef.h"



 

#line 84 "C:\\Keil_v5\\ARM\\PACK\\ARM\\CMSIS\\5.2.0\\CMSIS\\RTOS\\RTX\\INC\\cmsis_os.h"










typedef enum  {
  osPriorityIdle          = -3,          
  osPriorityLow           = -2,          
  osPriorityBelowNormal   = -1,          
  osPriorityNormal        =  0,          
  osPriorityAboveNormal   = +1,          
  osPriorityHigh          = +2,          
  osPriorityRealtime      = +3,          
  osPriorityError         =  0x84,       
  os_priority_reserved    =  0x7FFFFFFF  
} osPriority;





typedef enum  {
  osOK                    =     0,       
  osEventSignal           =  0x08,       
  osEventMessage          =  0x10,       
  osEventMail             =  0x20,       
  osEventTimeout          =  0x40,       
  osErrorParameter        =  0x80,       
  osErrorResource         =  0x81,       
  osErrorTimeoutResource  =  0xC1,       
  osErrorISR              =  0x82,       
  osErrorISRRecursive     =  0x83,       
  osErrorPriority         =  0x84,       
  osErrorNoMemory         =  0x85,       
  osErrorValue            =  0x86,       
  osErrorOS               =  0xFF,       
  os_status_reserved      =  0x7FFFFFFF  
} osStatus;



typedef enum  {
  osTimerOnce             =     0,       
  osTimerPeriodic         =     1        
} os_timer_type;


typedef void (*os_pthread) (void const *argument);


typedef void (*os_ptimer) (void const *argument);




typedef struct os_thread_cb *osThreadId;


typedef struct os_timer_cb *osTimerId;


typedef struct os_mutex_cb *osMutexId;


typedef struct os_semaphore_cb *osSemaphoreId;


typedef struct os_pool_cb *osPoolId;


typedef struct os_messageQ_cb *osMessageQId;


typedef struct os_mailQ_cb *osMailQId;



typedef struct os_thread_def  {
  os_pthread               pthread;    
  osPriority             tpriority;    
  uint32_t               instances;    
  uint32_t               stacksize;    
} osThreadDef_t;


typedef struct os_timer_def  {
  os_ptimer                 ptimer;    
  void                      *timer;    
} osTimerDef_t;


typedef struct os_mutex_def  {
  void                      *mutex;    
} osMutexDef_t;


typedef struct os_semaphore_def  {
  void                  *semaphore;    
} osSemaphoreDef_t;


typedef struct os_pool_def  {
  uint32_t                 pool_sz;    
  uint32_t                 item_sz;    
  void                       *pool;    
} osPoolDef_t;


typedef struct os_messageQ_def  {
  uint32_t                queue_sz;    
  void                       *pool;    
} osMessageQDef_t;


typedef struct os_mailQ_def  {
  uint32_t                queue_sz;    
  uint32_t                 item_sz;    
  void                       *pool;    
} osMailQDef_t;


typedef struct  {
  osStatus                 status;     
  union  {
    uint32_t                    v;     
    void                       *p;     
    int32_t               signals;     
  } value;                             
  union  {
    osMailQId             mail_id;     
    osMessageQId       message_id;     
  } def;                               
} osEvent;






osStatus osKernelInitialize (void);



osStatus osKernelStart (void);



int32_t osKernelRunning(void);




extern uint32_t const os_tickfreq;
extern uint16_t const os_tickus_i;
extern uint16_t const os_tickus_f;




uint32_t osKernelSysTick (void);










 












#line 280 "C:\\Keil_v5\\ARM\\PACK\\ARM\\CMSIS\\5.2.0\\CMSIS\\RTOS\\RTX\\INC\\cmsis_os.h"











osThreadId osThreadCreate (const osThreadDef_t *thread_def, void *argument);



osThreadId osThreadGetId (void);




osStatus osThreadTerminate (osThreadId thread_id);



osStatus osThreadYield (void);





osStatus osThreadSetPriority (osThreadId thread_id, osPriority priority);




osPriority osThreadGetPriority (osThreadId thread_id);







osStatus osDelay (uint32_t millisec);

#line 333 "C:\\Keil_v5\\ARM\\PACK\\ARM\\CMSIS\\5.2.0\\CMSIS\\RTOS\\RTX\\INC\\cmsis_os.h"






#line 348 "C:\\Keil_v5\\ARM\\PACK\\ARM\\CMSIS\\5.2.0\\CMSIS\\RTOS\\RTX\\INC\\cmsis_os.h"











osTimerId osTimerCreate (const osTimerDef_t *timer_def, os_timer_type type, void *argument);





osStatus osTimerStart (osTimerId timer_id, uint32_t millisec);




osStatus osTimerStop (osTimerId timer_id);




osStatus osTimerDelete (osTimerId timer_id);








int32_t osSignalSet (osThreadId thread_id, int32_t signals);





int32_t osSignalClear (osThreadId thread_id, int32_t signals);









__value_in_regs osEvent osSignalWait (int32_t signals, uint32_t millisec);







#line 416 "C:\\Keil_v5\\ARM\\PACK\\ARM\\CMSIS\\5.2.0\\CMSIS\\RTOS\\RTX\\INC\\cmsis_os.h"









osMutexId osMutexCreate (const osMutexDef_t *mutex_def);





osStatus osMutexWait (osMutexId mutex_id, uint32_t millisec);




osStatus osMutexRelease (osMutexId mutex_id);




osStatus osMutexDelete (osMutexId mutex_id);








#line 458 "C:\\Keil_v5\\ARM\\PACK\\ARM\\CMSIS\\5.2.0\\CMSIS\\RTOS\\RTX\\INC\\cmsis_os.h"










osSemaphoreId osSemaphoreCreate (const osSemaphoreDef_t *semaphore_def, int32_t count);





int32_t osSemaphoreWait (osSemaphoreId semaphore_id, uint32_t millisec);




osStatus osSemaphoreRelease (osSemaphoreId semaphore_id);




osStatus osSemaphoreDelete (osSemaphoreId semaphore_id);












#line 506 "C:\\Keil_v5\\ARM\\PACK\\ARM\\CMSIS\\5.2.0\\CMSIS\\RTOS\\RTX\\INC\\cmsis_os.h"









osPoolId osPoolCreate (const osPoolDef_t *pool_def);




void *osPoolAlloc (osPoolId pool_id);




void *osPoolCAlloc (osPoolId pool_id);





osStatus osPoolFree (osPoolId pool_id, void *block);












#line 553 "C:\\Keil_v5\\ARM\\PACK\\ARM\\CMSIS\\5.2.0\\CMSIS\\RTOS\\RTX\\INC\\cmsis_os.h"










osMessageQId osMessageCreate (const osMessageQDef_t *queue_def, osThreadId thread_id);






osStatus osMessagePut (osMessageQId queue_id, uint32_t info, uint32_t millisec);









__value_in_regs osEvent osMessageGet (osMessageQId queue_id, uint32_t millisec);













#line 605 "C:\\Keil_v5\\ARM\\PACK\\ARM\\CMSIS\\5.2.0\\CMSIS\\RTOS\\RTX\\INC\\cmsis_os.h"










osMailQId osMailCreate (const osMailQDef_t *queue_def, osThreadId thread_id);





void *osMailAlloc (osMailQId queue_id, uint32_t millisec);





void *osMailCAlloc (osMailQId queue_id, uint32_t millisec);





osStatus osMailPut (osMailQId queue_id, void *mail);









__value_in_regs osEvent osMailGet (osMailQId queue_id, uint32_t millisec);






osStatus osMailFree (osMailQId queue_id, void *mail);








uint32_t os_suspend (void);



void os_resume (uint32_t sleep_time);


__declspec(noreturn) void os_idle_demon (void);



__declspec(noreturn) void os_error (uint32_t error_code);






#line 3 "Thread.c"
#line 1 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\string.h"
 
 
 
 




 








 












#line 38 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\string.h"


  



    typedef unsigned int size_t;    
#line 54 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\string.h"




extern __declspec(__nothrow) void *memcpy(void * __restrict  ,
                    const void * __restrict  , size_t  ) __attribute__((__nonnull__(1,2)));
   




 
extern __declspec(__nothrow) void *memmove(void *  ,
                    const void *  , size_t  ) __attribute__((__nonnull__(1,2)));
   







 
extern __declspec(__nothrow) char *strcpy(char * __restrict  , const char * __restrict  ) __attribute__((__nonnull__(1,2)));
   




 
extern __declspec(__nothrow) char *strncpy(char * __restrict  , const char * __restrict  , size_t  ) __attribute__((__nonnull__(1,2)));
   





 

extern __declspec(__nothrow) char *strcat(char * __restrict  , const char * __restrict  ) __attribute__((__nonnull__(1,2)));
   




 
extern __declspec(__nothrow) char *strncat(char * __restrict  , const char * __restrict  , size_t  ) __attribute__((__nonnull__(1,2)));
   






 






 

extern __declspec(__nothrow) int memcmp(const void *  , const void *  , size_t  ) __attribute__((__nonnull__(1,2)));
   





 
extern __declspec(__nothrow) int strcmp(const char *  , const char *  ) __attribute__((__nonnull__(1,2)));
   




 
extern __declspec(__nothrow) int strncmp(const char *  , const char *  , size_t  ) __attribute__((__nonnull__(1,2)));
   






 
extern __declspec(__nothrow) int strcasecmp(const char *  , const char *  ) __attribute__((__nonnull__(1,2)));
   





 
extern __declspec(__nothrow) int strncasecmp(const char *  , const char *  , size_t  ) __attribute__((__nonnull__(1,2)));
   






 
extern __declspec(__nothrow) int strcoll(const char *  , const char *  ) __attribute__((__nonnull__(1,2)));
   







 

extern __declspec(__nothrow) size_t strxfrm(char * __restrict  , const char * __restrict  , size_t  ) __attribute__((__nonnull__(2)));
   













 


#line 193 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\string.h"
extern __declspec(__nothrow) void *memchr(const void *  , int  , size_t  ) __attribute__((__nonnull__(1)));

   





 

#line 209 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\string.h"
extern __declspec(__nothrow) char *strchr(const char *  , int  ) __attribute__((__nonnull__(1)));

   




 

extern __declspec(__nothrow) size_t strcspn(const char *  , const char *  ) __attribute__((__nonnull__(1,2)));
   




 

#line 232 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\string.h"
extern __declspec(__nothrow) char *strpbrk(const char *  , const char *  ) __attribute__((__nonnull__(1,2)));

   




 

#line 247 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\string.h"
extern __declspec(__nothrow) char *strrchr(const char *  , int  ) __attribute__((__nonnull__(1)));

   





 

extern __declspec(__nothrow) size_t strspn(const char *  , const char *  ) __attribute__((__nonnull__(1,2)));
   



 

#line 270 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\string.h"
extern __declspec(__nothrow) char *strstr(const char *  , const char *  ) __attribute__((__nonnull__(1,2)));

   





 

extern __declspec(__nothrow) char *strtok(char * __restrict  , const char * __restrict  ) __attribute__((__nonnull__(2)));
extern __declspec(__nothrow) char *_strtok_r(char *  , const char *  , char **  ) __attribute__((__nonnull__(2,3)));

extern __declspec(__nothrow) char *strtok_r(char *  , const char *  , char **  ) __attribute__((__nonnull__(2,3)));

   

































 

extern __declspec(__nothrow) void *memset(void *  , int  , size_t  ) __attribute__((__nonnull__(1)));
   



 
extern __declspec(__nothrow) char *strerror(int  );
   





 
extern __declspec(__nothrow) size_t strlen(const char *  ) __attribute__((__nonnull__(1)));
   



 

extern __declspec(__nothrow) size_t strlcpy(char *  , const char *  , size_t  ) __attribute__((__nonnull__(1,2)));
   
















 

extern __declspec(__nothrow) size_t strlcat(char *  , const char *  , size_t  ) __attribute__((__nonnull__(1,2)));
   






















 

extern __declspec(__nothrow) void _membitcpybl(void *  , const void *  , int  , int  , size_t  ) __attribute__((__nonnull__(1,2)));
extern __declspec(__nothrow) void _membitcpybb(void *  , const void *  , int  , int  , size_t  ) __attribute__((__nonnull__(1,2)));
extern __declspec(__nothrow) void _membitcpyhl(void *  , const void *  , int  , int  , size_t  ) __attribute__((__nonnull__(1,2)));
extern __declspec(__nothrow) void _membitcpyhb(void *  , const void *  , int  , int  , size_t  ) __attribute__((__nonnull__(1,2)));
extern __declspec(__nothrow) void _membitcpywl(void *  , const void *  , int  , int  , size_t  ) __attribute__((__nonnull__(1,2)));
extern __declspec(__nothrow) void _membitcpywb(void *  , const void *  , int  , int  , size_t  ) __attribute__((__nonnull__(1,2)));
extern __declspec(__nothrow) void _membitmovebl(void *  , const void *  , int  , int  , size_t  ) __attribute__((__nonnull__(1,2)));
extern __declspec(__nothrow) void _membitmovebb(void *  , const void *  , int  , int  , size_t  ) __attribute__((__nonnull__(1,2)));
extern __declspec(__nothrow) void _membitmovehl(void *  , const void *  , int  , int  , size_t  ) __attribute__((__nonnull__(1,2)));
extern __declspec(__nothrow) void _membitmovehb(void *  , const void *  , int  , int  , size_t  ) __attribute__((__nonnull__(1,2)));
extern __declspec(__nothrow) void _membitmovewl(void *  , const void *  , int  , int  , size_t  ) __attribute__((__nonnull__(1,2)));
extern __declspec(__nothrow) void _membitmovewb(void *  , const void *  , int  , int  , size_t  ) __attribute__((__nonnull__(1,2)));
    














































 







#line 502 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\string.h"



 

#line 4 "Thread.c"
#line 1 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdio.h"
 
 
 





 






 







 




  
 








#line 47 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdio.h"


  



    typedef unsigned int size_t;    









 
 

 



    typedef struct __va_list __va_list;






   




 




typedef struct __fpos_t_struct {
    unsigned __int64 __pos;
    



 
    struct {
        unsigned int __state1, __state2;
    } __mbstate;
} fpos_t;
   


 


   

 

typedef struct __FILE FILE;
   






 

#line 136 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdio.h"


extern FILE __stdin, __stdout, __stderr;
extern FILE *__aeabi_stdin, *__aeabi_stdout, *__aeabi_stderr;

#line 166 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdio.h"
    

    

    





     



   


 


   


 

   



 

   


 




   


 





    


 






extern __declspec(__nothrow) int remove(const char *  ) __attribute__((__nonnull__(1)));
   





 
extern __declspec(__nothrow) int rename(const char *  , const char *  ) __attribute__((__nonnull__(1,2)));
   








 
extern __declspec(__nothrow) FILE *tmpfile(void);
   




 
extern __declspec(__nothrow) char *tmpnam(char *  );
   











 

extern __declspec(__nothrow) int fclose(FILE *  ) __attribute__((__nonnull__(1)));
   







 
extern __declspec(__nothrow) int fflush(FILE *  );
   







 
extern __declspec(__nothrow) FILE *fopen(const char * __restrict  ,
                           const char * __restrict  ) __attribute__((__nonnull__(1,2)));
   








































 
extern __declspec(__nothrow) FILE *freopen(const char * __restrict  ,
                    const char * __restrict  ,
                    FILE * __restrict  ) __attribute__((__nonnull__(2,3)));
   








 
extern __declspec(__nothrow) void setbuf(FILE * __restrict  ,
                    char * __restrict  ) __attribute__((__nonnull__(1)));
   




 
extern __declspec(__nothrow) int setvbuf(FILE * __restrict  ,
                   char * __restrict  ,
                   int  , size_t  ) __attribute__((__nonnull__(1)));
   















 
#pragma __printf_args
extern __declspec(__nothrow) int fprintf(FILE * __restrict  ,
                    const char * __restrict  , ...) __attribute__((__nonnull__(1,2)));
   


















 
#pragma __printf_args
extern __declspec(__nothrow) int _fprintf(FILE * __restrict  ,
                     const char * __restrict  , ...) __attribute__((__nonnull__(1,2)));
   



 
#pragma __printf_args
extern __declspec(__nothrow) int printf(const char * __restrict  , ...) __attribute__((__nonnull__(1)));
   




 
#pragma __printf_args
extern __declspec(__nothrow) int _printf(const char * __restrict  , ...) __attribute__((__nonnull__(1)));
   



 
#pragma __printf_args
extern __declspec(__nothrow) int sprintf(char * __restrict  , const char * __restrict  , ...) __attribute__((__nonnull__(1,2)));
   






 
#pragma __printf_args
extern __declspec(__nothrow) int _sprintf(char * __restrict  , const char * __restrict  , ...) __attribute__((__nonnull__(1,2)));
   



 

#pragma __printf_args
extern __declspec(__nothrow) int __ARM_snprintf(char * __restrict  , size_t  ,
                     const char * __restrict  , ...) __attribute__((__nonnull__(3)));


#pragma __printf_args
extern __declspec(__nothrow) int snprintf(char * __restrict  , size_t  ,
                     const char * __restrict  , ...) __attribute__((__nonnull__(3)));
   















 

#pragma __printf_args
extern __declspec(__nothrow) int _snprintf(char * __restrict  , size_t  ,
                      const char * __restrict  , ...) __attribute__((__nonnull__(3)));
   



 
#pragma __scanf_args
extern __declspec(__nothrow) int fscanf(FILE * __restrict  ,
                    const char * __restrict  , ...) __attribute__((__nonnull__(1,2)));
   






























 
#pragma __scanf_args
extern __declspec(__nothrow) int _fscanf(FILE * __restrict  ,
                     const char * __restrict  , ...) __attribute__((__nonnull__(1,2)));
   



 
#pragma __scanf_args
extern __declspec(__nothrow) int scanf(const char * __restrict  , ...) __attribute__((__nonnull__(1)));
   






 
#pragma __scanf_args
extern __declspec(__nothrow) int _scanf(const char * __restrict  , ...) __attribute__((__nonnull__(1)));
   



 
#pragma __scanf_args
extern __declspec(__nothrow) int sscanf(const char * __restrict  ,
                    const char * __restrict  , ...) __attribute__((__nonnull__(1,2)));
   








 
#pragma __scanf_args
extern __declspec(__nothrow) int _sscanf(const char * __restrict  ,
                     const char * __restrict  , ...) __attribute__((__nonnull__(1,2)));
   



 

 
extern __declspec(__nothrow) int vfscanf(FILE * __restrict  , const char * __restrict  , __va_list) __attribute__((__nonnull__(1,2)));
extern __declspec(__nothrow) int vscanf(const char * __restrict  , __va_list) __attribute__((__nonnull__(1)));
extern __declspec(__nothrow) int vsscanf(const char * __restrict  , const char * __restrict  , __va_list) __attribute__((__nonnull__(1,2)));

extern __declspec(__nothrow) int _vfscanf(FILE * __restrict  , const char * __restrict  , __va_list) __attribute__((__nonnull__(1,2)));
extern __declspec(__nothrow) int _vscanf(const char * __restrict  , __va_list) __attribute__((__nonnull__(1)));
extern __declspec(__nothrow) int _vsscanf(const char * __restrict  , const char * __restrict  , __va_list) __attribute__((__nonnull__(1,2)));
extern __declspec(__nothrow) int __ARM_vsscanf(const char * __restrict  , const char * __restrict  , __va_list) __attribute__((__nonnull__(1,2)));

extern __declspec(__nothrow) int vprintf(const char * __restrict  , __va_list  ) __attribute__((__nonnull__(1)));
   





 
extern __declspec(__nothrow) int _vprintf(const char * __restrict  , __va_list  ) __attribute__((__nonnull__(1)));
   



 
extern __declspec(__nothrow) int vfprintf(FILE * __restrict  ,
                    const char * __restrict  , __va_list  ) __attribute__((__nonnull__(1,2)));
   






 
extern __declspec(__nothrow) int vsprintf(char * __restrict  ,
                     const char * __restrict  , __va_list  ) __attribute__((__nonnull__(1,2)));
   






 
extern __declspec(__nothrow) int __ARM_vsnprintf(char * __restrict  , size_t  ,
                     const char * __restrict  , __va_list  ) __attribute__((__nonnull__(3)));

extern __declspec(__nothrow) int vsnprintf(char * __restrict  , size_t  ,
                     const char * __restrict  , __va_list  ) __attribute__((__nonnull__(3)));
   







 

extern __declspec(__nothrow) int _vsprintf(char * __restrict  ,
                      const char * __restrict  , __va_list  ) __attribute__((__nonnull__(1,2)));
   



 
extern __declspec(__nothrow) int _vfprintf(FILE * __restrict  ,
                     const char * __restrict  , __va_list  ) __attribute__((__nonnull__(1,2)));
   



 
extern __declspec(__nothrow) int _vsnprintf(char * __restrict  , size_t  ,
                      const char * __restrict  , __va_list  ) __attribute__((__nonnull__(3)));
   



 

#pragma __printf_args
extern __declspec(__nothrow) int asprintf(char **  , const char * __restrict  , ...) __attribute__((__nonnull__(2)));
extern __declspec(__nothrow) int vasprintf(char **  , const char * __restrict  , __va_list  ) __attribute__((__nonnull__(2)));

#pragma __printf_args
extern __declspec(__nothrow) int __ARM_asprintf(char **  , const char * __restrict  , ...) __attribute__((__nonnull__(2)));
extern __declspec(__nothrow) int __ARM_vasprintf(char **  , const char * __restrict  , __va_list  ) __attribute__((__nonnull__(2)));
   








 

extern __declspec(__nothrow) int fgetc(FILE *  ) __attribute__((__nonnull__(1)));
   







 
extern __declspec(__nothrow) char *fgets(char * __restrict  , int  ,
                    FILE * __restrict  ) __attribute__((__nonnull__(1,3)));
   










 
extern __declspec(__nothrow) int fputc(int  , FILE *  ) __attribute__((__nonnull__(2)));
   







 
extern __declspec(__nothrow) int fputs(const char * __restrict  , FILE * __restrict  ) __attribute__((__nonnull__(1,2)));
   




 
extern __declspec(__nothrow) int getc(FILE *  ) __attribute__((__nonnull__(1)));
   







 




    extern __declspec(__nothrow) int (getchar)(void);

   





 
extern __declspec(__nothrow) char *gets(char *  ) __attribute__((__nonnull__(1)));
   









 
extern __declspec(__nothrow) int putc(int  , FILE *  ) __attribute__((__nonnull__(2)));
   





 




    extern __declspec(__nothrow) int (putchar)(int  );

   



 
extern __declspec(__nothrow) int puts(const char *  ) __attribute__((__nonnull__(1)));
   





 
extern __declspec(__nothrow) int ungetc(int  , FILE *  ) __attribute__((__nonnull__(2)));
   






















 

extern __declspec(__nothrow) size_t fread(void * __restrict  ,
                    size_t  , size_t  , FILE * __restrict  ) __attribute__((__nonnull__(1,4)));
   











 

extern __declspec(__nothrow) size_t __fread_bytes_avail(void * __restrict  ,
                    size_t  , FILE * __restrict  ) __attribute__((__nonnull__(1,3)));
   











 

extern __declspec(__nothrow) size_t fwrite(const void * __restrict  ,
                    size_t  , size_t  , FILE * __restrict  ) __attribute__((__nonnull__(1,4)));
   







 

extern __declspec(__nothrow) int fgetpos(FILE * __restrict  , fpos_t * __restrict  ) __attribute__((__nonnull__(1,2)));
   








 
extern __declspec(__nothrow) int fseek(FILE *  , long int  , int  ) __attribute__((__nonnull__(1)));
   














 
extern __declspec(__nothrow) int fsetpos(FILE * __restrict  , const fpos_t * __restrict  ) __attribute__((__nonnull__(1,2)));
   










 
extern __declspec(__nothrow) long int ftell(FILE *  ) __attribute__((__nonnull__(1)));
   











 
extern __declspec(__nothrow) void rewind(FILE *  ) __attribute__((__nonnull__(1)));
   





 

extern __declspec(__nothrow) void clearerr(FILE *  ) __attribute__((__nonnull__(1)));
   




 

extern __declspec(__nothrow) int feof(FILE *  ) __attribute__((__nonnull__(1)));
   


 
extern __declspec(__nothrow) int ferror(FILE *  ) __attribute__((__nonnull__(1)));
   


 
extern __declspec(__nothrow) void perror(const char *  );
   









 

extern __declspec(__nothrow) int _fisatty(FILE *   ) __attribute__((__nonnull__(1)));
    
 

extern __declspec(__nothrow) void __use_no_semihosting_swi(void);
extern __declspec(__nothrow) void __use_no_semihosting(void);
    





 











#line 1021 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdio.h"



 

#line 5 "Thread.c"



 
 
void Thread (void const *argument);                             
void Thread1 (void const *argument);                             
void actgprs(void);
void remove_all_chars(char* str, char c, char d);
extern void clear();
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
extern char g_u8RecData[550];
extern char g_u8SendData[3500];
char ph_num[15] = {0};
char sender_num[15] = {0};
extern uint32_t life;
extern int network;
char temp_fs[100] = {0};
extern int8_t charging, cpinready, cregready;
char fileinstance[20] = {0};
char debug_at[200] ={0};
extern int32_t g_u8RecDataptr;
int send_on = 1;
extern int loop();
extern osMutexId	(uart_mutex_id); 
extern char vehicleregnum[15];

char signalquality[5] = {0};
char IP[50] = "104.236.203.4";
char PORT[6] = "5556";
int start_thead = 0;

int32_t signal;
int32_t signal2;

osThreadId tid_Thread;                                          

const osThreadDef_t os_thread_def_Thread = { (Thread), (osPriorityNormal), (1), (2250) };                   



__inline void strreplace(char s[], char chr, char repl_chr);
extern char temp[100];
void Save_FS(void);
extern __inline void manualdelay(int delayms);
extern __inline void Send_FS(void);
extern __inline int count_char(char ch,char* string);
extern  int qfread(char* fi);
extern uint8_t sendfs;
extern int32_t tmr0sec;
extern uint8_t mainla;
extern uint8_t th1la;
extern uint8_t th2la;
extern char * r1;
extern char * r2;
extern char * r3;
extern int motion;
extern char RI;
void csq(void);
void smsrequest(int _case, char* arg1, char* arg2){
  char *sn = sender_num+3;
  int go = 0;
  switch(_case){
    case 1:

      osMutexWait(uart_mutex_id, 0xFFFFFFFFU);
      tmr0sec = 0;
      g_u8RecDataptr=0;
      memset(g_u8RecData,0,550);
      r1=0;
      r2=0;
      r3=0;
      clear();
      printf("\r\nAT+CPBR=4\r\n\r\n");
      do{
        r1 = strstr(g_u8RecData, ">");
        r2 = strstr(g_u8RecData, "OK");
        r3 = strstr(g_u8RecData, "ERROR");
      }while(!(r1 || r2 || r3 ||((tmr0sec >= 5))));	 
      
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
      
      osMutexWait(uart_mutex_id, 0xFFFFFFFFU);
      tmr0sec = 0;
      g_u8RecDataptr=0;
      memset(g_u8RecData,0,550);
      r1=0;
      r2=0;
      r3=0;
      clear();
      printf("\r\nAT+CPBR=4\r\n\r\n");
      do{
        r1 = strstr(g_u8RecData, ">");
        r2 = strstr(g_u8RecData, "OK");
        r3 = strstr(g_u8RecData, "ERROR");
      }while(!(r1 || r2 || r3 ||((tmr0sec >= 5))));	 
      
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
      
      osMutexWait(uart_mutex_id, 0xFFFFFFFFU);
      tmr0sec = 0;
      g_u8RecDataptr=0;
      memset(g_u8RecData,0,550);
      r1=0;
      r2=0;
      r3=0;
      clear();
      printf("\r\nAT+CPBR=4\r\n\r\n");
      do{
        r1 = strstr(g_u8RecData, ">");
        r2 = strstr(g_u8RecData, "OK");
        r3 = strstr(g_u8RecData, "ERROR");
      }while(!(r1 || r2 || r3 ||((tmr0sec >= 5))));	 
      
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
        osMutexWait(uart_mutex_id, 0xFFFFFFFFU);
        tmr0sec = 0;
        g_u8RecDataptr=0;
        memset(g_u8RecData,0,550);
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
        memset(g_u8RecData,0,550);
        r1=0;
        r2=0;
        r3=0;
        clear();
        printf("\r\nAT+CMGF=1\r\n\r\n");
        do{
          r1 = strstr(g_u8RecData, ">");
          r2 = strstr(g_u8RecData, "OK");
          r3 = strstr(g_u8RecData, "ERROR");
        }while(!(r1 || r2 || r3 ||((tmr0sec >= 5))));	 
        

        tmr0sec = 0;
        g_u8RecDataptr=0;
        memset(g_u8RecData,0,550);
        r1=0;
        r2=0;
        r3=0;
        clear();
        printf("\r\nAT+CSCS=\"GSM\"\r\n\r\n");
        do{
          r1 = strstr(g_u8RecData, ">");
          r2 = strstr(g_u8RecData, "OK");
          r3 = strstr(g_u8RecData, "ERROR");
        }while(!(r1 || r2 || r3 ||((tmr0sec >= 5))));	 
        
       
        tmr0sec = 0;
        g_u8RecDataptr=0;
        memset(g_u8RecData,0,550);
        r1=0;
        r2=0;
        r3=0;
        clear();
        printf("\r\nAT+CMGS=\"%s\"\r\n\r\n",arg1);
        do{
          r1 = strstr(g_u8RecData, ">");
          r2 = strstr(g_u8RecData, "OK");
          r3 = strstr(g_u8RecData, "ERROR");
        }while(!(r1 || r2 || r3 ||((tmr0sec >= 5))));	 

        if(strstr(g_u8RecData, ">")){
          tmr0sec = 0;
          g_u8RecDataptr=0;
          memset(g_u8RecData,0,550);
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
          }while(!(r1 || r2 || r3 ||((tmr0sec >= 5))));	 
        }
        osMutexRelease(uart_mutex_id);
      break;
    case 7:
        memset(IP,0,50);
        parse_g(g_u8RecData, 1, 1, '(', ')' , IP);
        memset(PORT,0,6);
        parse_g(g_u8RecData, 2, 2, '(', ')' , PORT);    
      break;
    case 8:
        (*((volatile uint32_t *)(((((uint32_t)0x50000000) + 0x04200)+(0x40*(4))) + ((5)<<2)))) = 0; 
      break;
    case 9:
        (*((volatile uint32_t *)(((((uint32_t)0x50000000) + 0x04200)+(0x40*(4))) + ((5)<<2)))) = 1; 
      break;
    case 10:
      
      break;
    default:
      
      break;
    
  }
}


void sms_mc60(void){
  int smsreq=0;
  int delmsg = 0;
  

      
 
  
  if(RI == 1)
  {
 
  (*((volatile uint32_t *)(((((uint32_t)0x50000000) + 0x04200)+(0x40*(1))) + ((2)<<2))))=0;
	osMutexWait(uart_mutex_id, 0xFFFFFFFFU);
	tmr0sec=0;
	r1=0;
	r2=0;
	r3=0;
	g_u8RecDataptr=0;
	memset(g_u8RecData,0,550);


	printf("\r\nAT+CMGF=1\r\n\r\n");

	do{
		r1 = strstr(g_u8RecData, "OK");
		r2 = strstr(g_u8RecData, "ERROR");
		r3 = strstr(g_u8RecData, "CMS ERROR");
	}while(!(r1 || r2 || r3 ||((tmr0sec >= 5))));	 
 
  (*((volatile uint32_t *)(((((uint32_t)0x50000000) + 0x04200)+(0x40*(1))) + ((2)<<2))))=0;
	tmr0sec=0;

	r1=0;
	r2=0;
	r3=0;
	g_u8RecDataptr=0;
	memset(g_u8RecData,0,550);


	printf("\r\nAT+CMGR=1\r\n\r\n");

	do{
		r1 = strstr(g_u8RecData, "OK");
		r2 = strstr(g_u8RecData, "ERROR");
		r3 = strstr(g_u8RecData, "CMS ERROR");
	}while(!(r1 || r2 || r3 ||((tmr0sec >= 5))));	 
   if((r1 || r2 || r3))
    {
     delmsg = 1;
    }
    r1=r2=r3=0;   

      memset(sender_num,0,15);
      parse_g(g_u8RecData,3,4,'"','"',sender_num);    
    
    
    if(strstr(g_u8RecData,"IP")){
      smsreq = 7;
    }  
    else if(strstr(g_u8RecData,"IGNITION OFF")){
      smsreq = 8;
      send_on = 0;
    }
    else if(strstr(g_u8RecData,"IGNITION ON")){
      smsreq = 9;
      send_on = 1;
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
    else if(strstr(g_u8RecData,"LIC")){
      smsreq = 10;
      
      memset(vehicleregnum, 0, 15);
      parse_g(g_u8RecData,1,1,'(',')',vehicleregnum); 
    }       

  smsrequest(smsreq, ph_num, debug_at);
   
  
  if(delmsg == 1)
  {
    RI=0; 
    SendAT("\r\nAT+CMGD=1,4\r\n\r\n", "OK", "ERROR", "7103", 10);
  }
    
  osMutexRelease(uart_mutex_id);

  osDelay(10);
  }
}

void Save_FS(void)
{
  int len=0;
 	osMutexWait(uart_mutex_id, 0xFFFFFFFFU);
  fileopen();
  SendAT("\r\nAT+QFLDS=\"UFS\"\r\n", "Ready", "OK" , "ERROR",5);
	memset(temp,0,100);
	sprintf(temp,"\r\nAT+QFSEEK=%s,0,2\r\n",fileinstance);
	SendAT(temp, "CONNECT", "OK" , "ERROR",10);	  
  len = strlen(g_u8SendData);
  strcat(g_u8SendData,"\n\n\n\n\n");  
  len = strlen(g_u8SendData);

  strreplace(g_u8SendData, '~', 'C');  
  strreplace(g_u8SendData, '`', 'H');  
  strreplace(g_u8SendData, 0x1A, '\n');  
	memset(temp,0,100);
	sprintf(temp,"\r\nAT+QFWRITE=%s,%d,3\r\n",fileinstance,(len));
	SendAT(temp, "CONNECT", "OK" , "ERROR",2);	
  len = strlen(g_u8SendData);
  remove_all_chars(g_u8SendData,'\r',0x1A);
  SendAT_FS(g_u8SendData, "QWRITE", "OK" , "ERROR",5);	



   if(strstr(g_u8RecData,"+QFWRITE"))
  {
    memset(g_u8SendData,0,3500);
  } 
  fileclose();
	osMutexRelease(uart_mutex_id);
}




int Init_Thread (void) {

	tid_Thread = osThreadCreate (&os_thread_def_Thread, 0);
  if (!tid_Thread) return(-1);

  return(0);
}




void Thread (void const *argument) 
{
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
        SendAT("\r\nAT+QILOCIP\r\n\r\n", "z", "OK" , "ERROR",2);	
      }
    }
    SendAT("\r\nAT+QSCLK=1\r\n\r\n", "Ready", "OK" , "ERROR",5);
    memset(temp, 0, 100);
    sprintf(temp,"\r\nAT+QIOPEN=\"TCP\",\"%s\",\"%s\"\r\n\r\n",IP,PORT);
    SendAT(temp,"CONNECT","ERROR","FAIL",10);	
    network=0;
    if (start_thead != 0){
    osSignalWait (0x0001, 0xFFFFFFFFU); 
    osSignalClear (tid_Thread, 0x0001);
		}start_thead = 1;    
    TCP_Send("\r\nAT+QISEND\r\n\r\n\r\n",g_u8SendData,">","ERROR","SEND OK",10);	

    if(network == 1)
    {
      Save_FS();
      SendAT("\r\nAT+QICLOSE\r\n\r\n","CLOSE OK\r\n","ERROR","FAIL",10);	
      SendAT("\r\nAT+CFUN=0\r\n\r\n", "OK", "NOT INSERTED" , "ERROR",10);
      SendAT("\r\nAT+CFUN=1\r\n\r\n", "Ready", "NOT INSERTED" , "ERROR",10);

      osDelay(500);
    }
    else
    {
  
  
  
  
  
    }  

  }
}



__inline void strreplace(char s[], char chr, char repl_chr)
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




void csq(){
 
  static int attry;

	osMutexWait(uart_mutex_id, 0xFFFFFFFFU);

	tmr0sec=0;

	r1=0;
	r2=0;
	r3=0;
	g_u8RecDataptr=0;
	memset(g_u8RecData,0,550);
	printf("%c",0x1A);
	clear();
	printf("\r\nAT+CSQ\r\n\r\n");

	do{
		r1 = strstr(g_u8RecData, "Ready");
		r2 = strstr(g_u8RecData, "OK");
		r3 = strstr(g_u8RecData, "ERROR");
	}while(!(r1 || r2 || r3 ||((tmr0sec >= 4))));	 
     if(!(r1 || r2 || r3))
      {
        (*((volatile uint32_t *)(((((uint32_t)0x50000000) + 0x04200)+(0x40*(0))) + ((13)<<2))))=1;
        attry++;
        if(attry > 3){

            printf("\r\nAT+CFUN=1,1\r\n");	
            manualdelay(100);



        }
        (*((volatile uint32_t *)(((((uint32_t)0x50000000) + 0x04200)+(0x40*(0))) + ((13)<<2))))=0;
      }
      else{attry=0;}
      memset(signalquality, 0, 5);
      parse_g(g_u8RecData, 1, 1, ':', ',', signalquality);
      remove_all_chars(signalquality, ' ', '\r');
osMutexRelease(uart_mutex_id);

   

}

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
 
__inline void fileopen(void)
{
  if(strlen(fileinstance) < 7)
  {
    SendAT("\r\nAT+QFOPEN=\"LOG.TXT\",0\r\n", "Ready", "OK" , "ERROR",10);	
    if(strstr(g_u8RecData,"CME ERROR"))
    {
        (*((volatile uint32_t *)(((((uint32_t)0x50000000) + 0x04200)+(0x40*(0))) + ((13)<<2))))=1;
        printf("\r\n\r\nAT+CFUN=1,1\r\n\r\n");
            manualdelay(100);
        (*((volatile uint32_t *)(((((uint32_t)0x50000000) + 0x04200)+(0x40*(0))) + ((13)<<2))))=0;
        memset(fileinstance,0,20);
    SendAT("\r\nAT+QFOPEN=\"LOG.TXT\",0\r\n", "Ready", "OK" , "ERROR",10);	
    }
    parse_g(g_u8RecData, 1, 2, ' ', '\n' , fileinstance);
    remove_all_chars(fileinstance, '\r', '\n');   
    SendAT("\r\nAT+QGNSSC=1\r\n\r\n", "OK", "ERROR", "7103", 5);
  }
}



int loop(){
  
    mainla = 0;
    th1la = 1;
    th2la = 0;  
    sms_mc60();

    motion = 1;
    if(motion!=0){
    csq();      
    SendAT_GPS("\r\n\r\nAT+QGNSSRD = \"NMEA/RMC\"\r\n\r\n\r\n", "MGPSSTATUS", "OK" , "ERROR",10);	
    signal = osSignalSet (tid_Thread, 0x0001);

   }      
    osDelay(4900);  


}
  

 
 
 
