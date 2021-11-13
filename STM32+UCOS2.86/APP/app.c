#include "includes.h"

void Task_LED(void *p_arg)
{
	(void)p_arg;
	while(1)
	{
		GPIO_ResetBits(GPIOF,GPIO_Pin_6);
		OSTimeDlyHMSM(0,0,0,500);
		GPIO_SetBits(GPIOF,GPIO_Pin_6);
		
//		GPIO_ResetBits(GPIOF,GPIO_Pin_6);
		OSTimeDlyHMSM(0,0,0,500);
//		GPIO_SetBits(GPIOF,GPIO_Pin_6);
		
//		GPIO_ResetBits(GPIOF,GPIO_Pin_6);
//		OSTimeDlyHMSM(0,0,0,500);
//		GPIO_SetBits(GPIOF,GPIO_Pin_6);
	}
}
