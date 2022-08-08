#ifndef TRANSFORM_H
#define TRANSFORM_H

#include "glm/ext/vector_float2.hpp"

class Transform
{
public:
	glm::vec2 pos = { 0, 0 };
	glm::vec2 velocity = { 0, 0 };
	glm::vec2 rotation = { 0, 0 };

	Transform(const glm::vec2& p, const glm::vec2& v, const glm::vec2& r) : pos(p), velocity(v), rotation(r) { }
};

#endif // !TRANSFORM_H