#include "image.h"
#include "init.h"


SDL_Surface *loadImg( std::string fileName)
{
	//temp storage
	SDL_Surface* loadedImg = NULL;

	//opti image
	SDL_Surface* optiImg = NULL;

	//load
	loadedImg = SDL_LoadBMP(fileName.c_str());

	//optimize
	if(loadedImg != NULL)
	{
		optiImg = SDL_DisplayFormat(loadedImg);

		//free temp storage
		SDL_FreeSurface(loadedImg);

		if(optiImg != NULL)
		{
			SDL_SetColorKey(optiImg, SDL_SRCCOLORKEY, SDL_MapRGB(optiImg->format, 0, 255, 255));
		}
	}
	return optiImg;
}

//apply image
void applyImg(int x, int y, SDL_Surface* source, SDL_Surface* dest, int alpha)
{
	//temp rect for offsets
	SDL_Rect offsets;

	offsets.x = x;
	offsets.y = y;

	//blit
	SDL_BlitSurface(source, NULL, dest, &offsets);
	SDL_SetAlpha(source, SDL_SRCALPHA, alpha);
}