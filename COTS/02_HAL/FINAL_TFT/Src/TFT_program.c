/********************************************************************/
/*   Author             :    AHMED Tarek Mansour			  	  	*/
/*	 Date 				:    26/1/2021								*/
/*	 Version 			:    1.0V 							 		*/
/*	 Description 		:   Program algorithm for TFT Peripheral	*/
/*									 [program.c]			   		*/
/********************************************************************/




/****************************************************************/
/***********************  LIB DIRECTIVES ************************/
/****************************************************************/

#include	"STD_TYPES.h"
#include	"Bit-Math.h"


/****************************************************************/
/***********************  TFT DIRECTIVES ************************/
/****************************************************************/
#include	"TFT_interface.h"
#include	"TFT_private.h"
#include	"TFT_config.h"
/****************************************************************/
/***********************  GPIO DIRECTIVES ************************/
/****************************************************************/
#include	"GPIO_interface.h"
/****************************************************************/
/***********************   MSTK DIRECTIVES ************************/
/****************************************************************/
#include	"STK_interface.h"
/****************************************************************/
/***********************  SPI DIRECTIVES ************************/
/****************************************************************/
#include	"SPI_interface.h"
/****************************************************************/
/*********************** Function Implementation  ***************/
/****************************************************************/

/****************************************************************/
/* Description    :  This function used to Initilize RCC		*/
/*					 Inputs :									*/
/*													 			*/
/*					 return : void		 						*/
/****************************************************************/

u16 current_XPos_start;
u16 current_XPos_end;
u16 current_YPos_start;
u16 current_YPos_end;


void HTFT_voidInit(void){
	


	/* Reset Pulse */
	MGPIO_voidSetPinValue(TFT_RST,GPIO_U8_HIGH);
		MSTK_voidSetBusyWait(100);
		MGPIO_voidSetPinValue(TFT_RST,GPIO_U8_LOW);
		MSTK_voidSetBusyWait(1);
		MGPIO_voidSetPinValue(TFT_RST,GPIO_U8_HIGH);
		MSTK_voidSetBusyWait(100);
		MGPIO_voidSetPinValue(TFT_RST,GPIO_U8_LOW);
		MSTK_voidSetBusyWait(100);
		MGPIO_voidSetPinValue(TFT_RST,GPIO_U8_HIGH);
		MSTK_voidSetBusyWait(120000);

		/* Sleep Out Command */
		voidWriteCommand(0x11);

		/* Wait 150 ms */
		MSTK_voidSetBusyWait(150000);

		/* Color Mode Command */
		voidWriteCommand(0x3A);
		voidWriteData   (0x05);

		/* Display On Command */
		voidWriteCommand(0x29);





}

void HTFT_voidDisplayImage(const u16 * Copy_Image){
	u8 Local_u8Data;
	/* Set X ADD*/
	voidWriteCommand(0x2A);
	voidWriteData(0);
	voidWriteData(0);
	/*END ADD*/
	voidWriteData(0);
	voidWriteData(127);
	/*SET Y ADD*/
	
	/* Set X ADD*/
	voidWriteCommand(0x2B);
	voidWriteData(0);
	voidWriteData(0);
	/*END ADD*/
	voidWriteData(0);
	voidWriteData(159);
	
	/* Ram Write*/
	voidWriteCommand(0x2C);
	for(u16 i = 0 ;i<20480;i++){
		/* MSB First High byte*/
		Local_u8Data=Copy_Image[i]>>8;
		voidWriteData(Local_u8Data);
		/* Low byte*/
		Local_u8Data=Copy_Image[i]&0x00ff;
		voidWriteData(Local_u8Data);
	}
	
	
}


 static void voidWriteCommand(u8 Copy_u8Command){
	u8 Local_u8Dummy;
	/* A0 LOW*/
	
		MGPIO_voidSetPinValue(TFT_A0,GPIO_U8_LOW);
	MSPI1_voidSendReciveByte(Copy_u8Command,&Local_u8Dummy);
	
}

static  void voidWriteData(u8 Copy_u8Data){
	u8 Local_u8Dummy;
	/* A0 LOW*/
	
		MGPIO_voidSetPinValue(TFT_A0,GPIO_U8_HIGH);
	MSPI1_voidSendReciveByte( Copy_u8Data,&Local_u8Dummy);
	
}





void HTFT_voidFillBackground(u16 color){
	u8 Local_u8Data;
	/* Set X ADD*/
	voidWriteCommand(0x2A);
	voidWriteData(0);
	voidWriteData(0);
	/*END ADD*/
	voidWriteData(0);
	voidWriteData(127);
	/*SET Y ADD*/

	/* Set X ADD*/
	voidWriteCommand(0x2B);
	voidWriteData(0);
	voidWriteData(0);
	/*END ADD*/
	voidWriteData(0);
	voidWriteData(159);

	/* Ram Write*/
	voidWriteCommand(0x2C);
	for(u16 i = 0 ;i<20480;i++){
		/* MSB First High byte*/
		Local_u8Data=color>>8;
		voidWriteData(Local_u8Data);
		/* Low byte*/
		Local_u8Data=color&0x00ff;
		voidWriteData(Local_u8Data);
	}


}




void TFT_vSetXPos(u16 xStart, u16 xEnd)
{
	current_XPos_start = xStart;
	current_XPos_end = xEnd;
	/* 1- set X position */
	voidWriteCommand(0x2A);
	// xstart: 0, xEnd: 127
	voidWriteData(0);
	voidWriteData(xStart);


	voidWriteData(0);
	voidWriteData(xEnd);
}
void TFT_vSetYPos(u16 yStart, u16 yEnd)
{
	current_YPos_start = yStart;
	current_YPos_end  = yEnd ;
	/* 2- set Y position */
	voidWriteCommand(0x2B);
	// ystart: 0, yEnd: 159
	voidWriteData(0);
	voidWriteData(yStart);
	voidWriteData(0);
	voidWriteData(yEnd);
}

void TFT_vFillRectangle(u16 Color)
{
	u32 No_pixels = (current_XPos_end-current_XPos_start)*(current_YPos_end-current_YPos_start);
	/* 3- send image data */
	voidWriteCommand(0x2C);
	for(int i=0; i<No_pixels; i++)
	{
		voidWriteData(Color >> 8); // Most-Significatn byte
		voidWriteData(Color & 0x00FF); // Least-Significant Byte
	}
}



void TFT_vletter(u16 A_pu16img[],u32 No_pixels )
{

    /* 3- send image data */
    voidWriteCommand(0x2C);
    for(int i=0; i<No_pixels; i++)
    {
    	voidWriteData(A_pu16img[i] >> 8); // Most-Significatn byte
    	voidWriteData(A_pu16img[i] & 0x00FF); // Least-Significant Byte
    }
}















