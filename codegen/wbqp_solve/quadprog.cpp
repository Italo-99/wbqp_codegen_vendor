//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: quadprog.cpp
//
// MATLAB Coder version            : 24.1
// C/C++ source code generated on  : 10-Sep-2025 16:14:33
//

// Include Files
#include "quadprog.h"
#include "computeFirstOrderOpt.h"
#include "computeFval.h"
#include "driver.h"
#include "linearForm_.h"
#include "maxConstraintViolation.h"
#include "rt_nonfinite.h"
#include "setProblemType.h"
#include "wbqp_solve_internal_types.h"
#include <algorithm>
#include <cmath>
#include <cstring>
#include <emmintrin.h>

// Function Definitions
//
// Arguments    : const double H[81]
//                const double f[9]
//                const double bineq[30]
//                const double lb[9]
//                const double ub[9]
//                double x0[9]
//                double &exitflag
//                char output_algorithm[10]
//                double &output_firstorderopt
//                double &output_constrviolation
//                double &output_iterations
// Return Type  : double
//
namespace coder {
double quadprog(const double H[81], const double f[9], const double bineq[30],
                const double lb[9], const double ub[9], double x0[9],
                double &exitflag, char output_algorithm[10],
                double &output_firstorderopt, double &output_constrviolation,
                double &output_iterations)
{
  static const signed char b_iv[270]{
      1,  0, 0,  0, 0,  0, 0,  0, 0,  -1, 0, 0,  0, 0,  0, 0,  0, 0,  1, 0,
      0,  0, 0,  0, -1, 0, 0,  0, 0,  0,  0, 1,  0, 0,  0, 0,  0, 0,  0, 0,
      -1, 0, 0,  0, 0,  0, 0,  0, 0,  1,  0, 0,  0, 0,  0, -1, 0, 0,  0, 0,
      0,  0, 1,  0, 0,  0, 0,  0, 0,  0,  0, -1, 0, 0,  0, 0,  0, 0,  0, 0,
      1,  0, 0,  0, 0,  0, -1, 0, 0,  0,  0, 0,  0, 1,  0, 0,  0, 0,  0, 0,
      0,  0, -1, 0, 0,  0, 0,  0, 0,  0,  0, 1,  0, 0,  0, 0,  0, -1, 0, 0,
      0,  0, 0,  0, 1,  0, 0,  0, 0,  0,  0, 0,  0, -1, 0, 0,  0, 0,  0, 0,
      0,  0, 1,  0, 0,  0, 0,  0, -1, 0,  0, 0,  0, 0,  0, 1,  0, 0,  0, 0,
      0,  0, 0,  0, -1, 0, 0,  0, 0,  0,  0, 0,  0, 1,  0, 0,  0, 0,  0, -1,
      0,  0, 0,  0, 0,  0, 1,  0, 0,  0,  0, 0,  0, 0,  0, -1, 0, 0,  0, 0,
      0,  0, 0,  0, 0,  0, 0,  0, 0,  0,  0, 0,  0, 0,  0, 0,  0, 1,  0, 0,
      0,  0, 0,  0, 0,  0, -1, 0, 0,  0,  0, 0,  0, 0,  0, 0,  0, 0,  0, 0,
      0,  0, 0,  0, 0,  0, 0,  0, 1,  0,  0, 0,  0, 0,  0, 0,  0, -1, 0, 0,
      0,  0, 0,  0, 0,  0, 0,  0, 0,  0};
  static const char cv[10]{'a', 'c', 't', 'i', 'v', 'e', '-', 's', 'e', 't'};
  static const char t2_algorithm[10]{'a', 'c', 't', 'i', 'v',
                                     'e', '-', 's', 'e', 't'};
  b_struct_T QPObjective;
  c_struct_T CholRegManager;
  d_struct_T QRManager;
  e_struct_T memspace;
  f_struct_T WorkingSet;
  struct_T solution;
  double fval;
  int i;
  signed char obj_tmp[5];
  boolean_T exitg1;
  exitflag = rtInf;
  i = 0;
  exitg1 = false;
  while ((!exitg1) && (i < 9)) {
    if (lb[i] > ub[i]) {
      exitflag = -2.0;
      exitg1 = true;
    } else {
      i++;
    }
  }
  if (exitflag == -2.0) {
    fval = rtInf;
    for (int b_i{0}; b_i < 10; b_i++) {
      output_algorithm[b_i] = t2_algorithm[b_i];
    }
    output_firstorderopt = rtInf;
    output_constrviolation = rtInf;
    output_iterations = 0.0;
  } else {
    __m128d r;
    double H_infnrm;
    double colSum;
    double f_infnrm;
    double tol;
    int b_i;
    int mFixed;
    int mLB;
    int mUB;
    solution.fstar = 0.0;
    solution.firstorderopt = 0.0;
    std::memset(&solution.lambda[0], 0, 49U * sizeof(double));
    solution.state = 0;
    solution.maxConstr = 0.0;
    solution.iterations = 0;
    std::memset(&solution.searchDir[0], 0, 10U * sizeof(double));
    std::copy(&x0[0], &x0[9], &solution.xstar[0]);
    CholRegManager.ldm = 10;
    CholRegManager.ndims = 0;
    CholRegManager.info = 0;
    CholRegManager.ConvexCheck = true;
    CholRegManager.regTol_ = 0.0;
    CholRegManager.scaleFactor = 100.0;
    WorkingSet.nVar = 9;
    WorkingSet.nVarOrig = 9;
    WorkingSet.nVarMax = 10;
    WorkingSet.ldA = 10;
    std::memset(&WorkingSet.Aineq[0], 0, 300U * sizeof(double));
    std::memset(&WorkingSet.bineq[0], 0, 30U * sizeof(double));
    std::memset(&WorkingSet.lb[0], 0, 10U * sizeof(double));
    std::memset(&WorkingSet.ub[0], 0, 10U * sizeof(double));
    WorkingSet.mEqRemoved = 0;
    std::memset(&WorkingSet.ATwset[0], 0, 490U * sizeof(double));
    WorkingSet.nActiveConstr = 0;
    std::memset(&WorkingSet.bwset[0], 0, 49U * sizeof(double));
    std::memset(&WorkingSet.maxConstrWorkspace[0], 0, 49U * sizeof(double));
    std::memset(&WorkingSet.Wid[0], 0, 49U * sizeof(int));
    std::memset(&WorkingSet.Wlocalidx[0], 0, 49U * sizeof(int));
    for (i = 0; i < 49; i++) {
      WorkingSet.isActiveConstr[i] = false;
    }
    for (i = 0; i < 5; i++) {
      WorkingSet.nWConstr[i] = 0;
    }
    WorkingSet.probType = 3;
    WorkingSet.SLACK0 = 1.0E-5;
    for (i = 0; i < 10; i++) {
      WorkingSet.indexLB[i] = 0;
      WorkingSet.indexUB[i] = 0;
      WorkingSet.indexFixed[i] = 0;
    }
    mLB = 30;
    mUB = 0;
    mFixed = 0;
    for (int idx{0}; idx < 9; idx++) {
      boolean_T guard1;
      colSum = lb[idx];
      guard1 = false;
      if ((!std::isinf(colSum)) && (!std::isnan(colSum))) {
        if (std::abs(colSum - ub[idx]) < 1.0E-6) {
          mFixed++;
          WorkingSet.indexFixed[mFixed - 1] = idx + 1;
        } else {
          mLB++;
          WorkingSet.indexLB[mLB - 31] = idx + 1;
          guard1 = true;
        }
      } else {
        guard1 = true;
      }
      if (guard1) {
        colSum = ub[idx];
        if ((!std::isinf(colSum)) && (!std::isnan(colSum))) {
          mUB++;
          WorkingSet.indexUB[mUB - 1] = idx + 1;
        }
      }
    }
    i = (mLB + mUB) + mFixed;
    WorkingSet.mConstr = i;
    WorkingSet.mConstrOrig = i;
    WorkingSet.mConstrMax = 49;
    obj_tmp[0] = static_cast<signed char>(mFixed);
    obj_tmp[1] = 0;
    obj_tmp[2] = 30;
    obj_tmp[3] = static_cast<signed char>(mLB - 30);
    obj_tmp[4] = static_cast<signed char>(mUB);
    WorkingSet.sizesPhaseOne[0] = mFixed;
    WorkingSet.sizesPhaseOne[1] = 0;
    WorkingSet.sizesPhaseOne[2] = 30;
    WorkingSet.sizesPhaseOne[3] = mLB - 29;
    WorkingSet.sizesPhaseOne[4] = mUB;
    WorkingSet.sizesRegularized[0] = mFixed;
    WorkingSet.sizesRegularized[1] = 0;
    WorkingSet.sizesRegularized[2] = 30;
    WorkingSet.sizesRegularized[3] = mLB;
    WorkingSet.sizesRegularized[4] = mUB;
    WorkingSet.sizesRegPhaseOne[0] = mFixed;
    WorkingSet.sizesRegPhaseOne[1] = 0;
    WorkingSet.sizesRegPhaseOne[2] = 30;
    WorkingSet.sizesRegPhaseOne[3] = mLB + 1;
    WorkingSet.sizesRegPhaseOne[4] = mUB;
    WorkingSet.isActiveIdxRegPhaseOne[0] = 1;
    WorkingSet.isActiveIdxRegPhaseOne[1] = mFixed;
    WorkingSet.isActiveIdxRegPhaseOne[2] = 0;
    WorkingSet.isActiveIdxRegPhaseOne[3] = 30;
    WorkingSet.isActiveIdxRegPhaseOne[4] = mLB - 30;
    WorkingSet.isActiveIdxRegPhaseOne[5] = mUB;
    for (i = 0; i < 5; i++) {
      signed char i1;
      i1 = obj_tmp[i];
      WorkingSet.sizes[i] = i1;
      WorkingSet.sizesNormal[i] = i1;
      WorkingSet.isActiveIdxRegPhaseOne[i + 1] +=
          WorkingSet.isActiveIdxRegPhaseOne[i];
    }
    for (b_i = 0; b_i < 6; b_i++) {
      WorkingSet.isActiveIdx[b_i] = WorkingSet.isActiveIdxRegPhaseOne[b_i];
      WorkingSet.isActiveIdxNormal[b_i] =
          WorkingSet.isActiveIdxRegPhaseOne[b_i];
    }
    WorkingSet.isActiveIdxRegPhaseOne[0] = 1;
    WorkingSet.isActiveIdxRegPhaseOne[1] = mFixed;
    WorkingSet.isActiveIdxRegPhaseOne[2] = 0;
    WorkingSet.isActiveIdxRegPhaseOne[3] = 30;
    WorkingSet.isActiveIdxRegPhaseOne[4] = mLB - 29;
    WorkingSet.isActiveIdxRegPhaseOne[5] = mUB;
    for (i = 0; i < 5; i++) {
      WorkingSet.isActiveIdxRegPhaseOne[i + 1] +=
          WorkingSet.isActiveIdxRegPhaseOne[i];
    }
    for (b_i = 0; b_i < 6; b_i++) {
      WorkingSet.isActiveIdxPhaseOne[b_i] =
          WorkingSet.isActiveIdxRegPhaseOne[b_i];
    }
    WorkingSet.isActiveIdxRegPhaseOne[0] = 1;
    WorkingSet.isActiveIdxRegPhaseOne[1] = mFixed;
    WorkingSet.isActiveIdxRegPhaseOne[2] = 0;
    WorkingSet.isActiveIdxRegPhaseOne[3] = 30;
    WorkingSet.isActiveIdxRegPhaseOne[4] = mLB;
    WorkingSet.isActiveIdxRegPhaseOne[5] = mUB;
    for (i = 0; i < 5; i++) {
      WorkingSet.isActiveIdxRegPhaseOne[i + 1] +=
          WorkingSet.isActiveIdxRegPhaseOne[i];
    }
    for (b_i = 0; b_i < 6; b_i++) {
      WorkingSet.isActiveIdxRegularized[b_i] =
          WorkingSet.isActiveIdxRegPhaseOne[b_i];
    }
    WorkingSet.isActiveIdxRegPhaseOne[0] = 1;
    WorkingSet.isActiveIdxRegPhaseOne[1] = mFixed;
    WorkingSet.isActiveIdxRegPhaseOne[2] = 0;
    WorkingSet.isActiveIdxRegPhaseOne[3] = 30;
    WorkingSet.isActiveIdxRegPhaseOne[4] = mLB + 1;
    WorkingSet.isActiveIdxRegPhaseOne[5] = mUB;
    for (i = 0; i < 5; i++) {
      WorkingSet.isActiveIdxRegPhaseOne[i + 1] +=
          WorkingSet.isActiveIdxRegPhaseOne[i];
    }
    for (mLB = 0; mLB < 30; mLB++) {
      for (mUB = 0; mUB < 9; mUB++) {
        WorkingSet.Aineq[mUB + 10 * mLB] = b_iv[mLB + 30 * mUB];
      }
      WorkingSet.bineq[mLB] = bineq[mLB];
    }
    r = _mm_set1_pd(-1.0);
    _mm_storeu_pd(&WorkingSet.lb[0], _mm_mul_pd(_mm_loadu_pd(&lb[0]), r));
    _mm_storeu_pd(&WorkingSet.ub[0], _mm_loadu_pd(&ub[0]));
    _mm_storeu_pd(&WorkingSet.lb[2], _mm_mul_pd(_mm_loadu_pd(&lb[2]), r));
    _mm_storeu_pd(&WorkingSet.ub[2], _mm_loadu_pd(&ub[2]));
    _mm_storeu_pd(&WorkingSet.lb[4], _mm_mul_pd(_mm_loadu_pd(&lb[4]), r));
    _mm_storeu_pd(&WorkingSet.ub[4], _mm_loadu_pd(&ub[4]));
    _mm_storeu_pd(&WorkingSet.lb[6], _mm_mul_pd(_mm_loadu_pd(&lb[6]), r));
    _mm_storeu_pd(&WorkingSet.ub[6], _mm_loadu_pd(&ub[6]));
    WorkingSet.lb[8] = -lb[8];
    WorkingSet.ub[8] = ub[8];
    optim::coder::qpactiveset::WorkingSet::setProblemType(WorkingSet, 3);
    i = WorkingSet.isActiveIdx[2];
    for (int idx{i}; idx < 50; idx++) {
      WorkingSet.isActiveConstr[idx - 1] = false;
    }
    WorkingSet.nWConstr[0] = WorkingSet.sizes[0];
    WorkingSet.nWConstr[1] = 0;
    WorkingSet.nWConstr[2] = 0;
    WorkingSet.nWConstr[3] = 0;
    WorkingSet.nWConstr[4] = 0;
    WorkingSet.nActiveConstr = WorkingSet.nWConstr[0];
    b_i = static_cast<unsigned char>(WorkingSet.sizes[0]);
    for (mFixed = 0; mFixed < b_i; mFixed++) {
      WorkingSet.Wid[mFixed] = 1;
      WorkingSet.Wlocalidx[mFixed] = mFixed + 1;
      WorkingSet.isActiveConstr[mFixed] = true;
      i = 10 * mFixed;
      mLB = WorkingSet.indexFixed[mFixed];
      if (mLB - 2 >= 0) {
        std::memset(&WorkingSet.ATwset[i], 0,
                    static_cast<unsigned int>(((mLB + i) - i) - 1) *
                        sizeof(double));
      }
      WorkingSet.ATwset[(WorkingSet.indexFixed[mFixed] + i) - 1] = 1.0;
      mLB = WorkingSet.indexFixed[mFixed] + 1;
      mUB = WorkingSet.nVar;
      if (mLB <= mUB) {
        std::memset(&WorkingSet.ATwset[(mLB + i) + -1], 0,
                    static_cast<unsigned int>((((mUB + i) - mLB) - i) + 1) *
                        sizeof(double));
      }
      WorkingSet.bwset[mFixed] =
          WorkingSet.ub[WorkingSet.indexFixed[mFixed] - 1];
    }
    WorkingSet.SLACK0 = 0.0;
    tol = 1.0;
    for (mLB = 0; mLB < 30; mLB++) {
      colSum = 0.0;
      i = 10 * mLB;
      for (mUB = 0; mUB < 9; mUB++) {
        colSum += std::abs(WorkingSet.Aineq[mUB + i]);
      }
      tol = std::fmax(tol, colSum);
    }
    H_infnrm = 0.0;
    f_infnrm = 0.0;
    for (mLB = 0; mLB < 9; mLB++) {
      colSum = 0.0;
      for (mUB = 0; mUB < 9; mUB++) {
        colSum += std::abs(H[mUB + 9 * mLB]);
      }
      H_infnrm = std::fmax(H_infnrm, colSum);
      f_infnrm = std::fmax(f_infnrm, std::abs(f[mLB]));
    }
    optim::coder::qpactiveset::driver(
        H, f, solution, memspace, WorkingSet, CholRegManager, tol,
        std::fmax(std::fmax(tol, f_infnrm), H_infnrm), QRManager, QPObjective);
    std::copy(&solution.xstar[0], &solution.xstar[9], &x0[0]);
    if (solution.state > 0) {
      fval = solution.fstar;
    } else {
      fval = optim::coder::qpactiveset::Objective::computeFval(
          QPObjective, memspace.workspace_float, H, f, solution.xstar);
    }
    switch (solution.state) {
    case 2:
      solution.state = -3;
      break;
    case -3:
      solution.state = -2;
      break;
    case 4:
      solution.state = -2;
      break;
    }
    exitflag = solution.state;
    if (solution.state == -2) {
      solution.firstorderopt = rtInf;
    } else if (solution.state <= 0) {
      solution.maxConstr =
          optim::coder::qpactiveset::WorkingSet::maxConstraintViolation(
              WorkingSet, solution.xstar);
      if (solution.maxConstr <= 1.0E-6 * tol) {
        switch (QPObjective.objtype) {
        case 5:
          i = QPObjective.nvar;
          if (i - 2 >= 0) {
            std::memset(&QPObjective.grad[0], 0,
                        static_cast<unsigned int>(i - 1) * sizeof(double));
          }
          QPObjective.grad[QPObjective.nvar - 1] = QPObjective.gammaScalar;
          break;
        case 3:
          optim::coder::qpactiveset::Objective::b_linearForm_(
              QPObjective.hasLinear, QPObjective.nvar, QPObjective.grad, H, f,
              solution.xstar);
          break;
        default:
          optim::coder::qpactiveset::Objective::b_linearForm_(
              QPObjective.hasLinear, QPObjective.nvar, QPObjective.grad, H, f,
              solution.xstar);
          b_i = QPObjective.nvar + 1;
          i = ((((9 - QPObjective.nvar) / 2) << 1) + QPObjective.nvar) + 1;
          mLB = i - 2;
          for (int idx{b_i}; idx <= mLB; idx += 2) {
            r = _mm_loadu_pd(&solution.xstar[idx - 1]);
            _mm_storeu_pd(&QPObjective.grad[idx - 1],
                          _mm_mul_pd(_mm_set1_pd(0.0), r));
          }
          for (int idx{i}; idx < 10; idx++) {
            QPObjective.grad[idx - 1] = 0.0 * solution.xstar[idx - 1];
          }
          break;
        }
        optim::coder::qpactiveset::parseoutput::computeFirstOrderOpt(
            solution, QPObjective, WorkingSet.nVar, WorkingSet.ATwset,
            WorkingSet.nActiveConstr, memspace.workspace_float);
      } else {
        solution.firstorderopt = rtInf;
      }
    }
    for (b_i = 0; b_i < 10; b_i++) {
      output_algorithm[b_i] = cv[b_i];
    }
    output_firstorderopt = solution.firstorderopt;
    output_constrviolation = std::fmax(0.0, solution.maxConstr);
    output_iterations = solution.iterations;
  }
  return fval;
}

} // namespace coder

//
// File trailer for quadprog.cpp
//
// [EOF]
//
