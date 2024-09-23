#include "Note.h"
#include <iostream>

void Note::init()
{

	rect.setSize(sf::Vector2f(250,75));
	rect.setPosition(sf::Vector2f(offset, Engine::window->getSize().y / 2 - 25));
	rect.setFillColor(sf::Color::Red);
	std::cout << name;

	if (!font.loadFromFile("calibri.ttf")) //FONT
	{
		std::cout << "can't load font" << std::endl;
	}

}

void Note::draw()
{

	sf::Text text; //it just wont draw unless i do this stupid shit!!!
	text.setFont(font);

	text.setString(name);
	text.setCharacterSize(16.0);
	text.setFillColor(sf::Color::Black);

	text.setPosition(rect.getPosition());
	//text.setStyle(sf::Text::Bold);

	Engine::window->draw(rect);
	Engine::window->draw(text);

}
