/*
 * curr_sens.cpp
 *
 *  Created on: Feb 1, 2024
 *      Author: Sashr
 */
#include "curr_sens.h"
#include "stm32g4xx_hal.h"

#define SHUNT_RES 0.005
#define AMPLIFICATION 20*(SHUNT_RES)*

ADC_HandleTypeDef* CurrSensDriver::ADC_handle = nullptr;
uint32_t CurrSensDriver::ADCValues[3];

void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef* hadc)
{
    // Read & Update The ADC Result
	if(hadc == CurrSensDriver::ADC_handle){
		CurrSensDriver::ADCValues[0] = HAL_ADC_GetValue(hadc);
	}
	HAL_ADC_Stop_IT(hadc);
}

double CurrSensDriver::get_current_Amp(PhaseType phase){

	uint32_t ADC_counts = CurrSensDriver::ADCValues[0];
	double sense_out = ( ADC_counts * MAX_ADC_READ_VOLTAGE/MAX_ADC_COUNTS);
	double shifted_voltage = sense_out - AMPLIFIER_SHIFT;
	double scaled_voltage = shifted_voltage/AMPLIFIER_SCALE;
	double current = scaled_voltage/SHUNT_RESISTANCE;

	return current;
}



double CurrSensDriver::get_voltage_V(VoltageSenseType voltageInput){
	return 0;
}

bool CurrSensDriver::set_voltage_V(PhaseType phase, double voltage){
	return true;
}

