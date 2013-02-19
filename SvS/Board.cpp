#include "Board.h"


Board::Board(const sf::RenderWindow& gameWindow)
{
	

	mLeftBoardOffset = 125;

	// Define the board outline rectangle
	mBoardOutline.setSize(sf::Vector2f(gameWindow.getSize().x - mLeftBoardOffset, gameWindow.getSize().y));
	mBoardOutline.setPosition(mLeftBoardOffset, 0);
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
}
Board::~Board() {}

void Board::draw(sf::RenderWindow& gameWindow) {
	gameWindow.draw(mBoardOutline);
	for (int i = 0; i < GRID_HEIGHT; i++) {
		for (int j = 0; j < GRID_WIDTH;  j++) {
			gameWindow.draw(mBoardGrid[i][j]);
		}
	}
}