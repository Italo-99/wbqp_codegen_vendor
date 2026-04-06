//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: computeGrad_StoreHx.cpp
//
// MATLAB Coder version            : 24.1
// C/C++ source code generated on  : 10-Sep-2025 16:14:33
//

// Include Files
#include "computeGrad_StoreHx.h"
#include "rt_nonfinite.h"
#include "wbqp_solve_internal_types.h"
#include "xgemv.h"
#include <algorithm>
#include <cstring>
#include <emmintrin.h>

// Function Definitions
//
// Arguments    : b_struct_T &obj
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
void computeGrad_StoreHx(b_struct_T &obj, const double H[81], const double f[9],
                         const double x[10])
{
  switch (obj.objtype) {
  case 5: {
    int ixlast;
    ixlast = obj.nvar;
    if (ixlast - 2 >= 0) {
      std::memset(&obj.grad[0], 0,
                  static_cast<unsigned int>(ixlast - 1) * sizeof(double));
    }
    obj.grad[obj.nvar - 1] = obj.gammaScalar;
  } break;
  case 3: {
    int ixlast;
    internal::blas::xgemv(obj.nvar, obj.nvar, H, obj.nvar, x, obj.Hx);
    ixlast = static_cast<unsigned char>(obj.nvar);
    if (ixlast - 1 >= 0) {
      std::copy(&obj.Hx[0], &obj.Hx[ixlast], &obj.grad[0]);
    }
    if (obj.hasLinear && (obj.nvar >= 1)) {
      int scalarLB;
      int vectorUB;
      ixlast = obj.nvar - 1;
      scalarLB = ((ixlast + 1) / 2) << 1;
      vectorUB = scalarLB - 2;
      for (int idx{0}; idx <= vectorUB; idx += 2) {
        __m128d r;
        r = _mm_loadu_pd(&obj.grad[idx]);
        _mm_storeu_pd(&obj.grad[idx], _mm_add_pd(r, _mm_loadu_pd(&f[idx])));
      }
      for (int idx{scalarLB}; idx <= ixlast; idx++) {
        obj.grad[idx] += f[idx];
      }
    }
  } break;
  default: {
    int ixlast;
    int scalarLB;
    int vectorUB;
    internal::blas::xgemv(obj.nvar, obj.nvar, H, obj.nvar, x, obj.Hx);
    ixlast = obj.nvar + 1;
    scalarLB = (((10 - ixlast) / 2) << 1) + ixlast;
    vectorUB = scalarLB - 2;
    for (int idx{ixlast}; idx <= vectorUB; idx += 2) {
      _mm_storeu_pd(&obj.Hx[idx - 1],
                    _mm_mul_pd(_mm_set1_pd(0.0), _mm_loadu_pd(&x[idx - 1])));
    }
    for (int idx{scalarLB}; idx < 10; idx++) {
      obj.Hx[idx - 1] = 0.0 * x[idx - 1];
    }
    std::copy(&obj.Hx[0], &obj.Hx[9], &obj.grad[0]);
    if (obj.hasLinear && (obj.nvar >= 1)) {
      ixlast = obj.nvar - 1;
      scalarLB = ((ixlast + 1) / 2) << 1;
      vectorUB = scalarLB - 2;
      for (int idx{0}; idx <= vectorUB; idx += 2) {
        __m128d r;
        r = _mm_loadu_pd(&obj.grad[idx]);
        _mm_storeu_pd(&obj.grad[idx], _mm_add_pd(r, _mm_loadu_pd(&f[idx])));
      }
      for (int idx{scalarLB}; idx <= ixlast; idx++) {
        obj.grad[idx] += f[idx];
      }
    }
  } break;
  }
}

} // namespace Objective
} // namespace qpactiveset
} // namespace coder
} // namespace optim
} // namespace coder

//
// File trailer for computeGrad_StoreHx.cpp
//
// [EOF]
//
