//ReimuBultLink.cpp
//µ¯Ä»Á´ÊµÏÖ

#include"ReimuDatasheet.h"
#include"ReimuHeadFile.h"

void pushBullet(BulletNode * const headBulletNode, Bullet * const bullet)
{
	BulletNode * ptr;
	ptr = headBulletNode;
	while (ptr->next != NULL)
	{
		ptr = ptr->next;
		if (ptr->bullet == NULL)
		{
			ptr->bullet = bullet;
		}
	}
	ptr->next = new BulletNode;
	ptr = ptr->next;
	ptr->bullet = bullet;
	ptr->next = NULL;
}
void popBullet(BulletNode *const headBulletNode, Bullet * const bullet)
{
	BulletNode * ptr;
	ptr = headBulletNode;
	while (ptr->next!=NULL)
	{
		ptr = ptr->next;
		if (ptr->next==NULL)
		{
			return;
		};
	}
	ptr->bullet = NULL;
}

void freshBulletLink(BulletNode *const headBulletNode)
{
	BulletNode * ptr;
	ptr = headBulletNode;
	while (ptr->next!=NULL)
	{
		ptr = ptr->next;
		if (ptr->bullet==NULL)
		{
			ptr->prev->next = ptr->next;
			BulletNode * temp;
			temp = ptr;
			ptr = ptr->prev;
			delete temp;
			continue;
		}
		else
		{
			ptr->bullet->fresh();
		}

	}
}

void emptyBulletLink(BulletNode * const headBulletNode)
{
	BulletNode * ptr;
	ptr = headBulletNode;
	while (ptr->next!=NULL)
	{
		ptr = ptr->next;
		delete ptr->prev;
	}
	delete ptr;
}