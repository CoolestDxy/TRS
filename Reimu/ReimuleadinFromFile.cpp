//leadinFromFile.cpp
//���ļ���ȡ��Ļ��Ϣ����

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
		//		const int time,								//ʱ��
		//		Location &bulletLocation,					//��Ļ����λ��
		//		const Location bulletInitialLocation,		//��Ļ�����ʼλ��
		//		const Location selfLocation,				//�Ի�λ��
		//		const double angle							//��ʼ�Ƕ�
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