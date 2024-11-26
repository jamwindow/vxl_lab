/*
 * timer_0.c
 *
 *  Created on: Sep 29, 2024
 *      Author: ASUS
 */
#include "main.h"
#include "timer_0.h"


void setTimer0(int duration){
	timer0_counter = duration /TIMER_CYCLE;
	timer0_flag = 0;
}

void timer_run(){
	if (timer0_counter > 0){
		timer0_counter--;
		if (timer0_counter == 0){
			timer0_flag = 1;
		}
	}

}

