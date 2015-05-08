#include "Object.h"

class Nave : public Object{
	private:
    	int health;
	public:
  		Nave(int, int, int, int);
  		~Nave();
  		//Health
  		void set_health(int);
  		int get_health();
};

Nave::Nave(int w, int h, int x_parameter, int y_parameter) : Object(w, h, x_parameter, y_parameter) {
	

}

Nave::~Nave(){

}

//Health
void Nave::set_health(int h){
	health = h;
}
int Nave::get_health(){
	return health;
}