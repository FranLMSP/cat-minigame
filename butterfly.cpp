#include "butterfly.h"
#include "graphics.h"
#include "haryball.h"

#include <ctime>

int fc = 0;
int cs = 0;

int random(int min, int max) {
	return (rand() % (max - min + 1) + min);
}

void randomize() {
	srand(time(0));
}

Butterfly::Butterfly()
{
	//randomize();

	this->setElement(globals::SCREEN_WIDTH + 100, random(20, globals::SCREEN_HEIGHT - 80), 82, 76);
	this->setSource(0, 0, 82, 76);
}

void Butterfly::move(int speed)
{
	this->setX(this->getX() - speed);
}


bool Butterfly::limits()
{
	if (this->getX() < -100)
	{
		return true;
	}
	else
	{
		return false;
	}
}


void Butterfly::animation(int dif)
{
	fc++;
	if (fc == dif)
	{
		fc = 0;
		if (cs == 0)
		{
			cs = 1;
			this->setSource(0, 0, this->getW(), this->getH());
		}
		else
		if (cs == 1)
		{
			cs = 0;
			this->setSource(92, 0, this->getW(), this->getH());
		}
	}
	
}

void Butterfly::update()
{
	this->animation(3);
	this->move(6);

	this->setDest();
	if (this->limits())
	{
		this->deleteFromList = true;
	}
		
}


Butterfly::~Butterfly()
{

}