/*
 * EEPROM.h
 *  Created on: Dec 10, 2022
 *   Author : Mohammed Mostafa
 */


#ifndef MCAL_IIC_H_
#define MCAL_IIC_H_

#include "STD_TYPES.h"
#include "Macros.h"
#include "Register_addresses.h"
#include "DIO.h"

#define START_ACK                0x08 // start has been sent
#define REP_START_ACK            0x10 // repeated start
#define SLAVE_ADD_AND_WR_ACK     0x18 // Master transmit ( slave address + Write request ) ACK
#define SLAVE_ADD_AND_RD_ACK     0x40 // Master transmit ( slave address + Read request ) ACK
#define WR_BYTE_ACK              0x28 // Master transmit data ACK
#define RD_BYTE_WITH_NACK        0x58// Master received data with not ACK
#define RD_BYTE_WITH_ACK         0x50// Master received data with not ACK
#define SLAVE_ADD_RCVD_RD_REQ    0xA8 // means that slave address is received with write req
#define SLAVE_ADD_RCVD_WR_REQ    0x60 // means that slave address is received with read req
#define SLAVE_DATA_RECEIVED      0x80 // means that read byte req is received
#define SLAVE_BYTE_TRANSMITTED   0xC0 // means that write byte req is received


void IIC_Master_Init(void);

void IIC_Slave_Init(void);

void IIC_Start_Condition(void);

void IIC_Repeated_Start(void);

void IIC_SendSlaveAddress_Write(uint8 addr);

void IIC_SendSlaveAddress_Read(uint8 addr);

void IIC_Send_Data(uint8 data);

uint8 IIC_Read_Data(void);

void IIC_Stop_Condition(void);

#endif /* MCAL_IIC_H_ */
