#include "enemylist.h"

void EnemyList::initSprites(Graphics &graphics)
{
	RGB_Color color{ 38,130,232 };
	this->spriteButterfly.loadSprite(graphics, "dt/nmy/tmp.pbm",&color);
}

void EnemyList::updateButterfly()
{
	list<Butterfly*>::iterator it;
	for (it = this->ListaButterfly.begin(); it != this->ListaButterfly.end(); it++)
	{
		(*it)->update();
		if ((*it)->deleteFromList)
		{
			delete(*it);
			it = this->ListaButterfly.erase(it);
			this->ListaButterfly.push_back(new (Butterfly));
			break;
		}
	}
}

void EnemyList::updateAll()
{
	this->updateButterfly();
}

void EnemyList::printButterfly(Graphics &graphics)
{
	list<Butterfly*>::iterator it;
	for (it = this->ListaButterfly.begin(); it != this->ListaButterfly.end(); it++)
	{
		(*it)->print(graphics,this->spriteButterfly);
	}
}

void EnemyList::printAll(Graphics &graphics)
{
	this->printButterfly(graphics);
}

void EnemyList::newButterfly()
{
	this->ListaButterfly.push_back(new (Butterfly));
}