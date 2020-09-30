#include "PID.h"

/**
 * TODO: Complete the PID class. You may add any additional desired functions.
 */

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp_, double Ki_, double Kd_) {
   Kp_ = Kp_;
   Ki_= Ki_;
   Kd_=Kd_;
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
    std::cout << "CTE: " << cte << " error_d: " << d_error << " error_p: " << p_error << " error_i: " << i_error << std::endl;
}

double PID::TotalError() {
  return  Kp * p_error + Kd * d_error + Ki * i_error;
    // TODO: Add your total error calc here!
}