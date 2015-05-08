

class Nave : public Object{
	private:
    	int health;
      int angulo;
	public:
  		Nave(int, int, int, int);
  		~Nave();
  		//Health
      void set_health(int);
      int get_health();
      //Angulo
      void set_angulo(int);
      int get_angulo();
};

Nave::Nave(int w, int h, int x_parameter, int y_parameter) : Object(w, h, x_parameter, y_parameter) {
	
  health = 100;
}

//Health
void Nave::set_health(int h){
  health = h;
}
int Nave::get_health(){
  return health;
}

//Angulo
void Nave::set_angulo(int h){
  angulo = h;
}
int Nave::get_angulo(){
  return angulo;
}