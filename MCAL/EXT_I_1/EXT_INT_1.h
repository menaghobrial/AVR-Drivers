/*
 * EXT_INT_1.h
 *
 * Created: 4/30/2022 6:03:59 AM
 *  Author: Mena Ghobrial
 */ 


#ifndef EXT_INT_1_H_
#define EXT_INT_1_H_


void M_ExtInt1Init(void);
void M_EXT_INT1_SetCallBack(void (*)(void));

#define FALLING_EDGE          1
#define RISING_EDGE           2
#define ANY_LOGICAL_CHANGE    3
#define LOW_LEVEL             4


#endif /* EXT_INT_1_H_ */