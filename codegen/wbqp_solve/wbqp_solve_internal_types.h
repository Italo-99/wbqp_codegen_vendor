//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: wbqp_solve_internal_types.h
//
// MATLAB Coder version            : 24.1
// C/C++ source code generated on  : 10-Sep-2025 16:14:33
//

#ifndef WBQP_SOLVE_INTERNAL_TYPES_H
#define WBQP_SOLVE_INTERNAL_TYPES_H

// Include Files
#include "rtwtypes.h"
#include "wbqp_solve_types.h"

// Type Definitions
struct struct_T {
  double xstar[10];
  double fstar;
  double firstorderopt;
  double lambda[49];
  int state;
  double maxConstr;
  int iterations;
  double searchDir[10];
};

struct b_struct_T {
  double grad[10];
  double Hx[9];
  boolean_T hasLinear;
  int nvar;
  int maxVar;
  double beta;
  double rho;
  int objtype;
  int prev_objtype;
  int prev_nvar;
  boolean_T prev_hasLinear;
  double gammaScalar;
};

struct c_struct_T {
  double FMat[100];
  int ldm;
  int ndims;
  int info;
  double scaleFactor;
  boolean_T ConvexCheck;
  double regTol_;
  double workspace_[480];
  double workspace2_[480];
};

struct d_struct_T {
  int ldq;
  double QR[490];
  double Q[100];
  int jpvt[49];
  int mrows;
  int ncols;
  double tau[10];
  int minRowCol;
  boolean_T usedPivoting;
};

struct e_struct_T {
  double workspace_float[490];
  int workspace_int[49];
  int workspace_sort[49];
};

struct f_struct_T {
  int mConstr;
  int mConstrOrig;
  int mConstrMax;
  int nVar;
  int nVarOrig;
  int nVarMax;
  int ldA;
  double Aineq[300];
  double bineq[30];
  double lb[10];
  double ub[10];
  int indexLB[10];
  int indexUB[10];
  int indexFixed[10];
  int mEqRemoved;
  double ATwset[490];
  double bwset[49];
  int nActiveConstr;
  double maxConstrWorkspace[49];
  int sizes[5];
  int sizesNormal[5];
  int sizesPhaseOne[5];
  int sizesRegularized[5];
  int sizesRegPhaseOne[5];
  int isActiveIdx[6];
  int isActiveIdxNormal[6];
  int isActiveIdxPhaseOne[6];
  int isActiveIdxRegularized[6];
  int isActiveIdxRegPhaseOne[6];
  boolean_T isActiveConstr[49];
  int Wid[49];
  int Wlocalidx[49];
  int nWConstr[5];
  int probType;
  double SLACK0;
};

#endif
//
// File trailer for wbqp_solve_internal_types.h
//
// [EOF]
//
