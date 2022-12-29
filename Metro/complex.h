
class Cut_Pyramid{
public:
	Cube a, b;
	int top_width,  top_depth,  bottom_width,
		 bottom_depth,  height;
	Cut_Pyramid( int top_width, int top_depth, int bottom_width,
		int bottom_depth, int height){
		a = Cube(top_width, height, top_depth); // top
		b = Cube(bottom_depth, height, bottom_depth); // bottom
	}

	void draw(){
		Rect a_rect = a.get_top_face();
		glPushMatrix();
		
		Rect b_rect = b.get_bottom_face();
		b_rect.draw();
		glPopMatrix();
		//glColor3f(1.0, 1.0, 1.0);
		a_rect.draw(); 

		//front
		     // w,h,0   0,h,0        0,0,0     
		//Rect(a_rect.p2, a_rect.p1, b_rect.p1, b_rect.p2).draw();

	}
};