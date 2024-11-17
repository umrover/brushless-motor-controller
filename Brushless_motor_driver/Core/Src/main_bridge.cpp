/*
 * main_bridge.cpp
 *
 *  Created on: Feb 6, 2024
 *      Author: Sashreek
 */
#include "main_bridge.h"
#include "curr_sens.h"
#include "hall_encoder.h"
#include "space_vector_pwm.h"
#include "math.h"
#include "stm32g4xx_hal.h"
#include <stdio.h>
#include <memory>

extern ADC_HandleTypeDef hadc1;

extern TIM_HandleTypeDef htim1;
extern TIM_HandleTypeDef htim2;
extern TIM_HandleTypeDef htim3;
extern TIM_HandleTypeDef htim8;
extern TIM_HandleTypeDef htim20;
//extern UART_HandleTypeDef huart4;


std::unique_ptr<HallEncoderDriver> hall_driver;

double voltage_a = 0.0;
double voltage_b = 0.0;
double theta = 0;
double radius = 5.0;

void setup() {

	CurrSensDriver::ADC_handle = &hadc1;

	hall_driver = std::make_unique<HallEncoderDriver>(HallEncoderDriver());

	HAL_ADCEx_Calibration_Start(CurrSensDriver::ADC_handle, ADC_SINGLE_ENDED);
//	HAL_TIM_Base_Start_IT(&htim8);
//	HAL_TIM_Base_Start_IT(&htim20);

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
// 	char str[80] = {};
// 	sprintf(str, "angle = %f\r\n", hall_driver->get_thetad());
// //	HAL_UART_Transmit (&huart4, reinterpret_cast<uint8_t*>(&str[0]), sizeof(str), 10);
// 	CurrSensDriver::PhaseCurrents PhaseCurrents;
// 	CurrSensDriver::get_current_Amp(PhaseCurrents);


	TimerChannel_t Phase_A_timer{&htim8, 4, TIM8, &TIM8->CCR4, &TIM8->ARR, &TIM8->PSC};
	TimerChannel_t Phase_B_timer{&htim8, 1, TIM8, &TIM8->CCR1, &TIM8->ARR, &TIM8->PSC};
	TimerChannel_t Phase_C_timer{&htim20, 4, TIM20, &TIM20->CCR4, &TIM20->ARR, &TIM20->PSC};
	
	SpaceVectorPWM SVPWM_obj (100.0, Phase_A_timer, Phase_B_timer, Phase_C_timer);

	while (theta <= 6.2831){
		voltage_b = radius * sin(theta);
		voltage_a = radius * cos(theta);
		SVPWM_obj.setInputVoltages(voltage_a, voltage_b);
		theta += 0.0174533;
	}


	HAL_Delay(1000);
}

