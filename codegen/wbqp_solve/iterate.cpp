//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: iterate.cpp
//
// MATLAB Coder version            : 24.1
// C/C++ source code generated on  : 10-Sep-2025 16:14:33
//

// Include Files
#include "iterate.h"
#include "addBoundToActiveSetMatrix_.h"
#include "computeFval_ReuseHx.h"
#include "computeGrad_StoreHx.h"
#include "computeQ_.h"
#include "compute_deltax.h"
#include "deleteColMoveEnd.h"
#include "factorQR.h"
#include "feasibleX0ForWorkingSet.h"
#include "feasibleratiotest.h"
#include "maxConstraintViolation.h"
#include "ratiotest.h"
#include "removeConstr.h"
#include "rt_nonfinite.h"
#include "wbqp_solve_internal_types.h"
#include "wbqp_solve_rtwutil.h"
#include "xnrm2.h"
#include "xrotg.h"
#include <algorithm>
#include <cmath>
#include <cstring>
#include <emmintrin.h>

// Function Definitions
//
// Arguments    : const double H[81]
//                const double f[9]
//                struct_T &solution
//                e_struct_T &memspace
//                f_struct_T &workingset
//                d_struct_T &qrmanager
//                c_struct_T &cholmanager
//                b_struct_T &objective
//                double options_ObjectiveLimit
//                double options_StepTolerance
//                double runTimeOptions_ConstrRelTolFactor
//                double runTimeOptions_ProbRelTolFactor
//                boolean_T runTimeOptions_RemainFeasible
// Return Type  : void
//
namespace coder {
namespace optim {
namespace coder {
namespace qpactiveset {
void iterate(const double H[81], const double f[9], struct_T &solution,
             e_struct_T &memspace, f_struct_T &workingset,
             d_struct_T &qrmanager, c_struct_T &cholmanager,
             b_struct_T &objective, double options_ObjectiveLimit,
             double options_StepTolerance,
             double runTimeOptions_ConstrRelTolFactor,
             double runTimeOptions_ProbRelTolFactor,
             boolean_T runTimeOptions_RemainFeasible)
{
  double s;
  double temp;
  double tolDelta;
  int TYPE;
  int activeSetChangeID;
  int globalActiveConstrIdx;
  int iyend;
  int localActiveConstrIdx;
  int nVar;
  boolean_T newBlocking;
  boolean_T subProblemChanged;
  boolean_T updateFval;
  subProblemChanged = true;
  updateFval = true;
  activeSetChangeID = 0;
  TYPE = objective.objtype;
  tolDelta = 6.7434957617430445E-7;
  nVar = workingset.nVar;
  globalActiveConstrIdx = 0;
  Objective::computeGrad_StoreHx(objective, H, f, solution.xstar);
  solution.fstar = Objective::computeFval_ReuseHx(
      objective, memspace.workspace_float, f, solution.xstar);
  if (solution.iterations < 50) {
    solution.state = -5;
  } else {
    solution.state = 0;
  }
  std::memset(&solution.lambda[0], 0, 49U * sizeof(double));
  int exitg1;
  do {
    exitg1 = 0;
    if (solution.state == -5) {
      __m128d r;
      double c;
      double minLambda;
      int i;
      int iAineq0;
      int idx;
      int k;
      boolean_T guard1;
      boolean_T guard2;
      guard1 = false;
      guard2 = false;
      if (subProblemChanged) {
        switch (activeSetChangeID) {
        case 1:
          localActiveConstrIdx = 10 * (workingset.nActiveConstr - 1);
          iyend = qrmanager.mrows;
          iAineq0 = qrmanager.ncols + 1;
          if (iyend <= iAineq0) {
            iAineq0 = iyend;
          }
          qrmanager.minRowCol = iAineq0;
          iAineq0 = 10 * qrmanager.ncols;
          if (qrmanager.mrows != 0) {
            iyend = iAineq0 + qrmanager.mrows;
            if (iAineq0 + 1 <= iyend) {
              std::memset(&qrmanager.QR[iAineq0], 0,
                          static_cast<unsigned int>(iyend - iAineq0) *
                              sizeof(double));
            }
            i = 10 * (qrmanager.mrows - 1) + 1;
            for (iyend = 1; iyend <= i; iyend += 10) {
              c = 0.0;
              k = (iyend + qrmanager.mrows) - 1;
              for (idx = iyend; idx <= k; idx++) {
                c += qrmanager.Q[idx - 1] *
                     workingset.ATwset[(localActiveConstrIdx + idx) - iyend];
              }
              k = iAineq0 + div_nde_s32_floor(iyend - 1);
              qrmanager.QR[k] += c;
            }
          }
          qrmanager.ncols++;
          i = qrmanager.ncols - 1;
          qrmanager.jpvt[i] = qrmanager.ncols;
          for (idx = qrmanager.mrows - 2; idx + 2 > qrmanager.ncols; idx--) {
            k = idx + 10 * i;
            temp = qrmanager.QR[k + 1];
            c = internal::blas::xrotg(qrmanager.QR[k], temp, s);
            qrmanager.QR[k + 1] = temp;
            iyend = 10 * idx;
            iAineq0 = qrmanager.mrows;
            if (qrmanager.mrows >= 1) {
              for (k = 0; k < iAineq0; k++) {
                localActiveConstrIdx = iyend + k;
                minLambda = qrmanager.Q[localActiveConstrIdx + 10];
                temp = c * qrmanager.Q[localActiveConstrIdx] + s * minLambda;
                qrmanager.Q[localActiveConstrIdx + 10] =
                    c * minLambda - s * qrmanager.Q[localActiveConstrIdx];
                qrmanager.Q[localActiveConstrIdx] = temp;
              }
            }
          }
          break;
        case -1:
          QRManager::deleteColMoveEnd(qrmanager, globalActiveConstrIdx);
          break;
        default:
          QRManager::factorQR(qrmanager, workingset.ATwset, nVar,
                              workingset.nActiveConstr);
          QRManager::computeQ_(qrmanager, qrmanager.mrows);
          break;
        }
        compute_deltax(H, solution, memspace, qrmanager, cholmanager,
                       objective);
        if (solution.state != -5) {
          exitg1 = 1;
        } else if ((internal::blas::xnrm2(nVar, solution.searchDir) <
                    options_StepTolerance) ||
                   (workingset.nActiveConstr >= nVar)) {
          guard2 = true;
        } else {
          updateFval = (TYPE == 5);
          if (updateFval || runTimeOptions_RemainFeasible) {
            minLambda = feasibleratiotest(
                solution.xstar, solution.searchDir, memspace.workspace_float,
                workingset.nVar, workingset.Aineq, workingset.bineq,
                workingset.lb, workingset.ub, workingset.indexLB,
                workingset.indexUB, workingset.sizes, workingset.isActiveIdx,
                workingset.isActiveConstr, workingset.nWConstr, updateFval,
                newBlocking, iyend, localActiveConstrIdx);
          } else {
            minLambda = ratiotest(
                solution.xstar, solution.searchDir, memspace.workspace_float,
                workingset.nVar, workingset.Aineq, workingset.bineq,
                workingset.lb, workingset.ub, workingset.indexLB,
                workingset.indexUB, workingset.sizes, workingset.isActiveIdx,
                workingset.isActiveConstr, workingset.nWConstr, tolDelta,
                newBlocking, iyend, localActiveConstrIdx);
          }
          if (newBlocking) {
            switch (iyend) {
            case 3:
              workingset.nWConstr[2]++;
              workingset.isActiveConstr[(workingset.isActiveIdx[2] +
                                         localActiveConstrIdx) -
                                        2] = true;
              workingset.nActiveConstr++;
              workingset.Wid[workingset.nActiveConstr - 1] = 3;
              workingset.Wlocalidx[workingset.nActiveConstr - 1] =
                  localActiveConstrIdx;
              iAineq0 = 10 * (localActiveConstrIdx - 1);
              iyend = 10 * (workingset.nActiveConstr - 1);
              i = workingset.nVar - 1;
              for (idx = 0; idx <= i; idx++) {
                workingset.ATwset[iyend + idx] =
                    workingset.Aineq[iAineq0 + idx];
              }
              workingset.bwset[workingset.nActiveConstr - 1] =
                  workingset.bineq[localActiveConstrIdx - 1];
              break;
            case 4:
              WorkingSet::addBoundToActiveSetMatrix_(workingset, 4,
                                                     localActiveConstrIdx);
              break;
            default:
              WorkingSet::addBoundToActiveSetMatrix_(workingset, 5,
                                                     localActiveConstrIdx);
              break;
            }
            activeSetChangeID = 1;
          } else {
            if (objective.objtype == 5) {
              if (internal::blas::xnrm2(objective.nvar, solution.searchDir) >
                  100.0 * static_cast<double>(objective.nvar) *
                      1.4901161193847656E-8) {
                solution.state = 3;
              } else {
                solution.state = 4;
              }
            }
            subProblemChanged = false;
            if (workingset.nActiveConstr == 0) {
              solution.state = 1;
            }
          }
          if (!(minLambda == 0.0)) {
            iyend = nVar - 1;
            iAineq0 = (nVar / 2) << 1;
            localActiveConstrIdx = iAineq0 - 2;
            for (k = 0; k <= localActiveConstrIdx; k += 2) {
              __m128d r1;
              r = _mm_loadu_pd(&solution.searchDir[k]);
              r1 = _mm_loadu_pd(&solution.xstar[k]);
              _mm_storeu_pd(
                  &solution.xstar[k],
                  _mm_add_pd(r1, _mm_mul_pd(_mm_set1_pd(minLambda), r)));
            }
            for (k = iAineq0; k <= iyend; k++) {
              solution.xstar[k] += minLambda * solution.searchDir[k];
            }
          }
          Objective::computeGrad_StoreHx(objective, H, f, solution.xstar);
          updateFval = true;
          guard1 = true;
        }
      } else {
        if (nVar - 1 >= 0) {
          std::memset(&solution.searchDir[0], 0,
                      static_cast<unsigned int>(nVar) * sizeof(double));
        }
        guard2 = true;
      }
      if (guard2) {
        int nActiveConstr;
        nActiveConstr = qrmanager.ncols;
        if (qrmanager.ncols > 0) {
          boolean_T b_guard1;
          b_guard1 = false;
          if (objective.objtype != 4) {
            minLambda = 100.0 * static_cast<double>(qrmanager.mrows) *
                        2.2204460492503131E-16;
            if ((qrmanager.mrows > 0) && (qrmanager.ncols > 0)) {
              updateFval = true;
            } else {
              updateFval = false;
            }
            if (updateFval) {
              boolean_T b_guard2;
              idx = qrmanager.ncols;
              b_guard2 = false;
              if (qrmanager.mrows < qrmanager.ncols) {
                iyend = qrmanager.mrows + 10 * (qrmanager.ncols - 1);
                while ((idx > qrmanager.mrows) &&
                       (std::abs(qrmanager.QR[iyend - 1]) >= minLambda)) {
                  idx--;
                  iyend -= 10;
                }
                updateFval = (idx == qrmanager.mrows);
                if (updateFval) {
                  b_guard2 = true;
                }
              } else {
                b_guard2 = true;
              }
              if (b_guard2) {
                iyend = idx + 10 * (idx - 1);
                while ((idx >= 1) &&
                       (std::abs(qrmanager.QR[iyend - 1]) >= minLambda)) {
                  idx--;
                  iyend -= 11;
                }
                updateFval = (idx == 0);
              }
            }
            if (!updateFval) {
              solution.state = -7;
            } else {
              b_guard1 = true;
            }
          } else {
            b_guard1 = true;
          }
          if (b_guard1) {
            if (qrmanager.mrows != 0) {
              iyend = qrmanager.ncols;
              std::memset(&memspace.workspace_float[0], 0,
                          static_cast<unsigned int>(iyend) * sizeof(double));
              i = 10 * (qrmanager.ncols - 1) + 1;
              for (iyend = 1; iyend <= i; iyend += 10) {
                c = 0.0;
                k = (iyend + qrmanager.mrows) - 1;
                for (idx = iyend; idx <= k; idx++) {
                  c += qrmanager.Q[idx - 1] * objective.grad[idx - iyend];
                }
                k = div_nde_s32_floor(iyend - 1);
                memspace.workspace_float[k] += c;
              }
            }
            for (localActiveConstrIdx = nActiveConstr;
                 localActiveConstrIdx >= 1; localActiveConstrIdx--) {
              iyend =
                  (localActiveConstrIdx + (localActiveConstrIdx - 1) * 10) - 1;
              memspace.workspace_float[localActiveConstrIdx - 1] /=
                  qrmanager.QR[iyend];
              for (k = 0; k <= localActiveConstrIdx - 2; k++) {
                iAineq0 = (localActiveConstrIdx - k) - 2;
                memspace.workspace_float[iAineq0] -=
                    memspace.workspace_float[localActiveConstrIdx - 1] *
                    qrmanager.QR[(iyend - k) - 1];
              }
            }
            iAineq0 = nActiveConstr / 2 * 2;
            localActiveConstrIdx = iAineq0 - 2;
            for (idx = 0; idx <= localActiveConstrIdx; idx += 2) {
              r = _mm_loadu_pd(&memspace.workspace_float[idx]);
              r = _mm_mul_pd(r, _mm_set1_pd(-1.0));
              _mm_storeu_pd(&solution.lambda[idx], r);
            }
            for (idx = iAineq0; idx < nActiveConstr; idx++) {
              solution.lambda[idx] = -memspace.workspace_float[idx];
            }
          }
        }
        if ((solution.state != -7) || (workingset.nActiveConstr > nVar)) {
          iyend = 0;
          minLambda = 0.0 * runTimeOptions_ProbRelTolFactor *
                      static_cast<double>(TYPE != 5);
          i = (workingset.nWConstr[0] + workingset.nWConstr[1]) + 1;
          k = workingset.nActiveConstr;
          for (idx = i; idx <= k; idx++) {
            temp = solution.lambda[idx - 1];
            if (temp < minLambda) {
              minLambda = temp;
              iyend = idx;
            }
          }
          if (iyend == 0) {
            solution.state = 1;
          } else {
            activeSetChangeID = -1;
            globalActiveConstrIdx = iyend;
            subProblemChanged = true;
            WorkingSet::removeConstr(workingset, iyend);
            if (iyend < workingset.nActiveConstr + 1) {
              solution.lambda[iyend - 1] =
                  solution.lambda[workingset.nActiveConstr];
            }
            solution.lambda[workingset.nActiveConstr] = 0.0;
          }
        } else {
          iyend = workingset.nActiveConstr;
          activeSetChangeID = 0;
          globalActiveConstrIdx = workingset.nActiveConstr;
          subProblemChanged = true;
          WorkingSet::removeConstr(workingset, workingset.nActiveConstr);
          solution.lambda[iyend - 1] = 0.0;
        }
        updateFval = false;
        guard1 = true;
      }
      if (guard1) {
        solution.iterations++;
        if ((solution.iterations >= 50) &&
            ((solution.state != 1) || (objective.objtype == 5))) {
          solution.state = 0;
        }
        if (solution.iterations - solution.iterations / 50 * 50 == 0) {
          solution.maxConstr =
              WorkingSet::maxConstraintViolation(workingset, solution.xstar);
          minLambda = solution.maxConstr;
          if (objective.objtype == 5) {
            minLambda = solution.maxConstr - solution.xstar[objective.nvar - 1];
          }
          if (minLambda > 1.0E-6 * runTimeOptions_ConstrRelTolFactor) {
            i = static_cast<unsigned char>(objective.nvar);
            if (i - 1 >= 0) {
              std::copy(&solution.xstar[0], &solution.xstar[i],
                        &solution.searchDir[0]);
            }
            newBlocking = initialize::feasibleX0ForWorkingSet(
                memspace.workspace_float, solution.searchDir, workingset,
                qrmanager);
            if ((!newBlocking) && (solution.state != 0)) {
              solution.state = -2;
            }
            activeSetChangeID = 0;
            minLambda = WorkingSet::maxConstraintViolation(workingset,
                                                           solution.searchDir);
            if (minLambda < solution.maxConstr) {
              if (i - 1 >= 0) {
                std::copy(&solution.searchDir[0], &solution.searchDir[i],
                          &solution.xstar[0]);
              }
              solution.maxConstr = minLambda;
            }
          }
        }
        if (updateFval) {
          solution.fstar = Objective::computeFval_ReuseHx(
              objective, memspace.workspace_float, f, solution.xstar);
          if ((solution.fstar < options_ObjectiveLimit) &&
              ((solution.state != 0) || (objective.objtype != 5))) {
            solution.state = 2;
          }
        }
      }
    } else {
      if (!updateFval) {
        solution.fstar = Objective::computeFval_ReuseHx(
            objective, memspace.workspace_float, f, solution.xstar);
      }
      exitg1 = 1;
    }
  } while (exitg1 == 0);
}

} // namespace qpactiveset
} // namespace coder
} // namespace optim
} // namespace coder

//
// File trailer for iterate.cpp
//
// [EOF]
//
