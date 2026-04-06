//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: compute_deltax.cpp
//
// MATLAB Coder version            : 24.1
// C/C++ source code generated on  : 10-Sep-2025 16:14:33
//

// Include Files
#include "compute_deltax.h"
#include "fullColLDL2_.h"
#include "rt_nonfinite.h"
#include "wbqp_solve_internal_types.h"
#include "wbqp_solve_rtwutil.h"
#include <cmath>
#include <cstring>
#include <emmintrin.h>

// Function Definitions
//
// Arguments    : const double H[81]
//                struct_T &solution
//                e_struct_T &memspace
//                const d_struct_T &qrmanager
//                c_struct_T &cholmanager
//                const b_struct_T &objective
// Return Type  : void
//
namespace coder {
namespace optim {
namespace coder {
namespace qpactiveset {
void compute_deltax(const double H[81], struct_T &solution,
                    e_struct_T &memspace, const d_struct_T &qrmanager,
                    c_struct_T &cholmanager, const b_struct_T &objective)
{
  int mNull_tmp;
  int nVar_tmp;
  nVar_tmp = qrmanager.mrows - 1;
  mNull_tmp = qrmanager.mrows - qrmanager.ncols;
  if (mNull_tmp <= 0) {
    if (nVar_tmp >= 0) {
      std::memset(&solution.searchDir[0], 0,
                  static_cast<unsigned int>(nVar_tmp + 1) * sizeof(double));
    }
  } else {
    __m128d r;
    int ix;
    int nVars;
    int scalarLB;
    scalarLB = ((nVar_tmp + 1) / 2) << 1;
    ix = scalarLB - 2;
    for (nVars = 0; nVars <= ix; nVars += 2) {
      r = _mm_loadu_pd(&objective.grad[nVars]);
      _mm_storeu_pd(&solution.searchDir[nVars],
                    _mm_mul_pd(r, _mm_set1_pd(-1.0)));
    }
    for (nVars = scalarLB; nVars <= nVar_tmp; nVars++) {
      solution.searchDir[nVars] = -objective.grad[nVars];
    }
    if (qrmanager.ncols <= 0) {
      if (objective.objtype == 3) {
        double temp;
        int A_maxDiag_idx;
        temp = 1.4901161193847656E-6 * static_cast<double>(qrmanager.mrows);
        cholmanager.ndims = qrmanager.mrows;
        for (nVars = 0; nVars <= nVar_tmp; nVars++) {
          A_maxDiag_idx = (nVar_tmp + 1) * nVars;
          ix = 10 * nVars;
          for (scalarLB = 0; scalarLB <= nVar_tmp; scalarLB++) {
            cholmanager.FMat[ix + scalarLB] = H[A_maxDiag_idx + scalarLB];
          }
        }
        if (qrmanager.mrows < 1) {
          A_maxDiag_idx = -1;
        } else {
          A_maxDiag_idx = 0;
          if (qrmanager.mrows > 1) {
            double smax;
            smax = std::abs(cholmanager.FMat[0]);
            for (scalarLB = 2; scalarLB <= nVar_tmp + 1; scalarLB++) {
              double s;
              s = std::abs(cholmanager.FMat[(scalarLB - 1) * 11]);
              if (s > smax) {
                A_maxDiag_idx = scalarLB - 1;
                smax = s;
              }
            }
          }
        }
        cholmanager.regTol_ = std::fmax(
            std::abs(cholmanager.FMat[A_maxDiag_idx + 10 * A_maxDiag_idx]) *
                2.2204460492503131E-16,
            std::abs(temp));
        DynamicRegCholManager::fullColLDL2_(cholmanager, qrmanager.mrows, temp);
        if (cholmanager.ConvexCheck) {
          nVars = 0;
          int exitg1;
          do {
            exitg1 = 0;
            if (nVars <= nVar_tmp) {
              if (cholmanager.FMat[nVars + 10 * nVars] <= 0.0) {
                cholmanager.info = -nVars - 1;
                exitg1 = 1;
              } else {
                nVars++;
              }
            } else {
              cholmanager.ConvexCheck = false;
              exitg1 = 1;
            }
          } while (exitg1 == 0);
        }
        if (cholmanager.info != 0) {
          solution.state = -6;
        } else {
          int i;
          scalarLB = cholmanager.ndims - 2;
          if (cholmanager.ndims != 0) {
            for (nVars = 0; nVars <= scalarLB + 1; nVars++) {
              A_maxDiag_idx = nVars + nVars * 10;
              i = scalarLB - nVars;
              for (int br{0}; br <= i; br++) {
                ix = (nVars + br) + 1;
                solution.searchDir[ix] -=
                    solution.searchDir[nVars] *
                    cholmanager.FMat[(A_maxDiag_idx + br) + 1];
              }
            }
          }
          scalarLB = cholmanager.ndims;
          for (nVars = 0; nVars < scalarLB; nVars++) {
            solution.searchDir[nVars] /= cholmanager.FMat[nVars + 10 * nVars];
          }
          if (cholmanager.ndims != 0) {
            for (nVars = scalarLB; nVars >= 1; nVars--) {
              ix = (nVars - 1) * 10;
              temp = solution.searchDir[nVars - 1];
              i = nVars + 1;
              for (int br{scalarLB}; br >= i; br--) {
                temp -= cholmanager.FMat[(ix + br) - 1] *
                        solution.searchDir[br - 1];
              }
              solution.searchDir[nVars - 1] = temp;
            }
          }
        }
      }
    } else {
      int nullStartIdx;
      int nullStartIdx_tmp;
      nullStartIdx_tmp = 10 * qrmanager.ncols;
      nullStartIdx = nullStartIdx_tmp + 1;
      if (objective.objtype == 5) {
        for (nVars = 0; nVars < mNull_tmp; nVars++) {
          memspace.workspace_float[nVars] =
              -qrmanager.Q[nVar_tmp + 10 * (qrmanager.ncols + nVars)];
        }
        if (qrmanager.mrows != 0) {
          int i;
          std::memset(&solution.searchDir[0], 0,
                      static_cast<unsigned int>(nVar_tmp + 1) * sizeof(double));
          ix = 0;
          i = (nullStartIdx_tmp + 10 * (mNull_tmp - 1)) + 1;
          for (int A_maxDiag_idx{nullStartIdx}; A_maxDiag_idx <= i;
               A_maxDiag_idx += 10) {
            int i1;
            i1 = A_maxDiag_idx + nVar_tmp;
            for (scalarLB = A_maxDiag_idx; scalarLB <= i1; scalarLB++) {
              int i2;
              i2 = scalarLB - A_maxDiag_idx;
              solution.searchDir[i2] +=
                  qrmanager.Q[scalarLB - 1] * memspace.workspace_float[ix];
            }
            ix++;
          }
        }
      } else {
        double temp;
        int A_maxDiag_idx;
        int br;
        int i;
        int i1;
        int i2;
        if (objective.objtype == 3) {
          int ar;
          int lastColC;
          nVars = qrmanager.mrows;
          if (qrmanager.mrows != 0) {
            br = nullStartIdx_tmp;
            lastColC = 49 * (mNull_tmp - 1);
            for (int cr{0}; cr <= lastColC; cr += 49) {
              i = cr + 1;
              i1 = cr + nVars;
              if (i <= i1) {
                std::memset(&memspace.workspace_float[i + -1], 0,
                            static_cast<unsigned int>((i1 - i) + 1) *
                                sizeof(double));
              }
            }
            for (int cr{0}; cr <= lastColC; cr += 49) {
              ar = -1;
              i = br + 1;
              i1 = br + nVars;
              for (int ib{i}; ib <= i1; ib++) {
                i2 = cr + 1;
                A_maxDiag_idx = cr + nVars;
                scalarLB = ((A_maxDiag_idx - i2) + 1) / 2 * 2 + i2;
                ix = scalarLB - 2;
                for (int ic{i2}; ic <= ix; ic += 2) {
                  __m128d r1;
                  r = _mm_loadu_pd(&H[(ar + ic) - cr]);
                  r = _mm_mul_pd(_mm_set1_pd(qrmanager.Q[ib - 1]), r);
                  r1 = _mm_loadu_pd(&memspace.workspace_float[ic - 1]);
                  r = _mm_add_pd(r1, r);
                  _mm_storeu_pd(&memspace.workspace_float[ic - 1], r);
                }
                for (int ic{scalarLB}; ic <= A_maxDiag_idx; ic++) {
                  memspace.workspace_float[ic - 1] +=
                      qrmanager.Q[ib - 1] * H[(ar + ic) - cr];
                }
                ar += nVars;
              }
              br += 10;
            }
          }
          lastColC = 10 * (mNull_tmp - 1);
          for (int cr{0}; cr <= lastColC; cr += 10) {
            i = cr + 1;
            i1 = cr + mNull_tmp;
            if (i <= i1) {
              std::memset(&cholmanager.FMat[i + -1], 0,
                          static_cast<unsigned int>((i1 - i) + 1) *
                              sizeof(double));
            }
          }
          br = -1;
          for (int cr{0}; cr <= lastColC; cr += 10) {
            ar = nullStartIdx_tmp;
            i = cr + 1;
            i1 = cr + mNull_tmp;
            for (int ic{i}; ic <= i1; ic++) {
              temp = 0.0;
              for (A_maxDiag_idx = 0; A_maxDiag_idx < nVars; A_maxDiag_idx++) {
                temp += qrmanager.Q[A_maxDiag_idx + ar] *
                        memspace.workspace_float[(A_maxDiag_idx + br) + 1];
              }
              cholmanager.FMat[ic - 1] += temp;
              ar += 10;
            }
            br += 49;
          }
        }
        temp = 1.4901161193847656E-6 * static_cast<double>(mNull_tmp);
        cholmanager.ndims = mNull_tmp;
        A_maxDiag_idx = 0;
        if (mNull_tmp > 1) {
          double smax;
          smax = std::abs(cholmanager.FMat[0]);
          for (scalarLB = 2; scalarLB <= mNull_tmp; scalarLB++) {
            double s;
            s = std::abs(cholmanager.FMat[(scalarLB - 1) * 11]);
            if (s > smax) {
              A_maxDiag_idx = scalarLB - 1;
              smax = s;
            }
          }
        }
        cholmanager.regTol_ = std::fmax(
            std::abs(cholmanager.FMat[A_maxDiag_idx + 10 * A_maxDiag_idx]) *
                2.2204460492503131E-16,
            temp);
        DynamicRegCholManager::fullColLDL2_(cholmanager, mNull_tmp, temp);
        if (cholmanager.ConvexCheck) {
          nVars = 0;
          int exitg1;
          do {
            exitg1 = 0;
            if (nVars <= mNull_tmp - 1) {
              if (cholmanager.FMat[nVars + 10 * nVars] <= 0.0) {
                cholmanager.info = -nVars - 1;
                exitg1 = 1;
              } else {
                nVars++;
              }
            } else {
              cholmanager.ConvexCheck = false;
              exitg1 = 1;
            }
          } while (exitg1 == 0);
        }
        if (cholmanager.info != 0) {
          solution.state = -6;
        } else {
          if (qrmanager.mrows != 0) {
            std::memset(&memspace.workspace_float[0], 0,
                        static_cast<unsigned int>(mNull_tmp) * sizeof(double));
            i = (nullStartIdx_tmp + 10 * (mNull_tmp - 1)) + 1;
            for (A_maxDiag_idx = nullStartIdx; A_maxDiag_idx <= i;
                 A_maxDiag_idx += 10) {
              temp = 0.0;
              i1 = A_maxDiag_idx + nVar_tmp;
              for (scalarLB = A_maxDiag_idx; scalarLB <= i1; scalarLB++) {
                temp += qrmanager.Q[scalarLB - 1] *
                        objective.grad[scalarLB - A_maxDiag_idx];
              }
              i1 = div_nde_s32_floor((A_maxDiag_idx - nullStartIdx_tmp) - 1);
              memspace.workspace_float[i1] -= temp;
            }
          }
          scalarLB = cholmanager.ndims - 2;
          if (cholmanager.ndims != 0) {
            for (nVars = 0; nVars <= scalarLB + 1; nVars++) {
              A_maxDiag_idx = nVars + nVars * 10;
              i = scalarLB - nVars;
              for (br = 0; br <= i; br++) {
                ix = (nVars + br) + 1;
                memspace.workspace_float[ix] -=
                    memspace.workspace_float[nVars] *
                    cholmanager.FMat[(A_maxDiag_idx + br) + 1];
              }
            }
          }
          scalarLB = cholmanager.ndims;
          for (nVars = 0; nVars < scalarLB; nVars++) {
            memspace.workspace_float[nVars] /=
                cholmanager.FMat[nVars + 10 * nVars];
          }
          if (cholmanager.ndims != 0) {
            for (nVars = scalarLB; nVars >= 1; nVars--) {
              ix = (nVars - 1) * 10;
              temp = memspace.workspace_float[nVars - 1];
              i = nVars + 1;
              for (br = scalarLB; br >= i; br--) {
                temp -= cholmanager.FMat[(ix + br) - 1] *
                        memspace.workspace_float[br - 1];
              }
              memspace.workspace_float[nVars - 1] = temp;
            }
          }
          if (qrmanager.mrows != 0) {
            std::memset(&solution.searchDir[0], 0,
                        static_cast<unsigned int>(nVar_tmp + 1) *
                            sizeof(double));
            ix = 0;
            i = (nullStartIdx_tmp + 10 * (mNull_tmp - 1)) + 1;
            for (A_maxDiag_idx = nullStartIdx; A_maxDiag_idx <= i;
                 A_maxDiag_idx += 10) {
              i1 = A_maxDiag_idx + nVar_tmp;
              for (scalarLB = A_maxDiag_idx; scalarLB <= i1; scalarLB++) {
                i2 = scalarLB - A_maxDiag_idx;
                solution.searchDir[i2] +=
                    qrmanager.Q[scalarLB - 1] * memspace.workspace_float[ix];
              }
              ix++;
            }
          }
        }
      }
    }
  }
}

} // namespace qpactiveset
} // namespace coder
} // namespace optim
} // namespace coder

//
// File trailer for compute_deltax.cpp
//
// [EOF]
//
