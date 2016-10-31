#include<SFML/Graphics.hpp>
#include<iostream>
#include "../suil.hpp"

using namespace std;
using namespace sf;

int main(){
	RenderWindow janela(VideoMode(800,600),"HELLO");
	janela.setFramerateLimit(30);
	
	Font font;
	font.loadFromFile("8-BIT WONDER.TTF");
	
	Color bg = Color::Red;
	
	Button bt_red("Red", janela, font, 10,10,100,50);
	Button bt_green("Green", janela, font, 120,10,100,50);
	Button bt_blue("Blue", janela, font, 230,10,100,50);
	
	while(janela.isOpen()){
		Event event;
		while(janela.pollEvent(event)){
			if(event.type == Event::Closed){
				janela.close();
			}
		}
		janela.clear( bg);
		bt_red.draw();
		bt_green.draw();
		bt_blue.draw();
		if( bt_red.pressed()){
			bg = Color::Red;			
		} else if( bt_green.pressed()){
			bg = Color::Green;
		} else if( bt_blue.pressed()){
			bg = Color::Blue;
		}
		janela.display();
	}
	return 0;
}