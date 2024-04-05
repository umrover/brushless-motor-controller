/*
 * main_bridge.h
 *
 *  Created on: Feb 6, 2024
 *      Author: Sashr
 */

#ifndef INC_MAIN_BRIDGE_H_
#define INC_MAIN_BRIDGE_H_

#ifdef __cplusplus
extern "C" {
#endif

static double volatile motor_velocity;
static double volatile motor_position;

void loop();
void setup();

#ifdef __cplusplus
}
#endif

#endif /* INC_MAIN_BRIDGE_H_ */
