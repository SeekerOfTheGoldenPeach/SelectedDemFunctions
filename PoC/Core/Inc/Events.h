/**
 * @file Events.h
 * @author O.Komornicki
 * @date 15 May 2024
 * @brief This header provides API and the configuration of the AUTOSAR basic software module Diagnostic Event Manager (Dem)
 *
 * Diagnostic Event Manager (Dem) component is responsible for processing
 * and storing diagnostic events (errors) and associated data. Further, the Dem provides
 * fault information to the Dcm (e.g. read all stored DTCs from the event memory).
 * The Dem offers interfaces to the application layer and to other BSW modules.
 *
 * @see https://www.autosar.org/fileadmin/standards/R22-11/CP/AUTOSAR_SWS_DiagnosticEventManager.pdf
 */
#ifndef POC_CORE_INC_EVENTS_H_
#define POC_CORE_INC_EVENTS_H_

#include "Dem.h"
/*
 * Events IDs
 */
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

extern struct event overVoltage;
extern struct event underVoltage;

#endif // POC_CORE_INC_EVENTS_H_
