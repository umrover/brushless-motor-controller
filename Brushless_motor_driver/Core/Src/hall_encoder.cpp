/*
 * hall_encoder.cpp
 *
 *  Created on: Feb 6, 2024
 *      Author: Sashr
 */
#include "hall_encoder.h"
#include "stm32g4xx_hal.h"

HallEncoderDriver::HallEncoderDriver(){
	prev_state = std::make_unique<HallEncoderState>(HallEncoderState(
			(uint8_t) HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_2),
			(uint8_t) HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_9),
			(uint8_t) HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_6)));

	curr_state = std::make_unique<HallEncoderState>(HallEncoderState(
			(uint8_t) HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_2),
			(uint8_t) HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_9),
			(uint8_t) HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_6)));
}

double HallEncoderDriver::get_thetad() {
	return angle.getAngleRad();
}

int8_t HallEncoderDriver::getDirection() {
	int8_t diff = prev_state->getState() - curr_state->getState();

	// NOTE assumes we only transition one state at a time

	if (diff == 1 || diff == -5) {
		return FWD;
	} else if (diff == -1 || diff == 5) {
		return BWD;
	} else {
		// OHNO!!!
		return -128;
	}

}

void HallEncoderDriver::setState(uint8_t H1, uint8_t H2, uint8_t H3){
	HallEncoderState input_state (H1, H2, H3);
	if (*curr_state != input_state){
		*prev_state = *curr_state;
		this->curr_state->setState(H1, H2, H3);
		int8_t direction = getDirection();
		AngleType increment(DELTA_THETA * direction);
		this->angle += increment;
	}


}
