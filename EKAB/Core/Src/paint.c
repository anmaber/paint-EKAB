/*
 * paint.c
 *
 *  Created on: 16 kwi 2020
 *      Author: ekalinsk
 */

#include "paint.h"
#include "../../Drivers/BSP/STM32F429I-Discovery/stm32f429i_discovery_lcd.h"

void configTS(void)
{
	BSP_LCD_Clear(LCD_COLOR_WHITE);

	if(BSP_TS_Init(1000, 1000) == TS_OK)
	{
		BSP_LCD_Clear(LCD_COLOR_WHITE);
		BSP_LCD_SetTextColor(LCD_COLOR_BLACK);
	}
}

void paint(void)
{
	BSP_TS_GetState(&ts_struct);
	if(ts_struct.TouchDetected)
	{
		BSP_LCD_FillCircle(ts_struct.X, ts_struct.Y, 5);
	}
}
