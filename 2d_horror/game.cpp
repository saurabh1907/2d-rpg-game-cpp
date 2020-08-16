#include"game.h"
#include<iostream>

Game::Game(){
	//whatever comes here is executed only once
}
void Game::update(sf::RenderWindow* window){

	switch (current_room){
	case 1:{
		if (room1.load.map.size() == 0){
			room1.load.initializeMap("map1.txt", "texture.png");
			room1.tile_location = sf::Vector2i(15, 19);
			npc.setPosition(546, 236);
			npc.initialize();
		}

		if (active_object != current_room){
			player.setPosition(room1.tile_location.x * 32 + 4, room1.tile_location.y * 32 + 4);
			dialogue = "Bruce Phillips is a paranormal investigator who is called \nto investigate this old mansion.\n\nThere are reports of numerous murders and suicides in house.\n\nObjective: Free the house from Evil Forces.\n\n\t\t\t\t\t*Press spacebar to dismiss*";
			active_object = current_room;
		}

		current_room = room1.execute(&player, current_room, window);

		if (npc.characterImage.getPosition().y < 644)
			npc.movement(&player, window);

		if (game_state == 0){
			room1.load.map.clear();
			active_object = 0;
		}
		break;
	}
	case 2:{
		if (room2.load.map.size() == 0){
			room2.load.initializeMap("map2.txt", "texture.png");
			room2.tile_location = sf::Vector2i(11,8);
		}
		if (active_object != current_room){
			player.setPosition(room2.tile_location.x*32+4,room2.tile_location.y*32+4);
			dialogue = "Bruce:\n\tAlfred seems pretty scared.\n\tI should find out whats going on in the Mansion.\n\n\n\n\n\t\t\t\t\t*Press spacebar to dismiss*";
			active_object = current_room;
		}

		current_room = room2.execute(&player, current_room, window);

		if (game_state == 0){
			room2.load.map.clear(); active_object = 0;
		}
		break;
	}
	case 3:{
		if (room3.load.map.size() == 0){
			room3.load.initializeMap("map3.txt", "texture.png");
			room3.tile_location = sf::Vector2i(25, 6);
		}
		if (active_object != current_room){
			//dialogue = "room3";
			player.setPosition(room3.tile_location.x * 32 + 4, room3.tile_location.y * 32 + 4);
			active_object = current_room;
		}

		current_room = room3.execute(&player, current_room, window);

		if (game_state == 0){
			room3.load.map.clear(); active_object = 0;
		}
		break;
	}
	case 4:{
		if (room4.load.map.size() == 0){
			room4.load.initializeMap("map4.txt", "texture.png");
			room4.tile_location = sf::Vector2i(15, 4);
		}

		if (active_object != current_room){
			player.setPosition(room4.tile_location.x * 32 + 4, room4.tile_location.y * 32 + 4);
			dialogue = "Bruce:\n\tThe room seems to have contains broken surfaces\n\tI should be carefull !!";
			active_object = current_room;
		}

		current_room = room4.execute(&player, current_room, window);

		if (game_state == 0){
			room4.load.map.clear(); active_object = 0;
		}
		break;
	}
	case 5:{
		if (room5.load.map.size() == 0){
			room5.load.initializeMap("map5.txt", "texture.png");
			room5.tile_location = sf::Vector2i(16, 17);
		}
		if (active_object != current_room){
			player.setPosition(room5.tile_location.x * 32 + 4, room5.tile_location.y * 32 + 4);

			ghost1easy.setPosition(196, 452);
			ghost1easy.initialize();

			ghost2easy.setPosition(196, 324);
			ghost2easy.initialize();

			ghost3easy.setPosition(292, 228);
			ghost3easy.initialize();

			ghost1medium.setPosition(292, 228);
			ghost1medium.initialize();

			ghost2medium.setPosition(676, 164);
			ghost2medium.initialize();
			
			ghost3medium.setPosition(516, 128);
			ghost3medium.initialize();

			dialogue = "Bruce:\n\tI can feel the presence of evil forces in the room\n\n\tI must not come in contact with them.\n\n\n\n\t\t\t\t\t*Press spacebar to dismiss*";
			active_object = current_room;
		}
		current_room = room5.execute(&player, current_room, window);

		ghost1easy.movement(&player, window);
		ghost2easy.movement(&player, window);
		ghost3easy.movement(&player, window);
		ghost1medium.movement(&player, window);
		ghost2medium.movement(&player, window);
		ghost3medium.movement(&player, window);

		if (game_state == 0){
			room5.load.map.clear(); active_object = 0;
		}
		break;
	}
	case 6:{
		if (room6.load.map.size() == 0){
			room6.load.initializeMap("map6.txt", "texture.png");
			room6.tile_location = sf::Vector2i(16, 4);
		}
		if (active_object != current_room){
			player.setPosition(room6.tile_location.x * 32 + 4, room6.tile_location.y * 32 + 4);

			ghost1easy.setPosition(356, 388);
			ghost1easy.initialize();

			ghost2easy.setPosition(324, 516);
			ghost2easy.initialize();

			ghost3easy.setPosition(420, 260);
			ghost3easy.initialize();

			ghost1medium.setPosition(740, 132);
			ghost1medium.initialize();

			ghost2medium.setPosition(388, 132);
			ghost2medium.initialize();

			ghost3medium.setPosition(612, 164);
			ghost3medium.initialize();

			//dialogue = "room6";
			active_object = current_room;
		}
		current_room = room6.execute(&player, current_room, window);

		ghost1easy.movement(&player, window);
		ghost2easy.movement(&player, window);
		ghost3easy.movement(&player, window);
		ghost1medium.movement(&player, window);
		ghost2medium.movement(&player, window);

		if (game_state == 0){
			room6.load.map.clear(); active_object = 0;
		}
		break;
	}
	case 7:{
		if (room7.load.map.size() == 0){
			room7.load.initializeMap("map7.txt", "texture.png");
			room7.tile_location = sf::Vector2i(16, 14);
		}

		if (active_object != current_room){
			player.setPosition(room7.tile_location.x * 32 + 4, room7.tile_location.y * 32 + 4);
			//dialogue = "room7";
			active_object = current_room;
		}

		current_room = room7.execute(&player, current_room, window);

		if (game_state == 0){
			room7.load.map.clear(); active_object = 0;
		}
		break;
	}
	case 8:{
		if (room8.load.map.size() == 0){
			room8.load.initializeMap("map8.txt", "texture.png");
			room8.tile_location = sf::Vector2i(28, 11);
		}
		if (active_object != current_room){
			player.setPosition(room8.tile_location.x * 32 + 4, room8.tile_location.y * 32 + 4);

			boss.setPosition(838, 228);

			dialogue = "Bruce\n\tThe Devil is somewhere around,\n\tthe EMF meter starts beeping when he comes close.\n\tUse this to stay away from him\n\tObjective: Dig the ground to take out Devil's corpse and destroy it";
			active_object = current_room;
		}
		current_room = room8.execute(&player, current_room, window);

		boss.movement(&player, window);

		if (game_state == 0){
			room8.load.map.clear(); active_object = 0;
			player.is_mattock = false; room8.count = 0;
		}
		break;
	}
	}
	player.movement(window);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		dialogue = "";
	if (dialogue.length() != 0)
		speech.write(dialogue, player.characterImage.getPosition(), window);
}