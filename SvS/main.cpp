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

	sf::Clock gameClock;
	sf::Event gameEvents;
	float gameTime = 0;

	ThingSpawner thing(gameWindow, COLUMN_COUNT, LANE_COUNT);
	Cursor customCursor(gameWindow);

	while (gameWindow.isOpen()) 
	{
		while (gameWindow.pollEvent(gameEvents)) 
		{
			if ((gameEvents.type == sf::Event::KeyPressed && gameEvents.key.code == sf::Keyboard::Escape) || (gameEvents.type == sf::Event::Closed))
			{
				gameWindow.close();
			}
		}

		thing.update(gameTime);
		// Horrible update that sets the cursor to the mouse position
		customCursor.update(sf::Vector2f(sf::Mouse::getPosition(gameWindow)));
		
		Board::GetInstance(gameWindow)->draw();
		thing.draw();
		customCursor.draw();

		gameWindow.display();
		gameWindow.clear(sf::Color::White);

		gameTime = gameClock.restart().asSeconds();
		sf::sleep(sf::milliseconds(10));

	} // End window is open

	return 0;
}