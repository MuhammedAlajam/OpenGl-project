class Sound{
public:
	static void make_sound(){
		PlaySound(TEXT("jomanokat.m4a"), NULL, SND_SYNC);
	}
};