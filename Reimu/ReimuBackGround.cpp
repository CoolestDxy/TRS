//ReimuBackGround.cpp
//������غ���

#include"ReimuDatasheet.h"
#include"ReimuHeadFile.h"

void backGroundInitialize(IMAGE * backGround)
{
	loadimage(backGround, _T(BACKG_ROUND_IMAGINE));
}
void backGroundDraw(IMAGE * backGround)
{
	putimage(0, 0, backGround);
}