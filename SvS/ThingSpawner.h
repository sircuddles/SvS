#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include "TextWriter.h"
#include "Entity.h"
#include <list>

/*
1)  Countdown from SPAWN_INTERVAL_SECONDS to 0
2) Reset counter
3) Display counter on screen (bottom left?)

*/
class ThingSpawner
{

public:
	ThingSpawner(sf::RenderWindow& window, int columnCount, int laneCount);	
	~ThingSpawner();

	void draw();
	void update(float t);
	void spawn();

private:
	float mSpawnTimerSeconds;
	float mSpawnTimerCounter;
	int mColumnCount, mLaneCount;

	std::list<Entity*> mEntityList;
	TextWriter mSpawnTimerText;
	sf::Texture mZombieTexture;
	sf::RenderWindow* mWindow;
};