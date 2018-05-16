#line 1 "main.c"


 

#line 1 "osObjects.h"









 









#line 1 "C:\\Keil_v5\\ARM\\PACK\\ARM\\CMSIS\\5.2.0\\CMSIS\\RTOS\\RTX\\INC\\cmsis_os.h"









































 












#line 63 "C:\\Keil_v5\\ARM\\PACK\\ARM\\CMSIS\\5.2.0\\CMSIS\\RTOS\\RTX\\INC\\cmsis_os.h"







#line 81 "C:\\Keil_v5\\ARM\\PACK\\ARM\\CMSIS\\5.2.0\\CMSIS\\RTOS\\RTX\\INC\\cmsis_os.h"

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






#line 21 "osObjects.h"









 







 









 









 









 

#line 7 "main.c"










 
#line 1 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\math.h"




 





 












 






   









 






#line 61 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\math.h"

#line 75 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\math.h"







   




 















 
#line 112 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\math.h"











 





extern __attribute__((__pcs__("aapcs"))) unsigned __ARM_dcmp4(double  , double  );
extern __attribute__((__pcs__("aapcs"))) unsigned __ARM_fcmp4(float  , float  );
    




 

extern __declspec(__nothrow) __attribute__((__pcs__("aapcs"))) int __ARM_fpclassifyf(float  );
extern __declspec(__nothrow) __attribute__((__pcs__("aapcs"))) int __ARM_fpclassify(double  );
     
     

__inline __declspec(__nothrow) __attribute__((__pcs__("aapcs"))) int __ARM_isfinitef(float __x)
{
    return (((*(unsigned *)&(__x)) >> 23) & 0xff) != 0xff;
}
__inline __declspec(__nothrow) __attribute__((__pcs__("aapcs"))) int __ARM_isfinite(double __x)
{
    return (((*(1 + (unsigned *)&(__x))) >> 20) & 0x7ff) != 0x7ff;
}
     
     

__inline __declspec(__nothrow) __attribute__((__pcs__("aapcs"))) int __ARM_isinff(float __x)
{
    return ((*(unsigned *)&(__x)) << 1) == 0xff000000;
}
__inline __declspec(__nothrow) __attribute__((__pcs__("aapcs"))) int __ARM_isinf(double __x)
{
    return (((*(1 + (unsigned *)&(__x))) << 1) == 0xffe00000) && ((*(unsigned *)&(__x)) == 0);
}
     
     

__inline __declspec(__nothrow) __attribute__((__pcs__("aapcs"))) int __ARM_islessgreaterf(float __x, float __y)
{
    unsigned __f = __ARM_fcmp4(__x, __y) >> 28;
    return (__f == 8) || (__f == 2);  
}
__inline __declspec(__nothrow) __attribute__((__pcs__("aapcs"))) int __ARM_islessgreater(double __x, double __y)
{
    unsigned __f = __ARM_dcmp4(__x, __y) >> 28;
    return (__f == 8) || (__f == 2);  
}
    


 

__inline __declspec(__nothrow) __attribute__((__pcs__("aapcs"))) int __ARM_isnanf(float __x)
{
    return (0x7f800000 - ((*(unsigned *)&(__x)) & 0x7fffffff)) >> 31;
}
__inline __declspec(__nothrow) __attribute__((__pcs__("aapcs"))) int __ARM_isnan(double __x)
{
    unsigned __xf = (*(1 + (unsigned *)&(__x))) | (((*(unsigned *)&(__x)) == 0) ? 0 : 1);
    return (0x7ff00000 - (__xf & 0x7fffffff)) >> 31;
}
     
     

__inline __declspec(__nothrow) __attribute__((__pcs__("aapcs"))) int __ARM_isnormalf(float __x)
{
    unsigned __xe = ((*(unsigned *)&(__x)) >> 23) & 0xff;
    return (__xe != 0xff) && (__xe != 0);
}
__inline __declspec(__nothrow) __attribute__((__pcs__("aapcs"))) int __ARM_isnormal(double __x)
{
    unsigned __xe = ((*(1 + (unsigned *)&(__x))) >> 20) & 0x7ff;
    return (__xe != 0x7ff) && (__xe != 0);
}
     
     

__inline __declspec(__nothrow) __attribute__((__pcs__("aapcs"))) int __ARM_signbitf(float __x)
{
    return (*(unsigned *)&(__x)) >> 31;
}
__inline __declspec(__nothrow) __attribute__((__pcs__("aapcs"))) int __ARM_signbit(double __x)
{
    return (*(1 + (unsigned *)&(__x))) >> 31;
}
     
     








#line 230 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\math.h"







   
  typedef float float_t;
  typedef double double_t;
#line 251 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\math.h"



extern const int math_errhandling;
#line 261 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\math.h"

extern __declspec(__nothrow) double acos(double  );
    
    
    
extern __declspec(__nothrow) double asin(double  );
    
    
    
    

extern __declspec(__nothrow) __attribute__((const)) double atan(double  );
    
    

extern __declspec(__nothrow) double atan2(double  , double  );
    
    
    
    

extern __declspec(__nothrow) double cos(double  );
    
    
    
    
extern __declspec(__nothrow) double sin(double  );
    
    
    
    

extern void __use_accurate_range_reduction(void);
    
    

extern __declspec(__nothrow) double tan(double  );
    
    
    
    

extern __declspec(__nothrow) double cosh(double  );
    
    
    
    
extern __declspec(__nothrow) double sinh(double  );
    
    
    
    
    

extern __declspec(__nothrow) __attribute__((const)) double tanh(double  );
    
    

extern __declspec(__nothrow) double exp(double  );
    
    
    
    
    

extern __declspec(__nothrow) double frexp(double  , int *  ) __attribute__((__nonnull__(2)));
    
    
    
    
    
    

extern __declspec(__nothrow) double ldexp(double  , int  );
    
    
    
    
extern __declspec(__nothrow) double log(double  );
    
    
    
    
    
extern __declspec(__nothrow) double log10(double  );
    
    
    
extern __declspec(__nothrow) double modf(double  , double *  ) __attribute__((__nonnull__(2)));
    
    
    
    

extern __declspec(__nothrow) double pow(double  , double  );
    
    
    
    
    
    
extern __declspec(__nothrow) double sqrt(double  );
    
    
    




    __inline double _sqrt(double __x) { return sqrt(__x); }




    __inline float _sqrtf(float __x) { return (float)sqrt(__x); }

    



 

extern __declspec(__nothrow) __attribute__((const)) double ceil(double  );
    
    
extern __declspec(__nothrow) __attribute__((const)) double fabs(double  );
    
    

extern __declspec(__nothrow) __attribute__((const)) double floor(double  );
    
    

extern __declspec(__nothrow) double fmod(double  , double  );
    
    
    
    
    

    









 



extern __declspec(__nothrow) double acosh(double  );
    

 
extern __declspec(__nothrow) double asinh(double  );
    

 
extern __declspec(__nothrow) double atanh(double  );
    

 
extern __declspec(__nothrow) double cbrt(double  );
    

 
__inline __declspec(__nothrow) __attribute__((const)) double copysign(double __x, double __y)
    

 
{
    (*(1 + (unsigned *)&(__x))) = ((*(1 + (unsigned *)&(__x))) & 0x7fffffff) | ((*(1 + (unsigned *)&(__y))) & 0x80000000);
    return __x;
}
__inline __declspec(__nothrow) __attribute__((const)) float copysignf(float __x, float __y)
    

 
{
    (*(unsigned *)&(__x)) = ((*(unsigned *)&(__x)) & 0x7fffffff) | ((*(unsigned *)&(__y)) & 0x80000000);
    return __x;
}
extern __declspec(__nothrow) double erf(double  );
    

 
extern __declspec(__nothrow) double erfc(double  );
    

 
extern __declspec(__nothrow) double expm1(double  );
    

 



    

 






#line 479 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\math.h"


extern __declspec(__nothrow) double hypot(double  , double  );
    




 
extern __declspec(__nothrow) int ilogb(double  );
    

 
extern __declspec(__nothrow) int ilogbf(float  );
    

 
extern __declspec(__nothrow) int ilogbl(long double  );
    

 







    

 





    



 





    



 





    

 





    



 





    



 





    



 





    

 





    

 





    


 

extern __declspec(__nothrow) double lgamma (double  );
    


 
extern __declspec(__nothrow) double log1p(double  );
    

 
extern __declspec(__nothrow) double logb(double  );
    

 
extern __declspec(__nothrow) float logbf(float  );
    

 
extern __declspec(__nothrow) long double logbl(long double  );
    

 
extern __declspec(__nothrow) double nextafter(double  , double  );
    


 
extern __declspec(__nothrow) float nextafterf(float  , float  );
    


 
extern __declspec(__nothrow) long double nextafterl(long double  , long double  );
    


 
extern __declspec(__nothrow) double nexttoward(double  , long double  );
    


 
extern __declspec(__nothrow) float nexttowardf(float  , long double  );
    


 
extern __declspec(__nothrow) long double nexttowardl(long double  , long double  );
    


 
extern __declspec(__nothrow) double remainder(double  , double  );
    

 
extern __declspec(__nothrow) __attribute__((const)) double rint(double  );
    

 
extern __declspec(__nothrow) double scalbln(double  , long int  );
    

 
extern __declspec(__nothrow) float scalblnf(float  , long int  );
    

 
extern __declspec(__nothrow) long double scalblnl(long double  , long int  );
    

 
extern __declspec(__nothrow) double scalbn(double  , int  );
    

 
extern __declspec(__nothrow) float scalbnf(float  , int  );
    

 
extern __declspec(__nothrow) long double scalbnl(long double  , int  );
    

 




    

 



 
extern __declspec(__nothrow) __attribute__((const)) float _fabsf(float);  
__inline __declspec(__nothrow) __attribute__((const)) float fabsf(float __f) { return _fabsf(__f); }
extern __declspec(__nothrow) float sinf(float  );
extern __declspec(__nothrow) float cosf(float  );
extern __declspec(__nothrow) float tanf(float  );
extern __declspec(__nothrow) float acosf(float  );
extern __declspec(__nothrow) float asinf(float  );
extern __declspec(__nothrow) float atanf(float  );
extern __declspec(__nothrow) float atan2f(float  , float  );
extern __declspec(__nothrow) float sinhf(float  );
extern __declspec(__nothrow) float coshf(float  );
extern __declspec(__nothrow) float tanhf(float  );
extern __declspec(__nothrow) float expf(float  );
extern __declspec(__nothrow) float logf(float  );
extern __declspec(__nothrow) float log10f(float  );
extern __declspec(__nothrow) float powf(float  , float  );
extern __declspec(__nothrow) float sqrtf(float  );
extern __declspec(__nothrow) float ldexpf(float  , int  );
extern __declspec(__nothrow) float frexpf(float  , int *  ) __attribute__((__nonnull__(2)));
extern __declspec(__nothrow) __attribute__((const)) float ceilf(float  );
extern __declspec(__nothrow) __attribute__((const)) float floorf(float  );
extern __declspec(__nothrow) float fmodf(float  , float  );
extern __declspec(__nothrow) float modff(float  , float *  ) __attribute__((__nonnull__(2)));

 
 













 
__declspec(__nothrow) long double acosl(long double );
__declspec(__nothrow) long double asinl(long double );
__declspec(__nothrow) long double atanl(long double );
__declspec(__nothrow) long double atan2l(long double , long double );
__declspec(__nothrow) long double ceill(long double );
__declspec(__nothrow) long double cosl(long double );
__declspec(__nothrow) long double coshl(long double );
__declspec(__nothrow) long double expl(long double );
__declspec(__nothrow) long double fabsl(long double );
__declspec(__nothrow) long double floorl(long double );
__declspec(__nothrow) long double fmodl(long double , long double );
__declspec(__nothrow) long double frexpl(long double , int* ) __attribute__((__nonnull__(2)));
__declspec(__nothrow) long double ldexpl(long double , int );
__declspec(__nothrow) long double logl(long double );
__declspec(__nothrow) long double log10l(long double );
__declspec(__nothrow) long double modfl(long double  , long double *  ) __attribute__((__nonnull__(2)));
__declspec(__nothrow) long double powl(long double , long double );
__declspec(__nothrow) long double sinl(long double );
__declspec(__nothrow) long double sinhl(long double );
__declspec(__nothrow) long double sqrtl(long double );
__declspec(__nothrow) long double tanl(long double );
__declspec(__nothrow) long double tanhl(long double );





 
extern __declspec(__nothrow) float acoshf(float  );
__declspec(__nothrow) long double acoshl(long double );
extern __declspec(__nothrow) float asinhf(float  );
__declspec(__nothrow) long double asinhl(long double );
extern __declspec(__nothrow) float atanhf(float  );
__declspec(__nothrow) long double atanhl(long double );
__declspec(__nothrow) long double copysignl(long double , long double );
extern __declspec(__nothrow) float cbrtf(float  );
__declspec(__nothrow) long double cbrtl(long double );
extern __declspec(__nothrow) float erff(float  );
__declspec(__nothrow) long double erfl(long double );
extern __declspec(__nothrow) float erfcf(float  );
__declspec(__nothrow) long double erfcl(long double );
extern __declspec(__nothrow) float expm1f(float  );
__declspec(__nothrow) long double expm1l(long double );
extern __declspec(__nothrow) float log1pf(float  );
__declspec(__nothrow) long double log1pl(long double );
extern __declspec(__nothrow) float hypotf(float  , float  );
__declspec(__nothrow) long double hypotl(long double , long double );
extern __declspec(__nothrow) float lgammaf(float  );
__declspec(__nothrow) long double lgammal(long double );
extern __declspec(__nothrow) float remainderf(float  , float  );
__declspec(__nothrow) long double remainderl(long double , long double );
extern __declspec(__nothrow) float rintf(float  );
__declspec(__nothrow) long double rintl(long double );



#line 875 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\math.h"





#line 896 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\math.h"

#line 1087 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\math.h"











#line 1317 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\math.h"





 
#line 19 "main.c"
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



 

#line 20 "main.c"
#line 1 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdlib.h"
 
 
 




 
 



 






   














  


 








#line 54 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdlib.h"


  



    typedef unsigned int size_t;    
#line 70 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdlib.h"






    



    typedef unsigned short wchar_t;  
#line 91 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdlib.h"

typedef struct div_t { int quot, rem; } div_t;
    
typedef struct ldiv_t { long int quot, rem; } ldiv_t;
    

typedef struct lldiv_t { long long quot, rem; } lldiv_t;
    


#line 112 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdlib.h"
   



 

   




 
#line 131 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdlib.h"
   


 
extern __declspec(__nothrow) int __aeabi_MB_CUR_MAX(void);

   




 

   




 




extern __declspec(__nothrow) double atof(const char *  ) __attribute__((__nonnull__(1)));
   



 
extern __declspec(__nothrow) int atoi(const char *  ) __attribute__((__nonnull__(1)));
   



 
extern __declspec(__nothrow) long int atol(const char *  ) __attribute__((__nonnull__(1)));
   



 

extern __declspec(__nothrow) long long atoll(const char *  ) __attribute__((__nonnull__(1)));
   



 


extern __declspec(__nothrow) double strtod(const char * __restrict  , char ** __restrict  ) __attribute__((__nonnull__(1)));
   

















 

extern __declspec(__nothrow) float strtof(const char * __restrict  , char ** __restrict  ) __attribute__((__nonnull__(1)));
extern __declspec(__nothrow) long double strtold(const char * __restrict  , char ** __restrict  ) __attribute__((__nonnull__(1)));
   

 

extern __declspec(__nothrow) long int strtol(const char * __restrict  ,
                        char ** __restrict  , int  ) __attribute__((__nonnull__(1)));
   



























 
extern __declspec(__nothrow) unsigned long int strtoul(const char * __restrict  ,
                                       char ** __restrict  , int  ) __attribute__((__nonnull__(1)));
   


























 

 
extern __declspec(__nothrow) long long strtoll(const char * __restrict  ,
                                  char ** __restrict  , int  )
                          __attribute__((__nonnull__(1)));
   




 
extern __declspec(__nothrow) unsigned long long strtoull(const char * __restrict  ,
                                            char ** __restrict  , int  )
                                   __attribute__((__nonnull__(1)));
   



 

extern __declspec(__nothrow) int rand(void);
   







 
extern __declspec(__nothrow) void srand(unsigned int  );
   






 

struct _rand_state { int __x[57]; };
extern __declspec(__nothrow) int _rand_r(struct _rand_state *);
extern __declspec(__nothrow) void _srand_r(struct _rand_state *, unsigned int);
struct _ANSI_rand_state { int __x[1]; };
extern __declspec(__nothrow) int _ANSI_rand_r(struct _ANSI_rand_state *);
extern __declspec(__nothrow) void _ANSI_srand_r(struct _ANSI_rand_state *, unsigned int);
   


 

extern __declspec(__nothrow) void *calloc(size_t  , size_t  );
   



 
extern __declspec(__nothrow) void free(void *  );
   





 
extern __declspec(__nothrow) void *malloc(size_t  );
   



 
extern __declspec(__nothrow) void *realloc(void *  , size_t  );
   













 

extern __declspec(__nothrow) int posix_memalign(void **  , size_t  , size_t  );
   









 

typedef int (*__heapprt)(void *, char const *, ...);
extern __declspec(__nothrow) void __heapstats(int (*  )(void *  ,
                                           char const *  , ...),
                        void *  ) __attribute__((__nonnull__(1)));
   










 
extern __declspec(__nothrow) int __heapvalid(int (*  )(void *  ,
                                           char const *  , ...),
                       void *  , int  ) __attribute__((__nonnull__(1)));
   














 
extern __declspec(__nothrow) __declspec(__noreturn) void abort(void);
   







 

extern __declspec(__nothrow) int atexit(void (*  )(void)) __attribute__((__nonnull__(1)));
   




 
#line 436 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdlib.h"


extern __declspec(__nothrow) __declspec(__noreturn) void exit(int  );
   












 

extern __declspec(__nothrow) __declspec(__noreturn) void _Exit(int  );
   







      

extern __declspec(__nothrow) char *getenv(const char *  ) __attribute__((__nonnull__(1)));
   









 

extern __declspec(__nothrow) int  system(const char *  );
   









 

extern  void *bsearch(const void *  , const void *  ,
              size_t  , size_t  ,
              int (*  )(const void *, const void *)) __attribute__((__nonnull__(1,2,5)));
   












 
#line 524 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdlib.h"


extern  void qsort(void *  , size_t  , size_t  ,
           int (*  )(const void *, const void *)) __attribute__((__nonnull__(1,4)));
   









 

#line 553 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdlib.h"

extern __declspec(__nothrow) __attribute__((const)) int abs(int  );
   



 

extern __declspec(__nothrow) __attribute__((const)) div_t div(int  , int  );
   









 
extern __declspec(__nothrow) __attribute__((const)) long int labs(long int  );
   



 




extern __declspec(__nothrow) __attribute__((const)) ldiv_t ldiv(long int  , long int  );
   











 







extern __declspec(__nothrow) __attribute__((const)) long long llabs(long long  );
   



 




extern __declspec(__nothrow) __attribute__((const)) lldiv_t lldiv(long long  , long long  );
   











 
#line 634 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdlib.h"




 
typedef struct __sdiv32by16 { int quot, rem; } __sdiv32by16;
typedef struct __udiv32by16 { unsigned int quot, rem; } __udiv32by16;
    
typedef struct __sdiv64by32 { int rem, quot; } __sdiv64by32;

__value_in_regs extern __declspec(__nothrow) __attribute__((const)) __sdiv32by16 __rt_sdiv32by16(
     int  ,
     short int  );
   

 
__value_in_regs extern __declspec(__nothrow) __attribute__((const)) __udiv32by16 __rt_udiv32by16(
     unsigned int  ,
     unsigned short  );
   

 
__value_in_regs extern __declspec(__nothrow) __attribute__((const)) __sdiv64by32 __rt_sdiv64by32(
     int  , unsigned int  ,
     int  );
   

 




 
extern __declspec(__nothrow) unsigned int __fp_status(unsigned int  , unsigned int  );
   







 























 
extern __declspec(__nothrow) int mblen(const char *  , size_t  );
   












 
extern __declspec(__nothrow) int mbtowc(wchar_t * __restrict  ,
                   const char * __restrict  , size_t  );
   















 
extern __declspec(__nothrow) int wctomb(char *  , wchar_t  );
   













 





 
extern __declspec(__nothrow) size_t mbstowcs(wchar_t * __restrict  ,
                      const char * __restrict  , size_t  ) __attribute__((__nonnull__(2)));
   














 
extern __declspec(__nothrow) size_t wcstombs(char * __restrict  ,
                      const wchar_t * __restrict  , size_t  ) __attribute__((__nonnull__(2)));
   














 

extern __declspec(__nothrow) void __use_realtime_heap(void);
extern __declspec(__nothrow) void __use_realtime_division(void);
extern __declspec(__nothrow) void __use_two_region_memory(void);
extern __declspec(__nothrow) void __use_no_heap(void);
extern __declspec(__nothrow) void __use_no_heap_region(void);

extern __declspec(__nothrow) char const *__C_library_version_string(void);
extern __declspec(__nothrow) int __C_library_version_number(void);











#line 892 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdlib.h"





 
#line 21 "main.c"
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



 

#line 22 "main.c"

#line 1 "C:\\Keil_v5\\ARM\\PACK\\Nuvoton\\NuMicro_DFP\\1.1.0\\Device\\NUC100\\Include\\NUC100Series.h"
 









 




















 



































 








 




 



 

typedef enum IRQn
{
     
    NonMaskableInt_IRQn         = -14,     
    HardFault_IRQn              = -13,     
    SVCall_IRQn                 = -5,      
    PendSV_IRQn                 = -2,      
    SysTick_IRQn                = -1,      

     
    BOD_IRQn                  = 0,         
    WDT_IRQn                  = 1,         
    EINT0_IRQn                = 2,         
    EINT1_IRQn                = 3,         
    GPAB_IRQn                 = 4,         
    GPCDEF_IRQn               = 5,         
    PWMA_IRQn                 = 6,         
    PWMB_IRQn                 = 7,         
    TMR0_IRQn                 = 8,         
    TMR1_IRQn                 = 9,         
    TMR2_IRQn                 = 10,        
    TMR3_IRQn                 = 11,        
    UART02_IRQn               = 12,        
    UART1_IRQn                = 13,        
    SPI0_IRQn                 = 14,        
    SPI1_IRQn                 = 15,        
    SPI2_IRQn                 = 16,        
    SPI3_IRQn                 = 17,        
    I2C0_IRQn                 = 18,        
    I2C1_IRQn                 = 19,        
    CAN0_IRQn                 = 20,        
    CAN1_IRQn                 = 21,        
    SC012_IRQn                = 22,        
    USBD_IRQn                 = 23,        
    PS2_IRQn                  = 24,        
    ACMP_IRQn                 = 25,        
    PDMA_IRQn                 = 26,        
    I2S_IRQn                  = 27,        
    PWRWU_IRQn                = 28,        
    ADC_IRQn                  = 29,        
    IRC_IRQn                  = 30,        
    RTC_IRQn                  = 31         
} IRQn_Type;






 

 





   


#line 1 "C:\\Keil_v5\\ARM\\PACK\\ARM\\CMSIS\\5.2.0\\CMSIS\\Include\\core_cm0.h"
 




 
















 










#line 35 "C:\\Keil_v5\\ARM\\PACK\\ARM\\CMSIS\\5.2.0\\CMSIS\\Include\\core_cm0.h"

















 




 



 

#line 1 "C:\\Keil_v5\\ARM\\PACK\\ARM\\CMSIS\\5.2.0\\CMSIS\\Include\\cmsis_version.h"
 




 
















 










 
#line 64 "C:\\Keil_v5\\ARM\\PACK\\ARM\\CMSIS\\5.2.0\\CMSIS\\Include\\core_cm0.h"
 
 









 







#line 114 "C:\\Keil_v5\\ARM\\PACK\\ARM\\CMSIS\\5.2.0\\CMSIS\\Include\\core_cm0.h"

#line 1 "C:\\Keil_v5\\ARM\\PACK\\ARM\\CMSIS\\5.2.0\\CMSIS\\Include\\cmsis_compiler.h"
 




 
















 




#line 29 "C:\\Keil_v5\\ARM\\PACK\\ARM\\CMSIS\\5.2.0\\CMSIS\\Include\\cmsis_compiler.h"



 
#line 1 "C:\\Keil_v5\\ARM\\PACK\\ARM\\CMSIS\\5.2.0\\CMSIS\\Include\\cmsis_armcc.h"
 




 
















 









 













   
   


 
#line 100 "C:\\Keil_v5\\ARM\\PACK\\ARM\\CMSIS\\5.2.0\\CMSIS\\Include\\cmsis_armcc.h"

 



 





 
 






 
 





 
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


#line 335 "C:\\Keil_v5\\ARM\\PACK\\ARM\\CMSIS\\5.2.0\\CMSIS\\Include\\cmsis_armcc.h"


#line 373 "C:\\Keil_v5\\ARM\\PACK\\ARM\\CMSIS\\5.2.0\\CMSIS\\Include\\cmsis_armcc.h"



 


 



 




 






 







 






 








 










 










 






                  





 








 

__attribute__((section(".rev16_text"))) static __inline __asm uint32_t __REV16(uint32_t value)
{
  rev16 r0, r0
  bx lr
}








 

__attribute__((section(".revsh_text"))) static __inline __asm int16_t __REVSH(int16_t value)
{
  revsh r0, r0
  bx lr
}









 









 








 




__attribute__((always_inline)) static __inline uint32_t __RBIT(uint32_t value)
{
  uint32_t result;
  uint32_t s = (4U   * 8U) - 1U;  

  result = value;                       
  for (value >>= 1U; value != 0U; value >>= 1U)
  {
    result <<= 1U;
    result |= value & 1U;
    s--;
  }
  result <<= s;                         
  return result;
}








 



#line 730 "C:\\Keil_v5\\ARM\\PACK\\ARM\\CMSIS\\5.2.0\\CMSIS\\Include\\cmsis_armcc.h"







 
__attribute__((always_inline)) static __inline int32_t __SSAT(int32_t val, uint32_t sat)
{
  if ((sat >= 1U) && (sat <= 32U))
  {
    const int32_t max = (int32_t)((1U << (sat - 1U)) - 1U);
    const int32_t min = -1 - max ;
    if (val > max)
    {
      return max;
    }
    else if (val < min)
    {
      return min;
    }
  }
  return val;
}







 
__attribute__((always_inline)) static __inline uint32_t __USAT(int32_t val, uint32_t sat)
{
  if (sat <= 31U)
  {
    const uint32_t max = ((1U << sat) - 1U);
    if (val > (int32_t)max)
    {
      return max;
    }
    else if (val < 0)
    {
      return 0U;
    }
  }
  return (uint32_t)val;
}




   


 



 

#line 864 "C:\\Keil_v5\\ARM\\PACK\\ARM\\CMSIS\\5.2.0\\CMSIS\\Include\\cmsis_armcc.h"
 


#line 35 "C:\\Keil_v5\\ARM\\PACK\\ARM\\CMSIS\\5.2.0\\CMSIS\\Include\\cmsis_compiler.h"




 
#line 254 "C:\\Keil_v5\\ARM\\PACK\\ARM\\CMSIS\\5.2.0\\CMSIS\\Include\\cmsis_compiler.h"




#line 116 "C:\\Keil_v5\\ARM\\PACK\\ARM\\CMSIS\\5.2.0\\CMSIS\\Include\\core_cm0.h"

















 
#line 150 "C:\\Keil_v5\\ARM\\PACK\\ARM\\CMSIS\\5.2.0\\CMSIS\\Include\\core_cm0.h"

 






 
#line 166 "C:\\Keil_v5\\ARM\\PACK\\ARM\\CMSIS\\5.2.0\\CMSIS\\Include\\core_cm0.h"

 




 










 



 






 



 
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

 












 



 



 









 








 
 







 






 







 


 







 

 










 









 


 



 





 

#line 575 "C:\\Keil_v5\\ARM\\PACK\\ARM\\CMSIS\\5.2.0\\CMSIS\\Include\\core_cm0.h"
 
 
#line 583 "C:\\Keil_v5\\ARM\\PACK\\ARM\\CMSIS\\5.2.0\\CMSIS\\Include\\core_cm0.h"
 





#line 598 "C:\\Keil_v5\\ARM\\PACK\\ARM\\CMSIS\\5.2.0\\CMSIS\\Include\\core_cm0.h"




 
 










 
static __inline void __NVIC_EnableIRQ(IRQn_Type IRQn)
{
  if ((int32_t)(IRQn) >= 0)
  {
    ((NVIC_Type *) ((0xE000E000UL) + 0x0100UL) )->ISER[0U] = (uint32_t)(1UL << (((uint32_t)(int32_t)IRQn) & 0x1FUL));
  }
}









 
static __inline uint32_t __NVIC_GetEnableIRQ(IRQn_Type IRQn)
{
  if ((int32_t)(IRQn) >= 0)
  {
    return((uint32_t)(((((NVIC_Type *) ((0xE000E000UL) + 0x0100UL) )->ISER[0U] & (1UL << (((uint32_t)(int32_t)IRQn) & 0x1FUL))) != 0UL) ? 1UL : 0UL));
  }
  else
  {
    return(0U);
  }
}







 
static __inline void __NVIC_DisableIRQ(IRQn_Type IRQn)
{
  if ((int32_t)(IRQn) >= 0)
  {
    ((NVIC_Type *) ((0xE000E000UL) + 0x0100UL) )->ICER[0U] = (uint32_t)(1UL << (((uint32_t)(int32_t)IRQn) & 0x1FUL));
    do { __schedule_barrier(); __dsb(0xF); __schedule_barrier(); } while (0U);
    do { __schedule_barrier(); __isb(0xF); __schedule_barrier(); } while (0U);
  }
}









 
static __inline uint32_t __NVIC_GetPendingIRQ(IRQn_Type IRQn)
{
  if ((int32_t)(IRQn) >= 0)
  {
    return((uint32_t)(((((NVIC_Type *) ((0xE000E000UL) + 0x0100UL) )->ISPR[0U] & (1UL << (((uint32_t)(int32_t)IRQn) & 0x1FUL))) != 0UL) ? 1UL : 0UL));
  }
  else
  {
    return(0U);
  }
}







 
static __inline void __NVIC_SetPendingIRQ(IRQn_Type IRQn)
{
  if ((int32_t)(IRQn) >= 0)
  {
    ((NVIC_Type *) ((0xE000E000UL) + 0x0100UL) )->ISPR[0U] = (uint32_t)(1UL << (((uint32_t)(int32_t)IRQn) & 0x1FUL));
  }
}







 
static __inline void __NVIC_ClearPendingIRQ(IRQn_Type IRQn)
{
  if ((int32_t)(IRQn) >= 0)
  {
    ((NVIC_Type *) ((0xE000E000UL) + 0x0100UL) )->ICPR[0U] = (uint32_t)(1UL << (((uint32_t)(int32_t)IRQn) & 0x1FUL));
  }
}










 
static __inline void __NVIC_SetPriority(IRQn_Type IRQn, uint32_t priority)
{
  if ((int32_t)(IRQn) >= 0)
  {
    ((NVIC_Type *) ((0xE000E000UL) + 0x0100UL) )->IP[( (((uint32_t)(int32_t)(IRQn)) >> 2UL) )]  = ((uint32_t)(((NVIC_Type *) ((0xE000E000UL) + 0x0100UL) )->IP[( (((uint32_t)(int32_t)(IRQn)) >> 2UL) )]  & ~(0xFFUL << ( ((((uint32_t)(int32_t)(IRQn)) ) & 0x03UL) * 8UL))) |
       (((priority << (8U - 2)) & (uint32_t)0xFFUL) << ( ((((uint32_t)(int32_t)(IRQn)) ) & 0x03UL) * 8UL)));
  }
  else
  {
    ((SCB_Type *) ((0xE000E000UL) + 0x0D00UL) )->SHP[( (((((uint32_t)(int32_t)(IRQn)) & 0x0FUL)-8UL) >> 2UL) )] = ((uint32_t)(((SCB_Type *) ((0xE000E000UL) + 0x0D00UL) )->SHP[( (((((uint32_t)(int32_t)(IRQn)) & 0x0FUL)-8UL) >> 2UL) )] & ~(0xFFUL << ( ((((uint32_t)(int32_t)(IRQn)) ) & 0x03UL) * 8UL))) |
       (((priority << (8U - 2)) & (uint32_t)0xFFUL) << ( ((((uint32_t)(int32_t)(IRQn)) ) & 0x03UL) * 8UL)));
  }
}










 
static __inline uint32_t __NVIC_GetPriority(IRQn_Type IRQn)
{

  if ((int32_t)(IRQn) >= 0)
  {
    return((uint32_t)(((((NVIC_Type *) ((0xE000E000UL) + 0x0100UL) )->IP[ ( (((uint32_t)(int32_t)(IRQn)) >> 2UL) )] >> ( ((((uint32_t)(int32_t)(IRQn)) ) & 0x03UL) * 8UL) ) & (uint32_t)0xFFUL) >> (8U - 2)));
  }
  else
  {
    return((uint32_t)(((((SCB_Type *) ((0xE000E000UL) + 0x0D00UL) )->SHP[( (((((uint32_t)(int32_t)(IRQn)) & 0x0FUL)-8UL) >> 2UL) )] >> ( ((((uint32_t)(int32_t)(IRQn)) ) & 0x03UL) * 8UL) ) & (uint32_t)0xFFUL) >> (8U - 2)));
  }
}










 
static __inline void __NVIC_SetVector(IRQn_Type IRQn, uint32_t vector)
{
  uint32_t *vectors = (uint32_t *)0x0U;
  vectors[(int32_t)IRQn + 16] = vector;
}









 
static __inline uint32_t __NVIC_GetVector(IRQn_Type IRQn)
{
  uint32_t *vectors = (uint32_t *)0x0U;
  return vectors[(int32_t)IRQn + 16];
}





 
static __inline void __NVIC_SystemReset(void)
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

 


 





 








 
static __inline uint32_t SCB_GetFPUType(void)
{
    return 0U;            
}


 



 





 













 
static __inline uint32_t SysTick_Config(uint32_t ticks)
{
  if ((ticks - 1UL) > (0xFFFFFFUL ))
  {
    return (1UL);                                                    
  }

  ((SysTick_Type *) ((0xE000E000UL) + 0x0010UL) )->LOAD  = (uint32_t)(ticks - 1UL);                          
  __NVIC_SetPriority (SysTick_IRQn, (1UL << 2) - 1UL);  
  ((SysTick_Type *) ((0xE000E000UL) + 0x0010UL) )->VAL   = 0UL;                                              
  ((SysTick_Type *) ((0xE000E000UL) + 0x0010UL) )->CTRL  = (1UL << 2U) |
                   (1UL << 1U)   |
                   (1UL );                          
  return (0UL);                                                      
}



 










#line 149 "C:\\Keil_v5\\ARM\\PACK\\Nuvoton\\NuMicro_DFP\\1.1.0\\Device\\NUC100\\Include\\NUC100Series.h"
#line 1 "C:\\Keil_v5\\ARM\\PACK\\Nuvoton\\NuMicro_DFP\\1.1.0\\Device\\NUC100\\Include\\system_NUC100Series.h"
 









 






 
 
 

 




 






extern uint32_t SystemCoreClock;     
extern uint32_t CyclesPerUs;         
extern uint32_t PllClock;            









 
extern void SystemInit(void);










 
extern void SystemCoreClockUpdate(void);





#line 150 "C:\\Keil_v5\\ARM\\PACK\\Nuvoton\\NuMicro_DFP\\1.1.0\\Device\\NUC100\\Include\\NUC100Series.h"


#pragma anon_unions



 



 

 



 



typedef struct
{














































 

    volatile uint32_t CMPCR[2];       
    volatile uint32_t CMPSR;          

} ACMP_T;






 


 















 












   
   




 



 


typedef struct
{


















































































































































































































 

    volatile const  uint32_t ADDR[8];        
    volatile uint32_t ADCR;           
    volatile uint32_t ADCHER;         
    volatile uint32_t ADCMPR[2];      
    volatile uint32_t ADSR;           
    volatile const  uint32_t RESERVE0[3];  
    volatile const  uint32_t ADPDMA;         

} ADC_T;






 

 









 






























 






 


















 





















 



   
   



 



 


typedef struct
{






























































































































































































































































































































































































































































































































































































 

    volatile uint32_t PWRCON;         
    volatile uint32_t AHBCLK;         
    volatile uint32_t APBCLK;         
    volatile uint32_t CLKSTATUS;      
    volatile uint32_t CLKSEL0;        
    volatile uint32_t CLKSEL1;        
    volatile uint32_t CLKDIV;         
    volatile uint32_t CLKSEL2;        
    volatile uint32_t PLLCON;         
    volatile uint32_t FRQDIV;         
    volatile uint32_t RESERVE[2];   
    volatile uint32_t APBCLK1;        
    volatile uint32_t CLKSEL3;        
    volatile uint32_t CLKDIV1;        

} CLK_T;






 

 































 










 











































































 









 






















 






 







































 






































 









 












 









 





















 












   
   



 



 


typedef struct
{













































































































































































 

    volatile uint32_t CTL;            
    volatile uint32_t DMASAR;         
    volatile const  uint32_t RESERVED0;    
    volatile uint32_t DMABCR ;        
    volatile const  uint32_t RESERVED1;    
    volatile const  uint32_t DMACSAR;        
    volatile const  uint32_t RESERVED2;    
    volatile const  uint32_t DMACBCR;        
    volatile uint32_t DMAIER ;        
    volatile uint32_t DMAISR;         
    volatile const  uint32_t RESERVED3[22];
    volatile uint32_t WDATA;          
    volatile uint32_t SEED;           
    volatile const  uint32_t CHECKSUM;       

} CRC_T;







 

 



























 



 



 



 



 






 






 



 



 


   
   



 



 



typedef struct
{




















































 

    volatile uint32_t EBICON;         
    volatile uint32_t EXTIME;         
    volatile uint32_t EBICON2;        

} EBI_T;






 

 












 












 








   
   



 



 


typedef struct
{

























































































































































 

    volatile uint32_t ISPCON;         
    volatile uint32_t ISPADR;         
    volatile uint32_t ISPDAT;         
    volatile uint32_t ISPCMD;         
    volatile uint32_t ISPTRG;         
    volatile const  uint32_t DFBADR;         
    volatile uint32_t FATCON;         
    volatile const  uint32_t RESERVED[9];  
    volatile uint32_t ISPSTA;         

} FMC_T;






 

 
























 



 



 









 



 



 
























   
   




 



 


typedef struct
{
























































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































 

    volatile uint32_t PMD;            
    volatile uint32_t OFFD;           
    volatile uint32_t DOUT;           
    volatile uint32_t DMASK;          
    volatile const  uint32_t PIN;            
    volatile uint32_t DBEN;           
    volatile uint32_t IMD;            
    volatile uint32_t IEN;            
    volatile uint32_t ISRC;           

} GPIO_T;





typedef struct
{



































 

    volatile uint32_t DBNCECON;       

} GPIO_DBNCECON_T;






 


 
















































 



 



 



 



 



 



 






 



 








   
   




 



 


typedef struct
{
























































































































































































































 

    volatile uint32_t I2CON;          
    volatile uint32_t I2CADDR0;       
    volatile uint32_t I2CDAT;         
    volatile const  uint32_t I2CSTATUS;      
    volatile uint32_t I2CLK;          
    volatile uint32_t I2CTOC;         
    volatile uint32_t I2CADDR1;       
    volatile uint32_t I2CADDR2;       
    volatile uint32_t I2CADDR3;       
    volatile uint32_t I2CADM0;        
    volatile uint32_t I2CADM1;        
    volatile uint32_t I2CADM2;        
    volatile uint32_t I2CADM3;        
    volatile const  uint32_t RESERVED0[2];
    volatile uint32_t I2CWKUPCON;     
    volatile uint32_t I2CWKUPSTS;     

} I2C_T;







 

 


















 






 



 



 



 









 



 



 



   
   



 



 


typedef struct
{





























































































































































































































































































 

    volatile uint32_t CON;            
    volatile uint32_t CLKDIV;         
    volatile uint32_t IE;             
    volatile uint32_t STATUS;         
    volatile  uint32_t TXFIFO;         
    volatile const  uint32_t RXFIFO;         

} I2S_T;







 

 






















































                                                  






                                                      

























 

























































   
   



 



 


typedef struct
{









































































































































 

    volatile uint32_t CSR;            
    volatile uint32_t SAR;            
    volatile uint32_t DAR;            
    volatile uint32_t BCR;            
    volatile const  uint32_t POINT;          
    volatile const  uint32_t CSAR;           
    volatile const  uint32_t CDAR;           
    volatile const  uint32_t CBCR;           
    volatile uint32_t IER;            
    volatile uint32_t ISR;            
    volatile const  uint32_t RESERVE[22];  
    volatile const  uint32_t SBUF;           

} PDMA_T;





typedef struct
{




































































































































































































 

    volatile uint32_t GCRCSR;         
    volatile uint32_t PDSSR0;         
    volatile uint32_t PDSSR1;         
    volatile uint32_t GCRISR;         
    volatile uint32_t PDSSR2;         

} PDMA_GCR_T;






 


 





















 



 



 




 






 






 






























 
























 















 

































 





   
   



 



 


typedef struct
{









































































































































































 

    volatile uint32_t PS2CON;         
    volatile uint32_t PS2TXDATA0;     
    volatile uint32_t PS2TXDATA1;     
    volatile uint32_t PS2TXDATA2;     
    volatile uint32_t PS2TXDATA3;     
    volatile uint32_t PS2RXDATA;      
    volatile uint32_t PS2STATUS;      
    volatile uint32_t PS2INTID;       

} PS2_T;







 

 



























 



 



























 


                                                                                                    


   
   


 



 


typedef struct
{
























































































































































































































































































































































































































































































































































































































































































































































































































 

    volatile uint32_t PPR;            
    volatile uint32_t CSR;            
    volatile uint32_t PCR;            
    volatile uint32_t CNR0;           
    volatile uint32_t CMR0;           
    volatile const  uint32_t PDR0;           
    volatile uint32_t CNR1;           
    volatile uint32_t CMR1;           
    volatile const  uint32_t PDR1;           
    volatile uint32_t CNR2;           
    volatile uint32_t CMR2;           
    volatile const  uint32_t PDR2;           
    volatile uint32_t CNR3;           
    volatile uint32_t CMR3;           
    volatile const  uint32_t PDR3;           
    volatile uint32_t PBCR;           
    volatile uint32_t PIER;           
    volatile uint32_t PIIR;           
    volatile const  uint32_t RESERVE1[2];  
    volatile uint32_t CCR0;           
    volatile uint32_t CCR2;           
    volatile uint32_t CRLR0;          
    volatile uint32_t CFLR0;          
    volatile uint32_t CRLR1;          
    volatile uint32_t CFLR1;          
    volatile uint32_t CRLR2;          
    volatile uint32_t CFLR2;          
    volatile uint32_t CRLR3;          
    volatile uint32_t CFLR3;          
    volatile uint32_t CAPENR;         
    volatile uint32_t POE;            
    volatile uint32_t TCON;           
    volatile uint32_t TSTATUS;        
    volatile uint32_t SYNCBUSY0;      
    volatile uint32_t SYNCBUSY1;      
    volatile uint32_t SYNCBUSY2;      
    volatile uint32_t SYNCBUSY3;      

} PWM_T;






 

 












 












 




























































 


                                                                                            
                                                          


                                                                                            
                                                          



 



 































 
























 










































 










































 



 



 












 












 













 













 



 



 



 


   
   





 



 


typedef struct
{


































































































































































































































 

    volatile uint32_t INIR;           
    volatile uint32_t AER;            
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
    volatile const  uint32_t RESERVED[2];  
    volatile uint32_t SPRCTL;         
    volatile uint32_t SPR[20];        

} RTC_T;






 

 






 






 






 


















 


















 



 



 


















 


















 



 









 









 



 

















   
   




 



 


typedef struct
{


    































































































































































































































































































































































































































































































































































































































































 

    volatile const  uint32_t RBR;            
    volatile  uint32_t THR;            
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
    volatile const  uint32_t RESERVED0;    
    volatile const  uint32_t TDRA;           
    volatile const  uint32_t TDRB;           

} SC_T;






 

 



 



 













































 










































 



 



 






 

































 


































 



















































 







































 






 






 






 



 





   
   




 



 


typedef struct
{





































































































































































































































































































































































































































 

    volatile uint32_t CNTRL;          
    volatile uint32_t DIVIDER;        
    volatile uint32_t SSR;            
    volatile const  uint32_t RESERVE0;     
    volatile const  uint32_t RX[2];          
    volatile const  uint32_t RESERVE1;     
    volatile const  uint32_t RESERVE2;     
    volatile  uint32_t TX[2];          
    volatile const  uint32_t RESERVE3;     
    volatile const  uint32_t RESERVE4;     
    volatile const  uint32_t RESERVE5;     
    volatile uint32_t VARCLK;         
    volatile uint32_t DMA;            
    volatile uint32_t CNTRL2;         
    volatile uint32_t FIFO_CTL;       
    volatile uint32_t STATUS;         
    
} SPI_T;






 

 






















































 






 















 









 
























 
























 



































   
   




 



 



typedef struct
{































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































 

    volatile const  uint32_t PDID;           
    volatile uint32_t RSTSRC;         
    volatile uint32_t IPRSTC1;        
    volatile uint32_t IPRSTC2;        
    volatile uint32_t IPRSTC3;        
    volatile const  uint32_t RESERVE0;
    volatile uint32_t BODCR;          
    volatile uint32_t TEMPCR;         
    volatile const  uint32_t RESERVE1;
    volatile uint32_t PORCR;          
    volatile const  uint32_t RESERVE2[2];
    volatile uint32_t GPA_MFP;        
    volatile uint32_t GPB_MFP;        
    volatile uint32_t GPC_MFP;        
    volatile uint32_t GPD_MFP;        
    volatile uint32_t GPE_MFP;        
    volatile uint32_t GPF_MFP;        
    volatile const  uint32_t RESERVE3[2];
    volatile uint32_t ALT_MFP;        
    volatile const  uint32_t RESERVE4;
    volatile uint32_t ALT_MFP1;       
    volatile uint32_t ALT_MFP2;       
    volatile const  uint32_t RESERVE5[8];
    volatile uint32_t IRCTRIMCTL;     
    volatile uint32_t IRCTRIMIEN;     
    volatile uint32_t IRCTRIMINT;     
    volatile const  uint32_t RESERVE6[29];   
    volatile uint32_t REGWRPROT;      

} GCR_T;







 

 





















 












 































































 









 





















 



 



 







 






 






 






 












 















 




























































 













































 












 






 









 








typedef struct
{

    











































































 

    volatile const  uint32_t IRQSRC[32];    
    volatile uint32_t NMISEL;        
    volatile uint32_t MCUIRQ;        
    
} GCR_INT_T;



 



 





   
   




 



 


typedef struct
{

























































































































































 

    volatile uint32_t TCSR;           
    volatile uint32_t TCMPR;          
    volatile uint32_t TISR;           
    volatile const  uint32_t TDR;            
    volatile const  uint32_t TCAP;           
    volatile uint32_t TEXCON;         
    volatile uint32_t TEXISR;         

} TIMER_T;






 

 






























 



 






 



 



 





















 


   
   



 



 


typedef struct
{




































































































































































































































































































































































































































































































































































































































































































































 

    union
    {
        volatile uint32_t DATA;           
        volatile uint32_t THR;            
        volatile uint32_t RBR;            
    };
    volatile uint32_t IER;            
    volatile uint32_t FCR;            
    volatile uint32_t LCR;            
    volatile uint32_t MCR;            
    volatile uint32_t MSR;            
    volatile uint32_t FSR;            
    volatile uint32_t ISR;            
    volatile uint32_t TOR;            
    volatile uint32_t BAUD;           
    volatile uint32_t IRCR;           
    volatile uint32_t ALT_CSR;        
    volatile uint32_t FUN_SEL;        
    volatile uint32_t LIN_CTL;        
    volatile uint32_t LIN_SR;         
    

} UART_T;







 

 



 



 








 






























 















 


















 









 










 







































 



































































 






 


                                                                                     


                                                                                     


                                                                                     



 









 
























 



 










































 

















   
   



 



 



typedef struct
{










































































 

    volatile uint32_t BUFSEG;         
    volatile uint32_t MXPLD;          
    volatile uint32_t CFG;            
    volatile uint32_t CFGP;           

} USBD_EP_T;







typedef struct
{

















































































































































































































 

    volatile uint32_t INTEN;          
    volatile uint32_t INTSTS;         
    volatile uint32_t FADDR;          
    volatile const  uint32_t EPSTS;          
    volatile uint32_t ATTR;           
    volatile const  uint32_t FLDET;          
    volatile uint32_t STBUFSEG;       
    volatile const  uint32_t RESERVE0;   
    USBD_EP_T     EP[6];          
    volatile const  uint32_t RESERVE1[4];  
    volatile uint32_t DRVSE0;         

} USBD_T;







 

 


















                                           


















                                            



                                            





















                                             






























                                            



 



 



                                            



                                              















                                             






                                           



   
   




 



 


typedef struct
{




















































































 

    volatile uint32_t WTCR;           
    volatile uint32_t WTCRALT;        

} WDT_T;






 

 






























                                                  


   
   


 



 


typedef struct
{













































































 

    volatile uint32_t WWDTRLD;        
    volatile uint32_t WWDTCR;         
    volatile uint32_t WWDTSR;         
    volatile const  uint32_t WWDTCVR;        

} WWDT_T;






 

 



                                                   















                                                   






                                                  


   
   
   


 
 
 



 
 






 
#line 12442 "C:\\Keil_v5\\ARM\\PACK\\Nuvoton\\NuMicro_DFP\\1.1.0\\Device\\NUC100\\Include\\NUC100Series.h"










































#line 12493 "C:\\Keil_v5\\ARM\\PACK\\Nuvoton\\NuMicro_DFP\\1.1.0\\Device\\NUC100\\Include\\NUC100Series.h"















   

 
 
 




 
#line 12525 "C:\\Keil_v5\\ARM\\PACK\\Nuvoton\\NuMicro_DFP\\1.1.0\\Device\\NUC100\\Include\\NUC100Series.h"










































#line 12576 "C:\\Keil_v5\\ARM\\PACK\\Nuvoton\\NuMicro_DFP\\1.1.0\\Device\\NUC100\\Include\\NUC100Series.h"














   











 

typedef volatile unsigned char  vu8;        
typedef volatile unsigned short vu16;       
typedef volatile unsigned long  vu32;       





 







 







 








 







 








 







 







 






 








 







 








 







 







 






 


   







 













 
#line 12784 "C:\\Keil_v5\\ARM\\PACK\\Nuvoton\\NuMicro_DFP\\1.1.0\\Device\\NUC100\\Include\\NUC100Series.h"

 










   

   


 
 
 
#line 1 "C:\\Keil_v5\\ARM\\PACK\\Nuvoton\\NuMicro_DFP\\1.1.0\\Device\\NUC100\\Driver\\SYS.h"
 









 










 



 



 


 
 
 
#line 64 "C:\\Keil_v5\\ARM\\PACK\\Nuvoton\\NuMicro_DFP\\1.1.0\\Device\\NUC100\\Driver\\SYS.h"


 
 
 
#line 75 "C:\\Keil_v5\\ARM\\PACK\\Nuvoton\\NuMicro_DFP\\1.1.0\\Device\\NUC100\\Driver\\SYS.h"


 
 
 







 



































    


































































































































































































































































































































































































































































































































































































































































































































































































































































































































































    






























































































































































































































































   



 







 







 







 







 








 









 







 







 







 











 








 








 








 








 








 








 








 







 







 







 







 














 









 
static __inline void SYS_LockReg(void)
{
    ((GCR_T *) ((( uint32_t)0x50000000) + 0x00000))->REGWRPROT = 0;
}








 
static __inline void SYS_UnlockReg(void)
{
    while(((GCR_T *) ((( uint32_t)0x50000000) + 0x00000))->REGWRPROT != (1ul << 0))
    {
        ((GCR_T *) ((( uint32_t)0x50000000) + 0x00000))->REGWRPROT = 0x59;
        ((GCR_T *) ((( uint32_t)0x50000000) + 0x00000))->REGWRPROT = 0x16;
        ((GCR_T *) ((( uint32_t)0x50000000) + 0x00000))->REGWRPROT = 0x88;
    }
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


   

   

   








 
#line 12805 "C:\\Keil_v5\\ARM\\PACK\\Nuvoton\\NuMicro_DFP\\1.1.0\\Device\\NUC100\\Include\\NUC100Series.h"
#line 1 "C:\\Keil_v5\\ARM\\PACK\\Nuvoton\\NuMicro_DFP\\1.1.0\\Device\\NUC100\\Driver\\ADC.h"
 









 












 



 



 
 
 
 
























 
 
 




 
 
 
#line 76 "C:\\Keil_v5\\ARM\\PACK\\Nuvoton\\NuMicro_DFP\\1.1.0\\Device\\NUC100\\Driver\\ADC.h"

 
 
 




 
 
 




 
 
 





 
 
 



 
 
 





   



 











 








 







 








 












 












 








 









 









 








 







 
















 
#line 254 "C:\\Keil_v5\\ARM\\PACK\\Nuvoton\\NuMicro_DFP\\1.1.0\\Device\\NUC100\\Driver\\ADC.h"






 
















 
#line 287 "C:\\Keil_v5\\ARM\\PACK\\Nuvoton\\NuMicro_DFP\\1.1.0\\Device\\NUC100\\Driver\\ADC.h"






 










 










 







 








 


void ADC_Open(ADC_T *adc,
              uint32_t u32InputMode,
              uint32_t u32OpMode,
              uint32_t u32ChMask);
void ADC_Close(ADC_T *adc);
void ADC_EnableHWTrigger(ADC_T *adc,
                         uint32_t u32Source,
                         uint32_t u32Param);
void ADC_DisableHWTrigger(ADC_T *adc);
void ADC_EnableInt(ADC_T *adc, uint32_t u32Mask);
void ADC_DisableInt(ADC_T *adc, uint32_t u32Mask);



   

   

   







 
#line 12806 "C:\\Keil_v5\\ARM\\PACK\\Nuvoton\\NuMicro_DFP\\1.1.0\\Device\\NUC100\\Include\\NUC100Series.h"
#line 1 "C:\\Keil_v5\\ARM\\PACK\\Nuvoton\\NuMicro_DFP\\1.1.0\\Device\\NUC100\\Driver\\FMC.h"
 









 












 



 



 


 
 
 







 
 
 



 
 
 
#line 61 "C:\\Keil_v5\\ARM\\PACK\\Nuvoton\\NuMicro_DFP\\1.1.0\\Device\\NUC100\\Driver\\FMC.h"


   



 

 
 
 









 












 













 













 














 











 













 












 













 















 














 



 
 
 











 
static __inline void FMC_Write(uint32_t u32addr, uint32_t u32data)
{
    ((FMC_T *) ((( uint32_t)0x50000000) + 0x0C000))->ISPCMD = 0x21;    
    ((FMC_T *) ((( uint32_t)0x50000000) + 0x0C000))->ISPADR = u32addr;               
    ((FMC_T *) ((( uint32_t)0x50000000) + 0x0C000))->ISPDAT = u32data;               
    ((FMC_T *) ((( uint32_t)0x50000000) + 0x0C000))->ISPTRG = 0x1;                   
    do { __schedule_barrier(); __isb(0xF); __schedule_barrier(); } while (0U);                             
    while(((FMC_T *) ((( uint32_t)0x50000000) + 0x0C000))->ISPTRG);                  
}










 
static __inline uint32_t FMC_Read(uint32_t u32addr)
{
    ((FMC_T *) ((( uint32_t)0x50000000) + 0x0C000))->ISPCMD = 0x00;  
    ((FMC_T *) ((( uint32_t)0x50000000) + 0x0C000))->ISPADR = u32addr;          
    ((FMC_T *) ((( uint32_t)0x50000000) + 0x0C000))->ISPTRG = 0x1;              
    do { __schedule_barrier(); __isb(0xF); __schedule_barrier(); } while (0U);                        
    while(((FMC_T *) ((( uint32_t)0x50000000) + 0x0C000))->ISPTRG);             

    return ((FMC_T *) ((( uint32_t)0x50000000) + 0x0C000))->ISPDAT;
}













 
static __inline int32_t FMC_Erase(uint32_t u32addr)
{
    ((FMC_T *) ((( uint32_t)0x50000000) + 0x0C000))->ISPCMD = 0x22;  
    ((FMC_T *) ((( uint32_t)0x50000000) + 0x0C000))->ISPADR = u32addr;                
    ((FMC_T *) ((( uint32_t)0x50000000) + 0x0C000))->ISPTRG = 0x1;                    
    do { __schedule_barrier(); __isb(0xF); __schedule_barrier(); } while (0U);                              
    while(((FMC_T *) ((( uint32_t)0x50000000) + 0x0C000))->ISPTRG);                   

     
    if(((FMC_T *) ((( uint32_t)0x50000000) + 0x0C000))->ISPCON & (1ul << 6))
    {
        ((FMC_T *) ((( uint32_t)0x50000000) + 0x0C000))->ISPCON = (1ul << 6);
        return -1;
    }
    return 0;
}










 
static __inline uint32_t FMC_ReadUID(uint8_t u8index)
{
    ((FMC_T *) ((( uint32_t)0x50000000) + 0x0C000))->ISPCMD = 0x04;  
    ((FMC_T *) ((( uint32_t)0x50000000) + 0x0C000))->ISPADR = (u8index << 2);       
    ((FMC_T *) ((( uint32_t)0x50000000) + 0x0C000))->ISPTRG = 0x1;                  
    do { __schedule_barrier(); __isb(0xF); __schedule_barrier(); } while (0U);                            
    while(((FMC_T *) ((( uint32_t)0x50000000) + 0x0C000))->ISPTRG);                 

    return ((FMC_T *) ((( uint32_t)0x50000000) + 0x0C000))->ISPDAT;
}











 
static __inline uint32_t FMC_ReadCID(void)
{
    ((FMC_T *) ((( uint32_t)0x50000000) + 0x0C000))->ISPCMD = 0x0B;            
    ((FMC_T *) ((( uint32_t)0x50000000) + 0x0C000))->ISPADR = 0x0;                            
    ((FMC_T *) ((( uint32_t)0x50000000) + 0x0C000))->ISPTRG = (1ul << 0);           
    do { __schedule_barrier(); __isb(0xF); __schedule_barrier(); } while (0U);                                      
    while(((FMC_T *) ((( uint32_t)0x50000000) + 0x0C000))->ISPTRG & (1ul << 0)) ;   

    return ((FMC_T *) ((( uint32_t)0x50000000) + 0x0C000))->ISPDAT;
}










 
static __inline uint32_t FMC_ReadPID(void)
{
    ((FMC_T *) ((( uint32_t)0x50000000) + 0x0C000))->ISPCMD = 0x0C;           
    ((FMC_T *) ((( uint32_t)0x50000000) + 0x0C000))->ISPADR = 0x04;                          
    ((FMC_T *) ((( uint32_t)0x50000000) + 0x0C000))->ISPTRG = (1ul << 0);          
    do { __schedule_barrier(); __isb(0xF); __schedule_barrier(); } while (0U);                                     
    while(((FMC_T *) ((( uint32_t)0x50000000) + 0x0C000))->ISPTRG & (1ul << 0));   

    return ((FMC_T *) ((( uint32_t)0x50000000) + 0x0C000))->ISPDAT;
}










 
static __inline uint32_t FMC_ReadUCID(uint32_t u32Index)
{
    ((FMC_T *) ((( uint32_t)0x50000000) + 0x0C000))->ISPCMD = 0x04;           
    ((FMC_T *) ((( uint32_t)0x50000000) + 0x0C000))->ISPADR = (0x04 * u32Index) + 0x10;      
    ((FMC_T *) ((( uint32_t)0x50000000) + 0x0C000))->ISPTRG = (1ul << 0);          
    do { __schedule_barrier(); __isb(0xF); __schedule_barrier(); } while (0U);                                     
    while(((FMC_T *) ((( uint32_t)0x50000000) + 0x0C000))->ISPTRG & (1ul << 0));   

    return ((FMC_T *) ((( uint32_t)0x50000000) + 0x0C000))->ISPDAT;
}















 
static __inline void FMC_SetVectorPageAddr(uint32_t u32PageAddr)
{
    ((FMC_T *) ((( uint32_t)0x50000000) + 0x0C000))->ISPCMD = 0x2e;  
    ((FMC_T *) ((( uint32_t)0x50000000) + 0x0C000))->ISPADR = u32PageAddr;        
    ((FMC_T *) ((( uint32_t)0x50000000) + 0x0C000))->ISPTRG = 0x1;                
    do { __schedule_barrier(); __isb(0xF); __schedule_barrier(); } while (0U);                          
    while(((FMC_T *) ((( uint32_t)0x50000000) + 0x0C000))->ISPTRG);               
}














 
static __inline uint32_t FMC_GetVECMAP(void)
{
    return (((FMC_T *) ((( uint32_t)0x50000000) + 0x0C000))->ISPSTA & (0xFFFul << 9));
}

extern void FMC_Open(void);
extern void FMC_Close(void);
extern void FMC_EnableAPUpdate(void);
extern void FMC_DisableAPUpdate(void);
extern void FMC_EnableConfigUpdate(void);
extern void FMC_DisableConfigUpdate(void);
extern void FMC_EnableLDUpdate(void);
extern void FMC_DisableLDUpdate(void);
extern int32_t FMC_ReadConfig(uint32_t *u32Config, uint32_t u32Count);
extern int32_t FMC_WriteConfig(uint32_t *u32Config, uint32_t u32Count);
extern void FMC_SetBootSource(int32_t i32BootSrc);
extern int32_t FMC_GetBootSource(void);
extern uint32_t FMC_ReadDataFlashBaseAddr(void);

   

   

   








#line 12807 "C:\\Keil_v5\\ARM\\PACK\\Nuvoton\\NuMicro_DFP\\1.1.0\\Device\\NUC100\\Include\\NUC100Series.h"
#line 1 "C:\\Keil_v5\\ARM\\PACK\\Nuvoton\\NuMicro_DFP\\1.1.0\\Device\\NUC100\\Driver\\GPIO.h"
 









 











 



 



 


 
 
 





 
 
 






 
 
 



 
 
 






#line 82 "C:\\Keil_v5\\ARM\\PACK\\Nuvoton\\NuMicro_DFP\\1.1.0\\Device\\NUC100\\Driver\\GPIO.h"















 
#line 183 "C:\\Keil_v5\\ARM\\PACK\\Nuvoton\\NuMicro_DFP\\1.1.0\\Device\\NUC100\\Driver\\GPIO.h"


   




 












 













 













 













 













 













 













 














 



















 










 











 










 















 














 
















 














 



void GPIO_SetMode(GPIO_T *port, uint32_t u32PinMask, uint32_t u32Mode);
void GPIO_EnableInt(GPIO_T *port, uint32_t u32Pin, uint32_t u32IntAttribs);
void GPIO_DisableInt(GPIO_T *port, uint32_t u32Pin);


   

   

   







 
#line 12808 "C:\\Keil_v5\\ARM\\PACK\\Nuvoton\\NuMicro_DFP\\1.1.0\\Device\\NUC100\\Include\\NUC100Series.h"
#line 1 "C:\\Keil_v5\\ARM\\PACK\\Nuvoton\\NuMicro_DFP\\1.1.0\\Device\\NUC100\\Driver\\I2C.h"
 









 












 



 



 

 
 
 
#line 48 "C:\\Keil_v5\\ARM\\PACK\\Nuvoton\\NuMicro_DFP\\1.1.0\\Device\\NUC100\\Driver\\I2C.h"




   



 









 










 










 










 










 











 










 











 











 










 


void I2C_ClearTimeoutFlag(I2C_T *i2c);
void I2C_Close(I2C_T *i2c);
void I2C_Trigger(I2C_T *i2c, uint8_t u8Start, uint8_t u8Stop, uint8_t u8Si, uint8_t u8Ack);
void I2C_DisableInt(I2C_T *i2c);
void I2C_EnableInt(I2C_T *i2c);
uint32_t I2C_GetBusClockFreq(I2C_T *i2c);
uint32_t I2C_SetBusClockFreq(I2C_T *i2c, uint32_t u32BusClock);
uint32_t I2C_GetIntFlag(I2C_T *i2c);
uint32_t I2C_GetStatus(I2C_T *i2c);
uint32_t I2C_Open(I2C_T *i2c, uint32_t u32BusClock);
uint8_t I2C_GetData(I2C_T *i2c);
void I2C_SetSlaveAddr(I2C_T *i2c, uint8_t u8SlaveNo, uint8_t u8SlaveAddr, uint8_t u8GCMode);
void I2C_SetSlaveAddrMask(I2C_T *i2c, uint8_t u8SlaveNo, uint8_t u8SlaveAddrMask);
void I2C_EnableTimeout(I2C_T *i2c, uint8_t u8LongTimeout);
void I2C_DisableTimeout(I2C_T *i2c);
void I2C_EnableWakeup(I2C_T *i2c);
void I2C_DisableWakeup(I2C_T *i2c);
void I2C_SetData(I2C_T *i2c, uint8_t u8Data);

   

   

   

#line 12809 "C:\\Keil_v5\\ARM\\PACK\\Nuvoton\\NuMicro_DFP\\1.1.0\\Device\\NUC100\\Include\\NUC100Series.h"
#line 1 "C:\\Keil_v5\\ARM\\PACK\\Nuvoton\\NuMicro_DFP\\1.1.0\\Device\\NUC100\\Driver\\PWM.h"
 








 











 



 



 
#line 43 "C:\\Keil_v5\\ARM\\PACK\\Nuvoton\\NuMicro_DFP\\1.1.0\\Device\\NUC100\\Driver\\PWM.h"
 
 
 






   




 











 
#line 79 "C:\\Keil_v5\\ARM\\PACK\\Nuvoton\\NuMicro_DFP\\1.1.0\\Device\\NUC100\\Driver\\PWM.h"









 










 













 

















 













 














 
















 
#line 186 "C:\\Keil_v5\\ARM\\PACK\\Nuvoton\\NuMicro_DFP\\1.1.0\\Device\\NUC100\\Driver\\PWM.h"


uint32_t PWM_ConfigCaptureChannel(PWM_T *pwm,
                                  uint32_t u32ChannelNum,
                                  uint32_t u32UnitTimeNsec,
                                  uint32_t u32CaptureEdge);
uint32_t PWM_ConfigOutputChannel(PWM_T *pwm,
                                 uint32_t u32ChannelNum,
                                 uint32_t u32Frequncy,
                                 uint32_t u32DutyCycle);
void PWM_Start(PWM_T *pwm, uint32_t u32ChannelMask);
void PWM_Stop(PWM_T *pwm, uint32_t u32ChannelMask);
void PWM_ForceStop(PWM_T *pwm, uint32_t u32ChannelMask);
void PWM_EnableADCTrigger(PWM_T *pwm, uint32_t u32ChannelNum, uint32_t u32Condition);
void PWM_DisableADCTrigger(PWM_T *pwm, uint32_t u32ChannelNum);
void PWM_ClearADCTriggerFlag(PWM_T *pwm, uint32_t u32ChannelNum, uint32_t u32Condition);
uint32_t PWM_GetADCTriggerFlag(PWM_T *pwm, uint32_t u32ChannelNum);
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
void PWM_EnableDutyInt(PWM_T *pwm, uint32_t u32ChannelNum, uint32_t u32IntDutyType);
void PWM_DisableDutyInt(PWM_T *pwm, uint32_t u32ChannelNum);
void PWM_ClearDutyIntFlag(PWM_T *pwm, uint32_t u32ChannelNum);
uint32_t PWM_GetDutyIntFlag(PWM_T *pwm, uint32_t u32ChannelNum);
void PWM_EnablePeriodInt(PWM_T *pwm, uint32_t u32ChannelNum,  uint32_t u32IntPeriodType);
void PWM_DisablePeriodInt(PWM_T *pwm, uint32_t u32ChannelNum);
void PWM_ClearPeriodIntFlag(PWM_T *pwm, uint32_t u32ChannelNum);
uint32_t PWM_GetPeriodIntFlag(PWM_T *pwm, uint32_t u32ChannelNum);



   

   

   







 
#line 12810 "C:\\Keil_v5\\ARM\\PACK\\Nuvoton\\NuMicro_DFP\\1.1.0\\Device\\NUC100\\Include\\NUC100Series.h"
#line 1 "C:\\Keil_v5\\ARM\\PACK\\Nuvoton\\NuMicro_DFP\\1.1.0\\Device\\NUC100\\Driver\\SPI.h"
 









 











 



 



 














#line 52 "C:\\Keil_v5\\ARM\\PACK\\Nuvoton\\NuMicro_DFP\\1.1.0\\Device\\NUC100\\Driver\\SPI.h"







   




 






 







 







 







 







 







 







 








 







 







 







 







 







 








 








 








 







 







 








 








 










 







 







 







 







 







 







 










 







 







 








 








 









 




 
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
uint32_t SPI_GetIntFlag(SPI_T *spi, uint32_t u32Mask);
void SPI_ClearIntFlag(SPI_T *spi, uint32_t u32Mask);
uint32_t SPI_GetStatus(SPI_T *spi, uint32_t u32Mask);





 



 



 




#line 12811 "C:\\Keil_v5\\ARM\\PACK\\Nuvoton\\NuMicro_DFP\\1.1.0\\Device\\NUC100\\Include\\NUC100Series.h"
#line 1 "C:\\Keil_v5\\ARM\\PACK\\Nuvoton\\NuMicro_DFP\\1.1.0\\Device\\NUC100\\Driver\\CRC.h"
 








 











 



 



 
 
 
 





 
 
 





 
 
 




   




 









 










 










 










 













 










 










 



 
void CRC_Open(uint32_t u32Mode, uint32_t u32Attribute, uint32_t u32Seed, uint32_t u32DataLen);
void CRC_StartDMATransfer(uint32_t u32SrcAddr, uint32_t u32ByteCount);
uint32_t CRC_GetChecksum(void);

   

   

   







 
#line 12812 "C:\\Keil_v5\\ARM\\PACK\\Nuvoton\\NuMicro_DFP\\1.1.0\\Device\\NUC100\\Include\\NUC100Series.h"
#line 1 "C:\\Keil_v5\\ARM\\PACK\\Nuvoton\\NuMicro_DFP\\1.1.0\\Device\\NUC100\\Driver\\TIMER.h"
 








 











 



 



 

#line 43 "C:\\Keil_v5\\ARM\\PACK\\Nuvoton\\NuMicro_DFP\\1.1.0\\Device\\NUC100\\Driver\\TIMER.h"

   




 










 












 











 










 
static __inline void TIMER_Start(TIMER_T *timer)
{
    timer->TCSR |= (1ul << 30);
}









 
static __inline void TIMER_Stop(TIMER_T *timer)
{
    timer->TCSR &= ~(1ul << 30);
}










 
static __inline void TIMER_EnableWakeup(TIMER_T *timer)
{
    timer->TCSR |= (1ul << 23);
}









 
static __inline void TIMER_DisableWakeup(TIMER_T *timer)
{
    timer->TCSR &= ~(1ul << 23);
}









 
static __inline void TIMER_EnableCaptureDebounce(TIMER_T *timer)
{
    timer->TEXCON |= (1ul << 6);
}









 
static __inline void TIMER_DisableCaptureDebounce(TIMER_T *timer)
{
    timer->TEXCON &= ~(1ul << 6);
}









 
static __inline void TIMER_EnableEventCounterDebounce(TIMER_T *timer)
{
    timer->TEXCON |= (1ul << 7);
}









 
static __inline void TIMER_DisableEventCounterDebounce(TIMER_T *timer)
{
    timer->TEXCON &= ~(1ul << 7);
}









 
static __inline void TIMER_EnableInt(TIMER_T *timer)
{
    timer->TCSR |= (1ul << 29);
}









 
static __inline void TIMER_DisableInt(TIMER_T *timer)
{
    timer->TCSR &= ~(1ul << 29);
}









 
static __inline void TIMER_EnableCaptureInt(TIMER_T *timer)
{
    timer->TEXCON |= (1ul << 5);
}









 
static __inline void TIMER_DisableCaptureInt(TIMER_T *timer)
{
    timer->TEXCON &= ~(1ul << 5);
}










 
static __inline uint32_t TIMER_GetIntFlag(TIMER_T *timer)
{
    return (timer->TISR & (1ul << 0) ? 1 : 0);
}









 
static __inline void TIMER_ClearIntFlag(TIMER_T *timer)
{
    timer->TISR = (1ul << 0);
}










 
static __inline uint32_t TIMER_GetCaptureIntFlag(TIMER_T *timer)
{
    return timer->TEXISR;
}









 
static __inline void TIMER_ClearCaptureIntFlag(TIMER_T *timer)
{
    timer->TEXISR = (1ul << 0);
}










 
static __inline uint32_t TIMER_GetWakeupFlag(TIMER_T *timer)
{
    return (timer->TISR & (1ul << 1) ? 1 : 0);
}









 
static __inline void TIMER_ClearWakeupFlag(TIMER_T *timer)
{
    timer->TISR = (1ul << 1);
}









 
static __inline uint32_t TIMER_GetCaptureData(TIMER_T *timer)
{
    return timer->TCAP;
}









 
static __inline uint32_t TIMER_GetCounter(TIMER_T *timer)
{
    return timer->TDR;
}

uint32_t TIMER_Open(TIMER_T *timer, uint32_t u32Mode, uint32_t u32Freq);
void TIMER_Close(TIMER_T *timer);
void TIMER_Delay(TIMER_T *timer, uint32_t u32Usec);
void TIMER_EnableCapture(TIMER_T *timer, uint32_t u32CapMode, uint32_t u32Edge);
void TIMER_DisableCapture(TIMER_T *timer);
void TIMER_EnableEventCounter(TIMER_T *timer, uint32_t u32Edge);
void TIMER_DisableEventCounter(TIMER_T *timer);
uint32_t TIMER_GetModuleClock(TIMER_T *timer);

   

   

   







 
#line 12813 "C:\\Keil_v5\\ARM\\PACK\\Nuvoton\\NuMicro_DFP\\1.1.0\\Device\\NUC100\\Include\\NUC100Series.h"
#line 1 "C:\\Keil_v5\\ARM\\PACK\\Nuvoton\\NuMicro_DFP\\1.1.0\\Device\\NUC100\\Driver\\WDT.h"
 








 











 



 



 
 
 
 
#line 42 "C:\\Keil_v5\\ARM\\PACK\\Nuvoton\\NuMicro_DFP\\1.1.0\\Device\\NUC100\\Driver\\WDT.h"

 
 
 





   




 









 










 










 











 











 











 












 










 
static __inline void WDT_Close(void)
{
    ((WDT_T *) ((( uint32_t)0x40000000) + 0x4000))->WTCR = 0;
    return;
}









 
static __inline void WDT_EnableInt(void)
{
    ((WDT_T *) ((( uint32_t)0x40000000) + 0x4000))->WTCR |= (1ul << 6);
    return;
}









 
static __inline void WDT_DisableInt(void)
{
    
    ((WDT_T *) ((( uint32_t)0x40000000) + 0x4000))->WTCR &= ~((1ul << 6) | (1ul << 2) | (1ul << 3) | (1ul << 5));
    return;
}

void WDT_Open(uint32_t u32TimeoutInterval, uint32_t u32ResetDelay, uint32_t u32EnableReset, uint32_t u32EnableWakeup);

   

   

   







 
#line 12814 "C:\\Keil_v5\\ARM\\PACK\\Nuvoton\\NuMicro_DFP\\1.1.0\\Device\\NUC100\\Include\\NUC100Series.h"
#line 1 "C:\\Keil_v5\\ARM\\PACK\\Nuvoton\\NuMicro_DFP\\1.1.0\\Device\\NUC100\\Driver\\WWDT.h"
 








 











 



 



 
 
 
 
#line 50 "C:\\Keil_v5\\ARM\\PACK\\Nuvoton\\NuMicro_DFP\\1.1.0\\Device\\NUC100\\Driver\\WWDT.h"



   




 









 










 











 











 










 












 


void WWDT_Open(uint32_t u32PreScale, uint32_t u32CmpValue, uint32_t u32EnableInt);

   

   

   







 
#line 12815 "C:\\Keil_v5\\ARM\\PACK\\Nuvoton\\NuMicro_DFP\\1.1.0\\Device\\NUC100\\Include\\NUC100Series.h"
#line 1 "C:\\Keil_v5\\ARM\\PACK\\Nuvoton\\NuMicro_DFP\\1.1.0\\Device\\NUC100\\Driver\\RTC.h"
 








 











 



 



 















#line 54 "C:\\Keil_v5\\ARM\\PACK\\Nuvoton\\NuMicro_DFP\\1.1.0\\Device\\NUC100\\Driver\\RTC.h"

#line 62 "C:\\Keil_v5\\ARM\\PACK\\Nuvoton\\NuMicro_DFP\\1.1.0\\Device\\NUC100\\Driver\\RTC.h"







   




 


 
typedef struct
{
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

   




 










 










 










 











 











 










 











 












 













 










 
static __inline void RTC_WaitAccessEnable(void)
{
     
    while((((RTC_T *) ((( uint32_t)0x40000000) + 0x08000))->AER & (1ul << 16)) == (1ul << 16));
    ((RTC_T *) ((( uint32_t)0x40000000) + 0x08000))->AER = 0x0000A965UL;

     
    while((((RTC_T *) ((( uint32_t)0x40000000) + 0x08000))->AER & (1ul << 16)) == 0x0);
}

void RTC_Open(S_RTC_TIME_DATA_T *sPt);
void RTC_Close(void);
void RTC_32KCalibration(int32_t i32FrequencyX100);
void RTC_GetDateAndTime(S_RTC_TIME_DATA_T *sPt);
void RTC_GetAlarmDateAndTime(S_RTC_TIME_DATA_T *sPt);
void RTC_SetDateAndTime(S_RTC_TIME_DATA_T *sPt);
void RTC_SetAlarmDateAndTime(S_RTC_TIME_DATA_T *sPt);
void RTC_SetDate(uint32_t u32Year, uint32_t u32Month, uint32_t u32Day, uint32_t u32DayOfWeek);
void RTC_SetTime(uint32_t u32Hour, uint32_t u32Minute, uint32_t u32Second, uint32_t u32TimeMode, uint32_t u32AmPm);
void RTC_SetAlarmDate(uint32_t u32Year, uint32_t u32Month, uint32_t u32Day);
void RTC_SetAlarmTime(uint32_t u32Hour, uint32_t u32Minute, uint32_t u32Second, uint32_t u32TimeMode, uint32_t u32AmPm);
uint32_t RTC_GetDayOfWeek(void);
void RTC_SetTickPeriod(uint32_t u32TickSelection);
void RTC_EnableInt(uint32_t u32IntFlagMask);
void RTC_DisableInt(uint32_t u32IntFlagMask);
void RTC_EnableSpareRegister(void);
void RTC_DisableSpareRegister(void);
void RTC_EnableSnooperDetection(uint32_t u32PinCondition);
void RTC_DisableSnooperDetection(void);

   

   

   







 
#line 12816 "C:\\Keil_v5\\ARM\\PACK\\Nuvoton\\NuMicro_DFP\\1.1.0\\Device\\NUC100\\Include\\NUC100Series.h"
#line 1 "C:\\Keil_v5\\ARM\\PACK\\Nuvoton\\NuMicro_DFP\\1.1.0\\Device\\NUC100\\Driver\\UART.h"
 









 












 



 



 
    
 
 
 




  
 
 
 

#line 53 "C:\\Keil_v5\\ARM\\PACK\\Nuvoton\\NuMicro_DFP\\1.1.0\\Device\\NUC100\\Driver\\UART.h"

#line 61 "C:\\Keil_v5\\ARM\\PACK\\Nuvoton\\NuMicro_DFP\\1.1.0\\Device\\NUC100\\Driver\\UART.h"

 
 
 
















 
 
 



 
 
 



 
 
 





 
 
 
#line 120 "C:\\Keil_v5\\ARM\\PACK\\Nuvoton\\NuMicro_DFP\\1.1.0\\Device\\NUC100\\Driver\\UART.h"

 
 
 




   




 











 











 












 










 












 












 











 











 











 












 











 












 












 




















 



















 




















 











 
static __inline void UART_CLEAR_RTS(UART_T* uart)
{
    (uart)->MCR |= (1ul << 9);
    (uart)->MCR &= ~(1ul << 1);
}









 
static __inline void UART_SET_RTS(UART_T* uart)
{
    (uart)->MCR |= (1ul << 9) | (1ul << 1);
}










 












 



void UART_ClearIntFlag(UART_T* uart , uint32_t u32InterruptFlag);
void UART_Close(UART_T* uart);
void UART_DisableFlowCtrl(UART_T* uart);
void UART_DisableInt(UART_T*  uart, uint32_t u32InterruptFlag);
void UART_EnableFlowCtrl(UART_T* uart);
void UART_EnableInt(UART_T*  uart, uint32_t u32InterruptFlag);
void UART_Open(UART_T* uart, uint32_t u32baudrate);
uint32_t UART_Read(UART_T* uart, uint8_t *pu8RxBuf, uint32_t u32ReadBytes);
void UART_SetLine_Config(UART_T* uart, uint32_t u32baudrate, uint32_t u32data_width, uint32_t u32parity, uint32_t  u32stop_bits);
void UART_SetTimeoutCnt(UART_T* uart, uint32_t u32TOC);
void UART_SelectIrDAMode(UART_T* uart, uint32_t u32Buadrate, uint32_t u32Direction);
void UART_SelectRS485Mode(UART_T* uart, uint32_t u32Mode, uint32_t u32Addr);
void UART_SelectLINMode(UART_T* uart, uint32_t u32Mode, uint32_t u32BreakLength);
uint32_t UART_Write(UART_T* uart, uint8_t *pu8TxBuf, uint32_t u32WriteBytes);


   

   

   







 

#line 12817 "C:\\Keil_v5\\ARM\\PACK\\Nuvoton\\NuMicro_DFP\\1.1.0\\Device\\NUC100\\Include\\NUC100Series.h"
#line 1 "C:\\Keil_v5\\ARM\\PACK\\Nuvoton\\NuMicro_DFP\\1.1.0\\Device\\NUC100\\Driver\\I2S.h"
 








 











 



 



 





 



 



 



 
#line 57 "C:\\Keil_v5\\ARM\\PACK\\Nuvoton\\NuMicro_DFP\\1.1.0\\Device\\NUC100\\Driver\\I2S.h"

#line 66 "C:\\Keil_v5\\ARM\\PACK\\Nuvoton\\NuMicro_DFP\\1.1.0\\Device\\NUC100\\Driver\\I2S.h"

 



 



   



 
 
 
 








 
static __inline void I2S_ENABLE_TX_ZCD(I2S_T *i2s, uint32_t u32ChMask)
{
    if(u32ChMask == 0)
        i2s->CON |= (1ul << 16);
    else
        i2s->CON |= (1ul << 17);
}









 
static __inline void I2S_DISABLE_TX_ZCD(I2S_T *i2s, uint32_t u32ChMask)
{
    if(u32ChMask == 0)
        i2s->CON &= ~(1ul << 16);
    else
        i2s->CON &= ~(1ul << 17);
}






 







 







 







 







 







 







 







 







 







 







 







 










 
static __inline void I2S_SET_MONO_RX_CHANNEL(I2S_T *i2s, uint32_t u32Ch)
{
    u32Ch == (1ul << 23) ?
    (i2s->CON |= (1ul << 23)) :
    (i2s->CON &= ~(1ul << 23));
}







 







 








 








 







 







 



 
uint32_t I2S_Open(I2S_T *i2s, uint32_t u32MasterSlave, uint32_t u32SampleRate, uint32_t u32WordWidth, uint32_t u32Channels, uint32_t u32DataFormat);
void I2S_Close(I2S_T *i2s);
void I2S_EnableInt(I2S_T *i2s, uint32_t u32Mask);
void I2S_DisableInt(I2S_T *i2s, uint32_t u32Mask);
uint32_t I2S_EnableMCLK(I2S_T *i2s, uint32_t u32BusClock);
void I2S_DisableMCLK(I2S_T *i2s);

   


   

   



 

#line 12818 "C:\\Keil_v5\\ARM\\PACK\\Nuvoton\\NuMicro_DFP\\1.1.0\\Device\\NUC100\\Include\\NUC100Series.h"
#line 1 "C:\\Keil_v5\\ARM\\PACK\\Nuvoton\\NuMicro_DFP\\1.1.0\\Device\\NUC100\\Driver\\USBD.h"
 









 







 



 



 


typedef struct s_usbd_info
{
    const uint8_t *gu8DevDesc;             
    const uint8_t *gu8ConfigDesc;          
    const uint8_t **gu8StringDesc;         
    const uint8_t *gu8HidReportDesc;       

} S_USBD_INFO_T;

extern const S_USBD_INFO_T gsInfo;

   





 







#line 63 "C:\\Keil_v5\\ARM\\PACK\\Nuvoton\\NuMicro_DFP\\1.1.0\\Device\\NUC100\\Driver\\USBD.h"


 




 
#line 82 "C:\\Keil_v5\\ARM\\PACK\\Nuvoton\\NuMicro_DFP\\1.1.0\\Device\\NUC100\\Driver\\USBD.h"

 
#line 91 "C:\\Keil_v5\\ARM\\PACK\\Nuvoton\\NuMicro_DFP\\1.1.0\\Device\\NUC100\\Driver\\USBD.h"

 



 
#line 103 "C:\\Keil_v5\\ARM\\PACK\\Nuvoton\\NuMicro_DFP\\1.1.0\\Device\\NUC100\\Driver\\USBD.h"

 







 



 
 
 














#line 146 "C:\\Keil_v5\\ARM\\PACK\\Nuvoton\\NuMicro_DFP\\1.1.0\\Device\\NUC100\\Driver\\USBD.h"




























   





 










 












 












 











 











 











 











 











 











 











 














 











 














 











 















 












 











 












 












 













 











 













 













 











 










 










 












 















 
static __inline void USBD_MemCopy(uint8_t *dest, uint8_t *src, int32_t size)
{
    while(size--) *dest++ = *src++;
}











 
static __inline void USBD_SetStall(uint8_t epnum)
{
    uint32_t u32CfgAddr;
    uint32_t u32Cfg;
    int i;

    for(i = 0; i < 8; i++)
    {
        u32CfgAddr = (uint32_t)(i << 4) + (uint32_t)&((USBD_T *) ((( uint32_t)0x40000000) + 0x60000))->EP[0].CFG;  
        u32Cfg = *((volatile uint32_t *)(u32CfgAddr));

        if((u32Cfg & 0xf) == epnum)
        {
            u32CfgAddr = (uint32_t)(i << 4) + (uint32_t)&((USBD_T *) ((( uint32_t)0x40000000) + 0x60000))->EP[0].CFGP;  
            u32Cfg = *((volatile uint32_t *)(u32CfgAddr));

            *((volatile uint32_t *)(u32CfgAddr)) = (u32Cfg | (1ul << 1));
            break;
        }
    }
}









 
static __inline void USBD_ClearStall(uint8_t epnum)
{
    uint32_t u32CfgAddr;
    uint32_t u32Cfg;
    int i;

    for(i = 0; i < 8; i++)
    {
        u32CfgAddr = (uint32_t)(i << 4) + (uint32_t)&((USBD_T *) ((( uint32_t)0x40000000) + 0x60000))->EP[0].CFG;  
        u32Cfg = *((volatile uint32_t *)(u32CfgAddr));

        if((u32Cfg & 0xf) == epnum)
        {
            u32CfgAddr = (uint32_t)(i << 4) + (uint32_t)&((USBD_T *) ((( uint32_t)0x40000000) + 0x60000))->EP[0].CFGP;  
            u32Cfg = *((volatile uint32_t *)(u32CfgAddr));

            *((volatile uint32_t *)(u32CfgAddr)) = (u32Cfg & ~(1ul << 1));
            break;
        }
    }
}











 
static __inline uint32_t USBD_GetStall(uint8_t epnum)
{
    uint32_t u32CfgAddr;
    uint32_t u32Cfg;
    int i;

    for(i = 0; i < 8; i++)
    {
        u32CfgAddr = (uint32_t)(i << 4) + (uint32_t)&((USBD_T *) ((( uint32_t)0x40000000) + 0x60000))->EP[0].CFG;  
        u32Cfg = *((volatile uint32_t *)(u32CfgAddr));

        if((u32Cfg & 0xf) == epnum)
        {
            u32CfgAddr = (uint32_t)(i << 4) + (uint32_t)&((USBD_T *) ((( uint32_t)0x40000000) + 0x60000))->EP[0].CFGP;  
            break;
        }
    }

    return ((*((volatile uint32_t *)(u32CfgAddr))) & (1ul << 1));
}


extern volatile uint8_t g_usbd_RemoteWakeupEn;
typedef void (*VENDOR_REQ)(void);            
typedef void (*CLASS_REQ)(void);             
typedef void (*SET_INTERFACE_REQ)(void);     
typedef void (*SET_CONFIG_CB)(void);        

 
void USBD_Open(const S_USBD_INFO_T *param, CLASS_REQ pfnClassReq, SET_INTERFACE_REQ pfnSetInterface);
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
void USBD_SetConfigCallback(SET_CONFIG_CB pfnSetConfigCallback);
void USBD_LockEpStall(uint32_t u32EpBitmap);

   

   

   




 
#line 12819 "C:\\Keil_v5\\ARM\\PACK\\Nuvoton\\NuMicro_DFP\\1.1.0\\Device\\NUC100\\Include\\NUC100Series.h"
#line 1 "C:\\Keil_v5\\ARM\\PACK\\Nuvoton\\NuMicro_DFP\\1.1.0\\Device\\NUC100\\Driver\\PDMA.h"
 









 







 



 



 

 
 
 




 
 
 





 
 
 
#line 63 "C:\\Keil_v5\\ARM\\PACK\\Nuvoton\\NuMicro_DFP\\1.1.0\\Device\\NUC100\\Driver\\PDMA.h"


   



 









 










 











 











 











 











 












 
#line 160 "C:\\Keil_v5\\ARM\\PACK\\Nuvoton\\NuMicro_DFP\\1.1.0\\Device\\NUC100\\Driver\\PDMA.h"









 


void PDMA_Open(uint32_t u32Mask);
void PDMA_Close(void);
void PDMA_SetTransferCnt(uint32_t u32Ch, uint32_t u32Width, uint32_t u32TransCount);
void PDMA_SetTransferAddr(uint32_t u32Ch, uint32_t u32SrcAddr, uint32_t u32SrcCtrl, uint32_t u32DstAddr, uint32_t u32DstCtrl);
void PDMA_SetTransferMode(uint32_t u32Ch, uint32_t u32Periphral, uint32_t u32ScatterEn, uint32_t u32DescAddr);
void PDMA_Trigger(uint32_t u32Ch);
void PDMA_EnableInt(uint32_t u32Ch, uint32_t u32Mask);
void PDMA_DisableInt(uint32_t u32Ch, uint32_t u32Mask);




 



 



 



#line 12820 "C:\\Keil_v5\\ARM\\PACK\\Nuvoton\\NuMicro_DFP\\1.1.0\\Device\\NUC100\\Include\\NUC100Series.h"
#line 1 "C:\\Keil_v5\\ARM\\PACK\\Nuvoton\\NuMicro_DFP\\1.1.0\\Device\\NUC100\\Driver\\SC.h"
 








 











 



 



 
#line 37 "C:\\Keil_v5\\ARM\\PACK\\Nuvoton\\NuMicro_DFP\\1.1.0\\Device\\NUC100\\Driver\\SC.h"

#line 48 "C:\\Keil_v5\\ARM\\PACK\\Nuvoton\\NuMicro_DFP\\1.1.0\\Device\\NUC100\\Driver\\SC.h"


   




 





















 






















 











 
#line 121 "C:\\Keil_v5\\ARM\\PACK\\Nuvoton\\NuMicro_DFP\\1.1.0\\Device\\NUC100\\Driver\\SC.h"











 
#line 141 "C:\\Keil_v5\\ARM\\PACK\\Nuvoton\\NuMicro_DFP\\1.1.0\\Device\\NUC100\\Driver\\SC.h"










 
#line 160 "C:\\Keil_v5\\ARM\\PACK\\Nuvoton\\NuMicro_DFP\\1.1.0\\Device\\NUC100\\Driver\\SC.h"










 
#line 179 "C:\\Keil_v5\\ARM\\PACK\\Nuvoton\\NuMicro_DFP\\1.1.0\\Device\\NUC100\\Driver\\SC.h"







 









 









 








 
static __inline void SC_SetTxRetry(SC_T *sc, uint32_t u32Count)
{
    while((sc)->CTL & (1ul << 30));
    if((u32Count) == 0)         
    {
        (sc)->CTL &= ~((7ul << 20) | (1ul << 23));
    }
    else
    {
        (sc)->CTL = ((sc)->CTL & ~(7ul << 20)) | (((u32Count) - 1) << 20) | (1ul << 23);
    }
}







 
static __inline void  SC_SetRxRetry(SC_T *sc, uint32_t u32Count)
{
    while((sc)->CTL & (1ul << 30));
    if((u32Count) == 0)         
    {
        (sc)->CTL &= ~((7ul << 16) | (1ul << 19));
    }
    else
    {
        (sc)->CTL = ((sc)->CTL & ~(7ul << 16)) | (((u32Count) - 1) << 16) | (1ul << 19);
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


   

   

   







 
#line 12821 "C:\\Keil_v5\\ARM\\PACK\\Nuvoton\\NuMicro_DFP\\1.1.0\\Device\\NUC100\\Include\\NUC100Series.h"
#line 1 "C:\\Keil_v5\\ARM\\PACK\\Nuvoton\\NuMicro_DFP\\1.1.0\\Device\\NUC100\\Driver\\PS2.h"
 








 











 



 




 

 
 
 










 











 











 












 
static __inline void PS2_CLEAR_TX_FIFO(void)
{
    ((PS2_T *) ((( uint32_t)0x40100000) + 0x00000))->PS2CON |= (1ul << 8);
    ((PS2_T *) ((( uint32_t)0x40100000) + 0x00000))->PS2CON &= ~(1ul << 8);
}









 










 











 










 










 










 










 










 










 










 










 










 



 
 
 

void PS2_Open(void);
void PS2_Close(void);
uint8_t PS2_Read(void);
int32_t PS2_Write(uint32_t *pu32Buf, uint32_t u32ByteCount);
void PS2_EnableInt(uint32_t u32Mask);
void PS2_DisableInt(uint32_t u32Mask);


   

   

   







 

#line 12822 "C:\\Keil_v5\\ARM\\PACK\\Nuvoton\\NuMicro_DFP\\1.1.0\\Device\\NUC100\\Include\\NUC100Series.h"
#line 1 "C:\\Keil_v5\\ARM\\PACK\\Nuvoton\\NuMicro_DFP\\1.1.0\\Device\\NUC100\\Driver\\CLK.h"
 









 










 



 



 







 
 
 













 
 
 









#line 74 "C:\\Keil_v5\\ARM\\PACK\\Nuvoton\\NuMicro_DFP\\1.1.0\\Device\\NUC100\\Driver\\CLK.h"

#line 99 "C:\\Keil_v5\\ARM\\PACK\\Nuvoton\\NuMicro_DFP\\1.1.0\\Device\\NUC100\\Driver\\CLK.h"





#line 114 "C:\\Keil_v5\\ARM\\PACK\\Nuvoton\\NuMicro_DFP\\1.1.0\\Device\\NUC100\\Driver\\CLK.h"

#line 125 "C:\\Keil_v5\\ARM\\PACK\\Nuvoton\\NuMicro_DFP\\1.1.0\\Device\\NUC100\\Driver\\CLK.h"

 
 
 










#line 159 "C:\\Keil_v5\\ARM\\PACK\\Nuvoton\\NuMicro_DFP\\1.1.0\\Device\\NUC100\\Driver\\CLK.h"

#line 170 "C:\\Keil_v5\\ARM\\PACK\\Nuvoton\\NuMicro_DFP\\1.1.0\\Device\\NUC100\\Driver\\CLK.h"

#line 181 "C:\\Keil_v5\\ARM\\PACK\\Nuvoton\\NuMicro_DFP\\1.1.0\\Device\\NUC100\\Driver\\CLK.h"

#line 192 "C:\\Keil_v5\\ARM\\PACK\\Nuvoton\\NuMicro_DFP\\1.1.0\\Device\\NUC100\\Driver\\CLK.h"

#line 203 "C:\\Keil_v5\\ARM\\PACK\\Nuvoton\\NuMicro_DFP\\1.1.0\\Device\\NUC100\\Driver\\CLK.h"








 
 
 
#line 226 "C:\\Keil_v5\\ARM\\PACK\\Nuvoton\\NuMicro_DFP\\1.1.0\\Device\\NUC100\\Driver\\CLK.h"


 
 
 






 
 
 





 
 
 










#line 268 "C:\\Keil_v5\\ARM\\PACK\\Nuvoton\\NuMicro_DFP\\1.1.0\\Device\\NUC100\\Driver\\CLK.h"








 
 
 

 

#line 292 "C:\\Keil_v5\\ARM\\PACK\\Nuvoton\\NuMicro_DFP\\1.1.0\\Device\\NUC100\\Driver\\CLK.h"

#line 301 "C:\\Keil_v5\\ARM\\PACK\\Nuvoton\\NuMicro_DFP\\1.1.0\\Device\\NUC100\\Driver\\CLK.h"


#line 399 "C:\\Keil_v5\\ARM\\PACK\\Nuvoton\\NuMicro_DFP\\1.1.0\\Device\\NUC100\\Driver\\CLK.h"


#line 421 "C:\\Keil_v5\\ARM\\PACK\\Nuvoton\\NuMicro_DFP\\1.1.0\\Device\\NUC100\\Driver\\CLK.h"

   




 







 
static __inline uint32_t CLK_GetPLLClockFreq(void)
{
    uint32_t u32PllFreq = 0, u32PllReg;
    uint32_t u32FIN, u32NF, u32NR, u32NO;
    uint8_t au8NoTbl[4] = {1, 2, 2, 4};

    u32PllReg = ((CLK_T *) ((( uint32_t)0x50000000) + 0x00200))->PLLCON;

    if(u32PllReg & ((1ul << 16) | (1ul << 18)))
        return 0;            

    if(u32PllReg & 0x00080000UL)
        u32FIN = (22118400UL);     
    else
        u32FIN = (12000000UL);      

    if(u32PllReg & (1ul << 17))
        return u32FIN;       

     
    u32NO = au8NoTbl[((u32PllReg & (3ul << 14)) >> 14)];
    u32NF = ((u32PllReg & (0x1FFul << 0)) >> 0) + 2;
    u32NR = ((u32PllReg & (0x1Ful << 9)) >> 9) + 2;

     
    u32PllFreq = (((u32FIN >> 2) * u32NF) / (u32NR * u32NO) << 2);

    return u32PllFreq;
}








 
static __inline void CLK_SysTickDelay(uint32_t us)
{
    ((SysTick_Type *) ((0xE000E000UL) + 0x0010UL) )->LOAD = us * CyclesPerUs;
    ((SysTick_Type *) ((0xE000E000UL) + 0x0010UL) )->VAL  = (0x00);
    ((SysTick_Type *) ((0xE000E000UL) + 0x0010UL) )->CTRL = (1UL << 2U) | (1UL );

     
    while((((SysTick_Type *) ((0xE000E000UL) + 0x0010UL) )->CTRL & (1UL << 16U)) == 0);
    
     
    ((SysTick_Type *) ((0xE000E000UL) + 0x0010UL) )->CTRL = 0;    
}


void CLK_DisableCKO(void);
void CLK_EnableCKO(uint32_t u32ClkSrc, uint32_t u32ClkDiv, uint32_t u32ClkDivBy1En);
void CLK_PowerDown(void);
void CLK_Idle(void);
uint32_t CLK_GetHXTFreq(void);
uint32_t CLK_GetLXTFreq(void);
uint32_t CLK_GetHCLKFreq(void);
uint32_t CLK_GetPCLKFreq(void);
uint32_t CLK_GetCPUFreq(void);
uint32_t CLK_SetCoreClock(uint32_t u32Hclk);
void CLK_SetHCLK(uint32_t u32ClkSrc, uint32_t u32ClkDiv);
void CLK_SetModuleClock(uint32_t u32ModuleIdx, uint32_t u32ClkSrc, uint32_t u32ClkDiv);
void CLK_SetSysTickClockSrc(uint32_t u32ClkSrc);
void CLK_EnableXtalRC(uint32_t u32ClkMask);
void CLK_DisableXtalRC(uint32_t u32ClkMask);
void CLK_EnableModuleClock(uint32_t u32ModuleIdx);
void CLK_DisableModuleClock(uint32_t u32ModuleIdx);
uint32_t CLK_EnablePLL(uint32_t u32PllClkSrc, uint32_t u32PllFreq);
void CLK_DisablePLL(void);
uint32_t CLK_WaitClockReady(uint32_t u32ClkMask);


   

   

   







 
#line 12823 "C:\\Keil_v5\\ARM\\PACK\\Nuvoton\\NuMicro_DFP\\1.1.0\\Device\\NUC100\\Include\\NUC100Series.h"
#line 1 "C:\\Keil_v5\\ARM\\PACK\\Nuvoton\\NuMicro_DFP\\1.1.0\\Device\\NUC100\\Driver\\ACMP.h"
 








 











 



 



 

 
 
 
#line 44 "C:\\Keil_v5\\ARM\\PACK\\Nuvoton\\NuMicro_DFP\\1.1.0\\Device\\NUC100\\Driver\\ACMP.h"

   




 







 








 











 








 








 








 








 









 








 








 








 








 



 
void ACMP_Open(ACMP_T *, uint32_t u32ChNum, uint32_t u32NegSrc, uint32_t u32HysteresisEn);
void ACMP_Close(ACMP_T *, uint32_t u32ChNum);

   

   

   







 
#line 12824 "C:\\Keil_v5\\ARM\\PACK\\Nuvoton\\NuMicro_DFP\\1.1.0\\Device\\NUC100\\Include\\NUC100Series.h"






#line 24 "main.c"
#line 1 "WinboundFlash.h"
 








 




 



 



 

 
 
 
extern void Open_SPI_Flash(void);
extern unsigned int SpiFlash_ReadMidDid(void);
extern void SpiFlash_ChipErase(void);
extern unsigned int SpiFlash_ReadStatusReg1(void);
extern unsigned int SpiFlash_ReadStatusReg2(void);
extern void SpiFlash_WaitReady(void);
extern void SpiFlash_PageProgram(unsigned char *DataBuffer, unsigned int StartAddress, unsigned int ByteCount);
extern void SpiFlash_ReadData(unsigned char *DataBuffer, unsigned int StartAddress, unsigned int ByteCount);


   

   

   

 
#line 25 "main.c"
#line 1 "preprocessor.h"
#line 26 "main.c"
#line 27 "main.c"

    uint32_t u32BusClock;
int16_t OUT_Y_H_A,  OUT_X_H_A,  OUT_Z_H_A, OUT_X_L_A, OUT_Y_L_A, OUT_Z_L_A, STATUS_REG_A, CTRL_REG4_A;
int ay,ax,az = -1;
int gy,gx,gz = -1;
float aay,aax,aaz = -1;
int ggy,ggx,ggz = -1;
int simselect = 0; 
char IP1[50] = "104.236.203.4";
char PORT1[10] = "5557";
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
uint8_t antennaselect = 0;
extern uint8_t alertid;
extern int fix;
volatile int g_u32AdcIntFlag;
volatile int netselect;
volatile int ignitionhighlow = 0;
volatile int emergencyhighlow = 0;

uint8_t tmr1sec;
volatile uint32_t wetmr;
volatile int interval_count = 0;
volatile int interval_count_health = 0;
extern volatile int sleepinterval_health;
extern char cregresp[10];
char firmwaresize[20] = 0;
char messagedata[200];
volatile uint8_t input1, input2, input3, input4;
extern   int sleepinterval;
 
 
 




extern volatile int pidcounter;
extern char latitude[12];
extern char longitude[12];
extern char prevlatitude[12];
extern char prevlongitude[12];
extern char gpsdate[7];
extern char gpstime[7];
extern char kmph[6];
extern char heading[8];
extern char alt[8];
extern char sat[3];
extern char latdir[2];
extern char longdir[2];
extern char hdop[6];
extern char pdop[5];
extern char networkoperator[30];
extern char mcc[5];
extern char mnc[5];
extern char lac[5];
extern char cellid[10];
extern char packetstatus;
extern char nmr[200];
 
 
 

char g_u8SendData[2500] = {0};
char g_u8RecData[1000]	= {0};
char g_u8OBDSendData[100] = {0};
char g_u8OBDRecData[100]	= {0};
uint8_t g_u8OBDRecDataptr=0;
int MidDid;
volatile int parameterupgrade = 0;
volatile uint32_t g_u32comRbytes = 0;
volatile uint32_t g_u32comRhead  = 0;
volatile uint32_t g_u32comRtail  = 0;
volatile int32_t g_bWait         = 1;
volatile int notsentcounter= 0;
volatile int triggeruart = 0;
 
 
 
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
__inline void remove_all_alpha(char* str, char c, char d);
extern void supportedpid(char command[5]);
extern  void cpinquerry();
extern int8_t charging, cpinready, cregready;
extern volatile int8_t  network;
extern float pt = 0;
extern volatile int start_thead;
extern osThreadId tid_Thread_OBD_READ;                                          

osThreadId mainThreadID;
extern osThreadId tid_Thread_accgyro_READ;
extern int32_t signal;
extern int32_t signal2;

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
uint32_t os_mutex_cb_uart_mutex[4] = { 0 }; const osMutexDef_t os_mutex_def_uart_mutex = { (os_mutex_cb_uart_mutex) };		
osMutexId	(uart_mutex_id); 
uint32_t os_mutex_cb_tcp_mutex[4] = { 0 }; const osMutexDef_t os_mutex_def_tcp_mutex = { (os_mutex_cb_tcp_mutex) };		
osMutexId	(tcp_mutex_id); 
uint32_t os_mutex_cb_fs_mutex[4] = { 0 }; const osMutexDef_t os_mutex_def_fs_mutex = { (os_mutex_cb_fs_mutex) };		
osMutexId	(fs_mutex_id); 
volatile int wait=0;
volatile uint8_t g_u8DeviceAddr = 0x6B;
volatile uint8_t g_au8TxData[3];
volatile uint8_t g_u8RxData;
volatile uint8_t g_u8DataLen;
volatile uint8_t g_u8EndFlag = 0;
volatile uint32_t u32Status = 0;


 
int main (void) {
  int one = 0;

  SYS_UnlockReg();                          
  SYS_Init();                               
  SYS_LockReg();                            
  TIMER_Open(((TIMER_T *) ((( uint32_t)0x40000000) + 0x10000)), (1UL << 27), 1);
  TIMER_EnableInt(((TIMER_T *) ((( uint32_t)0x40000000) + 0x10000)));
  __NVIC_EnableIRQ(TMR0_IRQn);
  TIMER_Start(((TIMER_T *) ((( uint32_t)0x40000000) + 0x10000)));
  ADC_Open(((ADC_T *) ((( uint32_t)0x40000000) + 0xE0000)), (0UL<<10), (3UL<<2), 0x7f);
  ((((ADC_T *) ((( uint32_t)0x40000000) + 0xE0000)))->ADCR |= (1ul << 0));
  ADC_EnableInt(((ADC_T *) ((( uint32_t)0x40000000) + 0xE0000)), ((1ul << 0)));  
  __NVIC_EnableIRQ(ADC_IRQn);
  Open_SPI_Flash();         
  
  
  cregready  =   Init_Thread ();
  osKernelInitialize ();                    

  SYS_UnlockReg();
  g_u8IsWDTTimeoutINT = 0;
  WWDT_Open((12 << 8), 0x20, 1);  
  WDT_EnableInt();
  __NVIC_EnableIRQ(WDT_IRQn);  
  SYS_LockReg();                            

  
  UARTs_Init();                             
  osKernelStart ();                         
  MidDid = SpiFlash_ReadMidDid();
  MidDid = SpiFlash_ReadMidDid();



  mainThreadID = osThreadGetId();
(*((volatile uint32_t *)(((((( uint32_t)0x50000000) + 0x4000) + 0x0200)+(0x40*(0))) + ((7)<<2)))) = 1;




memset(temp,0,100);

sprintf(temp,"\r\nAT+**********************************%s*******************************\r\n\r\n", "2.1.6");
SendAT(temp, "OK", "NOT INSERTED" , "ERROR",5);
SendAT(temp, "OK", "NOT INSERTED" , "ERROR",5);

SendAT("\r\nAT+QSCLK=1\r\n\r\n", "Ready", "OK" , "ERROR",5);
SendAT("\r\nAT+QSTK?\r\n\r\n", "OK", "NOT INSERTED" , "ERROR",5);
SendAT("\r\nAT+QSTK=1\r\n\r\n", "OK", "NOT INSERTED" , "ERROR",5);



readipconfigurations();
  while (1) {
    
    
    netselect = 1;
    SendAT("\r\nAT+CFUN=1\r\n\r\n", "OK", "NOT INSERTED" , "ERROR",10);
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
        
          {
            SendAT("\r\nAT+CGREG?\r\n\r\n", "Ready", "OK" , "ERROR",5);
            if(netselect == 1){
              SendAT("\r\nAT+STKTR=\"810301218082028281830100\"\r\n", "+STKPCI: 0", "NAK" , "NAK",2);   
              manualdelay(5);
              memset(configdata,0,300);
              parse_g(g_u8RecData,3,4,'"','"',configdata);  
              hextoascii(configdata,strlen(configdata));
              
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
                
                if(strstr(DestArray,"National(ON)")){
                  simselect = 1;
                }else if(strstr(DestArray,"International(ON)")){
                  simselect = 2;
                }
              }
              
              memset(temp,0,100);
              if(simselect == 1){
                sprintf(temp,"\r\nAT+QIREGAPP=\"%s\",\"\",\"\"\r\n\r\n",apn1);
              }else if(simselect == 2){
                sprintf(temp,"\r\nAT+QIREGAPP=\"%s\",\"\",\"\"\r\n\r\n",apn2);          
              }
            }else{
              sprintf(temp,"\r\nAT+QIREGAPP=\"%s\",\"\",\"\"\r\n\r\n","www");      
            }
            SendAT(temp, "Ready", "OK" , "ERROR",5);	
            SendAT("\r\nAT+QIACT\r\n\r\n", "Ready", "OK" , "ERROR",10);	
            if(timeoutflag != 0){
                SendAT("\r\nAT+CFUN=1,1\r\n\r\n", "ERROR", "OK" , "ERROR",1);
              
                (*((volatile uint32_t *)(((((( uint32_t)0x50000000) + 0x4000) + 0x0200)+(0x40*(1))) + ((15)<<2)))) = 0;
                manualdelay(1);
                (*((volatile uint32_t *)(((((( uint32_t)0x50000000) + 0x4000) + 0x0200)+(0x40*(1))) + ((15)<<2)))) = 1;
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
                
                SYS_UnlockReg();                          
                ((GCR_T *) ((( uint32_t)0x50000000) + 0x00000))->IPRSTC1 = 0x1;  
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
      sprintf(temp,"\n\n$%s$%s$%s$%s$%s\n%c",vehicleregnum,imei,"2.1.6","1.0.0",lastlocation,0x1A);
      loginpacket = 1;
      TCP_Send("\r\nAT+QISEND=0\r\n\r\n\r\n",temp,">","ERROR","SEND OK",10);	
      loginpacket = 0;
    }    
    memset(temp,0,100);
    sprintf(temp,"\r\nAT+QIOPEN=1,\"TCP\",\"%s\",\"%s\"\r\n\r\n",IP2,PORT2);
    SendAT(temp,"CONNECT","ERROR","FAIL",10);
    if((network == 1) && strstr(g_u8RecData,"CONNECT OK")){
      memset(temp,0,100);
      sprintf(temp,"$%s$%s$%s$%s$%s\n%c",vehicleregnum,imei,"2.1.6","1.0.0",lastlocation,0x1A);
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
      if(alertid == 10){
        memset(temp, 0, 100);
        sprintf(temp, "%s,%s,%s,%s,%s,%d,%s,%s,%s,%s,%s",imei, latitude, latdir, longitude, longdir,  fix, kmph, cellid , lac, gpsdate, gpstime);
        send_sms(emernum1, temp);
        send_sms(emernum2, temp);
      }
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
      wait = 0;
      do{
        sms_mc60(); 
      }while(wait < 2);
      Save_FS();
      SendAT("\r\nAT+QIDEACT\r\n\r\n", "OK", "DEACT OK" , "ERROR",10);
      SendAT("\r\nAT+QIMODE=0\r\n\r\n", "OK", "NOT INSERTED" , "ERROR",5);
      SendAT("\r\nAT+QIMUX?\r\n\r\n", "OK", "NOT INSERTED" , "ERROR",5);	
      SendAT("\r\nAT+QIMUX=1\r\n\r\n", "OK", "NOT INSERTED" , "ERROR",5);
      
    }
    else{
      
        
           SendAT("\r\nAT+QGEPOF=0,255\r\n\r\n", "OK", "NOT INSERTED" , "ERROR",5);
           
               
        
      
        if(interval_count > 10000)interval_count = 0;     
        if(interval_count_health > 10000)interval_count_health = 0;     
        if(tc > 10000)tc = 0;     
        if(tmr0sec > 10000)tmr0sec = 0;     
        if(tcpsendchtimer > 10000)tcpsendchtimer = 0;     
        if(i2ctimeout > 10000)i2ctimeout = 0;
        if(wetmr > 10000)wetmr = 0;
        if(ignition == 1){
          sleepinterval = sleepinterval_i1;
        }else{
          sleepinterval = sleepinterval_i0;      
        }
        
        one = 1;
        while((interval_count_health < sleepinterval_health) && (interval_count < sleepinterval)){






          (*((volatile uint32_t *)(((((( uint32_t)0x50000000) + 0x4000) + 0x0200)+(0x40*(1))) + ((7)<<2)))) = 0;
          if((*((volatile uint32_t *)(((((( uint32_t)0x50000000) + 0x4000) + 0x0200)+(0x40*(1))) + ((6)<<2)))) == 0){
            sms_mc60();
          }
        }
        one = 0;

    }
  }
}

__inline void networkswitch(){
 int timout = 0;
  _NETSWITCH:
  timout++;
  if(timout > 0){
    SendAT("\r\nAT+CFUN=1,1\r\n\r\n", "ERROR", "OK" , "ERROR",1);
    goto __RETURN;
  }
  SendAT("\r\nAT+CFUN=1,1\r\n\r\n", "ERROR", "OK" , "ERROR",1);
  
  (*((volatile uint32_t *)(((((( uint32_t)0x50000000) + 0x4000) + 0x0200)+(0x40*(1))) + ((15)<<2)))) = 0;
  manualdelay(1);
  (*((volatile uint32_t *)(((((( uint32_t)0x50000000) + 0x4000) + 0x0200)+(0x40*(1))) + ((15)<<2)))) = 1;
  manualdelay(50);      
  SendAT("\r\nAT\r\n", "+STKPCI", "NAK" , "NAK",40);
  manualdelay(50);
  SendAT("\r\nAT+COPS?\r\n", "OK", "NAK" , "NAK",40);
  
  SendAT("\r\nAT+STKTR=\"810301250082028281830100\"\r\n", "+STKPCI:", "NAK" , "NAK",40);
  manualdelay(50);
  
  SendAT("\r\nAT+STKENV=\"D30782020181900101\"\r\n", "+STKPCI: 0", "NAK" , "NAK",40);
  manualdelay(50);
  memset(configdata,0,300);
  parse_g(g_u8RecData,3,4,'"','"',configdata);  
  hextoascii(configdata,strlen(configdata));
  
  if(strstr(DestArray,"National(ON)")){
    simselect = 1;
    SendAT("\r\nAT+STKTR=\"810301240082028281830100900102\"\r\n", "+STKPCI: 0", "NAK" , "NAK",40);   
  }else if(strstr(DestArray,"International(ON)")){
    simselect = 2;
    SendAT("\r\nAT+STKTR=\"810301240082028281830100900101\"\r\n", "+STKPCI: 0", "NAK" , "NAK",40);   
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
  
  SendAT("\r\nAT+STKTR=\"810301218082028281830100\"\r\n", "+STKPCI: 0", "NAK" , "NAK",40);   
  manualdelay(50);
  memset(configdata,0,300);
  parse_g(g_u8RecData,3,4,'"','"',configdata);    
  hextoascii(configdata,strlen(configdata));
  if(!strstr(DestArray, "Refreshing.")){
    goto _NETSWITCH;
  }    
  
  SendAT("\r\nAT+CFUN=1,1\r\n\r\n", "ERROR", "OK" , "ERROR",1);

  (*((volatile uint32_t *)(((((( uint32_t)0x50000000) + 0x4000) + 0x0200)+(0x40*(1))) + ((15)<<2)))) = 0;
  manualdelay(1);
  (*((volatile uint32_t *)(((((( uint32_t)0x50000000) + 0x4000) + 0x0200)+(0x40*(1))) + ((15)<<2)))) = 1;
  manualdelay(100);      
  SendAT("\r\nAT\r\n", "+STKPCI: 0", "NAK" , "NAK",40);
  manualdelay(100);   
  __RETURN:
}

__inline void accgyroconfig(void){

  
  

  
  
  
  
  
}

__inline float binTwosComplementToSignedDecimal(int data,int significantBits) 
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
 while(1){








 


   
    osSignalWait (0x0001, 0xFFFFFFFFU);  
   {
    ax = ((I2C_Read(0x29) << 8) | I2C_Read(0x28));
    ay = ((I2C_Read(0x2B) << 8) | I2C_Read(0x2A));
    az = ((I2C_Read(0x2D) << 8) | I2C_Read(0x2C));

    aax = binTwosComplementToSignedDecimal(ax, 16)*0.00061;
    aay = binTwosComplementToSignedDecimal(ay, 16)*0.00061;
    aaz = binTwosComplementToSignedDecimal(az, 16)*0.00061;

    
    gx = ((I2C_Read(0x23) << 8) | I2C_Read(0x22));
    gy = ((I2C_Read(0x25) << 8) | I2C_Read(0x24));
    gz = ((I2C_Read(0x27) << 8) | I2C_Read(0x26));
   
    ggx = binTwosComplementToSignedDecimal(gx, 16)*0.00763;
    ggy = binTwosComplementToSignedDecimal(gy, 16)*0.00763;
    ggz = binTwosComplementToSignedDecimal(gz, 16)*0.00763;
    
    
  }osSignalClear (tid_Thread_accgyro_READ, 0x0001);
  
 }
 
}

__inline uint8_t I2C_Write(uint16_t u16Address, uint8_t u8Data)
{
  u32Status=0;
  ((((I2C_T *) ((( uint32_t)0x40000000) + 0x20000)))->I2CON = ((((I2C_T *) ((( uint32_t)0x40000000) + 0x20000)))->I2CON & ~0x3c) | 0x20UL);
  i2ctimeout = 0;
  while((u32Status != 0x08) && (i2ctimeout == 0)){
    u32Status = ((((I2C_T *) ((( uint32_t)0x40000000) + 0x20000)))->I2CSTATUS);   
  }    
  ((((I2C_T *) ((( uint32_t)0x40000000) + 0x20000)))->I2CDAT = ((g_u8DeviceAddr << 1)));   
  ((((I2C_T *) ((( uint32_t)0x40000000) + 0x20000)))->I2CON = ((((I2C_T *) ((( uint32_t)0x40000000) + 0x20000)))->I2CON & ~0x3c) | 0x08UL);
  i2ctimeout = 0;while((u32Status != 0x18) && (i2ctimeout == 0)){
    u32Status = ((((I2C_T *) ((( uint32_t)0x40000000) + 0x20000)))->I2CSTATUS);   
  }    
  ((((I2C_T *) ((( uint32_t)0x40000000) + 0x20000)))->I2CDAT = ((u16Address) ));   
  ((((I2C_T *) ((( uint32_t)0x40000000) + 0x20000)))->I2CON = ((((I2C_T *) ((( uint32_t)0x40000000) + 0x20000)))->I2CON & ~0x3c) | 0x08UL);  
  i2ctimeout = 0;while((u32Status != 0x28) && (i2ctimeout == 0)){
    u32Status = ((((I2C_T *) ((( uint32_t)0x40000000) + 0x20000)))->I2CSTATUS);   
  }    
  u32Status = 0;
  ((((I2C_T *) ((( uint32_t)0x40000000) + 0x20000)))->I2CDAT = ((u8Data)));  
  ((((I2C_T *) ((( uint32_t)0x40000000) + 0x20000)))->I2CON = ((((I2C_T *) ((( uint32_t)0x40000000) + 0x20000)))->I2CON & ~0x3c) | 0x08UL);  
  i2ctimeout = 0;while((u32Status != 0x28) && (i2ctimeout == 0)){
    u32Status = ((((I2C_T *) ((( uint32_t)0x40000000) + 0x20000)))->I2CSTATUS);   
  }    
  ((((I2C_T *) ((( uint32_t)0x40000000) + 0x20000)))->I2CON = ((((I2C_T *) ((( uint32_t)0x40000000) + 0x20000)))->I2CON & ~0x3c) | 0x10UL | 0x08UL);  
  return 0;
}







 
__inline uint8_t I2C_Read(uint16_t u16Address){
  ((((I2C_T *) ((( uint32_t)0x40000000) + 0x20000)))->I2CON = ((((I2C_T *) ((( uint32_t)0x40000000) + 0x20000)))->I2CON & ~0x3c) | 0x20UL);
  i2ctimeout = 0;
  
  u32Status = ((((I2C_T *) ((( uint32_t)0x40000000) + 0x20000)))->I2CSTATUS);
  while((u32Status != 0x08) && (i2ctimeout == 0)){
    u32Status = ((((I2C_T *) ((( uint32_t)0x40000000) + 0x20000)))->I2CSTATUS);    
  }
  ((((I2C_T *) ((( uint32_t)0x40000000) + 0x20000)))->I2CDAT = ((g_u8DeviceAddr << 1)| (0x00)));   
  ((((I2C_T *) ((( uint32_t)0x40000000) + 0x20000)))->I2CON = ((((I2C_T *) ((( uint32_t)0x40000000) + 0x20000)))->I2CON & ~0x3c) | 0x08UL);
  i2ctimeout = 0;
  while((u32Status != 0x18) && (i2ctimeout == 0)){
    u32Status = ((((I2C_T *) ((( uint32_t)0x40000000) + 0x20000)))->I2CSTATUS);
  }
  
  
  ((((I2C_T *) ((( uint32_t)0x40000000) + 0x20000)))->I2CDAT = ((u16Address)));   
  ((((I2C_T *) ((( uint32_t)0x40000000) + 0x20000)))->I2CON = ((((I2C_T *) ((( uint32_t)0x40000000) + 0x20000)))->I2CON & ~0x3c) | 0x08UL);  
  i2ctimeout = 0;
  while((u32Status != 0x28) && (i2ctimeout == 0)){
    u32Status = ((((I2C_T *) ((( uint32_t)0x40000000) + 0x20000)))->I2CSTATUS);    
  }
  
  
  ((((I2C_T *) ((( uint32_t)0x40000000) + 0x20000)))->I2CON = ((((I2C_T *) ((( uint32_t)0x40000000) + 0x20000)))->I2CON & ~0x3c) | 0x20UL | 0x08UL);
  i2ctimeout = 0;
  while((u32Status != 0x10) && (i2ctimeout == 0)){
    u32Status = ((((I2C_T *) ((( uint32_t)0x40000000) + 0x20000)))->I2CSTATUS);
  }    
  

  ((((I2C_T *) ((( uint32_t)0x40000000) + 0x20000)))->I2CDAT = ((g_u8DeviceAddr << 1) | (0x01) ));   
  ((((I2C_T *) ((( uint32_t)0x40000000) + 0x20000)))->I2CON = ((((I2C_T *) ((( uint32_t)0x40000000) + 0x20000)))->I2CON & ~0x3c) | 0x08UL);
  i2ctimeout = 0;
  while((u32Status != 0x40) && (i2ctimeout == 0)){
    u32Status = ((((I2C_T *) ((( uint32_t)0x40000000) + 0x20000)))->I2CSTATUS);    
  }
  

  ((((I2C_T *) ((( uint32_t)0x40000000) + 0x20000)))->I2CON = ((((I2C_T *) ((( uint32_t)0x40000000) + 0x20000)))->I2CON & ~0x3c) | 0x08UL);  
  i2ctimeout = 0;
  while((u32Status != 0x58) && (i2ctimeout == 0)){
    u32Status = ((((I2C_T *) ((( uint32_t)0x40000000) + 0x20000)))->I2CSTATUS);    
  }
  

  g_u8RxData = ((((I2C_T *) ((( uint32_t)0x40000000) + 0x20000)))->I2CDAT);
  ((((I2C_T *) ((( uint32_t)0x40000000) + 0x20000)))->I2CON = ((((I2C_T *) ((( uint32_t)0x40000000) + 0x20000)))->I2CON & ~0x3c) | 0x10UL | 0x08UL);  
  return g_u8RxData;
}




__inline void sms_mc60(void){
  char epolatlong[30] = {0};
  int smsreq=0;
  int del = 0;
  if(ring = 1){
	
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
      
      SendAT("\r\nAT+CMGD=1,4\r\n\r\n", "OK", "ERROR", "7103", 10);
      SendAT("\r\nAT+CFUN=1,1\r\n\r\n", "ERROR", "OK" , "ERROR",1);

      (*((volatile uint32_t *)(((((( uint32_t)0x50000000) + 0x4000) + 0x0200)+(0x40*(1))) + ((15)<<2)))) = 0;
      manualdelay(1);
      (*((volatile uint32_t *)(((((( uint32_t)0x50000000) + 0x4000) + 0x0200)+(0x40*(1))) + ((15)<<2)))) = 1;
      manualdelay(50);       
      
      SYS_UnlockReg();                          
      ((GCR_T *) ((( uint32_t)0x50000000) + 0x00000))->IPRSTC1 = 0x1;        
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
    else if(strstr(g_u8RecData,"SETBATTHRESH")){
      parameterupgrade = 1;
      memset(temp,0,100);
      parse_g(g_u8RecData,9,10,'"','"',temp);  
      batteryvoltagethreshold = atof(temp); 
      saveipconfigurations();  
      sprintf(messagedata,"Battery Alert below \"%.1f\" volts configured and saved",batteryvoltagethreshold);
      send_sms(sender_num, messagedata);          
    }
    else if(strstr(g_u8RecData,"SETSIMSWITCH")){
      parameterupgrade = 1;
      memset(temp,0,100);
      
      
      networkswitch();
      send_sms(sender_num, imei);  
      manualdelay(500);
    }     
    else if(strstr(g_u8RecData,"GETIMEI")){
      send_sms(sender_num, imei);
    }
    else if(strstr(g_u8RecData,"EPO")){
      memset(epolatlong,0,30);
      parse_g(g_u8RecData,9,10,'"','"',epolatlong);        
      SendAT("\r\nAT+CREG?;+CGREG?\r\n\r\n", "OK", "ERROR", "7103", 10);
      memset(cregresp,0,10);
      parse_g(g_u8RecData, 1, 1, ',', 'O' , cregresp);
      remove_all_chars(cregresp,'\r','\n');      
      if(strstr(g_u8RecData,"1") || strstr(g_u8RecData, "5"))
        {
          memset(temp,0,100);
          sprintf(temp,"\r\nAT+QGREFLOC=%s\r\n\r\n",epolatlong);
          SendAT(temp, "OK", "ERROR", "7103", 10);
          SendAT("\r\nAT+QGNSSEPO=1\r\n\r\n", "OK", "ERROR", "7103", 10);
          SendAT("\r\nAT+QGEPOAID=1\r\n\r\n", "OK", "ERROR", "7103", 10);
      }
    }        
     else if(strstr(g_u8RecData,"ANTENNA")){
      memset(epolatlong,0,30);
      parse_g(g_u8RecData,9,10,'"','"',epolatlong);        
      if(strstr(epolatlong,"EXT")){
        antennaselect = 0;
      }else if(strstr(epolatlong,"INT")){
        antennaselect = 1;
      }        
      saveipconfigurations(); 
    }       
     else if(strstr(g_u8RecData,"DEFAULT")){
        memset(IP1,0,50);
        strcat(IP1,"104.236.203.4");
        memset(PORT1,0,10);
        strcat(PORT1,"5557");
        memset(PORT2,0,10);
        memset(IP2,0,50);
        strcat(IP1,"104.236.203.4");
        strcat(PORT1,"5557");    
        memset(vehicleregnum,0,15);
        strcat(vehicleregnum,"BR15AN1526");

        memset(apn1,0,20);
        memset(apn2,0,20);
        strcat(apn1,"airtelgprs.com");
        strcat(apn2,"internet");
        sleepinterval_i1 = 30;
        sleepinterval_i0 = 30;

        saveipconfigurations(); 
    } 
     else if(strstr(g_u8RecData,"SETVENDORID")){
      memset(temp,0,100);
      parse_g(g_u8RecData,9,10,'"','"',temp);        
      
      saveipconfigurations(); 
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
  memset(g_u8RecData,0,1000);
  clear();
  printf(content);
  printf("%c",0x1A); 
  printf("%c",0x1A); 
  printf("%c",0x1A); 
  do{
  g_u8RecData[0] = '\r';
	}while(!(strstr(g_u8RecData, "OK") || strstr(g_u8RecData, "ERROR") || strstr(g_u8RecData, "CME") ||((tmr0sec >= 5))));	 
  

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
    if((strlen(IP1) < 4) || (strlen(IP2) < 4)|| (strlen(PORT1) < 1) || (strlen(PORT2) < 1) || (strlen(vehicleregnum) < 4)){

      
      SYS_UnlockReg();                          
      ((GCR_T *) ((( uint32_t)0x50000000) + 0x00000))->IPRSTC1 = 0x1;  
    
      memset(IP1,0,50);
      memset(IP2,0,50);
      memset(PORT1,0,7);
      memset(PORT2,0,7);
      memset(vehicleregnum,0,15);
      strcat(IP1, "203.129.207.124");
      strcat(IP2, "104.236.203.4");
      strcat(PORT1, "1025");
      strcat(PORT2, "5557");
      strcat(vehicleregnum, "DL1PC5498");
      send_sms("8287324005", "bhasad hai");
      sleepinterval_i1 = 30;
      sleepinterval_i0 = 30;
      sleepinterval_health = 900;
  }    
    
    
    memset(fileinstance,0,20);
    SendAT("\r\nAT+QFDEL=\"IPCONFIG.TXT\"\r\n", "ERROR", "OK" , "4010",10);
    while(strstr(g_u8RecData,"ERROR")){
      SendAT("\r\nAT+CFUN=1,1\r\n\r\n", "ERROR", "OK" , "ERROR",1);
      (*((volatile uint32_t *)(((((( uint32_t)0x50000000) + 0x4000) + 0x0200)+(0x40*(1))) + ((15)<<2)))) = 0;
        manualdelay(1);
      (*((volatile uint32_t *)(((((( uint32_t)0x50000000) + 0x4000) + 0x0200)+(0x40*(1))) + ((15)<<2)))) = 1;
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
      SendAT("\r\nAT+CFUN=1,1\r\n\r\n", "ERROR", "OK" , "ERROR",1);
      (*((volatile uint32_t *)(((((( uint32_t)0x50000000) + 0x4000) + 0x0200)+(0x40*(1))) + ((15)<<2)))) = 0;
        manualdelay(1);
      (*((volatile uint32_t *)(((((( uint32_t)0x50000000) + 0x4000) + 0x0200)+(0x40*(1))) + ((15)<<2)))) = 1;
      manualdelay(100);      
      SendAT("\r\nAT\r\n", "ERROR", "OK" , "4010",10);
      manualdelay(20);
      SendAT("\r\nAT\r\n", "ERROR", "CFUN: " , "4010",10);
      SendAT("\r\nAT+QFOPEN=\"IPCONFIG.TXT\",0\r\n", "ERROR", "OK" , "ERROR",10);
      
    
    }      
      parse_g(g_u8RecData, 1, 1, ' ', 'K' , fileinstance);
      remove_all_chars(fileinstance, '\r', '\n'); 
      remove_all_chars(fileinstance, 'O', 'K');   
    
    
    memset(temp,0,100);
    sprintf(temp, "AT+QFSEEK=%s,0,0\r\n\r\n", fileinstance);
    SendAT(temp, "CONNECT", "OK" , "ERROR",10);	  

    memset(configdata,0,300);
    sprintf(configdata,"|IP1|%s|P1|%s|IP2|%s|P2|%s|F_R_P|%.0f|F_W_P|%.0f|I1_NR|%d|L_PLT|%s|APN1|%s|OS|%.1f|HA|%.1f|HB|%.1f|RT|%.1f|I_HLT|%d|I0_NR|%d|I_EM|%d|B_V_T|%.1f|net|%d|APN2|%s|ant|%d|\n",                         IP1,PORT1,IP2,PORT2,readpt,pt,sleepinterval_i1,vehicleregnum,apn1,overspeed,harshacc,harshbrake,rashturn,sleepinterval_health,sleepinterval_i0,wakeinterval_emer,batteryvoltagethreshold,netselect,apn2,antennaselect);

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
SendAT("\r\nAT+QICLOSE=0\r\n\r\n","CLOSE OK\r\n","ERROR","FAIL",10);	
SendAT("\r\nAT+QICLOSE=1\r\n\r\n","CLOSE OK\r\n","ERROR","FAIL",10);	

return 0;
}
__inline void readipconfigurations(void){
  int retry = 1;
  int len;
  char pt_c[10] = 0;
  char readpt_c[10] = 0;
  char interval_c[10] = 0;
  __READCONFIG:
  do{    
    manualdelay(10);
    memset(fileinstance,0,20);
    SendAT("\r\nAT+QFOPEN=\"IPCONFIG.TXT\",0\r\n", "ERROR", "OK\r\n" , "ERROR",10);	
    if(!strstr(g_u8RecData, "OK")){
      SendAT("\r\nAT+CFUN=1,1\r\n\r\n", "ERROR", "OK" , "ERROR",1);
      (*((volatile uint32_t *)(((((( uint32_t)0x50000000) + 0x4000) + 0x0200)+(0x40*(1))) + ((15)<<2)))) = 0;
        manualdelay(1);
      (*((volatile uint32_t *)(((((( uint32_t)0x50000000) + 0x4000) + 0x0200)+(0x40*(1))) + ((15)<<2)))) = 1;
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
    remove_all_alpha(fileinstance, 'O', 'K'); 
    if(strlen(fileinstance)<1)retry = 1;
    else{
      
      manualdelay(10);
      memset(temp,0,100);
      sprintf(temp, "AT+QFSEEK=%s,0,0\r\n\r\n", fileinstance);
      SendAT(temp, "CONNECT", "OK" , "ERROR",10);	    
      memset(temp,0,100);
      manualdelay(10);
      sprintf(temp, "AT+QFREAD=%s\r\n\r\n", fileinstance);
      SendAT(temp, "OK", "OK" , "ERROR",10);	    
      if(!strstr(g_u8RecData, "CONNECT")){
        goto __READCONFIG;
      }
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
      memset(temp,0,100);
      parse_g(g_u8RecData, 40,41,'|','|', temp);      
      antennaselect = atoi(temp);
      
      (*((volatile uint32_t *)(((((( uint32_t)0x50000000) + 0x4000) + 0x0200)+(0x40*(1))) + ((8)<<2)))) = antennaselect;
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























}
__inline void SYS_Init(void)
{
     
     
     


     
    CLK_EnableXtalRC((1ul << 2));

     
    CLK_WaitClockReady((1ul << 4));

     
    CLK_SetHCLK((0x7UL<<0), ((1)-1));

     
    CLK_EnableXtalRC((1ul << 0));

     
    CLK_WaitClockReady((1ul << 0));

     
    CLK_SetCoreClock(50000000);

     
    CLK_EnableModuleClock(((((1) & 0x03) << 30)|(((16) & 0x1f) << 0)| (((1) & 0x03) << 28)|(((3) & 0x07) << 25)|(((24) & 0x1f) << 20)| (((0) & 0x03) << 18)|(((0x0F) & 0xff) << 10)|(((8) & 0x1f) << 5)));

     
    CLK_SetModuleClock(((((1) & 0x03) << 30)|(((16) & 0x1f) << 0)| (((1) & 0x03) << 28)|(((3) & 0x07) << 25)|(((24) & 0x1f) << 20)| (((0) & 0x03) << 18)|(((0x0F) & 0xff) << 10)|(((8) & 0x1f) << 5)), (0x3UL<<24), (((1)-1) << 8));
    
     
    CLK_EnableModuleClock(((((1) & 0x03) << 30)|(((17) & 0x1f) << 0)| (((1) & 0x03) << 28)|(((3) & 0x07) << 25)|(((24) & 0x1f) << 20)| (((0) & 0x03) << 18)|(((0x0F) & 0xff) << 10)|(((8) & 0x1f) << 5)));

     
    CLK_SetModuleClock(((((1) & 0x03) << 30)|(((17) & 0x1f) << 0)| (((1) & 0x03) << 28)|(((3) & 0x07) << 25)|(((24) & 0x1f) << 20)| (((0) & 0x03) << 18)|(((0x0F) & 0xff) << 10)|(((8) & 0x1f) << 5)), (0x3UL<<24), (((1)-1) << 8));
    
     
    CLK_EnableModuleClock(((((1) & 0x03) << 30)|(((18) & 0x1f) << 0)| (((1) & 0x03) << 28)|(((3) & 0x07) << 25)|(((24) & 0x1f) << 20)| (((0) & 0x03) << 18)|(((0x0F) & 0xff) << 10)|(((8) & 0x1f) << 5)));

     
    CLK_SetModuleClock(((((1) & 0x03) << 30)|(((18) & 0x1f) << 0)| (((1) & 0x03) << 28)|(((3) & 0x07) << 25)|(((24) & 0x1f) << 20)| (((0) & 0x03) << 18)|(((0x0F) & 0xff) << 10)|(((8) & 0x1f) << 5)), (0x3UL<<24), (((1)-1) << 8));

     
    CLK_EnableModuleClock(((((1) & 0x03) << 30)|(((8) & 0x1f) << 0) | (((0x0) & 0x03) << 28)|(((0x0) & 0x07) << 25)|(((0x0) & 0x1f) << 20)| (((0x0) & 0x03) << 18)|(((0x0) & 0xff) << 10)|(((0x0) & 0x1f) << 5)));
    
     
    ((GCR_T *) ((( uint32_t)0x50000000) + 0x00000))->GPA_MFP &= ~((1UL<<8) | (1UL<<9));
    ((GCR_T *) ((( uint32_t)0x50000000) + 0x00000))->GPA_MFP |= (1UL<<8) | (1UL<<9);

    CLK_EnableModuleClock(((((1) & 0x03) << 30)|(((0) & 0x1f) << 0) | (((2) & 0x03) << 28)|(((3) & 0x07) << 25)|(((16) & 0x1f) << 20)| (((0x0) & 0x03) << 18)|(((0x0) & 0xff) << 10)|(((0x0) & 0x1f) << 5)));         
     
    CLK_SetModuleClock(((((1) & 0x03) << 30)|(((0) & 0x1f) << 0) | (((2) & 0x03) << 28)|(((3) & 0x07) << 25)|(((16) & 0x1f) << 20)| (((0x0) & 0x03) << 18)|(((0x0) & 0xff) << 10)|(((0x0) & 0x1f) << 5)), (0x2UL<<16), 0);    
     
    CLK_SetModuleClock(((((1) & 0x03) << 30)|(((28) & 0x1f) << 0) | (((1) & 0x03) << 28)|(((3) & 0x07) << 25)|(((2) & 0x1f) << 20)| (((0) & 0x03) << 18)|(((0xFF) & 0xff) << 10)|(((16) & 0x1f) << 5)), (0x3UL<<2), (((7)-1) << 16));
    CLK_EnableModuleClock(((((1) & 0x03) << 30)|(((2) & 0x1f) << 0) | (((1) & 0x03) << 28)|(((7) & 0x07) << 25)|(((8) & 0x1f) << 20)| (((0x0) & 0x03) << 18)|(((0x0) & 0xff) << 10)|(((0x0) & 0x1f) << 5)));   
    CLK_SetModuleClock(((((1) & 0x03) << 30)|(((2) & 0x1f) << 0) | (((1) & 0x03) << 28)|(((7) & 0x07) << 25)|(((8) & 0x1f) << 20)| (((0x0) & 0x03) << 18)|(((0x0) & 0xff) << 10)|(((0x0) & 0x1f) << 5)), (0x0UL<<8), 0);
   
     
    ((GCR_T *) ((( uint32_t)0x50000000) + 0x00000))->IPRSTC2 |=  (1ul << 8);
    ((GCR_T *) ((( uint32_t)0x50000000) + 0x00000))->IPRSTC2 &= ~(1ul << 8);

     
    ((I2C_T *) ((( uint32_t)0x40000000) + 0x20000))->I2CON |= (1ul << 6);

     
    u32BusClock = 100000;
    ((I2C_T *) ((( uint32_t)0x40000000) + 0x20000))->I2CLK = (uint32_t)(((SystemCoreClock * 10) / (u32BusClock * 4) + 5) / 10 - 1);  

     
    

     
     
    ((I2C_T *) ((( uint32_t)0x40000000) + 0x20000))->I2CADDR0 = (((I2C_T *) ((( uint32_t)0x40000000) + 0x20000))->I2CADDR0 & ~(0x7Ful << 1)) | (0x15 << 1);
     
    ((I2C_T *) ((( uint32_t)0x40000000) + 0x20000))->I2CADDR1 = (((I2C_T *) ((( uint32_t)0x40000000) + 0x20000))->I2CADDR1 & ~(0x7Ful << 1)) | (0x35 << 1);
     
    ((I2C_T *) ((( uint32_t)0x40000000) + 0x20000))->I2CADDR2 = (((I2C_T *) ((( uint32_t)0x40000000) + 0x20000))->I2CADDR2 & ~(0x7Ful << 1)) | (0x55 << 1);
     
    ((I2C_T *) ((( uint32_t)0x40000000) + 0x20000))->I2CADDR3 = (((I2C_T *) ((( uint32_t)0x40000000) + 0x20000))->I2CADDR3 & ~(0x7Ful << 1)) | (0x75 << 1);

    CLK_EnableModuleClock(((((1) & 0x03) << 30)|(((28) & 0x1f) << 0) | (((1) & 0x03) << 28)|(((3) & 0x07) << 25)|(((2) & 0x1f) << 20)| (((0) & 0x03) << 18)|(((0xFF) & 0xff) << 10)|(((16) & 0x1f) << 5)));
    
    CLK_SetModuleClock(((((1) & 0x03) << 30)|(((28) & 0x1f) << 0) | (((1) & 0x03) << 28)|(((3) & 0x07) << 25)|(((2) & 0x1f) << 20)| (((0) & 0x03) << 18)|(((0xFF) & 0xff) << 10)|(((16) & 0x1f) << 5)), (0x3UL<<2), (((7)-1) << 16));


     
     
     

     
    ((GCR_T *) ((( uint32_t)0x50000000) + 0x00000))->GPB_MFP &= ~((1UL<<0) | (1UL<<1));
    ((GCR_T *) ((( uint32_t)0x50000000) + 0x00000))->GPB_MFP |= (1UL<<0) | (1UL<<1);
    
     
    ((GCR_T *) ((( uint32_t)0x50000000) + 0x00000))->GPB_MFP &= ~((1UL<<4) | (1UL<<5));
    ((GCR_T *) ((( uint32_t)0x50000000) + 0x00000))->GPB_MFP |= (1UL<<4) | (1UL<<5);

     
    ((GCR_T *) ((( uint32_t)0x50000000) + 0x00000))->GPD_MFP &= ~((1UL<<14) | (1UL<<15));
    ((GCR_T *) ((( uint32_t)0x50000000) + 0x00000))->GPD_MFP |= (1UL<<14) | (1UL<<15);

     
    ((GCR_T *) ((( uint32_t)0x50000000) + 0x00000))->GPA_MFP &= ~((1UL<<0) | (1UL<<1) | (1UL<<2) | (1UL<<3) | (1UL<<4) | (1UL<<5) | (1UL<<6));
    ((GCR_T *) ((( uint32_t)0x50000000) + 0x00000))->GPA_MFP |= (1UL<<0) | (1UL<<1) | (1UL<<2) | (1UL<<3) | (1UL<<4) | (1UL<<5) | (1UL<<6) ;
    ((GCR_T *) ((( uint32_t)0x50000000) + 0x00000))->ALT_MFP1 = 0;
    
    (((GPIO_DBNCECON_T *) (((( uint32_t)0x50000000) + 0x4000) + 0x0180))->DBNCECON = ((1ul << 5) | (0x00000000UL) | (0x0000000FUL)));
    ((((GPIO_T *) (((( uint32_t)0x50000000) + 0x4000) + 0x0040)))->DBEN |= (0x00000040 | 0x00000200 | 0x00000400 | 0x00002000 | 0x00000100 | 0x00008000));
    ((((GPIO_T *) (((( uint32_t)0x50000000) + 0x4000) )))->DBEN |= (0x00004000 | 0x00008000 | 0x00001000 | 0x00002000));   
    
    
    GPIO_SetMode(((GPIO_T *) (((( uint32_t)0x50000000) + 0x4000) )), 0x00004000, 0x0UL);      
    GPIO_EnableInt(((GPIO_T *) (((( uint32_t)0x50000000) + 0x4000) )), 14, 0x00000001UL);
    __NVIC_EnableIRQ(GPAB_IRQn);
    GPIO_SetMode(((GPIO_T *) (((( uint32_t)0x50000000) + 0x4000) )), 0x00008000, 0x0UL);      
    GPIO_EnableInt(((GPIO_T *) (((( uint32_t)0x50000000) + 0x4000) )), 15, 0x00000001UL);
    __NVIC_EnableIRQ(GPAB_IRQn);
    GPIO_SetMode(((GPIO_T *) (((( uint32_t)0x50000000) + 0x4000) )), 0x00001000, 0x0UL);      
    GPIO_EnableInt(((GPIO_T *) (((( uint32_t)0x50000000) + 0x4000) )), 12, 0x00000001UL);
    __NVIC_EnableIRQ(GPAB_IRQn);
    GPIO_SetMode(((GPIO_T *) (((( uint32_t)0x50000000) + 0x4000) )), 0x00002000, 0x0UL);      
    GPIO_EnableInt(((GPIO_T *) (((( uint32_t)0x50000000) + 0x4000) )), 13, 0x00000001UL);
    __NVIC_EnableIRQ(GPAB_IRQn);
    
    
    GPIO_SetMode(((GPIO_T *) (((( uint32_t)0x50000000) + 0x4000) + 0x0040)), 0x00000040, 0x0UL);       


    GPIO_SetMode(((GPIO_T *) (((( uint32_t)0x50000000) + 0x4000) + 0x0040)), 0x00000200, 0x0UL);       
    GPIO_EnableInt(((GPIO_T *) (((( uint32_t)0x50000000) + 0x4000) + 0x0040)), 9, 0x00010001UL);
    __NVIC_EnableIRQ(GPAB_IRQn);
    GPIO_SetMode(((GPIO_T *) (((( uint32_t)0x50000000) + 0x4000) + 0x0040)), 0x00000400, 0x0UL);      
    GPIO_EnableInt(((GPIO_T *) (((( uint32_t)0x50000000) + 0x4000) + 0x0040)), 10, 0x00010001UL);
    __NVIC_EnableIRQ(GPAB_IRQn);
    GPIO_SetMode(((GPIO_T *) (((( uint32_t)0x50000000) + 0x4000) + 0x0040)), 0x00002000, 0x0UL);      
    GPIO_EnableInt(((GPIO_T *) (((( uint32_t)0x50000000) + 0x4000) + 0x0040)), 13, 0x00000001UL);
    __NVIC_EnableIRQ(GPAB_IRQn);    
    
    GPIO_SetMode(((GPIO_T *) (((( uint32_t)0x50000000) + 0x4000) + 0x0040)), 0x00000100, 0x1UL);       
    GPIO_SetMode(((GPIO_T *) (((( uint32_t)0x50000000) + 0x4000) + 0x0040)), 0x00008000, 0x1UL);       
    GPIO_SetMode(((GPIO_T *) (((( uint32_t)0x50000000) + 0x4000) )), 0x00000080, 0x1UL);       
    
    GPIO_SetMode(((GPIO_T *) (((( uint32_t)0x50000000) + 0x4000) + 0x0080)), 0x00000004, 0x1UL);       
    GPIO_SetMode(((GPIO_T *) (((( uint32_t)0x50000000) + 0x4000) + 0x0080)), 0x00000008, 0x1UL);       


    (*((volatile uint32_t *)(((((( uint32_t)0x50000000) + 0x4000) + 0x0200)+(0x40*(1))) + ((8)<<2)))) = 1;
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
          send_sms(emernum1, "Alert – over the air parameter change");
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
     
     
     
     
    SYS_ResetModule(((0x4<<24) | 16 ));
    SYS_ResetModule(((0x4<<24) | 17 ));
    SYS_ResetModule(((0x4<<24) | 18 ));

     
    UART_Open(((UART_T *) ((( uint32_t)0x40000000) + 0x50000)), 9600);             
    UART_Open(((UART_T *) ((( uint32_t)0x40100000) + 0x50000)), 115200);           
    UART_Open(((UART_T *) ((( uint32_t)0x40100000) + 0x54000)), 9600);             
		((((UART_T *) ((( uint32_t)0x40100000) + 0x50000)))->IER |= (((1ul << 0) )));
		__NVIC_EnableIRQ(UART1_IRQn);  
		((((UART_T *) ((( uint32_t)0x40100000) + 0x54000)))->IER |= (((1ul << 0) )));
		__NVIC_EnableIRQ(UART02_IRQn);  
}

void UART1_IRQHandler(void)
{char uart1data;
    while(!((((UART_T *) ((( uint32_t)0x40100000) + 0x50000)))->FSR & (1ul << 14))) 
    {
      uart1data = ((((UART_T *) ((( uint32_t)0x40100000) + 0x50000)))->RBR);
      if(uart1data != '\0'){
        g_u8RecData[g_u8RecDataptr] = uart1data;
        g_u8RecDataptr++;
        if(g_u8RecDataptr > (1000-10)){
          g_u8RecDataptr = 0;
        }
      tmr0sec=0;
      }
    }
}
void UART02_IRQHandler(void)
{
    while(!((((UART_T *) ((( uint32_t)0x40100000) + 0x54000)))->FSR & (1ul << 14))) 
    {
      g_u8OBDRecData[g_u8OBDRecDataptr] = ((((UART_T *) ((( uint32_t)0x40100000) + 0x54000)))->RBR);
      g_u8OBDRecDataptr++;
    }
}



__inline void Init_IOs(){
  







 
  
  












  






























    

  













   
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
    osSignalWait (0x0123, 0xFFFFFFFFU); 
    osSignalClear (mainThreadID, 0x0123);
}

void signal123(){
    osSignalSet (tid_Thread_OBD_READ, 0x0123);
}
void waitfor321(){
    osSignalWait (0x0321, 0xFFFFFFFFU); 
    osSignalClear (tid_Thread_OBD_READ, 0x0321);
}

void signal321(){
    osSignalSet (mainThreadID, 0x0321);
}


void GPAB_IRQHandler(void){
  int trueint = 0;
     






















    if(((((GPIO_T *) (((( uint32_t)0x50000000) + 0x4000) + 0x0040)))->ISRC & (0x00000200))){
        ((((GPIO_T *) (((( uint32_t)0x50000000) + 0x4000) + 0x0040)))->ISRC = (0x00000200));
        emergencystatus = 1;
        if((*((volatile uint32_t *)(((((( uint32_t)0x50000000) + 0x4000) + 0x0200)+(0x40*(1))) + ((9)<<2)))) == 0){
        emergencyhighlow = 1;
        }else{
          emergencyhighlow = 0;
        }
        trueint = 1;    
    }if(((((GPIO_T *) (((( uint32_t)0x50000000) + 0x4000) + 0x0040)))->ISRC & (0x00000400))){   
        ignition = 1;trueint = 1;
      if((*((volatile uint32_t *)(((((( uint32_t)0x50000000) + 0x4000) + 0x0200)+(0x40*(1))) + ((10)<<2)))) == 0){
        ignitionhighlow = 1;
      }else{
        ignitionhighlow = 0;
      }
      ((((GPIO_T *) (((( uint32_t)0x50000000) + 0x4000) + 0x0040)))->ISRC = (0x00000400));
      trueint = 1;
    }
    if(((((GPIO_T *) (((( uint32_t)0x50000000) + 0x4000) + 0x0040)))->ISRC & (0x00002000))){
        ((((GPIO_T *) (((( uint32_t)0x50000000) + 0x4000) + 0x0040)))->ISRC = (0x00002000));
        tamperalert = 'O';trueint = 1;
    }
    
    
    
    
    if (trueint == 0)
    {
         
        ((GPIO_T *) (((( uint32_t)0x50000000) + 0x4000) + 0x0040))->ISRC = ((GPIO_T *) (((( uint32_t)0x50000000) + 0x4000) + 0x0040))->ISRC;
        ((GPIO_T *) (((( uint32_t)0x50000000) + 0x4000) ))->ISRC = ((GPIO_T *) (((( uint32_t)0x50000000) + 0x4000) ))->ISRC;
    }
   
}

__inline void remove_all_alpha(char* str, char c, char d) {
    char *pr = str, *pw = str;
    while (*pr) {
        *pw = *pr++;
			pw += (*pw > 47 && *pw < 58);
    }
    *pw = '\0';
}
void WDT_IRQHandler(void)
{
    
    (((WWDT_T *) ((( uint32_t)0x40000000) + 0x4100))->WWDTRLD = (0x00005AA5));
    (((WWDT_T *) ((( uint32_t)0x40000000) + 0x4100))->WWDTSR = (1ul << 0));
   

}

void TMR0_IRQHandler(void)
{
    if(TIMER_GetIntFlag(((TIMER_T *) ((( uint32_t)0x40000000) + 0x10000))) == 1)
    {
         
        TIMER_ClearIntFlag(((TIMER_T *) ((( uint32_t)0x40000000) + 0x10000)));
        interval_count++;
        interval_count_health++;
        tmr0sec++;
        
        tcpsendchtimer++;
        tc++;
        i2ctimeout++;
        
        wetmr+=1;
        wait++;
        (*((volatile uint32_t *)(((((( uint32_t)0x50000000) + 0x4000) + 0x0200)+(0x40*(2))) + ((2)<<2))))^=1;
        (*((volatile uint32_t *)(((((( uint32_t)0x50000000) + 0x4000) + 0x0200)+(0x40*(2))) + ((3)<<2))))^=1;

    }
}
void ADC_IRQHandler(void)
{
    g_u32AdcIntFlag = 1;
    ((((ADC_T *) ((( uint32_t)0x40000000) + 0xE0000)))->ADSR = (((1ul << 0))));  
}
