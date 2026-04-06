//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: maxConstraintViolation.cpp
//
// MATLAB Coder version            : 24.1
// C/C++ source code generated on  : 10-Sep-2025 16:14:33
//

// Include Files
#include "maxConstraintViolation.h"
#include "rt_nonfinite.h"
#include "wbqp_solve_internal_types.h"
#include "wbqp_solve_rtwutil.h"
#include <cmath>

// Function Definitions
//
// Arguments    : f_struct_T &obj
//                const double x[10]
// Return Type  : double
//
namespace coder {
namespace optim {
namespace coder {
namespace qpactiveset {
namespace WorkingSet {
double maxConstraintViolation(f_struct_T &obj, const double x[10])
{
  double v;
  int i;
  int idxLB;
  if (obj.probType == 2) {
    double c;
    v = 0.0;
    for (idxLB = 0; idxLB < 30; idxLB++) {
      obj.maxConstrWorkspace[idxLB] = obj.bineq[idxLB];
      obj.maxConstrWorkspace[idxLB] = -obj.maxConstrWorkspace[idxLB];
    }
    for (idxLB = 0; idxLB <= 290; idxLB += 10) {
      c = 0.0;
      i = idxLB + 9;
      for (int ia{idxLB + 1}; ia <= i; ia++) {
        c += obj.Aineq[ia - 1] * x[(ia - idxLB) - 1];
      }
      i = div_nde_s32_floor(idxLB);
      obj.maxConstrWorkspace[i] += c;
    }
    for (int ia{0}; ia < 30; ia++) {
      c = obj.maxConstrWorkspace[ia] - x[9];
      obj.maxConstrWorkspace[ia] = c;
      v = std::fmax(v, c);
    }
  } else {
    v = 0.0;
    for (idxLB = 0; idxLB < 30; idxLB++) {
      obj.maxConstrWorkspace[idxLB] = obj.bineq[idxLB];
      obj.maxConstrWorkspace[idxLB] = -obj.maxConstrWorkspace[idxLB];
    }
    for (idxLB = 0; idxLB <= 290; idxLB += 10) {
      double c;
      c = 0.0;
      i = idxLB + obj.nVar;
      for (int ia{idxLB + 1}; ia <= i; ia++) {
        c += obj.Aineq[ia - 1] * x[(ia - idxLB) - 1];
      }
      i = div_nde_s32_floor(idxLB);
      obj.maxConstrWorkspace[i] += c;
    }
    for (int ia{0}; ia < 30; ia++) {
      v = std::fmax(v, obj.maxConstrWorkspace[ia]);
    }
  }
  if (obj.sizes[3] > 0) {
    i = static_cast<unsigned char>(obj.sizes[3]);
    for (int ia{0}; ia < i; ia++) {
      idxLB = obj.indexLB[ia] - 1;
      v = std::fmax(v, -x[idxLB] - obj.lb[idxLB]);
    }
  }
  if (obj.sizes[4] > 0) {
    i = static_cast<unsigned char>(obj.sizes[4]);
    for (int ia{0}; ia < i; ia++) {
      idxLB = obj.indexUB[ia] - 1;
      v = std::fmax(v, x[idxLB] - obj.ub[idxLB]);
    }
  }
  if (obj.sizes[0] > 0) {
    i = static_cast<unsigned char>(obj.sizes[0]);
    for (int ia{0}; ia < i; ia++) {
      v = std::fmax(v, std::abs(x[obj.indexFixed[ia] - 1] -
                                obj.ub[obj.indexFixed[ia] - 1]));
    }
  }
  return v;
}

} // namespace WorkingSet
} // namespace qpactiveset
} // namespace coder
} // namespace optim
} // namespace coder

//
// File trailer for maxConstraintViolation.cpp
//
// [EOF]
//
