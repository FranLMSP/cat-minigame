#include "bullet.h"

bool Bullet::limits()
{
	if ((this->getHL() > globals::SCREEN_WIDTH) || (this->getHR() < 0) || (this->getHD() < 0) || (this->getHU() > globals::SCREEN_HEIGHT))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Bullet::collision(Element &element)
{
	if
		((((this->getHR() >= element.getHL()) && (this->getHR() <= element.getHR())) &&
		((this->getHD() >= element.getHU()) && (this->getHD() <= element.getHD())))
			||
			(((this->getHL() >= element.getHL()) && (this->getHL() <= element.getHR())) &&
			((this->getHD() >= element.getHU()) && (this->getHD() <= element.getHD())))
			||
			(((this->getHL() >= element.getHL()) && (this->getHL() <= element.getHR())) &&
			((this->getHU() >= element.getHU()) && (this->getHU() <= element.getHD())))
			||
			(((this->getHR() >= element.getHL()) && (this->getHR() <= element.getHL())) &&
			((this->getHU() >= element.getHU()) && (this->getHU() >= element.getHD()))))
	{
		return true;
	}
	else
	{
		return false;
	}
}