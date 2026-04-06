//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: ComputeNumDependentEq_.cpp
//
// MATLAB Coder version            : 24.1
// C/C++ source code generated on  : 10-Sep-2025 16:14:33
//

// Include Files
#include "ComputeNumDependentEq_.h"
#include "computeQ_.h"
#include "factorQRE.h"
#include "rt_nonfinite.h"
#include "wbqp_solve_internal_types.h"
#include <cmath>
#include <cstring>

// Function Definitions
//
// Arguments    : d_struct_T &qrmanager
//                const double beqf[49]
//                int mConstr
//                int nVar
// Return Type  : int
//
namespace coder {
namespace optim {
namespace coder {
namespace qpactiveset {
namespace initialize {
int ComputeNumDependentEq_(d_struct_T &qrmanager, const double beqf[49],
                           int mConstr, int nVar)
{
  double tol;
  int numDependent;
  int totalRank;
  numDependent = mConstr - nVar;
  if (numDependent <= 0) {
    numDependent = 0;
  }
  totalRank = static_cast<unsigned char>(nVar);
  std::memset(&qrmanager.jpvt[0], 0,
              static_cast<unsigned int>(totalRank) * sizeof(int));
  QRManager::factorQRE(qrmanager, mConstr, nVar);
  tol = 100.0 * static_cast<double>(nVar) * 2.2204460492503131E-16;
  if (nVar <= mConstr) {
    totalRank = nVar;
  } else {
    totalRank = mConstr;
  }
  totalRank += 10 * (totalRank - 1);
  while ((totalRank > 0) && (std::abs(qrmanager.QR[totalRank - 1]) < tol)) {
    totalRank -= 11;
    numDependent++;
  }
  if (numDependent > 0) {
    boolean_T exitg1;
    QRManager::computeQ_(qrmanager, qrmanager.mrows);
    totalRank = 0;
    exitg1 = false;
    while ((!exitg1) && (totalRank <= numDependent - 1)) {
      double qtb;
      int ix;
      ix = 10 * ((mConstr - totalRank) - 1);
      qtb = 0.0;
      for (int k{0}; k < mConstr; k++) {
        qtb += qrmanager.Q[ix + k] * beqf[k];
      }
      if (std::abs(qtb) >= tol) {
        numDependent = -1;
        exitg1 = true;
      } else {
        totalRank++;
      }
    }
  }
  return numDependent;
}

} // namespace initialize
} // namespace qpactiveset
} // namespace coder
} // namespace optim
} // namespace coder

//
// File trailer for ComputeNumDependentEq_.cpp
//
// [EOF]
//
