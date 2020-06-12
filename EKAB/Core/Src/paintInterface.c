/*
 * paintInterface.c
 *
 *  Created on: 16 kwi 2020
 *      Author: berna
 */

#include "paintInterface.h"
#include "chooseViewStructure.h"
#include "save.h"

uint32_t LastColor = LCD_COLOR_BLACK;
uint16_t LastRadius = 5;
uint16_t LastColorMarkdownX = 3;
uint16_t LastColorMArkdownY = 96;
uint16_t LastThicknessMarkdownX = 53;
uint16_t LastThicknessMArkdownY = 3;

void showPaintInterface(uint8_t canvas)
{
	BSP_LCD_Clear(LCD_COLOR_WHITE);

	BSP_LCD_SetTextColor(LCD_COLOR_BLACK);
	BSP_LCD_SetFont(&Font16);
	BSP_LCD_SetBackColor(LCD_COLOR_WHITE);
	BSP_LCD_DisplayChar(9, 5, '#');
	BSP_LCD_DisplayChar(20,5, canvas);

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

	markdown(LastColorMarkdownX, LastColorMArkdownY, COLOR);
	markdown(LastThicknessMarkdownX, LastThicknessMArkdownY, THICKNESS);
}

void paintService(uint8_t canvas)
{
	clearWorkspace(canvas);
	if(activeView == Canvas1)
	{
		loadPartOfSketch(10, 0x080C0000, 38, 38);
		loadPartOfSketch(11, 0x080E0000, 38, 179);
	}
	else
	{
		loadPartOfSketch(8, 0x08080000, 38, 38);
		loadPartOfSketch(9, 0x080A0000, 38, 179);
	}

	HAL_Delay(500);
	while(activeView == Canvas1 || activeView == Canvas2)
	{
		BSP_TS_GetState(&ts_struct);
		if(ts_struct.TouchDetected && ts_struct.X < 240-LastRadius){
			if(ts_struct.TouchDetected && ts_struct.X > 37 + LastRadius && ts_struct.Y > 37+LastRadius)
			{
				BSP_LCD_SetTextColor(LastColor);
				BSP_LCD_FillCircle(ts_struct.X, ts_struct.Y, LastRadius);
			}
			else if(ts_struct.TouchDetected && (ts_struct.X > 164) && (ts_struct.Y < 35) && (ts_struct.X <238))
			{
				LastColor = LCD_COLOR_BLACK;
				LastRadius = 5;
				LastColorMarkdownX = 3;
				LastColorMArkdownY = 96;
				LastThicknessMarkdownX = 53;
				LastThicknessMArkdownY = 3;

				if(activeView == Canvas1)
				{
					savePartOfSketch(10, 0x080C0000, 38, 38);
					savePartOfSketch(11, 0x080E0000, 38, 179);
				}
				else
				{
					savePartOfSketch(8, 0x08080000, 38, 38);
					savePartOfSketch(9, 0x080A0000, 38, 179);
				}
				activeView = ChooseScreen;
			}
			else if(ts_struct.TouchDetected && (ts_struct.Y > 22) && (ts_struct.Y < 52) && (ts_struct.X <35))
			{
				clearWorkspace(canvas);
			}
			else if(ts_struct.TouchDetected && (ts_struct.Y > 60) && (ts_struct.Y < 90))
			{
				markdown(3, 58, COLOR);
				LastColor = LCD_COLOR_WHITE;
			}
			else if(ts_struct.TouchDetected && (ts_struct.Y > 98) && (ts_struct.Y < 128))
			{
				markdown(3, 96, COLOR);
				LastColor = LCD_COLOR_BLACK;

			}
			else if(ts_struct.TouchDetected && (ts_struct.Y > 136) && (ts_struct.Y < 166))
			{
				markdown(3, 134, COLOR);
				LastColor = LCD_COLOR_YELLOW;

			}
			else if(ts_struct.TouchDetected && (ts_struct.Y > 174) && (ts_struct.Y < 204))
			{
				markdown(3, 172, COLOR);
				LastColor = LCD_COLOR_RED;

			}
			else if(ts_struct.TouchDetected && (ts_struct.Y > 212) && (ts_struct.Y < 242))
			{
				markdown(3, 210, COLOR);
				LastColor = LCD_COLOR_BLUE;

			}
			else if(ts_struct.TouchDetected && (ts_struct.Y > 250) && (ts_struct.Y < 280))
			{
				markdown(3, 248, COLOR);
				LastColor = LCD_COLOR_GREEN;
			}
			else if(ts_struct.TouchDetected && (ts_struct.Y > 288) && (ts_struct.Y < 318))
			{
				markdown(3, 286, COLOR);
				LastColor = LCD_COLOR_MAGENTA;

			}
			else if(ts_struct.TouchDetected && (ts_struct.X > 55) && (ts_struct.X < 85))
			{
				LastRadius = 5;
				markdown(53, 3, THICKNESS);

			}
			else if(ts_struct.TouchDetected && (ts_struct.X > 93) && (ts_struct.X < 123))
			{
				LastRadius = 10;
				markdown(91, 3, THICKNESS);
			}
			else if(ts_struct.TouchDetected && (ts_struct.X > 131) && (ts_struct.X < 161))
			{
				LastRadius = 15;
				markdown(129, 3, THICKNESS);
			}
		}
	}
}

void resetColorMarkdown(void)
{
	BSP_LCD_SetTextColor(LCD_COLOR_WHITE);
	BSP_LCD_DrawRect(3, 58, 34, 34);
	BSP_LCD_DrawRect(3, 96, 34, 34);
	BSP_LCD_DrawRect(3, 134, 34, 34);
	BSP_LCD_DrawRect(3, 172, 34, 34);
	BSP_LCD_DrawRect(3, 210, 34, 34);
	BSP_LCD_DrawRect(3, 248, 34, 34);
	BSP_LCD_DrawRect(3, 286, 34, 34);
}

void resetThicknessMarkdown(void)
{
	BSP_LCD_SetTextColor(LCD_COLOR_WHITE);

	BSP_LCD_DrawRect(53, 3, 34, 34);
	BSP_LCD_DrawRect(91, 3, 34, 34);
	BSP_LCD_DrawRect(129, 3, 34, 34);
}

void markdown(uint16_t x,uint16_t y,Markdown_type type)
{
	if(type == COLOR)
	{
		resetColorMarkdown();
		LastColorMarkdownX = x;
		LastColorMArkdownY = y;
	}
	else
	{
		resetThicknessMarkdown();
		LastThicknessMarkdownX = x;
		LastThicknessMArkdownY = y;
	}
	BSP_LCD_SetTextColor(LCD_COLOR_RED);
	BSP_LCD_DrawRect(x, y, 34, 34);
}

void clearWorkspace(uint8_t canvas)
{
	BSP_LCD_Clear(LCD_COLOR_WHITE);
	showPaintInterface(canvas);
	BSP_LCD_SetTextColor(LastColor);
}

void savePartOfSketch(uint8_t sector, uint32_t addrs,int startX,int startY)
{
	uint32_t buff[28482];
	uint16_t i;
	uint16_t j;
	int bufferIter = 0;
	for(i=startX ; i < 240; ++i)
	{
		for(j=startY; j < startY+141; ++j)
		{
			if(bufferIter > 28481) break;
			buff[bufferIter] = BSP_LCD_ReadPixel(i, j);
			bufferIter++;
		}
	}

	SetSectorAddr(sector,addrs);
	WriteToFlash(0, buff,28482);
}

void loadPartOfSketch(uint8_t sector, uint32_t addrs,int startX,int startY)
{
	uint32_t buff[28482];
	SetSectorAddr(sector,addrs);
	ReadFromFlash(0, buff,28482);
	uint16_t i;
	uint16_t j;
	int bufferIter = 0;
	for(i=startX ; i < 240; ++i)
	{
		for(j=startY; j < startY+141; ++j)
		{
			if(bufferIter> 28481) break;
			BSP_LCD_DrawPixel(i, j, buff[bufferIter]);
			bufferIter++;
		}
	}
}

