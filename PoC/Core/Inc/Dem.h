#ifndef POC_CORE_INC_DEM_H_
#define POC_CORE_INC_DEM_H_

#include "StdTypes.h"
#include "Rte_Dem_Type.h"
#include "Rte_NvM_Type.h"

typedef struct event
{
    char EventName[255];
    Dem_EventIdType EventId;
    Dem_EventStatusType EventStatus;
    NvM_BlockIdType blockId;
};

Std_ReturnType Dem_SetEventStatus(Dem_EventIdType EventId, Dem_EventStatusType EventStatus);

Std_ReturnType Dem_GetStatusOfDTC (uint8_t ClientId,uint8_t* DTCStatus);

#endif  // POC_CORE_INC_DEM_H_
