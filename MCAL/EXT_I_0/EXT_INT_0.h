/*
 * EXT_INT_0.h
 *
 * Created: 4/11/2022 10:06:34 AM
 *  Author: Mena Ghobrial
 */ 


#ifndef EXT_INT_H_
#define EXT_INT_H_


void M_ExtInt0Init(void);
void M_EXT_INT_SetCallBack(void (*)(void));

#define FALLING_EDGE          1
#define RISING_EDGE           2
#define ANY_LOGICAL_CHANGE    3
#define LOW_LEVEL             4

#endif /* EXT_INT_H_ */