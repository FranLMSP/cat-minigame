#include "haryball.h"
#include "graphics.h"
#include "globals.h"

HaryBall::HaryBall()
{

}

/*void HaryBall::initHary(int x, int y)
{
	this->x = x;
	this->y = y;
	this->source.x = 0;
	this->source.y = 0;
	this->source.w = 15;
	this->source.h = this->source.w;
	this->dest.x = (int(this->x*globals::SPRITE_SCALE));
	this->dest.y = (int(this->y*globals::SPRITE_SCALE));
	this->dest.w = 15 * globals::SPRITE_SCALE;
	this->dest.h = this->source.w;
}*/


void HaryBall::updateHary()
{
	this->moveHary(5);
	this->setDest();
	
	if (this->limits())
	{
		this->deleteFromList = true;
	}
}

void HaryBall::moveHary(int speed)
{
	this->setX(this->getX() + speed);
}

HaryBall::~HaryBall()
{
	
}