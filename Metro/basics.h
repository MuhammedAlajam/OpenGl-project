
class entity{
public:
};

class Point : public entity{
public:
	GLfloat x,y,z; // Coordinates of the point


	Point(GLfloat x_ = 0.0, GLfloat y_ = 0.0, GLfloat z_ = 0.0) : x(x_), y(y_), z(z_) {}

	// Getters for the coordinates of the point
	GLfloat getX() const { return x; }
	GLfloat getY() const { return y; }
	GLfloat getZ() const { return z; }

	// Setters for the coordinates of the point
	void setX(GLfloat x_) { x = x_; }
	void setY(GLfloat y_) { y = y_; }
	void setZ(GLfloat z_) { z = z_; }

	// Method to draw the point using legacy OpenGL
	void show() const {
		
		glVertex3f(x, y, z);
	}

	void draw() const {
		glVertex3f(x, y, z);
	}
};


bool betweenTwoPoints(GLfloat x1, GLfloat x2, GLfloat x, GLfloat add)
{
	GLfloat dif = 5; 
	if(max(abs(x1 - (x - add)), abs(x2 - (x - add))) < dif) canMove = false; 
	return ((x - add) <= max(x1, x2) && (x - add) >= min(x1, x2));
}

bool find_point(Point p1, Point p2, Point p3, Point p4, Point p)
{
	return (betweenTwoPoints(p1.x, p3.x, p.x, ac.x) && betweenTwoPoints(p2.z, p4.z, p.z, ac.z));
}


	
class Rect : public entity{
public:
	// Method to draw the rectangle using legacy OpenGL
	Point p1, p2, p3, p4;
	Point p[4];
	int texture;
	Rect(Point p1_= Point(0,0,0),Point  p2_= Point(1, 0, 0), Point p3_= Point(1,1,0),Point p4_= Point(0, 1, 0)):
		p1(p1_), p2(p2_), p3(p3_), p4(p4_){}
	                                                  
	void draw()  {
		glBegin(GL_QUADS);
		p1.show();
		p2.show();
		p3.show();
		p4.show();
		glEnd();}
	void draw_textured(int texture) {

		glBindTexture(GL_TEXTURE_2D, texture);
		glBegin(GL_QUADS);
		glTexCoord2d(0.0, 0.0);
		p1.draw();
		glTexCoord2d(1.0, 0.0);
		p2.draw();
		glTexCoord2d(1.0, 1.0);
		p3.draw();
		glTexCoord2d(0.0, 1.0);
		p4.draw();
		glEnd();
	}

	void checkMove()
	{
		Point camera_point = Point(camera.m_position.x, camera.m_position.y, camera.m_position.z); 
		Point virt_camera_point = Point(virt_cam.m_position.x, virt_cam.m_position.y, virt_cam.m_position.z); 


		if(find_point(p1, p2, p3, p4, camera_point) != find_point(p1, p2, p3, p4, virt_camera_point))
			canMove = false; 
	}

	
};


class Cube : public entity{
public:
	Point p[8];

	//Cube(){
	//	p[0] = Point(0, 0, 0); //front bottom left 
	//	p[1] = Point(1, 0, 0); //front bottom right
	//	p[2] = Point(1,1,0); //front bottom left
	//	p[3] = Point(0,1,0);

	//	p[4] = Point(0, 0, 0); 
	//	p[5] = Point(1, 0, 0);
	//	p[6] = Point(1,1,0);
	//	p[7] = Point(0,1,0);
	//}
	GLfloat w, h, d, texture;
	Cube(int width = 100, int height = 100, int depth = 100){
		p[0] = Point(0,0,0);  
		p[1] = Point(width, 0, 0);
		p[2] = Point(width, height, 0);
		p[3] = Point(0, height, 0);

		p[4] = Point(0, 0, depth);
		p[5] = Point(width, 0, depth);
		p[6] = Point(width, height, depth);
		p[7] = Point(0, height, depth);

		w = width, h = height, d = depth;
	}


	Rect get_front_face() const{return Rect(p[0],p[1],p[2],p[3]);} // 0

 
	Rect get_bottom_face() const{return Rect(p[0],p[1],p[5],p[4]);} //1

	Rect get_deep_face() const{return Rect(p[4],p[5],p[6],p[7]);} //2
	
	Rect get_top_face() const{return Rect(p[3], p[2], p[6],p[7]);} //3

	Rect get_right_face() const{return Rect(p[1], p[5], p[6], p[2]);} //4

	Rect get_left_face() const{return Rect(p[4], p[0], p[3], p[7]);} //5



	std::vector <Rect> get_all(){
		std::vector<Rect> v;
		v.push_back(get_front_face()); // front face 0
		v.push_back(get_bottom_face()); // bottom face 1
		v.push_back(get_deep_face()); // deep face 2
		v.push_back(get_top_face()); // top face 3
		v.push_back(get_right_face()); // right face 4
		v.push_back(get_left_face()); // left face 5
		return v;
	}

	void draw() const{

		Rect front_face = get_front_face(); // 0 
		Rect bottom_face = get_bottom_face(); // 1

		Rect deep_face = get_deep_face(); // 2

		Rect top_face = get_top_face(); // 3

		Rect right_face = get_right_face(); //4 

		Rect left_face = get_left_face(); //5


		//glColor3f(1.0, 0.0, 0.0);

		front_face.draw();

		//glColor3f(0.0, 0.0, 0.0);
		bottom_face.draw();

		//glColor3f(0.0, 0.0, 0.0);
		deep_face.draw();

		//glColor3ub(230, 230, 250);
		//glColor3ub(159, 43, 104);

		top_face.draw();

		//glColor3f(0.0, 1.0, 0.0);
		//glColor3ub(255,228,196);
		right_face.draw();

		//glColor3f(0.0, 0.0, 1.0);
		left_face.draw();


	}
	/*	HERE	*/
	void draw_textured(int texture){
		std::vector<Rect> rects = get_all();
		for(int i =0; i < rects.size(); i++)
		{
			
			rects[i].draw_textured(texture);
		}

	}
	
	void draw_texturedS(int textures[6])
	{
		std::vector<Rect> v = get_all();
		for(int i = 0; i < v.size(); i++){
			if(textures[i]!=NULL)
			v[i].draw_textured(textures[i]);
			else v[i].draw();
		}
	}
};

class Centered_Cube{
public:
	Point p[8];
	GLfloat width, height, depth;
	Centered_Cube(GLfloat w, GLfloat h, GLfloat d){
		width = w;
		height = h;
		depth = d;
		init();
	}
	Centered_Cube(){}

	void init(){
		p[0] = Point(-width/2,0,-depth/2);  
		p[1] = Point(width/2, 0, -depth/2);
		p[2] = Point(width/2, height, -depth/2);
		p[3] = Point(-width/2, height, -depth/2);

		p[4] = Point(-width/2, 0, depth/2);
		p[5] = Point(width/2, 0, depth/2);
		p[6] = Point(width/2, height, depth/2);
		p[7] = Point(-width/2, height, depth/2);
	}

	Rect get_front_face() const{return Rect(p[0],p[1],p[2],p[3]);} // 0

	Rect get_bottom_face() const{return Rect(p[0],p[1],p[5],p[4]);} //1

	Rect get_deep_face() const{return Rect(p[4],p[5],p[6],p[7]);} //2
	
	Rect get_top_face() const{return Rect(p[3], p[2], p[6],p[7]);} //3

	Rect get_right_face() const{return Rect(p[1], p[5], p[6], p[2]);} //4

	Rect get_left_face() const{return Rect(p[4], p[0], p[3], p[7]);} //5



	std::vector <Rect> get_all(){
		std::vector<Rect> v;
		v.push_back(get_front_face()); // front face 0
		v.push_back(get_bottom_face()); // bottom face 1
		v.push_back(get_deep_face()); // deep face 2
		v.push_back(get_top_face()); // top face 3
		v.push_back(get_right_face()); // right face 4
		v.push_back(get_left_face()); // left face 5
		return v;
	}


	void draw(){
		
		Rect front_face = get_front_face(); // 0 

		Rect bottom_face = get_bottom_face(); // 1

		Rect deep_face = get_deep_face(); // 2

		Rect top_face = get_top_face(); // 3

		Rect right_face = get_right_face(); //4 

		Rect left_face = get_left_face(); //5



		front_face.draw();

		bottom_face.checkMove();
		bottom_face.draw();

		deep_face.draw();

		top_face.draw();

		right_face.draw();

		left_face.draw();

		
	}
	void draw_textured(int texture){
		
		Rect front_face = get_front_face(); // 0 

		Rect bottom_face = get_bottom_face(); // 1

		Rect deep_face = get_deep_face(); // 2

		Rect top_face = get_top_face(); // 3

		Rect right_face = get_right_face(); //4 

		Rect left_face = get_left_face(); //5


		//glColor3f(1.0, 0.0, 0.0);

		front_face.draw_textured(texture);

		bottom_face.checkMove(); 
		bottom_face.draw_textured(texture);


		//glColor3f(0.0, 0.0, 0.0);
		deep_face.draw_textured(texture);

		//glColor3ub(230, 230, 250);
		//glColor3ub(159, 43, 104);

		top_face.draw_textured(texture);

		//glColor3f(0.0, 1.0, 0.0);
		//glColor3ub(255,228,196);
		right_face.draw_textured(texture);

		//glColor3f(0.0, 0.0, 1.0);
		left_face.draw_textured(texture);

		
	}

	void hitbox(){
		get_bottom_face().checkMove();
	}

	void draw_untethered(){
		Rect front_face = get_front_face(); // 0 

		Rect bottom_face = get_bottom_face(); // 1

		Rect deep_face = get_deep_face(); // 2

		Rect top_face = get_top_face(); // 3

		Rect right_face = get_right_face(); //4 

		Rect left_face = get_left_face(); //5



		front_face.draw();

		bottom_face.draw();

		deep_face.draw();

		top_face.draw();

		right_face.draw();

		left_face.draw();
	}

	void draw_texturedS(int textures[6])
	{
		std::vector<Rect> v = get_all();
		for(int i = 0; i < v.size(); i++){
			if(textures[i]!=NULL)
			v[i].draw_textured(textures[i]);
			if(i == 1)
				v[i].checkMove();
			//else v[i].draw();
		}
	}
	void draw_texturedS_raw(int textures[6])
	{
		std::vector<Rect> v = get_all();
		for(int i = 0; i < v.size(); i++){
			if(textures[i]!=NULL)
			v[i].draw_textured(textures[i]);
			
			//else v[i].draw();
		}
	}
};


class Frustum : public Centered_Cube{
public:
	GLfloat diff;

	Frustum(GLfloat w, GLfloat h, GLfloat d, GLfloat delta) {
		width = w;
		height = h;
		depth = d;
		diff = delta;
		init();
	}
	Frustum(){}

	void init(){
		p[0] = Point(-width/2,0,-depth/2);  
		p[1] = Point(width/2, 0, -depth/2);
		p[2] = Point((width/2)-diff, height, (-depth/2)+diff);
		p[3] = Point((-width/2)+diff, height, (-depth/2)+diff);

		p[4] = Point(-width/2, 0, depth/2);
		p[5] = Point(width/2, 0, depth/2);
		p[6] = Point((width/2)-diff, height, (depth/2)-diff);
		p[7] = Point((-width/2)+diff, height, (depth/2)-diff);
	}

};
