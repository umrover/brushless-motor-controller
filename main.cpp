/*
 * main_bridge.cpp
 *
 *  Created on: Feb 6, 2024
 *      Author: Sashreek
 */
#include "space_vector_pwm.h"
#include "math.h"
#include <stdio.h>
#include <memory>
#include <cstdint> 

double voltage_a = 0.0;
double voltage_b = 0.0;
double theta = 0.001;
double radius = 1.154701;

uint32_t TIM_CHANNEL_4 = 0;
uint32_t TIM_CHANNEL_1 = 0;

uint32_t TIM8 = 0;
uint32_t TIM20 = 0;

TimerChannel_t Phase_A_timer{0x0000, &TIM_CHANNEL_4, &TIM8, nullptr};
TimerChannel_t Phase_B_timer{0x0000, &TIM_CHANNEL_1, &TIM8, nullptr};
TimerChannel_t Phase_C_timer{0x0000, &TIM_CHANNEL_4, &TIM20, nullptr};

std::unique_ptr<SpaceVectorPWM> SVPWM_obj = std::make_unique<SpaceVectorPWM>(100.0, Phase_A_timer, Phase_B_timer, Phase_C_timer);

int main() {

	while(true){
		voltage_b = radius * sin(theta);
		voltage_a = radius * cos(theta);
		SVPWM_obj->setInputVoltages(voltage_a, voltage_b);
		SVPWM_obj->update();
		theta += 0.0020943951;
		theta = std::fmod(theta, 6.28318530718);
	}

}

