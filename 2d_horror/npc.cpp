#include"npc.h"
#include<iostream>
#include<algorithm>
Npc::Npc(){
	cTexture.loadFromFile("graphics/servent.png");
	characterImage.setTexture(cTexture);
	characterImage.setOrigin(0, 24);
}
void Npc::movement(Character* player, sf::RenderWindow* window){

	if (isCollisionCharacter(player) && state == standing){
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)){
			clock1.restart();
			state = counting;
			dialogue = "Alfred:\n\tGood Evening Mr. Philips.\n\tI have been expecting you.You are our only hope to stop the devil\n\tBe careful !!";
		}
	}
	if (state == counting){
	if (clock1.getElapsedTime().asSeconds() > 6.0f)
		dialogue = "Alfred:\n\tTake the Laltern. The electricity lines have been broken.";
		if (clock1.getElapsedTime().asSeconds() > 10){
			dialogue = "Alfred:\n\tIts getting dark. I should leave.\n\n\n\n\n\n\t\t\t\t\t*Press spacebar to dismiss*";
			state = moving;
		}
	}
	if (state == moving){
		if (characterImage.getPosition().x > 480){
			source.y = Left;
			characterImage.move(-velocity, 0);
		}
		else if (characterImage.getPosition().y < 645){
			source.y = Down;
			characterImage.move(0, velocity);
		}
		frameCounter += frameSpeed * clock.restart().asSeconds();
		if (frameCounter > switchFrame){
			frameCounter = 0;
			source.x++;
			if (source.x * 24 >= cTexture.getSize().x)
				source.x = 0;
		}
	}
	characterImage.setTextureRect(sf::IntRect(source.x * 24, source.y * 48, 24, 48));
	(*window).draw(characterImage);
}
void Npc::initialize(){
	characterSpeed = 0.50;
	velocity = characterSpeed;
	source = sf::Vector2i(0, Down);
}