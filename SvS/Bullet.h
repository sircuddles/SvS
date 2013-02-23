#pragma once
#include <SFML/Graphics.hpp>
#include "PlantItem.h"

class Bullet {
public:
	Bullet();
	~Bullet() {}

	void update(float t);
	void setPosition(sf::Vector2f position);
	sf::Sprite& getSprite() { return mSprite; }

private:
	sf::Sprite mSprite;
	sf::Texture mTexture;

	float mXVel;
};