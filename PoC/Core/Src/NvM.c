#include "NvM.h"
#include "Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_def.h"

extern I2C_HandleTypeDef hi2c1;
#define EEPROM_I2C &hi2c1
#define devAddr 0xA0
#define AddressSize 1

Std_ReturnType NvM_ReadBlock(NvM_BlockIdType BlockId, void *NvM_DstPtr)
{
    if (HAL_I2C_Mem_Read(&hi2c1, devAddr, BlockId, AddressSize, NvM_DstPtr, sizeof(NvM_DstPtr), HAL_MAX_DELAY) != HAL_OK)
    {
        return E_NOK;
    }
    return E_OK;
}

Std_ReturnType NvM_WriteBlock(NvM_BlockIdType BlockId, const void *NvM_SrcPtr)
{
    if (HAL_I2C_Mem_Write(&hi2c1, devAddr, BlockId, AddressSize, NvM_SrcPtr, sizeof(NvM_SrcPtr), HAL_MAX_DELAY) != HAL_OK)
    {
        return E_NOK;
    }
    return E_OK;
}
