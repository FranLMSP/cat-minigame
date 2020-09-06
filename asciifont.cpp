#include "asciifont.h"
#include "graphics.h"

#include <sstream>

void AsciiFont::init(Graphics &graphics)
{
	RGB_Color color{ 255,255,255 };
	this->sprite.loadSprite(graphics, "dt/fnt/asciiNESfont.pbm", &color);

	int x=0, y=0;

	for (int i = 0; i < 255; i++)
	{
		this->character[i].x = x;
		this->character[i].y = y;
		this->character[i].w = 15;
		this->character[i].h = 15;

		x += 16;
		if (x >= 255)
		{
			x = 0;
			y += 16;
		}
	}
}

void AsciiFont::putText(int x, int y,int w,int h, std::string text, Graphics &graphics)
{
	SDL_Rect dest;
	dest.x = int(x*globals::SPRITE_SCALE);
	dest.y = int(y*globals::SPRITE_SCALE);
	dest.w = int(w*globals::SPRITE_SCALE);
	dest.h = int(h*globals::SPRITE_SCALE);
	for (int i = 0;i< text.size(); i++)
	{
		sprite.draw(graphics, &this->character[text[i]], &dest);
		dest.x += int(16 * globals::SPRITE_SCALE);
	}
}

string acadena(int value)
{
	stringstream s;
	s<<value;
	return s.str();
}

void AsciiFont::putInt(int x, int y, int w, int h, int value, Graphics &graphics)
{
	this->putText(x, y, w, h, acadena(value), graphics);
}
