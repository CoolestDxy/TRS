//ReimuBackGround.cpp
//���屳����صĺ���

#include"ReimuDatasheet.h"
#include"ReimuHeadFile.h"


extern IMAGE backGround;

void backGroundInitialize()
{
	loadimage(&backGround, _T(".\\backGround\\backGround.jpg"));
}
void backGroundDraw()
{
	putimage(0, 0, &backGround);
}