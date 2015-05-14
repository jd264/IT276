#include "collision.h"

bool collisionCheck(SDL_Rect A, SDL_Rect B)
{
	int leftA;
	int leftB;
	int rightA;
	int rightB;
	int topA;
	int topB;
	int botA;
	int botB;

	//calculate and assign A
	leftA = A.x;
	rightA = A.x + A.w;
	topA = A.y;
	botA = A.y + A.h;

	//calculate and assign B
	leftB = B.x;
	rightB = B.x + B.w;
	topB = B.y;
	botB = B.y + B.h;

	//check
	if( botA <= topB )
	{
		return false;
	}
	if( topA >= botB )
	{
		return false;
	}
	if( rightA <= leftB )
	{
		return false;
	}
	if( leftA >= rightB )
	{
		return false;
	}
	

	return true;
}

bool sideCollisionCheck(SDL_Rect A, SDL_Rect B)
{
	int leftA;
	int leftB;
	int rightA;
	int rightB;
	int topA;
	int topB;
	int botA;
	int botB;

	//calculate and assign A
	leftA = A.x;
	rightA = A.x + A.w;
	topA = A.y;
	botA = A.y + A.h;

	//calculate and assign B
	leftB = B.x;
	rightB = B.x + B.w;
	topB = B.y;
	botB = B.y + B.h;

	if((rightA >= leftB) && (botA - 20 > topB) && (leftA <= rightB))
	{
		return true;
	}

	return false;
}