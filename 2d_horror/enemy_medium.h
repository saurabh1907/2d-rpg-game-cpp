#pragma once
#include<SFML/Graphics.hpp>
#include"character.h"
#include"level.h";

class Enemy_medium :public Character{
private:
public:
	float velocity;
	Enemy_medium();
	void initialize();
	void movement(Character*, sf::RenderWindow*);
};