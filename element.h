#ifndef ELEMENT_H
#define ELEMENT_H

#include "globals.h"
#include <SDL2/SDL.h>

class Graphics;
class Sprite;

class Element
{
private:
	int x,y,w,h;
	SDL_Rect source, dest;

public:
	void setElement(int x, int y, int w, int h);

	void setX(int value) { this->x = value; }
	void setY(int value) { this->y = value; }

	int getX() { return this->x; }
	int getY() { return this->y; }
	int getW() { return this->w; }
	int getH() { return this->h; }

	int getHU() { return this->y; }
	int getHD() { return this->y + this->h; }
	int getHL() { return this->x; }
	int getHR() { return this->x + this->w; }

	SDL_Rect getSource() { return this->source; }
	SDL_Rect getDest() { return this->dest; }

	void setSource(int x,int y,int w,int h)	{ this->source = { x,y,w,h }; }

	void setSourceX(int value) { this->source.x = value; }
	void setSourceY(int value) { this->source.y = value; }
	void setSourceW(int value) { this->source.w = value; }
	void setSourceH(int value) { this->source.h = value; }

	void setDest();

	void setSourceAndDest(int x, int y, int w, int h);

	void print(Graphics &graphics, Sprite &sprite);

	void SetDelete(bool a) { this->deleteFromList = a; }
	bool deleteFromList = false;
};

#endif // !ELEMENT_H
