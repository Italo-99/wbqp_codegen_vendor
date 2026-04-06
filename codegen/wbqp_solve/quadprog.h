//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: quadprog.h
//
// MATLAB Coder version            : 24.1
// C/C++ source code generated on  : 10-Sep-2025 16:14:33
//

#ifndef QUADPROG_H
#define QUADPROG_H

// Include Files
#include "rtwtypes.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace coder {
double quadprog(const double H[81], const double f[9], const double bineq[30],
                const double lb[9], const double ub[9], double x0[9],
                double &exitflag, char output_algorithm[10],
                double &output_firstorderopt, double &output_constrviolation,
                double &output_iterations);

}

#endif
//
// File trailer for quadprog.h
//
// [EOF]
//
