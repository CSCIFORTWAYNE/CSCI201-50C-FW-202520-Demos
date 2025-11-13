all: clock movie
	g++ -pedantic-errors -g -fdiagnostics-color=always main.cpp clock movie -o main
clock: clock.cpp clock.h
	g++ -pedantic-errors -g -fdiagnostics-color=always -c clock.cpp -o clock
movie: movieTimes.cpp movieTimes.h
	g++ -pedantic-errors -g -fdiagnostics-color=always -c movieTimes.cpp -o movie
