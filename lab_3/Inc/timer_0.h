/*
 * timer_0.h
 *
 *  Created on: Sep 29, 2024
 *      Author: ASUS
 */

#ifndef INC_TIMER_0_H_
#define INC_TIMER_0_H_

#include "input_proccessing.h"

extern int timer0_counter;
extern int timer0_flag;
extern int TIMER_CYCLE;

void setTimer0(int duration);
void timer_run();


#endif /* INC_TIMER_0_H_ */
