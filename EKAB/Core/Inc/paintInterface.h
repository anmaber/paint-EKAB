/*
 * paintInterface.h
 *
 *  Created on: 16 kwi 2020
 *      Author: berna
 */

#ifndef INC_PAINTINTERFACE_H_
#define INC_PAINTINTERFACE_H_

#include "../../Drivers/BSP/STM32F429I-Discovery/stm32f429i_discovery_lcd.h"
#include "paint.h"


typedef enum
{
	COLOR,
	THICKNESS

}Markdown_type;


void showPaintInterface(uint8_t canvas);
void resetColorMarkdown(void);
void resetThicknessMarkdown(void);
void markdown(uint16_t x,uint16_t y,Markdown_type type);
void clearWorkspace(uint8_t canvas);
void paintProcess(uint8_t canvas);
void savePartOfSketch(uint8_t sector, uint32_t addrs,int startX,int startY);
void loadPartOfSketch(uint8_t sector, uint32_t addrs,int startX,int startY);


#endif /* INC_PAINTINTERFACE_H_ */
