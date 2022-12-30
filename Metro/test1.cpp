#include "top.h"

void keyboard(){
	const float step = 2.0f;
	const float y_angle = 0.001;
	const float x_angle = 0.0005;
	if(keys['W']){
		camera.moveForward(step);
	}
	if(keys['S']){
		camera.moveForward(-step);
	}
	if(keys['A']){
		camera.moveRight(-step);
	}
	if(keys['D']){
		camera.moveRight(step);
	}
	if(keys['R']){
		camera.moveUp(step);
	}
	if(keys['F']){
		camera.moveUp(-step);
	}
	if(keys['T']){
		camera.rotateY(y_angle);
	}
	if(keys['E']){
		camera.rotateY(-y_angle);
	}
	if(keys['Z']){
		camera.rotateX(-x_angle);
	}
	if(keys['C']){
		camera.rotateX(x_angle);
	}
}
void chair();
void draw_chairs();
void draw_chairs_column();
void table();
Passenger_Carriage pc;
int x = 0;
int DrawGLScene(GLvoid)	// Here's Where We Do All The Drawing
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	keyboard();
	camera.look();
	glPushMatrix();
	glTranslated(0,0, -x);
	Centered_Cube(4000,4000,4000).draw_textured(space);
	glPopMatrix();
	//skybox();
	glPopMatrix();

	int b[] = {front, brick, back, top,right , left};
	//Centered_Cube(4000, 4000, 8000).draw_texturedS(b);
	//skybox();
	//glTranslated(1500, 500, -1000);
	//glTranslated(0, 0, 18000);
	
	//glTranslated(0,400,0);
	//pc.draw();
	//Centered_Cube(500, 500, 500).draw();
	table();
	frames++;
	return 1;
}

void table(){
	Color::show(WHITE);
	glPushMatrix();
	glRotated(90, 0, 1, 0);
	Centered_Cube(40, 15, 250).draw_textured(grayish);
	glRotated(90, 0, 1, 0);
	Centered_Cube(40, 15, 250).draw_textured(grayish);
	Color::show(BLACK);
	Centered_Cube(40, 2.2*150, 40).draw();
	glPopMatrix();
	Color::show(WHITE);
}

#include "bottom.h"