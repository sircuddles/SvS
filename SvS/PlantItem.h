#pragma once
#include <SFML\Graphics.hpp>

class PlantItem
{
public:
	PlantItem() { mIsActive = false; }
	~PlantItem() {}

	typedef enum 
	{ 
		NONE, 
		Shooter,
		Energy,
	} PLANT_TYPE;


	inline sf::RectangleShape* getPlantRectangle() { return &mPlantRectangle; }

	inline void setSprite(sf::Sprite sprite) { mSprite = sprite; }
	inline sf::Sprite* getSprite() { return &mSprite; }
	virtual inline int getEnergyCost() { return 0; }

	virtual void update(float t) {}
	virtual void draw(sf::RenderWindow &window) {}

	void activate();
	void deactivate();
	PLANT_TYPE getPlantType() { return mPlantType; }

private:
	bool mIsActive;
	sf::RectangleShape mPlantRectangle;
	
protected:
	sf::Sprite mSprite;
	sf::Texture mTexture;
	PLANT_TYPE mPlantType;
};