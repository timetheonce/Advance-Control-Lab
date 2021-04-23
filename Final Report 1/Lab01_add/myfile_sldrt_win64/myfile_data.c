/*
 * myfile_data.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "myfile".
 *
 * Model version              : 1.6
 * Simulink Coder version : 9.3 (R2020a) 18-Nov-2019
 * C source code generated on : Tue Apr 20 19:34:38 2021
 *
 * Target selection: sldrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "myfile.h"
#include "myfile_private.h"

/* Block parameters (default storage) */
P_myfile_T myfile_P = {
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

  /* Mask Parameter: AnalogOutput_MaxMissedTicks
   * Referenced by: '<Root>/Analog Output'
   */
  10.0,

  /* Mask Parameter: EncoderInput_MaxMissedTicks
   * Referenced by: '<Root>/Encoder Input'
   */
  10.0,

  /* Mask Parameter: EncoderInput1_MaxMissedTicks
   * Referenced by: '<Root>/Encoder Input1'
   */
  10.0,

  /* Mask Parameter: AnalogOutput_YieldWhenWaiting
   * Referenced by: '<Root>/Analog Output'
   */
  0.0,

  /* Mask Parameter: EncoderInput_YieldWhenWaiting
   * Referenced by: '<Root>/Encoder Input'
   */
  0.0,

  /* Mask Parameter: EncoderInput1_YieldWhenWaiting
   * Referenced by: '<Root>/Encoder Input1'
   */
  0.0,

  /* Mask Parameter: AnalogOutput_Channels
   * Referenced by: '<Root>/Analog Output'
   */
  1,

  /* Mask Parameter: EncoderInput_Channels
   * Referenced by: '<Root>/Encoder Input'
   */
  0,

  /* Mask Parameter: EncoderInput1_Channels
   * Referenced by: '<Root>/Encoder Input1'
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
  { -30.0, -225.0 },

  /* Computed Parameter: TransferFcn_C
   * Referenced by: '<Root>/Transfer Fcn'
   */
  { 15.0, 0.0 },

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

  /* Expression: 0
   * Referenced by: '<Root>/Constant'
   */
  0.0,

  /* Expression: 360/(4.5*4*500)
   * Referenced by: '<Root>/Arm'
   */
  0.04,

  /* Expression: 360/2000
   * Referenced by: '<Root>/pendulum'
   */
  0.18
};
