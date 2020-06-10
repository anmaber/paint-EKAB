/*
 * save.h
 *
 *  Created on: 8 cze 2020
 *      Author: berna
 */

#ifndef INC_SAVE_H_
#define INC_SAVE_H_
#include "stm32f4xx_hal.h"

void EraseSector(void);
void SetSectorAddr(uint8_t sector, uint32_t addrs);
void WriteToFlash(uint32_t idx, void *wrBuf, uint32_t Nsize);
void ReadFromFlash(uint32_t idx, void *rdBuf, uint32_t Nsize);

#endif /* INC_SAVE_H_ */
