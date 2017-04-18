Pokedex: main.o Pokemon.o Executive.o
	g++ -std=c++11 -g -Wall main.o Pokemon.o Executive.o -o Pokedex
main.o: main.cpp Pokemon.h Executive.h
	g++ -std=c++11 -g -Wall -c main.cpp
Pokemon.o: Pokemon.h Pokemon.cpp
	g++ -std=c++11 -g -Wall -c Pokemon.cpp
Executive.o: Executive.h Executive.cpp
	g++ -std=c++11 -g -Wall -c Executive.cpp
clean:
	rm *.o Pokedex
