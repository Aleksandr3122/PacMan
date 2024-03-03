#pragma once
//#include <iostream>
#include "SFML/Graphics.hpp"
struct Point2d
{
	int x = 0;
	int y = 0;
};

struct bound4i
{
	int x = 0;
	int y = 0;
	int width = 0;
	int height = 0;	
	Point2d a,b,c,d;
};
struct bound4f
{
	float x = 0.0;
	float y = 0.0;
	float width = 0.0;
	float height = 0.0;
};

class Cobject
{
public:
	Cobject();
	Cobject(sf::String str);
	sf::Image image;
	sf::Texture texture;
	sf::Sprite sprite;
	bool create(int width, int height);
	bound4i bound;
private:
	
	
//*******************
	int dirX = 0, dirY = 0;
	int life = 3;
	bool die = false;
	bool anim = false;
	int animFrameCount = 4;
	bool solid = true;
	bool collide = true;
};

