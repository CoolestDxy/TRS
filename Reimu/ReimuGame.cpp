//ReimuGame.cpp
//游戏客户端

#include"ReimuDatasheet.h"
#include"ReimuHeadFile.h"

#include<iostream>

Self self;
IMAGE backGround;
SysTime sysTime;


int main()
{
	//背景初始化
	backGroundInitialize();
	//生成弹幕链
	BulletNode * headBulletNode;
	headBulletNode = new BulletNode;
	headBulletNode->next = NULL;
	Bullet * example = new Bullet;
	//pushBullet(headBulletNode, new Bullet);
	example->initialization({ 320, 240 }, 5, 0, trail_sin, WHITE, 0);
	pushBullet(headBulletNode, example);



	initgraph(SCREEN_WIDTH, SCREEN_LENGTH);	//初始化UI界面
	////demo弹幕演示示例
	//Bullet a0({ 320, 240 }, 5, 0, trail_sin, WHITE,0);
	//Bullet a1({ 320, 240 }, 5, Pi / 2, trail_sin, WHITE,0);
	//Bullet a2({ 320, 240 }, 5, Pi, trail_sin, WHITE,0);
	//Bullet a3({ 320, 240 }, 5, Pi * 1.5, trail_sin, WHITE);
	//Bullet a[21],b[21],c[21],d[21],e[21],f[21],g[21],h[21];
	////重新初始化（上面的初始化废弃）
	//for (int i = 0; i < 20; i++)
	//{
	//	a[i].initialization({ 320, 240 }, 5, i / 20.0 * 2 * Pi, trail_sin, WHITE,1000);
	//	b[i].initialization({ 320, 240 }, 5, i / 20.0 * 2 * Pi, trail_line, YELLOW,2000);
	//	c[i].initialization({ 160, 120 }, 5, i / 20.0 * 2 * Pi, trail_sin, BLUE,3000);
	//	d[i].initialization({ 480, 120 }, 5, i / 20.0 * 2 * Pi, trail_sin, GREEN,4000);
	//	e[i].initialization({ 320, 120 }, 5, i / 20.0 * 2 * Pi, trail_circle_0, RED,5000);
	//	f[i].initialization({ 320, 120 }, 5, i / 20.0 * 2 * Pi, trail_circle_1, WHITE);
	//	g[i].initialization({ 320, 120 }, 5, i / 20.0 * 2 * Pi, trail_circle_2, RED);
	//	h[i].initialization({ 320, 120 }, 5, i / 20.0 * 2 * Pi, trail_circle_3, WHITE);
	//}
	//Bullet follow({ 100, 100 }, 5, 0, trail_follow, YELLOW);
	while (self.leastPlayer>0)	//存活判定
	{
		//开始批量绘图
		BeginBatchDraw();
		//背景绘制
		backGroundDraw();
		//自机移动
		self.Moveself();
		//刷新弹幕
		freshBulletLink(headBulletNode);
		//for (int i = 0; i < 20; i++)
		//{
		//	follow.fresh();
		//	a[i].fresh();
		//	b[i].fresh();
		//	c[i].fresh();
		//	d[i].fresh();
		//	e[i].fresh();
		//	f[i].fresh();
		//	g[i].fresh();
		//	h[i].fresh();
		//}
		//follow.fresh();
		//结束绘图释放缓冲
		FlushBatchDraw();
		//解锁帧率，否则请Sleep();
		Sleep(20);
	}
	delete example;

	for (;;)
	{
		Sleep(1000);
	}
	//TODO……替换为显示游戏失败界面。
	closegraph();
}
