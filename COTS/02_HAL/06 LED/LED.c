 #include "LED.h"
 
 void LED_init(u8 ledport  , u8 ledpin) {
	 DIO_voidSetPinDirection(port , pin, GPIO_OUTPUT_2MHZ_PP) ;
 }

 void LED_on (u8 ledport  , u8 ledpin ) {
	 DIO_voidSetPinValue(port ,pin , GPIO_HIGH) ;
	 
 }
void LED_off (u8 ledport , u8 ledpin ) {
	DIO_voidSetPinValue(port , pin ,GPIO_LOW) ;
}
