static int back, front, left, right, top, space, brick, one, two, floors, wood2, wood, sky, front_train, back_train, train_ceiling, chess, marble, ceiling_train, window_top_train, window_bottom_train, cushion, light_wood, reflective_metal, grayish, lake_ground, lake_right, lake_sky,lake_left, lake_front;



Model_3DS *tree, *palm_tree, *tundra_tree, *grass;
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
		reflective_metal = LoadTexture("pleather.bmp", 255);
		grayish = LoadTexture("grayish.bmp", 255);


		lake_ground = LoadTexture("lake_ground.bmp");
		lake_right = LoadTexture("lake_right.bmp");
		lake_sky = LoadTexture("lake_sky.bmp");
		lake_left  = LoadTexture("lake_left.bmp");
		lake_front  = LoadTexture("lake_front.bmp");

	}


	static void MAKE_MODELS(){
		

		/*       LOAD PINE TREE         */
		GLTexture leaf, woods;
		leaf.LoadBMP("leaf.bmp");
		woods.LoadBMP("wood.bmp");
		tree = new Model_3DS();
		tree->Load("tree.3ds");
		tree->Materials[0].tex = leaf;
		tree->Materials[1].tex = woods;
		tree->scale=0.4;

		/*      LOAD PALM TREE          */
		GLTexture palm_leaf, palm_wood;
		palm_leaf.LoadBMP("palm_leaf.bmp");
		palm_wood.LoadBMP("palm_wood.bmp");
		palm_tree = new Model_3DS();
		palm_tree->Load("palm.3ds");
		palm_tree->Materials[0].tex = palm_wood;
		palm_tree->Materials[1].tex = palm_leaf;
		palm_tree->scale=1.4;

		/*      LOAD TUNDRA TREE       */
		GLTexture tundra_leaf;
		tundra_leaf.LoadBMP("tundra_leaf.bmp");
		//wood.LoadBMP("wood.bmp");
		tundra_tree = new Model_3DS();
		tundra_tree->Load("tree.3ds");
		tundra_tree->Materials[1].tex = tundra_leaf;
		tundra_tree->Materials[0].tex = woods;
		tundra_tree->scale=0.4;

		/*     LOAD GRASS      */
		GLTexture grass_text;
		grass_text.LoadBMP("grass.bmp");
		grass = new Model_3DS();
		grass->Load("grass.3ds");
		grass->Materials[0].tex = grass_text;
		grass->scale=0.1;
	}
};