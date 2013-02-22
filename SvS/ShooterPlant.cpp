#include "ShooterPlant.h"

ShooterPlant::ShooterPlant()
{
	mBulletSpawnCounter = 0;
	mBulletSpawnDelay = 2;
	mPlantType = PLANT_TYPE::Shooter;
	mTexture.loadFromFile("assets/plant1.png");
	mSprite.setTexture(mTexture);
}

void ShooterPlant::update(float t)
{
	mBulletSpawnCounter += t;

	if (mBulletSpawnCounter >= mBulletSpawnDelay) {
		Bullet* newBullet = new Bullet;
		newBullet->setPosition(mSprite.getPosition());
		mBulletList.push_back(newBullet);
		mBulletSpawnCounter = 0;
	}

	for (std::list<Bullet*>::iterator iter = mBulletList.begin();  iter != mBulletList.end();  iter++) {
		(*iter)->update(t);
	}
}

void ShooterPlant::draw(sf::RenderWindow &window)
{
	window.draw(*getSprite());
	for (std::list<Bullet*>::iterator iter = mBulletList.begin();  iter != mBulletList.end();  iter++) {
		window.draw(*(*iter)->getSprite());
	}
}