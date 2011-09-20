#ifndef TRIANGLE_H_
#define TRIANGLE_H_

#include <GL/glut.h>

class Triangle
{
	public:
		Triangle();
		virtual ~Triangle();
		void scale(void);
		void rotate(void);
		void translate(void);
		void draw(void);
	private:
		float triVert[3][2];
};

#endif /* TRIANGLE_H_ */
