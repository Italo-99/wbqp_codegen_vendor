//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: wbqp_solve_initialize.cpp
//
// MATLAB Coder version            : 24.1
// C/C++ source code generated on  : 10-Sep-2025 16:14:33
//

// Include Files
#include "wbqp_solve_initialize.h"
#include "CoderTimeAPI.h"
#include "rt_nonfinite.h"
#include "wbqp_solve_data.h"

// Function Definitions
//
// Arguments    : void
// Return Type  : void
//
void wbqp_solve_initialize()
{
  CoderTimeAPI::callCoderClockGettime_init();
  isInitialized_wbqp_solve = true;
}

//
// File trailer for wbqp_solve_initialize.cpp
//
// [EOF]
//
