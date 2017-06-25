#include "Matrix3D.h"
#include <cmath>


Matrix3::Matrix3()
{
	m0000 = 1; 
	m0001 = 0;
	m0010 = 0;
	m0011 = 0;
	m0100 = 1;
	m0101 = 0;
	m0110 = 0;
	m0111 = 0;
	m1000 = 1;
}

Matrix3::Matrix3(float a_pos1, float a_pos2, float a_pos3,
				 float a_pos4, float a_pos5, float a_pos6,
				 float a_pos7, float a_pos8, float a_pos9)
{
	m0000 = a_pos1;
	m0001 = a_pos2;
	m0010 = a_pos3;
	m0011 = a_pos4;
	m0100 = a_pos5;
	m0101 = a_pos6;
	m0110 = a_pos7;
	m0111 = a_pos8;
	m1000 = a_pos9;
}

Matrix3::~Matrix3()
{
}

Vector3 Matrix3::operator*(const Vector3 & a_RHS)
{
	Vector3 result;
	//result.x = m0000 * a_RHS.x + m0001 * a_RHS.y + m0010 * a_RHS.z;
	//result.y = m0011 * a_RHS.x + m0100 * a_RHS.y + m0101 * a_RHS.z;
	//result.z = m0110 * a_RHS.x + m0111 * a_RHS.y + m1000 * a_RHS.z;

	result.x = m0000 * a_RHS.x + m0011 * a_RHS.y + m0110 * a_RHS.z;
	result.y = m0001 * a_RHS.x + m0100 * a_RHS.y + m0111 * a_RHS.z;
	result.z = m0010 * a_RHS.x + m0101 * a_RHS.y + m1000 * a_RHS.z;

	return result;
}

Matrix3 Matrix3::operator+(const Matrix3 & a_second)
{
	Matrix3 alt;
	alt = *this;
	for (int i = 0; i < 9; i++)
	{
		alt.data[i] += a_second.data[i];
	}
	return alt;
}

Matrix3 Matrix3::operator-(const Matrix3 & a_second)
{
	Matrix3 alt;
	alt = *this;
	for (int i = 0; i < 9; i++)
	{
		alt.data[i] -= a_second.data[i];
	}
	return alt;
}

Matrix3 Matrix3::operator*(const Matrix3 & a_second)
{
	Matrix3 product;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			float sum = 0;
			for (int k = 0; k < 3; k++)
			{
				sum = sum + (data[k * 3 + i] * a_second.data[j * 3 + k]);
			}
			product.data[j * 3 + i] = sum;
		}
	}
	return product;
}

Vector3& Matrix3::operator[](int a_int)
{
	return columns[a_int];
}

Matrix3::operator float*()
{
	return data;
}

void Matrix3::setRotateX(const float a_fRotation)
{
	m0000 = 1;
	m0100 = cos(a_fRotation);
	m0101 = sin(a_fRotation);
	m0111 = -sin(a_fRotation);
	m1000 = cos(a_fRotation);
}

void Matrix3::setRotateY(const float a_fRotation)
{
	m0000 = cos(a_fRotation);
	m0010 = -sin(a_fRotation);
	m0100 = 1;
	m0110 = sin(a_fRotation);
	m1000 = cos(a_fRotation);
}

void Matrix3::setRotateZ(const float a_fRotation)
{
	m0000 = cos(a_fRotation);
	m0001 = sin(a_fRotation);
	m0011 = -sin(a_fRotation);
	m0100 = cos(a_fRotation);
	m1000 = 1;
}
