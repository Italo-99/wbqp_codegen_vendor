//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: linearForm_.cpp
//
// MATLAB Coder version            : 24.1
// C/C++ source code generated on  : 10-Sep-2025 16:14:33
//

// Include Files
#include "linearForm_.h"
#include "rt_nonfinite.h"
#include <algorithm>
#include <cstring>

// Function Definitions
//
// Arguments    : boolean_T obj_hasLinear
//                int obj_nvar
//                double workspace[10]
//                const double H[81]
//                const double f[9]
//                const double x[10]
// Return Type  : void
//
namespace coder {
namespace optim {
namespace coder {
namespace qpactiveset {
namespace Objective {
void b_linearForm_(boolean_T obj_hasLinear, int obj_nvar, double workspace[10],
                   const double H[81], const double f[9], const double x[10])
{
  int beta1;
  beta1 = 0;
  if (obj_hasLinear) {
    beta1 = static_cast<unsigned char>(obj_nvar);
    if (beta1 - 1 >= 0) {
      std::copy(&f[0], &f[beta1], &workspace[0]);
    }
    beta1 = 1;
  }
  if (obj_nvar != 0) {
    int ix;
    if (beta1 != 1) {
      beta1 = static_cast<unsigned char>(obj_nvar);
      std::memset(&workspace[0], 0,
                  static_cast<unsigned int>(beta1) * sizeof(double));
    }
    ix = 0;
    beta1 = obj_nvar * (obj_nvar - 1) + 1;
    for (int iac{1}; obj_nvar < 0 ? iac >= beta1 : iac <= beta1;
         iac += obj_nvar) {
      int i;
      i = (iac + obj_nvar) - 1;
      for (int ia{iac}; ia <= i; ia++) {
        int i1;
        i1 = ia - iac;
        workspace[i1] += H[ia - 1] * x[ix];
      }
      ix++;
    }
  }
}

//
// Arguments    : boolean_T obj_hasLinear
//                int obj_nvar
//                double workspace[490]
//                const double H[81]
//                const double f[9]
//                const double x[10]
// Return Type  : void
//
void linearForm_(boolean_T obj_hasLinear, int obj_nvar, double workspace[490],
                 const double H[81], const double f[9], const double x[10])
{
  int beta1;
  beta1 = 0;
  if (obj_hasLinear) {
    beta1 = static_cast<unsigned char>(obj_nvar);
    if (beta1 - 1 >= 0) {
      std::copy(&f[0], &f[beta1], &workspace[0]);
    }
    beta1 = 1;
  }
  if (obj_nvar != 0) {
    int ix;
    if (beta1 != 1) {
      beta1 = static_cast<unsigned char>(obj_nvar);
      std::memset(&workspace[0], 0,
                  static_cast<unsigned int>(beta1) * sizeof(double));
    }
    ix = 0;
    beta1 = obj_nvar * (obj_nvar - 1) + 1;
    for (int iac{1}; obj_nvar < 0 ? iac >= beta1 : iac <= beta1;
         iac += obj_nvar) {
      double c;
      int i;
      c = 0.5 * x[ix];
      i = (iac + obj_nvar) - 1;
      for (int ia{iac}; ia <= i; ia++) {
        int i1;
        i1 = ia - iac;
        workspace[i1] += H[ia - 1] * c;
      }
      ix++;
    }
  }
}

} // namespace Objective
} // namespace qpactiveset
} // namespace coder
} // namespace optim
} // namespace coder

//
// File trailer for linearForm_.cpp
//
// [EOF]
//
