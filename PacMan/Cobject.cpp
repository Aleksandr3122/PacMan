#include "Cobject.h"

Cobject::Cobject()
{
	
}

Cobject::Cobject(sf::String str)
{
	this->image.loadFromFile(str);
}

bool Cobject::create(int width, int height)
{
	this->texture.create(width, height);
	texture.loadFromImage(this->image);
	return true;
}
