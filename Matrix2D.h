#ifndef MATRIX2D_H_
#define MATRIX2D_H_
#include <iostream>
using namespace std;

class Matrix2D
{
	public:
		Matrix2D();
		virtual ~Matrix2D();
		void load(float **m);		// Load internal matrix with m
		int multiply(float **m);	// matrix = matrix X m
		void printMatrix(float **m);	// Print the matrix for debugging
	private:
		float matrix[3][3];
};

#endif
