#ifndef TRIANGLE_H_
#define TRIANGLE_H_

#include <GL/glut.h>
#include <math.h>

class Triangle
{
	public:
		Triangle();
		virtual ~Triangle();
		void scale(float s);							// Scale triangle by factor s
		void rotate(float a);							// Rotate triangle by a degrees
		void translate(float x, float y);	// Translate triangle by (x,y)
		void draw(void);									// Draw the triangle
		void print(void);									// Print points for debugging
	private:
		float triVert[3][3];							// Points in the triangle
		float results[3][2];							// Results of transforming triangle
		void transform(float **m);				// Transform all points with matrix m
};

#endif
