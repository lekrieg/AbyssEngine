#ifndef TRANSFORM_H
#define TRANSFORM_H

#include "Abyss/vector2.h"

class Transform
{
public:
	abyss::math::Vector2 pos = { 0, 0 };
	abyss::math::Vector2 velocity = { 0, 0 };
	abyss::math::Vector2 rotation = { 0, 0 };

	Transform(const abyss::math::Vector2& p, const abyss::math::Vector2& v, const abyss::math::Vector2& r) : pos(p), velocity(v), rotation(r) { }
};

#endif // !TRANSFORM_H