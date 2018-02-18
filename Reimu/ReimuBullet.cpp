//ReimuBullet.cpp
//弹幕相关函数

#include"ReimuHeadFile.h"
#include"ReimuDatasheet.h"

extern SysTime sysTime;

Bullet::Bullet
(
	const Location b_,
	const int r_,
	const double angle_,
	void(*trail_)
		(
		const int time,								//时间
		Location &bulletLocation,					//弹幕坐标位置
		const Location bulletInitialLocation,		//弹幕坐标初始位置
		const Location selfLocation,				//自机位置
		const double angle							//初始角度
		)
	,
	int color_,
	unsigned long startTime_
)
{
	//赋值
	initialLocate = b_;
	r = r_;
	angle = angle_;
	trail = trail_;
	color = color_;
	startTime = startTime_;
}

void Bullet::fresh()
{
	if (startTime <= sysTime.now())
	{
		//计算自然坐标
		Location temp;
		trail(time.now()-startTime, this->locate,this->initialLocate, self.pointLocate(),this->angle);
		//绘制弹幕
		setlinecolor(WHITE);
		setfillcolor(color);
		fillcircle(locate.x, locate.y, r);
		setfillcolor(WHITE);
		//自机判定
		//计算全局坐标位置插值
		deltaLocate =
		{
			locate.x - self.pointLocate().x,
			locate.y - self.pointLocate().y
		};
		if (
			//短路计算快速过滤明显不会碰撞的弹幕
			deltaLocate.x < SAFE_DISTANCE&&
			deltaLocate.x > -1 * SAFE_DISTANCE&&
			deltaLocate.y < SAFE_DISTANCE&&
			deltaLocate.y > -1 * SAFE_DISTANCE&&
			//临近弹幕计算距离判定
			deltaLocate.x*deltaLocate.x + deltaLocate.y * deltaLocate.y <= r * r
			)
		{
			//碰撞判定
			self.leastPlayer--;
		}
	}
	//恢复为7秒前的状态（for demo）
	if (time.now() > 7000)
	{
		time.start();
	}
}

void Bullet::initialization
(
	const Location b_,
	const int r_,
	const double angle_,
	void(*trail_)
		(
		const int time,								//时间
		Location &bulletLocation,					//弹幕坐标位置
		const Location bulletInitialLocation,		//弹幕坐标初始位置
		const Location selfLocation,				//自机位置
		const double angle							//初始角度
		),
	int color_,
	unsigned long startTime_
)
{
	initialLocate = b_;
	r = r_;
	angle = angle_;
	trail = trail_;
	color = color_;
	startTime = startTime_;
}
