//leadinFromFile.cpp
//从文件读取弹幕信息函数

#include"ReimuHeadFile.h"

void leadinFromFile(BulletNode * headBulletNode, char * fileName)
{
	std::ifstream dataLeader;
	dataLeader.open(fileName);
	if (!dataLeader)
	{
		return;
	}
	while (!dataLeader.eof())
	{
		int type;
		dataLeader >> type;
		//int locationX = 0;
		//int locationY = 0;
		//dataLeader >> locationX;
		//dataLeader >> locationY;
		//Location location = { locationX,locationY };
		//int r = 0;
		//dataLeader >> r;
		//double angle = 0;
		//dataLeader >> angle;
		//void(*trail)
		//	(
		//		const int time,								//时间
		//		Location &bulletLocation,					//弹幕坐标位置
		//		const Location bulletInitialLocation,		//弹幕坐标初始位置
		//		const Location selfLocation,				//自机位置
		//		const double angle							//初始角度
		//	)=trail_stop;
		//	//dataLeader >> trail;
		//int color;
		//dataLeader >> color;
		//unsigned long startTime;
		//dataLeader >> startTime;
		//Bullet example(location, r, angle, trail, color, startTime);
		//pushBullet(headBulletNode, new Bullet(location, r, &angle, trail, color, startTime));
	}
	dataLeader.close();
}