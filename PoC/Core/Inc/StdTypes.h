/**
 * @file StdTypes.H
 * @author O.Komornicki
 * @date 15 May 2024
 * @brief This header provides specifies the AUTOSAR standard types
 *
 *
 * @see https://www.autosar.org/fileadmin/standards/R22-11/CP/AUTOSAR_SWS_StandardTypes.pdf
 */
#ifndef POC_CORE_INC_STDTYPES_H_
#define POC_CORE_INC_STDTYPES_H_

#include <stdint.h>

/*
 * Events IDs
 */
#define E_OK (0u)
#define E_NOK (1u)

/**
 * @brief This type can be used as standard API return type which is shared between the RTE and the BSW Modules.
 * The Std_ReturnType shall normally be used with value E_OK or E_NOT_OK. If those return values are not sufficient 
 * user specific values can be defined by using the 6 least specific bits.
 */
typedef uint8_t Std_ReturnType;
#endif /*POC_CORE_INC_STDTYPES_H_*/
