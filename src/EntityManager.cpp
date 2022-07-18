#include "EntityManager.h"

void EntityManager::update()
{
	for (auto e : _entitiesToAdd)
	{
		_entities.push_back(e);
		_entityMap[e->getTag()].push_back(e);
	}

	removeDeadEntities(_entities);

	for (auto& item : _entityMap)
	{
		removeDeadEntities(item.second);
	}

	_entitiesToAdd.clear();
}

void EntityManager::removeDeadEntities(EntityVector& vector)
{
	// retorna um iterator para o ponto atual, contornando o problema do iterator invalidation
	vector.erase(std::remove_if(vector.begin(), vector.end(), IsAlive()), vector.end());
}

std::shared_ptr<Entity> EntityManager::addEntity(const std::string& tag)
{
	auto e = std::shared_ptr<Entity>(new Entity(tag, _totalEntities++));
	_entitiesToAdd.push_back(e);
	return e;
}

const EntityVector& EntityManager::getEntities()
{
	return _entities;
}

const EntityVector& EntityManager::getEntities(const std::string& tag)
{
	return _entityMap[tag];
}