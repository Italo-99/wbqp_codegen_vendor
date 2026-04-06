//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: computeFirstOrderOpt.cpp
//
// MATLAB Coder version            : 24.1
// C/C++ source code generated on  : 10-Sep-2025 16:14:33
//

// Include Files
#include "computeFirstOrderOpt.h"
#include "rt_nonfinite.h"
#include "wbqp_solve_internal_types.h"
#include <algorithm>
#include <cmath>

// Function Definitions
//
// Arguments    : struct_T &solution
//                const b_struct_T &objective
//                int workingset_nVar
//                const double workingset_ATwset[490]
//                int workingset_nActiveConstr
//                double workspace[490]
// Return Type  : void
//
namespace coder {
namespace optim {
namespace coder {
namespace qpactiveset {
namespace parseoutput {
void computeFirstOrderOpt(struct_T &solution, const b_struct_T &objective,
                          int workingset_nVar,
                          const double workingset_ATwset[490],
                          int workingset_nActiveConstr, double workspace[490])
{
  double infNorm;
  int i;
  boolean_T exitg1;
  i = static_cast<unsigned char>(workingset_nVar);
  std::copy(&objective.grad[0], &objective.grad[i], &workspace[0]);
  if (workingset_nActiveConstr != 0) {
    int ix;
    ix = 0;
    i = 10 * (workingset_nActiveConstr - 1) + 1;
    for (int iac{1}; iac <= i; iac += 10) {
      int b_i;
      b_i = (iac + workingset_nVar) - 1;
      for (int ia{iac}; ia <= b_i; ia++) {
        int i1;
        i1 = ia - iac;
        workspace[i1] += workingset_ATwset[ia - 1] * solution.lambda[ix];
      }
      ix++;
    }
  }
  infNorm = 0.0;
  i = 0;
  exitg1 = false;
  while ((!exitg1) && (i <= static_cast<unsigned char>(workingset_nVar) - 1)) {
    double abs_workspace_i;
    abs_workspace_i = std::abs(workspace[i]);
    if (std::isnan(abs_workspace_i)) {
      infNorm = rtNaN;
      exitg1 = true;
    } else {
      infNorm = std::fmax(infNorm, abs_workspace_i);
      i++;
    }
  }
  solution.firstorderopt = infNorm;
}

} // namespace parseoutput
} // namespace qpactiveset
} // namespace coder
} // namespace optim
} // namespace coder

//
// File trailer for computeFirstOrderOpt.cpp
//
// [EOF]
//
