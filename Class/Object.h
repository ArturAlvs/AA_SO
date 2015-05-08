
class Object {
	protected:
    	int width, height;
    	int x, y;
	public:
      Object(int, int, int, int);
  		Object();
  		~Object();
  		// X & Y
   		void set_position (int,int);
    	void set_x(int);
    	void set_y(int);
    	int get_x();
    	int get_y();
    	//Width & Height
    	void set_dimension (int,int);
    	void set_width(int);
    	void set_height(int);
    	int get_width();
    	int get_height();
};

Object::Object(int w, int h, int x_parameter, int y_parameter){
  width = w;
  height = h;
  x = x_parameter;
  y = y_parameter;
}
Object::Object(){
  
}
Object::~Object(){

}

// X & Y
void Object::set_position (int x_parameter, int y_parameter) {
  x = x_parameter;
  y = y_parameter;
}
void Object::set_x (int x_parameter) {
  x = x_parameter;
}
void Object::set_y (int y_parameter) {
  y = y_parameter;
}
int Object::get_x () {
  return x;
}
int Object::get_y () {
  return y;
}
// Width & Height
void Object::set_dimension (int w, int h) {
  width = w;
  height = h;
}
void Object::set_width (int w) {
  width = w;
}
void Object::set_height (int h) {
  height = h;
}
int Object::get_width () {
  return width;
}
int Object::get_height () {
  return height;
}