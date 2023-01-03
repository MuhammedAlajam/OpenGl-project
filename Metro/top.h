#include <windows.h>		// Header File For Windows
#include <gl.h>			// Header File For The OpenGL32 Library
#include <glu.h>			// Header File For The GLu32 Library
#include <glaux.h>		// Header File For The Glaux Library
#include <vector>
#include <stack>
#include <cmath>
#include <map>
#include <tuple>
#include <string.h> 
#include <texture.h>
#include "perspective_cam.h"
#include "colors.h"
#include <iostream> 
#include <math.h>
#include <random>
#include "Model_3DS.h"
#include "Axis_control.h"
#include "sound.h"


int desert[6], tundra[6];
Camera camera, virt_cam, virt_cam2;;
int mouseX = 0, mouseY = 0;
bool isClicked = 0, isRClicked = 0;
AxisControl ac = AxisControl(); 
bool canMove = false;
float movementHeight, increasing = 1;
GLfloat light_ambient[] = { 0, 0, 0, 1 };
GLfloat light_diffuse[] = { 100, 100, 100, 0 };
GLfloat light_specular[] = { 100, 100, 100, 0 };
GLfloat light_position[] = { 150, 2000, 0, 1 };
float mAmbient[] = {1.0,1.0,1.0,1};
float mDiffuse[] = {1.0,1.0,1.0,1};
float mSpecular[] = {0,0,0,1};
float mShininess[] = {128};



#include "basics.h"
#include "setup_textures.h"






HDC			hDC = NULL;		// Private GDI Device Context
HGLRC		hRC = NULL;		// Permanent Rendering Cntext
HWND		hWnd = NULL;		// Holds Our Window Handle
HINSTANCE	hInstance;		// Holds The Instance Of The Application

bool	keys[256];			// Array Used For The Keyboard Routine
bool	active = TRUE;		// Window Active Flag Set To TRUE By Default
bool	fullscreen = FALSE;	// Fullscreen Flag Set To Fullscreen Mode By Default

GLvoid ReSizeGLScene(GLsizei width, GLsizei height)		// Resize And Initialize The GL Window
{
	if (height == 0)										// Prevent A Divide By Zero By
	{
		height = 1;										// Making Height Equal One
	}

	glViewport(0, 0, width, height);						// Reset The Current Viewport

	glMatrixMode(GL_PROJECTION);						// Select The Projection Matrix
	glLoadIdentity();									// Reset The Projection Matrix

	// Calculate The Aspect Ratio Of The Window
	gluPerspective(45.0f, (GLfloat)width / (GLfloat)height, 0.1f, 200000.0f);

	glMatrixMode(GL_MODELVIEW);							// Select The Modelview Matrix
	glLoadIdentity();									// Reset The Modelview Matrix
}


int InitGL(GLvoid)										// All Setup For OpenGL Goes Here
{
	// Set the initial position and direction of the camera
	camera.setPosition( 0, 500, 1);
	camera.setDirection( 0.0f, 0.0f, -1.0f );
	virt_cam.setPosition( 0, 500, 2000);
	virt_cam.setDirection( 0.0f, 0.0f, -1.0f );
	glShadeModel(GL_SMOOTH);							// Enable Smooth Shading
	glClearColor(0.0f, 0.0f, 0.0f, 0.5f);				// Black Background
	glClearDepth(1.0f);									// Depth Buffer Setup
	glEnable(GL_DEPTH_TEST);							// Enables Depth Testing
	glDepthFunc(GL_LEQUAL);	
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);// The Type Of Depth Testing To Do
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);	// Really Nice Perspective Calculations


	
	



	/*	setup textures	*/
	glEnable(GL_TEXTURE_2D);
	Texture::LOAD_TEXTURES();
	Texture::MAKE_MODELS();

	/*	setup lists	*/
	Texture::MAKE_LISTS();




	/* setup lighting */
	glLightfv(GL_LIGHT1,GL_POSITION,light_position);
  glLightfv(GL_LIGHT1,GL_AMBIENT,light_ambient);
  glLightfv(GL_LIGHT1,GL_DIFFUSE,light_diffuse);
  glLightfv(GL_LIGHT1,GL_SPECULAR,light_specular);
  glMaterialfv(GL_FRONT,GL_AMBIENT,mAmbient);
  glMaterialfv(GL_FRONT,GL_DIFFUSE,mDiffuse);
  glMaterialfv(GL_FRONT,GL_SPECULAR,mSpecular);
  glMaterialfv(GL_FRONT,GL_SHININESS,mShininess);
  glEnable(GL_COLOR_MATERIAL);
  glEnable(GL_LIGHT1);
  glEnable(GL_LIGHTING);




	return TRUE;										// Initialization Went OK
}

double movX=1000, movZ=-1000,movY=500;

double lX=-1000, lY=-1000,lZ=-1000;

int shift = 1;

int frames = 0;


#include "objects.h"
#include "carriages.h"
#include "skybox.h"
