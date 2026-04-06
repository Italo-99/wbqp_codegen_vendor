//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: wbqp_solve.cpp
//
// MATLAB Coder version            : 24.1
// C/C++ source code generated on  : 10-Sep-2025 16:14:33
//

// Include Files
#include "wbqp_solve.h"
#include "quadprog.h"
#include "rt_nonfinite.h"
#include "tic.h"
#include "toc.h"
#include "wbqp_solve_data.h"
#include "wbqp_solve_initialize.h"
#include "wbqp_solve_types.h"
#include <cmath>
#include <emmintrin.h>

// Function Definitions
//
// WBQP_SOLVE  One QP step (final notation: dotq* decision, u = J*dotq*).
//
//  Inputs (per-step):
//    in.J_full   [6 x m] or in.J [6 x 9]   Whole-body Jacobian; reduced cols =
//    qp.cols in.q        [6 x 1]   Current joint positions (rad)  (for position
//    bounds) in.u_star   [6 x 1]   Desired task twist (WORLD): [b_pos; b_omega]
//    in.dotq_prev[9 x 1]   Previous accepted dotq*
//    in.dt       [1 x 1]   Control period
//
//  Output:
//    dotq_star_opt [9 x 1] Optimal (or best) decision vector
//    dbg           struct  Diagnostics (exitflag, timing, used_qp, etc.)
//
// Arguments    : const struct0_T *qp
//                const struct1_T *in
//                double dotq_star_opt[9]
//                struct2_T *dbg
// Return Type  : void
//
void wbqp_solve(const struct0_T *qp, const struct1_T *in,
                double dotq_star_opt[9], struct2_T *dbg)
{
  static const double b_y[81]{
      0.0004, 0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,
      0.0,    0.0004, 0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,
      0.0,    0.0,    0.0004, 0.0,    0.0,    0.0,    0.0,    0.0,    0.0,
      0.0,    0.0,    0.0,    0.0004, 0.0,    0.0,    0.0,    0.0,    0.0,
      0.0,    0.0,    0.0,    0.0,    0.0004, 0.0,    0.0,    0.0,    0.0,
      0.0,    0.0,    0.0,    0.0,    0.0,    0.0004, 0.0,    0.0,    0.0,
      0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0004, 0.0,    0.0,
      0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0004, 0.0,
      0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0004};
  static const signed char b[81]{
      1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1};
  __m128d r;
  double Hls[81];
  double dv[81];
  double H_tmp[54];
  double b_in[30];
  double delta[9];
  double maxval[9];
  double rhs[9];
  double b_expl_temp;
  double exitflag;
  double output_constrviolation;
  double output_firstorderopt;
  double s;
  double smax;
  int b_i;
  int i;
  int jA;
  int jp1j;
  int k;
  boolean_T b_b[9];
  boolean_T c_b[9];
  boolean_T exitg1;
  boolean_T y;
  if (!isInitialized_wbqp_solve) {
    wbqp_solve_initialize();
  }
  //  --- Reduced Jacobian (6x9)
  //  J(1:2,1:6) = -J(1:2,1:6); %FIX TEMP
  //  --- Quadratic cost: H, f   (no factor-2 convention)
  //  min  || J*dotq* - u_star ||_{Wt}^2 + (dotq*)' Wq dotq* + nu ||dotq* -
  //  dotq_prev||^2 9x9
  for (i = 0; i < 9; i++) {
    for (jp1j = 0; jp1j < 6; jp1j++) {
      smax = 0.0;
      for (jA = 0; jA < 6; jA++) {
        smax += in->J[jA + 6 * i] * qp->Wt[jA + 6 * jp1j];
      }
      H_tmp[i + 9 * jp1j] = smax;
    }
    for (jp1j = 0; jp1j < 9; jp1j++) {
      smax = 0.0;
      for (jA = 0; jA < 6; jA++) {
        smax += H_tmp[i + 9 * jA] * in->J[jA + 6 * jp1j];
      }
      Hls[i + 9 * jp1j] = smax;
    }
    smax = 0.0;
    for (jp1j = 0; jp1j < 6; jp1j++) {
      smax += H_tmp[i + 9 * jp1j] * in->u_star[jp1j];
    }
    rhs[i] = smax;
  }
  //  9x1
  //  --- Soft acceleration bounds around dotq_prev
  for (b_i = 0; b_i < 6; b_i++) {
    delta[b_i] = qp->qddot_max * in->dt;
  }
  smax = qp->a_lin_max * in->dt;
  delta[6] = smax;
  delta[7] = smax;
  delta[8] = qp->alpha_max * in->dt;
  //  --- Joint position bounds per step: q + dq* dt in [qmin, qmax]
  //  picks dq from dotq*
  //  --- Combine inequalities
  //  --- Solve QP (bounded iterations, warm start)
  for (k = 0; k < 9; k++) {
    dotq_star_opt[k] =
        std::fmin(std::fmax(in->dotq_prev[k], qp->lb[k]), qp->ub[k]);
  }
  smax = coder::tic(s);
  //  x0 = pinv(J)*in.u_star;
  //  cf = @(x)(J*x-in.u_star).'*(J*x-in.u_star);
  //  [x_qp, ~, exitflag, output] = fmincon(cf, x0, Aineq, bineq, [], [], qp.lb,
  //  qp.ub, [], qp.optsQP); Default solver options 'interior-point-convex'
  for (i = 0; i < 81; i++) {
    dv[i] = 2.0 * ((Hls[i] + qp->Wq[i]) + qp->nu * static_cast<double>(b[i]));
  }
  __m128d r1;
  __m128d r2;
  __m128d r3;
  __m128d r4;
  char expl_temp[10];
  r = _mm_loadu_pd(&in->dotq_prev[0]);
  r1 = _mm_loadu_pd(&rhs[0]);
  r2 = _mm_set1_pd(-2.0);
  r3 = _mm_set1_pd(qp->nu);
  _mm_storeu_pd(&maxval[0], _mm_mul_pd(r2, _mm_add_pd(r1, _mm_mul_pd(r3, r))));
  r1 = _mm_loadu_pd(&delta[0]);
  _mm_storeu_pd(&b_in[0], _mm_add_pd(r, r1));
  r4 = _mm_set1_pd(-1.0);
  _mm_storeu_pd(&b_in[9], _mm_add_pd(_mm_mul_pd(r, r4), r1));
  r = _mm_loadu_pd(&in->dotq_prev[2]);
  r1 = _mm_loadu_pd(&rhs[2]);
  _mm_storeu_pd(&maxval[2], _mm_mul_pd(r2, _mm_add_pd(r1, _mm_mul_pd(r3, r))));
  r1 = _mm_loadu_pd(&delta[2]);
  _mm_storeu_pd(&b_in[2], _mm_add_pd(r, r1));
  _mm_storeu_pd(&b_in[11], _mm_add_pd(_mm_mul_pd(r, r4), r1));
  r = _mm_loadu_pd(&in->dotq_prev[4]);
  r1 = _mm_loadu_pd(&rhs[4]);
  _mm_storeu_pd(&maxval[4], _mm_mul_pd(r2, _mm_add_pd(r1, _mm_mul_pd(r3, r))));
  r1 = _mm_loadu_pd(&delta[4]);
  _mm_storeu_pd(&b_in[4], _mm_add_pd(r, r1));
  _mm_storeu_pd(&b_in[13], _mm_add_pd(_mm_mul_pd(r, r4), r1));
  r = _mm_loadu_pd(&in->dotq_prev[6]);
  r1 = _mm_loadu_pd(&rhs[6]);
  _mm_storeu_pd(&maxval[6], _mm_mul_pd(r2, _mm_add_pd(r1, _mm_mul_pd(r3, r))));
  r1 = _mm_loadu_pd(&delta[6]);
  _mm_storeu_pd(&b_in[6], _mm_add_pd(r, r1));
  _mm_storeu_pd(&b_in[15], _mm_add_pd(_mm_mul_pd(r, r4), r1));
  maxval[8] = -2.0 * (rhs[8] + qp->nu * in->dotq_prev[8]);
  b_in[8] = in->dotq_prev[8] + delta[8];
  b_in[17] = -in->dotq_prev[8] + delta[8];
  r = _mm_set1_pd(in->dt);
  _mm_storeu_pd(&b_in[18], _mm_div_pd(_mm_sub_pd(_mm_loadu_pd(&qp->qmax[0]),
                                                 _mm_loadu_pd(&in->q[0])),
                                      r));
  _mm_storeu_pd(&b_in[24],
                _mm_mul_pd(_mm_div_pd(_mm_sub_pd(_mm_loadu_pd(&qp->qmin[0]),
                                                 _mm_loadu_pd(&in->q[0])),
                                      r),
                           r4));
  _mm_storeu_pd(&b_in[20], _mm_div_pd(_mm_sub_pd(_mm_loadu_pd(&qp->qmax[2]),
                                                 _mm_loadu_pd(&in->q[2])),
                                      r));
  _mm_storeu_pd(&b_in[26],
                _mm_mul_pd(_mm_div_pd(_mm_sub_pd(_mm_loadu_pd(&qp->qmin[2]),
                                                 _mm_loadu_pd(&in->q[2])),
                                      r),
                           r4));
  _mm_storeu_pd(&b_in[22], _mm_div_pd(_mm_sub_pd(_mm_loadu_pd(&qp->qmax[4]),
                                                 _mm_loadu_pd(&in->q[4])),
                                      r));
  _mm_storeu_pd(&b_in[28],
                _mm_mul_pd(_mm_div_pd(_mm_sub_pd(_mm_loadu_pd(&qp->qmin[4]),
                                                 _mm_loadu_pd(&in->q[4])),
                                      r),
                           r4));
  coder::quadprog(dv, maxval, b_in, qp->lb, qp->ub, dotq_star_opt, exitflag,
                  expl_temp, output_firstorderopt, output_constrviolation,
                  b_expl_temp);
  dbg->t_qp = coder::toc(smax, s);
  for (b_i = 0; b_i < 9; b_i++) {
    smax = dotq_star_opt[b_i];
    b_b[b_i] = std::isinf(smax);
    c_b[b_i] = std::isnan(smax);
  }
  y = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k <= 8)) {
    if (b_b[k] || c_b[k]) {
      y = false;
      exitg1 = true;
    } else {
      k++;
    }
  }
  if (y && (exitflag >= 0.0)) {
    y = true;
  } else {
    signed char ipiv[9];
    y = false;
    //  Weighted damped least-squares fallback, then project to box
    for (i = 0; i <= 78; i += 2) {
      r = _mm_loadu_pd(&Hls[i]);
      _mm_storeu_pd(&Hls[i], _mm_add_pd(r, _mm_loadu_pd(&b_y[i])));
    }
    Hls[80] += b_y[80];
    for (i = 0; i < 9; i++) {
      ipiv[i] = static_cast<signed char>(i + 1);
    }
    for (int j{0}; j < 8; j++) {
      int Hls_tmp;
      int b_tmp;
      int mmj_tmp;
      signed char i1;
      mmj_tmp = 7 - j;
      b_tmp = j * 10;
      jp1j = b_tmp + 2;
      jA = 9 - j;
      b_i = 0;
      smax = std::abs(Hls[b_tmp]);
      for (k = 2; k <= jA; k++) {
        s = std::abs(Hls[(b_tmp + k) - 1]);
        if (s > smax) {
          b_i = k - 1;
          smax = s;
        }
      }
      if (Hls[b_tmp + b_i] != 0.0) {
        if (b_i != 0) {
          jA = j + b_i;
          ipiv[j] = static_cast<signed char>(jA + 1);
          for (k = 0; k < 9; k++) {
            b_i = j + k * 9;
            smax = Hls[b_i];
            Hls_tmp = jA + k * 9;
            Hls[b_i] = Hls[Hls_tmp];
            Hls[Hls_tmp] = smax;
          }
        }
        i = (b_tmp - j) + 9;
        for (b_i = jp1j; b_i <= i; b_i++) {
          Hls[b_i - 1] /= Hls[b_tmp];
        }
      }
      jA = b_tmp;
      for (b_i = 0; b_i <= mmj_tmp; b_i++) {
        smax = Hls[(b_tmp + b_i * 9) + 9];
        if (smax != 0.0) {
          i = jA + 11;
          jp1j = (jA - j) + 18;
          for (Hls_tmp = i; Hls_tmp <= jp1j; Hls_tmp++) {
            Hls[Hls_tmp - 1] += Hls[((b_tmp + Hls_tmp) - jA) - 10] * -smax;
          }
        }
        jA += 9;
      }
      i1 = ipiv[j];
      if (i1 != j + 1) {
        smax = rhs[j];
        rhs[j] = rhs[i1 - 1];
        rhs[i1 - 1] = smax;
      }
    }
    for (k = 0; k < 9; k++) {
      jA = 9 * k;
      if (rhs[k] != 0.0) {
        i = k + 2;
        for (b_i = i; b_i < 10; b_i++) {
          rhs[b_i - 1] -= rhs[k] * Hls[(b_i + jA) - 1];
        }
      }
    }
    for (k = 8; k >= 0; k--) {
      jA = 9 * k;
      smax = rhs[k];
      if (smax != 0.0) {
        smax /= Hls[k + jA];
        rhs[k] = smax;
        for (b_i = 0; b_i < k; b_i++) {
          rhs[b_i] -= rhs[k] * Hls[b_i + jA];
        }
      }
    }
    for (k = 0; k < 9; k++) {
      dotq_star_opt[k] = std::fmin(std::fmax(rhs[k], qp->lb[k]), qp->ub[k]);
    }
  }
  //  --- Diagnostics
  dbg->exitflag = exitflag;
  dbg->used_qp = y;
  //  ----- UTILS ----- %
  dbg->firstorderopt = output_firstorderopt;
  //  ----- UTILS ----- %
  dbg->constrviolation = output_constrviolation;
  //  dbg.firstorderopt   = output.firstorderopt;
  //  dbg.constrviolation = output.constrviolation;
  for (i = 0; i < 6; i++) {
    smax = 0.0;
    for (jp1j = 0; jp1j < 9; jp1j++) {
      smax += in->J[i + 6 * jp1j] * dotq_star_opt[jp1j];
    }
    dbg->u_actual[i] = smax;
  }
  //  task twist actually commanded
}

//
// File trailer for wbqp_solve.cpp
//
// [EOF]
//
