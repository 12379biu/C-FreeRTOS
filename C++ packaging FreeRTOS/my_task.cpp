#include "my_task.h"

/* 任务属性赋值 */
TaskBase::TaskBase (const char * const Name,const uint16_t Size,UBaseType_t Pri, void *arg):
pcName(Name),Task_Size(Size),Priority(Pri),Handler(NULL),task_arg(arg)
{
    xTaskCreate(App,pcName,Task_Size,this,Priority,&Handler);
}

/* 任务函数成员，调用纯虚函数 */
void TaskBase::App(void *arg)
{
    TaskBase *p = static_cast<TaskBase*>(arg);
    p->task(p->task_arg);
}

 /* 删除任务 */
void TaskBase::vdelete()
{
    if (Handler != NULL)
    {
        vTaskDelete(Handler);
        Handler = NULL;
    }
}

//获取高水位值
unsigned portBASE_TYPE TaskBase::uxGetWater()
{
	return uxTaskGetStackHighWaterMark(getHandle());
}

//挂起任务
void TaskBase::vSuspend()
{
	vTaskSuspend(getHandle());
}

//恢复任务
void TaskBase::vResume()
{
	//处于挂起态，则恢复
	if (eGetState() == eSuspended)
		vTaskResume(getHandle());
}

//状态查询
eTaskState TaskBase::eGetState()
{
	return eTaskGetState(getHandle());
}
/*------------------------------------------------------------------*/
/* end------------------------------------------------------------------ */
