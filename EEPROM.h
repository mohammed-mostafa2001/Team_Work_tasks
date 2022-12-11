/*
 * EEPROM.h
 * Created on: Dec 10, 2022
 * Author : Mohammed Mostafa
 */

#ifndef HALL_EEPROM_H_
#define HALL_EEPROM_H_


#include "IIC.h"

void EEPROM_Init();
void EEPROM_WRITE(uint8 EEPROM_ADDRESS,uint8 EEPROM_DATA);
uint8 EEPROM_READ(uint8 EEPROM_ADDRESS);



#endif /* HALL_EEPROM_H_ */
