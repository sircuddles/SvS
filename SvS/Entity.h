#pragma once
#include <SFML/Graphics.hpp>

class Entity {
private:
	sf::Sprite mSprite;

public:
	Entity(sf::Texture* texture);
	virtual ~Entity(void);

	virtual void update(float t);

	sf::Sprite& getSprite() { return mSprite; }
};