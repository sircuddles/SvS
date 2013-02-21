#include "ThingSpawner.h"
#include <sstream>
#include <math.h>
#include <iostream>

#include "Board.h"

ThingSpawner::ThingSpawner(sf::RenderWindow& window, int columnCount, int laneCount) {
	// Initialize timer variables
	mWindow = &window;
	mSpawnTimerSeconds = 1;
	mSpawnTimerCounter = 0;
	mSpawnTimerText.setPosition(0, 700);
	mSpawnTimerText.setString("");

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
	mSpawnTimerCounter += t;

	if (mSpawnTimerCounter >= mSpawnTimerSeconds) {
		// Find random row
		// Spawn zombie in row
		spawn();
		mSpawnTimerCounter = 0;
	}

	// Set the displayed text string to the value of mSpawnTimerCounter
	std::stringstream ss;
	ss << floor(mSpawnTimerCounter);
	mSpawnTimerText.setString(ss.str());

	// Run the updates of everything in the list
	for (std::list<Entity* >::iterator iter = mEntityList.begin();  iter != mEntityList.end();) {
		Entity *thing = *iter;
		thing->update(t);
		
		// If the right side of the texture of the sprite is off the screen (to the left)
		//  Delete sprite.
		if(thing->getSprite().getGlobalBounds().left < Board::GetInstance(*mWindow)->getBoardRect().getGlobalBounds().left)
		{
			// 'Thing' is ready to be deleted.
			//	 Delete thing...
			iter = mEntityList.erase(iter);
		}
		else
		{
			iter++;
		}
	}
}

void ThingSpawner::draw() {
	// Draw timer text
	mSpawnTimerText.draw(*mWindow);

	// Draw all entities in the list
	std::list<Entity* >::iterator iter;
	for (iter = mEntityList.begin();  iter != mEntityList.end(); iter++) {
		mWindow->draw((*iter)->getSprite());
	}
}

void ThingSpawner::spawn() {
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