#ifndef DEBUGMODE_H
#define DEBUGMODE_H

#include "globals.h"
#include "asciifont.h"

class HaryBall;
class EnemyList;


class Debugmode
{
public:
	void init(Graphics &graphics);

	void printCantEntities(int cant,Graphics &graphics);
	void printCantEnemies(int cant,Graphics &graphics);
	void printCantBullets(int cant,Graphics &graphics);
	void printPlayerXY(int x, int y,Graphics &graphics);
	void printPlayerCenter(int x, int y,Graphics &graphics);
	void printPlayerCenterPoint(int x, int y,Graphics &graphics);
	void printPlayerHitboxes(int u, int d, int l, int r,Graphics &graphics);
	void printPlayerHitboxesXY(int u, int d, int l, int r,Graphics &graphics);
	void printEntitiesHitboxes(EnemyList enemylist,Graphics &graphics);
	void printPlayerLife(int value, Graphics &graphics);
	void printPlayerLive(int value,Graphics &graphics);
	void showMenuOptions(int tiempo,Graphics &graphics);

	void printAll(int entities,int enemies,int bullets,int plife,int plives,int x,int y,int u,int d,int l,int r,Graphics &graphics);

	void showOptions(Graphics &graphics);


	void swichCantEntities() { if (this->showCantEntities) { this->showCantEntities = false; } else { this->showCantEntities = true; } }
	void swichCantEnemies() { if (this->showCantEnemies) { this->showCantEnemies=false; } else { this->showCantEnemies=true; } }
	void swichCantBullets() { if (this->showCantBullets) { this->showCantBullets = false; } else { this->showCantBullets = true; } }
	void swichPlayerXY() { if (this->showPlayerXY) { this->showPlayerXY = false; } else { this->showPlayerXY = true; } }
	void swichPlayerCenter() { if (this->showPlayerCenter) { this->showPlayerCenter = false; } else { this->showPlayerCenter = true; } }
	void swichPlayerCenterPoint() { if (this->showPlayerCenterPoint) { this->showPlayerCenterPoint = false; } else { this->showPlayerCenterPoint = true; } }
	void swichPlayerHitboxes() { if (this->showPlayerHitboxes) { this->showPlayerHitboxes = false; } else { this->showPlayerHitboxes = true; } }
	void swichPlayerHitboxesXY() { if (this->showPlayerHitboxesXY) { this->showPlayerHitboxesXY = false; } else { this->showPlayerHitboxesXY = true; } }
	void swichEntitiesHitboxes() { if (this->showEntitiesHitboxes) { this->showEntitiesHitboxes = false; } else { this->showEntitiesHitboxes = true; } }
	void swichPlayerLife() { if (this->showPlayerLife) { this->showPlayerLife = false; } else { this->showPlayerLife = true; } }
	void swichPlayerLive() { if (this->showPlayerLive) { this->showPlayerLive = false; } else { this->showPlayerLive = true; } }

	void swichAll() 
	{ 
		if (this->all) 
		{
			this->all = false;
		}
		else
		{
			this->all = true;
		}
		this->setAll(this->all);
	}

	void setAll(bool value)
	{
		this->showCantEntities = value;
		this->showCantEnemies = value;
		this->showCantBullets = value;
		this->showPlayerXY = value;
		this->showPlayerCenter = value;
		this->showPlayerCenterPoint = value;
		this-> showPlayerHitboxes = value;
		this->showPlayerHitboxesXY = value;
		this->showEntitiesHitboxes = value;
		this->showPlayerLife = value;
		this->showPlayerLive = value;
	}

	bool viewOptions = false;
private:
	bool showCantEntities = false;
	bool showCantEnemies = false;
	bool showCantBullets = false;
	bool showPlayerXY = false;
	bool showPlayerCenter = false;
	bool showPlayerCenterPoint = false;
	bool showPlayerHitboxes = false;
	bool showPlayerHitboxesXY = false;
	bool showEntitiesHitboxes = false;
	bool showPlayerLife = false;
	bool showPlayerLive = false;

	bool all = false;

	AsciiFont letras;
protected:
};

#endif