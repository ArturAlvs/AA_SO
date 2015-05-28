
class Asteroid : public Object{

	bool isBig;
	int velocidade;

	public:
		Asteroid(bool);
		~Asteroid();

		bool get_isBig();
		void set_isBig(bool);

		//Move
		void moveAsteroid(SDL_Surface *);

	
};

Asteroid::Asteroid(bool big) : Object(){

	this->isBig = big;
	this->velocidade = (rand() % 3) + 2 ;

	if (big){
		position.w = 50, position.h = 50;
	}else{
		position.w = 30, position.h = 30;
	}


}

Asteroid::~Asteroid(){
	
}

bool Asteroid::get_isBig(){
	return isBig;
}

void Asteroid::set_isBig(bool big){
	this->isBig = big;
}

void Asteroid::moveAsteroid(SDL_Surface *screen){

	const double pi = 3.1415926535897;
	this->move( screen, (velocidade * cos(pi*this->angulo/180)), (-velocidade * sin(pi*this->angulo/180)) );

}