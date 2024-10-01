/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
TIM_HandleTypeDef htim2;

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_TIM2_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
void display7SEG(int num){
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

int timer0_counter = 0;
int timer0_flag = 0;
int TIMER_CYCLE = 10;

void setTimer0(int duration){
	timer0_counter = duration / TIMER_CYCLE;
	timer0_flag = 0;
}

void timer_run(){
	if (timer0_counter > 0){
		timer0_counter--;
		if (timer0_counter == 0) timer0_flag = 1;
	}
}

void delay_with_timer(int delay_duration) {
    setTimer0(delay_duration);  // Set the delay in ms
    while (!timer0_flag);       // Wait until timer expires
    timer0_flag = 1;            // Reset the timer flag
}

  	const int MAX_LED = 4;
  	int index_led = 0;
  	int led_buffer[4] = {1, 2, 3, 4};
  	void update7SEG(int index){
  		switch (index){
  		case 0:
  			display7SEG(led_buffer[0]);
  			break;
  		case 1:
  			display7SEG(led_buffer[1]);
  			break;
  		case 2:
  			display7SEG(led_buffer[2]);
  			break;
  		case 3:
  			display7SEG(led_buffer[3]);
  			break;
  		default:
  			break;
  		}
  	}


  	void setRow(int row) {
  	    // Reset all rows (deactivate them) by pulling the GPIO pins to LOW
  	    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, RESET);
  	    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, RESET);
  	    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, RESET);
  	    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, RESET);
  	    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12, RESET);
  	    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_13, RESET);
  	    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_14, RESET);
  	    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, RESET);

  	    // Set the specific row to HIGH (active) to enable it via ULN2803
  	    switch (row) {
  	        case 0:
  	            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, SET);  // Activate Row 0
  	            break;
  	        case 1:
  	            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, SET);  // Activate Row 1
  	            break;
  	        case 2:
  	            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, SET); // Activate Row 2
  	            break;
  	        case 3:
  	            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, SET); // Activate Row 3
  	            break;
  	        case 4:
  	            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12, SET); // Activate Row 4
  	            break;
  	        case 5:
  	            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_13, SET); // Activate Row 5
  	            break;
  	        case 6:
  	            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_14, SET); // Activate Row 6
  	            break;
  	        case 7:
  	            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, SET); // Activate Row 7
  	            break;
  	        default:
  	            break;
  	    }
  	}



  	void displayLEDMatrix(uint8_t rowData) {
  	    // Set the column pins based on the rowData byte (assuming GPIOB is used for columns)
  	    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, (rowData & 0x01) ? RESET : SET);  // Column 1
  	    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9, (rowData & 0x02) ? RESET : SET);  // Column 2
  	    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10, (rowData & 0x04) ? RESET : SET);  // Column 3
  	    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_11, (rowData & 0x08) ? RESET : SET);  // Column 4
  	    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, (rowData & 0x10) ? RESET : SET);  // Column 5
  	    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, (rowData & 0x20) ? RESET : SET);  // Column 6
  	    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, (rowData & 0x40) ? RESET : SET);  // Column 7
  	    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, (rowData & 0x80) ? RESET : SET);  // Column 8
  	}

	const int MAX_LED_MATRIX = 8;
	int index_led_matrix = 0;
	uint8_t matrix_buffer[8] = {0xE7, 0xC3, 0x99, 0x99, 0x81, 0x99, 0x99, 0x99};
	void updateLEDMatrix(int index){
		 switch (index){
		 case 0:
			 displayLEDMatrix(matrix_buffer[0]);
			 break;
		 case 1:
			 displayLEDMatrix(matrix_buffer[1]);
			 break;
		 case 2:
			 displayLEDMatrix(matrix_buffer[2]);
			 break;
		 case 3:
			 displayLEDMatrix(matrix_buffer[3]);
			 break;
		 case 4:
			 displayLEDMatrix(matrix_buffer[4]);
			 break;
		 case 5:
			 displayLEDMatrix(matrix_buffer[5]);
			 break;
		 case 6:
			 displayLEDMatrix(matrix_buffer[6]);
			 break;
		 case 7:
			 displayLEDMatrix(matrix_buffer[7]);
			 break;
		 default:
			 break;
			 }
	}



	void scrollLeft(int speed) {
	    for (int shiftCount = 0; shiftCount < 8; shiftCount++) {
	        for (int step = 0; step < speed; step++) {
	            // Update the LED matrix to display the current state (no delay here)
	            for (int row = 0; row < 8; row++) {
	                setRow(row);
	                displayLEDMatrix(matrix_buffer[row]);
//	                HAL_Delay(1);  // Small delay for multiplexing effect
	                delay_with_timer(10);
	            }
	        }

	        // Shift the letter one column to the left after the "speed" iterations
	        for (int i = 0; i < 8; i++) {
	            // Save the rightmost bit (LSB) before shifting
	            uint8_t lsb = (matrix_buffer[i] & 0x01) ? 0x80 : 0;
	            matrix_buffer[i] >>= 1;  // Shift bits to the right

	            // Optionally wrap the rightmost bit to the leftmost position
	            matrix_buffer[i] |= lsb;
	        }
	    }
	}

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_TIM2_Init();
  /* USER CODE BEGIN 2 */
	HAL_TIM_Base_Start_IT(&htim2);
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  	int hour = 15, minute = 8, second = 50;

  	// Function to update the clock buffer based on the current hour and minute
  	void updateClockBuffer() {
  	  	// Update the led_buffer with the digits of hour and minute
  	  	// First two digits for hour, last two digits for minute
  	  	led_buffer[0] = hour / 10;  // Tens place of hour
  	  	led_buffer[1] = hour % 10;  // Ones place of hour
  	  	led_buffer[2] = minute / 10;  // Tens place of minute
  	  	led_buffer[3] = minute % 10;  // Ones place of minute
  	 }

 setTimer0(10);
int counter = 0;
  while (1)
  {
    /* USER CODE END WHILE */


//	  for (int i = 0; i < 8; i++) {
//	          setRow(i);                            // Activate current row
//	          updateLEDMatrix(i);   // Set column data for that row
//	          HAL_Delay(1);                         // Short delay for multiplexing effect
//	      }

//	  if(timer0_flag == 1){
//		  scrollLeft(10);
//	  }



//	  if(timer0_flag == 1){
//		  for (int i = 0; i < 8; i++) {
//		          setRow(i);                            // Activate current row
//		          updateLEDMatrix(i);   // Set column data for that row
//		          delay_with_timer(10);
//		  }
//	  }

    /* USER CODE BEGIN 3 */

//	  if(timer0_flag == 1){
//
//	  	  if (counter == 0){
//	          setRow(counter);                            // Activate current row
//	          displayLEDMatrix(matrix_buffer[counter]);   // Set column data for that row
//	  	  		counter++;
//	  	  	}else if (counter == 1){
//		          setRow(counter);                            // Activate current row
//		          displayLEDMatrix(matrix_buffer[counter]);   // Set column data for that row
//	  	  		counter++;
//	  	  	}else if (counter == 2){
//		          setRow(counter);                            // Activate current row
//		          displayLEDMatrix(matrix_buffer[counter]);   // Set column data for that row
//	  	  		counter++;
//	  	  	}else if (counter == 3){
//		          setRow(counter);                            // Activate current row
//		          displayLEDMatrix(matrix_buffer[counter]);   // Set column data for that row
//	  	  		counter++;
//	  	  	}else if (counter == 4){
//		          setRow(counter);                            // Activate current row
//		          displayLEDMatrix(matrix_buffer[counter]);   // Set column data for that row
//	  	  		counter++;
//	  	  	}else if (counter == 5){
//		          setRow(counter);                            // Activate current row
//		          displayLEDMatrix(matrix_buffer[counter]);   // Set column data for that row
//	  	  		counter++;
//	  	  	}else if (counter == 6){
//		          setRow(counter);                            // Activate current row
//		          displayLEDMatrix(matrix_buffer[counter]);   // Set column data for that row
//	  	  		counter++;
//	  	  	}else if (counter == 7){
//		          setRow(counter);                            // Activate current row
//		          displayLEDMatrix(matrix_buffer[counter]);   // Set column data for that row
//	  	  		counter++;
//	  	  	}else if (counter == 8){
//	  	  		counter = 0;
//		          setRow(counter);                            // Activate current row
//		          displayLEDMatrix(matrix_buffer[counter]);   // Set column data for that row
//	  	  	}
//	  	setTimer0(10);
//  }
//	  if (counter == 0){
//	  		setRow(0);
//	  		counter++;
//	  	}else if (counter == 1){
//	  		setRow(1);
//	  		counter++;
//	  	}else if (counter == 2){
//	  		setRow(2);
//	  		counter++;
//	  	}else if (counter == 3){
//	  		setRow(3);
//	  		counter++;
//	  	}else if (counter == 4){
//	  		setRow(4);
//	  		counter++;
//	  	}else if (counter == 5){
//	  		setRow(5);
//	  		counter++;
//	  	}else if (counter == 6){
//	  		setRow(6);
//	  		counter++;
//	  	}else if (counter == 7){
//	  		setRow(7);
//	  		counter++;
//	  	}else if (counter == 8){
//	  		counter = 0;
//	  	}else {
//	  		counter++;
//	  	}

//		  setRow(0);
//		  setTimer0(100);

//		  second++;  // Increment seconds
//
//		      // Check if seconds roll over
//		      if (second >= 60) {
//		          second = 0;
//		          minute++;  // Increment minutes when seconds reach 60
//		      }
//
//		      // Check if minutes roll over
//		      if (minute >= 60) {
//		          minute = 0;
//		          hour++;  // Increment hours when minutes reach 60
//		      }
//
//		      // Check if hours roll over (24-hour format)
//		      if (hour >= 24) {
//		          hour = 0;
//		      }
//
////		       Update the clock buffer with the current time
//		      updateClockBuffer();
////		       HAL_Delay(1000);
//			  HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_4);
//			  setTimer0(2000);





//		      update7SEG(0);
//		      HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, RESET);
//		      HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, SET);
//		      HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, SET);
//		      HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, SET);
//
//		      HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_4);
//
//
//		      /////////////////////////////////////////////////
//		      update7SEG(1);
//		      HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, SET);
//		      HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, RESET);
//		      HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, SET);
//		      HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, SET);
//
//		      HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_4);
//		      HAL_Delay(1000);
//
//		      /////////////////////////////////////////////////
//		      update7SEG(2);
//		      HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, SET);
//		      HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, SET);
//		      HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, RESET);
//		      HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, SET);
//
//		      HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_4);
//		      HAL_Delay(1000);
//
//		      /////////////////////////////////////////////////
//		      update7SEG(3);
//		      HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, SET);
//		      HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, SET);
//		      HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, SET);
//		      HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, RESET);
//
//		      HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_4);
//		      HAL_Delay(1000);
//
//		      ///////////////////////////////////////////////




//	  setRow(0);
//	  setRow(1);


//	  for (int i = 0; i < 8; i++) {
//		  setRow(i);
//		  updateLEDMatrix(i);
//		  HAL_Delay(1000);
//		  setTimer0(2000);
//	  }


//	  updateLEDMatrix(i);

//	      for (int i = 0; i < 8; i++) {
//	          // Select the row (you will need additional logic to drive the row pins)
//	    	  setRow(i);
//	          // Display the data for the selected row from the buffer
//	    	  updateLEDMatrix(i);
//
//	          // Small delay to allow multiplexing effect
//	    	  HAL_Delay(1000);
//	    	  setTimer0(20000);
//	      }


//	  if(timer0_flag == 1){
//	  		  second++;  // Increment seconds
//
//	  		      // Check if seconds roll over
//	  		      if (second >= 60) {
//	  		          second = 0;
//	  		          minute++;  // Increment minutes when seconds reach 60
//	  		      }
//
//	  		      // Check if minutes roll over
//	  		      if (minute >= 60) {
//	  		          minute = 0;
//	  		          hour++;  // Increment hours when minutes reach 60
//	  		      }
//
//	  		      // Check if hours roll over (24-hour format)
//	  		      if (hour >= 24) {
//	  		          hour = 0;
//	  		      }
//
//	  		      // Update the clock buffer with the current time
//	  		      updateClockBuffer();
//	  	  	  	  HAL_Delay(1000);
//
//	  		      update7SEG(0);
//	  		      HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, RESET);
//	  		      HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, SET);
//	  		      HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, SET);
//	  		      HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, SET);
//
//	  		      HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_4);
//	  		      HAL_Delay(1000);
//
//	  		      /////////////////////////////////////////////////
//
//	  		      update7SEG(1);
//	  		      HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, SET);
//	  		      HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, RESET);
//	  		      HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, SET);
//	  		      HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, SET);
//
//	  		      HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_4);
//	  		      HAL_Delay(1000);
//
//	  		      /////////////////////////////////////////////////
//
//	  		      update7SEG(2);
//	  		      HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, SET);
//	  		      HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, SET);
//	  		      HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, RESET);
//	  		      HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, SET);
//
//	  		      HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_4);
//	  		      HAL_Delay(1000);
//
//	  		      /////////////////////////////////////////////////
//
//	  		      update7SEG(3);
//	  		      HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, SET);
//	  		      HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, SET);
//	  		      HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, SET);
//	  		      HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, RESET);
//
//	  		      HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_4);
//	  		      HAL_Delay(1000);
//
//	  		      /////////////////////////////////////////////////
//	  	   }




}

  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief TIM2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM2_Init(void)
{

  /* USER CODE BEGIN TIM2_Init 0 */

  /* USER CODE END TIM2_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};

  /* USER CODE BEGIN TIM2_Init 1 */

  /* USER CODE END TIM2_Init 1 */
  htim2.Instance = TIM2;
  htim2.Init.Prescaler = 7999;
  htim2.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim2.Init.Period = 9;
  htim2.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim2.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim2) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim2, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim2, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM2_Init 2 */

  /* USER CODE END TIM2_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_4|GPIO_PIN_5
                          |GPIO_PIN_6|GPIO_PIN_7|GPIO_PIN_8|GPIO_PIN_9
                          |GPIO_PIN_10|GPIO_PIN_11|GPIO_PIN_12|GPIO_PIN_13
                          |GPIO_PIN_14|GPIO_PIN_15, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_10
                          |GPIO_PIN_11|GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_14
                          |GPIO_PIN_15|GPIO_PIN_3|GPIO_PIN_4|GPIO_PIN_5
                          |GPIO_PIN_6|GPIO_PIN_8|GPIO_PIN_9, GPIO_PIN_RESET);

  /*Configure GPIO pins : PA2 PA3 PA4 PA5
                           PA6 PA7 PA8 PA9
                           PA10 PA11 PA12 PA13
                           PA14 PA15 */
  GPIO_InitStruct.Pin = GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_4|GPIO_PIN_5
                          |GPIO_PIN_6|GPIO_PIN_7|GPIO_PIN_8|GPIO_PIN_9
                          |GPIO_PIN_10|GPIO_PIN_11|GPIO_PIN_12|GPIO_PIN_13
                          |GPIO_PIN_14|GPIO_PIN_15;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : PB0 PB1 PB2 PB10
                           PB11 PB12 PB13 PB14
                           PB15 PB3 PB4 PB5
                           PB6 PB8 PB9 */
  GPIO_InitStruct.Pin = GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_10
                          |GPIO_PIN_11|GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_14
                          |GPIO_PIN_15|GPIO_PIN_3|GPIO_PIN_4|GPIO_PIN_5
                          |GPIO_PIN_6|GPIO_PIN_8|GPIO_PIN_9;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */
//int counter = 0;
//int counter_led = 0;
//void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
//{
//	 timer_run();
//
////	if (counter == 0){
////
////  		  counter++;
////  	  }else if (counter == 100){
////  		  update7SEG(1);
////  		  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, SET);
////  		  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, RESET);
////  		  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, SET);
////  		  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, SET);
////  		  counter++;
////  	  }else if (counter == 200){
////  		  update7SEG(2);
////  		  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, SET);
////  		  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, SET);
////  		  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, RESET);
////  		  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, SET);
////  		  counter++;
////  	  }else if (counter == 300){
////  		  update7SEG(3);
////  		  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, SET);
////  		  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, SET);
////  		  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, SET);
////  		  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, RESET);
////  		  counter++;
////  	  }else if(counter == 400){
////  		  counter = 0;
////  	  }else {
////  		counter++;
////  	  }
//
//
//////////////////////////////////////////////////////////////////
//		EX 3
////
////	if (counter == 0){
////			update7SEG(0);
////  		  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, RESET);
////  		  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, SET);
////  		  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, SET);
////  		  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, SET);
////  		  counter++;
////  	  }else if (counter == 100){
////  		  update7SEG(1);
////  		  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, SET);
////  		  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, RESET);
////  		  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, SET);
////  		  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, SET);
////  		  counter++;
////  	  }else if (counter == 200){
////  		  update7SEG(2);
////  		  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, SET);
////  		  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, SET);
////  		  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, RESET);
////  		  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, SET);
////  		  counter++;
////  	  }else if (counter == 300){
////  		  update7SEG(3);
////  		  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, SET);
////  		  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, SET);
////  		  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, SET);
////  		  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, RESET);
////  		  counter++;
////  	  }else if(counter == 400){
////  		  counter = 0;
////  	  }else {
////  		counter++;
////  	  }
/////////////////////////////////////////////////////////////////////////////////
////	if (counter_led == 0){
////		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, RESET);
////		counter_led++;
////	}else if (counter_led == 100){
////		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, SET);
////		counter_led++;
////	}else if (counter_led == 200){
////		counter_led = 0;
////	}else {
////		counter_led++;
////	}
//
//
//}

//	EX 2
int counter = 0;
int counter_led = 0;
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	if (counter == 0){
  		  display7SEG(1);
  		  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, RESET);
  		  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, SET);
  		  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, SET);
  		  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, SET);
  		  counter++;
  	  }else if (counter == 50){
  		  display7SEG(2);
  		  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, SET);
  		  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, RESET);
  		  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, SET);
  		  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, SET);
  		  counter++;
  	  }else if (counter == 100){
  		  display7SEG(3);
  		  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, SET);
  		  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, SET);
  		  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, RESET);
  		  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, SET);
  		  counter++;
  	  }else if (counter == 150){
  		  display7SEG(0);
  		  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, SET);
  		  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, SET);
  		  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, SET);
  		  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, RESET);
  		  counter++;
  	  }else if(counter == 200){
  		  counter = 0;
  	  }else {
  		counter++;
  	  }
/////////////////////////////////////////////////////////////////////////////
	if (counter_led == 0){
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, RESET);
		counter_led++;
	}else if (counter_led == 100){
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, SET);
		counter_led++;
	}else if (counter_led == 200){
		counter_led = 0;
	}else {
		counter_led++;
	}
}

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
