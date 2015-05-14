#include <SDL.h>
#include <SDL_ttf.h>
#include "image.h"


//joystick
extern SDL_Joystick *joystick;

//screen
extern const int screenW;
extern const int screenH;
extern const int screenBpp;

//lvl vars
extern int lvlSpeed;
extern int backSpeed;
extern bool quit; //quit bool
extern bool nextlvl; //next level bool
extern int lvlScene;

//currency
extern int points;

//Surfaces
extern SDL_Surface *player;
extern SDL_Surface *screen;
extern SDL_Surface *backg;
extern SDL_Surface *lvl1;
extern SDL_Surface *obst;
extern SDL_Surface *tileSheet;

//obstacles
extern SDL_Surface *barrelObstacle;
extern SDL_Surface *waterHolderObstacle;
extern SDL_Surface *chimneeObstacle;
extern SDL_Surface *crateObstacle;

//backSpikes
extern SDL_Surface *backSpikes;

//powerups
extern SDL_Surface *speedBoost;
extern SDL_Surface *immunity;
extern SDL_Surface *noGrav;
extern SDL_Surface *jumpBoost;

//powerups alpha
extern int sBoostAlpha;
extern int immuneAlpha;
extern int noGravAlpha;
extern int jBoostAlpha;

//walls
extern SDL_Rect wall1;
extern SDL_Rect wall2;
extern SDL_Rect wall3;
extern SDL_Rect wall4;
extern SDL_Rect wall5;
extern SDL_Rect wall6;
extern SDL_Rect wall7;
extern SDL_Rect wall8;
extern SDL_Rect wall9;
extern SDL_Rect wall10;
extern SDL_Rect wall11;
extern SDL_Rect wall12;
extern SDL_Rect wall13;
extern SDL_Rect wall14;
extern SDL_Rect wall15;
extern SDL_Rect wall16;
extern SDL_Rect wall17;
extern SDL_Rect wall18;
extern SDL_Rect wall19;
extern SDL_Rect wall20;

//obstacle walls
extern SDL_Rect barrel1;
extern SDL_Rect crate1;
extern SDL_Rect chimnee1;
extern SDL_Rect water1;
extern SDL_Rect barrel2;
extern SDL_Rect crate2;

//finish line wall
extern SDL_Rect finish;
extern SDL_Surface *finishS;

//sprite animations
extern SDL_Rect anim[8];

extern SDL_Rect spikes;

extern SDL_Event event;

extern bool init();

extern bool loadFiles();

extern void loadLevel(int levelNum);

extern void updateLevel();

extern void cleanUp();