#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <iostream>
#include <cmath>

class Nave : public Object{
	private:
    	int health;
	public:
  		Nave(int, int, int, int);
  		~Nave();
  		
  		//Move
  		void moveNave(SDL_Surface*);
  		//Health
     	void set_health(int);
     	int get_health();
     	//Angulo
     	void increaseAngulo();
     	void decreaseAngulo();
      
};

Nave::Nave(int w, int h, int x_parameter, int y_parameter) : Object(w, h, x_parameter, y_parameter) {
	
  health = 100;
}

//Move
void Nave::moveNave(SDL_Surface *screen){
	int v = 4;
	const double pi = 3.1415926535897;
	// this->setPos( this->getPos()->x+this->getVector()[0] ,this->getPos()->y+this->getVector()[1]);
	// this->setVector(v*cos(pi*this->angulo/180),-v*sin(pi*this->angulo/180));

	// this->switchSprite();
	// cout << this->angulo<< endl;
	// cout << "x "<<this->getVector()[0]<< " y "<<this->getVector()[1] << endl;
	this->move( screen, (v*cos(pi*this->angulo/180)), (-v*sin(pi*this->angulo/180)) );
}

//Health
void Nave::set_health(int h){
  health = h;
}
int Nave::get_health(){
  return health;
}

//Angle
void Nave::increaseAngulo(){
	angulo += 15;
}
void Nave::decreaseAngulo(){
	angulo -= 15;
}
