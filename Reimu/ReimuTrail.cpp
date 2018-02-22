//ReimuTrail.cpp
//�켣��غ���

#include"ReimuDatasheet.h"
#include"ReimuHeadFile.h"

void trail_line
(
	const int time,									//ʱ��
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
	//ת��Ϊȫ������
	bulletLocation =
	{
		static_cast<int>(bulletInitialLocation.x + bulletLocation.x*cos(angle) - bulletLocation.y*sin(angle)),
		static_cast<int>(bulletInitialLocation.y + bulletLocation.x*sin(angle) + bulletLocation.y*cos(angle))
	};

}
void trail_sin
(
	const int time,									//ʱ��
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
	//ת��Ϊȫ������
	bulletLocation =
	{
		static_cast<int>(bulletInitialLocation.x + bulletLocation.x*cos(angle) - bulletLocation.y*sin(angle)),
		static_cast<int>(bulletInitialLocation.y + bulletLocation.x*sin(angle) + bulletLocation.y*cos(angle))
	};

}
void trail_circle_0
(
	const int time,									//ʱ��
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
	//ת��Ϊȫ������
	bulletLocation =
	{
		static_cast<int>(bulletInitialLocation.x + bulletLocation.x*cos(angle) - bulletLocation.y*sin(angle)),
		static_cast<int>(bulletInitialLocation.y + bulletLocation.x*sin(angle) + bulletLocation.y*cos(angle))
	};

}
void trail_circle_1
(
	const int time,									//ʱ��
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
	//ת��Ϊȫ������
	bulletLocation =
	{
		static_cast<int>(bulletInitialLocation.x + bulletLocation.x*cos(angle) - bulletLocation.y*sin(angle)),
		static_cast<int>(bulletInitialLocation.y + bulletLocation.x*sin(angle) + bulletLocation.y*cos(angle))
	};
}
void trail_circle_2
(
	const int time,									//ʱ��
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
	//ת��Ϊȫ������
	bulletLocation =
	{
		static_cast<int>(bulletInitialLocation.x + bulletLocation.x*cos(angle) - bulletLocation.y*sin(angle)),
		static_cast<int>(bulletInitialLocation.y + bulletLocation.x*sin(angle) + bulletLocation.y*cos(angle))
	};

}
void trail_circle_3
(
	const int time,									//ʱ��
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
	//ת��Ϊȫ������
	bulletLocation =
	{
		static_cast<int>(bulletInitialLocation.x + bulletLocation.x*cos(angle) - bulletLocation.y*sin(angle)),
		static_cast<int>(bulletInitialLocation.y + bulletLocation.x*sin(angle) + bulletLocation.y*cos(angle))
	};

}
void trail_stop
(
	const int time,									//ʱ��
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
	//ת��Ϊȫ������
	bulletLocation =
	{
		static_cast<int>(bulletInitialLocation.x + bulletLocation.x*cos(angle) - bulletLocation.y*sin(angle)),
		static_cast<int>(bulletInitialLocation.y + bulletLocation.x*sin(angle) + bulletLocation.y*cos(angle))
	};

}
void trail_follow
(
	const int time,									//ʱ��
	Location &bulletLocation,					//��Ļ����λ��
	const Location bulletInitialLocation,		//��Ļ�����ʼλ��
	const Location selfLocation,				//�Ի�λ��
	const double angle							//��ʼ�Ƕ�
)
{
	//Todo..
	;
}
