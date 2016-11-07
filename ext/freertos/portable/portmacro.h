/*
    FreeRTOS V7.0.1 - Copyright (C) 2011 Real Time Engineers Ltd.
    
    Copyright (c) 2011, Fabian Greif
    Copyright (c) 2012, 2015, Niklas Hauser

    ***************************************************************************
     *                                                                       *
     *    FreeRTOS tutorial books are available in pdf and paperback.        *
     *    Complete, revised, and edited pdf reference manuals are also       *
     *    available.                                                         *
     *                                                                       *
     *    Purchasing FreeRTOS documentation will not only help you, by       *
     *    ensuring you get running as quickly as possible and with an        *
     *    in-depth knowledge of how to use FreeRTOS, it will also help       *
     *    the FreeRTOS project to continue with its mission of providing     *
     *    professional grade, cross platform, de facto standard solutions    *
     *    for microcontrollers - completely free of charge!                  *
     *                                                                       *
     *    >>> See http://www.FreeRTOS.org/Documentation for details. <<<     *
     *                                                                       *
     *    Thank you for using FreeRTOS, and thank you for your support!      *
     *                                                                       *
    ***************************************************************************


    This file is part of the FreeRTOS distribution.

    FreeRTOS is free software; you can redistribute it and/or modify it under
    the terms of the GNU General Public License (version 2) as published by the
    Free Software Foundation AND MODIFIED BY the FreeRTOS exception.
    >>>NOTE<<< The modification to the GPL is included to allow you to
    distribute a combined work that includes FreeRTOS without being obliged to
    provide the source code for proprietary components outside of the FreeRTOS
    kernel.  FreeRTOS is distributed in the hope that it will be useful, but
    WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
    or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
    more details. You should have received a copy of the GNU General Public
    License and the FreeRTOS license exception along with FreeRTOS; if not it
    can be viewed here: http://www.freertos.org/a00114.html and also obtained
    by writing to Richard Barry, contact details for whom are available on the
    FreeRTOS WEB site.

    1 tab == 4 spaces!

    http://www.FreeRTOS.org - Documentation, latest information, license and
    contact details.

    http://www.SafeRTOS.com - A version that is certified for use in safety
    critical systems.

    http://www.OpenRTOS.com - Commercial support, development, porting,
    licensing and training services.
*/


#ifndef PORTMACRO_H
#define PORTMACRO_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/*-----------------------------------------------------------
 * Port specific definitions.  
 *
 * The settings in this file configure FreeRTOS correctly for the
 * given hardware and compiler.
 *
 * These settings should not be altered.
 *-----------------------------------------------------------
 */

/* Type definitions. */
#define portCHAR		char
#define portFLOAT		float
#define portDOUBLE		double
#define portLONG		long
#define portSHORT		short
#define portSTACK_TYPE	uint32_t
#define portBASE_TYPE	long

#if( configUSE_16_BIT_TICKS == 1 )
	typedef unsigned portSHORT portTickType;
	#define portMAX_DELAY ( portTickType ) 0xffff
#else
	typedef unsigned portLONG portTickType;
	#define portMAX_DELAY ( portTickType ) 0xffffffff
#endif
/*-----------------------------------------------------------*/	

/* Architecture specifics. */
#define portSTACK_GROWTH			( -1 )
#if configTICK_RATE_HZ > 1000
/*
    this is a really ugly hack, the smallest time is 1ms here, we want 0.1ms (or whatever configTICK_RATE_HZ is).
    But we do not want to divide floating point either, because that will promote the entre value to float.
    The only code that uses this looks like this `500 / portTICK_RATE_MS`.
    So we replace the macro `portTICK_RATE_MS` with `1 * 10` -> `500 / 1 * 10`, which only works in this case!!!
*/
#   define portTICK_RATE_MS			1 * (configTICK_RATE_HZ / 1000)
#else   
#   define portTICK_RATE_MS         ( ( portTickType ) 1000 / configTICK_RATE_HZ )
#endif
#define portBYTE_ALIGNMENT			8
/*-----------------------------------------------------------*/	


/* Scheduler utilities. */
extern void vPortYieldFromISR( void );

#define portYIELD()					vPortYieldFromISR()

#define portEND_SWITCHING_ISR( xSwitchRequired ) do { if( xSwitchRequired ) { vPortYieldFromISR(); } } while (0)
/*-----------------------------------------------------------*/


/* Critical section management. */

/* 
 * Set basepri to portMAX_SYSCALL_INTERRUPT_PRIORITY without effecting other
 * registers.  r0 is clobbered.
 */ 
static inline void portSET_INTERRUPT_MASK(void)
{
	uint32_t reg;
	asm volatile (
		"mov	%0, %1			\n"
		"msr	basepri, %0		\n"
			: "=&r"(reg)		/* output operands */
			: "i"(configMAX_SYSCALL_INTERRUPT_PRIORITY)	/* input operands */
			: 					/* clobber list */
	);
}

/*
 * Set basepri back to 0 without effective other registers.
 * r0 is clobbered.
 */
static inline void portCLEAR_INTERRUPT_MASK(void)
{
	uint32_t reg;
	asm volatile (
		"mov	%0, #0			\n"
		"msr	basepri, %0		\n"
			: "=&r"(reg)		/* output operands */
			: 					/* input operands */
			: 					/* clobber list */
	);
}

#define portSET_INTERRUPT_MASK_FROM_ISR()		0;portSET_INTERRUPT_MASK()
#define portCLEAR_INTERRUPT_MASK_FROM_ISR(x)	portCLEAR_INTERRUPT_MASK();(void)x

extern void vPortEnterCritical( void );
extern void vPortExitCritical( void );

#define portDISABLE_INTERRUPTS()	portSET_INTERRUPT_MASK()
#define portENABLE_INTERRUPTS()		portCLEAR_INTERRUPT_MASK()
#define portENTER_CRITICAL()		vPortEnterCritical()
#define portEXIT_CRITICAL()			vPortExitCritical()
/*-----------------------------------------------------------*/

/* Task function macros as described on the FreeRTOS.org WEB site. */
#define portTASK_FUNCTION_PROTO( vFunction, pvParameters ) void vFunction( void *pvParameters )
#define portTASK_FUNCTION( vFunction, pvParameters ) void vFunction( void *pvParameters )

#define portNOP()

#ifdef __cplusplus
}
#endif

#endif /* PORTMACRO_H */

