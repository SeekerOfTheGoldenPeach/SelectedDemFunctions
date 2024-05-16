#include "NvM.h"
#undef DLT_LOG_CONTEX
#define DLT_LOG_CONTEX "NVM"

Std_ReturnType NvM_ReadBlock(NvM_BlockIdType BlockId, void *NvM_DstPtr)
{
    Std_ReturnType ret_val = E_NOK;

    LOGF(DL_DEBUG, "Operation started! Read Block ID: %x", BlockId);
    if (HAL_I2C_Mem_Read(&hi2c1, devAddr, BlockId, AddressSize, NvM_DstPtr, BLOCK_SIZE, HAL_MAX_DELAY) == HAL_OK)
    {
        LOGF(DL_DEBUG, "Operation succeeded!");
        ret_val = E_OK;
    }
    else
    {
        LOGFF(DL_FATAL, "Operation failed!");
        ret_val = E_NOK;
    }
    return ret_val;
}

Std_ReturnType NvM_WriteBlock(NvM_BlockIdType BlockId, const void *NvM_SrcPtr)
{
    Std_ReturnType ret_val = E_NOK;

    LOGF(DL_DEBUG, "Operation started! Writing Block ID %x", BlockId);
    if (HAL_I2C_Mem_Write(&hi2c1, devAddr, BlockId, AddressSize, NvM_SrcPtr, BLOCK_SIZE, HAL_MAX_DELAY) == HAL_OK)
    {
        LOGF(DL_DEBUG, "Operation succeeded!");
        ret_val = E_OK;
    }
    else
    {
        LOGFF(DL_FATAL, "Operation failed!");
        ret_val = E_NOK;
    }
    HAL_Delay(10);
    return ret_val;
}
#undef DLT_LOG_CONTEX
