#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include "Board.h"
#include "TextWriter.h"
#include "ThingSpawner.h"
#include "Cursor.h"
#include "ShooterPlant.h"

int main()
{
	const int LANE_COUNT = 5;
	const int COLUMN_COUNT = 9;

	sf::RenderWindow gameWindow(sf::VideoMode(1024, 768), "SvS", 1);
	gameWindow.setVerticalSyncEnabled(true);
	gameWindow.setMouseCursorVisible(false);

	// Create board.
	Board board;

	// Create plant items available to user.
	ShooterPlant shooterPlant1;
	PlantItem plantItem1, plantItem2;
	PlantItem* plantItems[] = {&shooterPlant1, &plantItem1, &plantItem2};

	// Initialize board with main grid and plant items.
	board.initialize(&gameWindow, (PlantItem**)plantItems);

	sf::Clock gameClock;
	sf::Event gameEvents;
	float gameTime = 0;

	ThingSpawner thing(&board, COLUMN_COUNT, LANE_COUNT);
	Cursor customCursor(&gameWindow);

	PlantItem* activePlantItem = NULL;
	sf::RectangleShape* boardCell = NULL;

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
				float x = (float)gameEvents.mouseButton.x;
				float y = (float)gameEvents.mouseButton.y;
				for(int i = 0; i < Board::MAX_PLANTS; i++)
				{
					if((*board.getPlantItems()[i]).getPlantRectangle()->getGlobalBounds().contains(x,y))
					{
						PlantItem* sourcePlantItem = board.getPlantItems()[i];
						for(int i = 0; i < Board::MAX_PLANTS; i++)
						{
							(*board.getPlantItems()[i]).deactivate();
						}

						sourcePlantItem->activate();
						activePlantItem = sourcePlantItem;
						printf("Hit detected on plant item at %.2f(x) and %.2f(y)!\n", (float)gameEvents.mouseButton.x, (float)gameEvents.mouseButton.y);
					}
				}

				if(activePlantItem != NULL && (boardCell = board.getMouseCollision(x,y)) != NULL)
				{
					if(!board.isCellActive(boardCell))
					{
						board.setCellActive(boardCell);
						board.addPlacedPlantItem(activePlantItem->getPlantType(), boardCell);
					}
				}
			}
		}

		thing.update(gameTime);
		// Horrible update that sets the cursor to the mouse position
		customCursor.update(sf::Vector2f(sf::Mouse::getPosition(gameWindow)));
		board.update(gameTime);
		
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