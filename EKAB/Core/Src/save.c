/*
 * save.c
 *
 *  Created on: 8 cze 2020
 *      Author: berna
 */


#include "save.h"

static uint32_t SectorAddr;
static uint8_t SectorNum;

void EraseSector(void)
{
	HAL_FLASH_Unlock();
	FLASH_Erase_Sector(SectorNum, FLASH_VOLTAGE_RANGE_3);
	HAL_FLASH_Lock();
}

void SetSectorAddr(uint8_t sector, uint32_t addr)
{
	SectorNum = sector;
	SectorAddr = addr;
}

void WriteToFlash(uint32_t idx, void *wrBuf, uint32_t Nsize)
{
	uint32_t flashAddress = SectorAddr + idx;

	EraseSector();

	HAL_FLASH_Unlock();

	for(uint32_t i=0; i<Nsize; i++)
	{
		HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, flashAddress , ((uint32_t *)wrBuf)[i]);
		flashAddress+=4;
	}

	HAL_FLASH_Lock();
}

void ReadFromFlash(uint32_t idx, void *rdBuf, uint32_t Nsize)
{
	uint32_t flashAddress = SectorAddr + idx;


		for(uint32_t i=0; i<Nsize; i++)
		{
			*((uint32_t *)rdBuf + i) = *(uint32_t *)flashAddress;
			flashAddress+=4;
		}

}
