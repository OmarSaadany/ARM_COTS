#ifndef BUTTON_H_
#define BUTTON_H_





#include	"STD_TYPES.h"
#include	"BIT_MATH.h"

#include "RCC_interface.h"
#include "DIO_interface.h"

void BUTTON_init (u8 port , u8 pin ) ;


u8 BUTTON_read(u8 port , u8 pin );



#endif /* BUTTON_H_ */
