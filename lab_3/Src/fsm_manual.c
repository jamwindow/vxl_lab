/*
 * fsm_manual.c
 *
 *  Created on: Sep 21, 2024
 *      Author: ASUS
 */

#include "fsm_manual.h"
#include "button.h"

void fsm_manual_run(){
	switch(status){
		case MAN_RED:
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, RESET);
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, SET);
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, SET);

			if (timer0_flag == 1){
				status = AUTO_RED;
				setTimer0(5000);
			}

			if (isButton1Pressed() == 1){
				status = MAN_GREEN;
				setTimer0(10000);
			}
			break;
		case MAN_GREEN:
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, SET);
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, SET);
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, RESET);

			if (timer0_flag == 1){
				status = AUTO_GREEN;
				setTimer0(3000);
			}

			if (isButton1Pressed() == 1){
				status = MAN_YELLOW;
				setTimer0(10000);
			}
			break;
		case MAN_YELLOW:
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, SET);
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, RESET);
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, SET);

			if (timer0_flag == 1){
				status = AUTO_YELLOW;
				setTimer0(2000);
			}

			if (isButton1Pressed() == 1){
				status = MAN_RED;
				setTimer0(10000);
			}
			break;
		default:
			break;
	}
}

