/*
 * jc_6.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "jc_6".
 *
 * Model version              : 1.15
 * Simulink Coder version : 9.3 (R2020a) 18-Nov-2019
 * C source code generated on : Tue Jun 22 18:26:30 2021
 *
 * Target selection: sldrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "jc_6.h"
#include "jc_6_private.h"
#include "jc_6_dt.h"

/* options for Simulink Desktop Real-Time board 0 */
static double SLDRTBoardOptions0[] = {
  0.0,
  0.0,
  0.0,
  2.0,
  2.0,
  2.0,
  2.0,
};

/* list of Simulink Desktop Real-Time timers */
const int SLDRTTimerCount = 1;
const double SLDRTTimers[2] = {
  0.001, 0.0,
};

/* list of Simulink Desktop Real-Time boards */
const int SLDRTBoardCount = 1;
SLDRTBOARD SLDRTBoards[1] = {
  { "National_Instruments/PCIe-6321", 4294967295U, 7, SLDRTBoardOptions0 },
};

/* Block signals (default storage) */
B_jc_6_T jc_6_B;

/* Continuous states */
X_jc_6_T jc_6_X;

/* Block states (default storage) */
DW_jc_6_T jc_6_DW;

/* Real-time model */
RT_MODEL_jc_6_T jc_6_M_;
RT_MODEL_jc_6_T *const jc_6_M = &jc_6_M_;

/*
 * This function updates continuous states using the ODE4 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE4_IntgData *id = (ODE4_IntgData *)rtsiGetSolverData(si);
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T *f3 = id->f[3];
  real_T temp;
  int_T i;
  int_T nXc = 2;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  jc_6_derivatives();

  /* f1 = f(t + (h/2), y + (h/2)*f0) */
  temp = 0.5 * h;
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (temp*f0[i]);
  }

  rtsiSetT(si, t + temp);
  rtsiSetdX(si, f1);
  jc_6_output();
  jc_6_derivatives();

  /* f2 = f(t + (h/2), y + (h/2)*f1) */
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (temp*f1[i]);
  }

  rtsiSetdX(si, f2);
  jc_6_output();
  jc_6_derivatives();

  /* f3 = f(t + h, y + h*f2) */
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (h*f2[i]);
  }

  rtsiSetT(si, tnew);
  rtsiSetdX(si, f3);
  jc_6_output();
  jc_6_derivatives();

  /* tnew = t + h
     ynew = y + (h/6)*(f0 + 2*f1 + 2*f2 + 2*f3) */
  temp = h / 6.0;
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + temp*(f0[i] + 2.0*f1[i] + 2.0*f2[i] + f3[i]);
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model output function */
void jc_6_output(void)
{
  /* local block i/o variables */
  real_T rtb_Abs;
  real_T rtb_Sum2_i;
  real_T rtb_Cdmatrix[2];
  real_T tmp;
  int32_T i;
  real_T tmp_0;
  if (rtmIsMajorTimeStep(jc_6_M)) {
    /* set solver stop time */
    if (!(jc_6_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&jc_6_M->solverInfo, ((jc_6_M->Timing.clockTickH0 +
        1) * jc_6_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&jc_6_M->solverInfo, ((jc_6_M->Timing.clockTick0 + 1)
        * jc_6_M->Timing.stepSize0 + jc_6_M->Timing.clockTickH0 *
        jc_6_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(jc_6_M)) {
    jc_6_M->Timing.t[0] = rtsiGetT(&jc_6_M->solverInfo);
  }

  /* TransferFcn: '<Root>/Transfer Fcn' */
  jc_6_B.TransferFcn = 0.0;
  jc_6_B.TransferFcn += jc_6_P.TransferFcn_C[0] * jc_6_X.TransferFcn_CSTATE[0];
  jc_6_B.TransferFcn += jc_6_P.TransferFcn_C[1] * jc_6_X.TransferFcn_CSTATE[1];
  if (rtmIsMajorTimeStep(jc_6_M)) {
    /* S-Function (sldrtei): '<Root>/Encoder Input' */
    /* S-Function Block: <Root>/Encoder Input */
    {
      ENCODERINPARM parm;
      parm.quad = (QUADMODE) 2;
      parm.index = (INDEXPULSE) 0;
      parm.infilter = jc_6_P.EncoderInput_InputFilter;
      RTBIO_DriverIO(0, ENCODERINPUT, IOREAD, 1, &jc_6_P.EncoderInput_Channels,
                     &rtb_Abs, &parm);
    }

    /* S-Function (sldrtei): '<Root>/Encoder Input1' */
    /* S-Function Block: <Root>/Encoder Input1 */
    {
      ENCODERINPARM parm;
      parm.quad = (QUADMODE) 2;
      parm.index = (INDEXPULSE) 0;
      parm.infilter = jc_6_P.EncoderInput1_InputFilter;
      RTBIO_DriverIO(0, ENCODERINPUT, IOREAD, 1, &jc_6_P.EncoderInput1_Channels,
                     &rtb_Sum2_i, &parm);
    }

    /* Gain: '<Root>/Gain' */
    jc_6_B.Gain = jc_6_P.Gain_Gain * rtb_Abs;

    /* Abs: '<Root>/Abs' */
    rtb_Abs = fabs(jc_6_B.Gain);

    /* DataTypeConversion: '<Root>/Data Type Conversion' incorporates:
     *  Constant: '<Root>/Constant1'
     *  RelationalOperator: '<Root>/Relational Operator'
     */
    jc_6_B.DataTypeConversion = (rtb_Abs < jc_6_P.Constant1_Value);
  }

  /* Gain: '<Root>/Gain3' incorporates:
   *  Gain: '<Root>/safety'
   *  Product: '<Root>/Product'
   *  Sum: '<Root>/Sum'
   */
  jc_6_B.Gain3 = (jc_6_B.TransferFcn - jc_6_B.Gain) * jc_6_P.safety_Gain *
    jc_6_B.DataTypeConversion * jc_6_P.Gain3_Gain;

  /* Saturate: '<Root>/Saturation' */
  if (jc_6_B.Gain3 > jc_6_P.Saturation_UpperSat) {
    tmp_0 = jc_6_P.Saturation_UpperSat;
  } else if (jc_6_B.Gain3 < jc_6_P.Saturation_LowerSat) {
    tmp_0 = jc_6_P.Saturation_LowerSat;
  } else {
    tmp_0 = jc_6_B.Gain3;
  }

  /* End of Saturate: '<Root>/Saturation' */

  /* Gain: '<Root>/Gain2' */
  jc_6_B.Gain2 = jc_6_P.Gain2_Gain * tmp_0;
  if (rtmIsMajorTimeStep(jc_6_M)) {
    /* S-Function (sldrtao): '<Root>/Analog Output' */
    /* S-Function Block: <Root>/Analog Output */
    {
      {
        ANALOGIOPARM parm;
        parm.mode = (RANGEMODE) jc_6_P.AnalogOutput_RangeMode;
        parm.rangeidx = jc_6_P.AnalogOutput_VoltRange;
        RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1,
                       &jc_6_P.AnalogOutput_Channels, ((real_T*) (&jc_6_B.Gain2)),
                       &parm);
      }
    }

    /* Gain: '<Root>/Gain1' */
    jc_6_B.Gain1 = jc_6_P.Gain1_Gain * rtb_Sum2_i;

    /* UnitDelay: '<S1>/Unit Delay' */
    jc_6_B.UnitDelay[0] = jc_6_DW.UnitDelay_DSTATE[0];
    jc_6_B.UnitDelay[1] = jc_6_DW.UnitDelay_DSTATE[1];
    jc_6_B.UnitDelay[2] = jc_6_DW.UnitDelay_DSTATE[2];
    jc_6_B.UnitDelay[3] = jc_6_DW.UnitDelay_DSTATE[3];

    /* UnitDelay: '<S2>/Unit Delay' */
    jc_6_B.UnitDelay_o[0] = jc_6_DW.UnitDelay_DSTATE_c[0];
    jc_6_B.UnitDelay_o[1] = jc_6_DW.UnitDelay_DSTATE_c[1];
    jc_6_B.UnitDelay_o[2] = jc_6_DW.UnitDelay_DSTATE_c[2];
    jc_6_B.UnitDelay_o[3] = jc_6_DW.UnitDelay_DSTATE_c[3];

    /* Constant: '<Root>/Constant' */
    jc_6_B.Constant = jc_6_P.Constant_Value;

    /* UnitDelay: '<S3>/Unit Delay' */
    jc_6_B.UnitDelay_l[0] = jc_6_DW.UnitDelay_DSTATE_k[0];
    jc_6_B.UnitDelay_l[1] = jc_6_DW.UnitDelay_DSTATE_k[1];
    jc_6_B.UnitDelay_l[2] = jc_6_DW.UnitDelay_DSTATE_k[2];
    jc_6_B.UnitDelay_l[3] = jc_6_DW.UnitDelay_DSTATE_k[3];

    /* UnitDelay: '<S4>/Unit Delay' */
    jc_6_B.UnitDelay_c[0] = jc_6_DW.UnitDelay_DSTATE_h[0];
    jc_6_B.UnitDelay_c[1] = jc_6_DW.UnitDelay_DSTATE_h[1];
    jc_6_B.UnitDelay_c[2] = jc_6_DW.UnitDelay_DSTATE_h[2];
    jc_6_B.UnitDelay_c[3] = jc_6_DW.UnitDelay_DSTATE_h[3];

    /* Gain: '<S1>/Cd matrix' */
    rtb_Sum2_i = ((jc_6_P.Cdmatrix_Gain[0] * jc_6_B.UnitDelay[0] +
                   jc_6_P.Cdmatrix_Gain[1] * jc_6_B.UnitDelay[1]) +
                  jc_6_P.Cdmatrix_Gain[2] * jc_6_B.UnitDelay[2]) +
      jc_6_P.Cdmatrix_Gain[3] * jc_6_B.UnitDelay[3];

    /* Sum: '<S1>/Sum2' incorporates:
     *  Gain: '<S1>/Dd matrix'
     *  Sum: '<S1>/Sum'
     */
    rtb_Sum2_i = jc_6_B.Gain - (jc_6_P.Ddmatrix_Gain * jc_6_B.Gain3 + rtb_Sum2_i);

    /* Sum: '<S1>/Sum3' incorporates:
     *  Gain: '<S1>/Ad matrix'
     *  Gain: '<S1>/Bd matrix'
     *  Gain: '<S1>/Ld matrix'
     *  Sum: '<S1>/Sum1'
     */
    for (i = 0; i < 4; i++) {
      jc_6_B.Sum3[i] = (((jc_6_P.Admatrix_Gain[i + 4] * jc_6_B.UnitDelay[1] +
                          jc_6_P.Admatrix_Gain[i] * jc_6_B.UnitDelay[0]) +
                         jc_6_P.Admatrix_Gain[i + 8] * jc_6_B.UnitDelay[2]) +
                        jc_6_P.Admatrix_Gain[i + 12] * jc_6_B.UnitDelay[3]) +
        (jc_6_P.Bdmatrix_Gain[i] * jc_6_B.Gain3 + jc_6_P.Ldmatrix_Gain[i] *
         rtb_Sum2_i);
    }

    /* End of Sum: '<S1>/Sum3' */

    /* Sum: '<S2>/Sum' incorporates:
     *  Gain: '<S2>/Cd matrix'
     *  Gain: '<S2>/Dd matrix'
     */
    for (i = 0; i < 2; i++) {
      rtb_Cdmatrix[i] = (((jc_6_P.Cdmatrix_Gain_e[i + 2] * jc_6_B.UnitDelay_o[1]
                           + jc_6_P.Cdmatrix_Gain_e[i] * jc_6_B.UnitDelay_o[0])
                          + jc_6_P.Cdmatrix_Gain_e[i + 4] * jc_6_B.UnitDelay_o[2])
                         + jc_6_P.Cdmatrix_Gain_e[i + 6] * jc_6_B.UnitDelay_o[3])
        + jc_6_P.Ddmatrix_Gain_m[i] * jc_6_B.Gain3;
    }

    /* End of Sum: '<S2>/Sum' */

    /* Sum: '<S2>/Sum2' */
    tmp_0 = rtb_Cdmatrix[0];
    tmp = rtb_Cdmatrix[1];
    rtb_Cdmatrix[0] = jc_6_B.Gain - tmp_0;
    rtb_Cdmatrix[1] = jc_6_B.Gain1 - tmp;

    /* Gain: '<S3>/Cd matrix' */
    tmp_0 = 0.0;
    for (i = 0; i < 4; i++) {
      /* Gain: '<S2>/Ad matrix' */
      tmp = jc_6_P.Admatrix_Gain_i[i + 12] * jc_6_B.UnitDelay_o[3] +
        (jc_6_P.Admatrix_Gain_i[i + 8] * jc_6_B.UnitDelay_o[2] +
         (jc_6_P.Admatrix_Gain_i[i + 4] * jc_6_B.UnitDelay_o[1] +
          jc_6_P.Admatrix_Gain_i[i] * jc_6_B.UnitDelay_o[0]));

      /* Sum: '<S2>/Sum3' incorporates:
       *  Gain: '<S2>/Bd matrix'
       *  Gain: '<S2>/Ld matrix'
       *  Sum: '<S2>/Sum1'
       */
      jc_6_B.Sum3_m[i] = ((jc_6_P.Ldmatrix_Gain_b[i + 4] * rtb_Cdmatrix[1] +
                           jc_6_P.Ldmatrix_Gain_b[i] * rtb_Cdmatrix[0]) +
                          jc_6_P.Bdmatrix_Gain_e[i] * jc_6_B.Gain3) + tmp;

      /* Gain: '<S3>/Cd matrix' */
      tmp_0 += jc_6_P.Cdmatrix_Gain_er[i] * jc_6_B.UnitDelay_l[i];
    }

    /* Gain: '<S3>/Cd matrix' */
    rtb_Sum2_i = tmp_0;

    /* Sum: '<S3>/Sum2' incorporates:
     *  Gain: '<S3>/Dd matrix'
     *  Sum: '<S3>/Sum'
     */
    rtb_Sum2_i = jc_6_B.Gain - (jc_6_P.Ddmatrix_Gain_c * jc_6_B.Gain3 +
      rtb_Sum2_i);

    /* Sum: '<S3>/Sum3' incorporates:
     *  Gain: '<S3>/Ad matrix'
     *  Gain: '<S3>/Bd matrix'
     *  Gain: '<S3>/Ld matrix'
     *  Sum: '<S3>/Sum1'
     */
    for (i = 0; i < 4; i++) {
      jc_6_B.Sum3_d[i] = (((jc_6_P.Admatrix_Gain_b[i + 4] * jc_6_B.UnitDelay_l[1]
                            + jc_6_P.Admatrix_Gain_b[i] * jc_6_B.UnitDelay_l[0])
                           + jc_6_P.Admatrix_Gain_b[i + 8] * jc_6_B.UnitDelay_l
                           [2]) + jc_6_P.Admatrix_Gain_b[i + 12] *
                          jc_6_B.UnitDelay_l[3]) + (jc_6_P.Bdmatrix_Gain_e0[i] *
        jc_6_B.Gain3 + jc_6_P.Ldmatrix_Gain_n[i] * rtb_Sum2_i);
    }

    /* End of Sum: '<S3>/Sum3' */

    /* Sum: '<S4>/Sum' incorporates:
     *  Gain: '<S4>/Cd matrix'
     *  Gain: '<S4>/Dd matrix'
     */
    for (i = 0; i < 2; i++) {
      rtb_Cdmatrix[i] = (((jc_6_P.Cdmatrix_Gain_h[i + 2] * jc_6_B.UnitDelay_c[1]
                           + jc_6_P.Cdmatrix_Gain_h[i] * jc_6_B.UnitDelay_c[0])
                          + jc_6_P.Cdmatrix_Gain_h[i + 4] * jc_6_B.UnitDelay_c[2])
                         + jc_6_P.Cdmatrix_Gain_h[i + 6] * jc_6_B.UnitDelay_c[3])
        + jc_6_P.Ddmatrix_Gain_a[i] * jc_6_B.Gain3;
    }

    /* End of Sum: '<S4>/Sum' */

    /* Sum: '<S4>/Sum2' */
    tmp_0 = rtb_Cdmatrix[0];
    tmp = rtb_Cdmatrix[1];
    rtb_Cdmatrix[0] = jc_6_B.Gain - tmp_0;
    rtb_Cdmatrix[1] = jc_6_B.Gain1 - tmp;
    for (i = 0; i < 4; i++) {
      /* Gain: '<S4>/Ad matrix' */
      tmp_0 = jc_6_P.Admatrix_Gain_c[i + 12] * jc_6_B.UnitDelay_c[3] +
        (jc_6_P.Admatrix_Gain_c[i + 8] * jc_6_B.UnitDelay_c[2] +
         (jc_6_P.Admatrix_Gain_c[i + 4] * jc_6_B.UnitDelay_c[1] +
          jc_6_P.Admatrix_Gain_c[i] * jc_6_B.UnitDelay_c[0]));

      /* Sum: '<S4>/Sum3' incorporates:
       *  Gain: '<S4>/Bd matrix'
       *  Gain: '<S4>/Ld matrix'
       *  Sum: '<S4>/Sum1'
       */
      jc_6_B.Sum3_p[i] = ((jc_6_P.Ldmatrix_Gain_h[i + 4] * rtb_Cdmatrix[1] +
                           jc_6_P.Ldmatrix_Gain_h[i] * rtb_Cdmatrix[0]) +
                          jc_6_P.Bdmatrix_Gain_d[i] * jc_6_B.Gain3) + tmp_0;
    }
  }
}

/* Model update function */
void jc_6_update(void)
{
  if (rtmIsMajorTimeStep(jc_6_M)) {
    /* Update for UnitDelay: '<S1>/Unit Delay' */
    jc_6_DW.UnitDelay_DSTATE[0] = jc_6_B.Sum3[0];

    /* Update for UnitDelay: '<S2>/Unit Delay' */
    jc_6_DW.UnitDelay_DSTATE_c[0] = jc_6_B.Sum3_m[0];

    /* Update for UnitDelay: '<S3>/Unit Delay' */
    jc_6_DW.UnitDelay_DSTATE_k[0] = jc_6_B.Sum3_d[0];

    /* Update for UnitDelay: '<S4>/Unit Delay' */
    jc_6_DW.UnitDelay_DSTATE_h[0] = jc_6_B.Sum3_p[0];

    /* Update for UnitDelay: '<S1>/Unit Delay' */
    jc_6_DW.UnitDelay_DSTATE[1] = jc_6_B.Sum3[1];

    /* Update for UnitDelay: '<S2>/Unit Delay' */
    jc_6_DW.UnitDelay_DSTATE_c[1] = jc_6_B.Sum3_m[1];

    /* Update for UnitDelay: '<S3>/Unit Delay' */
    jc_6_DW.UnitDelay_DSTATE_k[1] = jc_6_B.Sum3_d[1];

    /* Update for UnitDelay: '<S4>/Unit Delay' */
    jc_6_DW.UnitDelay_DSTATE_h[1] = jc_6_B.Sum3_p[1];

    /* Update for UnitDelay: '<S1>/Unit Delay' */
    jc_6_DW.UnitDelay_DSTATE[2] = jc_6_B.Sum3[2];

    /* Update for UnitDelay: '<S2>/Unit Delay' */
    jc_6_DW.UnitDelay_DSTATE_c[2] = jc_6_B.Sum3_m[2];

    /* Update for UnitDelay: '<S3>/Unit Delay' */
    jc_6_DW.UnitDelay_DSTATE_k[2] = jc_6_B.Sum3_d[2];

    /* Update for UnitDelay: '<S4>/Unit Delay' */
    jc_6_DW.UnitDelay_DSTATE_h[2] = jc_6_B.Sum3_p[2];

    /* Update for UnitDelay: '<S1>/Unit Delay' */
    jc_6_DW.UnitDelay_DSTATE[3] = jc_6_B.Sum3[3];

    /* Update for UnitDelay: '<S2>/Unit Delay' */
    jc_6_DW.UnitDelay_DSTATE_c[3] = jc_6_B.Sum3_m[3];

    /* Update for UnitDelay: '<S3>/Unit Delay' */
    jc_6_DW.UnitDelay_DSTATE_k[3] = jc_6_B.Sum3_d[3];

    /* Update for UnitDelay: '<S4>/Unit Delay' */
    jc_6_DW.UnitDelay_DSTATE_h[3] = jc_6_B.Sum3_p[3];
  }

  if (rtmIsMajorTimeStep(jc_6_M)) {
    rt_ertODEUpdateContinuousStates(&jc_6_M->solverInfo);
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++jc_6_M->Timing.clockTick0)) {
    ++jc_6_M->Timing.clockTickH0;
  }

  jc_6_M->Timing.t[0] = rtsiGetSolverStopTime(&jc_6_M->solverInfo);

  {
    /* Update absolute timer for sample time: [0.001s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick1"
     * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick1 and the high bits
     * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++jc_6_M->Timing.clockTick1)) {
      ++jc_6_M->Timing.clockTickH1;
    }

    jc_6_M->Timing.t[1] = jc_6_M->Timing.clockTick1 * jc_6_M->Timing.stepSize1 +
      jc_6_M->Timing.clockTickH1 * jc_6_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Derivatives for root system: '<Root>' */
void jc_6_derivatives(void)
{
  XDot_jc_6_T *_rtXdot;
  _rtXdot = ((XDot_jc_6_T *) jc_6_M->derivs);

  /* Derivatives for TransferFcn: '<Root>/Transfer Fcn' */
  _rtXdot->TransferFcn_CSTATE[0] = 0.0;
  _rtXdot->TransferFcn_CSTATE[0] += jc_6_P.TransferFcn_A[0] *
    jc_6_X.TransferFcn_CSTATE[0];
  _rtXdot->TransferFcn_CSTATE[1] = 0.0;
  _rtXdot->TransferFcn_CSTATE[0] += jc_6_P.TransferFcn_A[1] *
    jc_6_X.TransferFcn_CSTATE[1];
  _rtXdot->TransferFcn_CSTATE[1] += jc_6_X.TransferFcn_CSTATE[0];
  _rtXdot->TransferFcn_CSTATE[0] += jc_6_B.Constant;
}

/* Model initialize function */
void jc_6_initialize(void)
{
  /* Start for S-Function (sldrtao): '<Root>/Analog Output' */

  /* S-Function Block: <Root>/Analog Output */
  {
    {
      ANALOGIOPARM parm;
      parm.mode = (RANGEMODE) jc_6_P.AnalogOutput_RangeMode;
      parm.rangeidx = jc_6_P.AnalogOutput_VoltRange;
      RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1, &jc_6_P.AnalogOutput_Channels,
                     &jc_6_P.AnalogOutput_InitialValue, &parm);
    }
  }

  /* InitializeConditions for TransferFcn: '<Root>/Transfer Fcn' */
  jc_6_X.TransferFcn_CSTATE[0] = 0.0;
  jc_6_X.TransferFcn_CSTATE[1] = 0.0;

  /* InitializeConditions for S-Function (sldrtei): '<Root>/Encoder Input' */

  /* S-Function Block: <Root>/Encoder Input */
  {
    ENCODERINPARM parm;
    parm.quad = (QUADMODE) 2;
    parm.index = (INDEXPULSE) 0;
    parm.infilter = jc_6_P.EncoderInput_InputFilter;
    RTBIO_DriverIO(0, ENCODERINPUT, IORESET, 1, &jc_6_P.EncoderInput_Channels,
                   NULL, &parm);
  }

  /* InitializeConditions for S-Function (sldrtei): '<Root>/Encoder Input1' */

  /* S-Function Block: <Root>/Encoder Input1 */
  {
    ENCODERINPARM parm;
    parm.quad = (QUADMODE) 2;
    parm.index = (INDEXPULSE) 0;
    parm.infilter = jc_6_P.EncoderInput1_InputFilter;
    RTBIO_DriverIO(0, ENCODERINPUT, IORESET, 1, &jc_6_P.EncoderInput1_Channels,
                   NULL, &parm);
  }

  /* InitializeConditions for UnitDelay: '<S1>/Unit Delay' */
  jc_6_DW.UnitDelay_DSTATE[0] = jc_6_P.fast1_x0[0];

  /* InitializeConditions for UnitDelay: '<S2>/Unit Delay' */
  jc_6_DW.UnitDelay_DSTATE_c[0] = jc_6_P.fast2_x0[0];

  /* InitializeConditions for UnitDelay: '<S3>/Unit Delay' */
  jc_6_DW.UnitDelay_DSTATE_k[0] = jc_6_P.slow1_x0[0];

  /* InitializeConditions for UnitDelay: '<S4>/Unit Delay' */
  jc_6_DW.UnitDelay_DSTATE_h[0] = jc_6_P.slow2_x0[0];

  /* InitializeConditions for UnitDelay: '<S1>/Unit Delay' */
  jc_6_DW.UnitDelay_DSTATE[1] = jc_6_P.fast1_x0[1];

  /* InitializeConditions for UnitDelay: '<S2>/Unit Delay' */
  jc_6_DW.UnitDelay_DSTATE_c[1] = jc_6_P.fast2_x0[1];

  /* InitializeConditions for UnitDelay: '<S3>/Unit Delay' */
  jc_6_DW.UnitDelay_DSTATE_k[1] = jc_6_P.slow1_x0[1];

  /* InitializeConditions for UnitDelay: '<S4>/Unit Delay' */
  jc_6_DW.UnitDelay_DSTATE_h[1] = jc_6_P.slow2_x0[1];

  /* InitializeConditions for UnitDelay: '<S1>/Unit Delay' */
  jc_6_DW.UnitDelay_DSTATE[2] = jc_6_P.fast1_x0[2];

  /* InitializeConditions for UnitDelay: '<S2>/Unit Delay' */
  jc_6_DW.UnitDelay_DSTATE_c[2] = jc_6_P.fast2_x0[2];

  /* InitializeConditions for UnitDelay: '<S3>/Unit Delay' */
  jc_6_DW.UnitDelay_DSTATE_k[2] = jc_6_P.slow1_x0[2];

  /* InitializeConditions for UnitDelay: '<S4>/Unit Delay' */
  jc_6_DW.UnitDelay_DSTATE_h[2] = jc_6_P.slow2_x0[2];

  /* InitializeConditions for UnitDelay: '<S1>/Unit Delay' */
  jc_6_DW.UnitDelay_DSTATE[3] = jc_6_P.fast1_x0[3];

  /* InitializeConditions for UnitDelay: '<S2>/Unit Delay' */
  jc_6_DW.UnitDelay_DSTATE_c[3] = jc_6_P.fast2_x0[3];

  /* InitializeConditions for UnitDelay: '<S3>/Unit Delay' */
  jc_6_DW.UnitDelay_DSTATE_k[3] = jc_6_P.slow1_x0[3];

  /* InitializeConditions for UnitDelay: '<S4>/Unit Delay' */
  jc_6_DW.UnitDelay_DSTATE_h[3] = jc_6_P.slow2_x0[3];
}

/* Model terminate function */
void jc_6_terminate(void)
{
  /* Terminate for S-Function (sldrtao): '<Root>/Analog Output' */

  /* S-Function Block: <Root>/Analog Output */
  {
    {
      ANALOGIOPARM parm;
      parm.mode = (RANGEMODE) jc_6_P.AnalogOutput_RangeMode;
      parm.rangeidx = jc_6_P.AnalogOutput_VoltRange;
      RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1, &jc_6_P.AnalogOutput_Channels,
                     &jc_6_P.AnalogOutput_FinalValue, &parm);
    }
  }
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/

/* Solver interface called by GRT_Main */
#ifndef USE_GENERATED_SOLVER

void rt_ODECreateIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEDestroyIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEUpdateContinuousStates(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

#endif

void MdlOutputs(int_T tid)
{
  jc_6_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  jc_6_update();
  UNUSED_PARAMETER(tid);
}

void MdlInitializeSizes(void)
{
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
}

void MdlStart(void)
{
  jc_6_initialize();
}

void MdlTerminate(void)
{
  jc_6_terminate();
}

/* Registration function */
RT_MODEL_jc_6_T *jc_6(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* non-finite (run-time) assignments */
  jc_6_P.EncoderInput_InputFilter = rtInf;
  jc_6_P.EncoderInput1_InputFilter = rtInf;

  /* initialize real-time model */
  (void) memset((void *)jc_6_M, 0,
                sizeof(RT_MODEL_jc_6_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&jc_6_M->solverInfo, &jc_6_M->Timing.simTimeStep);
    rtsiSetTPtr(&jc_6_M->solverInfo, &rtmGetTPtr(jc_6_M));
    rtsiSetStepSizePtr(&jc_6_M->solverInfo, &jc_6_M->Timing.stepSize0);
    rtsiSetdXPtr(&jc_6_M->solverInfo, &jc_6_M->derivs);
    rtsiSetContStatesPtr(&jc_6_M->solverInfo, (real_T **) &jc_6_M->contStates);
    rtsiSetNumContStatesPtr(&jc_6_M->solverInfo, &jc_6_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&jc_6_M->solverInfo,
      &jc_6_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&jc_6_M->solverInfo,
      &jc_6_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&jc_6_M->solverInfo,
      &jc_6_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&jc_6_M->solverInfo, (&rtmGetErrorStatus(jc_6_M)));
    rtsiSetRTModelPtr(&jc_6_M->solverInfo, jc_6_M);
  }

  rtsiSetSimTimeStep(&jc_6_M->solverInfo, MAJOR_TIME_STEP);
  jc_6_M->intgData.y = jc_6_M->odeY;
  jc_6_M->intgData.f[0] = jc_6_M->odeF[0];
  jc_6_M->intgData.f[1] = jc_6_M->odeF[1];
  jc_6_M->intgData.f[2] = jc_6_M->odeF[2];
  jc_6_M->intgData.f[3] = jc_6_M->odeF[3];
  jc_6_M->contStates = ((real_T *) &jc_6_X);
  rtsiSetSolverData(&jc_6_M->solverInfo, (void *)&jc_6_M->intgData);
  rtsiSetSolverName(&jc_6_M->solverInfo,"ode4");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = jc_6_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    jc_6_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    jc_6_M->Timing.sampleTimes = (&jc_6_M->Timing.sampleTimesArray[0]);
    jc_6_M->Timing.offsetTimes = (&jc_6_M->Timing.offsetTimesArray[0]);

    /* task periods */
    jc_6_M->Timing.sampleTimes[0] = (0.0);
    jc_6_M->Timing.sampleTimes[1] = (0.001);

    /* task offsets */
    jc_6_M->Timing.offsetTimes[0] = (0.0);
    jc_6_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(jc_6_M, &jc_6_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = jc_6_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    jc_6_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(jc_6_M, -1);
  jc_6_M->Timing.stepSize0 = 0.001;
  jc_6_M->Timing.stepSize1 = 0.001;

  /* External mode info */
  jc_6_M->Sizes.checksums[0] = (1844447724U);
  jc_6_M->Sizes.checksums[1] = (3353108918U);
  jc_6_M->Sizes.checksums[2] = (2053455349U);
  jc_6_M->Sizes.checksums[3] = (3579837393U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    jc_6_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(jc_6_M->extModeInfo,
      &jc_6_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(jc_6_M->extModeInfo, jc_6_M->Sizes.checksums);
    rteiSetTPtr(jc_6_M->extModeInfo, rtmGetTPtr(jc_6_M));
  }

  jc_6_M->solverInfoPtr = (&jc_6_M->solverInfo);
  jc_6_M->Timing.stepSize = (0.001);
  rtsiSetFixedStepSize(&jc_6_M->solverInfo, 0.001);
  rtsiSetSolverMode(&jc_6_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  jc_6_M->blockIO = ((void *) &jc_6_B);
  (void) memset(((void *) &jc_6_B), 0,
                sizeof(B_jc_6_T));

  /* parameters */
  jc_6_M->defaultParam = ((real_T *)&jc_6_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &jc_6_X;
    jc_6_M->contStates = (x);
    (void) memset((void *)&jc_6_X, 0,
                  sizeof(X_jc_6_T));
  }

  /* states (dwork) */
  jc_6_M->dwork = ((void *) &jc_6_DW);
  (void) memset((void *)&jc_6_DW, 0,
                sizeof(DW_jc_6_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    jc_6_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 14;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Initialize Sizes */
  jc_6_M->Sizes.numContStates = (2);   /* Number of continuous states */
  jc_6_M->Sizes.numPeriodicContStates = (0);
                                      /* Number of periodic continuous states */
  jc_6_M->Sizes.numY = (0);            /* Number of model outputs */
  jc_6_M->Sizes.numU = (0);            /* Number of model inputs */
  jc_6_M->Sizes.sysDirFeedThru = (0);  /* The model is not direct feedthrough */
  jc_6_M->Sizes.numSampTimes = (2);    /* Number of sample times */
  jc_6_M->Sizes.numBlocks = (68);      /* Number of blocks */
  jc_6_M->Sizes.numBlockIO = (15);     /* Number of block outputs */
  jc_6_M->Sizes.numBlockPrms = (178);  /* Sum of parameter "widths" */
  return jc_6_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
