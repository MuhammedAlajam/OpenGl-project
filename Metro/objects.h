void chair(){
	ac.translate(0,40,0);
	ac.push_matrix();
	ac.translate(0,0,-5);
	Frustum(92.5*2,30,80, 4).draw_textured(cushion);
	ac.pop_matrix();
	Centered_Cube(105*2,-48,110).draw_textured(reflective_metal);
	ac.push_matrix();
	ac.translate(0, 0, -40);
	Centered_Cube(95*2, 120, -30).draw_textured(cushion);
	ac.translate(0, -14, -24);
	Color::show(WHITE);
	Centered_Cube(105*2, 150, -18).draw_textured(reflective_metal);
	ac.pop_matrix();
}
void draw_chairs(){
	ac.push_matrix();
	ac.translate(-250, 20, 0);

	ac.push_matrix();
	glScaled(1.4, 2.2, 1.4);
	chair();
	ac.pop_matrix();

	ac.translate(0, 0, 400);
	glRotated(180, 0, 1, 0);
	ac.push_matrix();
	glScaled(1.4, 2.2, 1.4);
	chair();
	ac.pop_matrix();
	ac.pop_matrix();
}
void draw_chairs_column(){
	ac.push_matrix();
	ac.translate(0, 0,400);
	draw_chairs();
	ac.translate(0, 0,-600);
	draw_chairs();
	ac.translate(0, 0,-600);
	draw_chairs();
	ac.pop_matrix();
}