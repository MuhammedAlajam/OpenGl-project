#include "top.h"
void keyboard(){
	const float step = 0.5f;
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
	if(keys['Q']){
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
Driver_Carriage driver_carriage;
int DrawGLScene(GLvoid)	// Here's Where We Do All The Drawing
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	keyboard();
	camera.look();
	glPushMatrix();
	glTranslated(-2000,0,2000);
	skybox();
	glPopMatrix();
	int b[] = {front, brick, back, top,right , left};
	//Centered_Cube(4000, 4000, 8000).draw_texturedS(b);
	//skybox();
	//glTranslated(1500, 500, -1000);
	//glTranslated(2000, 100, -2000);
	driver_carriage.draw();
	glPushMatrix();
	glTranslated(-100, 20, 0);
	glScaled(0.8, 0.8, 0.8);
	chair();
	glTranslated(0, 0, 200);
	glRotated(180, 0, 1, 0);
	chair();
	glPopMatrix();

	frames++;
	return 1;
}

void chair(){
	glTranslated(0,40,0);
	glPushMatrix();
	glTranslated(0,0,-5);
	Frustum(92.5*2,30,80, 4).draw_textured(cushion);
	glPopMatrix();
	Centered_Cube(105*2,-60,110).draw_textured(light_wood);
	glPushMatrix();
	glTranslated(0, 0, -40);
	Centered_Cube(95*2, 120, -30).draw_textured(cushion);
	glTranslated(0, -14, -24);
	Color::show(WHITE);
	Centered_Cube(105*2, 150, -18).draw_textured(light_wood);
	glPopMatrix();
}

#include "bottom.h"