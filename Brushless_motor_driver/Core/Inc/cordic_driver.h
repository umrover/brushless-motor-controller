/*
 * cordic_driver.h
 *
 *  Created on: Oct 29, 2024
 *      Author: Sashreek
 */

#ifndef INC_CORDIC_DRIVER_H_
#define INC_CORDIC_DRIVER_H_

#include "stm32g4xx_hal.h"
#include <cmath>

class STM32CORDIC {
public:
    // Enumeration to define supported operations for CORDIC core
    enum Operation {
        SIN_COS,
        ATAN,
        SQRT
    };

    // Constructor that accepts an operation type and scaling mode (if required)
    STM32CORDIC(Operation operation, uint32_t precision = 6);

    // Destructor
    ~STM32CORDIC();

    // Initializes the CORDIC peripheral
    bool init();

    // Performs sine operation
    float computeSin(float angle);

    // Performs cosine operation
    float computeCos(float angle);

    // Performs arctangent operation
    float computeAtan(float y, float x);

    // Rotates vector by an angle
    float computeSqrt(float num);

private:
    // Configures the CORDIC peripheral settings
    void configure(Operation operation, uint32_t precision);

    Operation currentOperation;
    uint32_t precision;
};

#endif /* INC_CORDIC_DRIVER_H_ */
