//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: _coder_wbqp_init_api.cpp
//
// MATLAB Coder version            : 24.1
// C/C++ source code generated on  : 10-Sep-2025 15:23:17
//

// Include Files
#include "_coder_wbqp_init_api.h"
#include "_coder_wbqp_init_mex.h"

// Variable Definitions
emlrtCTX emlrtRootTLSGlobal{nullptr};

emlrtContext emlrtContextGlobal{
    true,                                                 // bFirstTime
    false,                                                // bInitialized
    131643U,                                              // fVersionInfo
    nullptr,                                              // fErrorFunction
    "wbqp_init",                                          // fFunctionName
    nullptr,                                              // fRTCallStack
    false,                                                // bDebugMode
    {2045744189U, 2170104910U, 2743257031U, 4284093946U}, // fSigWrd
    nullptr                                               // fSigMem
};

// Function Declarations
static real_T b_emlrt_marshallIn(const emlrtStack &sp, const mxArray *src,
                                 const emlrtMsgIdentifier *msgId);

static void b_emlrt_marshallIn(const emlrtStack &sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId, real_T y[6]);

static void c_emlrt_marshallIn(const emlrtStack &sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId, real_T ret[9]);

static void d_emlrt_marshallIn(const emlrtStack &sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId, real_T ret[6]);

static void emlrtExitTimeCleanupDtorFcn(const void *r);

static void emlrt_marshallIn(const emlrtStack &sp, const mxArray *b_nullptr,
                             const char_T *identifier, struct10_T &y);

static void emlrt_marshallIn(const emlrtStack &sp, const mxArray *u,
                             const emlrtMsgIdentifier *parentId, struct10_T &y);

static void emlrt_marshallIn(const emlrtStack &sp, const mxArray *u,
                             const emlrtMsgIdentifier *parentId, real_T y[9]);

static real_T emlrt_marshallIn(const emlrtStack &sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId);

static const mxArray *emlrt_marshallOut(const emlrtStack &sp,
                                        const struct11_T &u);

static const mxArray *emlrt_marshallOut(const emlrtStack &sp,
                                        const struct12_T &u);

// Function Definitions
//
// Arguments    : const emlrtStack &sp
//                const mxArray *src
//                const emlrtMsgIdentifier *msgId
// Return Type  : real_T
//
static real_T b_emlrt_marshallIn(const emlrtStack &sp, const mxArray *src,
                                 const emlrtMsgIdentifier *msgId)
{
  static const int32_T dims{0};
  real_T ret;
  emlrtCheckBuiltInR2012b((emlrtConstCTX)&sp, msgId, src, "double", false, 0U,
                          (const void *)&dims);
  ret = *static_cast<real_T *>(emlrtMxGetData(src));
  emlrtDestroyArray(&src);
  return ret;
}

//
// Arguments    : const emlrtStack &sp
//                const mxArray *u
//                const emlrtMsgIdentifier *parentId
//                real_T y[6]
// Return Type  : void
//
static void b_emlrt_marshallIn(const emlrtStack &sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId, real_T y[6])
{
  d_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

//
// Arguments    : const emlrtStack &sp
//                const mxArray *src
//                const emlrtMsgIdentifier *msgId
//                real_T ret[9]
// Return Type  : void
//
static void c_emlrt_marshallIn(const emlrtStack &sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId, real_T ret[9])
{
  static const int32_T dims[2]{1, 9};
  real_T(*r)[9];
  emlrtCheckBuiltInR2012b((emlrtConstCTX)&sp, msgId, src, "double", false, 2U,
                          (const void *)&dims[0]);
  r = (real_T(*)[9])emlrtMxGetData(src);
  for (int32_T i{0}; i < 9; i++) {
    ret[i] = (*r)[i];
  }
  emlrtDestroyArray(&src);
}

//
// Arguments    : const emlrtStack &sp
//                const mxArray *src
//                const emlrtMsgIdentifier *msgId
//                real_T ret[6]
// Return Type  : void
//
static void d_emlrt_marshallIn(const emlrtStack &sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId, real_T ret[6])
{
  static const int32_T dims{6};
  real_T(*r)[6];
  emlrtCheckBuiltInR2012b((emlrtConstCTX)&sp, msgId, src, "double", false, 1U,
                          (const void *)&dims);
  r = (real_T(*)[6])emlrtMxGetData(src);
  for (int32_T i{0}; i < 6; i++) {
    ret[i] = (*r)[i];
  }
  emlrtDestroyArray(&src);
}

//
// Arguments    : const void *r
// Return Type  : void
//
static void emlrtExitTimeCleanupDtorFcn(const void *r)
{
  emlrtExitTimeCleanup(&emlrtContextGlobal);
}

//
// Arguments    : const emlrtStack &sp
//                const mxArray *b_nullptr
//                const char_T *identifier
//                struct10_T &y
// Return Type  : void
//
static void emlrt_marshallIn(const emlrtStack &sp, const mxArray *b_nullptr,
                             const char_T *identifier, struct10_T &y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = const_cast<const char_T *>(identifier);
  thisId.fParent = nullptr;
  thisId.bParentIsCell = false;
  emlrt_marshallIn(sp, emlrtAlias(b_nullptr), &thisId, y);
  emlrtDestroyArray(&b_nullptr);
}

//
// Arguments    : const emlrtStack &sp
//                const mxArray *u
//                const emlrtMsgIdentifier *parentId
//                struct10_T &y
// Return Type  : void
//
static void emlrt_marshallIn(const emlrtStack &sp, const mxArray *u,
                             const emlrtMsgIdentifier *parentId, struct10_T &y)
{
  static const int32_T dims{0};
  static const char_T *fieldNames[15]{
      "cols",      "beta_arm",  "alpha_xy",  "alpha_yaw", "w_lin",
      "w_ang",     "nu",        "max_dotq",  "max_V",     "max_Omegaz",
      "qddot_max", "a_lin_max", "alpha_max", "qmin",      "qmax"};
  emlrtMsgIdentifier thisId;
  thisId.fParent = parentId;
  thisId.bParentIsCell = false;
  emlrtCheckStructR2012b((emlrtConstCTX)&sp, parentId, u, 15,
                         (const char_T **)&fieldNames[0], 0U,
                         (const void *)&dims);
  thisId.fIdentifier = "cols";
  emlrt_marshallIn(
      sp, emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)&sp, u, 0, 0, "cols")),
      &thisId, y.cols);
  thisId.fIdentifier = "beta_arm";
  y.beta_arm = emlrt_marshallIn(
      sp,
      emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)&sp, u, 0, 1, "beta_arm")),
      &thisId);
  thisId.fIdentifier = "alpha_xy";
  y.alpha_xy = emlrt_marshallIn(
      sp,
      emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)&sp, u, 0, 2, "alpha_xy")),
      &thisId);
  thisId.fIdentifier = "alpha_yaw";
  y.alpha_yaw = emlrt_marshallIn(
      sp,
      emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)&sp, u, 0, 3, "alpha_yaw")),
      &thisId);
  thisId.fIdentifier = "w_lin";
  y.w_lin = emlrt_marshallIn(
      sp, emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)&sp, u, 0, 4, "w_lin")),
      &thisId);
  thisId.fIdentifier = "w_ang";
  y.w_ang = emlrt_marshallIn(
      sp, emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)&sp, u, 0, 5, "w_ang")),
      &thisId);
  thisId.fIdentifier = "nu";
  y.nu = emlrt_marshallIn(
      sp, emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)&sp, u, 0, 6, "nu")),
      &thisId);
  thisId.fIdentifier = "max_dotq";
  y.max_dotq = emlrt_marshallIn(
      sp,
      emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)&sp, u, 0, 7, "max_dotq")),
      &thisId);
  thisId.fIdentifier = "max_V";
  y.max_V = emlrt_marshallIn(
      sp, emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)&sp, u, 0, 8, "max_V")),
      &thisId);
  thisId.fIdentifier = "max_Omegaz";
  y.max_Omegaz =
      emlrt_marshallIn(sp,
                       emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)&sp, u, 0,
                                                      9, "max_Omegaz")),
                       &thisId);
  thisId.fIdentifier = "qddot_max";
  y.qddot_max =
      emlrt_marshallIn(sp,
                       emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)&sp, u, 0,
                                                      10, "qddot_max")),
                       &thisId);
  thisId.fIdentifier = "a_lin_max";
  y.a_lin_max =
      emlrt_marshallIn(sp,
                       emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)&sp, u, 0,
                                                      11, "a_lin_max")),
                       &thisId);
  thisId.fIdentifier = "alpha_max";
  y.alpha_max =
      emlrt_marshallIn(sp,
                       emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)&sp, u, 0,
                                                      12, "alpha_max")),
                       &thisId);
  thisId.fIdentifier = "qmin";
  b_emlrt_marshallIn(
      sp, emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)&sp, u, 0, 13, "qmin")),
      &thisId, y.qmin);
  thisId.fIdentifier = "qmax";
  b_emlrt_marshallIn(
      sp, emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)&sp, u, 0, 14, "qmax")),
      &thisId, y.qmax);
  emlrtDestroyArray(&u);
}

//
// Arguments    : const emlrtStack &sp
//                const mxArray *u
//                const emlrtMsgIdentifier *parentId
//                real_T y[9]
// Return Type  : void
//
static void emlrt_marshallIn(const emlrtStack &sp, const mxArray *u,
                             const emlrtMsgIdentifier *parentId, real_T y[9])
{
  c_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

//
// Arguments    : const emlrtStack &sp
//                const mxArray *u
//                const emlrtMsgIdentifier *parentId
// Return Type  : real_T
//
static real_T emlrt_marshallIn(const emlrtStack &sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId)
{
  real_T y;
  y = b_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

//
// Arguments    : const emlrtStack &sp
//                const struct11_T &u
// Return Type  : const mxArray *
//
static const mxArray *emlrt_marshallOut(const emlrtStack &sp,
                                        const struct11_T &u)
{
  static const int32_T iv[2]{1, 9};
  static const int32_T iv1[2]{9, 9};
  static const int32_T iv2[2]{6, 6};
  static const int32_T i1{6};
  static const int32_T i2{6};
  static const int32_T i3{9};
  static const int32_T i4{9};
  static const char_T *sv[20]{
      "cols",      "beta_arm",   "alpha_xy", "alpha_yaw", "w_lin",
      "w_ang",     "Wq",         "Wt",       "nu",        "max_dotq",
      "max_V",     "max_Omegaz", "qmin",     "qmax",      "qddot_max",
      "a_lin_max", "alpha_max",  "lb",       "ub",        "optsQP"};
  const mxArray *b_y;
  const mxArray *c_y;
  const mxArray *d_y;
  const mxArray *e_y;
  const mxArray *f_y;
  const mxArray *g_y;
  const mxArray *h_y;
  const mxArray *i_y;
  const mxArray *j_y;
  const mxArray *k_y;
  const mxArray *l_y;
  const mxArray *m;
  const mxArray *m_y;
  const mxArray *n_y;
  const mxArray *o_y;
  const mxArray *p_y;
  const mxArray *q_y;
  const mxArray *r_y;
  const mxArray *s_y;
  const mxArray *t_y;
  const mxArray *y;
  real_T *pData;
  int32_T b_i;
  y = nullptr;
  emlrtAssign(&y, emlrtCreateStructMatrix(1, 1, 20, (const char_T **)&sv[0]));
  b_y = nullptr;
  m = emlrtCreateNumericArray(2, (const void *)&iv[0], mxDOUBLE_CLASS, mxREAL);
  pData = emlrtMxGetPr(m);
  for (int32_T i{0}; i < 9; i++) {
    pData[i] = u.cols[i];
  }
  emlrtAssign(&b_y, m);
  emlrtSetFieldR2017b(y, 0, "cols", b_y, 0);
  c_y = nullptr;
  m = emlrtCreateDoubleScalar(u.beta_arm);
  emlrtAssign(&c_y, m);
  emlrtSetFieldR2017b(y, 0, "beta_arm", c_y, 1);
  d_y = nullptr;
  m = emlrtCreateDoubleScalar(u.alpha_xy);
  emlrtAssign(&d_y, m);
  emlrtSetFieldR2017b(y, 0, "alpha_xy", d_y, 2);
  e_y = nullptr;
  m = emlrtCreateDoubleScalar(u.alpha_yaw);
  emlrtAssign(&e_y, m);
  emlrtSetFieldR2017b(y, 0, "alpha_yaw", e_y, 3);
  f_y = nullptr;
  m = emlrtCreateDoubleScalar(u.w_lin);
  emlrtAssign(&f_y, m);
  emlrtSetFieldR2017b(y, 0, "w_lin", f_y, 4);
  g_y = nullptr;
  m = emlrtCreateDoubleScalar(u.w_ang);
  emlrtAssign(&g_y, m);
  emlrtSetFieldR2017b(y, 0, "w_ang", g_y, 5);
  h_y = nullptr;
  m = emlrtCreateNumericArray(2, (const void *)&iv1[0], mxDOUBLE_CLASS, mxREAL);
  pData = emlrtMxGetPr(m);
  b_i = 0;
  for (int32_T i{0}; i < 9; i++) {
    for (int32_T c_i{0}; c_i < 9; c_i++) {
      pData[b_i + c_i] = u.Wq[c_i + 9 * i];
    }
    b_i += 9;
  }
  emlrtAssign(&h_y, m);
  emlrtSetFieldR2017b(y, 0, "Wq", h_y, 6);
  i_y = nullptr;
  m = emlrtCreateNumericArray(2, (const void *)&iv2[0], mxDOUBLE_CLASS, mxREAL);
  pData = emlrtMxGetPr(m);
  b_i = 0;
  for (int32_T i{0}; i < 6; i++) {
    for (int32_T c_i{0}; c_i < 6; c_i++) {
      pData[b_i + c_i] = u.Wt[c_i + 6 * i];
    }
    b_i += 6;
  }
  emlrtAssign(&i_y, m);
  emlrtSetFieldR2017b(y, 0, "Wt", i_y, 7);
  j_y = nullptr;
  m = emlrtCreateDoubleScalar(u.nu);
  emlrtAssign(&j_y, m);
  emlrtSetFieldR2017b(y, 0, "nu", j_y, 8);
  k_y = nullptr;
  m = emlrtCreateDoubleScalar(u.max_dotq);
  emlrtAssign(&k_y, m);
  emlrtSetFieldR2017b(y, 0, "max_dotq", k_y, 9);
  l_y = nullptr;
  m = emlrtCreateDoubleScalar(u.max_V);
  emlrtAssign(&l_y, m);
  emlrtSetFieldR2017b(y, 0, "max_V", l_y, 10);
  m_y = nullptr;
  m = emlrtCreateDoubleScalar(u.max_Omegaz);
  emlrtAssign(&m_y, m);
  emlrtSetFieldR2017b(y, 0, "max_Omegaz", m_y, 11);
  n_y = nullptr;
  m = emlrtCreateNumericArray(1, (const void *)&i1, mxDOUBLE_CLASS, mxREAL);
  pData = emlrtMxGetPr(m);
  for (int32_T i{0}; i < 6; i++) {
    pData[i] = u.qmin[i];
  }
  emlrtAssign(&n_y, m);
  emlrtSetFieldR2017b(y, 0, "qmin", n_y, 12);
  o_y = nullptr;
  m = emlrtCreateNumericArray(1, (const void *)&i2, mxDOUBLE_CLASS, mxREAL);
  pData = emlrtMxGetPr(m);
  for (int32_T i{0}; i < 6; i++) {
    pData[i] = u.qmax[i];
  }
  emlrtAssign(&o_y, m);
  emlrtSetFieldR2017b(y, 0, "qmax", o_y, 13);
  p_y = nullptr;
  m = emlrtCreateDoubleScalar(u.qddot_max);
  emlrtAssign(&p_y, m);
  emlrtSetFieldR2017b(y, 0, "qddot_max", p_y, 14);
  q_y = nullptr;
  m = emlrtCreateDoubleScalar(u.a_lin_max);
  emlrtAssign(&q_y, m);
  emlrtSetFieldR2017b(y, 0, "a_lin_max", q_y, 15);
  r_y = nullptr;
  m = emlrtCreateDoubleScalar(u.alpha_max);
  emlrtAssign(&r_y, m);
  emlrtSetFieldR2017b(y, 0, "alpha_max", r_y, 16);
  s_y = nullptr;
  m = emlrtCreateNumericArray(1, (const void *)&i3, mxDOUBLE_CLASS, mxREAL);
  pData = emlrtMxGetPr(m);
  for (int32_T i{0}; i < 9; i++) {
    pData[i] = u.lb[i];
  }
  emlrtAssign(&s_y, m);
  emlrtSetFieldR2017b(y, 0, "lb", s_y, 17);
  t_y = nullptr;
  m = emlrtCreateNumericArray(1, (const void *)&i4, mxDOUBLE_CLASS, mxREAL);
  pData = emlrtMxGetPr(m);
  for (int32_T i{0}; i < 9; i++) {
    pData[i] = u.ub[i];
  }
  emlrtAssign(&t_y, m);
  emlrtSetFieldR2017b(y, 0, "ub", t_y, 18);
  emlrtSetFieldR2017b(y, 0, "optsQP", emlrt_marshallOut(sp, u.optsQP), 19);
  return y;
}

//
// Arguments    : const emlrtStack &sp
//                const struct12_T &u
// Return Type  : const mxArray *
//
static const mxArray *emlrt_marshallOut(const emlrtStack &sp,
                                        const struct12_T &u)
{
  static const int32_T iv[2]{1, 7};
  static const int32_T iv1[2]{0, 0};
  static const int32_T iv10[2]{1, 4};
  static const int32_T iv11[2]{1, 2};
  static const int32_T iv2[2]{1, 10};
  static const int32_T iv3[2]{1, 8};
  static const int32_T iv4[2]{1, 3};
  static const int32_T iv5[2]{1, 3};
  static const int32_T iv6[2]{1, 3};
  static const int32_T iv7[2]{0, 0};
  static const int32_T iv8[2]{0, 0};
  static const int32_T iv9[2]{0, 0};
  static const char_T *sv[32]{"NonFiniteSupport",
                              "IterDisplaySQP",
                              "InitDamping",
                              "FiniteDifferenceType",
                              "SpecifyObjectiveGradient",
                              "ScaleProblem",
                              "SpecifyConstraintGradient",
                              "FiniteDifferenceStepSize",
                              "MaxFunctionEvaluations",
                              "TypicalX",
                              "IterDisplayQP",
                              "PricingTolerance",
                              "Algorithm",
                              "ObjectiveLimit",
                              "ConstraintTolerance",
                              "OptimalityTolerance",
                              "StepTolerance",
                              "MaxIterations",
                              "FunctionTolerance",
                              "SolverName",
                              "CheckGradients",
                              "Diagnostics",
                              "DiffMaxChange",
                              "DiffMinChange",
                              "Display",
                              "FunValCheck",
                              "PlotFcn",
                              "OutputFcn",
                              "UseParallel",
                              "JacobianMultiplyFcn",
                              "LinearSolver",
                              "SubproblemAlgorithm"};
  const mxArray *ab_y;
  const mxArray *b_y;
  const mxArray *bb_y;
  const mxArray *c_y;
  const mxArray *cb_y;
  const mxArray *d_y;
  const mxArray *db_y;
  const mxArray *e_y;
  const mxArray *eb_y;
  const mxArray *f_y;
  const mxArray *fb_y;
  const mxArray *g_y;
  const mxArray *gb_y;
  const mxArray *h_y;
  const mxArray *hb_y;
  const mxArray *i_y;
  const mxArray *j_y;
  const mxArray *k_y;
  const mxArray *l_y;
  const mxArray *m;
  const mxArray *m_y;
  const mxArray *n_y;
  const mxArray *o_y;
  const mxArray *p_y;
  const mxArray *q_y;
  const mxArray *r_y;
  const mxArray *s_y;
  const mxArray *t_y;
  const mxArray *u_y;
  const mxArray *v_y;
  const mxArray *w_y;
  const mxArray *x_y;
  const mxArray *y;
  const mxArray *y_y;
  y = nullptr;
  emlrtAssign(&y, emlrtCreateStructMatrix(1, 1, 32, (const char_T **)&sv[0]));
  b_y = nullptr;
  m = emlrtCreateLogicalScalar(u.NonFiniteSupport);
  emlrtAssign(&b_y, m);
  emlrtSetFieldR2017b(y, 0, "NonFiniteSupport", b_y, 0);
  c_y = nullptr;
  m = emlrtCreateLogicalScalar(u.IterDisplaySQP);
  emlrtAssign(&c_y, m);
  emlrtSetFieldR2017b(y, 0, "IterDisplaySQP", c_y, 1);
  d_y = nullptr;
  m = emlrtCreateDoubleScalar(u.InitDamping);
  emlrtAssign(&d_y, m);
  emlrtSetFieldR2017b(y, 0, "InitDamping", d_y, 2);
  e_y = nullptr;
  m = emlrtCreateCharArray(2, &iv[0]);
  emlrtInitCharArrayR2013a((emlrtConstCTX)&sp, 7, m,
                           &u.FiniteDifferenceType[0]);
  emlrtAssign(&e_y, m);
  emlrtSetFieldR2017b(y, 0, "FiniteDifferenceType", e_y, 3);
  f_y = nullptr;
  m = emlrtCreateLogicalScalar(u.SpecifyObjectiveGradient);
  emlrtAssign(&f_y, m);
  emlrtSetFieldR2017b(y, 0, "SpecifyObjectiveGradient", f_y, 4);
  g_y = nullptr;
  m = emlrtCreateLogicalScalar(u.ScaleProblem);
  emlrtAssign(&g_y, m);
  emlrtSetFieldR2017b(y, 0, "ScaleProblem", g_y, 5);
  h_y = nullptr;
  m = emlrtCreateLogicalScalar(u.SpecifyConstraintGradient);
  emlrtAssign(&h_y, m);
  emlrtSetFieldR2017b(y, 0, "SpecifyConstraintGradient", h_y, 6);
  i_y = nullptr;
  m = emlrtCreateDoubleScalar(u.FiniteDifferenceStepSize);
  emlrtAssign(&i_y, m);
  emlrtSetFieldR2017b(y, 0, "FiniteDifferenceStepSize", i_y, 7);
  j_y = nullptr;
  m = emlrtCreateDoubleScalar(u.MaxFunctionEvaluations);
  emlrtAssign(&j_y, m);
  emlrtSetFieldR2017b(y, 0, "MaxFunctionEvaluations", j_y, 8);
  k_y = nullptr;
  m = emlrtCreateNumericArray(2, (const void *)&iv1[0], mxDOUBLE_CLASS, mxREAL);
  emlrtAssign(&k_y, m);
  emlrtSetFieldR2017b(y, 0, "TypicalX", k_y, 9);
  l_y = nullptr;
  m = emlrtCreateLogicalScalar(u.IterDisplayQP);
  emlrtAssign(&l_y, m);
  emlrtSetFieldR2017b(y, 0, "IterDisplayQP", l_y, 10);
  m_y = nullptr;
  m = emlrtCreateDoubleScalar(u.PricingTolerance);
  emlrtAssign(&m_y, m);
  emlrtSetFieldR2017b(y, 0, "PricingTolerance", m_y, 11);
  n_y = nullptr;
  m = emlrtCreateCharArray(2, &iv2[0]);
  emlrtInitCharArrayR2013a((emlrtConstCTX)&sp, 10, m, &u.Algorithm[0]);
  emlrtAssign(&n_y, m);
  emlrtSetFieldR2017b(y, 0, "Algorithm", n_y, 12);
  o_y = nullptr;
  m = emlrtCreateDoubleScalar(u.ObjectiveLimit);
  emlrtAssign(&o_y, m);
  emlrtSetFieldR2017b(y, 0, "ObjectiveLimit", o_y, 13);
  p_y = nullptr;
  m = emlrtCreateDoubleScalar(u.ConstraintTolerance);
  emlrtAssign(&p_y, m);
  emlrtSetFieldR2017b(y, 0, "ConstraintTolerance", p_y, 14);
  q_y = nullptr;
  m = emlrtCreateDoubleScalar(u.OptimalityTolerance);
  emlrtAssign(&q_y, m);
  emlrtSetFieldR2017b(y, 0, "OptimalityTolerance", q_y, 15);
  r_y = nullptr;
  m = emlrtCreateDoubleScalar(u.StepTolerance);
  emlrtAssign(&r_y, m);
  emlrtSetFieldR2017b(y, 0, "StepTolerance", r_y, 16);
  s_y = nullptr;
  m = emlrtCreateDoubleScalar(u.MaxIterations);
  emlrtAssign(&s_y, m);
  emlrtSetFieldR2017b(y, 0, "MaxIterations", s_y, 17);
  t_y = nullptr;
  m = emlrtCreateDoubleScalar(u.FunctionTolerance);
  emlrtAssign(&t_y, m);
  emlrtSetFieldR2017b(y, 0, "FunctionTolerance", t_y, 18);
  u_y = nullptr;
  m = emlrtCreateCharArray(2, &iv3[0]);
  emlrtInitCharArrayR2013a((emlrtConstCTX)&sp, 8, m, &u.SolverName[0]);
  emlrtAssign(&u_y, m);
  emlrtSetFieldR2017b(y, 0, "SolverName", u_y, 19);
  v_y = nullptr;
  m = emlrtCreateLogicalScalar(u.CheckGradients);
  emlrtAssign(&v_y, m);
  emlrtSetFieldR2017b(y, 0, "CheckGradients", v_y, 20);
  w_y = nullptr;
  m = emlrtCreateCharArray(2, &iv4[0]);
  emlrtInitCharArrayR2013a((emlrtConstCTX)&sp, 3, m, &u.Diagnostics[0]);
  emlrtAssign(&w_y, m);
  emlrtSetFieldR2017b(y, 0, "Diagnostics", w_y, 21);
  x_y = nullptr;
  m = emlrtCreateDoubleScalar(u.DiffMaxChange);
  emlrtAssign(&x_y, m);
  emlrtSetFieldR2017b(y, 0, "DiffMaxChange", x_y, 22);
  y_y = nullptr;
  m = emlrtCreateDoubleScalar(u.DiffMinChange);
  emlrtAssign(&y_y, m);
  emlrtSetFieldR2017b(y, 0, "DiffMinChange", y_y, 23);
  ab_y = nullptr;
  m = emlrtCreateCharArray(2, &iv5[0]);
  emlrtInitCharArrayR2013a((emlrtConstCTX)&sp, 3, m, &u.Display[0]);
  emlrtAssign(&ab_y, m);
  emlrtSetFieldR2017b(y, 0, "Display", ab_y, 24);
  bb_y = nullptr;
  m = emlrtCreateCharArray(2, &iv6[0]);
  emlrtInitCharArrayR2013a((emlrtConstCTX)&sp, 3, m, &u.FunValCheck[0]);
  emlrtAssign(&bb_y, m);
  emlrtSetFieldR2017b(y, 0, "FunValCheck", bb_y, 25);
  cb_y = nullptr;
  m = emlrtCreateNumericArray(2, (const void *)&iv7[0], mxDOUBLE_CLASS, mxREAL);
  emlrtAssign(&cb_y, m);
  emlrtSetFieldR2017b(y, 0, "PlotFcn", cb_y, 26);
  db_y = nullptr;
  m = emlrtCreateNumericArray(2, (const void *)&iv8[0], mxDOUBLE_CLASS, mxREAL);
  emlrtAssign(&db_y, m);
  emlrtSetFieldR2017b(y, 0, "OutputFcn", db_y, 27);
  eb_y = nullptr;
  m = emlrtCreateLogicalScalar(u.UseParallel);
  emlrtAssign(&eb_y, m);
  emlrtSetFieldR2017b(y, 0, "UseParallel", eb_y, 28);
  fb_y = nullptr;
  m = emlrtCreateNumericArray(2, (const void *)&iv9[0], mxDOUBLE_CLASS, mxREAL);
  emlrtAssign(&fb_y, m);
  emlrtSetFieldR2017b(y, 0, "JacobianMultiplyFcn", fb_y, 29);
  gb_y = nullptr;
  m = emlrtCreateCharArray(2, &iv10[0]);
  emlrtInitCharArrayR2013a((emlrtConstCTX)&sp, 4, m, &u.LinearSolver[0]);
  emlrtAssign(&gb_y, m);
  emlrtSetFieldR2017b(y, 0, "LinearSolver", gb_y, 30);
  hb_y = nullptr;
  m = emlrtCreateCharArray(2, &iv11[0]);
  emlrtInitCharArrayR2013a((emlrtConstCTX)&sp, 2, m, &u.SubproblemAlgorithm[0]);
  emlrtAssign(&hb_y, m);
  emlrtSetFieldR2017b(y, 0, "SubproblemAlgorithm", hb_y, 31);
  return y;
}

//
// Arguments    : const mxArray *prhs
//                const mxArray **plhs
// Return Type  : void
//
void wbqp_init_api(const mxArray *prhs, const mxArray **plhs)
{
  emlrtStack st{
      nullptr, // site
      nullptr, // tls
      nullptr  // prev
  };
  struct10_T cfg;
  struct11_T qp;
  st.tls = emlrtRootTLSGlobal;
  // Marshall function inputs
  emlrt_marshallIn(st, emlrtAliasP(prhs), "cfg", cfg);
  // Invoke the target function
  wbqp_init(&cfg, &qp);
  // Marshall function outputs
  *plhs = emlrt_marshallOut(st, qp);
}

//
// Arguments    : void
// Return Type  : void
//
void wbqp_init_atexit()
{
  emlrtStack st{
      nullptr, // site
      nullptr, // tls
      nullptr  // prev
  };
  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtPushHeapReferenceStackR2021a(&st, false, nullptr,
                                    (void *)&emlrtExitTimeCleanupDtorFcn,
                                    nullptr, nullptr, nullptr);
  emlrtEnterRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
  wbqp_init_xil_terminate();
  wbqp_init_xil_shutdown();
  emlrtExitTimeCleanup(&emlrtContextGlobal);
}

//
// Arguments    : void
// Return Type  : void
//
void wbqp_init_initialize()
{
  emlrtStack st{
      nullptr, // site
      nullptr, // tls
      nullptr  // prev
  };
  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtClearAllocCountR2012b(&st, false, 0U, nullptr);
  emlrtEnterRtStackR2012b(&st);
  emlrtFirstTimeR2012b(emlrtRootTLSGlobal);
}

//
// Arguments    : void
// Return Type  : void
//
void wbqp_init_terminate()
{
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

//
// File trailer for _coder_wbqp_init_api.cpp
//
// [EOF]
//
