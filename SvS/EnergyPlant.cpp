#include "EnergyPlant.h"

EnergyPlant::EnergyPlant()
{
	mEnergyTimerCounter = 0;
	mEnergyGainDelay = 8;
	mEnergyPlusAmount = 10;
	
	mPlantType = PLANT_TYPE::Energy;
	mTexture.loadFromFile("assets/plant2.png");
	mSprite.setTexture(mTexture);
}

void EnergyPlant::update(float t, int *currentEnergy)
{
	mEnergyTimerCounter += t;

	if (mEnergyTimerCounter >= mEnergyGainDelay) 
	{
		*currentEnergy += mEnergyPlusAmount;
		mEnergyTimerCounter = 0;
	}
}

void EnergyPlant::draw(sf::RenderWindow &window)
{
	window.draw(*getSprite());
}