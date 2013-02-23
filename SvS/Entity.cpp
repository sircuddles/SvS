#include "Entity.h"

Entity::Entity()
{
	mHealth = 100;
	mMaxHealth = 100;
}
Entity::~Entity(void) {}

void Entity::update(float t) 
{
	mSprite.move(-15.0f * t, 0);
}