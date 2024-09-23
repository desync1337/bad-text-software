#pragma once

#include "Panel.h"
#include "Engine.h"
#include <string>

class Tab
{
	sf::Font font;

private:
	
	
public:

	

	sf::Color color = sf::Color::Green;
	sf::RectangleShape rect;
	std::string name;
	int index;
	int offset = 70;

	bool opened = false;

	void init();
	float lerpf(float from, float to, float fac);
	void checkmouseinside(sf::Vector2f mousepos);
	void draw();


};

