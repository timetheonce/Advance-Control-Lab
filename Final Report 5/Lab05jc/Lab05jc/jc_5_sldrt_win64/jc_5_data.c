/*
 * jc_5_data.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "jc_5".
 *
 * Model version              : 1.15
 * Simulink Coder version : 9.3 (R2020a) 18-Nov-2019
 * C source code generated on : Tue Jun  8 19:00:17 2021
 *
 * Target selection: sldrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "jc_5.h"
#include "jc_5_private.h"

/* Block parameters (default storage) */
P_jc_5_T jc_5_P = {
  /* Mask Parameter: AnalogOutput_FinalValue
   * Referenced by: '<Root>/Analog Output'
   */
  0.0,

  /* Mask Parameter: AnalogOutput_InitialValue
   * Referenced by: '<Root>/Analog Output'
   */
  0.0,

  /* Mask Parameter: EncoderInput_InputFilter
   * Referenced by: '<Root>/Encoder Input'
   */
  0.0,

  /* Mask Parameter: EncoderInput1_InputFilter
   * Referenced by: '<Root>/Encoder Input1'
   */
  0.0,

  /* Mask Parameter: EncoderInput_MaxMissedTicks
   * Referenced by: '<Root>/Encoder Input'
   */
  10.0,

  /* Mask Parameter: EncoderInput1_MaxMissedTicks
   * Referenced by: '<Root>/Encoder Input1'
   */
  10.0,

  /* Mask Parameter: AnalogOutput_MaxMissedTicks
   * Referenced by: '<Root>/Analog Output'
   */
  10.0,

  /* Mask Parameter: EncoderInput_YieldWhenWaiting
   * Referenced by: '<Root>/Encoder Input'
   */
  0.0,

  /* Mask Parameter: EncoderInput1_YieldWhenWaiting
   * Referenced by: '<Root>/Encoder Input1'
   */
  0.0,

  /* Mask Parameter: AnalogOutput_YieldWhenWaiting
   * Referenced by: '<Root>/Analog Output'
   */
  0.0,

  /* Mask Parameter: EncoderInput_Channels
   * Referenced by: '<Root>/Encoder Input'
   */
  0,

  /* Mask Parameter: EncoderInput1_Channels
   * Referenced by: '<Root>/Encoder Input1'
   */
  1,

  /* Mask Parameter: AnalogOutput_Channels
   * Referenced by: '<Root>/Analog Output'
   */
  1,

  /* Mask Parameter: AnalogOutput_RangeMode
   * Referenced by: '<Root>/Analog Output'
   */
  0,

  /* Mask Parameter: AnalogOutput_VoltRange
   * Referenced by: '<Root>/Analog Output'
   */
  0,

  /* Computed Parameter: Internal_A
   * Referenced by: '<S2>/Internal'
   */
  { -200.0, 1.0 },

  /* Computed Parameter: Internal_B
   * Referenced by: '<S2>/Internal'
   */
  32.0,

  /* Computed Parameter: Internal_C
   * Referenced by: '<S2>/Internal'
   */
  { -6.25, -10.416666666666668 },

  /* Expression: 0.0
   * Referenced by: '<S2>/Internal'
   */
  0.0,

  /* Computed Parameter: TransferFcn_A
   * Referenced by: '<Root>/Transfer Fcn'
   */
  { -48.0, -900.0 },

  /* Computed Parameter: TransferFcn_C
   * Referenced by: '<Root>/Transfer Fcn'
   */
  { 0.0, 900.0 },

  /* Expression: 360/9000
   * Referenced by: '<Root>/Gain'
   */
  0.04,

  /* Expression: 0
   * Referenced by: '<Root>/safety'
   */
  0.0,

  /* Expression: 90
   * Referenced by: '<Root>/Constant1'
   */
  90.0,

  /* Computed Parameter: Internal_A_p
   * Referenced by: '<S1>/Internal'
   */
  { -23.759999999999998, 1.0 },

  /* Computed Parameter: Internal_B_e
   * Referenced by: '<S1>/Internal'
   */
  1.0,

  /* Computed Parameter: Internal_C_j
   * Referenced by: '<S1>/Internal'
   */
  { -0.6795048, 0.2757 },

  /* Computed Parameter: Internal_D
   * Referenced by: '<S1>/Internal'
   */
  0.04048,

  /* Expression: 0.0
   * Referenced by: '<S1>/Internal'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<Root>/Saturation'
   */
  1.0,

  /* Expression: -1
   * Referenced by: '<Root>/Saturation'
   */
  -1.0,

  /* Expression: 10
   * Referenced by: '<Root>/Gain2'
   */
  10.0,

  /* Expression: 360/2000
   * Referenced by: '<Root>/Gain1'
   */
  0.18,

  /* Expression: 0
   * Referenced by: '<Root>/Constant2'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Constant'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Gain3'
   */
  0.0
};
