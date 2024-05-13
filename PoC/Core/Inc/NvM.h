#ifndef INC_EEPROM_H_
#define INC_EEPROM_H_

#include "StdTypes.h"
#include "Rte_NvM_Type.h"
#include "stm32f4xx_hal.h"
#include "DLTuc.h"
#include "stm32f4xx_hal_def.h"

extern I2C_HandleTypeDef hi2c1;

#define DLT_LOG_CONTEX "NVM"

#define EEPROM_I2C &hi2c1
#define devAddr 0xA0
#define AddressSize 1

#define OVER_VOLTAGE_BOCK_ID (0x30u)
#define UNDER_VOLTAGE_BOCK_ID (0x34u)

Std_ReturnType NvM_GetErrorStatus(NvM_BlockIdType BlockId, NvM_RequestResultType *RequestResultPtr);

Std_ReturnType NvM_ReadBlock(NvM_BlockIdType BlockId, void *NvM_DstPtr);

Std_ReturnType NvM_WriteBlock(NvM_BlockIdType BlockId, const void *NvM_SrcPtr);

#endif /* INC_EEPROM_H_ */
