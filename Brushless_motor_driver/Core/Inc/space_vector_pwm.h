/*
 * space_vector_pwm.h
 *
 *  Created on: Oct 29, 2024
 *      Author: Sashreek
 */

#ifndef SPACE_VECTOR_PWM_H
#define SPACE_VECTOR_PWM_H

#include "stm32g4xx_hal.h"

typedef struct {
    TIM_HandleTypeDef *htim;
    uint32_t channel;

    TIM_TypeDef * TIM_obj;
    uint32_t CCR_addr;

} TimerChannel_t;

class SpaceVectorPWM {
public:
    // Constructor to initialize the SVPWM generator with specific parameters
    SpaceVectorPWM(float maxModulationIndex, TimerChannel_t PhaseA, TimerChannel_t PhaseB, TimerChannel_t PhaseC );

    // Set input voltages (e.g., in alpha-beta frame) and calculate duty cycles
    void setInputVoltages(float alphaVoltage, float betaVoltage);

    // Get the calculated duty cycles for each phase
    void getDutyCycles(float& dutyCycleA, float& dutyCycleB, float& dutyCycleC) const;

    void update();

private:
    // Internal helper to calculate sector number
    uint8_t calculate_sector();

    // Internal helper function for SVPWM calculations
    void calculateDutyCycles();

    // writes the PWM duty cycles stored in the object
    void writePWM();

    // Private data members
    float maxModulationIndex;

    float alphaVoltage;
    float betaVoltage;

    float dutyCycleA;
    float dutyCycleB;
    float dutyCycleC;


    TimerChannel_t PhaseA_iface;
    TimerChannel_t PhaseB_iface;
    TimerChannel_t PhaseC_iface;

};

#endif // SPACE_VECTOR_PWM_H
