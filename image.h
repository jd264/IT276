#include <SDL.h>
#include <string>
#include <SDL_image.h>

//load image function
extern SDL_Surface *loadImg( std::string fileName);

//apply image
extern void applyImg(int x, int y, SDL_Surface* source, SDL_Surface* dest, int alpha);