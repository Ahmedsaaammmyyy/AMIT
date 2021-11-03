/*
 * ADC_Program.c
 *
 *  Created on: Sep 19, 2021
 *      Author: ahmed
 */

#include"STD_TYPES.h"
#include"BIT_MATH.h"

#include"ADC_Private.h"

void ADC_voidInit(void)
{
	
	SET_BIT(ADMUX,6);
	CLR_BIT(ADMUX,7);
	CLR_BIT(ADMUX,5);
	SET_BIT(ADCSRA,2);
	SET_BIT(ADCSRA,1);
	SET_BIT(ADCSRA,0);
	SET_BIT(ADCSRA,7);
}
u16 ADC_u16StartConversion(u8 Copy_u8Channel)
{
	u16 LOC_u16DataValue=0;
	Copy_u8Channel&=0x07;
	ADMUX&=0xE0;
	ADMUX|=Copy_u8Channel;
	SET_BIT(ADCSRA,6);
	while(GET_BIT(ADCSRA,4)==0);
	//LOC_u16DataValue=ADCL|(ADCH<<8);
	LOC_u16DataValue=ADC;
	return LOC_u16DataValue;
}
