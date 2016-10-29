OBJ = button.o
LIBS = -lsfml-graphics -lsfml-system -lsfml-window

all: $(OBJ)
	g++ $(OBJ) $(LIBS)
	
button.o: button.cpp button.hpp
	g++ -c button.cpp button.hpp