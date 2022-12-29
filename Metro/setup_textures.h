static int back, front, left, right, top, space, brick, one, two, floors, wood2, wood, sky, front_train, back_train, train_ceiling, chess, marble, ceiling_train, window_top_train, window_bottom_train, cushion, light_wood;
class Texture{
public:


	static void LOAD_TEXTURES(){
		sky = LoadTexture("mountain.bmp");
		wood = LoadTexture("wood.bmp");
		back = LoadTexture("back.bmp");
		top = LoadTexture("top.bmp",255);
		space = LoadTexture("space.bmp",255);
		front = LoadTexture("front.bmp",255);
		brick = LoadTexture("brick.bmp",255);
		left = LoadTexture("left.bmp",255);
		right = LoadTexture("right.bmp",255);
		one = LoadTexture("one.bmp",255);
		two = LoadTexture("two.bmp",255);
		floors = LoadTexture("floor.bmp",255);
		front_train = LoadTexture("front_train.bmp",255);
		back_train = LoadTexture("back_train.bmp",255);
		train_ceiling = LoadTexture("train_ceiling.bmp",255);
		wood2 = LoadTexture("wood2.bmp",255);
		chess = LoadTexture("chess.bmp",255);
		marble = LoadTexture("marble.bmp",255);
		ceiling_train = LoadTexture("train_ceiling.bmp",255);
		window_top_train = LoadTexture("window_top_train.bmp",255);
		window_bottom_train = LoadTexture
			("window_bottom_train.bmp",255);
		cushion = LoadTexture("cushion.bmp", 255);
		light_wood = LoadTexture("brick.bmp",255);
	}

};