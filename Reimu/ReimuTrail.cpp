//ReimuTrail.cpp
//�켣��غ���

#include"ReimuDatasheet.h"
#include"ReimuHeadFile.h"

void trail_line
(
	const int time,								//ʱ��
	Location &bulletLocation,					//��Ļ����λ��
	const Location bulletInitialLocation,		//��Ļ�����ʼλ��
	const Location selfLocation,				//�Ի�λ��
	const double angle							//��ʼ�Ƕ�
)
{
	bulletLocation =
	{
		time / BULLET_BASE_SPEED,
		0
	};
}
void trail_sin
(
	const int time,								//ʱ��
	Location &bulletLocation,					//��Ļ����λ��
	const Location bulletInitialLocation,		//��Ļ�����ʼλ��
	const Location selfLocation,				//�Ի�λ��
	const double angle							//��ʼ�Ƕ�
)
{
	bulletLocation =
	{
		time / BULLET_BASE_SPEED,
		static_cast<int>(10 * sin(time / (ANGLE_BASE_DIVISOR/100 * BULLET_BASE_SPEED)))
	};
}
void trail_circle_0
(
	const int time,								//ʱ��
	Location &bulletLocation,					//��Ļ����λ��
	const Location bulletInitialLocation,		//��Ļ�����ʼλ��
	const Location selfLocation,				//�Ի�λ��
	const double angle							//��ʼ�Ƕ�
)
{
	bulletLocation =
	{
		static_cast<int>(time*sin(time / ANGLE_BASE_DIVISOR) / BULLET_BASE_SPEED),
		static_cast<int>(time*cos(time / ANGLE_BASE_DIVISOR) / BULLET_BASE_SPEED)
	};
}
void trail_circle_1
(
	const int time,								//ʱ��
	Location &bulletLocation,					//��Ļ����λ��
	const Location bulletInitialLocation,		//��Ļ�����ʼλ��
	const Location selfLocation,				//�Ի�λ��
	const double angle							//��ʼ�Ƕ�
)

{
	bulletLocation =
	{
		static_cast<int>(time*sin(time / ANGLE_BASE_DIVISOR) / BULLET_BASE_SPEED),
		static_cast<int>(-time * cos(time / ANGLE_BASE_DIVISOR) / BULLET_BASE_SPEED)
	};
}
void trail_circle_2
(
	const int time,								//ʱ��
	Location &bulletLocation,					//��Ļ����λ��
	const Location bulletInitialLocation,		//��Ļ�����ʼλ��
	const Location selfLocation,				//�Ի�λ��
	const double angle							//��ʼ�Ƕ�
)

{
	bulletLocation =
	{
		static_cast<int>(time*sin(time / ANGLE_BASE_DIVISOR) / 2 / BULLET_BASE_SPEED),
		static_cast<int>(time * cos(time / ANGLE_BASE_DIVISOR) / BULLET_BASE_SPEED)
	};
}
void trail_circle_3
(
	const int time,								//ʱ��
	Location &bulletLocation,					//��Ļ����λ��
	const Location bulletInitialLocation,		//��Ļ�����ʼλ��
	const Location selfLocation,				//�Ի�λ��
	const double angle							//��ʼ�Ƕ�
)
{
	bulletLocation =
	{
		static_cast<int>(time*sin(time / ANGLE_BASE_DIVISOR) / BULLET_BASE_SPEED),
		static_cast<int>(-time * cos(time / ANGLE_BASE_DIVISOR) / 2 / BULLET_BASE_SPEED)
	};
}
void trail_stop
(
	const int time,								//ʱ��
	Location &bulletLocation,					//��Ļ����λ��
	const Location bulletInitialLocation,		//��Ļ�����ʼλ��
	const Location selfLocation,				//�Ի�λ��
	const double angle							//��ʼ�Ƕ�
)

{
	bulletLocation = 
	{
		0,
		0 
	};
}
void trail_follow
(
	const int time,								//ʱ��
	Location &bulletLocation,					//��Ļ����λ��
	const Location bulletInitialLocation,		//��Ļ�����ʼλ��
	const Location selfLocation,				//�Ի�λ��
	const double angle							//��ʼ�Ƕ�
)
{
	//Todo..
	;
}
