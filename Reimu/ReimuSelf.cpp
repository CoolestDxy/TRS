//ReimuSelf.cpp
#include"ReimuHeadFile.h"
#include"ReimuDatasheet.h"

Self::Self()
{
	loadimage(&selfimage[0], _T(".\\Reimu\\left.jpg"));
	loadimage(&selfimage[2], _T(".\\Reimu\\right.jpg"));
	loadimage(&selfimage[1], _T(".\\Reimu\\stop.jpg"));
	pictureSize = { selfimage[1].getwidth(),selfimage[1].getheight() };	//获取图像尺寸
	location = { SCREEN_WIDTH / 2 , SCREEN_LENGTH * 4 / 5 };

	//即将弃用
	//w = selfimage[1].getwidth();
	//h = selfimage[1].getheight();
}
//void Self::set()
//{
//	////setfillcolor(WHITE);	即将弃用
//	//putimage(SCREEN_WIDTH / 2, SCREEN_LENGTH * 1 / 10, &selfimage[1]);
//	//location = { SCREEN_WIDTH / 2, SCREEN_LENGTH * 2 / 10 };
//
//	//x = SCREEN_WIDTH / 2;
//	//y = SCREEN_LENGTH * 4 / 5;
//	//speed = 5;
//	//即将弃用
//}
void Self::Moveself()
{
	//擦除
	setlinecolor(BLACK);
	setfillcolor(BLACK);
	fillrectangle
	(
		location.x, location.y, 
		(location.x + pictureSize.x), (location.y + pictureSize.y)
	);
	State = selfimage[1];
	//低速判断
	if (GetAsyncKeyState(VK_SHIFT) & 0x8000)
	{
		speed = LOW_SPEED;
	}
	else 
	{ 
		speed = HIGH_SPEED; 
	}
	//自机游动
	if (GetAsyncKeyState(VK_LEFT) & 0x8000)
	{
		location.x -= speed; 
		State = selfimage[0];
	}
	if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
	{
		location.x += speed; 
		State = selfimage[2];
	}
	if (GetAsyncKeyState(VK_UP) & 0x8000)
	{
		location.y -= speed;
	}
	if (GetAsyncKeyState(VK_DOWN) & 0x8000)
	{
		location.y += speed;
	}

	//边框控制
	if (location.x < 0)
	{
		location.x = 0;
	}
	else if (location.x > SCREEN_WIDTH - pictureSize.x)
	{
		location.x = SCREEN_WIDTH - pictureSize.x;
	}
	if (location.y < 0)
	{
		location.y = 0;
	}
	else if (location.y > SCREEN_LENGTH - pictureSize.y)
	{
		location.y = SCREEN_LENGTH - pictureSize.y;
	}

	putimage(location.x, location.y, &State);
	Sleep(10);
}
Location Self::pointLocate()
{
	return { (location.x + pictureSize.x / 2),(location.y + pictureSize.y / 2) };
}


//Location Self::locate()
//{
//	return { x,y };
//}
//int Self::ValueofX()
//{
//	return x;
//}
//int Self::ValueofY()
//{
//	return y;
//}
//int Self::SelfpointX()
//{
//	return (x + w / 2);
//}
//int Self::SelfpointY()
//{
//	return (y + h / 2);
//}
