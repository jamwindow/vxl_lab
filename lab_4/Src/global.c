/*
 * global.c
 *
 *  Created on: Oct 29, 2024
 *      Author: ASUS
 */
#include "global.h"
////////////////////////////////////////////

int timer0_counter = 0;
int timer0_flag = 0;
int TIMER_CYCLE = 10;

////////////////////////////////////////////


enum Mode first_mode = mode_1;
enum Mode second_mode = mode_2;
enum Mode third_mode = mode_3;
enum Mode fourth_mode = mode_4;

enum ButtonState buttonState0 = BUTTON_RELEASED;
enum ButtonState buttonState1 = BUTTON_RELEASED;
enum ButtonState buttonState2 = BUTTON_RELEASED;

////////////////////////////////////////////

int red_temp = 0;
int yellow_temp = 0;
int green_temp = 0;

int chuc = 0;
int don_vi = 0;

////////////////////////////////////////////


enum Mode first_button = mode_4;

int red = 5;
int yellow = 2;
int green = 3;

int BUTTON_ONE = 0;
int BUTTON_TWO = 0;
int BUTTON_THREE = 0;

int BUTTON_ONE_LOOP = 0;
int BUTTON_TWO_LOOP = 0;
int BUTTON_THREE_LOOP = 0;

////////////////////////////////////////////































