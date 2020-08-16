#pragma once
#include<SFML/Graphics.hpp>
#include"character.h"
#include"level.h";


class Enemy_boss :public Character {
private:
public:
	Enemy_boss();
	int net_x;
	int net_y;
	void movement(Character*,sf::RenderWindow*);
	int colSpecialTile();
};