/*
 * EXT_INT_1.c
 *
 * Created: 4/30/2022 6:04:07 AM
 *  Author: Mena Ghobrial
 */ 

#include "STD.h"
#include "BIT_MATH.h"

#include "EXT_INT_1.h"
#include "REG.h"
#include "EXT_INT_1_CFG.h"

#include <avr/interrupt.h>

void (*int1_call_back) (void);

void M_ExtInt1Init(void)
{
	#if SENSE_CONTROL        ==      FALLING_EDGE
	CLR_BIT(MCUCR, 2);
	SET_BIT(MCUCR, 3);
	#elif SENSE_CONTROL      ==      RISING_EDGE
	SET_BIT(MCUCR, 2);
	SET_BIT(MCUCR, 3);
	#elif SENSE_CONTROL      ==      ANY_LOGICAL_CHANGE
	SET_BIT(MCUCR, 2);
	CLR_BIT(MCUCR, 3);
	#elif SENSE_CONTROL      ==      LOW_LEVEL
	CLR_BIT(MCUCR, 2);
	CLR_BIT(MCUCR, 3);
	#endif
	
	//Enable global interrupt
	SET_BIT(SREG, 7);
	//Enable extint0 int
	SET_BIT(GICR, 7);
}

void M_EXT_INT1_SetCallBack(void (*ptr)(void))
{
	int1_call_back = ptr;
}

ISR(INT1_vect)
{
	int1_call_back();
}        