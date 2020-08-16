#include"character.h"
#include<iostream>
#include<algorithm>
void Character::setPosition(int xPosition,int yPosition){
	characterImage.setPosition(xPosition, yPosition);
}

void Character::movement(sf::RenderWindow* window){}
void Character::movement(Character* character, sf::RenderWindow* window){}

int Character::isCollisionCharacter(Character* character1){
	if (abs(character1->characterImage.getPosition().x - characterImage.getPosition().x) < 24 &&
		abs(character1->characterImage.getPosition().y - characterImage.getPosition().y) < 24) {
		return 1;
	}
	else return 0;
}