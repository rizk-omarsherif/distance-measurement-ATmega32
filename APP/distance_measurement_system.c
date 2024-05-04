/******************************************************************************
 *
 * Layer: Application Layer
 *
 * File Name: distance_measurement_system.c
 *
 * Description: Source file for Distance Measuring System Project
 *
 * Author: Omar Rizk
 *
 ******************************************************************************/

#include <avr/io.h>
#include "../common_macros.h"

/* HAL Layer Libraries */
#include "../HAL/lcd.h"
#include "../HAL/ultrasonic.h"

int main(void)
{
    /* Enable Global Interrupt Flag */
    SREG |= 1<<7;

    /* Initialize Ultrasonic */
    Ultrasonic_init();
    /* Initialize LCD */
    LCD_init();
    /* Display at start */
    LCD_displayString("Distance:     cm");

    for(;;)
    {
        /* Display Ultrasonic Distance */
        LCD_moveCursor(0, 10);
        LCD_intgerToString(Ultrasonic_readDistance());
        LCD_displayCharacter(' ');
    }
}
