class Carriage{
public:
	GLfloat width, height, depth;
	Centered_Cube main_body;
	void draw();
};

class Driver_Carriage : public Carriage{
public:
	GLfloat delta_d, delta_h;
	Driver_Carriage(){
		height = 500;
		depth = 1000;
		width = 400;
		main_body = Centered_Cube(width, height, depth);
	}

	void draw(){
		Color::show(WHITE);
		main_body.get_bottom_face().draw_textured(floors);
		main_body.get_deep_face().draw_textured(front_train);
		main_body.get_front_face().draw_textured(front_train);
		glColor3ub(175, 175,175);
		main_body.get_top_face().draw();
		Color::show(WHITE);
		draw_left();
	}

private:
	void draw_left(){
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