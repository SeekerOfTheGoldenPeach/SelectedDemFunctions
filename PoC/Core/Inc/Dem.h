#ifndef POC_CORE_INC_DEM_H_
#define POC_CORE_INC_DEM_H_

#include "StdTypes.h"
#include "Rte_Dem_Type.h"
#include "Rte_NvM_Type.h"
#include "DLTuc.h"
#include "NvM.h"
#include "Events.h"

#define OVER_VOLTAGE_ID (0x00u)
#define UNDER_VOLTAGE_ID (0x01u)

#define DLT_LOG_CONTEX "DEM"

extern struct event overVoltage;
extern struct event underVoltage;

Std_ReturnType Dem_SetEventStatus(Dem_EventIdType EventId, Dem_EventStatusType EventStatus);

Std_ReturnType Dem_GetStatusOfDTC(uint8_t ClientId, uint8_t *DTCStatus);

Std_ReturnType Dem_ClearDTC(uint8_t ClientId);

#endif // POC_CORE_INC_DEM_H_
