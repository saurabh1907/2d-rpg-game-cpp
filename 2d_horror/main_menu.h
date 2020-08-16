#pragma once
#include<SFML/Graphics.hpp>

class Main_menu
{
private:
	sf::Font font;
	sf::Text title;
	sf::Text text;
	sf::Text quit;
	sf::Text top_text;
	int selected;
	int state;
public:
	void initialize(sf::RenderWindow* window);
	int render(int,sf::RenderWindow* window);
	int loadingScreen(int, sf::RenderWindow* window);

};