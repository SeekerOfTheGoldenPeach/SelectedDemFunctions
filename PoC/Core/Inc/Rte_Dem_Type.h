/**
 * @file Rte_Dem_Type.h
 * @author O.Komornicki K.Komornicka
 * @date 15 May 2024
 * @brief This header provides data type definition for external data elements
 *
 *
 * @see https://www.autosar.org/fileadmin/standards/R22-11/CP/AUTOSAR_SWS_DiagnosticEventManager.pdf
 */
#ifndef POC_CORE_INC_RTE_DEM_TYPE_H_
#define POC_CORE_INC_RTE_DEM_TYPE_H_

#include <stdint.h>

/**
 * @brief Identification of an event by assigned EventId. 
 * The EventId is assigned by the Dem. Example: 1 refers to monitor x, 2 refers to monitor y, etc.
 */
typedef uint16_t Dem_EventIdType;

/**
 * @brief This type contains all monitor test result values, which can be reported via Dem_SetEventStatus().
 */
typedef uint8_t Dem_EventStatusType;

/*
 * DEM Event Status Types
 */
#define DEM_EVENT_STATUS_PASSED (0x00u)
#define DEM_EVENT_STATUS_FAILED (0x01u)
#define DEM_EVENT_STATUS_PREPASSED (0x02u)
#define DEM_EVENT_STATUS_PREFAILED (0x03u)
#define DEM_EVENT_STATUS_FDC_THRESHOLD_REACHED (0x04u)

#endif /*POC_CORE_INC_RTE_DEM_TYPE_H_*/
