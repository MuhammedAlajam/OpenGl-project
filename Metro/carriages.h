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
		glColor4ub(0,0,0, 175);
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
	 void table(){
		
	}
};

class Chess_Carriage : public Basic_Carriage{
public:
	void draw(){

		private_draw();
		ac.push_matrix();
		ac.translate(-180,23,600);
		glCallList(chess_table_list);
		glColor4ub(255, 0, 0, 150);
		Centered_Cube(400,400,400).hitbox();
		Color::show(WHITE);
		ac.push_matrix();
		ac.translate(0, 120, 0);
		glScaled(0.05, 0.05, 0.05);
		draw_chessboard();
		
		ac.pop_matrix();
		
		ac.pop_matrix();

	}
	void draw_chessboard(){
		glCallList(chess_board_list);
	}
	
};