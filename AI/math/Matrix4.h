#pragma once
#include <iostream>
#include "Vector4.h"

class Matrix4
{
public:
public:
	union {
		struct {
			float m1, m2, m3, m4,
				  m5, m6, m7, m8,
			   	  m9, m10, m11, m12,
				  m13, m14, m15, m16;
		};
		float data[16];
		struct {
			Vector4 columns[4];
		};
	};
	Matrix4();
	Matrix4(float a_pos1, float a_pos2, float a_pos3, float a_pos4, 
			float a_pos5, float a_pos6,float a_pos7, float a_pos8, 
			float a_pos9, float a_pos10, float a_pos11, float a_pos12,
			float a_pos13, float a_pos14, float a_pos15, float a_pos16);
	~Matrix4();

	Vector4 operator*(const Vector4& a_RHS);
	Matrix4 operator+(const Matrix4& a_second);
	Matrix4 operator-(const Matrix4& a_second);
	Matrix4 operator*(const Matrix4& a_second);


	explicit operator float*();
	Vector4& operator[](int a_int);

	void setRotateX(const float a_fRotation);
	void setRotateY(const float a_fRotation);
	void setRotateZ(const float a_fRotation);

};

