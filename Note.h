#pragma once

#include "Engine.h"

class Note
{

private:

public:

	sf::RectangleShape rect;

	sf::Text text;
	sf::Font font;

	std::string name;
	int offset;

	void init();
	void draw();

};

