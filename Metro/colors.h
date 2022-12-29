int WHITE[4] = {255,255,255,255};
int RED[4] = {255,0, 0, 255};
int GREEN[4] = {0,255, 0, 255};
int BLUE[4] = {0,0, 255, 255};
int LIGHT_BLUE[4] = {0,0, 255, 64};
int BLACK[4] = {0,0, 0, 255};
int seethrough[4] = {255,255,255,0};

class Color{
public:
	static void show(int *param){
		glColor4ub(param[0], param[1], param[2], param[3]);
	}
};