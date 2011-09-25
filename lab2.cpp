/**********************************************************************
Lab 2

Description
-----------
The program below draws a red triangle at the origin in a 2D world.

Transform (compute a new position for) the triangle by multiplying
each vertex position by a 2D affine scaling, rotation, or translation
matrix as specified below through keyboard input. As described in the
readings on matrices and 2D transformations, in order to compute
a new 2d position, you must first create a 3x3 matrix to perform a specific
type of 2d transformation (scaling, rotation, translation with specific
values as listed below). New positions are then computed by multiplying
the old position with this transformation matrix. Multiply the first
transformation matrix with the initial vertex positions to compute the
new positions and continue multiplying each new matrix created with the
previously computed positions. As a result, your new triangle should move
about the screen scaling, rotating, and translating. To display your results,
draw the new triangle vertices in green along with the original red triangle.
You may NOT use OpenGL matrix functions such as glScale, glTranslate, or
glRotate to perform your transformations. As you move your triangle about
the screen, note the differences when scaling, rotation, and translation
transforms are executed in different orders. Try scaling first, then rotating,
then translating. Compare with translating, then rotating, then scaling.

Keyboard input:
's' key, scale by 1.1 units in X and Y
'r' key, rotate clockwise (in XY plane) by 2.0 degrees
't' key, translate 0.1 unit in X and Y
'q' key, quit program
**********************************************************************/

#include "lab2.h"

int main( int argc, char *argv[] )	// return int because of Linux tool chain
{
  // Initialize window system
  glutInit( &argc, argv );
  glutInitDisplayMode( GLUT_SINGLE | GLUT_RGB );
  glutInitWindowSize( 640, 480 );
  glutCreateWindow( "Lab 2" );

  // Initialize graphics
  myInit();

  // Callbacks
  glutDisplayFunc( myDraw );
	glutKeyboardFunc( keyboard );

	// Event loop
  glutMainLoop();
  return 0;
}

// Initialize drawing
void myInit()
{
  // Background color
  glClearColor(0.0, 0.0, 0.0, 1.0);

  // 2D world projection
  glMatrixMode( GL_PROJECTION );
  glLoadIdentity();
  gluOrtho2D( -10.0, 10.0, -10.0, 10.0 );
}

// Display callback
void myDraw()
{
	// Clear the screen
  glClearColor(0.0, 0.0, 0.0, 1.0);
  glClear(GL_COLOR_BUFFER_BIT );

  // Draw triangle in initial position
  glColor3f( 1.0, 0.0, 0.0 );
  glBegin( GL_LINE_LOOP );
  	triangle.drawOriginal();
	glEnd();

  // Draw triangle in new position here
  glColor3f( 0.0, 1.0, 0.0 );
  glBegin( GL_LINE_LOOP );
  	triangle.drawNew();
	glEnd();

  // Execute draw commands
  glFlush();
}

// Keyboard callback
void keyboard( unsigned char key, int x, int y )
{
  // Process keys
  switch (key)
  {
  	case 's':
  		triangle.scale(1.1);
  	break;
  	case 'r':
  		triangle.rotate(-2.0);
  	break;
  	case 't':
  		triangle.translate(0.1, 0.1);
  	break;
  	case 'q':						// exit program
      exit(1);
    break;
  }

  // Redraw the scene
  glutPostRedisplay();
}
