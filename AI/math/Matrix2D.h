#pragma once
#include <iostream>
#include "Vector2.h"

class Matrix2
{
public:
	union {
		struct {
			float m00, m01, m10, m11;
		};
		float data[4];
	};
	Matrix2();
	Matrix2(float a_pos1, float a_pos2, float a_pos3, float a_pos4);
	~Matrix2();

	Vector2 operator*(const Vector2& a_RHS);
	Matrix2 operator+(const Matrix2& a_second);
	Matrix2 operator-(const Matrix2& a_second);
	Matrix2 operator*(const Matrix2& a_second);

	explicit operator float*();

	void setRotate(const float a_fRotation);
};

