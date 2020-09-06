#include "hud.h"
#include "graphics.h"


void Hud::setNumbs(int x, int y)
{
	for (int i = 0; i < 10; i++)
	{
		this->numbs[i].x = x;
		this->numbs[i].y = y;
		this->numbs[i].w = 15;
		this->numbs[i].h = 15;

		x += 16;
	}
}

void Hud::init(Graphics &graphics)
{
	RGB_Color color = {0,0,0};

	this->sprite.loadSprite(graphics, "dt/hud/hud.pbm", &color);
	this->setNumbs(16, 17);
}

void Hud::putIzq(Graphics &graphics, int x, int y)
{
	SDL_Rect source{0,0,3,46};
	SDL_Rect dest{ (int(x*globals::SPRITE_SCALE)),(int(y*globals::SPRITE_SCALE)),3 * globals::SPRITE_SCALE,46 * globals::SPRITE_SCALE };

	this->sprite.draw(graphics, &source, &dest);
}

void Hud::putDer(Graphics &graphics, int x, int y)
{
	SDL_Rect source{ 4,0,3,46 };
	SDL_Rect dest{ (int(x*globals::SPRITE_SCALE)),(int(y*globals::SPRITE_SCALE)),3 * globals::SPRITE_SCALE,46 * globals::SPRITE_SCALE };

	this->sprite.draw(graphics, &source, &dest);
}

void Hud::putLifeBar(Graphics &graphics, int x, int y, int color)
{
	SDL_Rect source;

	source.y = 0;
	source.w = 1;
	source.h = 46;

	if (color == BLUE)
	{
		source.x = 10;
	}
	else
	if (color == RED)
	{
		source.x = 8;
	}

	SDL_Rect dest{ (int(x*globals::SPRITE_SCALE)),(int(y*globals::SPRITE_SCALE)),3 * globals::SPRITE_SCALE,46 * globals::SPRITE_SCALE };
	this->sprite.draw(graphics, &source, &dest);
}

void Hud::putLife(Graphics &graphics, int x, int y, int color)
{
	SDL_Rect source;

	source.y = 0;
	source.w = 1;
	source.h = 46;

	if (color == BLUE)
	{
		source.x = 14;
	}
	else
	if (color == RED)
	{
		source.x = 12;
	}
	SDL_Rect dest{ (int(x*globals::SPRITE_SCALE)),(int(y*globals::SPRITE_SCALE)),3 * globals::SPRITE_SCALE,46 * globals::SPRITE_SCALE };
	this->sprite.draw(graphics, &source, &dest);
}

void Hud::drawLifeBar(Graphics &graphics, int x, int y, int w, int h,int life, int color)
{
	this->putIzq(graphics, x, y);
	x += 2;
	for (int i = 0; i < w; i++)
	{
		x ++;
		if (i <= life)
		{
			this->putLife(graphics, x, y, color);
		}
		else
		{
			this->putLifeBar(graphics, x, y, color);
		}
	}

	x+=3;
	this->putDer(graphics, x, y);
}



void Hud::drawLives(Graphics &graphics, int lives, int x, int y)
{
	SDL_Rect s;
	SDL_Rect d;

	s.x = 32;
	s.y = 0;
	s.w = 13;
	s.h = 16;

	d.x = (int(x*globals::SPRITE_SCALE));
	d.y = (int(y*globals::SPRITE_SCALE));
	d.w = 13 * globals::SPRITE_SCALE;
	d.h = 16 * globals::SPRITE_SCALE;

	this->sprite.draw(graphics, &s, &d);

	x += 20 * globals::SPRITE_SCALE;
	y += 5 * globals::SPRITE_SCALE;

	s.x = 16;
	s.w = 14;
	s.h = 11;

	d.x = (int(x*globals::SPRITE_SCALE));
	d.y = (int(y*globals::SPRITE_SCALE));
	d.w = 14 * globals::SPRITE_SCALE;
	d.h = 11 * globals::SPRITE_SCALE;

	this->sprite.draw(graphics, &s, &d);

	x += 20 * globals::SPRITE_SCALE;
	y -= 3 * globals::SPRITE_SCALE;

	d.x = (int(x*globals::SPRITE_SCALE));
	d.y = (int(y*globals::SPRITE_SCALE));
	d.w = 15 * globals::SPRITE_SCALE;
	d.h = 15 * globals::SPRITE_SCALE;


	s = this->numbs[lives];
	//source.x += 1000;
	this->sprite.draw(graphics, &s, &d);
}