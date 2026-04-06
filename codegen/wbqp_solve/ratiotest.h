//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: ratiotest.h
//
// MATLAB Coder version            : 24.1
// C/C++ source code generated on  : 10-Sep-2025 16:14:33
//

#ifndef RATIOTEST_H
#define RATIOTEST_H

// Include Files
#include "rtwtypes.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
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
          boolean_T &newBlocking, int &constrType, int &constrIdx);

}
} // namespace coder
} // namespace optim
} // namespace coder

#endif
//
// File trailer for ratiotest.h
//
// [EOF]
//
