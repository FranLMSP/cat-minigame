#ifndef BULLET_H
#define BULLET_H

#include "element.h"

class Bullet : public Element
{
public:
	bool limits();
	bool collision(Element &element);
};

#endif