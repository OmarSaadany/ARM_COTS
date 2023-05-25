#include       "Std_Types.h"
#include       "Bit_Math.h"
#include       "delay.h"
#include       "RCC_interface.h"
#include       "DIO_interface.h"
#include       "NVIC_interface.h"
#include       "UART_interface.h"
#include       "EXTI_interface.h"
#include       "ESP_interface.h"
#include       "BUTTON.h"
#include       "KEYPAD.h"
#include       "LCD4BIT.h"
#include       "LED.h"

volatile u8 data[7] = {0};
volatile u8 data1[7]={0};
volatile u8 data2[60]={0};
volatile u8 data2_2[60]={0};

volatile u8 data3[30]={0};
volatile u8 data3_3[30]={0};
volatile u8 data4[10]={0};
volatile u8 data5[20]={0};
volatile u8 data51[25]={0};

void WIFI_init(void){
	u8 i = 0;
	u8 Dummy = 0;

	do{
	  i = 0;
	  Dummy = 0;
	  _delay_ms(1000);
	  UART1_voidSendString("ATE0\r\n");
	     while(Dummy != 255){
		        Dummy = UART_RXdata() ;
				data[i] = Dummy;
				i++;
	            }
	if(data[2]== 'O' && data[3]=='K'){
	    break;
	    }
	}while(Dummy==255) ;


	do{
	  _delay_ms(1000);
	  UART1_voidSendString("AT+CWMODE=1\r\n");
	  i = 0;
	  Dummy = 0;
	  while(Dummy != 255){
		Dummy = UART_RXdata() ;
		data1[i] = Dummy;
		i++;
	    }
	if(data1[2]== 'O' && data1[3]=='K'){
	   	 break;
	    }
	}while(Dummy==255);
}

void WIFI_connect(){
	u8 i = 0;
	u8 Dummy = 0;

	do{
	    _delay_ms(1000);
		UART1_voidSendString("AT+CWJAP_CUR=\"Amr\",\"elengahmed98\"\r\n");
	    i = 0;
		Dummy = 0;
		while(Dummy != 255){
			Dummy = UART_RXdata() ;
		    data2[i] = Dummy;
		    i++;
		    }
		_delay_ms(100) ;
		i = 0;
		Dummy = 0;
		while(Dummy != 255){
		     Dummy = UART_RXdata() ;
		     data2_2[i] = Dummy;
		     i++;
		     }
		_delay_ms(1000);
	 if(data2[13]== 'W' && data2[14]== 'I'  && data2[15]== 'F'  && data2[16]== 'I'  && data2[17]== ' ' && data2[18]== 'C' && data2[19]== 'O' && data2[20]== 'N'  && data2[21]== 'N' && data2[22]== 'E' && data2[23]== 'C'  && data2[24]== 'T' && data2[25]== 'E' && data2[26]== 'D'  )
	 {
	   break;
	 }else if(data2_2[0]== 'W' && data2_2[1]== 'I'  && data2_2[2]== 'F'  && data2_2[3]== 'I'  && data2_2[4]== ' ' && data2_2[5]== 'C' && data2_2[6]== 'O' && data2_2[7]== 'N'  && data2_2[8]== 'N' && data2_2[9]== 'E' && data2_2[10]== 'C'  && data2_2[11]== 'T' && data2_2[12]== 'E' && data2_2[13]== 'D' )
	 {
		 break;
	 }
	}while(Dummy==255);
}

void  WIFI_connectServer(void) {
	u8 i = 0;
	u8 Dummy = 0;

	do{
    _delay_ms(1000);
    UART1_voidSendString("AT+CIPSTART=\"TCP\",\"23.179.32.37\",80\r\n");
    i = 0;
    Dummy = 0;
    while(Dummy != 255){
  	   Dummy = UART_RXdata() ;
       data3[i] = Dummy;
       i++;
       }
     i = 0;
     Dummy = 0;
     while(Dummy != 255){
     Dummy = UART_RXdata() ;
     data3_3[i] = Dummy;
     i++;
     }
if(data3[1]== 'C' && data3[2]== 'O' && data3[3]== 'N'  && data3[4]== 'N' && data3[5]== 'E' && data3[6]== 'C'  && data3[7]== 'T' ){
   break ;
   }else if(data3[0]== 'A' && data3[1]== 'L' && data3[2]== 'R'  && data3[3]== 'E' && data3[4]== 'A' && data3[5]== 'D'  && data3[6]== 'Y' ){
	   break ;
	   }
}while(Dummy==255);



do{
	_delay_ms(1000);
    UART1_voidSendString("AT+CIPSEND=46\r\n");
    i = 0;
    Dummy = 0;
    while(Dummy != 255){
	     Dummy = UART_RXdata() ;
		 data4[i] = Dummy;
		 i++;
         }
if(data1[2]== 'O' && data1[3]=='K'){
 	 break;
  }
}while(Dummy==255);
}

u8 WIFI_GETvalue(void){
	u8 i = 0;
	u8 Dummy = 0;

	do{
		_delay_ms(1000);
	    UART1_voidSendString("GET http://doorlocker.freevar.com/status.txt\r\n");
	    i = 0;
	    Dummy = 0;
	    while(Dummy != 255){
		Dummy = UART_RXdata() ;
		data5[i] = Dummy;
		i++;
	    }
	    i = 0;
	    Dummy = 0;

	    while(Dummy != 255){
		Dummy = UART_RXdata() ;
		data51[i] = Dummy;
		i++;
	}
	    i = 0;
	    Dummy = 0;
if(data51[10]== '+' && data51[11]=='I'  && data51[12]=='P'  && data51[13]== 'D' && data51[14]== ',' && data51[15]=='1' && data51[16]== ':')
{
	    	 	 break;
	    	  	}

	}while(Dummy==255);

	return data51[17] ;
}

int main(void)
{

	u8 Data = 255 ;




    RCC_voidSysClkInt();
	RCC_voidEnablePerClk(RCC_APB2,2); //porta
	RCC_voidEnablePerClk(RCC_APB2,0);//AF
	RCC_voidEnablePerClk(RCC_APB2,14);//uart1


	DIO_voidSetPinDirection(PORTA ,PIN9, GPIO_OUTPUT_2MHZ_AFPP);
	DIO_voidSetPinDirection(PORTA ,PIN10,GPIO_INPUT_FLOAT );
    LED_init(PORTA, PIN0) ;
    LED_init(PORTA, PIN1) ;
	UART_init() ;
	UART_enableTX();
	UART_enableRX() ;


	WIFI_init() ;
	WIFI_connect();


while (1) {

	WIFI_connectServer();
	Data=WIFI_GETvalue();

	if(Data !=255){
		if (Data=='1'){
			LED_on(PORTA, PIN0) ;
			LED_off(PORTA, PIN1) ;
		}else{
			LED_off(PORTA, PIN0) ;
			LED_on(PORTA, PIN1) ;
		}
	}

	Data=255 ;

}
return 0 ;
}
