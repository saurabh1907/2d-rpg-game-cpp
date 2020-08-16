#pragma once
#include<SFML/Graphics.hpp>
#include<sstream>
#include<ctime>
#include<fstream>
#include<cstdlib>

class Map_loader{
private:
	sf::Texture texture;
	sf::Sprite sprite;
public:
	int anime_startIndex=21;
	std::vector <std::vector<sf::Vector2i>> map;
	void drawMap(sf::RenderWindow *);
	void initializeMap(std::string, std::string);
	void animate(int,int);
	std::vector <std::vector<sf::Vector2i>> getMap();
};
