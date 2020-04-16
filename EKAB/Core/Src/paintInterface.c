/*
 * paintInterface.c
 *
 *  Created on: 16 kwi 2020
 *      Author: berna
 */

#include "../../Drivers/BSP/STM32F429I-Discovery/stm32f429i_discovery_lcd.h"

void showPaintInterface()
{
	BSP_LCD_Clear(LCD_COLOR_WHITE);

	BSP_LCD_SetTextColor(LCD_COLOR_BLACK);
	BSP_LCD_DrawRect(55, 5, 30, 30);
	BSP_LCD_DrawRect(93, 5, 30, 30);
	BSP_LCD_DrawRect(131, 5, 30, 30);
	BSP_LCD_FillCircle(70, 20, 5);
	BSP_LCD_FillCircle(108, 20, 10);
	BSP_LCD_FillCircle(146, 20, 15);

	BSP_LCD_DrawRect(164, 5, 74, 30);
	BSP_LCD_SetFont(&Font16);
	BSP_LCD_DisplayStringAt(180, 15, (uint8_t *)"EXIT",LEFT_MODE);


	BSP_LCD_DrawRect(5, 22, 30, 30);
	BSP_LCD_DisplayChar(15, 30, 'C');

	BSP_LCD_DrawRect(5, 60, 30, 30);
	BSP_LCD_FillRect(5, 98, 30, 30);
	BSP_LCD_SetTextColor(LCD_COLOR_YELLOW);
	BSP_LCD_FillRect(5, 136, 30, 30);
	BSP_LCD_SetTextColor(LCD_COLOR_RED);
	BSP_LCD_FillRect(5, 174, 30, 30);
	BSP_LCD_SetTextColor(LCD_COLOR_BLUE);
	BSP_LCD_FillRect(5,212 , 30, 30);
	BSP_LCD_SetTextColor(LCD_COLOR_GREEN);
	BSP_LCD_FillRect(5, 250, 30, 30);
	BSP_LCD_SetTextColor(LCD_COLOR_MAGENTA);
	BSP_LCD_FillRect(5, 288, 30, 30);
}
