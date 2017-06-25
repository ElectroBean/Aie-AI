#include "Vector3.h"
#include <iostream>

Vector3::Vector3()
{
	x = 0;
	y = 0;
	z = 0;
}

Vector3::Vector3(float a_x, float a_y, float a_z)
{
	x = a_x;
	y = a_y;
	z = a_z;
}

const Vector3& Vector3::Translate(const Vector3& a_first, const Vector3& a_second)
{
	Vector3* destination = new Vector3();
	destination->x = (a_first.x + a_second.x);
	destination->y = (a_first.y + a_second.y);
	destination->z = (a_first.z + a_second.z);

	return *destination;
}
void Vector3::Add(const Vector3& a_second)
{
	x += a_second.x;
	y += a_second.y;
	z += a_second.z;
}
void Vector3::Subtract(const Vector3& a_second)
{
	x -= a_second.x;
	y -= a_second.y;
	z -= a_second.z;
}
const Vector3& Vector3::Scale(const Vector3& a_point, float a_scalar)
{
	Vector3* product = new Vector3();
	product->x = (a_point.x * a_scalar);
	product->y = (a_point.y * a_scalar);
	product->z = (a_point.z * a_scalar);

	return *product;
}
void Vector3::Multiply(float a_scalar)
{
	x *= a_scalar;
	y *= a_scalar;
	z *= a_scalar;
}
void Vector3::Divide(float a_scalar)
{
	x /= a_scalar;
	y /= a_scalar;
	z /= a_scalar;
}

float Vector3::magnitude()
{
	return sqrt((x * x) + (y * y) + (z * z));
}

void Vector3::normalise()
{
	float Length = magnitude();
	this->Divide(Length);
}

Vector3 Vector3::getNormalised()
{
	Vector3 normalisedVector = *this;
	normalisedVector.normalise();
	return normalisedVector;
}

float Vector3::dot(const Vector3 & a_second)
{
	return (x * a_second.x + y * a_second.y + z * a_second.z);
}

const Vector3 & Vector3::cross(const Vector3 & a_second)
{
	Vector3 crossProduct;

	crossProduct.x = y * a_second.z - z * a_second.y;
	crossProduct.y = z * a_second.x - x * a_second.z;
	crossProduct.z = x * a_second.y - y * a_second.x;

	return crossProduct;
}

void Vector3::setRotateX(float a_angle)
{
	float cosProduct = cos(a_angle);
	float sinProduct = sin(a_angle);
	y = y * cosProduct - z * sinProduct;
	z = y * sinProduct + z * cosProduct;
}

void Vector3::setRotateY(float a_angle)
{
	float cosProduct = cos(a_angle);
	float sinProduct = sin(a_angle);
	x = x * cosProduct - z * sinProduct;
	z = x * sinProduct + z * cosProduct;
}

void Vector3::setRotateZ(float a_angle)
{
	float cosProduct = cos(a_angle);
	float sinProduct = sin(a_angle);
	x = x * cosProduct - y * sinProduct;
	y = x * sinProduct + y * cosProduct;
}

Vector3::operator float*()
{
	return data;
}

Vector3 Vector3::operator+(const Vector3 & a_second) const
{
	Vector3 Result = *this;
	Result.Add(a_second);
	return Result;
}

Vector3 Vector3::operator-(const Vector3 & a_second) const
{
	Vector3 Result = *this;
	Result.Subtract(a_second);
	return Result;
}

Vector3 Vector3::operator*(const float a_second) const
{
	Vector3 Result = *this;
	Result.Multiply(a_second);
	return Result;
}

Vector3 Vector3::operator/(const float a_second) const
{
	Vector3 Result = *this;
	Result.Divide(a_second);
	return Result;
}

Vector3 Vector3::operator*(const Vector3 & a_second) const
{
	Vector3 result;
	result.x = this->x * a_second.x;
	result.y = this->y * a_second.y;
	result.z = this->z * a_second.z;
	return result;
}

float & Vector3::operator[](int a_i)
{
	return data[a_i];
}

Vector3 Vector3::Interpolate(Vector3 rhs, float t)
{
	return (rhs * (1 - t) + *this * t);
}

Vector3 Vector3::EaseLerp(Vector3 rhs, float t, float time)
{
	return *this;
}

Vector3 operator*(const float a_fscale, const Vector3 & a_RHS)
{
	return a_RHS * a_fscale;
}
