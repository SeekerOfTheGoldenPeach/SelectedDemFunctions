/**
 * @file Dem.h
 * @author O.Komornicki K.Komornicka
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
#ifndef POC_CORE_INC_DEM_H_
#define POC_CORE_INC_DEM_H_

#include "StdTypes.h"
#include "Rte_Dem_Type.h"
#include "Rte_NvM_Type.h"
#include "DLTuc.h"
#include "NvM.h"
#include "Events.h"

/*
 * Events IDs
 */
#define OVER_VOLTAGE_ID (0x00u)
#define UNDER_VOLTAGE_ID (0x01u)

/*!
 ************************************************************************************************
 * \brief Dem_SetEventStatus
 * \details Called by SW-Cs or BSW modules to report monitor status information to the Dem.
 * BSW modules calling Dem_SetEventStatus can safely ignore the return value.
 *
 * \param[in] EventId - Identification of an event by assigned EventId.
 * \param[in] EventStatus - Monitor test result
 * \retval E_OK: set of event status was successful
 *         E_NOT_OK: Event status setting or processing failed or could not be accepted.
 *************************************************************************************************/
Std_ReturnType Dem_SetEventStatus(Dem_EventIdType EventId, Dem_EventStatusType EventStatus);

/*!
 ************************************************************************************************
 * \brief Dem_GetStatusOfDTC
 * \details Gets the status of a DTC.
 *
 * \param[in] ClientId - Unique client id, assigned to the instance of the calling module.
 * \param[out] DTCStatus - This parameter receives the status information of the requested DTC.
 * \retval E_OK: The status of the DTC is correctly provided in the DTCStatus parameter.
 *         E_NOT_OK: No DTC selected
 *************************************************************************************************/
Std_ReturnType Dem_GetStatusOfDTC(uint8_t ClientId, uint8_t *DTCStatus);

/*!
 ************************************************************************************************
 * \brief Dem_ClearDTC
 * \details Clears single DTCs, as well as groups of DTCs.
 *
 * \param[in] ClientId - Unique client id, assigned to the instance of the calling module.
 * \retval E_OK: DTC successfully cleared
 *         E_NOT_OK: No DTC selected
 *************************************************************************************************/
Std_ReturnType Dem_ClearDTC(uint8_t ClientId);

#endif // POC_CORE_INC_DEM_H_
