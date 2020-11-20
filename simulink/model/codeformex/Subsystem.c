/*
 * File: Subsystem.c
 *
 * Code generated for Simulink model 'Subsystem'.
 *
 * Model version                  : 1.575
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * C/C++ source code generated on : Fri Nov 20 16:56:52 2020
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Subsystem.h"
#include "Subsystem_private.h"

/* Block signals (auto storage) */
B_Subsystem_T Subsystem_B;

/* Continuous states */
X_Subsystem_T Subsystem_X;

/* External inputs (root inport signals with auto storage) */
ExtU_Subsystem_T Subsystem_U;

/* External outputs (root outports fed by signals with auto storage) */
ExtY_Subsystem_T Subsystem_Y;

/* Real-time model */
RT_MODEL_Subsystem_T Subsystem_M_;
RT_MODEL_Subsystem_T *const Subsystem_M = &Subsystem_M_;

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
  Subsystem_derivatives();

  /* f1 = f(t + (h/2), y + (h/2)*f0) */
  temp = 0.5 * h;
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (temp*f0[i]);
  }

  rtsiSetT(si, t + temp);
  rtsiSetdX(si, f1);
  Subsystem_step();
  Subsystem_derivatives();

  /* f2 = f(t + (h/2), y + (h/2)*f1) */
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (temp*f1[i]);
  }

  rtsiSetdX(si, f2);
  Subsystem_step();
  Subsystem_derivatives();

  /* f3 = f(t + h, y + h*f2) */
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (h*f2[i]);
  }

  rtsiSetT(si, tnew);
  rtsiSetdX(si, f3);
  Subsystem_step();
  Subsystem_derivatives();

  /* tnew = t + h
     ynew = y + (h/6)*(f0 + 2*f1 + 2*f2 + 2*f3) */
  temp = h / 6.0;
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + temp*(f0[i] + 2.0*f1[i] + 2.0*f2[i] + f3[i]);
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model step function */
void Subsystem_step(void)
{
  real_T r;
  real_T Pleft;
  real_T delta;
  real_T a;
  if (rtmIsMajorTimeStep(Subsystem_M)) {
    /* set solver stop time */
    rtsiSetSolverStopTime(&Subsystem_M->solverInfo,
                          ((Subsystem_M->Timing.clockTick0+1)*
      Subsystem_M->Timing.stepSize0));
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(Subsystem_M)) {
    Subsystem_M->Timing.t[0] = rtsiGetT(&Subsystem_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(Subsystem_M)) {
    /* Gain: '<S1>/Gain4' incorporates:
     *  Inport: '<Root>/In1'
     */
    Subsystem_B.Gain4 = Subsystem_P.Gain4_Gain * Subsystem_U.In1[2];

    /* Gain: '<S1>/Gain3' incorporates:
     *  Inport: '<Root>/In1'
     */
    Subsystem_B.Gain3 = Subsystem_P.Gain3_Gain * Subsystem_U.In1[1];

    /* Gain: '<S2>/Gain' incorporates:
     *  Gain: '<S1>/Gain2'
     *  Inport: '<Root>/In1'
     */
    Subsystem_B.Gain = Subsystem_P.Gain2_Gain * Subsystem_U.In1[0] *
      Subsystem_P.Gain_Gain;
  }

  /* Integrator: '<S1>/Integrator'
   *
   * Regarding '<S1>/Integrator':
   *  Limited Integrator
   */
  if (Subsystem_X.Integrator_CSTATE[0] >= (Subsystem_P.Integrator_UpperSat[0]) )
  {
    Subsystem_X.Integrator_CSTATE[0] = (Subsystem_P.Integrator_UpperSat[0]);
  } else if (Subsystem_X.Integrator_CSTATE[0] <=
             (Subsystem_P.Integrator_LowerSat[0]) ) {
    Subsystem_X.Integrator_CSTATE[0] = (Subsystem_P.Integrator_LowerSat[0]);
  }

  if (Subsystem_X.Integrator_CSTATE[1] >= (Subsystem_P.Integrator_UpperSat[1]) )
  {
    Subsystem_X.Integrator_CSTATE[1] = (Subsystem_P.Integrator_UpperSat[1]);
  } else if (Subsystem_X.Integrator_CSTATE[1] <=
             (Subsystem_P.Integrator_LowerSat[1]) ) {
    Subsystem_X.Integrator_CSTATE[1] = (Subsystem_P.Integrator_LowerSat[1]);
  }

  Subsystem_B.wradsphirad[0] = Subsystem_X.Integrator_CSTATE[0];
  Subsystem_B.wradsphirad[1] = Subsystem_X.Integrator_CSTATE[1];

  /* MATLAB Function: '<S2>/柱塞' incorporates:
   *  Constant: '<S2>/D_ZSBZS'
   */
  /* MATLAB Function 'Subsystem/柱塞泵/柱塞': '<S4>:1' */
  /* '<S4>:1:3' */
  r = Subsystem_P._D_ZSBZS / 2.0;

  /* Outport: '<Root>/Out1' incorporates:
   *  Constant: '<S2>/A_ZSBZS'
   *  Constant: '<S2>/BETA_ZSBZS'
   *  Constant: '<S2>/Constant7'
   *  Constant: '<S2>/ETA_V'
   *  Constant: '<S2>/RHO'
   *  Gain: '<S1>/Gain6'
   *  MATLAB Function: '<S2>/柱塞'
   */
  /* '<S4>:1:4' */
  /* '<S4>:1:6' */
  /* '<S4>:1:7' */
  /* '<S4>:1:8' */
  /* -- Calculate q_tab and total Q -- */
  /* '<S4>:1:11' */
  Subsystem_Y.Out1[0] = Subsystem_P._RHO * Subsystem_P._ETA_V * cos
    (Subsystem_P._BETA_ZSBZS) * Subsystem_P._A_ZSBZS * (2.0 * r * tan
    (Subsystem_B.wradsphirad[1])) * Subsystem_P._Z_ZSBZS * Subsystem_B.Gain *
    0.5 / 3.1415926535897931 * 1.0E-9 * Subsystem_P.Gain6_Gain;
  Subsystem_Y.Out1[1] = Subsystem_B.wradsphirad[1];
  if (rtmIsMajorTimeStep(Subsystem_M)) {
    /* Gain: '<S1>/Gain5' incorporates:
     *  Inport: '<Root>/In1'
     */
    Subsystem_B.Gain5 = Subsystem_P.Gain5_Gain * Subsystem_U.In1[3];
  }

  /* MATLAB Function: '<S2>/调节机构' incorporates:
   *  Constant: '<S2>/BETA_ZSBSD'
   *  Inport: '<Root>/In1'
   */
  /* MATLAB Function 'Subsystem/柱塞泵/调节机构': '<S5>:1' */
  /* 计算活塞位置 */
  /* '<S5>:1:4' */
  a = Subsystem_U.In1[5] - cos(Subsystem_B.wradsphirad[1] +
    Subsystem_P._BETA_ZSBSD) * Subsystem_U.In1[4];

  /* 计算随动活塞杆上的作用力 */
  /* '<S5>:1:7' */
  Pleft = Subsystem_B.Gain4 * 1000.0;

  /* kPa */
  /* '<S5>:1:8' */
  /* kPa */
  /* '<S5>:1:9' */
  /* N */
  /* '<S5>:1:10' */
  /* N */
  /* '<S5>:1:11' */
  /* '<S5>:1:12' */
  /* 计算随动活塞杆力对斜盘作用力矩 */
  /* '<S5>:1:15' */
  delta = asin((Subsystem_U.In1[5] - cos(Subsystem_B.wradsphirad[1] +
    Subsystem_P._BETA_ZSBSD) * Subsystem_U.In1[4]) / Subsystem_U.In1[6]);

  /* MATLAB Function: '<S2>/斜盘动力学方程' incorporates:
   *  Constant: '<S2>/A_ZSBTJ'
   *  Constant: '<S2>/A_ZSBZS'
   *  Constant: '<S2>/BETA_ZSBSD'
   *  Constant: '<S2>/Constant7'
   *  Constant: '<S2>/J_ZSBXP'
   *  Constant: '<S2>/KD'
   *  Constant: '<S2>/L_ZSBHX'
   *  Constant: '<S2>/L_ZSBHX1'
   *  Constant: '<S2>/L_x0'
   *  Constant: '<S2>/k'
   *  Inport: '<Root>/In1'
   *  MATLAB Function: '<S2>/调节机构'
   *  MATLAB Function: '<S2>/柱塞'
   */
  /* '<S5>:1:16' */
  /* MATLAB Function 'Subsystem/柱塞泵/斜盘动力学方程': '<S3>:1' */
  /* '<S3>:1:3' */
  /* '<S3>:1:4' */
  Subsystem_B.Wdot = (((((Subsystem_P._L_x0 - (((sin(Subsystem_B.wradsphirad[1]
    + Subsystem_P._BETA_ZSBSD) * Subsystem_U.In1[4] + Subsystem_U.In1[7]) -
    Subsystem_U.In1[8]) - sqrt(Subsystem_U.In1[6] * Subsystem_U.In1[6] - a * a)))
    * Subsystem_P._k * 0.001 + (Pleft - Subsystem_B.Gain5 * 1000.0) *
    Subsystem_P._A_ZSBTJ[1] * 1.0E-6) - Pleft * Subsystem_P._A_ZSBTJ[0] * 1.0E-6)
                       / cos(delta) * cos((delta - Subsystem_B.wradsphirad[1]) -
    Subsystem_P._BETA_ZSBSD) * Subsystem_U.In1[4] * 0.001 + (0.5 * r * r *
    Subsystem_P._Z_ZSBZS * Subsystem_P._M_ZS * tan(Subsystem_B.wradsphirad[1]) *
    Subsystem_B.Gain * Subsystem_B.Gain / cos(Subsystem_B.wradsphirad[1]) + -0.5
    * Subsystem_P._Z_ZSBZS * Subsystem_P._L_ZSBHX * tan(Subsystem_B.wradsphirad
    [1]) * Subsystem_P._A_ZSBZS * (Subsystem_B.Gain4 + Subsystem_B.Gain3) / cos
    (Subsystem_B.wradsphirad[1])) * 1.0E-6) - Subsystem_B.wradsphirad[0] *
                      Subsystem_P._KD) / Subsystem_P._J_ZSBXP;
  if (rtmIsMajorTimeStep(Subsystem_M)) {
    rt_ertODEUpdateContinuousStates(&Subsystem_M->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     */
    ++Subsystem_M->Timing.clockTick0;
    Subsystem_M->Timing.t[0] = rtsiGetSolverStopTime(&Subsystem_M->solverInfo);

    {
      /* Update absolute timer for sample time: [0.01s, 0.0s] */
      /* The "clockTick1" counts the number of times the code of this task has
       * been executed. The resolution of this integer timer is 0.01, which is the step size
       * of the task. Size of "clockTick1" ensures timer will not overflow during the
       * application lifespan selected.
       */
      Subsystem_M->Timing.clockTick1++;
    }
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void Subsystem_derivatives(void)
{
  /* Derivatives for Integrator: '<S1>/Integrator' */
  {
    boolean_T lsat;
    boolean_T usat;
    lsat = ( Subsystem_X.Integrator_CSTATE[0] <=
            (Subsystem_P.Integrator_LowerSat[0]) );
    usat = ( Subsystem_X.Integrator_CSTATE[0] >=
            (Subsystem_P.Integrator_UpperSat[0]) );
    if ((!lsat && !usat) ||
        (lsat && (Subsystem_B.Wdot > 0)) ||
        (usat && (Subsystem_B.Wdot < 0)) ) {
      ((XDot_Subsystem_T *) Subsystem_M->ModelData.derivs)->Integrator_CSTATE[0]
        = Subsystem_B.Wdot;
    } else {
      /* in saturation */
      ((XDot_Subsystem_T *) Subsystem_M->ModelData.derivs)->Integrator_CSTATE[0]
        = 0.0;
    }

    lsat = ( Subsystem_X.Integrator_CSTATE[1] <=
            (Subsystem_P.Integrator_LowerSat[1]) );
    usat = ( Subsystem_X.Integrator_CSTATE[1] >=
            (Subsystem_P.Integrator_UpperSat[1]) );
    if ((!lsat && !usat) ||
        (lsat && (Subsystem_B.wradsphirad[0] > 0)) ||
        (usat && (Subsystem_B.wradsphirad[0] < 0)) ) {
      ((XDot_Subsystem_T *) Subsystem_M->ModelData.derivs)->Integrator_CSTATE[1]
        = Subsystem_B.wradsphirad[0];
    } else {
      /* in saturation */
      ((XDot_Subsystem_T *) Subsystem_M->ModelData.derivs)->Integrator_CSTATE[1]
        = 0.0;
    }
  }
}

/* Model initialize function */
void Subsystem_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)Subsystem_M, 0,
                sizeof(RT_MODEL_Subsystem_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&Subsystem_M->solverInfo,
                          &Subsystem_M->Timing.simTimeStep);
    rtsiSetTPtr(&Subsystem_M->solverInfo, &rtmGetTPtr(Subsystem_M));
    rtsiSetStepSizePtr(&Subsystem_M->solverInfo, &Subsystem_M->Timing.stepSize0);
    rtsiSetdXPtr(&Subsystem_M->solverInfo, &Subsystem_M->ModelData.derivs);
    rtsiSetContStatesPtr(&Subsystem_M->solverInfo, (real_T **)
                         &Subsystem_M->ModelData.contStates);
    rtsiSetNumContStatesPtr(&Subsystem_M->solverInfo,
      &Subsystem_M->Sizes.numContStates);
    rtsiSetErrorStatusPtr(&Subsystem_M->solverInfo, (&rtmGetErrorStatus
      (Subsystem_M)));
    rtsiSetRTModelPtr(&Subsystem_M->solverInfo, Subsystem_M);
  }

  rtsiSetSimTimeStep(&Subsystem_M->solverInfo, MAJOR_TIME_STEP);
  Subsystem_M->ModelData.intgData.y = Subsystem_M->ModelData.odeY;
  Subsystem_M->ModelData.intgData.f[0] = Subsystem_M->ModelData.odeF[0];
  Subsystem_M->ModelData.intgData.f[1] = Subsystem_M->ModelData.odeF[1];
  Subsystem_M->ModelData.intgData.f[2] = Subsystem_M->ModelData.odeF[2];
  Subsystem_M->ModelData.intgData.f[3] = Subsystem_M->ModelData.odeF[3];
  Subsystem_M->ModelData.contStates = ((X_Subsystem_T *) &Subsystem_X);
  rtsiSetSolverData(&Subsystem_M->solverInfo, (void *)
                    &Subsystem_M->ModelData.intgData);
  rtsiSetSolverName(&Subsystem_M->solverInfo,"ode4");
  rtmSetTPtr(Subsystem_M, &Subsystem_M->Timing.tArray[0]);
  Subsystem_M->Timing.stepSize0 = 0.01;

  /* block I/O */
  (void) memset(((void *) &Subsystem_B), 0,
                sizeof(B_Subsystem_T));

  /* states (continuous) */
  {
    (void) memset((void *)&Subsystem_X, 0,
                  sizeof(X_Subsystem_T));
  }

  /* external inputs */
  (void) memset(Subsystem_U.In1, 0,
                9U*sizeof(real_T));

  /* external outputs */
  (void) memset(&Subsystem_Y.Out1[0], 0,
                2U*sizeof(real_T));

  /* InitializeConditions for Integrator: '<S1>/Integrator' */
  Subsystem_X.Integrator_CSTATE[0] = Subsystem_P.Integrator_IC;
  Subsystem_X.Integrator_CSTATE[1] = Subsystem_P.Integrator_IC;
}

/* Model terminate function */
void Subsystem_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
