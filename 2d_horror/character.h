#pragma once
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include"collision.h"

class Character{
private:
public:
	enum Direction{ Down, Left, Right, Up };
	float bottom, left, right, top;
	float frameCounter = 0, frameSpeed = 1000, switchFrame = 100;
	sf::Texture cTexture;
	sf::Clock clock;
	sf::SoundBuffer soundbuffer_beep, soundbuffer_dead;
	sf::Sound beep_sound, dead_sound;

	std::vector<sf::Vector2i> tiles;
	sf::Vector2i source;
	sf::Sprite characterImage;
	float characterSpeed;
	Collision col;
	void setPosition(int,int);
	virtual void movement(sf::RenderWindow*);
	virtual void movement(Character*,sf::RenderWindow*);
	std::vector<sf::Vector2i> update();
	int isCollisionCharacter(Character*);
};