#pragma once
struct Vector2
{
public:
	union {
		struct {
			float x;
			float y;
		};
		float data[2];
	};

	Vector2::Vector2();
	Vector2::~Vector2();
	Vector2::Vector2(float x, float y);

	void Add(const Vector2& a_second);			//addition
	void Subtract(const Vector2& a_second);		//subtraction
	void Multiply(float a_scalar);				//multiplication
	void Divide(float a_scalar);				//division
	float magnitude();						    //get the magnitude
	void normalise();							//normalise void
	Vector2 Vector2::getNormalised();			//return new normalised vector2
	Vector2 Vector2::Direction();				//return direction vector
	void setRotateRad(float a_angle);			//set rotation in radians
	void setRotateDeg(float a_angle);			//set rotation in degrees
	float dot(const Vector2& a_second);
	static float distance(Vector2 a_1, Vector2 a_2);

	explicit operator float*();

	Vector2 operator+(const Vector2& a_second) const; //addition overload
	Vector2 operator-(const Vector2& a_second) const; //subtraction overload
	Vector2 operator*(const float a_second) const;    //multiplication overload
	Vector2 operator/(const float a_second) const;	  //division overload
	float& operator[](int a_i);						  //return from subscriptoverload
};

 Vector2 operator*(const float a_fscale, const Vector2& a_RHS);