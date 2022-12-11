/*
 * EEPROM.h
 * Created on: Dec 10, 2022
 * Author : Mohammed Mostafa
 */

#include "EEPROM.h"


void EEPROM_Init()
{
	IIC_Master_Init();

}


void EEPROM_WRITE(uint8 EEPROM_ADDRESS,uint8 EEPROM_DATA)
{
	IIC_Start_Condition();
	IIC_SendSlaveAddress_Write(0b1010000);
	IIC_Send_Data(EEPROM_ADDRESS);
	IIC_Send_Data(EEPROM_DATA);
	IIC_Stop_Condition();

}
uint8 EEPROM_READ(uint8 EEPROM_ADDRESS)
{
	uint8 data=0;
	IIC_Start_Condition();
	IIC_SendSlaveAddress_Write(0b1010000);
	IIC_Send_Data(EEPROM_ADDRESS);
	IIC_Repeated_Start();
	IIC_SendSlaveAddress_Read(0b1010000);
	data = IIC_Read_Data();
	IIC_Stop_Condition();

	return data;
}


