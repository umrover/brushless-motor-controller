/*
 * hall_encoder.h
 *
 *  Created on: Feb 6, 2024
 *      Author: Sashr
 */

#ifndef INC_HALL_ENCODER_H_
#define INC_HALL_ENCODER_H_


#define NUM_POLES 16
#define DELTA_THETA 360/NUM_POLES


class HallEncoderDriver{
public:
	static double get_thetad();

};


#endif /* INC_HALL_ENCODER_H_ */
