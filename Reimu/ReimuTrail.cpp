//ReimuTrail.cpp
//轨迹相关函数

#include"ReimuDatasheet.h"
#include"ReimuHeadFile.h"

void trail_line
(
	const int time,									//时间
	Location &bulletLocation,					//弹幕坐标位置
	const Location bulletInitialLocation,		//弹幕坐标初始位置
	const Location selfLocation,				//自机位置
	const double angle							//初始角度
)
{
	bulletLocation =
	{
		time / BULLET_BASE_SPEED,
		0
	};
	//转化为全局坐标
	bulletLocation =
	{
		static_cast<int>(bulletInitialLocation.x + bulletLocation.x*cos(angle) - bulletLocation.y*sin(angle)),
		static_cast<int>(bulletInitialLocation.y + bulletLocation.x*sin(angle) + bulletLocation.y*cos(angle))
	};

}
void trail_sin
(
	const int time,									//时间
	Location &bulletLocation,					//弹幕坐标位置
	const Location bulletInitialLocation,		//弹幕坐标初始位置
	const Location selfLocation,				//自机位置
	const double angle							//初始角度
)
{
	bulletLocation =
	{
		time / BULLET_BASE_SPEED,
		static_cast<int>(10 * sin(time / (ANGLE_BASE_DIVISOR/100 * BULLET_BASE_SPEED)))
	};
	//转化为全局坐标
	bulletLocation =
	{
		static_cast<int>(bulletInitialLocation.x + bulletLocation.x*cos(angle) - bulletLocation.y*sin(angle)),
		static_cast<int>(bulletInitialLocation.y + bulletLocation.x*sin(angle) + bulletLocation.y*cos(angle))
	};

}
void trail_circle_0
(
	const int time,									//时间
	Location &bulletLocation,					//弹幕坐标位置
	const Location bulletInitialLocation,		//弹幕坐标初始位置
	const Location selfLocation,				//自机位置
	const double angle							//初始角度
)
{
	bulletLocation =
	{
		static_cast<int>(time*sin(time / ANGLE_BASE_DIVISOR) / BULLET_BASE_SPEED),
		static_cast<int>(time*cos(time / ANGLE_BASE_DIVISOR) / BULLET_BASE_SPEED)
	};
	//转化为全局坐标
	bulletLocation =
	{
		static_cast<int>(bulletInitialLocation.x + bulletLocation.x*cos(angle) - bulletLocation.y*sin(angle)),
		static_cast<int>(bulletInitialLocation.y + bulletLocation.x*sin(angle) + bulletLocation.y*cos(angle))
	};

}
void trail_circle_1
(
	const int time,									//时间
	Location &bulletLocation,					//弹幕坐标位置
	const Location bulletInitialLocation,		//弹幕坐标初始位置
	const Location selfLocation,				//自机位置
	const double angle							//初始角度
)

{
	bulletLocation =
	{
		static_cast<int>(time*sin(time / ANGLE_BASE_DIVISOR) / BULLET_BASE_SPEED),
		static_cast<int>(-time * cos(time / ANGLE_BASE_DIVISOR) / BULLET_BASE_SPEED)
	};
	//转化为全局坐标
	bulletLocation =
	{
		static_cast<int>(bulletInitialLocation.x + bulletLocation.x*cos(angle) - bulletLocation.y*sin(angle)),
		static_cast<int>(bulletInitialLocation.y + bulletLocation.x*sin(angle) + bulletLocation.y*cos(angle))
	};
}
void trail_circle_2
(
	const int time,									//时间
	Location &bulletLocation,					//弹幕坐标位置
	const Location bulletInitialLocation,		//弹幕坐标初始位置
	const Location selfLocation,				//自机位置
	const double angle							//初始角度
)

{
	bulletLocation =
	{
		static_cast<int>(time*sin(time / ANGLE_BASE_DIVISOR) / 2 / BULLET_BASE_SPEED),
		static_cast<int>(time * cos(time / ANGLE_BASE_DIVISOR) / BULLET_BASE_SPEED)
	};
	//转化为全局坐标
	bulletLocation =
	{
		static_cast<int>(bulletInitialLocation.x + bulletLocation.x*cos(angle) - bulletLocation.y*sin(angle)),
		static_cast<int>(bulletInitialLocation.y + bulletLocation.x*sin(angle) + bulletLocation.y*cos(angle))
	};

}
void trail_circle_3
(
	const int time,									//时间
	Location &bulletLocation,					//弹幕坐标位置
	const Location bulletInitialLocation,		//弹幕坐标初始位置
	const Location selfLocation,				//自机位置
	const double angle							//初始角度
)
{
	bulletLocation =
	{
		static_cast<int>(time*sin(time / ANGLE_BASE_DIVISOR) / BULLET_BASE_SPEED),
		static_cast<int>(-time * cos(time / ANGLE_BASE_DIVISOR) / 2 / BULLET_BASE_SPEED)
	};
	//转化为全局坐标
	bulletLocation =
	{
		static_cast<int>(bulletInitialLocation.x + bulletLocation.x*cos(angle) - bulletLocation.y*sin(angle)),
		static_cast<int>(bulletInitialLocation.y + bulletLocation.x*sin(angle) + bulletLocation.y*cos(angle))
	};

}
void trail_stop
(
	const int time,									//时间
	Location &bulletLocation,					//弹幕坐标位置
	const Location bulletInitialLocation,		//弹幕坐标初始位置
	const Location selfLocation,				//自机位置
	const double angle							//初始角度
)
{
	bulletLocation = 
	{
		0,
		0 
	};
	//转化为全局坐标
	bulletLocation =
	{
		static_cast<int>(bulletInitialLocation.x + bulletLocation.x*cos(angle) - bulletLocation.y*sin(angle)),
		static_cast<int>(bulletInitialLocation.y + bulletLocation.x*sin(angle) + bulletLocation.y*cos(angle))
	};

}
void trail_follow
(
	const int time,									//时间
	Location &bulletLocation,					//弹幕坐标位置
	const Location bulletInitialLocation,		//弹幕坐标初始位置
	const Location selfLocation,				//自机位置
	const double angle							//初始角度
)
{
	//Todo..
	;
}
