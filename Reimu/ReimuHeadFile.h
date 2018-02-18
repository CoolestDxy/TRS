//ReimuHeadFile.h
#pragma once
//�ṩȫ�ֶ���
#include<graphics.h>
#include<conio.h>
#include<ctime>
#include<cmath>
#include"ReimuDatasheet.h"

//ʱ��ϵͳ
class SysTime
{
private:
	clock_t startTime;
	clock_t endTime;
public:
	//��ʼ��ʱ
	//��Ϸ��ʼʱ����һ��
	void start();
	//��ȡ��ǰʱ��
	//����unsigned long���͵ĺ�����
	unsigned long now();
};

//����
struct Location
{
	int x;
	int y;
};

//����
void backGroundInitialize();
void backGroundDraw();

//�Ի�
class Self
{
private:
	int speed;			//�ƶ��ٶ�
	IMAGE selfimage[3];	//�Ի�ͼ��
	IMAGE State;		//��ǰ�Ի�ͼ��
public:
	Location location;	//ͼ��λ�ã���ͼԭ�㣩
	Location pictureSize;	//ͼ��ߴ�
	int leastPlayer = 1;	//�л���
	Self();
	void Moveself();	//�����ƶ�
	Location pointLocate();	//�����ж�������
};

extern Self self;

//��ֹ��Ļ��Ĭ��ֵ�ã�
void trail_stop
(
	const int time,								//ʱ��
	Location &bulletLocation,					//��Ļ����λ��
	const Location bulletInitialLocation,		//��Ļ�����ʼλ��
	const Location selfLocation,				//�Ի�λ��
	const double angle							//��ʼ�Ƕ�
);	//ʱ�䣬�Ի����꣬��Ļ����

//��Ļ

class Bullet
{
private:
	Location initialLocate;	//��ʼλ��
	Location deltaLocate;	//�����
	int r;			//��Ļ�뾶
	double angle;	//���ƽǶ�
	void(*trail)
		(
		const int time,								//ʱ��
		Location &bulletLocation,					//��Ļ����λ��
		const Location bulletInitialLocation,		//��Ļ�����ʼλ��
		const Location selfLocation,				//�Ի�λ��
		const double angle							//��ʼ�Ƕ�
		)
		;//·����ʽ
	SysTime time;	//ʱ��
	int color;		//��ɫ
	unsigned long startTime;	//����ʱ��
public:
	Location locate;	//����λ��

	Bullet(			//Ĭ��ֵ
		const Location b_ = { 100,100 },
		const int r_ = 5,
		const double angle_ = 0,
		void(*trail_)
			(
			const int time,								//ʱ��
			Location &bulletLocation,					//��Ļ����λ��
			const Location bulletInitialLocation,		//��Ļ�����ʼλ��
			const Location selfLocation,				//�Ի�λ��
			const double angle							//��ʼ�Ƕ�
			)
		= trail_stop,
		int color_ = WHITE,
		unsigned long startTime_ = 0	//����ʱ��
	);

	//��ʼ����Ļ
	void initialization
	(
		const Location b_ = { 100,100 },
		const int r_ = 5,
		const double angle_ = 0,
		void(*trail_)
			(
			const int time,								//ʱ��
			Location &bulletLocation,					//��Ļ����λ��
			const Location bulletInitialLocation,		//��Ļ�����ʼλ��
			const Location selfLocation,				//�Ի�λ��
			const double angle							//��ʼ�Ƕ�
			)
		= trail_stop,
		int color_ = WHITE,
		unsigned long  startTime_ = 0
	);
	//ˢ�µ�Ļ&��ײ�ж�
	void fresh();
};

//��Ļ��ϵͳ
class BulletNode
{
public:
	Bullet * bullet;
	struct BulletNode * prev;
	struct BulletNode * next;
};

//����Ļ����ѹ���µ�Ļ
void pushBullet(BulletNode * const headBulletNode, Bullet * const bullet);
//�ӵ�Ļ���е�����Ļ
void popBullet(BulletNode *const headBulletNode, Bullet * const bullet);
//ˢ�£����ƣ���Ļ��
void freshBulletLink(BulletNode * headBulletNode);
//��յ�Ļ��
void emptyBulletLink(BulletNode *const headBulletNode);


//��Ļ�켣����

//ֱ�߹켣
void trail_line
(
	const int time,								//ʱ��
	Location &bulletLocation,					//��Ļ����λ��
	const Location bulletInitialLocation,		//��Ļ�����ʼλ��
	const Location selfLocation,				//�Ի�λ��
	const double angle							//��ʼ�Ƕ�
);
//���ι켣
void trail_sin
(
	const int time,								//ʱ��
	Location &bulletLocation,					//��Ļ����λ��
	const Location bulletInitialLocation,		//��Ļ�����ʼλ��
	const Location selfLocation,				//�Ի�λ��
	const double angle							//��ʼ�Ƕ�
);

//Բ�ι켣(��ʱ��)
void trail_circle_0
(
	const int time,								//ʱ��
	Location &bulletLocation,					//��Ļ����λ��
	const Location bulletInitialLocation,		//��Ļ�����ʼλ��
	const Location selfLocation,				//�Ի�λ��
	const double angle							//��ʼ�Ƕ�
);

//Բ�ι켣(˳ʱ��)
void trail_circle_1
(
	const int time,								//ʱ��
	Location &bulletLocation,					//��Ļ����λ��
	const Location bulletInitialLocation,		//��Ļ�����ʼλ��
	const Location selfLocation,				//�Ի�λ��
	const double angle							//��ʼ�Ƕ�
);
//Բ��Ѳ�ع켣(��ʱ��)
void trail_circle_2
(
	const int time,								//ʱ��
	Location &bulletLocation,					//��Ļ����λ��
	const Location bulletInitialLocation,		//��Ļ�����ʼλ��
	const Location selfLocation,				//�Ի�λ��
	const double angle							//��ʼ�Ƕ�
);
//Բ��Ѳ�ع켣(˳ʱ��)
void trail_circle_3
(
	const int time,								//ʱ��
	Location &bulletLocation,					//��Ļ����λ��
	const Location bulletInitialLocation,		//��Ļ�����ʼλ��
	const Location selfLocation,				//�Ի�λ��
	const double angle							//��ʼ�Ƕ�
);
//׷�ٵ�Ļ�켣
void trail_follow
(
	const int time,								//ʱ��
	Location &bulletLocation,					//��Ļ����λ��
	const Location bulletInitialLocation,		//��Ļ�����ʼλ��
	const Location selfLocation,				//�Ի�λ��
	const double angle							//��ʼ�Ƕ�
);		//Tips:׷�ٵ�Ļ���ڳ�ʼ��ʱ�Ƕ�ȫ����Ϊ0��
