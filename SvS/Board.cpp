#include "Board.h"

Board* Board::mInstance = NULL;

Board::Board()
{
}

void Board::initialize(sf::RenderWindow *gameWindow)
{
	mGameWindow = gameWindow;
	mLeftBoardOffset = 125;

	// Define the board outline rectangle
	mBoardOutline.setSize(sf::Vector2f((float)gameWindow->getSize().x - mLeftBoardOffset, (float)gameWindow->getSize().y));
	mBoardOutline.setPosition((float)mLeftBoardOffset, 0);
	mBoardOutline.setOutlineThickness(-5);
	mBoardOutline.setOutlineColor(sf::Color::Black);
	mBoardOutline.setFillColor(sf::Color::Transparent);

	float tileWidth = mBoardOutline.getSize().x / GRID_WIDTH;
	float tileHeight = mBoardOutline.getSize().y / GRID_HEIGHT;

	for (int i = 0; i < GRID_HEIGHT; i++) {
		for (int j = 0; j < GRID_WIDTH;  j++) {
			mBoardGrid[i][j].setOutlineColor(sf::Color::Black);
			mBoardGrid[i][j].setFillColor(sf::Color::Transparent);
			mBoardGrid[i][j].setOutlineThickness(-2);
			mBoardGrid[i][j].setSize(sf::Vector2f(tileWidth, tileHeight));
			mBoardGrid[i][j].setPosition((j * tileWidth) + mLeftBoardOffset, i* tileHeight);
		}
	}

	for(int i = 0; i < MAX_PLANTS; i++)
	{
		mPlantItems[i].getPlantRectangle()->setOutlineColor(sf::Color::Green);
		mPlantItems[i].getPlantRectangle()->setFillColor(sf::Color::Transparent);
		mPlantItems[i].getPlantRectangle()->setOutlineThickness(-2);
		mPlantItems[i].getPlantRectangle()->setSize(sf::Vector2f(tileWidth, tileHeight));
		mPlantItems[i].getPlantRectangle()->setPosition((float)PLANT_OFFSET_POSITION, (tileHeight) + (i * tileHeight));
	}
}

Board::~Board() 
{

}

void Board::draw() {
	mGameWindow->draw(mBoardOutline);
	for (int i = 0; i < GRID_HEIGHT; i++) {
		for (int j = 0; j < GRID_WIDTH;  j++) {
			mGameWindow->draw(mBoardGrid[i][j]);
		}
	}

	for(int i = 0; i < MAX_PLANTS; i++)
	{
		mGameWindow->draw(*mPlantItems[i].getPlantRectangle());
	}
}