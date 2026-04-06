//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: driver.h
//
// MATLAB Coder version            : 24.1
// C/C++ source code generated on  : 10-Sep-2025 16:14:33
//

#ifndef DRIVER_H
#define DRIVER_H

// Include Files
#include "rtwtypes.h"
#include <cstddef>
#include <cstdlib>

// Type Declarations
struct struct_T;

struct e_struct_T;

struct f_struct_T;

struct c_struct_T;

struct d_struct_T;

struct b_struct_T;

// Function Declarations
namespace coder {
namespace optim {
namespace coder {
namespace qpactiveset {
void driver(const double H[81], const double f[9], struct_T &solution,
            e_struct_T &memspace, f_struct_T &workingset,
            c_struct_T &cholmanager, double runTimeOptions_ConstrRelTolFactor,
            double runTimeOptions_ProbRelTolFactor, d_struct_T &qrmanager,
            b_struct_T &objective);

}
} // namespace coder
} // namespace optim
} // namespace coder

#endif
//
// File trailer for driver.h
//
// [EOF]
//
