//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: RemoveDependentIneq_.cpp
//
// MATLAB Coder version            : 24.1
// C/C++ source code generated on  : 10-Sep-2025 16:14:33
//

// Include Files
#include "RemoveDependentIneq_.h"
#include "countsort.h"
#include "factorQRE.h"
#include "removeConstr.h"
#include "rt_nonfinite.h"
#include "wbqp_solve_internal_types.h"
#include <algorithm>
#include <cmath>
#include <cstring>

// Function Definitions
//
// Arguments    : f_struct_T &workingset
//                d_struct_T &qrmanager
//                e_struct_T &memspace
//                double tolfactor
// Return Type  : void
//
namespace coder {
namespace optim {
namespace coder {
namespace qpactiveset {
namespace initialize {
void RemoveDependentIneq_(f_struct_T &workingset, d_struct_T &qrmanager,
                          e_struct_T &memspace, double tolfactor)
{
  int nActiveConstr_tmp;
  int nFixedConstr;
  int nVar;
  nActiveConstr_tmp = workingset.nActiveConstr;
  nFixedConstr = workingset.nWConstr[0] + workingset.nWConstr[1];
  nVar = workingset.nVar;
  if ((workingset.nWConstr[2] + workingset.nWConstr[3]) +
          workingset.nWConstr[4] >
      0) {
    double tol;
    int idx;
    int idxDiag;
    int nDepIneq;
    tol = tolfactor * static_cast<double>(workingset.nVar) *
          2.2204460492503131E-16;
    for (idx = 0; idx < nFixedConstr; idx++) {
      qrmanager.jpvt[idx] = 1;
    }
    idxDiag = nFixedConstr + 1;
    if (idxDiag <= nActiveConstr_tmp) {
      std::memset(&qrmanager.jpvt[idxDiag + -1], 0,
                  static_cast<unsigned int>((nActiveConstr_tmp - idxDiag) + 1) *
                      sizeof(int));
    }
    for (idx = 0; idx < nActiveConstr_tmp; idx++) {
      nDepIneq = 10 * idx;
      idxDiag = static_cast<unsigned char>(nVar);
      std::copy(
          &workingset.ATwset[nDepIneq],
          &workingset.ATwset[nDepIneq + ((idxDiag + nDepIneq) - nDepIneq)],
          &qrmanager.QR[nDepIneq]);
    }
    QRManager::factorQRE(qrmanager, workingset.nVar, workingset.nActiveConstr);
    nDepIneq = 0;
    for (idx = workingset.nActiveConstr - 1; idx + 1 > nVar; idx--) {
      nDepIneq++;
      memspace.workspace_int[nDepIneq - 1] = qrmanager.jpvt[idx];
    }
    if (idx + 1 <= workingset.nVar) {
      idxDiag = idx + 10 * idx;
      while ((idx + 1 > nFixedConstr) &&
             (std::abs(qrmanager.QR[idxDiag]) < tol)) {
        nDepIneq++;
        memspace.workspace_int[nDepIneq - 1] = qrmanager.jpvt[idx];
        idx--;
        idxDiag -= 11;
      }
    }
    utils::countsort(memspace.workspace_int, nDepIneq, memspace.workspace_sort,
                     nFixedConstr + 1, workingset.nActiveConstr);
    for (idx = nDepIneq; idx >= 1; idx--) {
      WorkingSet::removeConstr(workingset, memspace.workspace_int[idx - 1]);
    }
  }
}

} // namespace initialize
} // namespace qpactiveset
} // namespace coder
} // namespace optim
} // namespace coder

//
// File trailer for RemoveDependentIneq_.cpp
//
// [EOF]
//
