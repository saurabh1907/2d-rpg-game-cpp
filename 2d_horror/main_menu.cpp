#include "main_menu.h"
#include <iostream>

void Main_menu::initialize(sf::RenderWindow* window)
{
	selected = 0;
	font.loadFromFile("resources/cambriab.ttf");
	title.setFont(font);
	title.setCharacterSize(100U);
	title.setColor(sf::Color::Red);
	title.setString("Mansion Mystery");
	title.setOrigin(title.getGlobalBounds().width / 2, title.getGlobalBounds().height / 2);
	title.setPosition(window->getSize().x / 2, window->getSize().y / 4);

	top_text.setFont(font);
	top_text.setCharacterSize(50U);
	top_text.setOrigin(top_text.getGlobalBounds().width / 2, top_text.getGlobalBounds().height / 2);
	top_text.setPosition(window->getSize().x / 8 -20, window->getSize().y / 8);

	text.setFont(font);
	text.setOrigin(title.getGlobalBounds().width / 2, title.getGlobalBounds().height / 2);
	

	quit.setFont(font);
	quit.setCharacterSize(50U);
	quit.setOrigin(title.getGlobalBounds().width / 2, title.getGlobalBounds().height / 2);
	
}

int Main_menu::render(int state, sf::RenderWindow* window)
{
	text.setCharacterSize(50);
	text.setColor(sf::Color::White);
	text.setPosition(512, window->getSize().y / 2);
	quit.setColor(sf::Color::White);
	quit.setString("Quit");
	quit.setPosition(512, window->getSize().y / 2 + 100);

	switch (state){

	case 0:
		text.setString("Restart !!");
		break;
	case 2:
		text.setString("Resume");
		break;
	case 3:
		text.setString("Play");
		break;
	case 4:
		text.setString("No, I don't want to quit");
		quit.setString("Press SPACE to quit !!");
		break;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
		selected = 0;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
		selected = 1;


	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space) && state == 4)
		window->close();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Return))
	{
		if (!selected)
			return 1;
		else
			return 4;
	}
	if (!selected)
		text.setColor(sf::Color::Blue);
	else
		quit.setColor(sf::Color::Blue);
	window->setView(window->getDefaultView());
	window->draw(title);
	window->draw(text);
	window->draw(quit);
	return state;
}
int Main_menu::loadingScreen(int state, sf::RenderWindow* window)
{
	top_text.setCharacterSize(40);
	top_text.setColor(sf::Color::Red);
	text.setCharacterSize(25);
	//text.setPosition(window->getSize().x / 2+50, window->getSize().y / 2 +200);
	//quit.setPosition(window->getSize().x / 2-70, window->getSize().y / 2 + 100);
	text.setPosition( 575, window->getSize().y / 2 + 200);
	quit.setPosition(450, window->getSize().y / 2 + 100);
	quit.setColor(sf::Color::Blue);
	text.setColor(sf::Color::White);
	
	if (state == -1){
		top_text.setString("The game contains sudden surprises\n and frightening moments.\nFaint-hearted and people with lack of \ncourage shall not play.\nThe developer takes no responsibility for any \ntrouble that arises from playing the game.");
		text.setString("Arrows : Move\t\tEnter : Interact\t\tSpace : Dismiss");
			quit.setString("\t\t\t\t\t\t* CONTROLS *");
	}
	else if (state == 5){
		top_text.setString("\t\t\t\t\t\t\tCongratulations\n\n\t\t\t\t\tYou defeated the devil !!\n\n\t\tAnd freed the souls from the Mansion");
		text.setString(" Saurabh Kumar Prasad\n\n\tThanks for playing");
		text.setPosition(755, window->getSize().y / 2 + 200);
		quit.setString("\t\t\t\t\t  * Developed By: *");
	}
	else{
		top_text.setString("Burning the Mansion worsened the situation.\n\n\t\t\tThe souls came looking after you.\n\n\t\t\t\t\t\t You Were Killed !!");
		text.setString("Saurabh Kumar Prasad\n\n\tThanks for playing");
		text.setPosition(755, window->getSize().y / 2 + 200);
		quit.setString("\t\t\t\t\t  * Developed By: *");

	}
	window->setView(window->getDefaultView());
	window->draw(top_text);
	window->draw(text);
	window->draw(quit);
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space))
	{	
		if (state + 1 == 0)
			return 3;
		window->close();
	}
	
	return state;
}