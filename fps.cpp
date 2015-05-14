#include "fps.h"

FPS::FPS()
{
	//initialize
	startT = 0;
	pausedT = 0;
	paused = false;
	started = false;
}

void FPS::startFPS()
{
	started = true;
	paused = false;

	startT = SDL_GetTicks();
}

void FPS::stopFPS()
{
	started = false;
	paused = false;
}

void FPS::pauseFPS()
{
	if((started == true) && (paused == false))
	{
		paused = true;

		pausedT = SDL_GetTicks() - startT;
	}
}

void FPS::unpauseFPS()
{
	if(paused == true)
	{
		paused = false;

		startT = SDL_GetTicks() - pausedT;

		pausedT = 0;
	}
}

int FPS::getT()
{
	if(started == true)
	{
		if(paused == true)
		{
			return pausedT;
		}
		else
		{
			return SDL_GetTicks() - startT;
		}
	}

	return 0;
}

bool FPS::isStarted()
{
	return started;
}
bool FPS::isPause()
{
	return paused;
}