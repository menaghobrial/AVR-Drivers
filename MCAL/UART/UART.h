/*
 * UART.h
 *
 * Created: 4/20/2022 11:23:20 AM
 *  Author: Mena Ghobrial
 */ 


#ifndef UART_H_
#define UART_H_

#include "STD.h"

void M_UartInit(void);
void M_UartSend(u8);
u8   M_UartRec(void);

#define OFF	   1
#define ODD    2
#define EVEN   3


#endif /* UART_H_ */