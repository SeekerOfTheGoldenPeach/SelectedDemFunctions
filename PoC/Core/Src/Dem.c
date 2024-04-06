#include "Dem.h"

#define DLT_LOG_CONTEX           "DEM"

struct event overVoltage = {"OverVoltage", OVER_VOLTAGE_ID, DEM_EVENT_STATUS_PASSED, 0x00};
struct event underVoltage = {"UnderVoltage", UNDER_VOLTAGE_ID, DEM_EVENT_STATUS_PASSED, 0x04};

Std_ReturnType Dem_SetEventStatus(Dem_EventIdType EventId, Dem_EventStatusType EventStatus)
{
	LOGF(DL_DEBUG, "Operation started!");
    const void *pointerToData;
    char data[4] = {0};
    if (EventStatus == DEM_EVENT_STATUS_FAILED)
    {
        switch (EventId)
        {
        case OVER_VOLTAGE_ID:
        	LOGF(DL_DEBUG, "Got OverVoltage notification!");
            overVoltage.EventStatus = EventStatus;
            data[1] = overVoltage.EventId;
            data[0] = overVoltage.EventStatus;
            pointerToData = &data;
            LOGF(DL_DEBUG, "Start writing to NvM");
            if (NvM_WriteBlock(overVoltage.blockId, pointerToData) == E_OK)
            {
            	LOGF(DL_DEBUG, "Operation succeeded!");
                return E_OK;
            }

        case UNDER_VOLTAGE_ID:
        	LOGF(DL_DEBUG, "Got UnderVoltage notification!");
            underVoltage.EventStatus = EventStatus;
            data[1] = underVoltage.EventId;
            data[0] = underVoltage.EventStatus;
            pointerToData = &data;
            LOGF(DL_DEBUG, "Start writing to NvM");
            if (NvM_WriteBlock(underVoltage.blockId, pointerToData) == E_OK)
            {
            	LOGF(DL_DEBUG, "Operation succeeded!");
                return E_OK;
            }
        }
    }
    LOGFF(DL_FATAL, "Operation failed!");
    return E_NOK;
}

Std_ReturnType Dem_GetStatusOfDTC (uint8_t ClientId,uint8_t* DTCStatus)
{
	LOGF(DL_DEBUG, "Operation started!");
    switch (ClientId)
        {
        case OVER_VOLTAGE_ID:
            if (NvM_ReadBlock(overVoltage.blockId, DTCStatus) == E_OK)
            {
            	LOGL(DL_INFO, "DEM: OverVoltage status: %x", DTCStatus);
            	LOGF(DL_DEBUG, "Operation finished!");

                return E_OK;
            }

        case UNDER_VOLTAGE_ID:
            if (NvM_ReadBlock(underVoltage.blockId, DTCStatus) == E_OK)
            {
            	LOGL(DL_INFO, "DEM: UnderVoltage status: %x", DTCStatus);
            	LOGF(DL_DEBUG, "Operation finished!");
                return E_OK;
            }
        }
    LOGFF(DL_FATAL, "Operation failed!");
    return E_NOK;
}
