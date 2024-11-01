/*
 * space_vector_pwm.cpp
 *
 *  Created on: Oct 29, 2024
 *      Author: Sashreek
 */
#include "space_vector_pwm.h"
#include <cmath>

#define SQRT_3 1.7320508075688772

SpaceVectorPWM::SpaceVectorPWM(double maxModulationIndex, TimerChannel_t PhaseA, TimerChannel_t PhaseB, TimerChannel_t PhaseC ){
	this->maxModulationIndex = maxModulationIndex;
	PhaseA_iface = PhaseA;
	PhaseB_iface = PhaseB;
	PhaseC_iface = PhaseC;

	HAL_TIM_PWM_Start(PhaseA_iface.htim, PhaseA_iface.channel);
	HAL_TIM_PWM_Start(PhaseB_iface.htim, PhaseB_iface.channel);
	HAL_TIM_PWM_Start(PhaseC_iface.htim, PhaseC_iface.channel);
}

void SpaceVectorPWM::setInputVoltages(double alphaVoltage, double betaVoltage){

	this->alphaVoltage = alphaVoltage;
	this->betaVoltage = betaVoltage;
}

void SpaceVectorPWM::getDutyCycles(double& dutyCycleA, double& dutyCycleB, double& dutyCycleC) const{
	dutyCycleA = this->dutyCycleA;
	dutyCycleB = this->dutyCycleB;
	dutyCycleC = this->dutyCycleC;

}

uint8_t SpaceVectorPWM::calculate_sector() {
    // Calculate V_ref1, V_ref2, and V_ref3 using the given equations
	// sector number outputs
	// (0-60]		- 3
	// (60-120]		- 1
	// (120-180]	- 5
	// (180-240]	- 4
	// (240, 320]	- 6
	// (320, 0]		- 2

	double U_alpha = this->alphaVoltage;
	double U_beta = this->betaVoltage;

    double V_ref1 = U_beta;
    double V_ref2 = (-U_beta + U_alpha * SQRT_3) / 2;
    double V_ref3 = (-U_beta - U_alpha * SQRT_3) / 2;

    // Determine the values of a, b, and c based on the conditions
    int a = (V_ref1 > 0) ? 1 : 0;
    int b = (V_ref2 > 0) ? 1 : 0;
    int c = (V_ref3 > 0) ? 1 : 0;

    // Calculate the sector number
    int sector = 4 * c + 2 * b + a;

    return sector;
}

void SpaceVectorPWM::calculate_XYZ(double U_alpha, double U_beta){
	double X  = U_beta;
	double Y = (SQRT_3 * U_alpha + U_beta) / 2;
	double Z = (-SQRT_3 * U_alpha + U_beta) / 2;
}


std::pair<double, double> SpaceVectorPWM::calculate_vector_ontime(uint8_t sector){

	std::pair<double, double> result;
	switch (sector){
	case 1:
		result.first = this->Z;
		result.second = this->Y;

	case 2:
		result.first = this-Y;
		result.second = -1*this->X;

	case 3:
		result.first = -1*this->Z;
		result.second = this->X;

	case 4:
		result.first = -1*this->X;
		result.second = this->Z;

	case 5:
		result.first = this->X;
		result.second = this->Y;

	}
}



void SpaceVectorPWM::calculateDutyCycles(){
	// function that calculates duty-cycles on each phase given the alpha and beta values
	// The space of all p0ssible vectors can be divided into 6 sectors: 0,1,2,3,4,5.
	// The boundaries of each of these sectors are the basic vectors

	// Steps to calculate duty cycle as per https://e2e.ti.com/cfs-file/__key/communityserver-discussions-components-files/171/svgen_5F00_dq.pdf
	//  - Determination of the sector
	//	- Calculation of X, Y and Z
	//	- Calculation of t1 and t2
	//	- Determination of the duty cycle taon, tbon and tcon
	//	- Assignment of the duty cycles to Ta, Tb and Tc




}


void SpaceVectorPWM::writePWM(){

	// convert duty cycle to CCR
	// write the CCRs
	double dutyCycleA;
	double dutyCycleB;
	double dutyCycleC;

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
