/******************************************************************************
 *
 * [Module]: ULTRASONIC
 *
 * [Author]: Omar Rizk
 *
 * File Name: ultrasonic.h
 *
 * Description: Header file for the Ultrasonic sensor
 *
 ******************************************************************************/

#ifndef HAL_ULTRASONIC_H_
#define HAL_ULTRASONIC_H_

#include "../std_types.h"

/*******************************************************************************
 *                            Functions Prototypes                             *
 *******************************************************************************/

/*
 * [Function Name]    : Ultrasonic_init
 * [Description]      : This function initializes the Ultrasonic sensor.
 * [Args]             : Void.
 * [Return]           : Void.
 */
void Ultrasonic_init(void);


/*
 * [Function Name]    : Ultrasonic_readDistance
 * [Description]      : This function returns the measured distance by the Ultrasonic sensor.
 * [Args]             : Void.
 * [Return]           : The distance measured by the Ultrasonic sensor as uint16.
 */
uint16 Ultrasonic_readDistance(void);


/*
 * [Function Name]    : Ultrasonic_edgeProcessing
 * [Description]      : This function calculates the pulse time generated by the Ultrasonic sensor.
 * [Args]             : Void.
 * [Return]           : Void.
 */
void Ultrasonic_edgeProcessing(void);


#endif /* HAL_ULTRASONIC_H_ */