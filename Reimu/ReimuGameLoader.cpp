//ReimuGameLoader.cpp
//游戏引导函数

#include"ReimuDatasheet.h"
#include"ReimuHeadFile.h"

int gameLeader()
{
	IMAGE gameLoader;
	loadimage(&gameLoader, _T(GAMELOAD_IMAGINE));
	putimage(0, 0, &gameLoader);
	//Sleep(3000);
	return 0;
}