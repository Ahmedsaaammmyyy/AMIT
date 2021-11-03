/*
 * eeprom.h
 *
 * Created: 10/22/2021 12:56:09 PM
 *  Author: ahmed
 */ 


#ifndef EEPROM_H_
#define EEPROM_H_

#define EEPROM_SIZE 1023
#define EEAR	*((volatile u16*)0x3E)
#define EEWE     1
#define EEMWE    2
#define EERE     0


void EEPROM_write(u16 uiAddress, u8 ucData);
u8 EEPROM_read(u16 uiAddress);


#endif /* EEPROM_H_ */