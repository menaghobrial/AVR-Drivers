/*
 * TIMER_0.c
 *
 * Created: 4/13/2022 10:14:32 AM
 *  Author: Mena Ghobrial
 */ 

#include "STD.h"
#include "BIT_MATH.h"

#include "TIMER_0.h"
#include "REG.h"
#include "TIMER_0_CFG.h"

#include "DIO.h"
#include <avr/interrupt.h>


void(*T0_call_back)(void);
u32 u32_global_no_of_ov = 0;
u8  u8_global_rem_ticks = 0;
u32 u32_global_no_of_cm = 0;

void M_Timer0Init(void)
{
	#if TIMER_0_MODE             ==     NORMAL_MODE
	//to select normal mode
	CLR_BIT(TCCR0, 3);
	CLR_BIT(TCCR0, 6);
	// to enable timer0 ov interrupt
	SET_BIT(TIMSK, 0);
	#elif TIMER_0_MODE           ==     CTC_MODE
	// to select CTC Mode
	SET_BIT(TCCR0, 3);
	CLR_BIT(TCCR0, 6);
	// to enable CTC interrupt
	SET_BIT(TIMSK, 1);
	#endif
	//to enable global interrupt
	//SET_BIT(SREG, 7);
	asm("SEI"); // it can be this or the above one, but this is better because it is one instruction (cycle)
	
}

void M_Timer0SetTime(u32 u32_local_desired_time)
{
	u32 u32_local_tick_time   = PRESCALAR_D_F / CRYSTAL_FREQ;    //note : 64 is micro second. T=1/F and F=CRYSTAL_FREQ/PRESCALAR_D_F
	u32 u32_local_total_ticks = (u32_local_desired_time *1000) / u32_local_tick_time; // 1000 is to convert from milli to micro
	#if TIMER_0_MODE             ==     NORMAL_MODE
	u32_global_no_of_ov       = u32_local_total_ticks / 256; //we need to know the no. of overflows because the timer interrupts the cpu every overflow
	u8_global_rem_ticks       = u32_local_total_ticks % 256;
	if(u8_global_rem_ticks != 0)
	{
		TCNT0 = 256 - u8_global_rem_ticks;
		u32_global_no_of_ov++;
	}
	#elif TIMER_0_MODE       ==     CTC_MODE
	u8 u8_local_division_number = 255;
	while (u32_local_total_ticks % u8_local_division_number)
	{
		u8_local_division_number--;
	}
	u32_global_no_of_cm = u32_local_total_ticks / u8_local_division_number;
	OCR0                = u8_local_division_number - 1;
	#endif
}

void M_Timer0Start(void)
{
	#if PRESCALAR_D_F        ==        1024
	//to select 1024 division factor
	SET_BIT(TCCR0, 0);
	CLR_BIT(TCCR0, 1);
	SET_BIT(TCCR0, 2);
	#elif PRESCALAR_D_F      ==        256
	// to select 256 division factor
	CLR_BIT(TCCR0, 0);
	CLR_BIT(TCCR0, 1);
	SET_BIT(TCCR0, 2);
	#endif
	
}

void M_Timer0Stop(void)
{
	//to select the first option of the table (stop the timer)
	CLR_BIT(TCCR0, 0);
	CLR_BIT(TCCR0, 1);
	CLR_BIT(TCCR0, 2);
}

void M_Timer0_SetCallBack(void(*ptr)(void))
{
	T0_call_back = ptr;
}

#if TIMER_0_MODE             ==     NORMAL_MODE
ISR(TIMER0_OVF_vect)
{
	static u32 u32_static_local_counter = 0;
	u32_static_local_counter++;
	if(u32_static_local_counter == u32_global_no_of_ov)
	{
		T0_call_back();
		u32_static_local_counter = 0;
		TCNT0                    = 256 - u8_global_rem_ticks;
	}
}

#elif TIMER_0_MODE        ==         CTC_MODE
ISR(TIMER0_COMP_vect)
{
	static u32 u32_static_local_counter = 0;
	u32_static_local_counter++;
	if(u32_static_local_counter == u32_global_no_of_cm)
	{
		T0_call_back();
		u32_static_local_counter = 0;
	}
}
#endif

void M_Pwm0Init(void)
{
	// to enable output circuit
	SET_BIT(DDRB, 3);
	#if   PWM0MODE           ==           FAST_PWM
	// to select fast pwm mode
	SET_BIT(TCCR0, 3);
	SET_BIT(TCCR0, 6);
	// to select non inverted mode
	CLR_BIT(TCCR0, 4);
	SET_BIT(TCCR0, 5);
	#elif PWM0MODE           ==           PHASE_CORRECT_PWM
	// to select phase correct mode
	SET_BIT(TCCR0, 3);
	CLR_BIT(TCCR0, 6);
	// to select non inverted mode
	CLR_BIT(TCCR0, 4);
	SET_BIT(TCCR0, 5);
	#endif
	
}

void M_Pwm0SetDutyCycle(u8 u8_local_dutyCycle)
{
	#if   PWM0MODE           ==           FAST_PWM
	OCR0 = ((u8_local_dutyCycle * 256)/100) - 1;
	#elif PWM0MODE           ==           PHASE_CORRECT_PWM
	OCR0 = ((u8_local_dutyCycle * 255)/100);
	#endif
}

void M_Pwm0Start(void)
{
	M_Timer0Start();
}

void M_Pwm0Stop(void)
{
	M_Timer0Stop();
}