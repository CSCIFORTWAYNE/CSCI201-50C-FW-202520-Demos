all: clock main
main: main.cpp clock
	g++ -pedantic-errors -g -fdiagnostics-color=always main.cpp clock -o main
clock: clock.h clock.cpp
	g++ -pedantic-errors -g -fdiagnostics-color=always -c clock.cpp -o clock