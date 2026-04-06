//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: wbqp_solve_rtwutil.cpp
//
// MATLAB Coder version            : 24.1
// C/C++ source code generated on  : 10-Sep-2025 16:14:33
//

// Include Files
#include "wbqp_solve_rtwutil.h"
#include "rt_nonfinite.h"

// Function Definitions
//
// Arguments    : int numerator
// Return Type  : int
//
int div_nde_s32_floor(int numerator)
{
  int i;
  if ((numerator < 0) && (numerator % 10 != 0)) {
    i = -1;
  } else {
    i = 0;
  }
  return numerator / 10 + i;
}

//
// File trailer for wbqp_solve_rtwutil.cpp
//
// [EOF]
//
