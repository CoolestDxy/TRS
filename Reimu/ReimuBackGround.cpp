//ReimuBackGround.cpp
//±³¾°Ïà¹Øº¯Êý

#include"ReimuDatasheet.h"
#include"ReimuHeadFile.h"

void backGroundInitialize(IMAGE * backGround)
{
	loadimage(backGround, _T(BACKGROUND_IMAGINE));
}
void backGroundDraw(IMAGE * backGround)
{
	putimage(0, 0, backGround);
}