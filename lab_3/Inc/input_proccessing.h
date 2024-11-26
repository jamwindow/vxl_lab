/*
 * input_proccessing.h
 *
 *  Created on: Sep 19, 2024
 *      Author: ASUS
 */

#ifndef INC_INPUT_PROCCESSING_H_
#define INC_INPUT_PROCCESSING_H_

enum Mode{
	mode_1,
	mode_2,
	mode_3,
	mode_4
};

extern int red_temp;
extern int yellow_temp;
extern int green_temp;

extern int chuc;
extern int don_vi;

void fsm_for_input_processing0(enum Mode *first_button, int *BUTTON_ONE);
void fsm_for_input_processing1(enum Mode *first_button, int *red, int *yellow, int *green, int *BUTTON_ONE, int *BUTTON_TWO, int *BUTTON_THREE);
void mode_checking(enum Mode *first_button);
void mode_checking0(enum Mode *first_button);

#endif /* INC_INPUT_PROCCESSING_H_ */
