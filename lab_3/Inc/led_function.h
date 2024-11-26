/*
 * lead_function.h
 *
 *  Created on: Sep 29, 2024
 *      Author: ASUS
 */

#ifndef INC_LED_FUNCTION_H_
#define INC_LED_FUNCTION_H_

#include "input_proccessing.h"

void display7SEG1(int num);
void display7SEG2(int num);
void display_time(int *time0, int *time1, enum Mode *first_button, int *BUTTON_ONE);
void traffic_light(int red_time, int yellow_time, int green_time, enum Mode *first_button, int *BUTTON_ONE);
void red_time(enum Mode *first_button, int chuc, int don_vi);
void yellow_time(enum Mode *first_button,int chuc, int don_vi);
void green_time(enum Mode *first_button, int chuc, int don_vi);
int button_checking(void);

#endif /* INC_LED_FUNCTION_H_ */
