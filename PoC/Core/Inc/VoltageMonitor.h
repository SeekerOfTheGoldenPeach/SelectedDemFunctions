/**
 * @file VoltageMonitor.h
 * @author O.Komornicki K.Komornicka
 * @date 15 May 2024
 * @brief ADC Voltage monitor. Component checks if read adc value falls within required range.
 */

#ifndef POC_CORE_INC_VOLTAGEMONITOR_H_
#define POC_CORE_INC_VOLTAGEMONITOR_H_

#include "DLTuc.h"
#include "StdTypes.h"
#include "Rte_Dem_Type.h"
#include "Events.h"
#include <stdio.h>
#include <math.h>

/*
 * ADC Voltage thresholds
 */

#define OVER_VOLTAGE_THRESHOLD 2.5
#define UNDER_VOLTAGE_THRESHOLD 1.5

/*
 * ADC handler
 */
extern ADC_HandleTypeDef hadc1;

/*!
 ************************************************************************************************
 * \brief CheckVoltage
 * \details Reads ADC value and checks if within thresholds
 *
 * \retval void
 *************************************************************************************************/
void CheckVoltage();

#endif // POC_CORE_INC_VOLTAGEMONITOR_H_
