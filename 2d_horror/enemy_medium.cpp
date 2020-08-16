#include"enemy_medium.h"
#include<iostream>
#include<algorithm>
Enemy_medium::Enemy_medium(){
	cTexture.loadFromFile("graphics/enemy_medium.png");
	characterImage.setTexture(cTexture);
	characterImage.setOrigin(0, 24);
}
void Enemy_medium::movement(Character* character, sf::RenderWindow* window){
	if (characterImage.getPosition().y >544){
		source.y = Up;
		velocity = -velocity;
	}
	if (characterImage.getPosition().y <128){
		source.y = Down;
		velocity = -velocity;
	}
	characterImage.move(0,velocity);
	frameCounter += frameSpeed * clock.restart().asSeconds();
	if (frameCounter > switchFrame){
		frameCounter = 0;
		source.x++;
		if (source.x * 24 >= cTexture.getSize().x)
			source.x = 0;
	}
	characterImage.setTextureRect(sf::IntRect(source.x * 24, source.y * 48, 24, 48));
	(*window).draw(characterImage);
	if (isCollisionCharacter(character)){
		character->dead_sound.play();
		game_state = 0;
	}
}
void Enemy_medium::initialize(){
	characterSpeed = 0.60;
	velocity = characterSpeed;
	source = sf::Vector2i(0, Down);
}