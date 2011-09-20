/*
 * Triangle.cpp
 *
 *  Created on: Sep 20, 2011
 *      Author: pyridoxus
 */

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

void Triangle::scale(void)
{
	return;
}

void Triangle::rotate(void)
{
	return;
}

void Triangle::translate(void)
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
