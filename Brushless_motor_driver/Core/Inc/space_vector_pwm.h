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
    uint32_t* CCR_addr; // eg TIM3->CCR1
    uint32_t* ARR_addr;
    uint32_t* PSC_addr;
} TimerChannel_t;

class SpaceVectorPWM {
public:
    // Constructor to initialize the SVPWM generator with specific parameters
    SpaceVectorPWM(double maxModulationIndex, TimerChannel_t PhaseA, TimerChannel_t PhaseB, TimerChannel_t PhaseC );

    // Set input voltages (e.g., in alpha-beta frame) and calculate duty cycles
    void setInputVoltages(double alphaVoltage, double betaVoltage);

    // Get the calculated duty cycles for each phase
    void getDutyCycles(double& dutyCycleA, double& dutyCycleB, double& dutyCycleC) const;

    // Runs one iteration of the SVPWM algorithm
    void update();

private:

    // Internal helper to calculate sector number
    uint8_t calculate_sector();

    // helper function to calculate current X,Y,Z values and store them in the member variables
    void calculate_XYZ();

    // Helper function to calculate t1 and t2 values
    std::pair<double, double> calculate_vector_ontime(uint8_t sector);

    // Helper function to calculate on time for each phase
    void calculate_relative_time_on(uint8_t sector, double PWM_Period);

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

    double taon;
    double tbon;
    double tcon;

    double Peripheral_frequency;

    TimerChannel_t PhaseA_iface;
    TimerChannel_t PhaseB_iface;
    TimerChannel_t PhaseC_iface;


};

#endif // SPACE_VECTOR_PWM_H
