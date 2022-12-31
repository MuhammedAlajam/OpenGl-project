#include "top.h"




void keyboard(){
	const float step = 1.0f;
	const float y_angle = 0.001;
	const float x_angle = 0.0005;
	canMove = true; 
	/* set new virtual cam position to actual cam position */
	virt_cam.m_position = camera.m_position;
	//virt_cam.m_direction = camera.m_direction;
	if(keys['W']){
		virt_cam.moveForward(step);
	}
	if(keys['S']){
		virt_cam.moveForward(-step);
	}
	if(keys['A']){
		virt_cam.moveRight(-step);
	}
	if(keys['D']){
		virt_cam.moveRight(step);
	}
	if(keys['R']){
		virt_cam.moveUp(step);
	}
	if(keys['F']){
		virt_cam.moveUp(-step);
	}

	/*	ROTATION	*/
	if(keys['Q']){
		virt_cam.rotateY(y_angle);
	}
	if(keys['E']){
		virt_cam.rotateY(-y_angle);
	}
	if(keys['Z']){
		virt_cam.rotateX(-x_angle);
	}
	if(keys['C']){
		virt_cam.rotateX(x_angle);
	}

}
void chair();
void draw_chairs();
void draw_chairs_column();
void draw_tree();
void draw_dinner_chair();
void table();
void draw_dinner_chairs();
void draw_table_with_chairs();
Passenger_Carriage pc;
Kitchen_Carriage kc;
Centered_Cube box = Centered_Cube(4000,4000,pc.depth*11);
void draw_space(){
	glPushMatrix();
	glTranslated(0, 0, -((pc.depth*11)/2)+pc.depth*1.8);
	box.draw_textured(space);
	glPopMatrix();
}

int x = 0;
int DrawGLScene(GLvoid)	// Here's Where We Do All The Drawing
{
	glClear(GL_COLOR_BUFFER_BIT |				         GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	if(canMove || true){
		camera.m_position = virt_cam.m_position; 
		camera.m_direction = virt_cam.m_direction;
	}
	camera.look();
	keyboard(); 

	draw_space();
	glTranslated(0,30,0);
	kc.draw();
	glPushMatrix();
	glScaled(1, 1.8,1);
	table();
	glPopMatrix();
	draw_table_with_chairs();

	frames++;
	return 1;
}
void draw_table_with_chairs(){
	glPushMatrix();
	draw_dinner_chairs();
	glTranslated(-91, 0, 0);
	glRotated(180, 0, 1, 0);
	draw_dinner_chairs();
	glPopMatrix();
}
void draw_dinner_chair(){
	glPushMatrix();
	glScaled(2, 1.6, 1);
	dinner_chair->Draw();
	glPopMatrix();
}
void draw_dinner_chairs(){
	glPushMatrix();
	glTranslated(-130, 100,-100);
	draw_dinner_chair();
	glTranslated(170, 0, 0);
	draw_dinner_chair();
	glPopMatrix();
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

	// transition to MIDDLE and UP
	glTranslated(95/2, 0.6*150 + 0, 0);

	// TABLE TABLE
	glColor4ub(175,175,175, 255);
	Centered_Cube(300, 8, 200).draw_textured(dinner_table);
	Color::show(WHITE);

	// POP & EXIT
	glPopMatrix();
	Color::show(WHITE);
}


void draw_tree(){
	tree->pos.x = 0;
	tree->pos.y = 0;
	tree->pos.z = 0;
	//palm_tree->scale=0.4;	
	glPushMatrix();
	glTranslated(0, 350, 0);
	glRotated(-90,1, 0,0);
	tree->Draw();
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