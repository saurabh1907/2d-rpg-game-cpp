#pragma once
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include"character.h"
#include"light.h"

class Player:public Character{
private:
public:
	sf::View view;
	bool room1_lock=false, room2_lock=true, room3_lock=false, room4_lock=true, room5_lock=true, room6_lock=true, room7_lock=true, room8_lock=true;
	//bool room1_lock = false, room2_lock = false, room3_lock = false, room4_lock = false, room5_lock = false, room6_lock = false, room7_lock = false, room8_lock = false;
	float scale_x;;
	sf::SoundBuffer soundbuffer_object, soundbuffer_door, soundbuffer_end;
	sf::Sound object_sound, door_sound, end_sound;
	bool is_laltern = false, is_mattock=false;
	Light light;
	Player();
	void movement(sf::RenderWindow*);
};