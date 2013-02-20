#pragma once
#include <SFML/Graphics.hpp>

class Cursor {
private:
	sf::Texture texture;
	sf::Sprite sprite;
	sf::RenderWindow* mWindow;

public:
	Cursor(sf::RenderWindow& window);
	~Cursor(void);

	void update(sf::Vector2f position);
	void draw();
};

