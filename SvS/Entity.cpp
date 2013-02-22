#include "Entity.h"

Entity::Entity() {}
Entity::~Entity(void) {}

void Entity::update(float t) {
	// PLACEHOLDER CODE
	// TO TEST CLASS BEFORE 
	// DERIVED MOB CLASSES ADDED
	mSprite.move(-100 * t, 0);
}