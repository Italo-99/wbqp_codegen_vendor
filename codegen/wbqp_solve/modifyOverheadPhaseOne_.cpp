//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: modifyOverheadPhaseOne_.cpp
//
// MATLAB Coder version            : 24.1
// C/C++ source code generated on  : 10-Sep-2025 16:14:33
//

// Include Files
#include "modifyOverheadPhaseOne_.h"
#include "rt_nonfinite.h"
#include "wbqp_solve_internal_types.h"

// Function Definitions
//
// Arguments    : f_struct_T &obj
// Return Type  : void
//
namespace coder {
namespace optim {
namespace coder {
namespace qpactiveset {
namespace WorkingSet {
void modifyOverheadPhaseOne_(f_struct_T &obj)
{
  int i;
  int idxStartIneq;
  i = static_cast<unsigned char>(obj.sizes[0]);
  for (int idx{0}; idx < i; idx++) {
    obj.ATwset[10 * idx + 9] = 0.0;
  }
  for (int idx{0}; idx < 30; idx++) {
    obj.Aineq[10 * idx + 9] = -1.0;
  }
  obj.indexLB[obj.sizes[3] - 1] = 10;
  obj.lb[9] = obj.SLACK0;
  idxStartIneq = obj.isActiveIdx[2];
  i = obj.nActiveConstr;
  for (int idx{idxStartIneq}; idx <= i; idx++) {
    obj.ATwset[10 * (idx - 1) + 9] = -1.0;
  }
  idxStartIneq = obj.isActiveIdx[4] - 1;
  if (obj.nWConstr[4] > 0) {
    i = obj.sizesNormal[4] - 1;
    for (int idx{i}; idx >= 0; idx--) {
      int i1;
      i1 = idxStartIneq + idx;
      obj.isActiveConstr[i1] = obj.isActiveConstr[i1 - 1];
    }
  } else {
    obj.isActiveConstr[(obj.isActiveIdx[4] + obj.sizesNormal[4]) - 1] = false;
  }
  obj.isActiveConstr[obj.isActiveIdx[4] - 2] = false;
}

} // namespace WorkingSet
} // namespace qpactiveset
} // namespace coder
} // namespace optim
} // namespace coder

//
// File trailer for modifyOverheadPhaseOne_.cpp
//
// [EOF]
//
