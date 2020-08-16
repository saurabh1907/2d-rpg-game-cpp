#include"map_parser.h"


std::vector <std::vector<sf::Vector2i>> Map_parser::parseMap(std::string filename){
	filename = "resources/"+filename;
	std::ifstream openfile(filename);
	std::vector<sf::Vector2i> tempMap;
	map.clear();
	if (openfile.is_open()){
		while (!openfile.eof()){
			std::string str, value;
			std::getline(openfile, str);
			std::stringstream stream(str);
			while (std::getline(stream, value, ' ')){
				if (value.length() > 0){
					std::string xx = value.substr(0, value.find(','));
					std::string yy = value.substr(value.find(',') + 1);
					int x, y, i, j;
					for (i = 0; i < xx.length(); i++){
						if (!isdigit(xx[i]))
							break;
					}
					for (j = 0; j < yy.length(); j++){
						if (!isdigit(yy[j]))
							break;
					}
					x = (i == xx.length()) ? atoi(xx.c_str()) : -1;
					y = (j == yy.length()) ? atoi(yy.c_str()) : -1;
					tempMap.push_back(sf::Vector2i(x, y));
				}
			}
			if (tempMap.size() > 0){
				map.push_back(tempMap);
				tempMap.clear();
			}
		}
	}
	return map;
}
