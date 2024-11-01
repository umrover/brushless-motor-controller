/*
 * space_vector_pwm.h
 *
 *  Created on: Oct 29, 2024
 *      Author: Sashreek
 */

#ifndef SPACE_VECTOR_PWM_H
#define SPACE_VECTOR_PWM_H

#include "stm32g4xx_hal.h"
#include <utility>

typedef struct {
    TIM_HandleTypeDef *htim;
    uint32_t channel;

    TIM_TypeDef * TIM_obj;
    uint32_t CCR_addr;

} TimerChannel_t;

class SpaceVectorPWM {
public:
    // Constructor to initialize the SVPWM generator with specific parameters
    SpaceVectorPWM(double maxModulationIndex, TimerChannel_t PhaseA, TimerChannel_t PhaseB, TimerChannel_t PhaseC );

    // Set input voltages (e.g., in alpha-beta frame) and calculate duty cycles
    void setInputVoltages(double alphaVoltage, double betaVoltage);

    // Get the calculated duty cycles for each phase
    void getDutyCycles(double& dutyCycleA, double& dutyCycleB, double& dutyCycleC) const;

    void update();

private:

    // Internal helper to calculate sector number
    uint8_t calculate_sector();

    // helper function to calculate current X,Y,Z values and store them in the member variables
    void calculate_XYZ(double U_alpha, double U_beta);

    // Helper function to calculate t1 and t2 values
    std::pair<double, double> calculate_vector_ontime(uint8_t sector);

    // Helper function to calculate on time for each phase

    // Internal helper function for SVPWM calculations
    void calculateDutyCycles();

    // writes the PWM duty cycles stored in the object
    void writePWM();

    // Private data members
    double maxModulationIndex;

    double alphaVoltage;
    double betaVoltage;

    double dutyCycleA;
    double dutyCycleB;
    double dutyCycleC;


    double X;
    double Y;
    double Z;


    TimerChannel_t PhaseA_iface;
    TimerChannel_t PhaseB_iface;
    TimerChannel_t PhaseC_iface;

};

#endif // SPACE_VECTOR_PWM_H
