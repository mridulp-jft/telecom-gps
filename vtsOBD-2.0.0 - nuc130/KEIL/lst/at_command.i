#line 1 "at_command.c"
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



 

#line 2 "at_command.c"
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



 

#line 3 "at_command.c"
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





 
#line 4 "at_command.c"
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






#line 5 "at_command.c"
#line 1 "osObjects.h"









 









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






#line 21 "osObjects.h"









 







 









 









 









 

#line 7 "at_command.c"
#line 8 "at_command.c"
#line 9 "at_command.c"

#line 1 "WinboundFlash.h"
 








 




 



 



 

 
 
 
extern void Open_SPI_Flash(void);
extern unsigned int SpiFlash_ReadMidDid(void);
extern void SpiFlash_ChipErase(void);
extern unsigned int SpiFlash_ReadStatusReg1(void);
extern unsigned int SpiFlash_ReadStatusReg2(void);
extern void SpiFlash_WaitReady(void);
extern void SpiFlash_PageProgram(unsigned char *DataBuffer, unsigned int StartAddress, unsigned int ByteCount);
extern void SpiFlash_ReadData(unsigned char *DataBuffer, unsigned int StartAddress, unsigned int ByteCount);


   

   

   

 
#line 11 "at_command.c"






 
extern char g_u8SendData[2500];
extern char g_u8RecData[1000];
extern	int32_t life;
extern void SendChar(int ch);
extern void send_OBD(char * command, char * response1, char * response2, char * response3, int32_t timeout);


char SrcArray[257];char DestArray[257];

uint8_t g_u8DeviceAddr = 0x1E;
uint32_t u32Status;
uint8_t g_au8TxData[1];
uint8_t g_u8RxData;
uint8_t g_u8DataLen = 0;
uint8_t sendfs=0;
volatile uint8_t g_u8EndFlag = 0;
extern void Open_SPI_Flash(void);
extern unsigned int SpiFlash_ReadMidDid(void);
uint32_t readpt = 256;
extern int once;
extern uint32_t pt;



 
extern char obdresp[20];
extern char tempobdresp[20];
extern char obdrespbinary[33];
extern char suppportedpid[100][7];
extern int pidcounter;
extern char g_u8OBDRecData[100];

extern char vehicleregnum[15];
char signalquality[5] = {0};


 
  int tcpsendchtimer;
  int powerstatus = 0;
  int ignition = 0;
  int fix = 0;
  int emergencystatus = 0;
  char tamperalert = 'C';
  float ext_bat, int_bat, lati, longi, speed;
  float batteryvoltage = 0;
  float inputvoltage = 0;
  char latitude[12] = 0;
  char longitude[12] = 0;
  char gpsdate[7] = 0;
  char gpstime[7] = 0;
  char kmph[6] = 0;
  char heading[8] = 0;
  char alt[8] = 0;
  char sat[2] = 0;
  char latdir[2] = 0;
  char longdir[2] = 0;
  char hdop[6] = 0;
  char pdop[5] = 0;
  char networkoperator[30] = 0;
  char mcc[5] = 0;
  char mnc[5] = 0;
  char lac[5] = 0;
  char cellid[10] = 0;
  char packetstatus = 'L';
  char nmr[200] = 0;
  




 
int32_t	inc=0;
int stlen;
uint8_t u8InChar=0xFF;
int32_t g_u8RecDataptr=0;
float	u32ADC0Result;
float u32ADC0Result1;
int8_t charging, cpinready, cregready;
int motion_counts,immotion_counts;
int32_t timer0ticks=0;
int32_t tmr0sec=0;
char * r1;
char * r2;
char * r3;
char temp[100];
char fileinstance[20] = {0};
int8_t  network;
int breaker=0;
int seeker = 0;
int imeiptr0=0;
char imei[25];
int imeiptr=0;
	int tcpdatalength=0;
	int32_t tcpdataptr=0;
	int times = 0;
	int timesptr=0;
	int tdp=0;
  int read_obd = 0 ;
	int tdpend=300;
 

extern osMutexId	(uart_mutex_id); 
		

extern osMutexId	(tcp_mutex_id); 


extern osMutexId	(fs_mutex_id); 



 
void SendAT(char * command, char * response1, char * response2, char * response3, int32_t timeout);
void SendAT_FS(char * command, char * response1, char * response2, char * response3, int32_t timeout);
void TCP_Send_ch(char * tcpcommand,char * tcpdataq, char * tcpresponse1, char * tcpresponse2, char * tcpresponse3, int32_t tcptimeout);
void SendAT_GPS_WO_MUTEX(char * command, char * response1, char * response2, char * response3, int32_t timeout);
void TCP_Send_ch(char * tcpcommand,char * tcpdataq, char * tcpresponse1, char * tcpresponse2, char * tcpresponse3, int32_t tcptimeout);
void TCP_Send(char * tcpcommand,char * tcpdata, char * tcpresponse1, char * tcpresponse2, char * tcpresponse3, int32_t tcptimeout);

void clear(void);
__inline void manualdelay(int delayms);
__inline void fileclose(void);  
__inline void fileopen(void);
__inline void parse_g(char* str, int first, int sec, char f, char s , char *string);
__inline void remove_all_chars(char* str, char c, char d);
__inline void manualdelay(int delayms);
__inline void strreplace(char s[], char chr, char repl_chr);

void cregquerry(void);
void cpinquerry(void);
void Save_FS(void);
char *response1;
char *response2;
char *response3;

 



void SendAT(char * command, char * res1, char * res2, char * res3, int32_t timeout)
{
  static int attry;
  response1 = res1;
  response2 = res2;
  response3 = res3;

	tmr0sec=0;

	r1=0;
	r2=0;
	r3=0;
	g_u8RecDataptr=0;
	memset(g_u8RecData,0,1000);
	printf("%c",0x1A);
	clear();
	printf(command);
	do{
    g_u8RecData[0] = '\r';
		r1 = strstr(g_u8RecData, response1);
		r2 = strstr(g_u8RecData, response2);
		r3 = strstr(g_u8RecData, response3);
    
	}while(!(r1 || r2 || r3 ||((tmr0sec >= timeout))));	 

   if(!(strstr(command, "QILOCIP") || strstr(command, "QGNSSC")))
   {
     if(!(r1 || r2 || r3))
      {
        (*((volatile uint32_t *)(((((( uint32_t)0x50000000) + 0x4000) + 0x0200)+(0x40*(0))) + ((13)<<2))))=1;
        attry++;
        if(attry > 3){
            printf("\r\nAT+CFUN=1,1\r\n");	
        }
        (*((volatile uint32_t *)(((((( uint32_t)0x50000000) + 0x4000) + 0x0200)+(0x40*(0))) + ((13)<<2))))=0;
      }
      else{attry=0;}
   }

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
char mystrstr(char* str1, char character)
{int sz,cn;
  sz=strlen(str1);
	for(cn=0;cn<=sz;cn++)
	{if(str1[cn] == character)
		{return 1;}
	}
	return 0;
}
__inline void fileopen(void)
{
  if(strlen(fileinstance) == 0)
  {
    SendAT("\r\nAT+QFOPEN=\"LOG.TXT\",0\r\n", "Ready", "OK" , "ERROR",10);	
    if(strstr(g_u8RecData,"CME ERROR"))
    {
        (*((volatile uint32_t *)(((((( uint32_t)0x50000000) + 0x4000) + 0x0200)+(0x40*(0))) + ((13)<<2))))=1;
        printf("\r\n\r\nAT+CFUN=1,1\r\n\r\n");
        manualdelay(100);
        (*((volatile uint32_t *)(((((( uint32_t)0x50000000) + 0x4000) + 0x0200)+(0x40*(0))) + ((13)<<2))))=0;
        memset(fileinstance,0,20);
    SendAT("\r\nAT+QFOPEN=\"LOG.TXT\",0\r\n", "Ready", "OK" , "ERROR",10);	
    }
    parse_g(g_u8RecData, 1, 2, ' ', '\n' , fileinstance);
    remove_all_chars(fileinstance, '\r', '\n');   
    SendAT("\r\nAT+QGNSSC=1\r\n\r\n", "OK", "ERROR", "7103", 5);
  }
}

__inline void remove_all_chars(char* str, char c, char d) {
    char *pr = str, *pw = str;
    while (*pr) {
        *pw = *pr++;
			pw += (*pw != c && *pw != d && *pw != ' ' && *pw != '/' && *pw != ':');
    }
    *pw = '\0';
}


void parse_g(char* str, int first, int sec, char f, char s , char *string)
{int sz1,sz2,i11,temp11,j11,l;
    if(mystrstr(str,f) && mystrstr(str,s))
    {  

		sz1=	strlen(str);
		sz2=	strlen(string);
		memset(string,0,sz2);
		for(i11=0,temp11=0;i11<sz1;i11++)
		{
		if(str[i11]==s)
			{
        temp11++;
        j11=i11;
      }
		else{}
			
		if(temp11>=sec){i11=9900;}
		else{}	
		
		}	
		
		for(i11=0,temp11=0;i11<sz1;i11++)
		{
		if(str[i11]==f)
			{
        temp11++;l=i11;
      }										
		else{}
		if(temp11>=first){i11=9900;}else{}
		}	
		for(i11=0;i11<(j11-l-1);i11++)
		{
      string[i11] = str[l+i11+1];
		}
	

    }
  }


__inline void fileclose(void)
{
    memset(temp,0,100);
    sprintf(temp,"\r\nAT+QFCLOSE=%s\r\n\r\n",fileinstance);
    SendAT(temp, "+CME ERROR", "OK" , "ERROR",10);
    memset(fileinstance,0,20);
}


void clear()
{char dump = 0;
    while(!((((UART_T *) ((( uint32_t)0x40100000) + 0x50000)))->FSR & (1ul << 14))) 
    {
      dump = ((((UART_T *) ((( uint32_t)0x40100000) + 0x50000)))->RBR);
    }
}

__inline void Send_FS(void)
{
  if(sendfs==1){
  TCP_Send_ch("\r\nAT+QISEND\r\n\r\n",g_u8SendData,">","ERROR","SEND OK",5);	
  }
}


void Save_FS(void)
{ char * pch = 0;
  int i,j;
  int len=0;
  strcat(g_u8SendData,"\n");
  pch = strstr (g_u8SendData,",L,");
  if (pch){
    strncpy(pch,",H,",3);
  }
  strreplace(g_u8SendData, 0x1A, '\n'); 
  remove_all_chars(g_u8SendData,'\r',0x1A);
  SpiFlash_WaitReady();
  

  remove_all_chars(g_u8SendData,'\n','\n'); 
  strcat(g_u8SendData, "S**************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************E\n");
  life = strlen(g_u8SendData); 
  times = life/256 + 1;
  j = 0;
  while(times > 0){
    
    memset(SrcArray,0,257);
    for(i=0;i<256;i++){
      SrcArray[i] = g_u8SendData[j];
      j++;
    }
    manualdelay(25);
    SpiFlash_PageProgram(SrcArray, pt, 256);
    
    memset(DestArray,0,257);
    
    SpiFlash_ReadData(DestArray, pt, 256);
    times--; 
    pt+=256;
  }
  memset(g_u8SendData,0,2500);
}

 void cpinquerry()
{
  int timeout;
	
  
	tmr0sec=0;
	timeout =10;
	r1=0;
	r2=0;
	r3=0;
	g_u8RecDataptr=0;
	memset(g_u8RecData,0,1000);
	printf("%c",0x1A);
	clear();
	printf("\r\nAT+CPIN?\r\n\r\n");
	do{
    g_u8RecData[0] = '\r';
		r1 = strstr(g_u8RecData, "NOT READY");
		r2 = strstr(g_u8RecData, "OK");
		r3 = strstr(g_u8RecData, "ERROR");
			
	}while(!(r1 || r2 || r3 ||((tmr0sec >= timeout))));	 
  clear();
 
  if(!strstr(g_u8RecData, "NOT READY"))
  {
    cpinready=1;
  }
  else
  {
    cpinready=0;
  } 
}

void cregquerry()
{
  int timeout;
  char cregresp[10];
	
  
	tmr0sec=0;
	timeout =10;
	r1=0;r2=0;r3=0;
	g_u8RecDataptr=0;
	memset(g_u8RecData,0,1000);
	printf("%c",0x1A);
	clear();
	printf("\r\nAT+CREG?\r\n\r\n");
	do{
    g_u8RecData[0] = '\r';
		r1 = strstr(g_u8RecData, "CPIN: READY");
		r2 = strstr(g_u8RecData, "OK");
		r3 = strstr(g_u8RecData, "ERROR");
	}while(!(r1 || r2 || r3 ||((tmr0sec >= timeout))));	 
  clear();
  memset(cregresp,0,10);
  parse_g(g_u8RecData, 1, 2, ',', '\n' , cregresp);
  if(strstr(cregresp,"1") || strstr(cregresp, "5"))
  {
    cregready=1;
  }
  else
  {
    cregready=0;
  }
 
}




void SendAT_FS(char * command, char * response1, char * response2, char * response3, int32_t timeout)
{
	tmr0sec=0;

	
	r1=0;
	r2=0;
	r3=0;
	g_u8RecDataptr=0;
	memset(g_u8RecData,0,1000);

	clear();
	printf(command);
	do{
		r1 = strstr(g_u8RecData, response1);
		r2 = strstr(g_u8RecData, response2);
		r3 = strstr(g_u8RecData, response3);
	}while(!(r1 || r2 || r3 ||((tmr0sec >= timeout))));	 
clear();
   if(!strstr(command, "QILOCIP"))
   {
     if(!(r1 || r2 || r3))
      {
        (*((volatile uint32_t *)(((((( uint32_t)0x50000000) + 0x4000) + 0x0200)+(0x40*(0))) + ((13)<<2))))=1;
        printf("\r\n\r\nAT+CFUN=1,1\r\n\r\n");
        manualdelay(100);
        fileclose();
        fileopen();
        SendAT("\r\nAT+QGNSSC=1\r\n\r\n", "OK", "ERROR", "7103", 10);

        (*((volatile uint32_t *)(((((( uint32_t)0x50000000) + 0x4000) + 0x0200)+(0x40*(0))) + ((13)<<2))))=0;
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

__inline int8_t checkallnumsinstring(char* checkstring)
{
  int returnval, checkstringptr, lencheckstring=0;
  lencheckstring  = strlen(checkstring);
  for(checkstringptr  = 0 ; checkstringptr < lencheckstring ; checkstringptr++)
  {
    if((checkstring[checkstringptr]  > 47 ) && (checkstring[checkstringptr]  < 58 ))
    {returnval  = 0;}
    else
    {returnval  = 1;break;}
  }
  return returnval;
}


void TCP_Send_ch(char * tcpcommand,char * tcpdataq, char * tcpresponse1, char * tcpresponse2, char * tcpresponse3, int32_t tcptimeout)
{
  int outfromloop = 0;
  int tcpdatalength=0;
	int tcpdataptr=0;
	int times = 0;
	int timesptr=0;
	int tdp=0;
	int tdpend=300;
  char chdatalength[5];
  char tcpdata[300];
  int  cc =0;
  breaker = 0;
	(*((volatile uint32_t *)(((((( uint32_t)0x50000000) + 0x4000) + 0x0200)+(0x40*(1))) + ((2)<<2))))=0;
	printf("%c",0x1A);
  tcpsendchtimer = 0;

do{
  memset(tcpdata,0,300);
  
  SpiFlash_ReadData(tcpdata, readpt, 256);
  if(tcpdata[0] != 0xFF && tcpdata[0] != '\0')
    times = 1;
  else{
    SpiFlash_ChipErase();
    times = 0;
    pt = 0;
    readpt = 0;
    readpt = 0;
    pt = 0;    
    
  }
  if(times == 1){
      clear();
      
      tmr0sec=0;
      tcptimeout =5;
      r1=0;
      r2=0;
      r3=0;
			g_u8RecDataptr=0;
			tmr0sec=0;
			memset(g_u8RecData,0,1000);
			printf("\r\nAT+QISEND=0\r\n\r\n\r\n");
			do{
        g_u8RecData[0] = '\r';
				r1 = strstr(g_u8RecData, tcpresponse1);
				r2 = strstr(g_u8RecData, tcpresponse2);
				r3 = strstr(g_u8RecData, tcpresponse3);
					
			}while(!(r1 || r2 || r3 ||((tmr0sec >= tcptimeout))));	 
      clear();
				tmr0sec=0;
				if(r1)
					{
						tmr0sec=0;
						tcptimeout =5;
						r1=0;
						r2=0;
						r3=0;
						g_u8RecDataptr=0;
						memset(g_u8RecData,0,1000);
						clear();
 						tcpdataptr=0;
            tdpend=strlen(tcpdata);
   
						for(tdp=0;tdp<tdpend;tdp++)
						{
              SendChar(tcpdata[tdp]);
              tcpdataptr++;
            }
						printf("%c",0x1A);
						do{
              g_u8RecData[0] = '\r';
							r1 = strstr(g_u8RecData, tcpresponse1);
							r2 = strstr(g_u8RecData, tcpresponse2);
							r3 = strstr(g_u8RecData, tcpresponse3);
						}while(!(r1 || r2 || r3 ||((tmr0sec >= tcptimeout))));
          }

			if(!(r3)){
				network=1;
        breaker = 1;        
				break;
			}else{
        breaker = 0;
				network=0;
			}
      
      if(network == 0){    
        
        clear();
        tmr0sec=0;
        tcptimeout =5;
        r1=0;
        r2=0;
        r3=0;
        g_u8RecDataptr=0;
        tmr0sec=0;
        memset(g_u8RecData,0,1000);
        printf("\r\nAT+QISEND=1\r\n\r\n\r\n");
        do{
          g_u8RecData[0] = '\r';
          r1 = strstr(g_u8RecData, tcpresponse1);
          r2 = strstr(g_u8RecData, tcpresponse2);
          r3 = strstr(g_u8RecData, tcpresponse3);
            
        }while(!(r1 || r2 || r3 ||((tmr0sec >= tcptimeout))));	 
        clear();
          tmr0sec=0;
          if(r1)
            {
              tmr0sec=0;
              tcptimeout =5;
              r1=0;
              r2=0;
              r3=0;
              g_u8RecDataptr=0;
              memset(g_u8RecData,0,1000);
              clear();
              tcpdataptr=0;
              tdpend=strlen(tcpdata);
     
              for(tdp=0;tdp<tdpend;tdp++)
              {
                SendChar(tcpdata[tdp]);
                tcpdataptr++;
              }
              printf("%c",0x1A);
              do{
                g_u8RecData[0] = '\r';
                r1 = strstr(g_u8RecData, tcpresponse1);
                r2 = strstr(g_u8RecData, tcpresponse2);
                r3 = strstr(g_u8RecData, tcpresponse3);
              }while(!(r1 || r2 || r3 ||((tmr0sec >= tcptimeout))));
            }

        if(!(r3)){
          network=1;
          breaker = 1;        
          break;
        }else{
          breaker = 0;
          readpt+=256;
          network=0;
        }
      }
      if(tcpsendchtimer > 4){
        breaker = 1;
        break;
      }else breaker = 0;
    
    }
  outfromloop = 1;
  }while(times == 1);

}



void TCP_Send(char * tcpcommand,char * tcpdata, char * tcpresponse1, char * tcpresponse2, char * tcpresponse3, int32_t tcptimeout)
{
	int tcpdatalength=0;
	int tcpdataptr=0;
	int times = 0;
	int timesptr=0;
	int tdp=0;
	int tdpend=600;

	tmr0sec=0;
	tcptimeout =5;
	r1=0;
	r2=0;
	r3=0;
	g_u8RecDataptr=0;
	printf("%c",0x1A);
	tcpdatalength = strlen(tcpdata);
		if(tcpdatalength>15)
		{
			clear();
			g_u8RecDataptr=0;
			tmr0sec=0;
			memset(g_u8RecData,0,1000);
			printf("\r\nAT+QISEND=0\r\n\r\n\r\n");
			do{
        g_u8RecData[0] = '\r';
				r1 = strstr(g_u8RecData, tcpresponse1);
				r2 = strstr(g_u8RecData, tcpresponse2);
				r3 = strstr(g_u8RecData, tcpresponse3);					
			}while(!(r1 || r2 || r3 ||((tmr0sec >= tcptimeout))));	 
      clear();
				tmr0sec=0;
				if(r1)
					{
						tmr0sec=0;
						tcptimeout =5;
						r1=0;
						r2=0;
						r3=0;
						g_u8RecDataptr=0;
						memset(g_u8RecData,0,1000);
						clear();
						for(tdp=0;tdp<tcpdatalength;tdp++){
						SendChar(tcpdata[tcpdataptr]);
						tcpdataptr++;
            }
						printf("%c",0x1A);
						do{
              g_u8RecData[0] = '\r';
							r1 = strstr(g_u8RecData, tcpresponse1);
							r2 = strstr(g_u8RecData, tcpresponse2);
							r3 = strstr(g_u8RecData, tcpresponse3);
						}while(!(r1 || r2 || r3 ||((tmr0sec >= tcptimeout))));
           clear();            
          }
			if(!(r3)){
				network=1;
        sendfs = 0;
			}
			else{
				network=0;
        sendfs = 1;        
			}
	}else{network = 1;sendfs = 0;} 
   
  tcpdatalength=0;
  tcpdataptr=0;
  times = 0;
  timesptr=0;
  tdp=0;
  tdpend=600;  
   
  if(network == 0){  
    tmr0sec=0;
    tcptimeout =5;
    r1=0;
    r2=0;
    r3=0;
    g_u8RecDataptr=0;
    printf("%c",0x1A);
    tcpdatalength = strlen(tcpdata);
      if(tcpdatalength>15)
      {
        clear();
        g_u8RecDataptr=0;
        tmr0sec=0;
        memset(g_u8RecData,0,1000);
        printf("\r\nAT+QISEND=1\r\n\r\n\r\n");
        do{
          g_u8RecData[0] = '\r';
          r1 = strstr(g_u8RecData, tcpresponse1);
          r2 = strstr(g_u8RecData, tcpresponse2);
          r3 = strstr(g_u8RecData, tcpresponse3);            
        }while(!(r1 || r2 || r3 ||((tmr0sec >= tcptimeout))));	 
        clear();
          tmr0sec=0;
          if(r1)
            {
              tmr0sec=0;
              tcptimeout =5;
              r1=0;
              r2=0;
              r3=0;
              g_u8RecDataptr=0;
              memset(g_u8RecData,0,1000);
              clear();
              for(tdp=0;tdp<tcpdatalength;tdp++){
              SendChar(tcpdata[tcpdataptr]);
              tcpdataptr++;
              }
              printf("%c",0x1A);
              do{
                g_u8RecData[0] = '\r';
                r1 = strstr(g_u8RecData, tcpresponse1);
                r2 = strstr(g_u8RecData, tcpresponse2);
                r3 = strstr(g_u8RecData, tcpresponse3);
              }while(!(r1 || r2 || r3 ||((tmr0sec >= tcptimeout))));
             clear();           
            }
        if(!(r3)){
          network=1;
          sendfs = 0;
        }
        else{
          network=0;
          sendfs = 1;
        }
    if(network == 0 && timesptr>=times){
      memset(g_u8SendData,0,2500);
      sendfs=1;
    }
    else{
      sendfs=0;
    }
    }else{network = 1; sendfs = 1;}
  }
  
  if(sendfs == 1){
    memset(tcpdata,0,300);
    
    SpiFlash_ReadData(tcpdata, readpt, 256);
    if(tcpdata[0] != 0xFF)
      sendfs = 1;
    else
      sendfs = 0;
  }

}





void SendAT_GPS_WO_MUTEX(char * command, char * response1, char * response2, char * response3, int32_t timeout)
{

	
	tmr0sec=0;
	r1=0;
	r2=0;
	r3=0;
	g_u8RecDataptr=0;
	memset(g_u8RecData,0,1000);
	printf("%c",0x1A);
	clear();
	if(checkallnumsinstring(imei) ||  (strlen(imei) < 5))
	{
		printf("\r\nAT+GSN\r\n");
		do{
			r1 = strstr(g_u8RecData, response1);
			r2 = strstr(g_u8RecData, response2);
			r3 = strstr(g_u8RecData, response3);
		}while(!(r1 || r2 || r3 || ((tmr0sec >= timeout))));	 
		memset(imei,0,25);
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
	}
	tmr0sec=0;
	r1=0;
	r2=0;
	r3=0;
	g_u8RecDataptr=0;
	memset(g_u8RecData,0,1000);
	clear();
	printf("%c",0x1A);
	printf(command);
	do{
		r1 = strstr(g_u8RecData, response1);
		r2 = strstr(g_u8RecData, response2);
		r3 = strstr(g_u8RecData, response3);
	}while(!(r1 || r2 || r3 || ((tmr0sec >= timeout))));	 
	if(strstr(g_u8RecData,"GNRMC"))
	{
    u32ADC0Result = 3;
    ((((ADC_T *) ((( uint32_t)0x40000000) + 0xE0000)))->ADCR |= (1ul << 11));
    u32ADC0Result = ((((ADC_T *) ((( uint32_t)0x40000000) + 0xE0000)))->ADDR[(0)] & (0xFFFFul << 0));
    u32ADC0Result = (3.943/2.097)*((u32ADC0Result*3.312) /4096);
    
		memset(temp,0,100);
		parse_g(g_u8RecData, 2, 10, 'C', ',' , temp);
		strcat(g_u8SendData,imei);
		strcat(g_u8SendData,",");
		strcat(g_u8SendData,temp);
		memset(temp,0,100);
		sprintf(temp,",F=%.1f",u32ADC0Result);
		strcat(g_u8SendData,temp);
		memset(temp,0,100);
		sprintf(temp,",LIFE=%d\n",life);
		strcat(g_u8SendData,temp);
  }
  if((strlen(g_u8SendData) > 2900))
  {
    memset(g_u8SendData,0,2500);
    strcat(g_u8SendData,imei);
    strcat(g_u8SendData,"error:RAMfull\n");
  }

}


















void SendAT_GPS(char * command, char * response1, char * response2, char * response3, int32_t timeout)
{
  powerstatus = 0;
  ignition = 0;
  fix = 0;
  emergencystatus = 0;
  tamperalert = 'C';
  ext_bat, int_bat, lati, longi, speed;
  batteryvoltage = 0;
  inputvoltage = 0;
  latitude[12] = 0;
  longitude[12] = 0;
  gpsdate[7] = 0;
  gpstime[7] = 0;
  kmph[6] = 0;
  heading[8] = 0;
  alt[8] = 0;
  sat[2] = 0;
  latdir[2] = 0;
  longdir[2] = 0;
  hdop[6] = 0;
  pdop[5] = 0;
  networkoperator[30] = 0;
  mcc[5] = 0;
  mnc[5] = 0;
  lac[5] = 0;
  cellid[10] = 0;
  packetstatus = 'L';
  nmr[200] = 0;  




	
  SendAT("\r\nAT+QGNSSC=1\r\n\r\n", "OK", "ERROR: 7103" , "OK",5);
  clear();
  

  SendAT("\r\nAT+CSQ\r\n\r\n", "Ready", "OK" , "ERROR",4);	
  parse_g(g_u8RecData, 1, 1, ' ', ',' , signalquality);	

	tmr0sec=0;
	r1=0;
	r2=0;
	r3=0;
	g_u8RecDataptr=0;
 	clear();
	memset(g_u8RecData,0,1000);
  printf("\r\n\r\nAT+GSN\r\n\r\n");
  do{
    g_u8RecData[0] = '\r';
    r1 = strstr(g_u8RecData, response1);
    r2 = strstr(g_u8RecData, response2);
    r3 = strstr(g_u8RecData, response3);
  }while(!(r1 || r2 || r3 || ((tmr0sec >= timeout))));	 
  memset(imei,0,25);
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
	
	tmr0sec=0;
	r1=0;
	r2=0;
	r3=0;
	g_u8RecDataptr=0;
	memset(g_u8RecData,0,1000);
  clear();

	printf("\r\n\r\nAT+QGNSSRD =\"NMEA/RMC\"\r\n\r\n\r\n");
	do{
    g_u8RecData[0] = '\r';
		r1 = strstr(g_u8RecData, response1);
		r2 = strstr(g_u8RecData, response2);
		r3 = strstr(g_u8RecData, response3);
	}while(!(r1 || r2 || r3 || ((tmr0sec >= timeout))));	 
  clear();
	if(strstr(g_u8RecData,"GNRMC"))
  {  
    memset(temp, 0, 100);
    parse_g(g_u8RecData, 1, 1, '$', '*' , temp);
    parse_g(temp, 1, 1, ',', '.' , gpstime);
    parse_g(temp, 3, 4, ',', ',' , latitude);
    parse_g(temp, 4, 5, ',', ',' , latdir);
    parse_g(temp, 5, 6, ',', ',' , longitude);
    parse_g(temp, 6, 7, ',', ',' , longdir);
    parse_g(temp, 8, 9, ',', ',' , heading);
    parse_g(temp, 9, 10, ',', ',' , gpsdate);
    if(latitude != '\0')
      fix = 1;
    else
      fix = 0;
      
    tmr0sec=0;
    r1=0;
    r2=0;
    r3=0;
    g_u8RecDataptr=0;
    memset(g_u8RecData,0,1000);
    clear();
    printf("\r\n\r\nAT+QGNSSRD=\"NMEA/GGA\"\r\n\r\n\r\n");
    do{
      g_u8RecData[0] = '\r';
      r1 = strstr(g_u8RecData, response1);
      r2 = strstr(g_u8RecData, response2);
      r3 = strstr(g_u8RecData, response3);
    }while(!(r1 || r2 || r3 || ((tmr0sec >= timeout))));	 
    clear();  

    memset(temp, 0, 100);
    parse_g(g_u8RecData, 1, 1, '$', '*' , temp);
    parse_g(temp, 7, 8, ',', ',' , sat);
    parse_g(temp, 8, 9, ',', ',' , hdop);
    parse_g(temp, 9, 10, ',', ',' , alt);
    
    tmr0sec=0;
    r1=0;
    r2=0;
    r3=0;
    g_u8RecDataptr=0;
    memset(g_u8RecData,0,1000);
    clear();

    printf("\r\n\r\nAT+QGNSSRD=\"NMEA/VTG\"\r\n\r\n\r\n");
    do{
      g_u8RecData[0] = '\r';
      r1 = strstr(g_u8RecData, response1);
      r2 = strstr(g_u8RecData, response2);
      r3 = strstr(g_u8RecData, response3);
    }while(!(r1 || r2 || r3 || ((tmr0sec >= timeout))));	 
    clear();  

    memset(temp, 0, 100);
    parse_g(g_u8RecData, 1, 1, '$', '*' , temp);
    parse_g(temp, 7, 8, ',', ',' , kmph);
 
    tmr0sec=0;
    r1=0;
    r2=0;
    r3=0;
    g_u8RecDataptr=0;
    memset(g_u8RecData,0,1000);
    clear();

    printf("\r\n\r\nAT+QGNSSRD=\"NMEA/GSA\"\r\n\r\n\r\n");
    do{
      g_u8RecData[0] = '\r';
      r1 = strstr(g_u8RecData, response1);
      r2 = strstr(g_u8RecData, response2);
      r3 = strstr(g_u8RecData, response3);
    }while(!(r1 || r2 || r3 || ((tmr0sec >= timeout))));	 
    clear();  

    memset(temp, 0, 100);
    parse_g(g_u8RecData, 1, 1, '$', '*' , temp);
    parse_g(temp, 15, 16, ',', ',' , pdop);  

    tmr0sec=0;
    r1=0;
    r2=0;
    r3=0;
    g_u8RecDataptr=0;
    memset(g_u8RecData,0,1000);
    clear();
    printf("\r\n\r\nAT+COPS=0,1,0\r\n\r\n\r\n");
    do{
      g_u8RecData[0] = '\r';
      r1 = strstr(g_u8RecData, response1);
      r2 = strstr(g_u8RecData, response2);
      r3 = strstr(g_u8RecData, response3);
    }while(!(r1 || r2 || r3 || ((tmr0sec >= timeout))));	 
    clear();  
   
    tmr0sec=0;
    r1=0;
    r2=0;
    r3=0;
    g_u8RecDataptr=0;
    memset(g_u8RecData,0,1000);
    clear();
    printf("\r\n\r\nAT+COPS?\r\n\r\n\r\n");
    do{
      g_u8RecData[0] = '\r';
      r1 = strstr(g_u8RecData, response1);
      r2 = strstr(g_u8RecData, response2);
      r3 = strstr(g_u8RecData, response3);
    }while(!(r1 || r2 || r3 || ((tmr0sec >= timeout))));	 
    clear();  

    parse_g(g_u8RecData, 1,2, '"', '"' , networkoperator);  
    tmr0sec=0;
    r1=0;
    r2=0;
    r3=0;
    g_u8RecDataptr=0;
    memset(g_u8RecData,0,1000);
    clear();

    printf("\r\n\r\nAT+QENG = 2,3\r\n\r\n\r\n");
    do{
      g_u8RecData[0] = '\r';
      r1 = strstr(g_u8RecData, "NULL");
      r2 = strstr(g_u8RecData, "NULL");
      r3 = strstr(g_u8RecData, "+QENG: 2");
    }while(!(r1 || r2 || r3 || ((tmr0sec >= timeout))));	 
    clear();  
    
    memset(mcc,0,strlen(mcc));
    memset(mnc,0,strlen(mnc));
    memset(lac,0,strlen(lac));
    memset(cellid,0,strlen(cellid));
    memset(nmr,0,200);
    parse_g(g_u8RecData, 2, 3, ',', ',' , mcc);
    parse_g(g_u8RecData, 3, 4, ',', ',' , mnc);
    parse_g(g_u8RecData, 4, 5, ',', ',' , lac);
    parse_g(g_u8RecData, 5, 6, ',', ',' , cellid);
    parse_g(g_u8RecData, 20, 60, ',', ',' , nmr);
   
    

 

    tmr0sec=0;
    r1=0;
    r2=0;
    r3=0;
    g_u8RecDataptr=0;
    memset(g_u8RecData,0,1000);
    clear();    
    printf("\r\n\r\nAT+QENG = 0\r\n\r\n\r\n");
    do{
      g_u8RecData[0] = '\r';
      r1 = strstr(g_u8RecData, "OK");
      r2 = strstr(g_u8RecData, "ERROR");
      r3 = strstr(g_u8RecData, "�RROR");
    }while(!(r1 || r2 || r3 || ((tmr0sec >= timeout))));	 
    clear();  
        
    packetstatus = 'L';
    u32ADC0Result = 3;
    ((((ADC_T *) ((( uint32_t)0x40000000) + 0xE0000)))->ADCR |= (1ul << 11));
    u32ADC0Result = ((((ADC_T *) ((( uint32_t)0x40000000) + 0xE0000)))->ADDR[(0)] & (0xFFFFul << 0));
    u32ADC0Result = (3.943/2.097)*((u32ADC0Result*3.312) /4096);
    batteryvoltage = u32ADC0Result;

    
    
    sprintf(g_u8SendData, "$%s,%s,%s,NR,%c,%s,%s,%d,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%d,%d,%.1f,%.1f,%d,%c,%s,%s,%s,%s,%s,%s\n"    ,"HEADER", "JFT", "2.1.0", packetstatus, imei,vehicleregnum,fix,gpsdate,    gpstime,latitude,latdir,longitude,longdir,kmph,heading,sat,alt,pdop,hdop,networkoperator,    ignition,powerstatus,inputvoltage,batteryvoltage,emergencystatus,tamperalert,signalquality,    mcc, mnc, lac, cellid, nmr);




  
    }
    if((strlen(g_u8SendData) > 2900))
    {
      memset(g_u8SendData,0,2500);
      strcat(g_u8SendData,imei);
      strcat(g_u8SendData,"error:RAMfull\n");
    }
    osDelay(5);
#line 1248 "at_command.c"
}
