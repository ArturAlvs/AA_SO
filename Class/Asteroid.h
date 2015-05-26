
class Asteroid : public Object{

	bool isBig;

	public:
		Asteroid(bool);
		~Asteroid();

		bool get_isBig();
		void set_isBig(bool);

		//Move
		void moveAsteroid(SDL_Surface *);

	
};

Asteroid::Asteroid(bool big) : Object(){
	
	isBig = big;

	if (big){
		position.w = 50, position.h = 50;
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

	int v = 2;
	const double pi = 3.1415926535897;
	this->move( screen, (v*cos(pi*this->angulo/180)), (-v*sin(pi*this->angulo/180)) );

}