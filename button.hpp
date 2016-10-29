#ifndef BUTTON_HPP
#define BUTTON_HPP

#include<string>
#include<SFML/Graphics.hpp>

#define BT_COLOR_DEFAULT 150,150,150
#define BT_COLOR_CLICKED 100,100,100

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