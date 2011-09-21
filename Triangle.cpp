#include "Triangle.h"

Triangle::Triangle()
{
	triVert[0][0] = -1.0;
	triVert[0][1] =	-1.0;
	triVert[1][0] = 1.0;
	triVert[1][1] = -1.0;
	triVert[2][0] = 0.0;
	triVert[2][1] = 1.0;
	return;
}

Triangle::~Triangle()
{
}

void Triangle::scale(float s)
{
	return;
}

void Triangle::rotate(float a)
{
	return;
}

void Triangle::translate(float x, float y)
{
	return;
}

void Triangle::draw(void)
{
  glVertex2f( triVert[0][0], triVert[0][1] );
	glVertex2f( triVert[1][0], triVert[1][1] );
	glVertex2f( triVert[2][0], triVert[2][1] );
	return;
}
