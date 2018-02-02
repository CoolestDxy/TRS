//ReimuHeadFile.h
#pragma once
//提供全局定义
#include<graphics.h>
#include<conio.h>
#include<ctime>
#include<cmath>

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
};

//坐标
struct Location
{
	int x;
	int y;
};

//自机
class Self
{
private:
	int x, y, speed;
	IMAGE selfimage[3];
	IMAGE State;
	int w, h;
public:
	int leastPlayer;	//残机数
	Self();
	void Draw();	//绘制
	void Moveself();	//自身移动

	int ValueofX();	//不建议启用，请使用locate函数
	int ValueofY();	//不建议启用，请使用locate函数
	int SelfpointX();	//不建议启用，请使用pointLocate函数
	int SelfpointY();	//不建议启用，请使用pointLocate函数

	Location locate();	//返回图像坐标
	Location pointLocate();	//返回判定点坐标
};

extern Self self;

//弹幕

class Bullet
{
private:
	Location locate;	//初始位置
	Location nowLocate;	//坐标位置
	Location deltaLocate;	//距离差

	//待替换，不再推荐使用
	int x;			//初始位置:X
	int y;			//初始位置:y
	int nowx = 0;	//坐标位置:x'
	int nowy = 0;	//坐标位置:y'
	int delta_x;	//弹幕自机距离差:x
	int delta_y;	//弹幕自机距离差:y
					//待替换，不再推荐使用

	int r;			//弹幕半径
	double angle;	//绘制角度
	void(*trail)(int, int&, int&);//路径样式
	SysTime time;	//时间
	int color;		//颜色
public:
	Bullet	//默认值
	(
		const int x_,
		const int y_,
		const int r_,
		const double angle_,
		void(*trail_)(int, int&, int&),
		int color_
	);


	//初始化弹幕
	void initialization
	(
		const int x_,
		const int y_,
		const int r_,
		const double angle_,
		void(*trail_)(int, int&, int&),
		int color_
	);
	//刷新弹幕&碰撞判定
	void fresh();
	Location bulletLocate();	//返回子弹坐标
};

//弹幕轨迹函数

//直线轨迹
void trail_line(const int t, int& x, int& y);
//蛇形轨迹
void trail_sin(const int t, int& x, int& y);
//圆形轨迹(逆时针)
void trail_circle_0(const int t, int &x, int &y);
//圆形轨迹(顺时针)
void trail_circle_1(const int t, int &x, int &y);
//圆形巡回轨迹(逆时针)
void trail_circle_2(const int t, int &x, int &y);
//圆形巡回轨迹(顺时针)
void trail_circle_3(const int t, int &x, int &y);
//静止弹幕（测试用）
void trail_stop(const int t, int &x, int &y);
//追踪弹幕轨迹
void trail_follow(const int t, int &x, int &y);		//Tips:追踪弹幕请在初始化时角度全部设为0；

