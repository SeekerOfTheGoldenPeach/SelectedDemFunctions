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
	LOGF(DL_DEBUG, "Operation started!");

    Std_ReturnType ret_val = E_NOK;
    uint8_t* data = (uint8_t*)NvM_SrcPtr;

    LOGF(DL_DEBUG, "Checking EEPROM availability...");
    if (HAL_I2C_IsDeviceReady(&hi2c1, devAddr, TRIALS, PING_TIME_OUT) != HAL_OK)
    {
    	LOGFF(DL_FATAL, "Timeout, device not available after %d ms", (TRIALS*PING_TIME_OUT));
        LOGFF(DL_FATAL, "Operation failed!");
        ret_val = E_NOK;
    } else
    {
    	LOGF(DL_DEBUG, "Requested write Block ID %x", BlockId);
    	if (HAL_I2C_Mem_Write(&hi2c1, devAddr, BlockId, AddressSize, data, BLOCK_SIZE, HAL_MAX_DELAY) != HAL_OK)
    	{
    		LOGFF(DL_FATAL, "Operation failed!");
    		ret_val = E_NOK;
    	} else
    	{
    		LOGF(DL_DEBUG, "Operation succeeded!");
    		ret_val = E_OK;
        }
    }

    return ret_val;
}
#undef DLT_LOG_CONTEX
