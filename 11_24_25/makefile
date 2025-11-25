all: main 
main: main.cpp drink clock
	g++ -pedantic-errors -g -fdiagnostics-color=always main.cpp drink clock -o main
clock: clock.h clock.cpp
	g++ -pedantic-errors -g -fdiagnostics-color=always -c clock.cpp -o clock
drink: drink.h drink.cpp
	g++ -pedantic-errors -g -fdiagnostics-color=always -c drink.cpp -o drink