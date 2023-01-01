class AxisControl
{
public :	
	GLfloat x,z;
	std :: stack <std :: pair<GLfloat, GLfloat>> st; 

	void init()
	{
		while(!st.empty()) st.pop(); 
		x = z = 0; 
		st.push(std::make_pair(x, z)); 
	}
	void push_matrix()
	{
		st.push(st.top()); 
		glPushMatrix(); 
	}
	void pop_matrix()
	{
		st.pop(); 
		x = st.top().first;
		z = st.top().second;
		glPopMatrix(); 
	}
	void translate(GLfloat dx, GLfloat dy, GLfloat dz)
	{
		x += dx; 
		z += dz; 
		st.top().first += dx; 
		st.top().second += dz; 
		glTranslated(dx, dy, dz);
	}

};