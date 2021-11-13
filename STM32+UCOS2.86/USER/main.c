#include "includes.h"




static OS_STK startup_task_stk[STARTUP_TASK_STK_SIZE]; //定义任务堆栈

void LEDInit(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOF, ENABLE);
	/***PF6推挽输出***/
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6|GPIO_Pin_7|GPIO_Pin_8|GPIO_Pin_9;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_Init(GPIOF,&GPIO_InitStructure);
	
	GPIO_SetBits(GPIOF,GPIO_Pin_6|GPIO_Pin_7|GPIO_Pin_8|GPIO_Pin_9);
}


void SysTick_init(void)
{
	SysTick_Config(SystemCoreClock/OS_TICKS_PER_SEC);
}
int main (void)
{
	SysTick_init();
	LEDInit();
	OSInit();
	OSTaskCreate(Task_LED,(void *)0,&startup_task_stk[STARTUP_TASK_STK_SIZE-1],STARTUP_TASK_PRIO);
	OSStart();
	return 0;
}
