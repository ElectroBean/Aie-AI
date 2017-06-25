#include "Matrix2D.h"

Matrix2::Matrix2()
{
	m00 = 1.0f;
	m01 = 0.0f;
	m10 = 0.0f;
	m11 = 1.0f;
}

Matrix2::Matrix2(float a_pos1, float a_pos2, float a_pos3, float a_pos4)
{
	m00 = a_pos1;
	m01 = a_pos2;
	m10 = a_pos3;
	m11 = a_pos4;
}


Matrix2::~Matrix2()
{
}

Vector2 Matrix2::operator*(const Vector2 & a_RHS)
{
	Vector2 result;
	result.x = m00 * a_RHS.x + m10 * a_RHS.y;
	result.y = m01 * a_RHS.x + m11 * a_RHS.y;
	return result;
}

Matrix2 Matrix2::operator+(const Matrix2 & a_second)
{
	Matrix2 alt;
	alt = *this;
	for (int i = 0; i < 4; i++)
	{
		alt.data[i] += a_second.data[i];
	}
	return alt;
}

Matrix2 Matrix2::operator-(const Matrix2 & a_second)
{
	Matrix2 alt;
	alt = *this;
	for (int i = 0; i < 4; i++)
	{
		alt.data[i] -= a_second.data[i];
	}
	return alt;
}

Matrix2 Matrix2::operator*(const Matrix2 & a_second)
{
	return Matrix2((m00 * a_second.m00 + m10 * a_second.m01),
				   (m01 * a_second.m00 + m11 * a_second.m01),
				   (m00 * a_second.m10 + m10 * a_second.m11),
				   (m01 * a_second.m10 + m11 * a_second.m11)
	);
}

Matrix2::operator float*()
{
	return data;
}

void Matrix2::setRotate(const float a_fRotation)
{
	m00 = cos(a_fRotation);
	m10 = -sin(a_fRotation);
	m01 = sin(a_fRotation);
	m11 = cos(a_fRotation);
}
