
class Asteroid : public Object{

	bool isBig;

	public:
		Asteroid(bool);
		~Asteroid();

		bool get_isBig();
		void set_isBig(bool);
	
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