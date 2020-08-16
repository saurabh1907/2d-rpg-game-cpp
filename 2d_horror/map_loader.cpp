#include"map_loader.h"
#include"map_parser.h"

void Map_loader::initializeMap(std::string filename, std::string tname){
	Map_parser obj;
	map = obj.parseMap(filename);
	texture.loadFromFile("graphics/"+tname);
	sprite.setTexture(texture);
}
void Map_loader::drawMap(sf::RenderWindow *window){
	for (int i = 0; i < map.size(); i++){
		for (int j = 0; j < map[i].size(); j++){
			if (map[i][j].x != -1 && map[i][j].y != -1){
				animate(i, j);
				sprite.setPosition(j * 32, i * 32);
				sprite.setTextureRect(sf::IntRect(map[i][j].x * 32, map[i][j].y * 32, 32, 32));
				(*window).draw(sprite);

			}
		}
	}
}
void Map_loader::animate(int row,int column){
	std::srand(std::time(NULL));
	if (map[row][column].x >= anime_startIndex && map[row][column].y > 0){
		
		if (std::rand() % 2){
			map[row][column].y = (map[row][column].y + 1)%4;
			if (map[row][column].y == 0)map[row][column].y = 1;
		}
	}
	}
std::vector <std::vector<sf::Vector2i>> Map_loader::getMap(){
	return map;
}