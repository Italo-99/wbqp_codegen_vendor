//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: removeEqConstr.cpp
//
// MATLAB Coder version            : 24.1
// C/C++ source code generated on  : 10-Sep-2025 16:14:33
//

// Include Files
#include "removeEqConstr.h"
#include "rt_nonfinite.h"
#include "wbqp_solve_internal_types.h"

// Function Definitions
//
// Arguments    : f_struct_T &obj
//                int idx_global
// Return Type  : void
//
namespace coder {
namespace optim {
namespace coder {
namespace qpactiveset {
namespace WorkingSet {
void removeEqConstr(f_struct_T &obj, int idx_global)
{
  int totalEq;
  totalEq = obj.nWConstr[0] + obj.nWConstr[1];
  if ((totalEq != 0) && (idx_global <= totalEq)) {
    if ((obj.nActiveConstr == totalEq) || (idx_global == totalEq)) {
      obj.mEqRemoved++;
      // A check that is always false is detected at compile-time. Eliminating
      // code that follows.
    } else {
      obj.mEqRemoved++;
      // A check that is always false is detected at compile-time. Eliminating
      // code that follows.
    }
  }
}

} // namespace WorkingSet
} // namespace qpactiveset
} // namespace coder
} // namespace optim
} // namespace coder

//
// File trailer for removeEqConstr.cpp
//
// [EOF]
//
