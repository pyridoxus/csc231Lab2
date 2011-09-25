#ifndef TRIANGLE_H_
#define TRIANGLE_H_

#include <iostream>
using namespace std;
#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>

class Triangle
{
	public:
		Triangle();
		virtual ~Triangle();
		void scale(float s);							// Set scale triangle by factor s
		void rotate(float a);							// Set rotate triangle by a degrees
		void translate(float x, float y);	// Set translate triangle by (x,y)
		void drawOriginal(void);					// Draw the original triangle
		void drawNew(void);								// Draw the transformed triangle
		void print(void); 								// Print points for debugging
	private:
		float triVert[3][3];							// Points in the triangle
		float results[3][3];							// Results of transforming triangle
		float tx;													// Translation X from original
		float ty;													// Translation Y from original
		float tr;													// Rotation from original
		float ts;													// Scale from original
		void transform(float m[3][3]);		// Transform all points with matrix m
		void doScale(void);								// Scale triangle by factor s
		void doRotate(void);							// Rotate triangle by a degrees
		void doTranslate(void);						// Translate triangle by (x,y)
};

#endif
