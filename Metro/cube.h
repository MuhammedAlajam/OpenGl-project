#include <windows.h>		// Header File For Windows
#include <gl.h>			// Header File For The OpenGL32 Library
#include <glu.h>
#include <GL/gl.h> // Include the OpenGL header file
#include "basics.h"
class Cube : public entity{
public:
	Point p[8];

	Cube(){
		p[0] = Point(0, 0, 0); 
		p[1] = Point(1, 0, 0);
		p[2] = Point(1,1,0);
		p[3] = Point(0,1,0);

		p[4] = Point(0, 0, 0); 
		p[5] = Point(1, 0, 0);
		p[6] = Point(1,1,0);
		p[7] = Point(0,1,0);
	};

	Rect(p[0], p[1], p[2], p[3]);
	Rect(p[0], p[1], p[2], p[3]);

};