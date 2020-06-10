/*
 * chooseCanvaInterface.c
 *
 *  Created on: 10 cze 2020
 *      Author: ekalinsk
 */

#include "chooseViewStructure.h"
#include "chooseCanvaInterface.h"
#include "../../Drivers/BSP/STM32F429I-Discovery/stm32f429i_discovery_lcd.h"

void showChooseCanvaInterface(void)
{
	BSP_LCD_Clear(LCD_COLOR_WHITE);

	BSP_LCD_SetTextColor(LCD_COLOR_DARKMAGENTA);

	BSP_LCD_FillRect(30, 45, 180, 70);
	BSP_LCD_FillRect(30, 125, 180, 70);
	BSP_LCD_FillRect(30, 205, 180, 70);

	BSP_LCD_SetTextColor(LCD_COLOR_WHITE);
	BSP_LCD_SetFont(&Font24);
	BSP_LCD_SetBackColor(LCD_COLOR_DARKMAGENTA);

	BSP_LCD_DisplayStringAt(0,68, (uint8_t*)"CANVAS #1", CENTER_MODE);
	BSP_LCD_DisplayStringAt(0,148, (uint8_t*)"CANVAS #2", CENTER_MODE);
	BSP_LCD_DisplayStringAt(0,228, (uint8_t*)"INFO", CENTER_MODE);
	activeView = ChooseScreen;
	HAL_Delay(500);


}

void choose(void)
{
	while(activeView == ChooseScreen)
	{
		BSP_TS_GetState(&tsChooseCanva);
		if(tsChooseCanva.TouchDetected && tsChooseCanva.Y > 45 && tsChooseCanva.Y < 115)
		{
			activeView = Canvas1;
		}
		else if(tsChooseCanva.TouchDetected && tsChooseCanva.Y > 125 && tsChooseCanva.Y < 195)
		{
			activeView = Canvas2;
		}
		else if(tsChooseCanva.TouchDetected && tsChooseCanva.Y > 205 && tsChooseCanva.Y < 275)
		{
			activeView = Info;
		}
	}
}

void showInfoScreen(void)
{
	BSP_LCD_Clear(LCD_COLOR_WHITE);
	BSP_LCD_SetTextColor(LCD_COLOR_BLACK);
	BSP_LCD_SetBackColor(LCD_COLOR_WHITE);


	BSP_LCD_SetFont(&Font16);
	BSP_LCD_DisplayStringAt(0,50, (uint8_t*)"App:",CENTER_MODE);

	BSP_LCD_SetFont(&Font12);

	BSP_LCD_DisplayStringAt(0,68, (uint8_t*)"App has autosave mode. When you",CENTER_MODE);
	BSP_LCD_DisplayStringAt(0,82, (uint8_t*)"leave canvas and return,",CENTER_MODE);
	BSP_LCD_DisplayStringAt(0,96, (uint8_t*)"you will see your last drawing.",CENTER_MODE);

	BSP_LCD_SetFont(&Font16);
	BSP_LCD_DisplayStringAt(0,125, (uint8_t*)"Authors:",CENTER_MODE);

	BSP_LCD_SetFont(&Font12);

	BSP_LCD_DisplayStringAt(0,142, (uint8_t*)"Anna Bernas",CENTER_MODE);
	BSP_LCD_DisplayStringAt(0,160, (uint8_t*)"Emilia Kalinska",CENTER_MODE);

	BSP_LCD_SetTextColor(LCD_COLOR_DARKMAGENTA);
	BSP_LCD_SetBackColor(LCD_COLOR_DARKMAGENTA);
	BSP_LCD_FillRect(30, 205, 180, 70);
	BSP_LCD_SetTextColor(LCD_COLOR_WHITE);
	BSP_LCD_SetFont(&Font24);
	BSP_LCD_DisplayStringAt(0,228, (uint8_t*)"BACK", CENTER_MODE);
	BSP_LCD_SetBackColor(LCD_COLOR_WHITE);
}

void serviceInfoScreen(void)
{
	showInfoScreen();
	HAL_Delay(500);
	while(activeView == Info)
	{
		BSP_TS_GetState(&tsChooseCanva);
		if(tsChooseCanva.TouchDetected && tsChooseCanva.Y > 205 && tsChooseCanva.Y < 275)
		{
			activeView = ChooseScreen;
		}
	}
}
