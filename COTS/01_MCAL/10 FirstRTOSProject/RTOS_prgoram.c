
#include "RTOS_interface.h"




void scheduler(void){
	for(u8 i = 0 ; i < 3 ; i ++){
		arroftask[i].PTR() ;
	}

}

void creat_task (u8 pariortynum ,u8 per , void (*ptr)(void) ){
	arroftask[pariortynum].period = per ;
	arroftask[pariortynum].PTR = ptr ;
}

void start (void ) {
	STK_voidSetIntervalSingle(10000 , scheduler) ;

}
