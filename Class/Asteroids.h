
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

		//Blit
		void blit_asteroids(SDL_Surface*);

		//Move
		void moveAsteroids(SDL_Surface *);

		//Player collision
		void player_collision(Nave*);

		//Shoot collision
		void shoot_collision(Shoot*);

		//Size
		int get_quantidade();

		//Add
		void add_asteroids(Asteroid *);

	
};

Asteroids::Asteroids(int quantidade_asteroids, SDL_Surface* screen){

	sprite_asteroid_BIG = IMG_Load("Media/asteroid.png");
	sprite_asteroid_SMALL = IMG_Load("Media/asteroid_small.png");

	for (int i = 0; i < quantidade_asteroids; ++i){

		Asteroid a(true);

		a.set_x( rand() % (screen->w - 50) );
		a.set_y( rand() % (screen->h - 50) );

		a.set_angulo( rand() % 360 );

		// cout << a.get_x() << " " << a.get_y() << endl;

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

void Asteroids::moveAsteroids(SDL_Surface *screen){

	for (int i = 0; i < vetor_Asteroids.size(); ++i){

		vetor_Asteroids.at( i ).moveAsteroid(screen);
	}
	

}

//Player collision
void Asteroids::player_collision(Nave *player){

	for (int i = 0; i < vetor_Asteroids.size(); ++i){

		bool was_detected = vetor_Asteroids.at( i ).collision(player);

		if (was_detected){
			player->damage_by_asteroid();
		}

	}

}
//Shoot collision
void Asteroids::shoot_collision(Shoot *tiro){

	for (int i = 0; i < vetor_Asteroids.size(); ++i){

		bool was_detected = vetor_Asteroids.at( i ).collision(tiro);

		if (was_detected){

			tiro->tiro_go_home();		

			if (vetor_Asteroids.at(i).get_isBig()){
				this->add_asteroids(&(vetor_Asteroids.at(i)));
				vetor_Asteroids.at(i).set_isBig(false);
			}else{
				vetor_Asteroids.erase( vetor_Asteroids.begin() + i );
			}

		}
	}
}


//Size
int Asteroids::get_quantidade(){
	return this->vetor_Asteroids.size();
}

//Add
void Asteroids::add_asteroids(Asteroid *asteroid_parameter){

	Asteroid a(false);

	a.set_x( asteroid_parameter->get_x() );
	a.set_y( asteroid_parameter->get_y() );

	if (asteroid_parameter->get_angulo() > 180){
		a.set_angulo( rand() % (180) );	
	}else{
		a.set_angulo( (rand() % 180) + 180 );	

	}


	vetor_Asteroids.push_back( a );

}