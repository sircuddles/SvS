#include "Board.h"
#include "Entity.h"

Board* Board::mInstance = NULL;

Board::Board()
{
	for (int i = 0; i < GRID_HEIGHT; i++) 
	{
		for (int j = 0; j < GRID_WIDTH;  j++) 
		{
			mBoardCells[i][j] = 0;
		}
	}
}

void Board::initialize(sf::RenderWindow *gameWindow, PlantItem** plants)
{
	mGameWindow = gameWindow;
	mPlantItems = plants;
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
		(*plants[i]).getPlantRectangle()->setOutlineColor(sf::Color::Green);
		(*plants[i]).getPlantRectangle()->setFillColor(sf::Color::Transparent);
		(*plants[i]).getPlantRectangle()->setOutlineThickness(-2);
		(*plants[i]).getPlantRectangle()->setSize(sf::Vector2f(tileWidth, tileHeight));
		(*plants[i]).getPlantRectangle()->setPosition((float)PLANT_OFFSET_POSITION, (tileHeight) + (i * tileHeight));
	}
}

Board::~Board() 
{

}

void Board::update(float t, int *currentEnergy)
{
	// Update 'Things'
	for (std::list<Entity*>::iterator thingIter = mThingSpawner->getEntities().begin();  thingIter != mThingSpawner->getEntities().end();)
	{
		Entity *thing = *thingIter;
		thing->update(t);
		
		// If the right side of the texture of the sprite is off the screen (to the left)
		//  Delete sprite.
		if(thing->getSprite().getGlobalBounds().left < getBoardRect().getGlobalBounds().left)
		{
			// 'Thing' is ready to be deleted.
			//	 Delete thing...
			mThingSpawner->getEntities().erase(thingIter++);
		}
		else
		{
			thingIter++;
		}
	}

	// Update placed plants.
	for (std::list<PlantItem*>::iterator iter = mPlacedPlantItems.begin();  iter != mPlacedPlantItems.end();  iter++) 
	{
		PlantItem* currentItem = (*iter);
		switch(currentItem->getPlantType())
		{
			case PlantItem::PLANT_TYPE::Energy:
			{
				((EnergyPlant*)currentItem)->update(t, currentEnergy);
			}
			break;

			case PlantItem::PLANT_TYPE::Shooter:
				currentItem->update(t);
				ShooterPlant* shooterPlant =(ShooterPlant*)currentItem;
				for (std::list<Bullet*>::iterator bulletIter = shooterPlant->getBulletList().begin();  bulletIter != shooterPlant->getBulletList().end();)
				{
					if((*bulletIter)->getSprite().getPosition().x + (*bulletIter)->getSprite().getGlobalBounds().width > mBoardOutline.getPosition().x + mBoardOutline.getGlobalBounds().width)
					{
						bulletIter = shooterPlant->getBulletList().erase(bulletIter);
		 			}
					else
					{
						++bulletIter;
					}
				}
				std::list<Bullet*>::iterator bulletIter = shooterPlant->getBulletList().begin();
				while(bulletIter != shooterPlant->getBulletList().end())
				{
					bool hasErased = false;
					std::list<Entity*>::iterator entityIter = mThingSpawner->getEntities().begin();
					while(entityIter != mThingSpawner->getEntities().end() && bulletIter != shooterPlant->getBulletList().end())
					{
						if((*entityIter)->getSprite().getGlobalBounds().intersects((*bulletIter)->getSprite().getGlobalBounds()))
						{
							delete *bulletIter;
							bulletIter = shooterPlant->getBulletList().erase(bulletIter);
							hasErased = true;

							if((*entityIter)->getHealth() <= 0)
							{
								delete *entityIter;

								entityIter = mThingSpawner->getEntities().erase(entityIter);
							}
							else
							{
								(*entityIter)->changeHealth(-25);
							}
						}
						else
						{
							++entityIter;
						}
					}
					if(!hasErased)
					{
						++bulletIter;
					}
				}
				break;
		}
	}
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
		mGameWindow->draw(*(*mPlantItems[i]).getPlantRectangle());
	}

	for (std::list<PlantItem*>::iterator iter = mPlacedPlantItems.begin();  iter != mPlacedPlantItems.end();  iter++) 
	{
		(*iter)->draw(*mGameWindow);
	}
}

sf::RectangleShape* Board::getMouseCollision(float x, float y)
{
	for (int i = 0; i < GRID_HEIGHT; i++) {
		for (int j = 0; j < GRID_WIDTH;  j++) {
			if(mBoardGrid[i][j].getGlobalBounds().contains(x, y))
			{
				return &mBoardGrid[i][j];
			}
		}
	}

	return NULL;
}

void Board::addPlacedPlantItem(PlantItem::PLANT_TYPE plantType, sf::RectangleShape* boardCell)
{
	switch(plantType)
	{
		case PlantItem::PLANT_TYPE::Shooter:
			{
				printf("Shooter wants to be placed!\n");
			
				ShooterPlant* plantItem = new ShooterPlant();
				mPlacedPlantItems.push_back(plantItem);

				plantItem->getSprite()->setPosition(boardCell->getGlobalBounds().left, boardCell->getGlobalBounds().top);
			}
			break;
		case PlantItem::PLANT_TYPE::Energy:
			{
				printf("Energy wants to be placed!\n");
			
				EnergyPlant* plantItem = new EnergyPlant();
				mPlacedPlantItems.push_back(plantItem);

				plantItem->getSprite()->setPosition(boardCell->getGlobalBounds().left, boardCell->getGlobalBounds().top);
			}
			break;
	}
}

void Board::setCellActive(sf::RectangleShape* cell)
{
	for (int i = 0; i < GRID_HEIGHT; i++) 
	{
		for (int j = 0; j < GRID_WIDTH;  j++) 
		{
			if(&(mBoardGrid[i][j]) == &(*(cell)))
			{
				mBoardCells[i][j] = 1;
			}
		}
	}
}

bool Board::isCellActive(sf::RectangleShape* cell)
{
	for (int i = 0; i < GRID_HEIGHT; i++) 
	{
		for (int j = 0; j < GRID_WIDTH;  j++) 
		{
			if(&(mBoardGrid[i][j]) == &(*(cell)) && mBoardCells[i][j] == 1)
			{
				return true;
			}
		}
	}

	return false;
}