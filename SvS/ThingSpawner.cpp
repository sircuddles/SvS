#include "ThingSpawner.h"
#include <sstream>
#include <math.h>
#include <iostream>

#include "Board.h"

ThingSpawner::ThingSpawner(sf::RenderWindow *window, int columnCount, int laneCount) {
	mWindow = window;
	mEntityList.clear();
	// Initialize timer variables
	mSpawnTimerSeconds = 15;
	mSpawnTimerCounter = 0;
	mLastDifficultyTimer = 0;
	mGlobalTimerCounter = 0;
	mSpawnNumber = 1;

	// Seed number generator
	std::srand((unsigned int)time(NULL));

	// Set the values for the grid
	mColumnCount = columnCount;
	mLaneCount = laneCount;

	// Set the values for Textures
	mZombieTexture.loadFromFile("assets/enemy.png");
}

ThingSpawner::~ThingSpawner() {
	// Delete stuff here

}

void ThingSpawner::update(float t) {
	static bool isFlip = false;
	mSpawnTimerCounter += t;
	mGlobalTimerCounter += t;

	if (mSpawnTimerCounter >= mSpawnTimerSeconds) {
		// Find random row
		// Spawn zombie in row
		spawn();
		mSpawnTimerCounter = 0;
	}

	if((mGlobalTimerCounter) >= mLastDifficultyTimer + 30)
	{
		if(mSpawnNumber >= 3)
		{
			mSpawnNumber = 0;
		}
		mSpawnNumber += 1;
		if(!isFlip)
		{
			mSpawnTimerSeconds -= 5;
			isFlip = true;
		}
		else
		{
			mSpawnTimerSeconds += 5;
		}
		mLastDifficultyTimer = mGlobalTimerCounter;
	}
}

void ThingSpawner::draw() {
	// Draw all entities in the list
	std::list<Entity* >::iterator iter;
	for (iter = mEntityList.begin();  iter != mEntityList.end(); iter++) 
	{
		Entity* thing = (*iter);
		if(thing->getHealth() / thing->getMaxHealth() > .75)
		{
			(*iter)->getSprite().setColor(sf::Color::Green);
		}
		else if(thing->getHealth() / thing->getMaxHealth() > .50)
		{
			(*iter)->getSprite().setColor(sf::Color::Yellow);
		}
		else if(thing->getHealth() / thing->getMaxHealth() > .25)
		{
			(*iter)->getSprite().setColor(sf::Color(255,127,0,255));
		}
		else
		{
			(*iter)->getSprite().setColor(sf::Color::Red);
		}
		mWindow->draw((*iter)->getSprite());
	}
}

void ThingSpawner::spawn() 
{
	for(int i = 0; i < mSpawnNumber; i++)
	{
		// Generate a random number between 0 and the number of rows
		int row = std::rand() % mLaneCount;

		// Create the new mob
		// Mob types to be added later
		Entity *newZombie = new Entity();
		newZombie->setTexture(&mZombieTexture);

		// Set the position to the far right of the screen,  with the
		// mob sprite aligned with the bottom of the row
		// it should be spawning on
		newZombie->getSprite().setPosition(1024, (row * newZombie->getSprite().getGlobalBounds().height));

		// Add the new mob to the list
		mEntityList.push_back(newZombie);
	}
}