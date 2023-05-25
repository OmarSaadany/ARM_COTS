#include 			"STD_TYPES.h"
#include 			"Bit-Math.h"
#include            "RCC_interface.h"
#include            "GPIO_interface.h"
#include            "SPI_interface.h"
#include            "TFT_interface.h"
#include            "STK_interface.h"
#include 			"TFT_Letters.h"
int  main(void){

	// HSE 8MHZ
	RCC_voidInit();
	// GPIO A
	RCC_voidEnableClock(RCC_APB2,2);
	/* spi enable clock*/
	RCC_voidEnableClock(RCC_APB2,12);

	MGPIO_voidSetPinDirection(GPIO_U8_A,GPIO_U8_PIN1,GPIO_OUTPUT_2MHZ_PP);
	MGPIO_voidSetPinDirection(GPIO_U8_A,GPIO_U8_PIN2,GPIO_OUTPUT_2MHZ_PP);
	MGPIO_voidSetPinDirection(GPIO_U8_A,GPIO_U8_PIN5,GPIO_OUTPUT_2MHZ_AFPP);
	MGPIO_voidSetPinDirection(GPIO_U8_A,GPIO_U8_PIN7,GPIO_OUTPUT_2MHZ_AFPP);


	MSTK_voidInit();

	MSPI1_voidInit();

	HTFT_voidInit();


	HTFT_voidFillBackground(0x0000);

	TFT_vSetXPos(9, 127);
	TFT_vSetYPos(4, 154);
	TFT_vFillRectangle(0xffff);

	TFT_vSetXPos(65		, (Letter_H_X-1)+65);
	TFT_vSetYPos(90		, (Letter_H_Y-1)+90);
	TFT_vletter(Letter_H, Letter_H_size)	;
	TFT_vSetXPos(58		, (Letter_I_X-1)+58);
	TFT_vSetYPos(90		, (Letter_I_Y-1)+90);
	TFT_vletter(Letter_I, Letter_I_size)	;
	TFT_vSetXPos(77		, (Letter_U_X-1)+77);
	TFT_vSetYPos(75		, (Letter_U_Y-1)+75);
	TFT_vletter(Letter_U, Letter_U_size)	;
	TFT_vSetXPos(67		, (Letter_S_X-1)+67);
	TFT_vSetYPos(75		, (Letter_S_Y-1)+75);
	TFT_vletter(Letter_S, Letter_S_size)	;
	TFT_vSetXPos(58		, (Letter_E_X-1)+58);
	TFT_vSetYPos(75		, (Letter_E_Y-1)+75);
	TFT_vletter(Letter_E, Letter_E_size)	;
	TFT_vSetXPos(48		, (Letter_R_X-1)+48);
	TFT_vSetYPos(75		, (Letter_R_Y-1)+75);
	TFT_vletter(Letter_R, Letter_R_size)	;


	while(1){



	}



	return 0;
}
