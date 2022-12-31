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
		main_body.get_top_face().draw_textured(roof);
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

class Kitchen_Carriage : public Basic_Carriage{
public:
	
	void draw(){
		private_draw();

		glPushMatrix();
		glTranslated(-200, 0,0);
		glPushMatrix();
		glTranslated(0,0, 500);
		draw_table_with_chairs();
		glTranslated(0,0, -600);
		draw_table_with_chairs();
		glTranslated(0,0, -500);
		draw_table_with_chairs();
		glPopMatrix();
		glPopMatrix();
	}
	void draw_table_with_chairs(){
		glPushMatrix();
		draw_dinner_chairs();
		glTranslated(-91, 0, 0);
		glRotated(180, 0, 1, 0);
		draw_dinner_chairs();
		glPopMatrix();
		glPushMatrix();
		glScaled(1, 1.8,1);
		table();
		glPopMatrix();
		glPushMatrix();
		glTranslated(-50,1.15*150,0);
		flower_vase->scale= 2;
		flower_vase->Draw();
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
};