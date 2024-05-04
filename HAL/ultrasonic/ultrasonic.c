/******************************************************************************
 *
 * [Module]: ULTRASONIC
 *
 * [Author]: Omar Rizk
 *
 * File Name: ultrasonic.h
 *
 * Description: Source file for the Ultrasonic sensor
 *
 ******************************************************************************/

#include <util/delay.h>
#include "../MCAL/gpio.h"
#include "../MCAL/icu.h"
#include "ultrasonic.h"


volatile static uint8 ultrasonic_edge_count = 0;
volatile static uint16 ultrasonic_echo_high_time = 0;

Icu_ConfigType ICU_Config = { F_CPU_8, RISING };


/*
 * [Function Name]    : Ultrasonic_init
 * [Description]      : This function initializes the Ultrasonic sensor.
 * [Args]             : Void.
 * [Return]           : Void.
 */
void Ultrasonic_init(void)
{
    Icu_setCallBack(Ultrasonic_edgeProcessing);

    GPIO_setupPinDirection(PORTB_ID, PIN5_ID, PIN_OUTPUT);

    Icu_init(&ICU_Config);
}


/*
 * [Function Name]    : Ultrasonic_trigger
 * [Description]      : This function sends a trigger pulse.
 * [Args]             : Void.
 * [Return]           : Void.
 */
static void Ultrasonic_trigger(void)
{
    GPIO_writePin(PORTB_ID, PIN5_ID, LOGIC_HIGH);
    _delay_us(10);
    GPIO_writePin(PORTB_ID, PIN5_ID, LOGIC_LOW);
}


/*
 * [Function Name]    : Ultrasonic_readDistance
 * [Description]      : This function returns the measured distance by the Ultrasonic sensor.
 * [Args]             : Void.
 * [Return]           : The distance measured by the Ultrasonic sensor as uint16.
 */
uint16 Ultrasonic_readDistance(void)
{
    uint16 distance = 0;
    Ultrasonic_trigger();
    distance = ((float) 0.01731 * ultrasonic_echo_high_time);
    return distance;
}


/*
 * [Function Name]    : Ultrasonic_edgeProcessing
 * [Description]      : This function calculates the pulse time generated.
 * [Args]             : Void.
 * [Return]           : Void.
 */
void Ultrasonic_edgeProcessing(void)
{
    ultrasonic_edge_count++;
    if (1 == ultrasonic_edge_count)
    {
        Icu_clearTimerValue();
        Icu_setEdgeDetectionType(FALLING);
    }
    else
    {
        ultrasonic_echo_high_time = Icu_getInputCaptureValue();
        Icu_clearTimerValue();
        Icu_setEdgeDetectionType(RISING);
        ultrasonic_edge_count = 0;
    }
}
