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
	putimage(0, 0, &ending);
	//������ͼ�ͷŻ���
	FlushBatchDraw();
}