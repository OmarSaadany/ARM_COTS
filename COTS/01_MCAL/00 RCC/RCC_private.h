#ifndef		RCC_PRIVATE_H
#define		RCC_PRIVATE_H

#define		RCC_BASE_ADD		(0x40021000)

#define		RCC_CR				*((u32 *)(RCC_BASE_ADD+0x00))
#define		RCC_CFGR			*((u32 *)(RCC_BASE_ADD+0x04))
#define		RCC_CIR				*((u32 *)(RCC_BASE_ADD+0x08))
#define		RCC_APB2RSTR		*((u32 *)(RCC_BASE_ADD+0x0C))
#define		RCC_APB1RSTR		*((u32 *)(RCC_BASE_ADD+0x10))
#define		RCC_AHBENR			*((u32 *)(RCC_BASE_ADD+0x14))
#define		RCC_APB2ENR			*((u32 *)(RCC_BASE_ADD+0x18))
#define		RCC_APB1ENR			*((u32 *)(RCC_BASE_ADD+0x1C))
#define		RCC_BDCR			*((u32 *)(RCC_BASE_ADD+0x20))
#define		RCC_CSR				*((u32 *)(RCC_BASE_ADD+0x24))



#define		sysClkSelect_HSE			1
#define     sysClkSelect_HSI			2
#define     sysClkSelect_PLL			3

#define		SYSCLK_divided_1			1
#define     SYSCLK_divided_2			2
#define     SYSCLK_divided_4			3
#define		SYSCLK_divided_8			4
#define     SYSCLK_divided_16			5
#define     SYSCLK_divided_64			6
#define		SYSCLK_divided_128			7
#define     SYSCLK_divided_256			8
#define     SYSCLK_divided_512			9

#define		HCLK_divided_1			1
#define     HCLK_divided_2			2
#define     HCLK_divided_4			3
#define		HCLK_divided_8			4
#define     HCLK_divided_16			5
#define     HCLK_divided_6			6

#define		HSI_divided_2			1
#define     HSE						2

#define		HSE_NODivided			1
#define     HSE_divided_2			2

#define		PLL_input_x4			1
#define     PLL_input_x5			2
#define     PLL_input_x6			3
#define		PLL_input_x7			4
#define     PLL_input_x8			5
#define     PLL_input_x9			6


#define		sysClk_HSE			1
#define     sysClk_HSI			2
#define     sysClk_PLL			3

#define		sysState_HSE			1
#define     sysState_HSI			2
#define     sysState_PLL			3

#define		BYB_ON			1
#define     BYB_Off			2


#define		CSS_ON			1
#define     CSS_Off			2
#endif
