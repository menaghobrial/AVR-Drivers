/*
 * ADC.c
 *
 * Created: 4/12/2022 10:26:29 AM
 *  Author: Mena Ghobrial
 */ 

#include "STD.h"
#include "BIT_MATH.h"

#include "ADC.h"
#include "REG.h"


void M_AdcInit(void)
{

	#if V_REF              ==      AVCC
		SET_BIT(ADMUX, 6);
		CLR_BIT(ADMUX, 7);
	#elif V_REF            ==      AREF_PIN
	CLR_BIT(ADMUX, 6);
	CLR_BIT(ADMUX, 7);
	#elif V_REF            ==      _2_V
	SET_BIT(ADMUX, 6);
	SET_BIT(ADMUX, 7);
	#endif
	#if RESULT_ADJUST      ==      RIGHT
	CLR_BIT(ADMUX, 5);
	#elif RESULT_ADJUST    ==      LEFT
	SET_BIT(ADMUX, 5);
	#endif
	#if PRESCALAR_D_F      ==       _64
	//prescalar
	CLR_BIT(ADCSRA, 0);
	SET_BIT(ADCSRA, 1);
	SET_BIT(ADCSRA, 2);
	#elif PRESCALAR_D_F    ==       _128
	SET_BIT(ADCSRA, 0);
	SET_BIT(ADCSRA, 1);
	SET_BIT(ADCSRA, 2);
	#endif
	#if   AUTOTRIGGER     ==       ON
	SET_BIT(ADCSRA, 5);
	#elif AUTOTRIGGER     ==       OFF
	CLR_BIT(ADCSRA, 5);
	#endif
	//to enable ADC
	SET_BIT(ADCSRA, 7);
	
}

u16 M_AdcRead(void)
{
	SET_BIT(ADCSRA, 6);
	while((GET_BIT(ADCSRA, 4)) == 0);
	return ADC_VALUE;
}