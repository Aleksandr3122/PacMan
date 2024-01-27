#pragma once
//#include <iostream>
#include "SFML/Graphics.hpp"
class Cobject
{
public:
	Cobject();
	Cobject(sf::String str);
	bool create(int width, int height);


private:
	//***********
	sf::Image image;
	sf::Texture texture;
	sf::Sprite sprite;
//*******************
	int life = 3;
	bool die = false;
	bool anim = false;
	int animFrameCount = 4;
	bool solid = true;
	
};

