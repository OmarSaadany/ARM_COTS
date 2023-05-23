//#include	"Std_Types.h"
//#include	"Bit_Math.h"
//
//#include	"RCC_interface.h"
//#include	"DIO_interface.h"
//
//#include	"NVIC_interface.h"
//void	EXTI0_IRQHandler(void);
//
//void	_delay_ms(u32 ticks)
//{
//	u32 i;
//	for( i = 0; i < (ticks * 500) ; i++)
//	{
//		asm("NOP");
//	}
//}
//
//int main(void)
//{
//	/*	System Clock Init			*/
//	RCC_voidSysClkInt();
//
//	/*	Enable RCC for GPIOC 		*/
//	RCC_voidEnablePerClk(RCC_APB2,4);
//
//	/*	C13 Direction 	"Output @ 2MHz Push Pull"	*/
//	DIO_voidSetPinDirection(PORTC,PIN13,GPIO_OUTPUT_2MHZ_PP);
//
//	/*	Interrupt Initialization	*/
//	NVIC_voidInit();
//
//	/*	Set pending Flag EXTI0		*/
//	NVIC_voidSetPendingFlag(6);
//
//	/*	Set pending Flag EXTI0		*/
//	NVIC_voidSetPendingFlag(7);
//
//
//	/*	NVIC EXTI0 Enable 			*/
//	NVIC_voidEnablePerInt(6);
//
//	/*	NVIC EXTI0 Enable 			*/
//	NVIC_voidEnablePerInt(7);
//	while(1)
//	{
//
//	}
//	return 0;
//}
////void 	__vector_1(void)
//void	EXTI0_IRQHandler(void)
//{
//		/*		Led On		*/
//		DIO_voidSetPinValue(PORTC,PIN13,GPIO_LOW);
//		_delay_ms(500);
//		/*		Led Off		*/
//		DIO_voidSetPinValue(PORTC,PIN13,GPIO_HIGH);
//		_delay_ms(500);
//	/*	Clear EXTI0 Flag	*/
//}
//
//
//void	EXTI1_IRQHandler(void)
//{
//		/*		Led On		*/
//		DIO_voidSetPinValue(PORTC,PIN13,GPIO_LOW);
//		_delay_ms(1000);
//		/*		Led Off		*/
//		DIO_voidSetPinValue(PORTC,PIN13,GPIO_HIGH);
//		_delay_ms(1000);
//	/*	Clear EXTI0 Flag	*/
//}





#include	"Std_Types.h"
#include	"Bit_Math.h"

#include	"RCC_interface.h"
#include	"DIO_interface.h"
#include 	"EXTI_interface.h"
#include 	"EXTI_private.h"
#include	"NVIC_interface.h"
u8 i=2;
void	EXTI0_IRQHandler(void);

void	_delay_ms(u32 ticks)
{
	u32 i;
	for( i = 0; i < (ticks * 500) ; i++)
	{
		asm("NOP");
	}
}

int main(void)
{

	/*	System Clock Init			*/
	RCC_voidSysClkInt();

	/*	Enable RCC for GPIOC 		*/
	RCC_voidEnablePerClk(RCC_APB2,4);
	RCC_voidEnablePerClk(RCC_APB2,2);
	RCC_voidEnablePerClk(RCC_APB2,0);
	/*	C13 Direction 	"Output @ 2MHz Push Pull"	*/
	DIO_voidSetPinDirection(PORTC,PIN13,GPIO_OUTPUT_2MHZ_PP);
	DIO_voidSetPinDirection(PORTA,PIN0,GPIO_INPUT_PULL_UP_DOWN);
	DIO_voidSetPinDirection(PORTA,PIN2,GPIO_INPUT_PULL_UP_DOWN);

	DIO_voidSetPinDirection(PORTA,PIN3,GPIO_INPUT_PULL_UP_DOWN);

	DIO_voidSetPinDirection(PORTA,PIN4,GPIO_INPUT_PULL_UP_DOWN);

	DIO_voidSetPinDirection(PORTA,PIN5,GPIO_INPUT_PULL_UP_DOWN);



	DIO_voidSetPinValue(PORTA,PIN0,GPIO_HIGH);
	DIO_voidSetPinValue(PORTC,PIN13,GPIO_LOW);
	/*	Interrupt Initialization	*/
	NVIC_voidInit();

	EXTI_voidInit(EXTI_PORTA, 0);
	EXTI_voidEnableInt(EXTI_LINE_0);
	EXTI_voidChangeSenseMode(EXTI_LINE_0, FALLING_EDGE);
	NVIC_voidEnablePerInt(6);

	while(1)
	{

	}
	return 0;
}
//void 	__vector_1(void)
void	EXTI0_IRQHandler(void)
{
		/*		Led On		*/


	DIO_voidSetPinValue(PORTC, 13, GPIO_HIGH);


}

//
//void	EXTI1_IRQHandler(void)
//{
//		/*		Led On		*/
//		DIO_voidSetPinValue(PORTC,PIN13,GPIO_LOW);
//		_delay_ms(1000);
//		/*		Led Off		*/
//		DIO_voidSetPinValue(PORTC,PIN13,GPIO_HIGH);
//		_delay_ms(1000);
//	/*	Clear EXTI0 Flag	*/
//}
//


