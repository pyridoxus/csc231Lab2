#include "Vector.h"

Vector::Vector(void)
{
	this->x = 0.0;
	this->y = 0.0;
	this->z = 0.0;
	return;
}

float Vector::getX(void)
{
	return this->x;
}

float Vector::getY(void)
{
	return this->y;
}

float Vector::getZ(void)
{
	return this->z;
}
