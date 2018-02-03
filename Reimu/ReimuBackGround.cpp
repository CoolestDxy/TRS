//ReimuBackGround.cpp
#include"ReimuDatasheet.h"
#include"ReimuHeadFile.h"

char *a = ".\\backGround\\backGround.jpg";

extern IMAGE backGround;

void backGroundInitialize()
{
	loadimage(&backGround, _T(".\\backGround\\backGround.jpg"));
}
void backGroundDraw()
{
	putimage(0, 0, &backGround);
}