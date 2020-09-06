#ifndef SPRITE_H
#define SPRITE_H

#include <SDL2/SDL.h>
#include "globals.h"

class Graphics;

class Sprite
{
public:
	Sprite();
	Sprite(Graphics &graphics,std::string path,RGB_Color*color);
	~Sprite();

	void loadSprite(Graphics &graphics, std::string path, RGB_Color*color);

	void draw(Graphics &graphics, SDL_Rect *sourceRect, SDL_Rect *destinationRect);

private:
	SDL_Texture*spriteSheet=NULL;
protected:
};

#endif
