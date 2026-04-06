//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: computeFval.cpp
//
// MATLAB Coder version            : 24.1
// C/C++ source code generated on  : 10-Sep-2025 16:14:33
//

// Include Files
#include "computeFval.h"
#include "linearForm_.h"
#include "rt_nonfinite.h"
#include "wbqp_solve_internal_types.h"
#include <emmintrin.h>

// Function Definitions
//
// Arguments    : const b_struct_T &obj
//                double workspace[490]
//                const double H[81]
//                const double f[9]
//                const double x[10]
// Return Type  : double
//
namespace coder {
namespace optim {
namespace coder {
namespace qpactiveset {
namespace Objective {
double computeFval(const b_struct_T &obj, double workspace[490],
                   const double H[81], const double f[9], const double x[10])
{
  double val;
  switch (obj.objtype) {
  case 5:
    val = obj.gammaScalar * x[obj.nvar - 1];
    break;
  case 3: {
    linearForm_(obj.hasLinear, obj.nvar, workspace, H, f, x);
    val = 0.0;
    if (obj.nvar >= 1) {
      int i;
      i = static_cast<unsigned char>(obj.nvar);
      for (int scalarLB{0}; scalarLB < i; scalarLB++) {
        val += x[scalarLB] * workspace[scalarLB];
      }
    }
  } break;
  default: {
    int i;
    int scalarLB;
    int vectorUB;
    linearForm_(obj.hasLinear, obj.nvar, workspace, H, f, x);
    i = obj.nvar + 1;
    scalarLB = (((10 - i) / 2) << 1) + i;
    vectorUB = scalarLB - 2;
    for (int idx{i}; idx <= vectorUB; idx += 2) {
      _mm_storeu_pd(&workspace[idx - 1],
                    _mm_mul_pd(_mm_set1_pd(0.0), _mm_loadu_pd(&x[idx - 1])));
    }
    for (int idx{scalarLB}; idx < 10; idx++) {
      workspace[idx - 1] = 0.0 * x[idx - 1];
    }
    val = 0.0;
    for (scalarLB = 0; scalarLB < 9; scalarLB++) {
      val += x[scalarLB] * workspace[scalarLB];
    }
  } break;
  }
  return val;
}

} // namespace Objective
} // namespace qpactiveset
} // namespace coder
} // namespace optim
} // namespace coder

//
// File trailer for computeFval.cpp
//
// [EOF]
//
