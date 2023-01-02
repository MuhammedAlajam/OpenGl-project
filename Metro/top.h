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

Camera camera, virt_cam, third_cam;
int mouseX = 0, mouseY = 0;
bool isClicked = 0, isRClicked = 0;
AxisControl ac = AxisControl(); 
bool canMove = false;


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
	camera.setPosition( 0, 500, 2000);
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

	return TRUE;										// Initialization Went OK
}

double movX=1000, movZ=-1000,movY=500;

double lX=-1000, lY=-1000,lZ=-1000;

int shift = 1;

int frames = 0;


#include "objects.h"
#include "carriages.h"
#include "skybox.h"
