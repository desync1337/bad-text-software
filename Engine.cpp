#include "Engine.h"

#include "sidebar.h"
#include "Panel.h"
#include "TextPanel.h"

#include <iostream>

using namespace sf;

RenderWindow* Engine::window = nullptr;

//OBJECTS 
sidebar SideBar;
Panel panel;
TextPanel textpanel;

//GLOBALS
std::string openedtab;



void Engine::initializeVariables()
{
	//this->window = nullptr;
}

void Engine::initWindow()
{

	videoMode.height = 800;
	videoMode.width = 1400;


	//this->videoMode.getDesktopMode; /  get the dimenstions of screen

	this->window = new sf::RenderWindow(this->videoMode, "fucking hell", Style::Titlebar | Style::Close);

	this->window->setFramerateLimit(60);
}

void Engine::initUI()
{
	SideBar.init();
}

//Constructors / Destructors

Engine::Engine()
{
	this->initializeVariables();
	this->initWindow();
	this->initUI();
}

Engine::~Engine() // this prevents memory leaks!!
{
	delete this->window;
}

//Functions

const bool Engine::getWindowIsOpen() const
{
	return this->window->isOpen();
}

void Engine::textpanelClose()
{
	textpanel.rect.setPosition(sf::Vector2f(1400, 0));
	textpanel.string.clear();
}

void Engine::textpanelOpen(std::string filename)
{

	textpanel.rect.setPosition(sf::Vector2f(1000, 0));
	textpanel.init(filename);

}

void Engine::panelOpen(std::string filename)
{
	panel.init(filename);
	openedtab = filename;
}

void Engine::PollEvents() // INPUT 
{
	while (this->window->pollEvent(ev))
	{
		switch (ev.type)
		{

			case Event::Closed():
				this->window->close();
				break;

			//case Event::MouseWheelScrolled:
			//	SideBar.delta = ev.mouseWheelScroll.delta;
			//	SideBar.update();

			case Event::KeyPressed:
				textpanel.input(ev);


			case Event::MouseButtonReleased:
				if(ev.mouseButton.button == sf::Mouse::Left)
				{
				
				sf::Vector2f clickposition = sf::Vector2f(ev.mouseButton.x, ev.mouseButton.y);

				SideBar.mousepos = sf::Vector2f(clickposition);
				SideBar.update();
				textpanel.update(clickposition);
				panel.notepresscheck(clickposition);
				
				}

		}
	}
}

void Engine::update()
{
	PollEvents();
}

void Engine::render()
{
	this->window->clear(sf::Color::Transparent);

	SideBar.draw();
	panel.drawnotes();
	textpanel.draw();

	this->window->display();
}

