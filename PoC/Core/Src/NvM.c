#include "NvM.h"
#include "../../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_def.h"

extern I2C_HandleTypeDef hi2c1;
#define EEPROM_I2C &hi2c1
#define devAddr 0xA0
#define AddressSize 1

#define DLT_LOG_CONTEX           "NVM"

Std_ReturnType NvM_ReadBlock(NvM_BlockIdType BlockId, void *NvM_DstPtr)
{
	LOGF(DL_DEBUG, "Operation started!");
    if (HAL_I2C_Mem_Read(&hi2c1, devAddr, BlockId, AddressSize, NvM_DstPtr, sizeof(NvM_DstPtr), HAL_MAX_DELAY) != HAL_OK)
    {
    	LOGFF(DL_FATAL, "Operation failed!");
        return E_NOK;
    }
    LOGF(DL_DEBUG, "Operation succeeded!");
    return E_OK;
}

Std_ReturnType NvM_WriteBlock(NvM_BlockIdType BlockId, const void *NvM_SrcPtr)
{
	LOGF(DL_DEBUG, "Operation started!");
    if (HAL_I2C_Mem_Write(&hi2c1, devAddr, BlockId, AddressSize, NvM_SrcPtr, sizeof(NvM_SrcPtr), HAL_MAX_DELAY) != HAL_OK)
    {
    	HAL_Delay(5);
    	LOGFF(DL_FATAL, "Operation failed!");
        return E_NOK;
    }
    LOGF(DL_DEBUG, "Operation succeeded!");
    return E_OK;
}
