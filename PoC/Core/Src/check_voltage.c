#include "check_voltage.h"
#define DLT_LOG_CONTEX           "vMon"

uint32_t vol_conv = 0;

void Check_Voltage(uint32_t vol_read)
{
	LOGF(DL_DEBUG, "Operation Started");

  vol_conv = (vol_read * 5.0) / 4095.0;
  if (vol_conv <= 2)
  {
	  LOGF(DL_DEBUG, "OverVoltage detected!");
    if (Dem_SetEventStatus(OVER_VOLTAGE_ID, DEM_EVENT_STATUS_FAILED) != E_OK)
    {
    	LOGFF(DL_FATAL, "Reporting Event failed!");
    }
    LOGF(DL_DEBUG, "Reporting OverVoltage succeed!");
  }
  if (vol_conv >= 4)
  {
	  LOGF(DL_DEBUG, "UnderVoltage detected!");
    if (Dem_SetEventStatus(UNDER_VOLTAGE_ID, DEM_EVENT_STATUS_FAILED) != E_OK)
    {
    	LOGFF(DL_FATAL, "Reporting Event failed!");
    }
    LOGF(DL_DEBUG, "Reporting UnderVoltage succeed");
  }
  LOGF(DL_DEBUG, "Operation Finished");
}
