/*
 * TIMER_0_CFG.h
 *
 * Created: 4/14/2022 5:22:33 PM
 *  Author: Mena Ghobrial
 */ 


#ifndef TIMER_0_CFG_H_
#define TIMER_0_CFG_H_

// TIMER_0_MODE options --> [ NORMAL_MODE , CTC_MODE ]
#define TIMER_0_MODE     NORMAL_MODE
// select crystal oscillator frequency in MHz
#define CRYSTAL_FREQ     16
// PRESCALAR_D_F options --> [ 256 , 1024 ]
#define PRESCALAR_D_F    1024
// PWM0MODE --> [  ,]
#define PWM0MODE         PHASE_CORRECT_PWM

#endif /* TIMER_0_CFG_H_ */