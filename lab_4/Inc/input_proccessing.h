/*
 * input_proccessing.h
 *
 *  Created on: Sep 19, 2024
 *      Author: ASUS
 */

#ifndef INC_INPUT_PROCCESSING_H_
#define INC_INPUT_PROCCESSING_H_

#include "global.h"
#include "input_reading.h"
#include "led_function.h"
#include "timer_0.h"


void fsm_for_input_processing0();
void fsm_for_input_processing1();
void mode_checking();
void mode_checking0();
void mode_making();

#endif /* INC_INPUT_PROCCESSING_H_ */
