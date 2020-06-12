/*
 * chooseCanvaInterface.h
 *
 *  Created on: 22 kwi 2020
 *      Author: berna
 */

#ifndef INC_CHOOSECANVAINTERFACE_H_
#define INC_CHOOSECANVAINTERFACE_H_

#include "../../Drivers/BSP/STM32F429I-Discovery/stm32f429i_discovery_ts.h"

TS_StateTypeDef tsChooseCanva;

void showChooseCanvaInterface(void);
void showInfoScreen(void);
void choose(void);
void serviceInfoScreen(void);

#endif /* INC_CHOOSECANVAINTERFACE_H_ */
