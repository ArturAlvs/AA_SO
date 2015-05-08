
class Eve : public Object{
	public:
		Eve(int, int, int, int);
		~Eve();

		virtual void fight_hero() = 0; //Pure virtual function makes this class Abstract class.

	
};

Eve::Eve(int w, int h, int x_parameter, int y_parameter) : Object(w, h, x_parameter, y_parameter) {

}