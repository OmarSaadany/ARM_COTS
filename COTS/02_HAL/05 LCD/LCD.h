
#ifndef LCD4BIT_H_
#define LCD4BIT_H_

#include	"STD_TYPES.h"
#include	"BIT_MATH.h"

#include	"RCC_interface.h"
#include    "DIO_interface.h"



void LCD_init( ) ;
void LCD_writechar(u8 data) ;
void LCD_writecmd(u8 cmd)  ;
void LCD_writestring(u8 *str);
void LCD_goto(u8 row, u8 col);
void LCD_writernumber(u16 number) ;
void LCD_customchar(u8 x , u8 y );

#define  RS					 PIN8
#define  RW					 PIN7
#define  EN                  PIN6
#define  CONTROL_PORT        PORTB
#define  DATA_PORT           PORTA





#endif /* LCD4BIT_H_ */
