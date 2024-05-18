#include "VoltageMonitor.h"
#undef DLT_LOG_CONTEX
#define DLT_LOG_CONTEX "vMon"

void CheckVoltage()
{
  const float SupplyVoltage = 3.0;
  const float ADCResolution = 4095.0;
  uint32_t adcResult = 0;
  float voltage = 0;
  char strVoltage[50];

  LOGF(DL_DEBUG, "Operation Started!");

  HAL_ADC_Start_DMA(&hadc1, &adcResult, 1);
  voltage = (SupplyVoltage * adcResult) / ADCResolution;
  voltage = roundf(10 * voltage) / 10;
  gcvt(voltage, 6, strVoltage);
  //replacing gcvt crashes buttons operations
  //sprintf (strVoltage, "%d.%01u", (int)voltage, (int) ((voltage- (int) voltage ) * 100) );

  LOGF(DL_DEBUG, "ReadADC: %d  |  Voltage: %s", adcResult, strVoltage);

  if (voltage >= OVER_VOLTAGE_THRESHOLD)
  {
    LOGF(DL_DEBUG, "OverVoltage detected!");
    if (Dem_SetEventStatus(overVoltage.clientId, DEM_EVENT_STATUS_FAILED) != E_OK)
    {
      LOGFF(DL_FATAL, "Reporting Event failed!");
    }
    LOGF(DL_DEBUG, "Reporting OverVoltage succeed!");
  }
  if (voltage <= UNDER_VOLTAGE_THRESHOLD)
  {
    LOGF(DL_DEBUG, "UnderVoltage detected!");
    if (Dem_SetEventStatus(underVoltage.clientId, DEM_EVENT_STATUS_FAILED) != E_OK)
    {
      LOGFF(DL_FATAL, "Reporting Event failed!");
    }
    LOGF(DL_DEBUG, "Reporting UnderVoltage succeed");
  }
  LOGF(DL_DEBUG, "Operation Finished");
}
#undef DLT_LOG_CONTEX
