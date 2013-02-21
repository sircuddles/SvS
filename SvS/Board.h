#pragma once
#include <SFML/Graphics.hpp>
#include "PlantItem.h"

class Board
{
public:
	static const int MAX_PLANTS = 3;

	Board();	
	~Board();
	
	void initialize(sf::RenderWindow* gameWindow);
	void draw();

	inline sf::RenderWindow* getGameWindow() { return mGameWindow; }
	sf::RectangleShape getBoardRect() { return mBoardOutline; }
	PlantItem* getPlantItems() { return mPlantItems; }
	void setPlantItems(PlantItem* plantItems) { mPlantItems = plantItems; }

private:
	static Board* mInstance;

	// Grid
	static const int GRID_WIDTH = 9;
	static const int GRID_HEIGHT = 5;

	// Plants
	static const int PLANT_OFFSET_POSITION = 15;

	sf::RenderWindow* mGameWindow;
	sf::RectangleShape mBoardGrid[GRID_HEIGHT][GRID_WIDTH];
	PlantItem* mPlantItems;
	sf::RectangleShape mBoardOutline;
	int mLeftBoardOffset;
	sf::Vector2i mPosition;
};
