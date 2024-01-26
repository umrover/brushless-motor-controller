/*
 * math_utils.cpp
 *
 *  Created on: Jan 25, 2024
 *      Author: Sashreek and Jonah
 */
#include "math_utils.h"
#include <cmath>

ParkOut tf_park (double ialpha, double ibeta, double theta_d){
	ParkOut output;
	output.id = ialpha * cos(theta_d) + ibeta * sin(theta_d);
	output.iq = -ialpha * sin(theta_d) + ibeta * cos(theta_d);
	return output;

}

InvParkOut tf_inv_park (double vd, double vq, double theta_d){
	InvParkOut output;
	output.valpha = vd * cos(theta_d) - vq * sin(theta_d);
	output.vbeta = vd * sin(theta_d) + vq * cos(theta_d);
	return output;
}

//Clarke transform
ClarkeOut tf_clarke (double ia, double ib, double ic){
	ClarkeOut output;
	output.ialpha = (3.0/2.0) * ia;
	output.ibeta = (sqrt(3)/2) * ib - (sqrt(3)/2) * ic;
	return output;
}

// Inverse Clarke transform
InvClarkeOut tf_inv_clarke (double valpha, double vbeta){
	InvClarkeOut output;
	output.va = (2.0/3.0) * valpha;
	output.vb = (-1.0/3.0) * valpha + (1/sqrt(3)) * vbeta;
	output.vc = (-1.0/3.0) * valpha - (1/sqrt(3)) * vbeta;
	return output;
}

