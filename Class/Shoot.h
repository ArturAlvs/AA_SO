
class Shoot : public Object{

    int moving;

	public:
		Shoot(int,int,int,int);
		~Shoot();

		//Move
  		void moveShoot(SDL_Surface*);
  		int get_moving();
  		void set_moving(int);

  		//Tiro, go home, you're drunk
  		void tiro_go_home();

};


Shoot::Shoot(int w, int h, int x_parameter, int y_parameter) : Object(w, h, x_parameter, y_parameter) {
	
	this->set_moving(0);
	this->set_angulo(0);

}


//Move
void Shoot::moveShoot(SDL_Surface *screen){
	
	if (this->get_moving()){
		int v = 7;
		const double pi = 3.1415926535897;
		// this->setPos( this->getPos()->x+this->getVector()[0] ,this->getPos()->y+this->getVector()[1]);
		// this->setVector(v*cos(pi*this->angulo/180),-v*sin(pi*this->angulo/180));

		// this->switchSprite();
		// cout << this->angulo<< endl;
		// cout << "x "<<this->getVector()[0]<< " y "<<this->getVector()[1] << endl;
		this->move( screen, (v*cos(pi*this->angulo/180)), (-v*sin(pi*this->angulo/180)) );

		this->set_moving( this->get_moving() - 1 );
	}

}
int Shoot::get_moving(){
	return this->moving;
};
void Shoot::set_moving(int movement){
	this->moving = movement;

};

//Tiro, go home, you're drunk
void Shoot::tiro_go_home(){
	this->set_moving(0);
	this->set_x(-100);
	this->set_y(-100);
}