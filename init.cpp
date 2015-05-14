#include "init.h"

//joystick
SDL_Joystick *joystick;

//screen
const int screenW = 640;
const int screenH = 480;
const int screenBpp = 32;

//level vars
int lvlSpeed = 0;
int backSpeed = 0;

bool quit = false;
bool nextlvl = false;
int lvlScene = 1;

//currency
int points = 0;

//Surfaces
SDL_Surface *player = NULL;
SDL_Surface *screen = NULL;
SDL_Surface *backg = NULL;
SDL_Surface *lvl1 = NULL;
SDL_Surface *obst = NULL;
SDL_Surface *tileSheet = NULL;

//Obstacles
SDL_Surface *barrelObstacle = NULL;
SDL_Surface *waterHolderObstacle = NULL;
SDL_Surface *chimneeObstacle = NULL;
SDL_Surface *crateObstacle = NULL;

//backSpikes
SDL_Surface *backSpikes = NULL;

//powerups
SDL_Surface *speedBoost = NULL;
SDL_Surface *immunity = NULL;
SDL_Surface *noGrav = NULL;
SDL_Surface *jumpBoost = NULL;

int sBoostAlpha = 50;
int immuneAlpha = 50;
int noGravAlpha = 50;
int jBoostAlpha = 50;

//walls
SDL_Rect wall1;
SDL_Rect wall2;
SDL_Rect wall3;
SDL_Rect wall4;
SDL_Rect wall5;
SDL_Rect wall6;
SDL_Rect wall7;
SDL_Rect wall8;
SDL_Rect wall9;
SDL_Rect wall10;
SDL_Rect wall11;
SDL_Rect wall12;
SDL_Rect wall13;
SDL_Rect wall14;
SDL_Rect wall15;
SDL_Rect wall16;
SDL_Rect wall17;
SDL_Rect wall18;
SDL_Rect wall19;
SDL_Rect wall20;

//obstacle walls
SDL_Rect barrel1;
SDL_Rect crate1;
SDL_Rect chimnee1;
SDL_Rect water1;
SDL_Rect barrel2;
SDL_Rect crate2;

//finish line wall
SDL_Rect finish;
SDL_Surface *finishS;

//anim
SDL_Rect anim[8];

SDL_Rect spikes;

SDL_Event event;

bool init()
{
	if(SDL_Init(SDL_INIT_EVERYTHING) == -1)
	{
		return false;
	}

	//screen setup
	screen = SDL_SetVideoMode(screenW, screenH, screenBpp, SDL_SWSURFACE);

	//screen error
	if(screen == NULL)
	{
		return false;
	}

	SDL_JoystickEventState(SDL_ENABLE);

	//caption
	SDL_WM_SetCaption("Run Free or Bail Hard", NULL);

	return true;
}

bool loadFiles()
{
	player = loadImg("RU_6.bmp");
	backg = loadImg("batman.bmp");
	lvl1 = loadImg("level1.bmp");

	//obstacles
	barrelObstacle = loadImg("barrilObstacle.bmp");
	waterHolderObstacle = loadImg("waterHolderObstacle.bmp");
	chimneeObstacle = loadImg("chimneeObstacle.bmp");
	crateObstacle = loadImg("boxObstacle.bmp"); 

	//backSpikes
	backSpikes = loadImg("backSpikes.bmp");

	//powerups
	speedBoost = loadImg("speedBoostPU.bmp");
	immunity = loadImg("immunityPU.bmp");
	noGrav = loadImg("noGravPU.bmp");
	jumpBoost = loadImg("jumpBoostPU.bmp");

	//finishSurface
	finishS = loadImg("finish.bmp");

	joystick = SDL_JoystickOpen(0);

	//loading errors
	if((player == NULL) || (backg == NULL) || (lvl1 == NULL) || (barrelObstacle == NULL) 
		|| (waterHolderObstacle == NULL) || (chimneeObstacle == NULL) || (crateObstacle == NULL)
		|| (backSpikes == NULL) || (speedBoost == NULL) || (immunity == NULL) || noGrav == NULL 
		|| (jumpBoost == NULL) || (finishS == NULL))
	{
		//File Missing
		return false;
	}

	return true;
}

void loadLevel(int levelNum)
{
	loadFiles();

	//walls
		wall1.x = 0;
		wall1.y = 380;
		wall1.w = 350;
		wall1.h = 100;

		wall2.x = 385;
		wall2.y = 330;
		wall2.w = 200;
		wall2.h = 150;

		wall3.x = 616;
		wall3.y = 330;
		wall3.w = 100;
		wall3.h = 150;

		wall4.x = 716;
		wall4.y = 280;
		wall4.w = 100;
		wall4.h = 200;

		wall5.x = 816;
		wall5.y = 430;
		wall5.w = 200;
		wall5.h = 50;

		wall6.x = 1049;
		wall6.y = 405;
		wall6.w = 200;
		wall6.h = 75;

		wall7.x = 1249;
		wall7.y = 380;
		wall7.w = 200;
		wall7.h = 100;

		wall8.x = 1449;
		wall8.y = 355;
		wall8.w = 200;
		wall8.h = 125;

		wall9.x = 1669;
		wall9.y = 330;
		wall9.w = 200;
		wall9.h = 150;

		wall10.x = 1949;
		wall10.y = 430;
		wall10.w = 100;
		wall10.h = 50;

		wall11.x = 2049;
		wall11.y = 380;
		wall11.w = 150;
		wall11.h = 100;

		wall12.x = 2228;
		wall12.y = 355;
		wall12.w = 150;
		wall12.h = 125;

		wall13.x = 2378;
		wall13.y = 380;
		wall13.w = 150;
		wall13.h = 100;

		wall14.x = 2580;
		wall14.y = 305;
		wall14.w = 150;
		wall14.h = 175;

		wall15.x = 2730;
		wall15.y = 280;
		wall15.w = 150;
		wall15.h = 200;

		wall16.x = 2880;
		wall16.y = 230;
		wall16.w = 150;
		wall16.h = 250;

		wall17.x = 3030;
		wall17.y = 430;
		wall17.w = 170;
		wall17.h = 50;

		wall18.x = 0;
		wall18.y = 380;
		wall18.w = 350;
		wall18.h = 100;

		wall19.x = 0;
		wall19.y = 380;
		wall19.w = 350;
		wall19.h = 100;

		wall20.x = 0;
		wall20.y = 380;
		wall20.w = 350;
		wall20.h = 100;

		spikes.x = 0;
		spikes.y = 0;
		spikes.w = 45;
		spikes.h = 480;

		//obstacles
		barrel1.x = 450;
		barrel1.y = 270;
		barrel1.w = 32;
		barrel1.h = 60;

		crate1.x = 652;
		crate1.y = 298;
		crate1.w = 64;
		crate1.h = 32;

		chimnee1.x = 840;
		chimnee1.y = 405;
		chimnee1.w = 10;
		chimnee1.h = 25;

		water1.x = 1300;
		water1.y = 252;
		water1.w = 64;
		water1.h = 128;

		barrel2.x = 1575;
		barrel2.y = 295;
		barrel2.w = 32;
		barrel2.h = 60;

		crate2.x = 2464;
		crate2.y = 348;
		crate2.w = 64;
		crate2.h = 32;

		//finish
		finish.x = 3150;
		finish.y = 230;
		finish.w = 50;
		finish.h = 200;
}

void updateLevel()
{
	//lvlVars
		lvlSpeed -= 5;
		backSpeed -= 5;

	//wallsVars
		wall1.x -= 5;
		wall2.x -= 5;
		wall3.x -= 5;
		wall4.x -= 5;
		wall5.x -= 5;
		wall6.x -= 5;
		wall7.x -= 5;
		wall8.x -= 5;
		wall9.x -= 5;
		wall10.x -= 5;
		wall11.x -= 5;
		wall12.x -= 5;
		wall13.x -= 5;
		wall14.x -= 5;
		wall15.x -= 5;
		wall16.x -= 5;
		wall17.x -= 5;

		//obstacles
		barrel1.x -= 5;
		barrel2.x -= 5;
		crate1.x -= 5;
		crate2.x -= 5;
		chimnee1.x -= 5;
		water1.x -= 5;

		//finish
		finish.x -= 5;

	//points
		points += 1;

		if(points >= 60)
		{
			sBoostAlpha = 255;
		}
		else
		{
			sBoostAlpha = 50;
		}

		if(points >= 120)
		{
			jBoostAlpha = 255;
		}
		else
		{
			jBoostAlpha = 50;
		}
		if(points >= 180)
		{
			noGravAlpha = 255;
		}
		else
		{
			noGravAlpha = 50;
		}

		if(points >= 240)
		{
			immuneAlpha = 255;
		}
		else
		{
			immuneAlpha = 50;
		}

	//surfaces
		if(backSpeed <= -backg->w)
		{
			backSpeed = 0;
		}

		applyImg(backSpeed, 0, backg, screen , 255);
		applyImg(backSpeed + backg->w, 0, backg, screen, 255);

		applyImg(450 + lvlSpeed , 270, barrelObstacle, screen, 255);
		applyImg(652 + lvlSpeed , 298, crateObstacle, screen, 255);
		applyImg(840 + lvlSpeed , 405, chimneeObstacle, screen, 255);
		applyImg(1300 + lvlSpeed , 252, waterHolderObstacle, screen, 255);
		applyImg(1575 + lvlSpeed , 295, barrelObstacle, screen, 255);
		applyImg(2464 + lvlSpeed , 348, crateObstacle, screen, 255);

		applyImg(lvlSpeed, 0, lvl1, screen, 255);

		applyImg(0, 0, backSpikes, screen, 255);

		applyImg(3150 + lvlSpeed, 230, finishS, screen, 255);

		//powerups
		applyImg(576, 416, immunity, screen, immuneAlpha);
		applyImg(512, 416, noGrav, screen, noGravAlpha);
		applyImg(448, 416, jumpBoost, screen, jBoostAlpha);
		applyImg(384, 416, speedBoost, screen, sBoostAlpha);
}

void cleanUp()
{
	//free ents
	SDL_FreeSurface(player);
	SDL_FreeSurface(backg);
	SDL_FreeSurface(lvl1);
	SDL_FreeSurface(obst);
	SDL_FreeSurface(barrelObstacle);
	SDL_FreeSurface(waterHolderObstacle);
	SDL_FreeSurface(chimneeObstacle);
	SDL_FreeSurface(crateObstacle);
	SDL_FreeSurface(backSpikes);
	SDL_FreeSurface(speedBoost);
	SDL_FreeSurface(immunity);
	SDL_FreeSurface(noGrav);
	SDL_FreeSurface(jumpBoost);
	SDL_FreeSurface(finishS);

	if(lvlScene < 4)
	{
		loadLevel(lvlScene);
	}
	else
	{
		quit == true;
	}
	
}