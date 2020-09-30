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
}

void PID::UpdateError(double cte) {
  /**
   * TODO: Update PID errors based on cte.
   */
    d_error=cte-p_error;
    p_error=cte;
    i_error=i_error + cte;
}

double PID::TotalError() {
  double alpha = -Kp * p_error - Kd * d_error - Ki * i_error;
  return alpha;  // TODO: Add your total error calc here!
}