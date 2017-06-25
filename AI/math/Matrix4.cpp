#include "Matrix4.h"



Matrix4::Matrix4()
{
	m1  =  1;
	m2  =  0;
	m3  =  0;
	m4  =  0;
	m5  =  0;
	m6  =  1;
	m7  =  0;
	m8  =  0;
	m9  =  0;
	m10 =  0;
	m11 =  1;
	m12 =  0;
	m13 =  0;
	m14 =  0;
	m15 =  0;
	m16 =  1;
}

Matrix4::Matrix4(float a_pos1, float a_pos2, float a_pos3, float a_pos4,
	float a_pos5, float a_pos6, float a_pos7, float a_pos8,
	float a_pos9, float a_pos10, float a_pos11, float a_pos12,
	float a_pos13, float a_pos14, float a_pos15, float a_pos16)
{
	m1 = a_pos1;
	m2 = a_pos2;
	m3 = a_pos3;
	m4 = a_pos4;
	m5 = a_pos5;
	m6 = a_pos6;
	m7 = a_pos7;
	m8 = a_pos8;
	m9 = a_pos9;
	m10 = a_pos10;
	m11 = a_pos11;
	m12 = a_pos12;
	m13 = a_pos13;
	m14 = a_pos14;
	m15 = a_pos15;
	m16 = a_pos16;
}


Matrix4::~Matrix4()
{
}

Vector4 Matrix4::operator*(const Vector4 & a_RHS)
{
	Vector4 result;

	result.x = m1 * a_RHS.x + m5 * a_RHS.y + m9 * a_RHS.z + m13 * a_RHS.w;
	result.y = m2 * a_RHS.x + m6 * a_RHS.y + m10 * a_RHS.z + m14 * a_RHS.w;
	result.z = m3 * a_RHS.x + m7 * a_RHS.y + m11 * a_RHS.z + m15 * a_RHS.w;
	result.w = m4 * a_RHS.x + m8 * a_RHS.y + m12 * a_RHS.z + m16 * a_RHS.w;

	return result;
}

Matrix4 Matrix4::operator+(const Matrix4 & a_second)
{
	Matrix4 alt;
	alt = *this;
	for (int i = 0; i < 16; i++)
	{
		alt.data[i] += a_second.data[i];
	}
	return alt;
}

Matrix4 Matrix4::operator-(const Matrix4 & a_second)
{
	Matrix4 alt;
	alt = *this;
	for (int i = 0; i < 16; i++)
	{
		alt.data[i] -= a_second.data[i];
	}
	return alt;
}

Matrix4 Matrix4::operator*(const Matrix4 & a_second)
{
	Matrix4 product;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			float sum = 0;
			for (int k = 0; k < 4; k++)
			{
				sum = sum + (data[k * 4 + i] * a_second.data[j * 4 + k]);
			}
			product.data[j * 4 + i] = sum;
		}
	}
	return product;
}

Matrix4::operator float*()
{
	return data;
}

Vector4 & Matrix4::operator[](int a_int)
{
	return columns[a_int];
	// TODO: insert return statement here
}

void Matrix4::setRotateX(const float a_fRotation)
{
	m1 = 1;
	m6 = cos(a_fRotation);
	m7 = sin(a_fRotation);
	m10 = -sin(a_fRotation);
	m11 = cos(a_fRotation);
	m16 = 1;
}

void Matrix4::setRotateY(const float a_fRotation)
{
	m1 = cos(a_fRotation);
	m3 = -sin(a_fRotation);
	m6 = 1;
	m9 = sin(a_fRotation);
	m11 = cos(a_fRotation);
	m16 = 1;
}

void Matrix4::setRotateZ(const float a_fRotation)
{
	m1 = cos(a_fRotation);
	m2 = sin(a_fRotation);
	m5 = -sin(a_fRotation);
	m6 = cos(a_fRotation);
	m11 = 1;
	m16 = 1;
}
