//ReimuHeadFile.h
#pragma once
//提供全局定义
#include<graphics.h>
#include<conio.h>
#include<ctime>
#include<cmath>
#include"ReimuDatasheet.h"

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
	int speed;			//移动速度
	IMAGE selfimage[3];	//自机图像
	IMAGE State;		//当前自机图像

	//int x, y;			//图像位置的旧版本，不再建议使用
	//int w, h;			//图像尺寸的旧版本，不再建议使用
public:
	Location location;	//图像位置（绘图原点）
	Location pictureSize;	//图像尺寸
	int leastPlayer = 1;	//残机数
	Self();
	//void set();	//绘制
	void Moveself();	//自身移动
	Location pointLocate();	//返回判定点坐标

	//int ValueofX();	//不建议启用，请使用locate函数
	//int ValueofY();	//不建议启用，请使用locate函数
	//int SelfpointX();	//不建议启用，请使用pointLocate函数
	//int SelfpointY();	//不建议启用，请使用pointLocate函数
	//Location locate();	//返回图像坐标
};

extern Self self;

//静止弹幕（默认值用）
//void trail_stop(const int t, int &x, int &y);

void trail_stop(const int t, Location &s, Location &b);	//时间，自机坐标，弹幕坐标

//弹幕

class Bullet
{
private:
	Location initialLocate;	//初始位置
	Location deltaLocate;	//距离差

	////待替换，不再推荐使用
	//int x;			//初始位置:X
	//int y;			//初始位置:y
	//int nowx = 0;	//坐标位置:x'
	//int nowy = 0;	//坐标位置:y'
	//int delta_x;	//弹幕自机距离差:x
	//int delta_y;	//弹幕自机距离差:y
	////待替换，不再推荐使用

	int r;			//弹幕半径
	double angle;	//绘制角度
	void(*trail)(int, Location&, Location&);//路径样式
	SysTime time;	//时间
	int color;		//颜色
public:
	Location locate;	//坐标位置

	Bullet(			//默认值
		const Location b_ = { 100,100 },
		const int r_ = 5,
		const double angle_ = 0,
		void(*trail_)(int, Location&, Location&) = trail_stop,
		int color_ = WHITE
	);

	//初始化弹幕
	void initialization
	(
		const Location b_ = { 100,100 },
		const int r_ = 5,
		const double angle_ = 0,
		void(*trail_)(int, Location&, Location&) = trail_stop,
		int color_ = WHITE
		);
	//刷新弹幕&碰撞判定
	void fresh();
};


//弹幕轨迹函数

//直线轨迹
//void trail_line(const int t, int& x, int& y);
void trail_line(const int t, Location &s, Location &b);
//蛇形轨迹
//void trail_sin(const int t, int& x, int& y);
void trail_sin(const int t, Location &s, Location &b);
//圆形轨迹(逆时针)
//void trail_circle_0(const int t, int &x, int &y);
void trail_circle_0(const int t, Location &s, Location &b);
//圆形轨迹(顺时针)
//void trail_circle_1(const int t, int &x, int &y);
void trail_circle_1(const int t, Location &s, Location &b);
//圆形巡回轨迹(逆时针)
//void trail_circle_2(const int t, int &x, int &y);
void trail_circle_2(const int t, Location &s, Location &b);
//圆形巡回轨迹(顺时针)
//void trail_circle_3(const int t, int &x, int &y);
void trail_circle_3(const int t, Location &s, Location &b);
//追踪弹幕轨迹
//void trail_follow(const int t, int &x, int &y);		//Tips:追踪弹幕请在初始化时角度全部设为0；
void trail_follow(const int t, Location &s, Location &b);		//Tips:追踪弹幕请在初始化时角度全部设为0；
