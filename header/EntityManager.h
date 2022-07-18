#ifndef ENTITY_MANAGER_H
#define ENTITY_MANAGER_H

#include "Entity.h"

#include <memory>
#include <vector>
#include <map>

typedef std::vector<std::shared_ptr<Entity>> EntityVector;
typedef std::map<std::string, EntityVector> EntityMap;

struct IsAlive
{
	bool operator() (const std::shared_ptr<Entity>& e)
	{
		return e->isAlive() == 0;
	}
};

class EntityManager
{
private:
	EntityVector _entities;
	EntityVector _entitiesToAdd;
	EntityMap _entityMap;
	size_t _totalEntities = 0;

	void removeDeadEntities(EntityVector& vector);
	//bool isAlive(std::shared_ptr<Entity>& e);

public:
	EntityManager() { }

	void update();
	std::shared_ptr<Entity> addEntity(const std::string& tag);
	const EntityVector& getEntities();
	const EntityVector& getEntities(const std::string& tag);
};

#endif // !ENTITY_MANAGER_H