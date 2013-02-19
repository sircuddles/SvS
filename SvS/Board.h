#include <SFML/Graphics.hpp>


class Board
{
public:
	Board(const sf::RenderWindow& gameWindow);
	~Board();

	void draw(sf::RenderWindow& gameWindow);

private:
	static const int GRID_WIDTH = 9;
	static const int GRID_HEIGHT = 5;

	sf::RectangleShape mBoardGrid[GRID_HEIGHT][GRID_WIDTH];
	sf::RectangleShape mBoardOutline;
	int mLeftBoardOffset;
	
};
