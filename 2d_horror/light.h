#include <SFML/Graphics.hpp>

class Light{
private:
public:
	sf::RenderTexture flashlightTexture;
	sf::RenderTexture layer;
	
	sf::Sprite flashlight;
	sf::Sprite sprite;
	Light();
	void lighteffect(sf::Vector2f, sf::RenderWindow*);
};