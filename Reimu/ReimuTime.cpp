//ReimuTime.cpp
//ʱ����غ���

#include"ReimuHeadFile.h"

//��ʼ��ʱ
void SysTime::start()
{
	startTime = clock();
}
//��ȡ��ǰʱ��
//����unsigned long���͵ĺ�����
unsigned long SysTime::now()
{
	endTime = clock();
	return (endTime - startTime) * 1000 / CLOCKS_PER_SEC;
}