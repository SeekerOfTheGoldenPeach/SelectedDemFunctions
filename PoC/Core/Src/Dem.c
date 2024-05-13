#include "Dem.h"

Std_ReturnType Dem_SetEventStatus(Dem_EventIdType EventId, Dem_EventStatusType EventStatus)
{
    LOGF(DL_DEBUG, "Operation started!");
    struct event event;
    const void *pointerToData;
    uint8_t data[4] = {0};
    if (EventStatus == DEM_EVENT_STATUS_FAILED)
    {
        switch (EventId)
        {
        case OVER_VOLTAGE_ID:
            event = overVoltage;
            break;

        case UNDER_VOLTAGE_ID:
            event = underVoltage;
            break;
        }
        LOGF(DL_DEBUG, "Got %s notification!", event.EventName);
        event.EventStatus = EventStatus;
        data[0] = event.EventId;
        data[1] = event.EventStatus;
        data[2] = 0xff;
        data[3] = 0xff;
        pointerToData = &data;
        LOGF(DL_DEBUG, "Operation succeeded! Data passed to write: %x %x %x %x", data[0], data[1], data[2], data[3]);
        LOGF(DL_DEBUG, "Start writing to NvM");
        if (NvM_WriteBlock(event.blockId, pointerToData) == E_OK)
        {
            return E_OK;
        }
    }
    LOGFF(DL_FATAL, "Operation failed!");
    return E_NOK;
}

Std_ReturnType Dem_GetStatusOfDTC(uint8_t ClientId, uint8_t *DTCStatus)
{
    LOGF(DL_DEBUG, "Operation started!");
    struct event event;

    switch (ClientId)
    {
    case OVER_VOLTAGE_ID:
        event = overVoltage;
        break;

    case UNDER_VOLTAGE_ID:
        event = underVoltage;
        break;
    }

    LOGF(DL_DEBUG, "Requesting status: %s", event.EventName);
    if (NvM_ReadBlock(event.blockId, DTCStatus) == E_OK)
    {
        LOGL(DL_INFO, "DEM: %s status: %x %x %x %x", event.EventName, DTCStatus[0], DTCStatus[1], DTCStatus[2], DTCStatus[3]);
        LOGF(DL_DEBUG, "Operation finished!");

        return E_OK;
    }

    LOGFF(DL_FATAL, "Operation failed!");
    return E_NOK;
}

Std_ReturnType Dem_ClearDTC(uint8_t ClientId)
{
    LOGF(DL_DEBUG, "Operation started!");
    uint8_t emptyData[4] = {0};
    struct event event;

    switch (ClientId)
    {
    case OVER_VOLTAGE_ID:
        event = overVoltage;
        break;

    case UNDER_VOLTAGE_ID:
        event = underVoltage;
        break;
    }
    LOGF(DL_DEBUG, "Clear: %s  | BlockId: ", event.EventName, event.blockId);
    if (NvM_WriteBlock(event.blockId, emptyData) == E_OK)
    {
        LOGF(DL_DEBUG, "Operation finished!");
        return E_OK;
    }

    LOGFF(DL_FATAL, "Operation failed!");
    return E_NOK;
}
