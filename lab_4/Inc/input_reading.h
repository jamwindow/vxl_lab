/*
 * input_reading.h
 *
 *  Created on: Sep 19, 2024
 *      Author: ASUS
 */

#ifndef INC_INPUT_READING_H_
#define INC_INPUT_READING_H_

#include "global.h"

// We aim to work with more than one button
#define N0_OF_BUTTONS 3
// Timer interrupt duration is 10ms, so to pass 1 second,
// we need to jump to the interrupt service routine 100 times
#define DURATION_FOR_AUTO_INCREASING 10
#define BUTTON_IS_PRESSED GPIO_PIN_RESET
#define BUTTON_IS_RELEASED GPIO_PIN_SET

extern GPIO_PinState buttonBuffer[N0_OF_BUTTONS];



void button_reading(void);
 unsigned char is_button_pressed(unsigned char index);
 unsigned char is_button_pressed_1s(unsigned char index);

#endif /* INC_INPUT_READING_H_ */
