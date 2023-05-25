
#include "UART_interface.h"

u8 ESP_ValidateCmd(void)
{
	u8 Local_Response[100] = {0};
	u8 i = 0;
	u8 Dummy = 0;
	u8 Result = 0;

	while (Dummy != 255)
	{
		Dummy= UART_RXdata();
		Local_Response[i] = Dummy;
		i++;
	}

	/* Check if Ok */
	if (Local_Response[0] == 'O' && Local_Response[1] == 'K')
	{
		Result = 1;
	}

	else if (Local_Response[0] == 'W' && Local_Response[1] == 'I' && Local_Response[2] == 'F' && Local_Response[3] == 'I' && Local_Response[4] == ' ' && Local_Response[5] == 'C' && Local_Response[6] == 'O' && Local_Response[7] == 'N' && Local_Response[8] == 'N' && Local_Response[9] == 'E' && Local_Response[10] == 'C' && Local_Response[11] == 'T' && Local_Response[12] == 'E' && Local_Response[13] == 'D' )
	{
		Result = 1;
	}
	else if (Local_Response[0] == 'C' && Local_Response[1] == 'O' && Local_Response[2] == 'N' && Local_Response[3] == 'N' && Local_Response[4] == 'E' && Local_Response[5] == 'C' && Local_Response[6] == 'T' )
	{
		Result = 1;
	}

	return Result;
}




void ESP_voidInit(void)
{
	u8 Local_Result = 0;

	while(Local_Result == 0)
	{
		/* Stop ECHO */
		UART1_voidSendString("ATE0\r\n");
		Local_Result = ESP_ValidateCmd();
	}

	Local_Result = 0;

	while(Local_Result == 0)
	{
		/* Set station mode */
		UART1_voidSendString("AT+CWMODE=1\r\n");
		Local_Result = ESP_ValidateCmd();
	}
}

void ESP_ConnectWiFi(void)
{
	u8 Local_Result = 0 ;

	while(Local_Result==0 ){
    UART1_voidSendString("AT+CWJAP_CUR=\"Amr\",\"elengahmed98\"\r\n");
	Local_Result = ESP_ValidateCmd();

	}

}

void  ESP_ConnectServer(void){

	u8 Local_Result = 0 ;

	while(Local_Result==0 ){
    UART1_voidSendString("AT+CIPSTART=\"TCP\",\"23.179.32.37\",80 \r\n");
	Local_Result = ESP_ValidateCmd();

	}


}

void  ESP_send(void){
	u8 Local = 0 ;
	u8 Local_Result = 0 ;

	while(Local_Result==0 ){
    UART1_voidSendString("AT+CIPSEND=46");
	Local_Result = ESP_ValidateCmd();

	}

	Local_Result = 0 ;

	while(Local_Result==0 ){
    UART1_voidSendString("GET http://doorlocker.freevar.com/status.txt");
	Local_Result = ESP_ValidateCmd();

	}

	Local= UART_RXdata() ;
}

u8  ESP_CMD2MC(void ) {
	u8 Local_Response[100] = {0};

	u8 i = 0;
	u8 Dummy = 0;
	u8 Result = 0;

	while (Dummy != 255)
	{
		Dummy= UART_RXdata() ;
		Local_Response[i] = Dummy;
		i++;
	}
if (Local_Response[0] == '+' && Local_Response[1] == 'I'  && Local_Response[2] == 'P'   && Local_Response[3] == 'D'  && Local_Response[4] == ','  && Local_Response[5] == '1'  && Local_Response[6] == ':' )
	{
		Result = Local_Response[7] ;
	}
	return Result ;
}


