#include "Matrix2D.h"

Matrix2D::Matrix2D()
{
	float m[3][3] = { {0.0, 0.0, 0.0},
									  {0.0, 0.0, 0.0},
									  {0.0, 0.0, 0.0} };
	this->load(m);
}

Matrix2D::~Matrix2D()
{
}

void Matrix2D::load(float **m)
{
	for(int y = 0; y < 3; y++)
	{
		for(int x = 0; x < 3; x++)
		{
			this->matrix[x][y] = m[x][y];
		}
	}
	return;
}

int Matrix2D::multiply(float **m)
{
	float sum;
	float temp[3][3];
	int a, x, y;
	for(y = 0; y < 3; y++)
	{
		for(x = 0; x < 3; x++)
		{
			sum = 0.0;
			for(a = 0; a < 3; a++)
			{
				sum += this->matrix[a][y] * m[x][a];
			}
			temp[x][y] = sum;
		}
	}
	this->load(temp);
	this->printMatrix(this->matrix);
	return 0;
}

void Matrix2D::printMatrix(float **m)
{
	cout << m[0][0] << " " << m[1][0] << " " << m[2][0] << endl;
	cout << m[0][1] << " " << m[1][1] << " " << m[2][1] << endl;
	cout << m[0][2] << " " << m[1][2] << " " << m[2][2] << endl;
	return;
}
