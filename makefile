OBJ = button.o
LIBS = -lsfml-graphics -lsfml-system -lsfml-window
	
button.o: button.cpp button.hpp
	g++ -c button.cpp button.hpp