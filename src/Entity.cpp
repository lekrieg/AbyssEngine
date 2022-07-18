#include "Entity.h"

const std::string Entity::getTag() const
{
	return _tag;
}

size_t Entity::getId() const
{
	return _id;
}

bool Entity::isAlive() const
{
	return _alive;
}

void Entity::destroy()
{
	_alive = false;
}