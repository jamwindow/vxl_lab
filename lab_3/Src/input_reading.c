/*
 * input_reading.c
 *
 *  Created on: Sep 19, 2024
 *      Author: ASUS
 */

#include "main.h"
#include "input_reading.h"
#include "timer_0.h"
#include "led_function.h"


// The buffer where the final result is stored after debouncing
GPIO_PinState buttonBuffer[N0_OF_BUTTONS];

// We define two buffers for debouncing
static GPIO_PinState debounceButtonBuffer1[N0_OF_BUTTONS];
static GPIO_PinState debounceButtonBuffer2[N0_OF_BUTTONS];

// We define a flag for a button pressed more than 1 second
static uint8_t flagForButtonPress1s[N0_OF_BUTTONS];

// We define a counter for automatically increasing the value
// after the button is pressed for more than 1 second
static uint16_t counterForButtonPress1s[N0_OF_BUTTONS];

const uint16_t pinNumbers[] = {GPIO_PIN_11, GPIO_PIN_12, GPIO_PIN_13};  // Define pin numbers

void button_reading(void) {
    for (char i = 0; i < N0_OF_BUTTONS; i++) {
        debounceButtonBuffer2[i] = debounceButtonBuffer1[i];
        debounceButtonBuffer1[i] = HAL_GPIO_ReadPin(GPIOA, pinNumbers[i]);

        if (debounceButtonBuffer1[i] == debounceButtonBuffer2[i]) {
            buttonBuffer[i] = debounceButtonBuffer1[i];
        }

        if (buttonBuffer[i] == BUTTON_IS_PRESSED) {

            if (i == 0){
            	BUTTON_ONE = 1;
            }
            if (i == 1){
            	BUTTON_TWO = 1;
            }
            if (i == 2){
            	BUTTON_THREE = 1;
            }

            // If a button is pressed, we start counting
            if (counterForButtonPress1s[i] < DURATION_FOR_AUTO_INCREASING) {
                counterForButtonPress1s[i]++;
            } else {
                // The flag is turned on when 1 second has passed
                // since the button is pressed
                flagForButtonPress1s[i] = 1;
                // Add further logic if needed
            }
        } else {
            counterForButtonPress1s[i] = 0;
            flagForButtonPress1s[i] = 0;
        }
    }
}

unsigned char is_button_pressed(uint8_t index){
	 if(index >= N0_OF_BUTTONS) return 0;
	 return (buttonBuffer[index] == BUTTON_IS_PRESSED);
 }

unsigned char is_button_pressed_1s(unsigned char index){
	 if(index >= N0_OF_BUTTONS) return 0xff;
	 return (flagForButtonPress1s[index] == 1);
 }
