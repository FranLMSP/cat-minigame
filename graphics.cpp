#include "graphics.h"
#include <iostream>

Graphics::Graphics()
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		std::cout << "Init video error: " << SDL_GetError() << std::endl;;
	}

	SDL_CreateWindowAndRenderer(globals::SCREEN_WIDTH*globals::SPRITE_SCALE,
		globals::SCREEN_HEIGHT*globals::SPRITE_SCALE,SDL_WINDOW_SHOWN, &this->window, &this->renderer);
	SDL_SetWindowTitle(this->window,"Undefined");
}

SDL_Surface* Graphics::loadImage(std::string path, RGB_Color*color)
{
	SDL_Surface *image=NULL;
	image = SDL_LoadBMP(path.c_str());
	if (color != NULL)
	{
		SDL_SetColorKey(image, SDL_TRUE, SDL_MapRGB(image->format, color->r, color->g, color->b));
	}
	if (image == NULL)
	{
		std::cout << "Error loading image: " << path.c_str() << " " << SDL_GetError() << std::endl;
	}
	return image;
}

SDL_Renderer*Graphics::getRenderer()
{
	return this->renderer;
}

void Graphics::blitSurface(SDL_Texture*source, SDL_Rect*sourceRectangle, SDL_Rect*destinationRectangle)
{
	SDL_RenderCopy(this->renderer, source, sourceRectangle, destinationRectangle);
}

void Graphics::clear()
{
	SDL_RenderClear(this->renderer);
}

void Graphics::flip()
{
	SDL_RenderPresent(this->renderer);
}

Graphics::~Graphics()
{
	SDL_DestroyWindow(this->window);
	SDL_DestroyRenderer(this->renderer);
	this->renderer = NULL;
	this->window = NULL;

	SDL_VideoQuit();
}