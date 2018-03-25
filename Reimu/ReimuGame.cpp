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
	//初始化UI界面
	initgraph(SCREEN_WIDTH, SCREEN_LENGTH);	
	//游戏开始界面
	gameLeader();
	//背景初始化
	backGroundInitialize(&backGround);
	//生成弹幕链
	BulletNode * headBulletNode;
	headBulletNode = new BulletNode;
	headBulletNode->next = NULL;
	//ReimuLeadinFromFile(headBulletNode,"test.data");
	Bullet * example = new Bullet;
	example->initialization({ 320, 240 }, 5, 0, trail_sin, WHITE, 0);
	pushBullet(headBulletNode, example);
	pushBullet(headBulletNode, new Bullet({ 320, 240 }, 5, 1 / 20.0 * 2 * Pi, trail_sin, WHITE, 1000));
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			pushBullet(headBulletNode, new Bullet({ 320, 240 }, 5, i / 20.0 * 2 * Pi, trail_sin, WHITE, 1000 + 100 * j));
			pushBullet(headBulletNode, new Bullet({ 320, 240 }, 5, i / 20.0 * 2 * Pi, trail_sin, WHITE, 3000 - 400 * j));
			pushBullet(headBulletNode, new Bullet({ 320, 240 }, 5, i / 20.0 * 2 * Pi, trail_line, YELLOW, 2000 + 50 * j));
			pushBullet(headBulletNode, new Bullet({ 160, 120 }, 5, i / 20.0 * 2 * Pi, trail_sin, BLUE, 3000 + 100 * j));
			pushBullet(headBulletNode, new Bullet({ 480, 120 }, 5, i / 20.0 * 2 * Pi, trail_sin, GREEN, 4000 + 50 * j));
			pushBullet(headBulletNode, new Bullet({ 320, 120 }, 5, i / 20.0 * 2 * Pi, trail_circle_0, RED, 5000 + 50 * j));
			pushBullet(headBulletNode, new Bullet({ 320, 120 }, 5, i / 20.0 * 2 * Pi, trail_circle_1, WHITE, 6000 + 20 * j));
			pushBullet(headBulletNode, new Bullet({ 320, 120 }, 5, i / 20.0 * 2 * Pi, trail_circle_2, RED, 7000 + 50 * j));
			pushBullet(headBulletNode, new Bullet({ 320, 120 }, 5, i / 20.0 * 2 * Pi, trail_circle_3, WHITE, 8000 + 50 * j));
			pushBullet(headBulletNode, new Bullet({ 320, 240 }, 5, i / 20.0 * 2 * Pi, trail_sin, WHITE, 3000 - 100 * j));
		}
	}
	sysTime.start();
	while ((self.leastPlayer > 0||true)&&headBulletNode->isEmpty())	//存活判定
	{
		//开始批量绘图
		BeginBatchDraw();
		//背景绘制
		backGroundDraw(&backGround);
		//自机移动
		self.Moveself();
		//刷新弹幕
		freshBulletLink(headBulletNode);
		//结束绘图释放缓冲
		FlushBatchDraw();
		//解锁帧率，否则请Sleep();
		Sleep(10);

	}
	//清理弹幕链，释放资源
	emptyBulletLink(headBulletNode);
	gameEnding(&self);
	//空循环等待
	//TODO..实现失败界面
	for (int i=0;i<3;i++)
	{
		Sleep(1000);
	}
	closegraph();
}
