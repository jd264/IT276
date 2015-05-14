#include <SDL.h>
#include "init.h"

const int playerW = 64;
const int playerH = 64;

const int gravVal = 15;

extern int pAlpha;

extern class Player
{
	private:
		SDL_Rect pBox;
		int x;
		int y;
		int xSpeed;
		int ySpeed;
		int initialY;
		int initialX;
		int limit;
	public:
		Player();
		void getInputPlayer();
		void movePlayer();
		void showPlayer(int alpha);
};