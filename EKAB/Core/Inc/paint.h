/*
 * paintIntro.h
 *
 *  Created on: 16 kwi 2020
 *      Author: ekalinsk
 */

#ifndef INC_PAINT_H_
#define INC_PAINT_H_

#include "../../Drivers/BSP/STM32F429I-Discovery/stm32f429i_discovery_ts.h"

TS_StateTypeDef ts_struct;

void configTS(void);
void paint(void);

#endif /* INC_PAINT_H_ */
