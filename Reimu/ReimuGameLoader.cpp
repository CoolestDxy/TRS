//ReimuGameLoader.cpp
//游戏引导函数

#include"ReimuDatasheet.h"
#include"ReimuHeadFile.h"

int gameLeader()
{
	//开始批量绘图
	BeginBatchDraw();
	IMAGE gameLoader;
	loadimage(&gameLoader, _T(GAMELOAD_IMAGINE));
	putimage(0, 0, &gameLoader);
	//结束绘图释放缓冲
	FlushBatchDraw();
	Sleep(3000);
	return 0;
}