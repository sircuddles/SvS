#pragma once
#include <SFML\Graphics.hpp>
#include "PlantItem.h"

class EnergyPlant : public PlantItem
{
public:
	EnergyPlant();
	~EnergyPlant() { }

	void update(float t, int *currentEnergy);
	void draw(sf::RenderWindow &window);
	inline int getEnergyCost() { return 25; }

private:
	float mEnergyTimerCounter;
	int mEnergyGainDelay;	
	int mEnergyPlusAmount;
};