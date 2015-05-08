#include <iostream>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
#include "SDL/SDL_mixer.h"


#include "Class/Object.h"
#include "Class/Eve.h"
#include "Class/Nave.h"
#include "Class/Asteroid.h"
#include "Class/Shoot.h"
#include "Class/Eve_Poison.h"

using namespace std;


int main(int argc, char const *argv[]){
	
	srand(time(NULL));
	

	//INITIALIZING SDL
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_WM_SetCaption("DroneNudes", NULL);
	TTF_Init();
	Mix_OpenAudio( 22050, MIX_DEFAULT_FORMAT, 2, 4096 );
	SDL_Surface *screen = NULL;
	screen=SDL_SetVideoMode(800,640,16,SDL_SWSURFACE);

	bool running = true;

	SDL_Event event;

	while(running){

		while(SDL_PollEvent(&event)){
			if( event.type==SDL_QUIT){
				running = false;
			}
			if( event.type == SDL_MOUSEMOTION )	{
				
			}
			// if(event.type == SDL_KEYDOWN){
			// 	switch( event.key.keysym.sym )
			// 	{
			// 		case SDLK_UP: { player->moveShip(screen); break;}
			// 		case SDLK_LEFT:{ player->increaseAngle(); break;}
			// 		case SDLK_RIGHT:{player->decreaseAngle(); break;}
			// 	}
			// }
		}


	}

	return 0;
}