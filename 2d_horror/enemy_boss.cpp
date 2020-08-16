#include"enemy_boss.h"
#include<iostream>
#include<algorithm>
#include<cmath>

Enemy_boss::Enemy_boss(){
	cTexture.loadFromFile("graphics/enemy_boss.png");
	characterImage.setTexture(cTexture);
	characterSpeed = .5;
	characterImage.setOrigin(0, 24);
	source = sf::Vector2i(0, Down);
}
void Enemy_boss::movement(Character* player, sf::RenderWindow* window){
	net_x = player->characterImage.getPosition().x - characterImage.getPosition().x;
	net_y = player->characterImage.getPosition().y - characterImage.getPosition().y;
	
	if (abs(net_x) < abs(net_y)){
		if (net_x > 0){
			source.y = Right;
		}
		else if (net_x < 0){
			source.y = Left;
		}
		else{
			if (net_y > 0){
				source.y = Down;
			}
			else{
				source.y = Up;
			}
		}
		if (!col.isCollisionMap(characterImage.getPosition(), source.y)|| colSpecialTile()){
			if (net_x > 0){
				characterImage.move(characterSpeed, 0);
			}
			else if (net_x < 0){
				characterImage.move(-characterSpeed, 0);
			}
			else{
				if (net_y > 0){
					characterImage.move(0, characterSpeed);
				}
				else{
					characterImage.move(0, -characterSpeed);
				}
			}
		}
		else
		{
			if (source.y == Right || source.y == Left){
				if (net_y > 0){
					source.y = Down;
				}
				else {
					source.y = Up;
				}
			}
			if (!col.isCollisionMap(characterImage.getPosition(), source.y) || colSpecialTile()){
				if (net_y > 0){
					characterImage.move(0, characterSpeed);
				}
				else {
					characterImage.move(0, -characterSpeed);
				}
			}
		}
	}
	else
	{
		if (net_y > 0){
			source.y = Down;
		}
		else if (net_y < 0){
			source.y = Up;
		}
		else{
			if (net_x > 0){
				source.y = Right;
			}
			else{
				source.y = Left;
			}
		}
		if (!col.isCollisionMap(characterImage.getPosition(), source.y) || colSpecialTile()){
			if (net_y > 0){
				characterImage.move(0, characterSpeed);
			}
			else if (net_y < 0){
				characterImage.move(0, -characterSpeed);
			}
			else{
				if (net_x > 0){
					characterImage.move(characterSpeed, 0);
				}
				else {
					characterImage.move(-characterSpeed, 0);
				}
			}
		}
		else
		{
			if (source.y == Down || source.y == Up){
				if (net_x > 0){
					source.y = Right;
				}
				else {
					source.y = Left;
				}
			}
			if (!col.isCollisionMap(characterImage.getPosition(), source.y) || colSpecialTile()){
				if (net_x > 0){
					characterImage.move(characterSpeed, 0);
				}
				else {
					characterImage.move(-characterSpeed, 0);
				}
			}
		}
	}
		
		frameCounter += frameSpeed * clock.restart().asSeconds();
		if (frameCounter > switchFrame){
			frameCounter = 0;
			source.x++;
			if (source.x * 24 >= cTexture.getSize().x)
				source.x = 0;
		}
		characterImage.setTextureRect(sf::IntRect(source.x * 24, source.y * 48, 24, 48));
		(*window).draw(characterImage);
		if (isCollisionCharacter(player)){
			player->dead_sound.play();
			game_state = 0;
		}
		if (game_state == 1){
			if (abs(net_x) < 150 && abs(net_y) < 150){
				if (!player->beep_sound.getStatus()){
					//player->beep_sound.setPlayingOffset(sf::seconds(3.0f));
					player->beep_sound.play();
				}
			}
			else
				player->beep_sound.stop();
		}
		else
			player->beep_sound.stop();

	}
	int Enemy_boss::colSpecialTile(){
		if ((current_map[col.next_tile1.y][col.next_tile1.x].y>0 && current_map[col.next_tile1.y][col.next_tile1.x].x != 13) ||
			( current_map[col.next_tile2.y][col.next_tile2.x].y>0 && current_map[col.next_tile2.y][col.next_tile2.x].x != 13))
			return 0;//cannot pass	
		return 1; //can pass
	}