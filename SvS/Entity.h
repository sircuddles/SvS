#pragma once
#include <SFML/Graphics.hpp>

class Entity {
public:
	Entity();
	virtual ~Entity(void);

	virtual void update(float t);

	inline void setTexture(sf::Texture* texture) { mSprite.setTexture(*texture); }
	sf::Sprite& getSprite() { return mSprite; }
	inline float getHealth() { return  mHealth; }
	inline float getMaxHealth() { return mMaxHealth; }
	inline void changeHealth(int health) { mHealth += health; }

private:
	sf::Sprite mSprite;
	float mHealth;
	float mMaxHealth;
};