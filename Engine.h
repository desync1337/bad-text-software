#pragma once

#include <vector>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>


class Engine
{

private:

	sf::Event ev;
	sf::VideoMode videoMode;


	//Private functions
	void initializeVariables();
	void initWindow();
	void initUI();

public:

	static sf::RenderWindow* window;
	// Constructors / Destructors
	Engine();
	virtual ~Engine();																												 
	const bool getWindowIsOpen() const;			

	//global vars
	///std::string openedtab;


	//func
	static void textpanelClose();
	static void textpanelOpen(std::string filename);
	static void panelOpen(std::string filename);
	void PollEvents();
	void update();
	void render();

};

