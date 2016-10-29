#include<SFML/Graphics.hpp>
#include<iostream>
#include "simple-ui-library/suil.hpp"

using namespace std;
using namespace sf;

int main(){
	RenderWindow janela(VideoMode(800,600),"HELLO");
	janela.setFramerateLimit(30);
	
	sf::Font font;
	font.loadFromFile("8-BIT WONDER.TTF");
	
	Button bt("Hello", janela, font, 50,80,100,50);
	
	while(janela.isOpen()){
		Event event;
		while(janela.pollEvent(event)){
			if(event.type == Event::Closed){
				janela.close();
			}
		}
		janela.clear(Color::Black);
		bt.draw();
		if(bt.pressed()){
			cout<<"CLICK"<<endl;
		}
		janela.display();
	}
	return 0;
}