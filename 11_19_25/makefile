all: main vector clock movie
main: main.cpp vector clock movie
	g++ -pedantic-errors -g -fdiagnostics-color=always main.cpp movie vector clock -o main
vector: vector.h vector.cpp
	g++ -pedantic-errors -g -fdiagnostics-color=always -c vector.cpp -o vector
clock: clock.h clock.cpp
	g++ -pedantic-errors -g -fdiagnostics-color=always -c clock.cpp -o clock
movie: movieTimes.cpp movieTimes.h
	g++ -pedantic-errors -g -fdiagnostics-color=always -c movieTimes.cpp -o movie
