/****************************************************************/
/*   Author             :    AHMED Tarek Mansour			    */
/*	 Date 				:   26/1/2021							*/
/*	 Version 			:    1.0V 							 	*/
/*	 Description 		:   									*/
/*									 [interface.h]			    */
/****************************************************************/

/****************************************************************/
/* Description   : Guard to protect this File from include more */
/*                 than one time .                              */
/****************************************************************/



#ifndef _TFT_INTERFACE_H
#define _TFT_INTERFACE_H

void HTFT_voidInit(void);
void HTFT_voidDisplayImage(const u16 * Copy_Image);
void HTFT_voidFillBackground(u16 color);
void TFT_vSetXPos(u16 xStart, u16 xEnd);
void TFT_vSetYPos(u16 yStart, u16 yEnd);
void TFT_vFillRectangle(u16 Color);
void TFT_vletter(u16 A_pu16img[],u32 No_pixels );


#endif /** !comment  :  End of guard                            **/ 
