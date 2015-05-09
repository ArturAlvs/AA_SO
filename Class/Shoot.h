
class Shoot : public Object{

	public:
		Shoot(int,int,int,int);
		~Shoot();
		void set_vetor(int, int);
		int* get_vetor();

};


Shoot::Shoot(int w, int h, int x_parameter, int y_parameter) : Object(w, h, x_parameter, y_parameter) {
	

}