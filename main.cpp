#include <iostream>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
#include "SDL/SDL_mixer.h"

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 640

#define QUANTIDADE_ASTEROIDS 10


#include "Class/Object.h"
#include "Class/Eve.h"

#include "Class/Nave.h"
#include "Class/Shoot.h"
#include "Class/Asteroid.h"
#include "Class/Asteroids.h"

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
	screen = SDL_SetVideoMode( SCREEN_WIDTH, SCREEN_HEIGHT, 16, SDL_SWSURFACE );

	bool running = true;

	SDL_Event event;

	//background
	SDL_Surface* background = IMG_Load("Media/space.jpg");

	Nave player( 50, 50, ((SCREEN_WIDTH / 2) - 25), ((SCREEN_HEIGHT / 2) - 25) );
	player.setSprite("Media/nave.png");

	Shoot tiro( 10, 10, ((SCREEN_WIDTH / 2) - 25), ((SCREEN_HEIGHT / 2) - 25));
	tiro.setSprite("Media/tiro.png");

	Asteroids asteroids_do_game(QUANTIDADE_ASTEROIDS, screen);


	//Laço principal
	while(running){
		int t1 = SDL_GetTicks();

		while(SDL_PollEvent(&event)){
			if( event.type==SDL_QUIT){
				running = false;
			}
			if(event.type == SDL_KEYDOWN){

				switch( event.key.keysym.sym ){
					case SDLK_UP: { player.set_moving(50); break;}
					case SDLK_LEFT:{ player.increaseAngulo(); break;}
					case SDLK_RIGHT:{ player.decreaseAngulo(); break;}
					case SDLK_SPACE:{ 
						if (tiro.get_moving() <= 50){
							tiro.set_moving(100);
							tiro.set_angulo( player.get_angulo() );
							tiro.set_position( ( player.get_x() + (player.get_width() / 2) ), ( player.get_y() + (player.get_height() / 2) ) );
						}
						break;
					}
				}

			}
		}

		SDL_BlitSurface(background,NULL,screen,NULL);

		player.blit(screen);
		asteroids_do_game.blit_asteroids(screen);


		asteroids_do_game.player_collision(&player); //Detectando collision

		if (player.get_moving()){
			player.moveNave(screen);
		}

		if (tiro.get_moving()){
			tiro.blit(screen);

			tiro.moveShoot(screen);

			asteroids_do_game.shoot_collision(&tiro); //Detectando collision

		}

		asteroids_do_game.moveAsteroids(screen);



		//FPS------------------------
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