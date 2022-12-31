void chair(){
	glTranslated(0,40,0);
	glPushMatrix();
	glTranslated(0,0,-5);
	Frustum(92.5*2,30,80, 4).draw_textured(cushion);
	glPopMatrix();
	Centered_Cube(105*2,-48,110).draw_textured(reflective_metal);
	glPushMatrix();
	glTranslated(0, 0, -40);
	Centered_Cube(95*2, 120, -30).draw_textured(cushion);
	glTranslated(0, -14, -24);
	Color::show(WHITE);
	Centered_Cube(105*2, 150, -18).draw_textured(reflective_metal);
	glPopMatrix();
}
void draw_chairs(){
	glPushMatrix();
	glTranslated(-250, 20, 0);

	glPushMatrix();
	glScaled(1.4, 2.2, 1.4);
	chair();
	glPopMatrix();

	glTranslated(0, 0, 400);
	glRotated(180, 0, 1, 0);
	glPushMatrix();
	glScaled(1.4, 2.2, 1.4);
	chair();
	glPopMatrix();
	glPopMatrix();
}
void draw_chairs_column(){
	glPushMatrix();
	glTranslated(0, 0,400);
	draw_chairs();
	glTranslated(0, 0,-600);
	draw_chairs();
	glTranslated(0, 0,-600);
	draw_chairs();
	glPopMatrix();
}