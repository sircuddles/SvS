#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include "Board.h"
#include "TextWriter.h"
#include "ThingSpawner.h"

int main()
{
	sf::RenderWindow gameWindow(sf::VideoMode(1024, 768), "Something", 1);
	gameWindow.setVerticalSyncEnabled(true);

	sf::Clock gameClock;
	sf::Event gameEvents;
	double gameTime = 0;

	Board gameBoard(gameWindow);	
	ThingSpawner thing(9, 5);

	while (gameWindow.isOpen()) 
	{
		while (gameWindow.pollEvent(gameEvents)) 
		{
			if ((gameEvents.key.code == sf::Keyboard::Escape) || (gameEvents.type == sf::Event::Closed))
				gameWindow.close();
		}

		thing.update(gameTime);
		
		gameBoard.draw(gameWindow);
		thing.draw(gameWindow);

		gameWindow.display();
		gameWindow.clear(sf::Color::White);

		gameTime = gameClock.restart().asSeconds();
		sf::sleep(sf::milliseconds(10));

	} // End window is open
		


	return 0;
}