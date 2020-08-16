#include"enemy_easy.h"
#include<iostream>
#include<algorithm>
Enemy_easy::Enemy_easy(){
	cTexture.loadFromFile("graphics/enemy_easy.png");
	characterImage.setTexture(cTexture);
	characterImage.setOrigin(0, 24);
}
void Enemy_easy::movement(Character* character,sf::RenderWindow* window){

	if (col.isCollisionMap(characterImage.getPosition(), source.y)){
		if (source.y == Right)
			source.y = Left;
		else
			source.y = Right;
		velocity = -velocity;	
		}
		characterImage.move(velocity, 0);
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
void Enemy_easy::initialize(){
	characterSpeed = 0.50;
	velocity = characterSpeed;
	source = sf::Vector2i(0, Right);
}