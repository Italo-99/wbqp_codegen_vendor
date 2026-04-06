//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: fullColLDL2_.cpp
//
// MATLAB Coder version            : 24.1
// C/C++ source code generated on  : 10-Sep-2025 16:14:33
//

// Include Files
#include "fullColLDL2_.h"
#include "rt_nonfinite.h"
#include "wbqp_solve_internal_types.h"
#include <cmath>
#include <emmintrin.h>

// Function Definitions
//
// Arguments    : c_struct_T &obj
//                int NColsRemain
//                double REG_PRIMAL
// Return Type  : void
//
namespace coder {
namespace optim {
namespace coder {
namespace DynamicRegCholManager {
void fullColLDL2_(c_struct_T &obj, int NColsRemain, double REG_PRIMAL)
{
  int jA;
  for (int k{0}; k < NColsRemain; k++) {
    double alpha1;
    double temp;
    int LD_diagOffset;
    int i;
    int offset1;
    int subMatrixDim;
    int vectorUB;
    LD_diagOffset = 11 * k;
    temp = obj.FMat[LD_diagOffset];
    if (std::abs(temp) <= obj.regTol_) {
      temp += REG_PRIMAL;
      obj.FMat[LD_diagOffset] = temp;
    }
    alpha1 = -1.0 / temp;
    subMatrixDim = (NColsRemain - k) - 2;
    offset1 = LD_diagOffset + 2;
    for (int b_k{0}; b_k <= subMatrixDim; b_k++) {
      obj.workspace_[b_k] = obj.FMat[(LD_diagOffset + b_k) + 1];
    }
    if (!(alpha1 == 0.0)) {
      jA = LD_diagOffset;
      for (int b_k{0}; b_k <= subMatrixDim; b_k++) {
        temp = obj.workspace_[b_k];
        if (temp != 0.0) {
          temp *= alpha1;
          i = jA + 12;
          vectorUB = subMatrixDim + jA;
          for (int ijA{i}; ijA <= vectorUB + 12; ijA++) {
            obj.FMat[ijA - 1] += obj.workspace_[(ijA - jA) - 12] * temp;
          }
        }
        jA += 10;
      }
    }
    temp = 1.0 / obj.FMat[LD_diagOffset];
    i = LD_diagOffset + subMatrixDim;
    jA = (((((i - LD_diagOffset) + 1) / 2) << 1) + LD_diagOffset) + 2;
    vectorUB = jA - 2;
    for (int b_k{offset1}; b_k <= vectorUB; b_k += 2) {
      __m128d r;
      r = _mm_loadu_pd(&obj.FMat[b_k - 1]);
      _mm_storeu_pd(&obj.FMat[b_k - 1], _mm_mul_pd(_mm_set1_pd(temp), r));
    }
    for (int b_k{jA}; b_k <= i + 2; b_k++) {
      obj.FMat[b_k - 1] *= temp;
    }
  }
  jA = 11 * (NColsRemain - 1);
  if (std::abs(obj.FMat[jA]) <= obj.regTol_) {
    obj.FMat[jA] += REG_PRIMAL;
  }
}

} // namespace DynamicRegCholManager
} // namespace coder
} // namespace optim
} // namespace coder

//
// File trailer for fullColLDL2_.cpp
//
// [EOF]
//
