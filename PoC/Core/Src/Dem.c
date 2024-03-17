#include "Dem.h"
#include "NvM.h"
#include "Events.h"

struct event overVoltage = {"OverVoltage", OVER_VOLTAGE_ID, DEM_EVENT_STATUS_PASSED, 0x10, "U1401"};
struct event underVoltage = {"UnderVoltage", UNDER_VOLTAGE_ID, DEM_EVENT_STATUS_PASSED, 0x20, "X"};

Std_ReturnType Dem_SetEventStatus(Dem_EventIdType EventId, Dem_EventStatusType EventStatus)
{
    if (EventStatus == DEM_EVENT_STATUS_FAILED)
    {
        switch (EventId)
        {
        case OVER_VOLTAGE_ID:
            overVoltage.EventStatus = EventStatus;

            const void *pointerToDataAddress = &overVoltage.DTC;
            NvM_WriteBlock(overVoltage.blockId, pointerToDataAddress);
            return E_OK;

        case UNDER_VOLTAGE_ID:
            underVoltage.EventStatus = EventStatus;
            return E_OK;
        }
    }
    return E_NOK;
}
