
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

#include <vector>

using namespace std;

class Asteroids{
	vector<Asteroid> vetor_Asteroids;
	SDL_Surface* sprite_asteroid_BIG = NULL;
	SDL_Surface* sprite_asteroid_SMALL = NULL;


	public:
		Asteroids(int, SDL_Surface*);
		~Asteroids();

		//Blit
		void blit_asteroids(SDL_Surface*);
	
};

Asteroids::Asteroids(int quantidade_asteroids, SDL_Surface* screen){

	sprite_asteroid_BIG = IMG_Load("Media/asteroid.png");

	for (int i = 0; i < quantidade_asteroids; ++i){

		Asteroid a = new Asteroid(true);

		a.set_x( rand() % (screen->w - 50) );
		a.set_y( rand() % (screen->h - 50) );

		cout << a.get_x() << " " << a.get_y() << endl;

		vetor_Asteroids.push_back( a );
	}

}

void Asteroids::blit_asteroids(SDL_Surface *screen){
	
	for (int i = 0; i < vetor_Asteroids.size(); ++i)
	{
		if ( vetor_Asteroids.at(i).get_isBig() ){

			SDL_BlitSurface( sprite_asteroid_BIG, NULL, screen, ( vetor_Asteroids.at(i).get_position() ) );
			
		}else{

			SDL_BlitSurface( sprite_asteroid_SMALL, NULL, screen, ( vetor_Asteroids.at(i).get_position() ) );

		}
	}

}