#include "Vector2.h"
#include <cmath>

Vector2::Vector2()
{
	x = 0;
	y = 0;
}

Vector2::Vector2(float x, float y)
{
	this->x = x;
	this->y = y;
}

Vector2::~Vector2()
{
}

void Vector2::Add(const Vector2 & a_second)
{
	x += a_second.x;
	y += a_second.y;
}

void Vector2::Subtract(const Vector2 & a_second)
{
	x -= a_second.x;
	y -= a_second.y;
}

void Vector2::Multiply(float a_scalar)
{
	x *= a_scalar;
	y *= a_scalar;
}

void Vector2::Divide(float a_scalar)
{
	x /= a_scalar;
	y /= a_scalar;
}

float Vector2::magnitude()
{
	return sqrt((x * x) + (y * y));
}

void Vector2::normalise()
{
	float Length = magnitude();
	if (Length != 0)
	{
		this->Divide(Length);
	}
}

Vector2 Vector2::getNormalised()
{
	Vector2 normalisedVector = *this;
	normalisedVector.normalise();
	return normalisedVector;
}

Vector2 Vector2::Direction()
{
	float magnitude = this->magnitude();
	Vector2 dir;

	if (magnitude == 0) {
		dir.x = 0.0f;
		dir.y = 0.0f;
	}
	else {
		dir.x = x / magnitude;
		dir.y = y / magnitude;
	}

	return dir;
}

void Vector2::setRotateRad(float a_angle)
{
	//float degToRad = (3.14159f / 180.0f);
	//float radToDeg = (180.0f / 3.13159f);

	float cosResult = cos(a_angle);
	float sinResult = sin(a_angle);
	float oldX = x;
	float oldY = y;
	x = ((oldX * cosResult) - (oldY * sinResult));
	y = ((oldX * sinResult) + (oldY * cosResult));
}

void Vector2::setRotateDeg(float a_angle)
{
	float degToRad = (3.14159f / 180.0f);
	a_angle *= degToRad;

	float cosResult = cos(a_angle);
	float sinResult = sin(a_angle);
	float oldX = x;
	float oldY = y;
	x = ((oldX * cosResult) - (oldY * sinResult));
	y = ((oldX * sinResult) + (oldY * cosResult));
}

float Vector2::dot(const Vector2 & a_second)
{
	return (x * a_second.x + y * a_second.y);
}

float Vector2::distance(Vector2 a_1, Vector2 a_2)
{
	Vector2 diff = a_1 - a_2;
	float distance = sqrtf(diff.dot(diff));

	return distance;
}

Vector2::operator float*()
{
	return data;
}

Vector2 Vector2::operator+(const Vector2& a_second) const
{
	Vector2 Result = *this;
	Result.Add(a_second);
	return Result;
}
Vector2 Vector2::operator-(const Vector2& a_second) const
{
	Vector2 Result = *this;
	Result.Subtract(a_second);
	return Result;
}
Vector2 Vector2::operator*(const float a_second) const
{
	Vector2 Result = *this;
	Result.Multiply(a_second);
	return Result;
}
Vector2 Vector2::operator/(const float a_second) const
{
	Vector2 Result = *this;
	Result.Divide(a_second);
	return Result;
}

float & Vector2::operator[](int a_i)
{
	return data[a_i];
}

Vector2 operator*(const float a_fscale, const Vector2 & a_RHS)
{
	return a_RHS * a_fscale;
}
