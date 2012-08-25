//This program is free software: you can redistribute it and/or modify
//    it under the terms of the GNU General Public License as published by
//    the Free Software Foundation, either version 3 of the License, or
//    (at your option) any later version.
//
//    This program is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//    GNU General Public License for more details.
//
//    You should have received a copy of the GNU General Public License
//    along with this program.  If not, see <http://www.gnu.org/licenses/>.
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
