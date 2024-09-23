#pragma once

#include "Note.h"
#include "Engine.h"
#include <vector>
#include <string>

class Panel
{

private:

	
	sf::RectangleShape rect;

	std::vector<Note> strings; 

public:

	std::vector<sf::Vector3f> positions;
	

	void init(std::string filename);
	void notepresscheck(sf::Vector2f pos);
	void clearpanel();
	void drawnotes();

};

