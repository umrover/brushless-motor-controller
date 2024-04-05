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
#include "main_bridge.h"
#include <algorithm>


void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	// check if it gets here
	CurrSensDriver::PhaseCurrents PhaseCurrents;
	CurrSensDriver::get_current_Amp(PhaseCurrents);

	auto [curr_alpha, curr_beta] = tf_clarke(PhaseCurrents.iA, PhaseCurrents.iB, PhaseCurrents.iC);

	double theta_d =  HallEncoderDriver::get_thetad();
	auto [curr_d, curr_q] = tf_park(curr_alpha, curr_beta, theta_d);

	return;
}

void HAL_TIM_IC_CaptureCallback(TIM_HandleTypeDef* htim)
{
	// increment position counts by one every time in the callback

	// Every time this callback is called, the angle in the
	//motor increases by delta theta

	uint32_t H1 = TIM3->CCR1;
	uint32_t H2 = TIM3->CCR2;
	uint32_t H3 = TIM3->CCR3;

	uint32_t longest_CCR = std::max({H1, H2, H3});
	// The longest CCR represents the amount of time taken for the motor to move delta theta
	// where delta theta is (360/number of poles)
	double time_per_count = TIM3->ARR/(64000000);
	double angular_velocity = DELTA_THETA/(longest_CCR*time_per_count); //degrees per second
	motor_velocity = angular_velocity;
	motor_position += DELTA_THETA;
}
