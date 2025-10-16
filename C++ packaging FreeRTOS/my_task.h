#ifndef MY_TASK_H
#define MY_TASK_H

#ifdef __cplusplus
extern "C"{
#endif
#include "FreeRTOS.h"
#include "timers.h" 
#include "task.h"
#include "cmsis_os.h"
class TaskBase{
protected:
/* 任务属性定义 */
	const char * const pcName;
	const uint16_t Task_Size;
	UBaseType_t Priority;
	TaskHandle_t Handler;
	void *task_arg;

public:
	void vdelete(); /* 删除任务 */
	void vSuspend();//挂起任务
	void vResume();//恢复任务
	eTaskState eGetState();//状态查询
	static void App(void *arg);
	virtual void task(void *arg) = 0;//纯虚任务函数
	unsigned portBASE_TYPE uxGetWater();//获取高水位值
	TaskHandle_t getHandle(){return Handler;}/* 获取句柄 */
	TaskBase (const char * const Name,const uint16_t Size,UBaseType_t Pri, void *arg = NULL);
};
	

#ifdef __cplusplus
}

#endif
#endif
