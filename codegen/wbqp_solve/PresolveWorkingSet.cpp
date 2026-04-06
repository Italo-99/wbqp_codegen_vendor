//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: PresolveWorkingSet.cpp
//
// MATLAB Coder version            : 24.1
// C/C++ source code generated on  : 10-Sep-2025 16:14:33
//

// Include Files
#include "PresolveWorkingSet.h"
#include "ComputeNumDependentEq_.h"
#include "RemoveDependentIneq_.h"
#include "countsort.h"
#include "factorQRE.h"
#include "feasibleX0ForWorkingSet.h"
#include "maxConstraintViolation.h"
#include "removeEqConstr.h"
#include "rt_nonfinite.h"
#include "wbqp_solve_internal_types.h"
#include <algorithm>
#include <cstring>

// Function Definitions
//
// Arguments    : struct_T &solution
//                e_struct_T &memspace
//                f_struct_T &workingset
//                d_struct_T &qrmanager
// Return Type  : void
//
namespace coder {
namespace optim {
namespace coder {
namespace qpactiveset {
namespace initialize {
void PresolveWorkingSet(struct_T &solution, e_struct_T &memspace,
                        f_struct_T &workingset, d_struct_T &qrmanager)
{
  int idxEndIneq;
  int idxStartIneq;
  int idx_row;
  int mWorkingFixed;
  int nDepInd;
  solution.state = 82;
  qrmanager.ldq = 10;
  std::memset(&qrmanager.QR[0], 0, 490U * sizeof(double));
  std::memset(&qrmanager.Q[0], 0, 100U * sizeof(double));
  std::memset(&qrmanager.jpvt[0], 0, 49U * sizeof(int));
  qrmanager.mrows = 0;
  qrmanager.ncols = 0;
  std::memset(&qrmanager.tau[0], 0, 10U * sizeof(double));
  qrmanager.minRowCol = 0;
  qrmanager.usedPivoting = false;
  mWorkingFixed = workingset.nWConstr[0];
  nDepInd = 0;
  if (workingset.nWConstr[0] > 0) {
    idxStartIneq = static_cast<unsigned char>(workingset.nWConstr[0]);
    idxEndIneq = static_cast<unsigned char>(workingset.nVar);
    for (idx_row = 0; idx_row < idxStartIneq; idx_row++) {
      for (int idx_col{0}; idx_col < idxEndIneq; idx_col++) {
        qrmanager.QR[idx_row + 10 * idx_col] =
            workingset.ATwset[idx_col + 10 * idx_row];
      }
    }
    nDepInd = ComputeNumDependentEq_(qrmanager, workingset.bwset,
                                     workingset.nWConstr[0], workingset.nVar);
    if (nDepInd > 0) {
      for (int idx_col{0}; idx_col < idxStartIneq; idx_col++) {
        idx_row = 10 * idx_col;
        std::copy(
            &workingset.ATwset[idx_row],
            &workingset.ATwset[idx_row + ((idxEndIneq + idx_row) - idx_row)],
            &qrmanager.QR[idx_row]);
      }
      for (idxStartIneq = 0; idxStartIneq < mWorkingFixed; idxStartIneq++) {
        qrmanager.jpvt[idxStartIneq] = 1;
      }
      idxStartIneq = workingset.nWConstr[0] + 1;
      if (idxStartIneq <= mWorkingFixed) {
        std::memset(
            &qrmanager.jpvt[idxStartIneq + -1], 0,
            static_cast<unsigned int>((mWorkingFixed - idxStartIneq) + 1) *
                sizeof(int));
      }
      QRManager::factorQRE(qrmanager, workingset.nVar, workingset.nWConstr[0]);
      for (idxStartIneq = 0; idxStartIneq < nDepInd; idxStartIneq++) {
        memspace.workspace_int[idxStartIneq] =
            qrmanager.jpvt[(mWorkingFixed - nDepInd) + idxStartIneq];
      }
      utils::countsort(memspace.workspace_int, nDepInd, memspace.workspace_sort,
                       1, workingset.nWConstr[0]);
      for (idxStartIneq = nDepInd; idxStartIneq >= 1; idxStartIneq--) {
        WorkingSet::removeEqConstr(workingset,
                                   memspace.workspace_int[idxStartIneq - 1]);
      }
    }
  }
  if ((nDepInd != -1) && (workingset.nActiveConstr <= 10)) {
    boolean_T guard1;
    boolean_T okWorkingSet;
    RemoveDependentIneq_(workingset, qrmanager, memspace, 100.0);
    okWorkingSet = feasibleX0ForWorkingSet(
        memspace.workspace_float, solution.xstar, workingset, qrmanager);
    guard1 = false;
    if (!okWorkingSet) {
      RemoveDependentIneq_(workingset, qrmanager, memspace, 1000.0);
      okWorkingSet = feasibleX0ForWorkingSet(
          memspace.workspace_float, solution.xstar, workingset, qrmanager);
      if (!okWorkingSet) {
        solution.state = -7;
      } else {
        guard1 = true;
      }
    } else {
      guard1 = true;
    }
    if (guard1 &&
        (workingset.nWConstr[0] + workingset.nWConstr[1] == workingset.nVar)) {
      double constrViolation;
      constrViolation =
          WorkingSet::maxConstraintViolation(workingset, solution.xstar);
      if (constrViolation > 1.0E-6) {
        solution.state = -2;
      }
    }
  } else {
    solution.state = -3;
    idx_row = workingset.nWConstr[0] + workingset.nWConstr[1];
    idxStartIneq = idx_row + 1;
    idxEndIneq = workingset.nActiveConstr;
    for (nDepInd = idxStartIneq; nDepInd <= idxEndIneq; nDepInd++) {
      workingset.isActiveConstr
          [(workingset.isActiveIdx[workingset.Wid[nDepInd - 1] - 1] +
            workingset.Wlocalidx[nDepInd - 1]) -
           2] = false;
    }
    workingset.nWConstr[2] = 0;
    workingset.nWConstr[3] = 0;
    workingset.nWConstr[4] = 0;
    workingset.nActiveConstr = idx_row;
  }
}

//
// Arguments    : struct_T &solution
//                e_struct_T &memspace
//                f_struct_T &workingset
//                d_struct_T &qrmanager
// Return Type  : void
//
void b_PresolveWorkingSet(struct_T &solution, e_struct_T &memspace,
                          f_struct_T &workingset, d_struct_T &qrmanager)
{
  int idxEndIneq;
  int idxStartIneq;
  int mTotalWorkingEq_tmp_tmp;
  int mWorkingFixed;
  int nDepInd;
  solution.state = 82;
  mWorkingFixed = workingset.nWConstr[0];
  mTotalWorkingEq_tmp_tmp = workingset.nWConstr[0] + workingset.nWConstr[1];
  nDepInd = 0;
  if (mTotalWorkingEq_tmp_tmp > 0) {
    idxEndIneq = static_cast<unsigned char>(workingset.nVar);
    for (idxStartIneq = 0; idxStartIneq < mTotalWorkingEq_tmp_tmp;
         idxStartIneq++) {
      for (int idx_col{0}; idx_col < idxEndIneq; idx_col++) {
        qrmanager.QR[idxStartIneq + 10 * idx_col] =
            workingset.ATwset[idx_col + 10 * idxStartIneq];
      }
    }
    nDepInd = ComputeNumDependentEq_(qrmanager, workingset.bwset,
                                     mTotalWorkingEq_tmp_tmp, workingset.nVar);
    if (nDepInd > 0) {
      for (int idx_col{0}; idx_col < mTotalWorkingEq_tmp_tmp; idx_col++) {
        idxStartIneq = 10 * idx_col;
        std::copy(
            &workingset.ATwset[idxStartIneq],
            &workingset.ATwset[idxStartIneq +
                               ((idxEndIneq + idxStartIneq) - idxStartIneq)],
            &qrmanager.QR[idxStartIneq]);
      }
      for (idxStartIneq = 0; idxStartIneq < mWorkingFixed; idxStartIneq++) {
        qrmanager.jpvt[idxStartIneq] = 1;
      }
      idxEndIneq = workingset.nWConstr[0] + 1;
      if (idxEndIneq <= mTotalWorkingEq_tmp_tmp) {
        std::memset(&qrmanager.jpvt[idxEndIneq + -1], 0,
                    static_cast<unsigned int>(
                        (mTotalWorkingEq_tmp_tmp - idxEndIneq) + 1) *
                        sizeof(int));
      }
      QRManager::factorQRE(qrmanager, workingset.nVar, mTotalWorkingEq_tmp_tmp);
      for (idxStartIneq = 0; idxStartIneq < nDepInd; idxStartIneq++) {
        memspace.workspace_int[idxStartIneq] =
            qrmanager.jpvt[(mTotalWorkingEq_tmp_tmp - nDepInd) + idxStartIneq];
      }
      utils::countsort(memspace.workspace_int, nDepInd, memspace.workspace_sort,
                       1, mTotalWorkingEq_tmp_tmp);
      for (idxStartIneq = nDepInd; idxStartIneq >= 1; idxStartIneq--) {
        WorkingSet::removeEqConstr(workingset,
                                   memspace.workspace_int[idxStartIneq - 1]);
      }
    }
  }
  if ((nDepInd != -1) && (workingset.nActiveConstr <= 10)) {
    boolean_T guard1;
    boolean_T okWorkingSet;
    RemoveDependentIneq_(workingset, qrmanager, memspace, 100.0);
    okWorkingSet = feasibleX0ForWorkingSet(
        memspace.workspace_float, solution.xstar, workingset, qrmanager);
    guard1 = false;
    if (!okWorkingSet) {
      RemoveDependentIneq_(workingset, qrmanager, memspace, 1000.0);
      okWorkingSet = feasibleX0ForWorkingSet(
          memspace.workspace_float, solution.xstar, workingset, qrmanager);
      if (!okWorkingSet) {
        solution.state = -7;
      } else {
        guard1 = true;
      }
    } else {
      guard1 = true;
    }
    if (guard1 &&
        (workingset.nWConstr[0] + workingset.nWConstr[1] == workingset.nVar)) {
      double constrViolation;
      constrViolation =
          WorkingSet::maxConstraintViolation(workingset, solution.xstar);
      if (constrViolation > 1.0E-6) {
        solution.state = -2;
      }
    }
  } else {
    solution.state = -3;
    idxStartIneq = mTotalWorkingEq_tmp_tmp + 1;
    idxEndIneq = workingset.nActiveConstr;
    for (nDepInd = idxStartIneq; nDepInd <= idxEndIneq; nDepInd++) {
      workingset.isActiveConstr
          [(workingset.isActiveIdx[workingset.Wid[nDepInd - 1] - 1] +
            workingset.Wlocalidx[nDepInd - 1]) -
           2] = false;
    }
    workingset.nWConstr[2] = 0;
    workingset.nWConstr[3] = 0;
    workingset.nWConstr[4] = 0;
    workingset.nActiveConstr = mTotalWorkingEq_tmp_tmp;
  }
}

} // namespace initialize
} // namespace qpactiveset
} // namespace coder
} // namespace optim
} // namespace coder

//
// File trailer for PresolveWorkingSet.cpp
//
// [EOF]
//
