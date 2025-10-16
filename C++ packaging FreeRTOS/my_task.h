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
/* �������Զ��� */
	const char * const pcName;
	const uint16_t Task_Size;
	UBaseType_t Priority;
	TaskHandle_t Handler;
	void *task_arg;

public:
	void vdelete(); /* ɾ������ */
	void vSuspend();//��������
	void vResume();//�ָ�����
	eTaskState eGetState();//״̬��ѯ
	static void App(void *arg);
	virtual void task(void *arg) = 0;//����������
	unsigned portBASE_TYPE uxGetWater();//��ȡ��ˮλֵ
	TaskHandle_t getHandle(){return Handler;}/* ��ȡ��� */
	TaskBase (const char * const Name,const uint16_t Size,UBaseType_t Pri, void *arg = NULL);
};
	

#ifdef __cplusplus
}

#endif
#endif
