#include "AABB.h"

aabb::aabb()
{
	this->pos = Vector2();
	this->extents = Vector2();
}

aabb::~aabb()
{
}

aabb::aabb(const Vector2& pos, const Vector2& extents)
{
	this->pos = pos;
	this->extents = extents;
}

aabb::aabb(const float x, const float y, const float halfWidth, const float halfHeight)
{
	pos = Vector2(x, y);
	extents = Vector2(halfWidth, halfHeight);
}


bool aabb::collisionCheck(const aabb& box, const Vector2& point)
{
	// max < point || point < min = no collision
	return !((box.x + box.halfwidth < point.x) || (box.y + box.halfheight < point.y) ||
		(box.x - box.halfwidth > point.x) || (box.y - box.halfheight > point.y));
}

bool aabb::collisionCheck(const aabb& lhs, const aabb& rhs) 
{
	return !((lhs.x + lhs.halfwidth < rhs.x - rhs.halfwidth) || (lhs.y + lhs.halfheight < rhs.y - rhs.halfheight) ||
		(lhs.x - lhs.halfwidth > rhs.x + rhs.halfwidth) || (lhs.y - lhs.halfheight > rhs.y + rhs.halfheight));
}

bool aabb::collidesWith(const Vector2& point) const
{
	return collisionCheck(*this, point);
}

bool aabb::collidesWith(const aabb& box) const 
{
	return collisionCheck(*this, box);
}