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

template <typename T> class MovingAvgFilter{

private:
	uint8_t filter_size;
	std::vector<T> cache;
	T sum;

public:
	MovingAvgFilter(uint8_t filter_size):filter_size(filter_size){
		cache.resize(filter_size, 0);
		cache.reserve(filter_size);
		sum = 0;
	}
	void add_new_element(T item);
	T filtered_output();

};



#endif /* INC_FILTER_H_ */
