/*
 * data_types.h
 *
 *  Created on: Apr 19, 2024
 *      Author: Sashr
 */

#ifndef INC_DATA_TYPES_H_
#define INC_DATA_TYPES_H_

#include <math.h>
#include <stdint.h>

class AngleType {
private:
    double angleRad;

public:
    // Constructors
    AngleType();
    AngleType(double angle);

    // Member function to set angle
    void setAngle(double angle);

    // Getter for angle in radians
    double getAngleRad() const;

    // Getter for angle in degrees
    double getAngleDeg() const;

    // Unary operators
    AngleType operator+() const;
    AngleType operator-() const;

    // Binary arithmetic operators
    AngleType operator+(const AngleType& other) const;
    AngleType operator-(const AngleType& other) const;
    AngleType operator*(double scalar) const;
    AngleType operator/(double divisor) const;
    AngleType& operator+=(const AngleType& other);
    AngleType& operator-=(const AngleType& other);

    // Comparison operators
    bool operator==(const AngleType& other) const;
    bool operator!=(const AngleType& other) const;
    bool operator<(const AngleType& other) const;
    bool operator>(const AngleType& other) const;
    bool operator<=(const AngleType& other) const;
    bool operator>=(const AngleType& other) const;
};



class HallEncoderState {

private:
	uint8_t state;

public:
	HallEncoderState(uint8_t H1, uint8_t H2, uint8_t H3);
	uint8_t getState();
	void operator=(HallEncoderState other);
	void setState(uint8_t H1, uint8_t H2, uint8_t H3);

};

#endif /* INC_DATA_TYPES_H_ */
