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
	putimage(0, 0, &ending);
	//结束绘图释放缓冲
	FlushBatchDraw();
}