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

void showPaintInterface();
void paintService();
void resetColorMarkdown(void);
void resetThicknessMarkdown(void);
void markdown(uint16_t x,uint16_t y,Markdown_type type);
void clearWorkspace(void);

#endif /* INC_PAINTINTERFACE_H_ */
