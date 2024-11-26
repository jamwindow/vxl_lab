/*
 * global.h
 *
 *  Created on: Oct 29, 2024
 *      Author: ASUS
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_
///////////////////////////////

extern int timer0_counter;
extern int timer0_flag;
extern int TIMER_CYCLE;

////////////////////////////////

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

////////////////////////////////

extern int BUTTON_ONE;
extern int BUTTON_TWO;
extern int BUTTON_THREE;

extern int BUTTON_ONE_LOOP;
extern int BUTTON_TWO_LOOP;
extern int BUTTON_THREE_LOOP;

////////////////////////////////

enum ButtonState {
    BUTTON_RELEASED,
    BUTTON_PRESSED,
    BUTTON_PRESSED_MORE_THAN_1_SECOND
};

extern int red_temp;
extern int yellow_temp;
extern int green_temp;

extern int red;
extern int yellow;
extern int green;

extern int chuc;
extern int don_vi;

////////////////////////////////

enum Mode first_button;

enum Mode first_mode;
enum Mode second_mode;
enum Mode third_mode;
enum Mode fourth_mode;

enum ButtonState buttonState0;
enum ButtonState buttonState1;
enum ButtonState buttonState2;



#endif /* INC_GLOBAL_H_ */
