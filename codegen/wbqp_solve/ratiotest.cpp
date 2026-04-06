//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: ratiotest.cpp
//
// MATLAB Coder version            : 24.1
// C/C++ source code generated on  : 10-Sep-2025 16:14:33
//

// Include Files
#include "ratiotest.h"
#include "rt_nonfinite.h"
#include "wbqp_solve_rtwutil.h"
#include "xnrm2.h"
#include <cmath>
#include <cstring>
#include <emmintrin.h>

// Function Definitions
//
// Arguments    : const double solution_xstar[10]
//                const double solution_searchDir[10]
//                double workspace[490]
//                int workingset_nVar
//                const double workingset_Aineq[300]
//                const double workingset_bineq[30]
//                const double workingset_lb[10]
//                const double workingset_ub[10]
//                const int workingset_indexLB[10]
//                const int workingset_indexUB[10]
//                const int workingset_sizes[5]
//                const int workingset_isActiveIdx[6]
//                const boolean_T workingset_isActiveConstr[49]
//                const int workingset_nWConstr[5]
//                double &toldelta
//                boolean_T &newBlocking
//                int &constrType
//                int &constrIdx
// Return Type  : double
//
namespace coder {
namespace optim {
namespace coder {
namespace qpactiveset {
double
ratiotest(const double solution_xstar[10], const double solution_searchDir[10],
          double workspace[490], int workingset_nVar,
          const double workingset_Aineq[300], const double workingset_bineq[30],
          const double workingset_lb[10], const double workingset_ub[10],
          const int workingset_indexLB[10], const int workingset_indexUB[10],
          const int workingset_sizes[5], const int workingset_isActiveIdx[6],
          const boolean_T workingset_isActiveConstr[49],
          const int workingset_nWConstr[5], double &toldelta,
          boolean_T &newBlocking, int &constrType, int &constrIdx)
{
  double alpha;
  double alphaTemp;
  double c;
  double denomTol;
  double p_max;
  double phaseOneCorrectionP;
  double pk_corrected;
  double ratio_tmp;
  int i;
  int k;
  alpha = 1.0E+30;
  newBlocking = false;
  constrType = 0;
  constrIdx = 0;
  p_max = 0.0;
  denomTol = 2.2204460492503131E-13 *
             internal::blas::xnrm2(workingset_nVar, solution_searchDir);
  if (workingset_nWConstr[2] < 30) {
    for (k = 0; k <= 28; k += 2) {
      __m128d r;
      r = _mm_loadu_pd(&workingset_bineq[k]);
      r = _mm_mul_pd(r, _mm_set1_pd(-1.0));
      _mm_storeu_pd(&workspace[k], r);
    }
    for (k = 0; k <= 290; k += 10) {
      c = 0.0;
      i = k + workingset_nVar;
      for (int ia{k + 1}; ia <= i; ia++) {
        c += workingset_Aineq[ia - 1] * solution_xstar[(ia - k) - 1];
      }
      i = div_nde_s32_floor(k);
      workspace[i] += c;
    }
    std::memset(&workspace[49], 0, 30U * sizeof(double));
    for (k = 0; k <= 290; k += 10) {
      c = 0.0;
      i = k + workingset_nVar;
      for (int ia{k + 1}; ia <= i; ia++) {
        c += workingset_Aineq[ia - 1] * solution_searchDir[(ia - k) - 1];
      }
      i = div_nde_s32_floor(k) + 49;
      workspace[i] += c;
    }
    for (int ia{0}; ia < 30; ia++) {
      phaseOneCorrectionP = workspace[ia + 49];
      if ((phaseOneCorrectionP > denomTol) &&
          (!workingset_isActiveConstr[(workingset_isActiveIdx[2] + ia) - 1])) {
        c = workspace[ia];
        alphaTemp = std::fmin(std::abs(c - toldelta), (1.0E-6 - c) + toldelta) /
                    phaseOneCorrectionP;
        if ((alphaTemp <= alpha) && (std::abs(phaseOneCorrectionP) > p_max)) {
          alpha = alphaTemp;
          constrType = 3;
          constrIdx = ia + 1;
          newBlocking = true;
        }
        alphaTemp = std::fmin(std::abs(c), 1.0E-6 - c) / phaseOneCorrectionP;
        if (alphaTemp < alpha) {
          alpha = alphaTemp;
          constrType = 3;
          constrIdx = ia + 1;
          newBlocking = true;
          p_max = std::abs(phaseOneCorrectionP);
        }
      }
    }
  }
  if (workingset_nWConstr[3] < workingset_sizes[3]) {
    c = 0.0 * solution_xstar[workingset_nVar - 1];
    phaseOneCorrectionP = 0.0 * solution_searchDir[workingset_nVar - 1];
    i = workingset_sizes[3];
    for (int ia{0}; ia <= i - 2; ia++) {
      k = workingset_indexLB[ia];
      pk_corrected = -solution_searchDir[k - 1] - phaseOneCorrectionP;
      if ((pk_corrected > denomTol) &&
          (!workingset_isActiveConstr[(workingset_isActiveIdx[3] + ia) - 1])) {
        ratio_tmp = -solution_xstar[k - 1] - workingset_lb[k - 1];
        alphaTemp = (ratio_tmp - toldelta) - c;
        alphaTemp =
            std::fmin(std::abs(alphaTemp), 1.0E-6 - alphaTemp) / pk_corrected;
        if ((alphaTemp <= alpha) && (std::abs(pk_corrected) > p_max)) {
          alpha = alphaTemp;
          constrType = 4;
          constrIdx = ia + 1;
          newBlocking = true;
        }
        alphaTemp = ratio_tmp - c;
        alphaTemp =
            std::fmin(std::abs(alphaTemp), 1.0E-6 - alphaTemp) / pk_corrected;
        if (alphaTemp < alpha) {
          alpha = alphaTemp;
          constrType = 4;
          constrIdx = ia + 1;
          newBlocking = true;
          p_max = std::abs(pk_corrected);
        }
      }
    }
    i = workingset_indexLB[workingset_sizes[3] - 1] - 1;
    phaseOneCorrectionP = solution_searchDir[i];
    if ((-phaseOneCorrectionP > denomTol) &&
        (!workingset_isActiveConstr
             [(workingset_isActiveIdx[3] + workingset_sizes[3]) - 2])) {
      ratio_tmp = -solution_xstar[i] - workingset_lb[i];
      alphaTemp = ratio_tmp - toldelta;
      alphaTemp = std::fmin(std::abs(alphaTemp), 1.0E-6 - alphaTemp) /
                  -phaseOneCorrectionP;
      if ((alphaTemp <= alpha) && (std::abs(phaseOneCorrectionP) > p_max)) {
        alpha = alphaTemp;
        constrType = 4;
        constrIdx = workingset_sizes[3];
        newBlocking = true;
      }
      alphaTemp = std::fmin(std::abs(ratio_tmp), 1.0E-6 - ratio_tmp) /
                  -phaseOneCorrectionP;
      if (alphaTemp < alpha) {
        alpha = alphaTemp;
        constrType = 4;
        constrIdx = workingset_sizes[3];
        newBlocking = true;
        p_max = std::abs(phaseOneCorrectionP);
      }
    }
  }
  if (workingset_nWConstr[4] < workingset_sizes[4]) {
    c = 0.0 * solution_xstar[workingset_nVar - 1];
    phaseOneCorrectionP = 0.0 * solution_searchDir[workingset_nVar - 1];
    i = static_cast<unsigned char>(workingset_sizes[4]);
    for (int ia{0}; ia < i; ia++) {
      k = workingset_indexUB[ia];
      pk_corrected = solution_searchDir[k - 1] - phaseOneCorrectionP;
      if ((pk_corrected > denomTol) &&
          (!workingset_isActiveConstr[(workingset_isActiveIdx[4] + ia) - 1])) {
        ratio_tmp = solution_xstar[k - 1] - workingset_ub[k - 1];
        alphaTemp = (ratio_tmp - toldelta) - c;
        alphaTemp =
            std::fmin(std::abs(alphaTemp), 1.0E-6 - alphaTemp) / pk_corrected;
        if ((alphaTemp <= alpha) && (std::abs(pk_corrected) > p_max)) {
          alpha = alphaTemp;
          constrType = 5;
          constrIdx = ia + 1;
          newBlocking = true;
        }
        alphaTemp = ratio_tmp - c;
        alphaTemp =
            std::fmin(std::abs(alphaTemp), 1.0E-6 - alphaTemp) / pk_corrected;
        if (alphaTemp < alpha) {
          alpha = alphaTemp;
          constrType = 5;
          constrIdx = ia + 1;
          newBlocking = true;
          p_max = std::abs(pk_corrected);
        }
      }
    }
  }
  toldelta += 6.608625846508183E-7;
  if (p_max > 0.0) {
    alpha = std::fmax(alpha, 6.608625846508183E-7 / p_max);
  }
  if (newBlocking && (alpha > 1.0)) {
    newBlocking = false;
  }
  return std::fmin(alpha, 1.0);
}

} // namespace qpactiveset
} // namespace coder
} // namespace optim
} // namespace coder

//
// File trailer for ratiotest.cpp
//
// [EOF]
//
