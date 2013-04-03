#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include <iostream>
#include <sstream>
using namespace std;


int main()
{
// Create the main window
	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");
// Load a sprite to display
	sf::Texture texture;
	if (!texture.loadFromFile("graphics/test.bmp"))
		return EXIT_FAILURE;
	sf::Sprite sprite(texture);
	
	sf::Font font;
	
	sf::String str;
	//if (!font.loadFromFile("/usr/share/fonts/truetype/freefont/FreeMono.ttf"))
	if (!font.loadFromFile("./fonts/FreeMono.ttf"))
	{
			return EXIT_FAILURE;
	}
	sf::Text text("Fuck off!!", font, 30);
	text.setCharacterSize(30);
	text.setColor(sf::Color::White);
	text.setPosition(0.5, 0.5);
	
	

// Start the game loop
	while (window.isOpen()) {
// Process events
		sf::Event event;
		while (window.pollEvent(event)) {
			
			switch (event.type)
			{
			// window closed
			case sf::Event::Closed:
				window.close();
				break;

			// key pressed
			case sf::Event::KeyPressed:
				if (event.key.alt) str += "ALT + ";
				if (event.key.control) str += "CTRL + ";
				if (event.key.shift) str += "SHIFT + ";
				if (event.key.system) str += "SYST + ";
				if (event.key.code == sf::Keyboard::Return) str.clear();
				break;
				
			case sf::Event::KeyReleased:
				//str.clear();
				break;
				
			case sf::Event::TextEntered:
				str += sf::String(event.text.unicode);
				break;
				
			case sf::Event::MouseButtonPressed:
				if (event.mouseButton.button == sf::Mouse::Left) str += "LM + ";
				if (event.mouseButton.button == sf::Mouse::Right) str += "RM + ";
				if (event.mouseButton.button == sf::Mouse::Middle) str += "MM + ";
				{
					std::string position;
					std::ostringstream stream;
					stream << "(" << event.mouseButton.x <<", " << event.mouseButton.y << ")";
					position = stream.str();
					str += position;
				}
				break;

			// we don't process other types of events
			default:
				break;
				}
		}
// Clear screen
		window.clear();
// Draw the sprite
		//window.draw(sprite);
		
		//cout << text.getString().operator std::string();
		if (!str.isEmpty())
		{
			text.setString(str);
			window.draw(text);
			cout << std::string (str);
		}
// Update the window
		window.display();
	}
	return EXIT_SUCCESS;
}