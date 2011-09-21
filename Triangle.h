#ifndef TRIANGLE_H_
#define TRIANGLE_H_

#include <GL/glut.h>
#include "Vector.h"

class Triangle
{
	public:
		Triangle();
		virtual ~Triangle();
		void scale(float s);							// Scale triangle by factor s
		void rotate(float a);							// Rotate triangle by a degrees
		void translate(float x, float y);	// Translate triangle by (x,y)
		void draw(void);									// Draw the triangle
	private:
		float triVert[3][2];							// Points in the triangle
		void multiply(int p, Vector v);		// Multiply index to point p by vector v
};

#endif
