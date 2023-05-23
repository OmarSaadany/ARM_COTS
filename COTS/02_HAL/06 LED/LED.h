#ifndef LED_H_

#define LED_H_
#include	"STD_TYPES.h"
#include	"BIT_MATH.h"

#include    "DIO_interface.h"


 void LED_init(u8 	port  , u8 pin) ;
 void LED_on (u8 	port  , u8 pin ) ;
 void LED_off (u8 	port , u8  pin ) ;


#endif /* LED_H_ */
