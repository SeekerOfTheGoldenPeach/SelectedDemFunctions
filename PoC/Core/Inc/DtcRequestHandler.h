/**
 * @file DtcRequestHandler.h
 * @author O.Komornicki K.Komornicka
 * @date 15 May 2024
 * @brief Dtc Request Handler component is responsible for reading and clearing DTCs
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
