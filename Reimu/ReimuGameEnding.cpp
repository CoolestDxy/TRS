//ReimuGameEnding.cpp
//游戏结束处理函数

#include"ReimuDatasheet.h"
#include"ReimuHeadFile.h"

IMAGE  ending;

void gameEnding(Self * self)
{
	if (self->leastPlayer>0)		//判断是否存活
	{
		loadimage(&ending ,_T(ENDING_GOOD_IMAGINE));
	}
	else
	{
		loadimage(&ending, _T(ENDING_BAD_ENDING));
	}
	putimage(SCREEN_WIDTH/2-ending.getwidth()/2, SCREEN_LENGTH/2-ending.getheight()/2, &ending);
	//结束绘图释放缓冲
	FlushBatchDraw();
}