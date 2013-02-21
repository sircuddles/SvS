#include <SFML\Graphics.hpp>

class PlantItem
{
public:
	PlantItem() {}
	~PlantItem() {}

	inline void setSprite(sf::RectangleShape plantRectangle) { mPlantRectangle = plantRectangle; }
	inline sf::RectangleShape* getPlantRectangle() { return &mPlantRectangle; }

	inline void setSprite(sf::Sprite sprite) { mSprite = sprite; }
	inline sf::Sprite* getSprite() { return &mSprite; }

private:
	sf::RectangleShape mPlantRectangle;
	sf::Sprite mSprite;
};