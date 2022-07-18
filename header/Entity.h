#ifndef ENTITY_H
#define ENTITY_H

#include "Transform.h"
#include "Shape.h"
#include "Text.h"

#include <memory>
#include <vector>

class Entity
{
private:
	friend class EntityManager;

	const size_t _id = 0;
	const std::string _tag = "Default";
	bool _alive = true;
public:

	std::shared_ptr<Transform> transform;
	
	std::shared_ptr<Shape> shape;
	std::shared_ptr<Text> text;
	// std::shared_ptr<Name> name;
	// std::shared_ptr<BoundingBox> boundingBox;
	// std::shared_ptr<Component> transform;

	// std::vector<Component> _components;

	const std::string getTag() const;
	size_t getId() const;
	bool isAlive() const;
	void destroy();

private:

	Entity(const std::string& tag, size_t id) : _tag(tag), _id(id) { }
	
	//void addComponent<T>(args);
	//void getComponent<T>(args);
};

#endif // !ENTITY_H