//ReimuGameEnding.cpp
//��Ϸ����������

#include"ReimuDatasheet.h"
#include"ReimuHeadFile.h"

IMAGE  ending;

void gameEnding(Self * self)
{
	if (self->leastPlayer>0)		//�ж��Ƿ���
	{
		loadimage(&ending ,_T(ENDING_GOOD_IMAGINE));
	}
	else
	{
		loadimage(&ending, _T(ENDING_BAD_ENDING));
	}
	putimage(SCREEN_WIDTH/2-ending.getwidth()/2, SCREEN_LENGTH/2-ending.getheight()/2, &ending);
	//������ͼ�ͷŻ���
	FlushBatchDraw();
}