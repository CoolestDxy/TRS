//ReimuBackGround.cpp
//定义背景相关的函数

#include"ReimuDatasheet.h"
#include"ReimuHeadFile.h"


extern IMAGE backGround;

void backGroundInitialize()
{
	loadimage(&backGround, _T(BACKG_ROUND_IMAGINE));
}
void backGroundDraw()
{
	putimage(0, 0, &backGround);
}