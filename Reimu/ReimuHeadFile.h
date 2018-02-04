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
void trail_stop(const int t, Location &s, Location &b);	//ʱ�䣬�Ի����꣬��Ļ����

//��Ļ

class Bullet
{
private:
	Location initialLocate;	//��ʼλ��
	Location deltaLocate;	//�����
	int r;			//��Ļ�뾶
	double angle;	//���ƽǶ�
	void(*trail)(int, Location&, Location&);//·����ʽ
	SysTime time;	//ʱ��
	int color;		//��ɫ
public:
	Location locate;	//����λ��

	Bullet(			//Ĭ��ֵ
		const Location b_ = { 100,100 },
		const int r_ = 5,
		const double angle_ = 0,
		void(*trail_)(int, Location&, Location&) = trail_stop,
		int color_ = WHITE
	);

	//��ʼ����Ļ
	void initialization
	(
		const Location b_ = { 100,100 },
		const int r_ = 5,
		const double angle_ = 0,
		void(*trail_)(int, Location&, Location&) = trail_stop,
		int color_ = WHITE
		);
	//ˢ�µ�Ļ&��ײ�ж�
	void fresh();
};


//��Ļ�켣����

//ֱ�߹켣
void trail_line(const int t, Location &s, Location &b);
//���ι켣
void trail_sin(const int t, Location &s, Location &b);
//Բ�ι켣(��ʱ��)
void trail_circle_0(const int t, Location &s, Location &b);
//Բ�ι켣(˳ʱ��)
void trail_circle_1(const int t, Location &s, Location &b);
//Բ��Ѳ�ع켣(��ʱ��)
void trail_circle_2(const int t, Location &s, Location &b);
//Բ��Ѳ�ع켣(˳ʱ��)
void trail_circle_3(const int t, Location &s, Location &b);
//׷�ٵ�Ļ�켣
void trail_follow(const int t, Location &s, Location &b);		//Tips:׷�ٵ�Ļ���ڳ�ʼ��ʱ�Ƕ�ȫ����Ϊ0��
