//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: driver.cpp
//
// MATLAB Coder version            : 24.1
// C/C++ source code generated on  : 10-Sep-2025 16:14:33
//

// Include Files
#include "driver.h"
#include "PresolveWorkingSet.h"
#include "computeFirstOrderOpt.h"
#include "computeFval.h"
#include "feasibleX0ForWorkingSet.h"
#include "iterate.h"
#include "maxConstraintViolation.h"
#include "removeConstr.h"
#include "rt_nonfinite.h"
#include "setProblemType.h"
#include "wbqp_solve_internal_types.h"
#include <algorithm>
#include <cstring>

// Type Definitions
struct g_struct_T {
  char SolverName[8];
};

// Function Definitions
//
// Arguments    : const double H[81]
//                const double f[9]
//                struct_T &solution
//                e_struct_T &memspace
//                f_struct_T &workingset
//                c_struct_T &cholmanager
//                double runTimeOptions_ConstrRelTolFactor
//                double runTimeOptions_ProbRelTolFactor
//                d_struct_T &qrmanager
//                b_struct_T &objective
// Return Type  : void
//
namespace coder {
namespace optim {
namespace coder {
namespace qpactiveset {
void driver(const double H[81], const double f[9], struct_T &solution,
            e_struct_T &memspace, f_struct_T &workingset,
            c_struct_T &cholmanager, double runTimeOptions_ConstrRelTolFactor,
            double runTimeOptions_ProbRelTolFactor, d_struct_T &qrmanager,
            b_struct_T &objective)
{
  static const char cv[128]{
      '\x00', '\x01', '\x02', '\x03', '\x04', '\x05', '\x06', '\a',   '\b',
      '\t',   '\n',   '\v',   '\f',   '\r',   '\x0e', '\x0f', '\x10', '\x11',
      '\x12', '\x13', '\x14', '\x15', '\x16', '\x17', '\x18', '\x19', '\x1a',
      '\x1b', '\x1c', '\x1d', '\x1e', '\x1f', ' ',    '!',    '\"',   '#',
      '$',    '%',    '&',    '\'',   '(',    ')',    '*',    '+',    ',',
      '-',    '.',    '/',    '0',    '1',    '2',    '3',    '4',    '5',
      '6',    '7',    '8',    '9',    ':',    ';',    '<',    '=',    '>',
      '?',    '@',    'a',    'b',    'c',    'd',    'e',    'f',    'g',
      'h',    'i',    'j',    'k',    'l',    'm',    'n',    'o',    'p',
      'q',    'r',    's',    't',    'u',    'v',    'w',    'x',    'y',
      'z',    '[',    '\\',   ']',    '^',    '_',    '`',    'a',    'b',
      'c',    'd',    'e',    'f',    'g',    'h',    'i',    'j',    'k',
      'l',    'm',    'n',    'o',    'p',    'q',    'r',    's',    't',
      'u',    'v',    'w',    'x',    'y',    'z',    '{',    '|',    '}',
      '~',    '\x7f'};
  static const char cv1[8]{'q', 'u', 'a', 'd', 'p', 'r', 'o', 'g'};
  static const char t1_SolverName[8]{'q', 'u', 'a', 'd', 'p', 'r', 'o', 'g'};
  g_struct_T options;
  int PROBTYPE_ORIG;
  int i;
  int mConstr;
  std::memset(&objective.grad[0], 0, 10U * sizeof(double));
  std::memset(&objective.Hx[0], 0, 9U * sizeof(double));
  objective.hasLinear = true;
  objective.nvar = 9;
  objective.maxVar = 10;
  objective.beta = 0.0;
  objective.rho = 0.0;
  objective.objtype = 3;
  objective.prev_objtype = 3;
  objective.prev_nvar = 0;
  objective.prev_hasLinear = false;
  objective.gammaScalar = 0.0;
  solution.iterations = 0;
  PROBTYPE_ORIG = workingset.nVar;
  i = static_cast<unsigned char>(workingset.sizes[0]);
  for (mConstr = 0; mConstr < i; mConstr++) {
    solution.xstar[workingset.indexFixed[mConstr] - 1] =
        workingset.ub[workingset.indexFixed[mConstr] - 1];
  }
  i = static_cast<unsigned char>(workingset.sizes[3]);
  for (mConstr = 0; mConstr < i; mConstr++) {
    if (workingset.isActiveConstr[(workingset.isActiveIdx[3] + mConstr) - 1]) {
      solution.xstar[workingset.indexLB[mConstr] - 1] =
          -workingset.lb[workingset.indexLB[mConstr] - 1];
    }
  }
  i = static_cast<unsigned char>(workingset.sizes[4]);
  for (mConstr = 0; mConstr < i; mConstr++) {
    if (workingset.isActiveConstr[(workingset.isActiveIdx[4] + mConstr) - 1]) {
      solution.xstar[workingset.indexUB[mConstr] - 1] =
          workingset.ub[workingset.indexUB[mConstr] - 1];
    }
  }
  initialize::PresolveWorkingSet(solution, memspace, workingset, qrmanager);
  for (i = 0; i < 8; i++) {
    options.SolverName[i] = t1_SolverName[i];
  }
  if (solution.state >= 0) {
    int idxEndIneq_tmp_tmp;
    int idxStartIneq;
    boolean_T exitg1;
    boolean_T guard1;
    solution.iterations = 0;
    solution.maxConstr =
        WorkingSet::maxConstraintViolation(workingset, solution.xstar);
    guard1 = false;
    if (solution.maxConstr > 1.0E-6 * runTimeOptions_ConstrRelTolFactor) {
      solution.xstar[9] = solution.maxConstr + 1.0;
      WorkingSet::setProblemType(workingset, 1);
      mConstr = workingset.nWConstr[0] + workingset.nWConstr[1];
      idxStartIneq = mConstr + 1;
      idxEndIneq_tmp_tmp = workingset.nActiveConstr;
      for (int idx_global{idxStartIneq}; idx_global <= idxEndIneq_tmp_tmp;
           idx_global++) {
        workingset.isActiveConstr
            [(workingset.isActiveIdx[workingset.Wid[idx_global - 1] - 1] +
              workingset.Wlocalidx[idx_global - 1]) -
             2] = false;
      }
      workingset.nWConstr[2] = 0;
      workingset.nWConstr[3] = 0;
      workingset.nWConstr[4] = 0;
      workingset.nActiveConstr = mConstr;
      objective.prev_objtype = 3;
      objective.prev_nvar = 9;
      objective.prev_hasLinear = true;
      objective.objtype = 5;
      objective.nvar = 10;
      objective.gammaScalar = 1.0;
      objective.hasLinear = true;
      solution.fstar = Objective::computeFval(
          objective, memspace.workspace_float, H, f, solution.xstar);
      solution.state = 5;
      iterate(H, f, solution, memspace, workingset, qrmanager, cholmanager,
              objective, 1.0E-6 * runTimeOptions_ConstrRelTolFactor,
              1.4901161193847657E-10, runTimeOptions_ConstrRelTolFactor,
              runTimeOptions_ProbRelTolFactor, true);
      if (workingset.isActiveConstr
              [(workingset.isActiveIdx[3] + workingset.sizes[3]) - 2]) {
        mConstr = workingset.sizes[0];
        exitg1 = false;
        while ((!exitg1) && (mConstr + 1 <= workingset.nActiveConstr)) {
          if ((workingset.Wid[mConstr] == 4) &&
              (workingset.Wlocalidx[mConstr] == workingset.sizes[3])) {
            WorkingSet::removeConstr(workingset, mConstr + 1);
            exitg1 = true;
          } else {
            mConstr++;
          }
        }
      }
      mConstr = workingset.nActiveConstr;
      idxStartIneq = workingset.sizes[0];
      while ((mConstr > idxStartIneq) && (mConstr > PROBTYPE_ORIG)) {
        WorkingSet::removeConstr(workingset, mConstr);
        mConstr--;
      }
      solution.maxConstr = solution.xstar[9];
      WorkingSet::setProblemType(workingset, 3);
      objective.objtype = objective.prev_objtype;
      objective.nvar = objective.prev_nvar;
      objective.hasLinear = objective.prev_hasLinear;
      if (solution.state != 0) {
        solution.maxConstr =
            WorkingSet::maxConstraintViolation(workingset, solution.xstar);
        if (solution.maxConstr > 1.0E-6 * runTimeOptions_ConstrRelTolFactor) {
          std::memset(&solution.lambda[0], 0, 49U * sizeof(double));
          solution.fstar = Objective::computeFval(
              objective, memspace.workspace_float, H, f, solution.xstar);
          solution.state = -2;
        } else {
          if (solution.maxConstr > 0.0) {
            double maxConstr_new;
            i = static_cast<unsigned char>(PROBTYPE_ORIG);
            if (i - 1 >= 0) {
              std::copy(&solution.xstar[0], &solution.xstar[i],
                        &solution.searchDir[0]);
            }
            initialize::b_PresolveWorkingSet(solution, memspace, workingset,
                                             qrmanager);
            maxConstr_new =
                WorkingSet::maxConstraintViolation(workingset, solution.xstar);
            if (maxConstr_new >= solution.maxConstr) {
              solution.maxConstr = maxConstr_new;
              if (i - 1 >= 0) {
                std::copy(&solution.searchDir[0], &solution.searchDir[i],
                          &solution.xstar[0]);
              }
            }
          }
          guard1 = true;
        }
      }
    } else {
      guard1 = true;
    }
    if (guard1) {
      boolean_T b_bool;
      iterate(H, f, solution, memspace, workingset, qrmanager, cholmanager,
              objective, -1.0E+20, 0.0001, runTimeOptions_ConstrRelTolFactor,
              runTimeOptions_ProbRelTolFactor, true);
      b_bool = false;
      mConstr = 0;
      int exitg2;
      do {
        exitg2 = 0;
        if (mConstr < 8) {
          if (cv[static_cast<int>(options.SolverName[mConstr])] !=
              cv[static_cast<int>(cv1[mConstr])]) {
            exitg2 = 1;
          } else {
            mConstr++;
          }
        } else {
          b_bool = true;
          exitg2 = 1;
        }
      } while (exitg2 == 0);
      if (b_bool && (solution.state != -6)) {
        solution.maxConstr =
            WorkingSet::maxConstraintViolation(workingset, solution.xstar);
        parseoutput::computeFirstOrderOpt(
            solution, objective, workingset.nVar, workingset.ATwset,
            workingset.nActiveConstr, memspace.workspace_float);
        while ((solution.iterations < 50) &&
               ((solution.state == -7) ||
                ((solution.state == 1) &&
                 ((solution.maxConstr >
                   1.0E-6 * runTimeOptions_ConstrRelTolFactor) ||
                  (solution.firstorderopt >
                   1.0E-8 * runTimeOptions_ProbRelTolFactor))))) {
          initialize::feasibleX0ForWorkingSet(
              memspace.workspace_float, solution.xstar, workingset, qrmanager);
          initialize::b_PresolveWorkingSet(solution, memspace, workingset,
                                           qrmanager);
          PROBTYPE_ORIG = workingset.probType;
          i = workingset.nVar;
          solution.xstar[9] = solution.maxConstr + 1.0;
          if (workingset.probType == 3) {
            idxStartIneq = 1;
          } else {
            idxStartIneq = 4;
          }
          WorkingSet::setProblemType(workingset, idxStartIneq);
          idxStartIneq = (workingset.nWConstr[0] + workingset.nWConstr[1]) + 1;
          idxEndIneq_tmp_tmp = workingset.nActiveConstr;
          for (int idx_global{idxStartIneq}; idx_global <= idxEndIneq_tmp_tmp;
               idx_global++) {
            workingset.isActiveConstr
                [(workingset.isActiveIdx[workingset.Wid[idx_global - 1] - 1] +
                  workingset.Wlocalidx[idx_global - 1]) -
                 2] = false;
          }
          workingset.nWConstr[2] = 0;
          workingset.nWConstr[3] = 0;
          workingset.nWConstr[4] = 0;
          workingset.nActiveConstr =
              workingset.nWConstr[0] + workingset.nWConstr[1];
          objective.prev_objtype = objective.objtype;
          objective.prev_nvar = objective.nvar;
          objective.prev_hasLinear = objective.hasLinear;
          objective.objtype = 5;
          objective.nvar = 10;
          objective.gammaScalar = 1.0;
          objective.hasLinear = true;
          solution.fstar = Objective::computeFval(
              objective, memspace.workspace_float, H, f, solution.xstar);
          solution.state = 5;
          iterate(H, f, solution, memspace, workingset, qrmanager, cholmanager,
                  objective, 1.0E-6 * runTimeOptions_ConstrRelTolFactor,
                  1.4901161193847657E-10, runTimeOptions_ConstrRelTolFactor,
                  runTimeOptions_ProbRelTolFactor, false);
          if (workingset.isActiveConstr
                  [(workingset.isActiveIdx[3] + workingset.sizes[3]) - 2]) {
            mConstr = workingset.sizes[0];
            exitg1 = false;
            while ((!exitg1) && (mConstr + 1 <= workingset.nActiveConstr)) {
              if ((workingset.Wid[mConstr] == 4) &&
                  (workingset.Wlocalidx[mConstr] == workingset.sizes[3])) {
                WorkingSet::removeConstr(workingset, mConstr + 1);
                exitg1 = true;
              } else {
                mConstr++;
              }
            }
          }
          mConstr = workingset.nActiveConstr;
          idxStartIneq = workingset.sizes[0];
          while ((mConstr > idxStartIneq) && (mConstr > i)) {
            WorkingSet::removeConstr(workingset, mConstr);
            mConstr--;
          }
          solution.maxConstr = solution.xstar[9];
          WorkingSet::setProblemType(workingset, PROBTYPE_ORIG);
          objective.objtype = objective.prev_objtype;
          objective.nvar = objective.prev_nvar;
          objective.hasLinear = objective.prev_hasLinear;
          iterate(H, f, solution, memspace, workingset, qrmanager, cholmanager,
                  objective, -1.0E+20, 0.0001,
                  runTimeOptions_ConstrRelTolFactor,
                  runTimeOptions_ProbRelTolFactor, false);
          solution.maxConstr =
              WorkingSet::maxConstraintViolation(workingset, solution.xstar);
          parseoutput::computeFirstOrderOpt(
              solution, objective, workingset.nVar, workingset.ATwset,
              workingset.nActiveConstr, memspace.workspace_float);
        }
      }
    }
  }
}

} // namespace qpactiveset
} // namespace coder
} // namespace optim
} // namespace coder

//
// File trailer for driver.cpp
//
// [EOF]
//
