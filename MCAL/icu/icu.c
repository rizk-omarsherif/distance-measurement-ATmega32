/******************************************************************************
 *
 * Module: ICU
 *
 * File Name: icu.c
 *
 * Description: Source file for the AVR ICU driver
 *
 * Author: Omar Rizk
 *
 ******************************************************************************/

#include "icu.h"
#include "../common_macros.h" /* To use the macros like SET_BIT */
#include <avr/io.h> /* To use ICU/Timer1 Registers */
#include <avr/interrupt.h> /* For ICU ISR */

/*******************************************************************************
 *                           Global Variables                                  *
 *******************************************************************************/

#define NULL_PTR ((void*)0)

/* Global variable to hold the address of the callback function in the application */
static volatile void (*g_callBackPtr)(void) = NULL_PTR;

/*******************************************************************************
 *                       Interrupt Service Routines                            *
 *******************************************************************************/

ISR(TIMER1_CAPT_vect)
{
    if(g_callBackPtr != NULL_PTR)
    {
        /* Call the callback function in the application after the edge is detected */
        (*g_callBackPtr)();
        /* Another method to call the function using pointer to function: g_callBackPtr(); */
    }
}

/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/
/*
 * Description: Function to initialize the ICU driver.
 * 	1. Set the required clock.
 * 	2. Set the required edge detection.
 * 	3. Enable the Input Capture Interrupt.
 * 	4. Initialize Timer1 Registers.
 */
void Icu_init(const Icu_ConfigType * Config_Ptr)
{
    /* Configure ICP1/PD6 as input pin */
    DDRD &= ~(1<<PD6);

    /* Timer1 always operates in Normal Mode */
    TCCR1A = (1<<FOC1A) | (1<<FOC1B);

    /* Set the clock source */
    TCCR1B = (TCCR1B & 0xF8) | (Config_Ptr->clock);

    /* Set the edge type */
    TCCR1B = (TCCR1B & 0xBF) | ((Config_Ptr->edge)<<6);

    /* Initial value for Timer1 */
    TCNT1 = 0;

    /* Initial value for the input capture register */
    ICR1 = 0;

    /* Enable the Input Capture interrupt to generate an interrupt when an edge is detected on ICP1/PD6 pin */
    TIMSK |= (1<<TICIE1);
}

/*
 * Description: Function to set the callback function address.
 */
void Icu_setCallBack(void(*a_ptr)(void))
{
    /* Save the address of the callback function in a global variable */
    g_callBackPtr = a_ptr;
}

/*
 * Description: Function to set the required edge detection.
 */
void Icu_setEdgeDetectionType(const Icu_EdgeType a_edgeType)
{
    /* Set the edge type */
    TCCR1B = (TCCR1B & 0xBF) | (a_edgeType<<6);
}

/*
 * Description: Function to get the Timer1 value when the input is captured.
 *              The value is stored in the Input Capture Register ICR1.
 */
uint16 Icu_getInputCaptureValue(void)
{
    return ICR1;
}

/*
 * Description: Function to clear the Timer1 value to start counting from zero.
 */
void Icu_clearTimerValue(void)
{
    TCNT1 = 0;
}

/*
 * Description: Function to disable Timer1 to stop the ICU Driver.
 */
void Icu_DeInit(void)
{
    /* Clear all Timer1 Registers */
    TCCR1A = 0;
    TCCR1B = 0;
    TCNT1 = 0;
    ICR1 = 0;

    /* Disable the Input Capture interrupt */
    TIMSK &= ~(1<<TICIE1);
}
