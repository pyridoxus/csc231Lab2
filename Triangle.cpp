#include "Triangle.h"

Triangle::Triangle()
{
	this->triVert[0][0] = -1.0;
	this->triVert[0][1] =	-1.0;
	this->triVert[0][2] =	1.0;
	this->triVert[1][0] = 1.0;
	this->triVert[1][1] = -1.0;
	this->triVert[1][2] =	1.0;
	this->triVert[2][0] = 0.0;
	this->triVert[2][1] = 1.0;
	this->triVert[2][2] =	1.0;
	return;
}

Triangle::~Triangle()
{
}

void Triangle::scale(float s)
{
	float m[][] = { { s, 0, 0 },
									{ 0, s, 0 },
									{ 0, 0, 1 } };
	this->transform(m);
	return;
}

void Triangle::rotate(float a)
{
	float d = a * 3.141592654 / 180.0;	// Convert degrees into radians
	float m[][] = { { cos(d), -sin(d), 0 },
									{ sin(d),  cos(d), 0 },
									{      0,       0, 1 } };
	this->transform(m);
	return;
}

void Triangle::translate(float x, float y)
{
	float m[][] = { { 0, 0, x },
									{ 0, 0, y },
									{ 0, 0, 1 } };
	this->transform(m);
	return;
}

void Triangle::draw(void)
{
  glVertex2f( this->results[0][0], this->results[0][1] );
	glVertex2f( this->results[1][0], this->results[1][1] );
	glVertex2f( this->results[2][0], this->results[2][1] );
	return;
}

void Triangle::transform(int p, float **m)	// Transform point p with matrix m
{
	int x, y;
	for(p = 0; p < 3; p++)
	{
		this->results[p][0] = this->results[p][1] = this->results[p][2] = 0.0;
		for(y = 0; y < 3; y++)
		{
			for(x = 0; x < 3; x++)
			{
				this->results[p][y] += this->triVert[p][x] * m[x][y];
			}
		}
	}
	return;
}

void Triangle::print(void)	// Print the new points for debugging
{
	cout << this->results[0][0] << " " << this->results[0][1] << endl;
	cout << this->results[1][0] << " " << this->results[1][1] << endl;
	return;
}
