/*
 * REG.h
 *
 * Created: 4/5/2022 3:27:29 PM
 *  Author: Mena Ghobrial
 */ 


#ifndef REG_H_
#define REG_H_

#include "STD.h"

/*
 * Register names :
 * DDRx : Direction
 * PORTx : value of output
 * PINx : value of input
 */
#define PORTA         (*((volatile u8*)0x3B))
#define DDRA          (*((volatile u8*)0x3A))
#define PINA          (*((volatile u8*)0x39))
			          
#define PORTB         (*((volatile u8*)0x38))
#define DDRB          (*((volatile u8*)0x37))
#define PINB          (*((volatile u8*)0x36))
			          
#define PORTC         (*((volatile u8*)0x35))
#define DDRC          (*((volatile u8*)0x34))
#define PINC          (*((volatile u8*)0x33))
			          
#define PORTD         (*((volatile u8*)0x32))
#define DDRD          (*((volatile u8*)0x31))
#define PIND          (*((volatile u8*)0x30))
	
/*******************************************************_EXT_INT_REGISTERS_*******************************************************/
				      
#define MCUCR         (*((volatile u8*)0x55))
#define SREG          (*((volatile u8*)0x5F))
#define GICR          (*((volatile u8*)0x5B))
				      
/*******************************************************_ADC_REGISTERS_*******************************************************/
					  
#define ADMUX         (*((volatile u8*)0x27))
#define ADCSRA        (*((volatile u8*)0x26))
#define ADCL          (*((volatile u8*)0x24))
#define ADCH          (*((volatile u8*)0x25))
#define ADC_VALUE     (*((volatile u16*)0x24))

/*******************************************************_TIMER_0_REGISTERS_*******************************************************/

#define TIMSK         (*((volatile u8*)0x59))
#define TCCR0         (*((volatile u8*)0x53))
#define TCNT0         (*((volatile u8*)0x52))
#define OCR0          (*((volatile u8*)0x5C))


/*******************************************************_TIMER_1_REGISTERS_*******************************************************/

#define TCCR1A     (*((volatile u8*)0x4F))
#define TCCR1B     (*((volatile u8*)0x4E))
#define OCR1A      (*((volatile u16*)0x4A))
#define ICR1       (*((volatile u16*)0x46))

/*******************************************************_WDT_REGISTERS_*******************************************************/

#define WDTCR      (*((volatile u8*)0x41))


/*******************************************************_UART_REGISTERS_*******************************************************/

#define UCSRA      (*((volatile u8*)0x2B))
#define UCSRB      (*((volatile u8*)0x2A))
#define UCSRC      (*((volatile u8*)0x40))
#define UDR        (*((volatile u8*)0x2C))
#define UBRRL      (*((volatile u8*)0x29))


/*******************************************************_SPI_REGISTERS_*******************************************************/

#define SPCR       (*((volatile u8*)0x2D))


#endif /* REG_H_ */