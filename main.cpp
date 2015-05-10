#include <iostream>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
#include "SDL/SDL_mixer.h"


#include "Class/Object.h"
#include "Class/Eve.h"

#include "Class/Nave.h"
#include "Class/Asteroid.h"
#include "Class/Asteroids.h"

#include "Class/Shoot.h"
#include "Class/Eve_Poison.h"

using namespace std;

const int FPS = 20;


int main(int argc, char const *argv[]){
	
	srand(time(NULL));
	

	//INITIALIZING SDL
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_WM_SetCaption( "Nome do Jogo", NULL );
	TTF_Init();
	Mix_OpenAudio( 22050, MIX_DEFAULT_FORMAT, 2, 4096 );
	SDL_Surface *screen = NULL;
	screen = SDL_SetVideoMode( 800, 640, 16, SDL_SWSURFACE );

	bool running = true;

	SDL_Event event;

	//background
	SDL_Surface* background = IMG_Load("Media/space.jpg");

	Nave *player = new Nave( 50, 50, ((screen->w / 2) - 25), ((screen->h / 2) - 25) );
	player->setSprite("Media/nave.png");

	Asteroids* asteroids_do_game = new Asteroids(5, screen);



	//Laço principal
	while(running){
		int t1 = SDL_GetTicks();

		while(SDL_PollEvent(&event)){
			if( event.type==SDL_QUIT){
				running = false;
			}
			if( event.type == SDL_MOUSEMOTION )	{
				
			}
			if(event.type == SDL_KEYDOWN){
				switch( event.key.keysym.sym )
				{
					case SDLK_UP: { player->moveNave(screen); player->set_moving(50); break;}
					case SDLK_LEFT:{ player->increaseAngulo(); break;}
					case SDLK_RIGHT:{ player->decreaseAngulo(); break;}
				}

			}
		}

		SDL_BlitSurface(background,NULL,screen,NULL);

		player->blit(screen);
		asteroids_do_game->blit_asteroids(screen);

		if (player->get_moving())
		{
			player->moveNave(screen);
		}

		int t2 = SDL_GetTicks();
        int wait = t2 - t1;
        wait = (1000/FPS) - wait;
        if(wait > 0){
        	SDL_Delay(wait);
        }

		SDL_Flip(screen);

	}

	SDL_Quit();
}