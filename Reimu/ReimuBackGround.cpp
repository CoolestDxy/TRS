//ReimuBackGround.cpp
//������غ���

#include"ReimuDatasheet.h"
#include"ReimuHeadFile.h"

extern IMAGE backGround;

void backGroundInitialize(IMAGE * backGround)
{
	loadimage(backGround, _T(BACKG_ROUND_IMAGINE));
}
void backGroundDraw()
{
	putimage(0, 0, &backGround);
}