#include <SDL.h>
#include "level.h"
#include "image.h"
#include "collision.h"
#include <fstream>

const int levelW = 640;

const int tileW = 32;
const int tileH = 32;
const int totalT = 192;
const int tileSp = 5;

const int tileFloor = 0;
const int tileFall = 1;
const int tileObst = 2;
const int tileWin = 3;
const int tileNull = 4;

Tiles::Tiles( int x, int y, int tileType)
{
	colBox.x = x;
	colBox.y = y;

	colBox.w = tileW;
	colBox.h = tileH;

	type = tileType;
}

void Tiles::show()
{
	applyImg(colBox.x, colBox.y, tileSheet, screen, 255);
}

int Tiles::getType()
{
	return type;
}

SDL_Rect Tiles::getColBox()
{
	return colBox;
}

bool loadLevel( Tiles *tiles[])
{
	int x = 0;
	int y = 0;

	//open map
	std::ifstream tileMap("lazy.map");

	if( tileMap == NULL)
	{
		return false;
	}
	
	//init
	for( int t = 0; t < totalT; t++)
	{
		int tileType = -1;

		tileMap >> tileType;

		if( tileMap.fail() == true)
		{
			tileMap.close();
			return false;
		}

		if((tileType >= 0) && (tileType < tileSp))
		{
			tiles[t] = new Tiles(x, y, tileType);
		}
		else
		{
			tileMap.close();
			return false;
		}

		x += tileW;

		if( x >= levelW)
		{
			x = 0;

			y += tileH;
		}
	}

	tileMap.close();

	return true;
}

int touchWall( SDL_Rect collisionBox, Tiles *tiles[])
{
	for( int t = 0; t < totalT; t++)
	{
		if(tiles[t]->getType() == tileNull)
		{
			if(collisionCheck(collisionBox, tiles[t]->getColBox()) == true)
			{
				return 1;
			}
		}
		else if(tiles[t]->getType() == tileFloor)
		{
			if(collisionCheck(collisionBox, tiles[t]->getColBox()) == true)
			{
				return 2;
			}
		}
		else if(tiles[t]->getType() == tileFall)
		{
			if(collisionCheck(collisionBox, tiles[t]->getColBox()) == true)
			{
				return 3;
			}
		}
		else if(tiles[t]->getType() == tileObst)
		{
			if(collisionCheck(collisionBox, tiles[t]->getColBox()) == true)
			{
				return 4;
			}
		}
		else if(tiles[t]->getType() == tileWin)
		{
			if(collisionCheck(collisionBox, tiles[t]->getColBox()) == true)
			{
				return 5;
			}
		}
	}

	return 0;
}