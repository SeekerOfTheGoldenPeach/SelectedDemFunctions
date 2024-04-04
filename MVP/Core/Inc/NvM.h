#include "StdTypes.h"
#include "Rte_NvM_Type.h"

#include "stm32f4xx_hal.h"

#ifndef INC_EEPROM_H_
#define INC_EEPROM_H_

Std_ReturnType NvM_GetErrorStatus(NvM_BlockIdType BlockId, NvM_RequestResultType *RequestResultPtr);

Std_ReturnType NvM_ReadBlock(NvM_BlockIdType BlockId, void *NvM_DstPtr);

Std_ReturnType NvM_WriteBlock(NvM_BlockIdType BlockId, const void *NvM_SrcPtr);

#endif /* INC_EEPROM_H_ */