/*
 * jc_4_data.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "jc_4".
 *
 * Model version              : 1.14
 * Simulink Coder version : 9.3 (R2020a) 18-Nov-2019
 * C source code generated on : Tue May 25 18:43:09 2021
 *
 * Target selection: sldrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "jc_4.h"
#include "jc_4_private.h"

/* Block parameters (default storage) */
P_jc_4_T jc_4_P = {
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

  /* Expression: 1
   * Referenced by: '<Root>/safety'
   */
  1.0,

  /* Expression: 90
   * Referenced by: '<Root>/Constant1'
   */
  90.0,

  /* Computed Parameter: Internal_A
   * Referenced by: '<S1>/Internal'
   */
  { -23.764526154804184, 1.0 },

  /* Computed Parameter: Internal_B
   * Referenced by: '<S1>/Internal'
   */
  1.0,

  /* Computed Parameter: Internal_C
   * Referenced by: '<S1>/Internal'
   */
  { -0.67977095341845317, 0.2756552 },

  /* Computed Parameter: Internal_D
   * Referenced by: '<S1>/Internal'
   */
  0.040484712359121267,

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

  /* Expression: 15
   * Referenced by: '<Root>/Sine Wave'
   */
  15.0,

  /* Expression: 0
   * Referenced by: '<Root>/Sine Wave'
   */
  0.0,

  /* Expression: 3*2*pi
   * Referenced by: '<Root>/Sine Wave'
   */
  18.849555921538759,

  /* Expression: 0
   * Referenced by: '<Root>/Sine Wave'
   */
  0.0,

  /* Expression: 360/2000
   * Referenced by: '<Root>/Gain1'
   */
  0.18
};
