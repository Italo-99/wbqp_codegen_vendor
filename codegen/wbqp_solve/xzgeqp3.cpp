//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: xzgeqp3.cpp
//
// MATLAB Coder version            : 24.1
// C/C++ source code generated on  : 10-Sep-2025 16:14:33
//

// Include Files
#include "xzgeqp3.h"
#include "rt_nonfinite.h"
#include "xzlarf.h"
#include "xzlarfg.h"
#include <cstring>

// Function Definitions
//
// Arguments    : double A[490]
//                int m
//                int n
//                int nfxd
//                double tau[10]
// Return Type  : void
//
namespace coder {
namespace internal {
namespace reflapack {
void qrf(double A[490], int m, int n, int nfxd, double tau[10])
{
  double work[49];
  int i;
  std::memset(&tau[0], 0, 10U * sizeof(double));
  std::memset(&work[0], 0, 49U * sizeof(double));
  i = static_cast<unsigned char>(nfxd);
  for (int b_i{0}; b_i < i; b_i++) {
    double atmp;
    double d;
    int ii;
    int mmi;
    ii = b_i * 10 + b_i;
    mmi = m - b_i;
    if (b_i + 1 < m) {
      atmp = A[ii];
      d = xzlarfg(mmi, atmp, A, ii + 2);
      tau[b_i] = d;
      A[ii] = atmp;
    } else {
      d = 0.0;
      tau[b_i] = 0.0;
    }
    if (b_i + 1 < n) {
      atmp = A[ii];
      A[ii] = 1.0;
      xzlarf(mmi, (n - b_i) - 1, ii + 1, d, A, ii + 11, work);
      A[ii] = atmp;
    }
  }
}

} // namespace reflapack
} // namespace internal
} // namespace coder

//
// File trailer for xzgeqp3.cpp
//
// [EOF]
//
