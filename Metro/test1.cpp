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
void draw_chairs();
void draw_chairs_column();
void draw_tree();
void table();
Passenger_Carriage pc;
int x = 0;
int DrawGLScene(GLvoid)	// Here's Where We Do All The Drawing
{
	glClear(GL_COLOR_BUFFER_BIT |				         GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	keyboard();
	camera.look();
	
	Centered_Cube(4000,4000,4000).draw_textured(space);

	draw_tree();

	/*table();
	glTranslated(-50, 0, -150);
	chair();*/
	frames++;
	return 1;
}

void table(){
	Color::show(WHITE);
	glPushMatrix();

	// CROSS BRACE
	glRotated(90, 0, 1, 0);
	Centered_Cube(12, 7.5, 60).draw_textured(grayish);
	glRotated(90, 0, 1, 0);
	Centered_Cube(12, 7.5, 60).draw_textured(grayish);
	
	// SHAFT
	Centered_Cube(10, 0.6*150, 10).draw_textured(grayish);


	// transition to second pair
	glTranslated(95, 0, 0);

	// CROSS BRACE 2
	glRotated(90, 0, 1, 0);
	Centered_Cube(12, 7.5, 60).draw_textured(grayish);
	glRotated(90, 0, 1, 0);
	Centered_Cube(12, 7.5, 60).draw_textured(grayish);
	
	// SHAFT 2
	Centered_Cube(10, 0.6*150, 10).draw_textured(grayish);

	// transition to MIDDLE
	glTranslated(95/2, 0.6*150 + 0, 0);

	// TABLE TABLE
	Centered_Cube(300, 12, 200).draw_textured(wood);

	// POP & EXIT
	glPopMatrix();
	Color::show(WHITE);
}


void draw_tree(){
	tundra_tree->pos.x = 0;
	tundra_tree->pos.y = 0;
	tundra_tree->pos.z = 0;
	//palm_tree->scale=0.4;	
	glPushMatrix();
	glTranslated(0, 350, 0);
	glRotated(-90,1, 0,0);
	tundra_tree->Draw();
	glPopMatrix();
}


//Centered_Cube(4000, 4000, 8000).draw_texturedS(b);
	//skybox();
	//glTranslated(1500, 500, -1000);
	//glTranslated(0, 0, 18000);
	
	//glTranslated(0,400,0);
	//pc.draw();
	//Centered_Cube(500, 500, 500).draw();

#include "bottom.h"