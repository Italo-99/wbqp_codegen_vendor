//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: wbqp_init.cpp
//
// MATLAB Coder version            : 24.1
// C/C++ source code generated on  : 10-Sep-2025 15:23:17
//

// Include Files
#include "wbqp_init.h"
#include "rt_nonfinite.h"
#include "wbqp_init_types.h"
#include <algorithm>
#include <cstring>

// Function Definitions
//
// WBQP_INIT  Initialize Whole-Body QP configuration (final notation).
//  Decision variable: dotq_star = [dq(1:6); Vx; Vy; Omegaz] (9x1).
//
//  Inputs (optional fields; defaults mirror your values):
//    cfg.cols        : [1x9] reduced Jacobian column map (default [1:6,7,8,12])
//    cfg.Wq          : 9x9 command weights (if empty, built from scalars below)
//    cfg.beta_arm    : scalar weight for joints (default 1.0)
//    cfg.alpha_xy    : scalar weight for Vx,Vy (default 1.0)
//    cfg.alpha_yaw   : scalar weight for Omegaz (default 1.0)
//    cfg.Wt          : 6x6 task weights (diag of [w_lin(3), w_ang(3)])
//    cfg.w_lin       : scalar or 3x1 (default 1)
//    cfg.w_ang       : scalar or 3x1 (default 1)
//    cfg.nu          : Tikhonov reg. around dotq_prev (default 1e-3)
//    cfg.max_dotq    : joint speed (rad/s) (default 1.0)
//    cfg.max_V       : base speed (m/s) (default 0.5)
//    cfg.max_Omegaz  : yaw rate (rad/s) (default 1.0)
//    cfg.qmin,qmax   : 6x1 joint position bounds (rad)
//    cfg.qddot_max   : joint accel (rad/s^2) (default 2.0)
//    cfg.a_lin_max   : base accel (m/s^2) (default 1.0)
//    cfg.alpha_max   : yaw accel (rad/s^2) (default 1.0)
//    cfg.optsQP      : quadprog options (default interior-point-convex,
//    MaxIterations=50)
//
//  Output:
//    qp: struct with immutable fields for wbqp_solve().
//
// Arguments    : const struct10_T *cfg
//                struct11_T *qp
// Return Type  : void
//
void wbqp_init(const struct10_T *cfg, struct11_T *qp)
{
  static const char t0_Algorithm[10]{'a', 'c', 't', 'i', 'v',
                                     'e', '-', 's', 'e', 't'};
  static const char t0_SolverName[8]{'q', 'u', 'a', 'd', 'p', 'r', 'o', 'g'};
  static const char t0_FiniteDifferenceType[7]{'f', 'o', 'r', 'w',
                                               'a', 'r', 'd'};
  double v[9];
  double b_v[6];
  //  defaults
  //  Default solver options 'interior-point-convex'
  qp->optsQP.NonFiniteSupport = true;
  qp->optsQP.IterDisplaySQP = false;
  qp->optsQP.InitDamping = 0.01;
  for (int i{0}; i < 7; i++) {
    qp->optsQP.FiniteDifferenceType[i] = t0_FiniteDifferenceType[i];
  }
  qp->optsQP.SpecifyObjectiveGradient = false;
  qp->optsQP.ScaleProblem = false;
  qp->optsQP.SpecifyConstraintGradient = false;
  qp->optsQP.FiniteDifferenceStepSize = -1.0;
  qp->optsQP.MaxFunctionEvaluations = -1.0;
  qp->optsQP.IterDisplayQP = false;
  qp->optsQP.PricingTolerance = 0.0;
  for (int i{0}; i < 10; i++) {
    qp->optsQP.Algorithm[i] = t0_Algorithm[i];
  }
  qp->optsQP.ObjectiveLimit = -1.0E+20;
  qp->optsQP.ConstraintTolerance = 1.0E-6;
  qp->optsQP.OptimalityTolerance = 1.0E-8;
  qp->optsQP.StepTolerance = 0.0001;
  qp->optsQP.MaxIterations = 50.0;
  qp->optsQP.FunctionTolerance = rtInf;
  for (int i{0}; i < 8; i++) {
    qp->optsQP.SolverName[i] = t0_SolverName[i];
  }
  qp->optsQP.CheckGradients = false;
  qp->optsQP.DiffMaxChange = rtInf;
  qp->optsQP.DiffMinChange = 0.0;
  qp->optsQP.Diagnostics[0] = 'o';
  qp->optsQP.Display[0] = 'o';
  qp->optsQP.FunValCheck[0] = 'o';
  qp->optsQP.Diagnostics[1] = 'f';
  qp->optsQP.Display[1] = 'f';
  qp->optsQP.FunValCheck[1] = 'f';
  qp->optsQP.Diagnostics[2] = 'f';
  qp->optsQP.Display[2] = 'f';
  qp->optsQP.FunValCheck[2] = 'f';
  qp->optsQP.UseParallel = false;
  qp->optsQP.LinearSolver[0] = 'a';
  qp->optsQP.LinearSolver[1] = 'u';
  qp->optsQP.LinearSolver[2] = 't';
  qp->optsQP.LinearSolver[3] = 'o';
  qp->optsQP.SubproblemAlgorithm[0] = 'c';
  qp->optsQP.SubproblemAlgorithm[1] = 'g';
  //  qp.optsQP = optimoptions('fmincon', ...
  //      'Display','off', ...
  //      'Algorithm','interior-point', ...
  //      'OptimalityTolerance',1e-8, ...
  //      'StepTolerance',1e-4, ...
  //      'ConstraintTolerance',1e-6, ...
  //      'MaxIterations', 1000);
  std::copy(&cfg->cols[0], &cfg->cols[9], &qp->cols[0]);
  qp->beta_arm = cfg->beta_arm;
  qp->alpha_xy = cfg->alpha_xy;
  qp->alpha_yaw = cfg->alpha_yaw;
  qp->w_lin = cfg->w_lin;
  qp->w_ang = cfg->w_ang;
  qp->nu = cfg->nu;
  qp->max_dotq = cfg->max_dotq;
  qp->max_V = cfg->max_V;
  qp->max_Omegaz = cfg->max_Omegaz;
  qp->qddot_max = cfg->qddot_max;
  qp->a_lin_max = cfg->a_lin_max;
  qp->alpha_max = cfg->alpha_max;
  //  Command weights (Wq)
  for (int i{0}; i < 6; i++) {
    qp->qmin[i] = cfg->qmin[i];
    qp->qmax[i] = cfg->qmax[i];
    v[i] = cfg->beta_arm;
  }
  v[6] = cfg->alpha_xy;
  v[7] = cfg->alpha_xy;
  v[8] = cfg->alpha_yaw;
  std::memset(&qp->Wq[0], 0, 81U * sizeof(double));
  for (int i{0}; i < 9; i++) {
    qp->Wq[i + 9 * i] = v[i];
  }
  //  Task weights (Wt)
  b_v[0] = cfg->w_lin;
  b_v[3] = cfg->w_ang;
  b_v[1] = cfg->w_lin;
  b_v[4] = cfg->w_ang;
  b_v[2] = cfg->w_lin;
  b_v[5] = cfg->w_ang;
  std::memset(&qp->Wt[0], 0, 36U * sizeof(double));
  //  6x6
  //  qp.Wt(3,3) = qp.Wt(3,3)/4;    % TODO: FIX Z
  //  Fixed command box bounds on dotq_star
  qp->lb[6] = -cfg->max_V;
  qp->lb[7] = -cfg->max_V;
  qp->lb[8] = -cfg->max_Omegaz;
  for (int i{0}; i < 6; i++) {
    qp->Wt[i + 6 * i] = b_v[i];
    qp->lb[i] = -cfg->max_dotq;
    qp->ub[i] = cfg->max_dotq;
  }
  qp->ub[6] = cfg->max_V;
  qp->ub[7] = cfg->max_V;
  qp->ub[8] = cfg->max_Omegaz;
}

//
// File trailer for wbqp_init.cpp
//
// [EOF]
//
