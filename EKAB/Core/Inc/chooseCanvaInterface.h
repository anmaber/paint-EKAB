/*
 * chooseCanvaInterface.h
 *
 *  Created on: 10 cze 2020
 *      Author: ekalinsk
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
