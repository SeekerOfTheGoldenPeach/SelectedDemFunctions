#include <stdint.h>

typedef uint16_t Dem_EventIdType;

typedef uint8_t Dem_EventStatusType;

#define DEM_EVENT_STATUS_PASSED (0x00u)
#define DEM_EVENT_STATUS_FAILED (0x01u)
#define DEM_EVENT_STATUS_PREPASSED (0x02u)
#define DEM_EVENT_STATUS_PREFAILED (0x03u)
#define DEM_EVENT_STATUS_FDC_THRESHOLD_REACHED (0x04u)
