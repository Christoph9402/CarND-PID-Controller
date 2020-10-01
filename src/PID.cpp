#include "PID.h"

/**
 * TODO: Complete the PID class. You may add any additional desired functions.
 */

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
   this->Kp=Kp;
   this->Ki=Ki;
   this->Kd=Kd;

   //Initializing errors and previous_cte with 0.0
   //previous_cte=0;
   p_error=0;
   i_error=0;
   d_error=0;
}

void PID::UpdateError(double cte) {
  /**
   * TODO: Update PID errors based on cte.
   */
    // D-component:
    d_error=cte-p_error;
   //P-component:
    p_error=cte;
    // I-component:
    i_error += cte;

    //previous_cte=cte;


    //std::cout << "CTE: " << cte << " error_d: " << d_error << " error_p: " << p_error << " error_i: " << i_error << std::endl;
}

double PID::TotalError() {
  double error_t = -Kp * p_error - Kd * d_error - Ki * i_error;
  return error_t;
  // TODO: Add your total error calc here!
}