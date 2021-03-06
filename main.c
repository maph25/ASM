/*
 * Copyright (c) 2016, NXP Semiconductor, Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * o Redistributions of source code must retain the above copyright notice, this list
 *   of conditions and the following disclaimer.
 *
 * o Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 *
 * o Neither the name of NXP Semiconductor, Inc. nor the names of its
 *   contributors may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
 
/**
 * @file    asmDelay.c
 * @brief   Application entry point.
 */
#include <stdio.h>
#include "GPIO.h"
#include "delay.h"
#include "DataTypeDefinitions.h"
#include "MK64F12.h"

#define SYSTEM_CLOCK 21000000
#define uSECONDS 1
#define mSECONDS 0
#define DELAY 1000

int main(void) {

	GPIO_pinControlRegisterType pinControlRegisterPORTB = GPIO_MUX1;

	GPIO_clock_gating(GPIO_B);
	GPIO_pin_control_register(GPIO_B,BIT21,&pinControlRegisterPORTB);
	GPIO_data_direction_pin(GPIO_B,GPIO_OUTPUT,BIT21);
	GPIO_set_pin(GPIO_B,BIT21);
	GPIO_clear_pin(GPIO_B,BIT21);
    while(1) {

    	GPIO_set_pin(GPIO_B,BIT21);
    	delay_ms_or_us(DELAY, SYSTEM_CLOCK, mSECONDS);
    	GPIO_clear_pin(GPIO_B,BIT21);
    	delay_ms_or_us(DELAY, SYSTEM_CLOCK, mSECONDS);
    }
    return 0 ;
}
