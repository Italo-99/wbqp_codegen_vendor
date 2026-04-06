//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: main.cpp
//
// MATLAB Coder version            : 24.1
// C/C++ source code generated on  : 10-Sep-2025 16:14:33
//

/*************************************************************************/
/* This automatically generated example C++ main file shows how to call  */
/* entry-point functions that MATLAB Coder generated. You must customize */
/* this file for your application. Do not modify this file directly.     */
/* Instead, make a copy of this file, modify it, and integrate it into   */
/* your development environment.                                         */
/*                                                                       */
/* This file initializes entry-point function arguments to a default     */
/* size and value before calling the entry-point functions. It does      */
/* not store or use any values returned from the entry-point functions.  */
/* If necessary, it does pre-allocate memory for returned values.        */
/* You can use this file as a starting point for a main function that    */
/* you can deploy in your application.                                   */
/*                                                                       */
/* After you copy the file, and before you deploy it, you must make the  */
/* following changes:                                                    */
/* * For variable-size function arguments, change the example sizes to   */
/* the sizes that your application requires.                             */
/* * Change the example values of function arguments to the values that  */
/* your application requires.                                            */
/* * If the entry-point functions return values, store these values or   */
/* otherwise use them as required by your application.                   */
/*                                                                       */
/*************************************************************************/

// Include Files
#include "main.h"
#include "rt_nonfinite.h"
#include "wbqp_solve.h"
#include "wbqp_solve_terminate.h"
#include "wbqp_solve_types.h"
#include "coder_bounded_array.h"
#include <algorithm>

// Function Declarations
static void argInit_1xd12_int8_T(signed char result_data[], int result_size[2]);

static void argInit_6x1_real_T(double result[6]);

static void argInit_6x6_real_T(double result[36]);

static void argInit_6x9_real_T(double result[54]);

static void argInit_6xd12_real_T(double result_data[], int result_size[2]);

static void argInit_9x1_real_T(double result[9]);

static void argInit_9x9_real_T(double result[81]);

static signed char argInit_int8_T();

static double argInit_real_T();

static void argInit_struct0_T(struct0_T &result);

static void argInit_struct1_T(struct1_T &result);

// Function Definitions
//
// Arguments    : signed char result_data[]
//                int result_size[2]
// Return Type  : void
//
static void argInit_1xd12_int8_T(signed char result_data[], int result_size[2])
{
  // Set the size of the array.
  // Change this size to the value that the application requires.
  result_size[0] = 1;
  result_size[1] = 2;
  // Loop over the array to initialize each element.
  for (int idx1{0}; idx1 < 2; idx1++) {
    // Set the value of the array element.
    // Change this value to the value that the application requires.
    result_data[idx1] = argInit_int8_T();
  }
}

//
// Arguments    : double result[6]
// Return Type  : void
//
static void argInit_6x1_real_T(double result[6])
{
  // Loop over the array to initialize each element.
  for (int idx0{0}; idx0 < 6; idx0++) {
    // Set the value of the array element.
    // Change this value to the value that the application requires.
    result[idx0] = argInit_real_T();
  }
}

//
// Arguments    : double result[36]
// Return Type  : void
//
static void argInit_6x6_real_T(double result[36])
{
  // Loop over the array to initialize each element.
  for (int i{0}; i < 36; i++) {
    // Set the value of the array element.
    // Change this value to the value that the application requires.
    result[i] = argInit_real_T();
  }
}

//
// Arguments    : double result[54]
// Return Type  : void
//
static void argInit_6x9_real_T(double result[54])
{
  // Loop over the array to initialize each element.
  for (int i{0}; i < 54; i++) {
    // Set the value of the array element.
    // Change this value to the value that the application requires.
    result[i] = argInit_real_T();
  }
}

//
// Arguments    : double result_data[]
//                int result_size[2]
// Return Type  : void
//
static void argInit_6xd12_real_T(double result_data[], int result_size[2])
{
  // Set the size of the array.
  // Change this size to the value that the application requires.
  result_size[0] = 6;
  result_size[1] = 2;
  // Loop over the array to initialize each element.
  for (int i{0}; i < 12; i++) {
    // Set the value of the array element.
    // Change this value to the value that the application requires.
    result_data[i] = argInit_real_T();
  }
}

//
// Arguments    : double result[9]
// Return Type  : void
//
static void argInit_9x1_real_T(double result[9])
{
  // Loop over the array to initialize each element.
  for (int idx0{0}; idx0 < 9; idx0++) {
    // Set the value of the array element.
    // Change this value to the value that the application requires.
    result[idx0] = argInit_real_T();
  }
}

//
// Arguments    : double result[81]
// Return Type  : void
//
static void argInit_9x9_real_T(double result[81])
{
  // Loop over the array to initialize each element.
  for (int i{0}; i < 81; i++) {
    // Set the value of the array element.
    // Change this value to the value that the application requires.
    result[i] = argInit_real_T();
  }
}

//
// Arguments    : void
// Return Type  : signed char
//
static signed char argInit_int8_T()
{
  return 0;
}

//
// Arguments    : void
// Return Type  : double
//
static double argInit_real_T()
{
  return 0.0;
}

//
// Arguments    : struct0_T &result
// Return Type  : void
//
static void argInit_struct0_T(struct0_T &result)
{
  double result_tmp;
  // Set the value of each structure field.
  // Change this value to the value that the application requires.
  result_tmp = argInit_real_T();
  result.nu = result_tmp;
  result.max_dotq = result_tmp;
  argInit_6x1_real_T(result.qmin);
  result.qddot_max = result_tmp;
  argInit_9x1_real_T(result.lb);
  result.alpha_xy = result_tmp;
  result.alpha_yaw = result_tmp;
  result.max_V = result_tmp;
  result.max_Omegaz = result_tmp;
  result.a_lin_max = result_tmp;
  result.alpha_max = result_tmp;
  argInit_1xd12_int8_T(result.cols.data, result.cols.size);
  result.beta_arm = result_tmp;
  argInit_9x9_real_T(result.Wq);
  argInit_6x6_real_T(result.Wt);
  for (int i{0}; i < 6; i++) {
    result.qmax[i] = result.qmin[i];
  }
  std::copy(&result.lb[0], &result.lb[9], &result.ub[0]);
}

//
// Arguments    : struct1_T &result
// Return Type  : void
//
static void argInit_struct1_T(struct1_T &result)
{
  // Set the value of each structure field.
  // Change this value to the value that the application requires.
  argInit_6x1_real_T(result.q);
  argInit_6xd12_real_T(result.J_full.data, result.J_full.size);
  argInit_9x1_real_T(result.dotq_prev);
  result.dt = argInit_real_T();
  argInit_6x9_real_T(result.J);
  for (int i{0}; i < 6; i++) {
    result.u_star[i] = result.q[i];
  }
}

//
// Arguments    : int argc
//                char **argv
// Return Type  : int
//
int main(int, char **)
{
  // The initialize function is being called automatically from your entry-point
  // function. So, a call to initialize is not included here. Invoke the
  // entry-point functions.
  // You can call entry-point functions multiple times.
  main_wbqp_solve();
  // Terminate the application.
  // You do not need to do this more than one time.
  wbqp_solve_terminate();
  return 0;
}

//
// Arguments    : void
// Return Type  : void
//
void main_wbqp_solve()
{
  struct0_T r;
  struct1_T r1;
  struct2_T dbg;
  double dotq_star_opt[9];
  // Initialize function 'wbqp_solve' input arguments.
  // Initialize function input argument 'qp'.
  // Initialize function input argument 'in'.
  // Call the entry-point 'wbqp_solve'.
  argInit_struct0_T(r);
  argInit_struct1_T(r1);
  wbqp_solve(&r, &r1, dotq_star_opt, &dbg);
}

//
// File trailer for main.cpp
//
// [EOF]
//
