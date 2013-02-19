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
	ThingSpawner(int gridWidth, int gridHeight);	
	~ThingSpawner();

	void draw(sf::RenderWindow& w);
	void update(float t);
	void spawn();

private:
	float mSpawnTimerSeconds;
	float mSpawnTimerCounter;
	int mGridWidth, mGridHeight;

	std::list<Entity*> mEntityList;
	TextWriter mSpawnTimerText;
	sf::Texture mZombieTexture;


};