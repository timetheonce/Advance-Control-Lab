/*
 * jc_6_data.c
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

/* Block parameters (default storage) */
P_jc_6_T jc_6_P = {
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

  /* Mask Parameter: fast1_x0
   * Referenced by: '<S1>/Unit Delay'
   */
  { 0.0, 0.0, 0.0, 0.0 },

  /* Mask Parameter: fast2_x0
   * Referenced by: '<S2>/Unit Delay'
   */
  { 0.0, 0.0, 0.0, 0.0 },

  /* Mask Parameter: slow1_x0
   * Referenced by: '<S3>/Unit Delay'
   */
  { 0.0, 0.0, 0.0, 0.0 },

  /* Mask Parameter: slow2_x0
   * Referenced by: '<S4>/Unit Delay'
   */
  { 0.0, 0.0, 0.0, 0.0 },

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

  /* Expression: 0.02
   * Referenced by: '<Root>/Gain3'
   */
  0.02,

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
   * Referenced by: '<Root>/Constant'
   */
  0.0,

  /* Expression: Ad
   * Referenced by: '<S1>/Ad matrix'
   */
  { 1.0, 0.0, 0.0, 0.0, 0.00099883097041513673, 0.99766291250873951,
    1.303767424717192E-6, 0.0026062964038723905, 8.6069146109923126E-6,
    0.01720570504352836, 0.99996939254370354, -0.06120221950916295,
    6.7808241744785358E-8, 0.00013842239280892259, 0.00099974989258476183,
    0.999489682085028 },

  /* Expression: Bd
   * Referenced by: '<S1>/Bd matrix'
   */
  { 0.0, 0.10431001570506553, -5.8129997076840883E-5, -0.11620472953025131 },

  /* Expression: Cd
   * Referenced by: '<S1>/Cd matrix'
   */
  { 1.0, 0.0, 0.0, 0.0 },

  /* Expression: Dd
   * Referenced by: '<S1>/Dd matrix'
   */
  0.0,

  /* Expression: Ld
   * Referenced by: '<S1>/Ld matrix'
   */
  { 0.036823665272753832, 0.42285926472166779, 0.0852871827401486,
    -1.1505789655017651 },

  /* Expression: Ad
   * Referenced by: '<S2>/Ad matrix'
   */
  { 1.0, 0.0, 0.0, 0.0, 0.00099883097041513673, 0.99766291250873951,
    1.303767424717192E-6, 0.0026062964038723905, 8.6069146109923126E-6,
    0.01720570504352836, 0.99996939254370354, -0.06120221950916295,
    6.7808241744785358E-8, 0.00013842239280892259, 0.00099974989258476183,
    0.999489682085028 },

  /* Expression: Bd
   * Referenced by: '<S2>/Bd matrix'
   */
  { 0.0, 0.10431001570506553, -5.8129997076840883E-5, -0.11620472953025131 },

  /* Expression: Cd
   * Referenced by: '<S2>/Cd matrix'
   */
  { 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0 },

  /* Expression: Dd
   * Referenced by: '<S2>/Dd matrix'
   */
  { 0.0, 0.0 },

  /* Expression: Ld
   * Referenced by: '<S2>/Ld matrix'
   */
  { 0.017535142366723204, 0.058168728630979577, 0.002591338551054854,
    0.044166111092223216, 0.00017676520186408882, 0.019778967628593033,
    0.019288503305609293, 0.027697336357265224 },

  /* Expression: Ad
   * Referenced by: '<S3>/Ad matrix'
   */
  { 1.0, 0.0, 0.0, 0.0, 0.00099883097041513673, 0.99766291250873951,
    1.303767424717192E-6, 0.0026062964038723905, 8.6069146109923126E-6,
    0.01720570504352836, 0.99996939254370354, -0.06120221950916295,
    6.7808241744785358E-8, 0.00013842239280892259, 0.00099974989258476183,
    0.999489682085028 },

  /* Expression: Bd
   * Referenced by: '<S3>/Bd matrix'
   */
  { 0.0, 0.10431001570506553, -5.8129997076840883E-5, -0.11620472953025131 },

  /* Expression: Cd
   * Referenced by: '<S3>/Cd matrix'
   */
  { 1.0, 0.0, 0.0, 0.0 },

  /* Expression: Dd
   * Referenced by: '<S3>/Dd matrix'
   */
  0.0,

  /* Expression: Ld
   * Referenced by: '<S3>/Ld matrix'
   */
  { 0.0012198861755894372, -0.0592966544441735, -0.00973942754971897,
    0.20403298927399177 },

  /* Expression: Ad
   * Referenced by: '<S4>/Ad matrix'
   */
  { 1.0, 0.0, 0.0, 0.0, 0.00099883097041513673, 0.99766291250873951,
    1.303767424717192E-6, 0.0026062964038723905, 8.6069146109923126E-6,
    0.01720570504352836, 0.99996939254370354, -0.06120221950916295,
    6.7808241744785358E-8, 0.00013842239280892259, 0.00099974989258476183,
    0.999489682085028 },

  /* Expression: Bd
   * Referenced by: '<S4>/Bd matrix'
   */
  { 0.0, 0.10431001570506553, -5.8129997076840883E-5, -0.11620472953025131 },

  /* Expression: Cd
   * Referenced by: '<S4>/Cd matrix'
   */
  { 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0 },

  /* Expression: Dd
   * Referenced by: '<S4>/Dd matrix'
   */
  { 0.0, 0.0 },

  /* Expression: Ld
   * Referenced by: '<S4>/Ld matrix'
   */
  { -0.00063551410466491866, 0.0027279552413693232, 0.0039577076491358644,
    -0.002288172448034267, 5.7745393792602514E-5, 0.017259938413323496,
    0.0018554004601315441, -0.06062920596747539 }
};
