#pragma once
#include<SFML/Graphics.hpp>
#include"player.h"
#include"level.h"
#include"enemy_easy.h"
#include"enemy_medium.h"
#include"enemy_boss.h"
#include"npc.h"
#include"speech.h"

class Game{
private:
	int current_room=1, active_object = 0;
	Player player;
	Npc npc;
	Enemy_easy ghost1easy, ghost2easy, ghost3easy;
	Enemy_medium ghost1medium, ghost2medium,ghost3medium;
	Enemy_boss boss;
	Speech speech;
	Level room1, room2, room3, room4, room5, room6, room7, room8;
	
public:
	Game();
	void update(sf::RenderWindow*);
};