/*
 * led_function.c
 *
 *  Created on: Sep 29, 2024
 *      Author: ASUS
 */
#include "main.h"
#include "led_function.h"



void display7SEG1(int num){
	if (num == 0){
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, RESET);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, RESET);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2, RESET);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, RESET);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, RESET);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, RESET);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, SET);
	}else if (num == 1){
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, SET);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, RESET);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2, RESET);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, SET);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, SET);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, SET);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, SET);
	}else if (num == 2){
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, RESET);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, RESET);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2, SET);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, RESET);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, RESET);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, SET);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, RESET);
	}else if (num == 3){
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, RESET);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, RESET);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2, RESET);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, RESET);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, SET);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, SET);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, RESET);
	}else if (num == 4){
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, SET);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, RESET);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2, RESET);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, SET);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, SET);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, RESET);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, RESET);
	}else if (num == 5){
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, RESET);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, SET);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2, RESET);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, RESET);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, SET);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, RESET);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, RESET);
	}else if (num == 6){
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, RESET);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, SET);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2, RESET);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, RESET);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, RESET);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, RESET);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, RESET);
	}else if (num == 7){
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, RESET);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, RESET);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2, RESET);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, SET);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, SET);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, SET);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, SET);
	}else if (num == 8){
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, RESET);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, RESET);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2, RESET);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, RESET);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, RESET);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, RESET);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, RESET);
	}else {
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, RESET);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, RESET);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2, RESET);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, RESET);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, SET);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, RESET);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, RESET);
	}
}

void display7SEG2(int num){
	if (num == 0){
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9, RESET);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10, RESET);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_11, RESET);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, RESET);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, RESET);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, RESET);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, SET);
	}else if (num == 1){
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9, SET);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10, RESET);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_11, RESET);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, SET);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, SET);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, SET);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, SET);
	}else if (num == 2){
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9, RESET);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10, RESET);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_11, SET);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, RESET);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, RESET);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, SET);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, RESET);
	}else if (num == 3){
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9, RESET);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10, RESET);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_11, RESET);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, RESET);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, SET);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, SET);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, RESET);
	}else if (num == 4){
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9, SET);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10, RESET);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_11, RESET);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, SET);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, SET);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, RESET);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, RESET);
	}else if (num == 5){
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9, RESET);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10, SET);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_11, RESET);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, RESET);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, SET);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, RESET);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, RESET);
	}else if (num == 6){
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9, RESET);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10, SET);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_11, RESET);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, RESET);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, RESET);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, RESET);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, RESET);
	}else if (num == 7){
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9, RESET);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10, RESET);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_11, RESET);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, SET);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, SET);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, SET);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, SET);
	}else if (num == 8){
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9, RESET);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10, RESET);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_11, RESET);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, RESET);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, RESET);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, RESET);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, RESET);
	}else {
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9, RESET);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10, RESET);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_11, RESET);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, RESET);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, SET);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, RESET);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, RESET);
	}
}

typedef struct {
    int b;
    int c;
} Result;

Result separate0(int a) {
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

//Result res = separate(red_temp);

void display_segment(int a, int b,enum Mode *first_button, int *BUTTON_ONE){
	Result res_1 = separate0(a);
	Result res_2 = separate0(b);
	int counter = 0;

	while (counter != 2){
		if (counter == 0){
			display7SEG1(res_1.b);
			display7SEG2(res_2.b);
			  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, RESET);
			  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, SET);

			  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, RESET);
			  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, SET);

			  counter++;
		}else if (counter == 1){
			display7SEG1(res_1.c);
			display7SEG2(res_2.c);
			  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, SET);
			  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, RESET);

			  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, SET);
			  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, RESET);

			  counter++;
		}

		if (*BUTTON_ONE == 1){
			return;
		}

		  setTimer0(500);

		  while(timer0_flag == 0){
		  }
	}

}

void display_time(int *time0, int *time1, enum Mode *first_button, int *BUTTON_ONE){
	int out = 0;
	if (*time0 > *time1){
		out = *time1;
	}else{
		out = *time0;
	}

	while (out != 0){
//		display7SEG1(*time0);
//		display7SEG2(*time1);


		display_segment(*time0,*time1,first_button,BUTTON_ONE);

		out -= 1;
		*time1 -= 1;
		*time0 -= 1;

	}
}

int time0;
int time1;
int time2;
int time3;
int time4;
int time5;
void traffic_light(int red_time, int yellow_time, int green_time, enum Mode *first_button, int *BUTTON_ONE){
	time0 = red_time;
	time1 = yellow_time;
	time2 = green_time;
	time3 = red_time;
	time4 = yellow_time;
	time5 = green_time;

	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, RESET);
	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, SET);
	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, SET);
	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, SET);
	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, SET);
	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, RESET);

		if (*BUTTON_ONE == 1){
//			*BUTTON_ONE = 0;
//			mode_checking(first_button);
			return;
		}

	  display_time(&time0, &time2, first_button,BUTTON_ONE);

	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, RESET);
	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, SET);
	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, SET);
	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, SET);
	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, RESET);
	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, SET);

		if (*BUTTON_ONE == 1){
//			*BUTTON_ONE = 0;
//			mode_checking(first_button);
			return;
		}

	  display_time(&time0, &time1, first_button,BUTTON_ONE);

	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, SET);
	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, SET);
	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, RESET);
	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, RESET);
	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, SET);
	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, SET);

		if (*BUTTON_ONE == 1){
//			*BUTTON_ONE = 0;
//			mode_checking(first_button);
			return;
		}

	  display_time(&time5, &time3, first_button,BUTTON_ONE);

	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, SET);
	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, RESET);
	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, SET);
	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, RESET);
	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, SET);
	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, SET);

		if (*BUTTON_ONE == 1){
//			*BUTTON_ONE = 0;
//			mode_checking(first_button);
			return;
		}

	  display_time(&time4, &time3, first_button,BUTTON_ONE);
	  timer0_flag = 1;
}

void red_time(enum Mode *first_button, int chuc, int don_vi){
	int counter = 0;

	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, SET);
	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, SET);
	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, SET);
	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, SET);

	while (counter != 2){
		if (counter == 0){
			display7SEG1(don_vi);
			display7SEG2(0);
			  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, RESET);
			  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, RESET);

			  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, RESET);
			  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, SET);

			  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, RESET);
			  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, SET);

			  counter++;
		}else if (counter == 1){
			display7SEG1(don_vi);
			display7SEG2(2);
			  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, SET);
			  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, SET);

			  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, SET);
			  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, RESET);

			  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, SET);
			  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, RESET);

			  counter++;
		}

		if (BUTTON_TWO == 1){
//			BUTTON_TWO = 0;
//			mode_checking0();
//			  setTimer0(50);
//
//			  while(timer0_flag == 0){
//
//			  }
			return;
		}

		  setTimer0(500);

		  while(timer0_flag == 0){

		  }
	}
}

void yellow_time(enum Mode *first_button, int chuc, int don_vi){

		int counter = 0;

		  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, SET);
		  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, SET);
		  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, SET);
		  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, SET);

			display7SEG1(0);

		while (counter != 2){
			if (counter == 0){
				display7SEG1(chuc);
				display7SEG2(0);
				  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, RESET);
				  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, RESET);

				  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, RESET);
				  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, SET);

				  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, RESET);
				  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, SET);

				  counter++;
			}else if (counter == 1){
				display7SEG1(don_vi);
				display7SEG2(3);
				  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, SET);
				  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, SET);

				  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, SET);
				  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, RESET);

				  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, SET);
				  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, RESET);

				  counter++;
			}

			if (BUTTON_TWO == 1){
//				BUTTON_TWO = 0;
//				mode_checking0();
				return;
			}

			  setTimer0(500);

			  while(timer0_flag == 0){
			  }

		}
}


void green_time(enum Mode *first_button, int chuc, int don_vi){
		int counter = 0;

		  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, SET);
		  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, SET);
		  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, SET);
		  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, SET);

		while (counter != 2){
			if (counter == 0){
				display7SEG1(chuc);
				display7SEG2(0);
				  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, RESET);
				  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, RESET);

				  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, RESET);
				  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, SET);

				  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, RESET);
				  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, SET);

				  counter++;

			}else if (counter == 1){
				display7SEG1(don_vi);
				display7SEG2(4);
				  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, SET);
				  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, SET);

				  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, SET);
				  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, RESET);

				  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, SET);
				  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, RESET);

				  counter++;

			}

			if (BUTTON_TWO == 1){
//				BUTTON_TWO = 0;
//				mode_checking0();
				return;
			}

			  setTimer0(500);

			  while(timer0_flag == 0){

			  }
//			  timer0_flag = 1;  // Reset the flag for the next cycle
		}
}
