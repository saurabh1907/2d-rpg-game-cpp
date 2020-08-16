#include"light.h"

Light::Light(){
	layer.create(1024, 768);
	flashlightTexture.create(400, 400);
	flashlightTexture.clear();
	// Draw 10 circles with increasing transparency
	for (unsigned int i = 0; i < 47; ++i)
	{
		sf::CircleShape circle;
		if (i < 6){
			circle.setRadius(200 - i*20.f);
			circle.setOrigin(sf::Vector2f(200 - i*20.f, 200 - i*20.f));
			circle.setFillColor(sf::Color(0, 0, 0, 239 - i * 1));
		}
		else if (i < 31){
			circle.setRadius(106 - i*1.f);
			circle.setOrigin(sf::Vector2f(106 - i*1.f, 106 - i*1.f));
			circle.setFillColor(sf::Color(0, 0, 0, 240 - i*2.f));
		}
		else if (i < 46){
			circle.setRadius(106 - i*1.f);
			circle.setOrigin(sf::Vector2f(106 - i*1.f, 106 - i*1.f));
			circle.setFillColor(sf::Color(0, 0, 0, 516 - i * 11));
		}
		else{
			circle.setRadius(60);
			circle.setOrigin(sf::Vector2f(60, 60));
			circle.setFillColor(sf::Color(0, 0, 0, 10));
		}
		circle.setPosition(sf::Vector2f(200.f, 200.f));
		flashlightTexture.draw(circle, sf::BlendNone);
	}
	/*for (unsigned int i = 0; i < 42; ++i)
	{
		sf::CircleShape circle;
		if (i < 6){
			circle.setRadius(200 - i*20.f);
			circle.setOrigin(sf::Vector2f(200 - i*20.f, 200 - i*20.f));
			circle.setFillColor(sf::Color(0, 0, 0, 239-i*1));
		}
		else if (i < 31){
			circle.setRadius(101 - i*1.f);
			circle.setOrigin(sf::Vector2f(101 - i*1.f, 101 - i*1.f));
			circle.setFillColor(sf::Color(0, 0, 0,  240-i*2.f));
		}
		else if (i < 41){
			circle.setRadius(101 - i*1.f);
			circle.setOrigin(sf::Vector2f(101- i*1.f, 101 - i*1.f));
			circle.setFillColor(sf::Color(0, 0, 0, 640 - i * 15));
		}
		else{
			circle.setRadius(60);
			circle.setOrigin(sf::Vector2f(60, 60));
			circle.setFillColor(sf::Color(0, 0, 0, 10));
		}
		circle.setPosition(sf::Vector2f(200.f, 200.f));
		flashlightTexture.draw(circle, sf::BlendNone);
	}*/
	flashlight.setTexture(flashlightTexture.getTexture(), true);
	flashlight.setOrigin(200.f, 200.f);
	sprite.setTexture(layer.getTexture());
}
void Light::lighteffect(sf::Vector2f cordinates,sf::RenderWindow* window){
	flashlight.setPosition(cordinates.x+12,cordinates.y+12);
	// Stance-out the 'flashlight' circle
	layer.clear();
	layer.draw(flashlight, sf::BlendMultiply);
	layer.display();
	(*window).draw(sprite); 
	// Draw the layer sprite on top of the 'scene'
	
}
	