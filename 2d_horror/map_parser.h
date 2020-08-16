#pragma once
#include<SFML/Graphics.hpp>
#include<sstream>
#include<vector>
#include<fstream>

class Map_parser{
private:
	std::vector <std::vector<sf::Vector2i>> map;
public:
	std::vector <std::vector<sf::Vector2i>> parseMap(std::string);
};