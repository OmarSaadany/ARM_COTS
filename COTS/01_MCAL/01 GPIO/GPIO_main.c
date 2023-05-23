#include	"STD_TYPES.h"
#include	"BIT_MATH.h"


#include "RCC_interface.h"
#include "DIO_interface.h"



/*	C13 ==> Built in led (Toggle Led)		*/
int main()
{
	/*	System Clock Init			*/
	RCC_voidSysClkInt();
	/*	Enable RCC for GPIOC 		*/
	RCC_voidEnablePerClk(RCC_APB2,4);
	
	/*	C13 Direction 	"Output @ 2MHz Push Pull"	*/
	DIO_voidSetPinDirection(PORTC,PIN13,GPIO_OUTPUT_2MHZ_PP);
	
	while(1)
	{
		/*		Led On		*/
		DIO_voidSetPinValue(PORTC,PIN13,GPIO_LOW);
		for(u32 i = 0; i < 1000000 ; i++)
		{
			asm("NOP");
		}
		/*		Led Off		*/
		DIO_voidSetPinValue(PORTC,PIN13,GPIO_HIGH);
		for(u32 i = 0; i < 1000000 ; i++)
		{
			asm("NOP");
		}
	}
	return 0;
}



