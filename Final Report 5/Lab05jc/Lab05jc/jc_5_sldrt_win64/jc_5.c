/*
 * jc_5.c
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
#include "jc_5_dt.h"

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
B_jc_5_T jc_5_B;

/* Continuous states */
X_jc_5_T jc_5_X;

/* Block states (default storage) */
DW_jc_5_T jc_5_DW;

/* Real-time model */
RT_MODEL_jc_5_T jc_5_M_;
RT_MODEL_jc_5_T *const jc_5_M = &jc_5_M_;

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
  int_T nXc = 6;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  jc_5_derivatives();

  /* f1 = f(t + (h/2), y + (h/2)*f0) */
  temp = 0.5 * h;
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (temp*f0[i]);
  }

  rtsiSetT(si, t + temp);
  rtsiSetdX(si, f1);
  jc_5_output();
  jc_5_derivatives();

  /* f2 = f(t + (h/2), y + (h/2)*f1) */
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (temp*f1[i]);
  }

  rtsiSetdX(si, f2);
  jc_5_output();
  jc_5_derivatives();

  /* f3 = f(t + h, y + h*f2) */
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (h*f2[i]);
  }

  rtsiSetT(si, tnew);
  rtsiSetdX(si, f3);
  jc_5_output();
  jc_5_derivatives();

  /* tnew = t + h
     ynew = y + (h/6)*(f0 + 2*f1 + 2*f2 + 2*f3) */
  temp = h / 6.0;
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + temp*(f0[i] + 2.0*f1[i] + 2.0*f2[i] + f3[i]);
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model output function */
void jc_5_output(void)
{
  /* local block i/o variables */
  real_T rtb_EncoderInput1;
  real_T rtb_Abs;
  real_T tmp;
  if (rtmIsMajorTimeStep(jc_5_M)) {
    /* set solver stop time */
    if (!(jc_5_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&jc_5_M->solverInfo, ((jc_5_M->Timing.clockTickH0 +
        1) * jc_5_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&jc_5_M->solverInfo, ((jc_5_M->Timing.clockTick0 + 1)
        * jc_5_M->Timing.stepSize0 + jc_5_M->Timing.clockTickH0 *
        jc_5_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(jc_5_M)) {
    jc_5_M->Timing.t[0] = rtsiGetT(&jc_5_M->solverInfo);
  }

  /* StateSpace: '<S2>/Internal' */
  jc_5_B.Internal = 0.0;
  jc_5_B.Internal += jc_5_P.Internal_C[0] * jc_5_X.Internal_CSTATE[0];
  jc_5_B.Internal += jc_5_P.Internal_C[1] * jc_5_X.Internal_CSTATE[1];

  /* TransferFcn: '<Root>/Transfer Fcn' */
  jc_5_B.TransferFcn = 0.0;
  jc_5_B.TransferFcn += jc_5_P.TransferFcn_C[0] * jc_5_X.TransferFcn_CSTATE[0];
  jc_5_B.TransferFcn += jc_5_P.TransferFcn_C[1] * jc_5_X.TransferFcn_CSTATE[1];
  if (rtmIsMajorTimeStep(jc_5_M)) {
    /* S-Function (sldrtei): '<Root>/Encoder Input' */
    /* S-Function Block: <Root>/Encoder Input */
    {
      ENCODERINPARM parm;
      parm.quad = (QUADMODE) 2;
      parm.index = (INDEXPULSE) 0;
      parm.infilter = jc_5_P.EncoderInput_InputFilter;
      RTBIO_DriverIO(0, ENCODERINPUT, IOREAD, 1, &jc_5_P.EncoderInput_Channels,
                     &rtb_Abs, &parm);
    }

    /* S-Function (sldrtei): '<Root>/Encoder Input1' */
    /* S-Function Block: <Root>/Encoder Input1 */
    {
      ENCODERINPARM parm;
      parm.quad = (QUADMODE) 2;
      parm.index = (INDEXPULSE) 0;
      parm.infilter = jc_5_P.EncoderInput1_InputFilter;
      RTBIO_DriverIO(0, ENCODERINPUT, IOREAD, 1, &jc_5_P.EncoderInput1_Channels,
                     &rtb_EncoderInput1, &parm);
    }

    /* Gain: '<Root>/Gain' */
    jc_5_B.Gain = jc_5_P.Gain_Gain * rtb_Abs;

    /* Abs: '<Root>/Abs' */
    rtb_Abs = fabs(jc_5_B.Gain);

    /* DataTypeConversion: '<Root>/Data Type Conversion' incorporates:
     *  Constant: '<Root>/Constant1'
     *  RelationalOperator: '<Root>/Relational Operator'
     */
    jc_5_B.DataTypeConversion = (rtb_Abs < jc_5_P.Constant1_Value);
  }

  /* Product: '<Root>/Product' incorporates:
   *  Gain: '<Root>/safety'
   *  Sum: '<Root>/Sum'
   */
  jc_5_B.Product = ((jc_5_B.Internal + jc_5_B.TransferFcn) - jc_5_B.Gain) *
    jc_5_P.safety_Gain * jc_5_B.DataTypeConversion;

  /* StateSpace: '<S1>/Internal' */
  jc_5_B.Internal_j = 0.0;
  jc_5_B.Internal_j += jc_5_P.Internal_C_j[0] * jc_5_X.Internal_CSTATE_n[0];
  jc_5_B.Internal_j += jc_5_P.Internal_C_j[1] * jc_5_X.Internal_CSTATE_n[1];
  jc_5_B.Internal_j += jc_5_P.Internal_D * jc_5_B.Product;

  /* Saturate: '<Root>/Saturation' */
  if (jc_5_B.Internal_j > jc_5_P.Saturation_UpperSat) {
    tmp = jc_5_P.Saturation_UpperSat;
  } else if (jc_5_B.Internal_j < jc_5_P.Saturation_LowerSat) {
    tmp = jc_5_P.Saturation_LowerSat;
  } else {
    tmp = jc_5_B.Internal_j;
  }

  /* End of Saturate: '<Root>/Saturation' */

  /* Gain: '<Root>/Gain2' */
  jc_5_B.Gain2 = jc_5_P.Gain2_Gain * tmp;
  if (rtmIsMajorTimeStep(jc_5_M)) {
    /* S-Function (sldrtao): '<Root>/Analog Output' */
    /* S-Function Block: <Root>/Analog Output */
    {
      {
        ANALOGIOPARM parm;
        parm.mode = (RANGEMODE) jc_5_P.AnalogOutput_RangeMode;
        parm.rangeidx = jc_5_P.AnalogOutput_VoltRange;
        RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1,
                       &jc_5_P.AnalogOutput_Channels, ((real_T*) (&jc_5_B.Gain2)),
                       &parm);
      }
    }

    /* Gain: '<Root>/Gain1' */
    jc_5_B.Gain1 = jc_5_P.Gain1_Gain * rtb_EncoderInput1;

    /* Constant: '<Root>/Constant2' */
    jc_5_B.Constant2 = jc_5_P.Constant2_Value;

    /* Gain: '<Root>/Gain3' incorporates:
     *  Constant: '<Root>/Constant'
     *  Sum: '<Root>/Sum1'
     */
    jc_5_B.Gain3 = (jc_5_P.Constant_Value - jc_5_B.Gain1) * jc_5_P.Gain3_Gain;
  }
}

/* Model update function */
void jc_5_update(void)
{
  if (rtmIsMajorTimeStep(jc_5_M)) {
    rt_ertODEUpdateContinuousStates(&jc_5_M->solverInfo);
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
  if (!(++jc_5_M->Timing.clockTick0)) {
    ++jc_5_M->Timing.clockTickH0;
  }

  jc_5_M->Timing.t[0] = rtsiGetSolverStopTime(&jc_5_M->solverInfo);

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
    if (!(++jc_5_M->Timing.clockTick1)) {
      ++jc_5_M->Timing.clockTickH1;
    }

    jc_5_M->Timing.t[1] = jc_5_M->Timing.clockTick1 * jc_5_M->Timing.stepSize1 +
      jc_5_M->Timing.clockTickH1 * jc_5_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Derivatives for root system: '<Root>' */
void jc_5_derivatives(void)
{
  XDot_jc_5_T *_rtXdot;
  _rtXdot = ((XDot_jc_5_T *) jc_5_M->derivs);

  /* Derivatives for StateSpace: '<S2>/Internal' */
  _rtXdot->Internal_CSTATE[0] = 0.0;

  /* Derivatives for TransferFcn: '<Root>/Transfer Fcn' */
  _rtXdot->TransferFcn_CSTATE[0] = 0.0;
  _rtXdot->TransferFcn_CSTATE[0] += jc_5_P.TransferFcn_A[0] *
    jc_5_X.TransferFcn_CSTATE[0];

  /* Derivatives for StateSpace: '<S2>/Internal' */
  _rtXdot->Internal_CSTATE[1] = 0.0;

  /* Derivatives for TransferFcn: '<Root>/Transfer Fcn' */
  _rtXdot->TransferFcn_CSTATE[1] = 0.0;
  _rtXdot->TransferFcn_CSTATE[0] += jc_5_P.TransferFcn_A[1] *
    jc_5_X.TransferFcn_CSTATE[1];

  /* Derivatives for StateSpace: '<S2>/Internal' */
  _rtXdot->Internal_CSTATE[0] += jc_5_P.Internal_A[0] * jc_5_X.Internal_CSTATE[0];
  _rtXdot->Internal_CSTATE[1] += jc_5_P.Internal_A[1] * jc_5_X.Internal_CSTATE[0];
  _rtXdot->Internal_CSTATE[0] += jc_5_P.Internal_B * jc_5_B.Gain3;

  /* Derivatives for TransferFcn: '<Root>/Transfer Fcn' */
  _rtXdot->TransferFcn_CSTATE[1] += jc_5_X.TransferFcn_CSTATE[0];
  _rtXdot->TransferFcn_CSTATE[0] += jc_5_B.Constant2;

  /* Derivatives for StateSpace: '<S1>/Internal' */
  _rtXdot->Internal_CSTATE_n[0] = 0.0;
  _rtXdot->Internal_CSTATE_n[1] = 0.0;
  _rtXdot->Internal_CSTATE_n[0] += jc_5_P.Internal_A_p[0] *
    jc_5_X.Internal_CSTATE_n[0];
  _rtXdot->Internal_CSTATE_n[1] += jc_5_P.Internal_A_p[1] *
    jc_5_X.Internal_CSTATE_n[0];
  _rtXdot->Internal_CSTATE_n[0] += jc_5_P.Internal_B_e * jc_5_B.Product;
}

/* Model initialize function */
void jc_5_initialize(void)
{
  /* Start for S-Function (sldrtao): '<Root>/Analog Output' */

  /* S-Function Block: <Root>/Analog Output */
  {
    {
      ANALOGIOPARM parm;
      parm.mode = (RANGEMODE) jc_5_P.AnalogOutput_RangeMode;
      parm.rangeidx = jc_5_P.AnalogOutput_VoltRange;
      RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1, &jc_5_P.AnalogOutput_Channels,
                     &jc_5_P.AnalogOutput_InitialValue, &parm);
    }
  }

  /* InitializeConditions for StateSpace: '<S2>/Internal' */
  jc_5_X.Internal_CSTATE[0] = jc_5_P.Internal_InitialCondition;

  /* InitializeConditions for TransferFcn: '<Root>/Transfer Fcn' */
  jc_5_X.TransferFcn_CSTATE[0] = 0.0;

  /* InitializeConditions for StateSpace: '<S2>/Internal' */
  jc_5_X.Internal_CSTATE[1] = jc_5_P.Internal_InitialCondition;

  /* InitializeConditions for TransferFcn: '<Root>/Transfer Fcn' */
  jc_5_X.TransferFcn_CSTATE[1] = 0.0;

  /* InitializeConditions for S-Function (sldrtei): '<Root>/Encoder Input' */

  /* S-Function Block: <Root>/Encoder Input */
  {
    ENCODERINPARM parm;
    parm.quad = (QUADMODE) 2;
    parm.index = (INDEXPULSE) 0;
    parm.infilter = jc_5_P.EncoderInput_InputFilter;
    RTBIO_DriverIO(0, ENCODERINPUT, IORESET, 1, &jc_5_P.EncoderInput_Channels,
                   NULL, &parm);
  }

  /* InitializeConditions for S-Function (sldrtei): '<Root>/Encoder Input1' */

  /* S-Function Block: <Root>/Encoder Input1 */
  {
    ENCODERINPARM parm;
    parm.quad = (QUADMODE) 2;
    parm.index = (INDEXPULSE) 0;
    parm.infilter = jc_5_P.EncoderInput1_InputFilter;
    RTBIO_DriverIO(0, ENCODERINPUT, IORESET, 1, &jc_5_P.EncoderInput1_Channels,
                   NULL, &parm);
  }

  /* InitializeConditions for StateSpace: '<S1>/Internal' */
  jc_5_X.Internal_CSTATE_n[0] = jc_5_P.Internal_InitialCondition_n;
  jc_5_X.Internal_CSTATE_n[1] = jc_5_P.Internal_InitialCondition_n;
}

/* Model terminate function */
void jc_5_terminate(void)
{
  /* Terminate for S-Function (sldrtao): '<Root>/Analog Output' */

  /* S-Function Block: <Root>/Analog Output */
  {
    {
      ANALOGIOPARM parm;
      parm.mode = (RANGEMODE) jc_5_P.AnalogOutput_RangeMode;
      parm.rangeidx = jc_5_P.AnalogOutput_VoltRange;
      RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1, &jc_5_P.AnalogOutput_Channels,
                     &jc_5_P.AnalogOutput_FinalValue, &parm);
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
  jc_5_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  jc_5_update();
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
  jc_5_initialize();
}

void MdlTerminate(void)
{
  jc_5_terminate();
}

/* Registration function */
RT_MODEL_jc_5_T *jc_5(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* non-finite (run-time) assignments */
  jc_5_P.EncoderInput_InputFilter = rtInf;
  jc_5_P.EncoderInput1_InputFilter = rtInf;

  /* initialize real-time model */
  (void) memset((void *)jc_5_M, 0,
                sizeof(RT_MODEL_jc_5_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&jc_5_M->solverInfo, &jc_5_M->Timing.simTimeStep);
    rtsiSetTPtr(&jc_5_M->solverInfo, &rtmGetTPtr(jc_5_M));
    rtsiSetStepSizePtr(&jc_5_M->solverInfo, &jc_5_M->Timing.stepSize0);
    rtsiSetdXPtr(&jc_5_M->solverInfo, &jc_5_M->derivs);
    rtsiSetContStatesPtr(&jc_5_M->solverInfo, (real_T **) &jc_5_M->contStates);
    rtsiSetNumContStatesPtr(&jc_5_M->solverInfo, &jc_5_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&jc_5_M->solverInfo,
      &jc_5_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&jc_5_M->solverInfo,
      &jc_5_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&jc_5_M->solverInfo,
      &jc_5_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&jc_5_M->solverInfo, (&rtmGetErrorStatus(jc_5_M)));
    rtsiSetRTModelPtr(&jc_5_M->solverInfo, jc_5_M);
  }

  rtsiSetSimTimeStep(&jc_5_M->solverInfo, MAJOR_TIME_STEP);
  jc_5_M->intgData.y = jc_5_M->odeY;
  jc_5_M->intgData.f[0] = jc_5_M->odeF[0];
  jc_5_M->intgData.f[1] = jc_5_M->odeF[1];
  jc_5_M->intgData.f[2] = jc_5_M->odeF[2];
  jc_5_M->intgData.f[3] = jc_5_M->odeF[3];
  jc_5_M->contStates = ((real_T *) &jc_5_X);
  rtsiSetSolverData(&jc_5_M->solverInfo, (void *)&jc_5_M->intgData);
  rtsiSetSolverName(&jc_5_M->solverInfo,"ode4");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = jc_5_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    jc_5_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    jc_5_M->Timing.sampleTimes = (&jc_5_M->Timing.sampleTimesArray[0]);
    jc_5_M->Timing.offsetTimes = (&jc_5_M->Timing.offsetTimesArray[0]);

    /* task periods */
    jc_5_M->Timing.sampleTimes[0] = (0.0);
    jc_5_M->Timing.sampleTimes[1] = (0.001);

    /* task offsets */
    jc_5_M->Timing.offsetTimes[0] = (0.0);
    jc_5_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(jc_5_M, &jc_5_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = jc_5_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    jc_5_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(jc_5_M, -1);
  jc_5_M->Timing.stepSize0 = 0.001;
  jc_5_M->Timing.stepSize1 = 0.001;

  /* External mode info */
  jc_5_M->Sizes.checksums[0] = (1685641583U);
  jc_5_M->Sizes.checksums[1] = (3228598367U);
  jc_5_M->Sizes.checksums[2] = (2876431639U);
  jc_5_M->Sizes.checksums[3] = (3172354009U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    jc_5_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(jc_5_M->extModeInfo,
      &jc_5_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(jc_5_M->extModeInfo, jc_5_M->Sizes.checksums);
    rteiSetTPtr(jc_5_M->extModeInfo, rtmGetTPtr(jc_5_M));
  }

  jc_5_M->solverInfoPtr = (&jc_5_M->solverInfo);
  jc_5_M->Timing.stepSize = (0.001);
  rtsiSetFixedStepSize(&jc_5_M->solverInfo, 0.001);
  rtsiSetSolverMode(&jc_5_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  jc_5_M->blockIO = ((void *) &jc_5_B);
  (void) memset(((void *) &jc_5_B), 0,
                sizeof(B_jc_5_T));

  /* parameters */
  jc_5_M->defaultParam = ((real_T *)&jc_5_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &jc_5_X;
    jc_5_M->contStates = (x);
    (void) memset((void *)&jc_5_X, 0,
                  sizeof(X_jc_5_T));
  }

  /* states (dwork) */
  jc_5_M->dwork = ((void *) &jc_5_DW);
  (void) memset((void *)&jc_5_DW, 0,
                sizeof(DW_jc_5_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    jc_5_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 14;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Initialize Sizes */
  jc_5_M->Sizes.numContStates = (6);   /* Number of continuous states */
  jc_5_M->Sizes.numPeriodicContStates = (0);
                                      /* Number of periodic continuous states */
  jc_5_M->Sizes.numY = (0);            /* Number of model outputs */
  jc_5_M->Sizes.numU = (0);            /* Number of model inputs */
  jc_5_M->Sizes.sysDirFeedThru = (0);  /* The model is not direct feedthrough */
  jc_5_M->Sizes.numSampTimes = (2);    /* Number of sample times */
  jc_5_M->Sizes.numBlocks = (29);      /* Number of blocks */
  jc_5_M->Sizes.numBlockIO = (10);     /* Number of block outputs */
  jc_5_M->Sizes.numBlockPrms = (42);   /* Sum of parameter "widths" */
  return jc_5_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
