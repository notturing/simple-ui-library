#include "button.hpp"
#include<iostream>

using namespace std;

Button::Button( string name, RenderWindow &rw, Font &font, int x, int y, int w, int h){	
	this->x = x;
	this->y = y;
	this->w = w;
	this->h = h;
	this->rw = &rw;	
	this->bt.setSize( Vector2f( w, h));
	this->bt.setPosition( Vector2f( x, y));
	this->bt.setFillColor( Color::Red);
	this->text.setFont( font);
	this->text.setString( name);	
	this->text.setCharacterSize(14);
	this->text.setColor( Color(BT_COLOR_TEXT));
	FloatRect center = this->text.getLocalBounds();
	float cx = ( center.left + center.width ) / 2;
	float cy = ( center.top + center.height ) / 2;		
	this->text.setPosition( Vector2f( this->x + (this->w/2) - cx, this->y + (this->h/2) - cy));
}

void Button::draw(){	
	if( this->click == 1){
		this->bt.setFillColor( Color(BT_COLOR_CLICKED));
	} else {
		this->bt.setFillColor( Color(BT_COLOR_DEFAULT));
	}	
	this->rw->draw( this->bt);		
	this->rw->draw( this->text);
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

