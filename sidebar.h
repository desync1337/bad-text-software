#pragma once

#include "Engine.h"
#include <string>

#include "Tab.h"


class sidebar
{

private:
	
	sf::RectangleShape rect;
	sf::Color color;

	std::vector<Tab> tabs;


public:
	
	float delta;
	sf::Vector2f mousepos;

	void init();
	void update();//input
	void draw();
};

