/*
 * curr_sens.cpp
 *
 *  Created on: Feb 1, 2024
 *      Author: Sashreek
 */
#include "curr_sens.h"
#include "stm32g4xx_hal.h"
#include "filter.h"

ADC_HandleTypeDef* CurrSensDriver::ADC_handle = nullptr;
uint32_t CurrSensDriver::ADCValues[3];

MovingAvgFilter CurrSensDriver::curr_A_filter(10);
MovingAvgFilter CurrSensDriver::curr_B_filter(10);
MovingAvgFilter CurrSensDriver::curr_C_filter(10);

double CurrSensDriver::counts_to_amps(uint32_t ADC_counts){

	double sense_out = ( ADC_counts * MAX_ADC_READ_VOLTAGE/MAX_ADC_COUNTS);
	double shifted_voltage = sense_out - AMPLIFIER_SHIFT;
	double scaled_voltage = shifted_voltage/AMPLIFIER_SCALE;
	double current = scaled_voltage/SHUNT_RESISTANCE;
	return current;
}


void CurrSensDriver::get_current_Amp(PhaseCurrents& currents){

	HAL_ADC_Start_DMA(ADC_handle, CurrSensDriver::ADCValues, 3);
	curr_A_filter.add_new_element(counts_to_amps(ADCValues[0]));
	curr_B_filter.add_new_element(counts_to_amps(ADCValues[1]));
	curr_C_filter.add_new_element(counts_to_amps(ADCValues[2]));
	currents.iA = curr_A_filter.filtered_output();
	currents.iB = curr_B_filter.filtered_output();
	currents.iC = curr_C_filter.filtered_output();
}



double CurrSensDriver::get_voltage_V(VoltageSenseType voltageInput){
	return 0;
}

bool CurrSensDriver::set_voltage_V(PhaseType phase, double voltage){
	return true;
}

