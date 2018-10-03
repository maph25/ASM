/*
 * delay.c
 *
 *  Created on: Sep 20, 2018
 *      Author: LuisFernando
 */

#include "delay.h"
#include "DataTypeDefinitions.h"

#define ms 0.001F
#define us 0.000001F

void delay_cycles(uint32 cycles)
{
	__asm("ldr r1, = 0");
	__asm("ldr r2, = 0xFFFF");
	__asm("LOOP:");
	__asm("adds r0,r0,r2");
	__asm("cmp r1,r0");
	__asm("bne LOOP");

	__asm("FIN: ");
}

void delay_ms_or_us(uint16 time, uint32 systemClock, timeType msOrus)
{
	uint32 cycles = 0;
	ufloat32 clockPeriod = 0.0F;
	clockPeriod = 1/systemClock;
	if(MS == msOrus)
	{
		time = time*ms;
		cycles = (uint32)(time/clockPeriod);
		cycles = cycles - 1;
		delay_cycles(cycles);
	}
	else if(US == msOrus)
	{
		time = time*us;
		cycles = (uint32)(time/clockPeriod);
		cycles = cycles - 1;
		delay_cycles(cycles);
	}
}

