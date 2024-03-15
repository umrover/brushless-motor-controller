/*
 * curr_sens.h
 *
 *  Created on: Feb 1, 2024
 *      Author: Sashr
 */

#ifndef INC_CURR_SENS_H_
#define INC_CURR_SENS_H_

#include <filter.h>
#include <cstdint>
#include <vector>
#include "stm32g4xx_hal.h"
#include "filter.h"

#define MAX_ADC_READ_VOLTAGE 3.3
#define MAX_ADC_COUNTS 4096
#define AMPLIFIER_SHIFT 1.65
#define AMPLIFIER_SCALE 20
#define SHUNT_RESISTANCE 0.0005


class CurrSensDriver{

private:
	double phase_currents[3];
	static uint32_t ADCValues[3]; //PhaseA: 0; Phase B: 1; Phase C: 2;
	static double counts_to_amps(uint32_t ADC_counts);

	static MovingAvgFilter curr_A_filter;
	static MovingAvgFilter curr_B_filter;
	static MovingAvgFilter curr_C_filter;

public:

	static ADC_HandleTypeDef* ADC_handle;
	struct PhaseCurrents{
		double iA;
		double iB;
		double iC;
	};
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
	static void get_current_Amp(PhaseCurrents& currents);
	static bool set_voltage_V(PhaseType phase, double voltage);

};


#endif /* INC_CURR_SENS_H_ */
