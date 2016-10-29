#ifndef BUTTON_HPP
#define BUTTON_HPP

#include<string>
#include<SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class Button {
	private:
		string name;
		int x,y,w,h;
		RectangleShape bt;
		RenderWindow *rw;		
		int click;		
				
	public:
		Button( string, RenderWindow&, int, int, int, int);
		void draw();
		bool pressed();
};

#endif