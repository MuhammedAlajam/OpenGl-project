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
		depth = 2000;
		width = 800;
		main_body = Centered_Cube(width, height, depth);
	}

	void draw(){
		private_draw();
	}
	void private_draw(){
		Color::show(WHITE);
		main_body.get_bottom_face().draw_textured(floors);
		main_body.get_deep_face().draw_textured(front_train);
		main_body.get_front_face().draw_textured(front_train);
		glColor3ub(175, 175,175);
		main_body.get_top_face().draw_textured(wood);
		Color::show(WHITE);
		draw_sides();
	}
	void draw_sides(){
		glPushMatrix();
		Centered_Cube stamp(width, 3*height/12, depth);
		stamp.get_left_face().draw_textured(window_bottom_train);
		stamp.get_right_face().draw_textured(window_bottom_train);
		glTranslated(0, height/4, 0);
		stamp = Centered_Cube(width, 5*height/12, depth);
		glColor4ub(0, 0, 60, 102);
		stamp.get_left_face().draw();
		stamp.get_right_face().draw();
		glTranslated(0, 5*height/12, 0);
		Color::show(WHITE);
		stamp = Centered_Cube(width, 4*height/12, depth);
		stamp.get_left_face().draw_textured(window_top_train);
		stamp.get_right_face().draw_textured(window_top_train);
		glColor4ub(0,0,0, 175);
		Color::show(WHITE);
		glPopMatrix();
	}
};

class Passenger_Carriage : public Basic_Carriage{
public: 
	void draw(){
		glPushMatrix();
		private_draw();
		draw_chairs_column();
		glTranslated(500, 0, 0);
		draw_chairs_column();
		glTranslated(-500, 998, 0);
		glColor4ub(0,0,60, 100);
		Centered_Cube(10*width/12, 1, depth - (depth/4)).draw();
		glTranslated(0, 1, 0);
		glColor4ub(49, 48, 51, 255);
		Centered_Cube(width, 1, depth).get_top_face().draw();
		Color::show(WHITE);
		glPopMatrix();
	}
	void private_draw(){
		Color::show(WHITE);
		main_body.get_bottom_face().draw_textured(floors);
		main_body.get_deep_face().draw_textured(front_train);
		main_body.get_front_face().draw_textured(front_train);
		glColor3ub(175, 175,175);
		//main_body.get_top_face().draw_textured(wood);
		Color::show(WHITE);
		draw_sides();
	}

};