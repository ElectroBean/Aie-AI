#pragma once

struct Vector3
{
public:
	union {
		struct {
			float x, y, z;
		};
		float data[3];
	};

	Vector3::Vector3();
	Vector3::Vector3(float x, float y, float z);
	const Vector3& Translate(const Vector3& a_first, const Vector3& a_second);
	void Add(const Vector3& a_second);
	void Subtract(const Vector3& a_second);
	const Vector3& Scale(const Vector3& a_point, float a_scalar);
	void Multiply(float a_scalar);
	void Divide(float a_scalar);
	float magnitude();
	void normalise();
	Vector3 Vector3::getNormalised();
	float dot(const Vector3& a_second);
	const Vector3& cross(const Vector3& a_second);
	void setRotateX(float a_angle);
	void setRotateY(float a_angle);
	void setRotateZ(float a_angle);
	static float distance(Vector3 lh, Vector3 rh);

	explicit operator float*();

	Vector3 operator+(const Vector3& a_second) const;
	Vector3 operator-(const Vector3& a_second) const;
	Vector3 operator*(const float a_second) const;
	Vector3 operator/(const float a_second) const;
	Vector3 operator*(const Vector3& a_second) const;
	float& operator[](int a_i);
	Vector3 Interpolate(Vector3 rhs, float t);
	Vector3 EaseLerp(Vector3 rhs, float t, float time);
	bool operator==(const Vector3& a_second) const;
};

Vector3 operator*(const float a_fscale, const Vector3& a_RHS);