#ifndef ENEMYLIST_H
#define ENEMYLIST_H

#include "butterfly.h"

class EnemyList
{
public:
	void initSprites(Graphics &graphics);
	void updateButterfly();
	void updateAll();
	void printButterfly(Graphics &graphics);
	void printAll(Graphics &graphics);

	void newButterfly();
	int getCant() { return this->ListaButterfly.size(); };
private:
	Sprite spriteButterfly;
	list<Butterfly*> ListaButterfly;
};


#endif