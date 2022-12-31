static int back, front, left, right, top, space, brick, one, two, floors, wood2, wood, sky, front_train, back_train, train_ceiling, chess, marble, ceiling_train, window_top_train, window_bottom_train, cushion, light_wood, reflective_metal, grayish, lake_ground, lake_right, lake_sky,lake_left, lake_front, dinner_table, roof;



Model_3DS *tree, *palm_tree, *tundra_tree, *grass, *dinner_chair, *flower_vase, *chess_table;
GLuint dinner_chair_list, flower_vase_list, chess_table_list;
class Texture{
public:


	static void LOAD_TEXTURES(){
		sky = LoadTexture("mountain.bmp");
		wood = LoadTexture("wood.bmp");
		/*back = LoadTexture("back.bmp");
		top = LoadTexture("top.bmp",255);*/
		space = LoadTexture("space.bmp",255);
		/*front = LoadTexture("front.bmp",255);
		brick = LoadTexture("brick.bmp",255);
		left = LoadTexture("left.bmp",255);
		right = LoadTexture("right.bmp",255);
		one = LoadTexture("one.bmp",255);
		two = LoadTexture("two.bmp",255);*/
		floors = LoadTexture("floors.bmp",255);
		front_train = LoadTexture("front_train.bmp",255);
		back_train = LoadTexture("back_train.bmp",255);
		train_ceiling = LoadTexture("train_ceiling.bmp",255);
		wood2 = LoadTexture("wood2.bmp",255);
		chess = LoadTexture("chess.bmp",255);
		//marble = LoadTexture("marble.bmp",255);
		ceiling_train = LoadTexture("train_ceiling.bmp",255);
		window_top_train = LoadTexture("window_top_train.bmp",255);
		window_bottom_train = LoadTexture
			("window_bottom_train.bmp",255);
		cushion = LoadTexture("cushion.bmp", 255);
		light_wood = LoadTexture("brick.bmp",255);
		reflective_metal = LoadTexture("pleather.bmp", 255);
		grayish = LoadTexture("grayish.bmp", 255);
		roof = LoadTexture("roof.bmp",255);


		lake_ground = LoadTexture("lake_ground.bmp");
		lake_right = LoadTexture("lake_right.bmp");
		lake_sky = LoadTexture("lake_sky.bmp");
		lake_left  = LoadTexture("lake_left.bmp");
		lake_front  = LoadTexture("lake_front.bmp");
		dinner_table = LoadTexture("dinner_table.bmp");
	}


	static void MAKE_MODELS(){
		

		/*	LOAD PINE TREE	*/
		GLTexture leaf, woods;
		leaf.LoadBMP("leaf.bmp");
		woods.LoadBMP("wood.bmp");
		tree = new Model_3DS();
		tree->Load("tree.3ds");
		tree->Materials[0].tex = leaf;
		tree->Materials[1].tex = woods;
		tree->scale=0.4;

		/*	LOAD PALM TREE	*/
		GLTexture palm_leaf, palm_wood;
		palm_leaf.LoadBMP("palm_leaf.bmp");
		palm_wood.LoadBMP("palm_wood.bmp");
		palm_tree = new Model_3DS();
		palm_tree->Load("palm.3ds");
		palm_tree->Materials[0].tex = palm_wood;
		palm_tree->Materials[1].tex = palm_leaf;
		palm_tree->scale=1.4;

		/*	LOAD TUNDRA TREE	*/
		GLTexture tundra_leaf;
		tundra_leaf.LoadBMP("tundra_leaf.bmp");
		//wood.LoadBMP("wood.bmp");
		tundra_tree = new Model_3DS();
		tundra_tree->Load("tree.3ds");
		tundra_tree->Materials[1].tex = tundra_leaf;
		tundra_tree->Materials[0].tex = woods;
		tundra_tree->scale=0.4;

		/*	LOAD GRASS	*/
		GLTexture grass_text;
		grass_text.LoadBMP("grass.bmp");
		grass = new Model_3DS();
		grass->Load("grass.3ds");
		grass->Materials[0].tex = grass_text;
		grass->scale=0.1;

		/*	LOAD DINNER CHAIR	*/
		GLTexture dinner_chair_wood,dinner_chair_fabric;
		dinner_chair_wood.LoadBMP("dinner_chair_wood.bmp");
		dinner_chair_fabric.LoadBMP("pleather.bmp");
		dinner_chair = new Model_3DS();
		dinner_chair->Load("dinner_chair.3ds");
		dinner_chair->Materials[0].tex = dinner_chair_wood;
		dinner_chair->Materials[1].tex = dinner_chair_fabric;
		dinner_chair->Materials[2].tex = dinner_chair_fabric;
		dinner_chair->Materials[3].tex = dinner_chair_fabric;
		dinner_chair->scale = 0.015;


		/*	LOAD FLOWER VASE	*/
		GLTexture red_rose, leaf_gre, orange, stem, blue;
		orange.LoadBMP("flower_vase/orange.bmp");
		red_rose.LoadBMP("flower_vase/red.bmp");
		leaf_gre.LoadBMP("flower_vase/leaf_gre.bmp");
		stem.LoadBMP("flower_vase/leaf_gre.bmp");
		blue.LoadBMP("flower_vase/blue.bmp");
		flower_vase = new Model_3DS();
		flower_vase->Load("flower_vase/flower_vase.3DS");
		flower_vase->Materials[0].tex = red_rose;
		flower_vase->Materials[1].tex = leaf_gre;
		flower_vase->Materials[2].tex = stem;
		flower_vase->Materials[3].tex = stem;
		flower_vase->Materials[4].tex = stem;
		flower_vase->Materials[5].tex = blue;
		flower_vase->scale = 0.1;

		/*	LOAD CHESS TABLE	*/
		GLTexture metal_s6, metalbla, marble;
		metal_s6.LoadBMP("metal-s6.bmp");
		metalbla.LoadBMP("metalbla.bmp");
		marble.LoadBMP("marble.bmp");
		chess_table = new Model_3DS();
		chess_table->Load("chess_table.3ds");
		chess_table->Materials[0].tex = marble;
		chess_table->Materials[1].tex = metalbla;
		chess_table->scale=0.8;
		
	}

	static void MAKE_LISTS(){

		/*	DINNER CHAIR LIST*/
		dinner_chair_list = glGenLists(1);
		glNewList(dinner_chair_list, GL_COMPILE);
		glPushMatrix();
		glScaled(2, 1.6, 1);
		dinner_chair->Draw();
		glPopMatrix();
		glEndList();


		/*	FLOWER VASE LIST	*/
		flower_vase_list = glGenLists(1);
		glNewList(flower_vase_list, GL_COMPILE);
		flower_vase->scale= 2;
		flower_vase->Draw();
		glEndList();

		/*	CHESS TABLE LIST*/
		chess_table_list = glGenLists(1);
		glNewList(chess_table_list, GL_COMPILE);
		glTranslated(0, 110, 0);
		chess_table->Draw();
		glEndList();

		/*	CHESS CHAIR LIST	*/
	}
};