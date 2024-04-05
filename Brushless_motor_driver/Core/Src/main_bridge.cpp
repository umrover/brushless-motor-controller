/*
 * main_bridge.cpp
 *
 *  Created on: Feb 6, 2024
 *      Author: Sashreek
 */
#include "main_bridge.h"
#include "curr_sens.h"
#include "stm32g4xx_hal.h"

extern ADC_HandleTypeDef hadc1;
extern TIM_HandleTypeDef htim3;
uint64_t ADC_count = 0;

void setup() {

	CurrSensDriver::ADC_handle = &hadc1;
	HAL_ADCEx_Calibration_Start(CurrSensDriver::ADC_handle, ADC_SINGLE_ENDED);
	HAL_TIM_Base_Start_IT(&htim3);
	HAL_TIM_IC_Start_IT(&htim3, TIM_CHANNEL_1);
	HAL_TIM_IC_Start_IT(&htim3, TIM_CHANNEL_2);
	HAL_TIM_IC_Start_IT(&htim3, TIM_CHANNEL_3);
	// Enable the gate driver
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_6, GPIO_PIN_SET);
	HAL_Delay(10);
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_0, GPIO_PIN_SET);

	HAL_Delay(10);

	motor_velocity = 0;
	motor_position = 0;

}

void loop() {

//	HAL_ADC_Start_IT(CurrSensDriver::ADC_handle);
	CurrSensDriver::PhaseCurrents PhaseCurrents;
	CurrSensDriver::get_current_Amp(PhaseCurrents);
	HAL_Delay(1000);
}

