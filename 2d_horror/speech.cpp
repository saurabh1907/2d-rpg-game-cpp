#include"speech.h"

Speech::Speech(){
	box.setSize(sf::Vector2f(300, 105));
	box.setOutlineColor(sf::Color(147, 122, 66));
	box.setOutlineThickness(1.0f);
	box.setFillColor(sf::Color(0, 0, 0, 150));
	box.setOrigin(box.getSize().x / 2, box.getSize().y / 2);

	font.loadFromFile("resources/cambriab.ttf");
	text.setFont(font);
	text.setCharacterSize(10);

}
void Speech::write(std::string msg, sf::Vector2f reference, sf::RenderWindow* window){

	text.setString(msg);
	box.setPosition(reference.x + 12, reference.y + 110);
	text.setPosition(box.getPosition().x - box.getSize().x / 2 + 5, box.getPosition().y - box.getSize().y / 2 + 5);
	(*window).draw(box);
	(*window).draw(text);
}

