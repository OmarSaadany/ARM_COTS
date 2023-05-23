/*
 * SSD_int.h
 *
 *  Created on: Feb 15, 2023
 *      Author: e
 */

#include "STD_TYPES.h"

#ifndef _02_HAL_SSD_SSD_INT_H_
#define _02_HAL_SSD_SSD_INT_H_

#define COM_CATHODE    1
#define COM_ANODE      0



#define SSD_TYPE   COM_CATHODE




void SSD_vInit(u8 A_u8SSDPort, u8 startPin, u8 endPin);
void SSD_vDisplayNum(u8 A_u8SSDPort, u8 startPin, u8 A_u8Num);
void SSD_vTurnOff(u8 A_u8SSDPort,u8 startPin);




#endif /* 02_HAL_SSD_SSD_INT_H_ */


