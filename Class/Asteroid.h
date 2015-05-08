
class Asteroid : public Object{

	bool isBig;

	public:
		Asteroid(bool);
		~Asteroid();
	
};

Asteroid::Asteroid(bool big) : Object(){
	
	isBig = big;

	if (big){
		width = 50, height = 50;
		x = 0;
		y = 0;
	}


}