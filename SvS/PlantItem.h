#include <SFML\Graphics.hpp>

class PlantItem
{
public:
	PlantItem();
	~PlantItem();

	inline void setSprite(sf::Sprite sprite) { mSprite = sprite; }
	inline sf::Sprite* getSprite() { return &mSprite; }

private:
	sf::Sprite mSprite;
};