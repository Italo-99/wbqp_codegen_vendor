//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: xzlarfg.cpp
//
// MATLAB Coder version            : 24.1
// C/C++ source code generated on  : 10-Sep-2025 16:14:33
//

// Include Files
#include "xzlarfg.h"
#include "rt_nonfinite.h"
#include "xnrm2.h"
#include <cmath>
#include <emmintrin.h>

// Function Declarations
static double rt_hypotd_snf(double u0, double u1);

// Function Definitions
//
// Arguments    : double u0
//                double u1
// Return Type  : double
//
static double rt_hypotd_snf(double u0, double u1)
{
  double a;
  double b;
  double y;
  a = std::abs(u0);
  b = std::abs(u1);
  if (a < b) {
    a /= b;
    y = b * std::sqrt(a * a + 1.0);
  } else if (a > b) {
    b /= a;
    y = a * std::sqrt(b * b + 1.0);
  } else if (std::isnan(b)) {
    y = rtNaN;
  } else {
    y = a * 1.4142135623730951;
  }
  return y;
}

//
// Arguments    : int n
//                double &alpha1
//                double x[490]
//                int ix0
// Return Type  : double
//
namespace coder {
namespace internal {
namespace reflapack {
double xzlarfg(int n, double &alpha1, double x[490], int ix0)
{
  double tau;
  tau = 0.0;
  if (n > 0) {
    double xnorm;
    xnorm = blas::xnrm2(n - 1, x, ix0);
    if (xnorm != 0.0) {
      double beta1;
      beta1 = rt_hypotd_snf(alpha1, xnorm);
      if (alpha1 >= 0.0) {
        beta1 = -beta1;
      }
      if (std::abs(beta1) < 1.0020841800044864E-292) {
        __m128d r;
        int i;
        int knt;
        int scalarLB;
        int vectorUB;
        knt = 0;
        i = (ix0 + n) - 2;
        do {
          knt++;
          scalarLB = ((i - ix0) + 1) / 2 * 2 + ix0;
          vectorUB = scalarLB - 2;
          for (int k{ix0}; k <= vectorUB; k += 2) {
            r = _mm_loadu_pd(&x[k - 1]);
            r = _mm_mul_pd(_mm_set1_pd(9.9792015476736E+291), r);
            _mm_storeu_pd(&x[k - 1], r);
          }
          for (int k{scalarLB}; k <= i; k++) {
            x[k - 1] *= 9.9792015476736E+291;
          }
          beta1 *= 9.9792015476736E+291;
          alpha1 *= 9.9792015476736E+291;
        } while ((std::abs(beta1) < 1.0020841800044864E-292) && (knt < 20));
        beta1 = rt_hypotd_snf(alpha1, blas::xnrm2(n - 1, x, ix0));
        if (alpha1 >= 0.0) {
          beta1 = -beta1;
        }
        tau = (beta1 - alpha1) / beta1;
        xnorm = 1.0 / (alpha1 - beta1);
        scalarLB = ((i - ix0) + 1) / 2 * 2 + ix0;
        vectorUB = scalarLB - 2;
        for (int k{ix0}; k <= vectorUB; k += 2) {
          r = _mm_loadu_pd(&x[k - 1]);
          r = _mm_mul_pd(_mm_set1_pd(xnorm), r);
          _mm_storeu_pd(&x[k - 1], r);
        }
        for (int k{scalarLB}; k <= i; k++) {
          x[k - 1] *= xnorm;
        }
        for (int k{0}; k < knt; k++) {
          beta1 *= 1.0020841800044864E-292;
        }
        alpha1 = beta1;
      } else {
        int i;
        int scalarLB;
        int vectorUB;
        tau = (beta1 - alpha1) / beta1;
        xnorm = 1.0 / (alpha1 - beta1);
        i = (ix0 + n) - 2;
        scalarLB = ((i - ix0) + 1) / 2 * 2 + ix0;
        vectorUB = scalarLB - 2;
        for (int k{ix0}; k <= vectorUB; k += 2) {
          __m128d r;
          r = _mm_loadu_pd(&x[k - 1]);
          r = _mm_mul_pd(_mm_set1_pd(xnorm), r);
          _mm_storeu_pd(&x[k - 1], r);
        }
        for (int k{scalarLB}; k <= i; k++) {
          x[k - 1] *= xnorm;
        }
        alpha1 = beta1;
      }
    }
  }
  return tau;
}

} // namespace reflapack
} // namespace internal
} // namespace coder

//
// File trailer for xzlarfg.cpp
//
// [EOF]
//
