#ifndef POC_CORE_INC_VOLTAGEMONITOR_H_
#define POC_CORE_INC_VOLTAGEMONITOR_H_

#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_conf.h"
#include "DLTuc.h"
#include "StdTypes.h"
#include "Rte_Dem_Type.h"
#include "Events.h"
#include "stm32f4xx_hal_def.h"
#include "stm32f4xx_hal_adc.h"
#include <stdio.h>
#include <math.h>

extern ADC_HandleTypeDef hadc1;

void CheckVoltage();

#endif // POC_CORE_INC_VOLTAGEMONITOR_H_
