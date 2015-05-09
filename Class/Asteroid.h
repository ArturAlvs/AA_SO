
class Asteroid : public Object{

	bool isBig;

	public:
		Asteroid(bool);
		~Asteroid();
	
};

Asteroid::Asteroid(bool big) : Object(){
	
	isBig = big;

	if (big){
		position.w = 50, position.h = 50;
		position.x = 0;
		position.y = 0;
	}


}