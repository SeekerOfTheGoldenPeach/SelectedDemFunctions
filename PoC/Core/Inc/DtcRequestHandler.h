/**
 * @file DtcRequestHandler.h
 * @author O.Komornicki
 * @date 15 May 2024
 * @brief This header provides API and the configuration of the AUTOSAR basic software module Diagnostic Event Manager 
 *
 * Dtc Request Handler component is responsible for handling, reading and clearing
 * errors
 *
 * @see https://www.autosar.org/fileadmin/standards/R22-11/CP/AUTOSAR_SWS_DiagnosticEventManager.pdf
 */

#ifndef POC_CORE_INC_DTCREQUESTHANDLER_H_
#define POC_CORE_INC_DTCREQUESTHANDLER_H_

#include "StdTypes.h"
#include "Dem.h"


/*!
 ************************************************************************************************
 * \brief ClearAllDtc
 * \details 
 *  Call this function when the DTC must be cleared
 ************************************************************************************************
 * */
void ClearAllDtc();

/*!
 ************************************************************************************************
 * \brief ReadAllDtc
 * \details 
 *  Call this function when the DTC must be read
 ************************************************************************************************
 * */
void ReadAllDtc();

#endif // POC_CORE_INC_DTCREQUESTHANDLER_H_
