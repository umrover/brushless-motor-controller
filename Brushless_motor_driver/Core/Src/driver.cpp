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


void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	// check if it gets here
	double curr_A = CurrSensDriver::get_current_Amp(CurrSensDriver::PhaseType::A);
	double curr_B = CurrSensDriver::get_current_Amp(CurrSensDriver::PhaseType::B);
	double curr_C = CurrSensDriver::get_current_Amp(CurrSensDriver::PhaseType::C);

	auto [curr_alpha, curr_beta] = tf_clarke(curr_A, curr_B, curr_C);

	double theta_d =  HallEncoderDriver::get_thetad();
	auto [curr_d, curr_q] = tf_park(curr_alpha, curr_beta, theta_d);



	return;

}
