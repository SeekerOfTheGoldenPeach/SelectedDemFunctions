#include "check_voltage.h"
#include "Rte_Dem_Type.h"
#include "Events.h"
#include "../../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_def.h"
#include "logger.h"
#include "StdTypes.h"
uint32_t vol_conv = 0;

void Check_Voltage(uint32_t vol_read)
{
  logger("Voltage Monitor: Operation Started\n\r");
  vol_conv = (vol_read * 5.0) / 4095.0;
  if (vol_conv <= 2)
  {
	logger("Voltage Monitor: OverVoltage detected!\n\r");
    if (Dem_SetEventStatus(OVER_VOLTAGE_ID, DEM_EVENT_STATUS_FAILED) != E_OK)
    {
    	logger("Voltage Monitor: Reporting Event failed!\n\r");
    }
    logger("Voltage Monitor: Reporting OverVoltage succeed!\n\r");
  }
  if (vol_conv >= 4)
  {
	logger("Voltage Monitor: UnderVoltage detected!\n\r");
    if (Dem_SetEventStatus(UNDER_VOLTAGE_ID, DEM_EVENT_STATUS_FAILED) != E_OK)
    {
    	logger("Voltage Monitor: Reporting Event failed!\n\r");
    }
    logger("Voltage Monitor: Reporting UnderVoltage succeed!\n\r");
  }
  logger("Voltage Monitor: Operation Finished\n\r");
}
