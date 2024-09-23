#include "Panel.h"
#include "Note.h"
#include "sidebar.h"
#include <fstream>
#include <iostream>

void Panel::init(std::string filename)
{
	clearpanel();

	std::ifstream testfile("Data\\TextLists\\" + filename); //test vars for checking if file exists
	std::string testline;

	if (!std::getline(testfile, testline)) {

		std::cout << "\nERR! No textlist for: " << filename << std::endl;
		Engine::textpanelClose();
		return;
	}

	std::ifstream file("Data\\TextLists\\" + filename);
	std::string line;
	
	int i = 0;
	while (std::getline(file, line)) 
	{ 
		Note note;

		note.name = line;
		note.offset = 300 + (i * 300);

		strings.push_back(note);
		strings.back().init();
		//std::cout << note.offset << std::endl;
		i += 1;
	}
	i = 0;
}

void Panel::notepresscheck(sf::Vector2f pos)
{


	for (auto& e : strings) {

		sf::Vector2f rectpos = e.rect.getPosition();
		sf::Vector2f rectsize = e.rect.getSize();

		if (pos.x > rectpos.x && pos.x < rectpos.x + rectsize.x)
		{
			if (pos.y > rectpos.y && pos.y < rectpos.y + rectsize.y)
			{
				
				std::cout << "pressed on: "<< e.name << std::endl;

				Engine::textpanelOpen(e.name);

			}
		}

	}

}

void Panel::clearpanel()
{
	strings.clear();
}

void Panel::drawnotes()
{

	for (auto &e : strings) {

		e.draw();

	}

}
