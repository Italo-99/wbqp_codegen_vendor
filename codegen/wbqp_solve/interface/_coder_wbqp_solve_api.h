//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: _coder_wbqp_solve_api.h
//
// MATLAB Coder version            : 24.1
// C/C++ source code generated on  : 10-Sep-2025 16:14:33
//

#ifndef _CODER_WBQP_SOLVE_API_H
#define _CODER_WBQP_SOLVE_API_H

// Include Files
#include "coder_bounded_array.h"
#include "emlrt.h"
#include "mex.h"
#include "tmwtypes.h"
#include <algorithm>
#include <cstring>

// Type Definitions
struct struct2_T {
  real_T exitflag;
  real_T t_qp;
  boolean_T used_qp;
  real_T firstorderopt;
  real_T constrviolation;
  real_T u_actual[6];
};

struct struct0_T {
  coder::bounded_array<int8_T, 12U, 2U> cols;
  real_T beta_arm;
  real_T Wq[81];
  real_T Wt[36];
  real_T nu;
  real_T max_dotq;
  real_T qmin[6];
  real_T qmax[6];
  real_T qddot_max;
  real_T lb[9];
  real_T ub[9];
  real_T alpha_xy;
  real_T alpha_yaw;
  real_T max_V;
  real_T max_Omegaz;
  real_T a_lin_max;
  real_T alpha_max;
};

struct struct1_T {
  coder::bounded_array<real_T, 72U, 2U> J_full;
  real_T q[6];
  real_T u_star[6];
  real_T dotq_prev[9];
  real_T dt;
  real_T J[54];
};

// Variable Declarations
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

// Function Declarations
void wbqp_solve(struct0_T *qp, struct1_T *in, real_T dotq_star_opt[9],
                struct2_T *dbg);

void wbqp_solve_api(const mxArray *const prhs[2], int32_T nlhs,
                    const mxArray *plhs[2]);

void wbqp_solve_atexit();

void wbqp_solve_initialize();

void wbqp_solve_terminate();

void wbqp_solve_xil_shutdown();

void wbqp_solve_xil_terminate();

#endif
//
// File trailer for _coder_wbqp_solve_api.h
//
// [EOF]
//
