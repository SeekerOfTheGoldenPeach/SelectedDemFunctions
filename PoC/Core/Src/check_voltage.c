#include <stdio.h>
#include <string.h>
#include "check_voltage.h"
#include "Rte_Dem_Type.h"
#include "Events.h"
#include "../../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_def.h"
extern UART_HandleTypeDef huart2;

char msg[20];
uint32_t vol=0;
uint32_t vol_conv=0;

void Check_Voltage(ADC_HandleTypeDef* voltage)
{ 
  HAL_ADC_Start(&voltage);
  HAL_ADC_PollForConversion(&voltage,20);
  vol= HAL_ADC_GetValue(&voltage);
  vol_conv=(vol*5.0)/4095.0; 
  if (vol_conv <= 2)
  { 
 	 //HAL_UART_Transmit(&huart2,(uint8_t *)msg, strlen(msg),HAL_MAX_DELAY);
  	 //HAL_Delay(500);
  	 Dem_SetEventStatus(OVER_VOLTAGE_ID, DEM_EVENT_STATUS_FAILED);
  }
  if(vol_conv>=4)
  {

 	 //HAL_UART_Transmit(&huart2,(uint8_t *)msg, strlen(msg),HAL_MAX_DELAY);
  	// HAL_Delay(500);
  	 Dem_SetEventStatus(UNDER_VOLTAGE_ID, DEM_EVENT_STATUS_FAILED);
  }  
  }