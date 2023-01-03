#include "top.h"

const float step =2.0f;
const float y_angle = 0.001;
const float x_angle = 0.0005;
bool first_person = true;
void keyboard(){

	canMove = true; 
	/* set new virtual cam position to actual cam position */
	virt_cam.m_position = camera.m_position;
	//virt_cam.m_direction = camera.m_direction;
	if(keys['W']){
		virt_cam.moveForward(step);
		movementHeight += 0.05 * increasing;
		if(abs(movementHeight) >= 10) increasing = (increasing == 1 ? -1 : 1); 
	}
	if(keys['S']){
		virt_cam.moveForward(-step);
		movementHeight += 0.05 * increasing; 
		if(abs(movementHeight) >= 10) increasing = (increasing == 1 ? -1 : 1); 
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
	if(keys['V']){
		first_person = !first_person;
	}
}

Passenger_Carriage pc;
Kitchen_Carriage kc;
Chess_Carriage cc;
Football_Carriage fc;
Driver_Carriage dc;
GLfloat z_movement = 0;
int environment = 0;


Centered_Cube box (10000,4000,2600*11);
void draw_space(){
	ac.push_matrix(); 
	
	switch(environment){
	case 0:
		ac.translate(0, 0, -2600*10/2 + z_movement);
		box.draw_texturedS_raw(desert);
		ac.translate(0, 0, 2600*10 -200+ z_movement);
	Color::show(BLACK);
	Centered_Cube(6000, 4000, 500).draw();
	Color::show(WHITE);
		break;
	case 1:
		ac.translate(0, 0, -2600*10/2 + z_movement);
		box.draw_texturedS_raw(tundra);
		ac.translate(0, 0, 2600*10 -200 + z_movement);
	Color::show(BLACK);
	Centered_Cube(6000, 4000, 500).draw();
	Color::show(WHITE);	
	break;
	}
	Color::show(WHITE);
	//box.draw_textured(space);
	//box.hitbox();
	ac.pop_matrix();
	z_movement += 0.6;
}

void verify_movement(){
	if(canMove || keys['P']){
		camera.m_position.x =virt_cam.m_position.x; 
		camera.m_position.z =virt_cam.m_position.z; 
		camera.m_direction = virt_cam.m_direction;
	}
}

void third_person_cam(){
	virt_cam2.m_position = camera.m_position; 	
	virt_cam2.m_direction = camera.m_direction; 	
	virt_cam2.moveForward(-300);
	virt_cam2.moveUp(-20); 
	virt_cam2.moveRight(40); 
	virt_cam2.look();
	man->pos.x = camera.m_position.x; 
	man->pos.y = 0 + movementHeight; 
	man->pos.z = camera.m_position.z; 
	man->rot.x = 0; 
	man->rot.y = 180; 
	man->rot.z = 0; 
	man->Draw();
}

void reset_cam_pos(){
	camera.setPosition( 0, 500, 700);
	camera.setDirection( 0.0f, 0.0f, -1.0f );
	virt_cam.setPosition( 0, 500, 700);
	virt_cam.setDirection( 0.0f, 0.0f, -1.0f );
}

int curr_carriage = 0;

int DrawGLScene(GLvoid)	// Here's Where We Do All The Drawing
{
	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	ac.init();

	verify_movement();
	if(!first_person){
	// use third person cam
		third_person_cam();
	}
	else {
		camera.look();
	}
	
	keyboard(); 
	
	draw_space();
	
	ac.push_matrix();
	
	ac.translate(0, 40, 0);

	switch(curr_carriage){
	case 0:
		pc.draw(); 
		break;
	case 1:
		pc.draw();
		break;
	case 4:
		pc.draw();
		break;
	case  2:
		kc.draw();
		break;
	case  3:
		kc.draw();
		break;
	case 5:
		cc.draw();
		break;
	case 6:
		cc.draw();
		break;
	case 7: 
		fc.draw();
		break;
	case 8: 
		fc.draw();
		break;
	case 9:
		dc.draw();
		break;
	
	default:
		curr_carriage = 0;
		break;
	}

	if(keys['H'] && camera.m_position.z <= -800 && frames%573 == 0){
		curr_carriage++;
		reset_cam_pos();
	}	
	if(keys['H'] && camera.m_position.z >= 800 && frames%573 == 0){
		if(curr_carriage == 0){
			curr_carriage = 9;
		}else curr_carriage--;
		reset_cam_pos();
		
	}
	ac.pop_matrix();
	//glCallList(man_list);

	
	
	if(z_movement >= 2600*10){
		z_movement = 0;
		if(environment < 2) environment++;
		else environment = 0;
	}

	frames++;
	if(frames == 800) frames = 0;
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