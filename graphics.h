#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <SDL2/SDL.h>
#include "globals.h"

class Graphics
{
public:
	Graphics();
	~Graphics();

	SDL_Surface* loadImage(std::string path,RGB_Color*color);

	SDL_Window*window=NULL;
	SDL_Renderer*renderer=NULL;

	void blitSurface(SDL_Texture*source, SDL_Rect*sourceRectangle, SDL_Rect*destinationRectangle);
	void clear();
	void flip();
	SDL_Renderer*getRenderer();
private:
protected:
};

#endif // !GRAPHICS_H
