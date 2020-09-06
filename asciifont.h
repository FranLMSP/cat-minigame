#ifndef ASCIIFONT_H
#define ASCIIFONT_H

#include "sprite.h"

class Graphics;


class AsciiFont
{
public:
	void init(Graphics &graphics);
	void putText(int x, int y, int w,int h, std::string text,Graphics &graphics);
	void putInt(int x, int y, int w, int h, int value, Graphics &graphics);
private:
	Sprite sprite;
	SDL_Rect character[255];
};

#endif