#pragma once
#include <SFML/Graphics.hpp>

class Entity {
private:
	sf::Sprite mSprite;
public:
	Entity();
	virtual ~Entity(void);

	virtual void update(float t);

	inline void setTexture(sf::Texture* texture) { mSprite.setTexture(*texture); }
	sf::Sprite& getSprite() { return mSprite; }
};