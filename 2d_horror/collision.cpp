#include"collision.h"
#include<iostream>
#include"level.h"



int Collision::isCollisionMap(sf::Vector2f cordinates, int direction){

	switch (direction){
	case 0:
		next_tile1 = sf::Vector2i((int)((cordinates.x) / 32), (int)((cordinates.y + 24 + 1) / 32));
		next_tile2 = sf::Vector2i((int)((cordinates.x + 24) / 32), (int)((cordinates.y + 24 + 1) / 32));
		if (current_map[next_tile1.y][next_tile1.x].y > 0 || current_map[next_tile2.y][next_tile2.x].y > 0)
			return 1;
		break;
	case 1:
		next_tile1 = sf::Vector2i((int)((cordinates.x - 1) / 32), (int)((cordinates.y) / 32));
		next_tile2 = sf::Vector2i((int)((cordinates.x - 1) / 32), (int)((cordinates.y + 24) / 32));
		if (current_map[next_tile1.y][next_tile1.x].y > 0 || current_map[next_tile2.y][next_tile2.x].y > 0)
			return 1;
		break;
	case 2:
		next_tile1 = sf::Vector2i((int)((cordinates.x + 24 + 1) / 32), (int)((cordinates.y) / 32));
		next_tile2 = sf::Vector2i((int)((cordinates.x + 24 + 1) / 32), (int)((cordinates.y + 24) / 32));
		if (current_map[next_tile1.y][next_tile1.x].y > 0 || current_map[next_tile2.y][next_tile2.x].y > 0)
			return 1;
		break;
	case 3:
		next_tile1 = sf::Vector2i((int)((cordinates.x) / 32), (int)((cordinates.y - 1) / 32));
		next_tile2 = sf::Vector2i((int)((cordinates.x + 24) / 32), (int)((cordinates.y - 1) / 32));
		if (current_map[next_tile1.y][next_tile1.x].y > 0 || current_map[next_tile2.y][next_tile2.x].y > 0)
			return 1;
		break;
	}
	return 0;
}
//Old collision
/*int Collision::isCollisionMap(std::vector<sf::Vector2i> tiles,int direction){
map = current_map;
if (tiles.size() == 2){

if (map[tiles[0].y][tiles[0].x].y > 0 || map[tiles[1].y][tiles[1].x].y > 0){
if (direction == 0) return 3;
if (direction == 1) return 2;
if (direction == 2) return 1;
if (direction == 3) return 4;
}
}
else if (tiles.size() == 4){

if (map[tiles[0].y][tiles[0].x].y > 0){
if (direction == 3) return 4;
if (direction == 1) return 2;
}
if (map[tiles[1].y][tiles[1].x].y > 0){
if (direction == 2) return 1;
if (direction == 3) return 4;
}
if (map[tiles[2].y][tiles[2].x].y > 0){
if (direction == 0) return 3;
if (direction == 1) return 2;
}
if (map[tiles[3].y][tiles[3].x].y > 0){
if (direction == 0) return 3;
if (direction == 2) return 1;
}
if (map[tiles[0].y][tiles[0].x].y > 0 && map[tiles[1].y][tiles[1].x].y > 0)
if (direction == 3) return 4;
if (map[tiles[0].y][tiles[0].x].y > 0 && map[tiles[2].y][tiles[2].x].y > 0)
if (direction == 1) return 2;
if (map[tiles[3].y][tiles[3].x].y > 0 && map[tiles[1].y][tiles[1].x].y > 0)
if (direction == 2) return 1;
if (map[tiles[2].y][tiles[2].x].y > 0 && map[tiles[3].y][tiles[3].x].y > 0)
if (direction == 0) return 3;
}
return 0;
}*/


int Collision::isInteractionMap(sf::Vector2f cordinates, int direction){
	tile_location = sf::Vector2i((int)((cordinates.x + 12) / 32), (int)((cordinates.y + 12) / 32));
	switch (direction){
	case 0:
		if (current_map[tile_location.y + 1][tile_location.x].y == 1)
			return current_map[tile_location.y + 1][tile_location.x].x;
		break;
	case 1:
		if (current_map[tile_location.y][tile_location.x - 1].y == 1)
			return current_map[tile_location.y][tile_location.x - 1].x;
		break;
	case 2:
		if (current_map[tile_location.y][tile_location.x + 1].y == 1)
			return current_map[tile_location.y][tile_location.x + 1].x;
		break;
	case 3:
		if (current_map[tile_location.y - 1][tile_location.x].y == 1)
			return current_map[tile_location.y - 1][tile_location.x].x;
		break;
	}
	return -1;
}
