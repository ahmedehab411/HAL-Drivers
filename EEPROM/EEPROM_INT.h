/*
 * EEPROM_INT.h
 *
 *  Created on: Jan 7, 2022
 *      Author: Ahmed Ehab
 */

#ifndef EEPROM_INT_H_
#define EEPROM_INT_H_

void EEPROM_vidInit(void);
void EEPROM_vidReadByte(u16 Copy_u16SlaveAddress, u8 *Data);
void EEPROM_vidWriteByte(u16 Copy_u16SlaveAdress,u8 Copy_u8Data);
void EEPROM_vidReadInteger(u16 Copy_u16SlaveAddress, u32 *Data);
void EEPROM_vidWriteInteger(u16 Copy_u16SlaveAdress,u32 Copy_u32Data);

#endif /* EEPROM_INT_H_ */
