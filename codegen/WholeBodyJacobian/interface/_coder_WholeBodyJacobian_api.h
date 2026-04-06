//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: _coder_WholeBodyJacobian_api.h
//
// MATLAB Coder version            : 24.1
// C/C++ source code generated on  : 10-Sep-2025 14:53:20
//

#ifndef _CODER_WHOLEBODYJACOBIAN_API_H
#define _CODER_WHOLEBODYJACOBIAN_API_H

// Include Files
#include "emlrt.h"
#include "mex.h"
#include "tmwtypes.h"
#include <algorithm>
#include <cstring>

// Variable Declarations
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

// Function Declarations
void WholeBodyJacobian(real_T in1[15], real_T A[72]);

void WholeBodyJacobian_api(const mxArray *prhs, const mxArray **plhs);

void WholeBodyJacobian_atexit();

void WholeBodyJacobian_initialize();

void WholeBodyJacobian_terminate();

void WholeBodyJacobian_xil_shutdown();

void WholeBodyJacobian_xil_terminate();

#endif
//
// File trailer for _coder_WholeBodyJacobian_api.h
//
// [EOF]
//
