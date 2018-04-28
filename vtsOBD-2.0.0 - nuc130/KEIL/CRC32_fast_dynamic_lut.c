/* Fast lookup table based CRC32 - Lookup table run-time generated
   Minimum Resource Requirements:
	 RAM:   294 Bytes (Stack)
	 ROM:   116 Bytes
	 Execution Performance Cortex-M3@100Mhz Checksum for 256KByte ROM area:
	 29 ms (table initialize = 0.2ms)
	 
	 Suitable for systems that can provide a suitable amount of stack while the CRC 
	 is calculated. Saves code space and processing time. 
*/



#include <inttypes.h>
#include <string.h>
#include "CRC32.h"
 
uint32_t crc32_fdl (uint32_t crc, const uint8_t *buf, size_t len)
{
	static uint32_t table[256];
	static int have_table = 0;

	const uint8_t *p, *q;
 
	if (have_table == 0) {
		int i, j;
		for (i = 0; i < 256; i++) {
			uint32_t rem;
			rem = i;  
			for (j = 0; j < 8; j++) {
				if (rem & 1) {
					rem >>= 1;
					rem ^= CRC32_POLYNOMIAL;
				} else
					rem >>= 1;
			}
			table[i] = rem;
		}
		have_table = 1;
	}
 
	crc = ~crc;
	q = buf + len;
	for (p = buf; p < q; p++) {
	  uint8_t octet;
		octet = *p; 
		crc = (crc >> 8) ^ table[(crc & 0xff) ^ octet];
	}
	return ~crc;
}
