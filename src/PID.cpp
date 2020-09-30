#include "PID.h"

/**
 * TODO: Complete the PID class. You may add any additional desired functions.
 */

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp_, double Ki_, double Kd_) {
   Kp_ = Kp;
   Ki_= Ki;
   Kd_=Kd;
   //Initializing errors and previous_cte with 0.0
   previous_cte=0.0;
   p_error=0.0;
   i_error=0.0;
   d_error=0.0;
}

void PID::UpdateError(double cte) {
  /**
   * TODO: Update PID errors based on cte.
   */
   //P-component:
    p_error=cte;
    // I-component:
    i_error=i_error + cte;
    // D-component:
    d_error=cte-previous_cte;
    previous_cte=cte;

}

double PID::TotalError() {
  return  -Kp * p_error - Kd * d_error - Ki * i_error;
    // TODO: Add your total error calc here!
}