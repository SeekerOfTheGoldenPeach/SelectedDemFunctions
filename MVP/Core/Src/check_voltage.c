#include "check_voltage.h"
#include "Rte_Dem_Type.h"
#include "Events.h"
#include "../../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_def.h"

uint32_t vol_conv = 0;

void Check_Voltage(uint32_t vol_read)
{
  vol_conv = (vol_read * 5.0) / 4095.0;
  if (vol_conv <= 2)
  {
    Dem_SetEventStatus(OVER_VOLTAGE_ID, DEM_EVENT_STATUS_FAILED);
  }
  if (vol_conv >= 4)
  {
    Dem_SetEventStatus(UNDER_VOLTAGE_ID, DEM_EVENT_STATUS_FAILED);
  }
}
