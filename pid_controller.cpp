/**********************************************
 * Self-Driving Car Nano-degree - Udacity
 *  Created on: December 11, 2020
 *      Author: Mathilde Badoual
 **********************************************/

#include "pid_controller.h"
#include <vector>
#include <iostream>
#include <math.h>

using namespace std;

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kpi, double Kii, double Kdi, double output_lim_maxi, double output_lim_mini) {
   Kp = Kpi;
   Ki = Kii;
   Kd = Kdi;
   lim_max = output_lim_maxi;
   lim_min = output_lim_mini;

   p_err = 0.0;
   i_err = 0.0;
   d_err = 0.0;
   dt = 0.0;
}


void PID::UpdateError(double cte) {
   p_err = cte;
   i_err += cte * dt;
   d_err = dt > 0.0 ? (cte - p_err) / dt : 0.0;
}

double PID::TotalError() {
   double control = (Kp * p_err) + (Ki * i_err) + (Kd * d_err);

   if (control > lim_max) {
      control = lim_max;
   } else if (control < lim_min) {
      control = lim_min;
   }

   return control;
}

double PID::UpdateDeltaTime(double new_delta_time) {
   dt = new_delta_time;
   return dt;
}