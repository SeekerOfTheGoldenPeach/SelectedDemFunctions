#ifndef POC_CORE_INC_EVENTS_H_
#define POC_CORE_INC_EVENTS_H_

#include "Dem.h"

#define OVER_VOLTAGE_ID (0x00u)
#define UNDER_VOLTAGE_ID (0x01u)

typedef struct event
{
    char EventName[255];
    Dem_EventIdType EventId;
    Dem_EventStatusType EventStatus;
    NvM_BlockIdType blockId;
    uint8_t clientId;
}event;

#endif // POC_CORE_INC_EVENTS_H_
