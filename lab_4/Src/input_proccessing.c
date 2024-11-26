#include "main.h"
#include "input_proccessing.h"
#include "input_reading.h"

//#include "global.c"

void mode_making(void){
	switch (first_button) {
			            case mode_1:
			                traffic_light(red, yellow, green, &first_button, &BUTTON_ONE);
			                break;
			            case mode_2:
			                red_time(&first_button, chuc, don_vi);
			                break;
			            case mode_3:
			                yellow_time(&first_button, chuc, don_vi);
			                break;
			            case mode_4:
			                green_time(&first_button, chuc, don_vi);
			                break;
			            default:
			                // Handle unexpected mode if necessary
			                break;
			        }
}

void mode_checking(void){
	if (first_button == first_mode){
		first_button = mode_2;
	}else if (first_button == second_mode){
		first_button = mode_3;
	}else if (first_button == third_mode){
		first_button = mode_4;
	}else if (first_button == fourth_mode){
		first_button = mode_1;
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

void mode_checking0(){
	if (first_button == first_mode){
		return;
	}else if (first_button == second_mode){
		green_temp = 0;
		red_temp++;

		if (red_temp > 99){
			red_temp = 0;
		}

		Result res = separate(red_temp);
		chuc = res.b;
		don_vi = res.c;

	}else if (first_button == third_mode){
		red_temp = 0;
		yellow_temp++;

		if (yellow_temp > 99){
			yellow_temp = 0;
		}

		Result res = separate(yellow_temp);
		chuc = res.b;
		don_vi = res.c;

	}else if (first_button == fourth_mode){
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

void fsm_for_input_processing0() {
    switch (buttonState0) {
        case BUTTON_RELEASED:
            if (BUTTON_ONE == 1) {
                buttonState0 = BUTTON_PRESSED;
                // INCREASE VALUE OF PORT A BY ONE UNIT
                BUTTON_ONE = 0;
                mode_checking();
            }
            break;

        case BUTTON_PRESSED:
            if (!is_button_pressed(0)) {
                buttonState0 = BUTTON_RELEASED;

            } else if (is_button_pressed_1s(0)){
            	buttonState0 = BUTTON_PRESSED_MORE_THAN_1_SECOND;
                }

            break;

        case BUTTON_PRESSED_MORE_THAN_1_SECOND:
            if (!is_button_pressed(0)) {
                buttonState0 = BUTTON_RELEASED;
            }
            //  Add further logic for long press
//            mode_checking();
//            mode_making();

            break;
    }
}


void fsm_for_input_processing1() {
    switch (buttonState1) {
        case BUTTON_RELEASED:
            if (BUTTON_TWO == 1) {
                buttonState1 = BUTTON_PRESSED;
                // INCREASE VALUE OF PORT A BY ONE UNIT
                BUTTON_TWO = 0;
                mode_checking0();
//      		  setTimer0(50);
//
//      		  while(timer0_flag == 0){
//
//      		  }
            }

            if (BUTTON_ONE == 1){
        		chuc = 0;
        		don_vi = 0;
        		red_temp = 0;
        		yellow_temp = 0;
        		green_temp = 0;
            }

            if (BUTTON_THREE == 1){
            	BUTTON_THREE = 0;
            	if (first_button == second_mode && red_temp > 0){
            		red = red_temp;

            	}else if (first_button == third_mode && yellow_temp > 0){
            		yellow = yellow_temp;


            	}else if (first_button == fourth_mode && green_temp > 0){
            		green = green_temp;

            	}
            }

            break;
        case BUTTON_PRESSED:
            if (!is_button_pressed(1)) {
                buttonState1 = BUTTON_RELEASED;


            }else if ( BUTTON_TWO_LOOP == 1){
            	buttonState1 = BUTTON_PRESSED_MORE_THAN_1_SECOND;
            }
            break;
        case BUTTON_PRESSED_MORE_THAN_1_SECOND:
            if (BUTTON_TWO_LOOP == 0) {
                buttonState1 = BUTTON_RELEASED;
            }
            //  Add further logic for long press

            mode_checking0();
  		  setTimer0(500);

			if (BUTTON_TWO_LOOP == 0) {
				if (first_button == second_mode){

						red_temp = red_temp - 3;

					}else if (first_button == third_mode){

						yellow_temp -= 3;

					}else if (first_button == fourth_mode){
						green_temp -= 3;

					}

				return;
			}

  		  while(timer0_flag == 0){

  		  }

            break;
    }
}










