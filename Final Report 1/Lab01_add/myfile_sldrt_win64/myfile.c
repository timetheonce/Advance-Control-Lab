/*
 * myfile.c
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
#include "myfile_dt.h"

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
B_myfile_T myfile_B;

/* Continuous states */
X_myfile_T myfile_X;

/* Block states (default storage) */
DW_myfile_T myfile_DW;

/* Real-time model */
RT_MODEL_myfile_T myfile_M_;
RT_MODEL_myfile_T *const myfile_M = &myfile_M_;

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
  myfile_derivatives();

  /* f1 = f(t + (h/2), y + (h/2)*f0) */
  temp = 0.5 * h;
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (temp*f0[i]);
  }

  rtsiSetT(si, t + temp);
  rtsiSetdX(si, f1);
  myfile_output();
  myfile_derivatives();

  /* f2 = f(t + (h/2), y + (h/2)*f1) */
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (temp*f1[i]);
  }

  rtsiSetdX(si, f2);
  myfile_output();
  myfile_derivatives();

  /* f3 = f(t + h, y + h*f2) */
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (h*f2[i]);
  }

  rtsiSetT(si, tnew);
  rtsiSetdX(si, f3);
  myfile_output();
  myfile_derivatives();

  /* tnew = t + h
     ynew = y + (h/6)*(f0 + 2*f1 + 2*f2 + 2*f3) */
  temp = h / 6.0;
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + temp*(f0[i] + 2.0*f1[i] + 2.0*f2[i] + f3[i]);
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model output function */
void myfile_output(void)
{
  real_T u0;
  real_T u1;
  real_T u2;
  if (rtmIsMajorTimeStep(myfile_M)) {
    /* set solver stop time */
    if (!(myfile_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&myfile_M->solverInfo,
                            ((myfile_M->Timing.clockTickH0 + 1) *
        myfile_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&myfile_M->solverInfo, ((myfile_M->Timing.clockTick0
        + 1) * myfile_M->Timing.stepSize0 + myfile_M->Timing.clockTickH0 *
        myfile_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(myfile_M)) {
    myfile_M->Timing.t[0] = rtsiGetT(&myfile_M->solverInfo);
  }

  /* TransferFcn: '<Root>/Transfer Fcn' */
  myfile_B.TransferFcn = 0.0;
  myfile_B.TransferFcn += myfile_P.TransferFcn_C[0] *
    myfile_X.TransferFcn_CSTATE[0];
  myfile_B.TransferFcn += myfile_P.TransferFcn_C[1] *
    myfile_X.TransferFcn_CSTATE[1];

  /* Saturate: '<Root>/Saturation' */
  u0 = myfile_B.TransferFcn;
  u1 = myfile_P.Saturation_LowerSat;
  u2 = myfile_P.Saturation_UpperSat;
  if (u0 > u2) {
    myfile_B.Saturation = u2;
  } else if (u0 < u1) {
    myfile_B.Saturation = u1;
  } else {
    myfile_B.Saturation = u0;
  }

  /* End of Saturate: '<Root>/Saturation' */

  /* Gain: '<Root>/Gain2' */
  myfile_B.Gain2 = myfile_P.Gain2_Gain * myfile_B.Saturation;
  if (rtmIsMajorTimeStep(myfile_M)) {
    /* S-Function (sldrtao): '<Root>/Analog Output' */
    /* S-Function Block: <Root>/Analog Output */
    {
      {
        ANALOGIOPARM parm;
        parm.mode = (RANGEMODE) myfile_P.AnalogOutput_RangeMode;
        parm.rangeidx = myfile_P.AnalogOutput_VoltRange;
        RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1,
                       &myfile_P.AnalogOutput_Channels, ((real_T*)
          (&myfile_B.Gain2)), &parm);
      }
    }

    /* Constant: '<Root>/Constant' */
    myfile_B.Constant = myfile_P.Constant_Value;

    /* S-Function (sldrtei): '<Root>/Encoder Input' */
    /* S-Function Block: <Root>/Encoder Input */
    {
      ENCODERINPARM parm;
      parm.quad = (QUADMODE) 2;
      parm.index = (INDEXPULSE) 0;
      parm.infilter = myfile_P.EncoderInput_InputFilter;
      RTBIO_DriverIO(0, ENCODERINPUT, IOREAD, 1, &myfile_P.EncoderInput_Channels,
                     &myfile_B.EncoderInput, &parm);
    }

    /* S-Function (sldrtei): '<Root>/Encoder Input1' */
    /* S-Function Block: <Root>/Encoder Input1 */
    {
      ENCODERINPARM parm;
      parm.quad = (QUADMODE) 2;
      parm.index = (INDEXPULSE) 0;
      parm.infilter = myfile_P.EncoderInput1_InputFilter;
      RTBIO_DriverIO(0, ENCODERINPUT, IOREAD, 1,
                     &myfile_P.EncoderInput1_Channels, &myfile_B.EncoderInput1,
                     &parm);
    }

    /* Gain: '<Root>/Arm' */
    myfile_B.Arm = myfile_P.Arm_Gain * myfile_B.EncoderInput;

    /* Gain: '<Root>/pendulum' */
    myfile_B.pendulum = myfile_P.pendulum_Gain * myfile_B.EncoderInput1;
  }
}

/* Model update function */
void myfile_update(void)
{
  if (rtmIsMajorTimeStep(myfile_M)) {
    rt_ertODEUpdateContinuousStates(&myfile_M->solverInfo);
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
  if (!(++myfile_M->Timing.clockTick0)) {
    ++myfile_M->Timing.clockTickH0;
  }

  myfile_M->Timing.t[0] = rtsiGetSolverStopTime(&myfile_M->solverInfo);

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
    if (!(++myfile_M->Timing.clockTick1)) {
      ++myfile_M->Timing.clockTickH1;
    }

    myfile_M->Timing.t[1] = myfile_M->Timing.clockTick1 *
      myfile_M->Timing.stepSize1 + myfile_M->Timing.clockTickH1 *
      myfile_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Derivatives for root system: '<Root>' */
void myfile_derivatives(void)
{
  XDot_myfile_T *_rtXdot;
  _rtXdot = ((XDot_myfile_T *) myfile_M->derivs);

  /* Derivatives for TransferFcn: '<Root>/Transfer Fcn' */
  _rtXdot->TransferFcn_CSTATE[0] = 0.0;
  _rtXdot->TransferFcn_CSTATE[0] += myfile_P.TransferFcn_A[0] *
    myfile_X.TransferFcn_CSTATE[0];
  _rtXdot->TransferFcn_CSTATE[1] = 0.0;
  _rtXdot->TransferFcn_CSTATE[0] += myfile_P.TransferFcn_A[1] *
    myfile_X.TransferFcn_CSTATE[1];
  _rtXdot->TransferFcn_CSTATE[1] += myfile_X.TransferFcn_CSTATE[0];
  _rtXdot->TransferFcn_CSTATE[0] += myfile_B.Constant;
}

/* Model initialize function */
void myfile_initialize(void)
{
  /* Start for S-Function (sldrtao): '<Root>/Analog Output' */

  /* S-Function Block: <Root>/Analog Output */
  {
    {
      ANALOGIOPARM parm;
      parm.mode = (RANGEMODE) myfile_P.AnalogOutput_RangeMode;
      parm.rangeidx = myfile_P.AnalogOutput_VoltRange;
      RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1,
                     &myfile_P.AnalogOutput_Channels,
                     &myfile_P.AnalogOutput_InitialValue, &parm);
    }
  }

  /* InitializeConditions for TransferFcn: '<Root>/Transfer Fcn' */
  myfile_X.TransferFcn_CSTATE[0] = 0.0;
  myfile_X.TransferFcn_CSTATE[1] = 0.0;

  /* InitializeConditions for S-Function (sldrtei): '<Root>/Encoder Input' */

  /* S-Function Block: <Root>/Encoder Input */
  {
    ENCODERINPARM parm;
    parm.quad = (QUADMODE) 2;
    parm.index = (INDEXPULSE) 0;
    parm.infilter = myfile_P.EncoderInput_InputFilter;
    RTBIO_DriverIO(0, ENCODERINPUT, IORESET, 1, &myfile_P.EncoderInput_Channels,
                   NULL, &parm);
  }

  /* InitializeConditions for S-Function (sldrtei): '<Root>/Encoder Input1' */

  /* S-Function Block: <Root>/Encoder Input1 */
  {
    ENCODERINPARM parm;
    parm.quad = (QUADMODE) 2;
    parm.index = (INDEXPULSE) 0;
    parm.infilter = myfile_P.EncoderInput1_InputFilter;
    RTBIO_DriverIO(0, ENCODERINPUT, IORESET, 1, &myfile_P.EncoderInput1_Channels,
                   NULL, &parm);
  }
}

/* Model terminate function */
void myfile_terminate(void)
{
  /* Terminate for S-Function (sldrtao): '<Root>/Analog Output' */

  /* S-Function Block: <Root>/Analog Output */
  {
    {
      ANALOGIOPARM parm;
      parm.mode = (RANGEMODE) myfile_P.AnalogOutput_RangeMode;
      parm.rangeidx = myfile_P.AnalogOutput_VoltRange;
      RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1,
                     &myfile_P.AnalogOutput_Channels,
                     &myfile_P.AnalogOutput_FinalValue, &parm);
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
  myfile_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  myfile_update();
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
  myfile_initialize();
}

void MdlTerminate(void)
{
  myfile_terminate();
}

/* Registration function */
RT_MODEL_myfile_T *myfile(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* non-finite (run-time) assignments */
  myfile_P.EncoderInput_InputFilter = rtInf;
  myfile_P.EncoderInput1_InputFilter = rtInf;

  /* initialize real-time model */
  (void) memset((void *)myfile_M, 0,
                sizeof(RT_MODEL_myfile_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&myfile_M->solverInfo, &myfile_M->Timing.simTimeStep);
    rtsiSetTPtr(&myfile_M->solverInfo, &rtmGetTPtr(myfile_M));
    rtsiSetStepSizePtr(&myfile_M->solverInfo, &myfile_M->Timing.stepSize0);
    rtsiSetdXPtr(&myfile_M->solverInfo, &myfile_M->derivs);
    rtsiSetContStatesPtr(&myfile_M->solverInfo, (real_T **)
                         &myfile_M->contStates);
    rtsiSetNumContStatesPtr(&myfile_M->solverInfo,
      &myfile_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&myfile_M->solverInfo,
      &myfile_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&myfile_M->solverInfo,
      &myfile_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&myfile_M->solverInfo,
      &myfile_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&myfile_M->solverInfo, (&rtmGetErrorStatus(myfile_M)));
    rtsiSetRTModelPtr(&myfile_M->solverInfo, myfile_M);
  }

  rtsiSetSimTimeStep(&myfile_M->solverInfo, MAJOR_TIME_STEP);
  myfile_M->intgData.y = myfile_M->odeY;
  myfile_M->intgData.f[0] = myfile_M->odeF[0];
  myfile_M->intgData.f[1] = myfile_M->odeF[1];
  myfile_M->intgData.f[2] = myfile_M->odeF[2];
  myfile_M->intgData.f[3] = myfile_M->odeF[3];
  myfile_M->contStates = ((real_T *) &myfile_X);
  rtsiSetSolverData(&myfile_M->solverInfo, (void *)&myfile_M->intgData);
  rtsiSetSolverName(&myfile_M->solverInfo,"ode4");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = myfile_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    myfile_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    myfile_M->Timing.sampleTimes = (&myfile_M->Timing.sampleTimesArray[0]);
    myfile_M->Timing.offsetTimes = (&myfile_M->Timing.offsetTimesArray[0]);

    /* task periods */
    myfile_M->Timing.sampleTimes[0] = (0.0);
    myfile_M->Timing.sampleTimes[1] = (0.001);

    /* task offsets */
    myfile_M->Timing.offsetTimes[0] = (0.0);
    myfile_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(myfile_M, &myfile_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = myfile_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    myfile_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(myfile_M, -1);
  myfile_M->Timing.stepSize0 = 0.001;
  myfile_M->Timing.stepSize1 = 0.001;

  /* External mode info */
  myfile_M->Sizes.checksums[0] = (2987935103U);
  myfile_M->Sizes.checksums[1] = (3321043721U);
  myfile_M->Sizes.checksums[2] = (19740605U);
  myfile_M->Sizes.checksums[3] = (238372278U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    myfile_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(myfile_M->extModeInfo,
      &myfile_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(myfile_M->extModeInfo, myfile_M->Sizes.checksums);
    rteiSetTPtr(myfile_M->extModeInfo, rtmGetTPtr(myfile_M));
  }

  myfile_M->solverInfoPtr = (&myfile_M->solverInfo);
  myfile_M->Timing.stepSize = (0.001);
  rtsiSetFixedStepSize(&myfile_M->solverInfo, 0.001);
  rtsiSetSolverMode(&myfile_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  myfile_M->blockIO = ((void *) &myfile_B);
  (void) memset(((void *) &myfile_B), 0,
                sizeof(B_myfile_T));

  /* parameters */
  myfile_M->defaultParam = ((real_T *)&myfile_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &myfile_X;
    myfile_M->contStates = (x);
    (void) memset((void *)&myfile_X, 0,
                  sizeof(X_myfile_T));
  }

  /* states (dwork) */
  myfile_M->dwork = ((void *) &myfile_DW);
  (void) memset((void *)&myfile_DW, 0,
                sizeof(DW_myfile_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    myfile_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 14;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Initialize Sizes */
  myfile_M->Sizes.numContStates = (2); /* Number of continuous states */
  myfile_M->Sizes.numPeriodicContStates = (0);
                                      /* Number of periodic continuous states */
  myfile_M->Sizes.numY = (0);          /* Number of model outputs */
  myfile_M->Sizes.numU = (0);          /* Number of model inputs */
  myfile_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  myfile_M->Sizes.numSampTimes = (2);  /* Number of sample times */
  myfile_M->Sizes.numBlocks = (14);    /* Number of blocks */
  myfile_M->Sizes.numBlockIO = (8);    /* Number of block outputs */
  myfile_M->Sizes.numBlockPrms = (25); /* Sum of parameter "widths" */
  return myfile_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
