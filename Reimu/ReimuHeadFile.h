#pragma once
//提供全局定义
#include<graphics.h>
#include<conio.h>
#include<ctime>

//#include"Reimu_time.h"
//时间系统
class SysTime
{
private:
	clock_t startTime;
	clock_t endTime;
public:
	//开始计时
	//游戏开始时调用一次
	void start();
	//获取当前时间
	//返回unsigned long类型的毫秒数
	unsigned long now();
}sysGlobalTime;//宏观时间（游戏计时）

