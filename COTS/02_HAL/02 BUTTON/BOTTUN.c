#include "BUTTON.h"


void BUTTON_init (u8 port , u8 pin ) {
	DIO_voidSetPinDirection(port ,pin , GPIO_INPUT_PULL_UP_DOWN);
	DIO_voidSetPinValue(port,pin ,GPIO_HIGH);
}

u8 BUTTON_read(u8 port , u8 pin ){
	return DIO_u8GetPinValue(port , pin) ;
}

