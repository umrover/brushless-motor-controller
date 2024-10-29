/*
 * space_vector_pwm.cpp
 *
 *  Created on: Oct 29, 2024
 *      Author: Sashreek
 */
#include "space_vector_pwm.h"



SpaceVectorPWM::SpaceVectorPWM(float maxModulationIndex, TimerChannel_t PhaseA, TimerChannel_t PhaseB, TimerChannel_t PhaseC ){
	this->maxModulationIndex = maxModulationIndex;
	PhaseA_iface = PhaseA;
	PhaseB_iface = PhaseB;
	PhaseC_iface = PhaseC;

	HAL_TIM_PWM_Start(PhaseA_iface.htim, PhaseA_iface.channel);
	HAL_TIM_PWM_Start(PhaseB_iface.htim, PhaseB_iface.channel);
	HAL_TIM_PWM_Start(PhaseC_iface.htim, PhaseC_iface.channel);
}

void SpaceVectorPWM::setInputVoltages(float alphaVoltage, float betaVoltage){

	this->alphaVoltage = alphaVoltage;
	this->betaVoltage = betaVoltage;
}

void SpaceVectorPWM::getDutyCycles(float& dutyCycleA, float& dutyCycleB, float& dutyCycleC) const{
	dutyCycleA = this->dutyCycleA;
	dutyCycleB = this->dutyCycleB;
	dutyCycleC = this->dutyCycleC;

}

SpaceVectorPWM::calculateDutyCycles(){
	// function that calculates duty-cycles on each phase given the alpha and beta values
	// The space of all p0ssible vectors can be divided into 6 sectors: 0,1,2,3,4,5.
	// The boundaries of each of these sectors are the basic vectors
}


void SpaceVectorPWM::writePWM(){

	// convert duty cycle to CCR
	// write the CCRs
	float dutyCycleA;
	float dutyCycleB;
	float dutyCycleC;

	uint32_t ARR_phase_A = PhaseA_iface.TIM_obj->ARR;
	uint32_t ARR_phase_B = PhaseB_iface.TIM_obj->ARR;
	uint32_t ARR_phase_C = PhaseC_iface.TIM_obj->ARR;

	uint32_t CCR_to_set_Phase_A = (uint32_t) (dutyCycleA * ARR_phase_A);
	uint32_t CCR_to_set_Phase_B = (uint32_t) (dutyCycleB * ARR_phase_B);
	uint32_t CCR_to_set_Phase_C = (uint32_t) (dutyCycleC * ARR_phase_C);

	PhaseA_iface.TIM_obj->PhaseA_iface.CCR_addr;
	PhaseB_iface.TIM_obj->PhaseB_iface.CCR_addr;
	PhaseC_iface.TIM_obj->PhaseC_iface.CCR_addr;


}
