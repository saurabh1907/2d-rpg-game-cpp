#pragma once
#include<SFML/Graphics.hpp>
#include<iostream>
#include"player.h"
#include"collision.h"
#include"map_loader.h"

extern std::vector <std::vector<sf::Vector2i>> current_map;
extern int game_state;
extern std::string dialogue;

class Level{
private:

	
public:
	Map_loader load;
	int temp_state = 1;
	Collision collision;
	sf::Clock clock;
	bool in_contact = false;
	int timer=0;
	int count=0;
	sf::Vector2i map_next_tile1;
	sf::Vector2i map_next_tile2;
	sf::Vector2i tile_location;
	int interact_state;
	Level();
	int execute(Player *player,int,sf::RenderWindow*);
	int isDead(Player*);
	int nextRoom(int, int, Player *player);
	void changeTile(int, sf::Vector2i);

};