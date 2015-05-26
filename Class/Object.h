#include "SDL/SDL.h"
#include <SDL/SDL_image.h>
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Object {
	protected:

        SDL_Rect position; //position on the screen
		SDL_Surface* sprite = NULL; //image of the obj
		int angulo;

	public:
     	Object(int, int, int, int);
  		Object();
  		~Object();

  		//Move
  		void move(SDL_Surface*, int, int);
  		//Angulo
    	void set_angulo(int);
    	int get_angulo();
  		// X & Y
   		void set_position (int,int);
   		SDL_Rect* get_position ();
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

        //Collision
        bool collision(Object*);

    	//Sprite
    	void setSprite(string);
    	SDL_Surface* getSprite();
    	//Blitar
    	void blit(SDL_Surface*);
};

Object::Object(int width_parameter, int height_parameter, int x_parameter, int y_parameter){
  position.w = width_parameter;
  position.h = height_parameter;
  position.x = x_parameter;
  position.y = y_parameter;

}
Object::Object(){
  
}
Object::~Object(){

}

//Move Obj
void Object::move(SDL_Surface *screen, int x_parameter, int y_parameter){
	// this->setPos( this->getPos()->x+this->getVector()[0] ,this->getPos()->y+this->getVector()[1]);
	this->position.x += x_parameter;
	this->position.y += y_parameter;

	if (this->position.x > screen->w){
		this->position.x = 0;
	}
	else if(this->position.x < 0)
		this->position.x = screen->w;

	if (this->position.y > screen->h){
		this->position.y = 0;
	}
	else if(this->position.y < 0)
		this->position.y = screen->h;

	// cout << "x " << this->position.x <<"  y "<<this->position.y<< endl;
}

//Angulo
void Object::set_angulo(int ang){
  angulo = ang;
}
int Object::get_angulo(){
  return angulo;
}

// X & Y
void Object::set_position (int x_parameter, int y_parameter) {
  position.x = x_parameter;
  position.y = y_parameter;
}
SDL_Rect* Object::get_position (){

	return &position;

};

void Object::set_x (int x_parameter) {
  position.x = x_parameter;
}
void Object::set_y (int y_parameter) {
  position.y = y_parameter;
}
int Object::get_x () {
  return position.x;
}
int Object::get_y () {
  return position.y;
}
// Width & Height
void Object::set_dimension (int width_parameter, int height_parameter) {
  position.w = width_parameter;
  position.h = height_parameter;
}
void Object::set_width (int width_parameter) {
  position.w = width_parameter;
}
void Object::set_height (int height_parameter) {
  position.h = height_parameter;
}
int Object::get_width () {
    return position.w;
}
int Object::get_height () {
    return position.h;
}

//Collision
bool Object::collision(Object *a){

    if ( a->get_x() > (this->get_x() + this->get_width()) ||
         a->get_y() > (this->get_y() + this->get_height()) ||
         this->get_x() > (a->get_x() + a->get_width()) ||
         this->get_y() > (a->get_y() + a->get_height()) ){

        return false;

    }else{
        return true;
    }

    return false;

}

//Sprite
SDL_Surface* Object::getSprite(){
	return sprite;
}

void Object::setSprite(string path){
	sprite = IMG_Load(path.c_str());

}

//Blitar
void Object::blit(SDL_Surface* screen){
	SDL_BlitSurface( sprite, NULL, screen, &position );
}