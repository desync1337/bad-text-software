#include "Tab.h"

#include <iostream>

#include "Engine.h"



void Tab::init()
{
	std::cout << "initiated: " << name << index << std::endl;

	rect.setSize(sf::Vector2f(260.0, 64.0));
	rect.setFillColor(color);
	rect.setPosition(sf::Vector2f(0.0, 0.0 + (offset * index)));


	if (!font.loadFromFile("calibri.ttf"))
	{
		std::cout << "can't load font" << std::endl;
	}

	
}

float Tab::lerpf(float from, float to,float fac)
{

	float num = (to - from) * fac;
	return num;
	
}

void Tab::checkmouseinside(sf::Vector2f mousepos)
{
	sf::Vector2f rectpos = rect.getPosition();
	sf::Vector2f rectsize = rect.getSize();

	if (mousepos.x > rectpos.x && mousepos.x < rectpos.x + rectsize.x)
	{
		if (mousepos.y > rectpos.y && mousepos.y < rectpos.y + rectsize.y)
		{
			//if (opened) return;
			//std::cout << "NIGGER!" << std::endl;
			Engine::panelOpen(name);
			opened = true;

			
		}
	}


}


void Tab::draw()
{

	sf::Text text; //it just wont draw unless i do this stupid shit!!!
	text.setFont(font);

	text.setString(name);
	text.setCharacterSize(16.0);
	text.setFillColor(sf::Color::Red);

	text.setPosition(rect.getPosition());
	//text.setStyle(sf::Text::Bold);

	Engine::window->draw(rect);
	Engine::window->draw(text);
}
