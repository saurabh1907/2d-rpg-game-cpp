#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include"game.h"
#include"main_menu.h"
#include"level.h"
#define GAME_WIDTH 1024
#define GAME_HEIGHT 768

int main(){

	sf::RenderWindow window(sf::VideoMode(GAME_WIDTH, GAME_HEIGHT), "Mansion Mystery", sf::Style::Default);
	window.setFramerateLimit(120);
	Main_menu menu;
	menu.initialize(&window);
	Game start;
	sf::Texture bg_texture;
	sf::Sprite bg;
	bg_texture.loadFromFile("graphics/bg.png");
	bg.setTexture(bg_texture);

	sf::Music music;
	music.openFromFile("audio/bg_music.ogg");
	music.setLoop(true);
	music.play();
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed){
				window.close();
				break;
			}
			if (event.type == sf::Event::KeyPressed)
				if (event.key.code == sf::Keyboard::Escape)
					game_state = 2;
			if (event.type == sf::Event::LostFocus){
				game_state = 2;
				music.pause();
			}
			if (event.type == sf::Event::GainedFocus)
				music.play();
		}

		switch (game_state){
		case 0:
			game_state = menu.render(game_state, &window);
			break;
		case 1:
			window.draw(bg);
			start.update(&window);
			break;
		case 2:
			game_state = menu.render(game_state, &window);
			break;
		case 3:
			game_state = menu.render(game_state, &window);
			break;
		case 4:
			game_state = menu.render(game_state, &window);
			break;
		default:
			game_state = menu.loadingScreen(game_state, &window);
			break;
		}

		window.display();
		window.clear();
	}
	return 0;
}