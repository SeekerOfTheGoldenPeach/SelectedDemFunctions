#include "NvM.h"

Std_ReturnType NvM_ReadBlock(NvM_BlockIdType BlockId, void *NvM_DstPtr)
{
    LOGF(DL_DEBUG, "Operation started! Read Block ID: %x", BlockId);
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
    LOGF(DL_DEBUG, "Operation started! Writing Block ID %x", BlockId);
    if (HAL_I2C_Mem_Write(&hi2c1, devAddr, BlockId, AddressSize, NvM_SrcPtr, sizeof(NvM_SrcPtr), HAL_MAX_DELAY) != HAL_OK)
    {
        HAL_Delay(10);
        LOGFF(DL_FATAL, "Operation failed!");
        return E_NOK;
    }
    HAL_Delay(10);
    LOGF(DL_DEBUG, "Operation succeeded!");
    return E_OK;
}
