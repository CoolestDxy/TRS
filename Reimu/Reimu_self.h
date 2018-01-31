//Mowu_self.h
#ifndef GRAPHICS_H
#include<graphics.h>
#endif // !GRAPHICS_H
#include"Reimu_datasheet.h"

struct Location
{
	int x;
	int y;
};	//����λ������

class Self
{
private:
	int x, y, speed;
	IMAGE selfimage[3];
	IMAGE State;
	int w, h;
public:
	Self()
	{
		loadimage(&selfimage[0], _T(".\\Reimu\\left.jpg"));
		loadimage(&selfimage[2], _T(".\\Reimu\\right.jpg"));
		loadimage(&selfimage[1], _T(".\\Reimu\\stop.jpg"));
		w = selfimage[1].getwidth();
		h = selfimage[1].getheight();
	};
	void Drawself()
	{
		setfillcolor(WHITE);
		putimage(900, 900, &selfimage[1]);
		x = 900;
		y = 900;
		speed = 5;
	}
	void Moveself()	//�����ƶ�
	{
		setlinecolor(BLACK);
		setfillcolor(BLACK);
		fillrectangle(x, y, (x + w), (y + h));
		State = selfimage[1];
		if (GetAsyncKeyState(VK_SHIFT) & 0x8000) speed = LOW_SPEED; else speed = HIGH_SPEED;
		if (GetAsyncKeyState(VK_LEFT) & 0x8000) { x = x - speed; State = selfimage[0]; }
		if (GetAsyncKeyState(VK_RIGHT) & 0x8000) { x = x + speed; State = selfimage[2]; }
		if (GetAsyncKeyState(VK_UP) & 0x8000)y = y - speed;
		if (GetAsyncKeyState(VK_DOWN) & 0x8000)	y = y + speed;
		if (x<0)
		{
			x = 0;
		}
		else if (x > SCREEN_WIDTH-w)
		{
			x=SCREEN_WIDTH - w;
		}
		if (y<0)
		{
			y = 0;
		}
		else if (y > SCREEN_LENGTH - h)
		{
			y = SCREEN_LENGTH - h;
		}
		putimage(x, y, &State);
		Sleep(10);
	}
	int ValueofX()	//���������ã���ʹ��locate����
	{
		return x;
	}
	int ValueofY()	//���������ã���ʹ��locate����
	{
		return y;
	}
	int SelfpointX()	//���������ã���ʹ��pointLocate����
	{
		return (x + w / 2);
	}
	int SelfpointY()	//���������ã���ʹ��pointLocate����
	{
		return(y + h / 2);
	}
	Location locate()	//����ͼ������
	{
		return { x,y };
	}
	Location pointLocate()	//�����ж�������
	{
		return { (x + w / 2),(y + h / 2) };
	}
};
