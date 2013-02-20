#include "Cursor.h"


Cursor::Cursor(sf::RenderWindow& window) {
	mWindow = &window;

	// Load and assign the texture to the sprite
	texture.loadFromFile("assets/cursor.png");
	sprite.setTexture(texture);

	// Set the origin of the Sprite to the middle of the image
	sprite.setOrigin(sprite.getGlobalBounds().width / 2, sprite.getGlobalBounds().height / 2);
}
Cursor::~Cursor(void) {}

void Cursor::update(sf::Vector2f position) {
	sprite.setPosition(position);
}

void Cursor::draw() {
	mWindow->draw(sprite);
}