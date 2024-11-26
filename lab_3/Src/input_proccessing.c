#include "main.h"
#include "input_reading.h"
#include "input_proccessing.h"
#include "led_function.h"
#include "timer_0.h"

  int red_temp;
  int yellow_temp;
  int green_temp;

  int chuc;
  int don_vi;

enum ButtonState {
    BUTTON_RELEASED,
    BUTTON_PRESSED,
    BUTTON_PRESSED_MORE_THAN_1_SECOND
};

enum Mode first_mode = mode_1;
enum Mode second_mode = mode_2;
enum Mode third_mode = mode_3;
enum Mode fourth_mode = mode_4;

enum ButtonState buttonState0 = BUTTON_RELEASED;
enum ButtonState buttonState1 = BUTTON_RELEASED;
enum ButtonState buttonState2 = BUTTON_RELEASED;

void mode_checking(enum Mode *first_button){
	if (*first_button == first_mode){
		*first_button = mode_2;
	}else if (*first_button == second_mode){
		*first_button = mode_3;
	}else if (*first_button == third_mode){
		*first_button = mode_4;
	}else if (*first_button == fourth_mode){
		*first_button = mode_1;
	}


}

typedef struct {
    int b;
    int c;
} Result;

Result separate(int a) {
    Result result;
    if (a > 10) {
        result.c = a % 10;
        result.b = a / 10;
    } else if (a % 10 == 0){
        result.b = a / 10;
        result.c = 0;
    }else {
        result.b = 0;
        result.c = a;
    }
    return result;
}

void mode_checking0(enum Mode *first_button){
	if (*first_button == first_mode){
		return;
	}else if (*first_button == second_mode){
		green_temp = 0;
		red_temp++;

		if (red_temp > 99){
			red_temp = 0;
		}

		Result res = separate(red_temp);
		chuc = res.b;
		don_vi = res.c;
	}else if (*first_button == third_mode){
		red_temp = 0;
		yellow_temp++;

		if (yellow_temp > 99){
			yellow_temp = 0;
		}

		Result res = separate(yellow_temp);
		chuc = res.b;
		don_vi = res.c;
	}else if (*first_button == fourth_mode){
		yellow_temp = 0;
		green_temp++;

		if (green_temp > 99){
			green_temp = 0;
		}

		Result res = separate(green_temp);
		chuc = res.b;
		don_vi = res.c;
	}
}

void fsm_for_input_processing0(enum Mode *first_button, int *BUTTON_ONE) {
    switch (buttonState0) {
        case BUTTON_RELEASED:
            if (*BUTTON_ONE == 1) {
                buttonState0 = BUTTON_PRESSED;
                // INCREASE VALUE OF PORT A BY ONE UNIT
                *BUTTON_ONE = 0;
                mode_checking(first_button);

            }
            break;
//            is_button_pressed(0) ||
        case BUTTON_PRESSED:
            if (!is_button_pressed(0)) {
                buttonState0 = BUTTON_RELEASED;
            } else {
                if (*BUTTON_ONE == 1) {
                    buttonState0 = BUTTON_PRESSED_MORE_THAN_1_SECOND;
                    *BUTTON_ONE = 0;
                    mode_checking(first_button);

                }
            }
            break;

        case BUTTON_PRESSED_MORE_THAN_1_SECOND:
            if (!is_button_pressed(0)) {
                buttonState0 = BUTTON_RELEASED;
            }
            //  Add further logic for long press
            break;
    }
}



void fsm_for_input_processing1(enum Mode *first_button, int *red, int *yellow, int *green, int *BUTTON_ONE, int *BUTTON_TWO, int *BUTTON_THREE) {
    switch (buttonState1) {
        case BUTTON_RELEASED:
            if (*BUTTON_TWO == 1) {
                buttonState1 = BUTTON_PRESSED;
                // INCREASE VALUE OF PORT A BY ONE UNIT
                *BUTTON_TWO = 0;
                mode_checking0(first_button);
            }

            if (*BUTTON_ONE == 1){
        		chuc = 0;
        		don_vi = 0;
        		red_temp = 0;
        		yellow_temp = 0;
        		green_temp = 0;
            }

            if (*BUTTON_THREE == 1){
            	*BUTTON_THREE = 0;
            	if (*first_button == second_mode && red_temp > 0){
            		*red = red_temp;

            	}else if (*first_button == third_mode && yellow_temp > 0){
            		*yellow = yellow_temp;

      		        timer0_flag = 1;  // Reset the flag for the next cycle
            	}else if (*first_button == fourth_mode && green_temp > 0){
            		*green = green_temp;

            	}
            }

            break;
        case BUTTON_PRESSED:
            if (!is_button_pressed(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_12))) {
                buttonState1 = BUTTON_RELEASED;

            } else if (is_button_pressed_1s(2)){
            	buttonState1 = BUTTON_PRESSED_MORE_THAN_1_SECOND;
            }
            break;
        case BUTTON_PRESSED_MORE_THAN_1_SECOND:
            if (!is_button_pressed(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_12))) {
                buttonState1 = BUTTON_RELEASED;
            }
            //  Add further logic for long press
            if (*first_button == mode_2){
            	red_temp++;

            }else if (*first_button == mode_3){

            }else {

            }
            break;
    }
}










