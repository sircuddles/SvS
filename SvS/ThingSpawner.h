#pragma once
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

#include <list>
#include "Entity.h"

/*
1)  Countdown from SPAWN_INTERVAL_SECONDS to 0
2) Reset counter
3) Display counter on screen (bottom left?)

*/
class ThingSpawner
{
public:
	ThingSpawner(sf::RenderWindow *window, int columnCount, int laneCount);	
	~ThingSpawner();

	void draw();
	void update(float t);
	void spawn();

	inline std::list<Entity*>& getEntities() { return mEntityList; }

private:
	sf::RenderWindow* mWindow;
	float mSpawnTimerSeconds;
	float mSpawnTimerCounter;
	float mGlobalTimerCounter;
	float mLastDifficultyTimer;
	int mColumnCount, mLaneCount;
	int mSpawnNumber;

	std::list<Entity*> mEntityList;
	sf::Texture mZombieTexture;
};