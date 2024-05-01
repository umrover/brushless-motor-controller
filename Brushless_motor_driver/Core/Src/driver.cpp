/*
 * driver.cpp
 *
 *  Created on: Jan 25, 2024
 *      Author: Sashreek and Jonah
 */
#include "main.h"
#include "curr_sens.h"
#include "hall_encoder.h"
#include "math_utils.h"
#include "data_types.h"
#include "main_bridge.h"
#include <algorithm>

extern std::unique_ptr<HallEncoderDriver> hall_driver;

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) {
	// check if it gets here
	CurrSensDriver::PhaseCurrents PhaseCurrents;
	CurrSensDriver::get_current_Amp(PhaseCurrents);

	auto [curr_alpha, curr_beta] = tf_clarke(PhaseCurrents.iA, PhaseCurrents.iB,
			PhaseCurrents.iC);

	double theta_d = hall_driver->get_thetad();
	auto [curr_d, curr_q] = tf_park(curr_alpha, curr_beta, theta_d);

	return;
}

void HAL_TIM_IC_CaptureCallback(TIM_HandleTypeDef *htim) {
	// increment position counts by one every time in the callback

	// Every time this callback is called, the angle in the
	//motor increases by delta theta

	// not TODO: reconfigure as falling edge trigger

	// Time since last falling edge of each Hall Effect
	// TODO: need to reset CCR to 0 at the end
//	uint32_t *H1 = &TIM3->CCR1;
//	uint32_t *H2 = &TIM3->CCR2;
//	uint32_t *H3 = &TIM3->CCR3;

	hall_driver->setState(
			(uint8_t) HAL_GPIO_ReadPin(GPIOD, GPIO_PIN_0),
			(uint8_t) HAL_GPIO_ReadPin(GPIOD, GPIO_PIN_1),
			(uint8_t) HAL_GPIO_ReadPin(GPIOD, GPIO_PIN_2));


	// int8_t direction = (hall_driver.prev_state > cu) ? (-1) : 1;

//	std::vector<volatile uint32_t*> encoder_timer_readings(3);
//	encoder_timer_readings = {H1, H2, H3};
//	uint32_t longest_CCR = 0;
//	uint8_t hall_encoder_index = 0;
//	for (uint8_t i=0; i<encoder_timer_readings.size(); i++) {
//	    if(*(encoder_timer_readings[i]) > longest_CCR){
//	    	longest_CCR = *(encoder_timer_readings[i]);
//	    	hall_encoder_index = i;
//	    }
//
//	}
//
//
//	// The longest CCR represents the amount of time taken for the motor to move delta theta
//	// where delta theta is (360/number of poles)
//	double time_per_count = double(TIM3->ARR)/(64000000.0);
//	double angular_velocity = DELTA_THETA/(longest_CCR*time_per_count); //degrees per second
//	data_values.motor_velocity = angular_velocity;
//	data_values.motor_position += DELTA_THETA;
//	longest_CCR = 0;
//	*encoder_timer_readings[hall_encoder_index] = 0;
}
