
#ifndef RTOS_INTERFACE_H
#define RTOS_INTERFACE_H






typedef  struct {
	u8 period ;
	void (*PTR)(void) ;
}TASK_t;
void creat_task (u8 pariortynum , u8 per,void (*ptr)(void));
void start(void) ;
void scheduler(void) ;
TASK_t arroftask[3] ;




#endif