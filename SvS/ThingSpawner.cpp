#include "ThingSpawner.h"
#include <sstream>
#include <math.h>
#include <iostream>

ThingSpawner::ThingSpawner(int gridWidth, int gridHeight) {
	// Initialize timer variables
	mSpawnTimerSeconds = 5;
	mSpawnTimerCounter = 0;
	mSpawnTimerText.setPosition(0, 700);
	mSpawnTimerText.setString("");

	// Seed number generator
	std::srand(time(NULL));

	// Set the values for the grid
	mGridWidth = gridWidth;
	mGridHeight = gridHeight;

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
	std::list<Entity* >::iterator iter;
	for (iter = mEntityList.begin();  iter != mEntityList.end(); iter++) {
		(*iter)->update(t);
	}

}

void ThingSpawner::draw(sf::RenderWindow& w) {
	// Draw timer text
	mSpawnTimerText.draw(w);

	// Draw all entities in the list
	std::list<Entity* >::iterator iter;
	for (iter = mEntityList.begin();  iter != mEntityList.end(); iter++) {
		w.draw((*iter)->getSprite());
	}
}

void ThingSpawner::spawn() {
	// Generate a random number between 0 and the number of rows
	int row = std::rand() % mGridHeight;

	// Create the new mob
	// Mob types to be added later
	Entity *newZombie = new Entity(&mZombieTexture);

	// Set the position to the far right of the screen,  with the
	// mob sprite aligned with the bottom of the row
	// it should be spawning on
	newZombie->getSprite().setPosition(1024, (row * newZombie->getSprite().getGlobalBounds().height));

	// Add the new mob to the list
	mEntityList.push_back(newZombie);
}