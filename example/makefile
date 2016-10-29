OBJ = main.o simple-ui-library/button.o
LIBS = -lsfml-graphics -lsfml-system -lsfml-window

all: $(OBJ)
	g++ $(OBJ) $(LIBS)
		
main.o: main.cpp
	g++ -c main.cpp