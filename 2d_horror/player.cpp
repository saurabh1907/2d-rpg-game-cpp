#include"player.h"
#include<iostream>
#include<algorithm>
Player::Player(){
	cTexture.loadFromFile("graphics/player.png");
	characterImage.setTexture(cTexture);
	characterImage.setOrigin(0, 24);
	characterSpeed = 1.0;
	source = sf::Vector2i(0, Up);
	view.zoom(0.5);

	soundbuffer_door.loadFromFile("audio/open_door.wav");
	door_sound.setBuffer(soundbuffer_door);
	soundbuffer_object.loadFromFile("audio/sfx_pick.flac");
	object_sound.setBuffer(soundbuffer_object);
	soundbuffer_dead.loadFromFile("audio/dead.ogg");
	dead_sound.setBuffer(soundbuffer_dead);
	soundbuffer_end.loadFromFile("audio/end.ogg");
	end_sound.setBuffer(soundbuffer_end);
	soundbuffer_beep.loadFromFile("audio/beep.wav");
	beep_sound.setBuffer(soundbuffer_beep);
}
void Player::movement(sf::RenderWindow* window){
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
		source.y = Down;
		if (!col.isCollisionMap(characterImage.getPosition(), source.y))
		characterImage.move(0, characterSpeed);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
		source.y = Left;
		if (!col.isCollisionMap(characterImage.getPosition(), source.y))
		characterImage.move(-characterSpeed, 0);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
		source.y = Right;
		if (!col.isCollisionMap(characterImage.getPosition(), source.y))
		characterImage.move(characterSpeed, 0);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
		source.y = Up;
		if (!col.isCollisionMap(characterImage.getPosition(), source.y))
		characterImage.move(0, -characterSpeed);
	}
	/*if (col.isCollisionMap(update(),source.y)==1)
		characterImage.move(-1,0);
	else if (col.isCollisionMap(update(), source.y) == 2)
		characterImage.move(1, 0);
	else if (col.isCollisionMap(update(), source.y) == 3)
		characterImage.move(0,-1);
	else if (col.isCollisionMap(update(), source.y) == 4)
		characterImage.move(0,1);
	else{
		//view.setCenter(characterImage.getPosition());
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
			source.y = Up;//think about set position method
			characterImage.move(0, -.75);
		}
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
			source.y = Down;
			characterImage.move(0, .75);
		}
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
			source.y = Right;
			characterImage.move(.75, 0);
		}
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
			source.y = Left;
			characterImage.move(-.75, 0);
	}
	}*/
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up) ||
		sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
		frameCounter += frameSpeed * clock.restart().asSeconds();
		if (frameCounter > switchFrame){
			frameCounter = 0;
			source.x++;
			if (source.x * 24 >= cTexture.getSize().x)
				source.x = 0;
		}
	}

	scale_x = (4.0 / 3 * window->getSize().y / window->getSize().x);
	view.setViewport(sf::FloatRect((1-scale_x)/2, 0, scale_x, 1));
	view.setCenter(characterImage.getPosition());
	(*window).setView(view);
	characterImage.setTextureRect(sf::IntRect(source.x * 24, source.y * 48, 24, 48));
	(*window).draw(characterImage);
	if (is_laltern)
	light.lighteffect(characterImage.getPosition(), window);
}