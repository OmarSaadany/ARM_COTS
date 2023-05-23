
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "DIO_interface.h"
#include "SSD_interface.h"


/*	C13 ==> Built in led (Toggle Led)		*/
int main()
{
	/*	System Clock Init			*/
	RCC_voidSysClkInt();
	/*	Enable RCC for GPIOC 		*/

	RCC_voidEnablePerClk(RCC_APB2,2);
	u8 startPin=2;
	
	SSD_vInit(PORTA, startPin, 8);
	
	while(1)
	{
		for (u8 i=0 ;i<10; i++)
		{
			for (u8 x=0 ;x<100000; x++)
					{
			SSD_vDisplayNum(PORTA, startPin , i);
			SSD_vTurnOff(PORTA, startPin);
					}
		}


	}
	return 0;
}



