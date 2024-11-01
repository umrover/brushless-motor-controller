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


extern CORDIC_HandleTypeDef hcordic;


class STM32CORDIC {
public:
    // Enumeration to define supported operations for CORDIC core
    enum Operation {
        SIN_COS,
        ATAN,
        SQRT
    };

    // Constructor that accepts an operation type and scaling mode (if required)
    STM32CORDIC();

    // Destructor
    ~STM32CORDIC();

    // Initializes the CORDIC peripheral
    static bool init();

    // Performs sine operation
    static float computeSin(float angle);

    // Performs cosine operation
    static float computeCos(float angle);

    // Performs arctangent operation
    static float computeAtan(float y, float x);

    // Rotates vector by an angle
    static float computeSqrt(float num);

private:
    // Configures the CORDIC peripheral settings
    void configure(Operation operation, uint32_t precision);

};

#endif /* INC_CORDIC_DRIVER_H_ */
