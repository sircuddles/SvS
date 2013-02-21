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
		Shooter
	} PLANT_TYPE;


	inline sf::RectangleShape* getPlantRectangle() { return &mPlantRectangle; }

	inline void setSprite(sf::Sprite sprite) { mSprite = sprite; }
	inline sf::Sprite* getSprite() { return &mSprite; }
	inline void setWindow(sf::RenderWindow *window) { mWindow = window; }

	virtual void update(float t) = 0;
	virtual void draw() = 0;

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
	sf::RenderWindow* mWindow;
};