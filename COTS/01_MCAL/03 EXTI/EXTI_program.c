#include	"STD_TYPES.h"
#include	"BIT_MATH.h"
#include	"EXTI_interface.h"
#include 	"EXTI_private.h"


#ifndef		NULL
#define		NULL			((void *)0)
#endif

//
//static	void	(*EXTI0_CallBack)	(void)	= NULL;

void		EXTI_voidInit(u8 PORT, u8 pin)
{
	#ifndef			AFIO_EXTICR1
	#define			AFIO_BASE_ADD	     	(0x40010000)
	#define			AFIO_EXTICR1			*((u32 *)(AFIO_BASE_ADD+0x08))
	#endif

	#ifndef			AFIO_EXTICR2
	#define			AFIO_EXTICR2			*((u32 *)(AFIO_BASE_ADD+0x0C))
	#endif

	#ifndef			AFIO_EXTICR3
	#define			AFIO_EXTICR3			*((u32 *)(AFIO_BASE_ADD+0x10))
	#endif

	#ifndef			AFIO_EXTICR4
	#define			AFIO_EXTICR4			*((u32 *)(AFIO_BASE_ADD+0x14))
	#endif
if (pin <=3)
{
	switch (PORT)
		{
			case 	EXTI_PORTA: clr_bit(AFIO_EXTICR1,(0+(pin*4)));
								clr_bit(AFIO_EXTICR1,(1+(pin*4)));
								clr_bit(AFIO_EXTICR1,(2+(pin*4)));
								clr_bit(AFIO_EXTICR1,(3+(pin*4)));		break;

			case 	EXTI_PORTB:	set_bit(AFIO_EXTICR1,(0+(pin*4)));
								clr_bit(AFIO_EXTICR1,(1+(pin*4)));
								clr_bit(AFIO_EXTICR1,(2+(pin*4)));
								clr_bit(AFIO_EXTICR1,(3+(pin*4)));		break;

			case 	EXTI_PORTC: clr_bit(AFIO_EXTICR1,(0+(pin*4)));
								set_bit(AFIO_EXTICR1,(1+(pin*4)));
								clr_bit(AFIO_EXTICR1,(2+(pin*4)));
								clr_bit(AFIO_EXTICR1,(3+(pin*4)));		break;

		}
}
else if (pin <=7)
{
	pin-=4;
	switch (PORT)
			{
			case 	EXTI_PORTA: clr_bit(AFIO_EXTICR2,(0+(pin*4)));
								clr_bit(AFIO_EXTICR2,(1+(pin*4)));
								clr_bit(AFIO_EXTICR2,(2+(pin*4)));
								clr_bit(AFIO_EXTICR2,(3+(pin*4)));		break;

			case 	EXTI_PORTB:	set_bit(AFIO_EXTICR2,(0+(pin*4)));
								clr_bit(AFIO_EXTICR2,(1+(pin*4)));
								clr_bit(AFIO_EXTICR2,(2+(pin*4)));
								clr_bit(AFIO_EXTICR2,(3+(pin*4)));		break;

			case 	EXTI_PORTC: clr_bit(AFIO_EXTICR2,(0+(pin*4)));
								set_bit(AFIO_EXTICR2,(1+(pin*4)));
								clr_bit(AFIO_EXTICR2,(2+(pin*4)));
								clr_bit(AFIO_EXTICR2,(3+(pin*4)));		break;

			}

}
else if (pin <=11)
{
	pin-=8;
	switch (PORT)
			{
				case 	EXTI_PORTA: clr_bit(AFIO_EXTICR3,(0+(pin*4)));
									clr_bit(AFIO_EXTICR3,(1+(pin*4)));
									clr_bit(AFIO_EXTICR3,(2+(pin*4)));
									clr_bit(AFIO_EXTICR3,(3+(pin*4)));		break;

				case 	EXTI_PORTB:	set_bit(AFIO_EXTICR3,(0+(pin*4)));
									clr_bit(AFIO_EXTICR3,(1+(pin*4)));
									clr_bit(AFIO_EXTICR3,(2+(pin*4)));
									clr_bit(AFIO_EXTICR3,(3+(pin*4)));		break;

				case 	EXTI_PORTC: clr_bit(AFIO_EXTICR3,(0+(pin*4)));
									set_bit(AFIO_EXTICR3,(1+(pin*4)));
									clr_bit(AFIO_EXTICR3,(2+(pin*4)));
									clr_bit(AFIO_EXTICR3,(3+(pin*4)));		break;

			}

}

else if (pin <=15)
{
	pin-=12;
	switch (PORT)
			{
				case 	EXTI_PORTA: clr_bit(AFIO_EXTICR4,(0+(pin*4)));
									clr_bit(AFIO_EXTICR4,(1+(pin*4)));
									clr_bit(AFIO_EXTICR4,(2+(pin*4)));
									clr_bit(AFIO_EXTICR4,(3+(pin*4)));		break;

				case 	EXTI_PORTB:	set_bit(AFIO_EXTICR4,(0+(pin*4)));
									clr_bit(AFIO_EXTICR4,(1+(pin*4)));
									clr_bit(AFIO_EXTICR4,(2+(pin*4)));
									clr_bit(AFIO_EXTICR4,(3+(pin*4)));		break;

				case 	EXTI_PORTC: clr_bit(AFIO_EXTICR4,(0+(pin*4)));
									set_bit(AFIO_EXTICR4,(1+(pin*4)));
									clr_bit(AFIO_EXTICR4,(2+(pin*4)));
									clr_bit(AFIO_EXTICR4,(3+(pin*4)));		break;

			}

}


}


void		EXTI_voidEnableInt(u8 line_num)
{
	set_bit(EXTI -> IMR,line_num);
}


void		EXTI_voidDisableInt(u8 line_num)
{
	clr_bit(EXTI -> IMR,line_num);
}


void		EXTI_voidEnableSWI(u8 line_num)
{
	clr_bit(EXTI -> SWIER,line_num);
}

void		EXTI_voidChangeSenseMode(u8 line_num, u8 Sense_Mode)
{
	switch(Sense_Mode)
	{
		case	RISING_EDGE		:	set_bit(EXTI -> RTSR,line_num);
									clr_bit(EXTI -> FTSR,line_num);		break;
		case	FALLING_EDGE	:	set_bit(EXTI -> FTSR,line_num);
									clr_bit(EXTI -> RTSR,line_num);		break;
		case	ON_CHANGE		:	set_bit(EXTI -> RTSR,line_num);
									set_bit(EXTI -> FTSR,line_num);		break;
	}
	set_bit(EXTI -> IMR,line_num);
}

//void		EXTI0_voidSetCallBack(void (*Fptr)(void))
//{
//	if(Fptr != NULL)
//	{
//		Fptr = EXTI0_CallBack;
//	}
//}

//void	EXTI0_IRQHandler(void)
//{
//	EXTI0_CallBack();
//	/*	Clear the Flag			*/
//}
//

