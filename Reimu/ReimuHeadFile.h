//ReimuHeadFile.h
#pragma once
//�ṩȫ�ֶ���
#include<graphics.h>
#include<conio.h>
#include<ctime>
#include<cmath>

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

//�Ի�
class Self
{
private:
	int x, y, speed;
	IMAGE selfimage[3];
	IMAGE State;
	int w, h;
	int leastPlayer;	//�л���
public:
	Self();
	void Draw();	//����
	void Moveself();	//�����ƶ�
	int ValueofX();	//���������ã���ʹ��locate����
	int ValueofY();	//���������ã���ʹ��locate����
	int SelfpointX();	//���������ã���ʹ��pointLocate����
	int SelfpointY();	//���������ã���ʹ��pointLocate����
	Location locate();	//����ͼ������
	Location pointLocate();	//�����ж�������
}self;

//��Ļ�켣����

//ֱ�߹켣
void trail_line(const int t, int& x, int& y)
{
	x = t / 10;
	y = 0;
}
//���ι켣
void trail_sin(const int t, int& x, int& y)
{
	x = 0.1*t;
	y = 20 * sin(t / 100.0);
}
//Բ�ι켣(��ʱ��)
void trail_circle_0(const int t, int &x, int &y)
{
	x = 0.1*t*sin(t / 1000.0);
	y = 0.1*t*cos(t / 1000.0);
}
//Բ�ι켣(˳ʱ��)
void trail_circle_1(const int t, int &x, int &y)
{
	x = 0.1*t*sin(t / 1000.0);
	y = -0.1*t*cos(t / 1000.0);
}
//Բ��Ѳ�ع켣(��ʱ��)
void trail_circle_2(const int t, int &x, int &y)
{
	x = 0.05*t*sin(t / 1000.0);
	y = 0.1*t*cos(t / 1000.0);
}
//Բ��Ѳ�ع켣(˳ʱ��)
void trail_circle_3(const int t, int &x, int &y)
{
	x = 0.1*t*sin(t / 1000.0);
	y = -0.05*t*cos(t / 1000.0);
}
//��ֹ��Ļ�������ã�
void trail_stop(const int t, int &x, int &y)
{
	x = 0;
	y = 0;
}
//׷�ٵ�Ļ�켣
void trail_follow(const int t, int &x, int &y)		//Tips:׷�ٵ�Ļ���ڳ�ʼ��ʱ�Ƕ�ȫ����Ϊ0��
{
	Location selflocation = self.pointLocate();
}

//��Ļ
class Bullet
{
private:
	Location locate;	//��ʼλ��
	Location nowLocate;	//����λ��
	Location deltaLocate;	//�����

							//���滻�������Ƽ�ʹ��
	int x;			//��ʼλ��:X
	int y;			//��ʼλ��:y
	int nowx = 0;	//����λ��:x'
	int nowy = 0;	//����λ��:y'
	int delta_x;	//��Ļ�Ի������:x
	int delta_y;	//��Ļ�Ի������:y
					//���滻�������Ƽ�ʹ��

	int r;			//��Ļ�뾶
	double angle;	//���ƽǶ�
	void(*trail)(int, int&, int&);//·����ʽ
	SysTime time;	//ʱ��
	int color;		//��ɫ
public:
	Bullet	//Ĭ��ֵ
	(
		const int x_ = 0,
		const int y_ = 0,
		const int r_ = 10,
		const double angle_ = 0,
		void(*trail_)(int, int&, int&) = trail_line,
		int color_ = WHITE
	);

	//��ʼ����Ļ
	void initialization
	(
		const int x_ = 0,
		const int y_ = 0,
		const int r_ = 10,
		const double angle_ = 0,
		void(*trail_)(int, int&, int&) = trail_line,
		int color_ = WHITE
	);
	//ˢ�µ�Ļ&��ײ�ж�
	void fresh();
	Location bulletLocate();	//�����ӵ�����
};