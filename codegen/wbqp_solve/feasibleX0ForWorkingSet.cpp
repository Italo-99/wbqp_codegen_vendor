//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: feasibleX0ForWorkingSet.cpp
//
// MATLAB Coder version            : 24.1
// C/C++ source code generated on  : 10-Sep-2025 16:14:33
//

// Include Files
#include "feasibleX0ForWorkingSet.h"
#include "computeQ_.h"
#include "factorQR.h"
#include "rt_nonfinite.h"
#include "wbqp_solve_data.h"
#include "wbqp_solve_internal_types.h"
#include "wbqp_solve_rtwutil.h"
#include "xzgeqp3.h"
#include <algorithm>
#include <cmath>
#include <cstring>
#include <emmintrin.h>

// Function Definitions
//
// Arguments    : double workspace[490]
//                double xCurrent[10]
//                f_struct_T &workingset
//                d_struct_T &qrmanager
// Return Type  : boolean_T
//
namespace coder {
namespace optim {
namespace coder {
namespace qpactiveset {
namespace initialize {
boolean_T feasibleX0ForWorkingSet(double workspace[490], double xCurrent[10],
                                  f_struct_T &workingset, d_struct_T &qrmanager)
{
  double B[490];
  int mWConstr;
  int nVar;
  boolean_T nonDegenerateWset;
  mWConstr = workingset.nActiveConstr;
  nVar = workingset.nVar;
  nonDegenerateWset = true;
  if (mWConstr != 0) {
    __m128d r;
    __m128d r1;
    double c;
    int b_i;
    int br;
    int i;
    int i1;
    int iAcol;
    int j;
    for (br = 0; br < mWConstr; br++) {
      c = workingset.bwset[br];
      workspace[br] = c;
      workspace[br + 49] = c;
    }
    if (mWConstr != 0) {
      i = 10 * (mWConstr - 1) + 1;
      for (iAcol = 1; iAcol <= i; iAcol += 10) {
        c = 0.0;
        i1 = (iAcol + nVar) - 1;
        for (br = iAcol; br <= i1; br++) {
          c += workingset.ATwset[br - 1] * xCurrent[br - iAcol];
        }
        i1 = div_nde_s32_floor(iAcol - 1);
        workspace[i1] -= c;
      }
    }
    if (mWConstr >= nVar) {
      int jBcol;
      i = static_cast<unsigned char>(nVar);
      for (br = 0; br < i; br++) {
        iAcol = 10 * br;
        for (jBcol = 0; jBcol < mWConstr; jBcol++) {
          qrmanager.QR[jBcol + iAcol] = workingset.ATwset[br + 10 * jBcol];
        }
      }
      qrmanager.usedPivoting = false;
      qrmanager.mrows = mWConstr;
      qrmanager.ncols = nVar;
      j = (static_cast<unsigned char>(nVar) >> 2) << 2;
      b_i = j - 4;
      for (br = 0; br <= b_i; br += 4) {
        _mm_storeu_si128(
            (__m128i *)&qrmanager.jpvt[br],
            _mm_add_epi32(
                _mm_add_epi32(_mm_set1_epi32(br),
                              _mm_loadu_si128((const __m128i *)&iv[0])),
                _mm_set1_epi32(1)));
      }
      for (br = j; br < i; br++) {
        qrmanager.jpvt[br] = br + 1;
      }
      if (mWConstr <= nVar) {
        i = mWConstr;
      } else {
        i = nVar;
      }
      qrmanager.minRowCol = i;
      std::copy(&qrmanager.QR[0], &qrmanager.QR[490], &B[0]);
      std::memset(&qrmanager.tau[0], 0, 10U * sizeof(double));
      if (i >= 1) {
        std::copy(&qrmanager.QR[0], &qrmanager.QR[490], &B[0]);
        internal::reflapack::qrf(B, mWConstr, nVar, i, qrmanager.tau);
      }
      std::copy(&B[0], &B[490], &qrmanager.QR[0]);
      QRManager::computeQ_(qrmanager, mWConstr);
      std::copy(&workspace[0], &workspace[490], &B[0]);
      for (int cr{0}; cr <= 49; cr += 49) {
        i = cr + 1;
        i1 = cr + nVar;
        if (i <= i1) {
          std::memset(&workspace[i + -1], 0,
                      static_cast<unsigned int>((i1 - i) + 1) * sizeof(double));
        }
      }
      br = -1;
      for (int cr{0}; cr <= 49; cr += 49) {
        jBcol = -1;
        i = cr + 1;
        i1 = cr + nVar;
        for (int ic{i}; ic <= i1; ic++) {
          c = 0.0;
          for (iAcol = 0; iAcol < mWConstr; iAcol++) {
            c += qrmanager.Q[(iAcol + jBcol) + 1] * B[(iAcol + br) + 1];
          }
          workspace[ic - 1] += c;
          jBcol += 10;
        }
        br += 49;
      }
      for (j = 0; j < 2; j++) {
        jBcol = 49 * j - 1;
        for (int k{nVar}; k >= 1; k--) {
          iAcol = 10 * (k - 1) - 1;
          i = k + jBcol;
          c = workspace[i];
          if (c != 0.0) {
            workspace[i] = c / qrmanager.QR[k + iAcol];
            i1 = static_cast<unsigned char>(k - 1);
            for (b_i = 0; b_i < i1; b_i++) {
              int i2;
              i2 = (b_i + jBcol) + 1;
              workspace[i2] -= workspace[i] * qrmanager.QR[(b_i + iAcol) + 1];
            }
          }
        }
      }
    } else {
      int jBcol;
      QRManager::factorQR(qrmanager, workingset.ATwset, nVar, mWConstr);
      QRManager::computeQ_(qrmanager, qrmanager.minRowCol);
      for (j = 0; j < 2; j++) {
        jBcol = 49 * j;
        for (b_i = 0; b_i < mWConstr; b_i++) {
          iAcol = 10 * b_i;
          br = b_i + jBcol;
          c = workspace[br];
          i = static_cast<unsigned char>(b_i);
          for (int k{0}; k < i; k++) {
            c -= qrmanager.QR[k + iAcol] * workspace[k + jBcol];
          }
          workspace[br] = c / qrmanager.QR[b_i + iAcol];
        }
      }
      std::copy(&workspace[0], &workspace[490], &B[0]);
      for (int cr{0}; cr <= 49; cr += 49) {
        i = cr + 1;
        i1 = cr + nVar;
        if (i <= i1) {
          std::memset(&workspace[i + -1], 0,
                      static_cast<unsigned int>((i1 - i) + 1) * sizeof(double));
        }
      }
      br = 0;
      for (int cr{0}; cr <= 49; cr += 49) {
        jBcol = -1;
        i = br + 1;
        i1 = br + mWConstr;
        for (int k{i}; k <= i1; k++) {
          int i2;
          i2 = cr + 1;
          iAcol = cr + nVar;
          j = ((iAcol - i2) + 1) / 2 * 2 + i2;
          b_i = j - 2;
          for (int ic{i2}; ic <= b_i; ic += 2) {
            r = _mm_loadu_pd(&qrmanager.Q[(jBcol + ic) - cr]);
            r = _mm_mul_pd(_mm_set1_pd(B[k - 1]), r);
            r1 = _mm_loadu_pd(&workspace[ic - 1]);
            r = _mm_add_pd(r1, r);
            _mm_storeu_pd(&workspace[ic - 1], r);
          }
          for (int ic{j}; ic <= iAcol; ic++) {
            workspace[ic - 1] += B[k - 1] * qrmanager.Q[(jBcol + ic) - cr];
          }
          jBcol += 10;
        }
        br += 49;
      }
    }
    br = 0;
    int exitg1;
    do {
      exitg1 = 0;
      if (br <= static_cast<unsigned char>(nVar) - 1) {
        if (std::isinf(workspace[br]) || std::isnan(workspace[br])) {
          nonDegenerateWset = false;
          exitg1 = 1;
        } else {
          c = workspace[br + 49];
          if (std::isinf(c) || std::isnan(c)) {
            nonDegenerateWset = false;
            exitg1 = 1;
          } else {
            br++;
          }
        }
      } else {
        double b_v;
        double v;
        iAcol = nVar - 1;
        j = (iAcol + 1) / 2 * 2;
        b_i = j - 2;
        for (int k{0}; k <= b_i; k += 2) {
          r = _mm_loadu_pd(&workspace[k]);
          r1 = _mm_loadu_pd(&xCurrent[k]);
          r = _mm_add_pd(r, r1);
          _mm_storeu_pd(&workspace[k], r);
        }
        for (int k{j}; k <= iAcol; k++) {
          workspace[k] += xCurrent[k];
        }
        if (workingset.probType == 2) {
          v = 0.0;
          for (int k{0}; k < 30; k++) {
            workingset.maxConstrWorkspace[k] = workingset.bineq[k];
            workingset.maxConstrWorkspace[k] =
                -workingset.maxConstrWorkspace[k];
          }
          for (iAcol = 0; iAcol <= 290; iAcol += 10) {
            c = 0.0;
            i = iAcol + 9;
            for (br = iAcol + 1; br <= i; br++) {
              c += workingset.Aineq[br - 1] * workspace[(br - iAcol) - 1];
            }
            i = div_nde_s32_floor(iAcol);
            workingset.maxConstrWorkspace[i] += c;
          }
          for (br = 0; br < 30; br++) {
            c = workingset.maxConstrWorkspace[br] - workspace[br + 9];
            workingset.maxConstrWorkspace[br] = c;
            v = std::fmax(v, c);
          }
        } else {
          v = 0.0;
          for (int k{0}; k < 30; k++) {
            workingset.maxConstrWorkspace[k] = workingset.bineq[k];
            workingset.maxConstrWorkspace[k] =
                -workingset.maxConstrWorkspace[k];
          }
          for (iAcol = 0; iAcol <= 290; iAcol += 10) {
            c = 0.0;
            i = iAcol + workingset.nVar;
            for (br = iAcol + 1; br <= i; br++) {
              c += workingset.Aineq[br - 1] * workspace[(br - iAcol) - 1];
            }
            i = div_nde_s32_floor(iAcol);
            workingset.maxConstrWorkspace[i] += c;
          }
          for (br = 0; br < 30; br++) {
            v = std::fmax(v, workingset.maxConstrWorkspace[br]);
          }
        }
        if (workingset.sizes[3] > 0) {
          i = static_cast<unsigned char>(workingset.sizes[3]);
          for (br = 0; br < i; br++) {
            iAcol = workingset.indexLB[br] - 1;
            v = std::fmax(v, -workspace[iAcol] - workingset.lb[iAcol]);
          }
        }
        if (workingset.sizes[4] > 0) {
          i = static_cast<unsigned char>(workingset.sizes[4]);
          for (br = 0; br < i; br++) {
            iAcol = workingset.indexUB[br] - 1;
            v = std::fmax(v, workspace[iAcol] - workingset.ub[iAcol]);
          }
        }
        if (workingset.sizes[0] > 0) {
          i = static_cast<unsigned char>(workingset.sizes[0]);
          for (br = 0; br < i; br++) {
            v = std::fmax(
                v, std::abs(workspace[workingset.indexFixed[br] - 1] -
                            workingset.ub[workingset.indexFixed[br] - 1]));
          }
        }
        if (workingset.probType == 2) {
          b_v = 0.0;
          for (int k{0}; k < 30; k++) {
            workingset.maxConstrWorkspace[k] = workingset.bineq[k];
            workingset.maxConstrWorkspace[k] =
                -workingset.maxConstrWorkspace[k];
          }
          for (iAcol = 0; iAcol <= 290; iAcol += 10) {
            c = 0.0;
            i = iAcol + 9;
            for (br = iAcol + 1; br <= i; br++) {
              c += workingset.Aineq[br - 1] * workspace[(br - iAcol) + 48];
            }
            i = div_nde_s32_floor(iAcol);
            workingset.maxConstrWorkspace[i] += c;
          }
          for (br = 0; br < 30; br++) {
            c = workingset.maxConstrWorkspace[br] - workspace[br + 58];
            workingset.maxConstrWorkspace[br] = c;
            b_v = std::fmax(b_v, c);
          }
        } else {
          b_v = 0.0;
          for (int k{0}; k < 30; k++) {
            workingset.maxConstrWorkspace[k] = workingset.bineq[k];
            workingset.maxConstrWorkspace[k] =
                -workingset.maxConstrWorkspace[k];
          }
          for (iAcol = 0; iAcol <= 290; iAcol += 10) {
            c = 0.0;
            i = iAcol + workingset.nVar;
            for (br = iAcol + 1; br <= i; br++) {
              c += workingset.Aineq[br - 1] * workspace[(br - iAcol) + 48];
            }
            i = div_nde_s32_floor(iAcol);
            workingset.maxConstrWorkspace[i] += c;
          }
          for (br = 0; br < 30; br++) {
            b_v = std::fmax(b_v, workingset.maxConstrWorkspace[br]);
          }
        }
        if (workingset.sizes[3] > 0) {
          i = static_cast<unsigned char>(workingset.sizes[3]);
          for (br = 0; br < i; br++) {
            iAcol = workingset.indexLB[br];
            b_v = std::fmax(b_v,
                            -workspace[iAcol + 48] - workingset.lb[iAcol - 1]);
          }
        }
        if (workingset.sizes[4] > 0) {
          i = static_cast<unsigned char>(workingset.sizes[4]);
          for (br = 0; br < i; br++) {
            iAcol = workingset.indexUB[br];
            b_v = std::fmax(b_v,
                            workspace[iAcol + 48] - workingset.ub[iAcol - 1]);
          }
        }
        if (workingset.sizes[0] > 0) {
          i = static_cast<unsigned char>(workingset.sizes[0]);
          for (br = 0; br < i; br++) {
            b_v = std::fmax(
                b_v, std::abs(workspace[workingset.indexFixed[br] + 48] -
                              workingset.ub[workingset.indexFixed[br] - 1]));
          }
        }
        if ((v <= 2.2204460492503131E-16) || (v < b_v)) {
          i = static_cast<unsigned char>(nVar);
          std::copy(&workspace[0], &workspace[i], &xCurrent[0]);
        } else {
          i = static_cast<unsigned char>(nVar);
          std::copy(&workspace[49], &workspace[49 + i], &xCurrent[0]);
        }
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }
  return nonDegenerateWset;
}

} // namespace initialize
} // namespace qpactiveset
} // namespace coder
} // namespace optim
} // namespace coder

//
// File trailer for feasibleX0ForWorkingSet.cpp
//
// [EOF]
//
