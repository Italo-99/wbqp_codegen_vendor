//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: wbqp_init_types.h
//
// MATLAB Coder version            : 24.1
// C/C++ source code generated on  : 10-Sep-2025 15:23:17
//

#ifndef WBQP_INIT_TYPES_H
#define WBQP_INIT_TYPES_H

// Include Files
#include "rtwtypes.h"

// Type Definitions
struct struct10_T {
  double cols[9];
  double beta_arm;
  double alpha_xy;
  double alpha_yaw;
  double w_lin;
  double w_ang;
  double nu;
  double max_dotq;
  double max_V;
  double max_Omegaz;
  double qddot_max;
  double a_lin_max;
  double alpha_max;
  double qmin[6];
  double qmax[6];
};

struct struct12_T {
  boolean_T NonFiniteSupport;
  boolean_T IterDisplaySQP;
  double InitDamping;
  char FiniteDifferenceType[7];
  boolean_T SpecifyObjectiveGradient;
  boolean_T ScaleProblem;
  boolean_T SpecifyConstraintGradient;
  double FiniteDifferenceStepSize;
  double MaxFunctionEvaluations;
  boolean_T IterDisplayQP;
  double PricingTolerance;
  char Algorithm[10];
  double ObjectiveLimit;
  double ConstraintTolerance;
  double OptimalityTolerance;
  double StepTolerance;
  double MaxIterations;
  double FunctionTolerance;
  char SolverName[8];
  boolean_T CheckGradients;
  char Diagnostics[3];
  double DiffMaxChange;
  double DiffMinChange;
  char Display[3];
  char FunValCheck[3];
  boolean_T UseParallel;
  char LinearSolver[4];
  char SubproblemAlgorithm[2];
};

struct struct11_T {
  double cols[9];
  double beta_arm;
  double alpha_xy;
  double alpha_yaw;
  double w_lin;
  double w_ang;
  double Wq[81];
  double Wt[36];
  double nu;
  double max_dotq;
  double max_V;
  double max_Omegaz;
  double qmin[6];
  double qmax[6];
  double qddot_max;
  double a_lin_max;
  double alpha_max;
  double lb[9];
  double ub[9];
  struct12_T optsQP;
};

#endif
//
// File trailer for wbqp_init_types.h
//
// [EOF]
//
