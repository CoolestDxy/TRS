//ReimuTrail.cpp
//����켣��صĺ���

#include"ReimuDatasheet.h"
#include"ReimuHeadFile.h"

void trail_line(const int t, Location &s, Location &b)
{
	s =
	{
		t / BULLET_BASE_SPEED,
		0
	};
}
void trail_sin(const int t, Location &s, Location &b)
{
	s =
	{
		t / BULLET_BASE_SPEED,
		static_cast<int>(10 * sin(t / (ANGLE_BASE_DIVISOR/100 * BULLET_BASE_SPEED)))
	};
}
void trail_circle_0(const int t, Location &s, Location &b)
{
	s =
	{
		static_cast<int>(t*sin(t / ANGLE_BASE_DIVISOR) / BULLET_BASE_SPEED),
		static_cast<int>(t*cos(t / ANGLE_BASE_DIVISOR) / BULLET_BASE_SPEED)
	};
}
void trail_circle_1(const int t, Location &s, Location &b)
{
	s =
	{
		static_cast<int>(t*sin(t / ANGLE_BASE_DIVISOR) / BULLET_BASE_SPEED),
		static_cast<int>(-t * cos(t / ANGLE_BASE_DIVISOR) / BULLET_BASE_SPEED)
	};
}
void trail_circle_2(const int t, Location &s, Location &b)
{
	s =
	{
		static_cast<int>(t*sin(t / ANGLE_BASE_DIVISOR) / 2 / BULLET_BASE_SPEED),
		static_cast<int>(t * cos(t / ANGLE_BASE_DIVISOR) / BULLET_BASE_SPEED)
	};
}
void trail_circle_3(const int t, Location &s, Location &b)
{
	s =
	{
		static_cast<int>(t*sin(t / ANGLE_BASE_DIVISOR) / BULLET_BASE_SPEED),
		static_cast<int>(-t * cos(t / ANGLE_BASE_DIVISOR) / 2 / BULLET_BASE_SPEED)
	};
}
void trail_stop(const int t, Location &s, Location &b)
{
	s = 
	{
		0,
		0 
	};
}
void trail_follow(const int t, Location &s, Location &b)		//Tips:׷�ٵ�Ļ���ڳ�ʼ��ʱ�Ƕ�ȫ����Ϊ0��
{
	int delta;
	if (s.y != b.y)
	{
		delta = (s.x - b.x) * (s.y = b.y);
	}
	delta = delta / BULLET_BASE_SPEED;
	s.x += delta;
	s =
	{
		s.x,
		t/BULLET_BASE_SPEED
	};
}
