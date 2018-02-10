//ReimuSelf.cpp
//定义自机相关的函数

#include"ReimuHeadFile.h"
#include"ReimuDatasheet.h"

Self::Self()
{
	loadimage(&selfimage[0], _T(".\\Reimu\\left.jpg"));
	loadimage(&selfimage[2], _T(".\\Reimu\\right.jpg"));
	loadimage(&selfimage[1], _T(".\\Reimu\\stop.jpg"));
	pictureSize = { selfimage[1].getwidth(),selfimage[1].getheight() };	//获取图像尺寸
	location = { SCREEN_WIDTH / 2 , SCREEN_LENGTH * 4 / 5 };
}
void Self::Moveself()
{
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
	setlinecolor(WHITE);
	setfillcolor(BLACK);
	fillcircle(self.pointLocate().x, self.pointLocate().y, 2);
	Sleep(10);
}
Location Self::pointLocate()
{
	return { (location.x + pictureSize.x / 2),(location.y + pictureSize.y / 2) };
}
