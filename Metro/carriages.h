class Carriage{
public:
	GLfloat width, height, depth;
	Centered_Cube main_body;
	void draw();
};

class Basic_Carriage : public Carriage{
public:
	GLfloat delta_d, delta_h;
	Basic_Carriage(){
		height = 1000;
		depth = 2600;
		width = 800;
		main_body = Centered_Cube(width, height, depth);
		
	}

	void draw(){
		private_draw();
	}
	void private_draw(){
		Color::show(WHITE);
		main_body.get_bottom_face().checkMove();
		main_body.get_bottom_face().draw_textured(floors);
		main_body.get_deep_face().draw_textured(front_train);
		main_body.get_front_face().draw_textured(front_train);
		glColor3ub(175, 175,175);
		main_body.get_top_face().draw_textured(roof);
		Color::show(WHITE);
		draw_sides();
	}
	void draw_sides(){
		ac.push_matrix();
		Centered_Cube stamp(width, 3*height/12, depth);
		stamp.get_left_face().draw_textured(window_bottom_train);
		stamp.get_right_face().draw_textured(window_bottom_train);
		ac.translate(0, height/4, 0);
		stamp = Centered_Cube(width, 5*height/12, depth);
		glColor4ub(0, 0, 60, 102);
		stamp.get_left_face().draw();
		stamp.get_right_face().draw();
		ac.translate(0, 5*height/12, 0);
		Color::show(WHITE);
		stamp = Centered_Cube(width, 4*height/12, depth);
		stamp.get_left_face().draw_textured(window_top_train);
		stamp.get_right_face().draw_textured(window_top_train);
		glColor4ub(0,0,0, 100);
		Color::show(WHITE);
		ac.pop_matrix();
	}

};

class Passenger_Carriage : public Basic_Carriage{
public: 

	void draw(){
		ac.push_matrix();
		private_draw();
		draw_chairs_column();
		ac.translate(500, 0, 0);
		draw_chairs_column();
		ac.translate(-500, 998, 0);
		glColor4ub(0,0,60, 100);
		Centered_Cube(10*width/12, 1, depth - (depth/4)).draw();
		ac.translate(0, 1, 0);
		glColor4ub(49, 48, 51, 255);
		Centered_Cube(width, 1, depth).get_top_face().draw();
		Color::show(WHITE);
		ac.pop_matrix();
	}
	void private_draw(){
		Color::show(WHITE);
		main_body.get_bottom_face().checkMove(); 
		main_body.get_bottom_face().draw_textured(floors);
		main_body.get_deep_face().draw_textured(front_train);
		main_body.get_front_face().draw_textured(front_train);
		glColor3ub(175, 175,175);
		//main_body.get_top_face().draw_textured(wood);
		Color::show(WHITE);
		draw_sides();
	}

};

class Kitchen_Carriage : public Basic_Carriage{
public:
	void draw(){
		private_draw();

		ac.push_matrix();
		ac.translate(-140, 0,0);
		ac.push_matrix();
		ac.translate(0,0, 1100);
		draw_table_with_chairs();
		glColor4ub(255, 0,0, 150);
		ac.translate(-50,0,0);
		Centered_Cube(300, 60, 400).draw();
		Color::show(WHITE);
		ac.translate(0,0, -600);
		draw_table_with_chairs();
		glColor4ub(255, 0,0, 150);
		Centered_Cube(250, 60, 400).draw();
		Color::show(WHITE);
		ac.translate(0,0, -500);
		draw_table_with_chairs();
		glColor4ub(255, 0,0, 150);
		Centered_Cube(250, 60, 400).draw();
		Color::show(WHITE);
		ac.translate(0,0, -500);
		draw_table_with_chairs();
		glColor4ub(255, 0,0, 150);
		Centered_Cube(250, 60, 400).draw();
		Color::show(WHITE);
		ac.translate(0,0, -500);
		draw_table_with_chairs();
		glColor4ub(255, 0,0, 150);
		Centered_Cube(250, 60, 400).draw();
		Color::show(WHITE);
		ac.pop_matrix();
		ac.pop_matrix();


	}
	void draw_table_with_chairs(){
		glCallList(draw_table_with_chairs_list);
	}

	void draw_dinner_chairs(){
		glCallList(dinner_chairs_list);
	}
};

class Chess_Carriage : public Basic_Carriage{
public:
	Centered_Cube chess_table_hitbox, chess_chair_hitbox, end_table_hitbox;

	Chess_Carriage(){
		chess_table_hitbox = Centered_Cube(400,400,400);
		chess_chair_hitbox = Centered_Cube(340, 200, 320);
		end_table_hitbox = Centered_Cube(220, 300, 220);
	}

	void draw(){

		private_draw();
		ac.push_matrix();
		ac.translate(-180,23,0);
		glCallList(chess_table_list);
		glColor4ub(255, 0, 0, 150);
		chess_table_hitbox.hitbox();

		Color::show(WHITE);

		ac.push_matrix();
		ac.translate(0, 120, 0);
		glScaled(0.05, 0.05, 0.05);
		draw_chessboard();
		ac.pop_matrix();

		ac.translate(140, 120, 0);
		Color::show(WHITE);
		glCallList(chess_clock_list);


		ac.pop_matrix();


		// draw chairs
		ac.push_matrix();
		glScaled(0.9, 1,1);
		ac.translate(-180,23,-350);
		glCallList(chess_chairs_list);

		// create chair hitboxes
		ac.translate(0,0 , 0);
		chess_chair_hitbox.hitbox();

		ac.translate(-0, 0, 700);
		chess_chair_hitbox.hitbox();
		ac.pop_matrix();

		// draw end table one
		ac.push_matrix();
		ac.translate(-180, 0, 900);
		end_table_hitbox.hitbox();
		glCallList(end_table_list);
		ac.translate(0, 310, 5);

		// figurine deco
		glCallList(figurine_list);


		ac.pop_matrix();

		// draw end table two
		ac.push_matrix();
		ac.translate(-180, 0, -950);
		end_table_hitbox.hitbox();
		glCallList(end_table_list);
		ac.translate(0, 310, 5);

		// plate for deco
		glCallList(plate_list);

		ac.pop_matrix();

		if(keys['T']){
			Sound::make_sound(bell_sound);
		}

	}
	void draw_chessboard(){
		glCallList(chess_board_list);
	}

};

class Driver_Carriage:public Basic_Carriage{
public:
	Centered_Cube bottom_front_window, top_front_window,trainn;
	

	Driver_Carriage(){
		bottom_front_window = Centered_Cube(width, 2*height/5, depth);
		top_front_window = Centered_Cube(width, 3*height/5, depth);
		trainn = Centered_Cube (800,0,2600*11);
	}

	void draw(){
		private_draw();
		glColor3ub(115, 115,117);
		ac.push_matrix();
		ac.translate(-main_body.width/2 + main_body.width/16,0,(-main_body.depth/2) + 40);
		Centered_Cube(main_body.width/8, main_body.height, 80).draw();
		ac.pop_matrix();
		ac.push_matrix();
		ac.translate(-(-main_body.width/2 + main_body.width/16),0,(-main_body.depth/2) + 40);
		Centered_Cube(main_body.width/8, main_body.height, 80).draw();
		ac.pop_matrix();

		// DRAW CENTER CONSOLE
		ac.translate(0,0,(-main_body.depth/2) + 60);
		Color::show(WHITE);
		Centered_Cube(width - (main_body.width/4), bottom_front_window.height -40, 120).draw_textured(cabinn_train);

		//	DRAW DRIVER CHAIR
		ac.push_matrix();
		glRotated(180, 0, 1, 0);
		ac.translate(0, 100, -500);
		glScaled(1.4, 1.4, 1.4);
		chair();
		ac.pop_matrix();
		Color::show(WHITE);
	}

	void private_draw(){
		Color::show(WHITE);
		main_body.get_bottom_face().checkMove();
		main_body.get_bottom_face().draw_textured(floors);
		glPushMatrix();
		glTranslated(0,-5,-3000);
		trainn.get_bottom_face().draw_textured(train);											///Mohmad Joma
		glPopMatrix();
		main_body.get_deep_face().draw_textured(front_train);

		// DRAW DRIVER WINDOW

		bottom_front_window.get_front_face().draw_textured(window_bottom_train);
		ac.push_matrix();
		ac.translate(0, bottom_front_window.height, 0);
		glColor4ub(0, 0, 60, 102);
		top_front_window.get_front_face().draw();
		Color::show(WHITE);
		ac.pop_matrix();

		// DRAW ROOF
		glColor3ub(175, 175,175);
		main_body.get_top_face().draw_textured(roof);
		Color::show(WHITE);

		draw_sides();
	}
};

class Football_Carriage:public Basic_Carriage{
public:
	bool sound;
	Centered_Cube main_body, sofa_hitbox_1, sofa_hitbox_2;
	Football_Carriage(){
		main_body = Centered_Cube(width, height, depth);
		sofa_hitbox_1 = Centered_Cube(300, 200, 200);
		sofa_hitbox_2 = Centered_Cube(500, 200, 200);
		sound = false;
	}
	void draw(){
		int a[]  = {wall2, wall2, wall2, wall2, wall2, wall2};
		main_body.draw_texturedS(a);
		////cenama carriage
		ac.push_matrix();
		ac.translate(-200, 120, -700);
		sofa();

		// add table and tv
		ac.push_matrix();
		ac.translate((width/2)+80, 0, 100);
		tablee();
		Tv();
		ac.pop_matrix();



		//setup sofa hit box
		ac.push_matrix();
		ac.translate(40,40,-200);
		sofa_hitbox_1.hitbox();
		ac.translate(-340/2,0,400);
		glRotated(90, 0, 1, 0);
		sofa_hitbox_2.hitbox();
		ac.pop_matrix();

		//Cube(100, 100, -400).draw();
		ac.translate(0, 0, 900);
		sofa();

		//insert table and tv
		ac.push_matrix();
		ac.translate((width/2)+80, 0, 100);
		tablee();
		Tv();
		ac.pop_matrix();

		//setup sofa hit box
		ac.push_matrix();
		ac.translate(40,40,-200);
		sofa_hitbox_1.hitbox();
		ac.translate(-340/2,0,350);
		glRotated(90, 0, 1, 0);
		sofa_hitbox_2.hitbox();
		ac.pop_matrix();

		Color::show(WHITE);
		ac.pop_matrix();

		audio();
		}
	

	void audio(){
			if(keys['T']){

				if(sound )
					Sound::make_sound("sounds/sheel.wav");
				else Sound::make_sound("sounds/commentary.wav");
				sound = !sound;
			}}

	void carrageeAndImageOnWall()
	{
		glTranslated(0,40,-500);
		glPushMatrix();
		Centered_Cube cubee(800,1000,2600);
		int a[] = {wall2, wall2, wall2, wall2, wall2, wall2};
		cubee.draw_texturedS(a);
		glPopMatrix();


		glPushMatrix();
		glTranslated(599/2,500,1000/2);
		Centered_Cube PhotoRight(200,200,-300);
		PhotoRight.get_right_face().draw_textured(football1);
		glPopMatrix();

		glPushMatrix();
		glTranslated(1/2,500,-1000/2);
		Centered_Cube PhotoLeft(250,250,-350);
		PhotoLeft.get_left_face().draw_textured(football2);
		glPopMatrix();
	}
	void sofa(){
		glCallList(sofa_list);
	}
	void tablee()
	{

		glCallList(tablee_list);
	}
	void Tv()
	{
		glCallList(tv_list);
	}
};