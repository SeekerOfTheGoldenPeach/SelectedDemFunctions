/**
 * @file Rte_Dem_Type.h
 * @author O.Komornicki K.Komornicka
 * @date 15 May 2024
 * @brief This header provides data type definition for external data elements
 *
 *
 * @see https://www.autosar.org/fileadmin/standards/R22-11/CP/AUTOSAR_SWS_NVRAMManager.pdf
 */
#ifndef POC_CORE_INC_RTE_NVM_TYPE_H_
#define POC_CORE_INC_RTE_NVM_TYPE_H_

#include <stdint.h>
/*
 * NvM Request Result Types
 */
#define NVM_REQ_OK (0x00u)
#define NVM_REQ_NOT_OK (0x01u)
#define NVM_REQ_PENDING (0x02u)
#define NVM_REQ_INTEGRITY_FAILED (0x03u)
#define NVM_REQ_BLOCK_SKIPPED (0x04u)
#define NVM_REQ_NV_INVALIDATED (0x05u)
#define NVM_REQ_CANCELED (0x06u)
#define NVM_REQ_RESTORED_DEFAULTS (0x08u)
/*
 * NvM Init Block Request Types
 */
#define NVM_INIT_READ_BLOCK (0x00u)
#define NVM_INIT_RESTORE_BLOCK_DEFAULTS (0x01u)
#define NVM_INIT_READ_ALL_BLOCK (0x02u)
#define NVM_INIT_FIRST_INIT_ALL (0x03u)

/**
 * @brief dentification of a NVRAM block via a unique block identifier.
 * Reserved NVRAM block IDs: 0 -> to derive multi block request results via NvM_GetErrorStatus 1-> redundant 
 * NVRAM block which holds the configuration ID
 */
typedef uint16_t NvM_BlockIdType;

/**
 * @brief This is an asynchronous request result returned by the API service NvM_GetErrorStatus. 
 * The availability of an asynchronous request result can be additionally signaled via a callback function.
 */
typedef uint8_t NvM_RequestResultType;

/**
 * @brief Identifies the type of request performed on a block when signaled via the callback function.
 */
typedef uint8_t NvM_InitBlockRequestType;
#endif /*POC_CORE_INC_RTE_NVM_TYPE_H_*/
