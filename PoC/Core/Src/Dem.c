#include "Dem.h"
#undef DLT_LOG_CONTEX
#define DLT_LOG_CONTEX "DEM"

Std_ReturnType prepareEventDataForNvm(event event, Dem_EventStatusType EventStatus)
{
    Std_ReturnType ret_val = E_NOK;
    uint8_t data[4] = {0};
    const void *pointerToData = &data;

    LOGF(DL_DEBUG, "Got %s notification!", event.EventName);
    event.EventStatus = EventStatus;
    data[0] = event.EventId;
    data[1] = event.EventStatus;
    data[2] = 0xff;
    data[3] = 0xff;
    LOGF(DL_DEBUG, "Operation succeeded! Data passed to write: %x %x %x %x", data[0], data[1], data[2], data[3]);
    LOGF(DL_DEBUG, "Start writing to NvM");
    if (E_OK == NvM_WriteBlock(event.blockId, pointerToData))
    {
        ret_val = E_OK;
    }
    else
    {
        LOGFF(DL_FATAL, "Operation failed!");
        ret_val = E_NOK;
    }
    return ret_val;
}

Std_ReturnType readEventDataFromNvm(event event, uint8_t *DTCStatus)
{
    Std_ReturnType ret_val = E_NOK;
    LOGF(DL_DEBUG, "Requesting status: %s", event.EventName);
    if (E_OK == NvM_ReadBlock(event.blockId, DTCStatus))
    {
        LOGL(DL_INFO, "DEM: %s status: %x %x %x %x", event.EventName, DTCStatus[0], DTCStatus[1], DTCStatus[2], DTCStatus[3]);
        LOGF(DL_DEBUG, "Operation finished!");

        ret_val = E_OK;
    }
    else
    {
        LOGFF(DL_FATAL, "Operation failed!");
        ret_val = E_NOK;
    }
    return ret_val;
}

Std_ReturnType clearEventBlock(event event)
{
    uint8_t emptyData[4] = {0};
    Std_ReturnType ret_val = E_NOK;

    LOGF(DL_DEBUG, "Clear: %s  | BlockId: %x", event.EventName, event.blockId);
    if (E_OK == NvM_WriteBlock(event.blockId, emptyData))
    {
        LOGF(DL_DEBUG, "Operation finished!");
        ret_val = E_OK;
    }
    else
    {
        LOGFF(DL_FATAL, "Operation failed!");
        ret_val = E_NOK;
    }
    return ret_val;
}

Std_ReturnType Dem_SetEventStatus(Dem_EventIdType EventId, Dem_EventStatusType EventStatus)
{
    LOGF(DL_DEBUG, "Operation started!");
    struct event event = {"EmptyEvent", 0xFF, 0xFF, 0xFF, 0xFF};

    Std_ReturnType ret_val = E_NOK;

    if (DEM_EVENT_STATUS_FAILED == EventStatus)
    {
        switch (EventId)
        {
        case OVER_VOLTAGE_ID:
            event = overVoltage;
            ret_val = prepareEventDataForNvm(event, EventStatus);
            break;

        case UNDER_VOLTAGE_ID:
            event = underVoltage;
            ret_val = prepareEventDataForNvm(event, EventStatus);
            break;

        default:
            break;
        }
    }
    return ret_val;
}

Std_ReturnType Dem_GetStatusOfDTC(uint8_t ClientId, uint8_t *DTCStatus)
{
    LOGF(DL_DEBUG, "Operation started!");
    struct event event = {"EmptyEvent", 0xFF, 0xFF, 0xFF, 0xFF};
    Std_ReturnType ret_val = E_NOK;

    switch (ClientId)
    {
    case OVER_VOLTAGE_ID:
        event = overVoltage;
        ret_val = readEventDataFromNvm(event, DTCStatus);
        break;

    case UNDER_VOLTAGE_ID:
        event = underVoltage;
        ret_val = readEventDataFromNvm(event, DTCStatus);
        break;

    default:
        break;
    }
    return ret_val;
}

Std_ReturnType Dem_ClearDTC(uint8_t ClientId)
{
    LOGF(DL_DEBUG, "Operation started!");
    Std_ReturnType ret_val = E_NOK;

    struct event event = {"EmptyEvent", 0xFF, 0xFF, 0xFF, 0xFF};

    switch (ClientId)
    {
    case OVER_VOLTAGE_ID:
        event = overVoltage;
        ret_val = clearEventBlock(event);
        break;

    case UNDER_VOLTAGE_ID:
        event = underVoltage;
        ret_val = clearEventBlock(event);
        break;

    default:
        break;
    }

    return ret_val;
}

#undef DLT_LOG_CONTEX
