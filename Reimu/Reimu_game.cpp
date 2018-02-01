//MoWu_game.cpp
#include"Reimu_datasheet.h"
#include"ReimuHeadFile.h"
SysTime sysGlobalTime;//宏观时间（游戏计时）

int main()
{
	initgraph(SCREEN_WIDTH, SCREEN_LENGTH);	//初始化UI界面
	//demo弹幕演示示例
	Bullet a0(320, 240, 5, 0, trail_sin, WHITE);
	Bullet a1(320, 240, 5, 3.14159 / 2, trail_sin, WHITE);
	Bullet a2(320, 240, 5, 3.14159, trail_sin, WHITE);
	Bullet a3(320, 240, 5, 3.14159 * 1.5, trail_sin, WHITE);
	Bullet a[21],b[21],c[21],d[21],e[21],f[21],g[21],h[21];
	//重新初始化（上面的初始化废弃）
	for (int i = 0; i < 20; i++)
	{
		a[i].initialization(320, 240, 5, i / 20.0 * 2 * Pi, trail_sin, WHITE);
		b[i].initialization(320, 240, 5, i / 20.0 * 2 * Pi, trail_line, YELLOW);
		c[i].initialization(160, 120, 5, i / 20.0 * 2 * Pi, trail_sin, BLUE);
		d[i].initialization(480, 120, 5, i / 20.0 * 2 * Pi, trail_sin, GREEN);
		e[i].initialization(320, 120, 5, i / 20.0 * 2 * Pi, trail_circle_0, RED);
		f[i].initialization(320, 120, 5, i / 20.0 * 2 * Pi, trail_circle_1, WHITE);
		g[i].initialization(320, 120, 5, i / 20.0 * 2 * Pi, trail_circle_2, RED);
		h[i].initialization(320, 120, 5, i / 20.0 * 2 * Pi, trail_circle_3, WHITE);
	}
	Bullet follow(100, 100, 10, 0, trail_follow, WHITE);
	while (1)	//存活判定
	{
		//开始批量绘图
		BeginBatchDraw();
		//自机移动
		self.Moveself();
		//刷新弹幕
		for (int i = 0; i < 20; i++)
		{
			follow.fresh();
			a[i].fresh();
			b[i].fresh();
			c[i].fresh();
			d[i].fresh();
			e[i].fresh();
			f[i].fresh();
			g[i].fresh();
			h[i].fresh();
		}
		//结束绘图释放缓冲
		FlushBatchDraw();
		//解锁帧率，否则请Sleep();
		Sleep(20);
	}
	setlinecolor(WHITE);
	//TODO……替换为显示游戏失败界面。
	RECT r = { 0, 0, 640, 480 };
	drawtext(_T("Failed"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	_getch();
	closegraph();
}
