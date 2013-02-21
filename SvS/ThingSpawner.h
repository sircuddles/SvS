#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

#include <list>

#include "TextWriter.h"
#include "Entity.h"
#include "Board.h"

/*
1)  Countdown from SPAWN_INTERVAL_SECONDS to 0
2) Reset counter
3) Display counter on screen (bottom left?)

*/
class ThingSpawner
{

public:
	ThingSpawner(Board *board, int columnCount, int laneCount);	
	~ThingSpawner();

	void draw();
	void update(float t);
	void spawn();

private:
	Board *mBoard;
	float mSpawnTimerSeconds;
	float mSpawnTimerCounter;
	int mColumnCount, mLaneCount;

	std::list<Entity*> mEntityList;
	TextWriter mSpawnTimerText;
	sf::Texture mZombieTexture;
};