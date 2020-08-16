#pragma once
#include<SFML/Graphics.hpp>
#include"character.h"
#include"level.h";

class Enemy_easy :public Character{
private:
public:
	float velocity;
	Enemy_easy();
	void initialize();
	void movement(Character*,sf::RenderWindow*);
};