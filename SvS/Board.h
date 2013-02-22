#pragma once
#include <SFML/Graphics.hpp>
#include <list>
#include "PlantItem.h"
#include "ShooterPlant.h"

class Board
{
public:
	static const int MAX_PLANTS = 3;

	Board();	
	~Board();
	
	void initialize(sf::RenderWindow* gameWindow, PlantItem** plants);
	void draw();
	void update(float t);

	inline sf::RenderWindow* getGameWindow() { return mGameWindow; }
	sf::RectangleShape getBoardRect() { return mBoardOutline; }
	PlantItem** getPlantItems() { return mPlantItems; }
	bool isCellActive(sf::RectangleShape* cell);
	void setCellActive(sf::RectangleShape* cell);

	sf::RectangleShape* getMouseCollision(float x, float y);
	void addPlacedPlantItem(PlantItem::PLANT_TYPE plantType, sf::RectangleShape* boardCell);

private:
	static Board* mInstance;

	// Grid
	static const int GRID_WIDTH = 9;
	static const int GRID_HEIGHT = 5;

	// Plants
	static const int PLANT_OFFSET_POSITION = 15;

	sf::RenderWindow* mGameWindow;
	sf::RectangleShape mBoardGrid[GRID_HEIGHT][GRID_WIDTH];
	int mBoardCells[GRID_HEIGHT][GRID_WIDTH];
	PlantItem** mPlantItems;
	sf::RectangleShape mBoardOutline;
	int mLeftBoardOffset;
	sf::Vector2i mPosition;
	std::list<PlantItem*> mPlacedPlantItems;
};
