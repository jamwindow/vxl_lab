/*
 * timer.h
 *
 *  Created on: Sep 21, 2024
 *      Author: ASUS
 */

#ifndef INC_TIMER_H_
#define INC_TIMER_H_

extern int timer0_counter;
extern int timer0_flag;
extern int TIMER_CYCLE;

void setTimer0(int duration);

void timer_run();

#endif /* INC_TIMER_H_ */
