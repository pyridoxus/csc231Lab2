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
	this->tx = this->ty = this->tr = 0.0;
	this->ts = 1.0;
	return;
}

Triangle::~Triangle()
{
}

void Triangle::scale(float s)
{
	this->ts *= s;
	return;
}

void Triangle::rotate(float a)
{
	float d = a * 3.141592654 / 180.0;	// Convert degrees into radians
	this->tr += d;
	return;
}

void Triangle::translate(float x, float y)
{
	this->tx += x;
	this->ty += y;
	return;
}

void Triangle::doScale(void)		// Scale triangle by factor s
{
	float m[3][3] = { { this->ts,        0, 0 },
						  			{        0, this->ts, 0 },
							  		{        0,        0, 1 } };
//	cout << "Scale..." << endl;
	this->transform(m);
	return;
}

void Triangle::doRotate(void)		// Rotate triangle by a degrees
{
	float m[3][3] = { { cos(this->tr), -sin(this->tr), 0 },
								  	{ sin(this->tr),  cos(this->tr), 0 },
					  				{             0,              0, 1 } };
//	cout << "Rotate..." << endl;
	this->transform(m);
	return;
}

void Triangle::doTranslate(void)	// Translate triangle by (x,y)
{
	float m[3][3] = { { 1, 0, this->tx },
							  		{ 0, 1, this->ty },
								  	{ 0, 0,        1 } };
//	cout << "Translate..." << endl;
//	cout << "tx: " << this->tx << endl;
//	cout << "ty: " << this->ty << endl;
	this->transform(m);
	return;
}

void Triangle::drawNew(void)
{
	for(int x = 0; x < 3; x++)
	{
		for(int y = 0; y < 3; y++)
		{
			this->results[x][y] = this->triVert[x][y];
		}
	}
	this->doRotate();
	this->doScale();
	this->doTranslate();
	glVertex2f( this->results[0][0], this->results[0][1] );
	glVertex2f( this->results[1][0], this->results[1][1] );
	glVertex2f( this->results[2][0], this->results[2][1] );
	return;
}

void Triangle::drawOriginal(void)
{
  glVertex2f( this->triVert[0][0], this->triVert[0][1] );
	glVertex2f( this->triVert[1][0], this->triVert[1][1] );
	glVertex2f( this->triVert[2][0], this->triVert[2][1] );
	return;
}

void Triangle::transform(float m[3][3])	// Transform points with matrix m
{
	int x, y;
	float temp[3];
	float sum;
	for(int p = 0; p < 3; p++)
	{
//		cout << "Point " << p << endl;
		for(x = 0; x < 3; x++) temp[x] = this->results[p][x];
		for(y = 0; y < 3; y++)
		{
			sum = 0.0;
			for(x = 0; x < 3; x++)
			{
				sum += temp[x] * m[y][x];
//				cout << temp[x] << " " << m[y][x] << endl;
			}
			this->results[p][y] = sum;
//			cout << endl;
		}
	}
//	this->print();
	return;
}

void Triangle::print(void)	// Print the new points for debugging
{
	cout << this->results[0][0] << " " << this->results[0][1] << endl;
	cout << this->results[1][0] << " " << this->results[1][1] << endl;
	cout << this->results[2][0] << " " << this->results[2][1] << endl;
	return;
}
