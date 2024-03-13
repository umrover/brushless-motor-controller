/*
 * filter.cpp
 *
 *  Created on: Mar 13, 2024
 *      Author: Sashreek
 */
#include "main.h"
#include "filter.h"


template <class T>
void MovingAvgFilter<T>::add_new_element(T item){
	T removed = cache.back();
	cache.pop_back();
	sum -= removed;
	sum += item;
	cache.insert(cache.begin(), item);
}


template <class T>
T MovingAvgFilter<T>::filtered_output(){
	return sum/filter_size;
}
