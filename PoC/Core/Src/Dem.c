#include "Dem.h"
#include "NvM.h"
#include "Events.h"

struct event overVoltage = {"OverVoltage", OVER_VOLTAGE_ID, DEM_EVENT_STATUS_PASSED, 0x02};
struct event underVoltage = {"UnderVoltage", UNDER_VOLTAGE_ID, DEM_EVENT_STATUS_PASSED, 0x10};

Std_ReturnType Dem_SetEventStatus(Dem_EventIdType EventId, Dem_EventStatusType EventStatus)
{
    const void *pointerToData;
    char data[4] = {0};
    if (EventStatus == DEM_EVENT_STATUS_FAILED)
    {
        switch (EventId)
        {
        case OVER_VOLTAGE_ID:
            overVoltage.EventStatus = EventStatus;
            data[1] = overVoltage.EventId;
            data[2] = overVoltage.EventStatus;
            pointerToData = &data;
            if (NvM_WriteBlock(overVoltage.blockId, pointerToData) == E_OK)
            {
                return E_OK;
            }

        case UNDER_VOLTAGE_ID:
            underVoltage.EventStatus = EventStatus;
            data[1] = underVoltage.EventId;
            data[2] = underVoltage.EventStatus;
            pointerToData = &data;
            if (NvM_WriteBlock(underVoltage.blockId, pointerToData) == E_OK)
            {
                return E_OK;
            }
        }
    }
    return E_NOK;
}

Std_ReturnType Dem_GetStatusOfDTC (uint8_t ClientId,uint8_t* DTCStatus)
{
    switch (ClientId)
        {
        case OVER_VOLTAGE_ID:
            if (NvM_ReadBlock(overVoltage.blockId, DTCStatus) == E_OK)
            {
                return E_OK;
            }

        case UNDER_VOLTAGE_ID:
            if (NvM_ReadBlock(underVoltage.blockId, DTCStatus) == E_OK)
            {
                return E_OK;
            }
        }
    return E_NOK;
}