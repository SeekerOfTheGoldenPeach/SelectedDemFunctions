#include "VoltageMonitor.h"
#define DLT_LOG_CONTEX "vMon"
void CheckVoltage()
{
  const float SupplyVoltage = 3.0;
  const float ADCResolution = 4095.0;
  uint16_t adcResult = 0;
  float voltage = 0;
  char strVoltage[50];

  LOGF(DL_DEBUG, "Operation Started!");
  if (HAL_ADC_PollForConversion(&hadc1, 20) == HAL_OK)
  {

    adcResult = HAL_ADC_GetValue(&hadc1);
    voltage = (SupplyVoltage * adcResult) / ADCResolution;
    HAL_ADC_Start(&hadc1);
    voltage = roundf(10 * voltage) / 10;
    gcvt(voltage, 6, strVoltage);
  }

  LOGF(DL_DEBUG, "ReadADC: %d  |  Voltage: %s", adcResult, strVoltage);

  if (voltage >= 2.5)
  {
    LOGF(DL_DEBUG, "OverVoltage detected!");
    if (Dem_SetEventStatus(OVER_VOLTAGE_ID, DEM_EVENT_STATUS_FAILED) != E_OK)
    {
      LOGFF(DL_FATAL, "Reporting Event failed!");
    }
    LOGF(DL_DEBUG, "Reporting OverVoltage succeed!");
  }
  if (voltage <= 1.5)
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
#undef DLT_LOG_CONTEX
