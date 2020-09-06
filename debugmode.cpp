#include "debugmode.h"
#include "graphics.h"
#include "enemylist.h"

void Debugmode::init(Graphics &graphics)
{
	this->letras.init(graphics);
}

void Debugmode::printPlayerXY(int xp, int yp, Graphics &graphics)
{
	this->letras.putText(16, 16, 15, 15, "X:     Y:", graphics);
	this->letras.putInt(16*3, 16, 15, 15, xp, graphics);
	this->letras.putInt(16*10, 16, 15, 15, yp, graphics);
}

void Debugmode::printPlayerCenter(int x, int y,Graphics &graphics)
{
	this->letras.putText(16, 16*2, 15, 15, "Center: x:    y:", graphics);
	this->letras.putInt(16 * 11, 16 * 2, 15, 15, x, graphics);
	this->letras.putInt(16 * 17, 16 * 2, 15, 15, y, graphics);
}

void Debugmode::printPlayerCenterPoint(int x, int y,Graphics &graphics)
{
	
	this->letras.putText(x, y, 15, 15, ".", graphics);
}

void Debugmode::printPlayerHitboxesXY(int u, int d, int l, int r, Graphics &graphics)
{
	this->letras.putText(16, 16 * 3, 15, 15, "Hl:    Hr:", graphics);
	this->letras.putText(16, 16 * 4, 15, 15, "Hu:    Hd:", graphics);

	this->letras.putInt(16 * 4, 16 * 3, 15, 15, l, graphics);
	this->letras.putInt(16 * 11, 16 * 3, 15, 15, r, graphics);
	this->letras.putInt(16 * 4, 16 * 4, 15, 15, u, graphics);
	this->letras.putInt(16 * 11, 16 * 4, 15, 15, d, graphics);
}

void Debugmode::printPlayerLife(int value, Graphics &graphics)
{
	this->letras.putText(16*32, 16, 15, 15, "Life:", graphics);
	this->letras.putInt(16 * 37, 16 , 15, 15, value, graphics);
}

void Debugmode::printPlayerLive(int value, Graphics &graphics)
{
	this->letras.putText(16 * 32, 16*2, 15, 15, "Lives:", graphics);
	this->letras.putInt(16 * 38, 16*2, 15, 15, value, graphics);
}

void Debugmode::printCantEnemies(int value, Graphics &graphics)
{
	this->letras.putText(16 , 16 * 28, 15, 15, "Enemies:", graphics);
	this->letras.putInt(16 * 10, 16 * 28, 15, 15, value, graphics);
}

void Debugmode::printCantEntities(int cant, Graphics &graphics)
{
	this->letras.putText(16, 16 * 27, 15, 15, "Entities:", graphics);
	this->letras.putInt(16 * 10, 16 * 27, 15, 15, cant, graphics);
}

void Debugmode::printCantBullets(int value, Graphics &graphics)
{
	this->letras.putText(16, 16 * 26, 15, 15, "Bullets:", graphics);
	this->letras.putInt(16 * 10, 16 * 26, 15, 15, value, graphics);
}

void Debugmode::printPlayerHitboxes(int u, int d, int l, int r, Graphics &graphics)
{
	int i;
	for (i = l; i < r; i++)
	{
		if (i == l)
		{
			this->letras.putText(l, u, 5, 5, "╔", graphics);
			this->letras.putText(l, d, 5, 5, "╚", graphics);
		}
		else
		if (i == r)
		{
			this->letras.putText(r, u, 5, 5, "╔", graphics);
			this->letras.putText(r, d, 5, 5, "╚", graphics);
		}
		else
		{
			this->letras.putText(i, u, 5, 5, "╗", graphics);
			this->letras.putText(i, d, 5, 5, "╝", graphics);
		}
	}
	for (i = u; i < d; i++)
	{
		if (i == u)
		{
			this->letras.putText(l, u, 5, 5, "╔", graphics);
			this->letras.putText(r, u, 5, 5, "╗", graphics);
		}
		else
		if (i == d)
		{
			this->letras.putText(l, d, 5, 5, "╚", graphics);
			this->letras.putText(r, d, 5, 5, "╝", graphics);
		}
		else
		{
			this->letras.putText(l, i, 5, 5, "║", graphics);
			this->letras.putText(r, i, 5, 5, "║", graphics);
		}
	}
}

void Debugmode::printEntitiesHitboxes(EnemyList enemylist, Graphics &graphics)
{

}

void Debugmode::showOptions(Graphics &graphics)
{
	this->letras.putText(16 * 4, 16 * 4, 15, 15, "F1: Hold for view this menu.", graphics);
	this->letras.putText(16 * 4, 16 * 6, 15, 15, "F2: View X-Y player position.", graphics);
	this->letras.putText(16 * 4, 16 * 8, 15, 15, "F3: View X-Y player center.", graphics);
	this->letras.putText(16 * 4, 16 * 10, 15, 15, "F4: View X-Y player hitboxes", graphics);
	this->letras.putText(16 * 4, 16 * 12, 15, 15, "F5: View player's life.", graphics);
	this->letras.putText(16 * 4, 16 * 14, 15, 15, "F6: View player's lives.", graphics);
	this->letras.putText(16 * 4, 16 * 16, 15, 15, "F7: View bullet counter.", graphics);
	this->letras.putText(16 * 4, 16 * 18, 15, 15, "F8: View entities counter.", graphics);
	this->letras.putText(16 * 4, 16 * 20, 15, 15, "F9: View enemies counter.", graphics);
	this->letras.putText(16 * 4, 16 * 22, 15, 15, "F10:View player's hitboxes.", graphics);
	this->letras.putText(16 * 4, 16 * 24, 15, 15, "F11:View all entities", graphics);
	this->letras.putText(16 * 4, 16 * 25, 15, 15, "    hitboxes (work in progress).", graphics);
	this->letras.putText(16 * 4, 16 * 26, 15, 15, "F12:All options (view everyting)", graphics);
	this->letras.putText(16 * 4, 16 * 27, 15, 15, "    (work in progress).", graphics);

	this->letras.putText(16, 16 * 28, 15, 15, "Use arrows or WASD for move", graphics);
	this->letras.putText(16, 16 * 29, 15, 15, "and X or K for shoot", graphics);
}

int counterframesmenu=0;

void Debugmode::showMenuOptions(int tiempo,Graphics &graphics)
{
	if (counterframesmenu <= tiempo)
	{
		this->letras.putText(16 * 7, 16 * 10, 15, 15, "Hold F1 for debug options.", graphics);
		counterframesmenu++;
	}
}

void Debugmode::printAll(int entities, int enemies, int bullets, int plife, int plives, int x, int y, int u, int d, int l, int r, Graphics &graphics)
{
	this->showMenuOptions(60 * 3, graphics);

	if (this->viewOptions)
	{
		this->showOptions(graphics);
	}

	if (this->showCantEntities)
	{
		this->printCantEntities(entities, graphics);
	}

	if (this->showCantEnemies)
	{
		this->printCantEnemies(enemies, graphics);
	}

	if (this->showCantBullets)
	{
		this->printCantBullets(bullets, graphics);
	}

	if (this->showPlayerXY)
	{
		this->printPlayerXY(x, y, graphics);
	}

	if (this->showPlayerCenter)
	{
		this->printPlayerCenter((x + r) / 2, (y + d) / 2, graphics);
	}

	if (this->showPlayerCenterPoint)
	{
		this->printPlayerCenterPoint((x + r) / 2, (y + d) / 2, graphics);
	}

	if (this->showPlayerHitboxes)
	{
		this->printPlayerHitboxes(u, d, l, r, graphics);
	}

	if (this->showPlayerHitboxesXY)
	{
		this->printPlayerHitboxesXY(u, d, l, r, graphics);
	}

	if (this->showEntitiesHitboxes)
	{
		//this->printEntitysHitboxes(EnemyList enemylist, graphics);
	}

	if (showPlayerLife)
	{
		this->printPlayerLife(plife, graphics);
	}

	if (showPlayerLive)
	{
		this->printPlayerLive(plives, graphics);
	}

}

