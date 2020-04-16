/*
 * paintIntro.c
 *
 *  Created on: 16 kwi 2020
 *      Author: berna
 */

#include "paintIntro.h"
#include "../../Drivers/BSP/STM32F429I-Discovery/stm32f429i_discovery_lcd.h"

void initLCD(void)
{
	BSP_LCD_Init();
	BSP_LCD_LayerDefaultInit(1,LCD_FRAME_BUFFER);
	BSP_LCD_SelectLayer(1);
	BSP_LCD_DisplayOn();
}

void printHelloScreen(void)
{
	BSP_LCD_Clear(LCD_COLOR_WHITE);
	BSP_LCD_SetTextColor(LCD_COLOR_DARKMAGENTA);
	BSP_LCD_DrawRect(10, 125, 220, 70);
	BSP_LCD_SetFont(&Font24);
	BSP_LCD_DisplayStringAt(0, 135, (uint8_t*)"EKAB", CENTER_MODE);
	BSP_LCD_SetFont(&Font16);
	BSP_LCD_DisplayStringAt(0, 155, (uint8_t*)"DRAW", CENTER_MODE);
	HAL_Delay(750);
	BSP_LCD_SetTextColor(LCD_COLOR_LIGHTMAGENTA);
	BSP_LCD_FillCircle(100, 176, 5);
	BSP_LCD_FillCircle(115, 176, 5);
	BSP_LCD_FillCircle(130, 176, 5);
	HAL_Delay(1000);
	int i =0;

	for(i = 100; i <=130; i+=15)
	{
		BSP_LCD_SetTextColor(LCD_COLOR_MAGENTA);
		BSP_LCD_FillCircle(i, 176, 5);
		HAL_Delay(750);
		BSP_LCD_SetTextColor(LCD_COLOR_DARKMAGENTA);
		BSP_LCD_FillCircle(i, 176, 5);
		HAL_Delay(750);
	}
}

