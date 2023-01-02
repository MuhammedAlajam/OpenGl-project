char* bell_sound = "bell.wav";
char* tv_sound="tv_sound.wav";

class Sound{
public:
	
	/*static void make_sound(){
		PlaySound(TEXT("bell.wav"), NULL, SND_SYNC);
	}*/

	static void make_sound(char* name){
		PlaySound(TEXT(name), NULL, SND_SYNC);
	}
}; 