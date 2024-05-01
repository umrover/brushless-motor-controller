/*
 * data_types.cpp
 *
 *  Created on: Apr 19, 2024
 *      Author: Sashr
 */

#include "data_types.h"
#include <iostream>

// Constructors
AngleType::AngleType() : angleRad(0.0) {}

AngleType::AngleType(double angle) {
    setAngle(angle);
}

// Member function to set angle
void AngleType::setAngle(double angle) {
    angleRad = std::fmod(angle, 2 * M_PI);  // Ensure angle is within [0, 2pi)
    if (angleRad < 0)  // Handle negative angles
        angleRad += 2 * M_PI;
}

// Getter for angle in radians
double AngleType::getAngleRad() const {
    return angleRad;
}

// Getter for angle in degrees
double AngleType::getAngleDeg() const {
    return angleRad * 180.0 / M_PI;
}

// Unary operators
AngleType AngleType::operator+() const {
    return *this;
}

AngleType AngleType::operator-() const {
    return AngleType(-angleRad);
}

// Binary arithmetic operators
AngleType AngleType::operator+(const AngleType& other) const {
    return AngleType(angleRad + other.angleRad);
}

AngleType AngleType::operator-(const AngleType& other) const {
    return AngleType(angleRad - other.angleRad);
}

AngleType AngleType::operator*(double scalar) const {
    return AngleType(angleRad * scalar);
}

AngleType AngleType::operator/(double divisor) const {
    if (divisor == 0.0) {
        std::cerr << "Error: Division by zero." << std::endl;
        return *this;
    }
    return AngleType(angleRad / divisor);
}

AngleType& AngleType::operator+=(const AngleType& other) {
    angleRad += other.angleRad;
    setAngle(angleRad);
    return *this;
}

AngleType& AngleType::operator-=(const AngleType& other) {
    angleRad -= other.angleRad;
    setAngle(angleRad);
    return *this;
}

// Comparison operators
bool AngleType::operator==(const AngleType& other) const {
    return angleRad == other.angleRad;
}

bool AngleType::operator!=(const AngleType& other) const {
    return angleRad != other.angleRad;
}

bool AngleType::operator<(const AngleType& other) const {
    return angleRad < other.angleRad;
}

bool AngleType::operator>(const AngleType& other) const {
    return angleRad > other.angleRad;
}

bool AngleType::operator<=(const AngleType& other) const {
    return angleRad <= other.angleRad;
}

bool AngleType::operator>=(const AngleType& other) const {
    return angleRad >= other.angleRad;
}



/*
 * Hall encoder state type
 * */

HallEncoderState::HallEncoderState(uint8_t H1, uint8_t H2, uint8_t H3) {
		uint8_t state_read = 0x0001 & (H1 << 2 | H2 << 1 | H3);
		state = encoder_LUT[state_read];
	}

void HallEncoderState::operator=(HallEncoderState other) {
		this->state = other.state;
	}

void HallEncoderState::operator=(HallEncoderState other) {
		this->state = other.state;
	}
uint8_t HallEncoderState::getState() {return state;}

void HallEncoderState::setState(uint8_t H1, uint8_t H2, uint8_t H3) {
		uint8_t state_read = 0x0001 & (H1 << 2 | H2 << 1 | H3);
		state = encoder_LUT[state_read];
	}

