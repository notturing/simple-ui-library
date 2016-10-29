#include "button.hpp"

Button::Button( string name, RenderWindow& rw, int x, int y, int w, int h) : name(name), x(x), y(y), w(w), h(h), rw(&rw) {
	this->bt.setSize( Vector2f( w, h));
	this->bt.setPosition( Vector2f( x, y));
	this->bt.setFillColor( Color::Red);
}

void Button::draw(){	
	if( this->click == 1){
		this->bt.setFillColor( Color::Green);
	} else {
		this->bt.setFillColor( Color::Blue);
	}	
	this->rw->draw( this->bt);
}


bool Button::pressed(){	
	Vector2i mouse = Mouse::getPosition( *this->rw);
	bool inside = mouse.x > this->x ? 
				  mouse.x < this->x + this->w ?
				  mouse.y > this->y ?
				  mouse.y < this->y + this->h ?
				  true : false: false : false : false;
		
	if(Mouse::isButtonPressed( Mouse::Left)){
		switch( this->click){
			case 0: {
				if( inside){
					this->click = 1;
					return true;					
				} else {
					this->click = 2;
					return false;
				}
			}			
			case 1: return false;
			case 2: return false;
		}
	} else {
		this->click = 0;
		return false;
	}
}

