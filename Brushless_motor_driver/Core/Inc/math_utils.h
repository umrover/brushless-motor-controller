/*
 * math_utils.h
 *
 *  Created on: Jan 25, 2024
 *      Author: Sashreek and Jonah
 */

#ifndef INC_MATH_UTILS_H_
#define INC_MATH_UTILS_H_


struct ParkOut{
	double id;
	double iq;
};
struct InvParkOut{
	double valpha;
	double vbeta;
};
struct ClarkeOut{
	double ialpha;
	double ibeta;
};
struct InvClarkeOut{
	double va;
	double vb;
	double vc;
};
ParkOut tf_park (double ialpha, double ibeta, double theta_d);
InvParkOut tf_inv_park (double vd, double vq, double theta_d);
ClarkeOut tf_clarke (double ia, double ib, double ic);
InvClarkeOut tf_inv_clarke (double valpha, double vbeta);





#endif /* INC_MATH_UTILS_H_ */
