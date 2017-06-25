#pragma once
#include "Vector2.h"

class aabb
{
public:
	union
	{
		struct
		{
			Vector2 pos;
			Vector2 extents;
		};
		struct
		{
			float x, y, halfwidth, halfheight;
		};
	};
	aabb();
	~aabb();

	aabb(const Vector2& pos, const Vector2& extents);
	aabb(const float x, const float y, const float halfwidth, const float halfheight);

	static bool collisionCheck(const aabb& box, const Vector2& point);
	static bool collisionCheck(const aabb& lhs, const aabb& rhs);

	bool collidesWith(const Vector2& point) const;
	bool collidesWith(const aabb& box) const;
};

