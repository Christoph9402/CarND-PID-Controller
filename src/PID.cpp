#include "PID.h"


PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
   this->Kp=Kp;
   this->Ki=Ki;
   this->Kd=Kd;

   //Initializing errors and previous_cte with 0.0
   p_error=0;
   i_error=0;
   d_error=0;
}

void PID::UpdateError(double cte) {

    // D-component: calculated by subtracting p_error (which is 0 in the first step) from the cte
    d_error = cte - p_error;
    //P-component:set the p_error to the current cte
    p_error = cte;
    // I-component: add the current cte to the previous i_error
    i_error += cte;
}

double PID::TotalError() {
    //Calculate and return the total error using the formula presented in the lesson 12.12
  double error_t = -Kp * p_error - Kd * d_error - Ki * i_error;
  return error_t;
}