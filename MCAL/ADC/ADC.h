/*
 * ADC.h
 *
 * Created: 4/12/2022 10:23:26 AM
 *  Author: Mena Ghobrial
 */ 


#ifndef ADC_H_
#define ADC_H_
#include "ADC_CFG.h"

void M_AdcInit(void);
u16 M_AdcRead(void);

#define AVCC       1
#define AREF_PIN   2
#define _2_V       3

#define RIGHT      4
#define LEFT       5

#define _64        6
#define _128       7

#define ON         8
#define OFF        9



#endif /* ADC_H_ */