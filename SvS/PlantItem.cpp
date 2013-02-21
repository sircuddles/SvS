#include "PlantItem.h"

void PlantItem::activate()
{
	if(!mIsActive)
	{
		mIsActive = true;
		mPlantRectangle.setOutlineColor(sf::Color::Red);
	}
	else
	{
		deactivate();
	}
}

void PlantItem::deactivate()
{
	if(mIsActive)
	{
		mIsActive = false;
		mPlantRectangle.setOutlineColor(sf::Color::Green);
	}
}