#include "player.h"
#include "image.h"
#include "collision.h"

bool gravSwitch = true;
bool gravBoost = false;
bool immuneSwitch = false;

bool sideHit = false;

bool crouchSwitch = false;

int pAlpha = 255;

Player::Player()
{
	x = 200;
	y = 250;
	
	pBox.x = x + 16;
	pBox.y = y;

	pBox.w = playerW / 2;
	pBox.h = playerH;

	ySpeed = 0;
	xSpeed = 0;

	initialY = 250;
	initialX = 200;

	limit = 100;
}

void Player::getInputPlayer()
{
	if((event.type == SDL_KEYDOWN) && (gravSwitch == false) && (crouchSwitch ==false))
	{
		switch(event.key.keysym.sym)
		{
			case SDLK_w:
				ySpeed -= playerH / 2;
				break;
			case SDLK_d:
				if(sBoostAlpha == 255)
				{
					points -= 60;
					xSpeed += 5;
				}
				break;
			case SDLK_SPACE:
				if(jBoostAlpha == 255)
				{
					points -= 120;
					limit = 200;
				}
				ySpeed -= playerH/2;
				break;
			case SDLK_c:
				crouchSwitch = true;
				break;
			case SDLK_e:
				if(immuneAlpha == 240)
				{
					points -= 350;
					immuneSwitch = true;
				}
				break;
		}
	}
	else if((event.type == SDL_JOYBUTTONDOWN) && (gravSwitch == false) && (crouchSwitch ==false))
	{
		switch(event.jbutton.button)
		{
		case 0:
			ySpeed -= playerH / 2;
			break;
		case 4:
			if(sBoostAlpha == 255)
				{
					points -= 60;
					xSpeed += 5;
				}
			break;
		case 1:
			if(jBoostAlpha == 255)
				{
					points -= 120;
					limit = 200;
				}
			ySpeed -= playerH/2;
			break;
		case 2:
			case SDLK_c:
				crouchSwitch = true;
			break;
		case 5:
			if(immuneAlpha == 240)
				{
					points -= 350;
					immuneSwitch = true;
				}
			break;
		}
	}
	else if(event.type == SDL_JOYBUTTONDOWN)
	{
		switch(event.jbutton.button)
		{
			case 4:
				if(noGravAlpha == 255)
				{
					points -= 180;
					gravBoost = true;
				}
				break;
			case 8:
				gravBoost = false;
				break;
		}
	}
	else if(event.type == SDL_JOYBUTTONUP)
	{
		switch(event.jbutton.button)
		{
			case 2:
				crouchSwitch = false;
				break;
		}
	}
	else if(event.type == SDL_KEYDOWN)
	{
		switch(event.key.keysym.sym)
		{
			case SDLK_q:
				if(noGravAlpha == 255)
				{
					points -= 180;
					gravBoost = true;
				}
				break;
			case SDLK_s:
				gravBoost = false;
				break;
		}
	}
	else if(event.type == SDL_KEYUP)
	{
		switch(event.key.keysym.sym)
		{
			case SDLK_c:
				crouchSwitch = false;
				break;
		}
	}
}

void Player::movePlayer()
{
	if(sideCollisionCheck(pBox, wall2))
	{
		x -= 5;
		pBox.x -= 5;
		initialX = x;
		sideHit = true;
	}
	else if(sideCollisionCheck(pBox, wall3))
	{
		x -= 5;
		pBox.x -= 5;
		initialX = x;
		sideHit = true;
	}
	else if(sideCollisionCheck(pBox, wall4))
	{
		x -= 5;
		pBox.x -= 5;
		initialX = x;
		sideHit = true;
	}
	else if(sideCollisionCheck(pBox, wall5))
	{
		x -= 5;
		pBox.x -= 5;
		initialX = x;
		sideHit = true;
	}
	else if(sideCollisionCheck(pBox, wall6))
	{
		x -= 5;
		pBox.x -= 5;
		initialX = x;
		sideHit = true;
	}
	else if(sideCollisionCheck(pBox, wall7))
	{
		x -= 5;
		pBox.x -= 5;
		initialX = x;
		sideHit = true;
	}
	else if(sideCollisionCheck(pBox, wall8))
	{
		x -= 5;
		pBox.x -= 5;
		initialX = x;
		sideHit = true;
	}
	else if(sideCollisionCheck(pBox, wall9))
	{
		x -= 5;
		pBox.x -= 5;
		initialX = x;
		sideHit = true;
	}
	else if(sideCollisionCheck(pBox, wall10))
	{
		x -= 5;
		pBox.x -= 5;
		initialX = x;
		sideHit = true;
	}
	else if(sideCollisionCheck(pBox, wall11))
	{
		x -= 5;
		pBox.x -= 5;
		initialX = x;
		sideHit = true;
	}
	else if(sideCollisionCheck(pBox, wall12))
	{
		x -= 5;
		pBox.x -= 5;
		initialX = x;
		sideHit = true;
	}
	else if(sideCollisionCheck(pBox, wall13))
	{
		x -= 5;
		pBox.x -= 5;
		initialX = x;
		sideHit = true;
	}
	else if(sideCollisionCheck(pBox, wall14))
	{
		x -= 5;
		pBox.x -= 5;
		initialX = x;
		sideHit = true;
	}
	else if(sideCollisionCheck(pBox, wall15))
	{
		x -= 5;
		pBox.x -= 5;
		initialX = x;
		sideHit = true;
	}
	else if(sideCollisionCheck(pBox, wall16))
	{
		x -= 5;
		pBox.x -= 5;
		initialX = x;
		sideHit = true;
	}
	else if(sideCollisionCheck(pBox, wall17))
	{
		x -= 5;
		pBox.x -= 5;
		initialX = x;
		sideHit = true;
	}
	else if(sideCollisionCheck(pBox, barrel1) && immuneSwitch == false)
	{
		x -= 5;
		pBox.x -= 5;
		initialX = x;
		//sideHit = true;
	}
	else if(sideCollisionCheck(pBox, crate1)&& immuneSwitch == false)
	{
		x -= 5;
		pBox.x -= 5;
		initialX = x;
		//sideHit = true;
	}
	else if(sideCollisionCheck(pBox, chimnee1)&& immuneSwitch == false)
	{
		x -= 5;
		pBox.x -= 5;
		initialX = x;
		//sideHit = true;
	}
	else if(sideCollisionCheck(pBox, water1) && immuneSwitch == false && (crouchSwitch == false))
	{
		x -= 5;
		pBox.x -= 5;
		initialX = x;
		//sideHit = true;
	}
	else if(sideCollisionCheck(pBox, barrel2)&& immuneSwitch == false)
	{
		x -= 5;
		pBox.x -= 5;
		initialX = x;
		//sideHit = true;
	}
	else if(sideCollisionCheck(pBox, crate2)&& immuneSwitch == false)
	{
		x -= 5;
		pBox.x -= 5;
		initialX = x;
		//sideHit = true;
	}
	else if(sideCollisionCheck(pBox, finish))
	{
		nextlvl = true;
		lvlScene = 4;
		quit = true;
	}
	else if(collisionCheck(pBox, finish))
	{
		nextlvl = true;
		lvlScene = 4;
		quit = true;
	}
	else if(collisionCheck(pBox, wall1)) 
	{
		gravSwitch = false;
		initialY = y;
		if(pBox.y + pBox.h > wall1.y)
		{
			pBox.y = wall1.y - pBox.h + 1;
			y = wall1.y - pBox.h;
		}
	}
	else if(collisionCheck(pBox, wall2))
	{
		gravSwitch = false;
		initialY = y;
		if(pBox.y + pBox.h > wall2.y)
		{
			pBox.y = wall2.y - pBox.h + 1;
			y = wall2.y - pBox.h;
		}
	}
	else if(collisionCheck(pBox, wall3))
	{
		gravSwitch = false;
		initialY = y;
		if(pBox.y + pBox.h > wall3.y)
		{
			pBox.y = wall3.y - pBox.h + 1;
			y = wall3.y - pBox.h;
		}
	}
	else if(collisionCheck(pBox, wall4))
	{
		gravSwitch = false;
		initialY = y;
		if(pBox.y + pBox.h > wall4.y)
		{
			pBox.y = wall4.y - pBox.h + 1;
			y = wall4.y - pBox.h;
		}
	}
	else if(collisionCheck(pBox, wall5))
	{
		gravSwitch = false;
		initialY = y;
		if(pBox.y + pBox.h > wall5.y)
		{
			pBox.y = wall5.y - pBox.h + 1;
			y = wall5.y - pBox.h;
		}
	}
	else if(collisionCheck(pBox, wall6))
	{
		gravSwitch = false;
		initialY = y;
		if(pBox.y + pBox.h > wall6.y)
		{
			pBox.y = wall6.y - pBox.h + 1;
			y = wall6.y - pBox.h;
		}
	}
	else if(collisionCheck(pBox, wall7))
	{
		gravSwitch = false;
		initialY = y;
		if(pBox.y + pBox.h > wall7.y)
		{
			pBox.y = wall7.y - pBox.h + 1;
			y = wall7.y - pBox.h;
		}
	}
	else if(collisionCheck(pBox, wall8))
	{
		gravSwitch = false;
		initialY = y;
		if(pBox.y + pBox.h > wall8.y)
		{
			pBox.y = wall8.y - pBox.h + 1;
			y = wall8.y - pBox.h;
		}
	}
	else if(collisionCheck(pBox, wall9))
	{
		gravSwitch = false;
		initialY = y;
		if(pBox.y + pBox.h > wall9.y)
		{
			pBox.y = wall9.y - pBox.h + 1;
			y = wall9.y - pBox.h;
		}
	}
	else if(collisionCheck(pBox, wall10))
	{
		gravSwitch = false;
		initialY = y;
		if(pBox.y + pBox.h > wall10.y)
		{
			pBox.y = wall10.y - pBox.h + 1;
			y = wall10.y - pBox.h;
		}
	}
	else if(collisionCheck(pBox, wall11))
	{
		gravSwitch = false;
		initialY = y;
		if(pBox.y + pBox.h > wall11.y)
		{
			pBox.y = wall11.y - pBox.h + 1;
			y = wall11.y - pBox.h;
		}
	}
	else if(collisionCheck(pBox, wall12))
	{
		gravSwitch = false;
		initialY = y;
		if(pBox.y + pBox.h > wall12.y)
		{
			pBox.y = wall12.y - pBox.h + 1;
			y = wall12.y - pBox.h;
		}
	}
	else if(collisionCheck(pBox, wall13))
	{
		gravSwitch = false;
		initialY = y;
		if(pBox.y + pBox.h > wall13.y)
		{
			pBox.y = wall13.y - pBox.h + 1;
			y = wall13.y - pBox.h;
		}
	}
	else if(collisionCheck(pBox, wall14))
	{
		gravSwitch = false;
		initialY = y;
		if(pBox.y + pBox.h > wall14.y)
		{
			pBox.y = wall14.y - pBox.h + 1;
			y = wall14.y - pBox.h;
		}
	}
	else if(collisionCheck(pBox, wall15))
	{
		gravSwitch = false;
		initialY = y;
		if(pBox.y + pBox.h > wall15.y)
		{
			pBox.y = wall15.y - pBox.h + 1;
			y = wall15.y - pBox.h;
		}
	}
	else if(collisionCheck(pBox, wall16))
	{
		gravSwitch = false;
		initialY = y;
		if(pBox.y + pBox.h > wall16.y)
		{
			pBox.y = wall16.y - pBox.h + 1;
			y = wall16.y - pBox.h;
		}
	}
	else if(collisionCheck(pBox, wall17))
	{
		gravSwitch = false;
		initialY = y;
		if(pBox.y + pBox.h > wall17.y)
		{
			pBox.y = wall17.y - pBox.h + 1;
			y = wall17.y - pBox.h;
		}
	}
	else if(collisionCheck(pBox, crate1)&& immuneSwitch == false) 
	{
		gravSwitch = false;
		initialY = y;
		if(pBox.y + pBox.h > crate1.y)
		{
			pBox.y = crate1.y - pBox.h + 1;
			y = crate1.y - pBox.h;
		}
	}
	else if(collisionCheck(pBox, barrel1)&& immuneSwitch == false) 
	{
		gravSwitch = false;
		initialY = y;
		if(pBox.y + pBox.h > barrel1.y)
		{
			pBox.y = barrel1.y - pBox.h + 1;
			y = barrel1.y - pBox.h;
		}
	}
	else if(collisionCheck(pBox, chimnee1)&& immuneSwitch == false) 
	{
		gravSwitch = false;
		initialY = y;
		if(pBox.y + pBox.h > chimnee1.y)
		{
			pBox.y = chimnee1.y - pBox.h + 1;
			y = chimnee1.y - pBox.h;
		}
	}
	else if((collisionCheck(pBox, water1)) && (crouchSwitch == false)&& immuneSwitch == false ) 
	{
		gravSwitch = false;
		initialY = y;
		if(pBox.y + pBox.h > water1.y)
		{
			pBox.y = water1.y - pBox.h + 1;
			y = water1.y - pBox.h;
		}
	}
	else if(collisionCheck(pBox, barrel2)&& immuneSwitch == false) 
	{
		gravSwitch = false;
		initialY = y;
		if(pBox.y + pBox.h > barrel2.y)
		{
			pBox.y = barrel2.y - pBox.h + 1;
			y = barrel2.y - pBox.h;
		}
	}
	else if(collisionCheck(pBox, crate2)&& immuneSwitch == false) 
	{
		gravSwitch = false;
		initialY = y;
		if(pBox.y + pBox.h > crate2.y)
		{
			pBox.y = crate2.y - pBox.h + 1;
			y = crate2.y - pBox.h;
		}
	}
	else
	{
		if(gravBoost != true)
		{
			gravSwitch = true;
		}
		sideHit = false;
	}

	if(collisionCheck(pBox, spikes))
	{
		quit = true;
	}

	if(y <= (initialY - limit) && (gravBoost == false))
	{
		ySpeed = 0;
		limit = 100;
	}

	if(sideHit == true && ((pBox.y < (barrel1.y + barrel1.h))
		|| (pBox.y < (barrel2.y + barrel2.h)) || (pBox.y < (crate1.y + crate1.h))
		|| (pBox.y < (crate2.y + crate2.h)) || (pBox.y < (chimnee1.y + chimnee1.h))
		|| (pBox.y < (water1.y + water1.h))))
	{
		gravSwitch = false;
		xSpeed = 0;
		initialX = x;
	}
	else if(sideHit == true)
	{
		xSpeed = 0;
		initialX = x;
	}

	if(x >= (initialX + 60))
	{
		xSpeed = 0;
		initialX = x;
	}

	y += ySpeed;
	pBox.y += ySpeed;
	
	x += xSpeed;
	pBox.x += xSpeed;

	if(((y < 0) || (pBox.y < 0)) || ((y + playerH > screenH) || (pBox.y + playerH > screenH)))
	{
		//Move back
		y -= ySpeed;
		pBox.y -= ySpeed;
	}

	if( gravSwitch == true)
	{
		y += gravVal;
		pBox.y += gravVal;
	}

	if(y > screenH)
	{
		quit = true;
	}
}

void Player::showPlayer(int alpha)
{
	applyImg(x, y, player, screen, 255);

	//collision check mode
	//SDL_FillRect( screen, &pBox, SDL_MapRGB( screen->format, 0x77, 0x77, 0x77 ) );
}