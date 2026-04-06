//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: _coder_wbqp_init_api.h
//
// MATLAB Coder version            : 24.1
// C/C++ source code generated on  : 10-Sep-2025 15:23:17
//

#ifndef _CODER_WBQP_INIT_API_H
#define _CODER_WBQP_INIT_API_H

// Include Files
#include "emlrt.h"
#include "mex.h"
#include "tmwtypes.h"
#include <algorithm>
#include <cstring>

// Type Definitions
struct struct10_T {
  real_T cols[9];
  real_T beta_arm;
  real_T alpha_xy;
  real_T alpha_yaw;
  real_T w_lin;
  real_T w_ang;
  real_T nu;
  real_T max_dotq;
  real_T max_V;
  real_T max_Omegaz;
  real_T qddot_max;
  real_T a_lin_max;
  real_T alpha_max;
  real_T qmin[6];
  real_T qmax[6];
};

struct struct12_T {
  boolean_T NonFiniteSupport;
  boolean_T IterDisplaySQP;
  real_T InitDamping;
  char_T FiniteDifferenceType[7];
  boolean_T SpecifyObjectiveGradient;
  boolean_T ScaleProblem;
  boolean_T SpecifyConstraintGradient;
  real_T FiniteDifferenceStepSize;
  real_T MaxFunctionEvaluations;
  boolean_T IterDisplayQP;
  real_T PricingTolerance;
  char_T Algorithm[10];
  real_T ObjectiveLimit;
  real_T ConstraintTolerance;
  real_T OptimalityTolerance;
  real_T StepTolerance;
  real_T MaxIterations;
  real_T FunctionTolerance;
  char_T SolverName[8];
  boolean_T CheckGradients;
  char_T Diagnostics[3];
  real_T DiffMaxChange;
  real_T DiffMinChange;
  char_T Display[3];
  char_T FunValCheck[3];
  boolean_T UseParallel;
  char_T LinearSolver[4];
  char_T SubproblemAlgorithm[2];
};

struct struct11_T {
  real_T cols[9];
  real_T beta_arm;
  real_T alpha_xy;
  real_T alpha_yaw;
  real_T w_lin;
  real_T w_ang;
  real_T Wq[81];
  real_T Wt[36];
  real_T nu;
  real_T max_dotq;
  real_T max_V;
  real_T max_Omegaz;
  real_T qmin[6];
  real_T qmax[6];
  real_T qddot_max;
  real_T a_lin_max;
  real_T alpha_max;
  real_T lb[9];
  real_T ub[9];
  struct12_T optsQP;
};

// Variable Declarations
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

// Function Declarations
void wbqp_init(struct10_T *cfg, struct11_T *qp);

void wbqp_init_api(const mxArray *prhs, const mxArray **plhs);

void wbqp_init_atexit();

void wbqp_init_initialize();

void wbqp_init_terminate();

void wbqp_init_xil_shutdown();

void wbqp_init_xil_terminate();

#endif
//
// File trailer for _coder_wbqp_init_api.h
//
// [EOF]
//
