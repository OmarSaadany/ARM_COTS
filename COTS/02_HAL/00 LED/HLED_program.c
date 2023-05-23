
#include "HLED_interface.h"



void HLED_voidLedInit (u8 port, u8 pin) 
{
	DIO_voidSetPinDirection(port,pin,GPIO_OUTPUT_2MHZ_PP);
}

void HLED_voidLedOn (u8 port, u8 pin)
{

	DIO_voidSetPinValue(port,pin,GPIO_HIGH);

}


void HLED_voidLedOff (u8 port, u8 pin)
{

	DIO_voidSetPinValue(port,pin,GPIO_LOW);
	

}
