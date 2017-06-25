#pragma once
#include <iostream>
#include "Vector3.h"

class Matrix3
{
public:
public:
	union {
		struct {
			float m0000, m0001, m0010, 
				  m0011, m0100, m0101,
				  m0110, m0111, m1000;
		};
		float data[9];
		struct {
			Vector3 columns[3];
		};
		struct {
			Vector3 right;
			Vector3 forward;
			Vector3 position;
		};
	};
	Matrix3();
	Matrix3(float a_pos1, float a_pos2, float a_pos3, 
			float a_pos4, float a_pos5, float a_pos6, 
			float a_pos7, float a_pos8, float a_pos9);
	~Matrix3();

	Vector3 operator*(const Vector3& a_RHS);
	Matrix3 operator+(const Matrix3& a_second);
	Matrix3 operator-(const Matrix3& a_second);
	Matrix3 operator*(const Matrix3& a_second);

	
	explicit operator float*();
	Vector3& operator[](int a_int);

	void setRotateX(const float a_fRotation);
	void setRotateY(const float a_fRotation);
	void setRotateZ(const float a_fRotation);

};

