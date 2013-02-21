#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include "Board.h"
#include "TextWriter.h"
#include "ThingSpawner.h"
#include "Cursor.h"

int main()
{
	const int LANE_COUNT = 5;
	const int COLUMN_COUNT = 9;

	sf::RenderWindow gameWindow(sf::VideoMode(1024, 768), "SvS", 1);
	gameWindow.setVerticalSyncEnabled(true);
	gameWindow.setMouseCursorVisible(false);

	// Create board.
	Board board = Board();

	// Create plant items available to user.
	PlantItem plantItem1, plantItem2, plantItem3;
	PlantItem plantItems[] = {plantItem1, plantItem2, plantItem3};
	// Add plant items to board.
	board.setPlantItems(plantItems);

	// Initialize board with main grid and plant items.
	board.initialize(&gameWindow);

	sf::Clock gameClock;
	sf::Event gameEvents;
	float gameTime = 0;

	ThingSpawner thing(&board, COLUMN_COUNT, LANE_COUNT);
	Cursor customCursor(&gameWindow);

	while (gameWindow.isOpen()) 
	{
		while (gameWindow.pollEvent(gameEvents)) 
		{
			if ((gameEvents.type == sf::Event::KeyPressed && gameEvents.key.code == sf::Keyboard::Escape) || (gameEvents.type == sf::Event::Closed))
			{
				gameWindow.close();
			}

			if(gameEvents.type == sf::Event::MouseButtonPressed && gameEvents.mouseButton.button == sf::Mouse::Button::Left)
			{
				for(int i = 0; i < Board::MAX_PLANTS; i++)
				{
					if(board.getPlantItems()[i].getPlantRectangle()->getGlobalBounds().contains((float)gameEvents.mouseButton.x, (float)gameEvents.mouseButton.y))
					{
						printf("Hit detected on plant item at %.2f(x) and %.2f(y)!\n", (float)gameEvents.mouseButton.x, (float)gameEvents.mouseButton.y);
					}
				}
			}
		}

		thing.update(gameTime);
		// Horrible update that sets the cursor to the mouse position
		customCursor.update(sf::Vector2f(sf::Mouse::getPosition(gameWindow)));
		
		board.draw();
		thing.draw();
		customCursor.draw();

		gameWindow.display();
		gameWindow.clear(sf::Color::White);

		gameTime = gameClock.restart().asSeconds();
		sf::sleep(sf::milliseconds(10));

	} // End window is open

	return 0;
}