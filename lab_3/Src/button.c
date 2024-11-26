/*
 * button.c
 *
 *  Created on: Sep 19, 2024
 *      Author: ASUS
 */

#include "button.h"

int button1_flag = 0;

int keyReg0 = NORMAL_STATE;
int keyReg1 = NORMAL_STATE;
int keyReg2 = NORMAL_STATE;

int keyReg3 = NORMAL_STATE;
int TimerForKeyPress = 200;

int isButton1Pressed(){
	if (button1_flag == 1){
		button1_flag = 0;
		return 1;
	}
	return 0;
}

void subKeyProcess()
{
//	HAL_GPIO_TogglePin(GPIOA,GPIO_PIN_5);
	button1_flag = 1;

}
void getKeyInput(){
	keyReg0 = keyReg1;
	keyReg1 = keyReg2;
	keyReg2 = HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_13);
	if ((keyReg0 == keyReg1) && (keyReg1 == keyReg2)){
		if (keyReg3 != keyReg2){
			keyReg3 = keyReg2;
			if (keyReg2 == PRESSED_STATE){
				//	something
				subKeyProcess();
				TimerForKeyPress = 200;
			}
		}else {
			TimerForKeyPress--;
			if (TimerForKeyPress == 0){
				// something
				if (keyReg2 == PRESSED_STATE){
					subKeyProcess();
				}

				TimerForKeyPress = 200;
			}
		}
	}
}
