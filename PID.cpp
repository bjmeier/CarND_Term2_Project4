#include "PID.h"
#include <numeric>
#include <math.h> 
#include <iostream>

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init() {
	  
	  double p_error = 0;
	  double i_error = 0;
	  double d_error = 0;
}

void PID::SetK(double Kp_in, double Ki_in, double Kd_in)
{
	Kp = Kp_in;
	Ki = Ki_in;
	Kd = Kd_in;
}

void PID::UpdateError(double cte) {
	d_error = cte - p_error;
	p_error = cte;
	i_error += cte;
}

double PID::TotalError() {
}

