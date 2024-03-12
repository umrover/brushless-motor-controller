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
	CurrSensDriver::PhaseCurrents PhaseCurrents;
	CurrSensDriver::get_current_Amp(PhaseCurrents);

	auto [curr_alpha, curr_beta] = tf_clarke(PhaseCurrents.iA, PhaseCurrents.iB, PhaseCurrents.iC);

	double theta_d =  HallEncoderDriver::get_thetad();
	auto [curr_d, curr_q] = tf_park(curr_alpha, curr_beta, theta_d);



	return;

}
