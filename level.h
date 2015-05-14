#ifndef TILES_HEADER
#define TILES_HEADER

#include <SDL.h>
#include "init.h"

extern const int levelW;

extern const int tileW;
extern const int tileH;
extern const int totalT;
extern const int tileSp;

extern const int tileFloor;
extern const int tileFall;
extern const int tileObst;
extern const int tileWin;
extern const int tileNull;

extern class Tiles
{
	private:
		SDL_Rect colBox;
		int type;

	public:
		Tiles(int x, int y, int tileType);
		void show();
		int getType();
		SDL_Rect getColBox();
		
		
};

bool loadLevel(Tiles *tiles[]);
int touchWall(SDL_Rect collisionBox, Tiles *tiles[]);
extern void nextLevel();

#endif