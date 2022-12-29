#include <set>
#include <stdio.h>
const int width = 4000, depth = 4000, height = 1000;
int BOARD_COLOR[4] = {66, 40, 14, 255};
const int DELTA = 1000;
int winner = 0;

class Pawn{
public:
	int color; // 1 for white, 2 for black 

	Pawn(int col = 1):color(col){}
	// TODO : color the pawn + draw the pawn 


	void draw(){
		if(color == 1) Color::show(GREEN);
		else Color::show(BLACK);
		glPushMatrix();

		Centered_Cube(100, 50, 100).draw(); 

		glPopMatrix();
	}
}; 

class Square{
public:
	int w, h, d, selected, pawnColor;
	Centered_Cube patch;


	Square(int st=1,int w_ = 350, int h_=-5, int d_=350, int hasPawn=0, int p_ = 0, int s_ = 0):w(w_), h(h_), d(d_), pawnColor(p_), selected(s_)   {
		patch = Centered_Cube(w, h, d);
	}


	void set_selected(int st){selected = st;}

	void draw(){
		Color::show(WHITE);
		if(selected) Color::show(BLUE), patch.draw();

		Color::show(WHITE);
		if(pawnColor) Pawn(pawnColor).draw(); 


	}
};

class Chess_Board{
public:
	Square squares[8][8];
	int role, selectedInd; 


	std::set<std::pair<int, int>> coords[2]; 
	std::pair<int, int> selected; 

	int player(){
		return role%2;
	}

	std::set<int> random_position(){
		std::set<int> st; 
		while(st.size() < 3)
			st.insert(rand()%8);
		return st;
	}

	Chess_Board()
	{
		role = selectedInd = winner = 0;  // white starts the game 

		// white pawns
		for(int i : random_position())
			squares[0][i].pawnColor = 1,
			coords[0].insert(std::make_pair(0,i));

		// black pawns
		for(int i : random_position())
			squares[7][i].pawnColor = 2,
			coords[1].insert(std::make_pair(7,i));

		selected = *coords[0].begin();
		squares[0][*(random_position().begin())].selected = 1; 
	}

	void draw(){
		//TABLE
		Color::show(WHITE);
		Centered_Cube(20000,-50, 20000).draw_textured(marble);			
		glTranslated(0.0, 50, 0.0);

		//CHESS BOARD BASE
		Color::show(WHITE);
		Centered_Cube(4000, 200, 4000).draw_textured(wood2);
		glTranslated(0.0, 150, 0.0);

		//CHESS BOARD FRUSTUM
		Color::show(WHITE);
		Frustum(4000, 450, 4000, 500).draw_textured(wood2);
		glTranslated(0.0, 450, 0.0);
		Color::show(WHITE);
		int a[6] = {NULL, NULL, NULL, chess, NULL, NULL};
		Centered_Cube(2800, 80, 2800).draw_texturedS(a);

		//CHESS BOARD EDGE
		glPushMatrix();
		glTranslated(-1500, 0, -1400);
		Cube(100, 80, 2800).draw_textured(wood);
		glRotated(90, 0, 1, 0);
		Cube(100, 80, 3000).draw_textured(wood);
		glPopMatrix();

		glPushMatrix();
		glTranslated(1400, 0, -1400);
		Cube(100, 80, 2800).draw_textured(wood);
		glTranslated(100, 0, 2800);
		glRotated(-90, 0, 1, 0);
		Cube(100, 80, 3000).draw_textured(wood);
		glPopMatrix();
		glTranslated(0, -650, 0);
		draw_walls();
		glTranslated(-1400+(175), 740, -1400+(175));
		Color::show(WHITE);
		draw_patch();
	}

	void draw_walls(){
		Color::show(WHITE);
		int walls[] = {space, NULL, space, space, space, space};
		Centered_Cube(9000, 9000, 9000).draw_texturedS(walls);

	}

	void draw_patch(){
		glPushMatrix();
		for(int i = 0; i < 8; i++)
		{
			glPushMatrix(); 
			for(int j=0 ; j<8 ; j++){	
				if(j == 0 && i ==0)
					Color::show(WHITE);
				squares[i][j].draw(),
					glTranslated(350, 0, 0);}
			glPopMatrix(); 

			glTranslated(0, 0, 350);
		}

		glPopMatrix();
	}

	void game()
	{
		if(frames % 200 != 0 || winner) return;
		frames = 0;

		if(keys['J'] || keys['L']) // the player is choosing a pawn, J for left, L for right selection
		{
			squares[selected.first][selected.second].set_selected(0); 
			int sz = coords[player()].size(); 

			if(keys['J']) 
			{
				selectedInd -- ; 
				if(selectedInd == -1) selectedInd = sz - 1; 
			}
			if(keys['L']) 
			{
				selectedInd ++; 
				if(selectedInd == sz) selectedInd = 0; 
			}

			int counter = 0 ; 
			for(auto it : coords[player()])
			{
				if(counter == selectedInd)
				{
					selected = it; 
					break;
				}
				counter ++; 
			}
			squares[selected.first][selected.second].set_selected(1); 
		}
		else if(keys['U'] || keys['O'])
		{
			std::pair<int, int> goTo = selected; 
			if(player() == 0) goTo.first ++; 
			else goTo.first --; 

			if(keys['O'] ^ (role & 1)) goTo.second --; 
			else goTo.second ++; 



			if(coords[!player()].find(goTo) != coords[!player()].end())
			{
				coords[!player()].erase(coords[!player()].find(goTo));
				coords[player()].erase(coords[player()].find(selected));
				coords[player()].insert(goTo); 

				squares[selected.first][selected.second].pawnColor = 0; 
				squares[selected.first][selected.second].set_selected(0); 
				std::pair<int, int> p = *coords[!player()].begin(); 

				squares[p.first][p.second].set_selected(1); 



				if(squares[goTo.first][goTo.second].pawnColor == 1)  squares[goTo.first][goTo.second].pawnColor = 2; 
				else squares[goTo.first][goTo.second].pawnColor = 1; 


				if(goTo.first == 7) winner = 1; 
				if(goTo.first == 0) winner = 2; 

				selected = p; 
				role ++; 
				return; 
			}
		}else if(keys['I'])
		{
			OutputDebugString("poo poo\n");

			std::pair<int, int> goTo = selected; 
			(player() == 0) ? goTo.first ++ : goTo.first --; 


			if((coords[player()].find(goTo) == coords[player()].end())
				&& (coords[!player()].find(goTo) == coords[!player()].end()))
			{
				coords[player()].erase(coords[player()].find(selected)); 
				coords[player()].insert(goTo); 

				squares[selected.first][selected.second].pawnColor = 0;
				squares[selected.first][selected.second].selected = 0; 
				squares[goTo.first][goTo.second].pawnColor = player() + 1; 



				if(goTo.first == 7) winner = 1; 
				if(goTo.first == 0) winner = 2; 

				selected = *coords[!player()].begin();
				squares[selected.first][selected.second].selected = 1;
				role ++; 
				return; 
			}
		}

	}

};
