
Centered_Cube SKYBOX(4000,4000,4000);
void skybox()
{
	glBindTexture(GL_TEXTURE_2D, sky);
	glColor3f(1.0,1.0,1.0);
	glBegin(GL_QUADS); //front
	glTexCoord2d(0.90, 0.35);

	
	glVertex3d(0,0,0);
	
	
	glTexCoord2d(0.75, 0.35);  
	
	
	glVertex3d(4000,0,0);
	
	
	glTexCoord2d(0.75, 0.65);
	
	
	glVertex3d(4000,4000,0);
	
	
	glTexCoord2d(0.90, 0.65);
	
	
	glVertex3d(0,4000,0);
	
glEnd();


	glColor3f(1.0,1.0,1.0);
	glBegin(GL_QUADS); //back
	glTexCoord2d(0.30, 0.30);
	glVertex3d(0,0,-4000);
	glTexCoord2d(0.50, 0.30);
	glVertex3d(4000,0,-4000);
	glTexCoord2d(0.50, 0.80);
	glVertex3d(4000,4000,-4000);
	glTexCoord2d(0.30, 0.80);
	glVertex3d(0,4000,-4000);
	glEnd();


	glColor3f(1.0,1.0,1.0);
	glBegin(GL_QUADS); //left
	glTexCoord2d(0.5, 0.30);
	glVertex3d(0,0,0);
	glTexCoord2d(0.30, 0.30);
	glVertex3d(0,0,-4000);
	glTexCoord2d(0.30, 0.80);
	glVertex3d(0,4000,-4000);
	glTexCoord2d(0.5, 0.80);
	glVertex3d(0,4000,0);
	glEnd();



	glColor3f(1.0,1.0,1.0);
	glBegin(GL_QUADS); //right          
	glTexCoord2d(0.75, 0.40);
	glVertex3d(4000,0,0);
	glTexCoord2d(0.50, 0.40);            
	glVertex3d(4000,0,-4000);
	glTexCoord2d(0.50, 0.64);        
	glVertex3d(4000,4000,-4000);
	glTexCoord2d(0.75, 0.64);            
	glVertex3d(4000,4000,0);
	glEnd();




	glColor3f(1.0,1.0,1.0);
	glBegin(GL_QUADS); //up
	glTexCoord2d(0.30, 0.90);
	glVertex3d(0,4000,0);
	glTexCoord2d(0.50, 0.90);
	glVertex3d(4000,4000,0);
	glTexCoord2d(0.50, 0.80);
	glVertex3d(4000,4000,-4000);
	glTexCoord2d(0.30, 0.80);
	glVertex3d(0,4000,-4000);
	glEnd();



	glColor3f(1.0,1.0,1.0);//white
	glBegin(GL_QUADS); //under
	glTexCoord2d(0.30, 0.5);
	glVertex3d(0,0,0);
	glTexCoord2d(0.55, 0.5);
	glVertex3d(4000,0,0);
	glTexCoord2d(0.45, 0.25);
	glVertex3d(4000,0,-4000);
	glTexCoord2d(0.30, 0.25);
	glVertex3d(0,0,-4000);
	glEnd();
}