/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * File Name          : freertos.c
  * Description        : Code for freertos applications
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "FreeRTOS.h"
#include "task.h"
#include "main.h"
#include "cmsis_os.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */     
#include "chooseViewStructure.h"
#include "paintInterface.h"
#include "chooseCanvaInterface.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
uint8_t canvas = '0';
int printer = 0;
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN Variables */

/* USER CODE END Variables */
/* Definitions for mainTask */
osThreadId_t mainTaskHandle;
const osThreadAttr_t mainTask_attributes = {
  .name = "mainTask",
  .priority = (osPriority_t) osPriorityNormal,
  .stack_size = 128 * 4
};
/* Definitions for painterTask */
osThreadId_t painterTaskHandle;
const osThreadAttr_t painterTask_attributes = {
  .name = "painterTask",
  .priority = (osPriority_t) osPriorityNormal,
  .stack_size = 128 * 4
};

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */
   
/* USER CODE END FunctionPrototypes */

void mainTaskfunction(void *argument);
void painterTaskFunction(void *argument);

void MX_FREERTOS_Init(void); /* (MISRA C 2004 rule 8.1) */

/**
  * @brief  FreeRTOS initialization
  * @param  None
  * @retval None
  */
void MX_FREERTOS_Init(void) {
  /* USER CODE BEGIN Init */
       
  /* USER CODE END Init */

  /* USER CODE BEGIN RTOS_MUTEX */
  /* add mutexes, ... */
  /* USER CODE END RTOS_MUTEX */

  /* USER CODE BEGIN RTOS_SEMAPHORES */
  /* add semaphores, ... */
  /* USER CODE END RTOS_SEMAPHORES */

  /* USER CODE BEGIN RTOS_TIMERS */
  /* start timers, add new ones, ... */
  /* USER CODE END RTOS_TIMERS */

  /* USER CODE BEGIN RTOS_QUEUES */
  /* add queues, ... */
  /* USER CODE END RTOS_QUEUES */

  /* Create the thread(s) */
  /* creation of mainTask */
  mainTaskHandle = osThreadNew(mainTaskfunction, NULL, &mainTask_attributes);

  /* creation of painterTask */
  painterTaskHandle = osThreadNew(painterTaskFunction, NULL, &painterTask_attributes);

  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */
  /* USER CODE END RTOS_THREADS */

}

/* USER CODE BEGIN Header_mainTaskfunction */
/**
  * @brief  Function implementing the mainTask thread.
  * @param  argument: Not used 
  * @retval None
  */
/* USER CODE END Header_mainTaskfunction */
void mainTaskfunction(void *argument)
{
  /* USER CODE BEGIN mainTaskfunction */
  /* Infinite loop */
  for(;;)
  {
	  if(printer == 0)
	  {
		  switch(activeView)
		  		  	  		{
		  		  	  		case Canvas1:
		  		  	  			canvas = '1';
		  		  	  			clearWorkspace(canvas);

		  		  	  			loadPartOfSketch(10, 0x080C0000, 38, 38);
		  		  	  			loadPartOfSketch(11, 0x080E0000, 38, 179);

		  		  	  			osDelay(500);
		  		  	  			printer = 1;
		  		  	  			break;
		  		  	  		case Canvas2:
		  		  	  			canvas = '2';
		  		  	  			clearWorkspace(canvas);

		  		  	  			loadPartOfSketch(8, 0x08080000, 38, 38);
		  		  	  			loadPartOfSketch(9, 0x080A0000, 38, 179);

		  		  	  			osDelay(500);
		  		  	  			printer = 1;
		  		  	  			break;
		  		  	  		case ChooseScreen:
		  		  	  			showChooseCanvaInterface();
		  		  	  			choose();
		  		  	  			break;
		  		  	  		case Info:
		  		  	  			serviceInfoScreen();
		  		  	  			break;
		  		  	  		default:

		  		  	  			break;

		  		  	  		}
	  }

  }
    osDelay(1);
  }

  /* USER CODE END mainTaskfunction */

/* USER CODE BEGIN Header_painterTaskFunction */
/**
* @brief Function implementing the painterTask thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_painterTaskFunction */
void painterTaskFunction(void *argument)
{
  /* USER CODE BEGIN painterTaskFunction */
  /* Infinite loop */
  for(;;)
  {
	  if(printer == 1) paintProcess(canvas);
	  if(activeView == ChooseScreen) printer = 0;
	  osDelay(1);
  }
  /* USER CODE END painterTaskFunction */
}

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */
     
/* USER CODE END Application */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
