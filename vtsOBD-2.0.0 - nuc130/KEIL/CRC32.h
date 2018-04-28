#include <inttypes.h>

extern uint32_t crc32_fsl(uint32_t crc, const uint8_t *buf, uint32_t len);
extern uint32_t crc32_fdl(uint32_t crc, const uint8_t *buf, uint32_t len);
extern uint32_t crc32_snl(uint32_t crc, const uint8_t *buf, uint32_t len);

#define CRC32_POLYNOMIAL 0xedb88320ull
