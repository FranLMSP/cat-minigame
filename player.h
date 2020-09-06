#ifndef PLAYER_H
#define PLAYER_H

#include "globals.h"

#include "elementlist.h"
#include "haryball.h"

#define MAXLIFE 100

/*
	state 1: Normal
	state 2: Attack
	state 3: Invulnerable
	state 4: dead
*/

class Player : public Element
{
public:
	Player();
	~Player();

	void init(Graphics &graphics, std::string path);

	void moveUp();
	void moveDown();
	void moveLeft();
	void moveRight();
	void speedUp(char cant);
	void attack();
	void hurt(int damage);
	void dead();

	void reloadAttack(int frames);
	void releasedKey(bool rel);
	void update();

	int getLife();
	int getMaxLife();
	int getLives();

	int getCantBullets() { return this->balas.size(); }

	bool _visible;

	Sprite sprite;
	//Lista balas;
	list<HaryBall*> balas;
	Sprite spriteBalas;

	void updateBullets();
	void drawBullets(Graphics &graphics);

private:
	int life,lives,speed;
	char state;
	bool _releasedKey=true;
	
protected:


};

#endif // !PLAYER_H