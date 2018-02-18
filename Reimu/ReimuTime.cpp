//ReimuTime.cpp
//时间相关函数

#include"ReimuHeadFile.h"

//开始计时
void SysTime::start()
{
	startTime = clock();
}
//获取当前时间
//返回unsigned long类型的毫秒数
unsigned long SysTime::now()
{
	endTime = clock();
	return (endTime - startTime) * 1000 / CLOCKS_PER_SEC;
}