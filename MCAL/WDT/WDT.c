/*
 * WDT.c
 *
 * Created: 4/19/2022 10:45:35 AM
 *  Author: Mena Ghobrial
 */ 

#include "BIT_MATH.h"
#include "STD.h"

#include "WDT.h"
#include "REG.h"
#include "WDT_CFG.h"

void M_WdtInit(void)
{
	// to set prescalar to 1024
	SET_BIT(WDTCR, 0);
	SET_BIT(WDTCR, 1);
	SET_BIT(WDTCR, 2);
	// to enable WDT
	SET_BIT(WDTCR, 3);
}

void M_WdtRefresh(void)
{
	asm("WDR");
}