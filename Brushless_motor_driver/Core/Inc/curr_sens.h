/*
 * curr_sens.h
 *
 *  Created on: Feb 1, 2024
 *      Author: Sashr
 */

#ifndef INC_CURR_SENS_H_
#define INC_CURR_SENS_H_
#include <cstdint>
#include "stm32g4xx_hal.h"

#define MAX_ADC_READ_VOLTAGE 3.3
#define MAX_ADC_COUNTS 4096
#define AMPLIFIER_SHIFT 1.65
#define AMPLIFIER_SCALE 20
#define SHUNT_RESISTANCE 0.0005


class CurrSensDriver{
public:

	static ADC_HandleTypeDef* ADC_handle;
	static uint32_t ADCValues[3]; //PhaseA: 0; Phase B: 1; Phase C: 2;
	enum class PhaseType{
		A,B,C
	};
	enum class VoltageSenseType{
		SupplySense,
		SHASense,
		SHBSense,
		SHCSense
	};
	static double get_voltage_V(VoltageSenseType voltageInput);
	static double get_current_Amp(PhaseType phase);
	static bool set_voltage_V(PhaseType phase, double voltage);

};


#endif /* INC_CURR_SENS_H_ */
