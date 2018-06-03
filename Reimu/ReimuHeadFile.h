//ReimuHeadFile.h
#pragma once
//提供全局定义
#include<graphics.h>
#include<conio.h>
#include<ctime>
#include<cmath>
#include<fstream>
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
	long now();
};

//坐标
struct Location
{
	int x;
	int y;
};

//背景
void backGroundInitialize(IMAGE * backGround);
void backGroundDraw(IMAGE * backGround);

//自机
class Self
{
private:
	int speed;			//移动速度
	IMAGE selfimage[3];	//自机图像
	IMAGE State;		//当前自机图像
public:
	Location location;	//图像位置（绘图原点）
	Location pictureSize;	//图像尺寸
	int leastPlayer = 1;	//残机数
	int lastBoom = 1;		//剩余B点
	Self();
	void Moveself();	//自身移动
	Location pointLocate();	//返回判定点坐标
	int getLastBoom();		//返回剩余B点
};

//游戏开场动画
int gameLeader();
//游戏结束胜负判定函数
void gameEnding(Self * self);

extern Self self;

//静止弹幕（默认值用）
void trail_stop
(
	const int time,									//时间
	Location &bulletLocation,					//弹幕坐标位置
	const Location bulletInitialLocation,		//弹幕坐标初始位置
	const Location selfLocation,				//自机位置
	const double angle							//初始角度
);	//时间，自机坐标，弹幕坐标

class BulletNode;

//弹幕

class Bullet
{
private:
	Location initialLocate;	//初始位置
	Location deltaLocate;	//距离差
	int r;			//弹幕半径
	double angle;	//绘制角度
	void(*trail)
		(
		const int time,									//时间
		Location &bulletLocation,					//弹幕坐标位置
		const Location bulletInitialLocation,		//弹幕坐标初始位置
		const Location selfLocation,				//自机位置
		const double angle							//初始角度
		)
		;//路径样式
	int color;		//颜色
	long startTime;	//生成时间
public:
	Location locate;	//坐标位置

	Bullet			//默认值
	(
		Location b_ = { 100,100 },
		int r_ = 5,
		double angle_ = 0,
		void(*trail_)
			(
			const int time,								//时间
			Location &bulletLocation,					//弹幕坐标位置
			const Location bulletInitialLocation,		//弹幕坐标初始位置
			const Location selfLocation,				//自机位置
			const double angle							//初始角度
			)
		= trail_stop,
		int color_ = WHITE,
		long startTime_ = 0	//出现时间
	);

	//初始化弹幕
	void initialization
	(
		Location b_ = { 100,100 },
		int r_ = 5,
		double angle_ = 0,
		void(*trail_)
			(
			const int time,									//时间
			Location &bulletLocation,					//弹幕坐标位置
			const Location bulletInitialLocation,		//弹幕坐标初始位置
			const Location selfLocation,				//自机位置
			const double angle							//初始角度
			)
		= trail_stop,
		int color_ = WHITE,
		long  startTime_ = 0
	);
	//刷新弹幕&碰撞判定
	void fresh(BulletNode * headBulletNode);
};

class BulVector :public Bullet
{

};

//弹幕链系统
class BulletNode
{
public:
	Bullet * bullet;
	class BulletNode * prev;
	class BulletNode * next;
	bool isEmpty();
};

//往弹幕链中压入新弹幕
void pushBullet(BulletNode * const headBulletNode, Bullet * const bullet);
//从弹幕链中弹出弹幕
void popBullet(BulletNode *const headBulletNode, Bullet * const bullet);
//刷新（绘制）弹幕链
void freshBulletLink(BulletNode * headBulletNode);
//清空弹幕链
void emptyBulletLink(BulletNode *const headBulletNode);

//从文件读入弹幕信息
void ReimuLeadinFromFile(BulletNode * headBulletNode, char * fileName);

//弹幕轨迹函数

//直线轨迹
void trail_line
(
	const int time,									//时间
	Location &bulletLocation,					//弹幕坐标位置
	const Location bulletInitialLocation,		//弹幕坐标初始位置
	const Location selfLocation,				//自机位置
	const double angle							//初始角度
);
//蛇形轨迹
void trail_sin
(
	const int time,									//时间
	Location &bulletLocation,					//弹幕坐标位置
	const Location bulletInitialLocation,		//弹幕坐标初始位置
	const Location selfLocation,				//自机位置
	const double angle							//初始角度
);

//圆形轨迹(逆时针)
void trail_circle_0
(
	const int time,									//时间
	Location &bulletLocation,					//弹幕坐标位置
	const Location bulletInitialLocation,		//弹幕坐标初始位置
	const Location selfLocation,				//自机位置
	const double angle							//初始角度
);

//圆形轨迹(顺时针)
void trail_circle_1
(
	const int time,									//时间
	Location &bulletLocation,					//弹幕坐标位置
	const Location bulletInitialLocation,		//弹幕坐标初始位置
	const Location selfLocation,				//自机位置
	const double angle							//初始角度
);
//圆形巡回轨迹(逆时针)
void trail_circle_2
(
	const int time,									//时间
	Location &bulletLocation,					//弹幕坐标位置
	const Location bulletInitialLocation,		//弹幕坐标初始位置
	const Location selfLocation,				//自机位置
	const double angle							//初始角度
);
//圆形巡回轨迹(顺时针)
void trail_circle_3
(
	const int time,									//时间
	Location &bulletLocation,					//弹幕坐标位置
	const Location bulletInitialLocation,		//弹幕坐标初始位置
	const Location selfLocation,				//自机位置
	const double angle							//初始角度
);
//追踪弹幕轨迹
void trail_follow
(
	const int time,									//时间
	Location &bulletLocation,					//弹幕坐标位置
	const Location bulletInitialLocation,		//弹幕坐标初始位置
	const Location selfLocation,				//自机位置
	const double angle							//初始角度
);		//Tips:追踪弹幕请在初始化时角度全部设为0；
