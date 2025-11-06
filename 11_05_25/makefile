all: main clock
main: main.cpp clock
	g++ -fdiagnostics-color=always -pedantic-errors -g main.cpp clock -o main
clock: clock.h clock.cpp
	g++ -fdiagnostics-color=always -pedantic-errors -g -c clock.cpp -o clock