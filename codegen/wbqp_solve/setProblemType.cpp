//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: setProblemType.cpp
//
// MATLAB Coder version            : 24.1
// C/C++ source code generated on  : 10-Sep-2025 16:14:33
//

// Include Files
#include "setProblemType.h"
#include "modifyOverheadPhaseOne_.h"
#include "rt_nonfinite.h"
#include "wbqp_solve_internal_types.h"
#include <cstring>

// Function Definitions
//
// Arguments    : f_struct_T &obj
//                int PROBLEM_TYPE
// Return Type  : void
//
namespace coder {
namespace optim {
namespace coder {
namespace qpactiveset {
namespace WorkingSet {
void setProblemType(f_struct_T &obj, int PROBLEM_TYPE)
{
  switch (PROBLEM_TYPE) {
  case 3: {
    int i;
    obj.nVar = 9;
    obj.mConstr = obj.mConstrOrig;
    if (obj.nWConstr[4] > 0) {
      int idxUpperExisting;
      idxUpperExisting = obj.isActiveIdx[4] - 2;
      i = static_cast<unsigned char>(obj.sizesNormal[4]);
      for (int colOffsetATw{0}; colOffsetATw < i; colOffsetATw++) {
        int i1;
        i1 = (idxUpperExisting + colOffsetATw) + 1;
        obj.isActiveConstr[(obj.isActiveIdxNormal[4] + colOffsetATw) - 1] =
            obj.isActiveConstr[i1];
        obj.isActiveConstr[i1] = false;
      }
    }
    for (i = 0; i < 5; i++) {
      obj.sizes[i] = obj.sizesNormal[i];
    }
    for (i = 0; i < 6; i++) {
      obj.isActiveIdx[i] = obj.isActiveIdxNormal[i];
    }
  } break;
  case 1:
    obj.nVar = 10;
    obj.mConstr = obj.mConstrOrig + 1;
    for (int i{0}; i < 5; i++) {
      obj.sizes[i] = obj.sizesPhaseOne[i];
    }
    modifyOverheadPhaseOne_(obj);
    for (int i{0}; i < 6; i++) {
      obj.isActiveIdx[i] = obj.isActiveIdxPhaseOne[i];
    }
    break;
  case 2: {
    int i;
    obj.nVar = 9;
    obj.mConstr = 48;
    for (i = 0; i < 5; i++) {
      obj.sizes[i] = obj.sizesRegularized[i];
    }
    if (obj.probType != 4) {
      int colOffsetATw;
      int i1;
      int idxUpperExisting;
      
      // --- PATCH: make memset count explicit and guard it; avoid UB warnings
      // Original (kept for reference):
      // for (int idx_col{0}; idx_col < 30; idx_col++) {
      //   idxUpperExisting = 10 * idx_col;
      //   i = idx_col + 9;
      //   if (i >= 10) {
      //     std::memset(&obj.Aineq[idxUpperExisting + 9], 0,
      //                 static_cast<unsigned int>(
      //                     ((i + idxUpperExisting) - idxUpperExisting) - 9) *
      //                     sizeof(double));
      //   }
      //   obj.Aineq[(idx_col + idxUpperExisting) + 9] = -1.0;
      // }
      for (int idx_col = 0; idx_col < 30; ++idx_col) {
        idxUpperExisting = 10 * idx_col;

        // number of elements to zero starting from row 9 up to (9 + idx_col - 1)
        // i.e., exactly idx_col elements when idx_col > 0
        unsigned int zero_count = static_cast<unsigned int>(idx_col);
        if (zero_count > 0) {
          std::memset(&obj.Aineq[idxUpperExisting + 9], 0,
                      zero_count * sizeof(double));
        }

        // set diagonal element at row (9 + idx_col)
        obj.Aineq[(idx_col + idxUpperExisting) + 9] = -1.0;
      }
      // END OF PATCH

      idxUpperExisting = 9;
      i = obj.sizesNormal[3] + 1;
      i1 = obj.sizesRegularized[3];
      for (colOffsetATw = i; colOffsetATw <= i1; colOffsetATw++) {
        idxUpperExisting++;
        obj.indexLB[colOffsetATw - 1] = idxUpperExisting;
      }
      if (obj.nWConstr[4] > 0) {
        i = static_cast<unsigned char>(obj.sizesRegularized[4]);
        for (colOffsetATw = 0; colOffsetATw < i; colOffsetATw++) {
          obj.isActiveConstr[obj.isActiveIdxRegularized[4] + colOffsetATw] =
              obj.isActiveConstr[(obj.isActiveIdx[4] + colOffsetATw) - 1];
        }
      }
      i = obj.isActiveIdx[4];
      i1 = obj.isActiveIdxRegularized[4] - 1;
      if (i <= i1) {
        std::memset(&obj.isActiveConstr[i + -1], 0,
                    static_cast<unsigned int>((i1 - i) + 1) *
                        sizeof(boolean_T));
      }
      obj.lb[9] = 0.0;
      idxUpperExisting = obj.isActiveIdx[2];
      i = obj.nActiveConstr;
      for (int idx_col{idxUpperExisting}; idx_col <= i; idx_col++) {
        colOffsetATw = 10 * (idx_col - 1) - 1;
        if (obj.Wid[idx_col - 1] == 3) {
          int i2;
          i1 = obj.Wlocalidx[idx_col - 1];
          i2 = i1 + 8;
          if (i2 >= 10) {
            std::memset(&obj.ATwset[colOffsetATw + 10], 0,
                        static_cast<unsigned int>(
                            ((i2 + colOffsetATw) - colOffsetATw) - 9) *
                            sizeof(double));
          }
          obj.ATwset[(i1 + colOffsetATw) + 9] = -1.0;
          i1 += 10;
          if (i1 <= 9) {
            std::memset(&obj.ATwset[i1 + colOffsetATw], 0,
                        static_cast<unsigned int>(
                            ((colOffsetATw - i1) - colOffsetATw) + 10) *
                            sizeof(double));
          }
        }
      }
    }
    for (i = 0; i < 6; i++) {
      obj.isActiveIdx[i] = obj.isActiveIdxRegularized[i];
    }
  } break;
  default:
    obj.nVar = 10;
    obj.mConstr = 49;
    for (int i{0}; i < 5; i++) {
      obj.sizes[i] = obj.sizesRegPhaseOne[i];
    }
    modifyOverheadPhaseOne_(obj);
    for (int i{0}; i < 6; i++) {
      obj.isActiveIdx[i] = obj.isActiveIdxRegPhaseOne[i];
    }
    break;
  }
  obj.probType = PROBLEM_TYPE;
}

} // namespace WorkingSet
} // namespace qpactiveset
} // namespace coder
} // namespace optim
} // namespace coder

//
// File trailer for setProblemType.cpp
//
// [EOF]
//
