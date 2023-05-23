/*
 * SSD_prg.c
 *
 *  Created on: Feb 15, 2023
 *      Author: e
 */

#include "STD_TYPES.h"
#include "DIO_interface.h"
#include "DIO_private.h"

#include "SSD_interface.h"

static const u8 CGS_u8SSD_Num[10]={0b0111111,0b0000110,// value of sevenSegmant code == array index
		0b1011011,0b1001111,
		0b1100110,0b1101101,
		0b1111101,0b0000111,
		0b1111111,0b1101111};

void SSD_vInit(u8 A_u8SSDPort, u8 startPin, u8 endPin)
{

	switch (A_u8SSDPort)
	{
	case PORTA:
		for (u8 i=startPin; i<=endPin ; i++)
			{
				DIO_voidSetPinDirection(PORTA,i,GPIO_HIGH);
			}
		break;

	case PORTB:
		for (u8 i=startPin; i<endPin ; i++)
			{
				DIO_voidSetPinDirection(PORTB,i,GPIO_HIGH);
			}
		break;
	}
}


void SSD_vDisplayNum(u8 A_u8SSDPort, u8 startPin, u8 A_u8Num)
{
	//input validation
	if (A_u8Num<10)
	{
#if   SSD_TYPE == COM_CATHODE
		switch (A_u8SSDPort)
		{
			case PORTA:
				GPIOA_ODR &= ~(0b1111111<<startPin);
				GPIOA_ODR |= CGS_u8SSD_Num[A_u8Num]<<startPin ;
				break;

			case PORTB:
				GPIOB_ODR &= ~(0b1111111<<startPin);
				GPIOB_ODR |= CGS_u8SSD_Num[A_u8Num]<<startPin ;
				break;
		}


#elif SSD_TYPE == COM_ADODE
		switch (A_u8SSDPort)
		{
			case DIO_PORTA:
				GPIOA_ODR &= ~(0b1111111<<startPin);
				GPIOA_ODR |= CGS_u8SSD_Num[A_u8Num]<<startPin ;;
				break;
			case DIO_PORTB:
				GPIOB_ODR &= ~(0b1111111<<startPin);
				GPIOB_ODR |= CGS_u8SSD_Num[A_u8Num]<<startPin ;
				break;
		}

#endif
	}
}

void SSD_vTurnOff(u8 A_u8SSDPort,u8 startPin)
{
	switch (A_u8SSDPort)
	{
	case PORTA:
		GPIOA_ODR =GPIOA_ODR &= ~(0b1111111<<startPin);
		break;
	case PORTB:
		GPIOB_ODR =GPIOB_ODR &= ~(0b1111111<<startPin);
		break;
	}
}
