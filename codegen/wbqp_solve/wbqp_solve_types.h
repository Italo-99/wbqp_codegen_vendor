//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: wbqp_solve_types.h
//
// MATLAB Coder version            : 24.1
// C/C++ source code generated on  : 10-Sep-2025 16:14:33
//

#ifndef WBQP_SOLVE_TYPES_H
#define WBQP_SOLVE_TYPES_H

// Include Files
#include "rtwtypes.h"
#include "coder_bounded_array.h"

// Type Definitions
struct struct2_T {
  double exitflag;
  double t_qp;
  boolean_T used_qp;
  double firstorderopt;
  double constrviolation;
  double u_actual[6];
};

struct struct0_T {
  coder::bounded_array<signed char, 12U, 2U> cols;
  double beta_arm;
  double Wq[81];
  double Wt[36];
  double nu;
  double max_dotq;
  double qmin[6];
  double qmax[6];
  double qddot_max;
  double lb[9];
  double ub[9];
  double alpha_xy;
  double alpha_yaw;
  double max_V;
  double max_Omegaz;
  double a_lin_max;
  double alpha_max;
};

struct struct1_T {
  coder::bounded_array<double, 72U, 2U> J_full;
  double q[6];
  double u_star[6];
  double dotq_prev[9];
  double dt;
  double J[54];
};

#endif
//
// File trailer for wbqp_solve_types.h
//
// [EOF]
//
