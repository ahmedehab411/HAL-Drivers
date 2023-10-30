/*
 * EEPROM_PRG.c
 *
 *  Created on: Jan 7, 2022
 *      Author: Ahmed Ehab
 */

#include "LIB/stdtypes.h"
#include "LIB/bitmath.h"
#include "../../MCAL/I2C_Driver/I2C_INT.h"
#include "EEPROM_INT.h"
#include "util/delay.h"

void EEPROM_vidInit(void)
{
	I2C_vidInitMaster();
}

void EEPROM_vidWriteByte(u16 Copy_u16SlaveAddress, u8 Copy_u8Data)
{
    I2C_vidStart();
	I2C_vidSendSlaveAddressWithWriteRequest( 0x50 | ((Copy_u16SlaveAddress & 0x0700)>>8) );
	I2C_vidWriteByte((u8)Copy_u16SlaveAddress);
	I2C_vidWriteByte(Copy_u8Data);
	I2C_vidStop();
}
void EEPROM_vidRepeatedWriteByte(u16 Copy_u16SlaveAddress, u8 Copy_u8Data)
{
    I2C_vidRepeatedStart();
	I2C_vidSendSlaveAddressWithWriteRequest( 0x50 | ((Copy_u16SlaveAddress & 0x0700)>>8) );
	I2C_vidWriteByte((u8)Copy_u16SlaveAddress);
	I2C_vidWriteByte(Copy_u8Data);
	I2C_vidStop();
}

void EEPROM_vidReadByte(u16 Copy_u16SlaveAddress,u8 *Data)
{
	I2C_vidStart();
	I2C_vidSendSlaveAddressWithWriteRequest( 0x50 | ((Copy_u16SlaveAddress & 0x0700)>>8) );
    I2C_vidWriteByte((u8)Copy_u16SlaveAddress);
	I2C_vidRepeatedStart();
	I2C_vidSendSlaveAddressWithReadRequest( 0x50 | ((Copy_u16SlaveAddress & 0x0700)>>8) );
	I2C_vidReadByte(Data);
	I2C_vidStop();
}

void EEPROM_vidReadInteger(u16 Copy_u16SlaveAddress, u32 *Data)
{
	u8 byte1,byte2,byte3,byte4;
	u32 Read=0;
	EEPROM_vidReadByte(Copy_u16SlaveAddress,&byte1);
	EEPROM_vidReadByte((Copy_u16SlaveAddress+1),&byte2);
	EEPROM_vidReadByte((Copy_u16SlaveAddress+2),&byte3);
	EEPROM_vidReadByte((Copy_u16SlaveAddress+3),&byte4);
	Read|=byte1;
	Read|= ((u32)byte2)<<8;
	Read|= ((u32)byte3)<<16;
	Read|= ((u32)byte4)<<24;
	*Data=Read;
	I2C_vidStop();
}
void EEPROM_vidWriteInteger(u16 Copy_u16SlaveAdress,u32 Copy_u32Data)
{
	u8 byte1=(u8)(Copy_u32Data),byte2=(u8)(Copy_u32Data>>8),byte3=(u8)(Copy_u32Data>>16),byte4=(u8)(Copy_u32Data>>24);
	EEPROM_vidWriteByte(Copy_u16SlaveAdress,byte1);
	_delay_ms(20);
	EEPROM_vidWriteByte((Copy_u16SlaveAdress+1),byte2);
	_delay_ms(20);
	EEPROM_vidWriteByte((Copy_u16SlaveAdress+2),byte3);
	_delay_ms(20);
	EEPROM_vidWriteByte((Copy_u16SlaveAdress+3),byte4);
	_delay_ms(20);
	I2C_vidStop();
}
