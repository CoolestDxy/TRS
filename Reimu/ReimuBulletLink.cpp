//ReimuBultLink.cpp
//µ¯Ä»Á´ÊµÏÖ

#include"ReimuDatasheet.h"
#include"ReimuHeadFile.h"

bool BulletNode::isEmpty()
{
	return this->next&&true;
}
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
			return;
		}
	}
	ptr->next = new BulletNode;
	ptr->next->prev = ptr;
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
		if (ptr->bullet==bullet)
		{
			ptr->bullet = NULL;
			return;
		};
	}
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
			if (ptr->next != NULL)
			{
				ptr->next->prev = ptr->prev;
			}
			BulletNode * temp;
			temp = ptr;
			ptr = ptr->prev;
			delete temp;
			continue;
		}
		else
		{
			ptr->bullet->fresh(headBulletNode);
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