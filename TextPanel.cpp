#include "TextPanel.h"

bool lowercase = true;
int textcursor = 76;

void TextPanel::init(std::string filename)
{

	rect.setFillColor(sf::Color::Yellow);
	rect.setPosition(sf::Vector2f(1000, 0));
	rect.setSize(sf::Vector2f(400, 1400));

	if (!font.loadFromFile("calibri.ttf")) //FONT
	{
		std::cout << "can't load font" << std::endl;
	}

	std::ifstream testfile("Data\\TextLists\\Texts\\" + filename); //test vars for checking if file exists
	std::string testline;

	if (!std::getline(testfile, testline)) {

		std::cout << "\nERR! No textlist for: " << filename << std::endl;
		Engine::textpanelClose();
		return;
	}

	std::ifstream file("Data\\TextLists\\Texts\\" + filename);
	std::string line;

	string.clear();

	int i = 0;
	while (std::getline(file, line))
	{
		string.append(line + "\n");
		
		i += 1;
	}
	i = 0;


	name = filename;
	textcursor = string.size();
	std::cout << textcursor << std::endl;

	cursorrect.setSize(sf::Vector2f(6, 16));
	cursorrect.setFillColor(sf::Color::Red);
	


}

void TextPanel::input(sf::Event ev)
{
	
	if (ev.key.control)
	{
		if (ev.key.code == sf::Keyboard::S)
		{
			savetext(name);
			return;
		}

	}

	if (ev.key.code >= sf::Keyboard::A && ev.key.code <= sf::Keyboard::Z)
	{
		if (lowercase)
			string += static_cast<char>('a' + (ev.key.code - sf::Keyboard::A));
		else
			string += static_cast<char>('A' + (ev.key.code - sf::Keyboard::A));
	}

	if (ev.key.shift) // everything with shift pressed
	{


		if (ev.key.code == sf::Keyboard::Enter)
		{
			//endNote();
		}

		//if (ev.key.code >= 27 && ev.key.code <= 30) // symbols!! :3	(!@#$)							  <- this shit cause empty symbols
		//{
		//	string += static_cast<char>('!' + (ev.key.code - sf::Keyboard::Num0 - 1));
		//	return;
		//}
		if (ev.key.code == sf::Keyboard::Slash) //its stupid to add them one by one ,but cant help it!!! 
		{
			string += "?";
			return;
		}

		if (ev.key.code == 56)
		{
			string += "_";
			return;
		}

		if (ev.key.code == 26)
		{
			string += ")";
			return;
		}
		if (ev.key.code == 35)
		{
			string += "(";
			return;
		}

		if (ev.key.code == 48)
		{
			string += ":";
			return;
		}

	}

	else
	{
		if (ev.key.code == sf::Keyboard::Backspace && string.size() > 0)
		{
			string.pop_back();
		}

		if (ev.key.code == sf::Keyboard::Space) //space
		{
			string += " ";
		}

		if (ev.key.code == sf::Keyboard::Enter) // next row
		{
			string += "\n";
		}
	}
	
	

	textcursor = string.size();
	
	

}

void TextPanel::update(sf::Vector2f clickpos)
{
}

void TextPanel::savetext(std::string filename)
{

	// Create an output file stream
	std::ofstream outFile("Data\\TextLists\\Texts\\" + filename);

	// Check if the file was opened successfully
	if (!outFile) {
		std::cerr << "Error opening file for writing!" << std::endl;
	}

	// Write the string to the file
	outFile << string;

	// Close the file
	outFile.close();
	
	std::cout << "saved..." << std::endl;
}

void TextPanel::draw()
{
	sf::Text text; //it just wont draw unless i do this stupid shit!!!
	text.setFont(font);
	text.setString(sf::String::fromUtf8(string.begin(), string.end()));
	text.setCharacterSize(16.0);
	text.setFillColor(sf::Color::Black);

	text.setPosition(rect.getPosition());
	//text.setStyle(sf::Text::Bold);
	Engine::window->draw(rect);
	Engine::window->draw(text);
	Engine::window->draw(cursorrect);
	
	cursorrect.setPosition(text.findCharacterPos(string.length())); // this is fucking bad i need to do something with this stupid text!!!
}
