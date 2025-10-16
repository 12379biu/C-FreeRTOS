#include "my_task.h"

/* �������Ը�ֵ */
TaskBase::TaskBase (const char * const Name,const uint16_t Size,UBaseType_t Pri, void *arg):
pcName(Name),Task_Size(Size),Priority(Pri),Handler(NULL),task_arg(arg)
{
    xTaskCreate(App,pcName,Task_Size,this,Priority,&Handler);
}

/* ��������Ա�����ô��麯�� */
void TaskBase::App(void *arg)
{
    TaskBase *p = static_cast<TaskBase*>(arg);
    p->task(p->task_arg);
}

 /* ɾ������ */
void TaskBase::vdelete()
{
    if (Handler != NULL)
    {
        vTaskDelete(Handler);
        Handler = NULL;
    }
}

//��ȡ��ˮλֵ
unsigned portBASE_TYPE TaskBase::uxGetWater()
{
	return uxTaskGetStackHighWaterMark(getHandle());
}

//��������
void TaskBase::vSuspend()
{
	vTaskSuspend(getHandle());
}

//�ָ�����
void TaskBase::vResume()
{
	//���ڹ���̬����ָ�
	if (eGetState() == eSuspended)
		vTaskResume(getHandle());
}

//״̬��ѯ
eTaskState TaskBase::eGetState()
{
	return eTaskGetState(getHandle());
}
/*------------------------------------------------------------------*/
/* end------------------------------------------------------------------ */
