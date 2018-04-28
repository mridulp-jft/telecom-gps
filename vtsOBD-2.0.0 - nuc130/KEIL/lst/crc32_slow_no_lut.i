#line 1 "CRC32_slow_no_lut.c"









 



#line 1 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\inttypes.h"
 
 





 

 








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






 
#line 20 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\inttypes.h"



#line 33 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\inttypes.h"


     

#line 51 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\inttypes.h"

#line 66 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\inttypes.h"

#line 81 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\inttypes.h"

#line 96 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\inttypes.h"

#line 111 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\inttypes.h"

#line 126 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\inttypes.h"

#line 141 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\inttypes.h"

#line 156 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\inttypes.h"

#line 171 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\inttypes.h"

#line 186 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\inttypes.h"

#line 201 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\inttypes.h"





    



      typedef unsigned short wchar_t;  
#line 221 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\inttypes.h"

typedef struct imaxdiv_t { intmax_t quot, rem; } imaxdiv_t;
    





__declspec(__nothrow) intmax_t strtoimax(const char * __restrict  ,
                   char ** __restrict  , int  ) __attribute__((__nonnull__(1)));
     
__declspec(__nothrow) uintmax_t strtoumax(const char * __restrict  ,
                    char ** __restrict  , int  ) __attribute__((__nonnull__(1)));
     

__declspec(__nothrow) intmax_t wcstoimax(const wchar_t * __restrict  ,
                   wchar_t ** __restrict  , int  ) __attribute__((__nonnull__(1)));
__declspec(__nothrow) uintmax_t wcstoumax(const wchar_t * __restrict  ,
                    wchar_t ** __restrict  , int  ) __attribute__((__nonnull__(1)));

extern __declspec(__nothrow) __attribute__((const)) intmax_t imaxabs(intmax_t  );
   



 
extern __declspec(__nothrow) __attribute__((const)) imaxdiv_t imaxdiv(intmax_t  , intmax_t  );
   











 







 

#line 15 "CRC32_slow_no_lut.c"
#line 1 "CRC32.h"
#line 2 "CRC32.h"

extern uint32_t crc32_fsl(uint32_t crc, const uint8_t *buf, uint32_t len);
extern uint32_t crc32_fdl(uint32_t crc, const uint8_t *buf, uint32_t len);
extern uint32_t crc32_snl(uint32_t crc, const uint8_t *buf, uint32_t len);

#line 16 "CRC32_slow_no_lut.c"

uint32_t crc32_snl (uint32_t crc, const uint8_t *buf, uint32_t len) 

{
  uint8_t* current = (unsigned char*) buf;
	crc = ~crc; 
  while (len--)
  {
		uint32_t j;
    crc ^= *current++;
    for (j = 0; j < 8; j++)
      if (crc & 1)
        crc = (crc >> 1) ^ 0xedb88320ull;
      else
        crc =  crc >> 1;
  }
  return ~crc; 
}
