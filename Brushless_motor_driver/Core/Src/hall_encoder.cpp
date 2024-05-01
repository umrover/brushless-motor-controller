/*
 * hall_encoder.cpp
 *
 *  Created on: Feb 6, 2024
 *      Author: Sashr
 */
#include "hall_encoder.h"
#include "stm32g4xx_hal.h"

HallEncoderDriver::HallEncoderDriver(){
	prev_state = HallEncoderState((uint8_t) HAL_GPIO_ReadPin(GPIOD, GPIO_PIN_0),
			(uint8_t) HAL_GPIO_ReadPin(GPIOD, GPIO_PIN_1),
			(uint8_t) HAL_GPIO_ReadPin(GPIOD, GPIO_PIN_2));

	curr_state = HallEncoderState((uint8_t) HAL_GPIO_ReadPin(GPIOD, GPIO_PIN_0),
			(uint8_t) HAL_GPIO_ReadPin(GPIOD, GPIO_PIN_1),
			(uint8_t) HAL_GPIO_ReadPin(GPIOD, GPIO_PIN_2));
}

double HallEncoderDriver::get_thetad() {
	return angle.getAngleRad();
}

int8_t HallEncoderDriver::getDirection() {
	int8_t diff = prev_state.getState() - curr_state.getState();

	// NOTE assumes we only transition one state at a time

	if (diff == 0) {
		return HALT;
	} else if (diff == 1 || diff == -5) {
		return FWD;
	} else if (diff == -1 || diff == 5) {
		return BWD;
	} else {
		// OHNO!!!
		return -128;
	}

}
