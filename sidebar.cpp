#include "sidebar.h"

#include <iostream>
#include <fstream>

#include "Tab.h"


void sidebar::init()
{
	std::ifstream file("Data\\tabs");
	std::string line;

	while (std::getline(file, line)) { // Читаем файл построчно
		
		Tab tab;
		
		tab.name = line;
		tab.index = tabs.size();
		tab.init();
		tabs.push_back(tab);
	}

	rect.setSize(sf::Vector2f(260.0, Engine::window->getSize().y));
	rect.setFillColor(sf::Color::Cyan);
}

void sidebar::update()
{

	for (auto &e : tabs)
	{
		e.checkmouseinside(mousepos);
		e.rect.setPosition(sf::Vector2f(e.rect.getPosition().x, e.rect.getPosition().y + (delta * 10)));
		//sf::Vector2f targetpos = sf::Vector2f(0.0, 0.0 + (e.offset * e.index));
		//e.rect.setPosition(sf::Vector2f( 0.0,e.lerpf(e.rect.getPosition().y, targetpos.y ,  0.1)));
	}

}

void sidebar::draw()
{
	Engine::window->draw(rect);

	for (auto &e : tabs)
	{
		//std::cout << "drawing... " << e.index << std::endl;

		e.draw();
		
	}

}
