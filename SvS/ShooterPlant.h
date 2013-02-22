#pragma once
#include <SFML\Graphics.hpp>
#include <list>
#include "Board.h"
#include "PlantItem.h"
#include "Bullet.h"

class ShooterPlant : public PlantItem
{
public:
	ShooterPlant();
	~ShooterPlant() { }

	void update(float t);
	void draw(sf::RenderWindow &window);
	std::list<Bullet*>& getBulletList() { return mBulletList; }

	inline int getEnergyCost() { return 50; }

private:
	int mBulletSpawnDelay;
	float mBulletSpawnCounter;
	std::list<Bullet*> mBulletList;
};