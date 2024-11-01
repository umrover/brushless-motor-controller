/*
 * cordic_driver.cpp
 *
 *  Created on: Oct 29, 2024
 *      Author: Sashreek
 */

#include "cordic_driver.h"
#include <math.h>
#define q31_to_f32(x) ldexp((int32_t) x, -31)


int f32_to_q31(double input){
	const float Q31_MAX_F = 0x0.FFFFFFp0F;
	const float Q31_MIN_F = -1.0F;
	float clamped = fmaxf(fminf(input, Q31_MAX_F), Q31_MIN_F);
	return (int)roundf(scalbnf(clamped, 31));
}

static inline float cordic_q31_sinf(float x){
	CORDIC_ConfigTypeDef sConfig;
	int32_t input_q31 = f32_to_q31(fmod(x,2.0f * M_PI) 	/ (2.0f * M_PI)) << 1;
	int32_t output_q31;

	sConfig.Function = CORDIC_FUNCTION_COSINE;
	sConfig.Precision = CORDIC_PRECISION_6CYCLES;
	sConfig.Scale = CORDIC_SCALE_0;
	sConfig.NbWrite = CORDIC_NBWRITE_1;
	sConfig.NbRead = CORDIC_NBREAD_1;
	sConfig.InSize = CORDIC_INSIZE_32BITS;
	sConfig.OutSize = CORDIC_OUTSIZE_32BITS;
	HAL_CORDIC_Configure(&hcordic, &sConfig);
	HAL_CORDIC_CalculateZO(&hcordic, &input_q31, &output_q31, 1, 0);

	return q31_to_f32(output_q31);
}


// Constructor that accepts an operation type and scaling mode (if required)
STM32CORDIC::STM32CORDIC(){

}

// Destructor
STM32CORDIC::~STM32CORDIC(){

}

// Initializes the CORDIC peripheral
bool STM32CORDIC::init(){
	return true;
}

// Performs sine operation on angle in radians
float STM32CORDIC::computeSin(float angle){
	// First read gets the cosine value of the angle, second read gets the sin value of the angle
	float cordic_cosine = cordic_q31_sinf(angle);
	float cordic_sin = cordic_q31_sinf(angle);
	return cordic_sin;
}

// Performs cosine operation
float STM32CORDIC::computeCos(float angle){
	float cordic_cosine = cordic_q31_sinf(angle);
	float cordic_sin = cordic_q31_sinf(angle);
	return cordic_cosine;
}

// Performs arctangent operation
float STM32CORDIC::computeAtan(float y, float x){
	return 0.0f;
}

// Rotates vector by an angle
float STM32CORDIC::computeSqrt(float num){
	return 0.0f;
}



