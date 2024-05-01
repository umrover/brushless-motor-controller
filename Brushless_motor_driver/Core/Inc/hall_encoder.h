/*
 * hall_encoder.h
 *
 *  Created on: Feb 6, 2024
 *      Author: Sashr
 */

#ifndef INC_HALL_ENCODER_H_
#define INC_HALL_ENCODER_H_

#include "data_types.h"
#include<memory>

#define NUM_POLES 16  // one day this will be configurable...
#define DELTA_THETA 360/NUM_POLES

#define FWD 1
#define BWD -1
#define HALT 0



class HallEncoderDriver {

private:
	/*
	 * out	1	2	3	4	5	6
	 * 		----------------------
	 * H1	0	0	1	1	1	0
	 * H2	1	0	0	0	1	1
	 * H3	1	1	1	0	0	0
	 * 		----------------------
	 * in	3	1	5	4	6	2
	 *
	 * Driver logic:
	 * at rising/falling edge, read hall state(state of all input pins)
	 * if next state output > current state
	 * 	(dir = CW) and increment current theta by delta theta
	 *
	 * else dir = CCW
	 * 	and decrement current theta by delta theta
	 *
	 *make sure theta is a %360 value.
	 * */
	AngleType angle;
	std::unique_ptr<HallEncoderState> prev_state;
	std::unique_ptr<HallEncoderState> curr_state;

public:
	HallEncoderDriver();
	void setState(uint8_t H1, uint8_t H2, uint8_t H3);


	double get_thetad();
	int8_t getDirection();
};

#endif /* INC_HALL_ENCODER_H_ */
