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
    cte_d=cte-cte_p;
    cte_p=cte;
    cte_i=cte_i + cte;
}

double PID::TotalError() {
  /**
   * TODO: Calculate and return the total error
   */
  double alpha = -tau_p * cte_p - tau_d * cte_d - tau_i * it_cte;
  return alpha;  // TODO: Add your total error calc here!
}