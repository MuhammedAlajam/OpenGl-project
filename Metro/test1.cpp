#include "top.h"

const float step =1.0f;
const float y_angle = 0.001;
const float x_angle = 0.0005;

void keyboard(){

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

Passenger_Carriage pc;
Kitchen_Carriage kc;
Centered_Cube box (4000,4000,2600*11);
void draw_space(){
	ac.push_matrix(); 
	ac.translate(0, 0, -((pc.depth*11)/2)+pc.depth*1.8);
	glCallList(space_box_list);
	box.hitbox();
	ac.pop_matrix();
}

void verify_movement(){
	if(canMove || keys['P']){
		camera.m_position.x =virt_cam.m_position.x; 
		camera.m_position.z =virt_cam.m_position.z; 
		camera.m_direction = virt_cam.m_direction;
	}
}
Chess_Carriage cc;
int x = 0;
int DrawGLScene(GLvoid)	// Here's Where We Do All The Drawing
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	ac.init();

	verify_movement();

	camera.look();
	keyboard(); 

	draw_space();

	cc.draw(); 

	//glCallList(man_list);

	if(keys['H']){
		Sound::make_sound(bell_sound);
	}	

	frames++;
	return 1;
}



void draw_tree(){
	tree->pos.x = 0;
	tree->pos.y = 0;
	tree->pos.z = 0;
	//palm_tree->scale=0.4;	
	ac.push_matrix();
	ac.translate(0, 350, 0);
	glRotated(-90,1, 0,0);
	tree->Draw();
	ac.pop_matrix();
}


//Centered_Cube(4000, 4000, 8000).draw_texturedS(b);
//skybox();
//ac.translate(1500, 500, -1000);
//ac.translate(0, 0, 18000);

//ac.translate(0,400,0);
//pc.draw();
//Centered_Cube(500, 500, 500).draw();




#include "bottom.h"