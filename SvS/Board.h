#include <SFML/Graphics.hpp>


class Board
{
public:
	~Board();

	static Board* GetInstance(sf::RenderWindow& gameWindow)
	{
		if(!mInstance)
		{
			return new Board(gameWindow);
		}
		return mInstance;
	}

	void draw();

	sf::RectangleShape getBoardRect() { return mBoardOutline; }

private:
	static Board* mInstance;
	static const int GRID_WIDTH = 9;
	static const int GRID_HEIGHT = 5;

	Board(sf::RenderWindow& gameWindow);
	sf::RenderWindow* mGameWindow;
	sf::RectangleShape mBoardGrid[GRID_HEIGHT][GRID_WIDTH];
	sf::RectangleShape mBoardOutline;
	int mLeftBoardOffset;
	sf::Vector2i mPosition;
};
