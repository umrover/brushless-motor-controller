/*
 * main_bridge.cpp
 *
 *  Created on: Feb 6, 2024
 *      Author: Sashreek
 */
#include "main_bridge.h"
#include "curr_sens.h"
#include "hall_encoder.h"
#include "stm32g4xx_hal.h"
#include <stdio.h>
#include <memory>

extern ADC_HandleTypeDef hadc1;
extern TIM_HandleTypeDef htim3;
extern UART_HandleTypeDef huart4;

uint64_t ADC_count = 0;

std::unique_ptr<HallEncoderDriver> hall_driver;

void setup() {

	CurrSensDriver::ADC_handle = &hadc1;

	hall_driver = std::make_unique<HallEncoderDriver>(HallEncoderDriver());

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

}

void loop() {

//	HAL_ADC_Start_IT(CurrSensDriver::ADC_handle);
	char str[80] = {};
	sprintf(str, "angle = %f\r\n", hall_driver->get_thetad());
	HAL_UART_Transmit (&huart4, reinterpret_cast<uint8_t*>(&str[0]), sizeof(str), 10);
	CurrSensDriver::PhaseCurrents PhaseCurrents;
	CurrSensDriver::get_current_Amp(PhaseCurrents);

	HAL_Delay(1000);
}

