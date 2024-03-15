/*
 *  filter.h
 *
 *  Created on: Mar 13, 2024
 *      Author: Sashreek
 */

#ifndef INC_FILTER_H_
#define INC_FILTER_H_

#include<vector>
#include<cstdint>

class MovingAvgFilter{

private:
	uint8_t filter_size;
	std::vector<double> cache;
	double sum;

public:
	MovingAvgFilter(uint8_t filter_size);
	void add_new_element(double item);
	double filtered_output();

};

#endif /* INC_FILTER_H_ */
