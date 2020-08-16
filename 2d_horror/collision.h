#pragma once
#include<SFML/Graphics.hpp>

class Collision{
private:
	std::vector <std::vector<sf::Vector2i>> map;
public:
	int i;
	sf::Vector2i tile_location;
	sf::Vector2i next_tile1;
	sf::Vector2i next_tile2;
	int isCollisionMap(sf::Vector2f, int);
	int isInteractionMap(sf::Vector2f, int);
	
};