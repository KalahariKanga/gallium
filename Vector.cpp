#include "Vector.h"


Vector::Vector()
{
	x = y = 0;
}

Vector::Vector(float x, float y) : x(x), y(y)
{

}

Vector::~Vector()
{
}

void Vector::setXY(float x, float y)
{
	this->x = x;
	this->y = y;
}

void Vector::setPolar(float r, float theta)
{
	x = r*cos(theta);
	y = r*sin(theta);
}