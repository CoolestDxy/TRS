//ReimuGameLoader.cpp
//��Ϸ��������

#include"ReimuDatasheet.h"
#include"ReimuHeadFile.h"

int gameLeader()
{
	//��ʼ������ͼ
	BeginBatchDraw();
	IMAGE gameLoader;
	loadimage(&gameLoader, _T(GAMELOAD_IMAGINE));
	putimage(0, 0, &gameLoader);
	//������ͼ�ͷŻ���
	FlushBatchDraw();
	Sleep(3000);
	return 0;
}