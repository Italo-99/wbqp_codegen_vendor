//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: main.cpp
//
// MATLAB Coder version            : 24.1
// C/C++ source code generated on  : 10-Sep-2025 15:23:17
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
#include "wbqp_init.h"
#include "wbqp_init_terminate.h"
#include "wbqp_init_types.h"

// Function Declarations
static void argInit_1x9_real_T(double result[9]);

static void argInit_6x1_real_T(double result[6]);

static double argInit_real_T();

static void argInit_struct0_T(struct10_T &result);

// Function Definitions
//
// Arguments    : double result[9]
// Return Type  : void
//
static void argInit_1x9_real_T(double result[9])
{
  // Loop over the array to initialize each element.
  for (int idx1{0}; idx1 < 9; idx1++) {
    // Set the value of the array element.
    // Change this value to the value that the application requires.
    result[idx1] = argInit_real_T();
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
// Arguments    : void
// Return Type  : double
//
static double argInit_real_T()
{
  return 0.0;
}

//
// Arguments    : struct10_T &result
// Return Type  : void
//
static void argInit_struct0_T(struct10_T &result)
{
  double result_tmp;
  // Set the value of each structure field.
  // Change this value to the value that the application requires.
  result_tmp = argInit_real_T();
  result.alpha_xy = result_tmp;
  result.alpha_yaw = result_tmp;
  result.w_lin = result_tmp;
  result.w_ang = result_tmp;
  result.nu = result_tmp;
  result.max_dotq = result_tmp;
  result.max_V = result_tmp;
  result.max_Omegaz = result_tmp;
  result.qddot_max = result_tmp;
  result.a_lin_max = result_tmp;
  result.alpha_max = result_tmp;
  argInit_6x1_real_T(result.qmin);
  argInit_1x9_real_T(result.cols);
  result.beta_arm = result_tmp;
  for (int i{0}; i < 6; i++) {
    result.qmax[i] = result.qmin[i];
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
  main_wbqp_init();
  // Terminate the application.
  // You do not need to do this more than one time.
  wbqp_init_terminate();
  return 0;
}

//
// Arguments    : void
// Return Type  : void
//
void main_wbqp_init()
{
  struct10_T r;
  struct11_T qp;
  // Initialize function 'wbqp_init' input arguments.
  // Initialize function input argument 'cfg'.
  // Call the entry-point 'wbqp_init'.
  argInit_struct0_T(r);
  wbqp_init(&r, &qp);
}

//
// File trailer for main.cpp
//
// [EOF]
//
