/*
 * filter.cpp
 *
 *  Created on: Mar 13, 2024
 *      Author: Sashreek
 */
#include "main.h"
#include "filter.h"

MovingAvgFilter::MovingAvgFilter(uint8_t filter_size):filter_size(filter_size){
	cache.resize(filter_size, 0);
	cache.reserve(filter_size);
	sum = 0;
}


void MovingAvgFilter::add_new_element(double item){
	double removed = cache.back();
	cache.pop_back();
	sum -= removed;
	sum += item;
	cache.insert(cache.begin(), item);
}


double MovingAvgFilter::filtered_output(){
	return sum/filter_size;
}
