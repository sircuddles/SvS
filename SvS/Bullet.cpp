#include "Bullet.h"

Bullet::Bullet()
{
	mXVel = 100;
	mTexture.loadFromFile("assets/plant1.png");
	mSprite.setTexture(mTexture);
}

void Bullet::update(float t)
{
	mSprite.move(mXVel * t, 0);
}

void Bullet::setPosition(sf::Vector2f position) {
	mSprite.setPosition(mSprite.getGlobalBounds().width + 10, (mSprite.getGlobalBounds().top + mSprite.getGlobalBounds().height) / 2);
}