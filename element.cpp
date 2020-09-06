#include "element.h"
#include "graphics.h"
#include "sprite.h"

void Element::setElement(int x, int y, int w, int h)
{
	this->x = x;
	this->y = y;
	this->w = w;
	this->h = h;
	this->setDest();
}

void Element::setDest()
{
	this->dest.x = int(this->x*globals::SPRITE_SCALE);
	this->dest.y = int(this->y*globals::SPRITE_SCALE);
	this->dest.w = int(this->w*globals::SPRITE_SCALE);
	this->dest.h = int(this->h*globals::SPRITE_SCALE);
}

void Element::setSourceAndDest(int x, int y, int w, int h)
{
	this->setSource(x, y, w, h);
	this->setDest();
}

void Element::print(Graphics &graphics, Sprite &sprite)
{
	sprite.draw(graphics, &this->source, &this->dest);
}