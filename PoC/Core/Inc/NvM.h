/**
 * @file NvM.h
 * @author O.Komornicki K.Komornicka
 * @date 15 May 2024
 * @brief This header providesAPI and the configuration of the AUTOSAR Basic Software module NVRAM Manager (NvM)
 * 
 * 
 *The NvM module shall provide services to ensure the data storage and maintenance of
 *NV (non volatile) data according to their individual requirements in an automotive environment. 
 *The NvM module shall be able to administrate the NV data of an EEPROM
 *and/or a FLASH EEPROM emulation device.
 *The NvM module shall provide the required synchronous/asynchronous services for
 *the management and the maintenance of NV data (init/read/write/control).
 *
 * @see https://www.autosar.org/fileadmin/standards/R22-11/CP/AUTOSAR_SWS_NVRAMManager.pdf
 */

#ifndef POC_CORE_INC_NVM_H_
#define POC_CORE_INC_NVM_H_

#include "StdTypes.h"
#include "Rte_NvM_Type.h"
#include "stm32f4xx_hal.h"
#include "DLTuc.h"
#include "stm32f4xx_hal_def.h"

/*
* HAL I2C MEM configuration
*/
extern I2C_HandleTypeDef hi2c1;

#define EEPROM_I2C &hi2c1
#define devAddr 0xA0
#define AddressSize 1
#define BLOCK_SIZE 4

/*
 * Event Block IDs
 */
#define OVER_VOLTAGE_BOCK_ID (0x30u)
#define UNDER_VOLTAGE_BOCK_ID (0x34u)

/*!
 ************************************************************************************************
 * \brief NvM_GetErrorStatus
 * \details The function NvM_GetErrorStatus shall read the block dependent 
 * error/status information in the administrative part of a NVRAM block. The status/
 * error information of a NVRAM block shall be set by a former or current asynchronous request.
 *
 * \param[in] BlockId - The block identifier uniquely identifies one NVRAM block descriptor.
 * A NVRAM block descriptor contains all needed information about a single NVRAM block.
 * \param[out] RequestResultPtr - Pointer to where to store the request result. See NvM_Request
 * ResultType.
 * \retval E_OK: The block dependent error/status information was read successfully.
 *         E_NOT_OK: An error occured.
 *************************************************************************************************/
Std_ReturnType NvM_GetErrorStatus(NvM_BlockIdType BlockId, NvM_RequestResultType *RequestResultPtr);

/*!
 ************************************************************************************************
 * \brief NvM_ReadBlock
 * \details The job of the function NvM_ReadBlock shall copy the data 
 * of the NV block to the corresponding RAM block.
 * 
 * \param[in] BlockId - The block identifier uniquely identifies one NVRAM block descriptor. 
 * A NVRAM block descriptor contains all needed information about a single NVRAM block.
 * \param[out] NvM_DstPtr - Pointer to the RAM data block.
 * \retval E_OK: request has been accepted
 *         E_NOT_OK: request has not been accepted
 *************************************************************************************************/
Std_ReturnType NvM_ReadBlock(NvM_BlockIdType BlockId, void *NvM_DstPtr);

/*!
 ************************************************************************************************
 * \brief NvM_WriteBlock
 * \details Service to copy the data of the RAM block to its corresponding NV block.
 *
 * \param[in] BlockId - The block identifier uniquely identifies one NVRAM block descriptor. 
 * A NVRAM block descriptor contains all needed information about a single NVRAM block.
 * \param[in] NvM_SrcPtr - Pointer to the RAM data block.
 * \retval E_OK: request has been accepted
 *         E_NOT_OK: request has not been accepted
 *************************************************************************************************/
Std_ReturnType NvM_WriteBlock(NvM_BlockIdType BlockId, const void *NvM_SrcPtr);

#endif /*POC_CORE_INC_NVM_H_*/
