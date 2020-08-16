#pragma once
#include<SFML/Graphics.hpp>

class Speech{
private:
public:
	sf::Font font;
	sf::RectangleShape box;
	sf::Text text;
	Speech();
	sf::Event event;
	sf::String sentence;
	void write(std::string, sf::Vector2f, sf::RenderWindow*);
};