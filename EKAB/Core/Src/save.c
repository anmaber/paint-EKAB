/*
 * save.c
 *
 *  Created on: 8 cze 2020
 *      Author: berna
 */


#include "save.h"

//Private variables
//1. sector start address
static uint32_t SectorAddr;
static uint8_t SectorNum;

//functions definitions
//1. Erase Sector
void EraseSector(void)
{
	HAL_FLASH_Unlock();
	//Erase the required Flash sector
	FLASH_Erase_Sector(SectorNum, FLASH_VOLTAGE_RANGE_3);
	HAL_FLASH_Lock();
}

//2. Set Sector Adress
void SetSectorAddr(uint8_t sector, uint32_t addr)
{
	SectorNum = sector;
	SectorAddr = addr;
}

//3. Write Flash
void WriteToFlash(uint32_t idx, void *wrBuf, uint32_t Nsize)
{
	uint32_t flashAddress = SectorAddr + idx;

	//Erase sector before write
	EraseSector();

	//Unlock Flash
	HAL_FLASH_Unlock();
	//Write to Flash

	for(uint32_t i=0; i<Nsize; i++)
	{
		HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, flashAddress , ((uint32_t *)wrBuf)[i]);
		flashAddress+=4;
	}

	HAL_FLASH_Lock();
}
//4. Read Flash
void ReadFromFlash(uint32_t idx, void *rdBuf, uint32_t Nsize)
{
	uint32_t flashAddress = SectorAddr + idx;


		for(uint32_t i=0; i<Nsize; i++)
		{
			*((uint32_t *)rdBuf + i) = *(uint32_t *)flashAddress;
			flashAddress+=4;
		}

}
