#pragma once
#include "Math.h"
class Vector
{
	float x, y;
public:
	Vector();
	Vector(float x, float y);
	~Vector();
	void setXY(float x, float y);
	void setPolar(float r, float theta);
	float getX(){ return x; }
	float getY(){ return y; }
	float getR(){ return sqrt(x*x + y*y); }
	float getTheta(){ return atan2(y, x); }
	Vector& operator+(const Vector& v)
	{
		Vector vector;
		vector.x = this->x + v.x;
		vector.y = this->y + v.y;
		return vector;
	}
	Vector& operator-(const Vector& v)
	{
		Vector vector;
		vector.x = this->x - v.x;
		vector.y = this->y - v.y;
		return vector;
	}
	Vector& operator+=(const Vector& v)
	{
		this->x += v.x;
		this->y += v.y;
		return *this;
	}
};