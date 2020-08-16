#pragma once
#include<SFML/Graphics.hpp>
#include"character.h"
#include"level.h"

class Npc :public Character{
private:
public:
	float velocity;
	Npc();
	enum state{ standing,counting, moving };
	int state = standing;
	sf::Clock clock1;
	void initialize();
	void movement(Character*,sf::RenderWindow*);
};