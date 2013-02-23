#include "Bullet.h"

Bullet::Bullet()
{
	mXVel = 200.0f;
	mTexture.loadFromFile("assets/plantBullet.png");
	mSprite.setTexture(mTexture);
}

void Bullet::update(float t)
{
	mSprite.move(mXVel * t, 0);
}

void Bullet::setPosition(sf::Vector2f position) {
	mSprite.setPosition(position.x + mSprite.getGlobalBounds().width + 10, position.y + (mSprite.getGlobalBounds().top + mSprite.getGlobalBounds().height) / 2);
}