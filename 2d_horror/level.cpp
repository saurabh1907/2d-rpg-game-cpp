#include"level.h"
std::vector <std::vector<sf::Vector2i>> current_map;
int game_state = -1;
std::string dialogue = "";


Level::Level(){
}
int Level::execute(Player *player, int room_no, sf::RenderWindow* window){
	current_map = load.getMap();
	load.drawMap(window);
	if (isDead(player)){
		player->dead_sound.play();
		dialogue = "DEAD"; game_state = 0;
	}
	interact_state = collision.isInteractionMap(player->characterImage.getPosition(), player->source.y);
	tile_location = collision.tile_location;
	if (interact_state != 13)
		in_contact = false;

	if (interact_state + 1 != 0){
		if (interact_state == 13){
			if (player->is_mattock){
				if (!in_contact){
					clock.restart();
					in_contact = true;
				}
				if (clock.getElapsedTime().asSeconds() > 3.5){
					count++;
					changeTile(player->source.y, sf::Vector2i(16, 0));
					if (count == 2){
						player->is_mattock = false;
						dialogue = "the mattock broke, find another tool to dig";
					}
				}
				if (count == 4){
					dialogue = "Destroy the corpse";
					changeTile(player->source.y, sf::Vector2i(12, 1));
					//game_state = 5; 

				}
			}
			else
				dialogue = "Find some tool to dig and stand still !!";
		}
		else{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)){
				switch (interact_state){
				case 0:
					player->object_sound.play();
					if (room_no == 3){
						dialogue = "Drawer:\n\tKey found !!\n\n\n\n\n\n\t\t\t\t\t*Press spacebar to dismiss*";
						player->room4_lock = false;
					}
					else if (room_no == 2){
						dialogue = "june 26 1953\n\tA man killed 10 innocent people including\n\twomen and children and then committed suicide.\n\tThe Mansion has never found peace after that !\n\n\tUnfortunate things keep happening.....\n\n\t\t\t\t\t*Press spacebar to dismiss*";
					}
					else
						dialogue = "Drawer : \n\tDrawer is empty.";
					break;
				case 1:
					player->object_sound.play();
					if (room_no == 5){
						player->room6_lock = false;
					}
					if (room_no == 4)
						player->room5_lock = false;
					dialogue = "Chest:\n\tKey found !!";
					changeTile(player->source.y, sf::Vector2i(2, 1));
					break;
				case 2:
					player->object_sound.play();
					break;
				case 3:
					player->object_sound.play();
					if (room_no == 6)
						dialogue = "Police, Priest, Investigator all tried to solve \nthe mystery but none could restore the harmony.\nSome even lost their lives in doing so.\n.\n.\nSome say a Devil lives here !! ";
					break;
				case 4:
					return nextRoom(room_no, 1, player);
					break;
				case 5:
					return nextRoom(room_no, 2, player);
					break;
				case 6:
					return nextRoom(room_no, 3, player);
					break;
				case 7:
					return nextRoom(room_no, 4, player);
					break;
				case 8:
					return nextRoom(room_no, 5, player);
					break;
				case 9:
					return nextRoom(room_no, 6, player);
					break;
				case 10:
					player->object_sound.play();
					if (room_no == 3)
						dialogue = "Diary:\n\tThere are dead souls wandering in the Mansion\n\t.\n\t.\n\tSome force is stopping them to leave the place";
					else if (room_no == 4)
						dialogue = "A hint to open chest.";
					else if (room_no == 7)
						dialogue = "All attempts to save the house has failed.\nThe Devil is strongest in the next room !!\n\nI could either take petrol and burn the \nwhole house down and wish things to be alright.\n\nOr take courage and FIGHT THE DEVIL !!";
					break;
				case 11:
					player->object_sound.play();
					dialogue = "Laltern picked";
					player->is_laltern = true;
					player->room2_lock = false;
					changeTile(player->source.y, sf::Vector2i(-1, -1));
					break;
				case 12:
					player->end_sound.play();
					game_state = 5;
					break;
				case 15:
					player->object_sound.play();
					if (!player->is_mattock){
						dialogue = "Picked Mattock \nUse it to dig the ground!!";
						changeTile(player->source.y, sf::Vector2i(-1, -1));
						player->is_mattock = true;
					}
					else
						dialogue = "Bruce\n\tI already have this tool";
					break;
				case 16:
					player->object_sound.play();
					dialogue = "Picked sword !!";
					changeTile(player->source.y, sf::Vector2i(-1, -1));
					player->room8_lock = false;
					break;
				case 17:
					player->object_sound.play();
					dialogue = "Lever pulled !!";
					for (int i = 0; i < load.map.size(); i++){
						for (int j = 0; j < load.map[i].size(); j++){
							if (load.map[i][j].x == 21){
								load.map[i][j] = sf::Vector2i(21, 0);
							}
						}
					}
					changeTile(player->source.y, sf::Vector2i(17, 2));
					break;
				case 18:
					player->object_sound.play();
					dialogue = "Key Found!!";
					if (room_no == 6)player->room7_lock = false;
					changeTile(player->source.y, sf::Vector2i(-1, -1));
					break;
				case 19:
					player->object_sound.play();
					if (room_no == 7)
						dialogue = "Take your decision wisely as it may result in different endings !!";
					else if (room_no == 8)
						dialogue = "Devil's corpse is burried in the center.\n\nTake the digging tool and stand still to dig.";
					else
						dialogue = "Hint !!";
					changeTile(player->source.y, sf::Vector2i(-1, -1));
					break;
				case 20:
					player->object_sound.play();
					dialogue = "Petrol Picked !!";
					game_state = 6;

					break;
				case 21:
					dialogue = "Dead !!";
					break;
				case 22:
					dialogue = "Dead !!";
					break;
				default:dialogue = "I don't need this.";
					break;
				}
			}
		}
	}
	return room_no;
}

int Level::nextRoom(int current_room, int door_no, Player *player){
	switch (current_room){
	case 1:
		if (door_no == 5){
			if (!player->room1_lock){
				dialogue = "Bruce:\n\tI just came from here.";
				return 1;
			}
		}
		if (door_no == 6)
			if (!player->room2_lock){
				player->door_sound.play();
				return 2;
			}
			else{
				dialogue = "Its about to be dark\nPick the laltern before proceeding";
				return current_room;
			}
			dialogue = "Door Locked !! \nFind 'Key'";
			return current_room;
			break;
	case 2:
		if (door_no == 3)
			if (!player->room3_lock){
				player->door_sound.play();
				return 3;
			}
		if (door_no == 5)
			if (!player->room1_lock){
				player->door_sound.play();
				return 1;
			}
		if (door_no == 1)
			if (!player->room6_lock){
				player->door_sound.play();
				return 6;
			}
		if (door_no == 2)
			if (!player->room7_lock){
				player->door_sound.play();
				return 7;
			}
		dialogue = "Door Locked !! \nFind 'Key'";
		return current_room;
		break;
	case 3:
		if (door_no == 1)
			if (!player->room4_lock){
				player->door_sound.play();
				return 4;
			}
		if (door_no == 2)
			if (!player->room5_lock){
				player->door_sound.play();
				return 5;
			}
		if (door_no == 3)
			if (!player->room2_lock){
				player->door_sound.play();
				return 2;
			}
		dialogue = "Door Locked !! \nFind 'Key'";
		return current_room;
		break;
	case 4:
		if (door_no == 1)
			if (!player->room3_lock){
				player->door_sound.play();
				return 3;
			}
		dialogue = "Door Locked !! \nFind 'Key'";
		return current_room;
		break;
	case 5:
		if (door_no == 1)
			if (!player->room3_lock){
				player->door_sound.play();
				return 3;
			}
		dialogue = "Door Locked !! \nFind 'Key'";
		return current_room;
		break;
	case 6:
		if (door_no == 1)
			if (!player->room2_lock){
				player->door_sound.play();
				return 2;
			}
		dialogue = "Door Locked !! \nFind 'Key'";
		return current_room;
		break;
	case 7:
		if (door_no == 1)
			if (!player->room2_lock){
				player->door_sound.play();
				return 2;
			}
		if (door_no == 3)
			if (!player->room8_lock){
				player->door_sound.play();
				return 8;
			}
			else{
				dialogue = "Take decision before proceeding.";
				return current_room;
			}
			dialogue = "Door Locked !! \nFind 'Key'";
			return current_room;
			break;
	case 8:
		if (door_no == 1)
			if (!player->room8_lock){
				player->door_sound.play();
				return 8;
			}
		dialogue = "You cant't Leave !! ";
		return current_room;
		break;
	}
}
int Level::isDead(Player *player){
	map_next_tile1 = current_map[collision.next_tile1.y][collision.next_tile1.x];
	map_next_tile2 = current_map[collision.next_tile2.y][collision.next_tile2.x];

	if (collision.isCollisionMap(player->characterImage.getPosition(), player->source.y)){
		if (map_next_tile1.y == 1)
			if (map_next_tile1.x == 14 || map_next_tile1.x == 21 || map_next_tile1.x == 22)
				return 1;
		if (map_next_tile2.y == 1)
			if (map_next_tile2.x == 14 || map_next_tile2.x == 21 || map_next_tile2.x == 22)
				return 1;
	}
	return 0;
}

void Level::changeTile(int direction, sf::Vector2i new_tile){
	if (direction == 0)
		load.map[tile_location.y + 1][tile_location.x] = new_tile;
	else if (direction == 1)
		load.map[tile_location.y][tile_location.x - 1] = new_tile;
	else if (direction == 2)
		load.map[tile_location.y][tile_location.x + 1] = new_tile;
	else if (direction == 3)
		load.map[tile_location.y - 1][tile_location.x] = new_tile;
}