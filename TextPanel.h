#pragma once

#include <string>
#include "Engine.h"
#include <fstream>
#include <iostream>

class TextPanel
{

private:


public:

	sf::RectangleShape rect;
	sf::RectangleShape cursorrect;

	sf::Text text;
	sf::Font font;

	std::string string;

	std::string name;

	void init(std::string filename);
	void input(sf::Event ev);
	void update(sf::Vector2f clickpos);

	void createnote();
	void savetext(std::string filename);

	void draw();
};

