/*
 * EEPROM.h
 * Created on: Dec 10, 2022
 * Author : Mohammed Mostafa
 */
 /*but this  and iic.h in Mcal */

#include "IIC.h"

void IIC_Master_Init(void)
{
    DIO_SetPinDir(DIO_PORTC , DIO_PIN0 , DIO_PIN_OUTPUT);
	DIO_SetPinDir(DIO_PORTC , DIO_PIN1 , DIO_PIN_OUTPUT);
	/*SCL Freq = 400K when the oscilator = 8M */
	TWBR = 0x02;
	/*Enable IIC*/
	SET_BIT(TWCR , 2);
}

void IIC_Slave_Init(void)
{
	/*Address of Slave*/
	TWAR = (0x01<<1);
	/*Enable IIC*/
	SET_BIT(TWCR , 2);
}

void IIC_Start_Condition(void)
{
	

	TWCR = (1<<7) | (1<< 5) | (1<<2);  
	/*Generate Start Condition*/
	/*SET_BIT(TWCR , 5);
	SET_BIT(TWCR , 7);
	SET_BIT(TWCR , 2);*/

	while(GET_BIT(TWCR,7) == 0);

	while((TWSR & 0XF8) != START_ACK);
}

void IIC_Repeated_Start(void)
{

	TWCR = (1<<7) | (1<< 5) | (1<<2);
	/*Generate Repeated Start Condition*/
	/*SET_BIT(TWCR , 5);
	SET_BIT(TWCR , 7);
	SET_BIT(TWCR , 2);*/

	while(GET_BIT(TWCR,7) == 0);
	while((TWSR & 0XF8) != REP_START_ACK);
}

void IIC_SendSlaveAddress_Write(uint8 addr)
{
	TWDR = (addr << 1);


	TWCR = (1<<7) | (1<<2);
	
	/*SET_BIT(TWCR , 7);
	SET_BIT(TWCR , 2);*/

	while(GET_BIT(TWCR,7) == 0);

	while((TWSR & 0XF8) != SLAVE_ADD_AND_WR_ACK);

}

void IIC_SendSlaveAddress_Read(uint8 addr)
{
	TWDR = (addr << 1) | (0x01);


	TWCR = (1<<7) | (1<<2);

	/*SET_BIT(TWCR , 7);
	SET_BIT(TWCR , 2);*/

	while(GET_BIT(TWCR,7) == 0);

	while((TWSR & 0XF8) != SLAVE_ADD_AND_RD_ACK);
}

void IIC_Send_Data(uint8 data)
{
	TWDR  = data;


	TWCR = (1<<7) | (1<<2);
	
	/*SET_BIT(TWCR , 7);
	SET_BIT(TWCR , 2);*/

	while(GET_BIT(TWCR,7) == 0);

	while((TWSR & 0XF8) != WR_BYTE_ACK);

}

uint8 IIC_Read_Data(void)
{


	TWCR = (1<<7) | (1<<2);
	/*SET_BIT(TWCR , 7);
	SET_BIT(TWCR , 2);*/

	while(GET_BIT(TWCR,7) == 0);


	return TWDR;
}

void IIC_Stop_Condition(void)
{

	/*Generate Stop Condition*/
	/*SET_BIT(TWCR , 4);

	SET_BIT(TWCR , 7);
	SET_BIT(TWCR , 2);*/
	TWCR =(1<<7) | (1<< 4) | (1<<2);

}
