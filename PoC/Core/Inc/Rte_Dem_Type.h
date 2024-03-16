#include <stdint.h>

typedef uint16_t Dem_EventIdType;

struct Dem_EventStatusType
{
    uint8_t DEM_EVENT_STATUS_PASSED = 0x00;
    uint8_t DEM_EVENT_STATUS_FAILED = 0x01;
    uint8_t DEM_EVENT_STATUS_PREPASSED = 0x02;
    uint8_t DEM_EVENT_STATUS_PREFAILED = 0x03;
    uint8_t DEM_EVENT_STATUS_FDC_THRESHOLD_REACHED = 0x04;
};
