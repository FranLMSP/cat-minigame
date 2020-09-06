#include "sprite.h"
#include "graphics.h"

Sprite::Sprite()
{
	this->spriteSheet = nullptr;
}

Sprite::Sprite(Graphics &graphics, std::string path,RGB_Color*Color)
{
	this->spriteSheet = SDL_CreateTextureFromSurface(graphics.getRenderer(), graphics.loadImage(path.c_str(),Color));
}

void Sprite::loadSprite(Graphics &graphics, std::string path, RGB_Color*Color)
{
	this->spriteSheet = SDL_CreateTextureFromSurface(graphics.getRenderer(), graphics.loadImage(path.c_str(), Color));
}

void Sprite::draw(Graphics &graphics, SDL_Rect *sourceRect,SDL_Rect *destinationRect)
{
	graphics.blitSurface(this->spriteSheet, sourceRect, destinationRect);
}

Sprite::~Sprite()
{
	SDL_DestroyTexture(this->spriteSheet);
}