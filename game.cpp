#include "fps.h"
#include "init.h"
#include "player.h"


int main( int argc, char* args[])
{
	//player
	Player myPlayer;

	//fps
	FPS fps;

	//init
	if(init() == false)
	{
		return 1;
	}

	//load
	if(loadFiles() != false)
	{
		loadLevel(lvlScene);
	}
	else
	{
		return 1;
	}

	//while no quit
	while(quit == false)
	{
		//start timer
		fps.startFPS();

		while(SDL_PollEvent(&event))
		{
			//player event
			myPlayer.getInputPlayer();

			//x out window
			if(event.type == SDL_QUIT)
			{
				quit = true;
			}
		}
		
		//lvlupdate
		updateLevel();

		//player controls
		myPlayer.movePlayer();
		myPlayer.showPlayer(pAlpha);
		
		//SDL_FillRect( screen, &wall, SDL_MapRGB( screen->format, 0x77, 0x77, 0x77 ) );

		//nextlvl
		/*if(nextlvl == true)
		{
			cleanUp();
			nextlvl == false;
		}*/

		//update
		if(SDL_Flip(screen) == -1)
		{
			return 1;
		}

		//cap
		if(fps.getT() < 1000 / fpsNum)
		{
			SDL_Delay((1000 / fpsNum) - fps.getT());
		}
	}

	cleanUp();

	return 0;
}