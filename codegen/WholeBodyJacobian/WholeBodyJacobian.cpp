//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: WholeBodyJacobian.cpp
//
// MATLAB Coder version            : 24.1
// C/C++ source code generated on  : 10-Sep-2025 14:53:20
//

// Include Files
#include "WholeBodyJacobian.h"
#include <cmath>

// Function Declarations
static void ft_1(const double ct[190], double A[72]);

// Function Definitions
//
// Arguments    : const double ct[190]
//                double A[72]
// Return Type  : void
//
static void ft_1(const double ct[190], double A[72])
{
  double b_t667_tmp;
  double t353;
  double t414;
  double t518;
  double t519;
  double t546;
  double t569;
  double t580;
  double t582;
  double t583;
  double t584;
  double t588;
  double t599;
  double t600;
  double t601;
  double t602;
  double t603;
  double t604;
  double t605;
  double t607;
  double t610;
  double t617;
  double t622;
  double t623;
  double t624;
  double t630;
  double t632;
  double t639;
  double t654;
  double t655;
  double t656;
  double t663;
  double t665;
  double t666;
  double t667;
  double t667_tmp;
  double t667_tmp_tmp;
  double t668;
  double t683_tmp;
  double t685;
  t518 = ct[101] + ct[142];
  t546 = ct[97] + ct[160];
  t569 = (ct[118] + ct[141]) + ct[155];
  t580 = ((ct[113] + ct[114]) + ct[128]) + ct[148];
  t582 = (((ct[67] + ct[76]) + ct[77]) + ct[140]) + ct[156];
  t583 = ct[154] * ct[179];
  t584 = ct[20] * ct[179];
  t588 = ((ct[87] + ct[94]) + ct[103]) + ct[161];
  t599 = (ct[78] + ct[84]) + ct[177];
  t603 = ct[168] + ct[171];
  t604 = ct[167] + ct[172];
  t605 = ((ct[75] + ct[79]) + ct[80]) + ct[85];
  t630 = ((((t605 + ct[107]) + ct[111]) + ct[113]) + ct[115]) + ct[149];
  t639 = ((((t605 + ct[111]) + ct[113]) + ct[115]) + ct[130]) + ct[149];
  t353 = (ct[22] + ct[27]) + ct[44];
  t414 = (ct[51] + ct[58]) + ct[65];
  t519 = ct[102] + ct[143];
  t600 = (ct[79] + ct[83]) + t580;
  t605 = ct[139] - ct[157];
  t601 = ct[20] * ct[161] + -ct[154] * t605;
  t602 = ct[154] * ct[161] + ct[20] * t605;
  t607 = (ct[74] + ct[82]) + t599;
  t623 = ct[163] + t584;
  t632 = ct[169] + t584;
  t605 = ct[20] * ct[152] + ct[176];
  t610 = (ct[75] + ct[81]) + t600;
  t617 = ct[165] + ct[20] * t569;
  t622 = ct[162] + ct[20] * t582;
  t624 = ct[164] + ct[154] * t582;
  t654 = (-(ct[63] * ct[158]) + ct[56] * t588) + ct[23] * ct[182];
  t655 = (ct[72] * ct[158] + ct[73] * t588) + ct[57] * ct[182];
  t584 = ct[166] - ct[154] * t569;
  t656 = (ct[70] * ct[158] - ct[71] * t588) + ct[64] * ct[182];
  t663 = (ct[63] * t546 + ct[56] * t622) - ct[23] * t632;
  t665 = (ct[70] * t546 + ct[71] * t622) + ct[64] * t632;
  t667_tmp = ct[98] - ct[159];
  t667_tmp_tmp = ct[120] - ct[147];
  b_t667_tmp = t583 + ct[20] * t667_tmp_tmp;
  t667 = (-ct[70] * t667_tmp + ct[71] * t624) + ct[64] * b_t667_tmp;
  t668 = (ct[72] * t667_tmp + ct[73] * t624) + -ct[57] * b_t667_tmp;
  t666 = (ct[72] * t546 - ct[73] * t622) + ct[57] * t632;
  t582 = ct[152] * ct[154] +
         ct[20] *
             ((-ct[119] + ct[15] * (ct[76] + ct[77]) * 6.123233995736766E-17) +
              ct[106] * (ct[96] + ct[100]) * 6.123233995736766E-17);
  t683_tmp = (-(ct[56] * t624) + ct[23] * b_t667_tmp) + ct[63] * t667_tmp;
  t569 = (((ct[137] - ct[71] * ct[173]) + ct[64] * ct[174]) * t654 -
          ((ct[70] * ct[145] + -ct[71] * t582) + ct[64] * t617) * t663) +
         -((ct[70] * ct[144] - ct[71] * t605) + ct[64] * t584) * t683_tmp;
  t685 = (-(((ct[138] + ct[73] * ct[173]) + ct[57] * ct[174]) * t656) -
          ((ct[72] * ct[145] + ct[73] * t582) + ct[57] * t617) * t665) +
         ((ct[72] * ct[144] + ct[73] * t605) + ct[57] * t584) * t667;
  t605 = (-(((ct[134] + ct[56] * ct[173]) + ct[23] * ct[174]) * t655) +
          -t666 * ((-(ct[63] * ct[145]) + ct[23] * t617) + ct[56] * t582)) -
         ((-ct[153] + ct[56] * t605) + ct[23] * t584) * t668;
  A[0] = -ct[64] * t639 + ct[71] * ct[184];
  A[1] = ct[57] * t639 + ct[73] * ct[184];
  A[2] = -ct[23] * t639 - ct[56] * ct[184];
  t617 = t583 + ct[20] * (ct[95] - ct[147]);
  A[3] = (-t668 * (ct[56] * t617 + ct[23] * t624) -
          t655 * (ct[23] * ct[181] - ct[56] * ct[180])) +
         t666 * (ct[23] * t622 + ct[56] * t623);
  A[4] = (t654 * (ct[64] * ct[181] + ct[71] * ct[180]) +
          t663 * (ct[64] * t622 - ct[71] * t623)) +
         (ct[71] * t617 - ct[64] * t624) * t683_tmp;
  A[5] = (t667 * (ct[73] * t617 + ct[57] * t624) -
          t656 * (ct[57] * ct[181] - ct[73] * ct[180])) +
         t665 * (ct[57] * t622 + ct[73] * t623);
  A[6] = (-ct[70] * ct[136] - ct[64] * t610) + ct[71] * t607;
  A[7] = (ct[72] * ct[136] + ct[57] * t610) + ct[73] * t607;
  A[8] = (ct[63] * ct[136] - ct[23] * t610) - ct[56] * t607;
  A[9] = t605;
  A[10] = t569;
  A[11] = t685;
  A[12] = (-ct[70] * ct[133] - ct[64] * t600) + ct[71] * t599;
  A[13] = (ct[72] * ct[133] + ct[57] * t600) + ct[73] * t599;
  A[14] = (ct[63] * ct[133] - ct[23] * t600) - ct[56] * t599;
  A[15] = t605;
  A[16] = t569;
  A[17] = t685;
  A[18] = (-ct[70] * ct[125] - ct[64] * t580) + ct[71] * ct[177];
  A[19] = (ct[72] * ct[125] + ct[57] * t580) + ct[73] * ct[177];
  A[20] = (ct[63] * ct[125] - ct[23] * t580) - ct[56] * ct[177];
  A[21] = t605;
  A[22] = t569;
  A[23] = t685;
  t617 = ct[127] - ct[151];
  t569 = ct[105] - ct[150];
  A[24] = (-ct[70] * ct[110] + ct[64] * t617) + ct[71] * t569;
  A[25] = (ct[72] * ct[110] - ct[57] * t617) + ct[73] * t569;
  A[26] = (ct[63] * ct[110] + ct[23] * t617) - ct[56] * t569;
  t617 = ct[99] - ct[146];
  A[27] = (-t666 * ((ct[23] * t604 + ct[63] * t518) - ct[56] * t602) -
           t668 * ((ct[23] * t603 + ct[63] * t519) - ct[56] * t601)) +
          t655 * ((ct[63] * ct[93] + ct[23] * t667_tmp_tmp) - ct[56] * t617);
  A[28] = (-t663 * ((-ct[70] * t518 + ct[64] * t604) + ct[71] * t602) -
           ((-ct[70] * t519 + ct[64] * t603) + ct[71] * t601) * t683_tmp) -
          t654 * ((-ct[70] * ct[93] + ct[64] * t667_tmp_tmp) + ct[71] * t617);
  A[29] = (t665 * ((ct[72] * t518 - ct[57] * t604) + ct[73] * t602) -
           t667 * ((ct[72] * t519 - ct[57] * t603) + ct[73] * t601)) -
          t656 * ((ct[72] * ct[93] - ct[57] * t667_tmp_tmp) + ct[73] * t617);
  A[30] = 0.0;
  A[31] = 0.0;
  A[32] = 0.0;
  A[33] = t663 * t668 - t666 * t683_tmp;
  A[34] = -t663 * t667 - t665 * t683_tmp;
  A[35] = t665 * t668 + t666 * t667;
  A[36] = ct[3] * ct[7];
  A[37] = -ct[116] + ct[178];
  A[38] = ct[6];
  A[39] = 0.0;
  A[40] = 0.0;
  A[41] = 0.0;
  A[42] = ct[3] * ct[42];
  A[43] = ct[5];
  A[44] = -ct[121] + ct[175];
  A[45] = 0.0;
  A[46] = 0.0;
  A[47] = 0.0;
  A[48] = -ct[40];
  A[49] = ct[3] * ct[36];
  A[50] = ct[3] * ct[189];
  A[51] = 0.0;
  A[52] = 0.0;
  A[53] = 0.0;
  t617 = ct[14] - ct[16];
  t569 = ct[18] - ct[29];
  t605 = ct[183] * ct[186];
  t584 = (-ct[69] + ct[4] * t617) + t605 * t569;
  A[54] = ((((-ct[1] * ct[59] + ct[122] * ct[185]) + ct[135] * t630) -
            ct[0] * t617) -
           ct[2] * t569) +
          ct[170] * t584;
  t617 = ct[187] - ct[9];
  t569 = (ct[39] - ct[54]) + ct[25] * t617;
  A[55] = ((((ct[0] * ct[26] - ct[1] * ct[47]) - ct[108] * ct[170]) +
            ct[109] * t630) -
           ct[2] * t617) -
          ct[185] * t569;
  t617 = ct[19] - ct[28];
  t582 = (ct[43] - ct[52]) + ct[25] * t617;
  A[56] = ((((ct[0] * ct[31] - ct[1] * ct[46]) - ct[123] * ct[170]) +
            ct[124] * t630) -
           ct[2] * t617) -
          ct[185] * t582;
  A[57] = (t655 * ((-ct[123] * ct[158] + ct[124] * t588) + ct[182] * t582) -
           t666 * ((ct[123] * t546 + ct[124] * t622) - t632 * t582)) -
          t668 * ((-ct[124] * t624 + ct[123] * t667_tmp) + b_t667_tmp * t582);
  A[58] =
      (-t654 * ((-ct[122] * ct[182] + ct[135] * t588) + ct[158] * t584) -
       t663 * ((ct[122] * t632 + ct[135] * t622) - t546 * t584)) +
      ((ct[122] * b_t667_tmp + ct[135] * t624) + t667_tmp * t584) * t683_tmp;
  A[59] = (-t656 * ((-ct[108] * ct[158] + ct[109] * t588) + ct[182] * t569) +
           t665 * ((ct[108] * t546 + ct[109] * t622) - t632 * t569)) -
          t667 * ((-ct[109] * t624 + ct[108] * t667_tmp) + b_t667_tmp * t569);
  A[60] = ((((-ct[2] * ct[45] - ct[0] * ct[50]) + ct[1] * ct[60]) +
            ct[126] * ct[170]) -
           t414 * ct[185]) -
          ct[129] * t630;
  t617 = ct[188] - ct[37];
  t569 = (-ct[53] + ct[55]) + ct[8] * t617;
  A[61] = ((((ct[0] * ct[35] - ct[2] * ct[48]) - ct[104] * ct[185]) +
            ct[117] * t630) -
           ct[1] * t617) -
          ct[170] * t569;
  A[62] = ((((ct[0] * ct[33] + ct[1] * ct[62]) - ct[2] * ct[61]) +
            ct[131] * ct[170]) -
           ct[112] * ct[185]) +
          ct[132] * t630;
  A[63] =
      (t655 * ((ct[131] * ct[158] + ct[112] * ct[182]) + ct[132] * t588) +
       t666 * ((ct[131] * t546 + ct[112] * t632) - ct[132] * t622)) +
      t668 * ((-ct[112] * b_t667_tmp + ct[132] * t624) + ct[131] * t667_tmp);
  A[64] =
      (-t654 * ((ct[126] * ct[158] + t414 * ct[182]) - ct[129] * t588) +
       t663 * ((ct[126] * t546 + t414 * t632) + ct[129] * t622)) -
      ((t414 * b_t667_tmp + ct[129] * t624) - ct[126] * t667_tmp) * t683_tmp;
  A[65] = (-t656 * ((ct[104] * ct[182] + ct[117] * t588) - ct[158] * t569) +
           t665 * ((-ct[104] * t632 + ct[117] * t622) + t546 * t569)) -
          t667 * ((ct[104] * b_t667_tmp + t667_tmp * t569) - ct[117] * t624);
  A[66] = ((((-ct[0] * ct[11] + ct[2] * ct[30]) + ct[1] * ct[32]) +
            ct[92] * ct[170]) +
           ct[86] * ct[185]) -
          ct[91] * t630;
  A[67] = ((((-ct[0] * ct[10] + ct[2] * ct[24]) + ct[1] * ct[34]) +
            ct[90] * ct[170]) -
           ct[88] * t630) +
          t353 * ct[185];
  t617 = ct[13] - ct[17];
  t569 = (ct[38] - ct[68]) + t605 * t617;
  t584 = (-ct[41] + ct[66]) + ct[21] * ct[186] * t617;
  A[68] = ((((-ct[0] * ct[12] - ct[1] * ct[49]) + ct[89] * ct[185]) -
            ct[2] * t617) +
           ct[170] * t569) +
          t630 * t584;
  A[69] = (t655 * ((-ct[89] * ct[182] + ct[158] * t569) + t588 * t584) -
           t666 * ((ct[89] * t632 - t546 * t569) + t622 * t584)) +
          t668 * ((ct[89] * b_t667_tmp + t624 * t584) + t667_tmp * t569);
  A[70] =
      (t654 * ((-ct[92] * ct[158] + ct[86] * ct[182]) + ct[91] * t588) +
       t663 * ((ct[92] * t546 - ct[86] * t632) + ct[91] * t622)) +
      ((ct[86] * b_t667_tmp - ct[91] * t624) + ct[92] * t667_tmp) * t683_tmp;
  A[71] = (t656 * ((-ct[90] * ct[158] + t353 * ct[182]) + ct[88] * t588) -
           t665 * ((ct[90] * t546 + ct[88] * t622) - t353 * t632)) +
          t667 * ((t353 * b_t667_tmp - ct[88] * t624) + ct[90] * t667_tmp);
}

//
// WholeBodyJacobian
//     A = WholeBodyJacobian(IN1)
//
// Arguments    : const double in1[15]
//                double A[72]
// Return Type  : void
//
void WholeBodyJacobian(const double in1[15], double A[72])
{
  double b_in1[190];
  double t10;
  double t103;
  double t104;
  double t105;
  double t106;
  double t109;
  double t11;
  double t110;
  double t111;
  double t112;
  double t113;
  double t119;
  double t12;
  double t120;
  double t121;
  double t122;
  double t127_tmp;
  double t129_tmp;
  double t136;
  double t138;
  double t138_tmp;
  double t14;
  double t141;
  double t142;
  double t145;
  double t149;
  double t15;
  double t16;
  double t169;
  double t17;
  double t170;
  double t18;
  double t180;
  double t181;
  double t182;
  double t183;
  double t186;
  double t187;
  double t189;
  double t19;
  double t192;
  double t2;
  double t20;
  double t21;
  double t218;
  double t219;
  double t22;
  double t220;
  double t221;
  double t23;
  double t24;
  double t267;
  double t268;
  double t269;
  double t270;
  double t271;
  double t271_tmp;
  double t297;
  double t30;
  double t306;
  double t307;
  double t31;
  double t321;
  double t322;
  double t324;
  double t328;
  double t330;
  double t333;
  double t337;
  double t339;
  double t342;
  double t346;
  double t347;
  double t348;
  double t349;
  double t352;
  double t355;
  double t36;
  double t363;
  double t364;
  double t37;
  double t372;
  double t374;
  double t375;
  double t388;
  double t39;
  double t392;
  double t393;
  double t4;
  double t40;
  double t409;
  double t41;
  double t413;
  double t416;
  double t417;
  double t42;
  double t422;
  double t423;
  double t425;
  double t426;
  double t427;
  double t429;
  double t43;
  double t438;
  double t44;
  double t451;
  double t455;
  double t46;
  double t47;
  double t477;
  double t48;
  double t481;
  double t487;
  double t488;
  double t5;
  double t50;
  double t51;
  double t52;
  double t56;
  double t56_tmp;
  double t57;
  double t58;
  double t59;
  double t6;
  double t60;
  double t7;
  double t73;
  double t74;
  double t75;
  double t8;
  double t83;
  double t85;
  double t86;
  double t88;
  double t9;
  double t97;
  //     This function was generated by the Symbolic Math Toolbox version 24.2.
  //     01-Sep-2025 17:46:24
  t2 = std::cos(in1[3]);
  t4 = std::cos(in1[7]);
  t5 = std::cos(in1[8]);
  t6 = std::cos(in1[9]);
  t7 = std::cos(in1[10]);
  t8 = std::cos(in1[11]);
  t9 = std::cos(in1[12]);
  t10 = std::cos(in1[13]);
  t11 = std::cos(in1[14]);
  t12 = std::sin(in1[3]);
  t14 = std::sin(in1[7]);
  t15 = std::sin(in1[8]);
  t16 = std::sin(in1[9]);
  t17 = std::sin(in1[10]);
  t18 = std::sin(in1[11]);
  t19 = std::sin(in1[12]);
  t20 = std::sin(in1[13]);
  t21 = std::sin(in1[14]);
  t22 = in1[3] + in1[4];
  t23 = in1[4] + in1[5];
  t24 = t10 * t10;
  t30 = in1[5] + t22;
  t31 = in1[6] + t23;
  t36 = t6 * t8;
  t37 = t9 * t11;
  t40 = t6 * t18;
  t41 = t8 * t16;
  t42 = t9 * t21;
  t43 = t11 * t19;
  t47 = t16 * t18;
  t48 = t19 * t21;
  t52 = in1[3] - in1[4];
  t56_tmp = t10 * t19;
  t56 = t56_tmp * t20;
  t59 = t10 * t20 * t21;
  t60 = t23 - in1[3];
  t355 = t2 * 3.749399456654644E-33;
  t409 = t12 * 0.1333;
  t39 = std::cos(t31);
  t44 = in1[6] + t30;
  t46 = std::sin(t31);
  t57 = t20 * t42;
  t58 = t20 * t43;
  t31 -= in1[3];
  t83 = t24 * t37;
  t85 = t24 * t42;
  t86 = t24 * t43;
  t88 = t24 * t48;
  t328 = std::cos(t22) * 0.2125;
  t50 = std::cos(t44);
  t51 = std::sin(t44);
  t73 = t14 * t39;
  t74 = t4 * t46;
  t75 = t14 * t46;
  t44 = std::cos(t31);
  t97 = std::sin(t31);
  t103 = t36 + t17 * t47;
  t104 = t47 + t17 * t36;
  t105 = t37 + t20 * t48;
  t106 = t48 + t20 * t37;
  t121 = t56 + t85;
  t122 = t59 + t86;
  t297 = t39 * 6.123233995736766E-17;
  t337 = std::cos(t30) * 0.1961;
  t339 = std::sin(t52) * 0.2125;
  t342 = std::cos(t52) * 0.2125;
  t347 = std::cos(t60) * 0.1961;
  t348 = std::sin(t60) * 0.1961;
  t109 = t40 - t17 * t41;
  t110 = t41 - t17 * t40;
  t111 = t42 - t58;
  t112 = t43 - t57;
  t113 = t106 * t106;
  t119 = t20 * t105;
  t120 = t20 * t20 - t83;
  t127_tmp = t9 * t10;
  t31 = t127_tmp * t105;
  t129_tmp = t10 * t11;
  t36 = t129_tmp * t105;
  t136 = t56_tmp * t106;
  t138_tmp = t10 * t21;
  t138 = t138_tmp * t106;
  t47 = t105 * t106;
  t37 = t50 * 8.1129638414606682E+31;
  t48 = t44 * 8.1129638414606682E+31;
  t306 = t74 * 6.123233995736766E-17;
  t307 = t75 * 6.123233995736766E-17;
  t330 = t50 * 0.5;
  t52 = t51 * 0.5;
  t333 = t44 * 0.5;
  t60 = t97 * 0.5;
  t372 = t50 * 3.061616997868383E-17;
  t374 = t51 * 3.061616997868383E-17;
  t388 = t97 * 3.061616997868383E-17;
  t392 = t44 * 3.061616997868383E-17;
  t413 = t51 * 0.049850000000000012;
  t416 = t44 * 0.04985;
  t417 = t97 * 0.04985;
  t141 = t20 * t111;
  t142 = t20 * t112;
  t145 = t127_tmp * t111;
  t149 = t129_tmp * t112;
  t40 = t56_tmp * t111;
  t41 = t138_tmp * t112;
  t169 = t127_tmp * t20 + t127_tmp * t106;
  t170 = t129_tmp * t20 + t129_tmp * t106;
  t180 = t106 * t111;
  t181 = t106 * t112;
  t192 = t111 * t112;
  t346 = t37 + t48;
  t363 = t4 * (t297 + 6.123233995736766E-17);
  t364 = t14 * (t297 + 6.123233995736766E-17);
  t393 = (t73 - t46 * 6.123233995736766E-17) + t306;
  t422 = t330 + t333;
  t423 = t52 + t60;
  t438 =
      (t73 * 0.0996 + t74 * 6.098741059753819E-18) - t46 * 0.099700000000000011;
  t451 = (t46 + t73 * 6.123233995736766E-17) + t74 * 3.749399456654644E-33;
  t477 = t372 + t392;
  t44 = (-t12 + t374) + t388;
  t182 = t9 * t19 * t24 + t127_tmp * t112;
  t183 = t11 * t21 * t24 + t129_tmp * t111;
  t186 = t24 * (t19 * t19) - t31;
  t187 = t24 * (t21 * t21) - t36;
  t218 = t112 * t112 - t31;
  t219 = t111 * t111 - t36;
  t220 = t86 + t180;
  t221 = t85 + t181;
  t267 = t40 + t47;
  t268 = t56_tmp * t105 + t105 * t112;
  t269 = t41 + t47;
  t270 = t138_tmp * t105 + t105 * t111;
  t271_tmp = t6 * t7;
  t271 = (-(t271_tmp * t9 * t10) + t20 * t104) + t56_tmp * t110;
  t321 = t4 * t39 - t307;
  t322 = (t129_tmp * t104 + t271_tmp * t106) + t110 * t111;
  t324 = (t271_tmp * t112 - t138_tmp * t104) + t105 * t110;
  t349 = t37 - t48;
  t352 = t51 * 8.1129638414606682E+31 - t97 * 8.1129638414606682E+31;
  t47 = t74 + t364;
  t375 = t4 * t346 / 1.622592768292134E+32;
  t425 = t52 - t60;
  t426 = t4 * t422;
  t427 = t14 * t422;
  t429 = t14 * t423;
  t455 = std::cos(t23) * 0.3922 + t438;
  t31 = (t2 - t372) + t392;
  t481 = t4 * t477;
  t487 = t4 * t44;
  t488 = t14 * t44;
  t36 = t56 - t145;
  t189 = t59 - t149;
  t44 = t119 - t40;
  t97 = t119 - t41;
  t51 = t75 - t363;
  t119 = t4 * t352;
  t56 = t119 / 1.622592768292134E+32;
  t59 = t14 * t425;
  t86 = t306 + t364 * 6.123233995736766E-17;
  t85 = t4 * t31;
  t46 = t14 * t31;
  t24 = t487 * 0.0996;
  t60 = ((t39 - t307) + t363 * 6.123233995736766E-17) - 3.749399456654644E-33;
  t40 = t4 * t423 + t14 * t477;
  t41 = t427 + t487;
  t73 = t15 * t321 + t5 * t451;
  b_in1[0] = in1[0];
  b_in1[1] = in1[1];
  b_in1[2] = in1[2];
  b_in1[3] = t10;
  b_in1[4] = t104;
  b_in1[5] = t105;
  b_in1[6] = t106;
  b_in1[7] = t11;
  b_in1[8] = t110;
  b_in1[9] = t113;
  b_in1[10] = t120;
  b_in1[11] = t121;
  b_in1[12] = t122;
  b_in1[13] = t136;
  b_in1[14] = t138;
  b_in1[15] = t14;
  b_in1[16] = t141;
  b_in1[17] = t142;
  b_in1[18] = t145;
  b_in1[19] = t149;
  b_in1[20] = t15;
  b_in1[21] = t16;
  t52 = t7 * t8;
  b_in1[22] = t52 * t120;
  b_in1[23] = (t52 * t20 + t127_tmp * t17) - t7 * t10 * t18 * t19;
  b_in1[24] = t169;
  b_in1[25] = t17;
  b_in1[26] = t170;
  b_in1[27] = t17 * t169;
  b_in1[28] = t180;
  b_in1[29] = t181;
  b_in1[30] = t182;
  b_in1[31] = t183;
  b_in1[32] = t186;
  b_in1[33] = t187;
  b_in1[34] = t36;
  b_in1[35] = t189;
  b_in1[36] = t19;
  b_in1[37] = t192;
  b_in1[38] = t104 * t122;
  b_in1[39] = t52 * t170;
  b_in1[40] = t20;
  b_in1[41] = t109 * t122;
  b_in1[42] = t21;
  b_in1[43] = t52 * t183;
  t48 = t7 * t18;
  b_in1[44] = -(t48 * t36);
  b_in1[45] = t218;
  b_in1[46] = t219;
  b_in1[47] = t220;
  b_in1[48] = t221;
  b_in1[49] = t44;
  b_in1[50] = t97;
  b_in1[51] = t17 * t218;
  b_in1[52] = t48 * t219;
  b_in1[53] = t271_tmp * t221;
  b_in1[54] = t48 * t220;
  b_in1[55] = t104 * t189;
  b_in1[56] = (t7 * t9 * t10 * t16 + t56_tmp * t103) + t20 * t109;
  t37 = t52 * t10;
  b_in1[57] = (t37 * t21 + t48 * t105) + t17 * t112;
  b_in1[58] = -(t52 * t97);
  b_in1[59] = t267;
  b_in1[60] = t268;
  b_in1[61] = t269;
  b_in1[62] = t270;
  b_in1[63] = t271;
  b_in1[64] = (-(t37 * t11) + t17 * t106) + t48 * t111;
  b_in1[65] = t48 * t268;
  b_in1[66] = t103 * t44;
  b_in1[67] = -(t2 * 6.123233995736766E-17);
  b_in1[68] = t110 * t44;
  b_in1[69] = t110 * t267;
  b_in1[70] = t322;
  t37 = t7 * t16;
  b_in1[71] = (t129_tmp * t109 - t37 * t106) + t103 * t111;
  b_in1[72] = t324;
  b_in1[73] = (t138_tmp * t109 + t37 * t112) - t103 * t105;
  b_in1[74] = t328;
  b_in1[75] = std::sin(t22) * 0.2125;
  b_in1[76] = -t330;
  b_in1[77] = t333;
  b_in1[78] = t337;
  b_in1[79] = std::sin(t30) * 0.1961;
  b_in1[80] = t339;
  b_in1[81] = -t339;
  b_in1[82] = -t342;
  b_in1[83] = t348;
  b_in1[84] = -t347;
  b_in1[85] = -t348;
  b_in1[86] = (t52 * t121 + t17 * t182) - t48 * t186;
  b_in1[87] = t355;
  b_in1[88] = (t37 * t169 + t109 * t120) + t103 * t36;
  b_in1[89] = (t52 * t122 + -t17 * (t136 - t142)) + t48 * t44;
  b_in1[90] = (t104 * t120 - t271_tmp * t169) + t110 * t36;
  b_in1[91] = (t109 * t121 + t37 * t182) + t103 * t186;
  b_in1[92] = (t104 * t121 - t271_tmp * t182) + t110 * t186;
  b_in1[93] = t47;
  b_in1[94] = t372;
  b_in1[95] = t375;
  b_in1[96] = -t374;
  b_in1[97] = t5 * t47;
  b_in1[98] = t15 * t47;
  b_in1[99] = t56;
  b_in1[100] = t388;
  b_in1[101] = t5 * t51;
  b_in1[102] = t15 * t51;
  b_in1[103] = -t392;
  t47 = t88 - t192;
  b_in1[104] = (t52 * t189 + t17 * t221) + -t7 * t18 * t47;
  b_in1[105] = t119 * 6.1383239187509977E-34;
  b_in1[106] = t4;
  t36 = t14 * t352;
  b_in1[107] = t36 * 6.1383239187509977E-34;
  t31 = t83 - t113;
  t44 = -t6 * t7;
  b_in1[108] = (t44 * t31 + t104 * t170) + t110 * t220;
  b_in1[109] = (t37 * t31 + t109 * t170) + t103 * t220;
  b_in1[110] = t74 * 0.0996 + t364 * 0.0996;
  b_in1[111] = t2 * 0.1333;
  b_in1[112] = (t52 * t187 + t17 * t269) + t48 * t270;
  b_in1[113] = t50 * 0.049850000000000012;
  b_in1[114] = t416;
  b_in1[115] = -t416;
  b_in1[116] = t42;
  b_in1[117] = (t37 * t221 + t109 * t189) + t103 * t47;
  b_in1[118] = t422;
  b_in1[119] = t425;
  b_in1[120] = t426;
  b_in1[121] = t43;
  t47 = t138 - t141;
  t31 = t145 - t181;
  b_in1[122] = (t52 * t47 + t48 * t267) + -t17 * t31;
  t52 = t149 - t180;
  b_in1[123] = (t104 * t183 + t110 * t219) + t44 * t52;
  b_in1[124] = (t109 * t183 + t103 * t219) + t37 * t52;
  b_in1[125] = t438;
  b_in1[126] = (t271_tmp * t218 + t104 * t97) + t110 * t268;
  b_in1[127] = t426 * 0.0996;
  b_in1[128] = t429 * 0.0996;
  b_in1[129] = (-(t37 * t218) + t109 * t97) + t103 * t268;
  b_in1[130] = t59 * 0.0996;
  b_in1[131] = (-(t104 * t187) + t271_tmp * t269) + t110 * t270;
  b_in1[132] = (t109 * t187 + t37 * t269) - t103 * t270;
  b_in1[133] = t455;
  b_in1[134] = -(t271 * t393);
  b_in1[135] = (-t109 * t47 + t37 * t31) + t103 * t267;
  b_in1[136] = std::cos(in1[4]) * 0.425 + t455;
  b_in1[137] = t322 * t393;
  b_in1[138] = t324 * t393;
  b_in1[139] = t4 * t425 * 6.123233995736766E-17;
  b_in1[140] = t59 * 6.123233995736766E-17;
  b_in1[141] = -(t429 * 6.123233995736766E-17);
  b_in1[142] = t15 * t86;
  b_in1[143] = -(t5 * t86);
  b_in1[144] = t73;
  b_in1[145] = t5 * t321 - t15 * t451;
  b_in1[146] = t46;
  b_in1[147] = t488;
  b_in1[148] = -(t481 * 0.0996);
  b_in1[149] = t85 * 0.0996;
  b_in1[150] = t46 * 0.0996;
  b_in1[151] = t488 * 0.0996;
  b_in1[152] = t4 * t349 / 1.622592768292134E+32 - t36 * 3.7737343068413894E-49;
  b_in1[153] = t271 * t73;
  b_in1[154] = t5;
  b_in1[155] = t481 * 6.123233995736766E-17;
  b_in1[156] = t85 * 6.123233995736766E-17;
  b_in1[157] = t46 * 6.123233995736766E-17;
  b_in1[158] = (t297 + t51) - 2.2958450216584679E-49;
  b_in1[159] = t5 * t60;
  b_in1[160] = t15 * t60;
  b_in1[161] = t36 / 1.622592768292134E+32 + t85;
  t52 = t56 - t46;
  b_in1[162] = -t5 * t52;
  b_in1[163] = -t5 * (t375 - t488);
  b_in1[164] = t15 * t52;
  b_in1[165] = t5 * t40;
  b_in1[166] = t15 * t40;
  b_in1[167] = t5 * t41;
  b_in1[168] = t15 * t41;
  b_in1[169] = -t5 * (t426 - t488);
  b_in1[170] =
      ((((std::sin(in1[4]) * 0.425 + std::sin(t23) * 0.3922) + t75 * 0.0996) +
        t39 * 0.099700000000000011) -
       t363 * 0.0996) -
      0.1625;
  t52 = t426 * 6.123233995736766E-17 - t488 * 6.123233995736766E-17;
  b_in1[171] = -t5 * t52;
  b_in1[172] = t15 * t52;
  t52 = t14 * t349;
  b_in1[173] = ((-t374 + t52 / 1.622592768292134E+32) + t388) +
               t119 * 3.7737343068413894E-49;
  b_in1[174] = (t429 + t477) - t481;
  b_in1[175] = t57;
  t48 = t4 * (-t374 + t388);
  b_in1[176] = -t5 * ((-t425 + t14 * (-t330 + t333) * 6.123233995736766E-17) +
                      t48 * 6.123233995736766E-17);
  b_in1[177] = ((t52 * 6.1383239187509977E-34 - t413) + t417) + t48 * -0.0996;
  b_in1[178] = t58;
  b_in1[179] =
      ((t12 * 6.123233995736766E-17 + t423) + t427 * 6.123233995736766E-17) +
      t487 * 6.123233995736766E-17;
  t52 = t12 * 3.749399456654644E-33 + t374;
  t48 = t14 * t346;
  b_in1[180] = ((t52 - t48 / 1.622592768292134E+32) + t388) - t487;
  b_in1[181] = (((t355 + t372) - t392) + t59) + t85;
  b_in1[182] = ((t52 + t388) - t427) - t487;
  b_in1[183] = t6;
  t52 = ((t328 + t337) + t342) + t347;
  b_in1[184] =
      ((((t52 + t48 * 6.1383239187509977E-34) - t409) - t413) - t417) + t24;
  b_in1[185] = ((((t52 - t409) - t413) - t417) + t427 * 0.0996) + t24;
  b_in1[186] = t7;
  b_in1[187] = t83;
  b_in1[188] = t88;
  b_in1[189] = t9;
  ft_1(b_in1, A);
}

//
// File trailer for WholeBodyJacobian.cpp
//
// [EOF]
//
