#ifndef		EXTI_INTERFACE_H
#define		EXTI_INTERFACE_H





void		EXTI_voidInit(u8 PORT, u8 pin);
void		EXTI_voidEnableInt(u8 line_num);
void		EXTI_voidDisableInt(u8 line_num);

void		EXTI_voidEnableSWI(u8 line_num);
void		EXTI_voidChangeSenseMode(u8 line_num, u8 Sense_Mode);


void		EXTI0_voidSetCallBack(void (*Fptr)(void));

#define 		EXTI_PORTA			0
#define 		EXTI_PORTB			1
#define 		EXTI_PORTC			2


#define 		EXTI_LINE_0			0
#define 		EXTI_LINE_1 		1
#define 		EXTI_LINE_2 		2
#define 		EXTI_LINE_3 		3
#define 		EXTI_LINE_4 		4
#define 		EXTI_LINE_5 		5
#define 		EXTI_LINE_6 		6
#define 		EXTI_LINE_7 		7
#define 		EXTI_LINE_8 		8
#define 		EXTI_LINE_9  		9
#define 		EXTI_LINE_10		10
#define 		EXTI_LINE_11		11
#define 		EXTI_LINE_12		12
#define 		EXTI_LINE_13		13
#define 		EXTI_LINE_14		14
#define 		EXTI_LINE_15		15



#define			RISING_EDGE			0
#define			FALLING_EDGE		1
#define			ON_CHANGE			2
#endif
