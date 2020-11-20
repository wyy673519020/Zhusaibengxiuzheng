/*
 * File: Subsystem.h
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

#ifndef RTW_HEADER_Subsystem_h_
#define RTW_HEADER_Subsystem_h_
#include <math.h>
#include <string.h>
#ifndef Subsystem_COMMON_INCLUDES_
# define Subsystem_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#endif                                 /* Subsystem_COMMON_INCLUDES_ */

#include "Subsystem_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  (rtmGetTPtr((rtm))[0])
#endif

/* Block signals (auto storage) */
typedef struct {
  real_T Gain4;                        /* '<S1>/Gain4' */
  real_T Gain3;                        /* '<S1>/Gain3' */
  real_T Gain;                         /* '<S2>/Gain' */
  real_T wradsphirad[2];               /* '<S1>/Integrator' */
  real_T Gain5;                        /* '<S1>/Gain5' */
  real_T Wdot;                         /* '<S2>/斜盘动力学方程' */
} B_Subsystem_T;

/* Continuous states (auto storage) */
typedef struct {
  real_T Integrator_CSTATE[2];         /* '<S1>/Integrator' */
} X_Subsystem_T;

/* State derivatives (auto storage) */
typedef struct {
  real_T Integrator_CSTATE[2];         /* '<S1>/Integrator' */
} XDot_Subsystem_T;

/* State disabled  */
typedef struct {
  boolean_T Integrator_CSTATE[2];      /* '<S1>/Integrator' */
} XDis_Subsystem_T;

#ifndef ODE4_INTG
#define ODE4_INTG

/* ODE4 Integration Data */
typedef struct {
  real_T *y;                           /* output */
  real_T *f[4];                        /* derivatives */
} ODE4_IntgData;

#endif

/* External inputs (root inport signals with auto storage) */
typedef struct {
  real_T In1[9];                       /* '<Root>/In1' */
} ExtU_Subsystem_T;

/* External outputs (root outports fed by signals with auto storage) */
typedef struct {
  real_T Out1[2];                      /* '<Root>/Out1' */
} ExtY_Subsystem_T;

/* Parameters (auto storage) */
struct P_Subsystem_T_ {
  real_T _A_ZSBTJ[2];                  /* Mask Parameter: _A_ZSBTJ
                                        * Referenced by: '<S2>/A_ZSBTJ'
                                        */
  real_T _A_ZSBZS;                     /* Mask Parameter: _A_ZSBZS
                                        * Referenced by: '<S2>/A_ZSBZS'
                                        */
  real_T _BETA_ZSBSD;                  /* Mask Parameter: _BETA_ZSBSD
                                        * Referenced by: '<S2>/BETA_ZSBSD'
                                        */
  real_T _BETA_ZSBZS;                  /* Mask Parameter: _BETA_ZSBZS
                                        * Referenced by: '<S2>/BETA_ZSBZS'
                                        */
  real_T _D_ZSBZS;                     /* Mask Parameter: _D_ZSBZS
                                        * Referenced by: '<S2>/D_ZSBZS'
                                        */
  real_T _ETA_V;                       /* Mask Parameter: _ETA_V
                                        * Referenced by: '<S2>/ETA_V'
                                        */
  real_T _J_ZSBXP;                     /* Mask Parameter: _J_ZSBXP
                                        * Referenced by: '<S2>/J_ZSBXP'
                                        */
  real_T _KD;                          /* Mask Parameter: _KD
                                        * Referenced by: '<S2>/KD'
                                        */
  real_T _L_ZSBHX;                     /* Mask Parameter: _L_ZSBHX
                                        * Referenced by: '<S2>/L_ZSBHX'
                                        */
  real_T _L_x0;                        /* Mask Parameter: _L_x0
                                        * Referenced by: '<S2>/L_x0'
                                        */
  real_T _M_ZS;                        /* Mask Parameter: _M_ZS
                                        * Referenced by: '<S2>/L_ZSBHX1'
                                        */
  real_T _RHO;                         /* Mask Parameter: _RHO
                                        * Referenced by: '<S2>/RHO'
                                        */
  real_T _Z_ZSBZS;                     /* Mask Parameter: _Z_ZSBZS
                                        * Referenced by: '<S2>/Constant7'
                                        */
  real_T _k;                           /* Mask Parameter: _k
                                        * Referenced by: '<S2>/k'
                                        */
  real_T Gain4_Gain;                   /* Expression: 84*98
                                        * Referenced by: '<S1>/Gain4'
                                        */
  real_T Gain3_Gain;                   /* Expression: 529.2
                                        * Referenced by: '<S1>/Gain3'
                                        */
  real_T Gain2_Gain;                   /* Expression: 3200
                                        * Referenced by: '<S1>/Gain2'
                                        */
  real_T Gain_Gain;                    /* Expression: pi/30
                                        * Referenced by: '<S2>/Gain'
                                        */
  real_T Integrator_IC;                /* Expression: 0
                                        * Referenced by: '<S1>/Integrator'
                                        */
  real_T Integrator_UpperSat[2];       /* Expression: [999999 14.8/180*pi]
                                        * Referenced by: '<S1>/Integrator'
                                        */
  real_T Integrator_LowerSat[2];       /* Expression: [-999999 -0/180*pi ]
                                        * Referenced by: '<S1>/Integrator'
                                        */
  real_T Gain6_Gain;                   /* Expression: 75/273
                                        * Referenced by: '<S1>/Gain6'
                                        */
  real_T Gain5_Gain;                   /* Expression: 48*98
                                        * Referenced by: '<S1>/Gain5'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_Subsystem_T {
  const char_T *errorStatus;
  RTWSolverInfo solverInfo;

  /*
   * ModelData:
   * The following substructure contains information regarding
   * the data used in the model.
   */
  struct {
    X_Subsystem_T *contStates;
    real_T *derivs;
    boolean_T *contStateDisabled;
    boolean_T zCCacheNeedsReset;
    boolean_T derivCacheNeedsReset;
    boolean_T blkStateChange;
    real_T odeY[2];
    real_T odeF[4][2];
    ODE4_IntgData intgData;
  } ModelData;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    int_T numContStates;
    int_T numSampTimes;
  } Sizes;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    time_T stepSize0;
    uint32_T clockTick1;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

/* Block parameters (auto storage) */
extern P_Subsystem_T Subsystem_P;

/* Block signals (auto storage) */
extern B_Subsystem_T Subsystem_B;

/* Continuous states (auto storage) */
extern X_Subsystem_T Subsystem_X;

/* External inputs (root inport signals with auto storage) */
extern ExtU_Subsystem_T Subsystem_U;

/* External outputs (root outports fed by signals with auto storage) */
extern ExtY_Subsystem_T Subsystem_Y;

/* Model entry point functions */
extern void Subsystem_initialize(void);
extern void Subsystem_step(void);
extern void Subsystem_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Subsystem_T *const Subsystem_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Note that this particular code originates from a subsystem build,
 * and has its own system numbers different from the parent model.
 * Refer to the system hierarchy for this subsystem below, and use the
 * MATLAB hilite_system command to trace the generated code back
 * to the parent model.  For example,
 *
 * hilite_system('modelZSBmex/Subsystem')    - opens subsystem modelZSBmex/Subsystem
 * hilite_system('modelZSBmex/Subsystem/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'modelZSBmex'
 * '<S1>'   : 'modelZSBmex/Subsystem'
 * '<S2>'   : 'modelZSBmex/Subsystem/柱塞泵'
 * '<S3>'   : 'modelZSBmex/Subsystem/柱塞泵/斜盘动力学方程'
 * '<S4>'   : 'modelZSBmex/Subsystem/柱塞泵/柱塞'
 * '<S5>'   : 'modelZSBmex/Subsystem/柱塞泵/调节机构'
 */
#endif                                 /* RTW_HEADER_Subsystem_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
